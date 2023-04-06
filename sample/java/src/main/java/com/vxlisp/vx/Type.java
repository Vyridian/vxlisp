package com.vxlisp.vx;

import java.util.List;


public final class Type {

  /**
   * @function allowtypenames_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {stringlist}
   * (func allowtypenames<-type)
   */
  public static interface Func_allowtypenames_from_type extends Core.Func_any_from_any {
    public Core.Type_stringlist f_allowtypenames_from_type(final Core.Type_any type);
  }

  public static class Class_allowtypenames_from_type extends Core.Class_base implements Func_allowtypenames_from_type {

    @Override
    public Func_allowtypenames_from_type vx_new(Object... vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    @Override
    public Func_allowtypenames_from_type vx_copy(Object... vals) {
      Class_allowtypenames_from_type output = new Class_allowtypenames_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_allowtypenames_from_type vx_empty() {return e_allowtypenames_from_type;}
    @Override
    public Func_allowtypenames_from_type vx_type() {return t_allowtypenames_from_type;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_allowtypenames_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_allowtypenames_from_type(type);
      return output;
    }

    @Override
    public Core.Type_stringlist f_allowtypenames_from_type(final Core.Type_any type) {
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
   * Get the name of a given type
   * @param  {any} type
   * @return {typelist}
   * (func allowtypes<-type)
   */
  public static interface Func_allowtypes_from_type extends Core.Func_any_from_any {
    public Core.Type_typelist f_allowtypes_from_type(final Core.Type_any type);
  }

  public static class Class_allowtypes_from_type extends Core.Class_base implements Func_allowtypes_from_type {

    @Override
    public Func_allowtypes_from_type vx_new(Object... vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    @Override
    public Func_allowtypes_from_type vx_copy(Object... vals) {
      Class_allowtypes_from_type output = new Class_allowtypes_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_allowtypes_from_type vx_empty() {return e_allowtypes_from_type;}
    @Override
    public Func_allowtypes_from_type vx_type() {return t_allowtypes_from_type;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_allowtypes_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_allowtypes_from_type(type);
      return output;
    }

    @Override
    public Core.Type_typelist f_allowtypes_from_type(final Core.Type_any type) {
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
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   * (func is-boolean)
   */
  public static interface Func_is_boolean extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_boolean(final Core.Type_any value);
  }

  public static class Class_is_boolean extends Core.Class_base implements Func_is_boolean {

    @Override
    public Func_is_boolean vx_new(Object... vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    @Override
    public Func_is_boolean vx_copy(Object... vals) {
      Class_is_boolean output = new Class_is_boolean();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_boolean vx_empty() {return e_is_boolean;}
    @Override
    public Func_is_boolean vx_type() {return t_is_boolean;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_boolean(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_is_boolean(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_boolean(final Core.Type_any value) {
      return Type.f_is_boolean(value);
    }

  }

  public static final Func_is_boolean e_is_boolean = new Type.Class_is_boolean();
  public static final Func_is_boolean t_is_boolean = new Type.Class_is_boolean();

  public static Core.Type_boolean f_is_boolean(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string("boolean"),
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
  public static interface Func_is_decimal extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_decimal(final Core.Type_any value);
  }

  public static class Class_is_decimal extends Core.Class_base implements Func_is_decimal {

    @Override
    public Func_is_decimal vx_new(Object... vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    @Override
    public Func_is_decimal vx_copy(Object... vals) {
      Class_is_decimal output = new Class_is_decimal();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_decimal vx_empty() {return e_is_decimal;}
    @Override
    public Func_is_decimal vx_type() {return t_is_decimal;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_decimal(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_is_decimal(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_decimal(final Core.Type_any value) {
      return Type.f_is_decimal(value);
    }

  }

  public static final Func_is_decimal e_is_decimal = new Type.Class_is_decimal();
  public static final Func_is_decimal t_is_decimal = new Type.Class_is_decimal();

  public static Core.Type_boolean f_is_decimal(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string("decimal"),
      Core.f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_float
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
        "vx/type", // pkgname
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_float(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_is_float(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_float(final Core.Type_any value) {
      return Type.f_is_float(value);
    }

  }

  public static final Func_is_float e_is_float = new Type.Class_is_float();
  public static final Func_is_float t_is_float = new Type.Class_is_float();

  public static Core.Type_boolean f_is_float(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string("float"),
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
  public static interface Func_is_none extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_none(final Core.Type_any value);
  }

  public static class Class_is_none extends Core.Class_base implements Func_is_none {

    @Override
    public Func_is_none vx_new(Object... vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    @Override
    public Func_is_none vx_copy(Object... vals) {
      Class_is_none output = new Class_is_none();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_none vx_empty() {return e_is_none;}
    @Override
    public Func_is_none vx_type() {return t_is_none;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_none(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_is_none(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_none(final Core.Type_any value) {
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
  public static interface Func_is_string extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_string(final Core.Type_any value);
  }

  public static class Class_is_string extends Core.Class_base implements Func_is_string {

    @Override
    public Func_is_string vx_new(Object... vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    @Override
    public Func_is_string vx_copy(Object... vals) {
      Class_is_string output = new Class_is_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_string vx_empty() {return e_is_string;}
    @Override
    public Func_is_string vx_type() {return t_is_string;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_is_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_is_string(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_string(final Core.Type_any value) {
      return Type.f_is_string(value);
    }

  }

  public static final Func_is_string e_is_string = new Type.Class_is_string();
  public static final Func_is_string t_is_string = new Type.Class_is_string();

  public static Core.Type_boolean f_is_string(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string("vx/core/string"),
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
  public static interface Func_is_type extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_is_type(final Core.Type_any val, final Core.Type_any type);
  }

  public static class Class_is_type extends Core.Class_base implements Func_is_type {

    @Override
    public Func_is_type vx_new(Object... vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    @Override
    public Func_is_type vx_copy(Object... vals) {
      Class_is_type output = new Class_is_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_type vx_empty() {return e_is_type;}
    @Override
    public Func_is_type vx_type() {return t_is_type;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Type.f_is_type(val, type);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_type(final Core.Type_any val, final Core.Type_any type) {
      return Type.f_is_type(val, type);
    }

  }

  public static final Func_is_type e_is_type = new Type.Class_is_type();
  public static final Func_is_type t_is_type = new Type.Class_is_type();

  public static Core.Type_boolean f_is_type(final Core.Type_any val, final Core.Type_any type) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_or_1(
      Core.t_booleanlist.vx_new(
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
  public static interface Func_is_type_from_any_typelist extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist);
  }

  public static class Class_is_type_from_any_typelist extends Core.Class_base implements Func_is_type_from_any_typelist {

    @Override
    public Func_is_type_from_any_typelist vx_new(Object... vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    @Override
    public Func_is_type_from_any_typelist vx_copy(Object... vals) {
      Class_is_type_from_any_typelist output = new Class_is_type_from_any_typelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_is_type_from_any_typelist vx_empty() {return e_is_type_from_any_typelist;}
    @Override
    public Func_is_type_from_any_typelist vx_type() {return t_is_type_from_any_typelist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_typelist typelist = Core.f_any_from_any(Core.t_typelist, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Type.f_is_type_from_any_typelist(val, typelist);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist) {
      return Type.f_is_type_from_any_typelist(val, typelist);
    }

  }

  public static final Func_is_type_from_any_typelist e_is_type_from_any_typelist = new Type.Class_is_type_from_any_typelist();
  public static final Func_is_type_from_any_typelist t_is_type_from_any_typelist = new Type.Class_is_type_from_any_typelist();

  public static Core.Type_boolean f_is_type_from_any_typelist(final Core.Type_any val, final Core.Type_typelist typelist) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_reduce(
      Core.t_boolean,
      typelist,
      Core.t_boolean.vx_new_from_boolean(false),
      Core.t_any_from_reduce.fn_new((result_any, type_any) -> {
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
   * @function length_from_string
   * Returns length of a string.
   * @param  {string} text
   * @return {int}
   * (func length<-string)
   */
  public static interface Func_length_from_string extends Core.Func_any_from_any {
    public Core.Type_int f_length_from_string(final Core.Type_string text);
  }

  public static class Class_length_from_string extends Core.Class_base implements Func_length_from_string {

    @Override
    public Func_length_from_string vx_new(Object... vals) {
      Class_length_from_string output = new Class_length_from_string();
      return output;
    }

    @Override
    public Func_length_from_string vx_copy(Object... vals) {
      Class_length_from_string output = new Class_length_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/type", // pkgname
        "length<-string", // name
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
    public Func_length_from_string vx_empty() {return e_length_from_string;}
    @Override
    public Func_length_from_string vx_type() {return t_length_from_string;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Type.f_length_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_length_from_string(text);
      return output;
    }

    @Override
    public Core.Type_int f_length_from_string(final Core.Type_string text) {
      return Type.f_length_from_string(text);
    }

  }

  public static final Func_length_from_string e_length_from_string = new Type.Class_length_from_string();
  public static final Func_length_from_string t_length_from_string = new Type.Class_length_from_string();

  public static Core.Type_int f_length_from_string(final Core.Type_string text) {
    Core.Type_int output = Core.e_int;
    int len = text.vx_string().length();
    output = Core.t_int.vx_new_from_int(len);
    return output;
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} val
   * @return {string}
   * (func string<-int)
   */
  public static interface Func_string_from_int extends Core.Func_any_from_any {
    public Core.Type_string f_string_from_int(final Core.Type_int val);
  }

  public static class Class_string_from_int extends Core.Class_base implements Func_string_from_int {

    @Override
    public Func_string_from_int vx_new(Object... vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    @Override
    public Func_string_from_int vx_copy(Object... vals) {
      Class_string_from_int output = new Class_string_from_int();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_string_from_int vx_empty() {return e_string_from_int;}
    @Override
    public Func_string_from_int vx_type() {return t_string_from_int;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Type.f_string_from_int(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int val = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_string_from_int(val);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_int(final Core.Type_int val) {
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
      Core.t_thenelselist.vx_new(
        Core.f_case_1(
          Core.c_infinity,
          Core.t_any_from_func.fn_new(() -> {
            return Core.t_string.vx_new_from_string("infinity");
          })
        ),
        Core.f_case_1(
          Core.c_neginfinity,
          Core.t_any_from_func.fn_new(() -> {
            return Core.t_string.vx_new_from_string("neginfinity");
          })
        ),
        Core.f_case_1(
          Core.c_notanumber,
          Core.t_any_from_func.fn_new(() -> {
            return Core.t_string.vx_new_from_string("notanumber");
          })
        ),
        Core.f_else(
          Core.t_any_from_func.fn_new(() -> {
            return Core.f_new(
              Core.t_string,
              Core.t_anylist.vx_new(
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
  public static interface Func_string_from_string_end extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos);
  }

  public static class Class_string_from_string_end extends Core.Class_base implements Func_string_from_string_end {

    @Override
    public Func_string_from_string_end vx_new(Object... vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    @Override
    public Func_string_from_string_end vx_copy(Object... vals) {
      Class_string_from_string_end output = new Class_string_from_string_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_string_from_string_end vx_empty() {return e_string_from_string_end;}
    @Override
    public Func_string_from_string_end vx_type() {return t_string_from_string_end;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int endpos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Type.f_string_from_string_end(text, endpos);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos) {
      return Type.f_string_from_string_end(text, endpos);
    }

  }

  public static final Func_string_from_string_end e_string_from_string_end = new Type.Class_string_from_string_end();
  public static final Func_string_from_string_end t_string_from_string_end = new Type.Class_string_from_string_end();

  public static Core.Type_string f_string_from_string_end(final Core.Type_string text, final Core.Type_int endpos) {
    Core.Type_string output = Core.e_string;
    output = Type.f_string_from_string_start_end(text, Core.t_int.vx_new_from_int(0), endpos);
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
  public static interface Func_string_from_string_start extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_from_string_start(final Core.Type_string text, final Core.Type_int startpos);
  }

  public static class Class_string_from_string_start extends Core.Class_base implements Func_string_from_string_start {

    @Override
    public Func_string_from_string_start vx_new(Object... vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    @Override
    public Func_string_from_string_start vx_copy(Object... vals) {
      Class_string_from_string_start output = new Class_string_from_string_start();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_string_from_string_start vx_empty() {return e_string_from_string_start;}
    @Override
    public Func_string_from_string_start vx_type() {return t_string_from_string_start;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int startpos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Type.f_string_from_string_start(text, startpos);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_string_start(final Core.Type_string text, final Core.Type_int startpos) {
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
      Type.f_length_from_string(text)
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
  public static interface Func_string_from_string_start_end extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_string_from_string_start_end extends Core.Class_base implements Func_string_from_string_start_end {

    @Override
    public Func_string_from_string_start_end vx_new(Object... vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    @Override
    public Func_string_from_string_start_end vx_copy(Object... vals) {
      Class_string_from_string_start_end output = new Class_string_from_string_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_string_from_string_start_end vx_empty() {return e_string_from_string_start_end;}
    @Override
    public Func_string_from_string_start_end vx_type() {return t_string_from_string_start_end;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Type.f_string_from_string_start_end(text, start, end);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end) {
      return Type.f_string_from_string_start_end(text, start, end);
    }

  }

  public static final Func_string_from_string_start_end e_string_from_string_start_end = new Type.Class_string_from_string_start_end();
  public static final Func_string_from_string_start_end t_string_from_string_start_end = new Type.Class_string_from_string_start_end();

  public static Core.Type_string f_string_from_string_start_end(final Core.Type_string text, final Core.Type_int start, final Core.Type_int end) {
    Core.Type_string output = Core.e_string;
    String stext = text.vx_string();
    int istart = start.vx_int();
    int iend = end.vx_int();
    int ilen = stext.length();
    if (istart >= ilen) {
      stext = "";
    } else if (iend <= istart) {
      stext = "";
    } else if (iend >= ilen) {
      stext = stext.substring(istart, ilen);
    } else {
      stext = stext.substring(istart, iend);
    }
    output = Core.t_string.vx_new_from_string(stext);
    return output;
  }

  /**
   * @function string_from_stringlist_join
   * @param  {stringlist} vals
   * @param  {string} delim
   * @return {string}
   * (func string<-stringlist-join)
   */
  public static interface Func_string_from_stringlist_join extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim);
  }

  public static class Class_string_from_stringlist_join extends Core.Class_base implements Func_string_from_stringlist_join {

    @Override
    public Func_string_from_stringlist_join vx_new(Object... vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    @Override
    public Func_string_from_stringlist_join vx_copy(Object... vals) {
      Class_string_from_stringlist_join output = new Class_string_from_stringlist_join();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_string_from_stringlist_join vx_empty() {return e_string_from_stringlist_join;}
    @Override
    public Func_string_from_stringlist_join vx_type() {return t_string_from_stringlist_join;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_stringlist vals = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string delim = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Type.f_string_from_stringlist_join(vals, delim);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim) {
      return Type.f_string_from_stringlist_join(vals, delim);
    }

  }

  public static final Func_string_from_stringlist_join e_string_from_stringlist_join = new Type.Class_string_from_stringlist_join();
  public static final Func_string_from_stringlist_join t_string_from_stringlist_join = new Type.Class_string_from_stringlist_join();

  public static Core.Type_string f_string_from_stringlist_join(final Core.Type_stringlist vals, final Core.Type_string delim) {
    Core.Type_string output = Core.e_string;
    List<String> listvalstring = Core.arraylist_from_arraylist_fn(vals.vx_list(), (item) -> {
      Core.Type_string valstring = Core.f_any_from_any(Core.t_string, item);
      return valstring.vx_string();
    });
    String stext = String.join(delim.vx_string(), listvalstring);
    output = Core.t_string.vx_new_from_string(stext);
    return output;
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} val
   * @return {stringlist}
   * (func traitnames<-any)
   */
  public static interface Func_traitnames_from_any extends Core.Func_any_from_any {
    public Core.Type_stringlist f_traitnames_from_any(final Core.Type_any val);
  }

  public static class Class_traitnames_from_any extends Core.Class_base implements Func_traitnames_from_any {

    @Override
    public Func_traitnames_from_any vx_new(Object... vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    @Override
    public Func_traitnames_from_any vx_copy(Object... vals) {
      Class_traitnames_from_any output = new Class_traitnames_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_traitnames_from_any vx_empty() {return e_traitnames_from_any;}
    @Override
    public Func_traitnames_from_any vx_type() {return t_traitnames_from_any;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_traitnames_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_traitnames_from_any(val);
      return output;
    }

    @Override
    public Core.Type_stringlist f_traitnames_from_any(final Core.Type_any val) {
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
  public static interface Func_traits_from_any extends Core.Func_any_from_any {
    public Core.Type_typelist f_traits_from_any(final Core.Type_any val);
  }

  public static class Class_traits_from_any extends Core.Class_base implements Func_traits_from_any {

    @Override
    public Func_traits_from_any vx_new(Object... vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    @Override
    public Func_traits_from_any vx_copy(Object... vals) {
      Class_traits_from_any output = new Class_traits_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_traits_from_any vx_empty() {return e_traits_from_any;}
    @Override
    public Func_traits_from_any vx_type() {return t_traits_from_any;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Type.f_traits_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_traits_from_any(val);
      return output;
    }

    @Override
    public Core.Type_typelist f_traits_from_any(final Core.Type_any val) {
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
   * @param  {typedef} typedef
   * @return {typelist}
   * (func traits<-typedef)
   */
  public static interface Func_traits_from_typedef extends Core.Func_any_from_any {
    public Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef typedef);
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
        "vx/type", // pkgname
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Type.f_traits_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef typedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Type.f_traits_from_typedef(typedef);
      return output;
    }

    @Override
    public Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef typedef) {
      return Type.f_traits_from_typedef(typedef);
    }

  }

  public static final Func_traits_from_typedef e_traits_from_typedef = new Type.Class_traits_from_typedef();
  public static final Func_traits_from_typedef t_traits_from_typedef = new Type.Class_traits_from_typedef();

  public static Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef typedef) {
    Core.Type_typelist output = Core.e_typelist;
    output = typedef.traits();
    return output;
  }


}
