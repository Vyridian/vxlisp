namespace vx_core;

public static class vx_core {

  public interface Map<TKey, TValue> {
  }

  public class LinkedHashMap<TKey, TValue> : Map<TKey, TValue> {
  }

  public interface vx_Type_const {
    public vx_core.Type_constdef vx_constdef();
  }

  public interface Type_replfunc {
    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist);
  }

  public interface Type_replfunc_async {
    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist);
  }

  public static List<vx_core.Type_any> emptylistany = new List<vx_core.Type_any>();

  public static Map<String, vx_core.Type_any> emptymapany = new LinkedHashMap<String, vx_core.Type_any>();

  public class Class_base {
    protected int vx_iref = 0;
    protected vx_core.Type_constdef vxconstdef = null;
    protected vx_core.Type_msgblock vxmsgblock = null;
    public virtual vx_core.Type_any vx_new(params Object[] vals) {
      return e_any;
    }
    public virtual vx_core.Type_any vx_copy(params Object[] vals) {
      return e_any;
    }
    public virtual vx_core.Type_any vx_empty() {
      return e_any;
    }
    public virtual vx_core.Type_any vx_type() {
      return t_any;
    }
    public virtual vx_core.Type_typedef vx_typedef() {
      return e_typedef;
    }
    public List<Type_any> vx_dispose() {
      this.vx_iref = 0;
      this.vxmsgblock = null;
      return emptylistany;
    }
    public vx_core.Type_msgblock vx_msgblock() {return vxmsgblock;}
    public bool vx_release() {
      bool output = false;
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

  public class KeyValue<T> {
    public String key = "";
    public T value = null;
  }

  public static vx_core.Type_constdef constdef_new(
    String pkgname,
    String name,
    vx_core.Type_any typ
  ) {
    vx_core.Class_constdef output = new vx_core.Class_constdef();
    output.vx_p_pkgname = vx_core.vx_new_string(pkgname);
    output.vx_p_name = vx_core.vx_new_string(name);
    output.vx_p_type = typ;
    return output;
  }

  public static vx_core.Type_funcdef funcdef_new(
    String pkgname,
    String name,
    int idx,
    bool async,
    vx_core.Type_any typ
  ) {
    vx_core.Class_funcdef output = new vx_core.Class_funcdef();
    output.vx_p_pkgname = vx_core.vx_new_string(pkgname);
    output.vx_p_name = vx_core.vx_new_string(name);
    output.vx_p_idx = vx_core.vx_new_int(idx);
    output.vx_p_async = vx_core.vx_new_boolean(async);
    output.vx_p_type = typ;
    return output;
  }

  public static vx_core.Type_any[] arrayany_from_anylist(vx_core.Type_anylist list) {
    return list.vx_list().toArray(new vx_core.Type_any[0]);
  }

  public static List<T> arraylist_from_array<T>(params T[] items) {
    List<T> output = new List<>(items);
    return output;
  }

  public static List<T> arraylist_from_arraylist<T, U>(T generic_any_1, List<U> listval) where T : vx_core.Type_any where U : vx_core.Type_any {
    List<T> output = new List<>();
    foreach (vx_core.Type_any value in listval) {
      T t_val = vx_core.f_any_from_any(generic_any_1, value);
      output.add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_arraylist_fn<T, U>(List<U> listval, Func<U, T> fn_any_from_any) {
    List<T> output = new List<>();
    foreach (U value_u in listval) {
      T t_val = fn_any_from_any.apply(value_u);
      output.add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_linkedhashmap<T, U>(T generic_any_1, LinkedHashMap<String, U> mapval) where T : vx_core.Type_any where U : vx_core.Type_any {
    List<T> output = new List<T>();
    Set<String> keys = mapval.keySet();
    foreach (String key in keys) {
      U u_val = mapval.get(key);
      T t_val = vx_core.f_any_from_any(generic_any_1, u_val);
      output.add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_linkedhashmap_fn<T, U>(Map<String, U> mapval, Func<String, U, T> fn_any_from_key_value) {
    List<T> output = new List<T>();
    Set<String> keys = mapval.keySet();
    foreach (String key in keys) {
      U u_val = mapval.get(key);
      T t_val = fn_any_from_key_value.apply(key, u_val);
      output.add(t_val);
    }
    return output;
  }

  public static Task<T> async_new_completed<T>(T val) {
    Task<T> output = Task.completedFuture(val);
    return output;
  }

  public static Task<T> async_from_async<T, U>(T generic_any_1, Task<U> future) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = future.thenApply(val => {
      return vx_core.f_any_from_any(generic_any_1, val);
    });
    return output;
  }

  public static Task<T> async_from_async_fn<T, U>(Task<U> future, Func<U, T> fn) {
    Task<T> output = future.ContinueWith(antecedent => {
      U result = antedcedent.Result;
      return fn(result);
    });
    return output;
  }

  public static Task<List<T>> async_arraylist_from_arraylist_async<T>(List<Task<T>> list_future) {
    Task<Void> allFutures = Task.allOf(
      list_future.toArray(new Task[list_future.size()])
    );
    Task<List<T>> output = allFutures.thenApply(v => {
      List<T> list = list_future.stream()
        .map(future => future.join())
        .collect(Collectors.toList());
      return list;
    });
    return output;
  }

  public static LinkedHashMap<String, T> hashmap_from_keyvalues<T>(params KeyValue<T>[] keyvalues) {
    LinkedHashMap<String, T> output = new LinkedHashMap<>();
    foreach (KeyValue<T> keyvalue in keyvalues) {
      String key = keyvalue.key;
      T value = keyvalue.value;
      output.put(key, value);
    }
    return output;
  }

  public static KeyValue<T> keyvalue_from_key_value<T>(String key, T value) {
    KeyValue<T> output = new KeyValue<T>();
    output.key = key;
    output.value = value;
    return output;
  }

  public static Map<String, T> map_from_list_fn<T>(List<T> listval, Func<T, vx_core.Type_string> fn_any_from_any) {
    Map<String, T> output = new LinkedHashMap<>();
    foreach (T val in listval) {
      vx_core.Type_string valkey = fn_any_from_any.apply(val);
      String key = valkey.vx_string();
      output.put(key, val);
    }
    return output;
  }

  public static LinkedHashMap<String, T> map_from_map<T>(LinkedHashMap<String, vx_core.Type_any> mapval) where T : vx_core.Type_any {
    LinkedHashMap<String, T> output = new LinkedHashMap<>();
    Set<String> keys = mapval.keySet();
    foreach (String key in keys) {
      vx_core.Type_any value = mapval.get(key);
      try {
        T castval = (T)value;
        output.put(key, castval);
      } catch (Exception ex) {
        vx_core.vx_log("map<-map", ex);
      }
    }
    return output;
  }

  // vx_boolean_from_string_ends(string, string)
  public static bool vx_boolean_from_string_ends(String text, String ends) {
    return text.endsWith(ends);
  }

  // vx_boolean_from_string_find(string, string)
  public static bool vx_boolean_from_string_find(String text, String find) {
    return text.contains(find);
  }

  // vx_boolean_from_string_starts(string, string)
  public static bool vx_boolean_from_string_starts(String text, String starts) {
    return text.startsWith(starts);
  }

  // vx_eqeq(any, any)
  public static bool vx_eqeq(vx_core.Type_any val1, vx_core.Type_any val2) {
    bool output = false;
    if (val1 == val2) {
      output = true;
    } else if (val1.vx_msgblock() != vx_core.e_msgblock) {
    } else if (val2.vx_msgblock() != vx_core.e_msgblock) {
    } else {
      vx_core.Type_any type1 = val1.vx_type();
      vx_core.Type_any type2 = val2.vx_type();
      if (type1 != type2) {
      } else if (type1 == vx_core.t_int) {
        vx_core.Type_int valint1 = (vx_core.Type_int)val1;
        vx_core.Type_int valint2 = (vx_core.Type_int)val2;
        if (valint1.vx_int() == valint2.vx_int()) {
          output = true;
        }
      } else if (type1 == vx_core.t_float) {
        vx_core.Type_float valfloat1 = (vx_core.Type_float)val1;
        vx_core.Type_float valfloat2 = (vx_core.Type_float)val2;
        if (valfloat1.vx_float() == valfloat2.vx_float()) {
          output = true;
        }
      } else if (type1 == vx_core.t_decimal) {
        vx_core.Type_decimal valdecimal1 = (vx_core.Type_decimal)val1;
        vx_core.Type_decimal valdecimal2 = (vx_core.Type_decimal)val2;
        if (valdecimal1.vx_string() == valdecimal2.vx_string()) {
          output = true;
        }
      } else if (type1 == vx_core.t_string) {
        vx_core.Type_string valstring1 = (vx_core.Type_string)val1;
        vx_core.Type_string valstring2 = (vx_core.Type_string)val2;
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
  public static void vx_global_package_set(String pkgname, Map<String, vx_core.Type_any> maptype, Map<String, vx_core.Type_any> mapconst, Map<String, vx_core.Type_func> mapfunc) {
    vx_core.Class_typemap typemap = new vx_core.Class_typemap();
		  typemap.vx_p_map = maptype;
	   vx_core.Class_constmap constmap = new vx_core.Class_constmap();
		  constmap.vx_p_map = mapconst;
		  vx_core.Class_funcmap funcmap = new vx_core.Class_funcmap();
		  funcmap.vx_p_map = mapfunc;
    vx_core.Class_project global = (vx_core.Class_project)vx_core.c_global;
    vx_core.Class_packagemap packagemap = (vx_core.Class_packagemap)global.vx_p_packagemap;
    if (packagemap == null) {
      packagemap = new vx_core.Class_packagemap();
      global.vx_p_packagemap = packagemap;
    }
    Map<String, vx_core.Type_package> mappackage = new LinkedHashMap<>(packagemap.vx_p_map);
		  vx_core.Class_package pkg = new vx_core.Class_package();
		  pkg.vx_p_constmap = constmap;
		  pkg.vx_p_typemap = typemap;
		  pkg.vx_p_funcmap = funcmap;
    mappackage.put(pkgname, pkg);
    packagemap.vx_p_map = mappackage;
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
    return text.IndexOf(find);
  }

  // vx_int_from_string_findlast(string, string)
  public static int vx_int_from_string_findlast(String text, String findlast) {
    return text.LastIndexOf(findlast);
  }

  // vx_is_float(string)
  public static bool vx_is_float(String text) {
    bool output = false;
    try {
      Float.parseFloat(text);
      output = true;
    } catch (Exception e) {
    }    
    return output;
  }

  // vx_is_float(any)
  public static bool vx_is_float(vx_core.Type_any value) {
    bool output = false;
    if (value is vx_core.Type_number) {
      output = true;
    } else if (value is vx_core.Type_string) {
      vx_core.Type_string valuestring = (vx_core.Type_string)value;
      output = vx_core.vx_is_float(valuestring.vx_string());
    }
    return output;
  }

  // vx_is_int(string)
  public static bool vx_is_int(String text) {
    bool output = false;
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
  public static bool vx_is_int(vx_core.Type_any value) {
    bool result = false;
    if (value == vx_core.c_infinity) {
      result = true;
    } else if (value == vx_core.c_neginfinity) {
      result = true;
    } else if (value == vx_core.c_notanumber) {
      result = true;
    } else if (value is vx_core.Type_int) {
      result = true;
    } else if (value is vx_core.Type_float) {
      vx_core.Type_float valfloat = (vx_core.Type_float)value;
      float floatval = valfloat.vx_float();
      if ((int)floatval == floatval) {
        result = true;
      }
    } else if (value is vx_core.Type_decimal) {
      vx_core.Type_decimal valdec = (vx_core.Type_decimal)value;
      String strval = valdec.vx_string();
      try {
        if (Integer.parseInt(strval) == Float.parseFloat(strval)) {
          result = true;
        }
      } catch (Exception ex) {
      }
    } else if (value is vx_core.Type_string) {
      vx_core.Type_string valstr = (vx_core.Type_string)value;
      String strval = valstr.vx_string();
      result = vx_is_int(strval);
    }
    return result;
  }

  // vx_log(object...)
  public static void vx_log(params Object[] values) {
    foreach (Object value in values) {
      String text = "";
      if (value == null) {
        text = "null";
      } else if (value is vx_core.Type_string) {
        vx_core.Type_string valstring = (vx_core.Type_string)value;
        text = valstring.vx_string();
      } else if (value is vx_core.Type_any) {
        vx_core.Type_any valany = (vx_core.Type_any)value;
        vx_core.Type_string valstring = vx_core.f_string_from_any(valany);
        text = valstring.vx_string();
      } else {
        text = value.toString();
      }
      System.Console.WriteLine(text);
    }
  }

  // vx_msg_error
  public static Type_msg vx_msg_error(String text) {
    Class_msg output = new Class_msg();
    output.vx_p_text = vx_core.vx_new_string(text);
    output.vx_p_severity = vx_core.c_msg_severe;
    return output;
  }

  // vx_msg_from_exception
  public static Type_msg vx_msg_from_exception(String text, Exception err) {
    Class_msg output = new Class_msg();
    output.vx_p_text = vx_core.vx_new_string(text);
    output.vx_p_severity = vx_core.c_msg_severe;
    output.err = err;
    vx_core.vx_log(output);
    return output;
  }

  public static Type_boolean vx_new_boolean(bool isval) {
    Type_boolean output = vx_core.c_false;
    if (isval) {
      output = vx_core.c_true;
    }
    return output;
  }

  public static Type_float vx_new_float(float fval) {
    Class_float output = new vx_core.Class_float();
    output.vxfloat = fval;
    return output;
  }

  public static Type_int vx_new_int(int ival) {
    Type_int output;
    if ((ival == 0) && vx_core.e_int != null) {
      output = vx_core.e_int;
    } else {
      Class_int work = new vx_core.Class_int();
      work.vxint = ival;
      output = work;

    }
    return output;
  }

  public static Type_string vx_new_string(String text) {
    Type_string output;
    if (text.equals("") && vx_core.e_string != null) {
      output = vx_core.e_string;
    } else {
      Class_string work = new vx_core.Class_string();
      work.vxstring = text;
      output = work;
    }
    return output;
  }

  public static String vx_string_from_any(vx_core.Type_any value) {
    return vx_string_from_any_indent(value, 0, false);
  }

  public static String vx_string_from_any_indent(vx_core.Type_any value, int indent, bool linefeed) {
    String indenttext = " ".repeat(indent);
    String output = "";
    if (indent > 50) {
      output = "Error: Max Depth Exceeded";
    } else if (value == null) {
      output = "null";
    } else if (value == value.vx_type()) {
      if (value is vx_core.Type_func) {
        vx_core.Type_func valuefunc = (vx_core.Type_func)value;
        vx_core.Type_funcdef funcdef = valuefunc.vx_funcdef();
        output = funcdef.pkgname().vx_string() + "/" + funcdef.name().vx_string();
      } else {
        vx_core.Type_typedef typedef = value.vx_typedef();
        output = typedef.pkgname().vx_string() + "/" + typedef.name().vx_string();
      }
    } else if (value is vx_core.Type_boolean) {
      vx_core.Type_boolean valbool = vx_core.f_any_from_any(vx_core.t_boolean, value);
      if (valbool.vx_boolean() == true) {
        output = "true";
      } else {
        output = "false";
      }
    } else if (value is vx_core.Type_decimal) {
      vx_core.Type_decimal valdec = vx_core.f_any_from_any(vx_core.t_decimal, value);
      output = valdec.vx_string();
    } else if (value is vx_core.Type_float) {
      vx_core.Type_float valfloat = vx_core.f_any_from_any(vx_core.t_float, value);
      output = Float.toString(valfloat.vx_float());
      if (output.endsWith(".0")) {
        output = output.substring(0, output.length() - 2);
      }
    } else if (value is vx_core.Type_int) {
      if (value == vx_core.c_notanumber) {
        output = "notanumber";
      } else if (value == vx_core.c_infinity) {
        output = "infinity";
      } else if (value == vx_core.c_neginfinity) {
        output = "neginfinity";
      } else {
        vx_core.Type_int valint = vx_core.f_any_from_any(vx_core.t_int, value);
        output = Integer.toString(valint.vx_int());
      }
    } else if (value is vx_core.Type_string) {
      vx_core.Type_string valstring = vx_core.f_any_from_any(vx_core.t_string, value);
      output = "\"" + valstring.vx_string() + "\"";
    } else if (value is vx_core.vx_Type_const) {
      vx_core.vx_Type_const constvalue = (vx_core.vx_Type_const)value;
      vx_core.Type_constdef constdef = constvalue.vx_constdef();
      String constpkg = constdef.pkgname().vx_string();
      String constname = constdef.name().vx_string();
      if (constpkg.equals("vx/core")) {
        output = constname;
      } else {
        output = constpkg + "/" + constname;
      }
    } else if (value is vx_core.Type_list) {
      vx_core.Type_list vallist = vx_core.f_any_from_any(vx_core.t_list, value);
      vx_core.Type_typedef typedef = vallist.vx_typedef();
      vx_core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 1;
      List<vx_core.Type_any> listval = vallist.vx_list();
      foreach (vx_core.Type_any valsub in listval) {
        String valtext = vx_core.vx_string_from_any_indent(valsub, indentint, linefeed);
        output += "\n " + indenttext + valtext;
      }
      if (vallist.vx_msgblock() != null) {
        String msgtext = vx_core.vx_string_from_any_indent(vallist.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is vx_core.Type_map) {
      vx_core.Type_map valmap = vx_core.f_any_from_any(vx_core.t_map, value);
      vx_core.Type_typedef typedef = valmap.vx_typedef();
      vx_core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 2;
      Map<String, vx_core.Type_any> mapval = valmap.vx_map();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any valsub = mapval.get(key);
        if (!key.startsWith(":")) {
          key = ":" + key;
        }
        String strval = vx_core.vx_string_from_any_indent(valsub, indentint, linefeed);
        if (strval.contains("\n")) {
          strval = "\n  " + indenttext + strval;
        } else {
          strval = " " + strval;
        }
        output += "\n" + indenttext + " " + key + strval;
      }
      if (valmap.vx_msgblock() != null) {
        String msgtext = vx_core.vx_string_from_any_indent(valmap.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is vx_core.Type_struct) {
      vx_core.Type_struct valstruct = vx_core.f_any_from_any(vx_core.t_struct, value);
      vx_core.Type_typedef typedef = valstruct.vx_typedef();
      vx_core.Type_string typedefname = typedef.name();
      int indentint2 = indent;
      indentint2 += 2;
      Map<String, vx_core.Type_any> mapval2 = valstruct.vx_map();
      Set<String> keys2 = mapval2.keySet();
      foreach (String key in keys2) {
        vx_core.Type_any valsub2 = mapval2.get(key);
        if (!vx_core.f_is_empty_1(valsub2).vx_boolean()) {
          if (!key.startsWith(":")) {
            key = ":" + key;
          }
          String strval2 = vx_core.vx_string_from_any_indent(valsub2, indentint2, linefeed);
          if (strval2.contains("\n")) {
            strval2 = "\n  " + indenttext + strval2;
          } else {
            strval2 = " " + strval2;
          }
          output += "\n" + indenttext + " " + key + strval2;
        }
      }
      if (valstruct.vx_msgblock() != null) {
        String msgtext2 = vx_core.vx_string_from_any_indent(valstruct.vx_msgblock(), indentint2, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext2;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is vx_core.Type_func) {
      vx_core.Type_func valfunc = vx_core.f_any_from_any(vx_core.t_func, value);
      vx_core.Type_funcdef funcdef = valfunc.vx_funcdef();
      vx_core.Type_string funcdefname = vx_core.f_funcname_from_funcdef(funcdef);
      output = funcdefname.vx_string();
      if (valfunc.vx_msgblock() != null) {
        String msgtext = vx_core.vx_string_from_any_indent(valfunc.vx_msgblock(), indent, linefeed);
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

  public static vx_core.Type_typedef typedef_new(
    String pkgname,
    String name,
    String extend,
    vx_core.Type_typelist traits,
    vx_core.Type_typelist allowtypes,
    vx_core.Type_typelist disallowtypes,
    vx_core.Type_funclist allowfuncs,
    vx_core.Type_funclist disallowfuncs,
    vx_core.Type_anylist allowvalues,
    vx_core.Type_anylist disallowvalues,
    vx_core.Type_argmap properties
  ) {
    vx_core.Class_typedef output = new vx_core.Class_typedef();
    output.vx_p_pkgname = vx_core.vx_new_string(pkgname);
    output.vx_p_name = vx_core.vx_new_string(name);
    output.vx_p_extend = vx_core.vx_new_string(extend);
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

  public static vx_core.Type_anylist vx_anylist_from_arraystring(String[] arraystring) {
    List<Object> listany = new List<>();
    foreach (String svalue in arraystring) {
      vx_core.Type_string value = vx_core.vx_new_string(svalue);
      listany.add(value);
    }
    Object[] arrayany = listany.toArray();
    vx_core.Type_anylist output = vx_core.t_anylist.vx_new(arrayany);
    return output;
  }

  // Warning!: Blocking
  public static T vx_sync_from_async<T>(T generic_any_1, Task<T> future) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    try {
      output = future.get();
    } catch (Exception e) {
      vx_core.Type_msg msg = vx_core.vx_msg_from_exception("sync<-async", e);
      vx_core.Type_any val = generic_any_1.vx_new(msg);
      output = vx_core.f_any_from_any(generic_any_1, val);
    }
    return output;
  }

  /**
   * type: any
   * Any Value for Variant Type
   * (type any)
   */
  public interface Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_typedef vx_typedef();
    public List<Type_any> vx_dispose();
    public vx_core.Type_msgblock vx_msgblock();
    public bool vx_release();
    public void vx_reserve();
  }

  public class Class_any : vx_core.Class_base, Type_any {

    public override vx_core.Type_any vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_any,
       vals);
    }

    public override vx_core.Type_any vx_copy(params Object[] vals) {
      Type_any output = this;
      boolean ischanged = false;
      Class_any val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_any work = new Class_any();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_any e_any = new Class_any();
  public static Type_any t_any = new Class_any();

  /**
   * type: any-async<-func
   * A sync or async function that returns one value.
   * (type any-async<-func)
   */
  public interface Type_any_async_from_func : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_any_async_from_func : vx_core.Class_base, Type_any_async_from_func {

    public override vx_core.Type_any_async_from_func vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_any_async_from_func,
       vals);
    }

    public override vx_core.Type_any_async_from_func vx_copy(params Object[] vals) {
      Type_any_async_from_func output = this;
      boolean ischanged = false;
      Class_any_async_from_func val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_any_async_from_func work = new Class_any_async_from_func();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_async_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_async_from_func;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "any-async<-func", // name
        ":func", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_any_async_from_func e_any_async_from_func = new Class_any_async_from_func();
  public static Type_any_async_from_func t_any_async_from_func = new Class_any_async_from_func();

  /**
   * type: any<-anylist
   * List of any<-any
   * (type any<-anylist)
   */
  public interface Type_any_from_anylist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Func_any_from_any> vx_listany_from_any();
    public vx_core.Func_any_from_any vx_any_from_any(vx_core.Type_int index);
  }

  public class Class_any_from_anylist : vx_core.Class_base, Type_any_from_anylist {

    protected List<vx_core.Func_any_from_any> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Func_any_from_any>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Func_any_from_any vx_any_from_any(vx_core.Type_int index) {
      vx_core.Func_any_from_any output = vx_core.e_any_from_any;
      vx_core.Class_any_from_anylist list = this;
      int iindex = index.vx_int();
      List<vx_core.Func_any_from_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Func_any_from_any> vx_listany_from_any() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_any_from_any(index);
    }

    public override vx_core.Type_any_from_anylist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_any_from_anylist,
       vals);
    }

    public override vx_core.Type_any_from_anylist vx_copy(params Object[] vals) {
      Type_any_from_anylist output = this;
      boolean ischanged = false;
      Class_any_from_anylist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Func_any_from_any> listval = new ArrayList<>(val.vx_listany_from_any());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Func_any_from_any) {
          vx_core.Func_any_from_any anysub = valsub as vx_core.Func_any_from_any;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_any_from_anylist) {
          Type_any_from_anylist multi = (Type_any_from_anylist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listany_from_any());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Func_any_from_any) {
              vx_core.Func_any_from_any valitem = (vx_core.Func_any_from_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/any<-anylist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/any<-anylist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_any_from_anylist work = new Class_any_from_anylist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_anylist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_anylist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "any<-anylist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_any_from_anylist e_any_from_anylist = new Class_any_from_anylist();
  public static Type_any_from_anylist t_any_from_anylist = new Class_any_from_anylist();

  /**
   * type: anylist
   * A list of any
   * (type anylist)
   */
  public interface Type_anylist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_anylist : vx_core.Class_base, Type_anylist {

    protected List<vx_core.Type_any> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_any>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_anylist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public override vx_core.Type_anylist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_anylist,
       vals);
    }

    public override vx_core.Type_anylist vx_copy(params Object[] vals) {
      Type_anylist output = this;
      boolean ischanged = false;
      Class_anylist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_any> listval = new ArrayList<>(val.vx_list());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_any) {
          ischanged = true;
          listval.add((vx_core.Type_any)valsub);
        } else if (valsub is vx_core.Type_anylist) {
          Type_anylist multi = (Type_anylist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_any) {
              vx_core.Type_any valitem = (vx_core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/anylist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/anylist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_anylist work = new Class_anylist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_anylist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_anylist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "anylist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_anylist e_anylist = new Class_anylist();
  public static Type_anylist t_anylist = new Class_anylist();

  /**
   * type: anymap
   * A map of any
   * (type anymap)
   */
  public interface Type_anymap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_anymap : vx_core.Class_base, Type_anymap {

    protected Map<String, vx_core.Type_any> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_any) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_any castval = (vx_core.Type_any)value;
        Map<String, vx_core.Type_any> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_anymap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_any);
      return output;
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_anymap output = new vx_core.Class_anymap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_any) {
          vx_core.Type_any castval = (vx_core.Type_any)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/anymap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_anymap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_anymap,
       vals);
    }

    public override vx_core.Type_anymap vx_copy(params Object[] vals) {
      Type_anymap output = this;
      boolean ischanged = false;
      Class_anymap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_any> mapval = new LinkedHashMap<>(val.vx_map());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/anymap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_any valany = null;
          if (valsub is vx_core.Type_any) {
            valany = (vx_core.Type_any)valsub;
          } else if (valsub is vx_core.Type_any) {
            valany = valsub as vx_core.Type_any;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/anymap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_anymap work = new Class_anymap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_anymap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_anymap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "anymap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_anymap e_anymap = new Class_anymap();
  public static Type_anymap t_anymap = new Class_anymap();

  /**
   * type: anytype
   * Any Type that allows any Type as a Value
   * (type anytype)
   */
  public interface Type_anytype : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_anytype : vx_core.Class_base, Type_anytype {

    public override vx_core.Type_anytype vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_anytype,
       vals);
    }

    public override vx_core.Type_anytype vx_copy(params Object[] vals) {
      Type_anytype output = this;
      boolean ischanged = false;
      Class_anytype val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_anytype work = new Class_anytype();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_anytype;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_anytype;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "anytype", // name
        ":type", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_anytype e_anytype = new Class_anytype();
  public static Type_anytype t_anytype = new Class_anytype();

  /**
   * type: arg
   * A function argument
   * (type arg)
   */
  public interface Type_arg : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string name();
    public vx_core.Type_any argtype();
    public vx_core.Func_any_from_func fn_any();
    public vx_core.Type_string doc();
  }

  public class Class_arg : vx_core.Class_base, Type_arg {

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_any vx_p_argtype;

    public vx_core.Type_any argtype() {
      return this.vx_p_argtype == null ? vx_core.e_any : this.vx_p_argtype;
    }

    protected vx_core.Func_any_from_func vx_p_fn_any;

    public vx_core.Func_any_from_func fn_any() {
      return this.vx_p_fn_any == null ? vx_core.e_any_from_func : this.vx_p_fn_any;
    }

    protected vx_core.Type_string vx_p_doc;

    public vx_core.Type_string doc() {
      return this.vx_p_doc == null ? vx_core.e_string : this.vx_p_doc;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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
      case ":doc":
        output = this.doc();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":argtype", this.argtype());
      output.put(":fn-any", this.fn_any());
      output.put(":doc", this.doc());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_arg vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_arg,
       vals);
    }

    public override vx_core.Type_arg vx_copy(params Object[] vals) {
      Type_arg output = this;
      boolean ischanged = false;
      Class_arg val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_any vx_p_argtype = val.argtype();
      vx_core.Func_any_from_func vx_p_fn_any = val.fn_any();
      vx_core.Type_string vx_p_doc = val.doc();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":argtype");
      validkeys.add(":fn-any");
      validkeys.add(":doc");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":argtype":
            if (valsub == vx_p_argtype) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_argtype = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("argtype"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub is vx_core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (vx_core.Func_any_from_func)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("fn-any"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":doc":
            if (valsub == vx_p_doc) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_doc = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_doc = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("doc"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/arg", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_arg work = new Class_arg();
        work.vx_p_name = vx_p_name;
        work.vx_p_argtype = vx_p_argtype;
        work.vx_p_fn_any = vx_p_fn_any;
        work.vx_p_doc = vx_p_doc;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_arg;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_arg;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "arg", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_arg e_arg = new Class_arg();
  public static Type_arg t_arg = new Class_arg();

  /**
   * type: arglist
   * A list of arg
   * (type arglist)
   */
  public interface Type_arglist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_arg> vx_listarg();
    public vx_core.Type_arg vx_arg(vx_core.Type_int index);
  }

  public class Class_arglist : vx_core.Class_base, Type_arglist {

    protected List<vx_core.Type_arg> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_arg>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_arg vx_arg(vx_core.Type_int index) {
      vx_core.Type_arg output = vx_core.e_arg;
      vx_core.Class_arglist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_arg> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_arg> vx_listarg() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_arg(index);
    }

    public override vx_core.Type_arglist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_arglist,
       vals);
    }

    public override vx_core.Type_arglist vx_copy(params Object[] vals) {
      Type_arglist output = this;
      boolean ischanged = false;
      Class_arglist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_arg> listval = new ArrayList<>(val.vx_listarg());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_arg) {
          vx_core.Type_arg anysub = valsub as vx_core.Type_arg;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_arg) {
          ischanged = true;
          listval.add((vx_core.Type_arg)valsub);
        } else if (valsub is vx_core.Type_arglist) {
          Type_arglist multi = (Type_arglist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listarg());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_arg) {
              vx_core.Type_arg valitem = (vx_core.Type_arg)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/arglist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/arglist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_arglist work = new Class_arglist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_arglist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_arglist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "arglist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_arg), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_arglist e_arglist = new Class_arglist();
  public static Type_arglist t_arglist = new Class_arglist();

  /**
   * type: argmap
   * A map of arg
   * (type argmap)
   */
  public interface Type_argmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_arg> vx_maparg();
    public vx_core.Type_arg vx_arg(vx_core.Type_string key);
  }

  public class Class_argmap : vx_core.Class_base, Type_argmap {

    protected Map<String, vx_core.Type_arg> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_arg>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_arg) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_arg castval = (vx_core.Type_arg)value;
        Map<String, vx_core.Type_arg> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_arg) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_arg vx_arg(vx_core.Type_string key) {
      vx_core.Type_arg output = vx_core.e_arg;
      vx_core.Class_argmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_arg> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_arg);
      return output;
    }

    public Map<String, vx_core.Type_arg> vx_maparg() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_arg(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_argmap output = new vx_core.Class_argmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_arg> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_arg) {
          vx_core.Type_arg castval = (vx_core.Type_arg)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/argmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_argmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_argmap,
       vals);
    }

    public override vx_core.Type_argmap vx_copy(params Object[] vals) {
      Type_argmap output = this;
      boolean ischanged = false;
      Class_argmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_arg> mapval = new LinkedHashMap<>(val.vx_maparg());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/argmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_arg valany = null;
          if (valsub is vx_core.Type_arg) {
            valany = (vx_core.Type_arg)valsub;
          } else if (valsub is vx_core.Type_arg) {
            valany = valsub as vx_core.Type_arg;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/argmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_argmap work = new Class_argmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_argmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_argmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_arg), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_argmap e_argmap = new Class_argmap();
  public static Type_argmap t_argmap = new Class_argmap();

  /**
   * type: boolean
   * Standard Boolean Type
   * (type boolean)
   */
  public interface Type_boolean : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_boolean : vx_core.Class_base, Type_boolean {

    public override vx_core.Type_boolean vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_boolean,
       vals);
    }

    public override vx_core.Type_boolean vx_copy(params Object[] vals) {
      Type_boolean output = this;
      boolean ischanged = false;
      Class_boolean val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      boolean booleanval = val.vx_boolean();
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_boolean) {
          vx_core.Type_boolean valboolean = valsub as vx_core.Type_boolean;
          booleanval = booleanval || valboolean.vx_boolean();
        } else if (valsub is bool) {
          booleanval = booleanval || valsub as bool;
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_boolean work = new Class_boolean();
        work.vxboolean = booleanval;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      } else if (booleanval) {
        output = vx_core.c_true;
      } else {
        output = vx_core.c_false;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_boolean t_boolean = new Class_boolean();

  /**
   * type: booleanlist
   * (type booleanlist)
   */
  public interface Type_booleanlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_boolean> vx_listboolean();
    public vx_core.Type_boolean vx_boolean(vx_core.Type_int index);
  }

  public class Class_booleanlist : vx_core.Class_base, Type_booleanlist {

    protected List<vx_core.Type_boolean> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_boolean>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_boolean vx_boolean(vx_core.Type_int index) {
      vx_core.Type_boolean output = vx_core.e_boolean;
      vx_core.Class_booleanlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_boolean> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_boolean> vx_listboolean() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_boolean(index);
    }

    public override vx_core.Type_booleanlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_booleanlist,
       vals);
    }

    public override vx_core.Type_booleanlist vx_copy(params Object[] vals) {
      Type_booleanlist output = this;
      boolean ischanged = false;
      Class_booleanlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_boolean> listval = new ArrayList<>(val.vx_listboolean());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_boolean) {
          vx_core.Type_boolean anysub = valsub as vx_core.Type_boolean;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is Boolean) {
          ischanged = true;
          listval.add(vx_core.vx_new(vx_core.t_boolean, valsub));
        } else if (valsub is vx_core.Type_booleanlist) {
          Type_booleanlist multi = (Type_booleanlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listboolean());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_boolean) {
              vx_core.Type_boolean valitem = (vx_core.Type_boolean)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/booleanlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/booleanlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_booleanlist work = new Class_booleanlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_booleanlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_booleanlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "booleanlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_boolean), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_booleanlist e_booleanlist = new Class_booleanlist();
  public static Type_booleanlist t_booleanlist = new Class_booleanlist();

  /**
   * type: collection
   * (type collection)
   */
  public interface Type_collection : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_collection : vx_core.Class_base, Type_collection {

    public override vx_core.Type_collection vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_collection,
       vals);
    }

    public override vx_core.Type_collection vx_copy(params Object[] vals) {
      Type_collection output = this;
      boolean ischanged = false;
      Class_collection val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_collection work = new Class_collection();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_collection;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_collection;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "collection", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_list, vx_core.t_map), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_collection e_collection = new Class_collection();
  public static Type_collection t_collection = new Class_collection();

  /**
   * type: compilelanguages
   * (type compilelanguages)
   */
  public interface Type_compilelanguages : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_compilelanguages : vx_core.Class_base, Type_compilelanguages {

    public override vx_core.Type_compilelanguages vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_compilelanguages,
       vals);
    }

    public override vx_core.Type_compilelanguages vx_copy(params Object[] vals) {
      Type_compilelanguages output = this;
      boolean ischanged = false;
      Class_compilelanguages val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_compilelanguages work = new Class_compilelanguages();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_compilelanguages;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_compilelanguages;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "compilelanguages", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_compilelanguages e_compilelanguages = new Class_compilelanguages();
  public static Type_compilelanguages t_compilelanguages = new Class_compilelanguages();

  /**
   * type: connect
   * General connect trait
   * (type connect)
   */
  public interface Type_connect : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_connect : vx_core.Class_base, Type_connect {

    public override vx_core.Type_connect vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_connect,
       vals);
    }

    public override vx_core.Type_connect vx_copy(params Object[] vals) {
      Type_connect output = this;
      boolean ischanged = false;
      Class_connect val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_connect work = new Class_connect();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_connect;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_connect;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "connect", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_connect e_connect = new Class_connect();
  public static Type_connect t_connect = new Class_connect();

  /**
   * type: connectlist
   * List of connect
   * (type connectlist)
   */
  public interface Type_connectlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_connect> vx_listconnect();
    public vx_core.Type_connect vx_connect(vx_core.Type_int index);
  }

  public class Class_connectlist : vx_core.Class_base, Type_connectlist {

    protected List<vx_core.Type_connect> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_connect>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_connect vx_connect(vx_core.Type_int index) {
      vx_core.Type_connect output = vx_core.e_connect;
      vx_core.Class_connectlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_connect> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_connect> vx_listconnect() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_connect(index);
    }

    public override vx_core.Type_connectlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_connectlist,
       vals);
    }

    public override vx_core.Type_connectlist vx_copy(params Object[] vals) {
      Type_connectlist output = this;
      boolean ischanged = false;
      Class_connectlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_connect> listval = new ArrayList<>(val.vx_listconnect());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_connect) {
          vx_core.Type_connect anysub = valsub as vx_core.Type_connect;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_connect) {
          ischanged = true;
          listval.add((vx_core.Type_connect)valsub);
        } else if (valsub is vx_core.Type_connectlist) {
          Type_connectlist multi = (Type_connectlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listconnect());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_connect) {
              vx_core.Type_connect valitem = (vx_core.Type_connect)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/connectlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/connectlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_connectlist work = new Class_connectlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_connectlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_connectlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "connectlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_connect), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_connectlist e_connectlist = new Class_connectlist();
  public static Type_connectlist t_connectlist = new Class_connectlist();

  /**
   * type: connectmap
   * Map of connect
   * (type connectmap)
   */
  public interface Type_connectmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_connect> vx_mapconnect();
    public vx_core.Type_connect vx_connect(vx_core.Type_string key);
  }

  public class Class_connectmap : vx_core.Class_base, Type_connectmap {

    protected Map<String, vx_core.Type_connect> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_connect>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_connect) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_connect castval = (vx_core.Type_connect)value;
        Map<String, vx_core.Type_connect> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_connect) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_connect vx_connect(vx_core.Type_string key) {
      vx_core.Type_connect output = vx_core.e_connect;
      vx_core.Class_connectmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_connect> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_connect);
      return output;
    }

    public Map<String, vx_core.Type_connect> vx_mapconnect() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_connect(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_connectmap output = new vx_core.Class_connectmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_connect> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_connect) {
          vx_core.Type_connect castval = (vx_core.Type_connect)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/connectmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_connectmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_connectmap,
       vals);
    }

    public override vx_core.Type_connectmap vx_copy(params Object[] vals) {
      Type_connectmap output = this;
      boolean ischanged = false;
      Class_connectmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_connect> mapval = new LinkedHashMap<>(val.vx_mapconnect());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/connectmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_connect valany = null;
          if (valsub is vx_core.Type_connect) {
            valany = (vx_core.Type_connect)valsub;
          } else if (valsub is vx_core.Type_connect) {
            valany = valsub as vx_core.Type_connect;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/connectmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_connectmap work = new Class_connectmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_connectmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_connectmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "connectmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_connect), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_connectmap e_connectmap = new Class_connectmap();
  public static Type_connectmap t_connectmap = new Class_connectmap();

  /**
   * type: const
   * Original Constant Class.
   * (type const)
   */
  public interface Type_const : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_const : vx_core.Class_base, Type_const {

    public override vx_core.Type_const vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_const,
       vals);
    }

    public override vx_core.Type_const vx_copy(params Object[] vals) {
      Type_const output = this;
      boolean ischanged = false;
      Class_const val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_const work = new Class_const();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_const;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_const;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "const", // name
        ":const", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_const e_const = new Class_const();
  public static Type_const t_const = new Class_const();

  /**
   * type: constdef
   * Const Definition Class for inspecting properties.
   * (type constdef)
   */
  public interface Type_constdef : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string pkgname();
    public vx_core.Type_string name();
    public vx_core.Type_any type();
  }

  public class Class_constdef : vx_core.Class_base, Type_constdef {

    protected vx_core.Type_string vx_p_pkgname;

    public vx_core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? vx_core.e_string : this.vx_p_pkgname;
    }

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_any vx_p_type;

    public vx_core.Type_any type() {
      return this.vx_p_type == null ? vx_core.e_any : this.vx_p_type;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":type", this.type());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_constdef vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_constdef,
       vals);
    }

    public override vx_core.Type_constdef vx_copy(params Object[] vals) {
      Type_constdef output = this;
      boolean ischanged = false;
      Class_constdef val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_pkgname = val.pkgname();
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_any vx_p_type = val.type();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":name");
      validkeys.add(":type");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_pkgname = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_type = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("type"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/constdef", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_constdef work = new Class_constdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_constdef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_constdef;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "constdef", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_constdef e_constdef = new Class_constdef();
  public static Type_constdef t_constdef = new Class_constdef();

  /**
   * type: constlist
   * List of Const.
   * (type constlist)
   */
  public interface Type_constlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_constlist : vx_core.Class_base, Type_constlist {

    protected List<vx_core.Type_any> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_any>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_constlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public override vx_core.Type_constlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_constlist,
       vals);
    }

    public override vx_core.Type_constlist vx_copy(params Object[] vals) {
      Type_constlist output = this;
      boolean ischanged = false;
      Class_constlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_any> listval = new ArrayList<>(val.vx_list());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_any) {
          ischanged = true;
          listval.add((vx_core.Type_any)valsub);
        } else if (valsub is vx_core.Type_constlist) {
          Type_constlist multi = (Type_constlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_any) {
              vx_core.Type_any valitem = (vx_core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/constlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/constlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_constlist work = new Class_constlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_constlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_constlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "constlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_constlist e_constlist = new Class_constlist();
  public static Type_constlist t_constlist = new Class_constlist();

  /**
   * type: constmap
   * Map of Const.
   * (type constmap)
   */
  public interface Type_constmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_constmap : vx_core.Class_base, Type_constmap {

    protected Map<String, vx_core.Type_any> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_any) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_any castval = (vx_core.Type_any)value;
        Map<String, vx_core.Type_any> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_constmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_any);
      return output;
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_constmap output = new vx_core.Class_constmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_any) {
          vx_core.Type_any castval = (vx_core.Type_any)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/constmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_constmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_constmap,
       vals);
    }

    public override vx_core.Type_constmap vx_copy(params Object[] vals) {
      Type_constmap output = this;
      boolean ischanged = false;
      Class_constmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_any> mapval = new LinkedHashMap<>(val.vx_map());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/constmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_any valany = null;
          if (valsub is vx_core.Type_any) {
            valany = (vx_core.Type_any)valsub;
          } else if (valsub is vx_core.Type_any) {
            valany = valsub as vx_core.Type_any;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/constmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_constmap work = new Class_constmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_constmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_constmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "constmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_constmap e_constmap = new Class_constmap();
  public static Type_constmap t_constmap = new Class_constmap();

  /**
   * type: context
   * Context
   * (type context)
   */
  public interface Type_context : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string code();
    public vx_core.Type_session session();
    public vx_core.Type_setting setting();
    public vx_core.Type_state state();
  }

  public class Class_context : vx_core.Class_base, Type_context {

    protected vx_core.Type_string vx_p_code;

    public vx_core.Type_string code() {
      return this.vx_p_code == null ? vx_core.e_string : this.vx_p_code;
    }

    protected vx_core.Type_session vx_p_session;

    public vx_core.Type_session session() {
      return this.vx_p_session == null ? vx_core.e_session : this.vx_p_session;
    }

    protected vx_core.Type_setting vx_p_setting;

    public vx_core.Type_setting setting() {
      return this.vx_p_setting == null ? vx_core.e_setting : this.vx_p_setting;
    }

    protected vx_core.Type_state vx_p_state;

    public vx_core.Type_state state() {
      return this.vx_p_state == null ? vx_core.e_state : this.vx_p_state;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":session", this.session());
      output.put(":setting", this.setting());
      output.put(":state", this.state());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_context vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_context,
       vals);
    }

    public override vx_core.Type_context vx_copy(params Object[] vals) {
      Type_context output = this;
      boolean ischanged = false;
      Class_context val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_code = val.code();
      vx_core.Type_session vx_p_session = val.session();
      vx_core.Type_setting vx_p_setting = val.setting();
      vx_core.Type_state vx_p_state = val.state();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":session");
      validkeys.add(":setting");
      validkeys.add(":state");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_code = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_code = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("code"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":session":
            if (valsub == vx_p_session) {
            } else if (valsub is vx_core.Type_session) {
              ischanged = true;
              vx_p_session = (vx_core.Type_session)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("session"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":setting":
            if (valsub == vx_p_setting) {
            } else if (valsub is vx_core.Type_setting) {
              ischanged = true;
              vx_p_setting = (vx_core.Type_setting)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("setting"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":state":
            if (valsub == vx_p_state) {
            } else if (valsub is vx_core.Type_state) {
              ischanged = true;
              vx_p_state = (vx_core.Type_state)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("state"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/context", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_context work = new Class_context();
        work.vx_p_code = vx_p_code;
        work.vx_p_session = vx_p_session;
        work.vx_p_setting = vx_p_setting;
        work.vx_p_state = vx_p_state;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_context;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "context", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_context e_context = new Class_context();
  public static Type_context t_context = new Class_context();

  /**
   * type: date
   * A simple UTC date.
   * (type date)
   */
  public interface Type_date : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_date : vx_core.Class_base, Type_date {

    public override vx_core.Type_date vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_date,
       vals);
    }

    public override vx_core.Type_date vx_copy(params Object[] vals) {
      Type_date output = this;
      boolean ischanged = false;
      Class_date val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_date work = new Class_date();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_date;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_date;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "date", // name
        ":string", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_date e_date = new Class_date();
  public static Type_date t_date = new Class_date();

  /**
   * type: decimal
   * A clean version of float like Java BigDecimal.
   * (type decimal)
   */
  public interface Type_decimal : vx_core.Type_number {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_decimal : vx_core.Class_base, Type_decimal {

    public override vx_core.Type_decimal vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_decimal,
       vals);
    }

    public override vx_core.Type_decimal vx_copy(params Object[] vals) {
      Type_decimal output = this;
      boolean ischanged = false;
      Class_decimal val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      String sval = val.vx_string();
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_string) {
          vx_core.Type_string valstring = valsub as vx_core.Type_string;
          ischanged = true;
          sval = valstring.vx_string();
        } else if (valsub is String) {
          ischanged = true;
          sval = (String)valsub;
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_decimal work = new Class_decimal();
        work.vxdecimal = sval;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_decimal;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_decimal;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "decimal", // name
        "", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_decimal e_decimal = new Class_decimal();
  public static Type_decimal t_decimal = new Class_decimal();

  /**
   * type: error
   * Error Type
   * (type error)
   */
  public interface Type_error : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_error : vx_core.Class_base, Type_error {

    public override vx_core.Type_error vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_error,
       vals);
    }

    public override vx_core.Type_error vx_copy(params Object[] vals) {
      Type_error output = this;
      boolean ischanged = false;
      Class_error val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_error work = new Class_error();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_error;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_error;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "error", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_error e_error = new Class_error();
  public static Type_error t_error = new Class_error();

  /**
   * type: float
   * Standard Floating Point Number
   * (type float)
   */
  public interface Type_float : vx_core.Type_number {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_float : vx_core.Class_base, Type_float {

    public override vx_core.Type_float vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_float,
       vals);
    }

    public override vx_core.Type_float vx_copy(params Object[] vals) {
      Type_float output = this;
      boolean ischanged = false;
      Class_float val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      float floatval = val.vx_float();
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_decimal) {
          vx_core.Type_decimal valnum = valsub as vx_core.Type_decimal;
          ischanged = true;
          floatval += valnum.vx_float();
        } else if (valsub is vx_core.Type_float) {
          vx_core.Type_float valnum = valsub as vx_core.Type_float;
          ischanged = true;
          floatval += valnum.vx_float();
        } else if (valsub is vx_core.Type_int) {
          vx_core.Type_int valnum = valsub as vx_core.Type_int;
          ischanged = true;
          floatval += valnum.vx_int();
        } else if (valsub is vx_core.Type_string) {
          vx_core.Type_string valstring = valsub as vx_core.Type_string;
          ischanged = true;
          floatval += Float.parseFloat(valstring.vx_string());
        } else if (valsub is Float) {
          ischanged = true;
          floatval += valsub as Float;
        } else if (valsub is Integer) {
          ischanged = true;
          floatval += valsub as Integer;
        } else if (valsub is String) {
          ischanged = true;
          floatval += Float.parseFloat(valsub as String);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_float work = new Class_float();
        work.vxfloat = floatval;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_float;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_float;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "float", // name
        "", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_float e_float = new Class_float();
  public static Type_float t_float = new Class_float();

  /**
   * type: func
   * Original Function Class.
   * (type func)
   */
  public interface Type_func : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
	   public vx_core.Type_funcdef vx_funcdef();
  }

  public class Class_func : vx_core.Class_base, Type_func {

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.e_funcdef;
    }
    public override vx_core.Type_func vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_func,
       vals);
    }

    public override vx_core.Type_func vx_copy(params Object[] vals) {
      Type_func output = this;
      boolean ischanged = false;
      Class_func val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_func work = new Class_func();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_func;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "func", // name
        ":func", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_func e_func = new Class_func();
  public static Type_func t_func = new Class_func();

  /**
   * type: funcdef
   * Func Definition Class for inspecting properties.
   * (type funcdef)
   */
  public interface Type_funcdef : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string pkgname();
    public vx_core.Type_string name();
    public vx_core.Type_int idx();
    public vx_core.Type_any type();
    public vx_core.Type_boolean async();
  }

  public class Class_funcdef : vx_core.Class_base, Type_funcdef {

    protected vx_core.Type_string vx_p_pkgname;

    public vx_core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? vx_core.e_string : this.vx_p_pkgname;
    }

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_int vx_p_idx;

    public vx_core.Type_int idx() {
      return this.vx_p_idx == null ? vx_core.e_int : this.vx_p_idx;
    }

    protected vx_core.Type_any vx_p_type;

    public vx_core.Type_any type() {
      return this.vx_p_type == null ? vx_core.e_any : this.vx_p_type;
    }

    protected vx_core.Type_boolean vx_p_async;

    public vx_core.Type_boolean async() {
      return this.vx_p_async == null ? vx_core.e_boolean : this.vx_p_async;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":idx", this.idx());
      output.put(":type", this.type());
      output.put(":async", this.async());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_funcdef vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_funcdef,
       vals);
    }

    public override vx_core.Type_funcdef vx_copy(params Object[] vals) {
      Type_funcdef output = this;
      boolean ischanged = false;
      Class_funcdef val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_pkgname = val.pkgname();
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_int vx_p_idx = val.idx();
      vx_core.Type_any vx_p_type = val.type();
      vx_core.Type_boolean vx_p_async = val.async();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":name");
      validkeys.add(":idx");
      validkeys.add(":type");
      validkeys.add(":async");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_pkgname = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":idx":
            if (valsub == vx_p_idx) {
            } else if (valsub is vx_core.Type_int) {
              ischanged = true;
              vx_p_idx = (vx_core.Type_int)valsub;
            } else if (valsub is Integer) {
              ischanged = true;
              vx_p_idx = vx_core.vx_new(vx_core.t_int, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("idx"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_type = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("type"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub is vx_core.Type_boolean) {
              ischanged = true;
              vx_p_async = (vx_core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_async = vx_core.vx_new(vx_core.t_boolean, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("async"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/funcdef", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_funcdef work = new Class_funcdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_idx = vx_p_idx;
        work.vx_p_type = vx_p_type;
        work.vx_p_async = vx_p_async;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_funcdef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_funcdef;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_funcdef e_funcdef = new Class_funcdef();
  public static Type_funcdef t_funcdef = new Class_funcdef();

  /**
   * type: funclist
   * List of Func.
   * (type funclist)
   */
  public interface Type_funclist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_func> vx_listfunc();
    public vx_core.Type_func vx_func(vx_core.Type_int index);
  }

  public class Class_funclist : vx_core.Class_base, Type_funclist {

    protected List<vx_core.Type_func> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_func>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_func vx_func(vx_core.Type_int index) {
      vx_core.Type_func output = vx_core.e_func;
      vx_core.Class_funclist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_func> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_func> vx_listfunc() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_func(index);
    }

    public override vx_core.Type_funclist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_funclist,
       vals);
    }

    public override vx_core.Type_funclist vx_copy(params Object[] vals) {
      Type_funclist output = this;
      boolean ischanged = false;
      Class_funclist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_func> listval = new ArrayList<>(val.vx_listfunc());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_func) {
          vx_core.Type_func anysub = valsub as vx_core.Type_func;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_func) {
          ischanged = true;
          listval.add((vx_core.Type_func)valsub);
        } else if (valsub is vx_core.Type_funclist) {
          Type_funclist multi = (Type_funclist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfunc());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_func) {
              vx_core.Type_func valitem = (vx_core.Type_func)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/funclist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/funclist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_funclist work = new Class_funclist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_funclist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_funclist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "funclist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_func), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_funclist e_funclist = new Class_funclist();
  public static Type_funclist t_funclist = new Class_funclist();

  /**
   * type: funcmap
   * Map of Func.
   * (type funcmap)
   */
  public interface Type_funcmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_func> vx_mapfunc();
    public vx_core.Type_func vx_func(vx_core.Type_string key);
  }

  public class Class_funcmap : vx_core.Class_base, Type_funcmap {

    protected Map<String, vx_core.Type_func> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_func>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_func) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_func castval = (vx_core.Type_func)value;
        Map<String, vx_core.Type_func> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_func) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_func vx_func(vx_core.Type_string key) {
      vx_core.Type_func output = vx_core.e_func;
      vx_core.Class_funcmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_func> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_func);
      return output;
    }

    public Map<String, vx_core.Type_func> vx_mapfunc() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_func(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_funcmap output = new vx_core.Class_funcmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_func> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_func) {
          vx_core.Type_func castval = (vx_core.Type_func)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/funcmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_funcmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_funcmap,
       vals);
    }

    public override vx_core.Type_funcmap vx_copy(params Object[] vals) {
      Type_funcmap output = this;
      boolean ischanged = false;
      Class_funcmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_func> mapval = new LinkedHashMap<>(val.vx_mapfunc());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/funcmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_func valany = null;
          if (valsub is vx_core.Type_func) {
            valany = (vx_core.Type_func)valsub;
          } else if (valsub is vx_core.Type_func) {
            valany = valsub as vx_core.Type_func;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/funcmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_funcmap work = new Class_funcmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_funcmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_funcmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "funcmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_func), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_funcmap e_funcmap = new Class_funcmap();
  public static Type_funcmap t_funcmap = new Class_funcmap();

  /**
   * type: int
   * A simple integer.
   * (type int)
   */
  public interface Type_int : vx_core.Type_number {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_int : vx_core.Class_base, Type_int {

    public override vx_core.Type_int vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_int,
       vals);
    }

    public override vx_core.Type_int vx_copy(params Object[] vals) {
      Type_int output = this;
      boolean ischanged = false;
      Class_int val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      int intval = val.vx_int();
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_int) {
          vx_core.Type_int valnum = valsub as vx_core.Type_int;
          ischanged = true;
          intval += valnum.vx_int();
        } else if (valsub is Integer) {
          ischanged = true;
          intval += valsub as Integer;
        } else if (valsub is String) {
          String valstring = valsub as String;
          ischanged = true;
          intval += Integer.parseInt(valstring);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_int work = new Class_int();
        work.vxint = intval;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_int;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_int;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_int e_int = new Class_int();
  public static Type_int t_int = new Class_int();

  /**
   * type: intlist
   * A list of int.
   * (type intlist)
   */
  public interface Type_intlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_int> vx_listint();
    public vx_core.Type_int vx_int(vx_core.Type_int index);
  }

  public class Class_intlist : vx_core.Class_base, Type_intlist {

    protected List<vx_core.Type_int> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_int>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_int vx_int(vx_core.Type_int index) {
      vx_core.Type_int output = vx_core.e_int;
      vx_core.Class_intlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_int> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_int> vx_listint() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_int(index);
    }

    public override vx_core.Type_intlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_intlist,
       vals);
    }

    public override vx_core.Type_intlist vx_copy(params Object[] vals) {
      Type_intlist output = this;
      boolean ischanged = false;
      Class_intlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_int> listval = new ArrayList<>(val.vx_listint());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_int) {
          vx_core.Type_int anysub = valsub as vx_core.Type_int;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is Integer) {
          ischanged = true;
          listval.add(vx_core.vx_new(vx_core.t_int, valsub));
        } else if (valsub is vx_core.Type_intlist) {
          Type_intlist multi = (Type_intlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listint());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_int) {
              vx_core.Type_int valitem = (vx_core.Type_int)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/intlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/intlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_intlist work = new Class_intlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_intlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_intlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "intlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_int), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_intlist e_intlist = new Class_intlist();
  public static Type_intlist t_intlist = new Class_intlist();

  /**
   * type: intmap
   * A map of int.
   * (type intmap)
   */
  public interface Type_intmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_int> vx_mapint();
    public vx_core.Type_int vx_int(vx_core.Type_string key);
  }

  public class Class_intmap : vx_core.Class_base, Type_intmap {

    protected Map<String, vx_core.Type_int> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_int>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_int) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_int castval = (vx_core.Type_int)value;
        Map<String, vx_core.Type_int> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_int) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_int vx_int(vx_core.Type_string key) {
      vx_core.Type_int output = vx_core.e_int;
      vx_core.Class_intmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_int> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_int);
      return output;
    }

    public Map<String, vx_core.Type_int> vx_mapint() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_int(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_intmap output = new vx_core.Class_intmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_int> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_int) {
          vx_core.Type_int castval = (vx_core.Type_int)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/intmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_intmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_intmap,
       vals);
    }

    public override vx_core.Type_intmap vx_copy(params Object[] vals) {
      Type_intmap output = this;
      boolean ischanged = false;
      Class_intmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_int> mapval = new LinkedHashMap<>(val.vx_mapint());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/intmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_int valany = null;
          if (valsub is vx_core.Type_int) {
            valany = (vx_core.Type_int)valsub;
          } else if (valsub is Integer) {
            valany = vx_core.vx_new(vx_core.t_int, valsub);
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/intmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_intmap work = new Class_intmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_intmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_intmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "intmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_int), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_intmap e_intmap = new Class_intmap();
  public static Type_intmap t_intmap = new Class_intmap();

  /**
   * type: list
   * A simple untyped list.
   * (type list)
   */
  public interface Type_list : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_any> vx_list();
    public vx_core.Type_any vx_any(vx_core.Type_int index);
  }

  public class Class_list : vx_core.Class_base, Type_list {

    protected List<vx_core.Type_any> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_any>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_list list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public override vx_core.Type_list vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_list,
       vals);
    }

    public override vx_core.Type_list vx_copy(params Object[] vals) {
      Type_list output = this;
      boolean ischanged = false;
      Class_list val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_any> listval = new ArrayList<>(val.vx_list());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_any) {
          ischanged = true;
          listval.add((vx_core.Type_any)valsub);
        } else if (valsub is vx_core.Type_list) {
          Type_list multi = (Type_list)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_any) {
              vx_core.Type_any valitem = (vx_core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/list", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/list", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_list work = new Class_list();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "list", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_list e_list = new Class_list();
  public static Type_list t_list = new Class_list();

  /**
   * type: listtype
   * A generic type that extends :list.
   * (type listtype)
   */
  public interface Type_listtype : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_listtype : vx_core.Class_base, Type_listtype {

    public override vx_core.Type_listtype vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_listtype,
       vals);
    }

    public override vx_core.Type_listtype vx_copy(params Object[] vals) {
      Type_listtype output = this;
      boolean ischanged = false;
      Class_listtype val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_listtype work = new Class_listtype();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_listtype;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_listtype;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "listtype", // name
        ":type", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_listtype e_listtype = new Class_listtype();
  public static Type_listtype t_listtype = new Class_listtype();

  /**
   * type: locale
   * Localization data.
   * (type locale)
   */
  public interface Type_locale : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_locale : vx_core.Class_base, Type_locale {

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_locale vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_locale,
       vals);
    }

    public override vx_core.Type_locale vx_copy(params Object[] vals) {
      Type_locale output = this;
      boolean ischanged = false;
      Class_locale val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_locale work = new Class_locale();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_locale;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_locale;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "locale", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_locale e_locale = new Class_locale();
  public static Type_locale t_locale = new Class_locale();

  /**
   * type: map
   * A simple untyped map.
   * (type map)
   */
  public interface Type_map : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval);
    public vx_core.Type_any vx_any(vx_core.Type_string key);
    public Map<String, vx_core.Type_any> vx_map();
    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value);
  }

  public class Class_map : vx_core.Class_base, Type_map {

    protected Map<String, vx_core.Type_any> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_any) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_any castval = (vx_core.Type_any)value;
        Map<String, vx_core.Type_any> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_map map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_any);
      return output;
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_map output = new vx_core.Class_map();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_any) {
          vx_core.Type_any castval = (vx_core.Type_any)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/map", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_map vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_map,
       vals);
    }

    public override vx_core.Type_map vx_copy(params Object[] vals) {
      Type_map output = this;
      boolean ischanged = false;
      Class_map val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_any> mapval = new LinkedHashMap<>(val.vx_map());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/map", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_any valany = null;
          if (valsub is vx_core.Type_any) {
            valany = (vx_core.Type_any)valsub;
          } else if (valsub is vx_core.Type_any) {
            valany = valsub as vx_core.Type_any;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/map", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_map work = new Class_map();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_map;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_map;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "map", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_map e_map = new Class_map();
  public static Type_map t_map = new Class_map();

  /**
   * type: maptype
   * A generic type that extends :map.
   * (type maptype)
   */
  public interface Type_maptype : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_maptype : vx_core.Class_base, Type_maptype {

    public override vx_core.Type_maptype vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_maptype,
       vals);
    }

    public override vx_core.Type_maptype vx_copy(params Object[] vals) {
      Type_maptype output = this;
      boolean ischanged = false;
      Class_maptype val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_maptype work = new Class_maptype();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_maptype;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_maptype;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "maptype", // name
        ":type", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_maptype e_maptype = new Class_maptype();
  public static Type_maptype t_maptype = new Class_maptype();

  /**
   * type: mempool
   * Memory Pool
   * (type mempool)
   */
  public interface Type_mempool : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_value valuepool();
  }

  public class Class_mempool : vx_core.Class_base, Type_mempool {

    protected vx_core.Type_value vx_p_valuepool;

    public vx_core.Type_value valuepool() {
      return this.vx_p_valuepool == null ? vx_core.e_value : this.vx_p_valuepool;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":valuepool":
        output = this.valuepool();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":valuepool", this.valuepool());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_mempool vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_mempool,
       vals);
    }

    public override vx_core.Type_mempool vx_copy(params Object[] vals) {
      Type_mempool output = this;
      boolean ischanged = false;
      Class_mempool val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_value vx_p_valuepool = val.valuepool();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":valuepool");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/mempool", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/mempool", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":valuepool":
            if (valsub == vx_p_valuepool) {
            } else if (valsub is vx_core.Type_value) {
              ischanged = true;
              vx_p_valuepool = (vx_core.Type_value)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("valuepool"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/mempool", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/mempool", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_mempool work = new Class_mempool();
        work.vx_p_valuepool = vx_p_valuepool;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_mempool;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_mempool;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "mempool", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_mempool e_mempool = new Class_mempool();
  public static Type_mempool t_mempool = new Class_mempool();

  /**
   * type: msg
   * Message Type for error handling
   * (type msg)
   */
  public interface Type_msg : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_typedef vx_typedef();
    public vx_core.Type_string code();
    public vx_core.Type_any detail();
    public vx_core.Type_string path();
    public vx_core.Type_int severity();
    public vx_core.Type_string text();
  }

  public class Class_msg : vx_core.Class_base, Type_msg {

    protected vx_core.Type_string vx_p_code;

    public vx_core.Type_string code() {
      return this.vx_p_code == null ? vx_core.e_string : this.vx_p_code;
    }

    protected vx_core.Type_any vx_p_detail;

    public vx_core.Type_any detail() {
      return this.vx_p_detail == null ? vx_core.e_any : this.vx_p_detail;
    }

    protected vx_core.Type_string vx_p_path;

    public vx_core.Type_string path() {
      return this.vx_p_path == null ? vx_core.e_string : this.vx_p_path;
    }

    protected vx_core.Type_int vx_p_severity;

    public vx_core.Type_int severity() {
      return this.vx_p_severity == null ? vx_core.e_int : this.vx_p_severity;
    }

    protected vx_core.Type_string vx_p_text;

    public vx_core.Type_string text() {
      return this.vx_p_text == null ? vx_core.e_string : this.vx_p_text;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":code":
        output = this.code();
        break;
      case ":detail":
        output = this.detail();
        break;
      case ":path":
        output = this.path();
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":detail", this.detail());
      output.put(":path", this.path());
      output.put(":severity", this.severity());
      output.put(":text", this.text());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_msg vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_msg,
       vals);
    }

    public override vx_core.Type_msg vx_copy(params Object[] vals) {
      Type_msg output = this;
      boolean ischanged = false;
      Class_msg val = this;
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_code = val.code();
      vx_core.Type_any vx_p_detail = val.detail();
      vx_core.Type_string vx_p_path = val.path();
      vx_core.Type_int vx_p_severity = val.severity();
      vx_core.Type_string vx_p_text = val.text();
      String key = "";
      foreach (Object valsub in vals) {
        if (key == "") {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            key = valstr.vx_string();
          } else if (valsub is String) {
            key = (String)valsub;
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_code = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_code = vx_core.vx_new(vx_core.t_string, valsub);
            }
            break;
          case ":detail":
            if (valsub == vx_p_detail) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_detail = (vx_core.Type_any)valsub;
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_path = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_path = vx_core.vx_new(vx_core.t_string, valsub);
            }
            break;
          case ":severity":
            if (valsub == vx_p_severity) {
            } else if (valsub is vx_core.Type_int) {
              ischanged = true;
              vx_p_severity = (vx_core.Type_int)valsub;
            } else if (valsub is Integer) {
              ischanged = true;
              vx_p_severity = vx_core.vx_new(vx_core.t_int, valsub);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_text = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub);
            }
            break;
          }
          key = "";
        }
      }
      if (ischanged) {
        Class_msg work = new Class_msg();
        work.vx_p_code = vx_p_code;
        work.vx_p_detail = vx_p_detail;
        work.vx_p_path = vx_p_path;
        work.vx_p_severity = vx_p_severity;
        work.vx_p_text = vx_p_text;
        output = work;
      }
      return output;
    }
    
    public vx_core.Type_msgblock vx_msgblock() {
      return vx_core.e_msgblock;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msg;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msg;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "msg", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_msg e_msg = new Class_msg();
  public static Type_msg t_msg = new Class_msg();

  /**
   * type: msgblock
   * Block of Messages
   * (type msgblock)
   */
  public interface Type_msgblock : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_typedef vx_typedef();
    public vx_core.Type_msglist msgs();
    public vx_core.Type_msgblocklist msgblocks();
  }

  public class Class_msgblock : vx_core.Class_base, Type_msgblock {

    protected vx_core.Type_msglist vx_p_msgs;

    public vx_core.Type_msglist msgs() {
      return this.vx_p_msgs == null ? vx_core.e_msglist : this.vx_p_msgs;
    }

    protected vx_core.Type_msgblocklist vx_p_msgblocks;

    public vx_core.Type_msgblocklist msgblocks() {
      return this.vx_p_msgblocks == null ? vx_core.e_msgblocklist : this.vx_p_msgblocks;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":msgs", this.msgs());
      output.put(":msgblocks", this.msgblocks());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_msgblock vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_msgblock,
       vals);
    }

    public override vx_core.Type_msgblock vx_copy(params Object[] vals) {
      Type_msgblock output = this;
      boolean ischanged = false;
      Class_msgblock val = this;
      vx_core.Type_msgblock msgblock = this;
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_msglist vx_p_msgs = val.msgs();
      vx_core.Type_msgblocklist vx_p_msgblocks = val.msgblocks();
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          if (valsub != vx_core.e_msgblock) {
            vx_p_msgblocks = vx_core.vx_copy(vx_p_msgblocks, valsub);
            ischanged = true;
          }
        } else if (valsub is vx_core.Type_msgblocklist) {
          if (valsub != vx_core.e_msgblocklist) {
            vx_p_msgblocks = vx_core.vx_copy(vx_p_msgblocks, valsub);
            ischanged = true;
          }
        } else if (valsub is vx_core.Type_msg) {
          if (valsub != vx_core.e_msg) {
            vx_p_msgs = vx_core.vx_copy(vx_p_msgs, valsub);
            ischanged = true;
          }
        } else if (valsub is vx_core.Type_msglist) {
          if (valsub != vx_core.e_msglist) {
            vx_p_msgs = vx_core.vx_copy(vx_p_msgs, valsub);
            ischanged = true;
          }
        } else if (key == "") {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            key = valstr.vx_string();
          } else if (valsub is String) {
            key = (String)valsub;
          }
        } else {
          switch (key) {
          case ":msgs":
            if (valsub == vx_p_msgs) {
            } else if (valsub is vx_core.Type_msglist) {
              ischanged = true;
              vx_p_msgs = (vx_core.Type_msglist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("msgs"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/msgblock", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":msgblocks":
            if (valsub == vx_p_msgblocks) {
            } else if (valsub is vx_core.Type_msgblocklist) {
              ischanged = true;
              vx_p_msgblocks = (vx_core.Type_msgblocklist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("msgblocks"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/msgblock", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          }
          key = "";
        }
      }
      if (ischanged) {
        if ((vx_p_msgs.vx_list().size() == 0) && (vx_p_msgblocks.vx_list().size() == 1)) {
          output = vx_p_msgblocks.vx_listmsgblock().get(0);
        } else {
          Class_msgblock work = new Class_msgblock();
          work.vx_p_msgs = vx_p_msgs;
          work.vx_p_msgblocks = vx_p_msgblocks;
          output = work;
        }
      }
      return output;
    }
    
    public vx_core.Type_msgblock vx_msgblock() {
      return this;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msgblock;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msgblock;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_msgblock e_msgblock = new Class_msgblock();
  public static Type_msgblock t_msgblock = new Class_msgblock();

  /**
   * type: msgblocklist
   * List of Message Blocks
   * (type msgblocklist)
   */
  public interface Type_msgblocklist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_msgblock> vx_listmsgblock();
    public vx_core.Type_msgblock vx_msgblock(vx_core.Type_int index);
  }

  public class Class_msgblocklist : vx_core.Class_base, Type_msgblocklist {

    protected List<vx_core.Type_msgblock> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_msgblock>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_msgblock vx_msgblock(vx_core.Type_int index) {
      vx_core.Type_msgblock output = vx_core.e_msgblock;
      vx_core.Class_msgblocklist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_msgblock> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_msgblock> vx_listmsgblock() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_msgblock(index);
    }

    public override vx_core.Type_msgblocklist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_msgblocklist,
       vals);
    }

    public override vx_core.Type_msgblocklist vx_copy(params Object[] vals) {
      Type_msgblocklist output = this;
      boolean ischanged = false;
      Class_msgblocklist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_msgblock> listval = new ArrayList<>(val.vx_listmsgblock());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msgblock) {
          ischanged = true;
          listval.add((vx_core.Type_msgblock)valsub);
        } else if (valsub is vx_core.Type_msgblocklist) {
          Type_msgblocklist multi = (Type_msgblocklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listmsgblock());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_msgblock) {
              vx_core.Type_msgblock valitem = (vx_core.Type_msgblock)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/msgblocklist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/msgblocklist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_msgblocklist work = new Class_msgblocklist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msgblocklist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msgblocklist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "msgblocklist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_msgblock), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_msgblocklist e_msgblocklist = new Class_msgblocklist();
  public static Type_msgblocklist t_msgblocklist = new Class_msgblocklist();

  /**
   * type: msglist
   * List of Messages
   * (type msglist)
   */
  public interface Type_msglist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_msg> vx_listmsg();
    public vx_core.Type_msg vx_msg(vx_core.Type_int index);
  }

  public class Class_msglist : vx_core.Class_base, Type_msglist {

    protected List<vx_core.Type_msg> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_msg>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_msg vx_msg(vx_core.Type_int index) {
      vx_core.Type_msg output = vx_core.e_msg;
      vx_core.Class_msglist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_msg> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_msg> vx_listmsg() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_msg(index);
    }

    public override vx_core.Type_msglist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_msglist,
       vals);
    }

    public override vx_core.Type_msglist vx_copy(params Object[] vals) {
      Type_msglist output = this;
      boolean ischanged = false;
      Class_msglist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_msg> listval = new ArrayList<>(val.vx_listmsg());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          ischanged = true;
          listval.add((vx_core.Type_msg)valsub);
        } else if (valsub is vx_core.Type_msglist) {
          Type_msglist multi = (Type_msglist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listmsg());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_msg) {
              vx_core.Type_msg valitem = (vx_core.Type_msg)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/msglist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/msglist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_msglist work = new Class_msglist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msglist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msglist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "msglist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_msg), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_msglist e_msglist = new Class_msglist();
  public static Type_msglist t_msglist = new Class_msglist();

  /**
   * type: none
   * No Type. No type is returned at all. e.g. Void
   * (type none)
   */
  public interface Type_none : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_none : vx_core.Class_base, Type_none {

    public override vx_core.Type_none vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_none,
       vals);
    }

    public override vx_core.Type_none vx_copy(params Object[] vals) {
      Type_none output = this;
      boolean ischanged = false;
      Class_none val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_none work = new Class_none();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_none;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_none;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_none e_none = new Class_none();
  public static Type_none t_none = new Class_none();

  /**
   * type: notype
   * No Type that allows no Types as a Value
   * (type notype)
   */
  public interface Type_notype : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_notype : vx_core.Class_base, Type_notype {

    public override vx_core.Type_notype vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_notype,
       vals);
    }

    public override vx_core.Type_notype vx_copy(params Object[] vals) {
      Type_notype output = this;
      boolean ischanged = false;
      Class_notype val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_notype work = new Class_notype();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_notype;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_notype;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "notype", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_notype e_notype = new Class_notype();
  public static Type_notype t_notype = new Class_notype();

  /**
   * type: number
   * A generic number that could be int, float, or decimal.
   * (type number)
   */
  public interface Type_number : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_number : vx_core.Class_base, Type_number {

    public override vx_core.Type_number vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_number,
       vals);
    }

    public override vx_core.Type_number vx_copy(params Object[] vals) {
      Type_number output = this;
      boolean ischanged = false;
      Class_number val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_number work = new Class_number();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_number;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_number;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_number e_number = new Class_number();
  public static Type_number t_number = new Class_number();

  /**
   * type: numberlist
   * A list of number.
   * (type numberlist)
   */
  public interface Type_numberlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_number> vx_listnumber();
    public vx_core.Type_number vx_number(vx_core.Type_int index);
  }

  public class Class_numberlist : vx_core.Class_base, Type_numberlist {

    protected List<vx_core.Type_number> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_number>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_number vx_number(vx_core.Type_int index) {
      vx_core.Type_number output = vx_core.e_number;
      vx_core.Class_numberlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_number> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_number> vx_listnumber() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_number(index);
    }

    public override vx_core.Type_numberlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_numberlist,
       vals);
    }

    public override vx_core.Type_numberlist vx_copy(params Object[] vals) {
      Type_numberlist output = this;
      boolean ischanged = false;
      Class_numberlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_number> listval = new ArrayList<>(val.vx_listnumber());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_number) {
          vx_core.Type_number anysub = valsub as vx_core.Type_number;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_number) {
          ischanged = true;
          listval.add((vx_core.Type_number)valsub);
        } else if (valsub is vx_core.Type_numberlist) {
          Type_numberlist multi = (Type_numberlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listnumber());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_number) {
              vx_core.Type_number valitem = (vx_core.Type_number)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/numberlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/numberlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_numberlist work = new Class_numberlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_numberlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_numberlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "numberlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_numberlist e_numberlist = new Class_numberlist();
  public static Type_numberlist t_numberlist = new Class_numberlist();

  /**
   * type: numbermap
   * A map of number.
   * (type numbermap)
   */
  public interface Type_numbermap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_number> vx_mapnumber();
    public vx_core.Type_number vx_number(vx_core.Type_string key);
  }

  public class Class_numbermap : vx_core.Class_base, Type_numbermap {

    protected Map<String, vx_core.Type_number> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_number>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_number) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_number castval = (vx_core.Type_number)value;
        Map<String, vx_core.Type_number> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_number) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_number vx_number(vx_core.Type_string key) {
      vx_core.Type_number output = vx_core.e_number;
      vx_core.Class_numbermap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_number> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_number);
      return output;
    }

    public Map<String, vx_core.Type_number> vx_mapnumber() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_number(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_numbermap output = new vx_core.Class_numbermap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_number> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_number) {
          vx_core.Type_number castval = (vx_core.Type_number)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/numbermap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_numbermap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_numbermap,
       vals);
    }

    public override vx_core.Type_numbermap vx_copy(params Object[] vals) {
      Type_numbermap output = this;
      boolean ischanged = false;
      Class_numbermap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_number> mapval = new LinkedHashMap<>(val.vx_mapnumber());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/numbermap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_number valany = null;
          if (valsub is vx_core.Type_number) {
            valany = (vx_core.Type_number)valsub;
          } else if (valsub is vx_core.Type_number) {
            valany = valsub as vx_core.Type_number;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/numbermap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_numbermap work = new Class_numbermap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_numbermap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_numbermap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "numbermap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_numbermap e_numbermap = new Class_numbermap();
  public static Type_numbermap t_numbermap = new Class_numbermap();

  /**
   * type: package
   * A package that store types, consts and funcs.
   * (type package)
   */
  public interface Type_package : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string pkgname();
    public vx_core.Type_constmap constmap();
    public vx_core.Type_funcmap funcmap();
    public vx_core.Type_typemap typemap();
    public vx_core.Type_map emptymap();
  }

  public class Class_package : vx_core.Class_base, Type_package {

    protected vx_core.Type_string vx_p_pkgname;

    public vx_core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? vx_core.e_string : this.vx_p_pkgname;
    }

    protected vx_core.Type_constmap vx_p_constmap;

    public vx_core.Type_constmap constmap() {
      return this.vx_p_constmap == null ? vx_core.e_constmap : this.vx_p_constmap;
    }

    protected vx_core.Type_funcmap vx_p_funcmap;

    public vx_core.Type_funcmap funcmap() {
      return this.vx_p_funcmap == null ? vx_core.e_funcmap : this.vx_p_funcmap;
    }

    protected vx_core.Type_typemap vx_p_typemap;

    public vx_core.Type_typemap typemap() {
      return this.vx_p_typemap == null ? vx_core.e_typemap : this.vx_p_typemap;
    }

    protected vx_core.Type_map vx_p_emptymap;

    public vx_core.Type_map emptymap() {
      return this.vx_p_emptymap == null ? vx_core.e_map : this.vx_p_emptymap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":typemap", this.typemap());
      output.put(":emptymap", this.emptymap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_package vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_package,
       vals);
    }

    public override vx_core.Type_package vx_copy(params Object[] vals) {
      Type_package output = this;
      boolean ischanged = false;
      Class_package val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_pkgname = val.pkgname();
      vx_core.Type_constmap vx_p_constmap = val.constmap();
      vx_core.Type_funcmap vx_p_funcmap = val.funcmap();
      vx_core.Type_typemap vx_p_typemap = val.typemap();
      vx_core.Type_map vx_p_emptymap = val.emptymap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":constmap");
      validkeys.add(":funcmap");
      validkeys.add(":typemap");
      validkeys.add(":emptymap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_pkgname = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub is vx_core.Type_constmap) {
              ischanged = true;
              vx_p_constmap = (vx_core.Type_constmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("constmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub is vx_core.Type_funcmap) {
              ischanged = true;
              vx_p_funcmap = (vx_core.Type_funcmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("funcmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub is vx_core.Type_typemap) {
              ischanged = true;
              vx_p_typemap = (vx_core.Type_typemap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("typemap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":emptymap":
            if (valsub == vx_p_emptymap) {
            } else if (valsub is vx_core.Type_map) {
              ischanged = true;
              vx_p_emptymap = (vx_core.Type_map)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("emptymap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/package", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_package work = new Class_package();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_typemap = vx_p_typemap;
        work.vx_p_emptymap = vx_p_emptymap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_package;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_package;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "package", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_package e_package = new Class_package();
  public static Type_package t_package = new Class_package();

  /**
   * type: packagemap
   * (type packagemap)
   */
  public interface Type_packagemap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_package> vx_mappackage();
    public vx_core.Type_package vx_package(vx_core.Type_string key);
  }

  public class Class_packagemap : vx_core.Class_base, Type_packagemap {

    protected Map<String, vx_core.Type_package> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_package>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_package) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_package castval = (vx_core.Type_package)value;
        Map<String, vx_core.Type_package> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_package) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_package vx_package(vx_core.Type_string key) {
      vx_core.Type_package output = vx_core.e_package;
      vx_core.Class_packagemap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_package> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_package);
      return output;
    }

    public Map<String, vx_core.Type_package> vx_mappackage() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_package(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_packagemap output = new vx_core.Class_packagemap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_package> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_package) {
          vx_core.Type_package castval = (vx_core.Type_package)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/packagemap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_packagemap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_packagemap,
       vals);
    }

    public override vx_core.Type_packagemap vx_copy(params Object[] vals) {
      Type_packagemap output = this;
      boolean ischanged = false;
      Class_packagemap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_package> mapval = new LinkedHashMap<>(val.vx_mappackage());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/packagemap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_package valany = null;
          if (valsub is vx_core.Type_package) {
            valany = (vx_core.Type_package)valsub;
          } else if (valsub is vx_core.Type_package) {
            valany = valsub as vx_core.Type_package;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/packagemap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_packagemap work = new Class_packagemap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_packagemap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_packagemap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "packagemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_package), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_packagemap e_packagemap = new Class_packagemap();
  public static Type_packagemap t_packagemap = new Class_packagemap();

  /**
   * type: permission
   * Permission
   * (type permission)
   */
  public interface Type_permission : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string id();
  }

  public class Class_permission : vx_core.Class_base, Type_permission {

    protected vx_core.Type_string vx_p_id;

    public vx_core.Type_string id() {
      return this.vx_p_id == null ? vx_core.e_string : this.vx_p_id;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_permission vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_permission,
       vals);
    }

    public override vx_core.Type_permission vx_copy(params Object[] vals) {
      Type_permission output = this;
      boolean ischanged = false;
      Class_permission val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_id = val.id();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/permission", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/permission", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_id = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("id"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/permission", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/permission", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_permission work = new Class_permission();
        work.vx_p_id = vx_p_id;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_permission;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_permission;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "permission", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_permission e_permission = new Class_permission();
  public static Type_permission t_permission = new Class_permission();

  /**
   * type: permissionlist
   * List of Permission
   * (type permissionlist)
   */
  public interface Type_permissionlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_permission> vx_listpermission();
    public vx_core.Type_permission vx_permission(vx_core.Type_int index);
  }

  public class Class_permissionlist : vx_core.Class_base, Type_permissionlist {

    protected List<vx_core.Type_permission> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_permission>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_permission vx_permission(vx_core.Type_int index) {
      vx_core.Type_permission output = vx_core.e_permission;
      vx_core.Class_permissionlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_permission> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_permission> vx_listpermission() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_permission(index);
    }

    public override vx_core.Type_permissionlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_permissionlist,
       vals);
    }

    public override vx_core.Type_permissionlist vx_copy(params Object[] vals) {
      Type_permissionlist output = this;
      boolean ischanged = false;
      Class_permissionlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_permission> listval = new ArrayList<>(val.vx_listpermission());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_permission) {
          vx_core.Type_permission anysub = valsub as vx_core.Type_permission;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_permission) {
          ischanged = true;
          listval.add((vx_core.Type_permission)valsub);
        } else if (valsub is vx_core.Type_permissionlist) {
          Type_permissionlist multi = (Type_permissionlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listpermission());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_permission) {
              vx_core.Type_permission valitem = (vx_core.Type_permission)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/permissionlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/permissionlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_permissionlist work = new Class_permissionlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_permissionlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_permissionlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "permissionlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_permission), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_permissionlist e_permissionlist = new Class_permissionlist();
  public static Type_permissionlist t_permissionlist = new Class_permissionlist();

  /**
   * type: permissionmap
   * Map of Permission
   * (type permissionmap)
   */
  public interface Type_permissionmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_permission> vx_mappermission();
    public vx_core.Type_permission vx_permission(vx_core.Type_string key);
  }

  public class Class_permissionmap : vx_core.Class_base, Type_permissionmap {

    protected Map<String, vx_core.Type_permission> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_permission>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_permission) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_permission castval = (vx_core.Type_permission)value;
        Map<String, vx_core.Type_permission> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_permission) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_permission vx_permission(vx_core.Type_string key) {
      vx_core.Type_permission output = vx_core.e_permission;
      vx_core.Class_permissionmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_permission> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_permission);
      return output;
    }

    public Map<String, vx_core.Type_permission> vx_mappermission() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_permission(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_permissionmap output = new vx_core.Class_permissionmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_permission> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_permission) {
          vx_core.Type_permission castval = (vx_core.Type_permission)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/permissionmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_permissionmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_permissionmap,
       vals);
    }

    public override vx_core.Type_permissionmap vx_copy(params Object[] vals) {
      Type_permissionmap output = this;
      boolean ischanged = false;
      Class_permissionmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_permission> mapval = new LinkedHashMap<>(val.vx_mappermission());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/permissionmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_permission valany = null;
          if (valsub is vx_core.Type_permission) {
            valany = (vx_core.Type_permission)valsub;
          } else if (valsub is vx_core.Type_permission) {
            valany = valsub as vx_core.Type_permission;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/permissionmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_permissionmap work = new Class_permissionmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_permissionmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_permissionmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "permissionmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_permission), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_permissionmap e_permissionmap = new Class_permissionmap();
  public static Type_permissionmap t_permissionmap = new Class_permissionmap();

  /**
   * type: project
   * A project.
   * (type project)
   */
  public interface Type_project : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_packagemap packagemap();
  }

  public class Class_project : vx_core.Class_base, Type_project {

    protected vx_core.Type_packagemap vx_p_packagemap;

    public vx_core.Type_packagemap packagemap() {
      return this.vx_p_packagemap == null ? vx_core.e_packagemap : this.vx_p_packagemap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":packagemap":
        output = this.packagemap();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":packagemap", this.packagemap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_project vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_project,
       vals);
    }

    public override vx_core.Type_project vx_copy(params Object[] vals) {
      Type_project output = this;
      boolean ischanged = false;
      Class_project val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_packagemap vx_p_packagemap = val.packagemap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":packagemap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/project", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/project", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":packagemap":
            if (valsub == vx_p_packagemap) {
            } else if (valsub is vx_core.Type_packagemap) {
              ischanged = true;
              vx_p_packagemap = (vx_core.Type_packagemap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("packagemap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/project", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/project", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_project work = new Class_project();
        work.vx_p_packagemap = vx_p_packagemap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_project;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_project;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "project", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_project e_project = new Class_project();
  public static Type_project t_project = new Class_project();

  /**
   * type: security
   * Security rules
   * (type security)
   */
  public interface Type_security : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_funclist allowfuncs();
    public vx_core.Type_permissionlist permissions();
    public vx_core.Type_permissionmap permissionmap();
  }

  public class Class_security : vx_core.Class_base, Type_security {

    protected vx_core.Type_funclist vx_p_allowfuncs;

    public vx_core.Type_funclist allowfuncs() {
      return this.vx_p_allowfuncs == null ? vx_core.e_funclist : this.vx_p_allowfuncs;
    }

    protected vx_core.Type_permissionlist vx_p_permissions;

    public vx_core.Type_permissionlist permissions() {
      return this.vx_p_permissions == null ? vx_core.e_permissionlist : this.vx_p_permissions;
    }

    protected vx_core.Type_permissionmap vx_p_permissionmap;

    public vx_core.Type_permissionmap permissionmap() {
      return this.vx_p_permissionmap == null ? vx_core.e_permissionmap : this.vx_p_permissionmap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":allowfuncs", this.allowfuncs());
      output.put(":permissions", this.permissions());
      output.put(":permissionmap", this.permissionmap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_security vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_security,
       vals);
    }

    public override vx_core.Type_security vx_copy(params Object[] vals) {
      Type_security output = this;
      boolean ischanged = false;
      Class_security val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      vx_core.Type_permissionlist vx_p_permissions = val.permissions();
      vx_core.Type_permissionmap vx_p_permissionmap = val.permissionmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":allowfuncs");
      validkeys.add(":permissions");
      validkeys.add(":permissionmap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub is vx_core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (vx_core.Type_funclist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("allowfuncs"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":permissions":
            if (valsub == vx_p_permissions) {
            } else if (valsub is vx_core.Type_permissionlist) {
              ischanged = true;
              vx_p_permissions = (vx_core.Type_permissionlist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("permissions"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":permissionmap":
            if (valsub == vx_p_permissionmap) {
            } else if (valsub is vx_core.Type_permissionmap) {
              ischanged = true;
              vx_p_permissionmap = (vx_core.Type_permissionmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("permissionmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/security", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_security work = new Class_security();
        work.vx_p_allowfuncs = vx_p_allowfuncs;
        work.vx_p_permissions = vx_p_permissions;
        work.vx_p_permissionmap = vx_p_permissionmap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_security;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_security;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "security", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_security e_security = new Class_security();
  public static Type_security t_security = new Class_security();

  /**
   * type: session
   * Session
   * (type session)
   */
  public interface Type_session : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_user user();
    public vx_core.Type_connectlist connectlist();
    public vx_core.Type_connectmap connectmap();
    public vx_core.Type_locale locale();
    public vx_core.Type_translation translation();
    public vx_core.Type_translationmap translationmap();
  }

  public class Class_session : vx_core.Class_base, Type_session {

    protected vx_core.Type_user vx_p_user;

    public vx_core.Type_user user() {
      return this.vx_p_user == null ? vx_core.e_user : this.vx_p_user;
    }

    protected vx_core.Type_connectlist vx_p_connectlist;

    public vx_core.Type_connectlist connectlist() {
      return this.vx_p_connectlist == null ? vx_core.e_connectlist : this.vx_p_connectlist;
    }

    protected vx_core.Type_connectmap vx_p_connectmap;

    public vx_core.Type_connectmap connectmap() {
      return this.vx_p_connectmap == null ? vx_core.e_connectmap : this.vx_p_connectmap;
    }

    protected vx_core.Type_locale vx_p_locale;

    public vx_core.Type_locale locale() {
      return this.vx_p_locale == null ? vx_core.e_locale : this.vx_p_locale;
    }

    protected vx_core.Type_translation vx_p_translation;

    public vx_core.Type_translation translation() {
      return this.vx_p_translation == null ? vx_core.e_translation : this.vx_p_translation;
    }

    protected vx_core.Type_translationmap vx_p_translationmap;

    public vx_core.Type_translationmap translationmap() {
      return this.vx_p_translationmap == null ? vx_core.e_translationmap : this.vx_p_translationmap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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
      case ":locale":
        output = this.locale();
        break;
      case ":translation":
        output = this.translation();
        break;
      case ":translationmap":
        output = this.translationmap();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":user", this.user());
      output.put(":connectlist", this.connectlist());
      output.put(":connectmap", this.connectmap());
      output.put(":locale", this.locale());
      output.put(":translation", this.translation());
      output.put(":translationmap", this.translationmap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_session vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_session,
       vals);
    }

    public override vx_core.Type_session vx_copy(params Object[] vals) {
      Type_session output = this;
      boolean ischanged = false;
      Class_session val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_user vx_p_user = val.user();
      vx_core.Type_connectlist vx_p_connectlist = val.connectlist();
      vx_core.Type_connectmap vx_p_connectmap = val.connectmap();
      vx_core.Type_locale vx_p_locale = val.locale();
      vx_core.Type_translation vx_p_translation = val.translation();
      vx_core.Type_translationmap vx_p_translationmap = val.translationmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":user");
      validkeys.add(":connectlist");
      validkeys.add(":connectmap");
      validkeys.add(":locale");
      validkeys.add(":translation");
      validkeys.add(":translationmap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":user":
            if (valsub == vx_p_user) {
            } else if (valsub is vx_core.Type_user) {
              ischanged = true;
              vx_p_user = (vx_core.Type_user)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("user"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":connectlist":
            if (valsub == vx_p_connectlist) {
            } else if (valsub is vx_core.Type_connectlist) {
              ischanged = true;
              vx_p_connectlist = (vx_core.Type_connectlist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("connectlist"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":connectmap":
            if (valsub == vx_p_connectmap) {
            } else if (valsub is vx_core.Type_connectmap) {
              ischanged = true;
              vx_p_connectmap = (vx_core.Type_connectmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("connectmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":locale":
            if (valsub == vx_p_locale) {
            } else if (valsub is vx_core.Type_locale) {
              ischanged = true;
              vx_p_locale = (vx_core.Type_locale)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("locale"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":translation":
            if (valsub == vx_p_translation) {
            } else if (valsub is vx_core.Type_translation) {
              ischanged = true;
              vx_p_translation = (vx_core.Type_translation)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("translation"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":translationmap":
            if (valsub == vx_p_translationmap) {
            } else if (valsub is vx_core.Type_translationmap) {
              ischanged = true;
              vx_p_translationmap = (vx_core.Type_translationmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("translationmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/session", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_session work = new Class_session();
        work.vx_p_user = vx_p_user;
        work.vx_p_connectlist = vx_p_connectlist;
        work.vx_p_connectmap = vx_p_connectmap;
        work.vx_p_locale = vx_p_locale;
        work.vx_p_translation = vx_p_translation;
        work.vx_p_translationmap = vx_p_translationmap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_session;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_session;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "session", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_session e_session = new Class_session();
  public static Type_session t_session = new Class_session();

  /**
   * type: setting
   * Settings
   * (type setting)
   */
  public interface Type_setting : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_stringmap pathmap();
  }

  public class Class_setting : vx_core.Class_base, Type_setting {

    protected vx_core.Type_stringmap vx_p_pathmap;

    public vx_core.Type_stringmap pathmap() {
      return this.vx_p_pathmap == null ? vx_core.e_stringmap : this.vx_p_pathmap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pathmap":
        output = this.pathmap();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":pathmap", this.pathmap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_setting vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_setting,
       vals);
    }

    public override vx_core.Type_setting vx_copy(params Object[] vals) {
      Type_setting output = this;
      boolean ischanged = false;
      Class_setting val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_stringmap vx_p_pathmap = val.pathmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pathmap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/setting", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/setting", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pathmap":
            if (valsub == vx_p_pathmap) {
            } else if (valsub is vx_core.Type_stringmap) {
              ischanged = true;
              vx_p_pathmap = (vx_core.Type_stringmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("pathmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/setting", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/setting", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_setting work = new Class_setting();
        work.vx_p_pathmap = vx_p_pathmap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_setting;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_setting;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "setting", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_setting e_setting = new Class_setting();
  public static Type_setting t_setting = new Class_setting();

  /**
   * type: state
   * State. Note that this type is has mutable values.
   * (type state)
   */
  public interface Type_state : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_statelistenermap statelistenermap();
  }

  public class Class_state : vx_core.Class_base, Type_state {

    protected vx_core.Type_statelistenermap vx_p_statelistenermap;

    public vx_core.Type_statelistenermap statelistenermap() {
      return this.vx_p_statelistenermap == null ? vx_core.e_statelistenermap : this.vx_p_statelistenermap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":statelistenermap":
        output = this.statelistenermap();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":statelistenermap", this.statelistenermap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_state vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_state,
       vals);
    }

    public override vx_core.Type_state vx_copy(params Object[] vals) {
      Type_state output = this;
      boolean ischanged = false;
      Class_state val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_statelistenermap vx_p_statelistenermap = val.statelistenermap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":statelistenermap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/state", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/state", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":statelistenermap":
            if (valsub == vx_p_statelistenermap) {
            } else if (valsub is vx_core.Type_statelistenermap) {
              ischanged = true;
              vx_p_statelistenermap = (vx_core.Type_statelistenermap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("statelistenermap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/state", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/state", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_state work = new Class_state();
        work.vx_p_statelistenermap = vx_p_statelistenermap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_state;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_state;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "state", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_state e_state = new Class_state();
  public static Type_state t_state = new Class_state();

  /**
   * type: statelistener
   * (type statelistener)
   */
  public interface Type_statelistener : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string name();
    public vx_core.Type_any value();
    public vx_core.Func_boolean_from_none fn_boolean();
  }

  public class Class_statelistener : vx_core.Class_base, Type_statelistener {

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_any vx_p_value;

    public vx_core.Type_any value() {
      return this.vx_p_value == null ? vx_core.e_any : this.vx_p_value;
    }

    protected vx_core.Func_boolean_from_none vx_p_fn_boolean;

    public vx_core.Func_boolean_from_none fn_boolean() {
      return this.vx_p_fn_boolean == null ? vx_core.e_boolean_from_none : this.vx_p_fn_boolean;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":value", this.value());
      output.put(":fn-boolean", this.fn_boolean());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_statelistener vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_statelistener,
       vals);
    }

    public override vx_core.Type_statelistener vx_copy(params Object[] vals) {
      Type_statelistener output = this;
      boolean ischanged = false;
      Class_statelistener val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_any vx_p_value = val.value();
      vx_core.Func_boolean_from_none vx_p_fn_boolean = val.fn_boolean();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":value");
      validkeys.add(":fn-boolean");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_value = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("value"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-boolean":
            if (valsub == vx_p_fn_boolean) {
            } else if (valsub is vx_core.Func_boolean_from_none) {
              ischanged = true;
              vx_p_fn_boolean = (vx_core.Func_boolean_from_none)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("fn-boolean"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/statelistener", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_statelistener work = new Class_statelistener();
        work.vx_p_name = vx_p_name;
        work.vx_p_value = vx_p_value;
        work.vx_p_fn_boolean = vx_p_fn_boolean;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_statelistener;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_statelistener;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "statelistener", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_statelistener e_statelistener = new Class_statelistener();
  public static Type_statelistener t_statelistener = new Class_statelistener();

  /**
   * type: statelistenermap
   * Mutable map of statelisteners
   * (type statelistenermap)
   */
  public interface Type_statelistenermap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_statelistener> vx_mapstatelistener();
    public vx_core.Type_statelistener vx_statelistener(vx_core.Type_string key);
  }

  public class Class_statelistenermap : vx_core.Class_base, Type_statelistenermap {

    protected Map<String, vx_core.Type_statelistener> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_statelistener>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_statelistener) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_statelistener castval = (vx_core.Type_statelistener)value;
        Map<String, vx_core.Type_statelistener> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_statelistener) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_statelistener vx_statelistener(vx_core.Type_string key) {
      vx_core.Type_statelistener output = vx_core.e_statelistener;
      vx_core.Class_statelistenermap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_statelistener> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_statelistener);
      return output;
    }

    public Map<String, vx_core.Type_statelistener> vx_mapstatelistener() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_statelistener(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_statelistenermap output = new vx_core.Class_statelistenermap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_statelistener> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_statelistener) {
          vx_core.Type_statelistener castval = (vx_core.Type_statelistener)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/statelistenermap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_statelistenermap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_statelistenermap,
       vals);
    }

    public override vx_core.Type_statelistenermap vx_copy(params Object[] vals) {
      Type_statelistenermap output = this;
      boolean ischanged = false;
      Class_statelistenermap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_statelistener> mapval = new LinkedHashMap<>(val.vx_mapstatelistener());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/statelistenermap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_statelistener valany = null;
          if (valsub is vx_core.Type_statelistener) {
            valany = (vx_core.Type_statelistener)valsub;
          } else if (valsub is vx_core.Type_statelistener) {
            valany = valsub as vx_core.Type_statelistener;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/statelistenermap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_statelistenermap work = new Class_statelistenermap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_statelistenermap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_statelistenermap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "statelistenermap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_statelistener), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_statelistenermap e_statelistenermap = new Class_statelistenermap();
  public static Type_statelistenermap t_statelistenermap = new Class_statelistenermap();

  /**
   * type: string
   * A simple string.
   * (type string)
   */
  public interface Type_string : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_string : vx_core.Class_base, Type_string {

    public override vx_core.Type_string vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_string,
       vals);
    }

    public override vx_core.Type_string vx_copy(params Object[] vals) {
      Type_string output = this;
      boolean ischanged = false;
      Class_string val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      StringBuilder sb = new StringBuilder(val.vx_string());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_string) {
          vx_core.Type_string valstring = valsub as vx_core.Type_string;
          String ssub = valstring.vx_string();
          if (!ssub.equals("")) {
            ischanged = true;
            sb.append(ssub);
          }
        } else if (valsub is vx_core.Type_int) {
          vx_core.Type_int valint = valsub as vx_core.Type_int;
          ischanged = true;
          sb.append(valint.vx_int());
        } else if (valsub is vx_core.Type_float) {
          vx_core.Type_float valfloat = valsub as vx_core.Type_float;
          ischanged = true;
          sb.append(valfloat.vx_float());
        } else if (valsub is vx_core.Type_decimal) {
          vx_core.Type_decimal valdecimal = valsub as vx_core.Type_decimal;
          ischanged = true;
          sb.append(valdecimal.vx_string());
        } else if (valsub is String) {
          String ssub2 = valsub as String;
          if (!ssub2.equals("")) {
            ischanged = true;
            sb.append(ssub2);
          }
        } else if (valsub is Integer) {
          int ssub2 = valsub as Integer;
          ischanged = true;
          sb.append(ssub2);
        } else if (valsub is Float) {
          Float ssub2 = valsub as Float;
          ischanged = true;
          sb.append(ssub2);
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/string", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/string", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        String vxstring = sb.toString();
        Class_string work = new Class_string();
        work.vxstring = vxstring;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "string", // name
        ":string", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_string e_string = new Class_string();
  public static Type_string t_string = new Class_string();

  /**
   * type: stringlist
   * A list of string.
   * (type stringlist)
   */
  public interface Type_stringlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_string> vx_liststring();
    public vx_core.Type_string vx_string(vx_core.Type_int index);
  }

  public class Class_stringlist : vx_core.Class_base, Type_stringlist {

    protected List<vx_core.Type_string> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_string>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_string vx_string(vx_core.Type_int index) {
      vx_core.Type_string output = vx_core.e_string;
      vx_core.Class_stringlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_string> vx_liststring() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_string(index);
    }

    public override vx_core.Type_stringlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_stringlist,
       vals);
    }

    public override vx_core.Type_stringlist vx_copy(params Object[] vals) {
      Type_stringlist output = this;
      boolean ischanged = false;
      Class_stringlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_string> listval = new ArrayList<>(val.vx_liststring());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_string) {
          vx_core.Type_string anysub = valsub as vx_core.Type_string;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is String) {
          ischanged = true;
          listval.add(vx_core.vx_new(vx_core.t_string, valsub));
        } else if (valsub is vx_core.Type_stringlist) {
          Type_stringlist multi = (Type_stringlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststring());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_string) {
              vx_core.Type_string valitem = (vx_core.Type_string)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/stringlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/stringlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_stringlist work = new Class_stringlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_stringlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_stringlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_stringlist e_stringlist = new Class_stringlist();
  public static Type_stringlist t_stringlist = new Class_stringlist();

  /**
   * type: stringlistlist
   * A list of stringlist.
   * (type stringlistlist)
   */
  public interface Type_stringlistlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_stringlist> vx_liststringlist();
    public vx_core.Type_stringlist vx_stringlist(vx_core.Type_int index);
  }

  public class Class_stringlistlist : vx_core.Class_base, Type_stringlistlist {

    protected List<vx_core.Type_stringlist> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_stringlist>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_stringlist vx_stringlist(vx_core.Type_int index) {
      vx_core.Type_stringlist output = vx_core.e_stringlist;
      vx_core.Class_stringlistlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_stringlist> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_stringlist> vx_liststringlist() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_stringlist(index);
    }

    public override vx_core.Type_stringlistlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_stringlistlist,
       vals);
    }

    public override vx_core.Type_stringlistlist vx_copy(params Object[] vals) {
      Type_stringlistlist output = this;
      boolean ischanged = false;
      Class_stringlistlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_stringlist> listval = new ArrayList<>(val.vx_liststringlist());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_stringlist) {
          vx_core.Type_stringlist anysub = valsub as vx_core.Type_stringlist;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_stringlist) {
          ischanged = true;
          listval.add((vx_core.Type_stringlist)valsub);
        } else if (valsub is vx_core.Type_stringlistlist) {
          Type_stringlistlist multi = (Type_stringlistlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststringlist());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_stringlist) {
              vx_core.Type_stringlist valitem = (vx_core.Type_stringlist)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/stringlistlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/stringlistlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_stringlistlist work = new Class_stringlistlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_stringlistlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_stringlistlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "stringlistlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_stringlist), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_stringlistlist e_stringlistlist = new Class_stringlistlist();
  public static Type_stringlistlist t_stringlistlist = new Class_stringlistlist();

  /**
   * type: stringmap
   * A map of string.
   * (type stringmap)
   */
  public interface Type_stringmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_string> vx_mapstring();
    public vx_core.Type_string vx_string(vx_core.Type_string key);
  }

  public class Class_stringmap : vx_core.Class_base, Type_stringmap {

    protected Map<String, vx_core.Type_string> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_string>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_string) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_string castval = (vx_core.Type_string)value;
        Map<String, vx_core.Type_string> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_string vx_string(vx_core.Type_string key) {
      vx_core.Type_string output = vx_core.e_string;
      vx_core.Class_stringmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_string);
      return output;
    }

    public Map<String, vx_core.Type_string> vx_mapstring() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_string(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_stringmap output = new vx_core.Class_stringmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_string> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_string) {
          vx_core.Type_string castval = (vx_core.Type_string)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/stringmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_stringmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_stringmap,
       vals);
    }

    public override vx_core.Type_stringmap vx_copy(params Object[] vals) {
      Type_stringmap output = this;
      boolean ischanged = false;
      Class_stringmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_string> mapval = new LinkedHashMap<>(val.vx_mapstring());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/stringmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_string valany = null;
          if (valsub is vx_core.Type_string) {
            valany = (vx_core.Type_string)valsub;
          } else if (valsub is String) {
            valany = vx_core.vx_new(vx_core.t_string, valsub);
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/stringmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_stringmap work = new Class_stringmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_stringmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_stringmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "stringmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_stringmap e_stringmap = new Class_stringmap();
  public static Type_stringmap t_stringmap = new Class_stringmap();

  /**
   * type: stringmutablemap
   * A mutable map of string. Note: Mutables are dangerous.
   * (type stringmutablemap)
   */
  public interface Type_stringmutablemap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_string> vx_mapstring();
    public vx_core.Type_string vx_string(vx_core.Type_string key);
  }

  public class Class_stringmutablemap : vx_core.Class_base, Type_stringmutablemap {

    protected Map<String, vx_core.Type_string> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_string>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_string) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_string castval = (vx_core.Type_string)value;
        Map<String, vx_core.Type_string> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_string vx_string(vx_core.Type_string key) {
      vx_core.Type_string output = vx_core.e_string;
      vx_core.Class_stringmutablemap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_string);
      return output;
    }

    public Map<String, vx_core.Type_string> vx_mapstring() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_string(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_stringmutablemap output = new vx_core.Class_stringmutablemap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_string> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_string) {
          vx_core.Type_string castval = (vx_core.Type_string)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/stringmutablemap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_stringmutablemap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_stringmutablemap,
       vals);
    }

    public override vx_core.Type_stringmutablemap vx_copy(params Object[] vals) {
      Type_stringmutablemap output = this;
      boolean ischanged = false;
      Class_stringmutablemap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_string> mapval = new LinkedHashMap<>(val.vx_mapstring());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/stringmutablemap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_string valany = null;
          if (valsub is vx_core.Type_string) {
            valany = (vx_core.Type_string)valsub;
          } else if (valsub is String) {
            valany = vx_core.vx_new(vx_core.t_string, valsub);
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/stringmutablemap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_stringmutablemap work = new Class_stringmutablemap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_stringmutablemap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_stringmutablemap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "stringmutablemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_stringmutablemap e_stringmutablemap = new Class_stringmutablemap();
  public static Type_stringmutablemap t_stringmutablemap = new Class_stringmutablemap();

  /**
   * type: struct
   * Struct is the type of all structures/objects with properties.
   * (type struct)
   */
  public interface Type_struct : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_any vx_any(vx_core.Type_string key);
    public Map<String, vx_core.Type_any> vx_map();
  }

  public class Class_struct : vx_core.Class_base, Type_struct {

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_struct vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_struct,
       vals);
    }

    public override vx_core.Type_struct vx_copy(params Object[] vals) {
      Type_struct output = this;
      boolean ischanged = false;
      Class_struct val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_struct work = new Class_struct();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_struct;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_struct;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "struct", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_struct e_struct = new Class_struct();
  public static Type_struct t_struct = new Class_struct();

  /**
   * type: thenelse
   * (type thenelse)
   */
  public interface Type_thenelse : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string code();
    public vx_core.Type_any value();
    public vx_core.Type_list values();
    public vx_core.Func_boolean_from_func fn_cond();
    public vx_core.Func_any_from_func fn_any();
  }

  public class Class_thenelse : vx_core.Class_base, Type_thenelse {

    protected vx_core.Type_string vx_p_code;

    public vx_core.Type_string code() {
      return this.vx_p_code == null ? vx_core.e_string : this.vx_p_code;
    }

    protected vx_core.Type_any vx_p_value;

    public vx_core.Type_any value() {
      return this.vx_p_value == null ? vx_core.e_any : this.vx_p_value;
    }

    protected vx_core.Type_list vx_p_values;

    public vx_core.Type_list values() {
      return this.vx_p_values == null ? vx_core.e_list : this.vx_p_values;
    }

    protected vx_core.Func_boolean_from_func vx_p_fn_cond;

    public vx_core.Func_boolean_from_func fn_cond() {
      return this.vx_p_fn_cond == null ? vx_core.e_boolean_from_func : this.vx_p_fn_cond;
    }

    protected vx_core.Func_any_from_func vx_p_fn_any;

    public vx_core.Func_any_from_func fn_any() {
      return this.vx_p_fn_any == null ? vx_core.e_any_from_func : this.vx_p_fn_any;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":value", this.value());
      output.put(":values", this.values());
      output.put(":fn-cond", this.fn_cond());
      output.put(":fn-any", this.fn_any());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_thenelse vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_thenelse,
       vals);
    }

    public override vx_core.Type_thenelse vx_copy(params Object[] vals) {
      Type_thenelse output = this;
      boolean ischanged = false;
      Class_thenelse val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_code = val.code();
      vx_core.Type_any vx_p_value = val.value();
      vx_core.Type_list vx_p_values = val.values();
      vx_core.Func_boolean_from_func vx_p_fn_cond = val.fn_cond();
      vx_core.Func_any_from_func vx_p_fn_any = val.fn_any();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":value");
      validkeys.add(":values");
      validkeys.add(":fn-cond");
      validkeys.add(":fn-any");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_code = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_code = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("code"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_value = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("value"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":values":
            if (valsub == vx_p_values) {
            } else if (valsub is vx_core.Type_list) {
              ischanged = true;
              vx_p_values = (vx_core.Type_list)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("values"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-cond":
            if (valsub == vx_p_fn_cond) {
            } else if (valsub is vx_core.Func_boolean_from_func) {
              ischanged = true;
              vx_p_fn_cond = (vx_core.Func_boolean_from_func)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("fn-cond"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub is vx_core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (vx_core.Func_any_from_func)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("fn-any"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/thenelse", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_thenelse work = new Class_thenelse();
        work.vx_p_code = vx_p_code;
        work.vx_p_value = vx_p_value;
        work.vx_p_values = vx_p_values;
        work.vx_p_fn_cond = vx_p_fn_cond;
        work.vx_p_fn_any = vx_p_fn_any;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_thenelse;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_thenelse;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_thenelse e_thenelse = new Class_thenelse();
  public static Type_thenelse t_thenelse = new Class_thenelse();

  /**
   * type: thenelselist
   * (type thenelselist)
   */
  public interface Type_thenelselist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_thenelse> vx_listthenelse();
    public vx_core.Type_thenelse vx_thenelse(vx_core.Type_int index);
  }

  public class Class_thenelselist : vx_core.Class_base, Type_thenelselist {

    protected List<vx_core.Type_thenelse> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_thenelse>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_thenelse vx_thenelse(vx_core.Type_int index) {
      vx_core.Type_thenelse output = vx_core.e_thenelse;
      vx_core.Class_thenelselist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_thenelse> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_thenelse> vx_listthenelse() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_thenelse(index);
    }

    public override vx_core.Type_thenelselist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_thenelselist,
       vals);
    }

    public override vx_core.Type_thenelselist vx_copy(params Object[] vals) {
      Type_thenelselist output = this;
      boolean ischanged = false;
      Class_thenelselist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_thenelse> listval = new ArrayList<>(val.vx_listthenelse());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_thenelse) {
          vx_core.Type_thenelse anysub = valsub as vx_core.Type_thenelse;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_thenelse) {
          ischanged = true;
          listval.add((vx_core.Type_thenelse)valsub);
        } else if (valsub is vx_core.Type_thenelselist) {
          Type_thenelselist multi = (Type_thenelselist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listthenelse());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_thenelse) {
              vx_core.Type_thenelse valitem = (vx_core.Type_thenelse)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/thenelselist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/thenelselist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_thenelselist work = new Class_thenelselist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_thenelselist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_thenelselist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "thenelselist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_thenelse), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_thenelselist e_thenelselist = new Class_thenelselist();
  public static Type_thenelselist t_thenelselist = new Class_thenelselist();

  /**
   * type: translation
   * i18 language translation.
   * (type translation)
   */
  public interface Type_translation : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string name();
    public vx_core.Type_stringmap wordmap();
  }

  public class Class_translation : vx_core.Class_base, Type_translation {

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_stringmap vx_p_wordmap;

    public vx_core.Type_stringmap wordmap() {
      return this.vx_p_wordmap == null ? vx_core.e_stringmap : this.vx_p_wordmap;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":wordmap":
        output = this.wordmap();
        break;
      }
      return output;
    }

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":wordmap", this.wordmap());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_translation vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_translation,
       vals);
    }

    public override vx_core.Type_translation vx_copy(params Object[] vals) {
      Type_translation output = this;
      boolean ischanged = false;
      Class_translation val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_stringmap vx_p_wordmap = val.wordmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":wordmap");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/translation", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/translation", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/translation", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":wordmap":
            if (valsub == vx_p_wordmap) {
            } else if (valsub is vx_core.Type_stringmap) {
              ischanged = true;
              vx_p_wordmap = (vx_core.Type_stringmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("wordmap"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/translation", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/translation", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_translation work = new Class_translation();
        work.vx_p_name = vx_p_name;
        work.vx_p_wordmap = vx_p_wordmap;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_translation;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_translation;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "translation", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_translation e_translation = new Class_translation();
  public static Type_translation t_translation = new Class_translation();

  /**
   * type: translationlist
   * i18 language translation list.
   * (type translationlist)
   */
  public interface Type_translationlist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public List<vx_core.Type_translation> vx_listtranslation();
    public vx_core.Type_translation vx_translation(vx_core.Type_int index);
  }

  public class Class_translationlist : vx_core.Class_base, Type_translationlist {

    protected List<vx_core.Type_translation> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_translation>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_translation vx_translation(vx_core.Type_int index) {
      vx_core.Type_translation output = vx_core.e_translation;
      vx_core.Class_translationlist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_translation> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public List<vx_core.Type_translation> vx_listtranslation() {
      return vx_p_list;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      return this.vx_translation(index);
    }

    public override vx_core.Type_translationlist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_translationlist,
       vals);
    }

    public override vx_core.Type_translationlist vx_copy(params Object[] vals) {
      Type_translationlist output = this;
      boolean ischanged = false;
      Class_translationlist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_translation> listval = new ArrayList<>(val.vx_listtranslation());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_translation) {
          vx_core.Type_translation anysub = valsub as vx_core.Type_translation;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_translation) {
          ischanged = true;
          listval.add((vx_core.Type_translation)valsub);
        } else if (valsub is vx_core.Type_translationlist) {
          Type_translationlist multi = (Type_translationlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtranslation());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_translation) {
              vx_core.Type_translation valitem = (vx_core.Type_translation)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/translationlist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/translationlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_translationlist work = new Class_translationlist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_translationlist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_translationlist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "translationlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_translation), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_translationlist e_translationlist = new Class_translationlist();
  public static Type_translationlist t_translationlist = new Class_translationlist();

  /**
   * type: translationmap
   * i18 language translation map.
   * (type translationmap)
   */
  public interface Type_translationmap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public Map<String, vx_core.Type_translation> vx_maptranslation();
    public vx_core.Type_translation vx_translation(vx_core.Type_string key);
  }

  public class Class_translationmap : vx_core.Class_base, Type_translationmap {

    protected Map<String, vx_core.Type_translation> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_translation>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_translation) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_translation castval = (vx_core.Type_translation)value;
        Map<String, vx_core.Type_translation> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_translation) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_translation vx_translation(vx_core.Type_string key) {
      vx_core.Type_translation output = vx_core.e_translation;
      vx_core.Class_translationmap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_translation> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_translation);
      return output;
    }

    public Map<String, vx_core.Type_translation> vx_maptranslation() {
      return vx_p_map;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      return this.vx_translation(key);
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_translationmap output = new vx_core.Class_translationmap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_translation> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_translation) {
          vx_core.Type_translation castval = (vx_core.Type_translation)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/translationmap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_translationmap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_translationmap,
       vals);
    }

    public override vx_core.Type_translationmap vx_copy(params Object[] vals) {
      Type_translationmap output = this;
      boolean ischanged = false;
      Class_translationmap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_translation> mapval = new LinkedHashMap<>(val.vx_maptranslation());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/translationmap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_translation valany = null;
          if (valsub is vx_core.Type_translation) {
            valany = (vx_core.Type_translation)valsub;
          } else if (valsub is vx_core.Type_translation) {
            valany = valsub as vx_core.Type_translation;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/translationmap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_translationmap work = new Class_translationmap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_translationmap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_translationmap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "translationmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_translation), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_translationmap e_translationmap = new Class_translationmap();
  public static Type_translationmap t_translationmap = new Class_translationmap();

  /**
   * type: type
   * Original Type Class
   * (type type)
   */
  public interface Type_type : vx_core.Type_any {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_type : vx_core.Class_base, Type_type {

    public override vx_core.Type_type vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_type,
       vals);
    }

    public override vx_core.Type_type vx_copy(params Object[] vals) {
      Type_type output = this;
      boolean ischanged = false;
      Class_type val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_type work = new Class_type();
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_type;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_type;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "type", // name
        ":type", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_type e_type = new Class_type();
  public static Type_type t_type = new Class_type();

  /**
   * type: typedef
   * Type Definition Class for inspecting Type properties.
   * (type typedef)
   */
  public interface Type_typedef : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_string pkgname();
    public vx_core.Type_string name();
    public vx_core.Type_string extend();
    public vx_core.Type_funclist allowfuncs();
    public vx_core.Type_typelist allowtypes();
    public vx_core.Type_anylist allowvalues();
    public vx_core.Type_funclist disallowfuncs();
    public vx_core.Type_typelist disallowtypes();
    public vx_core.Type_anylist disallowvalues();
    public vx_core.Type_argmap properties();
    public vx_core.Type_arg proplast();
    public vx_core.Type_typelist traits();
  }

  public class Class_typedef : vx_core.Class_base, Type_typedef {

    protected vx_core.Type_string vx_p_pkgname;

    public vx_core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? vx_core.e_string : this.vx_p_pkgname;
    }

    protected vx_core.Type_string vx_p_name;

    public vx_core.Type_string name() {
      return this.vx_p_name == null ? vx_core.e_string : this.vx_p_name;
    }

    protected vx_core.Type_string vx_p_extend;

    public vx_core.Type_string extend() {
      return this.vx_p_extend == null ? vx_core.e_string : this.vx_p_extend;
    }

    protected vx_core.Type_funclist vx_p_allowfuncs;

    public vx_core.Type_funclist allowfuncs() {
      return this.vx_p_allowfuncs == null ? vx_core.e_funclist : this.vx_p_allowfuncs;
    }

    protected vx_core.Type_typelist vx_p_allowtypes;

    public vx_core.Type_typelist allowtypes() {
      return this.vx_p_allowtypes == null ? vx_core.e_typelist : this.vx_p_allowtypes;
    }

    protected vx_core.Type_anylist vx_p_allowvalues;

    public vx_core.Type_anylist allowvalues() {
      return this.vx_p_allowvalues == null ? vx_core.e_anylist : this.vx_p_allowvalues;
    }

    protected vx_core.Type_funclist vx_p_disallowfuncs;

    public vx_core.Type_funclist disallowfuncs() {
      return this.vx_p_disallowfuncs == null ? vx_core.e_funclist : this.vx_p_disallowfuncs;
    }

    protected vx_core.Type_typelist vx_p_disallowtypes;

    public vx_core.Type_typelist disallowtypes() {
      return this.vx_p_disallowtypes == null ? vx_core.e_typelist : this.vx_p_disallowtypes;
    }

    protected vx_core.Type_anylist vx_p_disallowvalues;

    public vx_core.Type_anylist disallowvalues() {
      return this.vx_p_disallowvalues == null ? vx_core.e_anylist : this.vx_p_disallowvalues;
    }

    protected vx_core.Type_argmap vx_p_properties;

    public vx_core.Type_argmap properties() {
      return this.vx_p_properties == null ? vx_core.e_argmap : this.vx_p_properties;
    }

    protected vx_core.Type_arg vx_p_proplast;

    public vx_core.Type_arg proplast() {
      return this.vx_p_proplast == null ? vx_core.e_arg : this.vx_p_proplast;
    }

    protected vx_core.Type_typelist vx_p_traits;

    public vx_core.Type_typelist traits() {
      return this.vx_p_traits == null ? vx_core.e_typelist : this.vx_p_traits;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
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
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_typedef vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_typedef,
       vals);
    }

    public override vx_core.Type_typedef vx_copy(params Object[] vals) {
      Type_typedef output = this;
      boolean ischanged = false;
      Class_typedef val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_string vx_p_pkgname = val.pkgname();
      vx_core.Type_string vx_p_name = val.name();
      vx_core.Type_string vx_p_extend = val.extend();
      vx_core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      vx_core.Type_typelist vx_p_allowtypes = val.allowtypes();
      vx_core.Type_anylist vx_p_allowvalues = val.allowvalues();
      vx_core.Type_funclist vx_p_disallowfuncs = val.disallowfuncs();
      vx_core.Type_typelist vx_p_disallowtypes = val.disallowtypes();
      vx_core.Type_anylist vx_p_disallowvalues = val.disallowvalues();
      vx_core.Type_argmap vx_p_properties = val.properties();
      vx_core.Type_arg vx_p_proplast = val.proplast();
      vx_core.Type_typelist vx_p_traits = val.traits();
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
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_pkgname = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":extends":
            if (valsub == vx_p_extend) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_extend = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_extend = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("extends"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub is vx_core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (vx_core.Type_funclist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("allowfuncs"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowtypes":
            if (valsub == vx_p_allowtypes) {
            } else if (valsub is vx_core.Type_typelist) {
              ischanged = true;
              vx_p_allowtypes = (vx_core.Type_typelist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("allowtypes"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowvalues":
            if (valsub == vx_p_allowvalues) {
            } else if (valsub is vx_core.Type_anylist) {
              ischanged = true;
              vx_p_allowvalues = (vx_core.Type_anylist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("allowvalues"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowfuncs":
            if (valsub == vx_p_disallowfuncs) {
            } else if (valsub is vx_core.Type_funclist) {
              ischanged = true;
              vx_p_disallowfuncs = (vx_core.Type_funclist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("disallowfuncs"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowtypes":
            if (valsub == vx_p_disallowtypes) {
            } else if (valsub is vx_core.Type_typelist) {
              ischanged = true;
              vx_p_disallowtypes = (vx_core.Type_typelist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("disallowtypes"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowvalues":
            if (valsub == vx_p_disallowvalues) {
            } else if (valsub is vx_core.Type_anylist) {
              ischanged = true;
              vx_p_disallowvalues = (vx_core.Type_anylist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("disallowvalues"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":properties":
            if (valsub == vx_p_properties) {
            } else if (valsub is vx_core.Type_argmap) {
              ischanged = true;
              vx_p_properties = (vx_core.Type_argmap)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("properties"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":proplast":
            if (valsub == vx_p_proplast) {
            } else if (valsub is vx_core.Type_arg) {
              ischanged = true;
              vx_p_proplast = (vx_core.Type_arg)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("proplast"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":traits":
            if (valsub == vx_p_traits) {
            } else if (valsub is vx_core.Type_typelist) {
              ischanged = true;
              vx_p_traits = (vx_core.Type_typelist)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("traits"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/typedef", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
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
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typedef;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "typedef", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_typedef e_typedef = new Class_typedef();
  public static Type_typedef t_typedef = new Class_typedef();

  /**
   * type: typelist
   * List of Types
   * (type typelist)
   */
  public interface Type_typelist : vx_core.Type_list {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_typelist : vx_core.Class_base, Type_typelist {

    protected List<vx_core.Type_any> vx_p_list = vx_core.immutablelist(new ArrayList<vx_core.Type_any>());

    public List<vx_core.Type_any> vx_list() {
      List<vx_core.Type_any> output = vx_core.immutablelist(new ArrayList<vx_core.Type_any>(this.vx_p_list));
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_int index) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_typelist list = this;
      int iindex = index.vx_int();
      List<vx_core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    public override vx_core.Type_typelist vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_typelist,
       vals);
    }

    public override vx_core.Type_typelist vx_copy(params Object[] vals) {
      Type_typelist output = this;
      boolean ischanged = false;
      Class_typelist val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<vx_core.Type_any> listval = new ArrayList<>(val.vx_list());
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub is vx_core.Type_any) {
          ischanged = true;
          listval.add((vx_core.Type_any)valsub);
        } else if (valsub is vx_core.Type_typelist) {
          Type_typelist multi = (Type_typelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub is List) {
          List listunknown = valsub as List;
          foreach (Object item in listunknown) {
            if (item is vx_core.Type_any) {
              vx_core.Type_any valitem = (vx_core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub is vx_core.Type_any) {
          vx_core.Type_any anysub = valsub as vx_core.Type_any;
          msg = vx_core.vx_msg_from_error("vx/core/typelist", ":invalidtype", anysub);
          msgblock = vx_core.vx_copy(msgblock, msg);
        } else {
          msg = vx_core.vx_msg_from_error("vx/core/typelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()));
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_typelist work = new Class_typelist();
        work.vx_p_list = vx_core.immutablelist(listval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typelist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typelist;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_typelist e_typelist = new Class_typelist();
  public static Type_typelist t_typelist = new Class_typelist();

  /**
   * type: typemap
   * Map of Any Type Class
   * (type typemap)
   */
  public interface Type_typemap : vx_core.Type_map {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
  }

  public class Class_typemap : vx_core.Class_base, Type_typemap {

    protected Map<String, vx_core.Type_any> vx_p_map = vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>());

    public Map<String, vx_core.Type_any> vx_map() {
      return vx_core.immutablemap(new LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map));
    }

    public vx_core.Type_boolean vx_set(vx_core.Type_string name, vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (value is vx_core.Type_any) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        vx_core.Type_any castval = (vx_core.Type_any)value;
        Map<String, vx_core.Type_any> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == vx_core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = vx_core.immutablemap(map);
        output = vx_core.c_true;
      }
      return output;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Class_typemap map = this;
      String skey = key.vx_string();
      Map<String, vx_core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, vx_core.e_any);
      return output;
    }

    public vx_core.Type_map vx_new_from_map(Map<String, vx_core.Type_any> mapval) {
      vx_core.Class_typemap output = new vx_core.Class_typemap();
      vx_core.Type_msgblock msgblock = vx_core.e_msgblock;
      Map<String, vx_core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      foreach (String key in keys) {
        vx_core.Type_any val = mapval.get(key);
        if (val is vx_core.Type_any) {
          vx_core.Type_any castval = (vx_core.Type_any)val;
          map.put(key, castval);
        } else {
          vx_core.Type_msg msg = vx_core.vx_msg_from_error("vx/core/typemap", ":invalidvalue", val);
          msgblock = vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = vx_core.immutablemap(map);
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override vx_core.Type_typemap vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_typemap,
       vals);
    }

    public override vx_core.Type_typemap vx_copy(params Object[] vals) {
      Type_typemap output = this;
      boolean ischanged = false;
      Class_typemap val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, vx_core.Type_any> mapval = new LinkedHashMap<>(val.vx_map());
      vx_core.Type_msg msg;
      String key = "";
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstring = valsub as vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is String) {
            key = valsub as String;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/typemap", ":keyexpected", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
        } else {
          vx_core.Type_any valany = null;
          if (valsub is vx_core.Type_any) {
            valany = (vx_core.Type_any)valsub;
          } else if (valsub is vx_core.Type_any) {
            valany = valsub as vx_core.Type_any;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = valsub as vx_core.Type_any;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
            msg = vx_core.vx_msg_from_error("vx/core/typemap", ":invalidkeyvalue", msgmap);
            msgblock = vx_core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_typemap work = new Class_typemap();
        work.vx_p_map = vx_core.immutablemap(mapval);
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typemap;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typemap;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "typemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_typemap e_typemap = new Class_typemap();
  public static Type_typemap t_typemap = new Class_typemap();

  /**
   * type: user
   * User Type
   * (type user)
   */
  public interface Type_user : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_security security();
    public vx_core.Type_string username();
    public vx_core.Type_string token();
  }

  public class Class_user : vx_core.Class_base, Type_user {

    protected vx_core.Type_security vx_p_security;

    public vx_core.Type_security security() {
      return this.vx_p_security == null ? vx_core.e_security : this.vx_p_security;
    }

    protected vx_core.Type_string vx_p_username;

    public vx_core.Type_string username() {
      return this.vx_p_username == null ? vx_core.e_string : this.vx_p_username;
    }

    protected vx_core.Type_string vx_p_token;

    public vx_core.Type_string token() {
      return this.vx_p_token == null ? vx_core.e_string : this.vx_p_token;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":security", this.security());
      output.put(":username", this.username());
      output.put(":token", this.token());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_user vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_user,
       vals);
    }

    public override vx_core.Type_user vx_copy(params Object[] vals) {
      Type_user output = this;
      boolean ischanged = false;
      Class_user val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_security vx_p_security = val.security();
      vx_core.Type_string vx_p_username = val.username();
      vx_core.Type_string vx_p_token = val.token();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":security");
      validkeys.add(":username");
      validkeys.add(":token");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":security":
            if (valsub == vx_p_security) {
            } else if (valsub is vx_core.Type_security) {
              ischanged = true;
              vx_p_security = (vx_core.Type_security)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("security"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":username":
            if (valsub == vx_p_username) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_username = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_username = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("username"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":token":
            if (valsub == vx_p_token) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_token = (vx_core.Type_string)valsub;
            } else if (valsub is String) {
              ischanged = true;
              vx_p_token = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("token"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/user", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_user work = new Class_user();
        work.vx_p_security = vx_p_security;
        work.vx_p_username = vx_p_username;
        work.vx_p_token = vx_p_token;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_user;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_user;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "user", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_user e_user = new Class_user();
  public static Type_user t_user = new Class_user();

  /**
   * type: value
   * (type value)
   */
  public interface Type_value : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_any next();
    public vx_core.Type_int refs();
  }

  public class Class_value : vx_core.Class_base, Type_value {

    protected vx_core.Type_any vx_p_next;

    public vx_core.Type_any next() {
      return this.vx_p_next == null ? vx_core.e_any : this.vx_p_next;
    }

    protected vx_core.Type_int vx_p_refs;

    public vx_core.Type_int refs() {
      return this.vx_p_refs == null ? vx_core.e_int : this.vx_p_refs;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
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

    public Map<String, vx_core.Type_any> vx_map() {
      Map<String, vx_core.Type_any> output = new LinkedHashMap<>();
      output.put(":next", this.next());
      output.put(":refs", this.refs());
      return vx_core.immutablemap(output);
    }

    public override vx_core.Type_value vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_value,
       vals);
    }

    public override vx_core.Type_value vx_copy(params Object[] vals) {
      Type_value output = this;
      boolean ischanged = false;
      Class_value val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_any vx_p_next = val.next();
      vx_core.Type_int vx_p_refs = val.refs();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":next");
      validkeys.add(":refs");
      String key = "";
      vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            vx_core.Type_any msgval;
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.toString());
            }
            msg = vx_core.vx_msg_from_error("vx/core/value", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              vx_core.Type_any msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/core/value", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":next":
            if (valsub == vx_p_next) {
            } else if (valsub is vx_core.Type_any) {
              ischanged = true;
              vx_p_next = (vx_core.Type_any)valsub;
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("next"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/value", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":refs":
            if (valsub == vx_p_refs) {
            } else if (valsub is vx_core.Type_int) {
              ischanged = true;
              vx_p_refs = (vx_core.Type_int)valsub;
            } else if (valsub is Integer) {
              ischanged = true;
              vx_p_refs = vx_core.vx_new(vx_core.t_int, valsub);
            } else {
              vx_core.Type_any msgval;
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.toString());
              }
              Map<String, vx_core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", vx_core.vx_new_string("refs"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/core/value", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            vx_core.Type_any msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/core/value", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_value work = new Class_value();
        work.vx_p_next = vx_p_next;
        work.vx_p_refs = vx_p_refs;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_value;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_value;
    }

    override
    public vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/core", // pkgname
        "value", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_value e_value = new Class_value();
  public static Type_value t_value = new Class_value();

  /**
   * Constant: false
   * {boolean}
   */
  public class Const_false : vx_core.Class_boolean, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "false", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_false output) {
    }

    public override bool vx_boolean() {
      this.vxboolean = false;
      return this.vxboolean;
    }

  }

  public static Const_false c_false = new Const_false();

  public static Type_boolean e_boolean = c_false;

  /**
   * Constant: global
   * Global variable for project data.
   * {project}
   */
  public class Const_global : vx_core.Class_project, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "global", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "project", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_global output) {
    }


  }

  public static Const_global c_global = new Const_global();


  /**
   * Constant: infinity
   * Infinity. Returned during unusual calculations.
   * {int}
   */
  public class Const_infinity : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "infinity", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_infinity output) {
    }

    override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static Const_infinity c_infinity = new Const_infinity();


  /**
   * Constant: mempool-active
   * Active Value Memory Pool
   * {mempool}
   */
  public class Const_mempool_active : vx_core.Class_mempool, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "mempool-active", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "mempool", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_mempool_active output) {
    }


  }

  public static Const_mempool_active c_mempool_active = new Const_mempool_active();


  /**
   * Constant: msg-error
   * Message is an Error
   * {int}
   */
  public class Const_msg_error : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "msg-error", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_msg_error output) {
    }

    override
    public int vx_int() {
      this.vxint = 2;
      return this.vxint;
    }

  }

  public static Const_msg_error c_msg_error = new Const_msg_error();


  /**
   * Constant: msg-info
   * Message is just information
   * {int}
   */
  public class Const_msg_info : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "msg-info", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_msg_info output) {
    }

    override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static Const_msg_info c_msg_info = new Const_msg_info();


  /**
   * Constant: msg-severe
   * Message is a Severe Error
   * {int}
   */
  public class Const_msg_severe : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "msg-severe", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_msg_severe output) {
    }

    override
    public int vx_int() {
      this.vxint = 3;
      return this.vxint;
    }

  }

  public static Const_msg_severe c_msg_severe = new Const_msg_severe();


  /**
   * Constant: msg-warning
   * Message is a Warning
   * {int}
   */
  public class Const_msg_warning : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "msg-warning", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_msg_warning output) {
    }

    override
    public int vx_int() {
      this.vxint = 1;
      return this.vxint;
    }

  }

  public static Const_msg_warning c_msg_warning = new Const_msg_warning();


  /**
   * Constant: neginfinity
   * Negative Infinity. Returned during unusual calculations.
   * {int}
   */
  public class Const_neginfinity : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "neginfinity", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_neginfinity output) {
    }

    override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static Const_neginfinity c_neginfinity = new Const_neginfinity();


  /**
   * Constant: newline
   * New line constant
   * {string}
   */
  public class Const_newline : vx_core.Class_string, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "newline", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_newline output) {
    }

    override
    public String vx_string() {
      this.vxstring = "\n";
      return this.vxstring;
    }

  }

  public static Const_newline c_newline = new Const_newline();


  /**
   * Constant: notanumber
   * Not a number. Returned during invalid calculations.
   * {int}
   */
  public class Const_notanumber : vx_core.Class_int, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "notanumber", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_notanumber output) {
    }

    override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static Const_notanumber c_notanumber = new Const_notanumber();


  /**
   * Constant: nothing
   * Nothing Value. Opposite of every other value. e.g. Nil, Null
   * {string}
   */
  public class Const_nothing : vx_core.Class_string, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "nothing", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_nothing output) {
    }

    override
    public String vx_string() {
      this.vxstring = "nothing";
      return this.vxstring;
    }

  }

  public static Const_nothing c_nothing = new Const_nothing();


  /**
   * Constant: quote
   * Quotation mark constant
   * {string}
   */
  public class Const_quote : vx_core.Class_string, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "quote", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_quote output) {
    }

    override
    public String vx_string() {
      this.vxstring = "\"";
      return this.vxstring;
    }

  }

  public static Const_quote c_quote = new Const_quote();


  /**
   * Constant: true
   * {boolean}
   */
  public class Const_true : vx_core.Class_boolean, vx_core.vx_Type_const {

    override
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/core", // pkgname
        "true", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_true output) {
    }

    public override bool vx_boolean() {
      this.vxboolean = true;
      return this.vxboolean;
    }

  }

  public static Const_true c_true = new Const_true();

  /**
   * @function not
   * Boolean not
   * @param  {boolean} val Thing to not
   * @return {boolean}
   * (func !)
   */
  public interface Func_not : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_not(vx_core.Type_boolean val);
  }

  public class Class_not : vx_core.Class_base, Func_not {

    public override vx_core.Func_not vx_new(params Object[] vals) {
      Class_not output = new Class_not();
      return output;
    }

    public override vx_core.Func_not vx_copy(params Object[] vals) {
      Class_not output = new Class_not();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "!", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_not;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_not;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_boolean inputval = (vx_core.Type_boolean)value;
      vx_core.Type_any outputval = vx_core.f_not(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_boolean val = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_not(val);
      return output;
    }

    override
    public vx_core.Type_boolean vx_not(vx_core.Type_boolean val) {
      return vx_core.f_not(val);
    }

  }

  public static Func_not e_not = new vx_core.Class_not();
  public static Func_not t_not = new vx_core.Class_not();

  public static vx_core.Type_boolean f_not(vx_core.Type_boolean val) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function notempty
   * Returns true if text is not empty.
   * @param  {string} text
   * @return {boolean}
   * (func !-empty)
   */
  public interface Func_notempty : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_notempty(vx_core.Type_string text);
  }

  public class Class_notempty : vx_core.Class_base, Func_notempty {

    public override vx_core.Func_notempty vx_new(params Object[] vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    public override vx_core.Func_notempty vx_copy(params Object[] vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_notempty;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_notempty;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_notempty(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_notempty(text);
      return output;
    }

    override
    public vx_core.Type_boolean vx_notempty(vx_core.Type_string text) {
      return vx_core.f_notempty(text);
    }

  }

  public static Func_notempty e_notempty = new vx_core.Class_notempty();
  public static Func_notempty t_notempty = new vx_core.Class_notempty();

  public static vx_core.Type_boolean f_notempty(vx_core.Type_string text) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_is_empty(text)
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
  public interface Func_notempty_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_notempty_1(vx_core.Type_any val);
  }

  public class Class_notempty_1 : vx_core.Class_base, Func_notempty_1 {

    public override vx_core.Func_notempty_1 vx_new(params Object[] vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    public override vx_core.Func_notempty_1 vx_copy(params Object[] vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_notempty_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_notempty_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_notempty_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_notempty_1(val);
      return output;
    }

    override
    public vx_core.Type_boolean vx_notempty_1(vx_core.Type_any val) {
      return vx_core.f_notempty_1(val);
    }

  }

  public static Func_notempty_1 e_notempty_1 = new vx_core.Class_notempty_1();
  public static Func_notempty_1 t_notempty_1 = new vx_core.Class_notempty_1();

  public static vx_core.Type_boolean f_notempty_1(vx_core.Type_any val) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_is_empty_1(val)
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
  public interface Func_ne : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_ne(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_ne : vx_core.Class_base, Func_ne {

    public override vx_core.Func_ne vx_new(params Object[] vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    public override vx_core.Func_ne vx_copy(params Object[] vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "!=", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_ne;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_ne;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_ne(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_ne(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_ne(val1, val2);
    }

  }

  public static Func_ne e_ne = new vx_core.Class_ne();
  public static Func_ne t_ne = new vx_core.Class_ne();

  public static vx_core.Type_boolean f_ne(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_eq(val1, val2)
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
  public interface Func_neqeq : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_neqeq(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_neqeq : vx_core.Class_base, Func_neqeq {

    public override vx_core.Func_neqeq vx_new(params Object[] vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    public override vx_core.Func_neqeq vx_copy(params Object[] vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "!==", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_neqeq;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_neqeq;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_neqeq(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_neqeq(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_neqeq(val1, val2);
    }

  }

  public static Func_neqeq e_neqeq = new vx_core.Class_neqeq();
  public static Func_neqeq t_neqeq = new vx_core.Class_neqeq();

  public static vx_core.Type_boolean f_neqeq(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_eqeq(val1, val2)
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
  public interface Func_multiply : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_multiply(vx_core.Type_int num1, vx_core.Type_int num2);
  }

  public class Class_multiply : vx_core.Class_base, Func_multiply {

    public override vx_core.Func_multiply vx_new(params Object[] vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    public override vx_core.Func_multiply vx_copy(params Object[] vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_multiply;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_multiply;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int num1 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int num2 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_multiply(num1, num2);
      return output;
    }

    override
    public vx_core.Type_int vx_multiply(vx_core.Type_int num1, vx_core.Type_int num2) {
      return vx_core.f_multiply(num1, num2);
    }

  }

  public static Func_multiply e_multiply = new vx_core.Class_multiply();
  public static Func_multiply t_multiply = new vx_core.Class_multiply();

  public static vx_core.Type_int f_multiply(vx_core.Type_int num1, vx_core.Type_int num2) {
    vx_core.Type_int output = vx_core.e_int;
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
  public interface Func_multiply_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_number vx_multiply_1(vx_core.Type_number num1, vx_core.Type_number num2);
  }

  public class Class_multiply_1 : vx_core.Class_base, Func_multiply_1 {

    public override vx_core.Func_multiply_1 vx_new(params Object[] vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    public override vx_core.Func_multiply_1 vx_copy(params Object[] vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_multiply_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_multiply_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_number num1 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_number num2 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_multiply_1(num1, num2);
      return output;
    }

    override
    public vx_core.Type_number vx_multiply_1(vx_core.Type_number num1, vx_core.Type_number num2) {
      return vx_core.f_multiply_1(num1, num2);
    }

  }

  public static Func_multiply_1 e_multiply_1 = new vx_core.Class_multiply_1();
  public static Func_multiply_1 t_multiply_1 = new vx_core.Class_multiply_1();

  public static vx_core.Type_number f_multiply_1(vx_core.Type_number num1, vx_core.Type_number num2) {
    vx_core.Type_number output = vx_core.e_number;
    return output;
  }

  /**
   * @function multiply 2
   * Math multiply
   * @param  {intlist} nums
   * @return {int}
   * (func *)
   */
  public interface Func_multiply_2 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_multiply_2(vx_core.Type_intlist nums);
  }

  public class Class_multiply_2 : vx_core.Class_base, Func_multiply_2 {

    public override vx_core.Func_multiply_2 vx_new(params Object[] vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    public override vx_core.Func_multiply_2 vx_copy(params Object[] vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_multiply_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_multiply_2;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_intlist inputval = (vx_core.Type_intlist)value;
      vx_core.Type_any outputval = vx_core.f_multiply_2(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_intlist nums = vx_core.f_any_from_any(vx_core.t_intlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_multiply_2(nums);
      return output;
    }

    override
    public vx_core.Type_int vx_multiply_2(vx_core.Type_intlist nums) {
      return vx_core.f_multiply_2(nums);
    }

  }

  public static Func_multiply_2 e_multiply_2 = new vx_core.Class_multiply_2();
  public static Func_multiply_2 t_multiply_2 = new vx_core.Class_multiply_2();

  public static vx_core.Type_int f_multiply_2(vx_core.Type_intlist nums) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_int,
      nums,
      vx_core.vx_new_int(1),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_int total = vx_core.f_any_from_any(vx_core.t_int, total_any);
        vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, num_any);
        return 
        vx_core.f_multiply(total, num);
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
  public interface Func_multiply_3 : vx_core.Func_any_from_any {
    public vx_core.Type_number vx_multiply_3(vx_core.Type_numberlist nums);
  }

  public class Class_multiply_3 : vx_core.Class_base, Func_multiply_3 {

    public override vx_core.Func_multiply_3 vx_new(params Object[] vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    public override vx_core.Func_multiply_3 vx_copy(params Object[] vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        3, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_multiply_3;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_multiply_3;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_numberlist inputval = (vx_core.Type_numberlist)value;
      vx_core.Type_any outputval = vx_core.f_multiply_3(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_numberlist nums = vx_core.f_any_from_any(vx_core.t_numberlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_multiply_3(nums);
      return output;
    }

    override
    public vx_core.Type_number vx_multiply_3(vx_core.Type_numberlist nums) {
      return vx_core.f_multiply_3(nums);
    }

  }

  public static Func_multiply_3 e_multiply_3 = new vx_core.Class_multiply_3();
  public static Func_multiply_3 t_multiply_3 = new vx_core.Class_multiply_3();

  public static vx_core.Type_number f_multiply_3(vx_core.Type_numberlist nums) {
    vx_core.Type_number output = vx_core.e_number;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_number,
      nums,
      vx_core.vx_new_int(1),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_number total = vx_core.f_any_from_any(vx_core.t_number, total_any);
        vx_core.Type_number num = vx_core.f_any_from_any(vx_core.t_number, num_any);
        return 
        vx_core.f_multiply_1(total, num);
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
  public interface Func_plus : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_plus(vx_core.Type_int num1, vx_core.Type_int num2);
  }

  public class Class_plus : vx_core.Class_base, Func_plus {

    public override vx_core.Func_plus vx_new(params Object[] vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    public override vx_core.Func_plus vx_copy(params Object[] vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_plus;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_plus;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int num1 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int num2 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_plus(num1, num2);
      return output;
    }

    override
    public vx_core.Type_int vx_plus(vx_core.Type_int num1, vx_core.Type_int num2) {
      return vx_core.f_plus(num1, num2);
    }

  }

  public static Func_plus e_plus = new vx_core.Class_plus();
  public static Func_plus t_plus = new vx_core.Class_plus();

  public static vx_core.Type_int f_plus(vx_core.Type_int num1, vx_core.Type_int num2) {
    vx_core.Type_int output = vx_core.e_int;
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
  public interface Func_plus_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_number vx_plus_1(vx_core.Type_number num1, vx_core.Type_number num2);
  }

  public class Class_plus_1 : vx_core.Class_base, Func_plus_1 {

    public override vx_core.Func_plus_1 vx_new(params Object[] vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    public override vx_core.Func_plus_1 vx_copy(params Object[] vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_plus_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_plus_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_number num1 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_number num2 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_plus_1(num1, num2);
      return output;
    }

    override
    public vx_core.Type_number vx_plus_1(vx_core.Type_number num1, vx_core.Type_number num2) {
      return vx_core.f_plus_1(num1, num2);
    }

  }

  public static Func_plus_1 e_plus_1 = new vx_core.Class_plus_1();
  public static Func_plus_1 t_plus_1 = new vx_core.Class_plus_1();

  public static vx_core.Type_number f_plus_1(vx_core.Type_number num1, vx_core.Type_number num2) {
    vx_core.Type_number output = vx_core.e_number;
    return output;
  }

  /**
   * @function plus 2
   * Math int plus
   * @param  {intlist} nums
   * @return {int}
   * (func +)
   */
  public interface Func_plus_2 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_plus_2(vx_core.Type_intlist nums);
  }

  public class Class_plus_2 : vx_core.Class_base, Func_plus_2 {

    public override vx_core.Func_plus_2 vx_new(params Object[] vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    public override vx_core.Func_plus_2 vx_copy(params Object[] vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_plus_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_plus_2;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_intlist inputval = (vx_core.Type_intlist)value;
      vx_core.Type_any outputval = vx_core.f_plus_2(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_intlist nums = vx_core.f_any_from_any(vx_core.t_intlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_plus_2(nums);
      return output;
    }

    override
    public vx_core.Type_int vx_plus_2(vx_core.Type_intlist nums) {
      return vx_core.f_plus_2(nums);
    }

  }

  public static Func_plus_2 e_plus_2 = new vx_core.Class_plus_2();
  public static Func_plus_2 t_plus_2 = new vx_core.Class_plus_2();

  public static vx_core.Type_int f_plus_2(vx_core.Type_intlist nums) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_int,
      nums,
      vx_core.vx_new_int(0),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_int total = vx_core.f_any_from_any(vx_core.t_int, total_any);
        vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, num_any);
        return 
        vx_core.f_plus(total, num);
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
  public interface Func_plus_3 : vx_core.Func_any_from_any {
    public vx_core.Type_number vx_plus_3(vx_core.Type_numberlist nums);
  }

  public class Class_plus_3 : vx_core.Class_base, Func_plus_3 {

    public override vx_core.Func_plus_3 vx_new(params Object[] vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    public override vx_core.Func_plus_3 vx_copy(params Object[] vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        3, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_plus_3;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_plus_3;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_numberlist inputval = (vx_core.Type_numberlist)value;
      vx_core.Type_any outputval = vx_core.f_plus_3(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_numberlist nums = vx_core.f_any_from_any(vx_core.t_numberlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_plus_3(nums);
      return output;
    }

    override
    public vx_core.Type_number vx_plus_3(vx_core.Type_numberlist nums) {
      return vx_core.f_plus_3(nums);
    }

  }

  public static Func_plus_3 e_plus_3 = new vx_core.Class_plus_3();
  public static Func_plus_3 t_plus_3 = new vx_core.Class_plus_3();

  public static vx_core.Type_number f_plus_3(vx_core.Type_numberlist nums) {
    vx_core.Type_number output = vx_core.e_number;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_number,
      nums,
      vx_core.vx_new_int(0),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_number total = vx_core.f_any_from_any(vx_core.t_number, total_any);
        vx_core.Type_number num = vx_core.f_any_from_any(vx_core.t_number, num_any);
        return 
        vx_core.f_plus_1(total, num);
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
  public interface Func_plus1 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_plus1(vx_core.Type_int num);
  }

  public class Class_plus1 : vx_core.Class_base, Func_plus1 {

    public override vx_core.Func_plus1 vx_new(params Object[] vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    public override vx_core.Func_plus1 vx_copy(params Object[] vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "+1", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_plus1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_plus1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_int inputval = (vx_core.Type_int)value;
      vx_core.Type_any outputval = vx_core.f_plus1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_plus1(num);
      return output;
    }

    override
    public vx_core.Type_int vx_plus1(vx_core.Type_int num) {
      return vx_core.f_plus1(num);
    }

  }

  public static Func_plus1 e_plus1 = new vx_core.Class_plus1();
  public static Func_plus1 t_plus1 = new vx_core.Class_plus1();

  public static vx_core.Type_int f_plus1(vx_core.Type_int num) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_plus(num, vx_core.vx_new_int(1));
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
  public interface Func_minus : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_minus(vx_core.Type_int num1, vx_core.Type_int num2);
  }

  public class Class_minus : vx_core.Class_base, Func_minus {

    public override vx_core.Func_minus vx_new(params Object[] vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    public override vx_core.Func_minus vx_copy(params Object[] vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_minus;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_minus;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int num1 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int num2 = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_minus(num1, num2);
      return output;
    }

    override
    public vx_core.Type_int vx_minus(vx_core.Type_int num1, vx_core.Type_int num2) {
      return vx_core.f_minus(num1, num2);
    }

  }

  public static Func_minus e_minus = new vx_core.Class_minus();
  public static Func_minus t_minus = new vx_core.Class_minus();

  public static vx_core.Type_int f_minus(vx_core.Type_int num1, vx_core.Type_int num2) {
    vx_core.Type_int output = vx_core.e_int;
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
  public interface Func_minus_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_number vx_minus_1(vx_core.Type_number num1, vx_core.Type_number num2);
  }

  public class Class_minus_1 : vx_core.Class_base, Func_minus_1 {

    public override vx_core.Func_minus_1 vx_new(params Object[] vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    public override vx_core.Func_minus_1 vx_copy(params Object[] vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_minus_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_minus_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_number num1 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_number num2 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_minus_1(num1, num2);
      return output;
    }

    override
    public vx_core.Type_number vx_minus_1(vx_core.Type_number num1, vx_core.Type_number num2) {
      return vx_core.f_minus_1(num1, num2);
    }

  }

  public static Func_minus_1 e_minus_1 = new vx_core.Class_minus_1();
  public static Func_minus_1 t_minus_1 = new vx_core.Class_minus_1();

  public static vx_core.Type_number f_minus_1(vx_core.Type_number num1, vx_core.Type_number num2) {
    vx_core.Type_number output = vx_core.e_number;
    return output;
  }

  /**
   * @function minus 2
   * Math integer minus
   * @param  {intlist} nums
   * @return {int}
   * (func -)
   */
  public interface Func_minus_2 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_minus_2(vx_core.Type_intlist nums);
  }

  public class Class_minus_2 : vx_core.Class_base, Func_minus_2 {

    public override vx_core.Func_minus_2 vx_new(params Object[] vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    public override vx_core.Func_minus_2 vx_copy(params Object[] vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_minus_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_minus_2;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_intlist inputval = (vx_core.Type_intlist)value;
      vx_core.Type_any outputval = vx_core.f_minus_2(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_intlist nums = vx_core.f_any_from_any(vx_core.t_intlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_minus_2(nums);
      return output;
    }

    override
    public vx_core.Type_int vx_minus_2(vx_core.Type_intlist nums) {
      return vx_core.f_minus_2(nums);
    }

  }

  public static Func_minus_2 e_minus_2 = new vx_core.Class_minus_2();
  public static Func_minus_2 t_minus_2 = new vx_core.Class_minus_2();

  public static vx_core.Type_int f_minus_2(vx_core.Type_intlist nums) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_int,
      nums,
      vx_core.vx_new_int(0),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_int total = vx_core.f_any_from_any(vx_core.t_int, total_any);
        vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, num_any);
        return 
        vx_core.f_minus(total, num);
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
  public interface Func_minus_3 : vx_core.Func_any_from_any {
    public vx_core.Type_number vx_minus_3(vx_core.Type_numberlist nums);
  }

  public class Class_minus_3 : vx_core.Class_base, Func_minus_3 {

    public override vx_core.Func_minus_3 vx_new(params Object[] vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    public override vx_core.Func_minus_3 vx_copy(params Object[] vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        3, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_minus_3;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_minus_3;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_numberlist inputval = (vx_core.Type_numberlist)value;
      vx_core.Type_any outputval = vx_core.f_minus_3(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_numberlist nums = vx_core.f_any_from_any(vx_core.t_numberlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_minus_3(nums);
      return output;
    }

    override
    public vx_core.Type_number vx_minus_3(vx_core.Type_numberlist nums) {
      return vx_core.f_minus_3(nums);
    }

  }

  public static Func_minus_3 e_minus_3 = new vx_core.Class_minus_3();
  public static Func_minus_3 t_minus_3 = new vx_core.Class_minus_3();

  public static vx_core.Type_number f_minus_3(vx_core.Type_numberlist nums) {
    vx_core.Type_number output = vx_core.e_number;
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_number,
      nums,
      vx_core.vx_new_int(0),
      vx_core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        vx_core.Type_number total = vx_core.f_any_from_any(vx_core.t_number, total_any);
        vx_core.Type_number num = vx_core.f_any_from_any(vx_core.t_number, num_any);
        return 
        vx_core.f_minus_1(total, num);
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
  public interface Func_minus1 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_minus1(vx_core.Type_int num);
  }

  public class Class_minus1 : vx_core.Class_base, Func_minus1 {

    public override vx_core.Func_minus1 vx_new(params Object[] vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    public override vx_core.Func_minus1 vx_copy(params Object[] vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "-1", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_minus1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_minus1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_int inputval = (vx_core.Type_int)value;
      vx_core.Type_any outputval = vx_core.f_minus1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_minus1(num);
      return output;
    }

    override
    public vx_core.Type_int vx_minus1(vx_core.Type_int num) {
      return vx_core.f_minus1(num);
    }

  }

  public static Func_minus1 e_minus1 = new vx_core.Class_minus1();
  public static Func_minus1 t_minus1 = new vx_core.Class_minus1();

  public static vx_core.Type_int f_minus1(vx_core.Type_int num) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_minus(num, vx_core.vx_new_int(1));
    return output;
  }

  /**
   * @function dotmethod
   * Not Recommened: Support for Object Oriented dot notation. e.g. (this.foo 'a') = this.foo('a')
   * @param  {any} target
   * @param  {string} method
   * @param  {anylist} parameters
   * @return {any}
   * (func .)
   */
  public interface Func_dotmethod : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_any vx_dotmethod(vx_core.Type_any target, vx_core.Type_string method, vx_core.Type_anylist parameters);
  }

  public class Class_dotmethod : vx_core.Class_base, Func_dotmethod {

    public override vx_core.Func_dotmethod vx_new(params Object[] vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    public override vx_core.Func_dotmethod vx_copy(params Object[] vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        ".", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_dotmethod;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_dotmethod;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any target = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string method = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_anylist parameters = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_dotmethod(target, method, parameters);
      return output;
    }

    override
    public vx_core.Type_any vx_dotmethod(vx_core.Type_any target, vx_core.Type_string method, vx_core.Type_anylist parameters) {
      return vx_core.f_dotmethod(target, method, parameters);
    }

  }

  public static Func_dotmethod e_dotmethod = new vx_core.Class_dotmethod();
  public static Func_dotmethod t_dotmethod = new vx_core.Class_dotmethod();

  public static vx_core.Type_any f_dotmethod(vx_core.Type_any target, vx_core.Type_string method, vx_core.Type_anylist parameters) {
    vx_core.Type_any output = vx_core.e_any;
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
  public interface Func_divide : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_number vx_divide(vx_core.Type_number num1, vx_core.Type_number num2);
  }

  public class Class_divide : vx_core.Class_base, Func_divide {

    public override vx_core.Func_divide vx_new(params Object[] vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    public override vx_core.Func_divide vx_copy(params Object[] vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "/", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_divide;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_divide;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_number num1 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_number num2 = vx_core.f_any_from_any(vx_core.t_number, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_divide(num1, num2);
      return output;
    }

    override
    public vx_core.Type_number vx_divide(vx_core.Type_number num1, vx_core.Type_number num2) {
      return vx_core.f_divide(num1, num2);
    }

  }

  public static Func_divide e_divide = new vx_core.Class_divide();
  public static Func_divide t_divide = new vx_core.Class_divide();

  public static vx_core.Type_number f_divide(vx_core.Type_number num1, vx_core.Type_number num2) {
    vx_core.Type_number output = vx_core.e_number;
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
  public interface Func_lt : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_lt(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_lt : vx_core.Class_base, Func_lt {

    public override vx_core.Func_lt vx_new(params Object[] vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    public override vx_core.Func_lt vx_copy(params Object[] vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_lt;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_lt;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_lt(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_lt(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_lt(val1, val2);
    }

  }

  public static Func_lt e_lt = new vx_core.Class_lt();
  public static Func_lt t_lt = new vx_core.Class_lt();

  public static vx_core.Type_boolean f_lt(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_switch(
      vx_core.t_boolean,
      vx_core.f_compare(val1, val2),
      vx_core.vx_new(vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_core.vx_new_int(-1),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(true);
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(false);
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
  public interface Func_lt_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_lt_1(vx_core.Type_anylist values);
  }

  public class Class_lt_1 : vx_core.Class_base, Func_lt_1 {

    public override vx_core.Func_lt_1 vx_new(params Object[] vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    public override vx_core.Func_lt_1 vx_copy(params Object[] vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_lt_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_lt_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_lt_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist values = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_lt_1(values);
      return output;
    }

    override
    public vx_core.Type_boolean vx_lt_1(vx_core.Type_anylist values) {
      return vx_core.f_lt_1(values);
    }

  }

  public static Func_lt_1 e_lt_1 = new vx_core.Class_lt_1();
  public static Func_lt_1 t_lt_1 = new vx_core.Class_lt_1();

  public static vx_core.Type_boolean f_lt_1(vx_core.Type_anylist values) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_any_from_list_start_reduce_next(
      vx_core.t_boolean,
      values,
      vx_core.vx_new_boolean(true),
      vx_core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        vx_core.Type_boolean reduce = vx_core.f_any_from_any(vx_core.t_boolean, reduce_any);
        vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, current_any);
        vx_core.Type_any next = vx_core.f_any_from_any(vx_core.t_any, next_any);
        return 
        vx_core.f_and(
          reduce,
          vx_core.f_lt(current, next)
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
  public interface Func_chainfirst : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_chainfirst<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any;
  }

  public class Class_chainfirst : vx_core.Class_base, Func_chainfirst {

    public override vx_core.Func_chainfirst vx_new(params Object[] vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    public override vx_core.Func_chainfirst vx_copy(params Object[] vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<-", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_chainfirst;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_chainfirst;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any_from_anylist fnlist = vx_core.f_any_from_any(vx_core.t_any_from_anylist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_chainfirst(generic_any_1, value, fnlist);
      return output;
    }

    override
    public T vx_chainfirst<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any {
      return vx_core.f_chainfirst(generic_any_1, value, fnlist);
    }

  }

  public static Func_chainfirst e_chainfirst = new vx_core.Class_chainfirst();
  public static Func_chainfirst t_chainfirst = new vx_core.Class_chainfirst();

  public static T f_chainfirst<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_chainlast : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_chainlast<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any;
  }

  public class Class_chainlast : vx_core.Class_base, Func_chainlast {

    public override vx_core.Func_chainlast vx_new(params Object[] vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    public override vx_core.Func_chainlast vx_copy(params Object[] vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<<-", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_chainlast;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_chainlast;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any_from_anylist fnlist = vx_core.f_any_from_any(vx_core.t_any_from_anylist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_chainlast(generic_any_1, value, fnlist);
      return output;
    }

    override
    public T vx_chainlast<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any {
      return vx_core.f_chainlast(generic_any_1, value, fnlist);
    }

  }

  public static Func_chainlast e_chainlast = new vx_core.Class_chainlast();
  public static Func_chainlast t_chainlast = new vx_core.Class_chainlast();

  public static T f_chainlast<T>(T generic_any_1, T value, vx_core.Type_any_from_anylist fnlist) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_le : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_le(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_le : vx_core.Class_base, Func_le {

    public override vx_core.Func_le vx_new(params Object[] vals) {
      Class_le output = new Class_le();
      return output;
    }

    public override vx_core.Func_le vx_copy(params Object[] vals) {
      Class_le output = new Class_le();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_le;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_le;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_le(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_le(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_le(val1, val2);
    }

  }

  public static Func_le e_le = new vx_core.Class_le();
  public static Func_le t_le = new vx_core.Class_le();

  public static vx_core.Type_boolean f_le(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_gt(val1, val2)
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
  public interface Func_le_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_le_1(vx_core.Type_anylist args);
  }

  public class Class_le_1 : vx_core.Class_base, Func_le_1 {

    public override vx_core.Func_le_1 vx_new(params Object[] vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    public override vx_core.Func_le_1 vx_copy(params Object[] vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_le_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_le_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_le_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist args = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_le_1(args);
      return output;
    }

    override
    public vx_core.Type_boolean vx_le_1(vx_core.Type_anylist args) {
      return vx_core.f_le_1(args);
    }

  }

  public static Func_le_1 e_le_1 = new vx_core.Class_le_1();
  public static Func_le_1 t_le_1 = new vx_core.Class_le_1();

  public static vx_core.Type_boolean f_le_1(vx_core.Type_anylist args) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_gt_1(args)
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
  public interface Func_eq : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_eq(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_eq : vx_core.Class_base, Func_eq {

    public override vx_core.Func_eq vx_new(params Object[] vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    public override vx_core.Func_eq vx_copy(params Object[] vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_eq;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_eq;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_eq(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_eq(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_eq(val1, val2);
    }

  }

  public static Func_eq e_eq = new vx_core.Class_eq();
  public static Func_eq t_eq = new vx_core.Class_eq();

  public static vx_core.Type_boolean f_eq(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function eq 1
   * Boolean equal/equivalent
   * @param  {anylist} values
   * @return {boolean}
   * (func =)
   */
  public interface Func_eq_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_eq_1(vx_core.Type_anylist values);
  }

  public class Class_eq_1 : vx_core.Class_base, Func_eq_1 {

    public override vx_core.Func_eq_1 vx_new(params Object[] vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    public override vx_core.Func_eq_1 vx_copy(params Object[] vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_eq_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_eq_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_eq_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist values = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_eq_1(values);
      return output;
    }

    override
    public vx_core.Type_boolean vx_eq_1(vx_core.Type_anylist values) {
      return vx_core.f_eq_1(values);
    }

  }

  public static Func_eq_1 e_eq_1 = new vx_core.Class_eq_1();
  public static Func_eq_1 t_eq_1 = new vx_core.Class_eq_1();

  public static vx_core.Type_boolean f_eq_1(vx_core.Type_anylist values) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_any_from_list_start_reduce_next(
      vx_core.t_boolean,
      values,
      vx_core.vx_new_boolean(false),
      vx_core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        vx_core.Type_boolean reduce = vx_core.f_any_from_any(vx_core.t_boolean, reduce_any);
        vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, current_any);
        vx_core.Type_any next = vx_core.f_any_from_any(vx_core.t_any, next_any);
        return 
        vx_core.f_and(
          reduce,
          vx_core.f_eq(current, next)
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
  public interface Func_eqeq : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_eqeq(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_eqeq : vx_core.Class_base, Func_eqeq {

    public override vx_core.Func_eqeq vx_new(params Object[] vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    public override vx_core.Func_eqeq vx_copy(params Object[] vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "==", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_eqeq;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_eqeq;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_eqeq(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_eqeq(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_eqeq(val1, val2);
    }

  }

  public static Func_eqeq e_eqeq = new vx_core.Class_eqeq();
  public static Func_eqeq t_eqeq = new vx_core.Class_eqeq();

  public static vx_core.Type_boolean f_eqeq(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
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
  public interface Func_gt : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_gt(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_gt : vx_core.Class_base, Func_gt {

    public override vx_core.Func_gt vx_new(params Object[] vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    public override vx_core.Func_gt vx_copy(params Object[] vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_gt;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_gt;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_gt(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_gt(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_gt(val1, val2);
    }

  }

  public static Func_gt e_gt = new vx_core.Class_gt();
  public static Func_gt t_gt = new vx_core.Class_gt();

  public static vx_core.Type_boolean f_gt(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_switch(
      vx_core.t_boolean,
      vx_core.f_compare(val1, val2),
      vx_core.vx_new(vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_core.vx_new_int(1),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(true);
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(false);
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
  public interface Func_gt_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_gt_1(vx_core.Type_anylist values);
  }

  public class Class_gt_1 : vx_core.Class_base, Func_gt_1 {

    public override vx_core.Func_gt_1 vx_new(params Object[] vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    public override vx_core.Func_gt_1 vx_copy(params Object[] vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_gt_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_gt_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_gt_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist values = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_gt_1(values);
      return output;
    }

    override
    public vx_core.Type_boolean vx_gt_1(vx_core.Type_anylist values) {
      return vx_core.f_gt_1(values);
    }

  }

  public static Func_gt_1 e_gt_1 = new vx_core.Class_gt_1();
  public static Func_gt_1 t_gt_1 = new vx_core.Class_gt_1();

  public static vx_core.Type_boolean f_gt_1(vx_core.Type_anylist values) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_any_from_list_start_reduce_next(
      vx_core.t_boolean,
      values,
      vx_core.vx_new_boolean(true),
      vx_core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        vx_core.Type_boolean reduce = vx_core.f_any_from_any(vx_core.t_boolean, reduce_any);
        vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, current_any);
        vx_core.Type_any next = vx_core.f_any_from_any(vx_core.t_any, next_any);
        return 
        vx_core.f_and(
          reduce,
          vx_core.f_gt(current, next)
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
  public interface Func_ge : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_ge(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_ge : vx_core.Class_base, Func_ge {

    public override vx_core.Func_ge vx_new(params Object[] vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    public override vx_core.Func_ge vx_copy(params Object[] vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_ge;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_ge;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_ge(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_ge(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_ge(val1, val2);
    }

  }

  public static Func_ge e_ge = new vx_core.Class_ge();
  public static Func_ge t_ge = new vx_core.Class_ge();

  public static vx_core.Type_boolean f_ge(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_lt(val1, val2)
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
  public interface Func_ge_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_ge_1(vx_core.Type_anylist args);
  }

  public class Class_ge_1 : vx_core.Class_base, Func_ge_1 {

    public override vx_core.Func_ge_1 vx_new(params Object[] vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    public override vx_core.Func_ge_1 vx_copy(params Object[] vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_ge_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_ge_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_ge_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist args = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_ge_1(args);
      return output;
    }

    override
    public vx_core.Type_boolean vx_ge_1(vx_core.Type_anylist args) {
      return vx_core.f_ge_1(args);
    }

  }

  public static Func_ge_1 e_ge_1 = new vx_core.Class_ge_1();
  public static Func_ge_1 t_ge_1 = new vx_core.Class_ge_1();

  public static vx_core.Type_boolean f_ge_1(vx_core.Type_anylist args) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_not(
      vx_core.f_lt_1(args)
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
  public interface Func_allowfuncs_from_security : vx_core.Func_any_from_any {
    public vx_core.Type_funclist vx_allowfuncs_from_security(vx_core.Type_security security);
  }

  public class Class_allowfuncs_from_security : vx_core.Class_base, Func_allowfuncs_from_security {

    public override vx_core.Func_allowfuncs_from_security vx_new(params Object[] vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    public override vx_core.Func_allowfuncs_from_security vx_copy(params Object[] vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "allowfuncs<-security", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "funclist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_func), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_allowfuncs_from_security;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_allowfuncs_from_security;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_security inputval = (vx_core.Type_security)value;
      vx_core.Type_any outputval = vx_core.f_allowfuncs_from_security(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_security security = vx_core.f_any_from_any(vx_core.t_security, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_allowfuncs_from_security(security);
      return output;
    }

    override
    public vx_core.Type_funclist vx_allowfuncs_from_security(vx_core.Type_security security) {
      return vx_core.f_allowfuncs_from_security(security);
    }

  }

  public static Func_allowfuncs_from_security e_allowfuncs_from_security = new vx_core.Class_allowfuncs_from_security();
  public static Func_allowfuncs_from_security t_allowfuncs_from_security = new vx_core.Class_allowfuncs_from_security();

  public static vx_core.Type_funclist f_allowfuncs_from_security(vx_core.Type_security security) {
    vx_core.Type_funclist output = vx_core.e_funclist;
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
  public interface Func_allowtypenames_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_stringlist vx_allowtypenames_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_allowtypenames_from_typedef : vx_core.Class_base, Func_allowtypenames_from_typedef {

    public override vx_core.Func_allowtypenames_from_typedef vx_new(params Object[] vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    public override vx_core.Func_allowtypenames_from_typedef vx_copy(params Object[] vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "allowtypenames<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_allowtypenames_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_allowtypenames_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_allowtypenames_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_allowtypenames_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_stringlist vx_allowtypenames_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_allowtypenames_from_typedef(vtypedef);
    }

  }

  public static Func_allowtypenames_from_typedef e_allowtypenames_from_typedef = new vx_core.Class_allowtypenames_from_typedef();
  public static Func_allowtypenames_from_typedef t_allowtypenames_from_typedef = new vx_core.Class_allowtypenames_from_typedef();

  public static vx_core.Type_stringlist f_allowtypenames_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_stringlist output = vx_core.e_stringlist;
    output = vx_core.f_typenames_from_typelist(
      vx_core.f_allowtypes_from_typedef(vtypedef)
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
  public interface Func_allowtypes_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_typelist vx_allowtypes_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_allowtypes_from_typedef : vx_core.Class_base, Func_allowtypes_from_typedef {

    public override vx_core.Func_allowtypes_from_typedef vx_new(params Object[] vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    public override vx_core.Func_allowtypes_from_typedef vx_copy(params Object[] vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "allowtypes<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_allowtypes_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_allowtypes_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_allowtypes_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_allowtypes_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_typelist vx_allowtypes_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_allowtypes_from_typedef(vtypedef);
    }

  }

  public static Func_allowtypes_from_typedef e_allowtypes_from_typedef = new vx_core.Class_allowtypes_from_typedef();
  public static Func_allowtypes_from_typedef t_allowtypes_from_typedef = new vx_core.Class_allowtypes_from_typedef();

  public static vx_core.Type_typelist f_allowtypes_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_typelist output = vx_core.e_typelist;
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
  public interface Func_and : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_and(vx_core.Type_boolean val1, vx_core.Type_boolean val2);
  }

  public class Class_and : vx_core.Class_base, Func_and {

    public override vx_core.Func_and vx_new(params Object[] vals) {
      Class_and output = new Class_and();
      return output;
    }

    public override vx_core.Func_and vx_copy(params Object[] vals) {
      Class_and output = new Class_and();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_and;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_and;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_boolean val1 = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_boolean val2 = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_and(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_and(vx_core.Type_boolean val1, vx_core.Type_boolean val2) {
      return vx_core.f_and(val1, val2);
    }

  }

  public static Func_and e_and = new vx_core.Class_and();
  public static Func_and t_and = new vx_core.Class_and();

  public static vx_core.Type_boolean f_and(vx_core.Type_boolean val1, vx_core.Type_boolean val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function and 1
   * Returns true if all values are true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func and)
   */
  public interface Func_and_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_and_1(vx_core.Type_booleanlist values);
  }

  public class Class_and_1 : vx_core.Class_base, Func_and_1 {

    public override vx_core.Func_and_1 vx_new(params Object[] vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    public override vx_core.Func_and_1 vx_copy(params Object[] vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_and_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_and_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_booleanlist inputval = (vx_core.Type_booleanlist)value;
      vx_core.Type_any outputval = vx_core.f_and_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_booleanlist values = vx_core.f_any_from_any(vx_core.t_booleanlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_and_1(values);
      return output;
    }

    override
    public vx_core.Type_boolean vx_and_1(vx_core.Type_booleanlist values) {
      return vx_core.f_and_1(values);
    }

  }

  public static Func_and_1 e_and_1 = new vx_core.Class_and_1();
  public static Func_and_1 t_and_1 = new vx_core.Class_and_1();

  public static vx_core.Type_boolean f_and_1(vx_core.Type_booleanlist values) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_switch(
      vx_core.t_boolean,
      vx_core.f_length_1(values),
      vx_core.vx_new(vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_core.vx_new_int(0),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(true);
          })
        ),
        vx_core.f_case_1(
          vx_core.vx_new_int(1),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.f_any_from_list(vx_core.t_boolean, values, vx_core.vx_new_int(1));
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.f_any_from_list_start_reduce_next(
              vx_core.t_boolean,
              values,
              vx_core.vx_new_boolean(true),
              vx_core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
                vx_core.Type_boolean reduce = vx_core.f_any_from_any(vx_core.t_boolean, reduce_any);
                vx_core.Type_boolean current = vx_core.f_any_from_any(vx_core.t_boolean, current_any);
                vx_core.Type_boolean next = vx_core.f_any_from_any(vx_core.t_boolean, next_any);
                return 
                  vx_core.f_and(
                    reduce,
                    vx_core.f_and(current, next)
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
  public interface Func_any_from_any : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn);
    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_any : vx_core.Class_base, Func_any_from_any {

    public IFn fn = null;

    override
    public Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      Class_any_from_any output = new Class_any_from_any();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_any vx_new(params Object[] vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    public override vx_core.Func_any_from_any vx_copy(params Object[] vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_any;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_any value);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_any_from_any(generic_any_1, value);
      return output;
    }

    override
    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(value);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any e_any_from_any = new vx_core.Class_any_from_any();
  public static Func_any_from_any t_any_from_any = new vx_core.Class_any_from_any();

  public static T f_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_any_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_any_async vx_fn_new(vx_core.Class_any_from_any_async.IFn fn);
    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_any_async : vx_core.Class_base, Func_any_from_any_async {

    public IFn fn = null;

    override
    public Func_any_from_any_async vx_fn_new(vx_core.Class_any_from_any_async.IFn fn) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_any_async vx_new(params Object[] vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    public override vx_core.Func_any_from_any_async vx_copy(params Object[] vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_any_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_any_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve(vx_core.Type_any value);
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_any_async(generic_any_1, value);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve(value);
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_any_async e_any_from_any_async = new vx_core.Class_any_from_any_async();
  public static Func_any_from_any_async t_any_from_any_async = new vx_core.Class_any_from_any_async();

  public static Task<T> f_any_from_any_async<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_any_context
   * Function Type taking any value any-2 and returning generic any-1 using context
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context)
   */
  public interface Func_any_from_any_context : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn);
    public T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_any_context : vx_core.Class_base, Func_any_from_any_context {

    public IFn fn = null;

    override
    public Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_any_context vx_new(params Object[] vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    public override vx_core.Func_any_from_any_context vx_copy(params Object[] vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_any_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_any_context;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_context context, vx_core.Type_any value);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_any_from_any_context(generic_any_1, context, value);
      return output;
    }

    override
    public T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(context, value);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any_context e_any_from_any_context = new vx_core.Class_any_from_any_context();
  public static Func_any_from_any_context t_any_from_any_context = new vx_core.Class_any_from_any_context();

  public static T f_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_any_context_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_any_context_async vx_fn_new(vx_core.Class_any_from_any_context_async.IFn fn);
    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_any_context_async : vx_core.Class_base, Func_any_from_any_context_async {

    public IFn fn = null;

    override
    public Func_any_from_any_context_async vx_fn_new(vx_core.Class_any_from_any_context_async.IFn fn) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_any_context_async vx_new(params Object[] vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    public override vx_core.Func_any_from_any_context_async vx_copy(params Object[] vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_any_context_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_any_context_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve(vx_core.Type_context context, vx_core.Type_any value);
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_any_context_async(generic_any_1, context, value);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve(context, value);
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_any_context_async e_any_from_any_context_async = new vx_core.Class_any_from_any_context_async();
  public static Func_any_from_any_context_async t_any_from_any_context_async = new vx_core.Class_any_from_any_context_async();

  public static Task<T> f_any_from_any_context_async<T, U>(T generic_any_1, vx_core.Type_context context, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_any_key_value
   * Generic Function returning Generic any-1 from a any-1, a key, and a value.
   * @param  {any-1} current
   * @param  {string} key
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-key-value)
   */
  public interface Func_any_from_any_key_value : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_any_key_value vx_fn_new(vx_core.Class_any_from_any_key_value.IFn fn);
    public T vx_any_from_any_key_value<T, U>(T generic_any_1, T current, vx_core.Type_string key, U value) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_any_key_value : vx_core.Class_base, Func_any_from_any_key_value {

    public IFn fn = null;

    override
    public Func_any_from_any_key_value vx_fn_new(vx_core.Class_any_from_any_key_value.IFn fn) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_any_key_value vx_new(params Object[] vals) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      return output;
    }

    public override vx_core.Func_any_from_any_key_value vx_copy(params Object[] vals) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-key-value", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_any_key_value;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_any_key_value;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_any current, vx_core.Type_string key, vx_core.Type_any value);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_any_from_any_key_value(generic_any_1, current, key, value);
      return output;
    }

    override
    public T vx_any_from_any_key_value<T, U>(T generic_any_1, T current, vx_core.Type_string key, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(current, key, value);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any_key_value e_any_from_any_key_value = new vx_core.Class_any_from_any_key_value();
  public static Func_any_from_any_key_value t_any_from_any_key_value = new vx_core.Class_any_from_any_key_value();

  public static T f_any_from_any_key_value<T, U>(T generic_any_1, T current, vx_core.Type_string key, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_func
   * Generic Function returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func)
   */
  public interface Func_any_from_func : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn);
    public T vx_any_from_func<T>(T generic_any_1) where T : vx_core.Type_any;
  }

  public class Class_any_from_func : vx_core.Class_base, Func_any_from_func {

    public IFn fn = null;

    override
    public Func_any_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn) {
      Class_any_from_func output = new Class_any_from_func();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_func vx_new(params Object[] vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    public override vx_core.Func_any_from_func vx_copy(params Object[] vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_func;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve();
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_any_from_func(generic_any_1);
      return output;
    }

    override
    public T vx_any_from_func<T>(T generic_any_1) where T : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve();
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_func e_any_from_func = new vx_core.Class_any_from_func();
  public static Func_any_from_func t_any_from_func = new vx_core.Class_any_from_func();

  public static T f_any_from_func<T>(T generic_any_1) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_func_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_func_async vx_fn_new(vx_core.Class_any_from_func_async.IFn fn);
    public Task<T> vx_any_from_func_async<T>(T generic_any_1) where T : vx_core.Type_any;
  }

  public class Class_any_from_func_async : vx_core.Class_base, Func_any_from_func_async {

    public IFn fn = null;

    override
    public Func_any_from_func_async vx_fn_new(vx_core.Class_any_from_func_async.IFn fn) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_func_async vx_new(params Object[] vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    public override vx_core.Func_any_from_func_async vx_copy(params Object[] vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-func-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_func_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_func_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve();
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_func_async(generic_any_1);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_func_async<T>(T generic_any_1) where T : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve();
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_func_async e_any_from_func_async = new vx_core.Class_any_from_func_async();
  public static Func_any_from_func_async t_any_from_func_async = new vx_core.Class_any_from_func_async();

  public static Task<T> f_any_from_func_async<T>(T generic_any_1) where T : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_int
   * Generic Function returning Generic any-1 from an int
   * @param  {int} value
   * @return {any-1}
   * (func any<-int)
   */
  public interface Func_any_from_int : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_int vx_fn_new(vx_core.Class_any_from_int.IFn fn);
    public T vx_any_from_int<T>(T generic_any_1, vx_core.Type_int value) where T : vx_core.Type_any;
  }

  public class Class_any_from_int : vx_core.Class_base, Func_any_from_int {

    public IFn fn = null;

    override
    public Func_any_from_int vx_fn_new(vx_core.Class_any_from_int.IFn fn) {
      Class_any_from_int output = new Class_any_from_int();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_int vx_new(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    public override vx_core.Func_any_from_int vx_copy(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-int", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_int;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_int;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_int value);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int value = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_any_from_int(generic_any_1, value);
      return output;
    }

    override
    public T vx_any_from_int<T>(T generic_any_1, vx_core.Type_int value) where T : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(value);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_int e_any_from_int = new vx_core.Class_any_from_int();
  public static Func_any_from_int t_any_from_int = new vx_core.Class_any_from_int();

  public static T f_any_from_int<T>(T generic_any_1, vx_core.Type_int value) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_int_any
   * Generic Function returning Generic any-1 from an int and a value
   * @param  {int} num
   * @param  {any-2} val
   * @return {any-1}
   * (func any<-int-any)
   */
  public interface Func_any_from_int_any : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_int_any vx_fn_new(vx_core.Class_any_from_int_any.IFn fn);
    public T vx_any_from_int_any<T, U>(T generic_any_1, vx_core.Type_int num, U val) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_int_any : vx_core.Class_base, Func_any_from_int_any {

    public IFn fn = null;

    override
    public Func_any_from_int_any vx_fn_new(vx_core.Class_any_from_int_any.IFn fn) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_int_any vx_new(params Object[] vals) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      return output;
    }

    public override vx_core.Func_any_from_int_any vx_copy(params Object[] vals) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-int-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_int_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_int_any;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_int num, vx_core.Type_any val);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int num = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_int_any(generic_any_1, num, val);
      return output;
    }

    override
    public T vx_any_from_int_any<T, U>(T generic_any_1, vx_core.Type_int num, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(num, val);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_int_any e_any_from_int_any = new vx_core.Class_any_from_int_any();
  public static Func_any_from_int_any t_any_from_int_any = new vx_core.Class_any_from_int_any();

  public static T f_any_from_int_any<T, U>(T generic_any_1, vx_core.Type_int num, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_key_value : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_key_value vx_fn_new(vx_core.Class_any_from_key_value.IFn fn);
    public T vx_any_from_key_value<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_key_value : vx_core.Class_base, Func_any_from_key_value {

    public IFn fn = null;

    override
    public Func_any_from_key_value vx_fn_new(vx_core.Class_any_from_key_value.IFn fn) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_key_value vx_new(params Object[] vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    public override vx_core.Func_any_from_key_value vx_copy(params Object[] vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_key_value;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_key_value;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_string key, vx_core.Type_any val);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_key_value(generic_any_1, key, val);
      return output;
    }

    override
    public T vx_any_from_key_value<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(key, val);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_key_value e_any_from_key_value = new vx_core.Class_any_from_key_value();
  public static Func_any_from_key_value t_any_from_key_value = new vx_core.Class_any_from_key_value();

  public static T f_any_from_key_value<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_key_value_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_key_value_async vx_fn_new(vx_core.Class_any_from_key_value_async.IFn fn);
    public Task<T> vx_any_from_key_value_async<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_key_value_async : vx_core.Class_base, Func_any_from_key_value_async {

    public IFn fn = null;

    override
    public Func_any_from_key_value_async vx_fn_new(vx_core.Class_any_from_key_value_async.IFn fn) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_key_value_async vx_new(params Object[] vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    public override vx_core.Func_any_from_key_value_async vx_copy(params Object[] vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_key_value_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_key_value_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve(vx_core.Type_string key, vx_core.Type_any val);
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_key_value_async(generic_any_1, key, val);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_key_value_async<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve(key, val);
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_key_value_async e_any_from_key_value_async = new vx_core.Class_any_from_key_value_async();
  public static Func_any_from_key_value_async t_any_from_key_value_async = new vx_core.Class_any_from_key_value_async();

  public static Task<T> f_any_from_key_value_async<T, U>(T generic_any_1, vx_core.Type_string key, U val) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
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
  public interface Func_any_from_list : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_list<T, X>(T generic_any_1, X values, vx_core.Type_int index) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_any_from_list : vx_core.Class_base, Func_any_from_list {

    public override vx_core.Func_any_from_list vx_new(params Object[] vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    public override vx_core.Func_any_from_list vx_copy(params Object[] vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_list;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int index = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_list(generic_any_1, values, index);
      return output;
    }

    override
    public T vx_any_from_list<T, X>(T generic_any_1, X values, vx_core.Type_int index) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_core.f_any_from_list(generic_any_1, values, index);
    }

  }

  public static Func_any_from_list e_any_from_list = new vx_core.Class_any_from_list();
  public static Func_any_from_list t_any_from_list = new vx_core.Class_any_from_list();

  public static T f_any_from_list<T, X>(T generic_any_1, X values, vx_core.Type_int index) where T : vx_core.Type_any where X : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_list_start_reduce
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce} fn-reduce
   * @return {any-1}
   * (func any<-list-start-reduce)
   */
  public interface Func_any_from_list_start_reduce : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce fn_reduce) where T : vx_core.Type_any where Y : vx_core.Type_list;
  }

  public class Class_any_from_list_start_reduce : vx_core.Class_base, Func_any_from_list_start_reduce {

    public override vx_core.Func_any_from_list_start_reduce vx_new(params Object[] vals) {
      Class_any_from_list_start_reduce output = new Class_any_from_list_start_reduce();
      return output;
    }

    public override vx_core.Func_any_from_list_start_reduce vx_copy(params Object[] vals) {
      Class_any_from_list_start_reduce output = new Class_any_from_list_start_reduce();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-start-reduce", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_list_start_reduce;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_list_start_reduce;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any valstart = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_reduce fn_reduce = vx_core.f_any_from_any(vx_core.t_any_from_reduce, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_any_from_list_start_reduce(generic_any_1, list, valstart, fn_reduce);
      return output;
    }

    override
    public T vx_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce fn_reduce) where T : vx_core.Type_any where Y : vx_core.Type_list {
      return vx_core.f_any_from_list_start_reduce(generic_any_1, list, valstart, fn_reduce);
    }

  }

  public static Func_any_from_list_start_reduce e_any_from_list_start_reduce = new vx_core.Class_any_from_list_start_reduce();
  public static Func_any_from_list_start_reduce t_any_from_list_start_reduce = new vx_core.Class_any_from_list_start_reduce();

  public static T f_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce fn_reduce) where T : vx_core.Type_any where Y : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_list_start_reduce_next
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce-next} fn-reduce-next
   * @return {any-1}
   * (func any<-list-start-reduce-next)
   */
  public interface Func_any_from_list_start_reduce_next : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce_next fn_reduce_next) where T : vx_core.Type_any where Y : vx_core.Type_list;
  }

  public class Class_any_from_list_start_reduce_next : vx_core.Class_base, Func_any_from_list_start_reduce_next {

    public override vx_core.Func_any_from_list_start_reduce_next vx_new(params Object[] vals) {
      Class_any_from_list_start_reduce_next output = new Class_any_from_list_start_reduce_next();
      return output;
    }

    public override vx_core.Func_any_from_list_start_reduce_next vx_copy(params Object[] vals) {
      Class_any_from_list_start_reduce_next output = new Class_any_from_list_start_reduce_next();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-start-reduce-next", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_list_start_reduce_next;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_list_start_reduce_next;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any valstart = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_reduce_next fn_reduce_next = vx_core.f_any_from_any(vx_core.t_any_from_reduce_next, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_any_from_list_start_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
      return output;
    }

    override
    public T vx_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce_next fn_reduce_next) where T : vx_core.Type_any where Y : vx_core.Type_list {
      return vx_core.f_any_from_list_start_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
    }

  }

  public static Func_any_from_list_start_reduce_next e_any_from_list_start_reduce_next = new vx_core.Class_any_from_list_start_reduce_next();
  public static Func_any_from_list_start_reduce_next t_any_from_list_start_reduce_next = new vx_core.Class_any_from_list_start_reduce_next();

  public static T f_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, vx_core.Func_any_from_reduce_next fn_reduce_next) where T : vx_core.Type_any where Y : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_map
   * Returns value from a map or empty if not found
   * @param  {map-1} valuemap
   * @param  {string} key
   * @return {any-1}
   * (func any<-map)
   */
  public interface Func_any_from_map : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_map<N, T>(T generic_any_1, N valuemap, vx_core.Type_string key) where N : vx_core.Type_map where T : vx_core.Type_any;
  }

  public class Class_any_from_map : vx_core.Class_base, Func_any_from_map {

    public override vx_core.Func_any_from_map vx_new(params Object[] vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    public override vx_core.Func_any_from_map vx_copy(params Object[] vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-map", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_map;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_map;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_map(generic_any_1, valuemap, key);
      return output;
    }

    override
    public T vx_any_from_map<N, T>(T generic_any_1, N valuemap, vx_core.Type_string key) where N : vx_core.Type_map where T : vx_core.Type_any {
      return vx_core.f_any_from_map(generic_any_1, valuemap, key);
    }

  }

  public static Func_any_from_map e_any_from_map = new vx_core.Class_any_from_map();
  public static Func_any_from_map t_any_from_map = new vx_core.Class_any_from_map();

  public static T f_any_from_map<N, T>(T generic_any_1, N valuemap, vx_core.Type_string key) where N : vx_core.Type_map where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_map_start_reduce
   * Returns a value by reducing each element of a map.
   * @param  {map-1} map
   * @param  {any-1} start
   * @param  {any<-any-key-value} fn-reduce
   * @return {any-1}
   * (func any<-map-start-reduce)
   */
  public interface Func_any_from_map_start_reduce : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, vx_core.Func_any_from_any_key_value fn_reduce) where N : vx_core.Type_map where T : vx_core.Type_any;
  }

  public class Class_any_from_map_start_reduce : vx_core.Class_base, Func_any_from_map_start_reduce {

    public override vx_core.Func_any_from_map_start_reduce vx_new(params Object[] vals) {
      Class_any_from_map_start_reduce output = new Class_any_from_map_start_reduce();
      return output;
    }

    public override vx_core.Func_any_from_map_start_reduce vx_copy(params Object[] vals) {
      Class_any_from_map_start_reduce output = new Class_any_from_map_start_reduce();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-map-start-reduce", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_map_start_reduce;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_map_start_reduce;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any_key_value fn_reduce = vx_core.f_any_from_any(vx_core.t_any_from_any_key_value, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_any_from_map_start_reduce(generic_any_1, map, start, fn_reduce);
      return output;
    }

    override
    public T vx_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, vx_core.Func_any_from_any_key_value fn_reduce) where N : vx_core.Type_map where T : vx_core.Type_any {
      return vx_core.f_any_from_map_start_reduce(generic_any_1, map, start, fn_reduce);
    }

  }

  public static Func_any_from_map_start_reduce e_any_from_map_start_reduce = new vx_core.Class_any_from_map_start_reduce();
  public static Func_any_from_map_start_reduce t_any_from_map_start_reduce = new vx_core.Class_any_from_map_start_reduce();

  public static T f_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, vx_core.Func_any_from_any_key_value fn_reduce) where N : vx_core.Type_map where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_none
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none)
   */
  public interface Func_any_from_none : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_none vx_fn_new(vx_core.Class_any_from_none.IFn fn);
    public T vx_any_from_none<T>(T generic_any_1) where T : vx_core.Type_any;
  }

  public class Class_any_from_none : vx_core.Class_base, Func_any_from_none {

    public IFn fn = null;

    override
    public Func_any_from_none vx_fn_new(vx_core.Class_any_from_none.IFn fn) {
      Class_any_from_none output = new Class_any_from_none();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_none vx_new(params Object[] vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    public override vx_core.Func_any_from_none vx_copy(params Object[] vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-none", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_none;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_none;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve();
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_any_from_none(generic_any_1);
      return output;
    }

    override
    public T vx_any_from_none<T>(T generic_any_1) where T : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve();
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_none e_any_from_none = new vx_core.Class_any_from_none();
  public static Func_any_from_none t_any_from_none = new vx_core.Class_any_from_none();

  public static T f_any_from_none<T>(T generic_any_1) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_none_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_none_async vx_fn_new(vx_core.Class_any_from_none_async.IFn fn);
    public Task<T> vx_any_from_none_async<T>(T generic_any_1) where T : vx_core.Type_any;
  }

  public class Class_any_from_none_async : vx_core.Class_base, Func_any_from_none_async {

    public IFn fn = null;

    override
    public Func_any_from_none_async vx_fn_new(vx_core.Class_any_from_none_async.IFn fn) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_none_async vx_new(params Object[] vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    public override vx_core.Func_any_from_none_async vx_copy(params Object[] vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-none-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_none_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_none_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve();
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_none_async(generic_any_1);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_none_async<T>(T generic_any_1) where T : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve();
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_none_async e_any_from_none_async = new vx_core.Class_any_from_none_async();
  public static Func_any_from_none_async t_any_from_none_async = new vx_core.Class_any_from_none_async();

  public static Task<T> f_any_from_none_async<T>(T generic_any_1) where T : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce)
   */
  public interface Func_any_from_reduce : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_reduce vx_fn_new(vx_core.Class_any_from_reduce.IFn fn);
    public T vx_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_reduce : vx_core.Class_base, Func_any_from_reduce {

    public IFn fn = null;

    override
    public Func_any_from_reduce vx_fn_new(vx_core.Class_any_from_reduce.IFn fn) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_reduce vx_new(params Object[] vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    public override vx_core.Func_any_from_reduce vx_copy(params Object[] vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_reduce;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_reduce;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_any result, vx_core.Type_any item);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any result = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any item = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_reduce(generic_any_1, result, item);
      return output;
    }

    override
    public T vx_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(result, item);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_reduce e_any_from_reduce = new vx_core.Class_any_from_reduce();
  public static Func_any_from_reduce t_any_from_reduce = new vx_core.Class_any_from_reduce();

  public static T f_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_reduce_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_reduce_async vx_fn_new(vx_core.Class_any_from_reduce_async.IFn fn);
    public Task<T> vx_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_reduce_async : vx_core.Class_base, Func_any_from_reduce_async {

    public IFn fn = null;

    override
    public Func_any_from_reduce_async vx_fn_new(vx_core.Class_any_from_reduce_async.IFn fn) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_reduce_async vx_new(params Object[] vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    public override vx_core.Func_any_from_reduce_async vx_copy(params Object[] vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_reduce_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_reduce_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve(vx_core.Type_any result, vx_core.Type_any item);
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any result = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any item = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_reduce_async(generic_any_1, result, item);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve(result, item);
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_async e_any_from_reduce_async = new vx_core.Class_any_from_reduce_async();
  public static Func_any_from_reduce_async t_any_from_reduce_async = new vx_core.Class_any_from_reduce_async();

  public static Task<T> f_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
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
  public interface Func_any_from_reduce_next : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_any_from_reduce_next vx_fn_new(vx_core.Class_any_from_reduce_next.IFn fn);
    public T vx_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_reduce_next : vx_core.Class_base, Func_any_from_reduce_next {

    public IFn fn = null;

    override
    public Func_any_from_reduce_next vx_fn_new(vx_core.Class_any_from_reduce_next.IFn fn) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_reduce_next vx_new(params Object[] vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    public override vx_core.Func_any_from_reduce_next vx_copy(params Object[] vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_reduce_next;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_reduce_next;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_any result, vx_core.Type_any current, vx_core.Type_any next);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any result = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any next = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_any_from_reduce_next(generic_any_1, result, current, next);
      return output;
    }

    override
    public T vx_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(result, current, next);
        output = vx_core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_next e_any_from_reduce_next = new vx_core.Class_any_from_reduce_next();
  public static Func_any_from_reduce_next t_any_from_reduce_next = new vx_core.Class_any_from_reduce_next();

  public static T f_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_reduce_next_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Func_any_from_reduce_next_async vx_fn_new(vx_core.Class_any_from_reduce_next_async.IFn fn);
    public Task<T> vx_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_any_from_reduce_next_async : vx_core.Class_base, Func_any_from_reduce_next_async {

    public IFn fn = null;

    override
    public Func_any_from_reduce_next_async vx_fn_new(vx_core.Class_any_from_reduce_next_async.IFn fn) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_any_from_reduce_next_async vx_new(params Object[] vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    public override vx_core.Func_any_from_reduce_next_async vx_copy(params Object[] vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_reduce_next_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_reduce_next_async;
    }

    @FunctionalInterface
    public interface IFn {
      public Task<vx_core.Type_any> resolve(vx_core.Type_any result, vx_core.Type_any current, vx_core.Type_any next);
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any result = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any current = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any next = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      Task<vx_core.Type_any> future = vx_core.f_any_from_reduce_next_async(generic_any_1, result, current, next);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Task.completedFuture(vx_core.f_empty(generic_any_1));
      } else {
        Task<vx_core.Type_any> future = fn.resolve(result, current, next);
        output = vx_core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_next_async e_any_from_reduce_next_async = new vx_core.Class_any_from_reduce_next_async();
  public static Func_any_from_reduce_next_async t_any_from_reduce_next_async = new vx_core.Class_any_from_reduce_next_async();

  public static Task<T> f_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : vx_core.Type_any where U : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
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
  public interface Func_any_from_struct : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_struct<R, T>(T generic_any_1, R vstruct, vx_core.Type_string key) where R : vx_core.Type_struct where T : vx_core.Type_any;
  }

  public class Class_any_from_struct : vx_core.Class_base, Func_any_from_struct {

    public override vx_core.Func_any_from_struct vx_new(params Object[] vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    public override vx_core.Func_any_from_struct vx_copy(params Object[] vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "any<-struct", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_any_from_struct;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_any_from_struct;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_struct vstruct = vx_core.f_any_from_any(vx_core.t_struct, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_any_from_struct(generic_any_1, vstruct, key);
      return output;
    }

    override
    public T vx_any_from_struct<R, T>(T generic_any_1, R vstruct, vx_core.Type_string key) where R : vx_core.Type_struct where T : vx_core.Type_any {
      return vx_core.f_any_from_struct(generic_any_1, vstruct, key);
    }

  }

  public static Func_any_from_struct e_any_from_struct = new vx_core.Class_any_from_struct();
  public static Func_any_from_struct t_any_from_struct = new vx_core.Class_any_from_struct();

  public static T f_any_from_struct<R, T>(T generic_any_1, R vstruct, vx_core.Type_string key) where R : vx_core.Type_struct where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_async : vx_core.Func_any_from_any_async {
    public Task<T> vx_async<T>(T generic_any_1, T value) where T : vx_core.Type_any;
  }

  public class Class_async : vx_core.Class_base, Func_async {

    public override vx_core.Func_async vx_new(params Object[] vals) {
      Class_async output = new Class_async();
      return output;
    }

    public override vx_core.Func_async vx_copy(params Object[] vals) {
      Class_async output = new Class_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_async;
    }

    override
    public vx_core.Func_any_from_any_async vx_fn_new(vx_core.Class_any_from_any_async.IFn fn) {return vx_core.e_any_from_any_async;}

    public override Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) {
      T inputval = vx_core.f_any_from_any(generic_any_1, value);
      Task<T> output = vx_core.f_async(generic_any_1, inputval);
      return output;
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_async(generic_any_1, value);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_async<T>(T generic_any_1, T value) where T : vx_core.Type_any {
      return vx_core.f_async(generic_any_1, value);
    }

  }

  public static Func_async e_async = new vx_core.Class_async();
  public static Func_async t_async = new vx_core.Class_async();

  public static Task<T> f_async<T>(T generic_any_1, T value) where T : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function boolean_permission_from_func
   * Returns true if the given func has permission.
   * @param  {func} func
   * @return {boolean}
   * (func boolean-permission<-func)
   */
  public interface Func_boolean_permission_from_func : vx_core.Func_any_from_any_context {
    public vx_core.Type_boolean vx_boolean_permission_from_func(vx_core.Type_context context, vx_core.Type_func func);
  }

  public class Class_boolean_permission_from_func : vx_core.Class_base, Func_boolean_permission_from_func {

    public override vx_core.Func_boolean_permission_from_func vx_new(params Object[] vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    public override vx_core.Func_boolean_permission_from_func vx_copy(params Object[] vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "boolean-permission<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean_permission_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean_permission_from_func;
    }

    override
    public vx_core.Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn) {
      return vx_core.e_any_from_any_context;
    }

    public override T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_func inputval = (vx_core.Type_func)value;
      vx_core.Type_any outputval = vx_core.f_boolean_permission_from_func(context, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_func func = vx_core.f_any_from_any(vx_core.t_func, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_boolean_permission_from_func(context, func);
      return output;
    }

    override
    public vx_core.Type_boolean vx_boolean_permission_from_func(vx_core.Type_context context, vx_core.Type_func func) {
      return vx_core.f_boolean_permission_from_func(context, func);
    }

  }

  public static Func_boolean_permission_from_func e_boolean_permission_from_func = new vx_core.Class_boolean_permission_from_func();
  public static Func_boolean_permission_from_func t_boolean_permission_from_func = new vx_core.Class_boolean_permission_from_func();

  public static vx_core.Type_boolean f_boolean_permission_from_func(vx_core.Type_context context, vx_core.Type_func func) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_contains_1(
      vx_core.f_allowfuncs_from_security(
        vx_core.f_security_from_context(context)
      ),
      func
    );
    return output;
  }

  /**
   * @function boolean_write_from_map_name_value
   * Returns true if it alters a mutable map false if it fails.
   * @param  {map-1} valuemap
   * @param  {string} name
   * @param  {any-1} value
   * @return {boolean}
   * (func boolean-write<-map-name-value)
   */
  public interface Func_boolean_write_from_map_name_value : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_boolean_write_from_map_name_value(vx_core.Type_map valuemap, vx_core.Type_string name, vx_core.Type_any value);
  }

  public class Class_boolean_write_from_map_name_value : vx_core.Class_base, Func_boolean_write_from_map_name_value {

    public override vx_core.Func_boolean_write_from_map_name_value vx_new(params Object[] vals) {
      Class_boolean_write_from_map_name_value output = new Class_boolean_write_from_map_name_value();
      return output;
    }

    public override vx_core.Func_boolean_write_from_map_name_value vx_copy(params Object[] vals) {
      Class_boolean_write_from_map_name_value output = new Class_boolean_write_from_map_name_value();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "boolean-write<-map-name-value", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean_write_from_map_name_value;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean_write_from_map_name_value;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string name = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_boolean_write_from_map_name_value(valuemap, name, value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_boolean_write_from_map_name_value(vx_core.Type_map valuemap, vx_core.Type_string name, vx_core.Type_any value) {
      return vx_core.f_boolean_write_from_map_name_value(valuemap, name, value);
    }

  }

  public static Func_boolean_write_from_map_name_value e_boolean_write_from_map_name_value = new vx_core.Class_boolean_write_from_map_name_value();
  public static Func_boolean_write_from_map_name_value t_boolean_write_from_map_name_value = new vx_core.Class_boolean_write_from_map_name_value();

  public static vx_core.Type_boolean f_boolean_write_from_map_name_value(vx_core.Type_map valuemap, vx_core.Type_string name, vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_any
   * Function Type taking generic any-1 and returning boolean
   * @param  {any-1} value
   * @return {boolean}
   * (func boolean<-any)
   */
  public interface Func_boolean_from_any : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_boolean_from_any vx_fn_new(vx_core.Class_boolean_from_any.IFn fn);
    public vx_core.Type_boolean vx_boolean_from_any(vx_core.Type_any value);
  }

  public class Class_boolean_from_any : vx_core.Class_base, Func_boolean_from_any {

    public IFn fn = null;

    override
    public Func_boolean_from_any vx_fn_new(vx_core.Class_boolean_from_any.IFn fn) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      output.fn = fn;
      return output;
    }

    public override vx_core.Func_boolean_from_any vx_new(params Object[] vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    public override vx_core.Func_boolean_from_any vx_copy(params Object[] vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean_from_any;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve(vx_core.Type_any value);
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_boolean_from_any(value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_boolean_from_any(vx_core.Type_any value) {
      vx_core.Type_boolean output = vx_core.c_false;
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve(value);
        output = vx_core.f_any_from_any(vx_core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_any e_boolean_from_any = new vx_core.Class_boolean_from_any();
  public static Func_boolean_from_any t_boolean_from_any = new vx_core.Class_boolean_from_any();

  public static vx_core.Type_boolean f_boolean_from_any(vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_func
   * Function Type returning boolean with any parameters
   * @return {boolean}
   * (func boolean<-func)
   */
  public interface Func_boolean_from_func : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_boolean_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn);
    public vx_core.Type_boolean vx_boolean_from_func();
  }

  public class Class_boolean_from_func : vx_core.Class_base, Func_boolean_from_func {

    public override vx_core.Func_boolean_from_func vx_new(params Object[] vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    public override vx_core.Func_boolean_from_func vx_copy(params Object[] vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean_from_func;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve();
    }

    public vx_core.Class_any_from_func.IFn fn = null;

    override
    public Func_boolean_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      output.fn = fn;
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      output = vx_core.f_boolean_from_func();
      return output;
    }

    override
    public vx_core.Type_boolean vx_boolean_from_func() {
      vx_core.Type_boolean output = vx_core.c_false;
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve();
        output = vx_core.f_any_from_any(vx_core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_func e_boolean_from_func = new vx_core.Class_boolean_from_func();
  public static Func_boolean_from_func t_boolean_from_func = new vx_core.Class_boolean_from_func();

  public static vx_core.Type_boolean f_boolean_from_func() {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_none
   * Function Type returning boolean with no parameters
   * @return {boolean}
   * (func boolean<-none)
   */
  public interface Func_boolean_from_none : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_boolean_from_none vx_fn_new(vx_core.Class_any_from_func.IFn fn);
    public vx_core.Type_boolean vx_boolean_from_none();
  }

  public class Class_boolean_from_none : vx_core.Class_base, Func_boolean_from_none {

    public override vx_core.Func_boolean_from_none vx_new(params Object[] vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    public override vx_core.Func_boolean_from_none vx_copy(params Object[] vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-none", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_boolean_from_none;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_boolean_from_none;
    }

    @FunctionalInterface
    public interface IFn {
      public vx_core.Type_any resolve();
    }

    public vx_core.Class_any_from_func.IFn fn = null;

    override
    public Func_boolean_from_none vx_fn_new(vx_core.Class_any_from_func.IFn fn) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      output.fn = fn;
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      output = vx_core.f_boolean_from_none();
      return output;
    }

    override
    public vx_core.Type_boolean vx_boolean_from_none() {
      vx_core.Type_boolean output = vx_core.c_false;
      if (fn != null) {
        vx_core.Type_any anyoutput = fn.resolve();
        output = vx_core.f_any_from_any(vx_core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_none e_boolean_from_none = new vx_core.Class_boolean_from_none();
  public static Func_boolean_from_none t_boolean_from_none = new vx_core.Class_boolean_from_none();

  public static vx_core.Type_boolean f_boolean_from_none() {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function case
   * @param  {list-1} values
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  public interface Func_case : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_thenelse vx_case(vx_core.Type_list values, vx_core.Func_any_from_func fn_any);
  }

  public class Class_case : vx_core.Class_base, Func_case {

    public override vx_core.Func_case vx_new(params Object[] vals) {
      Class_case output = new Class_case();
      return output;
    }

    public override vx_core.Func_case vx_copy(params Object[] vals) {
      Class_case output = new Class_case();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_case;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_case;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_case(values, fn_any);
      return output;
    }

    override
    public vx_core.Type_thenelse vx_case(vx_core.Type_list values, vx_core.Func_any_from_func fn_any) {
      return vx_core.f_case(values, fn_any);
    }

  }

  public static Func_case e_case = new vx_core.Class_case();
  public static Func_case t_case = new vx_core.Class_case();

  public static vx_core.Type_thenelse f_case(vx_core.Type_list values, vx_core.Func_any_from_func fn_any) {
    vx_core.Type_thenelse output = vx_core.e_thenelse;
    output = vx_core.f_new(
      vx_core.t_thenelse,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        vx_core.vx_new_string(":casemany"),
        vx_core.vx_new_string(":values"),
        values,
        vx_core.vx_new_string(":fn-any"),
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
  public interface Func_case_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_thenelse vx_case_1(vx_core.Type_any value, vx_core.Func_any_from_func fn_any);
  }

  public class Class_case_1 : vx_core.Class_base, Func_case_1 {

    public override vx_core.Func_case_1 vx_new(params Object[] vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    public override vx_core.Func_case_1 vx_copy(params Object[] vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_case_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_case_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_case_1(value, fn_any);
      return output;
    }

    override
    public vx_core.Type_thenelse vx_case_1(vx_core.Type_any value, vx_core.Func_any_from_func fn_any) {
      return vx_core.f_case_1(value, fn_any);
    }

  }

  public static Func_case_1 e_case_1 = new vx_core.Class_case_1();
  public static Func_case_1 t_case_1 = new vx_core.Class_case_1();

  public static vx_core.Type_thenelse f_case_1(vx_core.Type_any value, vx_core.Func_any_from_func fn_any) {
    vx_core.Type_thenelse output = vx_core.e_thenelse;
    output = vx_core.f_new(
      vx_core.t_thenelse,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        vx_core.vx_new_string(":case"),
        vx_core.vx_new_string(":value"),
        value,
        vx_core.vx_new_string(":fn-any"),
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
  public interface Func_compare : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_compare(vx_core.Type_any val1, vx_core.Type_any val2);
  }

  public class Class_compare : vx_core.Class_base, Func_compare {

    public override vx_core.Func_compare vx_new(params Object[] vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    public override vx_core.Func_compare vx_copy(params Object[] vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "compare", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_compare;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_compare;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val2 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_compare(val1, val2);
      return output;
    }

    override
    public vx_core.Type_int vx_compare(vx_core.Type_any val1, vx_core.Type_any val2) {
      return vx_core.f_compare(val1, val2);
    }

  }

  public static Func_compare e_compare = new vx_core.Class_compare();
  public static Func_compare t_compare = new vx_core.Class_compare();

  public static vx_core.Type_int f_compare(vx_core.Type_any val1, vx_core.Type_any val2) {
    vx_core.Type_int output = vx_core.e_int;
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
  public interface Func_contains : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_contains(vx_core.Type_string text, vx_core.Type_string find);
  }

  public class Class_contains : vx_core.Class_base, Func_contains {

    public override vx_core.Func_contains vx_new(params Object[] vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    public override vx_core.Func_contains vx_copy(params Object[] vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_contains;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_contains;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string find = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_contains(text, find);
      return output;
    }

    override
    public vx_core.Type_boolean vx_contains(vx_core.Type_string text, vx_core.Type_string find) {
      return vx_core.f_contains(text, find);
    }

  }

  public static Func_contains e_contains = new vx_core.Class_contains();
  public static Func_contains t_contains = new vx_core.Class_contains();

  public static vx_core.Type_boolean f_contains(vx_core.Type_string text, vx_core.Type_string find) {
    vx_core.Type_boolean output = vx_core.e_boolean;
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
  public interface Func_contains_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_contains_1(vx_core.Type_list values, vx_core.Type_any find);
  }

  public class Class_contains_1 : vx_core.Class_base, Func_contains_1 {

    public override vx_core.Func_contains_1 vx_new(params Object[] vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    public override vx_core.Func_contains_1 vx_copy(params Object[] vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_contains_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_contains_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any find = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_contains_1(values, find);
      return output;
    }

    override
    public vx_core.Type_boolean vx_contains_1(vx_core.Type_list values, vx_core.Type_any find) {
      return vx_core.f_contains_1(values, find);
    }

  }

  public static Func_contains_1 e_contains_1 = new vx_core.Class_contains_1();
  public static Func_contains_1 t_contains_1 = new vx_core.Class_contains_1();

  public static vx_core.Type_boolean f_contains_1(vx_core.Type_list values, vx_core.Type_any find) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function context_main
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-main)
   */
  public interface Func_context_main : vx_core.Func_any_from_any {
    public vx_core.Type_context vx_context_main(vx_core.Type_anylist args);
  }

  public class Class_context_main : vx_core.Class_base, Func_context_main {

    public override vx_core.Func_context_main vx_new(params Object[] vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    public override vx_core.Func_context_main vx_copy(params Object[] vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "context-main", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "context", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_context_main;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_context_main;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_context_main(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist args = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_context_main(args);
      return output;
    }

    override
    public vx_core.Type_context vx_context_main(vx_core.Type_anylist args) {
      return vx_core.f_context_main(args);
    }

  }

  public static Func_context_main e_context_main = new vx_core.Class_context_main();
  public static Func_context_main t_context_main = new vx_core.Class_context_main();

  public static vx_core.Type_context f_context_main(vx_core.Type_anylist args) {
    vx_core.Type_context output = vx_core.e_context;
    output = vx_core.f_empty(
      vx_core.t_context
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
  public interface Func_copy : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_copy<T>(vx_core.Type_any value, vx_core.Type_anylist values) where T : vx_core.Type_any;
  }

  public class Class_copy : vx_core.Class_base, Func_copy {

    public override vx_core.Func_copy vx_new(params Object[] vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    public override vx_core.Func_copy vx_copy(params Object[] vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "copy", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_copy;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_copy;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_anylist values = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_copy(value, values);
      return output;
    }

    override
    public T vx_copy<T>(vx_core.Type_any value, vx_core.Type_anylist values) where T : vx_core.Type_any {
      return vx_core.f_copy(value, values);
    }

  }

  public static Func_copy e_copy = new vx_core.Class_copy();
  public static Func_copy t_copy = new vx_core.Class_copy();

  public static T f_copy<T>(vx_core.Type_any value, vx_core.Type_anylist values) where T : vx_core.Type_any {
    return output;
  }

  /**
   * @function else
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func else)
   */
  public interface Func_else : vx_core.Func_any_from_any {
    public vx_core.Type_thenelse vx_else(vx_core.Func_any_from_func fn_any);
  }

  public class Class_else : vx_core.Class_base, Func_else {

    public override vx_core.Func_else vx_new(params Object[] vals) {
      Class_else output = new Class_else();
      return output;
    }

    public override vx_core.Func_else vx_copy(params Object[] vals) {
      Class_else output = new Class_else();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "else", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_else;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_else;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Func_any_from_func inputval = (vx_core.Func_any_from_func)value;
      vx_core.Type_any outputval = vx_core.f_else(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_else(fn_any);
      return output;
    }

    override
    public vx_core.Type_thenelse vx_else(vx_core.Func_any_from_func fn_any) {
      return vx_core.f_else(fn_any);
    }

  }

  public static Func_else e_else = new vx_core.Class_else();
  public static Func_else t_else = new vx_core.Class_else();

  public static vx_core.Type_thenelse f_else(vx_core.Func_any_from_func fn_any) {
    vx_core.Type_thenelse output = vx_core.e_thenelse;
    output = vx_core.f_new(
      vx_core.t_thenelse,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        vx_core.vx_new_string(":else"),
        vx_core.vx_new_string(":fn-any"),
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
  public interface Func_empty : vx_core.Func_any_from_any {
    public T vx_empty<T>(T type) where T : vx_core.Type_any;
  }

  public class Class_empty : vx_core.Class_base, Func_empty {

    public override vx_core.Func_empty vx_new(params Object[] vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    public override vx_core.Func_empty vx_copy(params Object[] vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "empty", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_empty;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_empty;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_empty(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any type = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_empty(type);
      return output;
    }

    override
    public T vx_empty<T>(T type) where T : vx_core.Type_any {
      return vx_core.f_empty(type);
    }

  }

  public static Func_empty e_empty = new vx_core.Class_empty();
  public static Func_empty t_empty = new vx_core.Class_empty();

  public static T f_empty<T>(T type) where T : vx_core.Type_any {
    return output;
  }

  /**
   * @function extends_from_any
   * @param  {any-1} val
   * @return {string}
   * (func extends<-any)
   */
  public interface Func_extends_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_extends_from_any(vx_core.Type_any val);
  }

  public class Class_extends_from_any : vx_core.Class_base, Func_extends_from_any {

    public override vx_core.Func_extends_from_any vx_new(params Object[] vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    public override vx_core.Func_extends_from_any vx_copy(params Object[] vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "extends<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_extends_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_extends_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_extends_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_extends_from_any(val);
      return output;
    }

    override
    public vx_core.Type_string vx_extends_from_any(vx_core.Type_any val) {
      return vx_core.f_extends_from_any(val);
    }

  }

  public static Func_extends_from_any e_extends_from_any = new vx_core.Class_extends_from_any();
  public static Func_extends_from_any t_extends_from_any = new vx_core.Class_extends_from_any();

  public static vx_core.Type_string f_extends_from_any(vx_core.Type_any val) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_extends_from_typedef(
      vx_core.f_typedef_from_any(val)
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
  public interface Func_extends_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_extends_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_extends_from_typedef : vx_core.Class_base, Func_extends_from_typedef {

    public override vx_core.Func_extends_from_typedef vx_new(params Object[] vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    public override vx_core.Func_extends_from_typedef vx_copy(params Object[] vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "extends<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_extends_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_extends_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_extends_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_extends_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_string vx_extends_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_extends_from_typedef(vtypedef);
    }

  }

  public static Func_extends_from_typedef e_extends_from_typedef = new vx_core.Class_extends_from_typedef();
  public static Func_extends_from_typedef t_extends_from_typedef = new vx_core.Class_extends_from_typedef();

  public static vx_core.Type_string f_extends_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_string output = vx_core.e_string;
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
  public interface Func_first_from_list : vx_core.Func_any_from_any {
    public T vx_first_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_first_from_list : vx_core.Class_base, Func_first_from_list {

    public override vx_core.Func_first_from_list vx_new(params Object[] vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    public override vx_core.Func_first_from_list vx_copy(params Object[] vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "first<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_first_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_first_from_list;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_first_from_list(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_first_from_list(generic_any_1, values);
      return output;
    }

    override
    public T vx_first_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_core.f_first_from_list(generic_any_1, values);
    }

  }

  public static Func_first_from_list e_first_from_list = new vx_core.Class_first_from_list();
  public static Func_first_from_list t_first_from_list = new vx_core.Class_first_from_list();

  public static T f_first_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_core.f_any_from_list(generic_any_1, values, vx_core.vx_new_int(1));
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
  public interface Func_first_from_list_any_from_any : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_first_from_list_any_from_any<T, X>(T generic_any_1, X values, vx_core.Func_any_from_any fn_any_from_any) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_first_from_list_any_from_any : vx_core.Class_base, Func_first_from_list_any_from_any {

    public override vx_core.Func_first_from_list_any_from_any vx_new(params Object[] vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    public override vx_core.Func_first_from_list_any_from_any vx_copy(params Object[] vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "first<-list-any<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_first_from_list_any_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_first_from_list_any_from_any;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any fn_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
      return output;
    }

    override
    public T vx_first_from_list_any_from_any<T, X>(T generic_any_1, X values, vx_core.Func_any_from_any fn_any_from_any) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
    }

  }

  public static Func_first_from_list_any_from_any e_first_from_list_any_from_any = new vx_core.Class_first_from_list_any_from_any();
  public static Func_first_from_list_any_from_any t_first_from_list_any_from_any = new vx_core.Class_first_from_list_any_from_any();

  public static T f_first_from_list_any_from_any<T, X>(T generic_any_1, X values, vx_core.Func_any_from_any fn_any_from_any) where T : vx_core.Type_any where X : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function float_from_string
   * Returns float from a given string.
   * @param  {string} text
   * @return {float}
   * (func float<-string)
   */
  public interface Func_float_from_string : vx_core.Func_any_from_any {
    public vx_core.Type_float vx_float_from_string(vx_core.Type_string text);
  }

  public class Class_float_from_string : vx_core.Class_base, Func_float_from_string {

    public override vx_core.Func_float_from_string vx_new(params Object[] vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    public override vx_core.Func_float_from_string vx_copy(params Object[] vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "float<-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "float", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_float_from_string;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_float_from_string;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_float_from_string(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_float_from_string(text);
      return output;
    }

    override
    public vx_core.Type_float vx_float_from_string(vx_core.Type_string text) {
      return vx_core.f_float_from_string(text);
    }

  }

  public static Func_float_from_string e_float_from_string = new vx_core.Class_float_from_string();
  public static Func_float_from_string t_float_from_string = new vx_core.Class_float_from_string();

  public static vx_core.Type_float f_float_from_string(vx_core.Type_string text) {
    vx_core.Type_float output = vx_core.e_float;
    return output;
  }

  /**
   * @function fn
   * Shell for lambda function calls
   * @param  {arglist} parameters
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func fn)
   */
  public interface Func_fn : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_fn<T>(T generic_any_1, vx_core.Type_arglist parameters, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any;
  }

  public class Class_fn : vx_core.Class_base, Func_fn {

    public override vx_core.Func_fn vx_new(params Object[] vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    public override vx_core.Func_fn vx_copy(params Object[] vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "fn", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_fn;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_fn;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_arglist parameters = vx_core.f_any_from_any(vx_core.t_arglist, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_fn(generic_any_1, parameters, fn_any);
      return output;
    }

    override
    public T vx_fn<T>(T generic_any_1, vx_core.Type_arglist parameters, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
      return vx_core.f_fn(generic_any_1, parameters, fn_any);
    }

  }

  public static Func_fn e_fn = new vx_core.Class_fn();
  public static Func_fn t_fn = new vx_core.Class_fn();

  public static T f_fn<T>(T generic_any_1, vx_core.Type_arglist parameters, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function funcdef_from_func
   * @param  {func} val
   * @return {funcdef}
   * (func funcdef<-func)
   */
  public interface Func_funcdef_from_func : vx_core.Func_any_from_any {
    public vx_core.Type_funcdef vx_funcdef_from_func(vx_core.Type_func val);
  }

  public class Class_funcdef_from_func : vx_core.Class_base, Func_funcdef_from_func {

    public override vx_core.Func_funcdef_from_func vx_new(params Object[] vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    public override vx_core.Func_funcdef_from_func vx_copy(params Object[] vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "funcdef<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "funcdef", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_funcdef_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_funcdef_from_func;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_func inputval = (vx_core.Type_func)value;
      vx_core.Type_any outputval = vx_core.f_funcdef_from_func(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_func val = vx_core.f_any_from_any(vx_core.t_func, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_funcdef_from_func(val);
      return output;
    }

    override
    public vx_core.Type_funcdef vx_funcdef_from_func(vx_core.Type_func val) {
      return vx_core.f_funcdef_from_func(val);
    }

  }

  public static Func_funcdef_from_func e_funcdef_from_func = new vx_core.Class_funcdef_from_func();
  public static Func_funcdef_from_func t_funcdef_from_func = new vx_core.Class_funcdef_from_func();

  public static vx_core.Type_funcdef f_funcdef_from_func(vx_core.Type_func val) {
    vx_core.Type_funcdef output = vx_core.e_funcdef;
    return output;
  }

  /**
   * @function funcname_from_funcdef
   * Get the name of a given funcdef
   * @param  {funcdef} funcdef
   * @return {string}
   * (func funcname<-funcdef)
   */
  public interface Func_funcname_from_funcdef : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_funcname_from_funcdef(vx_core.Type_funcdef funcdef);
  }

  public class Class_funcname_from_funcdef : vx_core.Class_base, Func_funcname_from_funcdef {

    public override vx_core.Func_funcname_from_funcdef vx_new(params Object[] vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    public override vx_core.Func_funcname_from_funcdef vx_copy(params Object[] vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "funcname<-funcdef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_funcname_from_funcdef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_funcname_from_funcdef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_funcdef inputval = (vx_core.Type_funcdef)value;
      vx_core.Type_any outputval = vx_core.f_funcname_from_funcdef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_funcdef funcdef = vx_core.f_any_from_any(vx_core.t_funcdef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_funcname_from_funcdef(funcdef);
      return output;
    }

    override
    public vx_core.Type_string vx_funcname_from_funcdef(vx_core.Type_funcdef funcdef) {
      return vx_core.f_funcname_from_funcdef(funcdef);
    }

  }

  public static Func_funcname_from_funcdef e_funcname_from_funcdef = new vx_core.Class_funcname_from_funcdef();
  public static Func_funcname_from_funcdef t_funcname_from_funcdef = new vx_core.Class_funcname_from_funcdef();

  public static vx_core.Type_string f_funcname_from_funcdef(vx_core.Type_funcdef funcdef) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_new(
      vx_core.t_string,
      vx_core.vx_new(vx_core.t_anylist,
        funcdef.pkgname(),
        vx_core.vx_new_string("/"),
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
  public interface Func_if : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_if<T>(T generic_any_1, vx_core.Type_boolean clause, T then) where T : vx_core.Type_any;
  }

  public class Class_if : vx_core.Class_base, Func_if {

    public override vx_core.Func_if vx_new(params Object[] vals) {
      Class_if output = new Class_if();
      return output;
    }

    public override vx_core.Func_if vx_copy(params Object[] vals) {
      Class_if output = new Class_if();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_if;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_if;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_boolean clause = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any then = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_if(generic_any_1, clause, then);
      return output;
    }

    override
    public T vx_if<T>(T generic_any_1, vx_core.Type_boolean clause, T then) where T : vx_core.Type_any {
      return vx_core.f_if(generic_any_1, clause, then);
    }

  }

  public static Func_if e_if = new vx_core.Class_if();
  public static Func_if t_if = new vx_core.Class_if();

  public static T f_if<T>(T generic_any_1, vx_core.Type_boolean clause, T then) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_if_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_if_1<T>(T generic_any_1, vx_core.Type_boolean clause, T thenval, T elseval) where T : vx_core.Type_any;
  }

  public class Class_if_1 : vx_core.Class_base, Func_if_1 {

    public override vx_core.Func_if_1 vx_new(params Object[] vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    public override vx_core.Func_if_1 vx_copy(params Object[] vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_if_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_if_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_boolean clause = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any thenval = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any elseval = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_if_1(generic_any_1, clause, thenval, elseval);
      return output;
    }

    override
    public T vx_if_1<T>(T generic_any_1, vx_core.Type_boolean clause, T thenval, T elseval) where T : vx_core.Type_any {
      return vx_core.f_if_1(generic_any_1, clause, thenval, elseval);
    }

  }

  public static Func_if_1 e_if_1 = new vx_core.Class_if_1();
  public static Func_if_1 t_if_1 = new vx_core.Class_if_1();

  public static T f_if_1<T>(T generic_any_1, vx_core.Type_boolean clause, T thenval, T elseval) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function if 2
   * Logical If function
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func if)
   */
  public interface Func_if_2 : vx_core.Func_any_from_any {
    public T vx_if_2<T>(T generic_any_1, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any;
  }

  public class Class_if_2 : vx_core.Class_base, Func_if_2 {

    public override vx_core.Func_if_2 vx_new(params Object[] vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    public override vx_core.Func_if_2 vx_copy(params Object[] vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_if_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_if_2;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_thenelselist inputval = (vx_core.Type_thenelselist)value;
      vx_core.Type_any outputval = vx_core.f_if_2(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_thenelselist thenelselist = vx_core.f_any_from_any(vx_core.t_thenelselist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_if_2(generic_any_1, thenelselist);
      return output;
    }

    override
    public T vx_if_2<T>(T generic_any_1, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any {
      return vx_core.f_if_2(generic_any_1, thenelselist);
    }

  }

  public static Func_if_2 e_if_2 = new vx_core.Class_if_2();
  public static Func_if_2 t_if_2 = new vx_core.Class_if_2();

  public static T f_if_2<T>(T generic_any_1, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function int_from_func
   * Function Type returning int with any parameters
   * @return {int}
   * (func int<-func)
   */
  public interface Func_int_from_func : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_int_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn);
    public vx_core.Type_int vx_int_from_func();
  }

  public class Class_int_from_func : vx_core.Class_base, Func_int_from_func {

    public override vx_core.Func_int_from_func vx_new(params Object[] vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    public override vx_core.Func_int_from_func vx_copy(params Object[] vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "int<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_int_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_int_from_func;
    }

    public vx_core.Class_any_from_func.IFn fn = null;

    override
    public Func_int_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn) {
      Class_int_from_func output = new Class_int_from_func();
      output.fn = fn;
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      output = vx_core.f_int_from_func();
      return output;
    }

    override
    public vx_core.Type_int vx_int_from_func() {
      return vx_core.f_int_from_func();
    }

  }

  public static Func_int_from_func e_int_from_func = new vx_core.Class_int_from_func();
  public static Func_int_from_func t_int_from_func = new vx_core.Class_int_from_func();

  public static vx_core.Type_int f_int_from_func() {
    vx_core.Type_int output = vx_core.e_int;
    return output;
  }

  /**
   * @function int_from_string
   * Function Type converting string to int
   * @param  {string} val
   * @return {int}
   * (func int<-string)
   */
  public interface Func_int_from_string : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_int_from_string(vx_core.Type_string val);
  }

  public class Class_int_from_string : vx_core.Class_base, Func_int_from_string {

    public override vx_core.Func_int_from_string vx_new(params Object[] vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    public override vx_core.Func_int_from_string vx_copy(params Object[] vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "int<-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_int_from_string;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_int_from_string;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_int_from_string(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string val = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_int_from_string(val);
      return output;
    }

    override
    public vx_core.Type_int vx_int_from_string(vx_core.Type_string val) {
      return vx_core.f_int_from_string(val);
    }

  }

  public static Func_int_from_string e_int_from_string = new vx_core.Class_int_from_string();
  public static Func_int_from_string t_int_from_string = new vx_core.Class_int_from_string();

  public static vx_core.Type_int f_int_from_string(vx_core.Type_string val) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_switch(
      vx_core.t_int,
      val,
      vx_core.vx_new(vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_core.vx_new_string("notanumber"),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.c_notanumber;
          })
        ),
        vx_core.f_case_1(
          vx_core.vx_new_string("infinity"),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.c_infinity;
          })
        ),
        vx_core.f_case_1(
          vx_core.vx_new_string("neginfinity"),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.c_neginfinity;
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new(() => {
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
  public interface Func_is_empty : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_empty(vx_core.Type_string text);
  }

  public class Class_is_empty : vx_core.Class_base, Func_is_empty {

    public override vx_core.Func_is_empty vx_new(params Object[] vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    public override vx_core.Func_is_empty vx_copy(params Object[] vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_empty;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_empty;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_is_empty(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_empty(text);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_empty(vx_core.Type_string text) {
      return vx_core.f_is_empty(text);
    }

  }

  public static Func_is_empty e_is_empty = new vx_core.Class_is_empty();
  public static Func_is_empty t_is_empty = new vx_core.Class_is_empty();

  public static vx_core.Type_boolean f_is_empty(vx_core.Type_string text) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function is_empty 1
   * Returns true if an value is empty
   * @param  {any} value
   * @return {boolean}
   * (func is-empty)
   */
  public interface Func_is_empty_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_empty_1(vx_core.Type_any value);
  }

  public class Class_is_empty_1 : vx_core.Class_base, Func_is_empty_1 {

    public override vx_core.Func_is_empty_1 vx_new(params Object[] vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    public override vx_core.Func_is_empty_1 vx_copy(params Object[] vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_empty_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_empty_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_is_empty_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_empty_1(value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_empty_1(vx_core.Type_any value) {
      return vx_core.f_is_empty_1(value);
    }

  }

  public static Func_is_empty_1 e_is_empty_1 = new vx_core.Class_is_empty_1();
  public static Func_is_empty_1 t_is_empty_1 = new vx_core.Class_is_empty_1();

  public static vx_core.Type_boolean f_is_empty_1(vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
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
  public interface Func_is_endswith : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_is_endswith(vx_core.Type_string text, vx_core.Type_string find);
  }

  public class Class_is_endswith : vx_core.Class_base, Func_is_endswith {

    public override vx_core.Func_is_endswith vx_new(params Object[] vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    public override vx_core.Func_is_endswith vx_copy(params Object[] vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-endswith", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_endswith;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_endswith;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string find = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_is_endswith(text, find);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_endswith(vx_core.Type_string text, vx_core.Type_string find) {
      return vx_core.f_is_endswith(text, find);
    }

  }

  public static Func_is_endswith e_is_endswith = new vx_core.Class_is_endswith();
  public static Func_is_endswith t_is_endswith = new vx_core.Class_is_endswith();

  public static vx_core.Type_boolean f_is_endswith(vx_core.Type_string text, vx_core.Type_string find) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function is_float
   * Returns true if the value is a float.
   * @param  {any} value
   * @return {boolean}
   * (func is-float)
   */
  public interface Func_is_float : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_float(vx_core.Type_any value);
  }

  public class Class_is_float : vx_core.Class_base, Func_is_float {

    public override vx_core.Func_is_float vx_new(params Object[] vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    public override vx_core.Func_is_float vx_copy(params Object[] vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-float", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_float;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_float;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_is_float(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_float(value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_float(vx_core.Type_any value) {
      return vx_core.f_is_float(value);
    }

  }

  public static Func_is_float e_is_float = new vx_core.Class_is_float();
  public static Func_is_float t_is_float = new vx_core.Class_is_float();

  public static vx_core.Type_boolean f_is_float(vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function is_func
   * Returns true if val is a function.
   * @param  {any} val
   * @return {boolean}
   * (func is-func)
   */
  public interface Func_is_func : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_func(vx_core.Type_any val);
  }

  public class Class_is_func : vx_core.Class_base, Func_is_func {

    public override vx_core.Func_is_func vx_new(params Object[] vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    public override vx_core.Func_is_func vx_copy(params Object[] vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_func;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_is_func(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_func(val);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_func(vx_core.Type_any val) {
      return vx_core.f_is_func(val);
    }

  }

  public static Func_is_func e_is_func = new vx_core.Class_is_func();
  public static Func_is_func t_is_func = new vx_core.Class_is_func();

  public static vx_core.Type_boolean f_is_func(vx_core.Type_any val) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function is_int
   * Returns true if the value is an integer.
   * @param  {any} value
   * @return {boolean}
   * (func is-int)
   */
  public interface Func_is_int : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_int(vx_core.Type_any value);
  }

  public class Class_is_int : vx_core.Class_base, Func_is_int {

    public override vx_core.Func_is_int vx_new(params Object[] vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    public override vx_core.Func_is_int vx_copy(params Object[] vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-int", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_int;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_int;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_is_int(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_int(value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_int(vx_core.Type_any value) {
      return vx_core.f_is_int(value);
    }

  }

  public static Func_is_int e_is_int = new vx_core.Class_is_int();
  public static Func_is_int t_is_int = new vx_core.Class_is_int();

  public static vx_core.Type_boolean f_is_int(vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function is_number
   * Return true if val is a number
   * @param  {any} value
   * @return {boolean}
   * (func is-number)
   */
  public interface Func_is_number : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_number(vx_core.Type_any value);
  }

  public class Class_is_number : vx_core.Class_base, Func_is_number {

    public override vx_core.Func_is_number vx_new(params Object[] vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    public override vx_core.Func_is_number vx_copy(params Object[] vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-number", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_number;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_number;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_is_number(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_number(value);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_number(vx_core.Type_any value) {
      return vx_core.f_is_number(value);
    }

  }

  public static Func_is_number e_is_number = new vx_core.Class_is_number();
  public static Func_is_number t_is_number = new vx_core.Class_is_number();

  public static vx_core.Type_boolean f_is_number(vx_core.Type_any value) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_switch(
      vx_core.t_boolean,
      vx_core.f_typename_from_any(value),
      vx_core.vx_new(vx_core.t_thenelselist,
        vx_core.f_case(
          vx_core.f_new(
            vx_core.t_list,
            vx_core.vx_new(vx_core.t_anylist,
              vx_core.vx_new_string("vx/core/decimal"),
              vx_core.vx_new_string("vx/core/float"),
              vx_core.vx_new_string("vx/core/int"),
              vx_core.vx_new_string("vx/core/number")
            )
          ),
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(true);
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new(() => {
            return vx_core.vx_new_boolean(false);
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
  public interface Func_is_pass_from_permission : vx_core.Func_any_from_any_context {
    public vx_core.Type_boolean vx_is_pass_from_permission(vx_core.Type_context context, vx_core.Type_permission permission);
  }

  public class Class_is_pass_from_permission : vx_core.Class_base, Func_is_pass_from_permission {

    public override vx_core.Func_is_pass_from_permission vx_new(params Object[] vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    public override vx_core.Func_is_pass_from_permission vx_copy(params Object[] vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "is-pass<-permission", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_is_pass_from_permission;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_is_pass_from_permission;
    }

    override
    public vx_core.Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn) {
      return vx_core.e_any_from_any_context;
    }

    public override T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_permission inputval = (vx_core.Type_permission)value;
      vx_core.Type_any outputval = vx_core.f_is_pass_from_permission(context, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_permission permission = vx_core.f_any_from_any(vx_core.t_permission, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_is_pass_from_permission(context, permission);
      return output;
    }

    override
    public vx_core.Type_boolean vx_is_pass_from_permission(vx_core.Type_context context, vx_core.Type_permission permission) {
      return vx_core.f_is_pass_from_permission(context, permission);
    }

  }

  public static Func_is_pass_from_permission e_is_pass_from_permission = new vx_core.Class_is_pass_from_permission();
  public static Func_is_pass_from_permission t_is_pass_from_permission = new vx_core.Class_is_pass_from_permission();

  public static vx_core.Type_boolean f_is_pass_from_permission(vx_core.Type_context context, vx_core.Type_permission permission) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_string id = permission.id();
        vx_core.Type_permission lookup = vx_core.f_permission_from_id_context(context, id);
        return vx_core.f_eq(lookup, permission);
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
  public interface Func_last_from_list : vx_core.Func_any_from_any {
    public T vx_last_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_last_from_list : vx_core.Class_base, Func_last_from_list {

    public override vx_core.Func_last_from_list vx_new(params Object[] vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    public override vx_core.Func_last_from_list vx_copy(params Object[] vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "last<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_last_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_last_from_list;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_last_from_list(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_last_from_list(generic_any_1, values);
      return output;
    }

    override
    public T vx_last_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_core.f_last_from_list(generic_any_1, values);
    }

  }

  public static Func_last_from_list e_last_from_list = new vx_core.Class_last_from_list();
  public static Func_last_from_list t_last_from_list = new vx_core.Class_last_from_list();

  public static T f_last_from_list<T, X>(T generic_any_1, X values) where T : vx_core.Type_any where X : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_int len = vx_core.f_length_1(values);
        return vx_core.f_any_from_list(generic_any_1, values, len);
      })
    );
    return output;
  }

  /**
   * @function length
   * Returns length of a string.
   * @param  {string} text
   * @return {int}
   * (func length)
   */
  public interface Func_length : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_length(vx_core.Type_string text);
  }

  public class Class_length : vx_core.Class_base, Func_length {

    public override vx_core.Func_length vx_new(params Object[] vals) {
      Class_length output = new Class_length();
      return output;
    }

    public override vx_core.Func_length vx_copy(params Object[] vals) {
      Class_length output = new Class_length();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_length;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_length;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_length(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_length(text);
      return output;
    }

    override
    public vx_core.Type_int vx_length(vx_core.Type_string text) {
      return vx_core.f_length(text);
    }

  }

  public static Func_length e_length = new vx_core.Class_length();
  public static Func_length t_length = new vx_core.Class_length();

  public static vx_core.Type_int f_length(vx_core.Type_string text) {
    vx_core.Type_int output = vx_core.e_int;
    return output;
  }

  /**
   * @function length 1
   * Returns the currently used size/length of a list
   * @param  {list-1} values
   * @return {int}
   * (func length)
   */
  public interface Func_length_1 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_length_1(vx_core.Type_list values);
  }

  public class Class_length_1 : vx_core.Class_base, Func_length_1 {

    public override vx_core.Func_length_1 vx_new(params Object[] vals) {
      Class_length_1 output = new Class_length_1();
      return output;
    }

    public override vx_core.Func_length_1 vx_copy(params Object[] vals) {
      Class_length_1 output = new Class_length_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_length_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_length_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_length_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_length_1(values);
      return output;
    }

    override
    public vx_core.Type_int vx_length_1(vx_core.Type_list values) {
      return vx_core.f_length_1(values);
    }

  }

  public static Func_length_1 e_length_1 = new vx_core.Class_length_1();
  public static Func_length_1 t_length_1 = new vx_core.Class_length_1();

  public static vx_core.Type_int f_length_1(vx_core.Type_list values) {
    vx_core.Type_int output = vx_core.e_int;
    return output;
  }

  /**
   * @function length 2
   * Returns the length of the given map.
   * @param  {map-1} valuemap
   * @return {int}
   * (func length)
   */
  public interface Func_length_2 : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_length_2(vx_core.Type_map valuemap);
  }

  public class Class_length_2 : vx_core.Class_base, Func_length_2 {

    public override vx_core.Func_length_2 vx_new(params Object[] vals) {
      Class_length_2 output = new Class_length_2();
      return output;
    }

    public override vx_core.Func_length_2 vx_copy(params Object[] vals) {
      Class_length_2 output = new Class_length_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_length_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_length_2;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_map inputval = (vx_core.Type_map)value;
      vx_core.Type_any outputval = vx_core.f_length_2(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_length_2(valuemap);
      return output;
    }

    override
    public vx_core.Type_int vx_length_2(vx_core.Type_map valuemap) {
      return vx_core.f_length_2(valuemap);
    }

  }

  public static Func_length_2 e_length_2 = new vx_core.Class_length_2();
  public static Func_length_2 t_length_2 = new vx_core.Class_length_2();

  public static vx_core.Type_int f_length_2(vx_core.Type_map valuemap) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_length_1(
      vx_core.f_stringlist_from_map(valuemap)
    );
    return output;
  }

  /**
   * @function let
   * @param  {arglist} args
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func let)
   */
  public interface Func_let : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_let<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any;
  }

  public class Class_let : vx_core.Class_base, Func_let {

    public override vx_core.Func_let vx_new(params Object[] vals) {
      Class_let output = new Class_let();
      return output;
    }

    public override vx_core.Func_let vx_copy(params Object[] vals) {
      Class_let output = new Class_let();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "let", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_let;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_let;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_let(generic_any_1, fn_any);
      return output;
    }

    override
    public T vx_let<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
      return vx_core.f_let(generic_any_1, fn_any);
    }

  }

  public static Func_let e_let = new vx_core.Class_let();
  public static Func_let t_let = new vx_core.Class_let();

  public static T f_let<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_let_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Task<T> vx_let_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any_async) where T : vx_core.Type_any;
  }

  public class Class_let_async : vx_core.Class_base, Func_let_async {

    public override vx_core.Func_let_async vx_new(params Object[] vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    public override vx_core.Func_let_async vx_copy(params Object[] vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "let-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_let_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_let_async;
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func_async fn_any_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_let_async(generic_any_1, fn_any_async);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_let_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any_async) where T : vx_core.Type_any {
      return vx_core.f_let_async(generic_any_1, fn_any_async);
    }

  }

  public static Func_let_async e_let_async = new vx_core.Class_let_async();
  public static Func_let_async t_let_async = new vx_core.Class_let_async();

  public static Task<T> f_let_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any_async) where T : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function list_join_from_list
   * Returns a list by joining the valid values in each value list
   * @param  {list-2} values
   * @return {list-1}
   * (func list-join<-list)
   */
  public interface Func_list_join_from_list : vx_core.Func_any_from_any {
    public X vx_list_join_from_list<X, Y>(X generic_any_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_join_from_list : vx_core.Class_base, Func_list_join_from_list {

    public override vx_core.Func_list_join_from_list vx_new(params Object[] vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    public override vx_core.Func_list_join_from_list vx_copy(params Object[] vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_join_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_join_from_list;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_list_join_from_list(vx_core.t_list, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_list_join_from_list(generic_list_1, values);
      return output;
    }

    override
    public X vx_list_join_from_list<X, Y>(X generic_list_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_join_from_list(generic_list_1, values);
    }

  }

  public static Func_list_join_from_list e_list_join_from_list = new vx_core.Class_list_join_from_list();
  public static Func_list_join_from_list t_list_join_from_list = new vx_core.Class_list_join_from_list();

  public static X f_list_join_from_list<X, Y>(X generic_list_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_core.f_list_join_from_list_1(
      generic_list_1,
      values,
      vx_core.t_any_from_any.vx_fn_new((value_any) => {
        vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, value_any);
        return value;
      })
    );
    return output;
  }

  /**
   * @function list_join_from_list 1
   * Returns a flattened list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list-join<-list)
   */
  public interface Func_list_join_from_list_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_join_from_list_1<X, Y>(X generic_any_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_join_from_list_1 : vx_core.Class_base, Func_list_join_from_list_1 {

    public override vx_core.Func_list_join_from_list_1 vx_new(params Object[] vals) {
      Class_list_join_from_list_1 output = new Class_list_join_from_list_1();
      return output;
    }

    public override vx_core.Func_list_join_from_list_1 vx_copy(params Object[] vals) {
      Class_list_join_from_list_1 output = new Class_list_join_from_list_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_join_from_list_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_join_from_list_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any fn_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_list_join_from_list_1(generic_list_1, values, fn_any_from_any);
      return output;
    }

    override
    public X vx_list_join_from_list_1<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_join_from_list_1(generic_list_1, values, fn_any_from_any);
    }

  }

  public static Func_list_join_from_list_1 e_list_join_from_list_1 = new vx_core.Class_list_join_from_list_1();
  public static Func_list_join_from_list_1 t_list_join_from_list_1 = new vx_core.Class_list_join_from_list_1();

  public static X f_list_join_from_list_1<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_list
   * Return a list with allowed values from another list
   * @param  {list-2} values
   * @return {list-1}
   * (func list<-list)
   */
  public interface Func_list_from_list : vx_core.Func_any_from_any {
    public X vx_list_from_list<X, Y>(X generic_any_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list : vx_core.Class_base, Func_list_from_list {

    public override vx_core.Func_list_from_list vx_new(params Object[] vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    public override vx_core.Func_list_from_list vx_copy(params Object[] vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_list;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_list_from_list(vx_core.t_list, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_list_from_list(generic_list_1, values);
      return output;
    }

    override
    public X vx_list_from_list<X, Y>(X generic_list_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_from_list(generic_list_1, values);
    }

  }

  public static Func_list_from_list e_list_from_list = new vx_core.Class_list_from_list();
  public static Func_list_from_list t_list_from_list = new vx_core.Class_list_from_list();

  public static X f_list_from_list<X, Y>(X generic_list_1, Y values) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_core.f_list_from_list_1(
      generic_list_1,
      values,
      vx_core.t_any_from_any.vx_fn_new((value_any) => {
        vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, value_any);
        return value;
      })
    );
    return output;
  }

  /**
   * @function list_from_list 1
   * Returns a list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list<-list)
   */
  public interface Func_list_from_list_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_1<X, Y>(X generic_any_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list_1 : vx_core.Class_base, Func_list_from_list_1 {

    public override vx_core.Func_list_from_list_1 vx_new(params Object[] vals) {
      Class_list_from_list_1 output = new Class_list_from_list_1();
      return output;
    }

    public override vx_core.Func_list_from_list_1 vx_copy(params Object[] vals) {
      Class_list_from_list_1 output = new Class_list_from_list_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_list_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_list_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any fn_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_list_from_list_1(generic_list_1, values, fn_any_from_any);
      return output;
    }

    override
    public X vx_list_from_list_1<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_from_list_1(generic_list_1, values, fn_any_from_any);
    }

  }

  public static Func_list_from_list_1 e_list_from_list_1 = new vx_core.Class_list_from_list_1();
  public static Func_list_from_list_1 t_list_from_list_1 = new vx_core.Class_list_from_list_1();

  public static X f_list_from_list_1<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any fn_any_from_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_list_from_list_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Task<X> vx_list_from_list_async<X, Y>(X generic_any_1, Y values, vx_core.Func_any_from_any_async fn_any_from_any_async) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list_async : vx_core.Class_base, Func_list_from_list_async {

    public override vx_core.Func_list_from_list_async vx_new(params Object[] vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    public override vx_core.Func_list_from_list_async vx_copy(params Object[] vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-list-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_list_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_list_async;
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any_async fn_any_from_any_async = vx_core.f_any_from_any(vx_core.t_any_from_any_async, arglist.vx_any(vx_core.vx_new_int(1)));
      Task<vx_core.Type_list> future = vx_core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<X> vx_list_from_list_async<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any_async fn_any_from_any_async) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
    }

  }

  public static Func_list_from_list_async e_list_from_list_async = new vx_core.Class_list_from_list_async();
  public static Func_list_from_list_async t_list_from_list_async = new vx_core.Class_list_from_list_async();

  public static Task<X> f_list_from_list_async<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_any_async fn_any_from_any_async) where X : vx_core.Type_list where Y : vx_core.Type_list {
    Task<X> output = vx_core.async_new_completed(vx_core.f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_list_intany
   * Returns a list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-int-any} fn-any<-int-any
   * @return {list-1}
   * (func list<-list-intany)
   */
  public interface Func_list_from_list_intany : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_intany<X, Y>(X generic_any_1, Y values, vx_core.Func_any_from_int_any fn_any_from_int_any) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list_intany : vx_core.Class_base, Func_list_from_list_intany {

    public override vx_core.Func_list_from_list_intany vx_new(params Object[] vals) {
      Class_list_from_list_intany output = new Class_list_from_list_intany();
      return output;
    }

    public override vx_core.Func_list_from_list_intany vx_copy(params Object[] vals) {
      Class_list_from_list_intany output = new Class_list_from_list_intany();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-list-intany", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_list_intany;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_list_intany;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_int_any fn_any_from_int_any = vx_core.f_any_from_any(vx_core.t_any_from_int_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_list_from_list_intany(generic_list_1, values, fn_any_from_int_any);
      return output;
    }

    override
    public X vx_list_from_list_intany<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_int_any fn_any_from_int_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_core.f_list_from_list_intany(generic_list_1, values, fn_any_from_int_any);
    }

  }

  public static Func_list_from_list_intany e_list_from_list_intany = new vx_core.Class_list_from_list_intany();
  public static Func_list_from_list_intany t_list_from_list_intany = new vx_core.Class_list_from_list_intany();

  public static X f_list_from_list_intany<X, Y>(X generic_list_1, Y values, vx_core.Func_any_from_int_any fn_any_from_int_any) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_map
   * Returns a list of allowed values from a map.
   * @param  {map-2} valuemap
   * @return {list-1}
   * (func list<-map)
   */
  public interface Func_list_from_map : vx_core.Func_any_from_any {
    public X vx_list_from_map<O, X>(X generic_any_1, O valuemap) where O : vx_core.Type_map where X : vx_core.Type_list;
  }

  public class Class_list_from_map : vx_core.Class_base, Func_list_from_map {

    public override vx_core.Func_list_from_map vx_new(params Object[] vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    public override vx_core.Func_list_from_map vx_copy(params Object[] vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_map;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_map;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_map inputval = (vx_core.Type_map)value;
      vx_core.Type_any outputval = vx_core.f_list_from_map(vx_core.t_list, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_list_from_map(generic_list_1, valuemap);
      return output;
    }

    override
    public X vx_list_from_map<O, X>(X generic_list_1, O valuemap) where O : vx_core.Type_map where X : vx_core.Type_list {
      return vx_core.f_list_from_map(generic_list_1, valuemap);
    }

  }

  public static Func_list_from_map e_list_from_map = new vx_core.Class_list_from_map();
  public static Func_list_from_map t_list_from_map = new vx_core.Class_list_from_map();

  public static X f_list_from_map<O, X>(X generic_list_1, O valuemap) where O : vx_core.Type_map where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_core.f_list_from_map_1(
      generic_list_1,
      valuemap,
      vx_core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, key_any);
        vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, value_any);
        return value;
      })
    );
    return output;
  }

  /**
   * @function list_from_map 1
   * Returns a list from a map by applying a function to each key value.
   * @param  {map-2} valuemap
   * @param  {any<-key-value} fn-any<-key-value
   * @return {list-1}
   * (func list<-map)
   */
  public interface Func_list_from_map_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_map_1<O, X>(X generic_any_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where O : vx_core.Type_map where X : vx_core.Type_list;
  }

  public class Class_list_from_map_1 : vx_core.Class_base, Func_list_from_map_1 {

    public override vx_core.Func_list_from_map_1 vx_new(params Object[] vals) {
      Class_list_from_map_1 output = new Class_list_from_map_1();
      return output;
    }

    public override vx_core.Func_list_from_map_1 vx_copy(params Object[] vals) {
      Class_list_from_map_1 output = new Class_list_from_map_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_map_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_map_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_key_value fn_any_from_key_value = vx_core.f_any_from_any(vx_core.t_any_from_key_value, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_list_from_map_1(generic_list_1, valuemap, fn_any_from_key_value);
      return output;
    }

    override
    public X vx_list_from_map_1<O, X>(X generic_list_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where O : vx_core.Type_map where X : vx_core.Type_list {
      return vx_core.f_list_from_map_1(generic_list_1, valuemap, fn_any_from_key_value);
    }

  }

  public static Func_list_from_map_1 e_list_from_map_1 = new vx_core.Class_list_from_map_1();
  public static Func_list_from_map_1 t_list_from_map_1 = new vx_core.Class_list_from_map_1();

  public static X f_list_from_map_1<O, X>(X generic_list_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where O : vx_core.Type_map where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_list_from_map_async : vx_core.Type_func, vx_core.Type_replfunc_async {
    public Task<X> vx_list_from_map_async<O, X>(X generic_any_1, O valuemap, vx_core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : vx_core.Type_map where X : vx_core.Type_list;
  }

  public class Class_list_from_map_async : vx_core.Class_base, Func_list_from_map_async {

    public override vx_core.Func_list_from_map_async vx_new(params Object[] vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    public override vx_core.Func_list_from_map_async vx_copy(params Object[] vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-map-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_map_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_map_async;
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_key_value_async fn_any_from_key_value_async = vx_core.f_any_from_any(vx_core.t_any_from_key_value_async, arglist.vx_any(vx_core.vx_new_int(1)));
      Task<vx_core.Type_list> future = vx_core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<X> vx_list_from_map_async<O, X>(X generic_list_1, O valuemap, vx_core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : vx_core.Type_map where X : vx_core.Type_list {
      return vx_core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
    }

  }

  public static Func_list_from_map_async e_list_from_map_async = new vx_core.Class_list_from_map_async();
  public static Func_list_from_map_async t_list_from_map_async = new vx_core.Class_list_from_map_async();

  public static Task<X> f_list_from_map_async<O, X>(X generic_list_1, O valuemap, vx_core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : vx_core.Type_map where X : vx_core.Type_list {
    Task<X> output = vx_core.async_new_completed(vx_core.f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_type
   * Create an empty list from a type. Used internally for default lists
   * @param  {any} type
   * @return {any}
   * (func list<-type)
   */
  public interface Func_list_from_type : vx_core.Func_any_from_any {
    public vx_core.Type_any vx_list_from_type(vx_core.Type_any type);
  }

  public class Class_list_from_type : vx_core.Class_base, Func_list_from_type {

    public override vx_core.Func_list_from_type vx_new(params Object[] vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    public override vx_core.Func_list_from_type vx_copy(params Object[] vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "list<-type", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_list_from_type;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_list_from_type;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_list_from_type(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any type = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_list_from_type(type);
      return output;
    }

    override
    public vx_core.Type_any vx_list_from_type(vx_core.Type_any type) {
      return vx_core.f_list_from_type(type);
    }

  }

  public static Func_list_from_type e_list_from_type = new vx_core.Class_list_from_type();
  public static Func_list_from_type t_list_from_type = new vx_core.Class_list_from_type();

  public static vx_core.Type_any f_list_from_type(vx_core.Type_any type) {
    vx_core.Type_any output = vx_core.e_any;
    return output;
  }

  /**
   * @function log
   * Writes a value to the console.
   * @param  {any} value
   * @return {any}
   * (func log)
   */
  public interface Func_log : vx_core.Func_any_from_any {
    public vx_core.Type_any vx_log(vx_core.Type_any value);
  }

  public class Class_log : vx_core.Class_base, Func_log {

    public override vx_core.Func_log vx_new(params Object[] vals) {
      Class_log output = new Class_log();
      return output;
    }

    public override vx_core.Func_log vx_copy(params Object[] vals) {
      Class_log output = new Class_log();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_log;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_log;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_log(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_log(value);
      return output;
    }

    override
    public vx_core.Type_any vx_log(vx_core.Type_any value) {
      return vx_core.f_log(value);
    }

  }

  public static Func_log e_log = new vx_core.Class_log();
  public static Func_log t_log = new vx_core.Class_log();

  public static vx_core.Type_any f_log(vx_core.Type_any value) {
    vx_core.Type_any output = vx_core.e_any;
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
  public interface Func_log_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_log_1<T>(T generic_any_1, vx_core.Type_string text, T value) where T : vx_core.Type_any;
  }

  public class Class_log_1 : vx_core.Class_base, Func_log_1 {

    public override vx_core.Func_log_1 vx_new(params Object[] vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    public override vx_core.Func_log_1 vx_copy(params Object[] vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_log_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_log_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_log_1(generic_any_1, text, value);
      return output;
    }

    override
    public T vx_log_1<T>(T generic_any_1, vx_core.Type_string text, T value) where T : vx_core.Type_any {
      return vx_core.f_log_1(generic_any_1, text, value);
    }

  }

  public static Func_log_1 e_log_1 = new vx_core.Class_log_1();
  public static Func_log_1 t_log_1 = new vx_core.Class_log_1();

  public static T f_log_1<T>(T generic_any_1, vx_core.Type_string text, T value) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function main
   * The default function for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {string}
   * (func main)
   */
  public interface Func_main : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_main(vx_core.Type_anylist args);
  }

  public class Class_main : vx_core.Class_base, Func_main {

    public override vx_core.Func_main vx_new(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override vx_core.Func_main vx_copy(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "main", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_main;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_main;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_main(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_anylist args = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_main(args);
      return output;
    }

    override
    public vx_core.Type_string vx_main(vx_core.Type_anylist args) {
      return vx_core.f_main(args);
    }

  }

  public static Func_main e_main = new vx_core.Class_main();
  public static Func_main t_main = new vx_core.Class_main();

  public static vx_core.Type_string f_main(vx_core.Type_anylist args) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_new(
      vx_core.t_string,
      args
    );
    return output;
  }

  /**
   * @function map_from_list
   * Returns a map from a list by applying a function to generate a key for each value.
   * @param  {list-2} vallist
   * @param  {any<-any} fn-any<-any
   * @return {map-1}
   * (func map<-list)
   */
  public interface Func_map_from_list : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_list<N, Y>(N generic_any_1, Y vallist, vx_core.Func_any_from_any fn_any_from_any) where N : vx_core.Type_map where Y : vx_core.Type_list;
  }

  public class Class_map_from_list : vx_core.Class_base, Func_map_from_list {

    public override vx_core.Func_map_from_list vx_new(params Object[] vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    public override vx_core.Func_map_from_list vx_copy(params Object[] vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "map<-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_map_from_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_map_from_list;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list vallist = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any fn_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
      return output;
    }

    override
    public N vx_map_from_list<N, Y>(N generic_map_1, Y vallist, vx_core.Func_any_from_any fn_any_from_any) where N : vx_core.Type_map where Y : vx_core.Type_list {
      return vx_core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
    }

  }

  public static Func_map_from_list e_map_from_list = new vx_core.Class_map_from_list();
  public static Func_map_from_list t_map_from_list = new vx_core.Class_map_from_list();

  public static N f_map_from_list<N, Y>(N generic_map_1, Y vallist, vx_core.Func_any_from_any fn_any_from_any) where N : vx_core.Type_map where Y : vx_core.Type_list {
    N output = vx_core.f_empty(generic_map_1);
    return output;
  }

  /**
   * @function map_from_map
   * Return a map with allowed values from another map
   * @param  {map-2} valuemap
   * @return {map-1}
   * (func map<-map)
   */
  public interface Func_map_from_map : vx_core.Func_any_from_any {
    public N vx_map_from_map<N, O>(N generic_any_1, O valuemap) where N : vx_core.Type_map where O : vx_core.Type_map;
  }

  public class Class_map_from_map : vx_core.Class_base, Func_map_from_map {

    public override vx_core.Func_map_from_map vx_new(params Object[] vals) {
      Class_map_from_map output = new Class_map_from_map();
      return output;
    }

    public override vx_core.Func_map_from_map vx_copy(params Object[] vals) {
      Class_map_from_map output = new Class_map_from_map();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "map<-map", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_map_from_map;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_map_from_map;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_map inputval = (vx_core.Type_map)value;
      vx_core.Type_any outputval = vx_core.f_map_from_map(vx_core.t_map, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_map_from_map(generic_map_1, valuemap);
      return output;
    }

    override
    public N vx_map_from_map<N, O>(N generic_map_1, O valuemap) where N : vx_core.Type_map where O : vx_core.Type_map {
      return vx_core.f_map_from_map(generic_map_1, valuemap);
    }

  }

  public static Func_map_from_map e_map_from_map = new vx_core.Class_map_from_map();
  public static Func_map_from_map t_map_from_map = new vx_core.Class_map_from_map();

  public static N f_map_from_map<N, O>(N generic_map_1, O valuemap) where N : vx_core.Type_map where O : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
    output = vx_core.f_map_from_map_1(
      generic_map_1,
      valuemap,
      vx_core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, key_any);
        vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, value_any);
        return value;
      })
    );
    return output;
  }

  /**
   * @function map_from_map 1
   * Returns a map from a map by applying a function to each key value.
   * @param  {map-2} valuemap
   * @param  {any<-key-value} fn-any<-key-value
   * @return {map-1}
   * (func map<-map)
   */
  public interface Func_map_from_map_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_map_1<N, O>(N generic_any_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where N : vx_core.Type_map where O : vx_core.Type_map;
  }

  public class Class_map_from_map_1 : vx_core.Class_base, Func_map_from_map_1 {

    public override vx_core.Func_map_from_map_1 vx_new(params Object[] vals) {
      Class_map_from_map_1 output = new Class_map_from_map_1();
      return output;
    }

    public override vx_core.Func_map_from_map_1 vx_copy(params Object[] vals) {
      Class_map_from_map_1 output = new Class_map_from_map_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "map<-map", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_map_from_map_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_map_from_map_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_key_value fn_any_from_key_value = vx_core.f_any_from_any(vx_core.t_any_from_key_value, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_map_from_map_1(generic_map_1, valuemap, fn_any_from_key_value);
      return output;
    }

    override
    public N vx_map_from_map_1<N, O>(N generic_map_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where N : vx_core.Type_map where O : vx_core.Type_map {
      return vx_core.f_map_from_map_1(generic_map_1, valuemap, fn_any_from_key_value);
    }

  }

  public static Func_map_from_map_1 e_map_from_map_1 = new vx_core.Class_map_from_map_1();
  public static Func_map_from_map_1 t_map_from_map_1 = new vx_core.Class_map_from_map_1();

  public static N f_map_from_map_1<N, O>(N generic_map_1, O valuemap, vx_core.Func_any_from_key_value fn_any_from_key_value) where N : vx_core.Type_map where O : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
    return output;
  }

  /**
   * @function msg_from_error
   * Returns a msg from error string
   * @param  {string} error
   * @return {msg}
   * (func msg<-error)
   */
  public interface Func_msg_from_error : vx_core.Func_any_from_any {
    public vx_core.Type_msg vx_msg_from_error(vx_core.Type_string error);
  }

  public class Class_msg_from_error : vx_core.Class_base, Func_msg_from_error {

    public override vx_core.Func_msg_from_error vx_new(params Object[] vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    public override vx_core.Func_msg_from_error vx_copy(params Object[] vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msg_from_error;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msg_from_error;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_msg_from_error(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string error = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_msg_from_error(error);
      return output;
    }

    override
    public vx_core.Type_msg vx_msg_from_error(vx_core.Type_string error) {
      return vx_core.f_msg_from_error(error);
    }

  }

  public static Func_msg_from_error e_msg_from_error = new vx_core.Class_msg_from_error();
  public static Func_msg_from_error t_msg_from_error = new vx_core.Class_msg_from_error();

  public static vx_core.Type_msg f_msg_from_error(vx_core.Type_string error) {
    vx_core.Type_msg output = vx_core.e_msg;
    output = vx_core.f_new(
      vx_core.t_msg,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":severity"),
        vx_core.c_msg_error,
        vx_core.vx_new_string(":text"),
        error
      )
    );
    return output;
  }

  /**
   * @function msg_from_error 1
   * Returns a msg from error code and detail
   * @param  {string} code
   * @param  {any} detail
   * @return {msg}
   * (func msg<-error)
   */
  public interface Func_msg_from_error_1 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_msg vx_msg_from_error_1(vx_core.Type_string code, vx_core.Type_any detail);
  }

  public class Class_msg_from_error_1 : vx_core.Class_base, Func_msg_from_error_1 {

    public override vx_core.Func_msg_from_error_1 vx_new(params Object[] vals) {
      Class_msg_from_error_1 output = new Class_msg_from_error_1();
      return output;
    }

    public override vx_core.Func_msg_from_error_1 vx_copy(params Object[] vals) {
      Class_msg_from_error_1 output = new Class_msg_from_error_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msg_from_error_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msg_from_error_1;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string code = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any detail = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_msg_from_error_1(code, detail);
      return output;
    }

    override
    public vx_core.Type_msg vx_msg_from_error_1(vx_core.Type_string code, vx_core.Type_any detail) {
      return vx_core.f_msg_from_error_1(code, detail);
    }

  }

  public static Func_msg_from_error_1 e_msg_from_error_1 = new vx_core.Class_msg_from_error_1();
  public static Func_msg_from_error_1 t_msg_from_error_1 = new vx_core.Class_msg_from_error_1();

  public static vx_core.Type_msg f_msg_from_error_1(vx_core.Type_string code, vx_core.Type_any detail) {
    vx_core.Type_msg output = vx_core.e_msg;
    output = vx_core.f_new(
      vx_core.t_msg,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        code,
        vx_core.vx_new_string(":detail"),
        detail,
        vx_core.vx_new_string(":severity"),
        vx_core.c_msg_error
      )
    );
    return output;
  }

  /**
   * @function msg_from_error 2
   * Returns a msg from error path code and detail
   * @param  {string} path
   * @param  {string} code
   * @param  {any} detail
   * @return {msg}
   * (func msg<-error)
   */
  public interface Func_msg_from_error_2 : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_msg vx_msg_from_error_2(vx_core.Type_string path, vx_core.Type_string code, vx_core.Type_any detail);
  }

  public class Class_msg_from_error_2 : vx_core.Class_base, Func_msg_from_error_2 {

    public override vx_core.Func_msg_from_error_2 vx_new(params Object[] vals) {
      Class_msg_from_error_2 output = new Class_msg_from_error_2();
      return output;
    }

    public override vx_core.Func_msg_from_error_2 vx_copy(params Object[] vals) {
      Class_msg_from_error_2 output = new Class_msg_from_error_2();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        2, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msg_from_error_2;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msg_from_error_2;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string path = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string code = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_any detail = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_msg_from_error_2(path, code, detail);
      return output;
    }

    override
    public vx_core.Type_msg vx_msg_from_error_2(vx_core.Type_string path, vx_core.Type_string code, vx_core.Type_any detail) {
      return vx_core.f_msg_from_error_2(path, code, detail);
    }

  }

  public static Func_msg_from_error_2 e_msg_from_error_2 = new vx_core.Class_msg_from_error_2();
  public static Func_msg_from_error_2 t_msg_from_error_2 = new vx_core.Class_msg_from_error_2();

  public static vx_core.Type_msg f_msg_from_error_2(vx_core.Type_string path, vx_core.Type_string code, vx_core.Type_any detail) {
    vx_core.Type_msg output = vx_core.e_msg;
    output = vx_core.f_new(
      vx_core.t_msg,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        code,
        vx_core.vx_new_string(":path"),
        path,
        vx_core.vx_new_string(":severity"),
        vx_core.c_msg_error,
        vx_core.vx_new_string(":detail"),
        detail
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
  public interface Func_msg_from_warning : vx_core.Func_any_from_any {
    public vx_core.Type_msg vx_msg_from_warning(vx_core.Type_string warning);
  }

  public class Class_msg_from_warning : vx_core.Class_base, Func_msg_from_warning {

    public override vx_core.Func_msg_from_warning vx_new(params Object[] vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    public override vx_core.Func_msg_from_warning vx_copy(params Object[] vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msg<-warning", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msg_from_warning;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msg_from_warning;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_msg_from_warning(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string warning = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_msg_from_warning(warning);
      return output;
    }

    override
    public vx_core.Type_msg vx_msg_from_warning(vx_core.Type_string warning) {
      return vx_core.f_msg_from_warning(warning);
    }

  }

  public static Func_msg_from_warning e_msg_from_warning = new vx_core.Class_msg_from_warning();
  public static Func_msg_from_warning t_msg_from_warning = new vx_core.Class_msg_from_warning();

  public static vx_core.Type_msg f_msg_from_warning(vx_core.Type_string warning) {
    vx_core.Type_msg output = vx_core.e_msg;
    output = vx_core.f_new(
      vx_core.t_msg,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":severity"),
        vx_core.c_msg_warning,
        vx_core.vx_new_string(":text"),
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
  public interface Func_msgblock_from_msgblock_msg : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_msgblock vx_msgblock_from_msgblock_msg(vx_core.Type_msgblock origblock, vx_core.Type_msg addmsg);
  }

  public class Class_msgblock_from_msgblock_msg : vx_core.Class_base, Func_msgblock_from_msgblock_msg {

    public override vx_core.Func_msgblock_from_msgblock_msg vx_new(params Object[] vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    public override vx_core.Func_msgblock_from_msgblock_msg vx_copy(params Object[] vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msg", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msgblock_from_msgblock_msg;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msgblock_from_msgblock_msg;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_msgblock origblock = vx_core.f_any_from_any(vx_core.t_msgblock, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_msg addmsg = vx_core.f_any_from_any(vx_core.t_msg, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_msgblock_from_msgblock_msg(origblock, addmsg);
      return output;
    }

    override
    public vx_core.Type_msgblock vx_msgblock_from_msgblock_msg(vx_core.Type_msgblock origblock, vx_core.Type_msg addmsg) {
      return vx_core.f_msgblock_from_msgblock_msg(origblock, addmsg);
    }

  }

  public static Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg = new vx_core.Class_msgblock_from_msgblock_msg();
  public static Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg = new vx_core.Class_msgblock_from_msgblock_msg();

  public static vx_core.Type_msgblock f_msgblock_from_msgblock_msg(vx_core.Type_msgblock origblock, vx_core.Type_msg addmsg) {
    vx_core.Type_msgblock output = vx_core.e_msgblock;
    output = vx_core.f_copy(origblock, vx_core.vx_new(vx_core.t_anylist,
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
  public interface Func_msgblock_from_msgblock_msgblock : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_msgblock vx_msgblock_from_msgblock_msgblock(vx_core.Type_msgblock origblock, vx_core.Type_msgblock addblock);
  }

  public class Class_msgblock_from_msgblock_msgblock : vx_core.Class_base, Func_msgblock_from_msgblock_msgblock {

    public override vx_core.Func_msgblock_from_msgblock_msgblock vx_new(params Object[] vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    public override vx_core.Func_msgblock_from_msgblock_msgblock vx_copy(params Object[] vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msgblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_msgblock_from_msgblock_msgblock;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_msgblock_from_msgblock_msgblock;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_msgblock origblock = vx_core.f_any_from_any(vx_core.t_msgblock, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_msgblock addblock = vx_core.f_any_from_any(vx_core.t_msgblock, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
      return output;
    }

    override
    public vx_core.Type_msgblock vx_msgblock_from_msgblock_msgblock(vx_core.Type_msgblock origblock, vx_core.Type_msgblock addblock) {
      return vx_core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
    }

  }

  public static Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock = new vx_core.Class_msgblock_from_msgblock_msgblock();
  public static Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock = new vx_core.Class_msgblock_from_msgblock_msgblock();

  public static vx_core.Type_msgblock f_msgblock_from_msgblock_msgblock(vx_core.Type_msgblock origblock, vx_core.Type_msgblock addblock) {
    vx_core.Type_msgblock output = vx_core.e_msgblock;
    output = vx_core.f_new(
      vx_core.t_msgblock,
      vx_core.vx_new(vx_core.t_anylist,
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
  public interface Func_name_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_name_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_name_from_typedef : vx_core.Class_base, Func_name_from_typedef {

    public override vx_core.Func_name_from_typedef vx_new(params Object[] vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    public override vx_core.Func_name_from_typedef vx_copy(params Object[] vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "name<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_name_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_name_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_name_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_name_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_string vx_name_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_name_from_typedef(vtypedef);
    }

  }

  public static Func_name_from_typedef e_name_from_typedef = new vx_core.Class_name_from_typedef();
  public static Func_name_from_typedef t_name_from_typedef = new vx_core.Class_name_from_typedef();

  public static vx_core.Type_string f_name_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_string output = vx_core.e_string;
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
  public interface Func_native : vx_core.Func_any_from_any {
    public T vx_native<T>(T generic_any_1, vx_core.Type_anylist clauses) where T : vx_core.Type_any;
  }

  public class Class_native : vx_core.Class_base, Func_native {

    public override vx_core.Func_native vx_new(params Object[] vals) {
      Class_native output = new Class_native();
      return output;
    }

    public override vx_core.Func_native vx_copy(params Object[] vals) {
      Class_native output = new Class_native();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "native", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_native;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_native;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_anylist inputval = (vx_core.Type_anylist)value;
      vx_core.Type_any outputval = vx_core.f_native(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_anylist clauses = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_native(generic_any_1, clauses);
      return output;
    }

    override
    public T vx_native<T>(T generic_any_1, vx_core.Type_anylist clauses) where T : vx_core.Type_any {
      return vx_core.f_native(generic_any_1, clauses);
    }

  }

  public static Func_native e_native = new vx_core.Class_native();
  public static Func_native t_native = new vx_core.Class_native();

  public static T f_native<T>(T generic_any_1, vx_core.Type_anylist clauses) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function native_from_any
   * Returns native value of value object
   * @param  {any-1} value
   * @return {any}
   * (func native<-any)
   */
  public interface Func_native_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_any vx_native_from_any(vx_core.Type_any value);
  }

  public class Class_native_from_any : vx_core.Class_base, Func_native_from_any {

    public override vx_core.Func_native_from_any vx_new(params Object[] vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    public override vx_core.Func_native_from_any vx_copy(params Object[] vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "native<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_native_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_native_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_native_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_native_from_any(value);
      return output;
    }

    override
    public vx_core.Type_any vx_native_from_any(vx_core.Type_any value) {
      return vx_core.f_native_from_any(value);
    }

  }

  public static Func_native_from_any e_native_from_any = new vx_core.Class_native_from_any();
  public static Func_native_from_any t_native_from_any = new vx_core.Class_native_from_any();

  public static vx_core.Type_any f_native_from_any(vx_core.Type_any value) {
    vx_core.Type_any output = vx_core.e_any;
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
  public interface Func_new : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_new<T>(T type, vx_core.Type_anylist values) where T : vx_core.Type_any;
  }

  public class Class_new : vx_core.Class_base, Func_new {

    public override vx_core.Func_new vx_new(params Object[] vals) {
      Class_new output = new Class_new();
      return output;
    }

    public override vx_core.Func_new vx_copy(params Object[] vals) {
      Class_new output = new Class_new();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "new", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_new;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_new;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any type = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_anylist values = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_new(type, values);
      return output;
    }

    override
    public T vx_new<T>(T type, vx_core.Type_anylist values) where T : vx_core.Type_any {
      return vx_core.f_new(type, values);
    }

  }

  public static Func_new e_new = new vx_core.Class_new();
  public static Func_new t_new = new vx_core.Class_new();

  @SuppressWarnings("unchecked")
  public static T f_new<T>(T type, vx_core.Type_anylist values) where T : vx_core.Type_any {
    return output;
  }

  /**
   * @function number_from_func
   * Function Type returning number with any parameters
   * @return {number}
   * (func number<-func)
   */
  public interface Func_number_from_func : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_number vx_number_from_func();
  }

  public class Class_number_from_func : vx_core.Class_base, Func_number_from_func {

    public override vx_core.Func_number_from_func vx_new(params Object[] vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    public override vx_core.Func_number_from_func vx_copy(params Object[] vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "number<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int, vx_core.t_float, vx_core.t_decimal), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_number_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_number_from_func;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      output = vx_core.f_number_from_func();
      return output;
    }

    override
    public vx_core.Type_number vx_number_from_func() {
      return vx_core.f_number_from_func();
    }

  }

  public static Func_number_from_func e_number_from_func = new vx_core.Class_number_from_func();
  public static Func_number_from_func t_number_from_func = new vx_core.Class_number_from_func();

  public static vx_core.Type_number f_number_from_func() {
    vx_core.Type_number output = vx_core.e_number;
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
  public interface Func_or : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_or(vx_core.Type_boolean val1, vx_core.Type_boolean val2);
  }

  public class Class_or : vx_core.Class_base, Func_or {

    public override vx_core.Func_or vx_new(params Object[] vals) {
      Class_or output = new Class_or();
      return output;
    }

    public override vx_core.Func_or vx_copy(params Object[] vals) {
      Class_or output = new Class_or();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_or;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_or;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_boolean val1 = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_boolean val2 = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_or(val1, val2);
      return output;
    }

    override
    public vx_core.Type_boolean vx_or(vx_core.Type_boolean val1, vx_core.Type_boolean val2) {
      return vx_core.f_or(val1, val2);
    }

  }

  public static Func_or e_or = new vx_core.Class_or();
  public static Func_or t_or = new vx_core.Class_or();

  public static vx_core.Type_boolean f_or(vx_core.Type_boolean val1, vx_core.Type_boolean val2) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    return output;
  }

  /**
   * @function or 1
   * Returns true if any value is true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func or)
   */
  public interface Func_or_1 : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_or_1(vx_core.Type_booleanlist values);
  }

  public class Class_or_1 : vx_core.Class_base, Func_or_1 {

    public override vx_core.Func_or_1 vx_new(params Object[] vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    public override vx_core.Func_or_1 vx_copy(params Object[] vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_or_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_or_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_booleanlist inputval = (vx_core.Type_booleanlist)value;
      vx_core.Type_any outputval = vx_core.f_or_1(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_booleanlist values = vx_core.f_any_from_any(vx_core.t_booleanlist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_or_1(values);
      return output;
    }

    override
    public vx_core.Type_boolean vx_or_1(vx_core.Type_booleanlist values) {
      return vx_core.f_or_1(values);
    }

  }

  public static Func_or_1 e_or_1 = new vx_core.Class_or_1();
  public static Func_or_1 t_or_1 = new vx_core.Class_or_1();

  public static vx_core.Type_boolean f_or_1(vx_core.Type_booleanlist values) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_any_from_list_start_reduce_next(
      vx_core.t_boolean,
      values,
      vx_core.vx_new_boolean(false),
      vx_core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        vx_core.Type_boolean reduce = vx_core.f_any_from_any(vx_core.t_boolean, reduce_any);
        vx_core.Type_boolean current = vx_core.f_any_from_any(vx_core.t_boolean, current_any);
        vx_core.Type_boolean next = vx_core.f_any_from_any(vx_core.t_boolean, next_any);
        return 
        vx_core.f_or(
          reduce,
          vx_core.f_or(current, next)
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
  public interface Func_package_global_from_name : vx_core.Func_any_from_any {
    public vx_core.Type_package vx_package_global_from_name(vx_core.Type_string name);
  }

  public class Class_package_global_from_name : vx_core.Class_base, Func_package_global_from_name {

    public override vx_core.Func_package_global_from_name vx_new(params Object[] vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    public override vx_core.Func_package_global_from_name vx_copy(params Object[] vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "package-global<-name", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "package", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_package_global_from_name;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_package_global_from_name;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_package_global_from_name(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string name = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_package_global_from_name(name);
      return output;
    }

    override
    public vx_core.Type_package vx_package_global_from_name(vx_core.Type_string name) {
      return vx_core.f_package_global_from_name(name);
    }

  }

  public static Func_package_global_from_name e_package_global_from_name = new vx_core.Class_package_global_from_name();
  public static Func_package_global_from_name t_package_global_from_name = new vx_core.Class_package_global_from_name();

  public static vx_core.Type_package f_package_global_from_name(vx_core.Type_string name) {
    vx_core.Type_package output = vx_core.e_package;
    output = vx_core.f_any_from_map(
      vx_core.t_package,
      vx_core.c_global.packagemap(),
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
  public interface Func_packagename_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_packagename_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_packagename_from_typedef : vx_core.Class_base, Func_packagename_from_typedef {

    public override vx_core.Func_packagename_from_typedef vx_new(params Object[] vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    public override vx_core.Func_packagename_from_typedef vx_copy(params Object[] vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "packagename<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_packagename_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_packagename_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_packagename_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_packagename_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_string vx_packagename_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_packagename_from_typedef(vtypedef);
    }

  }

  public static Func_packagename_from_typedef e_packagename_from_typedef = new vx_core.Class_packagename_from_typedef();
  public static Func_packagename_from_typedef t_packagename_from_typedef = new vx_core.Class_packagename_from_typedef();

  public static vx_core.Type_string f_packagename_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_string output = vx_core.e_string;
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
  public interface Func_path_from_context_path : vx_core.Func_any_from_any_context {
    public vx_core.Type_string vx_path_from_context_path(vx_core.Type_context context, vx_core.Type_string path);
  }

  public class Class_path_from_context_path : vx_core.Class_base, Func_path_from_context_path {

    public override vx_core.Func_path_from_context_path vx_new(params Object[] vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    public override vx_core.Func_path_from_context_path vx_copy(params Object[] vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "path<-context-path", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_path_from_context_path;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_path_from_context_path;
    }

    override
    public vx_core.Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn) {
      return vx_core.e_any_from_any_context;
    }

    public override T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_path_from_context_path(context, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string path = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_path_from_context_path(context, path);
      return output;
    }

    override
    public vx_core.Type_string vx_path_from_context_path(vx_core.Type_context context, vx_core.Type_string path) {
      return vx_core.f_path_from_context_path(context, path);
    }

  }

  public static Func_path_from_context_path e_path_from_context_path = new vx_core.Class_path_from_context_path();
  public static Func_path_from_context_path t_path_from_context_path = new vx_core.Class_path_from_context_path();

  public static vx_core.Type_string f_path_from_context_path(vx_core.Type_context context, vx_core.Type_string path) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_path_from_setting_path(
      vx_core.f_setting_from_context(context),
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
  public interface Func_path_from_setting_path : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_string vx_path_from_setting_path(vx_core.Type_setting session, vx_core.Type_string path);
  }

  public class Class_path_from_setting_path : vx_core.Class_base, Func_path_from_setting_path {

    public override vx_core.Func_path_from_setting_path vx_new(params Object[] vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    public override vx_core.Func_path_from_setting_path vx_copy(params Object[] vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "path<-setting-path", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_path_from_setting_path;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_path_from_setting_path;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_setting session = vx_core.f_any_from_any(vx_core.t_setting, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string path = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_path_from_setting_path(session, path);
      return output;
    }

    override
    public vx_core.Type_string vx_path_from_setting_path(vx_core.Type_setting session, vx_core.Type_string path) {
      return vx_core.f_path_from_setting_path(session, path);
    }

  }

  public static Func_path_from_setting_path e_path_from_setting_path = new vx_core.Class_path_from_setting_path();
  public static Func_path_from_setting_path t_path_from_setting_path = new vx_core.Class_path_from_setting_path();

  public static vx_core.Type_string f_path_from_setting_path(vx_core.Type_setting session, vx_core.Type_string path) {
    vx_core.Type_string output = vx_core.e_string;
    return output;
  }

  /**
   * @function permission_from_id_context
   * Return a permission from context by id
   * @param  {string} id
   * @return {permission}
   * (func permission<-id-context)
   */
  public interface Func_permission_from_id_context : vx_core.Func_any_from_any_context {
    public vx_core.Type_permission vx_permission_from_id_context(vx_core.Type_context context, vx_core.Type_string id);
  }

  public class Class_permission_from_id_context : vx_core.Class_base, Func_permission_from_id_context {

    public override vx_core.Func_permission_from_id_context vx_new(params Object[] vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    public override vx_core.Func_permission_from_id_context vx_copy(params Object[] vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "permission<-id-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "permission", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_permission_from_id_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_permission_from_id_context;
    }

    override
    public vx_core.Func_any_from_any_context vx_fn_new(vx_core.Class_any_from_any_context.IFn fn) {
      return vx_core.e_any_from_any_context;
    }

    public override T vx_any_from_any_context<T, U>(T generic_any_1, vx_core.Type_context context, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_string inputval = (vx_core.Type_string)value;
      vx_core.Type_any outputval = vx_core.f_permission_from_id_context(context, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string id = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_permission_from_id_context(context, id);
      return output;
    }

    override
    public vx_core.Type_permission vx_permission_from_id_context(vx_core.Type_context context, vx_core.Type_string id) {
      return vx_core.f_permission_from_id_context(context, id);
    }

  }

  public static Func_permission_from_id_context e_permission_from_id_context = new vx_core.Class_permission_from_id_context();
  public static Func_permission_from_id_context t_permission_from_id_context = new vx_core.Class_permission_from_id_context();

  public static vx_core.Type_permission f_permission_from_id_context(vx_core.Type_context context, vx_core.Type_string id) {
    vx_core.Type_permission output = vx_core.e_permission;
    output = vx_core.f_let(
      vx_core.t_permission,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_user user = vx_core.f_user_from_context(context);
        vx_core.Type_security security = user.security();
        vx_core.Type_permissionmap permissionmap = security.permissionmap();
        return vx_core.f_any_from_map(vx_core.t_permission, permissionmap, vx_core.vx_new_string(":id"));
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
  public interface Func_properties_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_argmap vx_properties_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_properties_from_typedef : vx_core.Class_base, Func_properties_from_typedef {

    public override vx_core.Func_properties_from_typedef vx_new(params Object[] vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    public override vx_core.Func_properties_from_typedef vx_copy(params Object[] vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "properties<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_arg), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_properties_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_properties_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_properties_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_properties_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_argmap vx_properties_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_properties_from_typedef(vtypedef);
    }

  }

  public static Func_properties_from_typedef e_properties_from_typedef = new vx_core.Class_properties_from_typedef();
  public static Func_properties_from_typedef t_properties_from_typedef = new vx_core.Class_properties_from_typedef();

  public static vx_core.Type_argmap f_properties_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_argmap output = vx_core.e_argmap;
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
  public interface Func_proplast_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_arg vx_proplast_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_proplast_from_typedef : vx_core.Class_base, Func_proplast_from_typedef {

    public override vx_core.Func_proplast_from_typedef vx_new(params Object[] vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    public override vx_core.Func_proplast_from_typedef vx_copy(params Object[] vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "proplast<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "arg", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_proplast_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_proplast_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_proplast_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_proplast_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_arg vx_proplast_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_proplast_from_typedef(vtypedef);
    }

  }

  public static Func_proplast_from_typedef e_proplast_from_typedef = new vx_core.Class_proplast_from_typedef();
  public static Func_proplast_from_typedef t_proplast_from_typedef = new vx_core.Class_proplast_from_typedef();

  public static vx_core.Type_arg f_proplast_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_arg output = vx_core.e_arg;
    output = vtypedef.proplast();
    return output;
  }

  /**
   * @function resolve
   * @param  {any-1} value
   * @return {any-1}
   * (func resolve)
   */
  public interface Func_resolve : vx_core.Func_any_from_any {
    public T vx_resolve<T>(T generic_any_1, T value) where T : vx_core.Type_any;
  }

  public class Class_resolve : vx_core.Class_base, Func_resolve {

    public override vx_core.Func_resolve vx_new(params Object[] vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    public override vx_core.Func_resolve vx_copy(params Object[] vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_resolve;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_resolve;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_resolve(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_resolve(generic_any_1, value);
      return output;
    }

    override
    public T vx_resolve<T>(T generic_any_1, T value) where T : vx_core.Type_any {
      return vx_core.f_resolve(generic_any_1, value);
    }

  }

  public static Func_resolve e_resolve = new vx_core.Class_resolve();
  public static Func_resolve t_resolve = new vx_core.Class_resolve();

  public static T f_resolve<T>(T generic_any_1, T value) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    output = value;
    return output;
  }

  /**
   * @function resolve 1
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func resolve)
   */
  public interface Func_resolve_1 : vx_core.Func_any_from_any {
    public T vx_resolve_1<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any;
  }

  public class Class_resolve_1 : vx_core.Class_base, Func_resolve_1 {

    public override vx_core.Func_resolve_1 vx_new(params Object[] vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    public override vx_core.Func_resolve_1 vx_copy(params Object[] vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_resolve_1;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_resolve_1;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Func_any_from_func inputval = (vx_core.Func_any_from_func)value;
      vx_core.Type_any outputval = vx_core.f_resolve_1(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_resolve_1(generic_any_1, fn_any);
      return output;
    }

    override
    public T vx_resolve_1<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
      return vx_core.f_resolve_1(generic_any_1, fn_any);
    }

  }

  public static Func_resolve_1 e_resolve_1 = new vx_core.Class_resolve_1();
  public static Func_resolve_1 t_resolve_1 = new vx_core.Class_resolve_1();

  public static T f_resolve_1<T>(T generic_any_1, vx_core.Func_any_from_func fn_any) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_resolve_async : vx_core.Func_any_from_any_async {
    public Task<T> vx_resolve_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any) where T : vx_core.Type_any;
  }

  public class Class_resolve_async : vx_core.Class_base, Func_resolve_async {

    public override vx_core.Func_resolve_async vx_new(params Object[] vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    public override vx_core.Func_resolve_async vx_copy(params Object[] vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "resolve-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_resolve_async;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_resolve_async;
    }

    override
    public vx_core.Func_any_from_any_async vx_fn_new(vx_core.Class_any_from_any_async.IFn fn) {return vx_core.e_any_from_any_async;}

    public override Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) {
      T inputval = vx_core.f_any_from_any(generic_any_1, value);
      Task<T> output = vx_core.f_async(generic_any_1, inputval);
      return output;
    }

    public Task<vx_core.Type_any> vx_repl(vx_core.Type_anylist arglist) {
      Task<vx_core.Type_any> output = Task.completedFuture(vx_core.e_any);
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func_async fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(0)));
      Task<vx_core.Type_any> future = vx_core.f_resolve_async(generic_any_1, fn_any);
      output = vx_core.async_from_async(vx_core.t_any, future);
      return output;
    }

    override
    public Task<T> vx_resolve_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any) where T : vx_core.Type_any {
      return vx_core.f_resolve_async(generic_any_1, fn_any);
    }

  }

  public static Func_resolve_async e_resolve_async = new vx_core.Class_resolve_async();
  public static Func_resolve_async t_resolve_async = new vx_core.Class_resolve_async();

  public static Task<T> f_resolve_async<T>(T generic_any_1, vx_core.Func_any_from_func_async fn_any) where T : vx_core.Type_any {
    Task<T> output = vx_core.async_new_completed(vx_core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function resolve_first
   * Returns the first value that is not nothing
   * @param  {list-1} clauses
   * @return {any-1}
   * (func resolve-first)
   */
  public interface Func_resolve_first : vx_core.Func_any_from_any {
    public T vx_resolve_first<T, X>(T generic_any_1, X clauses) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_resolve_first : vx_core.Class_base, Func_resolve_first {

    public override vx_core.Func_resolve_first vx_new(params Object[] vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    public override vx_core.Func_resolve_first vx_copy(params Object[] vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "resolve-first", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_resolve_first;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_resolve_first;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_resolve_first(vx_core.t_any, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list clauses = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_resolve_first(generic_any_1, clauses);
      return output;
    }

    override
    public T vx_resolve_first<T, X>(T generic_any_1, X clauses) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_core.f_resolve_first(generic_any_1, clauses);
    }

  }

  public static Func_resolve_first e_resolve_first = new vx_core.Class_resolve_first();
  public static Func_resolve_first t_resolve_first = new vx_core.Class_resolve_first();

  public static T f_resolve_first<T, X>(T generic_any_1, X clauses) where T : vx_core.Type_any where X : vx_core.Type_list {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_core.f_first_from_list_any_from_any(
      generic_any_1,
      clauses,
      vx_core.t_resolve
    );
    return output;
  }

  /**
   * @function resolve_list
   * @param  {list-1} clauses
   * @return {list-1}
   * (func resolve-list)
   */
  public interface Func_resolve_list : vx_core.Func_any_from_any {
    public X vx_resolve_list<X>(X generic_any_1, X clauses) where X : vx_core.Type_list;
  }

  public class Class_resolve_list : vx_core.Class_base, Func_resolve_list {

    public override vx_core.Func_resolve_list vx_new(params Object[] vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    public override vx_core.Func_resolve_list vx_copy(params Object[] vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "resolve-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_resolve_list;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_resolve_list;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_list inputval = (vx_core.Type_list)value;
      vx_core.Type_any outputval = vx_core.f_resolve_list(vx_core.t_list, inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list clauses = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_resolve_list(generic_list_1, clauses);
      return output;
    }

    override
    public X vx_resolve_list<X>(X generic_list_1, X clauses) where X : vx_core.Type_list {
      return vx_core.f_resolve_list(generic_list_1, clauses);
    }

  }

  public static Func_resolve_list e_resolve_list = new vx_core.Class_resolve_list();
  public static Func_resolve_list t_resolve_list = new vx_core.Class_resolve_list();

  public static X f_resolve_list<X>(X generic_list_1, X clauses) where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_core.f_list_from_list_1(
      generic_list_1,
      clauses,
      vx_core.t_resolve
    );
    return output;
  }

  /**
   * @function security_from_context
   * Return security from the given context.
   * @return {security}
   * (func security<-context)
   */
  public interface Func_security_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_security vx_security_from_context(vx_core.Type_context context);
  }

  public class Class_security_from_context : vx_core.Class_base, Func_security_from_context {

    public override vx_core.Func_security_from_context vx_new(params Object[] vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    public override vx_core.Func_security_from_context vx_copy(params Object[] vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "security<-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "security", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_security_from_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_security_from_context;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_security_from_context(context);
      return output;
    }

    override
    public vx_core.Type_security vx_security_from_context(vx_core.Type_context context) {
      return vx_core.f_security_from_context(context);
    }

  }

  public static Func_security_from_context e_security_from_context = new vx_core.Class_security_from_context();
  public static Func_security_from_context t_security_from_context = new vx_core.Class_security_from_context();

  public static vx_core.Type_security f_security_from_context(vx_core.Type_context context) {
    vx_core.Type_security output = vx_core.e_security;
    output = vx_core.f_security_from_user(
      vx_core.f_user_from_context(context)
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
  public interface Func_security_from_user : vx_core.Func_any_from_any {
    public vx_core.Type_security vx_security_from_user(vx_core.Type_user user);
  }

  public class Class_security_from_user : vx_core.Class_base, Func_security_from_user {

    public override vx_core.Func_security_from_user vx_new(params Object[] vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    public override vx_core.Func_security_from_user vx_copy(params Object[] vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "security<-user", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "security", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_security_from_user;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_security_from_user;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_user inputval = (vx_core.Type_user)value;
      vx_core.Type_any outputval = vx_core.f_security_from_user(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_user user = vx_core.f_any_from_any(vx_core.t_user, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_security_from_user(user);
      return output;
    }

    override
    public vx_core.Type_security vx_security_from_user(vx_core.Type_user user) {
      return vx_core.f_security_from_user(user);
    }

  }

  public static Func_security_from_user e_security_from_user = new vx_core.Class_security_from_user();
  public static Func_security_from_user t_security_from_user = new vx_core.Class_security_from_user();

  public static vx_core.Type_security f_security_from_user(vx_core.Type_user user) {
    vx_core.Type_security output = vx_core.e_security;
    output = user.security();
    return output;
  }

  /**
   * @function session_from_context
   * Returns session from a context
   * @return {session}
   * (func session<-context)
   */
  public interface Func_session_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_session vx_session_from_context(vx_core.Type_context context);
  }

  public class Class_session_from_context : vx_core.Class_base, Func_session_from_context {

    public override vx_core.Func_session_from_context vx_new(params Object[] vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    public override vx_core.Func_session_from_context vx_copy(params Object[] vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "session<-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_session_from_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_session_from_context;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_session_from_context(context);
      return output;
    }

    override
    public vx_core.Type_session vx_session_from_context(vx_core.Type_context context) {
      return vx_core.f_session_from_context(context);
    }

  }

  public static Func_session_from_context e_session_from_context = new vx_core.Class_session_from_context();
  public static Func_session_from_context t_session_from_context = new vx_core.Class_session_from_context();

  public static vx_core.Type_session f_session_from_context(vx_core.Type_context context) {
    vx_core.Type_session output = vx_core.e_session;
    output = context.session();
    return output;
  }

  /**
   * @function setting_from_context
   * Returns setting from a context
   * @return {setting}
   * (func setting<-context)
   */
  public interface Func_setting_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_setting vx_setting_from_context(vx_core.Type_context context);
  }

  public class Class_setting_from_context : vx_core.Class_base, Func_setting_from_context {

    public override vx_core.Func_setting_from_context vx_new(params Object[] vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    public override vx_core.Func_setting_from_context vx_copy(params Object[] vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "setting<-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "setting", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_setting_from_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_setting_from_context;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_setting_from_context(context);
      return output;
    }

    override
    public vx_core.Type_setting vx_setting_from_context(vx_core.Type_context context) {
      return vx_core.f_setting_from_context(context);
    }

  }

  public static Func_setting_from_context e_setting_from_context = new vx_core.Class_setting_from_context();
  public static Func_setting_from_context t_setting_from_context = new vx_core.Class_setting_from_context();

  public static vx_core.Type_setting f_setting_from_context(vx_core.Type_context context) {
    vx_core.Type_setting output = vx_core.e_setting;
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
  public interface Func_string_repeat : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_string vx_string_repeat(vx_core.Type_string text, vx_core.Type_int repeat);
  }

  public class Class_string_repeat : vx_core.Class_base, Func_string_repeat {

    public override vx_core.Func_string_repeat vx_new(params Object[] vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    public override vx_core.Func_string_repeat vx_copy(params Object[] vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "string-repeat", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string_repeat;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string_repeat;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int repeat = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_string_repeat(text, repeat);
      return output;
    }

    override
    public vx_core.Type_string vx_string_repeat(vx_core.Type_string text, vx_core.Type_int repeat) {
      return vx_core.f_string_repeat(text, repeat);
    }

  }

  public static Func_string_repeat e_string_repeat = new vx_core.Class_string_repeat();
  public static Func_string_repeat t_string_repeat = new vx_core.Class_string_repeat();

  public static vx_core.Type_string f_string_repeat(vx_core.Type_string text, vx_core.Type_int repeat) {
    vx_core.Type_string output = vx_core.e_string;
    return output;
  }

  /**
   * @function string_from_any
   * Return a string representation of a value
   * @param  {any} value
   * @return {string}
   * (func string<-any)
   */
  public interface Func_string_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_string_from_any(vx_core.Type_any value);
  }

  public class Class_string_from_any : vx_core.Class_base, Func_string_from_any {

    public override vx_core.Func_string_from_any vx_new(params Object[] vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    public override vx_core.Func_string_from_any vx_copy(params Object[] vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "string<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_string_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_string_from_any(value);
      return output;
    }

    override
    public vx_core.Type_string vx_string_from_any(vx_core.Type_any value) {
      return vx_core.f_string_from_any(value);
    }

  }

  public static Func_string_from_any e_string_from_any = new vx_core.Class_string_from_any();
  public static Func_string_from_any t_string_from_any = new vx_core.Class_string_from_any();

  public static vx_core.Type_string f_string_from_any(vx_core.Type_any value) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_string_from_any_indent(
      value,
      vx_core.vx_new_int(0),
      vx_core.vx_new_boolean(true)
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
  public interface Func_string_from_any_indent : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_string vx_string_from_any_indent(vx_core.Type_any value, vx_core.Type_int indent, vx_core.Type_boolean linefeed);
  }

  public class Class_string_from_any_indent : vx_core.Class_base, Func_string_from_any_indent {

    public override vx_core.Func_string_from_any_indent vx_new(params Object[] vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    public override vx_core.Func_string_from_any_indent vx_copy(params Object[] vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "string<-any-indent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string_from_any_indent;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string_from_any_indent;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int indent = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_boolean linefeed = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_string_from_any_indent(value, indent, linefeed);
      return output;
    }

    override
    public vx_core.Type_string vx_string_from_any_indent(vx_core.Type_any value, vx_core.Type_int indent, vx_core.Type_boolean linefeed) {
      return vx_core.f_string_from_any_indent(value, indent, linefeed);
    }

  }

  public static Func_string_from_any_indent e_string_from_any_indent = new vx_core.Class_string_from_any_indent();
  public static Func_string_from_any_indent t_string_from_any_indent = new vx_core.Class_string_from_any_indent();

  public static vx_core.Type_string f_string_from_any_indent(vx_core.Type_any value, vx_core.Type_int indent, vx_core.Type_boolean linefeed) {
    vx_core.Type_string output = vx_core.e_string;
    return output;
  }

  /**
   * @function string_from_func
   * Function Type returning string with any parameters
   * @return {string}
   * (func string<-func)
   */
  public interface Func_string_from_func : vx_core.Type_func, vx_core.Type_replfunc {
    public Func_string_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn);
    public vx_core.Type_string vx_string_from_func();
  }

  public class Class_string_from_func : vx_core.Class_base, Func_string_from_func {

    public override vx_core.Func_string_from_func vx_new(params Object[] vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    public override vx_core.Func_string_from_func vx_copy(params Object[] vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "string<-func", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string_from_func;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string_from_func;
    }

    public vx_core.Class_any_from_func.IFn fn = null;

    override
    public Func_string_from_func vx_fn_new(vx_core.Class_any_from_func.IFn fn) {
      Class_string_from_func output = new Class_string_from_func();
      output.fn = fn;
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      output = vx_core.f_string_from_func();
      return output;
    }

    override
    public vx_core.Type_string vx_string_from_func() {
      return vx_core.f_string_from_func();
    }

  }

  public static Func_string_from_func e_string_from_func = new vx_core.Class_string_from_func();
  public static Func_string_from_func t_string_from_func = new vx_core.Class_string_from_func();

  public static vx_core.Type_string f_string_from_func() {
    vx_core.Type_string output = vx_core.e_string;
    return output;
  }

  /**
   * @function string_from_string_find_replace
   * Returns a string with all instances of find replaced by replace.
   * @param  {string} text
   * @param  {string} find
   * @param  {string} replace
   * @return {string}
   * (func string<-string-find-replace)
   */
  public interface Func_string_from_string_find_replace : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_string vx_string_from_string_find_replace(vx_core.Type_string text, vx_core.Type_string find, vx_core.Type_string replace);
  }

  public class Class_string_from_string_find_replace : vx_core.Class_base, Func_string_from_string_find_replace {

    public override vx_core.Func_string_from_string_find_replace vx_new(params Object[] vals) {
      Class_string_from_string_find_replace output = new Class_string_from_string_find_replace();
      return output;
    }

    public override vx_core.Func_string_from_string_find_replace vx_copy(params Object[] vals) {
      Class_string_from_string_find_replace output = new Class_string_from_string_find_replace();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "string<-string-find-replace", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_string_from_string_find_replace;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_string_from_string_find_replace;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_string text = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string find = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_string replace = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_core.f_string_from_string_find_replace(text, find, replace);
      return output;
    }

    override
    public vx_core.Type_string vx_string_from_string_find_replace(vx_core.Type_string text, vx_core.Type_string find, vx_core.Type_string replace) {
      return vx_core.f_string_from_string_find_replace(text, find, replace);
    }

  }

  public static Func_string_from_string_find_replace e_string_from_string_find_replace = new vx_core.Class_string_from_string_find_replace();
  public static Func_string_from_string_find_replace t_string_from_string_find_replace = new vx_core.Class_string_from_string_find_replace();

  public static vx_core.Type_string f_string_from_string_find_replace(vx_core.Type_string text, vx_core.Type_string find, vx_core.Type_string replace) {
    vx_core.Type_string output = vx_core.e_string;
    return output;
  }

  /**
   * @function stringlist_from_map
   * Returns a stringlist of keys from any map in entry order.
   * @param  {map-1} map
   * @return {stringlist}
   * (func stringlist<-map)
   */
  public interface Func_stringlist_from_map : vx_core.Func_any_from_any {
    public vx_core.Type_stringlist vx_stringlist_from_map(vx_core.Type_map map);
  }

  public class Class_stringlist_from_map : vx_core.Class_base, Func_stringlist_from_map {

    public override vx_core.Func_stringlist_from_map vx_new(params Object[] vals) {
      Class_stringlist_from_map output = new Class_stringlist_from_map();
      return output;
    }

    public override vx_core.Func_stringlist_from_map vx_copy(params Object[] vals) {
      Class_stringlist_from_map output = new Class_stringlist_from_map();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "stringlist<-map", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_stringlist_from_map;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_stringlist_from_map;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_map inputval = (vx_core.Type_map)value;
      vx_core.Type_any outputval = vx_core.f_stringlist_from_map(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_stringlist_from_map(map);
      return output;
    }

    override
    public vx_core.Type_stringlist vx_stringlist_from_map(vx_core.Type_map map) {
      return vx_core.f_stringlist_from_map(map);
    }

  }

  public static Func_stringlist_from_map e_stringlist_from_map = new vx_core.Class_stringlist_from_map();
  public static Func_stringlist_from_map t_stringlist_from_map = new vx_core.Class_stringlist_from_map();

  public static vx_core.Type_stringlist f_stringlist_from_map(vx_core.Type_map map) {
    vx_core.Type_stringlist output = vx_core.e_stringlist;
    output = vx_core.f_list_from_map_1(
      vx_core.t_stringlist,
      map,
      vx_core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, key_any);
        vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, value_any);
        return key;
      })
    );
    return output;
  }

  /**
   * @function switch
   * Returns a value based on a logical switch
   * @param  {any-2} val
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func switch)
   */
  public interface Func_switch : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_switch<T, U>(T generic_any_1, U val, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any where U : vx_core.Type_any;
  }

  public class Class_switch : vx_core.Class_base, Func_switch {

    public override vx_core.Func_switch vx_new(params Object[] vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    public override vx_core.Func_switch vx_copy(params Object[] vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "switch", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_switch;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_switch;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_thenelselist thenelselist = vx_core.f_any_from_any(vx_core.t_thenelselist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_switch(generic_any_1, val, thenelselist);
      return output;
    }

    override
    public T vx_switch<T, U>(T generic_any_1, U val, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any where U : vx_core.Type_any {
      return vx_core.f_switch(generic_any_1, val, thenelselist);
    }

  }

  public static Func_switch e_switch = new vx_core.Class_switch();
  public static Func_switch t_switch = new vx_core.Class_switch();

  public static T f_switch<T, U>(T generic_any_1, U val, vx_core.Type_thenelselist thenelselist) where T : vx_core.Type_any where U : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function then
   * Returns a thenelse struct from a given condition function and value function
   * @param  {boolean<-func} fn-cond
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func then)
   */
  public interface Func_then : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_thenelse vx_then(vx_core.Func_boolean_from_func fn_cond, vx_core.Func_any_from_func fn_any);
  }

  public class Class_then : vx_core.Class_base, Func_then {

    public override vx_core.Func_then vx_new(params Object[] vals) {
      Class_then output = new Class_then();
      return output;
    }

    public override vx_core.Func_then vx_copy(params Object[] vals) {
      Class_then output = new Class_then();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "then", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_then;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_then;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Func_boolean_from_func fn_cond = vx_core.f_any_from_any(vx_core.t_boolean_from_func, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_func fn_any = vx_core.f_any_from_any(vx_core.t_any_from_func, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_core.f_then(fn_cond, fn_any);
      return output;
    }

    override
    public vx_core.Type_thenelse vx_then(vx_core.Func_boolean_from_func fn_cond, vx_core.Func_any_from_func fn_any) {
      return vx_core.f_then(fn_cond, fn_any);
    }

  }

  public static Func_then e_then = new vx_core.Class_then();
  public static Func_then t_then = new vx_core.Class_then();

  public static vx_core.Type_thenelse f_then(vx_core.Func_boolean_from_func fn_cond, vx_core.Func_any_from_func fn_any) {
    vx_core.Type_thenelse output = vx_core.e_thenelse;
    output = vx_core.f_new(
      vx_core.t_thenelse,
      vx_core.vx_new(vx_core.t_anylist,
        vx_core.vx_new_string(":code"),
        vx_core.vx_new_string(":then"),
        vx_core.vx_new_string(":fn-cond"),
        fn_cond,
        vx_core.vx_new_string(":fn-any"),
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
  public interface Func_traits_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_typelist vx_traits_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_traits_from_typedef : vx_core.Class_base, Func_traits_from_typedef {

    public override vx_core.Func_traits_from_typedef vx_new(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    public override vx_core.Func_traits_from_typedef vx_copy(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_traits_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_traits_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_traits_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_traits_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_typelist vx_traits_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_traits_from_typedef(vtypedef);
    }

  }

  public static Func_traits_from_typedef e_traits_from_typedef = new vx_core.Class_traits_from_typedef();
  public static Func_traits_from_typedef t_traits_from_typedef = new vx_core.Class_traits_from_typedef();

  public static vx_core.Type_typelist f_traits_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_typelist output = vx_core.e_typelist;
    return output;
  }

  /**
   * @function type_from_any
   * Gets the Type of a given Value
   * @param  {any-1} value
   * @return {any}
   * (func type<-any)
   */
  public interface Func_type_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_any vx_type_from_any(vx_core.Type_any value);
  }

  public class Class_type_from_any : vx_core.Class_base, Func_type_from_any {

    public override vx_core.Func_type_from_any vx_new(params Object[] vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    public override vx_core.Func_type_from_any vx_copy(params Object[] vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "type<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_type_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_type_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_type_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_type_from_any(value);
      return output;
    }

    override
    public vx_core.Type_any vx_type_from_any(vx_core.Type_any value) {
      return vx_core.f_type_from_any(value);
    }

  }

  public static Func_type_from_any e_type_from_any = new vx_core.Class_type_from_any();
  public static Func_type_from_any t_type_from_any = new vx_core.Class_type_from_any();

  public static vx_core.Type_any f_type_from_any(vx_core.Type_any value) {
    vx_core.Type_any output = vx_core.e_any;
    return output;
  }

  /**
   * @function typedef_from_any
   * Gets the typedef of a given value
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-any)
   */
  public interface Func_typedef_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_typedef vx_typedef_from_any(vx_core.Type_any val);
  }

  public class Class_typedef_from_any : vx_core.Class_base, Func_typedef_from_any {

    public override vx_core.Func_typedef_from_any vx_new(params Object[] vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    public override vx_core.Func_typedef_from_any vx_copy(params Object[] vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typedef_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typedef_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_typedef_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typedef_from_any(val);
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef_from_any(vx_core.Type_any val) {
      return vx_core.f_typedef_from_any(val);
    }

  }

  public static Func_typedef_from_any e_typedef_from_any = new vx_core.Class_typedef_from_any();
  public static Func_typedef_from_any t_typedef_from_any = new vx_core.Class_typedef_from_any();

  public static vx_core.Type_typedef f_typedef_from_any(vx_core.Type_any val) {
    vx_core.Type_typedef output = vx_core.e_typedef;
    output = vx_core.f_typedef_from_type(
      vx_core.f_type_from_any(val)
    );
    return output;
  }

  /**
   * @function typedef_from_type
   * Gets the typedef of a given type
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-type)
   */
  public interface Func_typedef_from_type : vx_core.Func_any_from_any {
    public vx_core.Type_typedef vx_typedef_from_type(vx_core.Type_any val);
  }

  public class Class_typedef_from_type : vx_core.Class_base, Func_typedef_from_type {

    public override vx_core.Func_typedef_from_type vx_new(params Object[] vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    public override vx_core.Func_typedef_from_type vx_copy(params Object[] vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-type", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typedef_from_type;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typedef_from_type;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_typedef_from_type(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typedef_from_type(val);
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef_from_type(vx_core.Type_any val) {
      return vx_core.f_typedef_from_type(val);
    }

  }

  public static Func_typedef_from_type e_typedef_from_type = new vx_core.Class_typedef_from_type();
  public static Func_typedef_from_type t_typedef_from_type = new vx_core.Class_typedef_from_type();

  public static vx_core.Type_typedef f_typedef_from_type(vx_core.Type_any val) {
    vx_core.Type_typedef output = vx_core.e_typedef;
    return output;
  }

  /**
   * @function typename_from_any
   * Gets the typename of a given value
   * @param  {any-2} value
   * @return {string}
   * (func typename<-any)
   */
  public interface Func_typename_from_any : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_typename_from_any(vx_core.Type_any value);
  }

  public class Class_typename_from_any : vx_core.Class_base, Func_typename_from_any {

    public override vx_core.Func_typename_from_any vx_new(params Object[] vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    public override vx_core.Func_typename_from_any vx_copy(params Object[] vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typename<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typename_from_any;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typename_from_any;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_typename_from_any(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any value = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typename_from_any(value);
      return output;
    }

    override
    public vx_core.Type_string vx_typename_from_any(vx_core.Type_any value) {
      return vx_core.f_typename_from_any(value);
    }

  }

  public static Func_typename_from_any e_typename_from_any = new vx_core.Class_typename_from_any();
  public static Func_typename_from_any t_typename_from_any = new vx_core.Class_typename_from_any();

  public static vx_core.Type_string f_typename_from_any(vx_core.Type_any value) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_typename_from_type(
      vx_core.f_type_from_any(value)
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
  public interface Func_typename_from_type : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_typename_from_type(vx_core.Type_any type);
  }

  public class Class_typename_from_type : vx_core.Class_base, Func_typename_from_type {

    public override vx_core.Func_typename_from_type vx_new(params Object[] vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    public override vx_core.Func_typename_from_type vx_copy(params Object[] vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typename<-type", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typename_from_type;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typename_from_type;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_core.f_typename_from_type(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any type = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typename_from_type(type);
      return output;
    }

    override
    public vx_core.Type_string vx_typename_from_type(vx_core.Type_any type) {
      return vx_core.f_typename_from_type(type);
    }

  }

  public static Func_typename_from_type e_typename_from_type = new vx_core.Class_typename_from_type();
  public static Func_typename_from_type t_typename_from_type = new vx_core.Class_typename_from_type();

  public static vx_core.Type_string f_typename_from_type(vx_core.Type_any type) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_typename_from_typedef(
      vx_core.f_typedef_from_type(type)
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
  public interface Func_typename_from_typedef : vx_core.Func_any_from_any {
    public vx_core.Type_string vx_typename_from_typedef(vx_core.Type_typedef vtypedef);
  }

  public class Class_typename_from_typedef : vx_core.Class_base, Func_typename_from_typedef {

    public override vx_core.Func_typename_from_typedef vx_new(params Object[] vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    public override vx_core.Func_typename_from_typedef vx_copy(params Object[] vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typename<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typename_from_typedef;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typename_from_typedef;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typedef inputval = (vx_core.Type_typedef)value;
      vx_core.Type_any outputval = vx_core.f_typename_from_typedef(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typedef vtypedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typename_from_typedef(vtypedef);
      return output;
    }

    override
    public vx_core.Type_string vx_typename_from_typedef(vx_core.Type_typedef vtypedef) {
      return vx_core.f_typename_from_typedef(vtypedef);
    }

  }

  public static Func_typename_from_typedef e_typename_from_typedef = new vx_core.Class_typename_from_typedef();
  public static Func_typename_from_typedef t_typename_from_typedef = new vx_core.Class_typename_from_typedef();

  public static vx_core.Type_string f_typename_from_typedef(vx_core.Type_typedef vtypedef) {
    vx_core.Type_string output = vx_core.e_string;
    output = vx_core.f_new(
      vx_core.t_string,
      vx_core.vx_new(vx_core.t_anylist,
        vtypedef.pkgname(),
        vx_core.vx_new_string("/"),
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
  public interface Func_typenames_from_typelist : vx_core.Func_any_from_any {
    public vx_core.Type_stringlist vx_typenames_from_typelist(vx_core.Type_typelist typelist);
  }

  public class Class_typenames_from_typelist : vx_core.Class_base, Func_typenames_from_typelist {

    public override vx_core.Func_typenames_from_typelist vx_new(params Object[] vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    public override vx_core.Func_typenames_from_typelist vx_copy(params Object[] vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "typenames<-typelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_typenames_from_typelist;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_typenames_from_typelist;
    }

    override
    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public override T vx_any_from_any<T, U>(T generic_any_1, U value) {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_typelist inputval = (vx_core.Type_typelist)value;
      vx_core.Type_any outputval = vx_core.f_typenames_from_typelist(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_typelist typelist = vx_core.f_any_from_any(vx_core.t_typelist, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_typenames_from_typelist(typelist);
      return output;
    }

    override
    public vx_core.Type_stringlist vx_typenames_from_typelist(vx_core.Type_typelist typelist) {
      return vx_core.f_typenames_from_typelist(typelist);
    }

  }

  public static Func_typenames_from_typelist e_typenames_from_typelist = new vx_core.Class_typenames_from_typelist();
  public static Func_typenames_from_typelist t_typenames_from_typelist = new vx_core.Class_typenames_from_typelist();

  public static vx_core.Type_stringlist f_typenames_from_typelist(vx_core.Type_typelist typelist) {
    vx_core.Type_stringlist output = vx_core.e_stringlist;
    output = vx_core.f_list_from_list_1(
      vx_core.t_stringlist,
      typelist,
      vx_core.t_any_from_any.vx_fn_new((type_any) => {
        vx_core.Type_any type = vx_core.f_any_from_any(vx_core.t_any, type_any);
        return 
        vx_core.f_typename_from_type(type);
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
  public interface Func_user_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_user vx_user_from_context(vx_core.Type_context context);
  }

  public class Class_user_from_context : vx_core.Class_base, Func_user_from_context {

    public override vx_core.Func_user_from_context vx_new(params Object[] vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    public override vx_core.Func_user_from_context vx_copy(params Object[] vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    override
    public vx_core.Type_typedef vx_typedef() {return vx_core.t_func.vx_typedef();}

    override
    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/core", // pkgname
        "user<-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "user", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    override
    public vx_core.Type_any vx_empty() {
      return e_user_from_context;
    }
    override
    public vx_core.Type_any vx_type() {
      return t_user_from_context;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_context context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_core.f_user_from_context(context);
      return output;
    }

    override
    public vx_core.Type_user vx_user_from_context(vx_core.Type_context context) {
      return vx_core.f_user_from_context(context);
    }

  }

  public static Func_user_from_context e_user_from_context = new vx_core.Class_user_from_context();
  public static Func_user_from_context t_user_from_context = new vx_core.Class_user_from_context();

  public static vx_core.Type_user f_user_from_context(vx_core.Type_context context) {
    vx_core.Type_user output = vx_core.e_user;
    output = vx_core.f_session_from_context(context).user();
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
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
    Map<String, vx_core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, vx_core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, vx_core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("any", vx_core.t_any);
    maptype.put("any-async<-func", vx_core.t_any_async_from_func);
    maptype.put("any<-anylist", vx_core.t_any_from_anylist);
    maptype.put("anylist", vx_core.t_anylist);
    maptype.put("anymap", vx_core.t_anymap);
    maptype.put("anytype", vx_core.t_anytype);
    maptype.put("arg", vx_core.t_arg);
    maptype.put("arglist", vx_core.t_arglist);
    maptype.put("argmap", vx_core.t_argmap);
    maptype.put("boolean", vx_core.t_boolean);
    maptype.put("booleanlist", vx_core.t_booleanlist);
    maptype.put("collection", vx_core.t_collection);
    maptype.put("compilelanguages", vx_core.t_compilelanguages);
    maptype.put("connect", vx_core.t_connect);
    maptype.put("connectlist", vx_core.t_connectlist);
    maptype.put("connectmap", vx_core.t_connectmap);
    maptype.put("const", vx_core.t_const);
    maptype.put("constdef", vx_core.t_constdef);
    maptype.put("constlist", vx_core.t_constlist);
    maptype.put("constmap", vx_core.t_constmap);
    maptype.put("context", vx_core.t_context);
    maptype.put("date", vx_core.t_date);
    maptype.put("decimal", vx_core.t_decimal);
    maptype.put("error", vx_core.t_error);
    maptype.put("float", vx_core.t_float);
    maptype.put("func", vx_core.t_func);
    maptype.put("funcdef", vx_core.t_funcdef);
    maptype.put("funclist", vx_core.t_funclist);
    maptype.put("funcmap", vx_core.t_funcmap);
    maptype.put("int", vx_core.t_int);
    maptype.put("intlist", vx_core.t_intlist);
    maptype.put("intmap", vx_core.t_intmap);
    maptype.put("list", vx_core.t_list);
    maptype.put("listtype", vx_core.t_listtype);
    maptype.put("locale", vx_core.t_locale);
    maptype.put("map", vx_core.t_map);
    maptype.put("maptype", vx_core.t_maptype);
    maptype.put("mempool", vx_core.t_mempool);
    maptype.put("msg", vx_core.t_msg);
    maptype.put("msgblock", vx_core.t_msgblock);
    maptype.put("msgblocklist", vx_core.t_msgblocklist);
    maptype.put("msglist", vx_core.t_msglist);
    maptype.put("none", vx_core.t_none);
    maptype.put("notype", vx_core.t_notype);
    maptype.put("number", vx_core.t_number);
    maptype.put("numberlist", vx_core.t_numberlist);
    maptype.put("numbermap", vx_core.t_numbermap);
    maptype.put("package", vx_core.t_package);
    maptype.put("packagemap", vx_core.t_packagemap);
    maptype.put("permission", vx_core.t_permission);
    maptype.put("permissionlist", vx_core.t_permissionlist);
    maptype.put("permissionmap", vx_core.t_permissionmap);
    maptype.put("project", vx_core.t_project);
    maptype.put("security", vx_core.t_security);
    maptype.put("session", vx_core.t_session);
    maptype.put("setting", vx_core.t_setting);
    maptype.put("state", vx_core.t_state);
    maptype.put("statelistener", vx_core.t_statelistener);
    maptype.put("statelistenermap", vx_core.t_statelistenermap);
    maptype.put("string", vx_core.t_string);
    maptype.put("stringlist", vx_core.t_stringlist);
    maptype.put("stringlistlist", vx_core.t_stringlistlist);
    maptype.put("stringmap", vx_core.t_stringmap);
    maptype.put("stringmutablemap", vx_core.t_stringmutablemap);
    maptype.put("struct", vx_core.t_struct);
    maptype.put("thenelse", vx_core.t_thenelse);
    maptype.put("thenelselist", vx_core.t_thenelselist);
    maptype.put("translation", vx_core.t_translation);
    maptype.put("translationlist", vx_core.t_translationlist);
    maptype.put("translationmap", vx_core.t_translationmap);
    maptype.put("type", vx_core.t_type);
    maptype.put("typedef", vx_core.t_typedef);
    maptype.put("typelist", vx_core.t_typelist);
    maptype.put("typemap", vx_core.t_typemap);
    maptype.put("user", vx_core.t_user);
    maptype.put("value", vx_core.t_value);
    mapconst.put("false", vx_core.c_false);
    mapconst.put("global", vx_core.c_global);
    mapconst.put("infinity", vx_core.c_infinity);
    mapconst.put("mempool-active", vx_core.c_mempool_active);
    mapconst.put("msg-error", vx_core.c_msg_error);
    mapconst.put("msg-info", vx_core.c_msg_info);
    mapconst.put("msg-severe", vx_core.c_msg_severe);
    mapconst.put("msg-warning", vx_core.c_msg_warning);
    mapconst.put("neginfinity", vx_core.c_neginfinity);
    mapconst.put("newline", vx_core.c_newline);
    mapconst.put("notanumber", vx_core.c_notanumber);
    mapconst.put("nothing", vx_core.c_nothing);
    mapconst.put("quote", vx_core.c_quote);
    mapconst.put("true", vx_core.c_true);
    mapfunc.put("!", vx_core.t_not);
    mapfunc.put("!-empty", vx_core.t_notempty);
    mapfunc.put("!-empty_1", vx_core.t_notempty_1);
    mapfunc.put("!=", vx_core.t_ne);
    mapfunc.put("!==", vx_core.t_neqeq);
    mapfunc.put("*", vx_core.t_multiply);
    mapfunc.put("*_1", vx_core.t_multiply_1);
    mapfunc.put("*_2", vx_core.t_multiply_2);
    mapfunc.put("*_3", vx_core.t_multiply_3);
    mapfunc.put("+", vx_core.t_plus);
    mapfunc.put("+_1", vx_core.t_plus_1);
    mapfunc.put("+_2", vx_core.t_plus_2);
    mapfunc.put("+_3", vx_core.t_plus_3);
    mapfunc.put("+1", vx_core.t_plus1);
    mapfunc.put("-", vx_core.t_minus);
    mapfunc.put("-_1", vx_core.t_minus_1);
    mapfunc.put("-_2", vx_core.t_minus_2);
    mapfunc.put("-_3", vx_core.t_minus_3);
    mapfunc.put("-1", vx_core.t_minus1);
    mapfunc.put(".", vx_core.t_dotmethod);
    mapfunc.put("/", vx_core.t_divide);
    mapfunc.put("<", vx_core.t_lt);
    mapfunc.put("<_1", vx_core.t_lt_1);
    mapfunc.put("<-", vx_core.t_chainfirst);
    mapfunc.put("<<-", vx_core.t_chainlast);
    mapfunc.put("<=", vx_core.t_le);
    mapfunc.put("<=_1", vx_core.t_le_1);
    mapfunc.put("=", vx_core.t_eq);
    mapfunc.put("=_1", vx_core.t_eq_1);
    mapfunc.put("==", vx_core.t_eqeq);
    mapfunc.put(">", vx_core.t_gt);
    mapfunc.put(">_1", vx_core.t_gt_1);
    mapfunc.put(">=", vx_core.t_ge);
    mapfunc.put(">=_1", vx_core.t_ge_1);
    mapfunc.put("allowfuncs<-security", vx_core.t_allowfuncs_from_security);
    mapfunc.put("allowtypenames<-typedef", vx_core.t_allowtypenames_from_typedef);
    mapfunc.put("allowtypes<-typedef", vx_core.t_allowtypes_from_typedef);
    mapfunc.put("and", vx_core.t_and);
    mapfunc.put("and_1", vx_core.t_and_1);
    mapfunc.put("any<-any", vx_core.t_any_from_any);
    mapfunc.put("any<-any-async", vx_core.t_any_from_any_async);
    mapfunc.put("any<-any-context", vx_core.t_any_from_any_context);
    mapfunc.put("any<-any-context-async", vx_core.t_any_from_any_context_async);
    mapfunc.put("any<-any-key-value", vx_core.t_any_from_any_key_value);
    mapfunc.put("any<-func", vx_core.t_any_from_func);
    mapfunc.put("any<-func-async", vx_core.t_any_from_func_async);
    mapfunc.put("any<-int", vx_core.t_any_from_int);
    mapfunc.put("any<-int-any", vx_core.t_any_from_int_any);
    mapfunc.put("any<-key-value", vx_core.t_any_from_key_value);
    mapfunc.put("any<-key-value-async", vx_core.t_any_from_key_value_async);
    mapfunc.put("any<-list", vx_core.t_any_from_list);
    mapfunc.put("any<-list-start-reduce", vx_core.t_any_from_list_start_reduce);
    mapfunc.put("any<-list-start-reduce-next", vx_core.t_any_from_list_start_reduce_next);
    mapfunc.put("any<-map", vx_core.t_any_from_map);
    mapfunc.put("any<-map-start-reduce", vx_core.t_any_from_map_start_reduce);
    mapfunc.put("any<-none", vx_core.t_any_from_none);
    mapfunc.put("any<-none-async", vx_core.t_any_from_none_async);
    mapfunc.put("any<-reduce", vx_core.t_any_from_reduce);
    mapfunc.put("any<-reduce-async", vx_core.t_any_from_reduce_async);
    mapfunc.put("any<-reduce-next", vx_core.t_any_from_reduce_next);
    mapfunc.put("any<-reduce-next-async", vx_core.t_any_from_reduce_next_async);
    mapfunc.put("any<-struct", vx_core.t_any_from_struct);
    mapfunc.put("async", vx_core.t_async);
    mapfunc.put("boolean-permission<-func", vx_core.t_boolean_permission_from_func);
    mapfunc.put("boolean-write<-map-name-value", vx_core.t_boolean_write_from_map_name_value);
    mapfunc.put("boolean<-any", vx_core.t_boolean_from_any);
    mapfunc.put("boolean<-func", vx_core.t_boolean_from_func);
    mapfunc.put("boolean<-none", vx_core.t_boolean_from_none);
    mapfunc.put("case", vx_core.t_case);
    mapfunc.put("case_1", vx_core.t_case_1);
    mapfunc.put("compare", vx_core.t_compare);
    mapfunc.put("contains", vx_core.t_contains);
    mapfunc.put("contains_1", vx_core.t_contains_1);
    mapfunc.put("context-main", vx_core.t_context_main);
    mapfunc.put("copy", vx_core.t_copy);
    mapfunc.put("else", vx_core.t_else);
    mapfunc.put("empty", vx_core.t_empty);
    mapfunc.put("extends<-any", vx_core.t_extends_from_any);
    mapfunc.put("extends<-typedef", vx_core.t_extends_from_typedef);
    mapfunc.put("first<-list", vx_core.t_first_from_list);
    mapfunc.put("first<-list-any<-any", vx_core.t_first_from_list_any_from_any);
    mapfunc.put("float<-string", vx_core.t_float_from_string);
    mapfunc.put("fn", vx_core.t_fn);
    mapfunc.put("funcdef<-func", vx_core.t_funcdef_from_func);
    mapfunc.put("funcname<-funcdef", vx_core.t_funcname_from_funcdef);
    mapfunc.put("if", vx_core.t_if);
    mapfunc.put("if_1", vx_core.t_if_1);
    mapfunc.put("if_2", vx_core.t_if_2);
    mapfunc.put("int<-func", vx_core.t_int_from_func);
    mapfunc.put("int<-string", vx_core.t_int_from_string);
    mapfunc.put("is-empty", vx_core.t_is_empty);
    mapfunc.put("is-empty_1", vx_core.t_is_empty_1);
    mapfunc.put("is-endswith", vx_core.t_is_endswith);
    mapfunc.put("is-float", vx_core.t_is_float);
    mapfunc.put("is-func", vx_core.t_is_func);
    mapfunc.put("is-int", vx_core.t_is_int);
    mapfunc.put("is-number", vx_core.t_is_number);
    mapfunc.put("is-pass<-permission", vx_core.t_is_pass_from_permission);
    mapfunc.put("last<-list", vx_core.t_last_from_list);
    mapfunc.put("length", vx_core.t_length);
    mapfunc.put("length_1", vx_core.t_length_1);
    mapfunc.put("length_2", vx_core.t_length_2);
    mapfunc.put("let", vx_core.t_let);
    mapfunc.put("let-async", vx_core.t_let_async);
    mapfunc.put("list-join<-list", vx_core.t_list_join_from_list);
    mapfunc.put("list-join<-list_1", vx_core.t_list_join_from_list_1);
    mapfunc.put("list<-list", vx_core.t_list_from_list);
    mapfunc.put("list<-list_1", vx_core.t_list_from_list_1);
    mapfunc.put("list<-list-async", vx_core.t_list_from_list_async);
    mapfunc.put("list<-list-intany", vx_core.t_list_from_list_intany);
    mapfunc.put("list<-map", vx_core.t_list_from_map);
    mapfunc.put("list<-map_1", vx_core.t_list_from_map_1);
    mapfunc.put("list<-map-async", vx_core.t_list_from_map_async);
    mapfunc.put("list<-type", vx_core.t_list_from_type);
    mapfunc.put("log", vx_core.t_log);
    mapfunc.put("log_1", vx_core.t_log_1);
    mapfunc.put("main", vx_core.t_main);
    mapfunc.put("map<-list", vx_core.t_map_from_list);
    mapfunc.put("map<-map", vx_core.t_map_from_map);
    mapfunc.put("map<-map_1", vx_core.t_map_from_map_1);
    mapfunc.put("msg<-error", vx_core.t_msg_from_error);
    mapfunc.put("msg<-error_1", vx_core.t_msg_from_error_1);
    mapfunc.put("msg<-error_2", vx_core.t_msg_from_error_2);
    mapfunc.put("msg<-warning", vx_core.t_msg_from_warning);
    mapfunc.put("msgblock<-msgblock-msg", vx_core.t_msgblock_from_msgblock_msg);
    mapfunc.put("msgblock<-msgblock-msgblock", vx_core.t_msgblock_from_msgblock_msgblock);
    mapfunc.put("name<-typedef", vx_core.t_name_from_typedef);
    mapfunc.put("native", vx_core.t_native);
    mapfunc.put("native<-any", vx_core.t_native_from_any);
    mapfunc.put("new", vx_core.t_new);
    mapfunc.put("number<-func", vx_core.t_number_from_func);
    mapfunc.put("or", vx_core.t_or);
    mapfunc.put("or_1", vx_core.t_or_1);
    mapfunc.put("package-global<-name", vx_core.t_package_global_from_name);
    mapfunc.put("packagename<-typedef", vx_core.t_packagename_from_typedef);
    mapfunc.put("path<-context-path", vx_core.t_path_from_context_path);
    mapfunc.put("path<-setting-path", vx_core.t_path_from_setting_path);
    mapfunc.put("permission<-id-context", vx_core.t_permission_from_id_context);
    mapfunc.put("properties<-typedef", vx_core.t_properties_from_typedef);
    mapfunc.put("proplast<-typedef", vx_core.t_proplast_from_typedef);
    mapfunc.put("resolve", vx_core.t_resolve);
    mapfunc.put("resolve_1", vx_core.t_resolve_1);
    mapfunc.put("resolve-async", vx_core.t_resolve_async);
    mapfunc.put("resolve-first", vx_core.t_resolve_first);
    mapfunc.put("resolve-list", vx_core.t_resolve_list);
    mapfunc.put("security<-context", vx_core.t_security_from_context);
    mapfunc.put("security<-user", vx_core.t_security_from_user);
    mapfunc.put("session<-context", vx_core.t_session_from_context);
    mapfunc.put("setting<-context", vx_core.t_setting_from_context);
    mapfunc.put("string-repeat", vx_core.t_string_repeat);
    mapfunc.put("string<-any", vx_core.t_string_from_any);
    mapfunc.put("string<-any-indent", vx_core.t_string_from_any_indent);
    mapfunc.put("string<-func", vx_core.t_string_from_func);
    mapfunc.put("string<-string-find-replace", vx_core.t_string_from_string_find_replace);
    mapfunc.put("stringlist<-map", vx_core.t_stringlist_from_map);
    mapfunc.put("switch", vx_core.t_switch);
    mapfunc.put("then", vx_core.t_then);
    mapfunc.put("traits<-typedef", vx_core.t_traits_from_typedef);
    mapfunc.put("type<-any", vx_core.t_type_from_any);
    mapfunc.put("typedef<-any", vx_core.t_typedef_from_any);
    mapfunc.put("typedef<-type", vx_core.t_typedef_from_type);
    mapfunc.put("typename<-any", vx_core.t_typename_from_any);
    mapfunc.put("typename<-type", vx_core.t_typename_from_type);
    mapfunc.put("typename<-typedef", vx_core.t_typename_from_typedef);
    mapfunc.put("typenames<-typelist", vx_core.t_typenames_from_typelist);
    mapfunc.put("user<-context", vx_core.t_user_from_context);
    vx_core.vx_global_package_set("vx/core", maptype, mapconst, mapfunc);
    }
  }

}
