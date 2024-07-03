package com.vxlisp.vx;

import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public final class Type {

  // vx_int_from_string_find(string, string)
  public static int vx_int_from_string_find(String text, String find) {
    return text.indexOf(find) + 1;
  }

  // vx_int_from_string_find(string, string)
  public static Core.Type_int vx_int_from_string_find(Core.Type_string text, Core.Type_string find) {
    int ipos = vx_int_from_string_find(text.vx_string(), find.vx_string());
    Core.Type_int output = Core.vx_new_int(ipos);
    return output;
  }

  // vx_int_from_string_findkeyword(string, string)
  public static int vx_int_from_string_findkeyword(String text, String find) {
    int output = -1;
    if (text == "") {
    } else if (find == ":nonwhitespace") {
      String wschars1 = " \n\r\t";
      int ilen = text.length();
      for (int i = 0; i < ilen; i++) {
        char cchar = text.charAt(i);
        int pos = wschars1.indexOf(cchar);
        if (pos < 0) {
          output = i;
          break;
        }
      }
    } else if (find == ":whitespace") {
      char[] wschars2 = {' ', '\n', '\r', '\t'};
      for (char cchar : wschars2) {
        int pos = text.indexOf(cchar);
        if (pos < 0) {
        } else if (output < 0) {
          output = pos;
        } else if (pos < output) {
          output = pos;
        }
      }
    } else {
	     output = text.indexOf(find);
		  }
    output += 1;
		  return output;
 	}

  // vx_int_from_string_findkeyword(string, string)
  public static Core.Type_int vx_int_from_string_findkeyword(Core.Type_string text, Core.Type_string find) {
    int ipos = vx_int_from_string_findkeyword(text.vx_string(), find.vx_string());
    Core.Type_int output = Core.vx_new_int(ipos);
    return output;
  }
 
  // vx_int_from_string_findlast(string, string)
  public static int vx_int_from_string_findlast(String text, String findlast) {
    return text.lastIndexOf(findlast) + 1;
  }

  // vx_int_from_string_findlast(string, string)
  public static Core.Type_int vx_int_from_string_findlast(Core.Type_string text, Core.Type_string findlast) {
    int ipos = vx_int_from_string_findlast(text.vx_string(), findlast.vx_string());
    Core.Type_int output = Core.vx_new_int(ipos);
    return output;
  }

  // vx_string_from_stringlist_join(stringlist, string)
  public static Core.Type_string vx_string_from_stringlist_join(Core.Type_stringlist vals, Core.Type_string delim) {
    List<String> listvalstring = Core.arraylist_from_arraylist_fn(vals.vx_list(), (item) -> {
      Core.Type_string valstring = Core.f_any_from_any(Core.t_string, item);
      return valstring.vx_string();
    });
    String stext = String.join(delim.vx_string(), listvalstring);  
    Core.Type_string output = Core.vx_new_string(stext);
    return output;
  }

  // vx_string_lowercase(string)
  public static Core.Type_string vx_string_lowercase(Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    String stext = text.vx_string();
    stext = stext.toLowerCase();
    output = Core.vx_new_string(stext);
    return output;
  }

  // vx_string_trim(string)
  public static Core.Type_string vx_string_trim(Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    String stext = text.vx_string();
    stext = stext.trim();
    output = Core.vx_new_string(stext);
    return output;
  }

  // vx_string_uppercase(string)
  public static Core.Type_string vx_string_uppercase(Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    String stext = text.vx_string();
    stext = stext.toUpperCase();
    output = Core.vx_new_string(stext);
    return output;
  }

  public static Core.Type_stringlist vx_stringlist_from_string_split(Core.Type_string text, Core.Type_string delim) {
    Core.Type_stringlist output = Core.e_stringlist;
    String stext = text.vx_string();
    String sdelim = delim.vx_string();
    Object[] arraystring = stext.split(java.util.regex.Pattern.quote(sdelim));
    output = Core.vx_new(Core.t_stringlist, arraystring);
    return output;
  }
  /**
   * @function allowtypenames_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {stringlist}
   * (func allowtypenames<-type)
   */
  public interface Func_allowtypenames_from_type extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_allowtypenames_from_type(final Core.Type_any type);
  }

  public static class Class_allowtypenames_from_type extends Core.Class_base implements Func_allowtypenames_from_type {

    @Override
    public Type.Func_allowtypenames_from_type vx_new(final Object... vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    @Override
    public Type.Func_allowtypenames_from_type vx_copy(final Object... vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_allowtypenames_from_type;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_allowtypenames_from_type;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_allowtypenames_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_allowtypenames_from_type(type);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_allowtypenames_from_type(final Core.Type_any type) {
      return Type.f_allowtypenames_from_type(type);
    }

  }

  public static final Func_allowtypenames_from_type e_allowtypenames_from_type = new Type.Class_allowtypenames_from_type();
  public static final Func_allowtypenames_from_type t_allowtypenames_from_type = new Type.Class_allowtypenames_from_type();

  public static Core.Type_stringlist f_allowtypenames_from_type(final Core.Type_any type) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_typenames_from_typelist(
      Type.f_allowtypes_from_type(type)
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
  public interface Func_allowtypes_from_type extends Core.Func_any_from_any {
    public Core.Type_typelist vx_allowtypes_from_type(final Core.Type_any type);
  }

  public static class Class_allowtypes_from_type extends Core.Class_base implements Func_allowtypes_from_type {

    @Override
    public Type.Func_allowtypes_from_type vx_new(final Object... vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    @Override
    public Type.Func_allowtypes_from_type vx_copy(final Object... vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
      return e_allowtypes_from_type;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_allowtypes_from_type;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_allowtypes_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_allowtypes_from_type(type);
      return output;
    }

    @Override
    public Core.Type_typelist vx_allowtypes_from_type(final Core.Type_any type) {
      return Type.f_allowtypes_from_type(type);
    }

  }

  public static final Func_allowtypes_from_type e_allowtypes_from_type = new Type.Class_allowtypes_from_type();
  public static final Func_allowtypes_from_type t_allowtypes_from_type = new Type.Class_allowtypes_from_type();

  public static Core.Type_typelist f_allowtypes_from_type(final Core.Type_any type) {
    Core.Type_typelist output = Core.e_typelist;
    output = Core.f_typedef_from_type(type).allowtypes();
    return output;
  }

  /**
   * @function any_from_int
   * Generic function returns any from an int.
   * @param  {int} val
   * @return {any-1}
   * (func any<-int)
   */
  public interface Func_any_from_int extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T vx_any_from_int(final T generic_any_1, final Core.Type_int val);
  }

  public static class Class_any_from_int extends Core.Class_base implements Func_any_from_int {

    @Override
    public Type.Func_any_from_int vx_new(final Object... vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    @Override
    public Type.Func_any_from_int vx_copy(final Object... vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
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
    public Core.Type_any vx_empty() {
      return e_any_from_int;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_int;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Type.f_any_from_int(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int val = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_any_from_int(generic_any_1, val);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_int(final T generic_any_1, final Core.Type_int val) {
      return Type.f_any_from_int(generic_any_1, val);
    }

  }

  public static final Func_any_from_int e_any_from_int = new Type.Class_any_from_int();
  public static final Func_any_from_int t_any_from_int = new Type.Class_any_from_int();

  public static <T extends Core.Type_any> T f_any_from_int(final T generic_any_1, final Core.Type_int val) {
    T output = Core.f_empty(generic_any_1);
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
  public interface Func_boolean_from_string_ends extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_from_string_ends(final Core.Type_string text, final Core.Type_string ends);
  }

  public static class Class_boolean_from_string_ends extends Core.Class_base implements Func_boolean_from_string_ends {

    @Override
    public Type.Func_boolean_from_string_ends vx_new(final Object... vals) {
      Class_boolean_from_string_ends output = new Class_boolean_from_string_ends();
      return output;
    }

    @Override
    public Type.Func_boolean_from_string_ends vx_copy(final Object... vals) {
      Class_boolean_from_string_ends output = new Class_boolean_from_string_ends();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-ends", // name
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
    public Core.Type_any vx_empty() {
      return e_boolean_from_string_ends;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_boolean_from_string_ends;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string ends = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_boolean_from_string_ends(text, ends);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_from_string_ends(final Core.Type_string text, final Core.Type_string ends) {
      return Type.f_boolean_from_string_ends(text, ends);
    }

  }

  public static final Func_boolean_from_string_ends e_boolean_from_string_ends = new Type.Class_boolean_from_string_ends();
  public static final Func_boolean_from_string_ends t_boolean_from_string_ends = new Type.Class_boolean_from_string_ends();

  public static Core.Type_boolean f_boolean_from_string_ends(final Core.Type_string text, final Core.Type_string ends) {
    Core.Type_boolean output = Core.e_boolean;
    boolean check = Core.vx_boolean_from_string_ends(text.vx_string(), ends.vx_string());
    output = Core.vx_new_boolean(check);
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
  public interface Func_boolean_from_string_starts extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_from_string_starts(final Core.Type_string text, final Core.Type_string starts);
  }

  public static class Class_boolean_from_string_starts extends Core.Class_base implements Func_boolean_from_string_starts {

    @Override
    public Type.Func_boolean_from_string_starts vx_new(final Object... vals) {
      Class_boolean_from_string_starts output = new Class_boolean_from_string_starts();
      return output;
    }

    @Override
    public Type.Func_boolean_from_string_starts vx_copy(final Object... vals) {
      Class_boolean_from_string_starts output = new Class_boolean_from_string_starts();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-starts", // name
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
    public Core.Type_any vx_empty() {
      return e_boolean_from_string_starts;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_boolean_from_string_starts;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string starts = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_boolean_from_string_starts(text, starts);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_from_string_starts(final Core.Type_string text, final Core.Type_string starts) {
      return Type.f_boolean_from_string_starts(text, starts);
    }

  }

  public static final Func_boolean_from_string_starts e_boolean_from_string_starts = new Type.Class_boolean_from_string_starts();
  public static final Func_boolean_from_string_starts t_boolean_from_string_starts = new Type.Class_boolean_from_string_starts();

  public static Core.Type_boolean f_boolean_from_string_starts(final Core.Type_string text, final Core.Type_string starts) {
    Core.Type_boolean output = Core.e_boolean;
    boolean check = Core.vx_boolean_from_string_starts(text.vx_string(), starts.vx_string());
    output = Core.vx_new_boolean(check);
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
  public interface Func_int_from_string_find extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_from_string_find(final Core.Type_string text, final Core.Type_string find);
  }

  public static class Class_int_from_string_find extends Core.Class_base implements Func_int_from_string_find {

    @Override
    public Type.Func_int_from_string_find vx_new(final Object... vals) {
      Class_int_from_string_find output = new Class_int_from_string_find();
      return output;
    }

    @Override
    public Type.Func_int_from_string_find vx_copy(final Object... vals) {
      Class_int_from_string_find output = new Class_int_from_string_find();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-find", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
      return e_int_from_string_find;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_int_from_string_find;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_int_from_string_find(text, find);
      return output;
    }

    @Override
    public Core.Type_int vx_int_from_string_find(final Core.Type_string text, final Core.Type_string find) {
      return Type.f_int_from_string_find(text, find);
    }

  }

  public static final Func_int_from_string_find e_int_from_string_find = new Type.Class_int_from_string_find();
  public static final Func_int_from_string_find t_int_from_string_find = new Type.Class_int_from_string_find();

  public static Core.Type_int f_int_from_string_find(final Core.Type_string text, final Core.Type_string find) {
    Core.Type_int output = Core.e_int;
    output = Type.vx_int_from_string_find(text, find);
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
  public interface Func_int_from_string_findkeyword extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_from_string_findkeyword(final Core.Type_string text, final Core.Type_string find);
  }

  public static class Class_int_from_string_findkeyword extends Core.Class_base implements Func_int_from_string_findkeyword {

    @Override
    public Type.Func_int_from_string_findkeyword vx_new(final Object... vals) {
      Class_int_from_string_findkeyword output = new Class_int_from_string_findkeyword();
      return output;
    }

    @Override
    public Type.Func_int_from_string_findkeyword vx_copy(final Object... vals) {
      Class_int_from_string_findkeyword output = new Class_int_from_string_findkeyword();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findkeyword", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
      return e_int_from_string_findkeyword;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_int_from_string_findkeyword;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_int_from_string_findkeyword(text, find);
      return output;
    }

    @Override
    public Core.Type_int vx_int_from_string_findkeyword(final Core.Type_string text, final Core.Type_string find) {
      return Type.f_int_from_string_findkeyword(text, find);
    }

  }

  public static final Func_int_from_string_findkeyword e_int_from_string_findkeyword = new Type.Class_int_from_string_findkeyword();
  public static final Func_int_from_string_findkeyword t_int_from_string_findkeyword = new Type.Class_int_from_string_findkeyword();

  public static Core.Type_int f_int_from_string_findkeyword(final Core.Type_string text, final Core.Type_string find) {
    Core.Type_int output = Core.e_int;
    output = Type.vx_int_from_string_findkeyword(text, find);
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
  public interface Func_int_from_string_findlast extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_from_string_findlast(final Core.Type_string text, final Core.Type_string findlast);
  }

  public static class Class_int_from_string_findlast extends Core.Class_base implements Func_int_from_string_findlast {

    @Override
    public Type.Func_int_from_string_findlast vx_new(final Object... vals) {
      Class_int_from_string_findlast output = new Class_int_from_string_findlast();
      return output;
    }

    @Override
    public Type.Func_int_from_string_findlast vx_copy(final Object... vals) {
      Class_int_from_string_findlast output = new Class_int_from_string_findlast();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findlast", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
      return e_int_from_string_findlast;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_int_from_string_findlast;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string findlast = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_int_from_string_findlast(text, findlast);
      return output;
    }

    @Override
    public Core.Type_int vx_int_from_string_findlast(final Core.Type_string text, final Core.Type_string findlast) {
      return Type.f_int_from_string_findlast(text, findlast);
    }

  }

  public static final Func_int_from_string_findlast e_int_from_string_findlast = new Type.Class_int_from_string_findlast();
  public static final Func_int_from_string_findlast t_int_from_string_findlast = new Type.Class_int_from_string_findlast();

  public static Core.Type_int f_int_from_string_findlast(final Core.Type_string text, final Core.Type_string findlast) {
    Core.Type_int output = Core.e_int;
    output = Type.vx_int_from_string_findlast(text, findlast);
    return output;
  }

  /**
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   * (func is-boolean)
   */
  public interface Func_is_boolean extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_boolean(final Core.Type_any value);
  }

  public static class Class_is_boolean extends Core.Class_base implements Func_is_boolean {

    @Override
    public Type.Func_is_boolean vx_new(final Object... vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    @Override
    public Type.Func_is_boolean vx_copy(final Object... vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-boolean", // name
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
    public Core.Type_any vx_empty() {
      return e_is_boolean;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_boolean;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_boolean(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_is_boolean(value);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_boolean(final Core.Type_any value) {
      return Type.f_is_boolean(value);
    }

  }

  public static final Func_is_boolean e_is_boolean = new Type.Class_is_boolean();
  public static final Func_is_boolean t_is_boolean = new Type.Class_is_boolean();

  public static Core.Type_boolean f_is_boolean(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.vx_new_string("boolean"),
      Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_decimal
   * @param  {any} value
   * @return {boolean}
   * (func is-decimal)
   */
  public interface Func_is_decimal extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_decimal(final Core.Type_any value);
  }

  public static class Class_is_decimal extends Core.Class_base implements Func_is_decimal {

    @Override
    public Type.Func_is_decimal vx_new(final Object... vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    @Override
    public Type.Func_is_decimal vx_copy(final Object... vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-decimal", // name
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
    public Core.Type_any vx_empty() {
      return e_is_decimal;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_decimal;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_decimal(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_is_decimal(value);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_decimal(final Core.Type_any value) {
      return Type.f_is_decimal(value);
    }

  }

  public static final Func_is_decimal e_is_decimal = new Type.Class_is_decimal();
  public static final Func_is_decimal t_is_decimal = new Type.Class_is_decimal();

  public static Core.Type_boolean f_is_decimal(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.vx_new_string("decimal"),
      Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_none
   * @param  {any} value
   * @return {boolean}
   * (func is-none)
   */
  public interface Func_is_none extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_none(final Core.Type_any value);
  }

  public static class Class_is_none extends Core.Class_base implements Func_is_none {

    @Override
    public Type.Func_is_none vx_new(final Object... vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    @Override
    public Type.Func_is_none vx_copy(final Object... vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-none", // name
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
    public Core.Type_any vx_empty() {
      return e_is_none;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_none;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_none(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_is_none(value);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_none(final Core.Type_any value) {
      return Type.f_is_none(value);
    }

  }

  public static final Func_is_none e_is_none = new Type.Class_is_none();
  public static final Func_is_none t_is_none = new Type.Class_is_none();

  public static Core.Type_boolean f_is_none(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      value,
      Core.t_none
    );
    return output;
  }

  /**
   * @function is_string
   * @param  {any} value
   * @return {boolean}
   * (func is-string)
   */
  public interface Func_is_string extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_string(final Core.Type_any value);
  }

  public static class Class_is_string extends Core.Class_base implements Func_is_string {

    @Override
    public Type.Func_is_string vx_new(final Object... vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    @Override
    public Type.Func_is_string vx_copy(final Object... vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-string", // name
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
    public Core.Type_any vx_empty() {
      return e_is_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_string;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_is_string(value);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_string(final Core.Type_any value) {
      return Type.f_is_string(value);
    }

  }

  public static final Func_is_string e_is_string = new Type.Class_is_string();
  public static final Func_is_string t_is_string = new Type.Class_is_string();

  public static Core.Type_boolean f_is_string(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.vx_new_string("vx/core/string"),
      Core.f_typename_from_any(value)
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
  public interface Func_is_type extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_is_type(final Core.Type_any val, final Core.Type_any type);
  }

  public static class Class_is_type extends Core.Class_base implements Func_is_type {

    @Override
    public Type.Func_is_type vx_new(final Object... vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    @Override
    public Type.Func_is_type vx_copy(final Object... vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-type", // name
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
    public Core.Type_any vx_empty() {
      return e_is_type;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_type;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_is_type(val, type);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_type(final Core.Type_any val, final Core.Type_any type) {
      return Type.f_is_type(val, type);
    }

  }

  public static final Func_is_type e_is_type = new Type.Class_is_type();
  public static final Func_is_type t_is_type = new Type.Class_is_type();

  public static Core.Type_boolean f_is_type(final Core.Type_any val, final Core.Type_any type) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_or_1(
      Core.vx_new(Core.t_booleanlist,
        Core.f_eq(
          Core.f_typename_from_type(type),
          Core.f_typename_from_any(val)
        ),
        Core.f_contains_1(
          Type.f_allowtypenames_from_type(type),
          Core.f_typename_from_any(val)
        ),
        Core.f_contains_1(
          Type.f_traitnames_from_any(val),
          Core.f_typename_from_type(type)
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
  public interface Func_is_type_from_any_typelist extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist);
  }

  public static class Class_is_type_from_any_typelist extends Core.Class_base implements Func_is_type_from_any_typelist {

    @Override
    public Type.Func_is_type_from_any_typelist vx_new(final Object... vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    @Override
    public Type.Func_is_type_from_any_typelist vx_copy(final Object... vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
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
    public Core.Type_any vx_empty() {
      return e_is_type_from_any_typelist;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_type_from_any_typelist;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_typelist typelist = Core.f_any_from_any(Core.t_typelist, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_is_type_from_any_typelist(val, typelist);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist) {
      return Type.f_is_type_from_any_typelist(val, typelist);
    }

  }

  public static final Func_is_type_from_any_typelist e_is_type_from_any_typelist = new Type.Class_is_type_from_any_typelist();
  public static final Func_is_type_from_any_typelist t_is_type_from_any_typelist = new Type.Class_is_type_from_any_typelist();

  public static Core.Type_boolean f_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_start_reduce(
      Core.t_boolean,
      typelist,
      Core.vx_new_boolean(false),
      Core.t_any_from_reduce.vx_fn_new((result_any, type_any) -> {
        Core.Type_boolean result = Core.f_any_from_any(Core.t_boolean, result_any);
        Core.Type_any type = Core.f_any_from_any(Core.t_any, type_any);
        return 
        Core.f_or(
          result,
          Type.f_is_type(val, type)
        );
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
  public interface Func_string_lowercase extends Core.Func_any_from_any {
    public Core.Type_string vx_string_lowercase(final Core.Type_string text);
  }

  public static class Class_string_lowercase extends Core.Class_base implements Func_string_lowercase {

    @Override
    public Type.Func_string_lowercase vx_new(final Object... vals) {
      Class_string_lowercase output = new Class_string_lowercase();
      return output;
    }

    @Override
    public Type.Func_string_lowercase vx_copy(final Object... vals) {
      Class_string_lowercase output = new Class_string_lowercase();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string-lowercase", // name
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
    public Core.Type_any vx_empty() {
      return e_string_lowercase;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_lowercase;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Type.f_string_lowercase(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_string_lowercase(text);
      return output;
    }

    @Override
    public Core.Type_string vx_string_lowercase(final Core.Type_string text) {
      return Type.f_string_lowercase(text);
    }

  }

  public static final Func_string_lowercase e_string_lowercase = new Type.Class_string_lowercase();
  public static final Func_string_lowercase t_string_lowercase = new Type.Class_string_lowercase();

  public static Core.Type_string f_string_lowercase(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Type.vx_string_lowercase(text);
    return output;
  }

  /**
   * @function string_outdent
   * Returns a string replacing leading whitespace on all lines based on first line.
   * @param  {string} text
   * @return {string}
   * (func string-outdent)
   */
  public interface Func_string_outdent extends Core.Func_any_from_any {
    public Core.Type_string vx_string_outdent(final Core.Type_string text);
  }

  public static class Class_string_outdent extends Core.Class_base implements Func_string_outdent {

    @Override
    public Type.Func_string_outdent vx_new(final Object... vals) {
      Class_string_outdent output = new Class_string_outdent();
      return output;
    }

    @Override
    public Type.Func_string_outdent vx_copy(final Object... vals) {
      Class_string_outdent output = new Class_string_outdent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string-outdent", // name
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
    public Core.Type_any vx_empty() {
      return e_string_outdent;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_outdent;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Type.f_string_outdent(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_string_outdent(text);
      return output;
    }

    @Override
    public Core.Type_string vx_string_outdent(final Core.Type_string text) {
      return Type.f_string_outdent(text);
    }

  }

  public static final Func_string_outdent e_string_outdent = new Type.Class_string_outdent();
  public static final Func_string_outdent t_string_outdent = new Type.Class_string_outdent();

  public static Core.Type_string f_string_outdent(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int pos = Type.f_int_from_string_findkeyword(text, Core.vx_new_string(":nonwhitespace"));
        return Core.f_if_2(
          Core.t_string,
          Core.vx_new(Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_int(0), pos);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return text;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_let(
                  Core.t_string,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    final Core.Type_string indent = Type.f_string_from_string_end(
                      text,
                      Core.f_minus1(pos)
                    );
                    final Core.Type_string rest = Type.f_string_from_string_start(text, pos);
                    final Core.Type_int linepos = Type.f_int_from_string_find(indent, Core.vx_new_string("\n"));
                    final Core.Type_string outdent = Core.f_if_1(
                      Core.t_string,
                      Core.f_eq(Core.vx_new_int(0), linepos),
                      Core.vx_new_string(""),
                      Core.vx_new_string("\n")
                    );
                    return Core.f_string_from_string_find_replace(rest, indent, outdent);
                  })
                );
              })
            )
          )
        );
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
  public interface Func_string_trim extends Core.Func_any_from_any {
    public Core.Type_string vx_string_trim(final Core.Type_string text);
  }

  public static class Class_string_trim extends Core.Class_base implements Func_string_trim {

    @Override
    public Type.Func_string_trim vx_new(final Object... vals) {
      Class_string_trim output = new Class_string_trim();
      return output;
    }

    @Override
    public Type.Func_string_trim vx_copy(final Object... vals) {
      Class_string_trim output = new Class_string_trim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string-trim", // name
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
    public Core.Type_any vx_empty() {
      return e_string_trim;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_trim;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Type.f_string_trim(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_string_trim(text);
      return output;
    }

    @Override
    public Core.Type_string vx_string_trim(final Core.Type_string text) {
      return Type.f_string_trim(text);
    }

  }

  public static final Func_string_trim e_string_trim = new Type.Class_string_trim();
  public static final Func_string_trim t_string_trim = new Type.Class_string_trim();

  public static Core.Type_string f_string_trim(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Type.vx_string_trim(text);
    return output;
  }

  /**
   * @function string_uppercase
   * Returns uppercase version of string
   * @param  {string} text
   * @return {string}
   * (func string-uppercase)
   */
  public interface Func_string_uppercase extends Core.Func_any_from_any {
    public Core.Type_string vx_string_uppercase(final Core.Type_string text);
  }

  public static class Class_string_uppercase extends Core.Class_base implements Func_string_uppercase {

    @Override
    public Type.Func_string_uppercase vx_new(final Object... vals) {
      Class_string_uppercase output = new Class_string_uppercase();
      return output;
    }

    @Override
    public Type.Func_string_uppercase vx_copy(final Object... vals) {
      Class_string_uppercase output = new Class_string_uppercase();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string-uppercase", // name
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
    public Core.Type_any vx_empty() {
      return e_string_uppercase;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_uppercase;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Type.f_string_uppercase(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_string_uppercase(text);
      return output;
    }

    @Override
    public Core.Type_string vx_string_uppercase(final Core.Type_string text) {
      return Type.f_string_uppercase(text);
    }

  }

  public static final Func_string_uppercase e_string_uppercase = new Type.Class_string_uppercase();
  public static final Func_string_uppercase t_string_uppercase = new Type.Class_string_uppercase();

  public static Core.Type_string f_string_uppercase(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Type.vx_string_uppercase(text);
    return output;
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} val
   * @return {string}
   * (func string<-int)
   */
  public interface Func_string_from_int extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_int(final Core.Type_int val);
  }

  public static class Class_string_from_int extends Core.Class_base implements Func_string_from_int {

    @Override
    public Type.Func_string_from_int vx_new(final Object... vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    @Override
    public Type.Func_string_from_int vx_copy(final Object... vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string<-int", // name
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
    public Core.Type_any vx_empty() {
      return e_string_from_int;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_from_int;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Type.f_string_from_int(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int val = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_string_from_int(val);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_int(final Core.Type_int val) {
      return Type.f_string_from_int(val);
    }

  }

  public static final Func_string_from_int e_string_from_int = new Type.Class_string_from_int();
  public static final Func_string_from_int t_string_from_int = new Type.Class_string_from_int();

  public static Core.Type_string f_string_from_int(final Core.Type_int val) {
    Core.Type_string output = Core.e_string;
    output = Core.f_switch(
      Core.t_string,
      val,
      Core.vx_new(Core.t_thenelselist,
        Core.f_case_1(
          Core.c_infinity,
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_string("infinity");
          })
        ),
        Core.f_case_1(
          Core.c_neginfinity,
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_string("neginfinity");
          })
        ),
        Core.f_case_1(
          Core.c_notanumber,
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_string("notanumber");
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Core.t_string,
              Core.vx_new(Core.t_anylist,
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
  public interface Func_string_from_string_end extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos);
  }

  public static class Class_string_from_string_end extends Core.Class_base implements Func_string_from_string_end {

    @Override
    public Type.Func_string_from_string_end vx_new(final Object... vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    @Override
    public Type.Func_string_from_string_end vx_copy(final Object... vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
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
    public Core.Type_any vx_empty() {
      return e_string_from_string_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_from_string_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int endpos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_string_from_string_end(text, endpos);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos) {
      return Type.f_string_from_string_end(text, endpos);
    }

  }

  public static final Func_string_from_string_end e_string_from_string_end = new Type.Class_string_from_string_end();
  public static final Func_string_from_string_end t_string_from_string_end = new Type.Class_string_from_string_end();

  public static Core.Type_string f_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos) {
    Core.Type_string output = Core.e_string;
    output = Type.f_string_from_string_start_end(text, Core.vx_new_int(1), endpos);
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
  public interface Func_string_from_string_start extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_string_start(final Core.Type_string text, final Core.Type_int startpos);
  }

  public static class Class_string_from_string_start extends Core.Class_base implements Func_string_from_string_start {

    @Override
    public Type.Func_string_from_string_start vx_new(final Object... vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    @Override
    public Type.Func_string_from_string_start vx_copy(final Object... vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
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
    public Core.Type_any vx_empty() {
      return e_string_from_string_start;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_from_string_start;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int startpos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_string_from_string_start(text, startpos);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_string_start(final Core.Type_string text, final Core.Type_int startpos) {
      return Type.f_string_from_string_start(text, startpos);
    }

  }

  public static final Func_string_from_string_start e_string_from_string_start = new Type.Class_string_from_string_start();
  public static final Func_string_from_string_start t_string_from_string_start = new Type.Class_string_from_string_start();

  public static Core.Type_string f_string_from_string_start(final Core.Type_string text, final Core.Type_int startpos) {
    Core.Type_string output = Core.e_string;
    output = Type.f_string_from_string_start_end(
      text,
      startpos,
      Core.f_length(text)
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
  public interface Func_string_from_string_start_end extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_string_from_string_start_end extends Core.Class_base implements Func_string_from_string_start_end {

    @Override
    public Type.Func_string_from_string_start_end vx_new(final Object... vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    @Override
    public Type.Func_string_from_string_start_end vx_copy(final Object... vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
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
    public Core.Type_any vx_empty() {
      return e_string_from_string_start_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_from_string_start_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Type.f_string_from_string_start_end(text, start, end);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end) {
      return Type.f_string_from_string_start_end(text, start, end);
    }

  }

  public static final Func_string_from_string_start_end e_string_from_string_start_end = new Type.Class_string_from_string_start_end();
  public static final Func_string_from_string_start_end t_string_from_string_start_end = new Type.Class_string_from_string_start_end();

  public static Core.Type_string f_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end) {
    Core.Type_string output = Core.e_string;
    String stext = Core.vx_string_from_string_start_end(text.vx_string(), start.vx_int(), end.vx_int());
    output = Core.vx_new_string(stext);
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
  public interface Func_string_from_stringlist_join extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim);
  }

  public static class Class_string_from_stringlist_join extends Core.Class_base implements Func_string_from_stringlist_join {

    @Override
    public Type.Func_string_from_stringlist_join vx_new(final Object... vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    @Override
    public Type.Func_string_from_stringlist_join vx_copy(final Object... vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
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
    public Core.Type_any vx_empty() {
      return e_string_from_stringlist_join;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_string_from_stringlist_join;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_stringlist vals = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string delim = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_string_from_stringlist_join(vals, delim);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim) {
      return Type.f_string_from_stringlist_join(vals, delim);
    }

  }

  public static final Func_string_from_stringlist_join e_string_from_stringlist_join = new Type.Class_string_from_stringlist_join();
  public static final Func_string_from_stringlist_join t_string_from_stringlist_join = new Type.Class_string_from_stringlist_join();

  public static Core.Type_string f_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim) {
    Core.Type_string output = Core.e_string;
    output = Type.vx_string_from_stringlist_join(vals, delim);
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
  public interface Func_stringlist_from_string_split extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_stringlist vx_stringlist_from_string_split(final Core.Type_string text, final Core.Type_string delim);
  }

  public static class Class_stringlist_from_string_split extends Core.Class_base implements Func_stringlist_from_string_split {

    @Override
    public Type.Func_stringlist_from_string_split vx_new(final Object... vals) {
      Class_stringlist_from_string_split output = new Class_stringlist_from_string_split();
      return output;
    }

    @Override
    public Type.Func_stringlist_from_string_split vx_copy(final Object... vals) {
      Class_stringlist_from_string_split output = new Class_stringlist_from_string_split();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "stringlist<-string-split", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_stringlist_from_string_split;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_stringlist_from_string_split;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string delim = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Type.f_stringlist_from_string_split(text, delim);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist_from_string_split(final Core.Type_string text, final Core.Type_string delim) {
      return Type.f_stringlist_from_string_split(text, delim);
    }

  }

  public static final Func_stringlist_from_string_split e_stringlist_from_string_split = new Type.Class_stringlist_from_string_split();
  public static final Func_stringlist_from_string_split t_stringlist_from_string_split = new Type.Class_stringlist_from_string_split();

  public static Core.Type_stringlist f_stringlist_from_string_split(final Core.Type_string text, final Core.Type_string delim) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Type.vx_stringlist_from_string_split(text, delim);
    return output;
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} val
   * @return {stringlist}
   * (func traitnames<-any)
   */
  public interface Func_traitnames_from_any extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_traitnames_from_any(final Core.Type_any val);
  }

  public static class Class_traitnames_from_any extends Core.Class_base implements Func_traitnames_from_any {

    @Override
    public Type.Func_traitnames_from_any vx_new(final Object... vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    @Override
    public Type.Func_traitnames_from_any vx_copy(final Object... vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      return e_traitnames_from_any;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_traitnames_from_any;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_traitnames_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_traitnames_from_any(val);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_traitnames_from_any(final Core.Type_any val) {
      return Type.f_traitnames_from_any(val);
    }

  }

  public static final Func_traitnames_from_any e_traitnames_from_any = new Type.Class_traitnames_from_any();
  public static final Func_traitnames_from_any t_traitnames_from_any = new Type.Class_traitnames_from_any();

  public static Core.Type_stringlist f_traitnames_from_any(final Core.Type_any val) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_typenames_from_typelist(
      Type.f_traits_from_any(val)
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
  public interface Func_traits_from_any extends Core.Func_any_from_any {
    public Core.Type_typelist vx_traits_from_any(final Core.Type_any val);
  }

  public static class Class_traits_from_any extends Core.Class_base implements Func_traits_from_any {

    @Override
    public Type.Func_traits_from_any vx_new(final Object... vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    @Override
    public Type.Func_traits_from_any vx_copy(final Object... vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "traits<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
      return e_traits_from_any;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_traits_from_any;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_traits_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_traits_from_any(val);
      return output;
    }

    @Override
    public Core.Type_typelist vx_traits_from_any(final Core.Type_any val) {
      return Type.f_traits_from_any(val);
    }

  }

  public static final Func_traits_from_any e_traits_from_any = new Type.Class_traits_from_any();
  public static final Func_traits_from_any t_traits_from_any = new Type.Class_traits_from_any();

  public static Core.Type_typelist f_traits_from_any(final Core.Type_any val) {
    Core.Type_typelist output = Core.e_typelist;
    output = Core.f_traits_from_typedef(
      Core.f_typedef_from_any(val)
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
  public interface Func_traits_from_typedef extends Core.Func_any_from_any {
    public Core.Type_typelist vx_traits_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_traits_from_typedef extends Core.Class_base implements Func_traits_from_typedef {

    @Override
    public Type.Func_traits_from_typedef vx_new(final Object... vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    @Override
    public Type.Func_traits_from_typedef vx_copy(final Object... vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
      return e_traits_from_typedef;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_traits_from_typedef;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Type.f_traits_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Type.f_traits_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_typelist vx_traits_from_typedef(final Core.Type_typedef vtypedef) {
      return Type.f_traits_from_typedef(vtypedef);
    }

  }

  public static final Func_traits_from_typedef e_traits_from_typedef = new Type.Class_traits_from_typedef();
  public static final Func_traits_from_typedef t_traits_from_typedef = new Type.Class_traits_from_typedef();

  public static Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_typelist output = Core.e_typelist;
    output = vtypedef.traits();
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    mapfunc.put("allowtypenames<-type", Type.t_allowtypenames_from_type);
    mapfunc.put("allowtypes<-type", Type.t_allowtypes_from_type);
    mapfunc.put("any<-int", Type.t_any_from_int);
    mapfunc.put("boolean<-string-ends", Type.t_boolean_from_string_ends);
    mapfunc.put("boolean<-string-starts", Type.t_boolean_from_string_starts);
    mapfunc.put("int<-string-find", Type.t_int_from_string_find);
    mapfunc.put("int<-string-findkeyword", Type.t_int_from_string_findkeyword);
    mapfunc.put("int<-string-findlast", Type.t_int_from_string_findlast);
    mapfunc.put("is-boolean", Type.t_is_boolean);
    mapfunc.put("is-decimal", Type.t_is_decimal);
    mapfunc.put("is-none", Type.t_is_none);
    mapfunc.put("is-string", Type.t_is_string);
    mapfunc.put("is-type", Type.t_is_type);
    mapfunc.put("is-type<-any-typelist", Type.t_is_type_from_any_typelist);
    mapfunc.put("string-lowercase", Type.t_string_lowercase);
    mapfunc.put("string-outdent", Type.t_string_outdent);
    mapfunc.put("string-trim", Type.t_string_trim);
    mapfunc.put("string-uppercase", Type.t_string_uppercase);
    mapfunc.put("string<-int", Type.t_string_from_int);
    mapfunc.put("string<-string-end", Type.t_string_from_string_end);
    mapfunc.put("string<-string-start", Type.t_string_from_string_start);
    mapfunc.put("string<-string-start-end", Type.t_string_from_string_start_end);
    mapfunc.put("string<-stringlist-join", Type.t_string_from_stringlist_join);
    mapfunc.put("stringlist<-string-split", Type.t_stringlist_from_string_split);
    mapfunc.put("traitnames<-any", Type.t_traitnames_from_any);
    mapfunc.put("traits<-any", Type.t_traits_from_any);
    mapfunc.put("traits<-typedef", Type.t_traits_from_typedef);
    Core.vx_global_package_set("vx/type", maptype, mapconst, mapfunc);
  }

}
