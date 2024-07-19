namespace Vx;

public static class Type {

  public static Vx.Core.Type_boolean vx_boolean_from_string_ends(
    Vx.Core.Type_string text,
    Vx.Core.Type_string ends) {
    bool check = Vx.Core.vx_boolean_from_string_ends(
      text.vx_string(),
      ends.vx_string());
    Vx.Core.Type_boolean output = Core.vx_new_boolean(check);
    return output;
  }

  public static Vx.Core.Type_boolean vx_boolean_from_string_starts(
    Vx.Core.Type_string text,
    Vx.Core.Type_string starts) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    bool check = Vx.Core.vx_boolean_from_string_starts(
      text.vx_string(),
      starts.vx_string()
    );
    output = Core.vx_new_boolean(check);
    return output;
  }

  // vx_int_from_string_find(string, string)
  public static int vx_int_from_string_find(String text, string find) {
    return text.IndexOf(find) + 1;
  }

  // vx_int_from_string_find(string, string)
  public static Vx.Core.Type_int vx_int_from_string_find(
    Vx.Core.Type_string text,
    Vx.Core.Type_string find) {
    int ipos = vx_int_from_string_find(text.vx_string(), find.vx_string());
    Vx.Core.Type_int output = Vx.Core.vx_new_int(ipos);
    return output;
  }

  // vx_int_from_string_findkeyword(string, string)
  public static int vx_int_from_string_findkeyword(
    string text,
    string find) {
    int output = -1;
    if (text == "") {
    } else if (find == ":nonwhitespace") {
      string wschars1 = " \n\r\t";
      int ilen = text.Length;
      for (int i = 0; i < ilen; i++) {
        char cchar = text[i];
        int pos = wschars1.IndexOf(cchar);
        if (pos < 0) {
          output = i;
          break;
        }
      }
    } else if (find == ":whitespace") {
      char[] wschars2 = {' ', '\n', '\r', '\t'};
      foreach (char cchar in wschars2) {
        int pos = text.IndexOf(cchar);
        if (pos < 0) {
        } else if (output < 0) {
          output = pos;
        } else if (pos < output) {
          output = pos;
        }
      }
    } else {
	     output = text.IndexOf(find);
		  }
    output += 1;
		  return output;
 	}

  // vx_int_from_string_findkeyword(string, string)
  public static Vx.Core.Type_int vx_int_from_string_findkeyword(
    Vx.Core.Type_string text,
    Vx.Core.Type_string find) {
    int ipos = vx_int_from_string_findkeyword(
      text.vx_string(),
      find.vx_string()
    );
    Vx.Core.Type_int output = Vx.Core.vx_new_int(ipos);
    return output;
  }
 
  // vx_int_from_string_findlast(string, string)
  public static int vx_int_from_string_findlast(
    string text,
    string findlast) {
    return text.LastIndexOf(findlast) + 1;
  }

  // vx_int_from_string_findlast(string, string)
  public static Vx.Core.Type_int vx_int_from_string_findlast(
    Vx.Core.Type_string text,
    Vx.Core.Type_string findlast) {
    int ipos = vx_int_from_string_findlast(
      text.vx_string(),
      findlast.vx_string()
    );
    Vx.Core.Type_int output = Vx.Core.vx_new_int(ipos);
    return output;
  }

  public static Vx.Core.Type_string vx_string_from_string_start_end(
    Vx.Core.Type_string text,
    Vx.Core.Type_int start,
    Vx.Core.Type_int end) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    string stext = Vx.Core.vx_string_from_string_start_end(
      text.vx_string(),
      start.vx_int(),
      end.vx_int()
    );
    output = Vx.Core.vx_new_string(stext);
    return output;
  }

  // vx_string_from_stringlist_join(stringlist, string)
  public static Vx.Core.Type_string vx_string_from_stringlist_join(
    Vx.Core.Type_stringlist vals,
    Vx.Core.Type_string delim) {
    Func<Vx.Core.Type_any, string> fn = (item) => {
      Vx.Core.Type_string valstring = Vx.Core.f_any_from_any(
        Vx.Core.t_string,
        item
      );
      return valstring.vx_string();
    };
    List<string> listvalstring = Vx.Core.arraylist_from_arraylist_fn(
      vals.vx_list(),
      fn
    );
    string stext = string.Join(delim.vx_string(), listvalstring);  
    Vx.Core.Type_string output = Vx.Core.vx_new_string(stext);
    return output;
  }

  // vx_string_lowercase(string)
  public static Vx.Core.Type_string vx_string_lowercase(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    string stext = text.vx_string();
    stext = stext.ToLower();
    output = Vx.Core.vx_new_string(stext);
    return output;
  }

  // vx_string_trim(string)
  public static Vx.Core.Type_string vx_string_trim(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    string stext = text.vx_string();
    stext = stext.Trim();
    output = Vx.Core.vx_new_string(stext);
    return output;
  }

  // vx_string_uppercase(string)
  public static Vx.Core.Type_string vx_string_uppercase(
    Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    string stext = text.vx_string();
    stext = stext.ToUpper();
    output = Vx.Core.vx_new_string(stext);
    return output;
  }

  public static Vx.Core.Type_stringlist vx_stringlist_from_string_split(
    Vx.Core.Type_string text,
    Vx.Core.Type_string delim) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    string stext = text.vx_string();
    string sdelim = delim.vx_string();
    Object[] arraystring = System.Text.RegularExpressions.Regex.Split(stext, sdelim);
    output = Vx.Core.vx_new(Vx.Core.t_stringlist, arraystring);
    return output;
  }
  /**
   * @function allowtypenames_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {stringlist}
   * (func allowtypenames<-type)
   */
  public interface Func_allowtypenames_from_type : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_allowtypenames_from_type(Vx.Core.Type_any type);
  }

  public class Class_allowtypenames_from_type : Vx.Core.Class_base, Func_allowtypenames_from_type {

    public override Vx.Type.Func_allowtypenames_from_type vx_new(params Object[] vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    public override Vx.Type.Func_allowtypenames_from_type vx_copy(params Object[] vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
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
      return e_allowtypenames_from_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_allowtypenames_from_type;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_allowtypenames_from_type(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_allowtypenames_from_type(type);
      return output;
    }

    public Vx.Core.Type_stringlist vx_allowtypenames_from_type(Vx.Core.Type_any type) {
      return Vx.Type.f_allowtypenames_from_type(type);
    }

  }

  public static Func_allowtypenames_from_type e_allowtypenames_from_type = new Vx.Type.Class_allowtypenames_from_type();
  public static Func_allowtypenames_from_type t_allowtypenames_from_type = new Vx.Type.Class_allowtypenames_from_type();

  public static Vx.Core.Type_stringlist f_allowtypenames_from_type(Vx.Core.Type_any type) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_typenames_from_typelist(
      Vx.Type.f_allowtypes_from_type(type)
    );
    return output;
  }

  /**
   * @function allowtypes_from_type
   * Returns the allowed types from a given type
   * @param  {any} type
   * @return {typelist}
   * (func allowtypes<-type)
   */
  public interface Func_allowtypes_from_type : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typelist vx_allowtypes_from_type(Vx.Core.Type_any type);
  }

  public class Class_allowtypes_from_type : Vx.Core.Class_base, Func_allowtypes_from_type {

    public override Vx.Type.Func_allowtypes_from_type vx_new(params Object[] vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    public override Vx.Type.Func_allowtypes_from_type vx_copy(params Object[] vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
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
      return e_allowtypes_from_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_allowtypes_from_type;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_allowtypes_from_type(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_allowtypes_from_type(type);
      return output;
    }

    public Vx.Core.Type_typelist vx_allowtypes_from_type(Vx.Core.Type_any type) {
      return Vx.Type.f_allowtypes_from_type(type);
    }

  }

  public static Func_allowtypes_from_type e_allowtypes_from_type = new Vx.Type.Class_allowtypes_from_type();
  public static Func_allowtypes_from_type t_allowtypes_from_type = new Vx.Type.Class_allowtypes_from_type();

  public static Vx.Core.Type_typelist f_allowtypes_from_type(Vx.Core.Type_any type) {
    Vx.Core.Type_typelist output = Vx.Core.e_typelist;
    output = Vx.Core.f_typedef_from_type(type).allowtypes();
    return output;
  }

  /**
   * @function any_from_int
   * Generic function returns any from an int.
   * @param  {int} val
   * @return {any-1}
   * (func any<-int)
   */
  public interface Func_any_from_int : Vx.Core.Func_any_from_any {
    public T vx_any_from_int<T>(T generic_any_1, Vx.Core.Type_int val) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_int : Vx.Core.Class_base, Func_any_from_int {

    public override Vx.Type.Func_any_from_int vx_new(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    public override Vx.Type.Func_any_from_int vx_copy(params Object[] vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
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

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Type.f_any_from_int(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int val = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_any_from_int(generic_any_1, val);
      return output;
    }

    public T vx_any_from_int<T>(T generic_any_1, Vx.Core.Type_int val) where T : Vx.Core.Type_any {
      return Vx.Type.f_any_from_int(generic_any_1, val);
    }

  }

  public static Func_any_from_int e_any_from_int = new Vx.Type.Class_any_from_int();
  public static Func_any_from_int t_any_from_int = new Vx.Type.Class_any_from_int();

  public static T f_any_from_int<T>(T generic_any_1, Vx.Core.Type_int val) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function boolean_from_string_ends
   * Returns true if string starts with find.
   * @param  {string} text
   * @param  {string} ends
   * @return {boolean}
   * (func boolean<-string-ends)
   */
  public interface Func_boolean_from_string_ends : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_from_string_ends(Vx.Core.Type_string text, Vx.Core.Type_string ends);
  }

  public class Class_boolean_from_string_ends : Vx.Core.Class_base, Func_boolean_from_string_ends {

    public override Vx.Type.Func_boolean_from_string_ends vx_new(params Object[] vals) {
      Class_boolean_from_string_ends output = new Class_boolean_from_string_ends();
      return output;
    }

    public override Vx.Type.Func_boolean_from_string_ends vx_copy(params Object[] vals) {
      Class_boolean_from_string_ends output = new Class_boolean_from_string_ends();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-ends", // name
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
      return e_boolean_from_string_ends;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_from_string_ends;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string ends = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_boolean_from_string_ends(text, ends);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_from_string_ends(Vx.Core.Type_string text, Vx.Core.Type_string ends) {
      return Vx.Type.f_boolean_from_string_ends(text, ends);
    }

  }

  public static Func_boolean_from_string_ends e_boolean_from_string_ends = new Vx.Type.Class_boolean_from_string_ends();
  public static Func_boolean_from_string_ends t_boolean_from_string_ends = new Vx.Type.Class_boolean_from_string_ends();

  public static Vx.Core.Type_boolean f_boolean_from_string_ends(Vx.Core.Type_string text, Vx.Core.Type_string ends) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Type.vx_boolean_from_string_ends(text, ends);
    return output;
  }

  /**
   * @function boolean_from_string_starts
   * Returns true if string starts with find.
   * @param  {string} text
   * @param  {string} starts
   * @return {boolean}
   * (func boolean<-string-starts)
   */
  public interface Func_boolean_from_string_starts : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_from_string_starts(Vx.Core.Type_string text, Vx.Core.Type_string starts);
  }

  public class Class_boolean_from_string_starts : Vx.Core.Class_base, Func_boolean_from_string_starts {

    public override Vx.Type.Func_boolean_from_string_starts vx_new(params Object[] vals) {
      Class_boolean_from_string_starts output = new Class_boolean_from_string_starts();
      return output;
    }

    public override Vx.Type.Func_boolean_from_string_starts vx_copy(params Object[] vals) {
      Class_boolean_from_string_starts output = new Class_boolean_from_string_starts();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-starts", // name
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
      return e_boolean_from_string_starts;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_from_string_starts;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string starts = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_boolean_from_string_starts(text, starts);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_from_string_starts(Vx.Core.Type_string text, Vx.Core.Type_string starts) {
      return Vx.Type.f_boolean_from_string_starts(text, starts);
    }

  }

  public static Func_boolean_from_string_starts e_boolean_from_string_starts = new Vx.Type.Class_boolean_from_string_starts();
  public static Func_boolean_from_string_starts t_boolean_from_string_starts = new Vx.Type.Class_boolean_from_string_starts();

  public static Vx.Core.Type_boolean f_boolean_from_string_starts(Vx.Core.Type_string text, Vx.Core.Type_string starts) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Type.vx_boolean_from_string_starts(text, starts);
    return output;
  }

  /**
   * @function int_from_string_find
   * Returns integer position of find string in text string.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   * (func int<-string-find)
   */
  public interface Func_int_from_string_find : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_int_from_string_find(Vx.Core.Type_string text, Vx.Core.Type_string find);
  }

  public class Class_int_from_string_find : Vx.Core.Class_base, Func_int_from_string_find {

    public override Vx.Type.Func_int_from_string_find vx_new(params Object[] vals) {
      Class_int_from_string_find output = new Class_int_from_string_find();
      return output;
    }

    public override Vx.Type.Func_int_from_string_find vx_copy(params Object[] vals) {
      Class_int_from_string_find output = new Class_int_from_string_find();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-find", // name
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
      return e_int_from_string_find;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_from_string_find;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_int_from_string_find(text, find);
      return output;
    }

    public Vx.Core.Type_int vx_int_from_string_find(Vx.Core.Type_string text, Vx.Core.Type_string find) {
      return Vx.Type.f_int_from_string_find(text, find);
    }

  }

  public static Func_int_from_string_find e_int_from_string_find = new Vx.Type.Class_int_from_string_find();
  public static Func_int_from_string_find t_int_from_string_find = new Vx.Type.Class_int_from_string_find();

  public static Vx.Core.Type_int f_int_from_string_find(Vx.Core.Type_string text, Vx.Core.Type_string find) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Type.vx_int_from_string_find(text, find);
    return output;
  }

  /**
   * @function int_from_string_findkeyword
   * Returns integer position of find string in text string. Note: the find terms :whitespace and :nonwhitespace have special meaning.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   * (func int<-string-findkeyword)
   */
  public interface Func_int_from_string_findkeyword : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_int_from_string_findkeyword(Vx.Core.Type_string text, Vx.Core.Type_string find);
  }

  public class Class_int_from_string_findkeyword : Vx.Core.Class_base, Func_int_from_string_findkeyword {

    public override Vx.Type.Func_int_from_string_findkeyword vx_new(params Object[] vals) {
      Class_int_from_string_findkeyword output = new Class_int_from_string_findkeyword();
      return output;
    }

    public override Vx.Type.Func_int_from_string_findkeyword vx_copy(params Object[] vals) {
      Class_int_from_string_findkeyword output = new Class_int_from_string_findkeyword();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findkeyword", // name
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
      return e_int_from_string_findkeyword;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_from_string_findkeyword;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_int_from_string_findkeyword(text, find);
      return output;
    }

    public Vx.Core.Type_int vx_int_from_string_findkeyword(Vx.Core.Type_string text, Vx.Core.Type_string find) {
      return Vx.Type.f_int_from_string_findkeyword(text, find);
    }

  }

  public static Func_int_from_string_findkeyword e_int_from_string_findkeyword = new Vx.Type.Class_int_from_string_findkeyword();
  public static Func_int_from_string_findkeyword t_int_from_string_findkeyword = new Vx.Type.Class_int_from_string_findkeyword();

  public static Vx.Core.Type_int f_int_from_string_findkeyword(Vx.Core.Type_string text, Vx.Core.Type_string find) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Type.vx_int_from_string_findkeyword(text, find);
    return output;
  }

  /**
   * @function int_from_string_findlast
   * Returns integer position of find string in text string.
   * @param  {string} text
   * @param  {string} findlast
   * @return {int}
   * (func int<-string-findlast)
   */
  public interface Func_int_from_string_findlast : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_int_from_string_findlast(Vx.Core.Type_string text, Vx.Core.Type_string findlast);
  }

  public class Class_int_from_string_findlast : Vx.Core.Class_base, Func_int_from_string_findlast {

    public override Vx.Type.Func_int_from_string_findlast vx_new(params Object[] vals) {
      Class_int_from_string_findlast output = new Class_int_from_string_findlast();
      return output;
    }

    public override Vx.Type.Func_int_from_string_findlast vx_copy(params Object[] vals) {
      Class_int_from_string_findlast output = new Class_int_from_string_findlast();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findlast", // name
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
      return e_int_from_string_findlast;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_from_string_findlast;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string findlast = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_int_from_string_findlast(text, findlast);
      return output;
    }

    public Vx.Core.Type_int vx_int_from_string_findlast(Vx.Core.Type_string text, Vx.Core.Type_string findlast) {
      return Vx.Type.f_int_from_string_findlast(text, findlast);
    }

  }

  public static Func_int_from_string_findlast e_int_from_string_findlast = new Vx.Type.Class_int_from_string_findlast();
  public static Func_int_from_string_findlast t_int_from_string_findlast = new Vx.Type.Class_int_from_string_findlast();

  public static Vx.Core.Type_int f_int_from_string_findlast(Vx.Core.Type_string text, Vx.Core.Type_string findlast) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Type.vx_int_from_string_findlast(text, findlast);
    return output;
  }

  /**
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   * (func is-boolean)
   */
  public interface Func_is_boolean : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_boolean(Vx.Core.Type_any value);
  }

  public class Class_is_boolean : Vx.Core.Class_base, Func_is_boolean {

    public override Vx.Type.Func_is_boolean vx_new(params Object[] vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    public override Vx.Type.Func_is_boolean vx_copy(params Object[] vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-boolean", // name
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
      return e_is_boolean;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_boolean;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_is_boolean(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_is_boolean(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_boolean(Vx.Core.Type_any value) {
      return Vx.Type.f_is_boolean(value);
    }

  }

  public static Func_is_boolean e_is_boolean = new Vx.Type.Class_is_boolean();
  public static Func_is_boolean t_is_boolean = new Vx.Type.Class_is_boolean();

  public static Vx.Core.Type_boolean f_is_boolean(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_eq(
      Vx.Core.vx_new_string("boolean"),
      Vx.Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_decimal
   * @param  {any} value
   * @return {boolean}
   * (func is-decimal)
   */
  public interface Func_is_decimal : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_decimal(Vx.Core.Type_any value);
  }

  public class Class_is_decimal : Vx.Core.Class_base, Func_is_decimal {

    public override Vx.Type.Func_is_decimal vx_new(params Object[] vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    public override Vx.Type.Func_is_decimal vx_copy(params Object[] vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-decimal", // name
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
      return e_is_decimal;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_decimal;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_is_decimal(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_is_decimal(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_decimal(Vx.Core.Type_any value) {
      return Vx.Type.f_is_decimal(value);
    }

  }

  public static Func_is_decimal e_is_decimal = new Vx.Type.Class_is_decimal();
  public static Func_is_decimal t_is_decimal = new Vx.Type.Class_is_decimal();

  public static Vx.Core.Type_boolean f_is_decimal(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_eq(
      Vx.Core.vx_new_string("decimal"),
      Vx.Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_none
   * @param  {any} value
   * @return {boolean}
   * (func is-none)
   */
  public interface Func_is_none : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_none(Vx.Core.Type_any value);
  }

  public class Class_is_none : Vx.Core.Class_base, Func_is_none {

    public override Vx.Type.Func_is_none vx_new(params Object[] vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    public override Vx.Type.Func_is_none vx_copy(params Object[] vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-none", // name
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
      return e_is_none;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_none;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_is_none(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_is_none(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_none(Vx.Core.Type_any value) {
      return Vx.Type.f_is_none(value);
    }

  }

  public static Func_is_none e_is_none = new Vx.Type.Class_is_none();
  public static Func_is_none t_is_none = new Vx.Type.Class_is_none();

  public static Vx.Core.Type_boolean f_is_none(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_eq(
      value,
      Vx.Core.t_none
    );
    return output;
  }

  /**
   * @function is_string
   * @param  {any} value
   * @return {boolean}
   * (func is-string)
   */
  public interface Func_is_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_string(Vx.Core.Type_any value);
  }

  public class Class_is_string : Vx.Core.Class_base, Func_is_string {

    public override Vx.Type.Func_is_string vx_new(params Object[] vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    public override Vx.Type.Func_is_string vx_copy(params Object[] vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-string", // name
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
      return e_is_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_is_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_is_string(value);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_string(Vx.Core.Type_any value) {
      return Vx.Type.f_is_string(value);
    }

  }

  public static Func_is_string e_is_string = new Vx.Type.Class_is_string();
  public static Func_is_string t_is_string = new Vx.Type.Class_is_string();

  public static Vx.Core.Type_boolean f_is_string(Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_eq(
      Vx.Core.vx_new_string("vx/core/string"),
      Vx.Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_type
   * @param  {any} val
   * @param  {any} type
   * @return {boolean}
   * (func is-type)
   */
  public interface Func_is_type : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_is_type(Vx.Core.Type_any val, Vx.Core.Type_any type);
  }

  public class Class_is_type : Vx.Core.Class_base, Func_is_type {

    public override Vx.Type.Func_is_type vx_new(params Object[] vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    public override Vx.Type.Func_is_type vx_copy(params Object[] vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-type", // name
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
      return e_is_type;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_type;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_is_type(val, type);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_type(Vx.Core.Type_any val, Vx.Core.Type_any type) {
      return Vx.Type.f_is_type(val, type);
    }

  }

  public static Func_is_type e_is_type = new Vx.Type.Class_is_type();
  public static Func_is_type t_is_type = new Vx.Type.Class_is_type();

  public static Vx.Core.Type_boolean f_is_type(Vx.Core.Type_any val, Vx.Core.Type_any type) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_or_1(
      Vx.Core.vx_new(Vx.Core.t_booleanlist,
        Vx.Core.f_eq(
          Vx.Core.f_typename_from_type(type),
          Vx.Core.f_typename_from_any(val)
        ),
        Vx.Core.f_contains_1(
          Vx.Type.f_allowtypenames_from_type(type),
          Vx.Core.f_typename_from_any(val)
        ),
        Vx.Core.f_contains_1(
          Vx.Type.f_traitnames_from_any(val),
          Vx.Core.f_typename_from_type(type)
        )
      )
    );
    return output;
  }

  /**
   * @function is_type_from_any_typelist
   * Returns true if val is any type in typelist.
   * @param  {any} val
   * @param  {typelist} typelist
   * @return {boolean}
   * (func is-type<-any-typelist)
   */
  public interface Func_is_type_from_any_typelist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_is_type_from_any_typelist(Vx.Core.Type_any val, Vx.Core.Type_typelist typelist);
  }

  public class Class_is_type_from_any_typelist : Vx.Core.Class_base, Func_is_type_from_any_typelist {

    public override Vx.Type.Func_is_type_from_any_typelist vx_new(params Object[] vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    public override Vx.Type.Func_is_type_from_any_typelist vx_copy(params Object[] vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
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
      return e_is_type_from_any_typelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_type_from_any_typelist;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_typelist typelist = Vx.Core.f_any_from_any(Vx.Core.t_typelist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_is_type_from_any_typelist(val, typelist);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_type_from_any_typelist(Vx.Core.Type_any val, Vx.Core.Type_typelist typelist) {
      return Vx.Type.f_is_type_from_any_typelist(val, typelist);
    }

  }

  public static Func_is_type_from_any_typelist e_is_type_from_any_typelist = new Vx.Type.Class_is_type_from_any_typelist();
  public static Func_is_type_from_any_typelist t_is_type_from_any_typelist = new Vx.Type.Class_is_type_from_any_typelist();

  public static Vx.Core.Type_boolean f_is_type_from_any_typelist(Vx.Core.Type_any val, Vx.Core.Type_typelist typelist) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Core.t_boolean,
      typelist,
      Vx.Core.vx_new_boolean(false),
      Vx.Core.t_any_from_reduce.vx_fn_new((result_any, type_any) => {
        Vx.Core.Type_boolean result = Vx.Core.f_any_from_any(Vx.Core.t_boolean, result_any);
        Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, type_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_or(
            result,
            Vx.Type.f_is_type(val, type)
          );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_lowercase
   * Returns lowercase version of string
   * @param  {string} text
   * @return {string}
   * (func string-lowercase)
   */
  public interface Func_string_lowercase : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_lowercase(Vx.Core.Type_string text);
  }

  public class Class_string_lowercase : Vx.Core.Class_base, Func_string_lowercase {

    public override Vx.Type.Func_string_lowercase vx_new(params Object[] vals) {
      Class_string_lowercase output = new Class_string_lowercase();
      return output;
    }

    public override Vx.Type.Func_string_lowercase vx_copy(params Object[] vals) {
      Class_string_lowercase output = new Class_string_lowercase();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string-lowercase", // name
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
      return e_string_lowercase;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_lowercase;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Type.f_string_lowercase(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_string_lowercase(text);
      return output;
    }

    public Vx.Core.Type_string vx_string_lowercase(Vx.Core.Type_string text) {
      return Vx.Type.f_string_lowercase(text);
    }

  }

  public static Func_string_lowercase e_string_lowercase = new Vx.Type.Class_string_lowercase();
  public static Func_string_lowercase t_string_lowercase = new Vx.Type.Class_string_lowercase();

  public static Vx.Core.Type_string f_string_lowercase(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.vx_string_lowercase(text);
    return output;
  }

  /**
   * @function string_outdent
   * Returns a string replacing leading whitespace on all lines based on first line.
   * @param  {string} text
   * @return {string}
   * (func string-outdent)
   */
  public interface Func_string_outdent : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_outdent(Vx.Core.Type_string text);
  }

  public class Class_string_outdent : Vx.Core.Class_base, Func_string_outdent {

    public override Vx.Type.Func_string_outdent vx_new(params Object[] vals) {
      Class_string_outdent output = new Class_string_outdent();
      return output;
    }

    public override Vx.Type.Func_string_outdent vx_copy(params Object[] vals) {
      Class_string_outdent output = new Class_string_outdent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string-outdent", // name
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
      return e_string_outdent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_outdent;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Type.f_string_outdent(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_string_outdent(text);
      return output;
    }

    public Vx.Core.Type_string vx_string_outdent(Vx.Core.Type_string text) {
      return Vx.Type.f_string_outdent(text);
    }

  }

  public static Func_string_outdent e_string_outdent = new Vx.Type.Class_string_outdent();
  public static Func_string_outdent t_string_outdent = new Vx.Type.Class_string_outdent();

  public static Vx.Core.Type_string f_string_outdent(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pos = Vx.Type.f_int_from_string_findkeyword(text, Vx.Core.vx_new_string(":nonwhitespace"));
        Vx.Core.Type_any output_2 = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_int(0), pos);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return text;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_let(
                  Vx.Core.t_string,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Core.Type_string indent = Vx.Type.f_string_from_string_end(
                      text,
                      Vx.Core.f_minus1(pos)
                    );
                    Vx.Core.Type_string rest = Vx.Type.f_string_from_string_start(text, pos);
                    Vx.Core.Type_int linepos = Vx.Type.f_int_from_string_find(indent, Vx.Core.vx_new_string("\n"));
                    Vx.Core.Type_string outdent = Vx.Core.f_if_1(
                      Vx.Core.t_string,
                      Vx.Core.f_eq(Vx.Core.vx_new_int(0), linepos),
                      Vx.Core.vx_new_string(""),
                      Vx.Core.vx_new_string("\n")
                    );
                    Vx.Core.Type_any output_1 = Vx.Core.f_string_from_string_find_replace(rest, indent, outdent);
                    return output_1;
                  })
                );
              })
            )
          )
        );
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function string_trim
   * Trims whitespace from the front and back of text
   * @param  {string} text
   * @return {string}
   * (func string-trim)
   */
  public interface Func_string_trim : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_trim(Vx.Core.Type_string text);
  }

  public class Class_string_trim : Vx.Core.Class_base, Func_string_trim {

    public override Vx.Type.Func_string_trim vx_new(params Object[] vals) {
      Class_string_trim output = new Class_string_trim();
      return output;
    }

    public override Vx.Type.Func_string_trim vx_copy(params Object[] vals) {
      Class_string_trim output = new Class_string_trim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string-trim", // name
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
      return e_string_trim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_trim;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Type.f_string_trim(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_string_trim(text);
      return output;
    }

    public Vx.Core.Type_string vx_string_trim(Vx.Core.Type_string text) {
      return Vx.Type.f_string_trim(text);
    }

  }

  public static Func_string_trim e_string_trim = new Vx.Type.Class_string_trim();
  public static Func_string_trim t_string_trim = new Vx.Type.Class_string_trim();

  public static Vx.Core.Type_string f_string_trim(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.vx_string_trim(text);
    return output;
  }

  /**
   * @function string_uppercase
   * Returns uppercase version of string
   * @param  {string} text
   * @return {string}
   * (func string-uppercase)
   */
  public interface Func_string_uppercase : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_uppercase(Vx.Core.Type_string text);
  }

  public class Class_string_uppercase : Vx.Core.Class_base, Func_string_uppercase {

    public override Vx.Type.Func_string_uppercase vx_new(params Object[] vals) {
      Class_string_uppercase output = new Class_string_uppercase();
      return output;
    }

    public override Vx.Type.Func_string_uppercase vx_copy(params Object[] vals) {
      Class_string_uppercase output = new Class_string_uppercase();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string-uppercase", // name
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
      return e_string_uppercase;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_uppercase;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Type.f_string_uppercase(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_string_uppercase(text);
      return output;
    }

    public Vx.Core.Type_string vx_string_uppercase(Vx.Core.Type_string text) {
      return Vx.Type.f_string_uppercase(text);
    }

  }

  public static Func_string_uppercase e_string_uppercase = new Vx.Type.Class_string_uppercase();
  public static Func_string_uppercase t_string_uppercase = new Vx.Type.Class_string_uppercase();

  public static Vx.Core.Type_string f_string_uppercase(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.vx_string_uppercase(text);
    return output;
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} val
   * @return {string}
   * (func string<-int)
   */
  public interface Func_string_from_int : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_int(Vx.Core.Type_int val);
  }

  public class Class_string_from_int : Vx.Core.Class_base, Func_string_from_int {

    public override Vx.Type.Func_string_from_int vx_new(params Object[] vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    public override Vx.Type.Func_string_from_int vx_copy(params Object[] vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string<-int", // name
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
      return e_string_from_int;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_int;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Type.f_string_from_int(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int val = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_string_from_int(val);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_int(Vx.Core.Type_int val) {
      return Vx.Type.f_string_from_int(val);
    }

  }

  public static Func_string_from_int e_string_from_int = new Vx.Type.Class_string_from_int();
  public static Func_string_from_int t_string_from_int = new Vx.Type.Class_string_from_int();

  public static Vx.Core.Type_string f_string_from_int(Vx.Core.Type_int val) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_switch(
      Vx.Core.t_string,
      val,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Core.c_infinity,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_string("infinity");
          })
        ),
        Vx.Core.f_case_1(
          Vx.Core.c_neginfinity,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_string("neginfinity");
          })
        ),
        Vx.Core.f_case_1(
          Vx.Core.c_notanumber,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_string("notanumber");
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Core.t_string,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  val
              )
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_string_end
   * Returns a substring between 0 end position.
   * @param  {string} text
   * @param  {int} endpos
   * @return {string}
   * (func string<-string-end)
   */
  public interface Func_string_from_string_end : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_string_end(Vx.Core.Type_string text, Vx.Core.Type_int endpos);
  }

  public class Class_string_from_string_end : Vx.Core.Class_base, Func_string_from_string_end {

    public override Vx.Type.Func_string_from_string_end vx_new(params Object[] vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    public override Vx.Type.Func_string_from_string_end vx_copy(params Object[] vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
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
      return e_string_from_string_end;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_string_end;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int endpos = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_string_from_string_end(text, endpos);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_string_end(Vx.Core.Type_string text, Vx.Core.Type_int endpos) {
      return Vx.Type.f_string_from_string_end(text, endpos);
    }

  }

  public static Func_string_from_string_end e_string_from_string_end = new Vx.Type.Class_string_from_string_end();
  public static Func_string_from_string_end t_string_from_string_end = new Vx.Type.Class_string_from_string_end();

  public static Vx.Core.Type_string f_string_from_string_end(Vx.Core.Type_string text, Vx.Core.Type_int endpos) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.f_string_from_string_start_end(text, Vx.Core.vx_new_int(1), endpos);
    return output;
  }

  /**
   * @function string_from_string_start
   * Returns a substring between start string end.
   * @param  {string} text
   * @param  {int} startpos
   * @return {string}
   * (func string<-string-start)
   */
  public interface Func_string_from_string_start : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_string_start(Vx.Core.Type_string text, Vx.Core.Type_int startpos);
  }

  public class Class_string_from_string_start : Vx.Core.Class_base, Func_string_from_string_start {

    public override Vx.Type.Func_string_from_string_start vx_new(params Object[] vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    public override Vx.Type.Func_string_from_string_start vx_copy(params Object[] vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
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
      return e_string_from_string_start;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_string_start;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int startpos = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_string_from_string_start(text, startpos);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_string_start(Vx.Core.Type_string text, Vx.Core.Type_int startpos) {
      return Vx.Type.f_string_from_string_start(text, startpos);
    }

  }

  public static Func_string_from_string_start e_string_from_string_start = new Vx.Type.Class_string_from_string_start();
  public static Func_string_from_string_start t_string_from_string_start = new Vx.Type.Class_string_from_string_start();

  public static Vx.Core.Type_string f_string_from_string_start(Vx.Core.Type_string text, Vx.Core.Type_int startpos) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.f_string_from_string_start_end(
      text,
      startpos,
      Vx.Core.f_length(text)
    );
    return output;
  }

  /**
   * @function string_from_string_start_end
   * Returns a substring between start and end positions.
   * @param  {string} text
   * @param  {int} start
   * @param  {int} end
   * @return {string}
   * (func string<-string-start-end)
   */
  public interface Func_string_from_string_start_end : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_string_start_end(Vx.Core.Type_string text, Vx.Core.Type_int start, Vx.Core.Type_int end);
  }

  public class Class_string_from_string_start_end : Vx.Core.Class_base, Func_string_from_string_start_end {

    public override Vx.Type.Func_string_from_string_start_end vx_new(params Object[] vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    public override Vx.Type.Func_string_from_string_start_end vx_copy(params Object[] vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
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
      return e_string_from_string_start_end;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_string_start_end;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int start = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int end = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Type.f_string_from_string_start_end(text, start, end);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_string_start_end(Vx.Core.Type_string text, Vx.Core.Type_int start, Vx.Core.Type_int end) {
      return Vx.Type.f_string_from_string_start_end(text, start, end);
    }

  }

  public static Func_string_from_string_start_end e_string_from_string_start_end = new Vx.Type.Class_string_from_string_start_end();
  public static Func_string_from_string_start_end t_string_from_string_start_end = new Vx.Type.Class_string_from_string_start_end();

  public static Vx.Core.Type_string f_string_from_string_start_end(Vx.Core.Type_string text, Vx.Core.Type_int start, Vx.Core.Type_int end) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.vx_string_from_string_start_end(text, start, end);
    return output;
  }

  /**
   * @function string_from_stringlist_join
   * Returns a string by joining a stringlist by the delimiter
   * @param  {stringlist} vals
   * @param  {string} delim
   * @return {string}
   * (func string<-stringlist-join)
   */
  public interface Func_string_from_stringlist_join : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_stringlist_join(Vx.Core.Type_stringlist vals, Vx.Core.Type_string delim);
  }

  public class Class_string_from_stringlist_join : Vx.Core.Class_base, Func_string_from_stringlist_join {

    public override Vx.Type.Func_string_from_stringlist_join vx_new(params Object[] vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    public override Vx.Type.Func_string_from_stringlist_join vx_copy(params Object[] vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
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
      return e_string_from_stringlist_join;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_stringlist_join;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_stringlist vals = Vx.Core.f_any_from_any(Vx.Core.t_stringlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string delim = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_string_from_stringlist_join(vals, delim);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stringlist_join(Vx.Core.Type_stringlist vals, Vx.Core.Type_string delim) {
      return Vx.Type.f_string_from_stringlist_join(vals, delim);
    }

  }

  public static Func_string_from_stringlist_join e_string_from_stringlist_join = new Vx.Type.Class_string_from_stringlist_join();
  public static Func_string_from_stringlist_join t_string_from_stringlist_join = new Vx.Type.Class_string_from_stringlist_join();

  public static Vx.Core.Type_string f_string_from_stringlist_join(Vx.Core.Type_stringlist vals, Vx.Core.Type_string delim) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Type.vx_string_from_stringlist_join(vals, delim);
    return output;
  }

  /**
   * @function stringlist_from_string_split
   * Returns a stringlist by splitting a string by the delimiter
   * @param  {string} text
   * @param  {string} delim
   * @return {stringlist}
   * (func stringlist<-string-split)
   */
  public interface Func_stringlist_from_string_split : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_stringlist vx_stringlist_from_string_split(Vx.Core.Type_string text, Vx.Core.Type_string delim);
  }

  public class Class_stringlist_from_string_split : Vx.Core.Class_base, Func_stringlist_from_string_split {

    public override Vx.Type.Func_stringlist_from_string_split vx_new(params Object[] vals) {
      Class_stringlist_from_string_split output = new Class_stringlist_from_string_split();
      return output;
    }

    public override Vx.Type.Func_stringlist_from_string_split vx_copy(params Object[] vals) {
      Class_stringlist_from_string_split output = new Class_stringlist_from_string_split();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "stringlist<-string-split", // name
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
      return e_stringlist_from_string_split;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringlist_from_string_split;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string delim = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Type.f_stringlist_from_string_split(text, delim);
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist_from_string_split(Vx.Core.Type_string text, Vx.Core.Type_string delim) {
      return Vx.Type.f_stringlist_from_string_split(text, delim);
    }

  }

  public static Func_stringlist_from_string_split e_stringlist_from_string_split = new Vx.Type.Class_stringlist_from_string_split();
  public static Func_stringlist_from_string_split t_stringlist_from_string_split = new Vx.Type.Class_stringlist_from_string_split();

  public static Vx.Core.Type_stringlist f_stringlist_from_string_split(Vx.Core.Type_string text, Vx.Core.Type_string delim) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Type.vx_stringlist_from_string_split(text, delim);
    return output;
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} val
   * @return {stringlist}
   * (func traitnames<-any)
   */
  public interface Func_traitnames_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_traitnames_from_any(Vx.Core.Type_any val);
  }

  public class Class_traitnames_from_any : Vx.Core.Class_base, Func_traitnames_from_any {

    public override Vx.Type.Func_traitnames_from_any vx_new(params Object[] vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    public override Vx.Type.Func_traitnames_from_any vx_copy(params Object[] vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
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
      return e_traitnames_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_traitnames_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_traitnames_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_traitnames_from_any(val);
      return output;
    }

    public Vx.Core.Type_stringlist vx_traitnames_from_any(Vx.Core.Type_any val) {
      return Vx.Type.f_traitnames_from_any(val);
    }

  }

  public static Func_traitnames_from_any e_traitnames_from_any = new Vx.Type.Class_traitnames_from_any();
  public static Func_traitnames_from_any t_traitnames_from_any = new Vx.Type.Class_traitnames_from_any();

  public static Vx.Core.Type_stringlist f_traitnames_from_any(Vx.Core.Type_any val) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_typenames_from_typelist(
      Vx.Type.f_traits_from_any(val)
    );
    return output;
  }

  /**
   * @function traits_from_any
   * Get the traits of a given value
   * @param  {any} val
   * @return {typelist}
   * (func traits<-any)
   */
  public interface Func_traits_from_any : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typelist vx_traits_from_any(Vx.Core.Type_any val);
  }

  public class Class_traits_from_any : Vx.Core.Class_base, Func_traits_from_any {

    public override Vx.Type.Func_traits_from_any vx_new(params Object[] vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    public override Vx.Type.Func_traits_from_any vx_copy(params Object[] vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
        "traits<-any", // name
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
      return e_traits_from_any;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_traits_from_any;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Type.f_traits_from_any(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_traits_from_any(val);
      return output;
    }

    public Vx.Core.Type_typelist vx_traits_from_any(Vx.Core.Type_any val) {
      return Vx.Type.f_traits_from_any(val);
    }

  }

  public static Func_traits_from_any e_traits_from_any = new Vx.Type.Class_traits_from_any();
  public static Func_traits_from_any t_traits_from_any = new Vx.Type.Class_traits_from_any();

  public static Vx.Core.Type_typelist f_traits_from_any(Vx.Core.Type_any val) {
    Vx.Core.Type_typelist output = Vx.Core.e_typelist;
    output = Vx.Core.f_traits_from_typedef(
      Vx.Core.f_typedef_from_any(val)
    );
    return output;
  }

  /**
   * @function traits_from_typedef
   * Get the traits of a given typedef
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func traits<-typedef)
   */
  public interface Func_traits_from_typedef : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_typelist vx_traits_from_typedef(Vx.Core.Type_typedef vtypedef);
  }

  public class Class_traits_from_typedef : Vx.Core.Class_base, Func_traits_from_typedef {

    public override Vx.Type.Func_traits_from_typedef vx_new(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    public override Vx.Type.Func_traits_from_typedef vx_copy(params Object[] vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/type", // pkgname
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
      Vx.Core.Type_any outputval = Vx.Type.f_traits_from_typedef(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_typedef vtypedef = Vx.Core.f_any_from_any(Vx.Core.t_typedef, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Type.f_traits_from_typedef(vtypedef);
      return output;
    }

    public Vx.Core.Type_typelist vx_traits_from_typedef(Vx.Core.Type_typedef vtypedef) {
      return Vx.Type.f_traits_from_typedef(vtypedef);
    }

  }

  public static Func_traits_from_typedef e_traits_from_typedef = new Vx.Type.Class_traits_from_typedef();
  public static Func_traits_from_typedef t_traits_from_typedef = new Vx.Type.Class_traits_from_typedef();

  public static Vx.Core.Type_typelist f_traits_from_typedef(Vx.Core.Type_typedef vtypedef) {
    Vx.Core.Type_typelist output = Vx.Core.e_typelist;
    output = vtypedef.traits();
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapfunc.put("allowtypenames<-type", Vx.Type.t_allowtypenames_from_type);
    mapfunc.put("allowtypes<-type", Vx.Type.t_allowtypes_from_type);
    mapfunc.put("any<-int", Vx.Type.t_any_from_int);
    mapfunc.put("boolean<-string-ends", Vx.Type.t_boolean_from_string_ends);
    mapfunc.put("boolean<-string-starts", Vx.Type.t_boolean_from_string_starts);
    mapfunc.put("int<-string-find", Vx.Type.t_int_from_string_find);
    mapfunc.put("int<-string-findkeyword", Vx.Type.t_int_from_string_findkeyword);
    mapfunc.put("int<-string-findlast", Vx.Type.t_int_from_string_findlast);
    mapfunc.put("is-boolean", Vx.Type.t_is_boolean);
    mapfunc.put("is-decimal", Vx.Type.t_is_decimal);
    mapfunc.put("is-none", Vx.Type.t_is_none);
    mapfunc.put("is-string", Vx.Type.t_is_string);
    mapfunc.put("is-type", Vx.Type.t_is_type);
    mapfunc.put("is-type<-any-typelist", Vx.Type.t_is_type_from_any_typelist);
    mapfunc.put("string-lowercase", Vx.Type.t_string_lowercase);
    mapfunc.put("string-outdent", Vx.Type.t_string_outdent);
    mapfunc.put("string-trim", Vx.Type.t_string_trim);
    mapfunc.put("string-uppercase", Vx.Type.t_string_uppercase);
    mapfunc.put("string<-int", Vx.Type.t_string_from_int);
    mapfunc.put("string<-string-end", Vx.Type.t_string_from_string_end);
    mapfunc.put("string<-string-start", Vx.Type.t_string_from_string_start);
    mapfunc.put("string<-string-start-end", Vx.Type.t_string_from_string_start_end);
    mapfunc.put("string<-stringlist-join", Vx.Type.t_string_from_stringlist_join);
    mapfunc.put("stringlist<-string-split", Vx.Type.t_stringlist_from_string_split);
    mapfunc.put("traitnames<-any", Vx.Type.t_traitnames_from_any);
    mapfunc.put("traits<-any", Vx.Type.t_traits_from_any);
    mapfunc.put("traits<-typedef", Vx.Type.t_traits_from_typedef);
    Vx.Core.vx_global_package_set("vx/type", maptype, mapconst, mapfunc);
    }
  }

}
