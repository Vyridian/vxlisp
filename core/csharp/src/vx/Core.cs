namespace Vx;

public static class Core {

  public interface Map<TKey, TValue> where TKey : notnull {
    public Map<TKey, TValue> copy();
    public TValue get(TKey key);
    public TValue getOrDefault(TKey key, TValue defaultvalue);
    public List<TKey> keys();
    public void put(TKey key, TValue value);
    public void remove(TKey key);
  }

  public class LinkedHashMap<TKey, TValue> : Map<TKey, TValue> where TKey : notnull {
    private Dictionary<TKey, TValue> dict = new Dictionary<TKey, TValue>();
    private List<TKey> listkey = new List<TKey>();
    public LinkedHashMap() {
    }
    public LinkedHashMap(Map<TKey, TValue> copy) {
      this.listkey = new List<TKey>(copy.keys());
      foreach (TKey key in this.listkey) {
        dict[key] = copy.get(key);
      }
    }
    public Map<TKey, TValue> copy() {
      return new LinkedHashMap<TKey, TValue>(this);
    }
    public TValue get(TKey key) {
      return dict[key];
    }
    public TValue getOrDefault(TKey key, TValue defaultvalue) {
      TValue output = defaultvalue;
      if (dict.ContainsKey(key)) {
        output = dict[key];
      }
      return output;
    }
    public List<TKey> keys() {
      return listkey;
    }
    public void put(TKey key, TValue value) {
      listkey.Add(key);
      dict[key] = value;
    }
    public void remove(TKey key) {
      listkey.Remove(key);
      dict.Remove(key);
    }
  }

  public interface vx_Type_const {
    public Vx.Core.Type_constdef vx_constdef();
  }

  public interface Type_replfunc {
    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist);
  }

  public interface Type_replfunc_async {
    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist);
  }

  public static List<Vx.Core.Type_any> emptylistany = new List<Vx.Core.Type_any>();

  public static Map<string, Vx.Core.Type_any> emptymapany = new LinkedHashMap<string, Vx.Core.Type_any>();

  public class Class_base {
    protected int vx_iref = 0;
    protected Vx.Core.Type_msgblock? vxmsgblock = null;
    public virtual Vx.Core.Type_any vx_new(params Object[] vals) {
      return e_any;
    }
    public virtual Vx.Core.Type_any vx_copy(params Object[] vals) {
      return e_any;
    }
    public virtual Vx.Core.Type_any vx_empty() {
      return e_any;
    }
    public virtual Vx.Core.Type_any vx_type() {
      return t_any;
    }
    public virtual Vx.Core.Type_typedef vx_typedef() {
      return e_typedef;
    }
    public List<Type_any> vx_dispose() {
      this.vx_iref = 0;
      this.vxmsgblock = Vx.Core.e_msgblock;
      return emptylistany;
    }
    public Vx.Core.Type_msgblock vx_msgblock() {
      if (this.vxmsgblock == null) {
        return Vx.Core.e_msgblock;
      } else {
        return vxmsgblock;
      }
    }
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
    public string key = "";
    public T? value = default(T);
  }

  public static Vx.Core.Type_constdef constdef_new(
    string pkgname,
    string name,
    Vx.Core.Type_any typ
  ) {
    Vx.Core.Class_constdef output = new Vx.Core.Class_constdef();
    output.vx_p_pkgname = Vx.Core.vx_new_string(pkgname);
    output.vx_p_name = Vx.Core.vx_new_string(name);
    output.vx_p_type = typ;
    return output;
  }

  public static Vx.Core.Type_funcdef funcdef_new(
    string pkgname,
    string name,
    int idx,
    bool async,
    Vx.Core.Type_any typ
  ) {
    Vx.Core.Class_funcdef output = new Vx.Core.Class_funcdef();
    output.vx_p_pkgname = Vx.Core.vx_new_string(pkgname);
    output.vx_p_name = Vx.Core.vx_new_string(name);
    output.vx_p_idx = Vx.Core.vx_new_int(idx);
    output.vx_p_async = Vx.Core.vx_new_boolean(async);
    output.vx_p_type = typ;
    return output;
  }

  public static Vx.Core.Type_any[] arrayany_from_anylist(Vx.Core.Type_anylist list) {
    return list.vx_list().ToArray();
  }

  public static List<Vx.Core.Type_any> arraylist_from_array(params Vx.Core.Type_any[] items) {
    List<Vx.Core.Type_any> output = new List<Vx.Core.Type_any>(items);
    return output;
  }

  public static List<T> arraylist_from_arraylist<T, U>(
    T generic_any_1, List<U> listval)
    where T : Vx.Core.Type_any
    where U : Vx.Core.Type_any {
    List<T> output = new List<T>();
    foreach (Vx.Core.Type_any value in listval) {
      T t_val = Vx.Core.f_any_from_any(generic_any_1, value);
      output.Add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_arraylist_fn<T, U>(
    List<U> listval,
    Func<U, T> fn_any_from_any) {
    List<T> output = new List<T>();
    foreach (U value_u in listval) {
      T t_val = fn_any_from_any.Invoke(value_u);
      output.Add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_linkedhashmap<T, U>(
    T generic_any_1,
    LinkedHashMap<string, U> mapval)
    where T : Vx.Core.Type_any
    where U : Vx.Core.Type_any {
    List<T> output = new List<T>();
    List<string> keys = mapval.keys();
    foreach (string key in keys) {
      U u_val = mapval.get(key);
      T t_val = Vx.Core.f_any_from_any(generic_any_1, u_val);
      output.Add(t_val);
    }
    return output;
  }

  public static List<T> arraylist_from_linkedhashmap_fn<T, U>(Map<string, U> mapval, Func<string, U, T> fn_any_from_key_value) {
    List<T> output = new List<T>();
    List<string> keys = mapval.keys();
    foreach (string key in keys) {
      U u_val = mapval.get(key);
      T t_val = fn_any_from_key_value.Invoke(key, u_val);
      output.Add(t_val);
    }
    return output;
  }

  public static LinkedHashMap<string, T> hashmap_from_keyvalues<T>(params KeyValue<T>[] keyvalues) {
    LinkedHashMap<string, T> output = new LinkedHashMap<string, T>();
    foreach (KeyValue<T> keyvalue in keyvalues) {
      string key = keyvalue.key;
      T? value = keyvalue.value;
      if (value != null) {
        output.put(key, value);
      }
    }
    return output;
  }

  public static KeyValue<T> keyvalue_from_key_value<T>(string key, T value) {
    KeyValue<T> output = new KeyValue<T>();
    output.key = key;
    output.value = value;
    return output;
  }

  public static List<T> immutablelist<T>(List<T> listval) {
    return listval;
  }

  public static Map<T, U> immutablemap<T, U>(Map<T, U> mapval) where T : notnull {
    return mapval;
  }

  public static Map<string, T> map_from_list_fn<T>(List<T> listval, Func<T, Vx.Core.Type_string> fn_any_from_any) {
    Map<string, T> output = new LinkedHashMap<string, T>();
    foreach (T val in listval) {
      Vx.Core.Type_string valkey = fn_any_from_any.Invoke(val);
      string key = valkey.vx_string();
      output.put(key, val);
    }
    return output;
  }

  public static LinkedHashMap<string, T> map_from_map<T>(LinkedHashMap<string, Vx.Core.Type_any> mapval) where T : Vx.Core.Type_any {
    LinkedHashMap<string, T> output = new LinkedHashMap<string, T>();
    List<string> keys = mapval.keys();
    foreach (string key in keys) {
      Vx.Core.Type_any value = mapval.get(key);
      try {
        T castval = (T)value;
        output.put(key, castval);
      } catch (Exception ex) {
        Vx.Core.vx_log("map<-map", ex);
      }
    }
    return output;
  }

  // vx_new(generic_any_1, args...)
  public static T vx_new<T>(T generic_any_1, params Object[] vals) where T : Vx.Core.Type_any {
    Vx.Core.Type_any val = generic_any_1.vx_new(vals);
    T output = Vx.Core.f_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_copy(generic_any_1, args...)
  public static T vx_copy<T>(T copyval, params Object[] vals) where T : Vx.Core.Type_any {
    Vx.Core.Type_any val = copyval.vx_copy(vals);
    T output = Vx.Core.f_any_from_any(copyval, val);
    return output;
  }

  // vx_empty(generic_any_1)
  public static T vx_empty<T>(T type) where T : Vx.Core.Type_any {
    T output = (T)(type.vx_empty());
    return output;
  }

  // vx_type(generic_any_1)
  public static T vx_type<T>(T type) where T : Vx.Core.Type_any {
    T output = (T)(type.vx_type());
    return output;
  }

  // vx_any_from_func(generic_any_1, func, args...)
  public static T vx_any_from_func<T>(T generic_any_1, Vx.Core.Type_replfunc func, params Vx.Core.Type_any[] args) where T : Vx.Core.Type_any {
    Vx.Core.Type_anylist anylist = Vx.Core.vx_new_anylist(args);
    Vx.Core.Type_any val = func.vx_repl(anylist);
    T output = Vx.Core.f_any_from_any(generic_any_1, val);
    return output;
  }

  public static Task<T> vx_async_new_completed<T>(T value) {
    Task<T> output = Task.FromResult<T>(value);
    return output;
  }

  public static Task<T> vx_async_from_async<T, U>(T generic_any_1, Task<U> future) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = future.ContinueWith(tasku => {
      U tval = tasku.Result;
      T result = Vx.Core.f_any_from_any(generic_any_1, tval);
      return result;
    });
    return output;
  }

  public static Task<T> vx_async_from_async_fn<T, U>(Task<U> future, Func<U, T> fn) {
    Task<T> output = future.ContinueWith(tasku => {
      U uval = tasku.Result;
      T tval = fn(uval);
      return tval;
    });
    return output;
  }

  public static Task<List<T>> vx_async_arraylist_from_arraylist_async<T>(List<Task<T>> list_future) {
    Task<T[]> future = Task.WhenAll(list_future);
    Task<List<T>> output = future.ContinueWith(taskarrayt => {
     T[] arrayt = taskarrayt.Result;
     List<T> listt = arrayt.ToList();
     return listt;
    });
    return output;
  }

  // vx_boolean_from_string_ends(string, string)
  public static bool vx_boolean_from_string_ends(string text, string ends) {
    return text.EndsWith(ends);
  }

  // vx_boolean_from_string_find(string, string)
  public static bool vx_boolean_from_string_find(string text, string find) {
    return text.Contains(find);
  }

  // vx_boolean_from_string_starts(string, string)
  public static bool vx_boolean_from_string_starts(string text, string starts) {
    return text.StartsWith(starts);
  }

  // vx_eqeq(any, any)
  public static bool vx_eqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    bool output = false;
    if (val1 == val2) {
      output = true;
    } else if (val1.vx_msgblock() != Vx.Core.e_msgblock) {
    } else if (val2.vx_msgblock() != Vx.Core.e_msgblock) {
    } else {
      Vx.Core.Type_any type1 = val1.vx_type();
      Vx.Core.Type_any type2 = val2.vx_type();
      if (type1 != type2) {
      } else if (type1 == Vx.Core.t_int) {
        Vx.Core.Type_int valint1 = (Vx.Core.Type_int)val1;
        Vx.Core.Type_int valint2 = (Vx.Core.Type_int)val2;
        if (valint1.vx_int() == valint2.vx_int()) {
          output = true;
        }
      } else if (type1 == Vx.Core.t_float) {
        Vx.Core.Type_float valfloat1 = (Vx.Core.Type_float)val1;
        Vx.Core.Type_float valfloat2 = (Vx.Core.Type_float)val2;
        if (valfloat1.vx_float() == valfloat2.vx_float()) {
          output = true;
        }
      } else if (type1 == Vx.Core.t_decimal) {
        Vx.Core.Type_decimal valdecimal1 = (Vx.Core.Type_decimal)val1;
        Vx.Core.Type_decimal valdecimal2 = (Vx.Core.Type_decimal)val2;
        if (valdecimal1.vx_string() == valdecimal2.vx_string()) {
          output = true;
        }
      } else if (type1 == Vx.Core.t_string) {
        Vx.Core.Type_string valstring1 = (Vx.Core.Type_string)val1;
        Vx.Core.Type_string valstring2 = (Vx.Core.Type_string)val2;
        if (valstring1.vx_string() == valstring2.vx_string()) {
          output = true;
        }
      }
    }
    return output;
  }

  // vx_float_from_string(string)
  public static float vx_float_from_string(string text) {
    float output = 0;
    try {
      output = float.Parse(text);
    } catch (Exception) {
    }
    return output;
  }

  // vx_global_package_set(string, map<any>, map<any>, map<func>)
  public static void vx_global_package_set(string pkgname, Map<string, Vx.Core.Type_any> maptype, Map<string, Vx.Core.Type_any> mapconst, Map<string, Vx.Core.Type_func> mapfunc) {
    Vx.Core.Class_typemap typemap = new Vx.Core.Class_typemap();
		  typemap.vx_p_map = maptype;
	   Vx.Core.Class_constmap constmap = new Vx.Core.Class_constmap();
		  constmap.vx_p_map = mapconst;
		  Vx.Core.Class_funcmap funcmap = new Vx.Core.Class_funcmap();
		  funcmap.vx_p_map = mapfunc;
    Vx.Core.Class_project global = (Vx.Core.Class_project)Vx.Core.c_global;
    Vx.Core.Class_packagemap packagemap = (Vx.Core.Class_packagemap)global.packagemap();
    if (packagemap == null) {
      packagemap = new Vx.Core.Class_packagemap();
      global.vx_p_packagemap = packagemap;
    }
    Map<string, Vx.Core.Type_package> mappackage = new LinkedHashMap<string, Vx.Core.Type_package>(packagemap.vx_p_map);
		  Vx.Core.Class_package pkg = new Vx.Core.Class_package();
		  pkg.vx_p_constmap = constmap;
		  pkg.vx_p_typemap = typemap;
		  pkg.vx_p_funcmap = funcmap;
    mappackage.put(pkgname, pkg);
    packagemap.vx_p_map = mappackage;
  }

  // vx_int_from_string(string)
  public static int vx_int_from_string(string text) {
    int output = 0;
    try {
      output = int.Parse(text);
    } catch (Exception) {
    }
    return output;
  }

  // vx_int_from_string_find(string, string)
  public static int vx_int_from_string_find(string text, string find) {
    return text.IndexOf(find);
  }

  // vx_int_from_string_findlast(string, string)
  public static int vx_int_from_string_findlast(string text, string findlast) {
    return text.LastIndexOf(findlast);
  }

  // vx_is_float(string)
  public static bool vx_is_float(string text) {
    bool output = false;
    try {
      float.Parse(text);
      output = true;
    } catch (Exception) {
    }
    return output;
  }

  // vx_is_float(any)
  public static bool vx_is_float(Vx.Core.Type_any value) {
    bool output = false;
    if (value is Vx.Core.Type_number) {
      output = true;
    } else if (value is Vx.Core.Type_string) {
      Vx.Core.Type_string valuestring = (Vx.Core.Type_string)value;
      output = Vx.Core.vx_is_float(valuestring.vx_string());
    }
    return output;
  }

  // vx_is_int(string)
  public static bool vx_is_int(string text) {
    bool output = false;
    switch (text) {
    case "notanumber":
    case "infinity":
    case "neginfinity":
      output = true;
      break;
    default:
      try {
        int.Parse(text);
        output = true;
      } catch (Exception) {
      }
      break;
    }
    return output;
  }

  // vx_is_int(any)
  public static bool vx_is_int(Vx.Core.Type_any value) {
    bool result = false;
    if (value == Vx.Core.c_infinity) {
      result = true;
    } else if (value == Vx.Core.c_neginfinity) {
      result = true;
    } else if (value == Vx.Core.c_notanumber) {
      result = true;
    } else if (value is Vx.Core.Type_int) {
      result = true;
    } else if (value is Vx.Core.Type_float) {
      Vx.Core.Type_float valfloat = (Vx.Core.Type_float)value;
      float floatval = valfloat.vx_float();
      if ((int)floatval == floatval) {
        result = true;
      }
    } else if (value is Vx.Core.Type_decimal) {
      Vx.Core.Type_decimal valdec = (Vx.Core.Type_decimal)value;
      string strval = valdec.vx_string();
      try {
        if (int.Parse(strval) == float.Parse(strval)) {
          result = true;
        }
      } catch (Exception) {
      }
    } else if (value is Vx.Core.Type_string) {
      Vx.Core.Type_string valstr = (Vx.Core.Type_string)value;
      string strval = valstr.vx_string();
      result = vx_is_int(strval);
    }
    return result;
  }

  // vx_log(object...)
  public static void vx_log(params Object[] values) {
    foreach (Object value in values) {
      string text = "";
      if (value == null) {
        text = "null";
      } else if (value is Vx.Core.Type_string valstring) {
        text = valstring.vx_string();
      } else if (value is Vx.Core.Type_any valany) {
        Vx.Core.Type_string valstring2 = Vx.Core.f_string_from_any(valany);
        text = valstring2.vx_string();
      } else {
        text = Vx.Core.vx_string_from_object(value);
      }
      System.Console.WriteLine(text);
    }
  }

  // vx_msg_from_error
  public static Type_msg vx_msg_from_error(string text) {
    Class_msg output = new Class_msg();
    output.vx_p_text = Vx.Core.vx_new_string(text);
    output.vx_p_severity = Vx.Core.c_msg_severe;
    return output;
  }

  // vx_msg_from_error
  public static Type_msg vx_msg_from_error(string path, string code, Vx.Core.Type_any detail) {
    Class_msg output = new Class_msg();
    output.vx_p_path = Vx.Core.vx_new_string(path);
    output.vx_p_code = Vx.Core.vx_new_string(code);
    output.vx_p_detail = detail;
    output.vx_p_severity = Vx.Core.c_msg_severe;
    return output;
  }

  // vx_msg_from_exception
  public static Type_msg vx_msg_from_exception(string text, Exception err) {
    Class_msg output = new Class_msg();
    output.vx_p_text = Vx.Core.vx_new_string(text);
    output.vx_p_severity = Vx.Core.c_msg_severe;
    output.err = err;
    Vx.Core.vx_log(output);
    return output;
  }

  // vx_msgblock_from_copy_arrayval(msgblock, any...)
  public static Vx.Core.Type_msgblock vx_msgblock_from_copy_arrayval(Vx.Core.Type_any copy, params Object[] vals) {
    Vx.Core.Type_msgblock output = Vx.Core.e_msgblock;
    Vx.Core.Type_msgblock copymsgblock = copy.vx_msgblock();
    if (copymsgblock != null) {
      output = copymsgblock;
    }
    return output;
  }

  public static Vx.Core.Type_anylist vx_new_anylist(params Vx.Core.Type_any[] anys) {
    List<Core.Type_any> listany = new List<Vx.Core.Type_any>(anys);
    return vx_new_anylist(listany);
  }

  public static Vx.Core.Type_anylist vx_new_anylist(List<Vx.Core.Type_any> listany) {
    Vx.Core.Class_anylist output = new Vx.Core.Class_anylist();
    output.vx_p_list = immutablelist(listany);
    return output;
  }

  public static Type_boolean vx_new_boolean(bool isval) {
    Type_boolean output = Vx.Core.c_false;
    if (isval) {
      output = Vx.Core.c_true;
    }
    return output;
  }

  public static Type_float vx_new_float(float fval) {
    Class_float output = new Vx.Core.Class_float();
    output.vxfloat = fval;
    return output;
  }

  public static Type_int vx_new_int(int ival) {
    Type_int output;
    if ((ival == 0) && Vx.Core.e_int != null) {
      output = Vx.Core.e_int;
    } else {
      Class_int work = new Vx.Core.Class_int();
      work.vxint = ival;
      output = work;
    }
    return output;
  }

  public static Type_string vx_new_string(string text) {
    Type_string output;
    if ((text == "") && Vx.Core.e_string != null) {
      output = Vx.Core.e_string;
    } else {
      Class_string work = new Vx.Core.Class_string();
      work.vxstring = text;
      output = work;
    }
    return output;
  }

  public static string vx_string_from_any(Vx.Core.Type_any value) {
    return Vx.Core.vx_string_from_any_indent(value, 0, false);
  }

  public static string vx_string_from_any_indent(
    Vx.Core.Type_any value,
    int indent,
    bool linefeed) {
    string indenttext = vx_string_repeat(" ", indent);
    string output = "";
    if (indent > 50) {
      output = "Error: Max Depth Exceeded";
    } else if (value == null) {
      output = "null";
    } else if (value == value.vx_type()) {
      if (value is Vx.Core.Type_func) {
        Vx.Core.Type_func valuefunc = (Vx.Core.Type_func)value;
        Vx.Core.Type_funcdef funcdef = valuefunc.vx_funcdef();
        output = funcdef.pkgname().vx_string() + "/" + funcdef.name().vx_string();
      } else {
        Vx.Core.Type_typedef typedef = value.vx_typedef();
        output = typedef.pkgname().vx_string() + "/" + typedef.name().vx_string();
      }
    } else if (value is Vx.Core.Type_boolean) {
      Vx.Core.Type_boolean valbool = Vx.Core.f_any_from_any(Vx.Core.t_boolean, value);
      if (valbool.vx_boolean() == true) {
        output = "true";
      } else {
        output = "false";
      }
    } else if (value is Vx.Core.Type_decimal) {
      Vx.Core.Type_decimal valdec = Vx.Core.f_any_from_any(Vx.Core.t_decimal, value);
      output = valdec.vx_string();
    } else if (value is Vx.Core.Type_float) {
      Vx.Core.Type_float valfloat = Vx.Core.f_any_from_any(Vx.Core.t_float, value);
      output = valfloat.vx_float().ToString();
      if (output.EndsWith(".0")) {
        output = output.Substring(0, output.Length - 2);
      }
    } else if (value is Vx.Core.Type_int) {
      if (value == Vx.Core.c_notanumber) {
        output = "notanumber";
      } else if (value == Vx.Core.c_infinity) {
        output = "infinity";
      } else if (value == Vx.Core.c_neginfinity) {
        output = "neginfinity";
      } else {
        Vx.Core.Type_int valint = Vx.Core.f_any_from_any(Vx.Core.t_int, value);
        output = valint.vx_int().ToString();
      }
    } else if (value is Vx.Core.Type_string) {
      Vx.Core.Type_string valstring = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      output = "\"" + valstring.vx_string() + "\"";
    } else if (value is Vx.Core.vx_Type_const) {
      Vx.Core.vx_Type_const constvalue = (Vx.Core.vx_Type_const)value;
      Vx.Core.Type_constdef constdef = constvalue.vx_constdef();
      string constpkg = constdef.pkgname().vx_string();
      string constname = constdef.name().vx_string();
      if (constpkg == "vx/core") {
        output = constname;
      } else {
        output = constpkg + "/" + constname;
      }
    } else if (value is Vx.Core.Type_list) {
      Vx.Core.Type_list vallist = Vx.Core.f_any_from_any(Vx.Core.t_list, value);
      Vx.Core.Type_typedef typedef = vallist.vx_typedef();
      Vx.Core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 1;
      List<Vx.Core.Type_any> listval = vallist.vx_list();
      foreach (Vx.Core.Type_any valsub in listval) {
        string valtext = Vx.Core.vx_string_from_any_indent(valsub, indentint, linefeed);
        output += "\n " + indenttext + valtext;
      }
      if (vallist.vx_msgblock() != null) {
        string msgtext = Vx.Core.vx_string_from_any_indent(vallist.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is Vx.Core.Type_map) {
      Vx.Core.Type_map valmap = Vx.Core.f_any_from_any(Vx.Core.t_map, value);
      Vx.Core.Type_typedef typedef = valmap.vx_typedef();
      Vx.Core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 2;
      Map<string, Vx.Core.Type_any> mapval = valmap.vx_map();
      List<string> keys = mapval.keys();
      foreach (string skey in keys) {
        string key = skey;
        Vx.Core.Type_any valsub = mapval.get(key);
        if (!key.StartsWith(":")) {
          key = ":" + key;
        }
        string strval = Vx.Core.vx_string_from_any_indent(valsub, indentint, linefeed);
        if (strval.Contains("\n")) {
          strval = "\n  " + indenttext + strval;
        } else {
          strval = " " + strval;
        }
        output += "\n" + indenttext + " " + key + strval;
      }
      if (valmap.vx_msgblock() != null) {
        string msgtext = Vx.Core.vx_string_from_any_indent(valmap.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is Vx.Core.Type_struct) {
      Vx.Core.Type_struct valstruct = Vx.Core.f_any_from_any(Vx.Core.t_struct, value);
      Vx.Core.Type_typedef typedef = valstruct.vx_typedef();
      Vx.Core.Type_string typedefname = typedef.name();
      int indentint2 = indent;
      indentint2 += 2;
      Map<string, Vx.Core.Type_any> mapval2 = valstruct.vx_map();
      List<string> keys2 = mapval2.keys();
      foreach (string skey in keys2) {
        string key = skey;
        Vx.Core.Type_any valsub2 = mapval2.get(key);
        if (!Vx.Core.f_is_empty_1(valsub2).vx_boolean()) {
          if (!key.StartsWith(":")) {
            key = ":" + key;
          }
          string strval2 = Vx.Core.vx_string_from_any_indent(valsub2, indentint2, linefeed);
          if (strval2.Contains("\n")) {
            strval2 = "\n  " + indenttext + strval2;
          } else {
            strval2 = " " + strval2;
          }
          output += "\n" + indenttext + " " + key + strval2;
        }
      }
      if (valstruct.vx_msgblock() != null) {
        string msgtext2 = Vx.Core.vx_string_from_any_indent(valstruct.vx_msgblock(), indentint2, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext2;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value is Vx.Core.Type_func) {
      Vx.Core.Type_func valfunc = Vx.Core.f_any_from_any(Vx.Core.t_func, value);
      Vx.Core.Type_funcdef funcdef = valfunc.vx_funcdef();
      Vx.Core.Type_string funcdefname = Vx.Core.f_funcname_from_funcdef(funcdef);
      output = funcdefname.vx_string();
      if (valfunc.vx_msgblock() != null) {
        string msgtext = Vx.Core.vx_string_from_any_indent(valfunc.vx_msgblock(), indent, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + output + ")";
    }
    return output;
  }

  public static string vx_string_from_object(Object obj) {
    string output = "";
    string? text = obj.ToString();
    if (text != null) {
      output = text;
    }
    return output;
  }

  public static string vx_string_from_string_start_end(string text, int start, int end) {
    string output = "";
    int maxlen = text.Length;
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
      output = text.Substring(start - 1, end);
    }
    return output;
  }

  public static string vx_string_repeat(string text, int repeat) {
    System.Text.StringBuilder sb = new System.Text.StringBuilder(text.Length * repeat);
    sb.Insert(0, text, repeat);
    string output = sb.ToString();
    return output;
  }
  public static Vx.Core.Type_typedef typedef_new(
    string pkgname,
    string name,
    string extend,
    Vx.Core.Type_typelist traits,
    Vx.Core.Type_typelist allowtypes,
    Vx.Core.Type_typelist disallowtypes,
    Vx.Core.Type_funclist allowfuncs,
    Vx.Core.Type_funclist disallowfuncs,
    Vx.Core.Type_anylist allowvalues,
    Vx.Core.Type_anylist disallowvalues,
    Vx.Core.Type_argmap properties
  ) {
    Vx.Core.Class_typedef output = new Vx.Core.Class_typedef();
    output.vx_p_pkgname = Vx.Core.vx_new_string(pkgname);
    output.vx_p_name = Vx.Core.vx_new_string(name);
    output.vx_p_extend = Vx.Core.vx_new_string(extend);
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

  public static Vx.Core.Type_anylist vx_anylist_from_arraystring(params string[] arraystring) {
    List<Object> listany = new List<Object>();
    foreach (string svalue in arraystring) {
      Vx.Core.Type_string value = Vx.Core.vx_new_string(svalue);
      listany.Add(value);
    }
    Object[] arrayany = listany.ToArray();
    Vx.Core.Type_anylist output = Vx.Core.vx_new(Vx.Core.t_anylist, arrayany);
    return output;
  }

  // Warning!: Blocking
  public static T vx_sync_from_async<T>(T generic_any_1, Task<T> future) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    try {
      future.Wait();
      output = future.Result;
    } catch (Exception ex) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("sync<-async", ex);
      Vx.Core.Type_any val = generic_any_1.vx_new(msg);
      output = Vx.Core.f_any_from_any(generic_any_1, val);
    }
    return output;
  }

  /**
   * type: any
   * Any Value for Variant Type
   * (type any)
   */
  public interface Type_any {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_typedef vx_typedef();
    public List<Type_any> vx_dispose();
    public Vx.Core.Type_msgblock vx_msgblock();
    public bool vx_release();
    public void vx_reserve();
  }

  public class Class_any : Vx.Core.Class_base, Type_any {

    public override Vx.Core.Type_any vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_any,
       vals);
    }

    public override Vx.Core.Type_any vx_copy(params Object[] vals) {
      Type_any output = this;
      bool ischanged = false;
      Class_any val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_any work = new Class_any();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_any;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
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

  public static Type_any e_any = new Class_any();
  public static Type_any t_any = new Class_any();

  /**
   * type: any-async<-func
   * A sync or async function that returns one value.
   * (type any-async<-func)
   */
  public interface Type_any_async_from_func : Vx.Core.Type_any {
  }

  public class Class_any_async_from_func : Vx.Core.Class_base, Type_any_async_from_func {

    public override Vx.Core.Type_any_async_from_func vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_any_async_from_func,
       vals);
    }

    public override Vx.Core.Type_any_async_from_func vx_copy(params Object[] vals) {
      Type_any_async_from_func output = this;
      bool ischanged = false;
      Class_any_async_from_func val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_any_async_from_func work = new Class_any_async_from_func();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_async_from_func;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_any_async_from_func;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "any-async<-func", // name
        ":func", // extends
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

  public static Type_any_async_from_func e_any_async_from_func = new Class_any_async_from_func();
  public static Type_any_async_from_func t_any_async_from_func = new Class_any_async_from_func();

  /**
   * type: any<-anylist
   * List of any<-any
   * (type any<-anylist)
   */
  public interface Type_any_from_anylist : Vx.Core.Type_list {
    public List<Vx.Core.Func_any_from_any> vx_listany_from_any();
    public Vx.Core.Func_any_from_any vx_any_from_any(Vx.Core.Type_int index);
  }

  public class Class_any_from_anylist : Vx.Core.Class_base, Type_any_from_anylist {

    public List<Vx.Core.Func_any_from_any> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Func_any_from_any>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Func_any_from_any vx_any_from_any(Vx.Core.Type_int index) {
      Vx.Core.Func_any_from_any output = Vx.Core.e_any_from_any;
      Vx.Core.Class_any_from_anylist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Func_any_from_any> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Func_any_from_any> vx_listany_from_any() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_any_from_any(index);
    }

    public override Vx.Core.Type_any_from_anylist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_any_from_anylist,
       vals);
    }

    public override Vx.Core.Type_any_from_anylist vx_copy(params Object[] vals) {
      Type_any_from_anylist output = this;
      bool ischanged = false;
      Class_any_from_anylist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Func_any_from_any> listval = new List<Vx.Core.Func_any_from_any>(val.vx_listany_from_any());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Func_any_from_any allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_any_from_anylist) {
          Type_any_from_anylist multi = (Type_any_from_anylist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listany_from_any());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Func_any_from_any) {
              Vx.Core.Func_any_from_any valitem = (Vx.Core.Func_any_from_any)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/any<-anylist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/any<-anylist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_any_from_anylist work = new Class_any_from_anylist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_anylist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_any_from_anylist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "any<-anylist", // name
        ":list", // extends
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

  public static Type_any_from_anylist e_any_from_anylist = new Class_any_from_anylist();
  public static Type_any_from_anylist t_any_from_anylist = new Class_any_from_anylist();

  /**
   * type: anylist
   * A list of any
   * (type anylist)
   */
  public interface Type_anylist : Vx.Core.Type_list {
  }

  public class Class_anylist : Vx.Core.Class_base, Type_anylist {

    public List<Vx.Core.Type_any> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_any>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_anylist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public override Vx.Core.Type_anylist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_anylist,
       vals);
    }

    public override Vx.Core.Type_anylist vx_copy(params Object[] vals) {
      Type_anylist output = this;
      bool ischanged = false;
      Class_anylist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_any> listval = new List<Vx.Core.Type_any>(val.vx_list());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_any allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_anylist) {
          Type_anylist multi = (Type_anylist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_list());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_any) {
              Vx.Core.Type_any valitem = (Vx.Core.Type_any)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/anylist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/anylist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_anylist work = new Class_anylist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_anylist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_anylist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "anylist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_anymap : Vx.Core.Type_map {
  }

  public class Class_anymap : Vx.Core.Class_base, Type_anymap {

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_any) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_any castval = (Vx.Core.Type_any)value;
        Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(this.vx_p_map);
        if (castval == Vx.Core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_anymap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_any);
      return output;
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_anymap output = new Vx.Core.Class_anymap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_any castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/anymap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_anymap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_anymap,
       vals);
    }

    public override Vx.Core.Type_anymap vx_copy(params Object[] vals) {
      Type_anymap output = this;
      bool ischanged = false;
      Class_anymap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(val.vx_map());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/anymap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_any? valany = null;
          if (valsub is Vx.Core.Type_any) {
            valany = (Vx.Core.Type_any)valsub;
          } else if (valsub is Vx.Core.Type_any) {
            valany = valsub as Vx.Core.Type_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/anymap", ":invalidkeyvalue", msgmap);
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
        Class_anymap work = new Class_anymap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_anymap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_anymap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "anymap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_anytype : Vx.Core.Type_any {
  }

  public class Class_anytype : Vx.Core.Class_base, Type_anytype {

    public override Vx.Core.Type_anytype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_anytype,
       vals);
    }

    public override Vx.Core.Type_anytype vx_copy(params Object[] vals) {
      Type_anytype output = this;
      bool ischanged = false;
      Class_anytype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_anytype work = new Class_anytype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_anytype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_anytype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "anytype", // name
        ":type", // extends
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

  public static Type_anytype e_anytype = new Class_anytype();
  public static Type_anytype t_anytype = new Class_anytype();

  /**
   * type: arg
   * A function argument
   * (type arg)
   */
  public interface Type_arg : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any argtype();
    public Vx.Core.Func_any_from_func fn_any();
    public Vx.Core.Type_string doc();
  }

  public class Class_arg : Vx.Core.Class_base, Type_arg {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_argtype = null;

    public Vx.Core.Type_any argtype() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_argtype != null) {
        output = this.vx_p_argtype;
      }
      return output;
    }

    public Vx.Core.Func_any_from_func? vx_p_fn_any = null;

    public Vx.Core.Func_any_from_func fn_any() {
      Vx.Core.Func_any_from_func output = Vx.Core.e_any_from_func;
      if (this.vx_p_fn_any != null) {
        output = this.vx_p_fn_any;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_doc = null;

    public Vx.Core.Type_string doc() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_doc != null) {
        output = this.vx_p_doc;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":argtype", this.argtype());
      output.put(":fn-any", this.fn_any());
      output.put(":doc", this.doc());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_arg vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_arg,
       vals);
    }

    public override Vx.Core.Type_arg vx_copy(params Object[] vals) {
      Type_arg output = this;
      bool ischanged = false;
      Class_arg val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_any vx_p_argtype = val.argtype();
      Vx.Core.Func_any_from_func vx_p_fn_any = val.fn_any();
      Vx.Core.Type_string vx_p_doc = val.doc();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":argtype");
      validkeys.Add(":fn-any");
      validkeys.Add(":doc");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":argtype":
            if (valsub == vx_p_argtype) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_argtype = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("argtype"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub is Vx.Core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (Vx.Core.Func_any_from_func)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-any"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":doc":
            if (valsub == vx_p_doc) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_doc = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_doc = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("doc"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/arg", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_arg work = new Class_arg();
        work.vx_p_name = vx_p_name;
        work.vx_p_argtype = vx_p_argtype;
        work.vx_p_fn_any = vx_p_fn_any;
        work.vx_p_doc = vx_p_doc;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_arg;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_arg;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "arg", // name
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

  public static Type_arg e_arg = new Class_arg();
  public static Type_arg t_arg = new Class_arg();

  /**
   * type: arglist
   * A list of arg
   * (type arglist)
   */
  public interface Type_arglist : Vx.Core.Type_list {
    public List<Vx.Core.Type_arg> vx_listarg();
    public Vx.Core.Type_arg vx_arg(Vx.Core.Type_int index);
  }

  public class Class_arglist : Vx.Core.Class_base, Type_arglist {

    public List<Vx.Core.Type_arg> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_arg>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_arg vx_arg(Vx.Core.Type_int index) {
      Vx.Core.Type_arg output = Vx.Core.e_arg;
      Vx.Core.Class_arglist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_arg> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_arg> vx_listarg() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_arg(index);
    }

    public override Vx.Core.Type_arglist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_arglist,
       vals);
    }

    public override Vx.Core.Type_arglist vx_copy(params Object[] vals) {
      Type_arglist output = this;
      bool ischanged = false;
      Class_arglist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_arg> listval = new List<Vx.Core.Type_arg>(val.vx_listarg());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_arg allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_arg) {
          ischanged = true;
          listval.Add((Vx.Core.Type_arg)valsub);
        } else if (valsub is Vx.Core.Type_arglist) {
          Type_arglist multi = (Type_arglist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listarg());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_arg) {
              Vx.Core.Type_arg valitem = (Vx.Core.Type_arg)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/arglist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/arglist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_arglist work = new Class_arglist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_arglist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_arglist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "arglist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_arg), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_argmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_arg> vx_maparg();
    public Vx.Core.Type_arg vx_arg(Vx.Core.Type_string key);
  }

  public class Class_argmap : Vx.Core.Class_base, Type_argmap {

    public Vx.Core.Map<string, Vx.Core.Type_arg> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_arg>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_arg) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_arg castval = (Vx.Core.Type_arg)value;
        Vx.Core.Map<string, Vx.Core.Type_arg> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_arg>(this.vx_p_map);
        if (castval == Vx.Core.e_arg) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_arg vx_arg(Vx.Core.Type_string key) {
      Vx.Core.Type_arg output = Vx.Core.e_arg;
      Vx.Core.Class_argmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_arg> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_arg);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_arg> vx_maparg() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_arg(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_argmap output = new Vx.Core.Class_argmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_arg> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_arg>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_arg castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/argmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_argmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_argmap,
       vals);
    }

    public override Vx.Core.Type_argmap vx_copy(params Object[] vals) {
      Type_argmap output = this;
      bool ischanged = false;
      Class_argmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_arg> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_arg>(val.vx_maparg());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/argmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_arg? valany = null;
          if (valsub is Vx.Core.Type_arg) {
            valany = (Vx.Core.Type_arg)valsub;
          } else if (valsub is Vx.Core.Type_arg) {
            valany = valsub as Vx.Core.Type_arg;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/argmap", ":invalidkeyvalue", msgmap);
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
        Class_argmap work = new Class_argmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_argmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_argmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_arg), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_boolean : Vx.Core.Type_any {
    public bool vx_boolean();
  }

  public class Class_boolean : Vx.Core.Class_base, Type_boolean {

    internal bool vxboolean = false;
    
    // :implements
    public bool vx_boolean() {return vxboolean;}

    public override Vx.Core.Type_boolean vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_boolean,
       vals);
    }

    public override Vx.Core.Type_boolean vx_copy(params Object[] vals) {
      Type_boolean output = this;
      bool ischanged = false;
      Class_boolean val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      bool booleanval = val.vx_boolean();
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_boolean valboolean) {
          booleanval = booleanval || valboolean.vx_boolean();
        } else if (valsub is bool issubval) {
          booleanval = booleanval || issubval;
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_boolean work = new Class_boolean();
        work.vxboolean = booleanval;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      } else if (booleanval) {
        output = Vx.Core.c_true;
      } else {
        output = Vx.Core.c_false;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_boolean;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
      );
    }

  }

  public static Type_boolean t_boolean = new Class_boolean();

  /**
   * type: booleanlist
   * (type booleanlist)
   */
  public interface Type_booleanlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_boolean> vx_listboolean();
    public Vx.Core.Type_boolean vx_boolean(Vx.Core.Type_int index);
  }

  public class Class_booleanlist : Vx.Core.Class_base, Type_booleanlist {

    public List<Vx.Core.Type_boolean> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_boolean>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean(Vx.Core.Type_int index) {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      Vx.Core.Class_booleanlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_boolean> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_boolean> vx_listboolean() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_boolean(index);
    }

    public override Vx.Core.Type_booleanlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_booleanlist,
       vals);
    }

    public override Vx.Core.Type_booleanlist vx_copy(params Object[] vals) {
      Type_booleanlist output = this;
      bool ischanged = false;
      Class_booleanlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_boolean> listval = new List<Vx.Core.Type_boolean>(val.vx_listboolean());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_boolean allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_boolean) {
          ischanged = true;
          listval.Add(Vx.Core.vx_new(Vx.Core.t_boolean, valsub));
        } else if (valsub is Vx.Core.Type_booleanlist) {
          Type_booleanlist multi = (Type_booleanlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listboolean());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_boolean) {
              Vx.Core.Type_boolean valitem = (Vx.Core.Type_boolean)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/booleanlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/booleanlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_booleanlist work = new Class_booleanlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_booleanlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_booleanlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "booleanlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_boolean), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_booleanlist e_booleanlist = new Class_booleanlist();
  public static Type_booleanlist t_booleanlist = new Class_booleanlist();

  /**
   * type: collection
   * (type collection)
   */
  public interface Type_collection : Vx.Core.Type_any {
  }

  public class Class_collection : Vx.Core.Class_base, Type_collection {

    public override Vx.Core.Type_collection vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_collection,
       vals);
    }

    public override Vx.Core.Type_collection vx_copy(params Object[] vals) {
      Type_collection output = this;
      bool ischanged = false;
      Class_collection val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_collection work = new Class_collection();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_collection;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_collection;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "collection", // name
        "", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_list, Vx.Core.t_map), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_collection e_collection = new Class_collection();
  public static Type_collection t_collection = new Class_collection();

  /**
   * type: compilelanguages
   * (type compilelanguages)
   */
  public interface Type_compilelanguages : Vx.Core.Type_any {
  }

  public class Class_compilelanguages : Vx.Core.Class_base, Type_compilelanguages {

    public override Vx.Core.Type_compilelanguages vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_compilelanguages,
       vals);
    }

    public override Vx.Core.Type_compilelanguages vx_copy(params Object[] vals) {
      Type_compilelanguages output = this;
      bool ischanged = false;
      Class_compilelanguages val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_compilelanguages work = new Class_compilelanguages();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_compilelanguages;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_compilelanguages;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "compilelanguages", // name
        "", // extends
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

  public static Type_compilelanguages e_compilelanguages = new Class_compilelanguages();
  public static Type_compilelanguages t_compilelanguages = new Class_compilelanguages();

  /**
   * type: connect
   * General connect trait
   * (type connect)
   */
  public interface Type_connect : Vx.Core.Type_any {
  }

  public class Class_connect : Vx.Core.Class_base, Type_connect {

    public override Vx.Core.Type_connect vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_connect,
       vals);
    }

    public override Vx.Core.Type_connect vx_copy(params Object[] vals) {
      Type_connect output = this;
      bool ischanged = false;
      Class_connect val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_connect work = new Class_connect();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_connect;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_connect;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "connect", // name
        "", // extends
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

  public static Type_connect e_connect = new Class_connect();
  public static Type_connect t_connect = new Class_connect();

  /**
   * type: connectlist
   * List of connect
   * (type connectlist)
   */
  public interface Type_connectlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_connect> vx_listconnect();
    public Vx.Core.Type_connect vx_connect(Vx.Core.Type_int index);
  }

  public class Class_connectlist : Vx.Core.Class_base, Type_connectlist {

    public List<Vx.Core.Type_connect> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_connect>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_connect vx_connect(Vx.Core.Type_int index) {
      Vx.Core.Type_connect output = Vx.Core.e_connect;
      Vx.Core.Class_connectlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_connect> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_connect> vx_listconnect() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_connect(index);
    }

    public override Vx.Core.Type_connectlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_connectlist,
       vals);
    }

    public override Vx.Core.Type_connectlist vx_copy(params Object[] vals) {
      Type_connectlist output = this;
      bool ischanged = false;
      Class_connectlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_connect> listval = new List<Vx.Core.Type_connect>(val.vx_listconnect());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_connect allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_connect) {
          ischanged = true;
          listval.Add((Vx.Core.Type_connect)valsub);
        } else if (valsub is Vx.Core.Type_connectlist) {
          Type_connectlist multi = (Type_connectlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listconnect());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_connect) {
              Vx.Core.Type_connect valitem = (Vx.Core.Type_connect)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/connectlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/connectlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_connectlist work = new Class_connectlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_connectlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_connectlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "connectlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_connect), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_connectmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_connect> vx_mapconnect();
    public Vx.Core.Type_connect vx_connect(Vx.Core.Type_string key);
  }

  public class Class_connectmap : Vx.Core.Class_base, Type_connectmap {

    public Vx.Core.Map<string, Vx.Core.Type_connect> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_connect>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_connect) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_connect castval = (Vx.Core.Type_connect)value;
        Vx.Core.Map<string, Vx.Core.Type_connect> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_connect>(this.vx_p_map);
        if (castval == Vx.Core.e_connect) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_connect vx_connect(Vx.Core.Type_string key) {
      Vx.Core.Type_connect output = Vx.Core.e_connect;
      Vx.Core.Class_connectmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_connect> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_connect);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_connect> vx_mapconnect() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_connect(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_connectmap output = new Vx.Core.Class_connectmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_connect> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_connect>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_connect castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/connectmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_connectmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_connectmap,
       vals);
    }

    public override Vx.Core.Type_connectmap vx_copy(params Object[] vals) {
      Type_connectmap output = this;
      bool ischanged = false;
      Class_connectmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_connect> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_connect>(val.vx_mapconnect());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/connectmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_connect? valany = null;
          if (valsub is Vx.Core.Type_connect) {
            valany = (Vx.Core.Type_connect)valsub;
          } else if (valsub is Vx.Core.Type_connect) {
            valany = valsub as Vx.Core.Type_connect;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/connectmap", ":invalidkeyvalue", msgmap);
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
        Class_connectmap work = new Class_connectmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_connectmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_connectmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "connectmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_connect), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_const : Vx.Core.Type_any {
  }

  public class Class_const : Vx.Core.Class_base, Type_const {

    public override Vx.Core.Type_const vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_const,
       vals);
    }

    public override Vx.Core.Type_const vx_copy(params Object[] vals) {
      Type_const output = this;
      bool ischanged = false;
      Class_const val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_const work = new Class_const();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_const;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_const;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "const", // name
        ":const", // extends
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

  public static Type_const e_const = new Class_const();
  public static Type_const t_const = new Class_const();

  /**
   * type: constdef
   * Const Definition Class for inspecting properties.
   * (type constdef)
   */
  public interface Type_constdef : Vx.Core.Type_struct {
    public Vx.Core.Type_string pkgname();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any type();
  }

  public class Class_constdef : Vx.Core.Class_base, Type_constdef {

    public Vx.Core.Type_string? vx_p_pkgname = null;

    public Vx.Core.Type_string pkgname() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_pkgname != null) {
        output = this.vx_p_pkgname;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_type = null;

    public Vx.Core.Type_any type() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":type", this.type());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_constdef vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_constdef,
       vals);
    }

    public override Vx.Core.Type_constdef vx_copy(params Object[] vals) {
      Type_constdef output = this;
      bool ischanged = false;
      Class_constdef val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_pkgname = val.pkgname();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_any vx_p_type = val.type();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pkgname");
      validkeys.Add(":name");
      validkeys.Add(":type");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_pkgname = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_type = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/constdef", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_constdef work = new Class_constdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_constdef;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_constdef;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "constdef", // name
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

  public static Type_constdef e_constdef = new Class_constdef();
  public static Type_constdef t_constdef = new Class_constdef();

  /**
   * type: constlist
   * List of Const.
   * (type constlist)
   */
  public interface Type_constlist : Vx.Core.Type_list {
  }

  public class Class_constlist : Vx.Core.Class_base, Type_constlist {

    public List<Vx.Core.Type_any> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_any>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_constlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public override Vx.Core.Type_constlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_constlist,
       vals);
    }

    public override Vx.Core.Type_constlist vx_copy(params Object[] vals) {
      Type_constlist output = this;
      bool ischanged = false;
      Class_constlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_any> listval = new List<Vx.Core.Type_any>(val.vx_list());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_any allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_constlist) {
          Type_constlist multi = (Type_constlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_list());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_any) {
              Vx.Core.Type_any valitem = (Vx.Core.Type_any)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/constlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/constlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_constlist work = new Class_constlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_constlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_constlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "constlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_constmap : Vx.Core.Type_map {
  }

  public class Class_constmap : Vx.Core.Class_base, Type_constmap {

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_any) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_any castval = (Vx.Core.Type_any)value;
        Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(this.vx_p_map);
        if (castval == Vx.Core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_constmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_any);
      return output;
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_constmap output = new Vx.Core.Class_constmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_any castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/constmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_constmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_constmap,
       vals);
    }

    public override Vx.Core.Type_constmap vx_copy(params Object[] vals) {
      Type_constmap output = this;
      bool ischanged = false;
      Class_constmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(val.vx_map());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/constmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_any? valany = null;
          if (valsub is Vx.Core.Type_any) {
            valany = (Vx.Core.Type_any)valsub;
          } else if (valsub is Vx.Core.Type_any) {
            valany = valsub as Vx.Core.Type_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/constmap", ":invalidkeyvalue", msgmap);
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
        Class_constmap work = new Class_constmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_constmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_constmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "constmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_context : Vx.Core.Type_struct {
    public Vx.Core.Type_string code();
    public Vx.Core.Type_session session();
    public Vx.Core.Type_setting setting();
    public Vx.Core.Type_state state();
  }

  public class Class_context : Vx.Core.Class_base, Type_context {

    public Vx.Core.Type_string? vx_p_code = null;

    public Vx.Core.Type_string code() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_code != null) {
        output = this.vx_p_code;
      }
      return output;
    }

    public Vx.Core.Type_session? vx_p_session = null;

    public Vx.Core.Type_session session() {
      Vx.Core.Type_session output = Vx.Core.e_session;
      if (this.vx_p_session != null) {
        output = this.vx_p_session;
      }
      return output;
    }

    public Vx.Core.Type_setting? vx_p_setting = null;

    public Vx.Core.Type_setting setting() {
      Vx.Core.Type_setting output = Vx.Core.e_setting;
      if (this.vx_p_setting != null) {
        output = this.vx_p_setting;
      }
      return output;
    }

    public Vx.Core.Type_state? vx_p_state = null;

    public Vx.Core.Type_state state() {
      Vx.Core.Type_state output = Vx.Core.e_state;
      if (this.vx_p_state != null) {
        output = this.vx_p_state;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":code", this.code());
      output.put(":session", this.session());
      output.put(":setting", this.setting());
      output.put(":state", this.state());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_context vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_context,
       vals);
    }

    public override Vx.Core.Type_context vx_copy(params Object[] vals) {
      Type_context output = this;
      bool ischanged = false;
      Class_context val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_code = val.code();
      Vx.Core.Type_session vx_p_session = val.session();
      Vx.Core.Type_setting vx_p_setting = val.setting();
      Vx.Core.Type_state vx_p_state = val.state();
      List<string> validkeys = new List<string>();
      validkeys.Add(":code");
      validkeys.Add(":session");
      validkeys.Add(":setting");
      validkeys.Add(":state");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_code = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_code = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("code"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":session":
            if (valsub == vx_p_session) {
            } else if (valsub is Vx.Core.Type_session) {
              ischanged = true;
              vx_p_session = (Vx.Core.Type_session)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("session"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":setting":
            if (valsub == vx_p_setting) {
            } else if (valsub is Vx.Core.Type_setting) {
              ischanged = true;
              vx_p_setting = (Vx.Core.Type_setting)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("setting"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":state":
            if (valsub == vx_p_state) {
            } else if (valsub is Vx.Core.Type_state) {
              ischanged = true;
              vx_p_state = (Vx.Core.Type_state)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("state"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/context", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_context work = new Class_context();
        work.vx_p_code = vx_p_code;
        work.vx_p_session = vx_p_session;
        work.vx_p_setting = vx_p_setting;
        work.vx_p_state = vx_p_state;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_context;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_context;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "context", // name
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

  public static Type_context e_context = new Class_context();
  public static Type_context t_context = new Class_context();

  /**
   * type: date
   * A simple UTC date.
   * (type date)
   */
  public interface Type_date : Vx.Core.Type_any {
  }

  public class Class_date : Vx.Core.Class_base, Type_date {

    public override Vx.Core.Type_date vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_date,
       vals);
    }

    public override Vx.Core.Type_date vx_copy(params Object[] vals) {
      Type_date output = this;
      bool ischanged = false;
      Class_date val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_date work = new Class_date();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_date;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_date;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "date", // name
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
    }

  }

  public static Type_date e_date = new Class_date();
  public static Type_date t_date = new Class_date();

  /**
   * type: decimal
   * A clean version of float like Java BigDecimal.
   * (type decimal)
   */
  public interface Type_decimal : Vx.Core.Type_number {
    public float vx_float();
    public string vx_string();
    public Type_decimal vx_new_from_string(string sval);
  }

  public class Class_decimal : Vx.Core.Class_base, Type_decimal {

    internal string vxdecimal = "0.0";
    
    // :implements
    public float vx_float() {
      return float.Parse(vxdecimal);
    }
    
    // :implements
    public string vx_string() {return vxdecimal;}
    
    // :implements
    public Type_decimal vx_new_from_string(string sval) {
      Class_decimal output = new Class_decimal();
      output.vxdecimal = sval;
      return output;
    }

    public override Vx.Core.Type_decimal vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_decimal,
       vals);
    }

    public override Vx.Core.Type_decimal vx_copy(params Object[] vals) {
      Type_decimal output = this;
      bool ischanged = false;
      Class_decimal val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      string sval = val.vx_string();
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_string valstring) {
          ischanged = true;
          sval = valstring.vx_string();
        } else if (valsub is string svalsub) {
          ischanged = true;
          sval = svalsub;
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_decimal work = new Class_decimal();
        work.vxdecimal = sval;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_decimal;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_decimal;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "decimal", // name
        "", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

  public static Type_decimal e_decimal = new Class_decimal();
  public static Type_decimal t_decimal = new Class_decimal();

  /**
   * type: error
   * Error Type
   * (type error)
   */
  public interface Type_error : Vx.Core.Type_any {
  }

  public class Class_error : Vx.Core.Class_base, Type_error {

    public override Vx.Core.Type_error vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_error,
       vals);
    }

    public override Vx.Core.Type_error vx_copy(params Object[] vals) {
      Type_error output = this;
      bool ischanged = false;
      Class_error val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_error work = new Class_error();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_error;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_error;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "error", // name
        "", // extends
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

  public static Type_error e_error = new Class_error();
  public static Type_error t_error = new Class_error();

  /**
   * type: float
   * Standard Floating Point Number
   * (type float)
   */
  public interface Type_float : Vx.Core.Type_number {
    public float vx_float();
  }

  public class Class_float : Vx.Core.Class_base, Type_float {

    internal float vxfloat = 0;
    
    // :implements
    public float vx_float() {return vxfloat;}

    public override Vx.Core.Type_float vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_float,
       vals);
    }

    public override Vx.Core.Type_float vx_copy(params Object[] vals) {
      Type_float output = this;
      bool ischanged = false;
      Class_float val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      float floatval = val.vx_float();
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_decimal valdecimal) {
          ischanged = true;
          floatval += valdecimal.vx_float();
        } else if (valsub is Vx.Core.Type_float valfloat) {
          ischanged = true;
          floatval += valfloat.vx_float();
        } else if (valsub is Vx.Core.Type_int valint) {
          ischanged = true;
          floatval += valint.vx_int();
        } else if (valsub is Vx.Core.Type_string valstring) {
          ischanged = true;
          floatval += float.Parse(valstring.vx_string());
        } else if (valsub is float fval) {
          ischanged = true;
          floatval += fval;
        } else if (valsub is int ival) {
          ischanged = true;
          floatval += ival;
        } else if (valsub is string sval) {
          ischanged = true;
          floatval += float.Parse(sval);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_float work = new Class_float();
        work.vxfloat = floatval;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_float;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_float;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "float", // name
        "", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

  public static Type_float e_float = new Class_float();
  public static Type_float t_float = new Class_float();

  /**
   * type: func
   * Original Function Class.
   * (type func)
   */
  public interface Type_func : Vx.Core.Type_any {
	   public Vx.Core.Type_funcdef vx_funcdef();
  }

  public class Class_func : Vx.Core.Class_base, Type_func {

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.e_funcdef;
    }
    public override Vx.Core.Type_func vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_func,
       vals);
    }

    public override Vx.Core.Type_func vx_copy(params Object[] vals) {
      Type_func output = this;
      bool ischanged = false;
      Class_func val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_func work = new Class_func();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_func;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_func;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "func", // name
        ":func", // extends
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

  public static Type_func e_func = new Class_func();
  public static Type_func t_func = new Class_func();

  /**
   * type: funcdef
   * Func Definition Class for inspecting properties.
   * (type funcdef)
   */
  public interface Type_funcdef : Vx.Core.Type_struct {
    public Vx.Core.Type_string pkgname();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_int idx();
    public Vx.Core.Type_any type();
    public Vx.Core.Type_boolean async();
  }

  public class Class_funcdef : Vx.Core.Class_base, Type_funcdef {

    public Vx.Core.Type_string? vx_p_pkgname = null;

    public Vx.Core.Type_string pkgname() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_pkgname != null) {
        output = this.vx_p_pkgname;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_idx = null;

    public Vx.Core.Type_int idx() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_idx != null) {
        output = this.vx_p_idx;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_type = null;

    public Vx.Core.Type_any type() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_async = null;

    public Vx.Core.Type_boolean async() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_async != null) {
        output = this.vx_p_async;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":idx", this.idx());
      output.put(":type", this.type());
      output.put(":async", this.async());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_funcdef vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_funcdef,
       vals);
    }

    public override Vx.Core.Type_funcdef vx_copy(params Object[] vals) {
      Type_funcdef output = this;
      bool ischanged = false;
      Class_funcdef val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_pkgname = val.pkgname();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_int vx_p_idx = val.idx();
      Vx.Core.Type_any vx_p_type = val.type();
      Vx.Core.Type_boolean vx_p_async = val.async();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pkgname");
      validkeys.Add(":name");
      validkeys.Add(":idx");
      validkeys.Add(":type");
      validkeys.Add(":async");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_pkgname = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":idx":
            if (valsub == vx_p_idx) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_idx = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_idx = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("idx"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_type = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_async = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_async = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("async"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/funcdef", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_funcdef work = new Class_funcdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_idx = vx_p_idx;
        work.vx_p_type = vx_p_type;
        work.vx_p_async = vx_p_async;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_funcdef;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_funcdef;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
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

  public static Type_funcdef e_funcdef = new Class_funcdef();
  public static Type_funcdef t_funcdef = new Class_funcdef();

  /**
   * type: funclist
   * List of Func.
   * (type funclist)
   */
  public interface Type_funclist : Vx.Core.Type_list {
    public List<Vx.Core.Type_func> vx_listfunc();
    public Vx.Core.Type_func vx_func(Vx.Core.Type_int index);
  }

  public class Class_funclist : Vx.Core.Class_base, Type_funclist {

    public List<Vx.Core.Type_func> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_func>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_func vx_func(Vx.Core.Type_int index) {
      Vx.Core.Type_func output = Vx.Core.e_func;
      Vx.Core.Class_funclist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_func> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_func> vx_listfunc() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_func(index);
    }

    public override Vx.Core.Type_funclist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_funclist,
       vals);
    }

    public override Vx.Core.Type_funclist vx_copy(params Object[] vals) {
      Type_funclist output = this;
      bool ischanged = false;
      Class_funclist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_func> listval = new List<Vx.Core.Type_func>(val.vx_listfunc());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_func allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_func) {
          ischanged = true;
          listval.Add((Vx.Core.Type_func)valsub);
        } else if (valsub is Vx.Core.Type_funclist) {
          Type_funclist multi = (Type_funclist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listfunc());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_func) {
              Vx.Core.Type_func valitem = (Vx.Core.Type_func)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/funclist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/funclist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_funclist work = new Class_funclist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_funclist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_funclist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "funclist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_func), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_funcmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_func> vx_mapfunc();
    public Vx.Core.Type_func vx_func(Vx.Core.Type_string key);
  }

  public class Class_funcmap : Vx.Core.Class_base, Type_funcmap {

    public Vx.Core.Map<string, Vx.Core.Type_func> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_func) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_func castval = (Vx.Core.Type_func)value;
        Vx.Core.Map<string, Vx.Core.Type_func> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>(this.vx_p_map);
        if (castval == Vx.Core.e_func) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_func vx_func(Vx.Core.Type_string key) {
      Vx.Core.Type_func output = Vx.Core.e_func;
      Vx.Core.Class_funcmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_func> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_func);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_func> vx_mapfunc() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_func(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_funcmap output = new Vx.Core.Class_funcmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_func> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_func castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/funcmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_funcmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_funcmap,
       vals);
    }

    public override Vx.Core.Type_funcmap vx_copy(params Object[] vals) {
      Type_funcmap output = this;
      bool ischanged = false;
      Class_funcmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_func> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>(val.vx_mapfunc());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/funcmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_func? valany = null;
          if (valsub is Vx.Core.Type_func) {
            valany = (Vx.Core.Type_func)valsub;
          } else if (valsub is Vx.Core.Type_func) {
            valany = valsub as Vx.Core.Type_func;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/funcmap", ":invalidkeyvalue", msgmap);
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
        Class_funcmap work = new Class_funcmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_funcmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_funcmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "funcmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_func), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_int : Vx.Core.Type_number {
    public int vx_int();
  }

  public class Class_int : Vx.Core.Class_base, Type_int {

    internal int vxint = 0;
    
    // :implements
    public int vx_int() {return vxint;}

    public override Vx.Core.Type_int vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_int,
       vals);
    }

    public override Vx.Core.Type_int vx_copy(params Object[] vals) {
      Type_int output = this;
      bool ischanged = false;
      Class_int val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      int intval = val.vx_int();
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_int valint) {
          ischanged = true;
          intval += valint.vx_int();
        } else if (valsub is int ival) {
          ischanged = true;
          intval += ival;
        } else if (valsub is string sval) {
          ischanged = true;
          intval += Int32.Parse(sval);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_int work = new Class_int();
        work.vxint = intval;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_int;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_int;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

  public static Type_int e_int = new Class_int();
  public static Type_int t_int = new Class_int();

  /**
   * type: intlist
   * A list of int.
   * (type intlist)
   */
  public interface Type_intlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_int> vx_listint();
    public Vx.Core.Type_int vx_int(Vx.Core.Type_int index);
  }

  public class Class_intlist : Vx.Core.Class_base, Type_intlist {

    public List<Vx.Core.Type_int> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_int>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_int vx_int(Vx.Core.Type_int index) {
      Vx.Core.Type_int output = Vx.Core.e_int;
      Vx.Core.Class_intlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_int> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_int> vx_listint() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_int(index);
    }

    public override Vx.Core.Type_intlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_intlist,
       vals);
    }

    public override Vx.Core.Type_intlist vx_copy(params Object[] vals) {
      Type_intlist output = this;
      bool ischanged = false;
      Class_intlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_int> listval = new List<Vx.Core.Type_int>(val.vx_listint());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_int allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_int) {
          ischanged = true;
          listval.Add(Vx.Core.vx_new(Vx.Core.t_int, valsub));
        } else if (valsub is Vx.Core.Type_intlist) {
          Type_intlist multi = (Type_intlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listint());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_int) {
              Vx.Core.Type_int valitem = (Vx.Core.Type_int)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/intlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/intlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_intlist work = new Class_intlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_intlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_intlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "intlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_intmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_int> vx_mapint();
    public Vx.Core.Type_int vx_int(Vx.Core.Type_string key);
  }

  public class Class_intmap : Vx.Core.Class_base, Type_intmap {

    public Vx.Core.Map<string, Vx.Core.Type_int> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_int>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_int) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_int castval = (Vx.Core.Type_int)value;
        Vx.Core.Map<string, Vx.Core.Type_int> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_int>(this.vx_p_map);
        if (castval == Vx.Core.e_int) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_int vx_int(Vx.Core.Type_string key) {
      Vx.Core.Type_int output = Vx.Core.e_int;
      Vx.Core.Class_intmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_int> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_int);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_int> vx_mapint() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_int(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_intmap output = new Vx.Core.Class_intmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_int> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_int>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_int castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/intmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_intmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_intmap,
       vals);
    }

    public override Vx.Core.Type_intmap vx_copy(params Object[] vals) {
      Type_intmap output = this;
      bool ischanged = false;
      Class_intmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_int> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_int>(val.vx_mapint());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/intmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_int? valany = null;
          if (valsub is Vx.Core.Type_int) {
            valany = (Vx.Core.Type_int)valsub;
          } else if (valsub is int) {
            valany = Vx.Core.vx_new(Vx.Core.t_int, valsub);
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
            msg = Vx.Core.vx_msg_from_error("vx/core/intmap", ":invalidkeyvalue", msgmap);
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
        Class_intmap work = new Class_intmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_intmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_intmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "intmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_list : Vx.Core.Type_any {
    public List<Vx.Core.Type_any> vx_list();
    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index);
  }

  public class Class_list : Vx.Core.Class_base, Type_list {

    public List<Vx.Core.Type_any> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_any>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_list list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public override Vx.Core.Type_list vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_list,
       vals);
    }

    public override Vx.Core.Type_list vx_copy(params Object[] vals) {
      Type_list output = this;
      bool ischanged = false;
      Class_list val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_any> listval = new List<Vx.Core.Type_any>(val.vx_list());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_any allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_list) {
          Type_list multi = (Type_list)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_list());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_any) {
              Vx.Core.Type_any valitem = (Vx.Core.Type_any)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/list", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/list", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_list work = new Class_list();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_list;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_list;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "list", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_listtype : Vx.Core.Type_any {
  }

  public class Class_listtype : Vx.Core.Class_base, Type_listtype {

    public override Vx.Core.Type_listtype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_listtype,
       vals);
    }

    public override Vx.Core.Type_listtype vx_copy(params Object[] vals) {
      Type_listtype output = this;
      bool ischanged = false;
      Class_listtype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_listtype work = new Class_listtype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_listtype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_listtype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "listtype", // name
        ":type", // extends
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

  public static Type_listtype e_listtype = new Class_listtype();
  public static Type_listtype t_listtype = new Class_listtype();

  /**
   * type: locale
   * Localization data.
   * (type locale)
   */
  public interface Type_locale : Vx.Core.Type_struct {
  }

  public class Class_locale : Vx.Core.Class_base, Type_locale {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_locale vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_locale,
       vals);
    }

    public override Vx.Core.Type_locale vx_copy(params Object[] vals) {
      Type_locale output = this;
      bool ischanged = false;
      Class_locale val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_locale work = new Class_locale();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_locale;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_locale;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "locale", // name
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

  public static Type_locale e_locale = new Class_locale();
  public static Type_locale t_locale = new Class_locale();

  /**
   * type: map
   * A simple untyped map.
   * (type map)
   */
  public interface Type_map : Vx.Core.Type_any {
    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval);
    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key);
    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map();
    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value);
  }

  public class Class_map : Vx.Core.Class_base, Type_map {

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_any) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_any castval = (Vx.Core.Type_any)value;
        Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(this.vx_p_map);
        if (castval == Vx.Core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_map map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_any);
      return output;
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_map output = new Vx.Core.Class_map();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_any castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/map", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_map vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_map,
       vals);
    }

    public override Vx.Core.Type_map vx_copy(params Object[] vals) {
      Type_map output = this;
      bool ischanged = false;
      Class_map val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(val.vx_map());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/map", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_any? valany = null;
          if (valsub is Vx.Core.Type_any) {
            valany = (Vx.Core.Type_any)valsub;
          } else if (valsub is Vx.Core.Type_any) {
            valany = valsub as Vx.Core.Type_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/map", ":invalidkeyvalue", msgmap);
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
        Class_map work = new Class_map();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_map;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_map;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "map", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_maptype : Vx.Core.Type_any {
  }

  public class Class_maptype : Vx.Core.Class_base, Type_maptype {

    public override Vx.Core.Type_maptype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_maptype,
       vals);
    }

    public override Vx.Core.Type_maptype vx_copy(params Object[] vals) {
      Type_maptype output = this;
      bool ischanged = false;
      Class_maptype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_maptype work = new Class_maptype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_maptype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_maptype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "maptype", // name
        ":type", // extends
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

  public static Type_maptype e_maptype = new Class_maptype();
  public static Type_maptype t_maptype = new Class_maptype();

  /**
   * type: mempool
   * Memory Pool
   * (type mempool)
   */
  public interface Type_mempool : Vx.Core.Type_struct {
    public Vx.Core.Type_value valuepool();
  }

  public class Class_mempool : Vx.Core.Class_base, Type_mempool {

    public Vx.Core.Type_value? vx_p_valuepool = null;

    public Vx.Core.Type_value valuepool() {
      Vx.Core.Type_value output = Vx.Core.e_value;
      if (this.vx_p_valuepool != null) {
        output = this.vx_p_valuepool;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":valuepool":
        output = this.valuepool();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":valuepool", this.valuepool());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_mempool vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_mempool,
       vals);
    }

    public override Vx.Core.Type_mempool vx_copy(params Object[] vals) {
      Type_mempool output = this;
      bool ischanged = false;
      Class_mempool val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_value vx_p_valuepool = val.valuepool();
      List<string> validkeys = new List<string>();
      validkeys.Add(":valuepool");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/mempool", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/mempool", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":valuepool":
            if (valsub == vx_p_valuepool) {
            } else if (valsub is Vx.Core.Type_value) {
              ischanged = true;
              vx_p_valuepool = (Vx.Core.Type_value)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("valuepool"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/mempool", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/mempool", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_mempool work = new Class_mempool();
        work.vx_p_valuepool = vx_p_valuepool;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_mempool;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_mempool;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "mempool", // name
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

  public static Type_mempool e_mempool = new Class_mempool();
  public static Type_mempool t_mempool = new Class_mempool();

  /**
   * type: msg
   * Message Type for error handling
   * (type msg)
   */
  public interface Type_msg : Vx.Core.Type_struct {
    public Vx.Core.Type_string code();
    public Vx.Core.Type_any detail();
    public Vx.Core.Type_string path();
    public Vx.Core.Type_int severity();
    public Vx.Core.Type_string text();
  }

  public class Class_msg : Vx.Core.Class_base, Type_msg {

    public Exception? err = null;

    public Vx.Core.Type_string? vx_p_code = null;

    public Vx.Core.Type_string code() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_code != null) {
        output = this.vx_p_code;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_detail = null;

    public Vx.Core.Type_any detail() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_detail != null) {
        output = this.vx_p_detail;
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

    public Vx.Core.Type_int? vx_p_severity = null;

    public Vx.Core.Type_int severity() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_severity != null) {
        output = this.vx_p_severity;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":code", this.code());
      output.put(":detail", this.detail());
      output.put(":path", this.path());
      output.put(":severity", this.severity());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_msg vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_msg,
       vals);
    }

    public override Vx.Core.Type_msg vx_copy(params Object[] vals) {
      Type_msg output = this;
      bool ischanged = false;
      Class_msg val = this;
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_code = val.code();
      Vx.Core.Type_any vx_p_detail = val.detail();
      Vx.Core.Type_string vx_p_path = val.path();
      Vx.Core.Type_int vx_p_severity = val.severity();
      Vx.Core.Type_string vx_p_text = val.text();
      string key = "";
      foreach (Object valsub in vals) {
        if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            key = valstr.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_code = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_code = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            }
            break;
          case ":detail":
            if (valsub == vx_p_detail) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_detail = (Vx.Core.Type_any)valsub;
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_path = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_path = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            }
            break;
          case ":severity":
            if (valsub == vx_p_severity) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_severity = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_severity = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
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

    public new Vx.Core.Type_msgblock vx_msgblock() {
      return Vx.Core.e_msgblock;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_msg;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_msg;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "msg", // name
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

  public static Type_msg e_msg = new Class_msg();
  public static Type_msg t_msg = new Class_msg();

  /**
   * type: msgblock
   * Block of Messages
   * (type msgblock)
   */
  public interface Type_msgblock : Vx.Core.Type_struct {
    public Vx.Core.Type_msglist msgs();
    public Vx.Core.Type_msgblocklist msgblocks();
  }

  public class Class_msgblock : Vx.Core.Class_base, Type_msgblock {

    public Vx.Core.Type_msglist? vx_p_msgs = null;

    public Vx.Core.Type_msglist msgs() {
      Vx.Core.Type_msglist output = Vx.Core.e_msglist;
      if (this.vx_p_msgs != null) {
        output = this.vx_p_msgs;
      }
      return output;
    }

    public Vx.Core.Type_msgblocklist? vx_p_msgblocks = null;

    public Vx.Core.Type_msgblocklist msgblocks() {
      Vx.Core.Type_msgblocklist output = Vx.Core.e_msgblocklist;
      if (this.vx_p_msgblocks != null) {
        output = this.vx_p_msgblocks;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":msgs", this.msgs());
      output.put(":msgblocks", this.msgblocks());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_msgblock vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_msgblock,
       vals);
    }

    public override Vx.Core.Type_msgblock vx_copy(params Object[] vals) {
      Type_msgblock output = this;
      bool ischanged = false;
      Class_msgblock val = this;
      Vx.Core.Type_msgblock msgblock = this;
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_msglist vx_p_msgs = val.msgs();
      Vx.Core.Type_msgblocklist vx_p_msgblocks = val.msgblocks();
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          if (valsub != Vx.Core.e_msgblock) {
            vx_p_msgblocks = Vx.Core.vx_copy(vx_p_msgblocks, valsub);
            ischanged = true;
          }
        } else if (valsub is Vx.Core.Type_msgblocklist) {
          if (valsub != Vx.Core.e_msgblocklist) {
            vx_p_msgblocks = Vx.Core.vx_copy(vx_p_msgblocks, valsub);
            ischanged = true;
          }
        } else if (valsub is Vx.Core.Type_msg) {
          if (valsub != Vx.Core.e_msg) {
            vx_p_msgs = Vx.Core.vx_copy(vx_p_msgs, valsub);
            ischanged = true;
          }
        } else if (valsub is Vx.Core.Type_msglist) {
          if (valsub != Vx.Core.e_msglist) {
            vx_p_msgs = Vx.Core.vx_copy(vx_p_msgs, valsub);
            ischanged = true;
          }
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            key = valstr.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          }
        } else {
          switch (key) {
          case ":msgs":
            if (valsub == vx_p_msgs) {
            } else if (valsub is Vx.Core.Type_msglist) {
              ischanged = true;
              vx_p_msgs = (Vx.Core.Type_msglist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("msgs"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/msgblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":msgblocks":
            if (valsub == vx_p_msgblocks) {
            } else if (valsub is Vx.Core.Type_msgblocklist) {
              ischanged = true;
              vx_p_msgblocks = (Vx.Core.Type_msgblocklist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("msgblocks"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/msgblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          }
          key = "";
        }
      }
      if (ischanged) {
        if ((vx_p_msgs.vx_list().Count == 0) && (vx_p_msgblocks.vx_list().Count == 1)) {
          output = vx_p_msgblocks.vx_listmsgblock()[0];
        } else {
          Class_msgblock work = new Class_msgblock();
          work.vx_p_msgs = vx_p_msgs;
          work.vx_p_msgblocks = vx_p_msgblocks;
          output = work;
        }
      }
      return output;
    }

    public new Vx.Core.Type_msgblock vx_msgblock() {
      return this;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_msgblock;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_msgblock;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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

  public static Type_msgblock e_msgblock = new Class_msgblock();
  public static Type_msgblock t_msgblock = new Class_msgblock();

  /**
   * type: msgblocklist
   * List of Message Blocks
   * (type msgblocklist)
   */
  public interface Type_msgblocklist : Vx.Core.Type_list {
    public List<Vx.Core.Type_msgblock> vx_listmsgblock();
    public Vx.Core.Type_msgblock vx_msgblock(Vx.Core.Type_int index);
  }

  public class Class_msgblocklist : Vx.Core.Class_base, Type_msgblocklist {

    public List<Vx.Core.Type_msgblock> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_msgblock>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_msgblock vx_msgblock(Vx.Core.Type_int index) {
      Vx.Core.Type_msgblock output = Vx.Core.e_msgblock;
      Vx.Core.Class_msgblocklist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_msgblock> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_msgblock> vx_listmsgblock() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_msgblock(index);
    }

    public override Vx.Core.Type_msgblocklist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_msgblocklist,
       vals);
    }

    public override Vx.Core.Type_msgblocklist vx_copy(params Object[] vals) {
      Type_msgblocklist output = this;
      bool ischanged = false;
      Class_msgblocklist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_msgblock> listval = new List<Vx.Core.Type_msgblock>(val.vx_listmsgblock());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msgblock) {
          ischanged = true;
          listval.Add((Vx.Core.Type_msgblock)valsub);
        } else if (valsub is Vx.Core.Type_msgblocklist) {
          Type_msgblocklist multi = (Type_msgblocklist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listmsgblock());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_msgblock) {
              Vx.Core.Type_msgblock valitem = (Vx.Core.Type_msgblock)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/msgblocklist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/msgblocklist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_msgblocklist work = new Class_msgblocklist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_msgblocklist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_msgblocklist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "msgblocklist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_msgblock), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_msglist : Vx.Core.Type_list {
    public List<Vx.Core.Type_msg> vx_listmsg();
    public Vx.Core.Type_msg vx_msg(Vx.Core.Type_int index);
  }

  public class Class_msglist : Vx.Core.Class_base, Type_msglist {

    public List<Vx.Core.Type_msg> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_msg>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_msg vx_msg(Vx.Core.Type_int index) {
      Vx.Core.Type_msg output = Vx.Core.e_msg;
      Vx.Core.Class_msglist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_msg> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_msg> vx_listmsg() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_msg(index);
    }

    public override Vx.Core.Type_msglist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_msglist,
       vals);
    }

    public override Vx.Core.Type_msglist vx_copy(params Object[] vals) {
      Type_msglist output = this;
      bool ischanged = false;
      Class_msglist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_msg> listval = new List<Vx.Core.Type_msg>(val.vx_listmsg());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          ischanged = true;
          listval.Add((Vx.Core.Type_msg)valsub);
        } else if (valsub is Vx.Core.Type_msglist) {
          Type_msglist multi = (Type_msglist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listmsg());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_msg) {
              Vx.Core.Type_msg valitem = (Vx.Core.Type_msg)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/msglist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/msglist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_msglist work = new Class_msglist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_msglist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_msglist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "msglist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_msg), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_none : Vx.Core.Type_any {
  }

  public class Class_none : Vx.Core.Class_base, Type_none {

    public override Vx.Core.Type_none vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_none,
       vals);
    }

    public override Vx.Core.Type_none vx_copy(params Object[] vals) {
      Type_none output = this;
      bool ischanged = false;
      Class_none val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_none work = new Class_none();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_none;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_none;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
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

  public static Type_none e_none = new Class_none();
  public static Type_none t_none = new Class_none();

  /**
   * type: notype
   * No Type that allows no Types as a Value
   * (type notype)
   */
  public interface Type_notype : Vx.Core.Type_any {
  }

  public class Class_notype : Vx.Core.Class_base, Type_notype {

    public override Vx.Core.Type_notype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_notype,
       vals);
    }

    public override Vx.Core.Type_notype vx_copy(params Object[] vals) {
      Type_notype output = this;
      bool ischanged = false;
      Class_notype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_notype work = new Class_notype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_notype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_notype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "notype", // name
        "", // extends
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

  public static Type_notype e_notype = new Class_notype();
  public static Type_notype t_notype = new Class_notype();

  /**
   * type: number
   * A generic number that could be int, float, or decimal.
   * (type number)
   */
  public interface Type_number : Vx.Core.Type_any {
  }

  public class Class_number : Vx.Core.Class_base, Type_number {

    public override Vx.Core.Type_number vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_number,
       vals);
    }

    public override Vx.Core.Type_number vx_copy(params Object[] vals) {
      Type_number output = this;
      bool ischanged = false;
      Class_number val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_number work = new Class_number();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_number;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_number;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_numberlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_number> vx_listnumber();
    public Vx.Core.Type_number vx_number(Vx.Core.Type_int index);
  }

  public class Class_numberlist : Vx.Core.Class_base, Type_numberlist {

    public List<Vx.Core.Type_number> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_number>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_number vx_number(Vx.Core.Type_int index) {
      Vx.Core.Type_number output = Vx.Core.e_number;
      Vx.Core.Class_numberlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_number> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_number> vx_listnumber() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_number(index);
    }

    public override Vx.Core.Type_numberlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_numberlist,
       vals);
    }

    public override Vx.Core.Type_numberlist vx_copy(params Object[] vals) {
      Type_numberlist output = this;
      bool ischanged = false;
      Class_numberlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_number> listval = new List<Vx.Core.Type_number>(val.vx_listnumber());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_number allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_number) {
          ischanged = true;
          listval.Add((Vx.Core.Type_number)valsub);
        } else if (valsub is Vx.Core.Type_numberlist) {
          Type_numberlist multi = (Type_numberlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listnumber());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_number) {
              Vx.Core.Type_number valitem = (Vx.Core.Type_number)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/numberlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/numberlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_numberlist work = new Class_numberlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_numberlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_numberlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "numberlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_numbermap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_number> vx_mapnumber();
    public Vx.Core.Type_number vx_number(Vx.Core.Type_string key);
  }

  public class Class_numbermap : Vx.Core.Class_base, Type_numbermap {

    public Vx.Core.Map<string, Vx.Core.Type_number> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_number>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_number) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_number castval = (Vx.Core.Type_number)value;
        Vx.Core.Map<string, Vx.Core.Type_number> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_number>(this.vx_p_map);
        if (castval == Vx.Core.e_number) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_number vx_number(Vx.Core.Type_string key) {
      Vx.Core.Type_number output = Vx.Core.e_number;
      Vx.Core.Class_numbermap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_number> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_number);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_number> vx_mapnumber() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_number(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_numbermap output = new Vx.Core.Class_numbermap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_number> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_number>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_number castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/numbermap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_numbermap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_numbermap,
       vals);
    }

    public override Vx.Core.Type_numbermap vx_copy(params Object[] vals) {
      Type_numbermap output = this;
      bool ischanged = false;
      Class_numbermap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_number> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_number>(val.vx_mapnumber());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/numbermap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_number? valany = null;
          if (valsub is Vx.Core.Type_number) {
            valany = (Vx.Core.Type_number)valsub;
          } else if (valsub is Vx.Core.Type_number) {
            valany = valsub as Vx.Core.Type_number;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/numbermap", ":invalidkeyvalue", msgmap);
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
        Class_numbermap work = new Class_numbermap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_numbermap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_numbermap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "numbermap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_package : Vx.Core.Type_struct {
    public Vx.Core.Type_string pkgname();
    public Vx.Core.Type_constmap constmap();
    public Vx.Core.Type_funcmap funcmap();
    public Vx.Core.Type_typemap typemap();
    public Vx.Core.Type_map emptymap();
  }

  public class Class_package : Vx.Core.Class_base, Type_package {

    public Vx.Core.Type_string? vx_p_pkgname = null;

    public Vx.Core.Type_string pkgname() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_pkgname != null) {
        output = this.vx_p_pkgname;
      }
      return output;
    }

    public Vx.Core.Type_constmap? vx_p_constmap = null;

    public Vx.Core.Type_constmap constmap() {
      Vx.Core.Type_constmap output = Vx.Core.e_constmap;
      if (this.vx_p_constmap != null) {
        output = this.vx_p_constmap;
      }
      return output;
    }

    public Vx.Core.Type_funcmap? vx_p_funcmap = null;

    public Vx.Core.Type_funcmap funcmap() {
      Vx.Core.Type_funcmap output = Vx.Core.e_funcmap;
      if (this.vx_p_funcmap != null) {
        output = this.vx_p_funcmap;
      }
      return output;
    }

    public Vx.Core.Type_typemap? vx_p_typemap = null;

    public Vx.Core.Type_typemap typemap() {
      Vx.Core.Type_typemap output = Vx.Core.e_typemap;
      if (this.vx_p_typemap != null) {
        output = this.vx_p_typemap;
      }
      return output;
    }

    public Vx.Core.Type_map? vx_p_emptymap = null;

    public Vx.Core.Type_map emptymap() {
      Vx.Core.Type_map output = Vx.Core.e_map;
      if (this.vx_p_emptymap != null) {
        output = this.vx_p_emptymap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":pkgname", this.pkgname());
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":typemap", this.typemap());
      output.put(":emptymap", this.emptymap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_package vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_package,
       vals);
    }

    public override Vx.Core.Type_package vx_copy(params Object[] vals) {
      Type_package output = this;
      bool ischanged = false;
      Class_package val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_pkgname = val.pkgname();
      Vx.Core.Type_constmap vx_p_constmap = val.constmap();
      Vx.Core.Type_funcmap vx_p_funcmap = val.funcmap();
      Vx.Core.Type_typemap vx_p_typemap = val.typemap();
      Vx.Core.Type_map vx_p_emptymap = val.emptymap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pkgname");
      validkeys.Add(":constmap");
      validkeys.Add(":funcmap");
      validkeys.Add(":typemap");
      validkeys.Add(":emptymap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_pkgname = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub is Vx.Core.Type_constmap) {
              ischanged = true;
              vx_p_constmap = (Vx.Core.Type_constmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("constmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub is Vx.Core.Type_funcmap) {
              ischanged = true;
              vx_p_funcmap = (Vx.Core.Type_funcmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("funcmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub is Vx.Core.Type_typemap) {
              ischanged = true;
              vx_p_typemap = (Vx.Core.Type_typemap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("typemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":emptymap":
            if (valsub == vx_p_emptymap) {
            } else if (valsub is Vx.Core.Type_map) {
              ischanged = true;
              vx_p_emptymap = (Vx.Core.Type_map)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("emptymap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/package", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_package work = new Class_package();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_typemap = vx_p_typemap;
        work.vx_p_emptymap = vx_p_emptymap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_package;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_package;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "package", // name
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

  public static Type_package e_package = new Class_package();
  public static Type_package t_package = new Class_package();

  /**
   * type: packagemap
   * (type packagemap)
   */
  public interface Type_packagemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_package> vx_mappackage();
    public Vx.Core.Type_package vx_package(Vx.Core.Type_string key);
  }

  public class Class_packagemap : Vx.Core.Class_base, Type_packagemap {

    public Vx.Core.Map<string, Vx.Core.Type_package> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_package>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_package) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_package castval = (Vx.Core.Type_package)value;
        Vx.Core.Map<string, Vx.Core.Type_package> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_package>(this.vx_p_map);
        if (castval == Vx.Core.e_package) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_package vx_package(Vx.Core.Type_string key) {
      Vx.Core.Type_package output = Vx.Core.e_package;
      Vx.Core.Class_packagemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_package> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_package);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_package> vx_mappackage() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_package(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_packagemap output = new Vx.Core.Class_packagemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_package> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_package>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_package castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/packagemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_packagemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_packagemap,
       vals);
    }

    public override Vx.Core.Type_packagemap vx_copy(params Object[] vals) {
      Type_packagemap output = this;
      bool ischanged = false;
      Class_packagemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_package> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_package>(val.vx_mappackage());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/packagemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_package? valany = null;
          if (valsub is Vx.Core.Type_package) {
            valany = (Vx.Core.Type_package)valsub;
          } else if (valsub is Vx.Core.Type_package) {
            valany = valsub as Vx.Core.Type_package;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/packagemap", ":invalidkeyvalue", msgmap);
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
        Class_packagemap work = new Class_packagemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_packagemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_packagemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "packagemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_package), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_permission : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
  }

  public class Class_permission : Vx.Core.Class_base, Type_permission {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_permission vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_permission,
       vals);
    }

    public override Vx.Core.Type_permission vx_copy(params Object[] vals) {
      Type_permission output = this;
      bool ischanged = false;
      Class_permission val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/permission", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/permission", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_id = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/permission", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/permission", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_permission work = new Class_permission();
        work.vx_p_id = vx_p_id;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_permission;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_permission;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "permission", // name
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

  public static Type_permission e_permission = new Class_permission();
  public static Type_permission t_permission = new Class_permission();

  /**
   * type: permissionlist
   * List of Permission
   * (type permissionlist)
   */
  public interface Type_permissionlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_permission> vx_listpermission();
    public Vx.Core.Type_permission vx_permission(Vx.Core.Type_int index);
  }

  public class Class_permissionlist : Vx.Core.Class_base, Type_permissionlist {

    public List<Vx.Core.Type_permission> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_permission>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_permission vx_permission(Vx.Core.Type_int index) {
      Vx.Core.Type_permission output = Vx.Core.e_permission;
      Vx.Core.Class_permissionlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_permission> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_permission> vx_listpermission() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_permission(index);
    }

    public override Vx.Core.Type_permissionlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_permissionlist,
       vals);
    }

    public override Vx.Core.Type_permissionlist vx_copy(params Object[] vals) {
      Type_permissionlist output = this;
      bool ischanged = false;
      Class_permissionlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_permission> listval = new List<Vx.Core.Type_permission>(val.vx_listpermission());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_permission allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_permission) {
          ischanged = true;
          listval.Add((Vx.Core.Type_permission)valsub);
        } else if (valsub is Vx.Core.Type_permissionlist) {
          Type_permissionlist multi = (Type_permissionlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listpermission());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_permission) {
              Vx.Core.Type_permission valitem = (Vx.Core.Type_permission)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/permissionlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/permissionlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_permissionlist work = new Class_permissionlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_permissionlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_permissionlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "permissionlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_permission), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_permissionmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_permission> vx_mappermission();
    public Vx.Core.Type_permission vx_permission(Vx.Core.Type_string key);
  }

  public class Class_permissionmap : Vx.Core.Class_base, Type_permissionmap {

    public Vx.Core.Map<string, Vx.Core.Type_permission> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_permission>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_permission) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_permission castval = (Vx.Core.Type_permission)value;
        Vx.Core.Map<string, Vx.Core.Type_permission> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_permission>(this.vx_p_map);
        if (castval == Vx.Core.e_permission) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_permission vx_permission(Vx.Core.Type_string key) {
      Vx.Core.Type_permission output = Vx.Core.e_permission;
      Vx.Core.Class_permissionmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_permission> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_permission);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_permission> vx_mappermission() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_permission(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_permissionmap output = new Vx.Core.Class_permissionmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_permission> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_permission>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_permission castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/permissionmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_permissionmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_permissionmap,
       vals);
    }

    public override Vx.Core.Type_permissionmap vx_copy(params Object[] vals) {
      Type_permissionmap output = this;
      bool ischanged = false;
      Class_permissionmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_permission> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_permission>(val.vx_mappermission());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/permissionmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_permission? valany = null;
          if (valsub is Vx.Core.Type_permission) {
            valany = (Vx.Core.Type_permission)valsub;
          } else if (valsub is Vx.Core.Type_permission) {
            valany = valsub as Vx.Core.Type_permission;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/permissionmap", ":invalidkeyvalue", msgmap);
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
        Class_permissionmap work = new Class_permissionmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_permissionmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_permissionmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "permissionmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_permission), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_project : Vx.Core.Type_struct {
    public Vx.Core.Type_packagemap packagemap();
  }

  public class Class_project : Vx.Core.Class_base, Type_project {

    public Vx.Core.Type_packagemap? vx_p_packagemap = null;

    public Vx.Core.Type_packagemap packagemap() {
      Vx.Core.Type_packagemap output = Vx.Core.e_packagemap;
      if (this.vx_p_packagemap != null) {
        output = this.vx_p_packagemap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":packagemap":
        output = this.packagemap();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":packagemap", this.packagemap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_project vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_project,
       vals);
    }

    public override Vx.Core.Type_project vx_copy(params Object[] vals) {
      Type_project output = this;
      bool ischanged = false;
      Class_project val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_packagemap vx_p_packagemap = val.packagemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":packagemap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/project", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/project", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":packagemap":
            if (valsub == vx_p_packagemap) {
            } else if (valsub is Vx.Core.Type_packagemap) {
              ischanged = true;
              vx_p_packagemap = (Vx.Core.Type_packagemap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("packagemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/project", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/project", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_project work = new Class_project();
        work.vx_p_packagemap = vx_p_packagemap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_project;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_project;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "project", // name
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

  public static Type_project e_project = new Class_project();
  public static Type_project t_project = new Class_project();

  /**
   * type: security
   * Security rules
   * (type security)
   */
  public interface Type_security : Vx.Core.Type_struct {
    public Vx.Core.Type_funclist allowfuncs();
    public Vx.Core.Type_permissionlist permissions();
    public Vx.Core.Type_permissionmap permissionmap();
  }

  public class Class_security : Vx.Core.Class_base, Type_security {

    public Vx.Core.Type_funclist? vx_p_allowfuncs = null;

    public Vx.Core.Type_funclist allowfuncs() {
      Vx.Core.Type_funclist output = Vx.Core.e_funclist;
      if (this.vx_p_allowfuncs != null) {
        output = this.vx_p_allowfuncs;
      }
      return output;
    }

    public Vx.Core.Type_permissionlist? vx_p_permissions = null;

    public Vx.Core.Type_permissionlist permissions() {
      Vx.Core.Type_permissionlist output = Vx.Core.e_permissionlist;
      if (this.vx_p_permissions != null) {
        output = this.vx_p_permissions;
      }
      return output;
    }

    public Vx.Core.Type_permissionmap? vx_p_permissionmap = null;

    public Vx.Core.Type_permissionmap permissionmap() {
      Vx.Core.Type_permissionmap output = Vx.Core.e_permissionmap;
      if (this.vx_p_permissionmap != null) {
        output = this.vx_p_permissionmap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":allowfuncs", this.allowfuncs());
      output.put(":permissions", this.permissions());
      output.put(":permissionmap", this.permissionmap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_security vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_security,
       vals);
    }

    public override Vx.Core.Type_security vx_copy(params Object[] vals) {
      Type_security output = this;
      bool ischanged = false;
      Class_security val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      Vx.Core.Type_permissionlist vx_p_permissions = val.permissions();
      Vx.Core.Type_permissionmap vx_p_permissionmap = val.permissionmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":allowfuncs");
      validkeys.Add(":permissions");
      validkeys.Add(":permissionmap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub is Vx.Core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (Vx.Core.Type_funclist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("allowfuncs"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":permissions":
            if (valsub == vx_p_permissions) {
            } else if (valsub is Vx.Core.Type_permissionlist) {
              ischanged = true;
              vx_p_permissions = (Vx.Core.Type_permissionlist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("permissions"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":permissionmap":
            if (valsub == vx_p_permissionmap) {
            } else if (valsub is Vx.Core.Type_permissionmap) {
              ischanged = true;
              vx_p_permissionmap = (Vx.Core.Type_permissionmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("permissionmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/security", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_security work = new Class_security();
        work.vx_p_allowfuncs = vx_p_allowfuncs;
        work.vx_p_permissions = vx_p_permissions;
        work.vx_p_permissionmap = vx_p_permissionmap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_security;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_security;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "security", // name
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

  public static Type_security e_security = new Class_security();
  public static Type_security t_security = new Class_security();

  /**
   * type: session
   * Session
   * (type session)
   */
  public interface Type_session : Vx.Core.Type_struct {
    public Vx.Core.Type_user user();
    public Vx.Core.Type_connectlist connectlist();
    public Vx.Core.Type_connectmap connectmap();
    public Vx.Core.Type_locale locale();
    public Vx.Core.Type_translation translation();
    public Vx.Core.Type_translationmap translationmap();
  }

  public class Class_session : Vx.Core.Class_base, Type_session {

    public Vx.Core.Type_user? vx_p_user = null;

    public Vx.Core.Type_user user() {
      Vx.Core.Type_user output = Vx.Core.e_user;
      if (this.vx_p_user != null) {
        output = this.vx_p_user;
      }
      return output;
    }

    public Vx.Core.Type_connectlist? vx_p_connectlist = null;

    public Vx.Core.Type_connectlist connectlist() {
      Vx.Core.Type_connectlist output = Vx.Core.e_connectlist;
      if (this.vx_p_connectlist != null) {
        output = this.vx_p_connectlist;
      }
      return output;
    }

    public Vx.Core.Type_connectmap? vx_p_connectmap = null;

    public Vx.Core.Type_connectmap connectmap() {
      Vx.Core.Type_connectmap output = Vx.Core.e_connectmap;
      if (this.vx_p_connectmap != null) {
        output = this.vx_p_connectmap;
      }
      return output;
    }

    public Vx.Core.Type_locale? vx_p_locale = null;

    public Vx.Core.Type_locale locale() {
      Vx.Core.Type_locale output = Vx.Core.e_locale;
      if (this.vx_p_locale != null) {
        output = this.vx_p_locale;
      }
      return output;
    }

    public Vx.Core.Type_translation? vx_p_translation = null;

    public Vx.Core.Type_translation translation() {
      Vx.Core.Type_translation output = Vx.Core.e_translation;
      if (this.vx_p_translation != null) {
        output = this.vx_p_translation;
      }
      return output;
    }

    public Vx.Core.Type_translationmap? vx_p_translationmap = null;

    public Vx.Core.Type_translationmap translationmap() {
      Vx.Core.Type_translationmap output = Vx.Core.e_translationmap;
      if (this.vx_p_translationmap != null) {
        output = this.vx_p_translationmap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":user", this.user());
      output.put(":connectlist", this.connectlist());
      output.put(":connectmap", this.connectmap());
      output.put(":locale", this.locale());
      output.put(":translation", this.translation());
      output.put(":translationmap", this.translationmap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_session vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_session,
       vals);
    }

    public override Vx.Core.Type_session vx_copy(params Object[] vals) {
      Type_session output = this;
      bool ischanged = false;
      Class_session val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_user vx_p_user = val.user();
      Vx.Core.Type_connectlist vx_p_connectlist = val.connectlist();
      Vx.Core.Type_connectmap vx_p_connectmap = val.connectmap();
      Vx.Core.Type_locale vx_p_locale = val.locale();
      Vx.Core.Type_translation vx_p_translation = val.translation();
      Vx.Core.Type_translationmap vx_p_translationmap = val.translationmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":user");
      validkeys.Add(":connectlist");
      validkeys.Add(":connectmap");
      validkeys.Add(":locale");
      validkeys.Add(":translation");
      validkeys.Add(":translationmap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":user":
            if (valsub == vx_p_user) {
            } else if (valsub is Vx.Core.Type_user) {
              ischanged = true;
              vx_p_user = (Vx.Core.Type_user)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("user"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":connectlist":
            if (valsub == vx_p_connectlist) {
            } else if (valsub is Vx.Core.Type_connectlist) {
              ischanged = true;
              vx_p_connectlist = (Vx.Core.Type_connectlist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("connectlist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":connectmap":
            if (valsub == vx_p_connectmap) {
            } else if (valsub is Vx.Core.Type_connectmap) {
              ischanged = true;
              vx_p_connectmap = (Vx.Core.Type_connectmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("connectmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":locale":
            if (valsub == vx_p_locale) {
            } else if (valsub is Vx.Core.Type_locale) {
              ischanged = true;
              vx_p_locale = (Vx.Core.Type_locale)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("locale"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":translation":
            if (valsub == vx_p_translation) {
            } else if (valsub is Vx.Core.Type_translation) {
              ischanged = true;
              vx_p_translation = (Vx.Core.Type_translation)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("translation"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":translationmap":
            if (valsub == vx_p_translationmap) {
            } else if (valsub is Vx.Core.Type_translationmap) {
              ischanged = true;
              vx_p_translationmap = (Vx.Core.Type_translationmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("translationmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/session", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_session work = new Class_session();
        work.vx_p_user = vx_p_user;
        work.vx_p_connectlist = vx_p_connectlist;
        work.vx_p_connectmap = vx_p_connectmap;
        work.vx_p_locale = vx_p_locale;
        work.vx_p_translation = vx_p_translation;
        work.vx_p_translationmap = vx_p_translationmap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_session;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_session;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "session", // name
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

  public static Type_session e_session = new Class_session();
  public static Type_session t_session = new Class_session();

  /**
   * type: setting
   * Settings
   * (type setting)
   */
  public interface Type_setting : Vx.Core.Type_struct {
    public Vx.Core.Type_stringmap pathmap();
  }

  public class Class_setting : Vx.Core.Class_base, Type_setting {

    public Vx.Core.Type_stringmap? vx_p_pathmap = null;

    public Vx.Core.Type_stringmap pathmap() {
      Vx.Core.Type_stringmap output = Vx.Core.e_stringmap;
      if (this.vx_p_pathmap != null) {
        output = this.vx_p_pathmap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":pathmap":
        output = this.pathmap();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":pathmap", this.pathmap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_setting vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_setting,
       vals);
    }

    public override Vx.Core.Type_setting vx_copy(params Object[] vals) {
      Type_setting output = this;
      bool ischanged = false;
      Class_setting val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_stringmap vx_p_pathmap = val.pathmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pathmap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/setting", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/setting", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pathmap":
            if (valsub == vx_p_pathmap) {
            } else if (valsub is Vx.Core.Type_stringmap) {
              ischanged = true;
              vx_p_pathmap = (Vx.Core.Type_stringmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pathmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/setting", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/setting", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_setting work = new Class_setting();
        work.vx_p_pathmap = vx_p_pathmap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_setting;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_setting;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "setting", // name
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

  public static Type_setting e_setting = new Class_setting();
  public static Type_setting t_setting = new Class_setting();

  /**
   * type: state
   * State. Note that this type is has mutable values.
   * (type state)
   */
  public interface Type_state : Vx.Core.Type_struct {
    public Vx.Core.Type_statelistenermap statelistenermap();
  }

  public class Class_state : Vx.Core.Class_base, Type_state {

    public Vx.Core.Type_statelistenermap? vx_p_statelistenermap = null;

    public Vx.Core.Type_statelistenermap statelistenermap() {
      Vx.Core.Type_statelistenermap output = Vx.Core.e_statelistenermap;
      if (this.vx_p_statelistenermap != null) {
        output = this.vx_p_statelistenermap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":statelistenermap":
        output = this.statelistenermap();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":statelistenermap", this.statelistenermap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_state vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_state,
       vals);
    }

    public override Vx.Core.Type_state vx_copy(params Object[] vals) {
      Type_state output = this;
      bool ischanged = false;
      Class_state val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_statelistenermap vx_p_statelistenermap = val.statelistenermap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":statelistenermap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/state", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/state", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":statelistenermap":
            if (valsub == vx_p_statelistenermap) {
            } else if (valsub is Vx.Core.Type_statelistenermap) {
              ischanged = true;
              vx_p_statelistenermap = (Vx.Core.Type_statelistenermap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("statelistenermap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/state", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/state", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_state work = new Class_state();
        work.vx_p_statelistenermap = vx_p_statelistenermap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_state;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_state;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "state", // name
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

  public static Type_state e_state = new Class_state();
  public static Type_state t_state = new Class_state();

  /**
   * type: statelistener
   * (type statelistener)
   */
  public interface Type_statelistener : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any value();
    public Vx.Core.Func_boolean_from_none fn_boolean();
  }

  public class Class_statelistener : Vx.Core.Class_base, Type_statelistener {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_value = null;

    public Vx.Core.Type_any value() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    public Vx.Core.Func_boolean_from_none? vx_p_fn_boolean = null;

    public Vx.Core.Func_boolean_from_none fn_boolean() {
      Vx.Core.Func_boolean_from_none output = Vx.Core.e_boolean_from_none;
      if (this.vx_p_fn_boolean != null) {
        output = this.vx_p_fn_boolean;
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
      case ":value":
        output = this.value();
        break;
      case ":fn-boolean":
        output = this.fn_boolean();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":value", this.value());
      output.put(":fn-boolean", this.fn_boolean());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_statelistener vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_statelistener,
       vals);
    }

    public override Vx.Core.Type_statelistener vx_copy(params Object[] vals) {
      Type_statelistener output = this;
      bool ischanged = false;
      Class_statelistener val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_any vx_p_value = val.value();
      Vx.Core.Func_boolean_from_none vx_p_fn_boolean = val.fn_boolean();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":value");
      validkeys.Add(":fn-boolean");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_value = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-boolean":
            if (valsub == vx_p_fn_boolean) {
            } else if (valsub is Vx.Core.Func_boolean_from_none) {
              ischanged = true;
              vx_p_fn_boolean = (Vx.Core.Func_boolean_from_none)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-boolean"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/statelistener", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_statelistener work = new Class_statelistener();
        work.vx_p_name = vx_p_name;
        work.vx_p_value = vx_p_value;
        work.vx_p_fn_boolean = vx_p_fn_boolean;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_statelistener;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_statelistener;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "statelistener", // name
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

  public static Type_statelistener e_statelistener = new Class_statelistener();
  public static Type_statelistener t_statelistener = new Class_statelistener();

  /**
   * type: statelistenermap
   * Mutable map of statelisteners
   * (type statelistenermap)
   */
  public interface Type_statelistenermap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_statelistener> vx_mapstatelistener();
    public Vx.Core.Type_statelistener vx_statelistener(Vx.Core.Type_string key);
  }

  public class Class_statelistenermap : Vx.Core.Class_base, Type_statelistenermap {

    public Vx.Core.Map<string, Vx.Core.Type_statelistener> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_statelistener>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_statelistener) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_statelistener castval = (Vx.Core.Type_statelistener)value;
        Vx.Core.Map<string, Vx.Core.Type_statelistener> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_statelistener>(this.vx_p_map);
        if (castval == Vx.Core.e_statelistener) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_statelistener vx_statelistener(Vx.Core.Type_string key) {
      Vx.Core.Type_statelistener output = Vx.Core.e_statelistener;
      Vx.Core.Class_statelistenermap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_statelistener> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_statelistener);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_statelistener> vx_mapstatelistener() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_statelistener(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_statelistenermap output = new Vx.Core.Class_statelistenermap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_statelistener> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_statelistener>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_statelistener castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/statelistenermap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_statelistenermap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_statelistenermap,
       vals);
    }

    public override Vx.Core.Type_statelistenermap vx_copy(params Object[] vals) {
      Type_statelistenermap output = this;
      bool ischanged = false;
      Class_statelistenermap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_statelistener> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_statelistener>(val.vx_mapstatelistener());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/statelistenermap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_statelistener? valany = null;
          if (valsub is Vx.Core.Type_statelistener) {
            valany = (Vx.Core.Type_statelistener)valsub;
          } else if (valsub is Vx.Core.Type_statelistener) {
            valany = valsub as Vx.Core.Type_statelistener;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/statelistenermap", ":invalidkeyvalue", msgmap);
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
        Class_statelistenermap work = new Class_statelistenermap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_statelistenermap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_statelistenermap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "statelistenermap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_statelistener), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_string : Vx.Core.Type_any {
    public string vx_string();
  }

  public class Class_string : Vx.Core.Class_base, Type_string {

    internal string vxstring = "";
    
    // :implements
    public string vx_string() {
      return vxstring;
    }

    public override Vx.Core.Type_string vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_string,
       vals);
    }

    public override Vx.Core.Type_string vx_copy(params Object[] vals) {
      Type_string output = this;
      bool ischanged = false;
      Class_string val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      System.Text.StringBuilder sb = new System.Text.StringBuilder(val.vx_string());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_string valstring) {
          string ssub = valstring.vx_string();
          if (ssub == "") {
          } else {
            ischanged = true;
            sb.Append(ssub);
          }
        } else if (valsub is Vx.Core.Type_int valint) {
          ischanged = true;
          sb.Append(valint.vx_int());
        } else if (valsub is Vx.Core.Type_float valfloat) {
          ischanged = true;
          sb.Append(valfloat.vx_float());
        } else if (valsub is Vx.Core.Type_decimal valdecimal) {
          ischanged = true;
          sb.Append(valdecimal.vx_string());
        } else if (valsub is string sval) {
          if (sval == "") {
          } else {
            ischanged = true;
            sb.Append(sval);
          }
        } else if (valsub is int ival) {
          ischanged = true;
          sb.Append(ival);
        } else if (valsub is float fval) {
          ischanged = true;
          sb.Append(fval);
        } else if (valsub is Vx.Core.Type_any anysub) {
          msg = Vx.Core.vx_msg_from_error("vx/core/string", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/string", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        string vxstring = Vx.Core.vx_string_from_object(sb);
        Class_string work = new Class_string();
        work.vxstring = vxstring;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_string;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
  public interface Type_stringlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_string> vx_liststring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_int index);
  }

  public class Class_stringlist : Vx.Core.Class_base, Type_stringlist {

    public List<Vx.Core.Type_string> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_string>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_string vx_string(Vx.Core.Type_int index) {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Class_stringlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_string> vx_liststring() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_string(index);
    }

    public override Vx.Core.Type_stringlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stringlist,
       vals);
    }

    public override Vx.Core.Type_stringlist vx_copy(params Object[] vals) {
      Type_stringlist output = this;
      bool ischanged = false;
      Class_stringlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_string> listval = new List<Vx.Core.Type_string>(val.vx_liststring());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_string allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_string) {
          ischanged = true;
          listval.Add(Vx.Core.vx_new(Vx.Core.t_string, valsub));
        } else if (valsub is Vx.Core.Type_stringlist) {
          Type_stringlist multi = (Type_stringlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_liststring());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_string) {
              Vx.Core.Type_string valitem = (Vx.Core.Type_string)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/stringlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/stringlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_stringlist work = new Class_stringlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stringlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_stringlistlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_stringlist> vx_liststringlist();
    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_int index);
  }

  public class Class_stringlistlist : Vx.Core.Class_base, Type_stringlistlist {

    public List<Vx.Core.Type_stringlist> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_stringlist>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_int index) {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      Vx.Core.Class_stringlistlist list = this;
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

    public override Vx.Core.Type_stringlistlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stringlistlist,
       vals);
    }

    public override Vx.Core.Type_stringlistlist vx_copy(params Object[] vals) {
      Type_stringlistlist output = this;
      bool ischanged = false;
      Class_stringlistlist val = this;
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
        } else if (valsub is Vx.Core.Type_stringlistlist) {
          Type_stringlistlist multi = (Type_stringlistlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_liststringlist());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_stringlist) {
              Vx.Core.Type_stringlist valitem = (Vx.Core.Type_stringlist)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/stringlistlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/stringlistlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_stringlistlist work = new Class_stringlistlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringlistlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stringlistlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "stringlistlist", // name
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

  public static Type_stringlistlist e_stringlistlist = new Class_stringlistlist();
  public static Type_stringlistlist t_stringlistlist = new Class_stringlistlist();

  /**
   * type: stringmap
   * A map of string.
   * (type stringmap)
   */
  public interface Type_stringmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key);
  }

  public class Class_stringmap : Vx.Core.Class_base, Type_stringmap {

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_string) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_string castval = (Vx.Core.Type_string)value;
        Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(this.vx_p_map);
        if (castval == Vx.Core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key) {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Class_stringmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_string);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_string(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_stringmap output = new Vx.Core.Class_stringmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_string castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/stringmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_stringmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stringmap,
       vals);
    }

    public override Vx.Core.Type_stringmap vx_copy(params Object[] vals) {
      Type_stringmap output = this;
      bool ischanged = false;
      Class_stringmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(val.vx_mapstring());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/stringmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_string? valany = null;
          if (valsub is Vx.Core.Type_string) {
            valany = (Vx.Core.Type_string)valsub;
          } else if (valsub is string) {
            valany = Vx.Core.vx_new(Vx.Core.t_string, valsub);
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
            msg = Vx.Core.vx_msg_from_error("vx/core/stringmap", ":invalidkeyvalue", msgmap);
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
        Class_stringmap work = new Class_stringmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stringmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
  public interface Type_stringmutablemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key);
  }

  public class Class_stringmutablemap : Vx.Core.Class_base, Type_stringmutablemap {

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_string) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_string castval = (Vx.Core.Type_string)value;
        Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(this.vx_p_map);
        if (castval == Vx.Core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key) {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Class_stringmutablemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_string);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_string(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_stringmutablemap output = new Vx.Core.Class_stringmutablemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_string castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/stringmutablemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_stringmutablemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stringmutablemap,
       vals);
    }

    public override Vx.Core.Type_stringmutablemap vx_copy(params Object[] vals) {
      Type_stringmutablemap output = this;
      bool ischanged = false;
      Class_stringmutablemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(val.vx_mapstring());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/stringmutablemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_string? valany = null;
          if (valsub is Vx.Core.Type_string) {
            valany = (Vx.Core.Type_string)valsub;
          } else if (valsub is string) {
            valany = Vx.Core.vx_new(Vx.Core.t_string, valsub);
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
            msg = Vx.Core.vx_msg_from_error("vx/core/stringmutablemap", ":invalidkeyvalue", msgmap);
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
        Class_stringmutablemap work = new Class_stringmutablemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringmutablemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stringmutablemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "stringmutablemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_struct : Vx.Core.Type_any {
    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key);
    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map();
  }

  public class Class_struct : Vx.Core.Class_base, Type_struct {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_struct vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_struct,
       vals);
    }

    public override Vx.Core.Type_struct vx_copy(params Object[] vals) {
      Type_struct output = this;
      bool ischanged = false;
      Class_struct val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_struct work = new Class_struct();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_struct;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_struct;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "struct", // name
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

  public static Type_struct e_struct = new Class_struct();
  public static Type_struct t_struct = new Class_struct();

  /**
   * type: thenelse
   * (type thenelse)
   */
  public interface Type_thenelse : Vx.Core.Type_struct {
    public Vx.Core.Type_string code();
    public Vx.Core.Type_any value();
    public Vx.Core.Type_list values();
    public Vx.Core.Func_boolean_from_func fn_cond();
    public Vx.Core.Func_any_from_func fn_any();
  }

  public class Class_thenelse : Vx.Core.Class_base, Type_thenelse {

    public Vx.Core.Type_string? vx_p_code = null;

    public Vx.Core.Type_string code() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_code != null) {
        output = this.vx_p_code;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_value = null;

    public Vx.Core.Type_any value() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    public Vx.Core.Type_list? vx_p_values = null;

    public Vx.Core.Type_list values() {
      Vx.Core.Type_list output = Vx.Core.e_list;
      if (this.vx_p_values != null) {
        output = this.vx_p_values;
      }
      return output;
    }

    public Vx.Core.Func_boolean_from_func? vx_p_fn_cond = null;

    public Vx.Core.Func_boolean_from_func fn_cond() {
      Vx.Core.Func_boolean_from_func output = Vx.Core.e_boolean_from_func;
      if (this.vx_p_fn_cond != null) {
        output = this.vx_p_fn_cond;
      }
      return output;
    }

    public Vx.Core.Func_any_from_func? vx_p_fn_any = null;

    public Vx.Core.Func_any_from_func fn_any() {
      Vx.Core.Func_any_from_func output = Vx.Core.e_any_from_func;
      if (this.vx_p_fn_any != null) {
        output = this.vx_p_fn_any;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":code", this.code());
      output.put(":value", this.value());
      output.put(":values", this.values());
      output.put(":fn-cond", this.fn_cond());
      output.put(":fn-any", this.fn_any());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_thenelse vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_thenelse,
       vals);
    }

    public override Vx.Core.Type_thenelse vx_copy(params Object[] vals) {
      Type_thenelse output = this;
      bool ischanged = false;
      Class_thenelse val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_code = val.code();
      Vx.Core.Type_any vx_p_value = val.value();
      Vx.Core.Type_list vx_p_values = val.values();
      Vx.Core.Func_boolean_from_func vx_p_fn_cond = val.fn_cond();
      Vx.Core.Func_any_from_func vx_p_fn_any = val.fn_any();
      List<string> validkeys = new List<string>();
      validkeys.Add(":code");
      validkeys.Add(":value");
      validkeys.Add(":values");
      validkeys.Add(":fn-cond");
      validkeys.Add(":fn-any");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_code = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_code = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("code"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_value = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":values":
            if (valsub == vx_p_values) {
            } else if (valsub is Vx.Core.Type_list) {
              ischanged = true;
              vx_p_values = (Vx.Core.Type_list)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("values"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-cond":
            if (valsub == vx_p_fn_cond) {
            } else if (valsub is Vx.Core.Func_boolean_from_func) {
              ischanged = true;
              vx_p_fn_cond = (Vx.Core.Func_boolean_from_func)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-cond"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub is Vx.Core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (Vx.Core.Func_any_from_func)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-any"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/thenelse", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_thenelse work = new Class_thenelse();
        work.vx_p_code = vx_p_code;
        work.vx_p_value = vx_p_value;
        work.vx_p_values = vx_p_values;
        work.vx_p_fn_cond = vx_p_fn_cond;
        work.vx_p_fn_any = vx_p_fn_any;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_thenelse;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_thenelse;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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

  public static Type_thenelse e_thenelse = new Class_thenelse();
  public static Type_thenelse t_thenelse = new Class_thenelse();

  /**
   * type: thenelselist
   * (type thenelselist)
   */
  public interface Type_thenelselist : Vx.Core.Type_list {
    public List<Vx.Core.Type_thenelse> vx_listthenelse();
    public Vx.Core.Type_thenelse vx_thenelse(Vx.Core.Type_int index);
  }

  public class Class_thenelselist : Vx.Core.Class_base, Type_thenelselist {

    public List<Vx.Core.Type_thenelse> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_thenelse>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_thenelse vx_thenelse(Vx.Core.Type_int index) {
      Vx.Core.Type_thenelse output = Vx.Core.e_thenelse;
      Vx.Core.Class_thenelselist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_thenelse> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_thenelse> vx_listthenelse() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_thenelse(index);
    }

    public override Vx.Core.Type_thenelselist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_thenelselist,
       vals);
    }

    public override Vx.Core.Type_thenelselist vx_copy(params Object[] vals) {
      Type_thenelselist output = this;
      bool ischanged = false;
      Class_thenelselist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_thenelse> listval = new List<Vx.Core.Type_thenelse>(val.vx_listthenelse());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_thenelse allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_thenelse) {
          ischanged = true;
          listval.Add((Vx.Core.Type_thenelse)valsub);
        } else if (valsub is Vx.Core.Type_thenelselist) {
          Type_thenelselist multi = (Type_thenelselist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listthenelse());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_thenelse) {
              Vx.Core.Type_thenelse valitem = (Vx.Core.Type_thenelse)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/thenelselist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/thenelselist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_thenelselist work = new Class_thenelselist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_thenelselist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_thenelselist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "thenelselist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_thenelse), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_translation : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_stringmap wordmap();
  }

  public class Class_translation : Vx.Core.Class_base, Type_translation {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_stringmap? vx_p_wordmap = null;

    public Vx.Core.Type_stringmap wordmap() {
      Vx.Core.Type_stringmap output = Vx.Core.e_stringmap;
      if (this.vx_p_wordmap != null) {
        output = this.vx_p_wordmap;
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
      case ":wordmap":
        output = this.wordmap();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":wordmap", this.wordmap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_translation vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_translation,
       vals);
    }

    public override Vx.Core.Type_translation vx_copy(params Object[] vals) {
      Type_translation output = this;
      bool ischanged = false;
      Class_translation val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_stringmap vx_p_wordmap = val.wordmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":wordmap");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/translation", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/translation", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/translation", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":wordmap":
            if (valsub == vx_p_wordmap) {
            } else if (valsub is Vx.Core.Type_stringmap) {
              ischanged = true;
              vx_p_wordmap = (Vx.Core.Type_stringmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("wordmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/translation", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/translation", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_translation work = new Class_translation();
        work.vx_p_name = vx_p_name;
        work.vx_p_wordmap = vx_p_wordmap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translation;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_translation;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "translation", // name
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

  public static Type_translation e_translation = new Class_translation();
  public static Type_translation t_translation = new Class_translation();

  /**
   * type: translationlist
   * i18 language translation list.
   * (type translationlist)
   */
  public interface Type_translationlist : Vx.Core.Type_list {
    public List<Vx.Core.Type_translation> vx_listtranslation();
    public Vx.Core.Type_translation vx_translation(Vx.Core.Type_int index);
  }

  public class Class_translationlist : Vx.Core.Class_base, Type_translationlist {

    public List<Vx.Core.Type_translation> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_translation>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_translation vx_translation(Vx.Core.Type_int index) {
      Vx.Core.Type_translation output = Vx.Core.e_translation;
      Vx.Core.Class_translationlist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_translation> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_translation> vx_listtranslation() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_translation(index);
    }

    public override Vx.Core.Type_translationlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_translationlist,
       vals);
    }

    public override Vx.Core.Type_translationlist vx_copy(params Object[] vals) {
      Type_translationlist output = this;
      bool ischanged = false;
      Class_translationlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_translation> listval = new List<Vx.Core.Type_translation>(val.vx_listtranslation());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_translation allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_translation) {
          ischanged = true;
          listval.Add((Vx.Core.Type_translation)valsub);
        } else if (valsub is Vx.Core.Type_translationlist) {
          Type_translationlist multi = (Type_translationlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtranslation());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_translation) {
              Vx.Core.Type_translation valitem = (Vx.Core.Type_translation)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/translationlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/translationlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_translationlist work = new Class_translationlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translationlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_translationlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "translationlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_translation), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_translationmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_translation> vx_maptranslation();
    public Vx.Core.Type_translation vx_translation(Vx.Core.Type_string key);
  }

  public class Class_translationmap : Vx.Core.Class_base, Type_translationmap {

    public Vx.Core.Map<string, Vx.Core.Type_translation> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_translation>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_translation) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_translation castval = (Vx.Core.Type_translation)value;
        Vx.Core.Map<string, Vx.Core.Type_translation> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_translation>(this.vx_p_map);
        if (castval == Vx.Core.e_translation) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_translation vx_translation(Vx.Core.Type_string key) {
      Vx.Core.Type_translation output = Vx.Core.e_translation;
      Vx.Core.Class_translationmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_translation> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_translation);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_translation> vx_maptranslation() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_translation(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_translationmap output = new Vx.Core.Class_translationmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_translation> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_translation>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_translation castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/translationmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_translationmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_translationmap,
       vals);
    }

    public override Vx.Core.Type_translationmap vx_copy(params Object[] vals) {
      Type_translationmap output = this;
      bool ischanged = false;
      Class_translationmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_translation> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_translation>(val.vx_maptranslation());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/translationmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_translation? valany = null;
          if (valsub is Vx.Core.Type_translation) {
            valany = (Vx.Core.Type_translation)valsub;
          } else if (valsub is Vx.Core.Type_translation) {
            valany = valsub as Vx.Core.Type_translation;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/translationmap", ":invalidkeyvalue", msgmap);
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
        Class_translationmap work = new Class_translationmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translationmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_translationmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "translationmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_translation), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_type : Vx.Core.Type_any {
  }

  public class Class_type : Vx.Core.Class_base, Type_type {

    public override Vx.Core.Type_type vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_type,
       vals);
    }

    public override Vx.Core.Type_type vx_copy(params Object[] vals) {
      Type_type output = this;
      bool ischanged = false;
      Class_type val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_type work = new Class_type();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_type;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_type;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "type", // name
        ":type", // extends
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

  public static Type_type e_type = new Class_type();
  public static Type_type t_type = new Class_type();

  /**
   * type: typedef
   * Type Definition Class for inspecting Type properties.
   * (type typedef)
   */
  public interface Type_typedef : Vx.Core.Type_struct {
    public Vx.Core.Type_string pkgname();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string extend();
    public Vx.Core.Type_funclist allowfuncs();
    public Vx.Core.Type_typelist allowtypes();
    public Vx.Core.Type_anylist allowvalues();
    public Vx.Core.Type_funclist disallowfuncs();
    public Vx.Core.Type_typelist disallowtypes();
    public Vx.Core.Type_anylist disallowvalues();
    public Vx.Core.Type_argmap properties();
    public Vx.Core.Type_arg proplast();
    public Vx.Core.Type_typelist traits();
  }

  public class Class_typedef : Vx.Core.Class_base, Type_typedef {

    public Vx.Core.Type_string? vx_p_pkgname = null;

    public Vx.Core.Type_string pkgname() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_pkgname != null) {
        output = this.vx_p_pkgname;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_extend = null;

    public Vx.Core.Type_string extend() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_extend != null) {
        output = this.vx_p_extend;
      }
      return output;
    }

    public Vx.Core.Type_funclist? vx_p_allowfuncs = null;

    public Vx.Core.Type_funclist allowfuncs() {
      Vx.Core.Type_funclist output = Vx.Core.e_funclist;
      if (this.vx_p_allowfuncs != null) {
        output = this.vx_p_allowfuncs;
      }
      return output;
    }

    public Vx.Core.Type_typelist? vx_p_allowtypes = null;

    public Vx.Core.Type_typelist allowtypes() {
      Vx.Core.Type_typelist output = Vx.Core.e_typelist;
      if (this.vx_p_allowtypes != null) {
        output = this.vx_p_allowtypes;
      }
      return output;
    }

    public Vx.Core.Type_anylist? vx_p_allowvalues = null;

    public Vx.Core.Type_anylist allowvalues() {
      Vx.Core.Type_anylist output = Vx.Core.e_anylist;
      if (this.vx_p_allowvalues != null) {
        output = this.vx_p_allowvalues;
      }
      return output;
    }

    public Vx.Core.Type_funclist? vx_p_disallowfuncs = null;

    public Vx.Core.Type_funclist disallowfuncs() {
      Vx.Core.Type_funclist output = Vx.Core.e_funclist;
      if (this.vx_p_disallowfuncs != null) {
        output = this.vx_p_disallowfuncs;
      }
      return output;
    }

    public Vx.Core.Type_typelist? vx_p_disallowtypes = null;

    public Vx.Core.Type_typelist disallowtypes() {
      Vx.Core.Type_typelist output = Vx.Core.e_typelist;
      if (this.vx_p_disallowtypes != null) {
        output = this.vx_p_disallowtypes;
      }
      return output;
    }

    public Vx.Core.Type_anylist? vx_p_disallowvalues = null;

    public Vx.Core.Type_anylist disallowvalues() {
      Vx.Core.Type_anylist output = Vx.Core.e_anylist;
      if (this.vx_p_disallowvalues != null) {
        output = this.vx_p_disallowvalues;
      }
      return output;
    }

    public Vx.Core.Type_argmap? vx_p_properties = null;

    public Vx.Core.Type_argmap properties() {
      Vx.Core.Type_argmap output = Vx.Core.e_argmap;
      if (this.vx_p_properties != null) {
        output = this.vx_p_properties;
      }
      return output;
    }

    public Vx.Core.Type_arg? vx_p_proplast = null;

    public Vx.Core.Type_arg proplast() {
      Vx.Core.Type_arg output = Vx.Core.e_arg;
      if (this.vx_p_proplast != null) {
        output = this.vx_p_proplast;
      }
      return output;
    }

    public Vx.Core.Type_typelist? vx_p_traits = null;

    public Vx.Core.Type_typelist traits() {
      Vx.Core.Type_typelist output = Vx.Core.e_typelist;
      if (this.vx_p_traits != null) {
        output = this.vx_p_traits;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_typedef vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_typedef,
       vals);
    }

    public override Vx.Core.Type_typedef vx_copy(params Object[] vals) {
      Type_typedef output = this;
      bool ischanged = false;
      Class_typedef val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_pkgname = val.pkgname();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_extend = val.extend();
      Vx.Core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      Vx.Core.Type_typelist vx_p_allowtypes = val.allowtypes();
      Vx.Core.Type_anylist vx_p_allowvalues = val.allowvalues();
      Vx.Core.Type_funclist vx_p_disallowfuncs = val.disallowfuncs();
      Vx.Core.Type_typelist vx_p_disallowtypes = val.disallowtypes();
      Vx.Core.Type_anylist vx_p_disallowvalues = val.disallowvalues();
      Vx.Core.Type_argmap vx_p_properties = val.properties();
      Vx.Core.Type_arg vx_p_proplast = val.proplast();
      Vx.Core.Type_typelist vx_p_traits = val.traits();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pkgname");
      validkeys.Add(":name");
      validkeys.Add(":extends");
      validkeys.Add(":allowfuncs");
      validkeys.Add(":allowtypes");
      validkeys.Add(":allowvalues");
      validkeys.Add(":disallowfuncs");
      validkeys.Add(":disallowtypes");
      validkeys.Add(":disallowvalues");
      validkeys.Add(":properties");
      validkeys.Add(":proplast");
      validkeys.Add(":traits");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_pkgname = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pkgname"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
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
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":extends":
            if (valsub == vx_p_extend) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_extend = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_extend = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("extends"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub is Vx.Core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (Vx.Core.Type_funclist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("allowfuncs"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowtypes":
            if (valsub == vx_p_allowtypes) {
            } else if (valsub is Vx.Core.Type_typelist) {
              ischanged = true;
              vx_p_allowtypes = (Vx.Core.Type_typelist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("allowtypes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":allowvalues":
            if (valsub == vx_p_allowvalues) {
            } else if (valsub is Vx.Core.Type_anylist) {
              ischanged = true;
              vx_p_allowvalues = (Vx.Core.Type_anylist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("allowvalues"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowfuncs":
            if (valsub == vx_p_disallowfuncs) {
            } else if (valsub is Vx.Core.Type_funclist) {
              ischanged = true;
              vx_p_disallowfuncs = (Vx.Core.Type_funclist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("disallowfuncs"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowtypes":
            if (valsub == vx_p_disallowtypes) {
            } else if (valsub is Vx.Core.Type_typelist) {
              ischanged = true;
              vx_p_disallowtypes = (Vx.Core.Type_typelist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("disallowtypes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":disallowvalues":
            if (valsub == vx_p_disallowvalues) {
            } else if (valsub is Vx.Core.Type_anylist) {
              ischanged = true;
              vx_p_disallowvalues = (Vx.Core.Type_anylist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("disallowvalues"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":properties":
            if (valsub == vx_p_properties) {
            } else if (valsub is Vx.Core.Type_argmap) {
              ischanged = true;
              vx_p_properties = (Vx.Core.Type_argmap)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("properties"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":proplast":
            if (valsub == vx_p_proplast) {
            } else if (valsub is Vx.Core.Type_arg) {
              ischanged = true;
              vx_p_proplast = (Vx.Core.Type_arg)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("proplast"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":traits":
            if (valsub == vx_p_traits) {
            } else if (valsub is Vx.Core.Type_typelist) {
              ischanged = true;
              vx_p_traits = (Vx.Core.Type_typelist)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("traits"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/typedef", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
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
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typedef;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_typedef;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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

  public static Type_typedef e_typedef = new Class_typedef();
  public static Type_typedef t_typedef = new Class_typedef();

  /**
   * type: typelist
   * List of Types
   * (type typelist)
   */
  public interface Type_typelist : Vx.Core.Type_list {
  }

  public class Class_typelist : Vx.Core.Class_base, Type_typelist {

    public List<Vx.Core.Type_any> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_any>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_typelist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public override Vx.Core.Type_typelist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_typelist,
       vals);
    }

    public override Vx.Core.Type_typelist vx_copy(params Object[] vals) {
      Type_typelist output = this;
      bool ischanged = false;
      Class_typelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_any> listval = new List<Vx.Core.Type_any>(val.vx_list());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_any allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_typelist) {
          Type_typelist multi = (Type_typelist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_list());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (item is Vx.Core.Type_any) {
              Vx.Core.Type_any valitem = (Vx.Core.Type_any)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/core/typelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/core/typelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_typelist work = new Class_typelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_typelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_typemap : Vx.Core.Type_map {
  }

  public class Class_typemap : Vx.Core.Class_base, Type_typemap {

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Core.Type_any) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Type_any castval = (Vx.Core.Type_any)value;
        Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(this.vx_p_map);
        if (castval == Vx.Core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Class_typemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_any);
      return output;
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Core.Class_typemap output = new Vx.Core.Class_typemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_any castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/typemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_typemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_typemap,
       vals);
    }

    public override Vx.Core.Type_typemap vx_copy(params Object[] vals) {
      Type_typemap output = this;
      bool ischanged = false;
      Class_typemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(val.vx_map());
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
            msg = Vx.Core.vx_msg_from_error("vx/core/typemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_any? valany = null;
          if (valsub is Vx.Core.Type_any) {
            valany = (Vx.Core.Type_any)valsub;
          } else if (valsub is Vx.Core.Type_any) {
            valany = valsub as Vx.Core.Type_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/core/typemap", ":invalidkeyvalue", msgmap);
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
        Class_typemap work = new Class_typemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_typemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "typemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_user : Vx.Core.Type_struct {
    public Vx.Core.Type_security security();
    public Vx.Core.Type_string username();
    public Vx.Core.Type_string token();
  }

  public class Class_user : Vx.Core.Class_base, Type_user {

    public Vx.Core.Type_security? vx_p_security = null;

    public Vx.Core.Type_security security() {
      Vx.Core.Type_security output = Vx.Core.e_security;
      if (this.vx_p_security != null) {
        output = this.vx_p_security;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_username = null;

    public Vx.Core.Type_string username() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_username != null) {
        output = this.vx_p_username;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_token = null;

    public Vx.Core.Type_string token() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_token != null) {
        output = this.vx_p_token;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":security", this.security());
      output.put(":username", this.username());
      output.put(":token", this.token());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_user vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_user,
       vals);
    }

    public override Vx.Core.Type_user vx_copy(params Object[] vals) {
      Type_user output = this;
      bool ischanged = false;
      Class_user val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_security vx_p_security = val.security();
      Vx.Core.Type_string vx_p_username = val.username();
      Vx.Core.Type_string vx_p_token = val.token();
      List<string> validkeys = new List<string>();
      validkeys.Add(":security");
      validkeys.Add(":username");
      validkeys.Add(":token");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":security":
            if (valsub == vx_p_security) {
            } else if (valsub is Vx.Core.Type_security) {
              ischanged = true;
              vx_p_security = (Vx.Core.Type_security)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("security"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":username":
            if (valsub == vx_p_username) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_username = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_username = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("username"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":token":
            if (valsub == vx_p_token) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_token = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_token = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("token"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/user", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_user work = new Class_user();
        work.vx_p_security = vx_p_security;
        work.vx_p_username = vx_p_username;
        work.vx_p_token = vx_p_token;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_user;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_user;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "user", // name
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

  public static Type_user e_user = new Class_user();
  public static Type_user t_user = new Class_user();

  /**
   * type: value
   * (type value)
   */
  public interface Type_value : Vx.Core.Type_struct {
    public Vx.Core.Type_any next();
    public Vx.Core.Type_int refs();
  }

  public class Class_value : Vx.Core.Class_base, Type_value {

    public Vx.Core.Type_any? vx_p_next = null;

    public Vx.Core.Type_any next() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_next != null) {
        output = this.vx_p_next;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_refs = null;

    public Vx.Core.Type_int refs() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_refs != null) {
        output = this.vx_p_refs;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":next", this.next());
      output.put(":refs", this.refs());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Core.Type_value vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_value,
       vals);
    }

    public override Vx.Core.Type_value vx_copy(params Object[] vals) {
      Type_value output = this;
      bool ischanged = false;
      Class_value val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_any vx_p_next = val.next();
      Vx.Core.Type_int vx_p_refs = val.refs();
      List<string> validkeys = new List<string>();
      validkeys.Add(":next");
      validkeys.Add(":refs");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/core/value", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/core/value", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":next":
            if (valsub == vx_p_next) {
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_next = (Vx.Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("next"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/value", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":refs":
            if (valsub == vx_p_refs) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_refs = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_refs = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("refs"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/core/value", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/core/value", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_value work = new Class_value();
        work.vx_p_next = vx_p_next;
        work.vx_p_refs = vx_p_refs;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_value;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_value;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/core", // pkgname
        "value", // name
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

  public static Type_value e_value = new Class_value();
  public static Type_value t_value = new Class_value();

  /**
   * Constant: false
   * {boolean}
   */
  public class Const_false : Vx.Core.Class_boolean, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "false", // name
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
        )
      );
    }

    public static void const_new(Const_false output) {
    }

    public 
    new bool vx_boolean() {
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
  public class Const_global : Vx.Core.Class_project, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "global", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "project", // name
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

    public static void const_new(Const_global output) {
    }


  }

  public static Const_global c_global = new Const_global();


  /**
   * Constant: infinity
   * Infinity. Returned during unusual calculations.
   * {int}
   */
  public class Const_infinity : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "infinity", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_infinity output) {
    }

    public 
    new int vx_int() {
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
  public class Const_mempool_active : Vx.Core.Class_mempool, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "mempool-active", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "mempool", // name
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

    public static void const_new(Const_mempool_active output) {
    }


  }

  public static Const_mempool_active c_mempool_active = new Const_mempool_active();


  /**
   * Constant: msg-error
   * Message is an Error
   * {int}
   */
  public class Const_msg_error : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "msg-error", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_msg_error output) {
    }

    public 
    new int vx_int() {
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
  public class Const_msg_info : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "msg-info", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_msg_info output) {
    }

    public 
    new int vx_int() {
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
  public class Const_msg_severe : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "msg-severe", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_msg_severe output) {
    }

    public 
    new int vx_int() {
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
  public class Const_msg_warning : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "msg-warning", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_msg_warning output) {
    }

    public 
    new int vx_int() {
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
  public class Const_neginfinity : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "neginfinity", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_neginfinity output) {
    }

    public 
    new int vx_int() {
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
  public class Const_newline : Vx.Core.Class_string, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "newline", // name
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
        )
      );
    }

    public static void const_new(Const_newline output) {
    }

    public 
    new string vx_string() {
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
  public class Const_notanumber : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "notanumber", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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

    public static void const_new(Const_notanumber output) {
    }

    public 
    new int vx_int() {
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
  public class Const_nothing : Vx.Core.Class_string, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "nothing", // name
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
        )
      );
    }

    public static void const_new(Const_nothing output) {
    }

    public 
    new string vx_string() {
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
  public class Const_quote : Vx.Core.Class_string, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "quote", // name
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
        )
      );
    }

    public static void const_new(Const_quote output) {
    }

    public 
    new string vx_string() {
      this.vxstring = "\"";
      return this.vxstring;
    }

  }

  public static Const_quote c_quote = new Const_quote();


  /**
   * Constant: true
   * {boolean}
   */
  public class Const_true : Vx.Core.Class_boolean, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/core", // pkgname
        "true", // name
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
        )
      );
    }

    public static void const_new(Const_true output) {
    }

    public 
    new bool vx_boolean() {
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
  public interface Func_not : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_not(Vx.Core.Type_boolean val);
  }

  public class Class_not : Vx.Core.Class_base, Func_not {

    public override Vx.Core.Func_not vx_new(params Object[] vals) {
      Class_not output = new Class_not();
      return output;
    }

    public override Vx.Core.Func_not vx_copy(params Object[] vals) {
      Class_not output = new Class_not();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "!", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_not;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_not;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_boolean inputval = (Vx.Core.Type_boolean)value;
      Vx.Core.Type_any outputval = Vx.Core.f_not(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_boolean val = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_not(val);
      return output;
    }

    public Vx.Core.Type_boolean vx_not(Vx.Core.Type_boolean val) {
      return Vx.Core.f_not(val);
    }

  }

  public static Func_not e_not = new Vx.Core.Class_not();
  public static Func_not t_not = new Vx.Core.Class_not();

  public static Vx.Core.Type_boolean f_not(Vx.Core.Type_boolean val) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function notempty
   * Returns true if text is not empty.
   * @param  {string} text
   * @return {boolean}
   * (func !-empty)
   */
  public interface Func_notempty : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_notempty(Vx.Core.Type_string text);
  }

  public class Class_notempty : Vx.Core.Class_base, Func_notempty {

    public override Vx.Core.Func_notempty vx_new(params Object[] vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    public override Vx.Core.Func_notempty vx_copy(params Object[] vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_notempty;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_notempty;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_notempty(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_notempty(text);
      return output;
    }

    public Vx.Core.Type_boolean vx_notempty(Vx.Core.Type_string text) {
      return Vx.Core.f_notempty(text);
    }

  }

  public static Func_notempty e_notempty = new Vx.Core.Class_notempty();
  public static Func_notempty t_notempty = new Vx.Core.Class_notempty();

  public static Vx.Core.Type_boolean f_notempty(Vx.Core.Type_string text) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_is_empty(text)
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
  public interface Func_notempty_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_notempty_1(Vx.Core.Type_any val);
  }

  public class Class_notempty_1 : Vx.Core.Class_base, Func_notempty_1 {

    public override Vx.Core.Func_notempty_1 vx_new(params Object[] vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    public override Vx.Core.Func_notempty_1 vx_copy(params Object[] vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_notempty_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_notempty_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_notempty_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_notempty_1(val);
      return output;
    }

    public Vx.Core.Type_boolean vx_notempty_1(Vx.Core.Type_any val) {
      return Vx.Core.f_notempty_1(val);
    }

  }

  public static Func_notempty_1 e_notempty_1 = new Vx.Core.Class_notempty_1();
  public static Func_notempty_1 t_notempty_1 = new Vx.Core.Class_notempty_1();

  public static Vx.Core.Type_boolean f_notempty_1(Vx.Core.Type_any val) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_is_empty_1(val)
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
  public interface Func_ne : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_ne(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_ne : Vx.Core.Class_base, Func_ne {

    public override Vx.Core.Func_ne vx_new(params Object[] vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    public override Vx.Core.Func_ne vx_copy(params Object[] vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "!=", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ne;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ne;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_ne(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_ne(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_ne(val1, val2);
    }

  }

  public static Func_ne e_ne = new Vx.Core.Class_ne();
  public static Func_ne t_ne = new Vx.Core.Class_ne();

  public static Vx.Core.Type_boolean f_ne(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_eq(val1, val2)
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
  public interface Func_neqeq : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_neqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_neqeq : Vx.Core.Class_base, Func_neqeq {

    public override Vx.Core.Func_neqeq vx_new(params Object[] vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    public override Vx.Core.Func_neqeq vx_copy(params Object[] vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "!==", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_neqeq;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_neqeq;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_neqeq(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_neqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_neqeq(val1, val2);
    }

  }

  public static Func_neqeq e_neqeq = new Vx.Core.Class_neqeq();
  public static Func_neqeq t_neqeq = new Vx.Core.Class_neqeq();

  public static Vx.Core.Type_boolean f_neqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_eqeq(val1, val2)
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
  public interface Func_multiply : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_multiply(Vx.Core.Type_int num1, Vx.Core.Type_int num2);
  }

  public class Class_multiply : Vx.Core.Class_base, Func_multiply {

    public override Vx.Core.Func_multiply vx_new(params Object[] vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    public override Vx.Core.Func_multiply vx_copy(params Object[] vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_multiply;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_multiply;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int num1 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int num2 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_multiply(num1, num2);
      return output;
    }

    public Vx.Core.Type_int vx_multiply(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
      return Vx.Core.f_multiply(num1, num2);
    }

  }

  public static Func_multiply e_multiply = new Vx.Core.Class_multiply();
  public static Func_multiply t_multiply = new Vx.Core.Class_multiply();

  public static Vx.Core.Type_int f_multiply(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
    Vx.Core.Type_int output = Vx.Core.e_int;
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
  public interface Func_multiply_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_number vx_multiply_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2);
  }

  public class Class_multiply_1 : Vx.Core.Class_base, Func_multiply_1 {

    public override Vx.Core.Func_multiply_1 vx_new(params Object[] vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    public override Vx.Core.Func_multiply_1 vx_copy(params Object[] vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_multiply_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_multiply_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_number num1 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_number num2 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_multiply_1(num1, num2);
      return output;
    }

    public Vx.Core.Type_number vx_multiply_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
      return Vx.Core.f_multiply_1(num1, num2);
    }

  }

  public static Func_multiply_1 e_multiply_1 = new Vx.Core.Class_multiply_1();
  public static Func_multiply_1 t_multiply_1 = new Vx.Core.Class_multiply_1();

  public static Vx.Core.Type_number f_multiply_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    return output;
  }

  /**
   * @function multiply 2
   * Math multiply
   * @param  {intlist} nums
   * @return {int}
   * (func *)
   */
  public interface Func_multiply_2 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_multiply_2(Vx.Core.Type_intlist nums);
  }

  public class Class_multiply_2 : Vx.Core.Class_base, Func_multiply_2 {

    public override Vx.Core.Func_multiply_2 vx_new(params Object[] vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    public override Vx.Core.Func_multiply_2 vx_copy(params Object[] vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_multiply_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_multiply_2;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_intlist inputval = (Vx.Core.Type_intlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_multiply_2(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_intlist nums = Vx.Core.f_any_from_any(Vx.Core.t_intlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_multiply_2(nums);
      return output;
    }

    public Vx.Core.Type_int vx_multiply_2(Vx.Core.Type_intlist nums) {
      return Vx.Core.f_multiply_2(nums);
    }

  }

  public static Func_multiply_2 e_multiply_2 = new Vx.Core.Class_multiply_2();
  public static Func_multiply_2 t_multiply_2 = new Vx.Core.Class_multiply_2();

  public static Vx.Core.Type_int f_multiply_2(Vx.Core.Type_intlist nums) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_int,
      nums,
      Vx.Core.vx_new_int(1),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_int total = Vx.Core.f_any_from_any(Vx.Core.t_int, total_any);
        Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_multiply(total, num);
        return output_1;
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
  public interface Func_multiply_3 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_number vx_multiply_3(Vx.Core.Type_numberlist nums);
  }

  public class Class_multiply_3 : Vx.Core.Class_base, Func_multiply_3 {

    public override Vx.Core.Func_multiply_3 vx_new(params Object[] vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    public override Vx.Core.Func_multiply_3 vx_copy(params Object[] vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        3, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_multiply_3;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_multiply_3;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_numberlist inputval = (Vx.Core.Type_numberlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_multiply_3(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_numberlist nums = Vx.Core.f_any_from_any(Vx.Core.t_numberlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_multiply_3(nums);
      return output;
    }

    public Vx.Core.Type_number vx_multiply_3(Vx.Core.Type_numberlist nums) {
      return Vx.Core.f_multiply_3(nums);
    }

  }

  public static Func_multiply_3 e_multiply_3 = new Vx.Core.Class_multiply_3();
  public static Func_multiply_3 t_multiply_3 = new Vx.Core.Class_multiply_3();

  public static Vx.Core.Type_number f_multiply_3(Vx.Core.Type_numberlist nums) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_number,
      nums,
      Vx.Core.vx_new_int(1),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_number total = Vx.Core.f_any_from_any(Vx.Core.t_number, total_any);
        Vx.Core.Type_number num = Vx.Core.f_any_from_any(Vx.Core.t_number, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_multiply_1(total, num);
        return output_1;
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
  public interface Func_plus : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_plus(Vx.Core.Type_int num1, Vx.Core.Type_int num2);
  }

  public class Class_plus : Vx.Core.Class_base, Func_plus {

    public override Vx.Core.Func_plus vx_new(params Object[] vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    public override Vx.Core.Func_plus vx_copy(params Object[] vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_plus;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_plus;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int num1 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int num2 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_plus(num1, num2);
      return output;
    }

    public Vx.Core.Type_int vx_plus(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
      return Vx.Core.f_plus(num1, num2);
    }

  }

  public static Func_plus e_plus = new Vx.Core.Class_plus();
  public static Func_plus t_plus = new Vx.Core.Class_plus();

  public static Vx.Core.Type_int f_plus(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
    Vx.Core.Type_int output = Vx.Core.e_int;
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
  public interface Func_plus_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_number vx_plus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2);
  }

  public class Class_plus_1 : Vx.Core.Class_base, Func_plus_1 {

    public override Vx.Core.Func_plus_1 vx_new(params Object[] vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    public override Vx.Core.Func_plus_1 vx_copy(params Object[] vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_plus_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_plus_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_number num1 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_number num2 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_plus_1(num1, num2);
      return output;
    }

    public Vx.Core.Type_number vx_plus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
      return Vx.Core.f_plus_1(num1, num2);
    }

  }

  public static Func_plus_1 e_plus_1 = new Vx.Core.Class_plus_1();
  public static Func_plus_1 t_plus_1 = new Vx.Core.Class_plus_1();

  public static Vx.Core.Type_number f_plus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    return output;
  }

  /**
   * @function plus 2
   * Math int plus
   * @param  {intlist} nums
   * @return {int}
   * (func +)
   */
  public interface Func_plus_2 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_plus_2(Vx.Core.Type_intlist nums);
  }

  public class Class_plus_2 : Vx.Core.Class_base, Func_plus_2 {

    public override Vx.Core.Func_plus_2 vx_new(params Object[] vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    public override Vx.Core.Func_plus_2 vx_copy(params Object[] vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_plus_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_plus_2;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_intlist inputval = (Vx.Core.Type_intlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_plus_2(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_intlist nums = Vx.Core.f_any_from_any(Vx.Core.t_intlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_plus_2(nums);
      return output;
    }

    public Vx.Core.Type_int vx_plus_2(Vx.Core.Type_intlist nums) {
      return Vx.Core.f_plus_2(nums);
    }

  }

  public static Func_plus_2 e_plus_2 = new Vx.Core.Class_plus_2();
  public static Func_plus_2 t_plus_2 = new Vx.Core.Class_plus_2();

  public static Vx.Core.Type_int f_plus_2(Vx.Core.Type_intlist nums) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_int,
      nums,
      Vx.Core.vx_new_int(0),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_int total = Vx.Core.f_any_from_any(Vx.Core.t_int, total_any);
        Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_plus(total, num);
        return output_1;
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
  public interface Func_plus_3 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_number vx_plus_3(Vx.Core.Type_numberlist nums);
  }

  public class Class_plus_3 : Vx.Core.Class_base, Func_plus_3 {

    public override Vx.Core.Func_plus_3 vx_new(params Object[] vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    public override Vx.Core.Func_plus_3 vx_copy(params Object[] vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        3, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_plus_3;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_plus_3;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_numberlist inputval = (Vx.Core.Type_numberlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_plus_3(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_numberlist nums = Vx.Core.f_any_from_any(Vx.Core.t_numberlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_plus_3(nums);
      return output;
    }

    public Vx.Core.Type_number vx_plus_3(Vx.Core.Type_numberlist nums) {
      return Vx.Core.f_plus_3(nums);
    }

  }

  public static Func_plus_3 e_plus_3 = new Vx.Core.Class_plus_3();
  public static Func_plus_3 t_plus_3 = new Vx.Core.Class_plus_3();

  public static Vx.Core.Type_number f_plus_3(Vx.Core.Type_numberlist nums) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_number,
      nums,
      Vx.Core.vx_new_int(0),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_number total = Vx.Core.f_any_from_any(Vx.Core.t_number, total_any);
        Vx.Core.Type_number num = Vx.Core.f_any_from_any(Vx.Core.t_number, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_plus_1(total, num);
        return output_1;
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
  public interface Func_plus1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_plus1(Vx.Core.Type_int num);
  }

  public class Class_plus1 : Vx.Core.Class_base, Func_plus1 {

    public override Vx.Core.Func_plus1 vx_new(params Object[] vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    public override Vx.Core.Func_plus1 vx_copy(params Object[] vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "+1", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_plus1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_plus1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Core.f_plus1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_plus1(num);
      return output;
    }

    public Vx.Core.Type_int vx_plus1(Vx.Core.Type_int num) {
      return Vx.Core.f_plus1(num);
    }

  }

  public static Func_plus1 e_plus1 = new Vx.Core.Class_plus1();
  public static Func_plus1 t_plus1 = new Vx.Core.Class_plus1();

  public static Vx.Core.Type_int f_plus1(Vx.Core.Type_int num) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_plus(num, Vx.Core.vx_new_int(1));
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
  public interface Func_minus : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_minus(Vx.Core.Type_int num1, Vx.Core.Type_int num2);
  }

  public class Class_minus : Vx.Core.Class_base, Func_minus {

    public override Vx.Core.Func_minus vx_new(params Object[] vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    public override Vx.Core.Func_minus vx_copy(params Object[] vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_minus;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_minus;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int num1 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int num2 = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_minus(num1, num2);
      return output;
    }

    public Vx.Core.Type_int vx_minus(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
      return Vx.Core.f_minus(num1, num2);
    }

  }

  public static Func_minus e_minus = new Vx.Core.Class_minus();
  public static Func_minus t_minus = new Vx.Core.Class_minus();

  public static Vx.Core.Type_int f_minus(Vx.Core.Type_int num1, Vx.Core.Type_int num2) {
    Vx.Core.Type_int output = Vx.Core.e_int;
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
  public interface Func_minus_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_number vx_minus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2);
  }

  public class Class_minus_1 : Vx.Core.Class_base, Func_minus_1 {

    public override Vx.Core.Func_minus_1 vx_new(params Object[] vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    public override Vx.Core.Func_minus_1 vx_copy(params Object[] vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_minus_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_minus_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_number num1 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_number num2 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_minus_1(num1, num2);
      return output;
    }

    public Vx.Core.Type_number vx_minus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
      return Vx.Core.f_minus_1(num1, num2);
    }

  }

  public static Func_minus_1 e_minus_1 = new Vx.Core.Class_minus_1();
  public static Func_minus_1 t_minus_1 = new Vx.Core.Class_minus_1();

  public static Vx.Core.Type_number f_minus_1(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    return output;
  }

  /**
   * @function minus 2
   * Math integer minus
   * @param  {intlist} nums
   * @return {int}
   * (func -)
   */
  public interface Func_minus_2 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_minus_2(Vx.Core.Type_intlist nums);
  }

  public class Class_minus_2 : Vx.Core.Class_base, Func_minus_2 {

    public override Vx.Core.Func_minus_2 vx_new(params Object[] vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    public override Vx.Core.Func_minus_2 vx_copy(params Object[] vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_minus_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_minus_2;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_intlist inputval = (Vx.Core.Type_intlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_minus_2(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_intlist nums = Vx.Core.f_any_from_any(Vx.Core.t_intlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_minus_2(nums);
      return output;
    }

    public Vx.Core.Type_int vx_minus_2(Vx.Core.Type_intlist nums) {
      return Vx.Core.f_minus_2(nums);
    }

  }

  public static Func_minus_2 e_minus_2 = new Vx.Core.Class_minus_2();
  public static Func_minus_2 t_minus_2 = new Vx.Core.Class_minus_2();

  public static Vx.Core.Type_int f_minus_2(Vx.Core.Type_intlist nums) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_int,
      nums,
      Vx.Core.vx_new_int(0),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_int total = Vx.Core.f_any_from_any(Vx.Core.t_int, total_any);
        Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_minus(total, num);
        return output_1;
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
  public interface Func_minus_3 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_number vx_minus_3(Vx.Core.Type_numberlist nums);
  }

  public class Class_minus_3 : Vx.Core.Class_base, Func_minus_3 {

    public override Vx.Core.Func_minus_3 vx_new(params Object[] vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    public override Vx.Core.Func_minus_3 vx_copy(params Object[] vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        3, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_minus_3;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_minus_3;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_numberlist inputval = (Vx.Core.Type_numberlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_minus_3(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_numberlist nums = Vx.Core.f_any_from_any(Vx.Core.t_numberlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_minus_3(nums);
      return output;
    }

    public Vx.Core.Type_number vx_minus_3(Vx.Core.Type_numberlist nums) {
      return Vx.Core.f_minus_3(nums);
    }

  }

  public static Func_minus_3 e_minus_3 = new Vx.Core.Class_minus_3();
  public static Func_minus_3 t_minus_3 = new Vx.Core.Class_minus_3();

  public static Vx.Core.Type_number f_minus_3(Vx.Core.Type_numberlist nums) {
    Vx.Core.Type_number output = Vx.Core.e_number;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_number,
      nums,
      Vx.Core.vx_new_int(0),
      Vx.Core.t_any_from_reduce.vx_fn_new((total_any, num_any) => {
        Vx.Core.Type_number total = Vx.Core.f_any_from_any(Vx.Core.t_number, total_any);
        Vx.Core.Type_number num = Vx.Core.f_any_from_any(Vx.Core.t_number, num_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_minus_1(total, num);
        return output_1;
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
  public interface Func_minus1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_minus1(Vx.Core.Type_int num);
  }

  public class Class_minus1 : Vx.Core.Class_base, Func_minus1 {

    public override Vx.Core.Func_minus1 vx_new(params Object[] vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    public override Vx.Core.Func_minus1 vx_copy(params Object[] vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "-1", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_minus1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_minus1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Core.f_minus1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_minus1(num);
      return output;
    }

    public Vx.Core.Type_int vx_minus1(Vx.Core.Type_int num) {
      return Vx.Core.f_minus1(num);
    }

  }

  public static Func_minus1 e_minus1 = new Vx.Core.Class_minus1();
  public static Func_minus1 t_minus1 = new Vx.Core.Class_minus1();

  public static Vx.Core.Type_int f_minus1(Vx.Core.Type_int num) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_minus(num, Vx.Core.vx_new_int(1));
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
  public interface Func_dotmethod : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_any vx_dotmethod(Vx.Core.Type_any target, Vx.Core.Type_string method, Vx.Core.Type_anylist parameters);
  }

  public class Class_dotmethod : Vx.Core.Class_base, Func_dotmethod {

    public override Vx.Core.Func_dotmethod vx_new(params Object[] vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    public override Vx.Core.Func_dotmethod vx_copy(params Object[] vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        ".", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dotmethod;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_dotmethod;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any target = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string method = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_anylist parameters = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_dotmethod(target, method, parameters);
      return output;
    }

    public Vx.Core.Type_any vx_dotmethod(Vx.Core.Type_any target, Vx.Core.Type_string method, Vx.Core.Type_anylist parameters) {
      return Vx.Core.f_dotmethod(target, method, parameters);
    }

  }

  public static Func_dotmethod e_dotmethod = new Vx.Core.Class_dotmethod();
  public static Func_dotmethod t_dotmethod = new Vx.Core.Class_dotmethod();

  public static Vx.Core.Type_any f_dotmethod(Vx.Core.Type_any target, Vx.Core.Type_string method, Vx.Core.Type_anylist parameters) {
    Vx.Core.Type_any output = Vx.Core.e_any;
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
  public interface Func_divide : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_number vx_divide(Vx.Core.Type_number num1, Vx.Core.Type_number num2);
  }

  public class Class_divide : Vx.Core.Class_base, Func_divide {

    public override Vx.Core.Func_divide vx_new(params Object[] vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    public override Vx.Core.Func_divide vx_copy(params Object[] vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "/", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_divide;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divide;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_number num1 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_number num2 = Vx.Core.f_any_from_any(Vx.Core.t_number, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_divide(num1, num2);
      return output;
    }

    public Vx.Core.Type_number vx_divide(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
      return Vx.Core.f_divide(num1, num2);
    }

  }

  public static Func_divide e_divide = new Vx.Core.Class_divide();
  public static Func_divide t_divide = new Vx.Core.Class_divide();

  public static Vx.Core.Type_number f_divide(Vx.Core.Type_number num1, Vx.Core.Type_number num2) {
    Vx.Core.Type_number output = Vx.Core.e_number;
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
  public interface Func_lt : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_lt(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_lt : Vx.Core.Class_base, Func_lt {

    public override Vx.Core.Func_lt vx_new(params Object[] vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    public override Vx.Core.Func_lt vx_copy(params Object[] vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_lt;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_lt;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_lt(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_lt(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_lt(val1, val2);
    }

  }

  public static Func_lt e_lt = new Vx.Core.Class_lt();
  public static Func_lt t_lt = new Vx.Core.Class_lt();

  public static Vx.Core.Type_boolean f_lt(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_switch(
      Vx.Core.t_boolean,
      Vx.Core.f_compare(val1, val2),
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Core.vx_new_int(-1),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(true);
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(false);
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
  public interface Func_lt_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_lt_1(Vx.Core.Type_anylist values);
  }

  public class Class_lt_1 : Vx.Core.Class_base, Func_lt_1 {

    public override Vx.Core.Func_lt_1 vx_new(params Object[] vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    public override Vx.Core.Func_lt_1 vx_copy(params Object[] vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_lt_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_lt_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_lt_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist values = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_lt_1(values);
      return output;
    }

    public Vx.Core.Type_boolean vx_lt_1(Vx.Core.Type_anylist values) {
      return Vx.Core.f_lt_1(values);
    }

  }

  public static Func_lt_1 e_lt_1 = new Vx.Core.Class_lt_1();
  public static Func_lt_1 t_lt_1 = new Vx.Core.Class_lt_1();

  public static Vx.Core.Type_boolean f_lt_1(Vx.Core.Type_anylist values) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_any_from_list_start_reduce_next(
      Vx.Core.t_boolean,
      values,
      Vx.Core.vx_new_boolean(true),
      Vx.Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        Vx.Core.Type_boolean reduce = Vx.Core.f_any_from_any(Vx.Core.t_boolean, reduce_any);
        Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, current_any);
        Vx.Core.Type_any next = Vx.Core.f_any_from_any(Vx.Core.t_any, next_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_and(
            reduce,
            Vx.Core.f_lt(current, next)
          );
        return output_1;
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
  public interface Func_chainfirst : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_chainfirst<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any;
  }

  public class Class_chainfirst : Vx.Core.Class_base, Func_chainfirst {

    public override Vx.Core.Func_chainfirst vx_new(params Object[] vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    public override Vx.Core.Func_chainfirst vx_copy(params Object[] vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<-", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_chainfirst;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_chainfirst;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any_from_anylist fnlist = Vx.Core.f_any_from_any(Vx.Core.t_any_from_anylist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_chainfirst(generic_any_1, value, fnlist);
      return output;
    }

    public T vx_chainfirst<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any {
      return Vx.Core.f_chainfirst(generic_any_1, value, fnlist);
    }

  }

  public static Func_chainfirst e_chainfirst = new Vx.Core.Class_chainfirst();
  public static Func_chainfirst t_chainfirst = new Vx.Core.Class_chainfirst();

  public static T f_chainfirst<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_chainlast : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_chainlast<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any;
  }

  public class Class_chainlast : Vx.Core.Class_base, Func_chainlast {

    public override Vx.Core.Func_chainlast vx_new(params Object[] vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    public override Vx.Core.Func_chainlast vx_copy(params Object[] vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<<-", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_chainlast;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_chainlast;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any_from_anylist fnlist = Vx.Core.f_any_from_any(Vx.Core.t_any_from_anylist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_chainlast(generic_any_1, value, fnlist);
      return output;
    }

    public T vx_chainlast<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any {
      return Vx.Core.f_chainlast(generic_any_1, value, fnlist);
    }

  }

  public static Func_chainlast e_chainlast = new Vx.Core.Class_chainlast();
  public static Func_chainlast t_chainlast = new Vx.Core.Class_chainlast();

  public static T f_chainlast<T>(T generic_any_1, T value, Vx.Core.Type_any_from_anylist fnlist) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_le : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_le(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_le : Vx.Core.Class_base, Func_le {

    public override Vx.Core.Func_le vx_new(params Object[] vals) {
      Class_le output = new Class_le();
      return output;
    }

    public override Vx.Core.Func_le vx_copy(params Object[] vals) {
      Class_le output = new Class_le();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_le;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_le;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_le(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_le(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_le(val1, val2);
    }

  }

  public static Func_le e_le = new Vx.Core.Class_le();
  public static Func_le t_le = new Vx.Core.Class_le();

  public static Vx.Core.Type_boolean f_le(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_gt(val1, val2)
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
  public interface Func_le_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_le_1(Vx.Core.Type_anylist args);
  }

  public class Class_le_1 : Vx.Core.Class_base, Func_le_1 {

    public override Vx.Core.Func_le_1 vx_new(params Object[] vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    public override Vx.Core.Func_le_1 vx_copy(params Object[] vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_le_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_le_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_le_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_le_1(args);
      return output;
    }

    public Vx.Core.Type_boolean vx_le_1(Vx.Core.Type_anylist args) {
      return Vx.Core.f_le_1(args);
    }

  }

  public static Func_le_1 e_le_1 = new Vx.Core.Class_le_1();
  public static Func_le_1 t_le_1 = new Vx.Core.Class_le_1();

  public static Vx.Core.Type_boolean f_le_1(Vx.Core.Type_anylist args) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_gt_1(args)
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
  public interface Func_eq : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_eq(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_eq : Vx.Core.Class_base, Func_eq {

    public override Vx.Core.Func_eq vx_new(params Object[] vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    public override Vx.Core.Func_eq vx_copy(params Object[] vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_eq;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_eq;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_eq(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_eq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_eq(val1, val2);
    }

  }

  public static Func_eq e_eq = new Vx.Core.Class_eq();
  public static Func_eq t_eq = new Vx.Core.Class_eq();

  public static Vx.Core.Type_boolean f_eq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function eq 1
   * Boolean equal/equivalent
   * @param  {anylist} values
   * @return {boolean}
   * (func =)
   */
  public interface Func_eq_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_eq_1(Vx.Core.Type_anylist values);
  }

  public class Class_eq_1 : Vx.Core.Class_base, Func_eq_1 {

    public override Vx.Core.Func_eq_1 vx_new(params Object[] vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    public override Vx.Core.Func_eq_1 vx_copy(params Object[] vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_eq_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_eq_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_eq_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist values = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_eq_1(values);
      return output;
    }

    public Vx.Core.Type_boolean vx_eq_1(Vx.Core.Type_anylist values) {
      return Vx.Core.f_eq_1(values);
    }

  }

  public static Func_eq_1 e_eq_1 = new Vx.Core.Class_eq_1();
  public static Func_eq_1 t_eq_1 = new Vx.Core.Class_eq_1();

  public static Vx.Core.Type_boolean f_eq_1(Vx.Core.Type_anylist values) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_any_from_list_start_reduce_next(
      Vx.Core.t_boolean,
      values,
      Vx.Core.vx_new_boolean(false),
      Vx.Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        Vx.Core.Type_boolean reduce = Vx.Core.f_any_from_any(Vx.Core.t_boolean, reduce_any);
        Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, current_any);
        Vx.Core.Type_any next = Vx.Core.f_any_from_any(Vx.Core.t_any, next_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_and(
            reduce,
            Vx.Core.f_eq(current, next)
          );
        return output_1;
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
  public interface Func_eqeq : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_eqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_eqeq : Vx.Core.Class_base, Func_eqeq {

    public override Vx.Core.Func_eqeq vx_new(params Object[] vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    public override Vx.Core.Func_eqeq vx_copy(params Object[] vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "==", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_eqeq;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_eqeq;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_eqeq(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_eqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_eqeq(val1, val2);
    }

  }

  public static Func_eqeq e_eqeq = new Vx.Core.Class_eqeq();
  public static Func_eqeq t_eqeq = new Vx.Core.Class_eqeq();

  public static Vx.Core.Type_boolean f_eqeq(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
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
  public interface Func_gt : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_gt(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_gt : Vx.Core.Class_base, Func_gt {

    public override Vx.Core.Func_gt vx_new(params Object[] vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    public override Vx.Core.Func_gt vx_copy(params Object[] vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_gt;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_gt;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_gt(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_gt(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_gt(val1, val2);
    }

  }

  public static Func_gt e_gt = new Vx.Core.Class_gt();
  public static Func_gt t_gt = new Vx.Core.Class_gt();

  public static Vx.Core.Type_boolean f_gt(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_switch(
      Vx.Core.t_boolean,
      Vx.Core.f_compare(val1, val2),
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Core.vx_new_int(1),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(true);
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(false);
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
  public interface Func_gt_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_gt_1(Vx.Core.Type_anylist values);
  }

  public class Class_gt_1 : Vx.Core.Class_base, Func_gt_1 {

    public override Vx.Core.Func_gt_1 vx_new(params Object[] vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    public override Vx.Core.Func_gt_1 vx_copy(params Object[] vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_gt_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_gt_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_gt_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist values = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_gt_1(values);
      return output;
    }

    public Vx.Core.Type_boolean vx_gt_1(Vx.Core.Type_anylist values) {
      return Vx.Core.f_gt_1(values);
    }

  }

  public static Func_gt_1 e_gt_1 = new Vx.Core.Class_gt_1();
  public static Func_gt_1 t_gt_1 = new Vx.Core.Class_gt_1();

  public static Vx.Core.Type_boolean f_gt_1(Vx.Core.Type_anylist values) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_any_from_list_start_reduce_next(
      Vx.Core.t_boolean,
      values,
      Vx.Core.vx_new_boolean(true),
      Vx.Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        Vx.Core.Type_boolean reduce = Vx.Core.f_any_from_any(Vx.Core.t_boolean, reduce_any);
        Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, current_any);
        Vx.Core.Type_any next = Vx.Core.f_any_from_any(Vx.Core.t_any, next_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_and(
            reduce,
            Vx.Core.f_gt(current, next)
          );
        return output_1;
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
  public interface Func_ge : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_ge(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_ge : Vx.Core.Class_base, Func_ge {

    public override Vx.Core.Func_ge vx_new(params Object[] vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    public override Vx.Core.Func_ge vx_copy(params Object[] vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ge;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ge;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_ge(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_ge(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_ge(val1, val2);
    }

  }

  public static Func_ge e_ge = new Vx.Core.Class_ge();
  public static Func_ge t_ge = new Vx.Core.Class_ge();

  public static Vx.Core.Type_boolean f_ge(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_lt(val1, val2)
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
  public interface Func_ge_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_ge_1(Vx.Core.Type_anylist args);
  }

  public class Class_ge_1 : Vx.Core.Class_base, Func_ge_1 {

    public override Vx.Core.Func_ge_1 vx_new(params Object[] vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    public override Vx.Core.Func_ge_1 vx_copy(params Object[] vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ge_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ge_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_ge_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_ge_1(args);
      return output;
    }

    public Vx.Core.Type_boolean vx_ge_1(Vx.Core.Type_anylist args) {
      return Vx.Core.f_ge_1(args);
    }

  }

  public static Func_ge_1 e_ge_1 = new Vx.Core.Class_ge_1();
  public static Func_ge_1 t_ge_1 = new Vx.Core.Class_ge_1();

  public static Vx.Core.Type_boolean f_ge_1(Vx.Core.Type_anylist args) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_not(
      Vx.Core.f_lt_1(args)
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
  public interface Func_allowfuncs_from_security : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_funclist vx_allowfuncs_from_security(Vx.Core.Type_security security);
  }

  public class Class_allowfuncs_from_security : Vx.Core.Class_base, Func_allowfuncs_from_security {

    public override Vx.Core.Func_allowfuncs_from_security vx_new(params Object[] vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    public override Vx.Core.Func_allowfuncs_from_security vx_copy(params Object[] vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "allowfuncs<-security", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "funclist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_func), // allowtypes
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
      return e_allowfuncs_from_security;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_allowfuncs_from_security;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_security inputval = (Vx.Core.Type_security)value;
      Vx.Core.Type_any outputval = Vx.Core.f_allowfuncs_from_security(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_security security = Vx.Core.f_any_from_any(Vx.Core.t_security, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_allowfuncs_from_security(security);
      return output;
    }

    public Vx.Core.Type_funclist vx_allowfuncs_from_security(Vx.Core.Type_security security) {
      return Vx.Core.f_allowfuncs_from_security(security);
    }

  }

  public static Func_allowfuncs_from_security e_allowfuncs_from_security = new Vx.Core.Class_allowfuncs_from_security();
  public static Func_allowfuncs_from_security t_allowfuncs_from_security = new Vx.Core.Class_allowfuncs_from_security();

  public static Vx.Core.Type_funclist f_allowfuncs_from_security(Vx.Core.Type_security security) {
    Vx.Core.Type_funclist output = Vx.Core.e_funclist;
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
  public interface Func_allowtypenames_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_allowtypenames_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_allowtypenames_from_typedef : Vx.Core.Class_base, Func_allowtypenames_from_typedef {

    public override Vx.Core.Func_allowtypenames_from_typedef vx_new(params Object[] vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    public override Vx.Core.Func_allowtypenames_from_typedef vx_copy(params Object[] vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "allowtypenames<-typedef", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_allowtypenames_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_allowtypenames_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_allowtypenames_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_allowtypenames_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_stringlist vx_allowtypenames_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_allowtypenames_from_typedef(vtypedef);
    }

  }

  public static Func_allowtypenames_from_typedef e_allowtypenames_from_typedef = new Vx.Core.Class_allowtypenames_from_typedef();
  public static Func_allowtypenames_from_typedef t_allowtypenames_from_typedef = new Vx.Core.Class_allowtypenames_from_typedef();

  public static Vx.Core.Type_stringlist f_allowtypenames_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_typenames_from_typelist(
      Vx.Core.f_allowtypes_from_typedef(vtypedef)
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
  public interface Func_allowtypes_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typelist vx_allowtypes_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_allowtypes_from_typedef : Vx.Core.Class_base, Func_allowtypes_from_typedef {

    public override Vx.Core.Func_allowtypes_from_typedef vx_new(params Object[] vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    public override Vx.Core.Func_allowtypes_from_typedef vx_copy(params Object[] vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "allowtypes<-typedef", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_allowtypes_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_allowtypes_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_allowtypes_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_allowtypes_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_typelist vx_allowtypes_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_allowtypes_from_typedef(vtypedef);
    }

  }

  public static Func_allowtypes_from_typedef e_allowtypes_from_typedef = new Vx.Core.Class_allowtypes_from_typedef();
  public static Func_allowtypes_from_typedef t_allowtypes_from_typedef = new Vx.Core.Class_allowtypes_from_typedef();

  public static Vx.Core.Type_typelist f_allowtypes_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_typelist output = Vx.Core.e_typelist;
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
  public interface Func_and : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_and(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2);
  }

  public class Class_and : Vx.Core.Class_base, Func_and {

    public override Vx.Core.Func_and vx_new(params Object[] vals) {
      Class_and output = new Class_and();
      return output;
    }

    public override Vx.Core.Func_and vx_copy(params Object[] vals) {
      Class_and output = new Class_and();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_and;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_and;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_boolean val1 = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_boolean val2 = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_and(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_and(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2) {
      return Vx.Core.f_and(val1, val2);
    }

  }

  public static Func_and e_and = new Vx.Core.Class_and();
  public static Func_and t_and = new Vx.Core.Class_and();

  public static Vx.Core.Type_boolean f_and(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function and 1
   * Returns true if all values are true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func and)
   */
  public interface Func_and_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_and_1(Vx.Core.Type_booleanlist values);
  }

  public class Class_and_1 : Vx.Core.Class_base, Func_and_1 {

    public override Vx.Core.Func_and_1 vx_new(params Object[] vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    public override Vx.Core.Func_and_1 vx_copy(params Object[] vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_and_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_and_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_booleanlist inputval = (Vx.Core.Type_booleanlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_and_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_booleanlist values = Vx.Core.f_any_from_any(Vx.Core.t_booleanlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_and_1(values);
      return output;
    }

    public Vx.Core.Type_boolean vx_and_1(Vx.Core.Type_booleanlist values) {
      return Vx.Core.f_and_1(values);
    }

  }

  public static Func_and_1 e_and_1 = new Vx.Core.Class_and_1();
  public static Func_and_1 t_and_1 = new Vx.Core.Class_and_1();

  public static Vx.Core.Type_boolean f_and_1(Vx.Core.Type_booleanlist values) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_switch(
      Vx.Core.t_boolean,
      Vx.Core.f_length_1(values),
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Core.vx_new_int(0),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(true);
          })
        ),
        Vx.Core.f_case_1(
          Vx.Core.vx_new_int(1),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_any_from_list(Vx.Core.t_boolean, values, Vx.Core.vx_new_int(1));
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_any_from_list_start_reduce_next(
              Vx.Core.t_boolean,
              values,
              Vx.Core.vx_new_boolean(true),
              Vx.Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
                Vx.Core.Type_boolean reduce = Vx.Core.f_any_from_any(Vx.Core.t_boolean, reduce_any);
                Vx.Core.Type_boolean current = Vx.Core.f_any_from_any(Vx.Core.t_boolean, current_any);
                Vx.Core.Type_boolean next = Vx.Core.f_any_from_any(Vx.Core.t_boolean, next_any);
                Vx.Core.Type_any output_1 = 
                    Vx.Core.f_and(
                      reduce,
                      Vx.Core.f_and(current, next)
                    );
                return output_1;
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
  public interface Func_any_from_any : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn);
    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_any : Vx.Core.Class_base, Func_any_from_any {

    public override Vx.Core.Func_any_from_any vx_new(params Object[] vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    public override Vx.Core.Func_any_from_any vx_copy(params Object[] vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_any;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      Class_any_from_any output = new Class_any_from_any();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_any_from_any(generic_any_1, value);
      return output;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(value);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any e_any_from_any = new Vx.Core.Class_any_from_any();
  public static Func_any_from_any t_any_from_any = new Vx.Core.Class_any_from_any();

  public static T f_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_any_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn);
    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_any_async : Vx.Core.Class_base, Func_any_from_any_async {

    public override Vx.Core.Func_any_from_any_async vx_new(params Object[] vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    public override Vx.Core.Func_any_from_any_async vx_copy(params Object[] vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_any_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_any_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn(Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_any_async(generic_any_1, value);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn(value);
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_any_async e_any_from_any_async = new Vx.Core.Class_any_from_any_async();
  public static Func_any_from_any_async t_any_from_any_async = new Vx.Core.Class_any_from_any_async();

  public static Task<T> f_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_any_context
   * Function Type taking any value any-2 and returning generic any-1 using context
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context)
   */
  public interface Func_any_from_any_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn);
    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_any_context : Vx.Core.Class_base, Func_any_from_any_context {

    public override Vx.Core.Func_any_from_any_context vx_new(params Object[] vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    public override Vx.Core.Func_any_from_any_context vx_copy(params Object[] vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_any_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_any_context;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_context context, Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, value);
      return output;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(context, value);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any_context e_any_from_any_context = new Vx.Core.Class_any_from_any_context();
  public static Func_any_from_any_context t_any_from_any_context = new Vx.Core.Class_any_from_any_context();

  public static T f_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_any_context_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_any_context_async vx_fn_new(Vx.Core.Class_any_from_any_context_async.IFn fn);
    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_any_context_async : Vx.Core.Class_base, Func_any_from_any_context_async {

    public override Vx.Core.Func_any_from_any_context_async vx_new(params Object[] vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    public override Vx.Core.Func_any_from_any_context_async vx_copy(params Object[] vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_any_context_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_any_context_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn(Vx.Core.Type_context context, Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_any_context_async vx_fn_new(Vx.Core.Class_any_from_any_context_async.IFn fn) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_any_context_async(generic_any_1, context, value);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn(context, value);
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_any_context_async e_any_from_any_context_async = new Vx.Core.Class_any_from_any_context_async();
  public static Func_any_from_any_context_async t_any_from_any_context_async = new Vx.Core.Class_any_from_any_context_async();

  public static Task<T> f_any_from_any_context_async<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
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
  public interface Func_any_from_any_key_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_any_key_value vx_fn_new(Vx.Core.Class_any_from_any_key_value.IFn fn);
    public T vx_any_from_any_key_value<T, U>(T generic_any_1, T current, Vx.Core.Type_string key, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_any_key_value : Vx.Core.Class_base, Func_any_from_any_key_value {

    public override Vx.Core.Func_any_from_any_key_value vx_new(params Object[] vals) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      return output;
    }

    public override Vx.Core.Func_any_from_any_key_value vx_copy(params Object[] vals) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-key-value", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_any_key_value;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_any_key_value;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_any current, Vx.Core.Type_string key, Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_any_key_value vx_fn_new(Vx.Core.Class_any_from_any_key_value.IFn fn) {
      Class_any_from_any_key_value output = new Class_any_from_any_key_value();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_any_from_any_key_value(generic_any_1, current, key, value);
      return output;
    }

    public T vx_any_from_any_key_value<T, U>(T generic_any_1, T current, Vx.Core.Type_string key, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(current, key, value);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_any_key_value e_any_from_any_key_value = new Vx.Core.Class_any_from_any_key_value();
  public static Func_any_from_any_key_value t_any_from_any_key_value = new Vx.Core.Class_any_from_any_key_value();

  public static T f_any_from_any_key_value<T, U>(T generic_any_1, T current, Vx.Core.Type_string key, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_func
   * Generic Function returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func)
   */
  public interface Func_any_from_func : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn fn);
    public T vx_any_from_func<T>(T generic_any_1) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_func : Vx.Core.Class_base, Func_any_from_func {

    public override Vx.Core.Func_any_from_func vx_new(params Object[] vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    public override Vx.Core.Func_any_from_func vx_copy(params Object[] vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-func", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_func;
    }

    public delegate Vx.Core.Type_any IFn();

    public IFn? fn = null;

    public Vx.Core.Func_any_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn fn) {
      Class_any_from_func output = new Class_any_from_func();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_any_from_func(generic_any_1);
      return output;
    }

    public T vx_any_from_func<T>(T generic_any_1) where T : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn();
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_func e_any_from_func = new Vx.Core.Class_any_from_func();
  public static Func_any_from_func t_any_from_func = new Vx.Core.Class_any_from_func();

  public static T f_any_from_func<T>(T generic_any_1) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_func_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_func_async vx_fn_new(Vx.Core.Class_any_from_func_async.IFn fn);
    public Task<T> vx_any_from_func_async<T>(T generic_any_1) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_func_async : Vx.Core.Class_base, Func_any_from_func_async {

    public override Vx.Core.Func_any_from_func_async vx_new(params Object[] vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    public override Vx.Core.Func_any_from_func_async vx_copy(params Object[] vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-func-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_func_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_func_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn();

    public IFn? fn = null;

    public Vx.Core.Func_any_from_func_async vx_fn_new(Vx.Core.Class_any_from_func_async.IFn fn) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_func_async(generic_any_1);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_func_async<T>(T generic_any_1) where T : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn();
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_func_async e_any_from_func_async = new Vx.Core.Class_any_from_func_async();
  public static Func_any_from_func_async t_any_from_func_async = new Vx.Core.Class_any_from_func_async();

  public static Task<T> f_any_from_func_async<T>(T generic_any_1) where T : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_int
   * Generic Function returning Generic any-1 from an int
   * @param  {int} value
   * @return {any-1}
   * (func any<-int)
   */
  public interface Func_any_from_int : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_int vx_fn_new(Vx.Core.Class_any_from_int.IFn fn);
    public T vx_any_from_int<T>(T generic_any_1, Vx.Core.Type_int value) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_int : Vx.Core.Class_base, Func_any_from_int {

    public override Vx.Core.Func_any_from_int vx_new(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    public override Vx.Core.Func_any_from_int vx_copy(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-int", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_int;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_int;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_int value);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_int vx_fn_new(Vx.Core.Class_any_from_int.IFn fn) {
      Class_any_from_int output = new Class_any_from_int();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int value = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_any_from_int(generic_any_1, value);
      return output;
    }

    public T vx_any_from_int<T>(T generic_any_1, Vx.Core.Type_int value) where T : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(value);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_int e_any_from_int = new Vx.Core.Class_any_from_int();
  public static Func_any_from_int t_any_from_int = new Vx.Core.Class_any_from_int();

  public static T f_any_from_int<T>(T generic_any_1, Vx.Core.Type_int value) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_int_any : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_int_any vx_fn_new(Vx.Core.Class_any_from_int_any.IFn fn);
    public T vx_any_from_int_any<T, U>(T generic_any_1, Vx.Core.Type_int num, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_int_any : Vx.Core.Class_base, Func_any_from_int_any {

    public override Vx.Core.Func_any_from_int_any vx_new(params Object[] vals) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      return output;
    }

    public override Vx.Core.Func_any_from_int_any vx_copy(params Object[] vals) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-int-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_int_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_int_any;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_int num, Vx.Core.Type_any val);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_int_any vx_fn_new(Vx.Core.Class_any_from_int_any.IFn fn) {
      Class_any_from_int_any output = new Class_any_from_int_any();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int num = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_int_any(generic_any_1, num, val);
      return output;
    }

    public T vx_any_from_int_any<T, U>(T generic_any_1, Vx.Core.Type_int num, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(num, val);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_int_any e_any_from_int_any = new Vx.Core.Class_any_from_int_any();
  public static Func_any_from_int_any t_any_from_int_any = new Vx.Core.Class_any_from_int_any();

  public static T f_any_from_int_any<T, U>(T generic_any_1, Vx.Core.Type_int num, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_key_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_key_value vx_fn_new(Vx.Core.Class_any_from_key_value.IFn fn);
    public T vx_any_from_key_value<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_key_value : Vx.Core.Class_base, Func_any_from_key_value {

    public override Vx.Core.Func_any_from_key_value vx_new(params Object[] vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    public override Vx.Core.Func_any_from_key_value vx_copy(params Object[] vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_key_value;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_key_value;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_string key, Vx.Core.Type_any val);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_key_value vx_fn_new(Vx.Core.Class_any_from_key_value.IFn fn) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_key_value(generic_any_1, key, val);
      return output;
    }

    public T vx_any_from_key_value<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(key, val);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_key_value e_any_from_key_value = new Vx.Core.Class_any_from_key_value();
  public static Func_any_from_key_value t_any_from_key_value = new Vx.Core.Class_any_from_key_value();

  public static T f_any_from_key_value<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_key_value_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_key_value_async vx_fn_new(Vx.Core.Class_any_from_key_value_async.IFn fn);
    public Task<T> vx_any_from_key_value_async<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_key_value_async : Vx.Core.Class_base, Func_any_from_key_value_async {

    public override Vx.Core.Func_any_from_key_value_async vx_new(params Object[] vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    public override Vx.Core.Func_any_from_key_value_async vx_copy(params Object[] vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_key_value_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_key_value_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn(Vx.Core.Type_string key, Vx.Core.Type_any val);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_key_value_async vx_fn_new(Vx.Core.Class_any_from_key_value_async.IFn fn) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_key_value_async(generic_any_1, key, val);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_key_value_async<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn(key, val);
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_key_value_async e_any_from_key_value_async = new Vx.Core.Class_any_from_key_value_async();
  public static Func_any_from_key_value_async t_any_from_key_value_async = new Vx.Core.Class_any_from_key_value_async();

  public static Task<T> f_any_from_key_value_async<T, U>(T generic_any_1, Vx.Core.Type_string key, U val) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
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
  public interface Func_any_from_list : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_list<T, X>(T generic_any_1, X values, Vx.Core.Type_int index) where T : Vx.Core.Type_any where X : Vx.Core.Type_list;
  }

  public class Class_any_from_list : Vx.Core.Class_base, Func_any_from_list {

    public override Vx.Core.Func_any_from_list vx_new(params Object[] vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    public override Vx.Core.Func_any_from_list vx_copy(params Object[] vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_list;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int index = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_list(generic_any_1, values, index);
      return output;
    }

    public T vx_any_from_list<T, X>(T generic_any_1, X values, Vx.Core.Type_int index) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
      return Vx.Core.f_any_from_list(generic_any_1, values, index);
    }

  }

  public static Func_any_from_list e_any_from_list = new Vx.Core.Class_any_from_list();
  public static Func_any_from_list t_any_from_list = new Vx.Core.Class_any_from_list();

  public static T f_any_from_list<T, X>(T generic_any_1, X values, Vx.Core.Type_int index) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_list_start_reduce : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce fn_reduce) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list;
  }

  public class Class_any_from_list_start_reduce : Vx.Core.Class_base, Func_any_from_list_start_reduce {

    public override Vx.Core.Func_any_from_list_start_reduce vx_new(params Object[] vals) {
      Class_any_from_list_start_reduce output = new Class_any_from_list_start_reduce();
      return output;
    }

    public override Vx.Core.Func_any_from_list_start_reduce vx_copy(params Object[] vals) {
      Class_any_from_list_start_reduce output = new Class_any_from_list_start_reduce();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-start-reduce", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_list_start_reduce;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_list_start_reduce;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list list = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any valstart = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Func_any_from_reduce fn_reduce = Vx.Core.f_any_from_any(Vx.Core.t_any_from_reduce, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_any_from_list_start_reduce(generic_any_1, list, valstart, fn_reduce);
      return output;
    }

    public T vx_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce fn_reduce) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list {
      return Vx.Core.f_any_from_list_start_reduce(generic_any_1, list, valstart, fn_reduce);
    }

  }

  public static Func_any_from_list_start_reduce e_any_from_list_start_reduce = new Vx.Core.Class_any_from_list_start_reduce();
  public static Func_any_from_list_start_reduce t_any_from_list_start_reduce = new Vx.Core.Class_any_from_list_start_reduce();

  public static T f_any_from_list_start_reduce<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce fn_reduce) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_list_start_reduce_next : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce_next fn_reduce_next) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list;
  }

  public class Class_any_from_list_start_reduce_next : Vx.Core.Class_base, Func_any_from_list_start_reduce_next {

    public override Vx.Core.Func_any_from_list_start_reduce_next vx_new(params Object[] vals) {
      Class_any_from_list_start_reduce_next output = new Class_any_from_list_start_reduce_next();
      return output;
    }

    public override Vx.Core.Func_any_from_list_start_reduce_next vx_copy(params Object[] vals) {
      Class_any_from_list_start_reduce_next output = new Class_any_from_list_start_reduce_next();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-start-reduce-next", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_list_start_reduce_next;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_list_start_reduce_next;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list list = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any valstart = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Func_any_from_reduce_next fn_reduce_next = Vx.Core.f_any_from_any(Vx.Core.t_any_from_reduce_next, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_any_from_list_start_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
      return output;
    }

    public T vx_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce_next fn_reduce_next) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list {
      return Vx.Core.f_any_from_list_start_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
    }

  }

  public static Func_any_from_list_start_reduce_next e_any_from_list_start_reduce_next = new Vx.Core.Class_any_from_list_start_reduce_next();
  public static Func_any_from_list_start_reduce_next t_any_from_list_start_reduce_next = new Vx.Core.Class_any_from_list_start_reduce_next();

  public static T f_any_from_list_start_reduce_next<T, Y>(T generic_any_1, Y list, T valstart, Vx.Core.Func_any_from_reduce_next fn_reduce_next) where T : Vx.Core.Type_any where Y : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_map : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_map<N, T>(T generic_any_1, N valuemap, Vx.Core.Type_string key) where N : Vx.Core.Type_map where T : Vx.Core.Type_any;
  }

  public class Class_any_from_map : Vx.Core.Class_base, Func_any_from_map {

    public override Vx.Core.Func_any_from_map vx_new(params Object[] vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    public override Vx.Core.Func_any_from_map vx_copy(params Object[] vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-map", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_map;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_map;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_map(generic_any_1, valuemap, key);
      return output;
    }

    public T vx_any_from_map<N, T>(T generic_any_1, N valuemap, Vx.Core.Type_string key) where N : Vx.Core.Type_map where T : Vx.Core.Type_any {
      return Vx.Core.f_any_from_map(generic_any_1, valuemap, key);
    }

  }

  public static Func_any_from_map e_any_from_map = new Vx.Core.Class_any_from_map();
  public static Func_any_from_map t_any_from_map = new Vx.Core.Class_any_from_map();

  public static T f_any_from_map<N, T>(T generic_any_1, N valuemap, Vx.Core.Type_string key) where N : Vx.Core.Type_map where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_map_start_reduce : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, Vx.Core.Func_any_from_any_key_value fn_reduce) where N : Vx.Core.Type_map where T : Vx.Core.Type_any;
  }

  public class Class_any_from_map_start_reduce : Vx.Core.Class_base, Func_any_from_map_start_reduce {

    public override Vx.Core.Func_any_from_map_start_reduce vx_new(params Object[] vals) {
      Class_any_from_map_start_reduce output = new Class_any_from_map_start_reduce();
      return output;
    }

    public override Vx.Core.Func_any_from_map_start_reduce vx_copy(params Object[] vals) {
      Class_any_from_map_start_reduce output = new Class_any_from_map_start_reduce();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-map-start-reduce", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_map_start_reduce;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_map_start_reduce;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map map = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any start = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Func_any_from_any_key_value fn_reduce = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any_key_value, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_any_from_map_start_reduce(generic_any_1, map, start, fn_reduce);
      return output;
    }

    public T vx_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, Vx.Core.Func_any_from_any_key_value fn_reduce) where N : Vx.Core.Type_map where T : Vx.Core.Type_any {
      return Vx.Core.f_any_from_map_start_reduce(generic_any_1, map, start, fn_reduce);
    }

  }

  public static Func_any_from_map_start_reduce e_any_from_map_start_reduce = new Vx.Core.Class_any_from_map_start_reduce();
  public static Func_any_from_map_start_reduce t_any_from_map_start_reduce = new Vx.Core.Class_any_from_map_start_reduce();

  public static T f_any_from_map_start_reduce<N, T>(T generic_any_1, N map, T start, Vx.Core.Func_any_from_any_key_value fn_reduce) where N : Vx.Core.Type_map where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_none
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none)
   */
  public interface Func_any_from_none : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_none vx_fn_new(Vx.Core.Class_any_from_none.IFn fn);
    public T vx_any_from_none<T>(T generic_any_1) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_none : Vx.Core.Class_base, Func_any_from_none {

    public override Vx.Core.Func_any_from_none vx_new(params Object[] vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    public override Vx.Core.Func_any_from_none vx_copy(params Object[] vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-none", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_none;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_none;
    }

    public delegate Vx.Core.Type_any IFn();

    public IFn? fn = null;

    public Vx.Core.Func_any_from_none vx_fn_new(Vx.Core.Class_any_from_none.IFn fn) {
      Class_any_from_none output = new Class_any_from_none();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_any_from_none(generic_any_1);
      return output;
    }

    public T vx_any_from_none<T>(T generic_any_1) where T : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn();
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_none e_any_from_none = new Vx.Core.Class_any_from_none();
  public static Func_any_from_none t_any_from_none = new Vx.Core.Class_any_from_none();

  public static T f_any_from_none<T>(T generic_any_1) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_none_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_none_async vx_fn_new(Vx.Core.Class_any_from_none_async.IFn fn);
    public Task<T> vx_any_from_none_async<T>(T generic_any_1) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_none_async : Vx.Core.Class_base, Func_any_from_none_async {

    public override Vx.Core.Func_any_from_none_async vx_new(params Object[] vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    public override Vx.Core.Func_any_from_none_async vx_copy(params Object[] vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-none-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_none_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_none_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn();

    public IFn? fn = null;

    public Vx.Core.Func_any_from_none_async vx_fn_new(Vx.Core.Class_any_from_none_async.IFn fn) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_none_async(generic_any_1);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_none_async<T>(T generic_any_1) where T : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn();
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_none_async e_any_from_none_async = new Vx.Core.Class_any_from_none_async();
  public static Func_any_from_none_async t_any_from_none_async = new Vx.Core.Class_any_from_none_async();

  public static Task<T> f_any_from_none_async<T>(T generic_any_1) where T : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce)
   */
  public interface Func_any_from_reduce : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_reduce vx_fn_new(Vx.Core.Class_any_from_reduce.IFn fn);
    public T vx_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_reduce : Vx.Core.Class_base, Func_any_from_reduce {

    public override Vx.Core.Func_any_from_reduce vx_new(params Object[] vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    public override Vx.Core.Func_any_from_reduce vx_copy(params Object[] vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_reduce;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_reduce;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_any result, Vx.Core.Type_any item);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_reduce vx_fn_new(Vx.Core.Class_any_from_reduce.IFn fn) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any result = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any item = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_reduce(generic_any_1, result, item);
      return output;
    }

    public T vx_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(result, item);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_reduce e_any_from_reduce = new Vx.Core.Class_any_from_reduce();
  public static Func_any_from_reduce t_any_from_reduce = new Vx.Core.Class_any_from_reduce();

  public static T f_any_from_reduce<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_reduce_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_reduce_async vx_fn_new(Vx.Core.Class_any_from_reduce_async.IFn fn);
    public Task<T> vx_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_reduce_async : Vx.Core.Class_base, Func_any_from_reduce_async {

    public override Vx.Core.Func_any_from_reduce_async vx_new(params Object[] vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    public override Vx.Core.Func_any_from_reduce_async vx_copy(params Object[] vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_reduce_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_reduce_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn(Vx.Core.Type_any result, Vx.Core.Type_any item);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_reduce_async vx_fn_new(Vx.Core.Class_any_from_reduce_async.IFn fn) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any result = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any item = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_reduce_async(generic_any_1, result, item);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn(result, item);
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_async e_any_from_reduce_async = new Vx.Core.Class_any_from_reduce_async();
  public static Func_any_from_reduce_async t_any_from_reduce_async = new Vx.Core.Class_any_from_reduce_async();

  public static Task<T> f_any_from_reduce_async<T, U>(T generic_any_1, T result, U item) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
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
  public interface Func_any_from_reduce_next : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_any_from_reduce_next vx_fn_new(Vx.Core.Class_any_from_reduce_next.IFn fn);
    public T vx_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_reduce_next : Vx.Core.Class_base, Func_any_from_reduce_next {

    public override Vx.Core.Func_any_from_reduce_next vx_new(params Object[] vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    public override Vx.Core.Func_any_from_reduce_next vx_copy(params Object[] vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_reduce_next;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_reduce_next;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_any result, Vx.Core.Type_any current, Vx.Core.Type_any next);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_reduce_next vx_fn_new(Vx.Core.Class_any_from_reduce_next.IFn fn) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any result = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any next = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_any_from_reduce_next(generic_any_1, result, current, next);
      return output;
    }

    public T vx_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(result, current, next);
        output = Vx.Core.f_any_from_any(generic_any_1, anyoutput);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_next e_any_from_reduce_next = new Vx.Core.Class_any_from_reduce_next();
  public static Func_any_from_reduce_next t_any_from_reduce_next = new Vx.Core.Class_any_from_reduce_next();

  public static T f_any_from_reduce_next<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_any_from_reduce_next_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Vx.Core.Func_any_from_reduce_next_async vx_fn_new(Vx.Core.Class_any_from_reduce_next_async.IFn fn);
    public Task<T> vx_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_any_from_reduce_next_async : Vx.Core.Class_base, Func_any_from_reduce_next_async {

    public override Vx.Core.Func_any_from_reduce_next_async vx_new(params Object[] vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    public override Vx.Core.Func_any_from_reduce_next_async vx_copy(params Object[] vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_reduce_next_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_reduce_next_async;
    }

    public delegate Task<Vx.Core.Type_any> IFn(Vx.Core.Type_any result, Vx.Core.Type_any current, Vx.Core.Type_any next);

    public IFn? fn = null;

    public Vx.Core.Func_any_from_reduce_next_async vx_fn_new(Vx.Core.Class_any_from_reduce_next_async.IFn fn) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      output.fn = fn;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any result = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any current = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any next = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_any_from_reduce_next_async(generic_any_1, result, current, next);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Task<T> output;
      if (fn == null) {
        output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
      } else {
        Task<Vx.Core.Type_any> future = fn(result, current, next);
        output = Vx.Core.vx_async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static Func_any_from_reduce_next_async e_any_from_reduce_next_async = new Vx.Core.Class_any_from_reduce_next_async();
  public static Func_any_from_reduce_next_async t_any_from_reduce_next_async = new Vx.Core.Class_any_from_reduce_next_async();

  public static Task<T> f_any_from_reduce_next_async<T, U>(T generic_any_1, T result, U current, U next) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
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
  public interface Func_any_from_struct : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_from_struct<R, T>(T generic_any_1, R vstruct, Vx.Core.Type_string key) where R : Vx.Core.Type_struct where T : Vx.Core.Type_any;
  }

  public class Class_any_from_struct : Vx.Core.Class_base, Func_any_from_struct {

    public override Vx.Core.Func_any_from_struct vx_new(params Object[] vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    public override Vx.Core.Func_any_from_struct vx_copy(params Object[] vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "any<-struct", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_from_struct;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_struct;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_struct vstruct = Vx.Core.f_any_from_any(Vx.Core.t_struct, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_any_from_struct(generic_any_1, vstruct, key);
      return output;
    }

    public T vx_any_from_struct<R, T>(T generic_any_1, R vstruct, Vx.Core.Type_string key) where R : Vx.Core.Type_struct where T : Vx.Core.Type_any {
      return Vx.Core.f_any_from_struct(generic_any_1, vstruct, key);
    }

  }

  public static Func_any_from_struct e_any_from_struct = new Vx.Core.Class_any_from_struct();
  public static Func_any_from_struct t_any_from_struct = new Vx.Core.Class_any_from_struct();

  public static T f_any_from_struct<R, T>(T generic_any_1, R vstruct, Vx.Core.Type_string key) where R : Vx.Core.Type_struct where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    Vx.Core.Type_any val = vstruct.vx_any(key);
    output = Vx.Core.f_any_from_any(generic_any_1, val);
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
  public interface Func_async : Vx.Core.Func_any_from_any_async {
    public Task<T> vx_async<T>(T generic_any_1, T value) where T : Vx.Core.Type_any;
  }

  public class Class_async : Vx.Core.Class_base, Func_async {

    public override Vx.Core.Func_async vx_new(params Object[] vals) {
      Class_async output = new Class_async();
      return output;
    }

    public override Vx.Core.Func_async vx_copy(params Object[] vals) {
      Class_async output = new Class_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_async;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T inputval = Vx.Core.f_any_from_any(generic_any_1, value);
      Task<T> output = Vx.Core.f_async(generic_any_1, inputval);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_async(generic_any_1, value);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_async<T>(T generic_any_1, T value) where T : Vx.Core.Type_any {
      return Vx.Core.f_async(generic_any_1, value);
    }

  }

  public static Func_async e_async = new Vx.Core.Class_async();
  public static Func_async t_async = new Vx.Core.Class_async();

  public static Task<T> f_async<T>(T generic_any_1, T value) where T : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    output = Vx.Core.vx_async_new_completed(value);
    return output;
  }

  /**
   * @function boolean_permission_from_func
   * Returns true if the given func has permission.
   * @param  {func} func
   * @return {boolean}
   * (func boolean-permission<-func)
   */
  public interface Func_boolean_permission_from_func : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_permission_from_func(Vx.Core.Type_context context, Vx.Core.Type_func func);
  }

  public class Class_boolean_permission_from_func : Vx.Core.Class_base, Func_boolean_permission_from_func {

    public override Vx.Core.Func_boolean_permission_from_func vx_new(params Object[] vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    public override Vx.Core.Func_boolean_permission_from_func vx_copy(params Object[] vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "boolean-permission<-func", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_permission_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_permission_from_func;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_func inputval = (Vx.Core.Type_func)value;
      Vx.Core.Type_any outputval = Vx.Core.f_boolean_permission_from_func(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_func func = Vx.Core.f_any_from_any(Vx.Core.t_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_boolean_permission_from_func(context, func);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_permission_from_func(Vx.Core.Type_context context, Vx.Core.Type_func func) {
      return Vx.Core.f_boolean_permission_from_func(context, func);
    }

  }

  public static Func_boolean_permission_from_func e_boolean_permission_from_func = new Vx.Core.Class_boolean_permission_from_func();
  public static Func_boolean_permission_from_func t_boolean_permission_from_func = new Vx.Core.Class_boolean_permission_from_func();

  public static Vx.Core.Type_boolean f_boolean_permission_from_func(Vx.Core.Type_context context, Vx.Core.Type_func func) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_contains_1(
      Vx.Core.f_allowfuncs_from_security(
        Vx.Core.f_security_from_context(context)
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
  public interface Func_boolean_write_from_map_name_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_map_name_value(Vx.Core.Type_map valuemap, Vx.Core.Type_string name, Vx.Core.Type_any value);
  }

  public class Class_boolean_write_from_map_name_value : Vx.Core.Class_base, Func_boolean_write_from_map_name_value {

    public override Vx.Core.Func_boolean_write_from_map_name_value vx_new(params Object[] vals) {
      Class_boolean_write_from_map_name_value output = new Class_boolean_write_from_map_name_value();
      return output;
    }

    public override Vx.Core.Func_boolean_write_from_map_name_value vx_copy(params Object[] vals) {
      Class_boolean_write_from_map_name_value output = new Class_boolean_write_from_map_name_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "boolean-write<-map-name-value", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_write_from_map_name_value;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_write_from_map_name_value;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_boolean_write_from_map_name_value(valuemap, name, value);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_map_name_value(Vx.Core.Type_map valuemap, Vx.Core.Type_string name, Vx.Core.Type_any value) {
      return Vx.Core.f_boolean_write_from_map_name_value(valuemap, name, value);
    }

  }

  public static Func_boolean_write_from_map_name_value e_boolean_write_from_map_name_value = new Vx.Core.Class_boolean_write_from_map_name_value();
  public static Func_boolean_write_from_map_name_value t_boolean_write_from_map_name_value = new Vx.Core.Class_boolean_write_from_map_name_value();

  public static Vx.Core.Type_boolean f_boolean_write_from_map_name_value(Vx.Core.Type_map valuemap, Vx.Core.Type_string name, Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_any
   * Function Type taking generic any-1 and returning boolean
   * @param  {any-1} value
   * @return {boolean}
   * (func boolean<-any)
   */
  public interface Func_boolean_from_any : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_boolean_from_any vx_fn_new(Vx.Core.Class_boolean_from_any.IFn fn);
    public Vx.Core.Type_boolean vx_boolean_from_any(Vx.Core.Type_any value);
  }

  public class Class_boolean_from_any : Vx.Core.Class_base, Func_boolean_from_any {

    public override Vx.Core.Func_boolean_from_any vx_new(params Object[] vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    public override Vx.Core.Func_boolean_from_any vx_copy(params Object[] vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_from_any;
    }

    public delegate Vx.Core.Type_any IFn(Vx.Core.Type_any value);

    public IFn? fn = null;

    public Vx.Core.Func_boolean_from_any vx_fn_new(Vx.Core.Class_boolean_from_any.IFn fn) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_boolean_from_any(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_from_any(Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn(value);
        output = Vx.Core.f_any_from_any(Vx.Core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_any e_boolean_from_any = new Vx.Core.Class_boolean_from_any();
  public static Func_boolean_from_any t_boolean_from_any = new Vx.Core.Class_boolean_from_any();

  public static Vx.Core.Type_boolean f_boolean_from_any(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_func
   * Function Type returning boolean with any parameters
   * @return {boolean}
   * (func boolean<-func)
   */
  public interface Func_boolean_from_func : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_boolean_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn);
    public Vx.Core.Type_boolean vx_boolean_from_func();
  }

  public class Class_boolean_from_func : Vx.Core.Class_base, Func_boolean_from_func {

    public override Vx.Core.Func_boolean_from_func vx_new(params Object[] vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    public override Vx.Core.Func_boolean_from_func vx_copy(params Object[] vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-func", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_from_func;
    }

    public delegate Vx.Core.Type_any IFn();

    public Vx.Core.Class_any_from_func.IFn? fn = null;

    public Vx.Core.Func_boolean_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Core.f_boolean_from_func();
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_from_func() {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn();
        output = Vx.Core.f_any_from_any(Vx.Core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_func e_boolean_from_func = new Vx.Core.Class_boolean_from_func();
  public static Func_boolean_from_func t_boolean_from_func = new Vx.Core.Class_boolean_from_func();

  public static Vx.Core.Type_boolean f_boolean_from_func() {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_none
   * Function Type returning boolean with no parameters
   * @return {boolean}
   * (func boolean<-none)
   */
  public interface Func_boolean_from_none : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_boolean_from_none vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn);
    public Vx.Core.Type_boolean vx_boolean_from_none();
  }

  public class Class_boolean_from_none : Vx.Core.Class_base, Func_boolean_from_none {

    public override Vx.Core.Func_boolean_from_none vx_new(params Object[] vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    public override Vx.Core.Func_boolean_from_none vx_copy(params Object[] vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-none", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_from_none;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_from_none;
    }

    public delegate Vx.Core.Type_any IFn();

    public Vx.Core.Class_any_from_func.IFn? fn = null;

    public Vx.Core.Func_boolean_from_none vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Core.f_boolean_from_none();
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_from_none() {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (fn != null) {
        Vx.Core.Type_any anyoutput = fn();
        output = Vx.Core.f_any_from_any(Vx.Core.t_boolean, anyoutput);
      }
      return output;
    }

  }

  public static Func_boolean_from_none e_boolean_from_none = new Vx.Core.Class_boolean_from_none();
  public static Func_boolean_from_none t_boolean_from_none = new Vx.Core.Class_boolean_from_none();

  public static Vx.Core.Type_boolean f_boolean_from_none() {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function case
   * @param  {list-1} values
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  public interface Func_case : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_thenelse vx_case(Vx.Core.Type_list values, Vx.Core.Func_any_from_func fn_any);
  }

  public class Class_case : Vx.Core.Class_base, Func_case {

    public override Vx.Core.Func_case vx_new(params Object[] vals) {
      Class_case output = new Class_case();
      return output;
    }

    public override Vx.Core.Func_case vx_copy(params Object[] vals) {
      Class_case output = new Class_case();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
      return e_case;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_case;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_case(values, fn_any);
      return output;
    }

    public Vx.Core.Type_thenelse vx_case(Vx.Core.Type_list values, Vx.Core.Func_any_from_func fn_any) {
      return Vx.Core.f_case(values, fn_any);
    }

  }

  public static Func_case e_case = new Vx.Core.Class_case();
  public static Func_case t_case = new Vx.Core.Class_case();

  public static Vx.Core.Type_thenelse f_case(Vx.Core.Type_list values, Vx.Core.Func_any_from_func fn_any) {
    Vx.Core.Type_thenelse output = Vx.Core.e_thenelse;
    output = Vx.Core.f_new(
      Vx.Core.t_thenelse,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        Vx.Core.vx_new_string(":casemany"),
        Vx.Core.vx_new_string(":values"),
        values,
        Vx.Core.vx_new_string(":fn-any"),
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
  public interface Func_case_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_thenelse vx_case_1(Vx.Core.Type_any value, Vx.Core.Func_any_from_func fn_any);
  }

  public class Class_case_1 : Vx.Core.Class_base, Func_case_1 {

    public override Vx.Core.Func_case_1 vx_new(params Object[] vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    public override Vx.Core.Func_case_1 vx_copy(params Object[] vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
      return e_case_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_case_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_case_1(value, fn_any);
      return output;
    }

    public Vx.Core.Type_thenelse vx_case_1(Vx.Core.Type_any value, Vx.Core.Func_any_from_func fn_any) {
      return Vx.Core.f_case_1(value, fn_any);
    }

  }

  public static Func_case_1 e_case_1 = new Vx.Core.Class_case_1();
  public static Func_case_1 t_case_1 = new Vx.Core.Class_case_1();

  public static Vx.Core.Type_thenelse f_case_1(Vx.Core.Type_any value, Vx.Core.Func_any_from_func fn_any) {
    Vx.Core.Type_thenelse output = Vx.Core.e_thenelse;
    output = Vx.Core.f_new(
      Vx.Core.t_thenelse,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        Vx.Core.vx_new_string(":case"),
        Vx.Core.vx_new_string(":value"),
        value,
        Vx.Core.vx_new_string(":fn-any"),
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
  public interface Func_compare : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_compare(Vx.Core.Type_any val1, Vx.Core.Type_any val2);
  }

  public class Class_compare : Vx.Core.Class_base, Func_compare {

    public override Vx.Core.Func_compare vx_new(params Object[] vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    public override Vx.Core.Func_compare vx_copy(params Object[] vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "compare", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_compare;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_compare;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val2 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_compare(val1, val2);
      return output;
    }

    public Vx.Core.Type_int vx_compare(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
      return Vx.Core.f_compare(val1, val2);
    }

  }

  public static Func_compare e_compare = new Vx.Core.Class_compare();
  public static Func_compare t_compare = new Vx.Core.Class_compare();

  public static Vx.Core.Type_int f_compare(Vx.Core.Type_any val1, Vx.Core.Type_any val2) {
    Vx.Core.Type_int output = Vx.Core.e_int;
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
  public interface Func_contains : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_contains(Vx.Core.Type_string text, Vx.Core.Type_string find);
  }

  public class Class_contains : Vx.Core.Class_base, Func_contains {

    public override Vx.Core.Func_contains vx_new(params Object[] vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    public override Vx.Core.Func_contains vx_copy(params Object[] vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_contains;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_contains;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_contains(text, find);
      return output;
    }

    public Vx.Core.Type_boolean vx_contains(Vx.Core.Type_string text, Vx.Core.Type_string find) {
      return Vx.Core.f_contains(text, find);
    }

  }

  public static Func_contains e_contains = new Vx.Core.Class_contains();
  public static Func_contains t_contains = new Vx.Core.Class_contains();

  public static Vx.Core.Type_boolean f_contains(Vx.Core.Type_string text, Vx.Core.Type_string find) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
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
  public interface Func_contains_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_contains_1(Vx.Core.Type_list values, Vx.Core.Type_any find);
  }

  public class Class_contains_1 : Vx.Core.Class_base, Func_contains_1 {

    public override Vx.Core.Func_contains_1 vx_new(params Object[] vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    public override Vx.Core.Func_contains_1 vx_copy(params Object[] vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_contains_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_contains_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any find = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_contains_1(values, find);
      return output;
    }

    public Vx.Core.Type_boolean vx_contains_1(Vx.Core.Type_list values, Vx.Core.Type_any find) {
      return Vx.Core.f_contains_1(values, find);
    }

  }

  public static Func_contains_1 e_contains_1 = new Vx.Core.Class_contains_1();
  public static Func_contains_1 t_contains_1 = new Vx.Core.Class_contains_1();

  public static Vx.Core.Type_boolean f_contains_1(Vx.Core.Type_list values, Vx.Core.Type_any find) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function context_main
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-main)
   */
  public interface Func_context_main : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_context vx_context_main(Vx.Core.Type_anylist args);
  }

  public class Class_context_main : Vx.Core.Class_base, Func_context_main {

    public override Vx.Core.Func_context_main vx_new(params Object[] vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    public override Vx.Core.Func_context_main vx_copy(params Object[] vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "context-main", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      return e_context_main;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_context_main;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_context_main(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_context_main(args);
      return output;
    }

    public Vx.Core.Type_context vx_context_main(Vx.Core.Type_anylist args) {
      return Vx.Core.f_context_main(args);
    }

  }

  public static Func_context_main e_context_main = new Vx.Core.Class_context_main();
  public static Func_context_main t_context_main = new Vx.Core.Class_context_main();

  public static Vx.Core.Type_context f_context_main(Vx.Core.Type_anylist args) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Core.f_empty(
      Vx.Core.t_context
    );
    return output;
  }

  /**
   * @function copy
   * Returns a copy of a given value with the given values added or updated.
   * @param  {any-1} value
   * @param  {anylist} values
   * @return {any-1}
   * (func copy)
   */
  public interface Func_copy : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_copy<T>(T value, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any;
  }

  public class Class_copy : Vx.Core.Class_base, Func_copy {

    public override Vx.Core.Func_copy vx_new(params Object[] vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    public override Vx.Core.Func_copy vx_copy(params Object[] vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "copy", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_copy;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_copy;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist values = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_copy(value, values);
      return output;
    }

    public T vx_copy<T>(T value, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any {
      return Vx.Core.f_copy(value, values);
    }

  }

  public static Func_copy e_copy = new Vx.Core.Class_copy();
  public static Func_copy t_copy = new Vx.Core.Class_copy();

  public static T f_copy<T>(T value, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any {
    Vx.Core.Type_any[] arrayany = Vx.Core.arrayany_from_anylist(values);
    object[] arrayobj = (Vx.Core.Type_any[])arrayany;
    T output = (T)(((T)value).vx_copy(arrayobj));
    return output;
  }

  /**
   * @function else
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func else)
   */
  public interface Func_else : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_thenelse vx_else(Vx.Core.Func_any_from_func fn_any);
  }

  public class Class_else : Vx.Core.Class_base, Func_else {

    public override Vx.Core.Func_else vx_new(params Object[] vals) {
      Class_else output = new Class_else();
      return output;
    }

    public override Vx.Core.Func_else vx_copy(params Object[] vals) {
      Class_else output = new Class_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "else", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
      return e_else;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_else;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Func_any_from_func inputval = (Vx.Core.Func_any_from_func)value;
      Vx.Core.Type_any outputval = Vx.Core.f_else(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_else(fn_any);
      return output;
    }

    public Vx.Core.Type_thenelse vx_else(Vx.Core.Func_any_from_func fn_any) {
      return Vx.Core.f_else(fn_any);
    }

  }

  public static Func_else e_else = new Vx.Core.Class_else();
  public static Func_else t_else = new Vx.Core.Class_else();

  public static Vx.Core.Type_thenelse f_else(Vx.Core.Func_any_from_func fn_any) {
    Vx.Core.Type_thenelse output = Vx.Core.e_thenelse;
    output = Vx.Core.f_new(
      Vx.Core.t_thenelse,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        Vx.Core.vx_new_string(":else"),
        Vx.Core.vx_new_string(":fn-any"),
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
  public interface Func_empty : Vx.Core.Func_any_from_any {
    public T vx_empty<T>(T type) where T : Vx.Core.Type_any;
  }

  public class Class_empty : Vx.Core.Class_base, Func_empty {

    public override Vx.Core.Func_empty vx_new(params Object[] vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    public override Vx.Core.Func_empty vx_copy(params Object[] vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "empty", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_empty;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_empty;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_empty(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_empty(type);
      return output;
    }

    public T vx_empty<T>(T type) where T : Vx.Core.Type_any {
      return Vx.Core.f_empty(type);
    }

  }

  public static Func_empty e_empty = new Vx.Core.Class_empty();
  public static Func_empty t_empty = new Vx.Core.Class_empty();

  public static T f_empty<T>(T type) where T : Vx.Core.Type_any {
    T output = Vx.Core.vx_empty(type);
    return output;
  }

  /**
   * @function extends_from_any
   * @param  {any-1} val
   * @return {string}
   * (func extends<-any)
   */
  public interface Func_extends_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_extends_from_any(Vx.Core.Type_any val);
  }

  public class Class_extends_from_any : Vx.Core.Class_base, Func_extends_from_any {

    public override Vx.Core.Func_extends_from_any vx_new(params Object[] vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    public override Vx.Core.Func_extends_from_any vx_copy(params Object[] vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "extends<-any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_extends_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_extends_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_extends_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_extends_from_any(val);
      return output;
    }

    public Vx.Core.Type_string vx_extends_from_any(Vx.Core.Type_any val) {
      return Vx.Core.f_extends_from_any(val);
    }

  }

  public static Func_extends_from_any e_extends_from_any = new Vx.Core.Class_extends_from_any();
  public static Func_extends_from_any t_extends_from_any = new Vx.Core.Class_extends_from_any();

  public static Vx.Core.Type_string f_extends_from_any(Vx.Core.Type_any val) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_extends_from_typedef(
      Vx.Core.f_typedef_from_any(val)
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
  public interface Func_extends_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_extends_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_extends_from_typedef : Vx.Core.Class_base, Func_extends_from_typedef {

    public override Vx.Core.Func_extends_from_typedef vx_new(params Object[] vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    public override Vx.Core.Func_extends_from_typedef vx_copy(params Object[] vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "extends<-typedef", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_extends_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_extends_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_extends_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_extends_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_string vx_extends_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_extends_from_typedef(vtypedef);
    }

  }

  public static Func_extends_from_typedef e_extends_from_typedef = new Vx.Core.Class_extends_from_typedef();
  public static Func_extends_from_typedef t_extends_from_typedef = new Vx.Core.Class_extends_from_typedef();

  public static Vx.Core.Type_string f_extends_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_first_from_list : Vx.Core.Func_any_from_any {
    public T vx_first_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list;
  }

  public class Class_first_from_list : Vx.Core.Class_base, Func_first_from_list {

    public override Vx.Core.Func_first_from_list vx_new(params Object[] vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    public override Vx.Core.Func_first_from_list vx_copy(params Object[] vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "first<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_first_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_first_from_list;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_first_from_list(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_first_from_list(generic_any_1, values);
      return output;
    }

    public T vx_first_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
      return Vx.Core.f_first_from_list(generic_any_1, values);
    }

  }

  public static Func_first_from_list e_first_from_list = new Vx.Core.Class_first_from_list();
  public static Func_first_from_list t_first_from_list = new Vx.Core.Class_first_from_list();

  public static T f_first_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_any_from_list(generic_any_1, values, Vx.Core.vx_new_int(1));
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
  public interface Func_first_from_list_any_from_any : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_first_from_list_any_from_any<T, X>(T generic_any_1, X values, Vx.Core.Func_any_from_any fn_any_from_any) where T : Vx.Core.Type_any where X : Vx.Core.Type_list;
  }

  public class Class_first_from_list_any_from_any : Vx.Core.Class_base, Func_first_from_list_any_from_any {

    public override Vx.Core.Func_first_from_list_any_from_any vx_new(params Object[] vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    public override Vx.Core.Func_first_from_list_any_from_any vx_copy(params Object[] vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "first<-list-any<-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_first_from_list_any_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_first_from_list_any_from_any;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_any fn_any_from_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
      return output;
    }

    public T vx_first_from_list_any_from_any<T, X>(T generic_any_1, X values, Vx.Core.Func_any_from_any fn_any_from_any) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
      return Vx.Core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
    }

  }

  public static Func_first_from_list_any_from_any e_first_from_list_any_from_any = new Vx.Core.Class_first_from_list_any_from_any();
  public static Func_first_from_list_any_from_any t_first_from_list_any_from_any = new Vx.Core.Class_first_from_list_any_from_any();

  public static T f_first_from_list_any_from_any<T, X>(T generic_any_1, X values, Vx.Core.Func_any_from_any fn_any_from_any) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function float_from_string
   * Returns float from a given string.
   * @param  {string} text
   * @return {float}
   * (func float<-string)
   */
  public interface Func_float_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_float vx_float_from_string(Vx.Core.Type_string text);
  }

  public class Class_float_from_string : Vx.Core.Class_base, Func_float_from_string {

    public override Vx.Core.Func_float_from_string vx_new(params Object[] vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    public override Vx.Core.Func_float_from_string vx_copy(params Object[] vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "float<-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "float", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_float_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_float_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_float_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_float_from_string(text);
      return output;
    }

    public Vx.Core.Type_float vx_float_from_string(Vx.Core.Type_string text) {
      return Vx.Core.f_float_from_string(text);
    }

  }

  public static Func_float_from_string e_float_from_string = new Vx.Core.Class_float_from_string();
  public static Func_float_from_string t_float_from_string = new Vx.Core.Class_float_from_string();

  public static Vx.Core.Type_float f_float_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_float output = Vx.Core.e_float;
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
  public interface Func_fn : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_fn<T>(T generic_any_1, Vx.Core.Type_arglist parameters, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any;
  }

  public class Class_fn : Vx.Core.Class_base, Func_fn {

    public override Vx.Core.Func_fn vx_new(params Object[] vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    public override Vx.Core.Func_fn vx_copy(params Object[] vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "fn", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fn;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_fn;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_arglist parameters = Vx.Core.f_any_from_any(Vx.Core.t_arglist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_fn(generic_any_1, parameters, fn_any);
      return output;
    }

    public T vx_fn<T>(T generic_any_1, Vx.Core.Type_arglist parameters, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
      return Vx.Core.f_fn(generic_any_1, parameters, fn_any);
    }

  }

  public static Func_fn e_fn = new Vx.Core.Class_fn();
  public static Func_fn t_fn = new Vx.Core.Class_fn();

  public static T f_fn<T>(T generic_any_1, Vx.Core.Type_arglist parameters, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function funcdef_from_func
   * @param  {func} val
   * @return {funcdef}
   * (func funcdef<-func)
   */
  public interface Func_funcdef_from_func : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_funcdef vx_funcdef_from_func(Vx.Core.Type_func val);
  }

  public class Class_funcdef_from_func : Vx.Core.Class_base, Func_funcdef_from_func {

    public override Vx.Core.Func_funcdef_from_func vx_new(params Object[] vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    public override Vx.Core.Func_funcdef_from_func vx_copy(params Object[] vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "funcdef<-func", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "funcdef", // name
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
      return e_funcdef_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_funcdef_from_func;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_func inputval = (Vx.Core.Type_func)value;
      Vx.Core.Type_any outputval = Vx.Core.f_funcdef_from_func(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_func val = Vx.Core.f_any_from_any(Vx.Core.t_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_funcdef_from_func(val);
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef_from_func(Vx.Core.Type_func val) {
      return Vx.Core.f_funcdef_from_func(val);
    }

  }

  public static Func_funcdef_from_func e_funcdef_from_func = new Vx.Core.Class_funcdef_from_func();
  public static Func_funcdef_from_func t_funcdef_from_func = new Vx.Core.Class_funcdef_from_func();

  public static Vx.Core.Type_funcdef f_funcdef_from_func(Vx.Core.Type_func val) {
    Vx.Core.Type_funcdef output = Vx.Core.e_funcdef;
    return output;
  }

  /**
   * @function funcname_from_funcdef
   * Get the name of a given funcdef
   * @param  {funcdef} funcdef
   * @return {string}
   * (func funcname<-funcdef)
   */
  public interface Func_funcname_from_funcdef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_funcname_from_funcdef(Vx.Core.Type_funcdef funcdef);
  }

  public class Class_funcname_from_funcdef : Vx.Core.Class_base, Func_funcname_from_funcdef {

    public override Vx.Core.Func_funcname_from_funcdef vx_new(params Object[] vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    public override Vx.Core.Func_funcname_from_funcdef vx_copy(params Object[] vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "funcname<-funcdef", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_funcname_from_funcdef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_funcname_from_funcdef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_funcdef inputval = (Vx.Core.Type_funcdef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_funcname_from_funcdef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_funcdef funcdef = Vx.Core.f_any_from_any(Vx.Core.t_funcdef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_funcname_from_funcdef(funcdef);
      return output;
    }

    public Vx.Core.Type_string vx_funcname_from_funcdef(Vx.Core.Type_funcdef funcdef) {
      return Vx.Core.f_funcname_from_funcdef(funcdef);
    }

  }

  public static Func_funcname_from_funcdef e_funcname_from_funcdef = new Vx.Core.Class_funcname_from_funcdef();
  public static Func_funcname_from_funcdef t_funcname_from_funcdef = new Vx.Core.Class_funcname_from_funcdef();

  public static Vx.Core.Type_string f_funcname_from_funcdef(Vx.Core.Type_funcdef funcdef) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_new(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        funcdef.pkgname(),
        Vx.Core.vx_new_string("/"),
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
  public interface Func_if : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_if<T>(T generic_any_1, Vx.Core.Type_boolean clause, T then) where T : Vx.Core.Type_any;
  }

  public class Class_if : Vx.Core.Class_base, Func_if {

    public override Vx.Core.Func_if vx_new(params Object[] vals) {
      Class_if output = new Class_if();
      return output;
    }

    public override Vx.Core.Func_if vx_copy(params Object[] vals) {
      Class_if output = new Class_if();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_if;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_if;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_boolean clause = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any then = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_if(generic_any_1, clause, then);
      return output;
    }

    public T vx_if<T>(T generic_any_1, Vx.Core.Type_boolean clause, T then) where T : Vx.Core.Type_any {
      return Vx.Core.f_if(generic_any_1, clause, then);
    }

  }

  public static Func_if e_if = new Vx.Core.Class_if();
  public static Func_if t_if = new Vx.Core.Class_if();

  public static T f_if<T>(T generic_any_1, Vx.Core.Type_boolean clause, T then) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_if_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_if_1<T>(T generic_any_1, Vx.Core.Type_boolean clause, T thenval, T elseval) where T : Vx.Core.Type_any;
  }

  public class Class_if_1 : Vx.Core.Class_base, Func_if_1 {

    public override Vx.Core.Func_if_1 vx_new(params Object[] vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    public override Vx.Core.Func_if_1 vx_copy(params Object[] vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_if_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_if_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_boolean clause = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any thenval = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any elseval = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_if_1(generic_any_1, clause, thenval, elseval);
      return output;
    }

    public T vx_if_1<T>(T generic_any_1, Vx.Core.Type_boolean clause, T thenval, T elseval) where T : Vx.Core.Type_any {
      return Vx.Core.f_if_1(generic_any_1, clause, thenval, elseval);
    }

  }

  public static Func_if_1 e_if_1 = new Vx.Core.Class_if_1();
  public static Func_if_1 t_if_1 = new Vx.Core.Class_if_1();

  public static T f_if_1<T>(T generic_any_1, Vx.Core.Type_boolean clause, T thenval, T elseval) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function if 2
   * Logical If function
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func if)
   */
  public interface Func_if_2 : Vx.Core.Func_any_from_any {
    public T vx_if_2<T>(T generic_any_1, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any;
  }

  public class Class_if_2 : Vx.Core.Class_base, Func_if_2 {

    public override Vx.Core.Func_if_2 vx_new(params Object[] vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    public override Vx.Core.Func_if_2 vx_copy(params Object[] vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_if_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_if_2;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_thenelselist inputval = (Vx.Core.Type_thenelselist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_if_2(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_thenelselist thenelselist = Vx.Core.f_any_from_any(Vx.Core.t_thenelselist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_if_2(generic_any_1, thenelselist);
      return output;
    }

    public T vx_if_2<T>(T generic_any_1, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any {
      return Vx.Core.f_if_2(generic_any_1, thenelselist);
    }

  }

  public static Func_if_2 e_if_2 = new Vx.Core.Class_if_2();
  public static Func_if_2 t_if_2 = new Vx.Core.Class_if_2();

  public static T f_if_2<T>(T generic_any_1, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function int_from_func
   * Function Type returning int with any parameters
   * @return {int}
   * (func int<-func)
   */
  public interface Func_int_from_func : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_int_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn);
    public Vx.Core.Type_int vx_int_from_func();
  }

  public class Class_int_from_func : Vx.Core.Class_base, Func_int_from_func {

    public override Vx.Core.Func_int_from_func vx_new(params Object[] vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    public override Vx.Core.Func_int_from_func vx_copy(params Object[] vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "int<-func", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_int_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_from_func;
    }

    public Vx.Core.Class_any_from_func.IFn? fn = null;

    public Vx.Core.Func_int_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn) {
      Class_int_from_func output = new Class_int_from_func();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Core.f_int_from_func();
      return output;
    }

    public Vx.Core.Type_int vx_int_from_func() {
      return Vx.Core.f_int_from_func();
    }

  }

  public static Func_int_from_func e_int_from_func = new Vx.Core.Class_int_from_func();
  public static Func_int_from_func t_int_from_func = new Vx.Core.Class_int_from_func();

  public static Vx.Core.Type_int f_int_from_func() {
    Vx.Core.Type_int output = Vx.Core.e_int;
    return output;
  }

  /**
   * @function int_from_string
   * Function Type converting string to int
   * @param  {string} val
   * @return {int}
   * (func int<-string)
   */
  public interface Func_int_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_int_from_string(Vx.Core.Type_string val);
  }

  public class Class_int_from_string : Vx.Core.Class_base, Func_int_from_string {

    public override Vx.Core.Func_int_from_string vx_new(params Object[] vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    public override Vx.Core.Func_int_from_string vx_copy(params Object[] vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "int<-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_int_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_int_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string val = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_int_from_string(val);
      return output;
    }

    public Vx.Core.Type_int vx_int_from_string(Vx.Core.Type_string val) {
      return Vx.Core.f_int_from_string(val);
    }

  }

  public static Func_int_from_string e_int_from_string = new Vx.Core.Class_int_from_string();
  public static Func_int_from_string t_int_from_string = new Vx.Core.Class_int_from_string();

  public static Vx.Core.Type_int f_int_from_string(Vx.Core.Type_string val) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_switch(
      Vx.Core.t_int,
      val,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Core.vx_new_string("notanumber"),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.c_notanumber;
          })
        ),
        Vx.Core.f_case_1(
          Vx.Core.vx_new_string("infinity"),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.c_infinity;
          })
        ),
        Vx.Core.f_case_1(
          Vx.Core.vx_new_string("neginfinity"),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.c_neginfinity;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {int intresult = 0;
            string strval = val.vx_string();
            try {
              float floatresult = float.Parse(strval);
              intresult = (int)floatresult;
              return Vx.Core.vx_new_int(intresult);
            } catch (Exception) {
              return Vx.Core.c_notanumber;
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
  public interface Func_is_empty : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_empty(Vx.Core.Type_string text);
  }

  public class Class_is_empty : Vx.Core.Class_base, Func_is_empty {

    public override Vx.Core.Func_is_empty vx_new(params Object[] vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    public override Vx.Core.Func_is_empty vx_copy(params Object[] vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_empty;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_empty;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_empty(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_empty(text);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_empty(Vx.Core.Type_string text) {
      return Vx.Core.f_is_empty(text);
    }

  }

  public static Func_is_empty e_is_empty = new Vx.Core.Class_is_empty();
  public static Func_is_empty t_is_empty = new Vx.Core.Class_is_empty();

  public static Vx.Core.Type_boolean f_is_empty(Vx.Core.Type_string text) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function is_empty 1
   * Returns true if an value is empty
   * @param  {any} value
   * @return {boolean}
   * (func is-empty)
   */
  public interface Func_is_empty_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_empty_1(Vx.Core.Type_any value);
  }

  public class Class_is_empty_1 : Vx.Core.Class_base, Func_is_empty_1 {

    public override Vx.Core.Func_is_empty_1 vx_new(params Object[] vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    public override Vx.Core.Func_is_empty_1 vx_copy(params Object[] vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_empty_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_empty_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_empty_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_empty_1(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_empty_1(Vx.Core.Type_any value) {
      return Vx.Core.f_is_empty_1(value);
    }

  }

  public static Func_is_empty_1 e_is_empty_1 = new Vx.Core.Class_is_empty_1();
  public static Func_is_empty_1 t_is_empty_1 = new Vx.Core.Class_is_empty_1();

  public static Vx.Core.Type_boolean f_is_empty_1(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
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
  public interface Func_is_endswith : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_is_endswith(Vx.Core.Type_string text, Vx.Core.Type_string find);
  }

  public class Class_is_endswith : Vx.Core.Class_base, Func_is_endswith {

    public override Vx.Core.Func_is_endswith vx_new(params Object[] vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    public override Vx.Core.Func_is_endswith vx_copy(params Object[] vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-endswith", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_endswith;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_endswith;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_is_endswith(text, find);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_endswith(Vx.Core.Type_string text, Vx.Core.Type_string find) {
      return Vx.Core.f_is_endswith(text, find);
    }

  }

  public static Func_is_endswith e_is_endswith = new Vx.Core.Class_is_endswith();
  public static Func_is_endswith t_is_endswith = new Vx.Core.Class_is_endswith();

  public static Vx.Core.Type_boolean f_is_endswith(Vx.Core.Type_string text, Vx.Core.Type_string find) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    string stext = text.vx_string();
    string sfind = find.vx_string();
    if (stext.EndsWith(sfind)) {
      output = Vx.Core.c_true;
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
  public interface Func_is_float : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_float(Vx.Core.Type_any value);
  }

  public class Class_is_float : Vx.Core.Class_base, Func_is_float {

    public override Vx.Core.Func_is_float vx_new(params Object[] vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    public override Vx.Core.Func_is_float vx_copy(params Object[] vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-float", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_float;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_float;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_float(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_float(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_float(Vx.Core.Type_any value) {
      return Vx.Core.f_is_float(value);
    }

  }

  public static Func_is_float e_is_float = new Vx.Core.Class_is_float();
  public static Func_is_float t_is_float = new Vx.Core.Class_is_float();

  public static Vx.Core.Type_boolean f_is_float(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function is_func
   * Returns true if val is a function.
   * @param  {any} val
   * @return {boolean}
   * (func is-func)
   */
  public interface Func_is_func : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_func(Vx.Core.Type_any val);
  }

  public class Class_is_func : Vx.Core.Class_base, Func_is_func {

    public override Vx.Core.Func_is_func vx_new(params Object[] vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    public override Vx.Core.Func_is_func vx_copy(params Object[] vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-func", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_func;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_func(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_func(val);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_func(Vx.Core.Type_any val) {
      return Vx.Core.f_is_func(val);
    }

  }

  public static Func_is_func e_is_func = new Vx.Core.Class_is_func();
  public static Func_is_func t_is_func = new Vx.Core.Class_is_func();

  public static Vx.Core.Type_boolean f_is_func(Vx.Core.Type_any val) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function is_int
   * Returns true if the value is an integer.
   * @param  {any} value
   * @return {boolean}
   * (func is-int)
   */
  public interface Func_is_int : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_int(Vx.Core.Type_any value);
  }

  public class Class_is_int : Vx.Core.Class_base, Func_is_int {

    public override Vx.Core.Func_is_int vx_new(params Object[] vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    public override Vx.Core.Func_is_int vx_copy(params Object[] vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-int", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_int;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_int;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_int(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_int(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_int(Vx.Core.Type_any value) {
      return Vx.Core.f_is_int(value);
    }

  }

  public static Func_is_int e_is_int = new Vx.Core.Class_is_int();
  public static Func_is_int t_is_int = new Vx.Core.Class_is_int();

  public static Vx.Core.Type_boolean f_is_int(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function is_number
   * Return true if val is a number
   * @param  {any} value
   * @return {boolean}
   * (func is-number)
   */
  public interface Func_is_number : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_number(Vx.Core.Type_any value);
  }

  public class Class_is_number : Vx.Core.Class_base, Func_is_number {

    public override Vx.Core.Func_is_number vx_new(params Object[] vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    public override Vx.Core.Func_is_number vx_copy(params Object[] vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-number", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_number;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_number;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_number(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_number(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_number(Vx.Core.Type_any value) {
      return Vx.Core.f_is_number(value);
    }

  }

  public static Func_is_number e_is_number = new Vx.Core.Class_is_number();
  public static Func_is_number t_is_number = new Vx.Core.Class_is_number();

  public static Vx.Core.Type_boolean f_is_number(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_switch(
      Vx.Core.t_boolean,
      Vx.Core.f_typename_from_any(value),
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case(
          Vx.Core.f_new(
            Vx.Core.t_list,
            Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string("vx/core/decimal"),
              Vx.Core.vx_new_string("vx/core/float"),
              Vx.Core.vx_new_string("vx/core/int"),
              Vx.Core.vx_new_string("vx/core/number")
            )
          ),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(true);
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_boolean(false);
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
  public interface Func_is_pass_from_permission : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_is_pass_from_permission(Vx.Core.Type_context context, Vx.Core.Type_permission permission);
  }

  public class Class_is_pass_from_permission : Vx.Core.Class_base, Func_is_pass_from_permission {

    public override Vx.Core.Func_is_pass_from_permission vx_new(params Object[] vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    public override Vx.Core.Func_is_pass_from_permission vx_copy(params Object[] vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "is-pass<-permission", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_is_pass_from_permission;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_pass_from_permission;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_permission inputval = (Vx.Core.Type_permission)value;
      Vx.Core.Type_any outputval = Vx.Core.f_is_pass_from_permission(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_permission permission = Vx.Core.f_any_from_any(Vx.Core.t_permission, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_is_pass_from_permission(context, permission);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_pass_from_permission(Vx.Core.Type_context context, Vx.Core.Type_permission permission) {
      return Vx.Core.f_is_pass_from_permission(context, permission);
    }

  }

  public static Func_is_pass_from_permission e_is_pass_from_permission = new Vx.Core.Class_is_pass_from_permission();
  public static Func_is_pass_from_permission t_is_pass_from_permission = new Vx.Core.Class_is_pass_from_permission();

  public static Vx.Core.Type_boolean f_is_pass_from_permission(Vx.Core.Type_context context, Vx.Core.Type_permission permission) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string id = permission.id();
        Vx.Core.Type_permission lookup = Vx.Core.f_permission_from_id_context(context, id);
        Vx.Core.Type_any output_1 = Vx.Core.f_eq(lookup, permission);
        return output_1;
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
  public interface Func_last_from_list : Vx.Core.Func_any_from_any {
    public T vx_last_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list;
  }

  public class Class_last_from_list : Vx.Core.Class_base, Func_last_from_list {

    public override Vx.Core.Func_last_from_list vx_new(params Object[] vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    public override Vx.Core.Func_last_from_list vx_copy(params Object[] vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "last<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_last_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_last_from_list;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_last_from_list(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_last_from_list(generic_any_1, values);
      return output;
    }

    public T vx_last_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
      return Vx.Core.f_last_from_list(generic_any_1, values);
    }

  }

  public static Func_last_from_list e_last_from_list = new Vx.Core.Class_last_from_list();
  public static Func_last_from_list t_last_from_list = new Vx.Core.Class_last_from_list();

  public static T f_last_from_list<T, X>(T generic_any_1, X values) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_let(
      generic_any_1,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int len = Vx.Core.f_length_1(values);
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_list(generic_any_1, values, len);
        return output_1;
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
  public interface Func_length : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_length(Vx.Core.Type_string text);
  }

  public class Class_length : Vx.Core.Class_base, Func_length {

    public override Vx.Core.Func_length vx_new(params Object[] vals) {
      Class_length output = new Class_length();
      return output;
    }

    public override Vx.Core.Func_length vx_copy(params Object[] vals) {
      Class_length output = new Class_length();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_length;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_length;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_length(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_length(text);
      return output;
    }

    public Vx.Core.Type_int vx_length(Vx.Core.Type_string text) {
      return Vx.Core.f_length(text);
    }

  }

  public static Func_length e_length = new Vx.Core.Class_length();
  public static Func_length t_length = new Vx.Core.Class_length();

  public static Vx.Core.Type_int f_length(Vx.Core.Type_string text) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    return output;
  }

  /**
   * @function length 1
   * Returns the currently used size/length of a list
   * @param  {list-1} values
   * @return {int}
   * (func length)
   */
  public interface Func_length_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_length_1(Vx.Core.Type_list values);
  }

  public class Class_length_1 : Vx.Core.Class_base, Func_length_1 {

    public override Vx.Core.Func_length_1 vx_new(params Object[] vals) {
      Class_length_1 output = new Class_length_1();
      return output;
    }

    public override Vx.Core.Func_length_1 vx_copy(params Object[] vals) {
      Class_length_1 output = new Class_length_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_length_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_length_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_length_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_length_1(values);
      return output;
    }

    public Vx.Core.Type_int vx_length_1(Vx.Core.Type_list values) {
      return Vx.Core.f_length_1(values);
    }

  }

  public static Func_length_1 e_length_1 = new Vx.Core.Class_length_1();
  public static Func_length_1 t_length_1 = new Vx.Core.Class_length_1();

  public static Vx.Core.Type_int f_length_1(Vx.Core.Type_list values) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    return output;
  }

  /**
   * @function length 2
   * Returns the length of the given map.
   * @param  {map-1} valuemap
   * @return {int}
   * (func length)
   */
  public interface Func_length_2 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_length_2(Vx.Core.Type_map valuemap);
  }

  public class Class_length_2 : Vx.Core.Class_base, Func_length_2 {

    public override Vx.Core.Func_length_2 vx_new(params Object[] vals) {
      Class_length_2 output = new Class_length_2();
      return output;
    }

    public override Vx.Core.Func_length_2 vx_copy(params Object[] vals) {
      Class_length_2 output = new Class_length_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "length", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_length_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_length_2;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_map inputval = (Vx.Core.Type_map)value;
      Vx.Core.Type_any outputval = Vx.Core.f_length_2(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_length_2(valuemap);
      return output;
    }

    public Vx.Core.Type_int vx_length_2(Vx.Core.Type_map valuemap) {
      return Vx.Core.f_length_2(valuemap);
    }

  }

  public static Func_length_2 e_length_2 = new Vx.Core.Class_length_2();
  public static Func_length_2 t_length_2 = new Vx.Core.Class_length_2();

  public static Vx.Core.Type_int f_length_2(Vx.Core.Type_map valuemap) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_length_1(
      Vx.Core.f_stringlist_from_map(valuemap)
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
  public interface Func_let : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_let<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any;
  }

  public class Class_let : Vx.Core.Class_base, Func_let {

    public override Vx.Core.Func_let vx_new(params Object[] vals) {
      Class_let output = new Class_let();
      return output;
    }

    public override Vx.Core.Func_let vx_copy(params Object[] vals) {
      Class_let output = new Class_let();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "let", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_let;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_let;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_let(generic_any_1, fn_any);
      return output;
    }

    public T vx_let<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
      return Vx.Core.f_let(generic_any_1, fn_any);
    }

  }

  public static Func_let e_let = new Vx.Core.Class_let();
  public static Func_let t_let = new Vx.Core.Class_let();

  public static T f_let<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_let_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Task<T> vx_let_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any_async) where T : Vx.Core.Type_any;
  }

  public class Class_let_async : Vx.Core.Class_base, Func_let_async {

    public override Vx.Core.Func_let_async vx_new(params Object[] vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    public override Vx.Core.Func_let_async vx_copy(params Object[] vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "let-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_let_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_let_async;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_any_async = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_let_async(generic_any_1, fn_any_async);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_let_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any_async) where T : Vx.Core.Type_any {
      return Vx.Core.f_let_async(generic_any_1, fn_any_async);
    }

  }

  public static Func_let_async e_let_async = new Vx.Core.Class_let_async();
  public static Func_let_async t_let_async = new Vx.Core.Class_let_async();

  public static Task<T> f_let_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any_async) where T : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function list_join_from_list
   * Returns a list by joining the valid values in each value list
   * @param  {list-2} values
   * @return {list-1}
   * (func list-join<-list)
   */
  public interface Func_list_join_from_list : Vx.Core.Func_any_from_any {
    public X vx_list_join_from_list<X, Y>(X generic_any_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_join_from_list : Vx.Core.Class_base, Func_list_join_from_list {

    public override Vx.Core.Func_list_join_from_list vx_new(params Object[] vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    public override Vx.Core.Func_list_join_from_list vx_copy(params Object[] vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_join_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_join_from_list;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_list_join_from_list(Vx.Core.t_list, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_list_join_from_list(generic_list_1, values);
      return output;
    }

    public X vx_list_join_from_list<X, Y>(X generic_list_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_join_from_list(generic_list_1, values);
    }

  }

  public static Func_list_join_from_list e_list_join_from_list = new Vx.Core.Class_list_join_from_list();
  public static Func_list_join_from_list t_list_join_from_list = new Vx.Core.Class_list_join_from_list();

  public static X f_list_join_from_list<X, Y>(X generic_list_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    output = Vx.Core.f_list_join_from_list_1(
      generic_list_1,
      values,
      Vx.Core.t_any_from_any.vx_fn_new((value_any) => {
        Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, value_any);
        Vx.Core.Type_any output_1 = value;
        return output_1;
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
  public interface Func_list_join_from_list_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public X vx_list_join_from_list_1<X, Y>(X generic_any_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_join_from_list_1 : Vx.Core.Class_base, Func_list_join_from_list_1 {

    public override Vx.Core.Func_list_join_from_list_1 vx_new(params Object[] vals) {
      Class_list_join_from_list_1 output = new Class_list_join_from_list_1();
      return output;
    }

    public override Vx.Core.Func_list_join_from_list_1 vx_copy(params Object[] vals) {
      Class_list_join_from_list_1 output = new Class_list_join_from_list_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_join_from_list_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_join_from_list_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_any fn_any_from_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_list_join_from_list_1(generic_list_1, values, fn_any_from_any);
      return output;
    }

    public X vx_list_join_from_list_1<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_join_from_list_1(generic_list_1, values, fn_any_from_any);
    }

  }

  public static Func_list_join_from_list_1 e_list_join_from_list_1 = new Vx.Core.Class_list_join_from_list_1();
  public static Func_list_join_from_list_1 t_list_join_from_list_1 = new Vx.Core.Class_list_join_from_list_1();

  public static X f_list_join_from_list_1<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_list
   * Return a list with allowed values from another list
   * @param  {list-2} values
   * @return {list-1}
   * (func list<-list)
   */
  public interface Func_list_from_list : Vx.Core.Func_any_from_any {
    public X vx_list_from_list<X, Y>(X generic_any_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_from_list : Vx.Core.Class_base, Func_list_from_list {

    public override Vx.Core.Func_list_from_list vx_new(params Object[] vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    public override Vx.Core.Func_list_from_list vx_copy(params Object[] vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_list;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_list_from_list(Vx.Core.t_list, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_list_from_list(generic_list_1, values);
      return output;
    }

    public X vx_list_from_list<X, Y>(X generic_list_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_from_list(generic_list_1, values);
    }

  }

  public static Func_list_from_list e_list_from_list = new Vx.Core.Class_list_from_list();
  public static Func_list_from_list t_list_from_list = new Vx.Core.Class_list_from_list();

  public static X f_list_from_list<X, Y>(X generic_list_1, Y values) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    output = Vx.Core.f_list_from_list_1(
      generic_list_1,
      values,
      Vx.Core.t_any_from_any.vx_fn_new((value_any) => {
        Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, value_any);
        Vx.Core.Type_any output_1 = value;
        return output_1;
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
  public interface Func_list_from_list_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public X vx_list_from_list_1<X, Y>(X generic_any_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_from_list_1 : Vx.Core.Class_base, Func_list_from_list_1 {

    public override Vx.Core.Func_list_from_list_1 vx_new(params Object[] vals) {
      Class_list_from_list_1 output = new Class_list_from_list_1();
      return output;
    }

    public override Vx.Core.Func_list_from_list_1 vx_copy(params Object[] vals) {
      Class_list_from_list_1 output = new Class_list_from_list_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_list_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_list_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_any fn_any_from_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_list_from_list_1(generic_list_1, values, fn_any_from_any);
      return output;
    }

    public X vx_list_from_list_1<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_from_list_1(generic_list_1, values, fn_any_from_any);
    }

  }

  public static Func_list_from_list_1 e_list_from_list_1 = new Vx.Core.Class_list_from_list_1();
  public static Func_list_from_list_1 t_list_from_list_1 = new Vx.Core.Class_list_from_list_1();

  public static X f_list_from_list_1<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any fn_any_from_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
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
  public interface Func_list_from_list_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Task<X> vx_list_from_list_async<X, Y>(X generic_any_1, Y values, Vx.Core.Func_any_from_any_async fn_any_from_any_async) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_from_list_async : Vx.Core.Class_base, Func_list_from_list_async {

    public override Vx.Core.Func_list_from_list_async vx_new(params Object[] vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    public override Vx.Core.Func_list_from_list_async vx_copy(params Object[] vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_list_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_list_async;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_any_async fn_any_from_any_async = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Core.Type_list> future = Vx.Core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<X> vx_list_from_list_async<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any_async fn_any_from_any_async) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
    }

  }

  public static Func_list_from_list_async e_list_from_list_async = new Vx.Core.Class_list_from_list_async();
  public static Func_list_from_list_async t_list_from_list_async = new Vx.Core.Class_list_from_list_async();

  public static Task<X> f_list_from_list_async<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_any_async fn_any_from_any_async) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    Task<X> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_list_1));
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
  public interface Func_list_from_list_intany : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public X vx_list_from_list_intany<X, Y>(X generic_any_1, Y values, Vx.Core.Func_any_from_int_any fn_any_from_int_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list;
  }

  public class Class_list_from_list_intany : Vx.Core.Class_base, Func_list_from_list_intany {

    public override Vx.Core.Func_list_from_list_intany vx_new(params Object[] vals) {
      Class_list_from_list_intany output = new Class_list_from_list_intany();
      return output;
    }

    public override Vx.Core.Func_list_from_list_intany vx_copy(params Object[] vals) {
      Class_list_from_list_intany output = new Class_list_from_list_intany();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list-intany", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_list_intany;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_list_intany;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list values = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_int_any fn_any_from_int_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_int_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_list_from_list_intany(generic_list_1, values, fn_any_from_int_any);
      return output;
    }

    public X vx_list_from_list_intany<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_int_any fn_any_from_int_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
      return Vx.Core.f_list_from_list_intany(generic_list_1, values, fn_any_from_int_any);
    }

  }

  public static Func_list_from_list_intany e_list_from_list_intany = new Vx.Core.Class_list_from_list_intany();
  public static Func_list_from_list_intany t_list_from_list_intany = new Vx.Core.Class_list_from_list_intany();

  public static X f_list_from_list_intany<X, Y>(X generic_list_1, Y values, Vx.Core.Func_any_from_int_any fn_any_from_int_any) where X : Vx.Core.Type_list where Y : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_map
   * Returns a list of allowed values from a map.
   * @param  {map-2} valuemap
   * @return {list-1}
   * (func list<-map)
   */
  public interface Func_list_from_map : Vx.Core.Func_any_from_any {
    public X vx_list_from_map<O, X>(X generic_any_1, O valuemap) where O : Vx.Core.Type_map where X : Vx.Core.Type_list;
  }

  public class Class_list_from_map : Vx.Core.Class_base, Func_list_from_map {

    public override Vx.Core.Func_list_from_map vx_new(params Object[] vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    public override Vx.Core.Func_list_from_map vx_copy(params Object[] vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_map;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_map;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_map inputval = (Vx.Core.Type_map)value;
      Vx.Core.Type_any outputval = Vx.Core.f_list_from_map(Vx.Core.t_list, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_list_from_map(generic_list_1, valuemap);
      return output;
    }

    public X vx_list_from_map<O, X>(X generic_list_1, O valuemap) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
      return Vx.Core.f_list_from_map(generic_list_1, valuemap);
    }

  }

  public static Func_list_from_map e_list_from_map = new Vx.Core.Class_list_from_map();
  public static Func_list_from_map t_list_from_map = new Vx.Core.Class_list_from_map();

  public static X f_list_from_map<O, X>(X generic_list_1, O valuemap) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    output = Vx.Core.f_list_from_map_1(
      generic_list_1,
      valuemap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, value_any);
        Vx.Core.Type_any output_1 = value;
        return output_1;
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
  public interface Func_list_from_map_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public X vx_list_from_map_1<O, X>(X generic_any_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where O : Vx.Core.Type_map where X : Vx.Core.Type_list;
  }

  public class Class_list_from_map_1 : Vx.Core.Class_base, Func_list_from_map_1 {

    public override Vx.Core.Func_list_from_map_1 vx_new(params Object[] vals) {
      Class_list_from_map_1 output = new Class_list_from_map_1();
      return output;
    }

    public override Vx.Core.Func_list_from_map_1 vx_copy(params Object[] vals) {
      Class_list_from_map_1 output = new Class_list_from_map_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_map_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_map_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_key_value fn_any_from_key_value = Vx.Core.f_any_from_any(Vx.Core.t_any_from_key_value, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_list_from_map_1(generic_list_1, valuemap, fn_any_from_key_value);
      return output;
    }

    public X vx_list_from_map_1<O, X>(X generic_list_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
      return Vx.Core.f_list_from_map_1(generic_list_1, valuemap, fn_any_from_key_value);
    }

  }

  public static Func_list_from_map_1 e_list_from_map_1 = new Vx.Core.Class_list_from_map_1();
  public static Func_list_from_map_1 t_list_from_map_1 = new Vx.Core.Class_list_from_map_1();

  public static X f_list_from_map_1<O, X>(X generic_list_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
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
  public interface Func_list_from_map_async : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Task<X> vx_list_from_map_async<O, X>(X generic_any_1, O valuemap, Vx.Core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : Vx.Core.Type_map where X : Vx.Core.Type_list;
  }

  public class Class_list_from_map_async : Vx.Core.Class_base, Func_list_from_map_async {

    public override Vx.Core.Func_list_from_map_async vx_new(params Object[] vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    public override Vx.Core.Func_list_from_map_async vx_copy(params Object[] vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-map-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_list_from_map_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_map_async;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_key_value_async fn_any_from_key_value_async = Vx.Core.f_any_from_any(Vx.Core.t_any_from_key_value_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Core.Type_list> future = Vx.Core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<X> vx_list_from_map_async<O, X>(X generic_list_1, O valuemap, Vx.Core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
      return Vx.Core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
    }

  }

  public static Func_list_from_map_async e_list_from_map_async = new Vx.Core.Class_list_from_map_async();
  public static Func_list_from_map_async t_list_from_map_async = new Vx.Core.Class_list_from_map_async();

  public static Task<X> f_list_from_map_async<O, X>(X generic_list_1, O valuemap, Vx.Core.Func_any_from_key_value_async fn_any_from_key_value_async) where O : Vx.Core.Type_map where X : Vx.Core.Type_list {
    Task<X> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_type
   * Create an empty list from a type. Used internally for default lists
   * @param  {any} type
   * @return {any}
   * (func list<-type)
   */
  public interface Func_list_from_type : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_list_from_type(Vx.Core.Type_any type);
  }

  public class Class_list_from_type : Vx.Core.Class_base, Func_list_from_type {

    public override Vx.Core.Func_list_from_type vx_new(params Object[] vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    public override Vx.Core.Func_list_from_type vx_copy(params Object[] vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "list<-type", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_list_from_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_list_from_type;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_list_from_type(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_list_from_type(type);
      return output;
    }

    public Vx.Core.Type_any vx_list_from_type(Vx.Core.Type_any type) {
      return Vx.Core.f_list_from_type(type);
    }

  }

  public static Func_list_from_type e_list_from_type = new Vx.Core.Class_list_from_type();
  public static Func_list_from_type t_list_from_type = new Vx.Core.Class_list_from_type();

  public static Vx.Core.Type_any f_list_from_type(Vx.Core.Type_any type) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    return output;
  }

  /**
   * @function log
   * Writes a value to the console.
   * @param  {any} value
   * @return {any}
   * (func log)
   */
  public interface Func_log : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_log(Vx.Core.Type_any value);
  }

  public class Class_log : Vx.Core.Class_base, Func_log {

    public override Vx.Core.Func_log vx_new(params Object[] vals) {
      Class_log output = new Class_log();
      return output;
    }

    public override Vx.Core.Func_log vx_copy(params Object[] vals) {
      Class_log output = new Class_log();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_log;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_log;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_log(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_log(value);
      return output;
    }

    public Vx.Core.Type_any vx_log(Vx.Core.Type_any value) {
      return Vx.Core.f_log(value);
    }

  }

  public static Func_log e_log = new Vx.Core.Class_log();
  public static Func_log t_log = new Vx.Core.Class_log();

  public static Vx.Core.Type_any f_log(Vx.Core.Type_any value) {
    Vx.Core.Type_any output = Vx.Core.e_any;
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
  public interface Func_log_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_log_1<T>(T generic_any_1, Vx.Core.Type_string text, T value) where T : Vx.Core.Type_any;
  }

  public class Class_log_1 : Vx.Core.Class_base, Func_log_1 {

    public override Vx.Core.Func_log_1 vx_new(params Object[] vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    public override Vx.Core.Func_log_1 vx_copy(params Object[] vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_log_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_log_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_log_1(generic_any_1, text, value);
      return output;
    }

    public T vx_log_1<T>(T generic_any_1, Vx.Core.Type_string text, T value) where T : Vx.Core.Type_any {
      return Vx.Core.f_log_1(generic_any_1, text, value);
    }

  }

  public static Func_log_1 e_log_1 = new Vx.Core.Class_log_1();
  public static Func_log_1 t_log_1 = new Vx.Core.Class_log_1();

  public static T f_log_1<T>(T generic_any_1, Vx.Core.Type_string text, T value) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function main
   * The default function for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {string}
   * (func main)
   */
  public interface Func_main : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_main(Vx.Core.Type_anylist args);
  }

  public class Class_main : Vx.Core.Class_base, Func_main {

    public override Vx.Core.Func_main vx_new(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override Vx.Core.Func_main vx_copy(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "main", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_main;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_main;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_main(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_main(args);
      return output;
    }

    public Vx.Core.Type_string vx_main(Vx.Core.Type_anylist args) {
      return Vx.Core.f_main(args);
    }

  }

  public static Func_main e_main = new Vx.Core.Class_main();
  public static Func_main t_main = new Vx.Core.Class_main();

  public static Vx.Core.Type_string f_main(Vx.Core.Type_anylist args) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_new(
      Vx.Core.t_string,
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
  public interface Func_map_from_list : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public N vx_map_from_list<N, Y>(N generic_any_1, Y vallist, Vx.Core.Func_any_from_any fn_any_from_any) where N : Vx.Core.Type_map where Y : Vx.Core.Type_list;
  }

  public class Class_map_from_list : Vx.Core.Class_base, Func_map_from_list {

    public override Vx.Core.Func_map_from_list vx_new(params Object[] vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    public override Vx.Core.Func_map_from_list vx_copy(params Object[] vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "map<-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_map_from_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_map_from_list;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map generic_map_1 = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list vallist = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_any fn_any_from_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
      return output;
    }

    public N vx_map_from_list<N, Y>(N generic_map_1, Y vallist, Vx.Core.Func_any_from_any fn_any_from_any) where N : Vx.Core.Type_map where Y : Vx.Core.Type_list {
      return Vx.Core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
    }

  }

  public static Func_map_from_list e_map_from_list = new Vx.Core.Class_map_from_list();
  public static Func_map_from_list t_map_from_list = new Vx.Core.Class_map_from_list();

  public static N f_map_from_list<N, Y>(N generic_map_1, Y vallist, Vx.Core.Func_any_from_any fn_any_from_any) where N : Vx.Core.Type_map where Y : Vx.Core.Type_list {
    N output = Vx.Core.f_empty(generic_map_1);
    return output;
  }

  /**
   * @function map_from_map
   * Return a map with allowed values from another map
   * @param  {map-2} valuemap
   * @return {map-1}
   * (func map<-map)
   */
  public interface Func_map_from_map : Vx.Core.Func_any_from_any {
    public N vx_map_from_map<N, O>(N generic_any_1, O valuemap) where N : Vx.Core.Type_map where O : Vx.Core.Type_map;
  }

  public class Class_map_from_map : Vx.Core.Class_base, Func_map_from_map {

    public override Vx.Core.Func_map_from_map vx_new(params Object[] vals) {
      Class_map_from_map output = new Class_map_from_map();
      return output;
    }

    public override Vx.Core.Func_map_from_map vx_copy(params Object[] vals) {
      Class_map_from_map output = new Class_map_from_map();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "map<-map", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_map_from_map;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_map_from_map;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_map inputval = (Vx.Core.Type_map)value;
      Vx.Core.Type_any outputval = Vx.Core.f_map_from_map(Vx.Core.t_map, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map generic_map_1 = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_map_from_map(generic_map_1, valuemap);
      return output;
    }

    public N vx_map_from_map<N, O>(N generic_map_1, O valuemap) where N : Vx.Core.Type_map where O : Vx.Core.Type_map {
      return Vx.Core.f_map_from_map(generic_map_1, valuemap);
    }

  }

  public static Func_map_from_map e_map_from_map = new Vx.Core.Class_map_from_map();
  public static Func_map_from_map t_map_from_map = new Vx.Core.Class_map_from_map();

  public static N f_map_from_map<N, O>(N generic_map_1, O valuemap) where N : Vx.Core.Type_map where O : Vx.Core.Type_map {
    N output = Vx.Core.f_empty(generic_map_1);
    output = Vx.Core.f_map_from_map_1(
      generic_map_1,
      valuemap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, value_any);
        Vx.Core.Type_any output_1 = value;
        return output_1;
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
  public interface Func_map_from_map_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public N vx_map_from_map_1<N, O>(N generic_any_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where N : Vx.Core.Type_map where O : Vx.Core.Type_map;
  }

  public class Class_map_from_map_1 : Vx.Core.Class_base, Func_map_from_map_1 {

    public override Vx.Core.Func_map_from_map_1 vx_new(params Object[] vals) {
      Class_map_from_map_1 output = new Class_map_from_map_1();
      return output;
    }

    public override Vx.Core.Func_map_from_map_1 vx_copy(params Object[] vals) {
      Class_map_from_map_1 output = new Class_map_from_map_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "map<-map", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_map_from_map_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_map_from_map_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map generic_map_1 = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_map valuemap = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_key_value fn_any_from_key_value = Vx.Core.f_any_from_any(Vx.Core.t_any_from_key_value, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_map_from_map_1(generic_map_1, valuemap, fn_any_from_key_value);
      return output;
    }

    public N vx_map_from_map_1<N, O>(N generic_map_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where N : Vx.Core.Type_map where O : Vx.Core.Type_map {
      return Vx.Core.f_map_from_map_1(generic_map_1, valuemap, fn_any_from_key_value);
    }

  }

  public static Func_map_from_map_1 e_map_from_map_1 = new Vx.Core.Class_map_from_map_1();
  public static Func_map_from_map_1 t_map_from_map_1 = new Vx.Core.Class_map_from_map_1();

  public static N f_map_from_map_1<N, O>(N generic_map_1, O valuemap, Vx.Core.Func_any_from_key_value fn_any_from_key_value) where N : Vx.Core.Type_map where O : Vx.Core.Type_map {
    N output = Vx.Core.f_empty(generic_map_1);
    return output;
  }

  /**
   * @function msg_from_error
   * Returns a msg from error string
   * @param  {string} error
   * @return {msg}
   * (func msg<-error)
   */
  public interface Func_msg_from_error : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_msg vx_msg_from_error(Vx.Core.Type_string error);
  }

  public class Class_msg_from_error : Vx.Core.Class_base, Func_msg_from_error {

    public override Vx.Core.Func_msg_from_error vx_new(params Object[] vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    public override Vx.Core.Func_msg_from_error vx_copy(params Object[] vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
      return e_msg_from_error;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msg_from_error;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_msg_from_error(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string error = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_msg_from_error(error);
      return output;
    }

    public Vx.Core.Type_msg vx_msg_from_error(Vx.Core.Type_string error) {
      return Vx.Core.f_msg_from_error(error);
    }

  }

  public static Func_msg_from_error e_msg_from_error = new Vx.Core.Class_msg_from_error();
  public static Func_msg_from_error t_msg_from_error = new Vx.Core.Class_msg_from_error();

  public static Vx.Core.Type_msg f_msg_from_error(Vx.Core.Type_string error) {
    Vx.Core.Type_msg output = Vx.Core.e_msg;
    output = Vx.Core.f_new(
      Vx.Core.t_msg,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":severity"),
        Vx.Core.c_msg_error,
        Vx.Core.vx_new_string(":text"),
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
  public interface Func_msg_from_error_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_msg vx_msg_from_error_1(Vx.Core.Type_string code, Vx.Core.Type_any detail);
  }

  public class Class_msg_from_error_1 : Vx.Core.Class_base, Func_msg_from_error_1 {

    public override Vx.Core.Func_msg_from_error_1 vx_new(params Object[] vals) {
      Class_msg_from_error_1 output = new Class_msg_from_error_1();
      return output;
    }

    public override Vx.Core.Func_msg_from_error_1 vx_copy(params Object[] vals) {
      Class_msg_from_error_1 output = new Class_msg_from_error_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
      return e_msg_from_error_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msg_from_error_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string code = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any detail = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_msg_from_error_1(code, detail);
      return output;
    }

    public Vx.Core.Type_msg vx_msg_from_error_1(Vx.Core.Type_string code, Vx.Core.Type_any detail) {
      return Vx.Core.f_msg_from_error_1(code, detail);
    }

  }

  public static Func_msg_from_error_1 e_msg_from_error_1 = new Vx.Core.Class_msg_from_error_1();
  public static Func_msg_from_error_1 t_msg_from_error_1 = new Vx.Core.Class_msg_from_error_1();

  public static Vx.Core.Type_msg f_msg_from_error_1(Vx.Core.Type_string code, Vx.Core.Type_any detail) {
    Vx.Core.Type_msg output = Vx.Core.e_msg;
    output = Vx.Core.f_new(
      Vx.Core.t_msg,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        code,
        Vx.Core.vx_new_string(":detail"),
        detail,
        Vx.Core.vx_new_string(":severity"),
        Vx.Core.c_msg_error
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
  public interface Func_msg_from_error_2 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_msg vx_msg_from_error_2(Vx.Core.Type_string path, Vx.Core.Type_string code, Vx.Core.Type_any detail);
  }

  public class Class_msg_from_error_2 : Vx.Core.Class_base, Func_msg_from_error_2 {

    public override Vx.Core.Func_msg_from_error_2 vx_new(params Object[] vals) {
      Class_msg_from_error_2 output = new Class_msg_from_error_2();
      return output;
    }

    public override Vx.Core.Func_msg_from_error_2 vx_copy(params Object[] vals) {
      Class_msg_from_error_2 output = new Class_msg_from_error_2();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        2, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
      return e_msg_from_error_2;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msg_from_error_2;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string path = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string code = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any detail = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_msg_from_error_2(path, code, detail);
      return output;
    }

    public Vx.Core.Type_msg vx_msg_from_error_2(Vx.Core.Type_string path, Vx.Core.Type_string code, Vx.Core.Type_any detail) {
      return Vx.Core.f_msg_from_error_2(path, code, detail);
    }

  }

  public static Func_msg_from_error_2 e_msg_from_error_2 = new Vx.Core.Class_msg_from_error_2();
  public static Func_msg_from_error_2 t_msg_from_error_2 = new Vx.Core.Class_msg_from_error_2();

  public static Vx.Core.Type_msg f_msg_from_error_2(Vx.Core.Type_string path, Vx.Core.Type_string code, Vx.Core.Type_any detail) {
    Vx.Core.Type_msg output = Vx.Core.e_msg;
    output = Vx.Core.f_new(
      Vx.Core.t_msg,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        code,
        Vx.Core.vx_new_string(":path"),
        path,
        Vx.Core.vx_new_string(":severity"),
        Vx.Core.c_msg_error,
        Vx.Core.vx_new_string(":detail"),
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
  public interface Func_msg_from_warning : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_msg vx_msg_from_warning(Vx.Core.Type_string warning);
  }

  public class Class_msg_from_warning : Vx.Core.Class_base, Func_msg_from_warning {

    public override Vx.Core.Func_msg_from_warning vx_new(params Object[] vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    public override Vx.Core.Func_msg_from_warning vx_copy(params Object[] vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-warning", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
      return e_msg_from_warning;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msg_from_warning;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_msg_from_warning(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string warning = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_msg_from_warning(warning);
      return output;
    }

    public Vx.Core.Type_msg vx_msg_from_warning(Vx.Core.Type_string warning) {
      return Vx.Core.f_msg_from_warning(warning);
    }

  }

  public static Func_msg_from_warning e_msg_from_warning = new Vx.Core.Class_msg_from_warning();
  public static Func_msg_from_warning t_msg_from_warning = new Vx.Core.Class_msg_from_warning();

  public static Vx.Core.Type_msg f_msg_from_warning(Vx.Core.Type_string warning) {
    Vx.Core.Type_msg output = Vx.Core.e_msg;
    output = Vx.Core.f_new(
      Vx.Core.t_msg,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":severity"),
        Vx.Core.c_msg_warning,
        Vx.Core.vx_new_string(":text"),
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
  public interface Func_msgblock_from_msgblock_msg : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_msgblock vx_msgblock_from_msgblock_msg(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msg addmsg);
  }

  public class Class_msgblock_from_msgblock_msg : Vx.Core.Class_base, Func_msgblock_from_msgblock_msg {

    public override Vx.Core.Func_msgblock_from_msgblock_msg vx_new(params Object[] vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    public override Vx.Core.Func_msgblock_from_msgblock_msg vx_copy(params Object[] vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msg", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
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
      return e_msgblock_from_msgblock_msg;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msgblock_from_msgblock_msg;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_msgblock origblock = Vx.Core.f_any_from_any(Vx.Core.t_msgblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_msg addmsg = Vx.Core.f_any_from_any(Vx.Core.t_msg, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_msgblock_from_msgblock_msg(origblock, addmsg);
      return output;
    }

    public Vx.Core.Type_msgblock vx_msgblock_from_msgblock_msg(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msg addmsg) {
      return Vx.Core.f_msgblock_from_msgblock_msg(origblock, addmsg);
    }

  }

  public static Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg = new Vx.Core.Class_msgblock_from_msgblock_msg();
  public static Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg = new Vx.Core.Class_msgblock_from_msgblock_msg();

  public static Vx.Core.Type_msgblock f_msgblock_from_msgblock_msg(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msg addmsg) {
    Vx.Core.Type_msgblock output = Vx.Core.e_msgblock;
    output = Vx.Core.f_copy(origblock, Vx.Core.vx_new(Vx.Core.t_anylist,
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
  public interface Func_msgblock_from_msgblock_msgblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_msgblock vx_msgblock_from_msgblock_msgblock(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msgblock addblock);
  }

  public class Class_msgblock_from_msgblock_msgblock : Vx.Core.Class_base, Func_msgblock_from_msgblock_msgblock {

    public override Vx.Core.Func_msgblock_from_msgblock_msgblock vx_new(params Object[] vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    public override Vx.Core.Func_msgblock_from_msgblock_msgblock vx_copy(params Object[] vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msgblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
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
      return e_msgblock_from_msgblock_msgblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_msgblock_from_msgblock_msgblock;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_msgblock origblock = Vx.Core.f_any_from_any(Vx.Core.t_msgblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_msgblock addblock = Vx.Core.f_any_from_any(Vx.Core.t_msgblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
      return output;
    }

    public Vx.Core.Type_msgblock vx_msgblock_from_msgblock_msgblock(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msgblock addblock) {
      return Vx.Core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
    }

  }

  public static Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock = new Vx.Core.Class_msgblock_from_msgblock_msgblock();
  public static Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock = new Vx.Core.Class_msgblock_from_msgblock_msgblock();

  public static Vx.Core.Type_msgblock f_msgblock_from_msgblock_msgblock(Vx.Core.Type_msgblock origblock, Vx.Core.Type_msgblock addblock) {
    Vx.Core.Type_msgblock output = Vx.Core.e_msgblock;
    output = Vx.Core.f_new(
      Vx.Core.t_msgblock,
      Vx.Core.vx_new(Vx.Core.t_anylist,
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
  public interface Func_name_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_name_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_name_from_typedef : Vx.Core.Class_base, Func_name_from_typedef {

    public override Vx.Core.Func_name_from_typedef vx_new(params Object[] vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    public override Vx.Core.Func_name_from_typedef vx_copy(params Object[] vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "name<-typedef", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_name_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_name_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_name_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_name_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_string vx_name_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_name_from_typedef(vtypedef);
    }

  }

  public static Func_name_from_typedef e_name_from_typedef = new Vx.Core.Class_name_from_typedef();
  public static Func_name_from_typedef t_name_from_typedef = new Vx.Core.Class_name_from_typedef();

  public static Vx.Core.Type_string f_name_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_native : Vx.Core.Func_any_from_any {
    public T vx_native<T>(T generic_any_1, Vx.Core.Type_anylist clauses) where T : Vx.Core.Type_any;
  }

  public class Class_native : Vx.Core.Class_base, Func_native {

    public override Vx.Core.Func_native vx_new(params Object[] vals) {
      Class_native output = new Class_native();
      return output;
    }

    public override Vx.Core.Func_native vx_copy(params Object[] vals) {
      Class_native output = new Class_native();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "native", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_native;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_native;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_native(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist clauses = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_native(generic_any_1, clauses);
      return output;
    }

    public T vx_native<T>(T generic_any_1, Vx.Core.Type_anylist clauses) where T : Vx.Core.Type_any {
      return Vx.Core.f_native(generic_any_1, clauses);
    }

  }

  public static Func_native e_native = new Vx.Core.Class_native();
  public static Func_native t_native = new Vx.Core.Class_native();

  public static T f_native<T>(T generic_any_1, Vx.Core.Type_anylist clauses) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function native_from_any
   * Returns native value of value object
   * @param  {any-1} value
   * @return {any}
   * (func native<-any)
   */
  public interface Func_native_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_native_from_any(Vx.Core.Type_any value);
  }

  public class Class_native_from_any : Vx.Core.Class_base, Func_native_from_any {

    public override Vx.Core.Func_native_from_any vx_new(params Object[] vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    public override Vx.Core.Func_native_from_any vx_copy(params Object[] vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "native<-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_native_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_native_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_native_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_native_from_any(value);
      return output;
    }

    public Vx.Core.Type_any vx_native_from_any(Vx.Core.Type_any value) {
      return Vx.Core.f_native_from_any(value);
    }

  }

  public static Func_native_from_any e_native_from_any = new Vx.Core.Class_native_from_any();
  public static Func_native_from_any t_native_from_any = new Vx.Core.Class_native_from_any();

  public static Vx.Core.Type_any f_native_from_any(Vx.Core.Type_any value) {
    Vx.Core.Type_any output = Vx.Core.e_any;
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
  public interface Func_new : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_new<T>(T type, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any;
  }

  public class Class_new : Vx.Core.Class_base, Func_new {

    public override Vx.Core.Func_new vx_new(params Object[] vals) {
      Class_new output = new Class_new();
      return output;
    }

    public override Vx.Core.Func_new vx_copy(params Object[] vals) {
      Class_new output = new Class_new();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "new", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_new;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_new;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist values = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_new(type, values);
      return output;
    }

    public T vx_new<T>(T type, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any {
      return Vx.Core.f_new(type, values);
    }

  }

  public static Func_new e_new = new Vx.Core.Class_new();
  public static Func_new t_new = new Vx.Core.Class_new();

  public static T f_new<T>(T type, Vx.Core.Type_anylist values) where T : Vx.Core.Type_any {
    Vx.Core.Type_any[] arrayany = Vx.Core.arrayany_from_anylist(values);
    object[] arrayobj = (Vx.Core.Type_any[])arrayany;
    T output = (T)(type.vx_new(arrayobj));
    return output;
  }

  /**
   * @function number_from_func
   * Function Type returning number with any parameters
   * @return {number}
   * (func number<-func)
   */
  public interface Func_number_from_func : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_number vx_number_from_func();
  }

  public class Class_number_from_func : Vx.Core.Class_base, Func_number_from_func {

    public override Vx.Core.Func_number_from_func vx_new(params Object[] vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    public override Vx.Core.Func_number_from_func vx_copy(params Object[] vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "number<-func", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int, Vx.Core.t_float, Vx.Core.t_decimal), // allowtypes
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
      return e_number_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_number_from_func;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Core.f_number_from_func();
      return output;
    }

    public Vx.Core.Type_number vx_number_from_func() {
      return Vx.Core.f_number_from_func();
    }

  }

  public static Func_number_from_func e_number_from_func = new Vx.Core.Class_number_from_func();
  public static Func_number_from_func t_number_from_func = new Vx.Core.Class_number_from_func();

  public static Vx.Core.Type_number f_number_from_func() {
    Vx.Core.Type_number output = Vx.Core.e_number;
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
  public interface Func_or : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_or(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2);
  }

  public class Class_or : Vx.Core.Class_base, Func_or {

    public override Vx.Core.Func_or vx_new(params Object[] vals) {
      Class_or output = new Class_or();
      return output;
    }

    public override Vx.Core.Func_or vx_copy(params Object[] vals) {
      Class_or output = new Class_or();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_or;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_or;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_boolean val1 = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_boolean val2 = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_or(val1, val2);
      return output;
    }

    public Vx.Core.Type_boolean vx_or(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2) {
      return Vx.Core.f_or(val1, val2);
    }

  }

  public static Func_or e_or = new Vx.Core.Class_or();
  public static Func_or t_or = new Vx.Core.Class_or();

  public static Vx.Core.Type_boolean f_or(Vx.Core.Type_boolean val1, Vx.Core.Type_boolean val2) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function or 1
   * Returns true if any value is true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func or)
   */
  public interface Func_or_1 : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_or_1(Vx.Core.Type_booleanlist values);
  }

  public class Class_or_1 : Vx.Core.Class_base, Func_or_1 {

    public override Vx.Core.Func_or_1 vx_new(params Object[] vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    public override Vx.Core.Func_or_1 vx_copy(params Object[] vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
        1, // idx
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_or_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_or_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_booleanlist inputval = (Vx.Core.Type_booleanlist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_or_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_booleanlist values = Vx.Core.f_any_from_any(Vx.Core.t_booleanlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_or_1(values);
      return output;
    }

    public Vx.Core.Type_boolean vx_or_1(Vx.Core.Type_booleanlist values) {
      return Vx.Core.f_or_1(values);
    }

  }

  public static Func_or_1 e_or_1 = new Vx.Core.Class_or_1();
  public static Func_or_1 t_or_1 = new Vx.Core.Class_or_1();

  public static Vx.Core.Type_boolean f_or_1(Vx.Core.Type_booleanlist values) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_any_from_list_start_reduce_next(
      Vx.Core.t_boolean,
      values,
      Vx.Core.vx_new_boolean(false),
      Vx.Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) => {
        Vx.Core.Type_boolean reduce = Vx.Core.f_any_from_any(Vx.Core.t_boolean, reduce_any);
        Vx.Core.Type_boolean current = Vx.Core.f_any_from_any(Vx.Core.t_boolean, current_any);
        Vx.Core.Type_boolean next = Vx.Core.f_any_from_any(Vx.Core.t_boolean, next_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_or(
            reduce,
            Vx.Core.f_or(current, next)
          );
        return output_1;
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
  public interface Func_package_global_from_name : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_package vx_package_global_from_name(Vx.Core.Type_string name);
  }

  public class Class_package_global_from_name : Vx.Core.Class_base, Func_package_global_from_name {

    public override Vx.Core.Func_package_global_from_name vx_new(params Object[] vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    public override Vx.Core.Func_package_global_from_name vx_copy(params Object[] vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "package-global<-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "package", // name
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
      return e_package_global_from_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_package_global_from_name;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_package_global_from_name(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_package_global_from_name(name);
      return output;
    }

    public Vx.Core.Type_package vx_package_global_from_name(Vx.Core.Type_string name) {
      return Vx.Core.f_package_global_from_name(name);
    }

  }

  public static Func_package_global_from_name e_package_global_from_name = new Vx.Core.Class_package_global_from_name();
  public static Func_package_global_from_name t_package_global_from_name = new Vx.Core.Class_package_global_from_name();

  public static Vx.Core.Type_package f_package_global_from_name(Vx.Core.Type_string name) {
    Vx.Core.Type_package output = Vx.Core.e_package;
    output = Vx.Core.f_any_from_map(
      Vx.Core.t_package,
      Vx.Core.c_global.packagemap(),
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
  public interface Func_packagename_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_packagename_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_packagename_from_typedef : Vx.Core.Class_base, Func_packagename_from_typedef {

    public override Vx.Core.Func_packagename_from_typedef vx_new(params Object[] vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    public override Vx.Core.Func_packagename_from_typedef vx_copy(params Object[] vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "packagename<-typedef", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_packagename_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_packagename_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_packagename_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_packagename_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_string vx_packagename_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_packagename_from_typedef(vtypedef);
    }

  }

  public static Func_packagename_from_typedef e_packagename_from_typedef = new Vx.Core.Class_packagename_from_typedef();
  public static Func_packagename_from_typedef t_packagename_from_typedef = new Vx.Core.Class_packagename_from_typedef();

  public static Vx.Core.Type_string f_packagename_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_path_from_context_path : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_string vx_path_from_context_path(Vx.Core.Type_context context, Vx.Core.Type_string path);
  }

  public class Class_path_from_context_path : Vx.Core.Class_base, Func_path_from_context_path {

    public override Vx.Core.Func_path_from_context_path vx_new(params Object[] vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    public override Vx.Core.Func_path_from_context_path vx_copy(params Object[] vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "path<-context-path", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_path_from_context_path;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_path_from_context_path;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_path_from_context_path(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string path = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_path_from_context_path(context, path);
      return output;
    }

    public Vx.Core.Type_string vx_path_from_context_path(Vx.Core.Type_context context, Vx.Core.Type_string path) {
      return Vx.Core.f_path_from_context_path(context, path);
    }

  }

  public static Func_path_from_context_path e_path_from_context_path = new Vx.Core.Class_path_from_context_path();
  public static Func_path_from_context_path t_path_from_context_path = new Vx.Core.Class_path_from_context_path();

  public static Vx.Core.Type_string f_path_from_context_path(Vx.Core.Type_context context, Vx.Core.Type_string path) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_path_from_setting_path(
      Vx.Core.f_setting_from_context(context),
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
  public interface Func_path_from_setting_path : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_path_from_setting_path(Vx.Core.Type_setting session, Vx.Core.Type_string path);
  }

  public class Class_path_from_setting_path : Vx.Core.Class_base, Func_path_from_setting_path {

    public override Vx.Core.Func_path_from_setting_path vx_new(params Object[] vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    public override Vx.Core.Func_path_from_setting_path vx_copy(params Object[] vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "path<-setting-path", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_path_from_setting_path;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_path_from_setting_path;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_setting session = Vx.Core.f_any_from_any(Vx.Core.t_setting, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string path = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_path_from_setting_path(session, path);
      return output;
    }

    public Vx.Core.Type_string vx_path_from_setting_path(Vx.Core.Type_setting session, Vx.Core.Type_string path) {
      return Vx.Core.f_path_from_setting_path(session, path);
    }

  }

  public static Func_path_from_setting_path e_path_from_setting_path = new Vx.Core.Class_path_from_setting_path();
  public static Func_path_from_setting_path t_path_from_setting_path = new Vx.Core.Class_path_from_setting_path();

  public static Vx.Core.Type_string f_path_from_setting_path(Vx.Core.Type_setting session, Vx.Core.Type_string path) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function permission_from_id_context
   * Return a permission from context by id
   * @param  {string} id
   * @return {permission}
   * (func permission<-id-context)
   */
  public interface Func_permission_from_id_context : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_permission vx_permission_from_id_context(Vx.Core.Type_context context, Vx.Core.Type_string id);
  }

  public class Class_permission_from_id_context : Vx.Core.Class_base, Func_permission_from_id_context {

    public override Vx.Core.Func_permission_from_id_context vx_new(params Object[] vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    public override Vx.Core.Func_permission_from_id_context vx_copy(params Object[] vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "permission<-id-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "permission", // name
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
      return e_permission_from_id_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_permission_from_id_context;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Core.f_permission_from_id_context(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_permission_from_id_context(context, id);
      return output;
    }

    public Vx.Core.Type_permission vx_permission_from_id_context(Vx.Core.Type_context context, Vx.Core.Type_string id) {
      return Vx.Core.f_permission_from_id_context(context, id);
    }

  }

  public static Func_permission_from_id_context e_permission_from_id_context = new Vx.Core.Class_permission_from_id_context();
  public static Func_permission_from_id_context t_permission_from_id_context = new Vx.Core.Class_permission_from_id_context();

  public static Vx.Core.Type_permission f_permission_from_id_context(Vx.Core.Type_context context, Vx.Core.Type_string id) {
    Vx.Core.Type_permission output = Vx.Core.e_permission;
    output = Vx.Core.f_let(
      Vx.Core.t_permission,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_user user = Vx.Core.f_user_from_context(context);
        Vx.Core.Type_security security = user.security();
        Vx.Core.Type_permissionmap permissionmap = security.permissionmap();
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_map(Vx.Core.t_permission, permissionmap, Vx.Core.vx_new_string(":id"));
        return output_1;
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
  public interface Func_properties_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_argmap vx_properties_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_properties_from_typedef : Vx.Core.Class_base, Func_properties_from_typedef {

    public override Vx.Core.Func_properties_from_typedef vx_new(params Object[] vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    public override Vx.Core.Func_properties_from_typedef vx_copy(params Object[] vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "properties<-typedef", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_arg), // allowtypes
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
      return e_properties_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_properties_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_properties_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_properties_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_argmap vx_properties_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_properties_from_typedef(vtypedef);
    }

  }

  public static Func_properties_from_typedef e_properties_from_typedef = new Vx.Core.Class_properties_from_typedef();
  public static Func_properties_from_typedef t_properties_from_typedef = new Vx.Core.Class_properties_from_typedef();

  public static Vx.Core.Type_argmap f_properties_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_argmap output = Vx.Core.e_argmap;
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
  public interface Func_proplast_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_arg vx_proplast_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_proplast_from_typedef : Vx.Core.Class_base, Func_proplast_from_typedef {

    public override Vx.Core.Func_proplast_from_typedef vx_new(params Object[] vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    public override Vx.Core.Func_proplast_from_typedef vx_copy(params Object[] vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "proplast<-typedef", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "arg", // name
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
      return e_proplast_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_proplast_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_proplast_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_proplast_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_arg vx_proplast_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_proplast_from_typedef(vtypedef);
    }

  }

  public static Func_proplast_from_typedef e_proplast_from_typedef = new Vx.Core.Class_proplast_from_typedef();
  public static Func_proplast_from_typedef t_proplast_from_typedef = new Vx.Core.Class_proplast_from_typedef();

  public static Vx.Core.Type_arg f_proplast_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_arg output = Vx.Core.e_arg;
    output = vtypedef.proplast();
    return output;
  }

  /**
   * @function resolve
   * @param  {any-1} value
   * @return {any-1}
   * (func resolve)
   */
  public interface Func_resolve : Vx.Core.Func_any_from_any {
    public T vx_resolve<T>(T generic_any_1, T value) where T : Vx.Core.Type_any;
  }

  public class Class_resolve : Vx.Core.Class_base, Func_resolve {

    public override Vx.Core.Func_resolve vx_new(params Object[] vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    public override Vx.Core.Func_resolve vx_copy(params Object[] vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_resolve;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_resolve(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_resolve(generic_any_1, value);
      return output;
    }

    public T vx_resolve<T>(T generic_any_1, T value) where T : Vx.Core.Type_any {
      return Vx.Core.f_resolve(generic_any_1, value);
    }

  }

  public static Func_resolve e_resolve = new Vx.Core.Class_resolve();
  public static Func_resolve t_resolve = new Vx.Core.Class_resolve();

  public static T f_resolve<T>(T generic_any_1, T value) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    output = value;
    return output;
  }

  /**
   * @function resolve 1
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func resolve)
   */
  public interface Func_resolve_1 : Vx.Core.Func_any_from_any {
    public T vx_resolve_1<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any;
  }

  public class Class_resolve_1 : Vx.Core.Class_base, Func_resolve_1 {

    public override Vx.Core.Func_resolve_1 vx_new(params Object[] vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    public override Vx.Core.Func_resolve_1 vx_copy(params Object[] vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_resolve_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Func_any_from_func inputval = (Vx.Core.Func_any_from_func)value;
      Vx.Core.Type_any outputval = Vx.Core.f_resolve_1(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_resolve_1(generic_any_1, fn_any);
      return output;
    }

    public T vx_resolve_1<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
      return Vx.Core.f_resolve_1(generic_any_1, fn_any);
    }

  }

  public static Func_resolve_1 e_resolve_1 = new Vx.Core.Class_resolve_1();
  public static Func_resolve_1 t_resolve_1 = new Vx.Core.Class_resolve_1();

  public static T f_resolve_1<T>(T generic_any_1, Vx.Core.Func_any_from_func fn_any) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_resolve_async : Vx.Core.Func_any_from_any_async {
    public Task<T> vx_resolve_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any) where T : Vx.Core.Type_any;
  }

  public class Class_resolve_async : Vx.Core.Class_base, Func_resolve_async {

    public override Vx.Core.Func_resolve_async vx_new(params Object[] vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    public override Vx.Core.Func_resolve_async vx_copy(params Object[] vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_resolve_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_async;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T inputval = Vx.Core.f_any_from_any(generic_any_1, value);
      Task<T> output = Vx.Core.f_async(generic_any_1, inputval);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_any> future = Vx.Core.f_resolve_async(generic_any_1, fn_any);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<T> vx_resolve_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any) where T : Vx.Core.Type_any {
      return Vx.Core.f_resolve_async(generic_any_1, fn_any);
    }

  }

  public static Func_resolve_async e_resolve_async = new Vx.Core.Class_resolve_async();
  public static Func_resolve_async t_resolve_async = new Vx.Core.Class_resolve_async();

  public static Task<T> f_resolve_async<T>(T generic_any_1, Vx.Core.Func_any_from_func_async fn_any) where T : Vx.Core.Type_any {
    Task<T> output = Vx.Core.vx_async_new_completed(Vx.Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function resolve_first
   * Returns the first value that is not nothing
   * @param  {list-1} clauses
   * @return {any-1}
   * (func resolve-first)
   */
  public interface Func_resolve_first : Vx.Core.Func_any_from_any {
    public T vx_resolve_first<T, X>(T generic_any_1, X clauses) where T : Vx.Core.Type_any where X : Vx.Core.Type_list;
  }

  public class Class_resolve_first : Vx.Core.Class_base, Func_resolve_first {

    public override Vx.Core.Func_resolve_first vx_new(params Object[] vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    public override Vx.Core.Func_resolve_first vx_copy(params Object[] vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-first", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_resolve_first;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_first;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_resolve_first(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list clauses = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_resolve_first(generic_any_1, clauses);
      return output;
    }

    public T vx_resolve_first<T, X>(T generic_any_1, X clauses) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
      return Vx.Core.f_resolve_first(generic_any_1, clauses);
    }

  }

  public static Func_resolve_first e_resolve_first = new Vx.Core.Class_resolve_first();
  public static Func_resolve_first t_resolve_first = new Vx.Core.Class_resolve_first();

  public static T f_resolve_first<T, X>(T generic_any_1, X clauses) where T : Vx.Core.Type_any where X : Vx.Core.Type_list {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_first_from_list_any_from_any(
      generic_any_1,
      clauses,
      Vx.Core.t_resolve
    );
    return output;
  }

  /**
   * @function resolve_list
   * @param  {list-1} clauses
   * @return {list-1}
   * (func resolve-list)
   */
  public interface Func_resolve_list : Vx.Core.Func_any_from_any {
    public X vx_resolve_list<X>(X generic_any_1, X clauses) where X : Vx.Core.Type_list;
  }

  public class Class_resolve_list : Vx.Core.Class_base, Func_resolve_list {

    public override Vx.Core.Func_resolve_list vx_new(params Object[] vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    public override Vx.Core.Func_resolve_list vx_copy(params Object[] vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-list", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_resolve_list;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_list;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_list inputval = (Vx.Core.Type_list)value;
      Vx.Core.Type_any outputval = Vx.Core.f_resolve_list(Vx.Core.t_list, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list generic_list_1 = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_list clauses = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_resolve_list(generic_list_1, clauses);
      return output;
    }

    public X vx_resolve_list<X>(X generic_list_1, X clauses) where X : Vx.Core.Type_list {
      return Vx.Core.f_resolve_list(generic_list_1, clauses);
    }

  }

  public static Func_resolve_list e_resolve_list = new Vx.Core.Class_resolve_list();
  public static Func_resolve_list t_resolve_list = new Vx.Core.Class_resolve_list();

  public static X f_resolve_list<X>(X generic_list_1, X clauses) where X : Vx.Core.Type_list {
    X output = Vx.Core.f_empty(generic_list_1);
    output = Vx.Core.f_list_from_list_1(
      generic_list_1,
      clauses,
      Vx.Core.t_resolve
    );
    return output;
  }

  /**
   * @function security_from_context
   * Return security from the given context.
   * @return {security}
   * (func security<-context)
   */
  public interface Func_security_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_security vx_security_from_context(Vx.Core.Type_context context);
  }

  public class Class_security_from_context : Vx.Core.Class_base, Func_security_from_context {

    public override Vx.Core.Func_security_from_context vx_new(params Object[] vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    public override Vx.Core.Func_security_from_context vx_copy(params Object[] vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "security<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      return e_security_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_security_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_security_from_context(context);
      return output;
    }

    public Vx.Core.Type_security vx_security_from_context(Vx.Core.Type_context context) {
      return Vx.Core.f_security_from_context(context);
    }

  }

  public static Func_security_from_context e_security_from_context = new Vx.Core.Class_security_from_context();
  public static Func_security_from_context t_security_from_context = new Vx.Core.Class_security_from_context();

  public static Vx.Core.Type_security f_security_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_security output = Vx.Core.e_security;
    output = Vx.Core.f_security_from_user(
      Vx.Core.f_user_from_context(context)
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
  public interface Func_security_from_user : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_security vx_security_from_user(Vx.Core.Type_user user);
  }

  public class Class_security_from_user : Vx.Core.Class_base, Func_security_from_user {

    public override Vx.Core.Func_security_from_user vx_new(params Object[] vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    public override Vx.Core.Func_security_from_user vx_copy(params Object[] vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "security<-user", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      return e_security_from_user;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_security_from_user;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_user inputval = (Vx.Core.Type_user)value;
      Vx.Core.Type_any outputval = Vx.Core.f_security_from_user(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_user user = Vx.Core.f_any_from_any(Vx.Core.t_user, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_security_from_user(user);
      return output;
    }

    public Vx.Core.Type_security vx_security_from_user(Vx.Core.Type_user user) {
      return Vx.Core.f_security_from_user(user);
    }

  }

  public static Func_security_from_user e_security_from_user = new Vx.Core.Class_security_from_user();
  public static Func_security_from_user t_security_from_user = new Vx.Core.Class_security_from_user();

  public static Vx.Core.Type_security f_security_from_user(Vx.Core.Type_user user) {
    Vx.Core.Type_security output = Vx.Core.e_security;
    output = user.security();
    return output;
  }

  /**
   * @function session_from_context
   * Returns session from a context
   * @return {session}
   * (func session<-context)
   */
  public interface Func_session_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_session vx_session_from_context(Vx.Core.Type_context context);
  }

  public class Class_session_from_context : Vx.Core.Class_base, Func_session_from_context {

    public override Vx.Core.Func_session_from_context vx_new(params Object[] vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    public override Vx.Core.Func_session_from_context vx_copy(params Object[] vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "session<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
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
      return e_session_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_session_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_session_from_context(context);
      return output;
    }

    public Vx.Core.Type_session vx_session_from_context(Vx.Core.Type_context context) {
      return Vx.Core.f_session_from_context(context);
    }

  }

  public static Func_session_from_context e_session_from_context = new Vx.Core.Class_session_from_context();
  public static Func_session_from_context t_session_from_context = new Vx.Core.Class_session_from_context();

  public static Vx.Core.Type_session f_session_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_session output = Vx.Core.e_session;
    output = context.session();
    return output;
  }

  /**
   * @function setting_from_context
   * Returns setting from a context
   * @return {setting}
   * (func setting<-context)
   */
  public interface Func_setting_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_setting vx_setting_from_context(Vx.Core.Type_context context);
  }

  public class Class_setting_from_context : Vx.Core.Class_base, Func_setting_from_context {

    public override Vx.Core.Func_setting_from_context vx_new(params Object[] vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    public override Vx.Core.Func_setting_from_context vx_copy(params Object[] vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "setting<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "setting", // name
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
      return e_setting_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_setting_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_setting_from_context(context);
      return output;
    }

    public Vx.Core.Type_setting vx_setting_from_context(Vx.Core.Type_context context) {
      return Vx.Core.f_setting_from_context(context);
    }

  }

  public static Func_setting_from_context e_setting_from_context = new Vx.Core.Class_setting_from_context();
  public static Func_setting_from_context t_setting_from_context = new Vx.Core.Class_setting_from_context();

  public static Vx.Core.Type_setting f_setting_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_setting output = Vx.Core.e_setting;
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
  public interface Func_string_repeat : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_repeat(Vx.Core.Type_string text, Vx.Core.Type_int repeat);
  }

  public class Class_string_repeat : Vx.Core.Class_base, Func_string_repeat {

    public override Vx.Core.Func_string_repeat vx_new(params Object[] vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    public override Vx.Core.Func_string_repeat vx_copy(params Object[] vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "string-repeat", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_repeat;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_repeat;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int repeat = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_string_repeat(text, repeat);
      return output;
    }

    public Vx.Core.Type_string vx_string_repeat(Vx.Core.Type_string text, Vx.Core.Type_int repeat) {
      return Vx.Core.f_string_repeat(text, repeat);
    }

  }

  public static Func_string_repeat e_string_repeat = new Vx.Core.Class_string_repeat();
  public static Func_string_repeat t_string_repeat = new Vx.Core.Class_string_repeat();

  public static Vx.Core.Type_string f_string_repeat(Vx.Core.Type_string text, Vx.Core.Type_int repeat) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function string_from_any
   * Return a string representation of a value
   * @param  {any} value
   * @return {string}
   * (func string<-any)
   */
  public interface Func_string_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_any(Vx.Core.Type_any value);
  }

  public class Class_string_from_any : Vx.Core.Class_base, Func_string_from_any {

    public override Vx.Core.Func_string_from_any vx_new(params Object[] vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    public override Vx.Core.Func_string_from_any vx_copy(params Object[] vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "string<-any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_string_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_string_from_any(value);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_any(Vx.Core.Type_any value) {
      return Vx.Core.f_string_from_any(value);
    }

  }

  public static Func_string_from_any e_string_from_any = new Vx.Core.Class_string_from_any();
  public static Func_string_from_any t_string_from_any = new Vx.Core.Class_string_from_any();

  public static Vx.Core.Type_string f_string_from_any(Vx.Core.Type_any value) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_string_from_any_indent(
      value,
      Vx.Core.vx_new_int(0),
      Vx.Core.vx_new_boolean(true)
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
  public interface Func_string_from_any_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_any_indent(Vx.Core.Type_any value, Vx.Core.Type_int indent, Vx.Core.Type_boolean linefeed);
  }

  public class Class_string_from_any_indent : Vx.Core.Class_base, Func_string_from_any_indent {

    public override Vx.Core.Func_string_from_any_indent vx_new(params Object[] vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    public override Vx.Core.Func_string_from_any_indent vx_copy(params Object[] vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "string<-any-indent", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_from_any_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_any_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_boolean linefeed = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_string_from_any_indent(value, indent, linefeed);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_any_indent(Vx.Core.Type_any value, Vx.Core.Type_int indent, Vx.Core.Type_boolean linefeed) {
      return Vx.Core.f_string_from_any_indent(value, indent, linefeed);
    }

  }

  public static Func_string_from_any_indent e_string_from_any_indent = new Vx.Core.Class_string_from_any_indent();
  public static Func_string_from_any_indent t_string_from_any_indent = new Vx.Core.Class_string_from_any_indent();

  public static Vx.Core.Type_string f_string_from_any_indent(Vx.Core.Type_any value, Vx.Core.Type_int indent, Vx.Core.Type_boolean linefeed) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function string_from_func
   * Function Type returning string with any parameters
   * @return {string}
   * (func string<-func)
   */
  public interface Func_string_from_func : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Func_string_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn);
    public Vx.Core.Type_string vx_string_from_func();
  }

  public class Class_string_from_func : Vx.Core.Class_base, Func_string_from_func {

    public override Vx.Core.Func_string_from_func vx_new(params Object[] vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    public override Vx.Core.Func_string_from_func vx_copy(params Object[] vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "string<-func", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_from_func;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_func;
    }

    public Vx.Core.Class_any_from_func.IFn? fn = null;

    public Vx.Core.Func_string_from_func vx_fn_new(Vx.Core.Class_any_from_func.IFn? fn) {
      Class_string_from_func output = new Class_string_from_func();
      output.fn = fn;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Core.f_string_from_func();
      return output;
    }

    public Vx.Core.Type_string vx_string_from_func() {
      return Vx.Core.f_string_from_func();
    }

  }

  public static Func_string_from_func e_string_from_func = new Vx.Core.Class_string_from_func();
  public static Func_string_from_func t_string_from_func = new Vx.Core.Class_string_from_func();

  public static Vx.Core.Type_string f_string_from_func() {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_string_from_string_find_replace : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_string_find_replace(Vx.Core.Type_string text, Vx.Core.Type_string find, Vx.Core.Type_string replace);
  }

  public class Class_string_from_string_find_replace : Vx.Core.Class_base, Func_string_from_string_find_replace {

    public override Vx.Core.Func_string_from_string_find_replace vx_new(params Object[] vals) {
      Class_string_from_string_find_replace output = new Class_string_from_string_find_replace();
      return output;
    }

    public override Vx.Core.Func_string_from_string_find_replace vx_copy(params Object[] vals) {
      Class_string_from_string_find_replace output = new Class_string_from_string_find_replace();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "string<-string-find-replace", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_from_string_find_replace;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_string_find_replace;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string replace = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Core.f_string_from_string_find_replace(text, find, replace);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_string_find_replace(Vx.Core.Type_string text, Vx.Core.Type_string find, Vx.Core.Type_string replace) {
      return Vx.Core.f_string_from_string_find_replace(text, find, replace);
    }

  }

  public static Func_string_from_string_find_replace e_string_from_string_find_replace = new Vx.Core.Class_string_from_string_find_replace();
  public static Func_string_from_string_find_replace t_string_from_string_find_replace = new Vx.Core.Class_string_from_string_find_replace();

  public static Vx.Core.Type_string f_string_from_string_find_replace(Vx.Core.Type_string text, Vx.Core.Type_string find, Vx.Core.Type_string replace) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function stringlist_from_map
   * Returns a stringlist of keys from any map in entry order.
   * @param  {map-1} map
   * @return {stringlist}
   * (func stringlist<-map)
   */
  public interface Func_stringlist_from_map : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_stringlist_from_map(Vx.Core.Type_map map);
  }

  public class Class_stringlist_from_map : Vx.Core.Class_base, Func_stringlist_from_map {

    public override Vx.Core.Func_stringlist_from_map vx_new(params Object[] vals) {
      Class_stringlist_from_map output = new Class_stringlist_from_map();
      return output;
    }

    public override Vx.Core.Func_stringlist_from_map vx_copy(params Object[] vals) {
      Class_stringlist_from_map output = new Class_stringlist_from_map();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "stringlist<-map", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_stringlist_from_map;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringlist_from_map;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_map inputval = (Vx.Core.Type_map)value;
      Vx.Core.Type_any outputval = Vx.Core.f_stringlist_from_map(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_map map = Vx.Core.f_any_from_any(Vx.Core.t_map, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_stringlist_from_map(map);
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist_from_map(Vx.Core.Type_map map) {
      return Vx.Core.f_stringlist_from_map(map);
    }

  }

  public static Func_stringlist_from_map e_stringlist_from_map = new Vx.Core.Class_stringlist_from_map();
  public static Func_stringlist_from_map t_stringlist_from_map = new Vx.Core.Class_stringlist_from_map();

  public static Vx.Core.Type_stringlist f_stringlist_from_map(Vx.Core.Type_map map) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Core.t_stringlist,
      map,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, value_any);
        Vx.Core.Type_any output_1 = key;
        return output_1;
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
  public interface Func_switch : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_switch<T, U>(T generic_any_1, U val, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any where U : Vx.Core.Type_any;
  }

  public class Class_switch : Vx.Core.Class_base, Func_switch {

    public override Vx.Core.Func_switch vx_new(params Object[] vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    public override Vx.Core.Func_switch vx_copy(params Object[] vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "switch", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_switch;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_switch;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_thenelselist thenelselist = Vx.Core.f_any_from_any(Vx.Core.t_thenelselist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_switch(generic_any_1, val, thenelselist);
      return output;
    }

    public T vx_switch<T, U>(T generic_any_1, U val, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      return Vx.Core.f_switch(generic_any_1, val, thenelselist);
    }

  }

  public static Func_switch e_switch = new Vx.Core.Class_switch();
  public static Func_switch t_switch = new Vx.Core.Class_switch();

  public static T f_switch<T, U>(T generic_any_1, U val, Vx.Core.Type_thenelselist thenelselist) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
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
  public interface Func_then : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_thenelse vx_then(Vx.Core.Func_boolean_from_func fn_cond, Vx.Core.Func_any_from_func fn_any);
  }

  public class Class_then : Vx.Core.Class_base, Func_then {

    public override Vx.Core.Func_then vx_new(params Object[] vals) {
      Class_then output = new Class_then();
      return output;
    }

    public override Vx.Core.Func_then vx_copy(params Object[] vals) {
      Class_then output = new Class_then();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "then", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
      return e_then;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_then;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Func_boolean_from_func fn_cond = Vx.Core.f_any_from_any(Vx.Core.t_boolean_from_func, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func fn_any = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Core.f_then(fn_cond, fn_any);
      return output;
    }

    public Vx.Core.Type_thenelse vx_then(Vx.Core.Func_boolean_from_func fn_cond, Vx.Core.Func_any_from_func fn_any) {
      return Vx.Core.f_then(fn_cond, fn_any);
    }

  }

  public static Func_then e_then = new Vx.Core.Class_then();
  public static Func_then t_then = new Vx.Core.Class_then();

  public static Vx.Core.Type_thenelse f_then(Vx.Core.Func_boolean_from_func fn_cond, Vx.Core.Func_any_from_func fn_any) {
    Vx.Core.Type_thenelse output = Vx.Core.e_thenelse;
    output = Vx.Core.f_new(
      Vx.Core.t_thenelse,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":code"),
        Vx.Core.vx_new_string(":then"),
        Vx.Core.vx_new_string(":fn-cond"),
        fn_cond,
        Vx.Core.vx_new_string(":fn-any"),
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
  public interface Func_traits_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typelist vx_traits_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_traits_from_typedef : Vx.Core.Class_base, Func_traits_from_typedef {

    public override Vx.Core.Func_traits_from_typedef vx_new(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    public override Vx.Core.Func_traits_from_typedef vx_copy(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
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
      return e_traits_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_traits_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_traits_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_traits_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_typelist vx_traits_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_traits_from_typedef(vtypedef);
    }

  }

  public static Func_traits_from_typedef e_traits_from_typedef = new Vx.Core.Class_traits_from_typedef();
  public static Func_traits_from_typedef t_traits_from_typedef = new Vx.Core.Class_traits_from_typedef();

  public static Vx.Core.Type_typelist f_traits_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_typelist output = Vx.Core.e_typelist;
    return output;
  }

  /**
   * @function type_from_any
   * Gets the Type of a given Value
   * @param  {any-1} value
   * @return {any}
   * (func type<-any)
   */
  public interface Func_type_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_type_from_any(Vx.Core.Type_any value);
  }

  public class Class_type_from_any : Vx.Core.Class_base, Func_type_from_any {

    public override Vx.Core.Func_type_from_any vx_new(params Object[] vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    public override Vx.Core.Func_type_from_any vx_copy(params Object[] vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "type<-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_type_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_type_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_type_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_type_from_any(value);
      return output;
    }

    public Vx.Core.Type_any vx_type_from_any(Vx.Core.Type_any value) {
      return Vx.Core.f_type_from_any(value);
    }

  }

  public static Func_type_from_any e_type_from_any = new Vx.Core.Class_type_from_any();
  public static Func_type_from_any t_type_from_any = new Vx.Core.Class_type_from_any();

  public static Vx.Core.Type_any f_type_from_any(Vx.Core.Type_any value) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    return output;
  }

  /**
   * @function typedef_from_any
   * Gets the typedef of a given value
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-any)
   */
  public interface Func_typedef_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typedef vx_typedef_from_any(Vx.Core.Type_any val);
  }

  public class Class_typedef_from_any : Vx.Core.Class_base, Func_typedef_from_any {

    public override Vx.Core.Func_typedef_from_any vx_new(params Object[] vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    public override Vx.Core.Func_typedef_from_any vx_copy(params Object[] vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
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
      return e_typedef_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typedef_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typedef_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typedef_from_any(val);
      return output;
    }

    public Vx.Core.Type_typedef vx_typedef_from_any(Vx.Core.Type_any val) {
      return Vx.Core.f_typedef_from_any(val);
    }

  }

  public static Func_typedef_from_any e_typedef_from_any = new Vx.Core.Class_typedef_from_any();
  public static Func_typedef_from_any t_typedef_from_any = new Vx.Core.Class_typedef_from_any();

  public static Vx.Core.Type_typedef f_typedef_from_any(Vx.Core.Type_any val) {
    Vx.Core.Type_typedef output = Vx.Core.e_typedef;
    output = Vx.Core.f_typedef_from_type(
      Vx.Core.f_type_from_any(val)
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
  public interface Func_typedef_from_type : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typedef vx_typedef_from_type(Vx.Core.Type_any val);
  }

  public class Class_typedef_from_type : Vx.Core.Class_base, Func_typedef_from_type {

    public override Vx.Core.Func_typedef_from_type vx_new(params Object[] vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    public override Vx.Core.Func_typedef_from_type vx_copy(params Object[] vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-type", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
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
      return e_typedef_from_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typedef_from_type;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typedef_from_type(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typedef_from_type(val);
      return output;
    }

    public Vx.Core.Type_typedef vx_typedef_from_type(Vx.Core.Type_any val) {
      return Vx.Core.f_typedef_from_type(val);
    }

  }

  public static Func_typedef_from_type e_typedef_from_type = new Vx.Core.Class_typedef_from_type();
  public static Func_typedef_from_type t_typedef_from_type = new Vx.Core.Class_typedef_from_type();

  public static Vx.Core.Type_typedef f_typedef_from_type(Vx.Core.Type_any val) {
    Vx.Core.Type_typedef output = Vx.Core.e_typedef;
    return output;
  }

  /**
   * @function typename_from_any
   * Gets the typename of a given value
   * @param  {any-2} value
   * @return {string}
   * (func typename<-any)
   */
  public interface Func_typename_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_typename_from_any(Vx.Core.Type_any value);
  }

  public class Class_typename_from_any : Vx.Core.Class_base, Func_typename_from_any {

    public override Vx.Core.Func_typename_from_any vx_new(params Object[] vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    public override Vx.Core.Func_typename_from_any vx_copy(params Object[] vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-any", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typename_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typename_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typename_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typename_from_any(value);
      return output;
    }

    public Vx.Core.Type_string vx_typename_from_any(Vx.Core.Type_any value) {
      return Vx.Core.f_typename_from_any(value);
    }

  }

  public static Func_typename_from_any e_typename_from_any = new Vx.Core.Class_typename_from_any();
  public static Func_typename_from_any t_typename_from_any = new Vx.Core.Class_typename_from_any();

  public static Vx.Core.Type_string f_typename_from_any(Vx.Core.Type_any value) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_typename_from_type(
      Vx.Core.f_type_from_any(value)
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
  public interface Func_typename_from_type : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_typename_from_type(Vx.Core.Type_any type);
  }

  public class Class_typename_from_type : Vx.Core.Class_base, Func_typename_from_type {

    public override Vx.Core.Func_typename_from_type vx_new(params Object[] vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    public override Vx.Core.Func_typename_from_type vx_copy(params Object[] vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-type", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typename_from_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typename_from_type;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typename_from_type(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typename_from_type(type);
      return output;
    }

    public Vx.Core.Type_string vx_typename_from_type(Vx.Core.Type_any type) {
      return Vx.Core.f_typename_from_type(type);
    }

  }

  public static Func_typename_from_type e_typename_from_type = new Vx.Core.Class_typename_from_type();
  public static Func_typename_from_type t_typename_from_type = new Vx.Core.Class_typename_from_type();

  public static Vx.Core.Type_string f_typename_from_type(Vx.Core.Type_any type) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_typename_from_typedef(
      Vx.Core.f_typedef_from_type(type)
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
  public interface Func_typename_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_typename_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_typename_from_typedef : Vx.Core.Class_base, Func_typename_from_typedef {

    public override Vx.Core.Func_typename_from_typedef vx_new(params Object[] vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    public override Vx.Core.Func_typename_from_typedef vx_copy(params Object[] vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-typedef", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_typename_from_typedef;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typename_from_typedef;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typedef inputval = (Vx.Core.Type_typedef)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typename_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typename_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_string vx_typename_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Core.f_typename_from_typedef(vtypedef);
    }

  }

  public static Func_typename_from_typedef e_typename_from_typedef = new Vx.Core.Class_typename_from_typedef();
  public static Func_typename_from_typedef t_typename_from_typedef = new Vx.Core.Class_typename_from_typedef();

  public static Vx.Core.Type_string f_typename_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_new(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        vtypedef.pkgname(),
        Vx.Core.vx_new_string("/"),
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
  public interface Func_typenames_from_typelist : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_typenames_from_typelist(Vx.Core.Type_typelist typelist);
  }

  public class Class_typenames_from_typelist : Vx.Core.Class_base, Func_typenames_from_typelist {

    public override Vx.Core.Func_typenames_from_typelist vx_new(params Object[] vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    public override Vx.Core.Func_typenames_from_typelist vx_copy(params Object[] vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "typenames<-typelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_typenames_from_typelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typenames_from_typelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_typelist inputval = (Vx.Core.Type_typelist)value;
      Vx.Core.Type_any outputval = Vx.Core.f_typenames_from_typelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typelist typelist = Vx.Core.f_any_from_any(Vx.Core.t_typelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_typenames_from_typelist(typelist);
      return output;
    }

    public Vx.Core.Type_stringlist vx_typenames_from_typelist(Vx.Core.Type_typelist typelist) {
      return Vx.Core.f_typenames_from_typelist(typelist);
    }

  }

  public static Func_typenames_from_typelist e_typenames_from_typelist = new Vx.Core.Class_typenames_from_typelist();
  public static Func_typenames_from_typelist t_typenames_from_typelist = new Vx.Core.Class_typenames_from_typelist();

  public static Vx.Core.Type_stringlist f_typenames_from_typelist(Vx.Core.Type_typelist typelist) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Core.t_stringlist,
      typelist,
      Vx.Core.t_any_from_any.vx_fn_new((type_any) => {
        Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, type_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_typename_from_type(type);
        return output_1;
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
  public interface Func_user_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_user vx_user_from_context(Vx.Core.Type_context context);
  }

  public class Class_user_from_context : Vx.Core.Class_base, Func_user_from_context {

    public override Vx.Core.Func_user_from_context vx_new(params Object[] vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    public override Vx.Core.Func_user_from_context vx_copy(params Object[] vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/core", // pkgname
        "user<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "user", // name
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
      return e_user_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_user_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Core.f_user_from_context(context);
      return output;
    }

    public Vx.Core.Type_user vx_user_from_context(Vx.Core.Type_context context) {
      return Vx.Core.f_user_from_context(context);
    }

  }

  public static Func_user_from_context e_user_from_context = new Vx.Core.Class_user_from_context();
  public static Func_user_from_context t_user_from_context = new Vx.Core.Class_user_from_context();

  public static Vx.Core.Type_user f_user_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_user output = Vx.Core.e_user;
    output = Vx.Core.f_session_from_context(context).user();
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
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("any", Vx.Core.t_any);
    maptype.put("any-async<-func", Vx.Core.t_any_async_from_func);
    maptype.put("any<-anylist", Vx.Core.t_any_from_anylist);
    maptype.put("anylist", Vx.Core.t_anylist);
    maptype.put("anymap", Vx.Core.t_anymap);
    maptype.put("anytype", Vx.Core.t_anytype);
    maptype.put("arg", Vx.Core.t_arg);
    maptype.put("arglist", Vx.Core.t_arglist);
    maptype.put("argmap", Vx.Core.t_argmap);
    maptype.put("boolean", Vx.Core.t_boolean);
    maptype.put("booleanlist", Vx.Core.t_booleanlist);
    maptype.put("collection", Vx.Core.t_collection);
    maptype.put("compilelanguages", Vx.Core.t_compilelanguages);
    maptype.put("connect", Vx.Core.t_connect);
    maptype.put("connectlist", Vx.Core.t_connectlist);
    maptype.put("connectmap", Vx.Core.t_connectmap);
    maptype.put("const", Vx.Core.t_const);
    maptype.put("constdef", Vx.Core.t_constdef);
    maptype.put("constlist", Vx.Core.t_constlist);
    maptype.put("constmap", Vx.Core.t_constmap);
    maptype.put("context", Vx.Core.t_context);
    maptype.put("date", Vx.Core.t_date);
    maptype.put("decimal", Vx.Core.t_decimal);
    maptype.put("error", Vx.Core.t_error);
    maptype.put("float", Vx.Core.t_float);
    maptype.put("func", Vx.Core.t_func);
    maptype.put("funcdef", Vx.Core.t_funcdef);
    maptype.put("funclist", Vx.Core.t_funclist);
    maptype.put("funcmap", Vx.Core.t_funcmap);
    maptype.put("int", Vx.Core.t_int);
    maptype.put("intlist", Vx.Core.t_intlist);
    maptype.put("intmap", Vx.Core.t_intmap);
    maptype.put("list", Vx.Core.t_list);
    maptype.put("listtype", Vx.Core.t_listtype);
    maptype.put("locale", Vx.Core.t_locale);
    maptype.put("map", Vx.Core.t_map);
    maptype.put("maptype", Vx.Core.t_maptype);
    maptype.put("mempool", Vx.Core.t_mempool);
    maptype.put("msg", Vx.Core.t_msg);
    maptype.put("msgblock", Vx.Core.t_msgblock);
    maptype.put("msgblocklist", Vx.Core.t_msgblocklist);
    maptype.put("msglist", Vx.Core.t_msglist);
    maptype.put("none", Vx.Core.t_none);
    maptype.put("notype", Vx.Core.t_notype);
    maptype.put("number", Vx.Core.t_number);
    maptype.put("numberlist", Vx.Core.t_numberlist);
    maptype.put("numbermap", Vx.Core.t_numbermap);
    maptype.put("package", Vx.Core.t_package);
    maptype.put("packagemap", Vx.Core.t_packagemap);
    maptype.put("permission", Vx.Core.t_permission);
    maptype.put("permissionlist", Vx.Core.t_permissionlist);
    maptype.put("permissionmap", Vx.Core.t_permissionmap);
    maptype.put("project", Vx.Core.t_project);
    maptype.put("security", Vx.Core.t_security);
    maptype.put("session", Vx.Core.t_session);
    maptype.put("setting", Vx.Core.t_setting);
    maptype.put("state", Vx.Core.t_state);
    maptype.put("statelistener", Vx.Core.t_statelistener);
    maptype.put("statelistenermap", Vx.Core.t_statelistenermap);
    maptype.put("string", Vx.Core.t_string);
    maptype.put("stringlist", Vx.Core.t_stringlist);
    maptype.put("stringlistlist", Vx.Core.t_stringlistlist);
    maptype.put("stringmap", Vx.Core.t_stringmap);
    maptype.put("stringmutablemap", Vx.Core.t_stringmutablemap);
    maptype.put("struct", Vx.Core.t_struct);
    maptype.put("thenelse", Vx.Core.t_thenelse);
    maptype.put("thenelselist", Vx.Core.t_thenelselist);
    maptype.put("translation", Vx.Core.t_translation);
    maptype.put("translationlist", Vx.Core.t_translationlist);
    maptype.put("translationmap", Vx.Core.t_translationmap);
    maptype.put("type", Vx.Core.t_type);
    maptype.put("typedef", Vx.Core.t_typedef);
    maptype.put("typelist", Vx.Core.t_typelist);
    maptype.put("typemap", Vx.Core.t_typemap);
    maptype.put("user", Vx.Core.t_user);
    maptype.put("value", Vx.Core.t_value);
    mapconst.put("false", Vx.Core.c_false);
    mapconst.put("global", Vx.Core.c_global);
    mapconst.put("infinity", Vx.Core.c_infinity);
    mapconst.put("mempool-active", Vx.Core.c_mempool_active);
    mapconst.put("msg-error", Vx.Core.c_msg_error);
    mapconst.put("msg-info", Vx.Core.c_msg_info);
    mapconst.put("msg-severe", Vx.Core.c_msg_severe);
    mapconst.put("msg-warning", Vx.Core.c_msg_warning);
    mapconst.put("neginfinity", Vx.Core.c_neginfinity);
    mapconst.put("newline", Vx.Core.c_newline);
    mapconst.put("notanumber", Vx.Core.c_notanumber);
    mapconst.put("nothing", Vx.Core.c_nothing);
    mapconst.put("quote", Vx.Core.c_quote);
    mapconst.put("true", Vx.Core.c_true);
    mapfunc.put("!", Vx.Core.t_not);
    mapfunc.put("!-empty", Vx.Core.t_notempty);
    mapfunc.put("!-empty_1", Vx.Core.t_notempty_1);
    mapfunc.put("!=", Vx.Core.t_ne);
    mapfunc.put("!==", Vx.Core.t_neqeq);
    mapfunc.put("*", Vx.Core.t_multiply);
    mapfunc.put("*_1", Vx.Core.t_multiply_1);
    mapfunc.put("*_2", Vx.Core.t_multiply_2);
    mapfunc.put("*_3", Vx.Core.t_multiply_3);
    mapfunc.put("+", Vx.Core.t_plus);
    mapfunc.put("+_1", Vx.Core.t_plus_1);
    mapfunc.put("+_2", Vx.Core.t_plus_2);
    mapfunc.put("+_3", Vx.Core.t_plus_3);
    mapfunc.put("+1", Vx.Core.t_plus1);
    mapfunc.put("-", Vx.Core.t_minus);
    mapfunc.put("-_1", Vx.Core.t_minus_1);
    mapfunc.put("-_2", Vx.Core.t_minus_2);
    mapfunc.put("-_3", Vx.Core.t_minus_3);
    mapfunc.put("-1", Vx.Core.t_minus1);
    mapfunc.put(".", Vx.Core.t_dotmethod);
    mapfunc.put("/", Vx.Core.t_divide);
    mapfunc.put("<", Vx.Core.t_lt);
    mapfunc.put("<_1", Vx.Core.t_lt_1);
    mapfunc.put("<-", Vx.Core.t_chainfirst);
    mapfunc.put("<<-", Vx.Core.t_chainlast);
    mapfunc.put("<=", Vx.Core.t_le);
    mapfunc.put("<=_1", Vx.Core.t_le_1);
    mapfunc.put("=", Vx.Core.t_eq);
    mapfunc.put("=_1", Vx.Core.t_eq_1);
    mapfunc.put("==", Vx.Core.t_eqeq);
    mapfunc.put(">", Vx.Core.t_gt);
    mapfunc.put(">_1", Vx.Core.t_gt_1);
    mapfunc.put(">=", Vx.Core.t_ge);
    mapfunc.put(">=_1", Vx.Core.t_ge_1);
    mapfunc.put("allowfuncs<-security", Vx.Core.t_allowfuncs_from_security);
    mapfunc.put("allowtypenames<-typedef", Vx.Core.t_allowtypenames_from_typedef);
    mapfunc.put("allowtypes<-typedef", Vx.Core.t_allowtypes_from_typedef);
    mapfunc.put("and", Vx.Core.t_and);
    mapfunc.put("and_1", Vx.Core.t_and_1);
    mapfunc.put("any<-any", Vx.Core.t_any_from_any);
    mapfunc.put("any<-any-async", Vx.Core.t_any_from_any_async);
    mapfunc.put("any<-any-context", Vx.Core.t_any_from_any_context);
    mapfunc.put("any<-any-context-async", Vx.Core.t_any_from_any_context_async);
    mapfunc.put("any<-any-key-value", Vx.Core.t_any_from_any_key_value);
    mapfunc.put("any<-func", Vx.Core.t_any_from_func);
    mapfunc.put("any<-func-async", Vx.Core.t_any_from_func_async);
    mapfunc.put("any<-int", Vx.Core.t_any_from_int);
    mapfunc.put("any<-int-any", Vx.Core.t_any_from_int_any);
    mapfunc.put("any<-key-value", Vx.Core.t_any_from_key_value);
    mapfunc.put("any<-key-value-async", Vx.Core.t_any_from_key_value_async);
    mapfunc.put("any<-list", Vx.Core.t_any_from_list);
    mapfunc.put("any<-list-start-reduce", Vx.Core.t_any_from_list_start_reduce);
    mapfunc.put("any<-list-start-reduce-next", Vx.Core.t_any_from_list_start_reduce_next);
    mapfunc.put("any<-map", Vx.Core.t_any_from_map);
    mapfunc.put("any<-map-start-reduce", Vx.Core.t_any_from_map_start_reduce);
    mapfunc.put("any<-none", Vx.Core.t_any_from_none);
    mapfunc.put("any<-none-async", Vx.Core.t_any_from_none_async);
    mapfunc.put("any<-reduce", Vx.Core.t_any_from_reduce);
    mapfunc.put("any<-reduce-async", Vx.Core.t_any_from_reduce_async);
    mapfunc.put("any<-reduce-next", Vx.Core.t_any_from_reduce_next);
    mapfunc.put("any<-reduce-next-async", Vx.Core.t_any_from_reduce_next_async);
    mapfunc.put("any<-struct", Vx.Core.t_any_from_struct);
    mapfunc.put("async", Vx.Core.t_async);
    mapfunc.put("boolean-permission<-func", Vx.Core.t_boolean_permission_from_func);
    mapfunc.put("boolean-write<-map-name-value", Vx.Core.t_boolean_write_from_map_name_value);
    mapfunc.put("boolean<-any", Vx.Core.t_boolean_from_any);
    mapfunc.put("boolean<-func", Vx.Core.t_boolean_from_func);
    mapfunc.put("boolean<-none", Vx.Core.t_boolean_from_none);
    mapfunc.put("case", Vx.Core.t_case);
    mapfunc.put("case_1", Vx.Core.t_case_1);
    mapfunc.put("compare", Vx.Core.t_compare);
    mapfunc.put("contains", Vx.Core.t_contains);
    mapfunc.put("contains_1", Vx.Core.t_contains_1);
    mapfunc.put("context-main", Vx.Core.t_context_main);
    mapfunc.put("copy", Vx.Core.t_copy);
    mapfunc.put("else", Vx.Core.t_else);
    mapfunc.put("empty", Vx.Core.t_empty);
    mapfunc.put("extends<-any", Vx.Core.t_extends_from_any);
    mapfunc.put("extends<-typedef", Vx.Core.t_extends_from_typedef);
    mapfunc.put("first<-list", Vx.Core.t_first_from_list);
    mapfunc.put("first<-list-any<-any", Vx.Core.t_first_from_list_any_from_any);
    mapfunc.put("float<-string", Vx.Core.t_float_from_string);
    mapfunc.put("fn", Vx.Core.t_fn);
    mapfunc.put("funcdef<-func", Vx.Core.t_funcdef_from_func);
    mapfunc.put("funcname<-funcdef", Vx.Core.t_funcname_from_funcdef);
    mapfunc.put("if", Vx.Core.t_if);
    mapfunc.put("if_1", Vx.Core.t_if_1);
    mapfunc.put("if_2", Vx.Core.t_if_2);
    mapfunc.put("int<-func", Vx.Core.t_int_from_func);
    mapfunc.put("int<-string", Vx.Core.t_int_from_string);
    mapfunc.put("is-empty", Vx.Core.t_is_empty);
    mapfunc.put("is-empty_1", Vx.Core.t_is_empty_1);
    mapfunc.put("is-endswith", Vx.Core.t_is_endswith);
    mapfunc.put("is-float", Vx.Core.t_is_float);
    mapfunc.put("is-func", Vx.Core.t_is_func);
    mapfunc.put("is-int", Vx.Core.t_is_int);
    mapfunc.put("is-number", Vx.Core.t_is_number);
    mapfunc.put("is-pass<-permission", Vx.Core.t_is_pass_from_permission);
    mapfunc.put("last<-list", Vx.Core.t_last_from_list);
    mapfunc.put("length", Vx.Core.t_length);
    mapfunc.put("length_1", Vx.Core.t_length_1);
    mapfunc.put("length_2", Vx.Core.t_length_2);
    mapfunc.put("let", Vx.Core.t_let);
    mapfunc.put("let-async", Vx.Core.t_let_async);
    mapfunc.put("list-join<-list", Vx.Core.t_list_join_from_list);
    mapfunc.put("list-join<-list_1", Vx.Core.t_list_join_from_list_1);
    mapfunc.put("list<-list", Vx.Core.t_list_from_list);
    mapfunc.put("list<-list_1", Vx.Core.t_list_from_list_1);
    mapfunc.put("list<-list-async", Vx.Core.t_list_from_list_async);
    mapfunc.put("list<-list-intany", Vx.Core.t_list_from_list_intany);
    mapfunc.put("list<-map", Vx.Core.t_list_from_map);
    mapfunc.put("list<-map_1", Vx.Core.t_list_from_map_1);
    mapfunc.put("list<-map-async", Vx.Core.t_list_from_map_async);
    mapfunc.put("list<-type", Vx.Core.t_list_from_type);
    mapfunc.put("log", Vx.Core.t_log);
    mapfunc.put("log_1", Vx.Core.t_log_1);
    mapfunc.put("main", Vx.Core.t_main);
    mapfunc.put("map<-list", Vx.Core.t_map_from_list);
    mapfunc.put("map<-map", Vx.Core.t_map_from_map);
    mapfunc.put("map<-map_1", Vx.Core.t_map_from_map_1);
    mapfunc.put("msg<-error", Vx.Core.t_msg_from_error);
    mapfunc.put("msg<-error_1", Vx.Core.t_msg_from_error_1);
    mapfunc.put("msg<-error_2", Vx.Core.t_msg_from_error_2);
    mapfunc.put("msg<-warning", Vx.Core.t_msg_from_warning);
    mapfunc.put("msgblock<-msgblock-msg", Vx.Core.t_msgblock_from_msgblock_msg);
    mapfunc.put("msgblock<-msgblock-msgblock", Vx.Core.t_msgblock_from_msgblock_msgblock);
    mapfunc.put("name<-typedef", Vx.Core.t_name_from_typedef);
    mapfunc.put("native", Vx.Core.t_native);
    mapfunc.put("native<-any", Vx.Core.t_native_from_any);
    mapfunc.put("new", Vx.Core.t_new);
    mapfunc.put("number<-func", Vx.Core.t_number_from_func);
    mapfunc.put("or", Vx.Core.t_or);
    mapfunc.put("or_1", Vx.Core.t_or_1);
    mapfunc.put("package-global<-name", Vx.Core.t_package_global_from_name);
    mapfunc.put("packagename<-typedef", Vx.Core.t_packagename_from_typedef);
    mapfunc.put("path<-context-path", Vx.Core.t_path_from_context_path);
    mapfunc.put("path<-setting-path", Vx.Core.t_path_from_setting_path);
    mapfunc.put("permission<-id-context", Vx.Core.t_permission_from_id_context);
    mapfunc.put("properties<-typedef", Vx.Core.t_properties_from_typedef);
    mapfunc.put("proplast<-typedef", Vx.Core.t_proplast_from_typedef);
    mapfunc.put("resolve", Vx.Core.t_resolve);
    mapfunc.put("resolve_1", Vx.Core.t_resolve_1);
    mapfunc.put("resolve-async", Vx.Core.t_resolve_async);
    mapfunc.put("resolve-first", Vx.Core.t_resolve_first);
    mapfunc.put("resolve-list", Vx.Core.t_resolve_list);
    mapfunc.put("security<-context", Vx.Core.t_security_from_context);
    mapfunc.put("security<-user", Vx.Core.t_security_from_user);
    mapfunc.put("session<-context", Vx.Core.t_session_from_context);
    mapfunc.put("setting<-context", Vx.Core.t_setting_from_context);
    mapfunc.put("string-repeat", Vx.Core.t_string_repeat);
    mapfunc.put("string<-any", Vx.Core.t_string_from_any);
    mapfunc.put("string<-any-indent", Vx.Core.t_string_from_any_indent);
    mapfunc.put("string<-func", Vx.Core.t_string_from_func);
    mapfunc.put("string<-string-find-replace", Vx.Core.t_string_from_string_find_replace);
    mapfunc.put("stringlist<-map", Vx.Core.t_stringlist_from_map);
    mapfunc.put("switch", Vx.Core.t_switch);
    mapfunc.put("then", Vx.Core.t_then);
    mapfunc.put("traits<-typedef", Vx.Core.t_traits_from_typedef);
    mapfunc.put("type<-any", Vx.Core.t_type_from_any);
    mapfunc.put("typedef<-any", Vx.Core.t_typedef_from_any);
    mapfunc.put("typedef<-type", Vx.Core.t_typedef_from_type);
    mapfunc.put("typename<-any", Vx.Core.t_typename_from_any);
    mapfunc.put("typename<-type", Vx.Core.t_typename_from_type);
    mapfunc.put("typename<-typedef", Vx.Core.t_typename_from_typedef);
    mapfunc.put("typenames<-typelist", Vx.Core.t_typenames_from_typelist);
    mapfunc.put("user<-context", Vx.Core.t_user_from_context);
    Vx.Core.vx_global_package_set("vx/core", maptype, mapconst, mapfunc);
    }
  }

}
