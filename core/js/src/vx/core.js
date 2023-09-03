'strict mode'


export default class vx_core {

  /**
   * type: any
   * Any Value for Variant Type
   */
  static t_any = {}

  /**
   * type: any-async<-func
   * A sync or async function that returns one value.
   */
  static t_any_async_from_func = {}

  /**
   * type: any<-anylist
   * List of Any
   */
  static t_any_from_anylist = {}

  /**
   * type: anylist
   */
  static t_anylist = {}

  /**
   * type: anytype
   * Any Type that allows any Type as a Value
   */
  static t_anytype = {}

  /**
   * type: arg
   * A function argument
   */
  static t_arg = {}

  /**
   * type: arglist
   * A list of arg
   */
  static t_arglist = {}

  /**
   * type: argmap
   * A map of arg
   */
  static t_argmap = {}

  /**
   * type: boolean
   */
  static t_boolean = {}

  /**
   * type: booleanlist
   */
  static t_booleanlist = {}

  /**
   * type: collection
   */
  static t_collection = {}

  /**
   * type: compilelanguages
   */
  static t_compilelanguages = {}

  /**
   * type: connect
   * General connect trait
   */
  static t_connect = {}

  /**
   * type: connectlist
   * List of connect
   */
  static t_connectlist = {}

  /**
   * type: connectmap
   * Map of connect
   */
  static t_connectmap = {}

  /**
   * type: const
   * Original Constant Class.
   */
  static t_const = {}

  /**
   * type: constdef
   * Const Definition Class for inspecting properties.
   */
  static t_constdef = {}

  /**
   * type: constlist
   * List of Const.
   */
  static t_constlist = {}

  /**
   * type: constmap
   * Map of Const.
   */
  static t_constmap = {}

  /**
   * type: context
   * Context
   */
  static t_context = {}

  /**
   * type: decimal
   * A clean version of float like Java BigDecimal.
   */
  static t_decimal = {}

  /**
   * type: error
   * Error Type
   */
  static t_error = {}

  /**
   * type: float
   */
  static t_float = {}

  /**
   * type: func
   * Original Function Class.
   */
  static t_func = {}

  /**
   * type: funcdef
   * Func Definition Class for inspecting properties.
   */
  static t_funcdef = {}

  /**
   * type: funclist
   * List of Func.
   */
  static t_funclist = {}

  /**
   * type: funcmap
   * Map of Func.
   */
  static t_funcmap = {}

  /**
   * type: int
   */
  static t_int = {}

  /**
   * type: intlist
   * A list of int.
   */
  static t_intlist = {}

  /**
   * type: intmap
   * A map of int.
   */
  static t_intmap = {}

  /**
   * type: list
   * A simple untyped list.
   */
  static t_list = {}

  /**
   * type: listtype
   * A generic type that extends :list.
   */
  static t_listtype = {}

  /**
   * type: map
   * A simple untyped map.
   */
  static t_map = {}

  /**
   * type: maptype
   * A generic type that extends :map.
   */
  static t_maptype = {}

  /**
   * type: mempool
   * Memory Pool
   */
  static t_mempool = {}

  /**
   * type: msg
   * Message Type for error handling
   */
  static t_msg = {}

  /**
   * type: msgblock
   * Block of Messages
   */
  static t_msgblock = {}

  /**
   * type: msgblocklist
   * List of Message Blocks
   */
  static t_msgblocklist = {}

  /**
   * type: msglist
   * List of Messages
   */
  static t_msglist = {}

  /**
   * type: none
   * No Type. No type is returned at all. e.g. Void
   */
  static t_none = {}

  /**
   * type: notype
   * No Type that allows no Types as a Value
   */
  static t_notype = {}

  /**
   * type: number
   * A generic number that could be int, float, or decimal.
   */
  static t_number = {}

  /**
   * type: numberlist
   * A list of number.
   */
  static t_numberlist = {}

  /**
   * type: numbermap
   * A map of number.
   */
  static t_numbermap = {}

  /**
   * type: package
   * A package that store types, consts and funcs.
   */
  static t_package = {}

  /**
   * type: packagemap
   */
  static t_packagemap = {}

  /**
   * type: permission
   * Permission
   */
  static t_permission = {}

  /**
   * type: permissionlist
   * List of Permission
   */
  static t_permissionlist = {}

  /**
   * type: permissionmap
   * Map of Permission
   */
  static t_permissionmap = {}

  /**
   * type: security
   * Security rules
   */
  static t_security = {}

  /**
   * type: session
   * Session
   */
  static t_session = {}

  /**
   * type: setting
   * Settings
   */
  static t_setting = {}

  /**
   * type: state
   */
  static t_state = {}

  /**
   * type: statelistener
   */
  static t_statelistener = {}

  /**
   * type: string
   */
  static t_string = {}

  /**
   * type: stringlist
   * A list of string.
   */
  static t_stringlist = {}

  /**
   * type: stringmap
   * A map of string.
   */
  static t_stringmap = {}

  /**
   * type: struct
   * Struct is the type of all structures/objects with properties.
   */
  static t_struct = {}

  /**
   * type: thenelse
   */
  static t_thenelse = {}

  /**
   * type: thenelselist
   */
  static t_thenelselist = {}

  /**
   * type: type
   * Original Type Class
   */
  static t_type = {}

  /**
   * type: typedef
   * Type Definition Class for inspecting Type properties.
   */
  static t_typedef = {}

  /**
   * type: typelist
   * List of Types
   */
  static t_typelist = {}

  /**
   * type: typemap
   * Map of Any Type Class
   */
  static t_typemap = {}

  /**
   * type: user
   * User Type
   */
  static t_user = {}

  /**
   * type: value
   */
  static t_value = {}
  /**
   * Constant: false
   * {boolean}
   */
  static c_false = false

  /**
   * Constant: globalpackagemap
   * {packagemap}
   */
  static c_globalpackagemap = {vx_type: vx_core.t_packagemap}

  /**
   * Constant: infinity
   * Infinity. Returned during unusual calculations.
   * {int}
   */
  static c_infinity = Infinity

  /**
   * Constant: mempool-active
   * Active Value Memory Pool
   * {mempool}
   */
  static c_mempool_active = {vx_type: vx_core.t_mempool}

  /**
   * Constant: msg-error
   * Message is an Error
   * {int}
   */
  static c_msg_error = 2

  /**
   * Constant: msg-info
   * Message is just information
   * {int}
   */
  static c_msg_info = 0

  /**
   * Constant: msg-severe
   * Message is a Severe Error
   * {int}
   */
  static c_msg_severe = 3

  /**
   * Constant: msg-warning
   * Message is a Warning
   * {int}
   */
  static c_msg_warning = 1

  /**
   * Constant: neginfinity
   * Negative Infinity. Returned during unusual calculations.
   * {int}
   */
  static c_neginfinity = -Infinity

  /**
   * Constant: newline
   * New line constant
   * {string}
   */
  static c_newline = "\n"

  /**
   * Constant: notanumber
   * Not a number. Returned during invalid calculations.
   * {int}
   */
  static c_notanumber = NaN

  /**
   * Constant: nothing
   * Nothing Value. Opposite of every other value. e.g. Nil, Null
   * {string}
   */
  static c_nothing = "nothing"

  /**
   * Constant: quote
   * Quotation mark constant
   * {string}
   */
  static c_quote = "\""

  /**
   * Constant: true
   * {boolean}
   */
  static c_true = true

  /**
   * @function not
   * Boolean not
   * @param  {boolean} val Thing to not
   * @return {boolean}
   */
  static t_not = {}
  static e_not = {vx_type: vx_core.t_not}

  static f_not(val) {
    let output = vx_core.e_boolean
    output = !val
    return output
  }

  /**
   * @function notempty
   * Returns true if text is not empty.
   * @param  {string} text
   * @return {boolean}
   */
  static t_notempty = {}
  static e_notempty = {vx_type: vx_core.t_notempty}

  static f_notempty(text) {
    let output = vx_core.e_boolean
    output = vx_core.f_not(
      vx_core.f_is_empty(text)
    )
    return output
  }

  /**
   * @function notempty
   * Returns true if val is not empty.
   * @param  {any} val
   * @return {boolean}
   */
  static t_notempty_1 = {}
  static e_notempty_1 = {vx_type: vx_core.t_notempty_1}

  static f_notempty_1(val) {
    let output = vx_core.e_boolean
    output = vx_core.f_not(
      vx_core.f_is_empty_1(val)
    )
    return output
  }

  /**
   * @function ne
   * Returns true if the first arg is not equal to any of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_ne = {}
  static e_ne = {vx_type: vx_core.t_ne}

  static f_ne(val1, val2) {
    let output = vx_core.e_boolean
    output = vx_core.f_not(
      vx_core.f_eq(val1, val2)
    )
    return output
  }

  /**
   * @function multiply
   * Math int multiply
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   */
  static t_multiply = {}
  static e_multiply = {vx_type: vx_core.t_multiply}

  static f_multiply(num1, num2) {
    let output = vx_core.e_int
    output = num1 * num2
    return output
  }

  /**
   * @function multiply
   * Math multipy
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   */
  static t_multiply_1 = {}
  static e_multiply_1 = {vx_type: vx_core.t_multiply_1}

  static f_multiply_1(num1, num2) {
    let output = vx_core.e_number
    output = num1 * num2
    return output
  }

  /**
   * @function multiply
   * Math multiply
   * @param  {intlist} ... nums
   * @return {int}
   */
  static t_multiply_2 = {}
  static e_multiply_2 = {vx_type: vx_core.t_multiply_2}

  static f_multiply_2(...nums) {
    let output = vx_core.e_int
    nums = vx_core.f_new(vx_core.t_intlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_int, "any-2": vx_core.t_int, "list-2": vx_core.t_intlist},
      nums,
      1,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_multiply(total, num))
    )
    return output
  }

  /**
   * @function multiply
   * Math multiply
   * @param  {numberlist} ... nums
   * @return {number}
   */
  static t_multiply_3 = {}
  static e_multiply_3 = {vx_type: vx_core.t_multiply_3}

  static f_multiply_3(...nums) {
    let output = vx_core.e_number
    nums = vx_core.f_new(vx_core.t_numberlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_number, "any-2": vx_core.t_number, "list-2": vx_core.t_numberlist},
      nums,
      1,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_multiply_1(total, num))
    )
    return output
  }

  /**
   * @function plus
   * Math int plus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   */
  static t_plus = {}
  static e_plus = {vx_type: vx_core.t_plus}

  static f_plus(num1, num2) {
    let output = vx_core.e_int
    output = num1 + num2
    return output
  }

  /**
   * @function plus
   * Math number plus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   */
  static t_plus_1 = {}
  static e_plus_1 = {vx_type: vx_core.t_plus_1}

  static f_plus_1(num1, num2) {
    let output = vx_core.e_number
    output = num1 + num2
    return output
  }

  /**
   * @function plus
   * Math int plus
   * @param  {intlist} ... nums
   * @return {int}
   */
  static t_plus_2 = {}
  static e_plus_2 = {vx_type: vx_core.t_plus_2}

  static f_plus_2(...nums) {
    let output = vx_core.e_int
    nums = vx_core.f_new(vx_core.t_intlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_int, "any-2": vx_core.t_int, "list-2": vx_core.t_intlist},
      nums,
      0,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_plus(total, num))
    )
    return output
  }

  /**
   * @function plus
   * Math number plus
   * @param  {numberlist} ... nums
   * @return {number}
   */
  static t_plus_3 = {}
  static e_plus_3 = {vx_type: vx_core.t_plus_3}

  static f_plus_3(...nums) {
    let output = vx_core.e_number
    nums = vx_core.f_new(vx_core.t_numberlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_number, "any-2": vx_core.t_number, "list-2": vx_core.t_numberlist},
      nums,
      0,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_plus_1(total, num))
    )
    return output
  }

  /**
   * @function plus1
   * Math int plus 1
   * @param  {int} num
   * @return {int}
   */
  static t_plus1 = {}
  static e_plus1 = {vx_type: vx_core.t_plus1}

  static f_plus1(num) {
    let output = vx_core.e_int
    output = num + 1
    return output
  }

  /**
   * @function minus
   * Math int minus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   */
  static t_minus = {}
  static e_minus = {vx_type: vx_core.t_minus}

  static f_minus(num1, num2) {
    let output = vx_core.e_int
    output = num1 - num2
    return output
  }

  /**
   * @function minus
   * Math number minus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   */
  static t_minus_1 = {}
  static e_minus_1 = {vx_type: vx_core.t_minus_1}

  static f_minus_1(num1, num2) {
    let output = vx_core.e_number
    output = num1 - num2
    return output
  }

  /**
   * @function minus
   * Math integer minus
   * @param  {intlist} ... nums
   * @return {int}
   */
  static t_minus_2 = {}
  static e_minus_2 = {vx_type: vx_core.t_minus_2}

  static f_minus_2(...nums) {
    let output = vx_core.e_int
    nums = vx_core.f_new(vx_core.t_intlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_int, "any-2": vx_core.t_int, "list-2": vx_core.t_intlist},
      nums,
      0,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_minus(total, num))
    )
    return output
  }

  /**
   * @function minus
   * Math number minus
   * @param  {numberlist} ... nums
   * @return {number}
   */
  static t_minus_3 = {}
  static e_minus_3 = {vx_type: vx_core.t_minus_3}

  static f_minus_3(...nums) {
    let output = vx_core.e_number
    nums = vx_core.f_new(vx_core.t_numberlist, ...nums)
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_number, "any-2": vx_core.t_number, "list-2": vx_core.t_numberlist},
      nums,
      0,
      vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
        vx_core.f_minus_1(total, num))
    )
    return output
  }

  /**
   * @function dotmethod
   * Not Recommened: Support for Object Oriented dot notation. e.g. (this.foo 'a') = this.foo('a')
   * @param  {any} object
   * @param  {string} method
   * @param  {anylist} ... params
   * @return {any}
   */
  static t_dotmethod = {}
  static e_dotmethod = {vx_type: vx_core.t_dotmethod}

  static f_dotmethod(object, method, ...params) {
    let output = vx_core.e_any
    params = vx_core.f_new(vx_core.t_anylist, ...params)
    output = object[method].apply(params)
    return output
  }

  /**
   * @function divide
   * Math divide
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   */
  static t_divide = {}
  static e_divide = {vx_type: vx_core.t_divide}

  static f_divide(num1, num2) {
    let output = vx_core.e_number
    output = num1 / num2
    return output
  }

  /**
   * @function lt
   * Returns true if the first arg is less than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_lt = {}
  static e_lt = {vx_type: vx_core.t_lt}

  static f_lt(val1, val2) {
    let output = vx_core.e_boolean
    output = vx_core.f_switch(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_int},
      vx_core.f_compare(val1, val2),
      vx_core.f_case_1(
        -1,
        vx_core.f_new(vx_core.t_any_from_func, () => {return true})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return false})
      )
    )
    return output
  }

  /**
   * @function lt
   * Returns true if the first arg is less than all of the other args
   * @param  {anylist} ... values
   * @return {boolean}
   */
  static t_lt_1 = {}
  static e_lt_1 = {vx_type: vx_core.t_lt_1}

  static f_lt_1(...values) {
    let output = vx_core.e_boolean
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    output = vx_core.f_any_from_list_reduce_next(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_any, "list-2": vx_core.t_anylist},
      values,
      true,
      vx_core.f_new(vx_core.t_any_from_reduce_next, (reduce, current, next) => 
        vx_core.f_and(
          reduce,
          vx_core.f_lt(current, next)
        ))
    )
    return output
  }

  /**
   * @function chainfirst
   * This is a special function that applies a value as the first argument for the first function.
   * The result is then used as the first argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {typemap} generic
   * @param  {any} value
   * @param  {any_from_anylist} ... fnlist
   * @return {any-1}
   */
  static t_chainfirst = {}
  static e_chainfirst = {vx_type: vx_core.t_chainfirst}

  static f_chainfirst(generic, value, ...fnlist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    fnlist = vx_core.f_new(vx_core.t_any_from_anylist, ...fnlist)
    return output
  }

  /**
   * @function chainlast
   * This is a special function that applies a value as the last argument for the first function.
   * The result is then used as the last argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {typemap} generic
   * @param  {any} value
   * @param  {any_from_anylist} ... fnlist
   * @return {any-1}
   */
  static t_chainlast = {}
  static e_chainlast = {vx_type: vx_core.t_chainlast}

  static f_chainlast(generic, value, ...fnlist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    fnlist = vx_core.f_new(vx_core.t_any_from_anylist, ...fnlist)
    return output
  }

  /**
   * @function le
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_le = {}
  static e_le = {vx_type: vx_core.t_le}

  static f_le(val1, val2) {
    let output = vx_core.e_boolean
    output = vx_core.f_not(
      vx_core.f_gt(val1, val2)
    )
    return output
  }

  /**
   * @function le
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {anylist} ... args
   * @return {boolean}
   */
  static t_le_1 = {}
  static e_le_1 = {vx_type: vx_core.t_le_1}

  static f_le_1(...args) {
    let output = vx_core.e_boolean
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_not(
      vx_core.f_gt_1(...args)
    )
    return output
  }

  /**
   * @function eq
   * Boolean equal/equivalent
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_eq = {}
  static e_eq = {vx_type: vx_core.t_eq}

  static f_eq(val1, val2) {
    let output = vx_core.e_boolean
    const native1 = vx_core.f_native_from_any(val1)
    const native2 = vx_core.f_native_from_any(val2)
    output = true
    if (val1 === val2) {
    } else if (native1 === native2) {
    } else {
      const typename = typeof native1
      switch (typename) {
      case 'number':
        if (isNaN(native1) && isNaN(native2)) {
        } else {
          output = false
        }
        break
      case 'boolean':
      case 'string':
        output = false
        break
      default:
        const type1 = vx_core.f_type_from_any(val1)
        const type2 = vx_core.f_type_from_any(val2)
        const extends1 = vx_core.f_extends_from_typedef(
      type1
    )
        const extends2 = vx_core.f_extends_from_typedef(
      type2
    )
        if (type1 != type2) {
          output = false
        } else if (extends1 != extends2) {
          output = false
        } else {
          switch (extends1) {
          case ':list':
            if (val1.length !== val2.length) {
              output = false
            } else if (val1.every((val, index) => val === val2[index])) {
              output = true
            } else {
              output = false
            }
            break
          case ':map':
            const keys1 = Object.keys(native1)
            const keys2 = Object.keys(native2)
            if (keys1.length !== keys2.length) {
              output = false
            } else if (keys1.every(key => native1[key] === native2[key])) {
              output = true
            } else {
              output = false
            }
            break
          default:
            output = false
            break
          }
          break
        }
        break
      }
    }
    return output
  }

  /**
   * @function eq
   * Boolean equal/equivalent
   * @param  {anylist} ... values
   * @return {boolean}
   */
  static t_eq_1 = {}
  static e_eq_1 = {vx_type: vx_core.t_eq_1}

  static f_eq_1(...values) {
    let output = vx_core.e_boolean
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    output = vx_core.f_any_from_list_reduce_next(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_any, "list-2": vx_core.t_anylist},
      values,
      false,
      vx_core.f_new(vx_core.t_any_from_reduce_next, (reduce, current, next) => 
        vx_core.f_and(
          reduce,
          vx_core.f_eq(current, next)
        ))
    )
    return output
  }

  /**
   * @function gt
   * Returns true if the first arg is greater than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_gt = {}
  static e_gt = {vx_type: vx_core.t_gt}

  static f_gt(val1, val2) {
    let output = vx_core.e_boolean
    output = vx_core.f_switch(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_int},
      vx_core.f_compare(val1, val2),
      vx_core.f_case_1(
        1,
        vx_core.f_new(vx_core.t_any_from_func, () => {return true})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return false})
      )
    )
    return output
  }

  /**
   * @function gt
   * Returns true if the first arg is greater than all of the other args
   * @param  {anylist} ... values
   * @return {boolean}
   */
  static t_gt_1 = {}
  static e_gt_1 = {vx_type: vx_core.t_gt_1}

  static f_gt_1(...values) {
    let output = vx_core.e_boolean
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    output = vx_core.f_any_from_list_reduce_next(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_any, "list-2": vx_core.t_anylist},
      values,
      true,
      vx_core.f_new(vx_core.t_any_from_reduce_next, (reduce, current, next) => 
        vx_core.f_and(
          reduce,
          vx_core.f_gt(current, next)
        ))
    )
    return output
  }

  /**
   * @function ge
   * Returns true if val1 is greater or equal to val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   */
  static t_ge = {}
  static e_ge = {vx_type: vx_core.t_ge}

  static f_ge(val1, val2) {
    let output = vx_core.e_boolean
    output = vx_core.f_not(
      vx_core.f_lt(val1, val2)
    )
    return output
  }

  /**
   * @function ge
   * Returns true if the first arg is greater or equal than all of the other args
   * @param  {anylist} ... args
   * @return {boolean}
   */
  static t_ge_1 = {}
  static e_ge_1 = {vx_type: vx_core.t_ge_1}

  static f_ge_1(...args) {
    let output = vx_core.e_boolean
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_not(
      vx_core.f_lt_1(...args)
    )
    return output
  }

  /**
   * @function allowtypenames_from_typedef
   * Return allow name list from type
   * @param  {typedef} vtypedef
   * @return {stringlist}
   */
  static t_allowtypenames_from_typedef = {}
  static e_allowtypenames_from_typedef = {vx_type: vx_core.t_allowtypenames_from_typedef}

  static f_allowtypenames_from_typedef(vtypedef) {
    let output = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_core.f_allowtypes_from_typedef(vtypedef)
    )
    return output
  }

  /**
   * @function allowtypes_from_typedef
   * Return allow type list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   */
  static t_allowtypes_from_typedef = {}
  static e_allowtypes_from_typedef = {vx_type: vx_core.t_allowtypes_from_typedef}

  static f_allowtypes_from_typedef(vtypedef) {
    let output = vx_core.e_typelist
    output = vtypedef['vx_value']['allowtypes']
    return output
  }

  /**
   * @function and
   * Returns true if all values are true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   */
  static t_and = {}
  static e_and = {vx_type: vx_core.t_and}

  static f_and(val1, val2) {
    let output = vx_core.e_boolean
    if (val1 && val2) {
      output = true
    } else {
      output = false
    }
    return output
  }

  /**
   * @function and
   * Returns true if all values are true
   * @param  {booleanlist} ... values
   * @return {boolean}
   */
  static t_and_1 = {}
  static e_and_1 = {vx_type: vx_core.t_and_1}

  static f_and_1(...values) {
    let output = vx_core.e_boolean
    values = vx_core.f_new(vx_core.t_booleanlist, ...values)
    output = vx_core.f_switch(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_int},
      vx_core.f_length_from_list(values),
      vx_core.f_case_1(
        0,
        vx_core.f_new(vx_core.t_any_from_func, () => {return true})
      ),
      vx_core.f_case_1(
        1,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_any_from_list({"any-1": vx_core.t_boolean, "list-1": vx_core.t_booleanlist}, values, 0)})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_any_from_list_reduce_next(
          {"any-1": vx_core.t_boolean, "any-2": vx_core.t_boolean, "list-2": vx_core.t_booleanlist},
          values,
          true,
          vx_core.f_new(vx_core.t_any_from_reduce_next, (reduce, current, next) => 
            vx_core.f_and(
              reduce,
              vx_core.f_and(current, next)
            ))
        )})
      )
    )
    return output
  }

  /**
   * @function any_from_any
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_any_from_any = {}
  static e_any_from_any = {vx_type: vx_core.t_any_from_any}

  static f_any_from_any(generic, value) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = value
    return output
  }

  /**
   * 
   * @async @function any_from_any_async
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_any_from_any_async = {}
  static e_any_from_any_async = {vx_type: vx_core.t_any_from_any_async}

  static async f_any_from_any_async(generic, value) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_any_context
   * Function Type taking any value any-2 and returning generic any-1 using context
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_any_from_any_context = {}
  static e_any_from_any_context = {vx_type: vx_core.t_any_from_any_context}

  static f_any_from_any_context(generic, value, context) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_any_context_async
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_any_from_any_context_async = {}
  static e_any_from_any_context_async = {vx_type: vx_core.t_any_from_any_context_async}

  static async f_any_from_any_context_async(generic, value, context) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_func
   * Function Type returning Generic any-1 with any parameters
   * @param  {typemap} generic
   * @return {any-1}
   */
  static t_any_from_func = {}
  static e_any_from_func = {vx_type: vx_core.t_any_from_func}

  static f_any_from_func(generic) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_func_async
   * Function Type returning Generic any-1 with any parameters
   * @param  {typemap} generic
   * @return {any-1}
   */
  static t_any_from_func_async = {}
  static e_any_from_func_async = {vx_type: vx_core.t_any_from_func_async}

  static async f_any_from_func_async(generic) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_key_value
   * @param  {typemap} generic
   * @param  {string} key
   * @param  {any} val
   * @return {any-1}
   */
  static t_any_from_key_value = {}
  static e_any_from_key_value = {vx_type: vx_core.t_any_from_key_value}

  static f_any_from_key_value(generic, key, val) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_key_value_async
   * @param  {typemap} generic
   * @param  {string} key
   * @param  {any} val
   * @return {any-1}
   */
  static t_any_from_key_value_async = {}
  static e_any_from_key_value_async = {vx_type: vx_core.t_any_from_key_value_async}

  static async f_any_from_key_value_async(generic, key, val) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_list
   * Returns nth value from a list or none if out of bounds
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {int} index
   * @return {any-1}
   */
  static t_any_from_list = {}
  static e_any_from_list = {vx_type: vx_core.t_any_from_list}

  static f_any_from_list(generic, values, index) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    if (index < values.length) {
      output = values[index]
    }
    return output
  }

  /**
   * @function any_from_list_reduce
   * Returns a val from a list reduce operation
   * @param  {typemap} generic
   * @param  {list} list
   * @param  {any} valstart
   * @param  {any_from_reduce} fn_reduce
   * @return {any-1}
   */
  static t_any_from_list_reduce = {}
  static e_any_from_list_reduce = {vx_type: vx_core.t_any_from_list_reduce}

  static f_any_from_list_reduce(generic, list, valstart, fn_reduce) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = output = valstart
    const fn = fn_reduce['vx_value']
    if (fn) {
      for (const item of list) {
        output = fn(output, item)
      }
    }
    return output
  }

  /**
   * @function any_from_list_reduce_next
   * Returns a val from a list reduce operation
   * @param  {typemap} generic
   * @param  {list} list
   * @param  {any} valstart
   * @param  {any_from_reduce_next} fn_reduce_next
   * @return {any-1}
   */
  static t_any_from_list_reduce_next = {}
  static e_any_from_list_reduce_next = {vx_type: vx_core.t_any_from_list_reduce_next}

  static f_any_from_list_reduce_next(generic, list, valstart, fn_reduce_next) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = output = valstart
    const fn = fn_reduce_next['vx_value']
    if (fn) {
      let current = vx_core.e_any
      let first = true
      for (const next of list) {
        if (first) {
          first = false
        } else {
          output = fn(output, current, next)
        }
        current = next
      }
    }
    return output
  }

  /**
   * @function any_from_map
   * Returns value from a map or empty if not found
   * @param  {typemap} generic
   * @param  {map} valuemap
   * @param  {string} key
   * @return {any}
   */
  static t_any_from_map = {}
  static e_any_from_map = {vx_type: vx_core.t_any_from_map}

  static f_any_from_map(generic, valuemap, key) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    if (key.startsWith(':')) {
      key = key.substring(1)
    }
    const mapval = valuemap['vx_value']
    let val = mapval[key]
    if (val != undefined) {
      output = val
    }
    return output
  }

  /**
   * @function any_from_none
   * Function Type returning Generic any-1 with no parameters
   * @param  {typemap} generic
   * @return {any-1}
   */
  static t_any_from_none = {}
  static e_any_from_none = {vx_type: vx_core.t_any_from_none}

  static f_any_from_none(generic) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_none_async
   * Function Type returning Generic any-1 with no parameters
   * @param  {typemap} generic
   * @return {any-1}
   */
  static t_any_from_none_async = {}
  static e_any_from_none_async = {vx_type: vx_core.t_any_from_none_async}

  static async f_any_from_none_async(generic) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_reduce
   * @param  {typemap} generic
   * @param  {any} result
   * @param  {any} item
   * @return {any-1}
   */
  static t_any_from_reduce = {}
  static e_any_from_reduce = {vx_type: vx_core.t_any_from_reduce}

  static f_any_from_reduce(generic, result, item) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_reduce_async
   * @param  {typemap} generic
   * @param  {any} result
   * @param  {any} item
   * @return {any-1}
   */
  static t_any_from_reduce_async = {}
  static e_any_from_reduce_async = {vx_type: vx_core.t_any_from_reduce_async}

  static async f_any_from_reduce_async(generic, result, item) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_reduce_next
   * @param  {typemap} generic
   * @param  {any} result
   * @param  {any} current
   * @param  {any} next
   * @return {any-1}
   */
  static t_any_from_reduce_next = {}
  static e_any_from_reduce_next = {vx_type: vx_core.t_any_from_reduce_next}

  static f_any_from_reduce_next(generic, result, current, next) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * 
   * @async @function any_from_reduce_next_async
   * @param  {typemap} generic
   * @param  {any} result
   * @param  {any} current
   * @param  {any} next
   * @return {any-1}
   */
  static t_any_from_reduce_next_async = {}
  static e_any_from_reduce_next_async = {vx_type: vx_core.t_any_from_reduce_next_async}

  static async f_any_from_reduce_next_async(generic, result, current, next) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    return output
  }

  /**
   * @function any_from_struct
   * Returns value from a struct
   * @param  {typemap} generic
   * @param  {struct} vstruct
   * @param  {string} key
   * @return {any-1}
   */
  static t_any_from_struct = {}
  static e_any_from_struct = {vx_type: vx_core.t_any_from_struct}

  static f_any_from_struct(generic, vstruct, key) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    const subvalmap = vstruct['vx_value']
    if (subvalmap != undefined) {
      if (key.startsWith(':')) {
        key = key.substring(1)
      }
      const val = subvalmap[key]
      if (val != undefined) {
        output = val
      }
    }
    return output
  }

  /**
   * 
   * @async @function async
   * Returns an asynchonous version value. This exists mostly for type-casting.
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_async = {}
  static e_async = {vx_type: vx_core.t_async}

  static async f_async(generic, value) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    output = value
    return output
  }

  /**
   * @function boolean_from_any
   * Function Type taking generic any-2 and returning boolean
   * @param  {any} value
   * @return {boolean}
   */
  static t_boolean_from_any = {}
  static e_boolean_from_any = {vx_type: vx_core.t_boolean_from_any}

  static f_boolean_from_any(value) {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function boolean_from_func
   * Function Type returning boolean with any parameters
   * @return {boolean}
   */
  static t_boolean_from_func = {}
  static e_boolean_from_func = {vx_type: vx_core.t_boolean_from_func}

  static f_boolean_from_func() {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function boolean_from_none
   * Function Type returning boolean with no parameters
   * @return {boolean}
   */
  static t_boolean_from_none = {}
  static e_boolean_from_none = {vx_type: vx_core.t_boolean_from_none}

  static f_boolean_from_none() {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function case
   * @param  {list} values
   * @param  {any_from_func} fn_any
   * @return {thenelse}
   */
  static t_case = {}
  static e_case = {vx_type: vx_core.t_case}

  static f_case(values, fn_any) {
    let output = vx_core.e_thenelse
    output = vx_core.f_new(
      vx_core.t_thenelse,
      ":code",
      ":casemany",
      ":values",
      values,
      ":fn-any",
      fn_any
    )
    return output
  }

  /**
   * @function case
   * @param  {any} value
   * @param  {any_from_func} fn_any
   * @return {thenelse}
   */
  static t_case_1 = {}
  static e_case_1 = {vx_type: vx_core.t_case_1}

  static f_case_1(value, fn_any) {
    let output = vx_core.e_thenelse
    output = vx_core.f_new(
      vx_core.t_thenelse,
      ":code",
      ":case",
      ":value",
      value,
      ":fn-any",
      fn_any
    )
    return output
  }

  /**
   * @function compare
   * Returns 0 if vals are equal, 1 if val1 > val2, -1 if val1 < val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {int}
   */
  static t_compare = {}
  static e_compare = {vx_type: vx_core.t_compare}

  static f_compare(val1, val2) {
    let output = vx_core.e_int
    if (val1 == val2) {
      output = 0
    } else if (val1 < val2) {
      output = -1
    } else {
      output = 1
    }
    return output
  }

  /**
   * @function contains
   * Returns true if the given list contains the given value.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   */
  static t_contains = {}
  static e_contains = {vx_type: vx_core.t_contains}

  static f_contains(text, find) {
    let output = vx_core.e_boolean
    output = text.includes(find)
    return output
  }

  /**
   * @function contains
   * Returns true if the given list contains the given value.
   * @param  {list} values Any list
   * @param  {any} find Any value
   * @return {boolean}
   */
  static t_contains_1 = {}
  static e_contains_1 = {vx_type: vx_core.t_contains_1}

  static f_contains_1(values, find) {
    let output = vx_core.e_boolean
    output = values.includes(find)
    return output
  }

  /**
   * @function copy
   * Returns a copy of a given value with the given values added or updated.
   * @param  {any} value
   * @param  {anylist} ... values
   * @return {any-1}
   */
  static t_copy = {}
  static e_copy = {vx_type: vx_core.t_copy}

  static f_copy(value, ...values) {
    let output
    output = vx_core.f_new(value, ...values)
    return output
  }

  /**
   * @function else
   * @param  {any_from_func} fn_any
   * @return {thenelse}
   */
  static t_else = {}
  static e_else = {vx_type: vx_core.t_else}

  static f_else(fn_any) {
    let output = vx_core.e_thenelse
    output = vx_core.f_new(
      vx_core.t_thenelse,
      ":code",
      ":else",
      ":fn-any",
      fn_any
    )
    return output
  }

  /**
   * @function empty
   * Returns the empty value for a given type. Can be called using (empty type) or simply (type)
   * @param  {any} type
   * @return {any-1}
   */
  static t_empty = {}
  static e_empty = {vx_type: vx_core.t_empty}

  static f_empty(type) {
    let output
    const typedef = vx_core.f_typedef_from_type(type)
    const pkgname = typedef['vx_value'].pkgname
    const typename = typedef['vx_value'].name
    const pkg = vx_core.f_global_package_get(pkgname)
    output = pkg.c_empty[typename]
    return output
  }

  /**
   * @function extends_from_any
   * @param  {any} val
   * @return {string}
   */
  static t_extends_from_any = {}
  static e_extends_from_any = {vx_type: vx_core.t_extends_from_any}

  static f_extends_from_any(val) {
    let output = vx_core.e_string
    output = vx_core.f_extends_from_typedef(
      vx_core.f_typedef_from_any(val)
    )
    return output
  }

  /**
   * @function extends_from_typedef
   * Get the basetype of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   */
  static t_extends_from_typedef = {}
  static e_extends_from_typedef = {vx_type: vx_core.t_extends_from_typedef}

  static f_extends_from_typedef(vtypedef) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_core.t_typedef}, vtypedef, ":extends")
    return output
  }

  /**
   * @function first_from_list
   * Returns first value
   * @param  {typemap} generic
   * @param  {list} values
   * @return {any-1}
   */
  static t_first_from_list = {}
  static e_first_from_list = {vx_type: vx_core.t_first_from_list}

  static f_first_from_list(generic, values) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_core.f_any_from_list({"any-1": vx_core.t_any}, values, 0)
    return output
  }

  /**
   * @function first_from_list_fn_any_from_any
   * Returns first value that is not nothing
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {any_from_any} fn_any_from_any
   * @return {any-1}
   */
  static t_first_from_list_fn_any_from_any = {}
  static e_first_from_list_fn_any_from_any = {vx_type: vx_core.t_first_from_list_fn_any_from_any}

  static f_first_from_list_fn_any_from_any(generic, values, fn_any_from_any) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = output = vx_core.c_nothing
    const fn = fn_any_from_any['vx_value']
    if (fn) {
      for (let index=0;index < values.length;index++) {
        output = fn(generic, values[index])
        if (output != vx_core.c_nothing) {
          break
        }
      }
    }
    return output
  }

  /**
   * @function fn
   * Shell for lambda function calls
   * @param  {typemap} generic
   * @param  {arglist} params
   * @param  {any_from_func} fn_any
   * @return {any-1}
   */
  static t_fn = {}
  static e_fn = {vx_type: vx_core.t_fn}

  static f_fn(generic, params, fn_any) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * @function funcdef_from_func
   * @param  {func} val
   * @return {funcdef}
   */
  static t_funcdef_from_func = {}
  static e_funcdef_from_func = {vx_type: vx_core.t_funcdef_from_func}

  static f_funcdef_from_func(val) {
    let output = vx_core.e_funcdef
    return output
  }

  /**
   * @function funcname_from_funcdef
   * Get the name of a given funcdef
   * @param  {funcdef} funcdef
   * @return {string}
   */
  static t_funcname_from_funcdef = {}
  static e_funcname_from_funcdef = {vx_type: vx_core.t_funcname_from_funcdef}

  static f_funcname_from_funcdef(funcdef) {
    let output = vx_core.e_string
    output = vx_core.f_new(
      vx_core.t_string,
      vx_core.f_any_from_struct({"any-1": vx_core.t_anylist, "struct-1": vx_core.t_funcdef}, funcdef, ":pkgname"),
      "/",
      vx_core.f_any_from_struct({"any-1": vx_core.t_anylist, "struct-1": vx_core.t_funcdef}, funcdef, ":name")
    )
    return output
  }

  /**
   * @function global_package_get
   * @param  {string} pkgname
   * @return {package}
   */
  static t_global_package_get = {}
  static e_global_package_get = {vx_type: vx_core.t_global_package_get}

  static f_global_package_get(pkgname) {
    let output
    output = vx_core.c_globalpackagemap[pkgname]
    return output
  }

  /**
   * @function global_package_set
   * @param  {string} pkgname
   * @param  {package} pkg
   * @return {none}
   */
  static t_global_package_set = {}
  static e_global_package_set = {vx_type: vx_core.t_global_package_set}

  static f_global_package_set(pkgname, pkg) {
    vx_core.c_globalpackagemap[pkgname] = pkg
  }

  /**
   * @function if
   * Logical If function
   * @param  {typemap} generic
   * @param  {boolean} clause
   * @param  {any} then
   * @return {any-1}
   */
  static t_if = {}
  static e_if = {vx_type: vx_core.t_if}

  static f_if(generic, clause, then) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    if (clause) {
      output = then
    }
    return output
  }

  /**
   * @function if
   * Logical If function
   * @param  {typemap} generic
   * @param  {boolean} clause
   * @param  {any} thenval
   * @param  {any} elseval
   * @return {any-1}
   */
  static t_if_1 = {}
  static e_if_1 = {vx_type: vx_core.t_if_1}

  static f_if_1(generic, clause, thenval, elseval) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    if (clause) {
      output = thenval
    } else {
      output = elseval
    }
    return output
  }

  /**
   * @function if
   * Logical If function
   * @param  {typemap} generic
   * @param  {thenelselist} ... thenelselist
   * @return {any-1}
   */
  static t_if_2 = {}
  static e_if_2 = {vx_type: vx_core.t_if_2}

  static f_if_2(generic, ...thenelselist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    thenelselist = vx_core.f_new(vx_core.t_thenelselist, ...thenelselist)
    let fn_any = null
    for (const thenelseval of thenelselist) {
      const thenelse = thenelseval['vx_value']
      const code = thenelse['code']
      switch (code) {
      case ':then':
        const fn_cond = thenelse['fn-cond']
        const fn = fn_cond['vx_value']
        const cond = fn()
        if (cond == true) {
          fn_any = thenelse['fn-any']
        }
        break
      case ':else':
        fn_any = thenelse['fn-any']
        break
      }
      if (fn_any != null) {
        const fn = fn_any['vx_value']
        output = fn()
        break
      }
    }
    return output
  }

  /**
   * @function int_from_func
   * Function Type returning int with any parameters
   * @return {int}
   */
  static t_int_from_func = {}
  static e_int_from_func = {vx_type: vx_core.t_int_from_func}

  static f_int_from_func() {
    let output = vx_core.e_int
    return output
  }

  /**
   * @function int_from_string
   * Function Type converting string to int
   * @param  {string} val
   * @return {int}
   */
  static t_int_from_string = {}
  static e_int_from_string = {vx_type: vx_core.t_int_from_string}

  static f_int_from_string(val) {
    let output = vx_core.e_int
    output = vx_core.f_switch(
      {"any-1": vx_core.t_int, "any-2": vx_core.t_string},
      val,
      vx_core.f_case_1(
        "notanumber",
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.c_notanumber})
      ),
      vx_core.f_case_1(
        "infinity",
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.c_infinity})
      ),
      vx_core.f_case_1(
        "neginfinity",
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.c_neginfinity})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return parseInt(val)})
      )
    )
    return output
  }

  /**
   * @function is_empty
   * Returns true if text is empty.
   * @param  {string} text
   * @return {boolean}
   */
  static t_is_empty = {}
  static e_is_empty = {vx_type: vx_core.t_is_empty}

  static f_is_empty(text) {
    let output = vx_core.e_boolean
    if (text.length == 0) {
      output = vx_core.c_true
    }
    return output
  }

  /**
   * @function is_empty
   * Returns true if an value is empty
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_empty_1 = {}
  static e_is_empty_1 = {vx_type: vx_core.t_is_empty_1}

  static f_is_empty_1(value) {
    let output = vx_core.e_boolean
    const type = vx_core.f_type_from_any(value)
    if (value == vx_core.f_empty(type)) {
      output = vx_core.c_true
    } else {
      output = vx_core.c_false
    }
    return output
  }

  /**
   * @function is_endswith
   * Returns true if text ends with find.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   */
  static t_is_endswith = {}
  static e_is_endswith = {vx_type: vx_core.t_is_endswith}

  static f_is_endswith(text, find) {
    let output = vx_core.e_boolean
    if (text.endsWith(find)) {
      output = vx_core.c_true
    }
    return output
  }

  /**
   * @function is_func
   * Returns true if val is a function.
   * @param  {any} val
   * @return {boolean}
   */
  static t_is_func = {}
  static e_is_func = {vx_type: vx_core.t_is_func}

  static f_is_func(val) {
    let output = vx_core.e_boolean
    const extend = vx_core.f_extends_from_any(val)
    if (extend == ':func') {
      output = vx_core.c_true
    }
    return output
  }

  /**
   * @function is_int
   * Returns true if the value is an integer.
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_int = {}
  static e_is_int = {vx_type: vx_core.t_is_int}

  static f_is_int(value) {
    let output = vx_core.e_boolean
    output = output = false
    switch (value) {
    case vx_core.c_infinity:
    case vx_core.c_neginfinity:
    case vx_core.c_notanumber:
      output = true
      break
    default:
      const typename = vx_core.f_typename_from_any(value)
      switch (typename) {
      case 'vx/core/int':
        output = true
        break
      case 'vx/core/number':
        if (parseInt(value) == value) {
          output = true
        }
        break
      case 'vx/core/string':
        if (parseInt(value) == parseFloat(value)) {
          output = true
        }
        break
      }
      break
    }
    return output
  }

  /**
   * @function is_number
   * Return true if val is a number
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_number = {}
  static e_is_number = {vx_type: vx_core.t_is_number}

  static f_is_number(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_switch(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_string},
      vx_core.f_typename_from_any(value),
      vx_core.f_case(
        vx_core.f_new(
          vx_core.t_list,
          "vx/core/decimal",
          "vx/core/float",
          "vx/core/int",
          "vx/core/number"
        ),
        vx_core.f_new(vx_core.t_any_from_func, () => {return true})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return false})
      )
    )
    return output
  }

  /**
   * @function is_pass_from_permission
   * Returns true if permission passes.
   * @param  {permission} permission
   * @return {boolean}
   */
  static t_is_pass_from_permission = {}
  static e_is_pass_from_permission = {vx_type: vx_core.t_is_pass_from_permission}

  static f_is_pass_from_permission(permission, context) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const id = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_core.t_permission}, permission, ":id")
        const lookup = vx_core.f_permission_from_id_context(id, context)
        return vx_core.f_eq(lookup, permission)
      })
    )
    return output
  }

  /**
   * @function last_from_list
   * Returns last value
   * @param  {typemap} generic
   * @param  {list} values
   * @return {any-1}
   */
  static t_last_from_list = {}
  static e_last_from_list = {vx_type: vx_core.t_last_from_list}

  static f_last_from_list(generic, values) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const len = vx_core.f_length_from_list(values)
        const last = vx_core.f_minus(len, 1)
        return vx_core.f_any_from_list({"any-1": vx_core.t_any}, values, last)
      })
    )
    return output
  }

  /**
   * @function length_from_list
   * Returns the currently used size/length of a list
   * @param  {list} values
   * @return {int}
   */
  static t_length_from_list = {}
  static e_length_from_list = {vx_type: vx_core.t_length_from_list}

  static f_length_from_list(values) {
    let output = vx_core.e_int
    output = values.length
    return output
  }

  /**
   * @function let
   * @param  {typemap} generic
   * @param  {arglist} args
   * @param  {any_from_func} fn_any
   * @return {any-1}
   */
  static t_let = {}
  static e_let = {vx_type: vx_core.t_let}

  static f_let(generic, args, fn_any) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    const fn = fn_any['vx_value']
    if (fn) {
      output = fn()
    }
    return output
  }

  /**
   * 
   * @async @function let_async
   * Same as normal let but returns async values.
   * @param  {typemap} generic
   * @param  {arglist} args
   * @param  {any_from_func_async} fn_any_async
   * @return {any-1}
   */
  static t_let_async = {}
  static e_let_async = {vx_type: vx_core.t_let_async}

  static async f_let_async(generic, args, fn_any_async) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    const fn = fn_any_async['vx_value']
    if (fn) {
      output = await fn()
    }
    return output
  }

  /**
   * @function list_join_from_list
   * Returns a flattened list of processed items from another list
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {any_from_any} fn_any_from_any
   * @return {list-1}
   */
  static t_list_join_from_list = {}
  static e_list_join_from_list = {vx_type: vx_core.t_list_join_from_list}

  static f_list_join_from_list(generic, values, fn_any_from_any) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    const fn = fn_any_from_any['vx_value']
    if (fn) {
      const listoflist = values.map(fn)
      output = listoflist.flat()
      output['vx_type'] = generic_list_1
    }
    return output
  }

  /**
   * @function list_from_list
   * Returns a list of processed items from another list
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {any_from_any} fn_any_from_any
   * @return {list-1}
   */
  static t_list_from_list = {}
  static e_list_from_list = {vx_type: vx_core.t_list_from_list}

  static f_list_from_list(generic, values, fn_any_from_any) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    const fn = fn_any_from_any['vx_value']
    if (fn) {
      output = values.map(fn)
      output['vx_type'] = generic_list_1
    }
    return output
  }

  /**
   * 
   * @async @function list_from_list_async
   * Returns an asynchronous list of the processed asynchronous items from another list
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {any_from_any_async} fn_any_from_any_async
   * @return {list-1}
   */
  static t_list_from_list_async = {}
  static e_list_from_list_async = {vx_type: vx_core.t_list_from_list_async}

  static async f_list_from_list_async(generic, values, fn_any_from_any_async) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_list_1))
    const fn = fn_any_from_any_async['vx_value']
    if (fn) {
      const listfuture = values.map(fn)
      const future = Promise.all(listfuture)
      output = await future
      output['vx_type'] = generic_list_1
    }
    return output
  }

  /**
   * @function list_from_map
   * Returns a list from a map by applying a function to each key value.
   * @param  {typemap} generic
   * @param  {map} valuemap
   * @param  {any_from_key_value} fn_any_from_key_value
   * @return {list-1}
   */
  static t_list_from_map = {}
  static e_list_from_map = {vx_type: vx_core.t_list_from_map}

  static f_list_from_map(generic, valuemap, fn_any_from_key_value) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    const fn = fn_any_from_key_value['vx_value']
    if (fn) {
      const entries = Object.entries(valuemap['vx_value'])
      const values = entries.map(fn)
      output = vx_core.f_new(generic_list_1, ...values)
    }
    return output
  }

  /**
   * 
   * @async @function list_from_map_async
   * @param  {typemap} generic
   * @param  {map} valuemap
   * @param  {any_from_key_value_async} fn_any_from_key_value_async
   * @return {list-1}
   */
  static t_list_from_map_async = {}
  static e_list_from_map_async = {vx_type: vx_core.t_list_from_map_async}

  static async f_list_from_map_async(generic, valuemap, fn_any_from_key_value_async) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_list_1))
    return output
  }

  /**
   * @function list_from_type
   * Create an empty list from a type. Used internally for default lists
   * @param  {any} type
   * @return {any}
   */
  static t_list_from_type = {}
  static e_list_from_type = {vx_type: vx_core.t_list_from_type}

  static f_list_from_type(type) {
    let output = vx_core.e_any
    output = output = []
    output['vx_type'] = type
    return output
  }

  /**
   * @function log
   * @param  {any} value
   * @return {any}
   */
  static t_log = {}
  static e_log = {vx_type: vx_core.t_log}

  static f_log(value) {
    let output = vx_core.e_any
    const text = vx_core.f_string_from_any(value)
    console.log(text)
    output = value
    return output
  }

  /**
   * @function map_from_list
   * Returns a map from a list by applying a function to each key value.
   * @param  {typemap} generic
   * @param  {list} vallist
   * @param  {any_from_any} fn_any_from_any
   * @return {map-1}
   */
  static t_map_from_list = {}
  static e_map_from_list = {vx_type: vx_core.t_map_from_list}

  static f_map_from_list(generic, vallist, fn_any_from_any) {
    const generic_any_1 = generic["any-1"]
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    const valmap = {}
    vallist.map(value => {
      const fn = fn_any_from_any['vx_value']
      if (fn) {
        const key = fn(value)
        valmap[key] = value
      }
    })
    output = {
      vx_type: generic_map_1,
      vx_value: valmap
    }
    return output
  }

  /**
   * @function mempool_addref
   * Add Value Reference
   * @param  {anylist} ... values
   * @return {none}
   */
  static t_mempool_addref = {}
  static e_mempool_addref = {vx_type: vx_core.t_mempool_addref}

  static f_mempool_addref(...values) {
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    for (const value of values) {
      const value = values[i]
      if (value.refs) {
        value.refs += 1
      }
    }
  }

  /**
   * @function mempool_release
   * Recycles a Value and adds it to the valuepool.
   * @param  {value} value
   * @return {none}
   */
  static t_mempool_release = {}
  static e_mempool_release = {vx_type: vx_core.t_mempool_release}

  static f_mempool_release(value) {
    const mempool = vx_core.c_mempool_active
    value.length = 0
    for (const key in value) {
      delete value[key]
    }
    next = mempool.valuepool
    value.next = next
    mempool.valuepool = value
  }

  /**
   * @function mempool_removeref
   * Remove Value Reference
   * @param  {anylist} ... values
   * @return {none}
   */
  static t_mempool_removeref = {}
  static e_mempool_removeref = {vx_type: vx_core.t_mempool_removeref}

  static f_mempool_removeref(...values) {
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    for (const value of values) {
      const value = values[i]
      if (value.refs) {
        value.refs -= 1
        if (value.refs == 0) {
          vx_core.f_mempool_removerefchildren(value)
          vx_core.f_mempool_recyclevalue(value)
        }
      }
    }
  }

  /**
   * @function mempool_removerefchildren
   * Remove Value Child References
   * @param  {anylist} ... values
   * @return {none}
   */
  static t_mempool_removerefchildren = {}
  static e_mempool_removerefchildren = {vx_type: vx_core.t_mempool_removerefchildren}

  static f_mempool_removerefchildren(...values) {
    values = vx_core.f_new(vx_core.t_anylist, ...values)
    for (const value of values) {
      const extend = vx_core.f_extends_from_any(
      vx_core.t_value
    )
      switch (extend) {
      case ':list':
        vx_core.f_mempool_removeref(...value['vx_value'])
        break
      case ':map':
      case ':struct':
        vx_core.f_mempool_removeref(...Object.entities(value['vx_value']))
        break
      }
    }
  }

  /**
   * @function mempool_reserve
   * Returns a recycled Value or creates a new one.
   * @return {value}
   */
  static t_mempool_reserve = {}
  static e_mempool_reserve = {vx_type: vx_core.t_mempool_reserve}

  static f_mempool_reserve() {
    let output = vx_core.e_value
    mempool = vx_core.c_mempool_active
    output = mempool.valuepool
    if (output == null) {
      output = {
        refs: 0
      }
    } else {
      const next = output.next
      if (next == null) {
        mempool.valuepool = null
      } else {
        mempool.valuepool = next
        output.next = null
      }
    }
    return output
  }

  /**
   * @function msg_from_error
   * Returns a msg from error string
   * @param  {string} error
   * @return {msg}
   */
  static t_msg_from_error = {}
  static e_msg_from_error = {vx_type: vx_core.t_msg_from_error}

  static f_msg_from_error(error) {
    let output = vx_core.e_msg
    output = vx_core.f_new(
      vx_core.t_msg,
      ":severity",
      vx_core.c_msg_error,
      ":text",
      error
    )
    return output
  }

  /**
   * @function msgblock_from_msgblock_msg
   * Return a new Msgblock with the added msg
   * @param  {msgblock} origblock
   * @param  {msg} addmsg
   * @return {msgblock}
   */
  static t_msgblock_from_msgblock_msg = {}
  static e_msgblock_from_msgblock_msg = {vx_type: vx_core.t_msgblock_from_msgblock_msg}

  static f_msgblock_from_msgblock_msg(origblock, addmsg) {
    let output = vx_core.e_msgblock
    output = vx_core.f_copy(origblock, addmsg)
    return output
  }

  /**
   * @function msgblock_from_msgblock_msgblock
   * Return a new Msgblock with the added block
   * @param  {msgblock} origblock
   * @param  {msgblock} addblock
   * @return {msgblock}
   */
  static t_msgblock_from_msgblock_msgblock = {}
  static e_msgblock_from_msgblock_msgblock = {vx_type: vx_core.t_msgblock_from_msgblock_msgblock}

  static f_msgblock_from_msgblock_msgblock(origblock, addblock) {
    let output = vx_core.e_msgblock
    output = vx_core.f_new(
      vx_core.t_msgblock,
      origblock,
      addblock
    )
    return output
  }

  /**
   * @function name_from_typedef
   * Returns the name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   */
  static t_name_from_typedef = {}
  static e_name_from_typedef = {vx_type: vx_core.t_name_from_typedef}

  static f_name_from_typedef(vtypedef) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_core.t_typedef}, vtypedef, ":name")
    return output
  }

  /**
   * @function native
   * Native Function Call
   * @param  {typemap} generic
   * @param  {anylist} ... clauses
   * @return {any-1}
   */
  static t_native = {}
  static e_native = {vx_type: vx_core.t_native}

  static f_native(generic, ...clauses) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    clauses = vx_core.f_new(vx_core.t_anylist, ...clauses)
    return output
  }

  /**
   * @function native_from_any
   * Returns native value of value object
   * @param  {any} value
   * @return {any}
   */
  static t_native_from_any = {}
  static e_native_from_any = {vx_type: vx_core.t_native_from_any}

  static f_native_from_any(value) {
    let output = vx_core.e_any
    output = output = value
    switch (typeof value) {
    case 'boolean':
    case 'number':
    case 'string':
      break
    default:
      const extend = vx_core.f_extends_from_any(value)
      switch (extend) {
      case ':list':
        output = [...value]
        break
      case ':func':
      case ':map':
      case ':struct':
        output = value['vx_value']
        break
      }
      break
    }
    return output
  }

  /**
   * @function new
   * Create a new Value of Type A
   * @param  {any} type
   * @param  {anylist} ... values
   * @return {any-1}
   */
  static t_new = {}
  static e_new = {vx_type: vx_core.t_new}

  static f_new(type, ...values) {
    let output
    const typedef = vx_core.f_typedef_from_any(type)
    const copy = type
    let msgblock = vx_core.e_msgblock
    if (values.length == 1) {
      // check if anylist passed as the only value
      const val1 = values[0]
      const val1typedef = val1['vx_type']
      if (val1typedef == undefined) {
      } else if (val1typedef == vx_core.t_anylist) {
        values = val1
      }
    }
    let isfirst = true
    switch (typedef) {
    case vx_core.t_boolean:
      output = false
      if (type == vx_core.t_boolean) {
      } else if ((typeof copy) == 'boolean') {
        output = copy
      } else {
        output = copy['vx_value']
        const testmsgblock = copy['vx_msgblock']
        if (testmsgblock != undefined) {
          msgblock = testmsgblock
        }
      }
      values.map(value => {
        switch (typeof value) {
        case 'boolean':
          if (isfirst) {
            isfirst = false
            output = value
          } else {
            output = output && value
          }
          break
        default:
          const valuetype = vx_core.f_typedef_from_any(value)
          switch (valuetype) {
          case vx_core.t_boolean:
            value = value['vx_value']
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output = output && value
            }
            break
          case vx_core.t_msgblock:
            msgblock = value
            break
          case vx_core.t_msg:
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
            break
          default:
            const typename = vx_core.f_typename_from_typedef(typedef)
            const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
            break
          }
          break
        }
      })
      if (msgblock != vx_core.e_msgblock) {
        output = {
          vx_type: typedef,
          vx_value: output,
          vx_msgblock: msgblock
        }
      }
      break
    case vx_core.t_int:
      output = 0
      if (type == vx_core.t_int) {
      } else if ((typeof copy) == 'number') {
        output = copy
      } else {
        output = copy['vx_value']
        const testmsgblock = copy['vx_msgblock']
        if (testmsgblock != undefined) {
          msgblock = testmsgblock
        }
      }
      values.map(value => {
        switch (typeof value) {
        case 'number':
          if (isfirst) {
            isfirst = false
            output = value
          } else {
            output += value
          }
          break
        case 'string':
          value = parseFloat(value)
          if (isfirst) {
            isfirst = false
            output = value
          } else {
            output += value
          }
          break
        default:
          const valuetype = vx_core.f_type_from_any(value)
          switch (valuetype) {
          case vx_core.t_int:
            value = value['vx_value']
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output = output + value
            }
            break
          case vx_core.t_float:
            value = value['vx_value']
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output += value
            }
            break
          case vx_core.t_string:
            value = parseFloat(value)
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output += value
            }
            break
          case vx_core.t_msgblock:
            msgblock = value
            break
          case vx_core.t_msg:
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
            break
          default:
            const typename = vx_core.f_typename_from_typedef(typedef)
            const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
            break
          }
          break
        }
      })
      output = Math.round(output)
      if (msgblock != vx_core.e_msgblock) {
        output = {
          vx_type: typedef,
          vx_value: output,
          vx_msgblock: msgblock
        }
      }
      break
    case vx_core.t_float:
      output = 0.0
      if (type == vx_core.t_float) {
      } else if ((typeof copy) == 'number') {
        output = copy
      } else {
        output = copy['vx_value']
        const testmsgblock = copy['vx_msgblock']
        if (testmsgblock != undefined) {
          msgblock = testmsgblock
        }
      }
      values.map(value => {
        switch (typeof value) {
        case 'number':
          if (isfirst) {
            isfirst = false
            output = value
          } else {
            output += value
          }
          break
        case 'string':
          value = parseFloat(value)
          if (isfirst) {
            isfirst = false
            output = value
          } else {
            output += value
          }
          break
        default:
          const valuetype = vx_core.f_type_from_any(value)
          switch (valuetype) {
          case vx_core.t_int:
          case vx_core.t_float:
            value = value['vx_value']
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output += value
            }
            break
          case vx_core.t_string:
            value = parseFloat(value['vx_value'])
            if (isfirst) {
              isfirst = false
              output = value
            } else {
              output += value
            }
            break
          case vx_core.t_msgblock:
            msgblock = value
            break
          case vx_core.t_msg:
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
            break
          default:
            const typename = vx_core.f_typename_from_typedef(typedef)
            const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
            break
          }
        }
      })
      if (msgblock != vx_core.e_msgblock) {
        output = {
          vx_type: typedef,
          vx_value: output,
          vx_msgblock: msgblock
        }
      }
      break
    case vx_core.t_string:
      output = ''
      if (type == vx_core.t_string) {
      } else if ((typeof copy) == 'string') {
        output = copy
      } else {
        output = copy['vx_value']
        const testmsgblock = copy['vx_msgblock']
        if (testmsgblock != undefined) {
          msgblock = testmsgblock
        }
      }
      values.map(value => {
        switch (typeof value) {
        case 'boolean':
          if (value) {
            output += 'true'
          } else {
            output += 'false'
          }
          break
        case 'number':
        case 'string':
          output += '' + value
          break
        default:
          const valuetype = vx_core.f_typedef_from_any(value)
          switch (valuetype) {
          case vx_core.t_int:
          case vx_core.t_float:
            output += '' + value
            break
          case vx_core.t_string:
            output += value
            break
          case vx_core.t_msgblock:
            msgblock = value
            break
          case vx_core.t_msg:
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
            break
          default:
            const typename = vx_core.f_typename_from_typedef(typedef)
            const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
            break
          }
          break
        }
      })
      if (msgblock != vx_core.e_msgblock) {
        output = {
          vx_type: typedef,
          vx_value: output,
          vx_msgblock: msgblock
        }
      }
      break
    default:
      let allowany = false
      let allowtypes = []
      let key = ''
      let propmap = {}
      const extend = vx_core.f_extends_from_typedef(typedef)
      switch (extend) {
      case ':func':
        // output = vx_core.f_mempool-getvalue()
        let fn = null
        const empty = vx_core.f_empty(typedef)
        if (type == typedef) {
        } else {
          fn = copy['vx_value']
          const testmsgblock = copy['vx_msgblock']
          if (testmsgblock != undefined) {
            msgblock = testmsgblock
          }
        }
        values.map(value => {
          if (value == empty) {
          } else if ((typeof value) == 'function') {
            fn = value
          } else {
            const valuetype = vx_core.f_type_from_any(value)
            if (value == valuetype) {
              fn = valuetype['vx_value']['fn']
            } else {
              switch (valuetype) {
              case vx_core.t_msgblock:
                msgblock = value
                break
              case vx_core.t_msg:
                msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
                break
              default:
                const typename = vx_core.f_typename_from_typedef(typedef)
                const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
                msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
                break
              }
            }
          }
        })
        if ((fn != null) || (msgblock != vx_core.e_msgblock)) {
          output = {}
          output['vx_type'] = typedef
          if (fn != null) {
            output['vx_value'] = fn
          }
          if (msgblock != vx_core.e_msgblock) {
            output['vx_msgblock'] = msgblock
          }
        } else {
          output = empty
        }
        break
      case ':list':
        // output = vx_core.f_mempool-getvalue()
        const listvals = []
        if (type == typedef) {
        } else {
          listvals = copy.slice()
          const testmsgblock = copy['vx_msgblock']
          if (testmsgblock != undefined) {
            msgblock = testmsgblock
          }
        }
        allowtypes = vx_core.f_allowtypes_from_typedef(typedef)
        if (allowtypes.includes(vx_core.t_any)) {
          allowany = true
        }
        values.map(value => {
          const valuetype = vx_core.f_type_from_any(value)
          let isfound = false
          if (typedef == valuetype) {
            listvals.push(...value)
            isfound = true
          } else if (allowany) {
            listvals.push(value)
            isfound = true
          } else if (allowtypes.includes(valuetype)) {
            listvals.push(value)
            isfound = true
          } else {
            switch (valuetype) {
            case vx_core.t_msgblock:
              msgblock = value
              isfound = true
              break
            case vx_core.t_msg:
              msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
              isfound = true
              break
            default:
              const valuetraits = vx_core.f_traits_from_typedef(valuetype)
              const intersection = allowtypes.filter(function(n) {
                return valuetraits.indexOf(n) > -1
              })
              if (intersection.length > 0) {
                listvals.push(value)
                isfound = true
              }
              break
            }
          }
          if (!isfound) {
            const typename = vx_core.f_typename_from_typedef(typedef)
            const msg = vx_core.f_msg_from_error('(new ' + typename + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Value')
            msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
          }
        })
        if ((listvals.length > 0) || (msgblock != vx_core.e_msgblock)) {
          output = listvals
          output['vx_type'] = typedef
          if (msgblock != vx_core.e_msgblock) {
            output['vx_msgblock'] = msgblock
          }
        } else {
          output = vx_core.f_empty(typedef)
        }
        break
      case ':map':
        if (type != typedef) {
          propmap = Object.assign({}, copy['vx_value'])
          const testmsgblock = copy['vx_msgblock']
          if (testmsgblock != undefined) {
            msgblock = testmsgblock
          }
        }
        allowtypes = vx_core.f_allowtypes_from_typedef(typedef)
        if (allowtypes.includes(vx_core.t_any)) {
          allowany = true
        }
        values.map(value => {
          const valuetype = vx_core.f_type_from_any(value)
          if (key == '') {
            switch (valuetype) {
            case vx_core.t_string:
              if ((typeof value) == 'string') {
                key = value
              } else {
                key = value['vx_value']
              }
              if (key.startsWith(':')) {
                key = key.substring(1)
              }
              break
            case vx_core.t_msgblock:
              msgblock = value
              break
            case vx_core.t_msg:
              msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
              break
            default:
              const typename = vx_core.f_typename_from_typedef(typedef)
              const msg = vx_core.f_msg_from_error('(new ' + typename + ' :key ' + vx_core.f_string_from_any(value) + ') - Invalid Key')
              msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
              break
            }
          } else {
            if (allowany) {
              propmap[key] = value
            } else if (allowtypes.includes(valuetype)) {
              propmap[key] = value
            } else {
              const valuetraits = vx_core.f_traits_from_typedef(valuetype)
              const intersection = allowtypes.filter(function(n) {
                return valuetraits.indexOf(n) > -1
              })
              if (intersection.length > 0) {
                propmap[key] = value
              } else {
                const typename = vx_core.f_typename_from_typedef(typedef)
                const msg = vx_core.f_msg_from_error('(new ' + typename + ' :key ' + key + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Key Value')
                msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
              }
            }
            key = ''
          }
        })
        // output = vx_core.f_mempool-getvalue()
        if ((Object.keys(propmap).length > 0) || (msgblock != vx_core.e_msgblock)) {
          output = {
            vx_type: typedef,
            vx_value: propmap
          }
          if (msgblock != vx_core.e_msgblock) {
            output['vx_msgblock'] = msgblock
          }
        } else {
          output = vx_core.f_empty(typedef)
        }
        break
      case ':struct':
        switch (typedef) {
        case vx_core.t_msgblock:
        case type:
          break
        default:
          propmap = Object.assign({}, copy['vx_value'])
          const testmsgblock = copy['vx_msgblock']
          if (testmsgblock != undefined) {
            msgblock = testmsgblock
          }
          break
        }
        if (values.length > 0) {
          const properties = vx_core.f_properties_from_typedef(typedef)
          const lastprop = vx_core.f_proplast_from_typedef(typedef)
          const validkeys = Object.keys(properties)
          let lastpropname = ''
          let lasttype = null
          let lastallowtypes = []
          const ismulti = lastprop['multi']
          if (ismulti) {
            lastpropname = lastprop['name']
            lasttype = lastprop['type']
            lastallowtypes = vx_core.f_allowtypes_from_typedef(lasttype)
          }
          let testkey = ''
          values.map(value => {
            const valuetype = vx_core.f_type_from_any(value)
            if (key == '') {
              switch (valuetype) {
              case vx_core.t_string:
                if ((typeof value) == 'string') {
                  testkey = value
                } else {
                  testkey = value['vx_value']
                }
                if (testkey.startsWith(':')) {
                  testkey = testkey.substring(1)
                }
                if (validkeys.includes(testkey)) {
                  key = testkey
                } else {
                  const typename = vx_core.f_typename_from_typedef(typedef)
                  const msg = vx_core.f_msg_from_error('(new ' + typename + ' :key ' + vx_core.f_string_from_any(value) + ') - Invalid Key')
                  msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
                }
                break
              case vx_core.t_msgblock:
                switch (typedef) {
                case vx_core.t_msg:
                  // invalid msg cannot contain msgblock
                  break
                case vx_core.t_msgblock:
                  if (value == vx_core.t_msgblock) {
                  } else {
                    let msgblocks = propmap['msgblocks']
                    if (msgblocks == undefined) {
                      msgblocks = [value]
                      msgblock['vx_type'] = vx_core.t_msgblocklist
                    } else {
                      msgblocks.push(value)
                    }
                    propmap['msgblocks'] = msgblocks
                  }
                  break
                default:
                  msgblock = vx_core.f_msgblock_from_msgblock_msgblock(msgblock, value)
                  break
                }
                break
              case vx_core.t_msg:
                switch (typedef) {
                case vx_core.t_msg:
                  // invalid msg cannot contain msg
                  break
                case vx_core.t_msgblock:
                  let msgs = propmap['msgs']
                  if (msgs == undefined) {
                    msgs = [value]
                    msgs['vx_type'] = vx_core.t_msglist
                  } else {
                    msgs.push(value)
                  }
                  propmap['msgs'] = msgs
                  break
                default:
                  msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, value)
                  break
                }
                break
              default:
                let isfound = false
                if (!ismulti) {
                } else if (lasttype == vx_core.t_any) {
                  isfound = true
                } else if (lasttype == valuetype) {
                  isfound = true
                } else if (lastallowtypes.length > 0) {
                  if (lastallowtypes.includes(valuetype)) {
                    isfound = true
                  } else {
                    const valuetraits = vx_core.f_traits_from_typedef(valuetype)
                    const intersection = lastallowtypes.filter(function(n) {
                      return valuetraits.indexOf(n) > -1
                    })
                    if (intersection.length > 0) {
                      isfound = true
                    }
                  }
                }
                if (isfound) {
                  let lastpropvalue = propmap[lastpropname]
                  if (lastpropvalue == undefined) {
                    lastpropvalue = []
                    lastpropvalue['vx_type'] = lasttype
                    propmap[lastpropname] = lastpropvalue
                  }
                  if (lasttype == valuetype) {
                    lastpropvalue.push(...value)
                  } else {
                    lastpropvalue.push(value)
                  }
                } else {
                  const typename = vx_core.f_typename_from_typedef(typedef)
                  const msg = vx_core.f_msg_from_error('(new ' + typename + ' :key ' + vx_core.f_string_from_any(value) + ') - Invalid Key')
                  msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
                }
                break
              }
            } else {
              const property = properties[key]
              const propertytype = property['type']
              if (propertytype == vx_core.t_any) {
                propmap[key] = value
              } else if (propertytype == valuetype) {
                propmap[key] = value
              } else {
                const typename = vx_core.f_typename_from_typedef(typedef)
                const msg = vx_core.f_msg_from_error('(new ' + typename + ' :key ' + key + ' :value ' + vx_core.f_string_from_any(value) + ') - Invalid Key Value')
                msgblock = vx_core.f_msgblock_from_msgblock_msg(msgblock, msg)
              }
              key = ''
            }
          })
        }
        // output = vx_core.f_mempool-getvalue()
        if ((Object.keys(propmap).length > 0) || (msgblock != vx_core.e_msgblock)) {
          output = {
            vx_type: typedef,
            vx_value: propmap
          }
          if (msgblock != vx_core.e_msgblock) {
            output['vx_msgblock'] = msgblock
          }
        } else {
          output = vx_core.f_empty(typedef)
        }
        break
      }
      break
    }
    return output
  }

  /**
   * @function number_from_func
   * Function Type returning number with any parameters
   * @return {number}
   */
  static t_number_from_func = {}
  static e_number_from_func = {vx_type: vx_core.t_number_from_func}

  static f_number_from_func() {
    let output = vx_core.e_number
    return output
  }

  /**
   * @function or
   * Returns true if any value is true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   */
  static t_or = {}
  static e_or = {vx_type: vx_core.t_or}

  static f_or(val1, val2) {
    let output = vx_core.e_boolean
    if (val1 || val2) {
      output = true
    } else {
      output = false
    }
    return output
  }

  /**
   * @function or
   * Returns true if any value is true
   * @param  {booleanlist} ... values
   * @return {boolean}
   */
  static t_or_1 = {}
  static e_or_1 = {vx_type: vx_core.t_or_1}

  static f_or_1(...values) {
    let output = vx_core.e_boolean
    values = vx_core.f_new(vx_core.t_booleanlist, ...values)
    output = vx_core.f_any_from_list_reduce_next(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_boolean, "list-2": vx_core.t_booleanlist},
      values,
      false,
      vx_core.f_new(vx_core.t_any_from_reduce_next, (reduce, current, next) => 
        vx_core.f_or(
          reduce,
          vx_core.f_or(current, next)
        ))
    )
    return output
  }

  /**
   * @function packagename_from_typedef
   * Returns the package name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   */
  static t_packagename_from_typedef = {}
  static e_packagename_from_typedef = {vx_type: vx_core.t_packagename_from_typedef}

  static f_packagename_from_typedef(vtypedef) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_core.t_typedef}, vtypedef, ":pkgname")
    return output
  }

  /**
   * @function path_from_context_path
   * Returns a path from a context
   * @param  {string} path
   * @return {string}
   */
  static t_path_from_context_path = {}
  static e_path_from_context_path = {vx_type: vx_core.t_path_from_context_path}

  static f_path_from_context_path(path, context) {
    let output = vx_core.e_string
    output = vx_core.f_path_from_setting_path(
      vx_core.f_setting_from_context(context),
      path
    )
    return output
  }

  /**
   * @function path_from_setting_path
   * Returns a path from a setting
   * @param  {setting} session
   * @param  {string} path
   * @return {string}
   */
  static t_path_from_setting_path = {}
  static e_path_from_setting_path = {vx_type: vx_core.t_path_from_setting_path}

  static f_path_from_setting_path(session, path) {
    let output = vx_core.e_string
    return output
  }

  /**
   * @function permission_from_id_context
   * Return a permission from context by id
   * @param  {string} id
   * @return {permission}
   */
  static t_permission_from_id_context = {}
  static e_permission_from_id_context = {vx_type: vx_core.t_permission_from_id_context}

  static f_permission_from_id_context(id, context) {
    let output = vx_core.e_permission
    output = vx_core.f_let(
      {"any-1": vx_core.t_permission, "map-1": vx_core.t_permissionmap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const user = vx_core.f_user_from_context(context)
        const security = vx_core.f_any_from_struct({"any-1": vx_core.t_security, "struct-1": vx_core.t_user}, user, ":security")
        const permissionmap = vx_core.f_any_from_struct({"any-1": vx_core.t_permissionmap, "struct-1": vx_core.t_security}, security, ":permissionmap")
        return vx_core.f_any_from_map({"any-1": vx_core.t_permission, "map-1": vx_core.t_permissionmap}, permissionmap, ":id")
      })
    )
    return output
  }

  /**
   * @function properties_from_typedef
   * Return property map from typedef
   * @param  {typedef} vtypedef
   * @return {argmap}
   */
  static t_properties_from_typedef = {}
  static e_properties_from_typedef = {vx_type: vx_core.t_properties_from_typedef}

  static f_properties_from_typedef(vtypedef) {
    let output = vx_core.e_argmap
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_argmap, "struct-1": vx_core.t_typedef}, vtypedef, ":properties")
    return output
  }

  /**
   * @function proplast_from_typedef
   * Return last property from typedef
   * @param  {typedef} vtypedef
   * @return {arg}
   */
  static t_proplast_from_typedef = {}
  static e_proplast_from_typedef = {vx_type: vx_core.t_proplast_from_typedef}

  static f_proplast_from_typedef(vtypedef) {
    let output = vx_core.e_arg
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_arg, "struct-1": vx_core.t_typedef}, vtypedef, ":proplast")
    return output
  }

  /**
   * @function resolve
   * @param  {typemap} generic
   * @param  {any} value
   * @return {any-1}
   */
  static t_resolve = {}
  static e_resolve = {vx_type: vx_core.t_resolve}

  static f_resolve(generic, value) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = value
    return output
  }

  /**
   * @function resolve
   * @param  {typemap} generic
   * @param  {any_from_func} fn_any
   * @return {any-1}
   */
  static t_resolve_1 = {}
  static e_resolve_1 = {vx_type: vx_core.t_resolve_1}

  static f_resolve_1(generic, fn_any) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    const typedef = vx_core.f_typedef_from_any(fn_any)
    const extend = vx_core.f_extends_from_typedef(typedef)
    switch (extend) {
    case ':func':
      const fn = fn_any['vx_value']
      if (fn) {
        output = fn()
      }
      break
    default:
      output = fn_any
      break
    }
    return output
  }

  /**
   * 
   * @async @function resolve_async
   * @param  {typemap} generic
   * @param  {any_from_func_async} fn_any
   * @return {any-1}
   */
  static t_resolve_async = {}
  static e_resolve_async = {vx_type: vx_core.t_resolve_async}

  static async f_resolve_async(generic, fn_any) {
    const generic_any_1 = generic["any-1"]
    let output = Promise.resolve(vx_core.f_empty(generic_any_1))
    const typedef = vx_core.f_typedef_from_any(fn_any)
    const extend = vx_core.f_extends_from_typedef(typedef)
    switch (extend) {
    case ':func':
      const fn = fn_any['vx_value']
      if (fn) {
        output = await fn()
      }
      break
    default:
      output = fn_any
      break
    }
    return output
  }

  /**
   * @function resolve_first
   * Returns the first value that is not nothing
   * @param  {typemap} generic
   * @param  {list} ... clauses
   * @return {any-1}
   */
  static t_resolve_first = {}
  static e_resolve_first = {vx_type: vx_core.t_resolve_first}

  static f_resolve_first(generic, ...clauses) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    clauses = vx_core.f_new(vx_core.t_list, ...clauses)
    output = vx_core.f_first_from_list_fn_any_from_any(
      {"any-1": vx_core.t_any},
      clauses,
      vx_core.f_new(vx_core.t_any_from_any, vx_core.t_resolve)
    )
    return output
  }

  /**
   * @function resolve_list
   * @param  {typemap} generic
   * @param  {list} clauses
   * @return {list-1}
   */
  static t_resolve_list = {}
  static e_resolve_list = {vx_type: vx_core.t_resolve_list}

  static f_resolve_list(generic, clauses) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
      clauses,
      vx_core.f_new(vx_core.t_any_from_any, vx_core.t_resolve)
    )
    return output
  }

  /**
   * @function session_from_context
   * Returns session from a context
   * @return {session}
   */
  static t_session_from_context = {}
  static e_session_from_context = {vx_type: vx_core.t_session_from_context}

  static f_session_from_context(context) {
    let output = vx_core.e_session
    output = vx_core.f_any_from_struct(
      {"any-1": vx_core.t_session, "struct-1": vx_core.t_context},
      vx_core.t_context,
      ":session"
    )
    return output
  }

  /**
   * @function setting_from_context
   * Returns setting from a context
   * @return {setting}
   */
  static t_setting_from_context = {}
  static e_setting_from_context = {vx_type: vx_core.t_setting_from_context}

  static f_setting_from_context(context) {
    let output = vx_core.e_setting
    output = vx_core.f_any_from_struct(
      {"any-1": vx_core.t_setting, "struct-1": vx_core.t_context},
      vx_core.t_context,
      ":setting"
    )
    return output
  }

  /**
   * @function string_repeat
   * @param  {string} text
   * @param  {int} repeat
   * @return {string}
   */
  static t_string_repeat = {}
  static e_string_repeat = {vx_type: vx_core.t_string_repeat}

  static f_string_repeat(text, repeat) {
    let output = vx_core.e_string
    output = text.repeat(repeat)
    return output
  }

  /**
   * @function string_from_any
   * Return a string representation of a value
   * @param  {any} value
   * @return {string}
   */
  static t_string_from_any = {}
  static e_string_from_any = {vx_type: vx_core.t_string_from_any}

  static f_string_from_any(value) {
    let output = vx_core.e_string
    output = vx_core.f_string_from_any_indent(
      value,
      0,
      true
    )
    return output
  }

  /**
   * @function string_from_any_indent
   * Return a string representation of a value
   * @param  {any} value
   * @param  {int} indent
   * @param  {boolean} linefeed
   * @return {string}
   */
  static t_string_from_any_indent = {}
  static e_string_from_any_indent = {vx_type: vx_core.t_string_from_any_indent}

  static f_string_from_any_indent(value, indent, linefeed) {
    let output = vx_core.e_string
    const indenttext = ' '.repeat(indent)
    let text = ''
    const typedef = vx_core.f_typedef_from_any(value)
    if (indent > 50) {
      text = 'Error: Max Depth Exceeded'
    } else if (value == null) {
      text = 'null'
    } else if (value == typedef) {
      text = vx_core.f_typename_from_typedef(typedef)
    } else {
      switch (typedef) {
      case vx_core.t_boolean:
        if (value == true) {
          text = 'true'
        } else {
          text = 'false'
        }
        break
      case vx_core.t_decimal:
        text = '' + value
        break
      case vx_core.t_float:
        text = '' + value
        if (text.endsWith('.0')) {
          text = text.substring(0, text.length() - 2)
        }
        break
      case vx_core.t_int:
        if (value == vx_core.c_notanumber) {
          text = 'notanumber'
        } else if (value == vx_core.c_infinity) {
          text = 'infinity'
        } else if (value == vx_core.c_neginfinity) {
          text = 'neginfinity'
        } else {
          text = '' + value
        }
        break
      case vx_core.t_string:
        text = '"' + value + '"'
        break
      default:
        const typedefname = typedef['vx_value']['name']
        const extend = vx_core.f_extends_from_typedef(typedef)
        switch (extend) {
        case ':list':
          indent += 1
          for (const valsub of value) {
            const valtext = vx_core.f_string_from_any_indent(valsub, indent, linefeed)
            text += '\n ' + indenttext + valtext
          }
          if (value['vx_msgblock'] != null) {
            const msgtext = vx_core.f_string_from_any_indent(value['vx_msgblock'], indent, linefeed)
            text += '\n' + indenttext + ' :msgblock\n  ' + indenttext + msgtext
          }
          text = '(' + typedefname + text + ')'
          break
        case ':map':
        case ':struct':
          indent += 2
          const valmap = value['vx_value']
          for (let key in valmap) {
            const valsub = valmap[key]
            if (!key.startsWith(':')) {
              key = ':' + key
            }
            let valtext = vx_core.f_string_from_any_indent(valsub, indent, linefeed)
            if (valtext.indexOf('\n') >= 0) {
              valtext = '\n  ' + indenttext + valtext
            } else {
              valtext = ' ' + valtext
            }
            text += '\n' + indenttext + ' ' + key + valtext
          }
          if (value['vx_msgblock'] != null) {
            const msgtext = vx_core.f_string_from_any_indent(value['vx_msgblock'], indent, linefeed)
            text += '\n' + indenttext + ' :msgblock\n  ' + indenttext + msgtext
          }
          text = '(' + typedefname + text + ')'
          break
        case ':func':
          text = typedefname
          if (value['vx_msgblock'] != null) {
            const msgtext = vx_core.f_string_from_any_indent(value['vx_msgblock'], indent, linefeed)
            text += '\n' + indenttext + ' :msgblock\n  ' + indenttext + msgtext
          }
          text = '(' + text + ')'
          break
        }
        break
      }
    }
    output = text
    return output
  }

  /**
   * @function string_from_func
   * Function Type returning string with any parameters
   * @return {string}
   */
  static t_string_from_func = {}
  static e_string_from_func = {vx_type: vx_core.t_string_from_func}

  static f_string_from_func() {
    let output = vx_core.e_string
    return output
  }

  /**
   * @function switch
   * @param  {typemap} generic
   * @param  {any} val
   * @param  {thenelselist} ... thenelselist
   * @return {any-1}
   */
  static t_switch = {}
  static e_switch = {vx_type: vx_core.t_switch}

  static f_switch(generic, val, ...thenelselist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    thenelselist = vx_core.f_new(vx_core.t_thenelselist, ...thenelselist)
    let fn_any = null
    if (thenelselist.length > 0) {
      for (let valthenelse of thenelselist) {
        const thenelse = valthenelse['vx_value']
        const code = thenelse['code']
        switch (code) {
        case ':case':
          const value = thenelse['value']
          if (value == val) {
            fn_any = thenelse['fn-any']
          } else if (typeof value == 'number') {
            // special handling of notanumber
            if (isNaN(val) && isNaN(value)) {
              fn_any = thenelse['fn-any']
            }
          }
          break
        case ':casemany':
          const values = thenelse['values']
          if (values.includes(val)) {
            fn_any = thenelse['fn-any']
          }
          break
        case ':else':
          fn_any = thenelse['fn-any']
          break
        }
        if (fn_any != null) {
          break
        }
      }
      if (fn_any != null) {
        const fn = fn_any['vx_value']
        if (fn) {
          output = fn()
        }
      }
    }
    return output
  }

  /**
   * @function then
   * @param  {boolean_from_func} fn_cond
   * @param  {any_from_func} fn_any
   * @return {thenelse}
   */
  static t_then = {}
  static e_then = {vx_type: vx_core.t_then}

  static f_then(fn_cond, fn_any) {
    let output = vx_core.e_thenelse
    output = vx_core.f_new(
      vx_core.t_thenelse,
      ":code",
      ":then",
      ":fn-cond",
      fn_cond,
      ":fn-any",
      fn_any
    )
    return output
  }

  /**
   * @function traits_from_typedef
   * Return trait list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   */
  static t_traits_from_typedef = {}
  static e_traits_from_typedef = {vx_type: vx_core.t_traits_from_typedef}

  static f_traits_from_typedef(vtypedef) {
    let output = vx_core.e_typelist
    output = vtypedef['vx_value']['traits']
    return output
  }

  /**
   * @function type_from_any
   * Gets the Type of a given Value
   * @param  {any} value
   * @return {any}
   */
  static t_type_from_any = {}
  static e_type_from_any = {vx_type: vx_core.t_type_from_any}

  static f_type_from_any(value) {
    let output = vx_core.e_any
    switch (typeof value) {
    case 'boolean':
      output = vx_core.t_boolean
      break
    case 'number':
      switch (value) {
      case vx_core.c_infinity:
      case vx_core.c_neginfinity:
      case vx_core.c_notanumber:
        output = vx_core.t_int
        break
      default:
        const strval = '' + value
        if (strval.indexOf('.') < 0) {
          output = vx_core.t_int
        } else {
          output = vx_core.t_float
        }
        break
      }
      break
    case 'string':
      output = vx_core.t_string
      break
    case 'function':
      output = vx_core.t_func
      break
    default:
      output = value['vx_type']
      if (output == vx_core.t_type) {
        output = value
      }
      break
    }
    return output
  }

  /**
   * @function typedef_from_any
   * @param  {any} val
   * @return {typedef}
   */
  static t_typedef_from_any = {}
  static e_typedef_from_any = {vx_type: vx_core.t_typedef_from_any}

  static f_typedef_from_any(val) {
    let output = vx_core.e_typedef
    output = vx_core.f_typedef_from_type(
      vx_core.f_type_from_any(val)
    )
    return output
  }

  /**
   * @function typedef_from_type
   * @param  {any} val
   * @return {typedef}
   */
  static t_typedef_from_type = {}
  static e_typedef_from_type = {vx_type: vx_core.t_typedef_from_type}

  static f_typedef_from_type(val) {
    let output = vx_core.e_typedef
    output = output = val
    return output
  }

  /**
   * @function typename_from_any
   * Gets the type of a given value
   * @param  {any} value
   * @return {string}
   */
  static t_typename_from_any = {}
  static e_typename_from_any = {vx_type: vx_core.t_typename_from_any}

  static f_typename_from_any(value) {
    let output = vx_core.e_string
    output = vx_core.f_typename_from_type(
      vx_core.f_type_from_any(value)
    )
    return output
  }

  /**
   * @function typename_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {string}
   */
  static t_typename_from_type = {}
  static e_typename_from_type = {vx_type: vx_core.t_typename_from_type}

  static f_typename_from_type(type) {
    let output = vx_core.e_string
    output = vx_core.f_typename_from_typedef(
      vx_core.f_typedef_from_type(type)
    )
    return output
  }

  /**
   * @function typename_from_typedef
   * Get the name of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   */
  static t_typename_from_typedef = {}
  static e_typename_from_typedef = {vx_type: vx_core.t_typename_from_typedef}

  static f_typename_from_typedef(vtypedef) {
    let output = vx_core.e_string
    output = vx_core.f_new(
      vx_core.t_string,
      vx_core.f_any_from_struct({"any-1": vx_core.t_anylist, "struct-1": vx_core.t_typedef}, vtypedef, ":pkgname"),
      "/",
      vx_core.f_any_from_struct({"any-1": vx_core.t_anylist, "struct-1": vx_core.t_typedef}, vtypedef, ":name")
    )
    return output
  }

  /**
   * @function typenames_from_typelist
   * Get the names from a type list
   * @param  {typelist} typelist
   * @return {stringlist}
   */
  static t_typenames_from_typelist = {}
  static e_typenames_from_typelist = {vx_type: vx_core.t_typenames_from_typelist}

  static f_typenames_from_typelist(typelist) {
    let output = vx_core.e_stringlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_string, "any-2": vx_core.t_any, "list-1": vx_core.t_stringlist, "list-2": vx_core.t_typelist},
      typelist,
      vx_core.f_new(vx_core.t_any_from_any, (type) => 
        vx_core.f_typename_from_type(type))
    )
    return output
  }

  /**
   * @function user_from_context
   * Returns the current user from context.
   * @return {user}
   */
  static t_user_from_context = {}
  static e_user_from_context = {vx_type: vx_core.t_user_from_context}

  static f_user_from_context(context) {
    let output = vx_core.e_user
    output = vx_core.f_any_from_struct(
      {"any-1": vx_core.t_user, "struct-1": vx_core.t_session},
      vx_core.f_session_from_context(context),
      ":user"
    )
    return output
  }

  // empty types
  static e_any = {}
  static e_any_async_from_func = {}
  static e_any_from_anylist = []
  static e_anylist = []
  static e_anytype = {}
  static e_arg = {}
  static e_arglist = []
  static e_argmap = {}
  static e_boolean = false
  static e_booleanlist = []
  static e_collection = {}
  static e_compilelanguages = {}
  static e_connect = {}
  static e_connectlist = []
  static e_connectmap = {}
  static e_const = {}
  static e_constdef = {}
  static e_constlist = []
  static e_constmap = {}
  static e_context = {}
  static e_decimal = {}
  static e_error = {}
  static e_float = 0
  static e_func = {}
  static e_funcdef = {}
  static e_funclist = []
  static e_funcmap = {}
  static e_int = 0
  static e_intlist = []
  static e_intmap = {}
  static e_list = []
  static e_listtype = {}
  static e_map = {}
  static e_maptype = {}
  static e_mempool = {}
  static e_msg = {}
  static e_msgblock = {}
  static e_msgblocklist = []
  static e_msglist = []
  static e_none = {}
  static e_notype = {}
  static e_number = {}
  static e_numberlist = []
  static e_numbermap = {}
  static e_package = {}
  static e_packagemap = {}
  static e_permission = {}
  static e_permissionlist = []
  static e_permissionmap = {}
  static e_security = {}
  static e_session = {}
  static e_setting = {}
  static e_state = {}
  static e_statelistener = {}
  static e_string = ''
  static e_stringlist = []
  static e_stringmap = {}
  static e_struct = {}
  static e_thenelse = {}
  static e_thenelselist = []
  static e_type = {}
  static e_typedef = {}
  static e_typelist = []
  static e_typemap = {}
  static e_user = {}
  static e_value = {}

  static c_empty = {
    "any": vx_core.e_any,
    "any-async<-func": vx_core.e_any_async_from_func,
    "any<-anylist": vx_core.e_any_from_anylist,
    "anylist": vx_core.e_anylist,
    "anytype": vx_core.e_anytype,
    "arg": vx_core.e_arg,
    "arglist": vx_core.e_arglist,
    "argmap": vx_core.e_argmap,
    "boolean": vx_core.e_boolean,
    "booleanlist": vx_core.e_booleanlist,
    "collection": vx_core.e_collection,
    "compilelanguages": vx_core.e_compilelanguages,
    "connect": vx_core.e_connect,
    "connectlist": vx_core.e_connectlist,
    "connectmap": vx_core.e_connectmap,
    "const": vx_core.e_const,
    "constdef": vx_core.e_constdef,
    "constlist": vx_core.e_constlist,
    "constmap": vx_core.e_constmap,
    "context": vx_core.e_context,
    "decimal": vx_core.e_decimal,
    "error": vx_core.e_error,
    "float": vx_core.e_float,
    "func": vx_core.e_func,
    "funcdef": vx_core.e_funcdef,
    "funclist": vx_core.e_funclist,
    "funcmap": vx_core.e_funcmap,
    "int": vx_core.e_int,
    "intlist": vx_core.e_intlist,
    "intmap": vx_core.e_intmap,
    "list": vx_core.e_list,
    "listtype": vx_core.e_listtype,
    "map": vx_core.e_map,
    "maptype": vx_core.e_maptype,
    "mempool": vx_core.e_mempool,
    "msg": vx_core.e_msg,
    "msgblock": vx_core.e_msgblock,
    "msgblocklist": vx_core.e_msgblocklist,
    "msglist": vx_core.e_msglist,
    "none": vx_core.e_none,
    "notype": vx_core.e_notype,
    "number": vx_core.e_number,
    "numberlist": vx_core.e_numberlist,
    "numbermap": vx_core.e_numbermap,
    "package": vx_core.e_package,
    "packagemap": vx_core.e_packagemap,
    "permission": vx_core.e_permission,
    "permissionlist": vx_core.e_permissionlist,
    "permissionmap": vx_core.e_permissionmap,
    "security": vx_core.e_security,
    "session": vx_core.e_session,
    "setting": vx_core.e_setting,
    "state": vx_core.e_state,
    "statelistener": vx_core.e_statelistener,
    "string": vx_core.e_string,
    "stringlist": vx_core.e_stringlist,
    "stringmap": vx_core.e_stringmap,
    "struct": vx_core.e_struct,
    "thenelse": vx_core.e_thenelse,
    "thenelselist": vx_core.e_thenelselist,
    "type": vx_core.e_type,
    "typedef": vx_core.e_typedef,
    "typelist": vx_core.e_typelist,
    "typemap": vx_core.e_typemap,
    "user": vx_core.e_user,
    "value": vx_core.e_value,
    "!": vx_core.e_not,
    "!-empty": vx_core.e_notempty,
    "!-empty_1": vx_core.e_notempty_1,
    "!=": vx_core.e_ne,
    "*": vx_core.e_multiply,
    "*_1": vx_core.e_multiply_1,
    "*_2": vx_core.e_multiply_2,
    "*_3": vx_core.e_multiply_3,
    "+": vx_core.e_plus,
    "+_1": vx_core.e_plus_1,
    "+_2": vx_core.e_plus_2,
    "+_3": vx_core.e_plus_3,
    "+1": vx_core.e_plus1,
    "-": vx_core.e_minus,
    "-_1": vx_core.e_minus_1,
    "-_2": vx_core.e_minus_2,
    "-_3": vx_core.e_minus_3,
    ".": vx_core.e_dotmethod,
    "/": vx_core.e_divide,
    "<": vx_core.e_lt,
    "<_1": vx_core.e_lt_1,
    "<-": vx_core.e_chainfirst,
    "<<-": vx_core.e_chainlast,
    "<=": vx_core.e_le,
    "<=_1": vx_core.e_le_1,
    "=": vx_core.e_eq,
    "=_1": vx_core.e_eq_1,
    ">": vx_core.e_gt,
    ">_1": vx_core.e_gt_1,
    ">=": vx_core.e_ge,
    ">=_1": vx_core.e_ge_1,
    "allowtypenames<-typedef": vx_core.e_allowtypenames_from_typedef,
    "allowtypes<-typedef": vx_core.e_allowtypes_from_typedef,
    "and": vx_core.e_and,
    "and_1": vx_core.e_and_1,
    "any<-any": vx_core.e_any_from_any,
    "any<-any-async": vx_core.e_any_from_any_async,
    "any<-any-context": vx_core.e_any_from_any_context,
    "any<-any-context-async": vx_core.e_any_from_any_context_async,
    "any<-func": vx_core.e_any_from_func,
    "any<-func-async": vx_core.e_any_from_func_async,
    "any<-key-value": vx_core.e_any_from_key_value,
    "any<-key-value-async": vx_core.e_any_from_key_value_async,
    "any<-list": vx_core.e_any_from_list,
    "any<-list-reduce": vx_core.e_any_from_list_reduce,
    "any<-list-reduce-next": vx_core.e_any_from_list_reduce_next,
    "any<-map": vx_core.e_any_from_map,
    "any<-none": vx_core.e_any_from_none,
    "any<-none-async": vx_core.e_any_from_none_async,
    "any<-reduce": vx_core.e_any_from_reduce,
    "any<-reduce-async": vx_core.e_any_from_reduce_async,
    "any<-reduce-next": vx_core.e_any_from_reduce_next,
    "any<-reduce-next-async": vx_core.e_any_from_reduce_next_async,
    "any<-struct": vx_core.e_any_from_struct,
    "async": vx_core.e_async,
    "boolean<-any": vx_core.e_boolean_from_any,
    "boolean<-func": vx_core.e_boolean_from_func,
    "boolean<-none": vx_core.e_boolean_from_none,
    "case": vx_core.e_case,
    "case_1": vx_core.e_case_1,
    "compare": vx_core.e_compare,
    "contains": vx_core.e_contains,
    "contains_1": vx_core.e_contains_1,
    "copy": vx_core.e_copy,
    "else": vx_core.e_else,
    "empty": vx_core.e_empty,
    "extends<-any": vx_core.e_extends_from_any,
    "extends<-typedef": vx_core.e_extends_from_typedef,
    "first<-list": vx_core.e_first_from_list,
    "first<-list-fn-any<-any": vx_core.e_first_from_list_fn_any_from_any,
    "fn": vx_core.e_fn,
    "funcdef<-func": vx_core.e_funcdef_from_func,
    "funcname<-funcdef": vx_core.e_funcname_from_funcdef,
    "global-package-get": vx_core.e_global_package_get,
    "global-package-set": vx_core.e_global_package_set,
    "if": vx_core.e_if,
    "if_1": vx_core.e_if_1,
    "if_2": vx_core.e_if_2,
    "int<-func": vx_core.e_int_from_func,
    "int<-string": vx_core.e_int_from_string,
    "is-empty": vx_core.e_is_empty,
    "is-empty_1": vx_core.e_is_empty_1,
    "is-endswith": vx_core.e_is_endswith,
    "is-func": vx_core.e_is_func,
    "is-int": vx_core.e_is_int,
    "is-number": vx_core.e_is_number,
    "is-pass<-permission": vx_core.e_is_pass_from_permission,
    "last<-list": vx_core.e_last_from_list,
    "length<-list": vx_core.e_length_from_list,
    "let": vx_core.e_let,
    "let-async": vx_core.e_let_async,
    "list-join<-list": vx_core.e_list_join_from_list,
    "list<-list": vx_core.e_list_from_list,
    "list<-list-async": vx_core.e_list_from_list_async,
    "list<-map": vx_core.e_list_from_map,
    "list<-map-async": vx_core.e_list_from_map_async,
    "list<-type": vx_core.e_list_from_type,
    "log": vx_core.e_log,
    "map<-list": vx_core.e_map_from_list,
    "mempool-addref": vx_core.e_mempool_addref,
    "mempool-release": vx_core.e_mempool_release,
    "mempool-removeref": vx_core.e_mempool_removeref,
    "mempool-removerefchildren": vx_core.e_mempool_removerefchildren,
    "mempool-reserve": vx_core.e_mempool_reserve,
    "msg<-error": vx_core.e_msg_from_error,
    "msgblock<-msgblock-msg": vx_core.e_msgblock_from_msgblock_msg,
    "msgblock<-msgblock-msgblock": vx_core.e_msgblock_from_msgblock_msgblock,
    "name<-typedef": vx_core.e_name_from_typedef,
    "native": vx_core.e_native,
    "native<-any": vx_core.e_native_from_any,
    "new": vx_core.e_new,
    "number<-func": vx_core.e_number_from_func,
    "or": vx_core.e_or,
    "or_1": vx_core.e_or_1,
    "packagename<-typedef": vx_core.e_packagename_from_typedef,
    "path<-context-path": vx_core.e_path_from_context_path,
    "path<-setting-path": vx_core.e_path_from_setting_path,
    "permission<-id-context": vx_core.e_permission_from_id_context,
    "properties<-typedef": vx_core.e_properties_from_typedef,
    "proplast<-typedef": vx_core.e_proplast_from_typedef,
    "resolve": vx_core.e_resolve,
    "resolve_1": vx_core.e_resolve_1,
    "resolve-async": vx_core.e_resolve_async,
    "resolve-first": vx_core.e_resolve_first,
    "resolve-list": vx_core.e_resolve_list,
    "session<-context": vx_core.e_session_from_context,
    "setting<-context": vx_core.e_setting_from_context,
    "string-repeat": vx_core.e_string_repeat,
    "string<-any": vx_core.e_string_from_any,
    "string<-any-indent": vx_core.e_string_from_any_indent,
    "string<-func": vx_core.e_string_from_func,
    "switch": vx_core.e_switch,
    "then": vx_core.e_then,
    "traits<-typedef": vx_core.e_traits_from_typedef,
    "type<-any": vx_core.e_type_from_any,
    "typedef<-any": vx_core.e_typedef_from_any,
    "typedef<-type": vx_core.e_typedef_from_type,
    "typename<-any": vx_core.e_typename_from_any,
    "typename<-type": vx_core.e_typename_from_type,
    "typename<-typedef": vx_core.e_typename_from_typedef,
    "typenames<-typelist": vx_core.e_typenames_from_typelist,
    "user<-context": vx_core.e_user_from_context
  }


  static {
    vx_core.f_global_package_set("vx/core", vx_core)

    // (type any)
    vx_core.t_any['vx_type'] = vx_core.t_type
    vx_core.t_any['vx_value'] = {
      name          : "any",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_any['vx_type'] = vx_core.t_any
    vx_core.e_any['vx_value'] = {}

    // (type any-async<-func)
    vx_core.t_any_async_from_func['vx_type'] = vx_core.t_type
    vx_core.t_any_async_from_func['vx_value'] = {
      name          : "any-async<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      allowfuncs    : [vx_core.f_any_from_func, vx_core.f_any_from_func_async],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_any_async_from_func['vx_type'] = vx_core.t_any_async_from_func
    vx_core.e_any_async_from_func['vx_value'] = {}

    // (type any<-anylist)
    vx_core.t_any_from_anylist['vx_type'] = vx_core.t_type
    vx_core.t_any_from_anylist['vx_value'] = {
      name          : "any<-anylist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [vx_core.f_any_from_any],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_any_from_anylist['vx_type'] = vx_core.t_any_from_anylist

    // (type anylist)
    vx_core.t_anylist['vx_type'] = vx_core.t_type
    vx_core.t_anylist['vx_value'] = {
      name          : "anylist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_anylist['vx_type'] = vx_core.t_anylist

    // (type anytype)
    vx_core.t_anytype['vx_type'] = vx_core.t_type
    vx_core.t_anytype['vx_value'] = {
      name          : "anytype",
      pkgname       : "vx/core",
      extends       : ":type",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_anytype['vx_type'] = vx_core.t_anytype
    vx_core.e_anytype['vx_value'] = {}

    // (type arg)
    vx_core.t_arg['vx_type'] = vx_core.t_type
    vx_core.t_arg['vx_value'] = {
      name          : "arg",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "argtype": {
          "name" : "argtype",
          "type" : vx_core.t_type,
          "multi": false
        },
        "fn-any": {
          "name" : "fn-any",
          "type" : vx_core.t_any_from_func,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-any",
        "type" : vx_core.t_any_from_func,
        "multi": false
      }
    }
    vx_core.e_arg['vx_type'] = vx_core.t_arg
    vx_core.e_arg['vx_value'] = {}

    // (type arglist)
    vx_core.t_arglist['vx_type'] = vx_core.t_type
    vx_core.t_arglist['vx_value'] = {
      name          : "arglist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_arg],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_arglist['vx_type'] = vx_core.t_arglist

    // (type argmap)
    vx_core.t_argmap['vx_type'] = vx_core.t_type
    vx_core.t_argmap['vx_value'] = {
      name          : "argmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_arg],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_argmap['vx_type'] = vx_core.t_argmap
    vx_core.e_argmap['vx_value'] = {}

    // (type boolean)
    vx_core.t_boolean['vx_type'] = vx_core.t_type
    vx_core.t_boolean['vx_value'] = {
      name          : "boolean",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    // (type booleanlist)
    vx_core.t_booleanlist['vx_type'] = vx_core.t_type
    vx_core.t_booleanlist['vx_value'] = {
      name          : "booleanlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_boolean],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_booleanlist['vx_type'] = vx_core.t_booleanlist

    // (type collection)
    vx_core.t_collection['vx_type'] = vx_core.t_type
    vx_core.t_collection['vx_value'] = {
      name          : "collection",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_list, vx_core.t_map],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_collection['vx_type'] = vx_core.t_collection
    vx_core.e_collection['vx_value'] = {}

    // (type compilelanguages)
    vx_core.t_compilelanguages['vx_type'] = vx_core.t_type
    vx_core.t_compilelanguages['vx_value'] = {
      name          : "compilelanguages",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_compilelanguages['vx_type'] = vx_core.t_compilelanguages
    vx_core.e_compilelanguages['vx_value'] = {}

    // (type connect)
    vx_core.t_connect['vx_type'] = vx_core.t_type
    vx_core.t_connect['vx_value'] = {
      name          : "connect",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_connect['vx_type'] = vx_core.t_connect
    vx_core.e_connect['vx_value'] = {}

    // (type connectlist)
    vx_core.t_connectlist['vx_type'] = vx_core.t_type
    vx_core.t_connectlist['vx_value'] = {
      name          : "connectlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_connect],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_connectlist['vx_type'] = vx_core.t_connectlist

    // (type connectmap)
    vx_core.t_connectmap['vx_type'] = vx_core.t_type
    vx_core.t_connectmap['vx_value'] = {
      name          : "connectmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_connect],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_connectmap['vx_type'] = vx_core.t_connectmap
    vx_core.e_connectmap['vx_value'] = {}

    // (type const)
    vx_core.t_const['vx_type'] = vx_core.t_type
    vx_core.t_const['vx_value'] = {
      name          : "const",
      pkgname       : "vx/core",
      extends       : ":const",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_const['vx_type'] = vx_core.t_const
    vx_core.e_const['vx_value'] = {}

    // (type constdef)
    vx_core.t_constdef['vx_type'] = vx_core.t_type
    vx_core.t_constdef['vx_value'] = {
      name          : "constdef",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "pkgname": {
          "name" : "pkgname",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "type": {
          "name" : "type",
          "type" : vx_core.t_any,
          "multi": false
        }
      },
      proplast      : {
        "name" : "type",
        "type" : vx_core.t_any,
        "multi": false
      }
    }
    vx_core.e_constdef['vx_type'] = vx_core.t_constdef
    vx_core.e_constdef['vx_value'] = {}

    // (type constlist)
    vx_core.t_constlist['vx_type'] = vx_core.t_type
    vx_core.t_constlist['vx_value'] = {
      name          : "constlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_const],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_constlist['vx_type'] = vx_core.t_constlist

    // (type constmap)
    vx_core.t_constmap['vx_type'] = vx_core.t_type
    vx_core.t_constmap['vx_value'] = {
      name          : "constmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_const],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_constmap['vx_type'] = vx_core.t_constmap
    vx_core.e_constmap['vx_value'] = {}

    // (type context)
    vx_core.t_context['vx_type'] = vx_core.t_type
    vx_core.t_context['vx_value'] = {
      name          : "context",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "code": {
          "name" : "code",
          "type" : vx_core.t_string,
          "multi": false
        },
        "session": {
          "name" : "session",
          "type" : vx_core.t_session,
          "multi": false
        },
        "setting": {
          "name" : "setting",
          "type" : vx_core.t_setting,
          "multi": false
        },
        "state": {
          "name" : "state",
          "type" : vx_core.t_state,
          "multi": false
        }
      },
      proplast      : {
        "name" : "state",
        "type" : vx_core.t_state,
        "multi": false
      }
    }
    vx_core.e_context['vx_type'] = vx_core.t_context
    vx_core.e_context['vx_value'] = {}

    // (type decimal)
    vx_core.t_decimal['vx_type'] = vx_core.t_type
    vx_core.t_decimal['vx_value'] = {
      name          : "decimal",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_core.t_number],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_decimal['vx_type'] = vx_core.t_decimal
    vx_core.e_decimal['vx_value'] = {}

    // (type error)
    vx_core.t_error['vx_type'] = vx_core.t_type
    vx_core.t_error['vx_value'] = {
      name          : "error",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_error['vx_type'] = vx_core.t_error
    vx_core.e_error['vx_value'] = {}

    // (type float)
    vx_core.t_float['vx_type'] = vx_core.t_type
    vx_core.t_float['vx_value'] = {
      name          : "float",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_core.t_number],
      properties    : {},
      proplast      : {}
    }
    // (type func)
    vx_core.t_func['vx_type'] = vx_core.t_type
    vx_core.t_func['vx_value'] = {
      name          : "func",
      pkgname       : "vx/core",
      extends       : ":func",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_func['vx_type'] = vx_core.t_func
    vx_core.e_func['vx_value'] = {}

    // (type funcdef)
    vx_core.t_funcdef['vx_type'] = vx_core.t_type
    vx_core.t_funcdef['vx_value'] = {
      name          : "funcdef",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "pkgname": {
          "name" : "pkgname",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "idx": {
          "name" : "idx",
          "type" : vx_core.t_int,
          "multi": false
        },
        "type": {
          "name" : "type",
          "type" : vx_core.t_any,
          "multi": false
        },
        "async": {
          "name" : "async",
          "type" : vx_core.t_boolean,
          "multi": false
        }
      },
      proplast      : {
        "name" : "async",
        "type" : vx_core.t_boolean,
        "multi": false
      }
    }
    vx_core.e_funcdef['vx_type'] = vx_core.t_funcdef
    vx_core.e_funcdef['vx_value'] = {}

    // (type funclist)
    vx_core.t_funclist['vx_type'] = vx_core.t_type
    vx_core.t_funclist['vx_value'] = {
      name          : "funclist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_func],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_funclist['vx_type'] = vx_core.t_funclist

    // (type funcmap)
    vx_core.t_funcmap['vx_type'] = vx_core.t_type
    vx_core.t_funcmap['vx_value'] = {
      name          : "funcmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_func],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_funcmap['vx_type'] = vx_core.t_funcmap
    vx_core.e_funcmap['vx_value'] = {}

    // (type int)
    vx_core.t_int['vx_type'] = vx_core.t_type
    vx_core.t_int['vx_value'] = {
      name          : "int",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_core.t_number],
      properties    : {},
      proplast      : {}
    }
    // (type intlist)
    vx_core.t_intlist['vx_type'] = vx_core.t_type
    vx_core.t_intlist['vx_value'] = {
      name          : "intlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_int],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_intlist['vx_type'] = vx_core.t_intlist

    // (type intmap)
    vx_core.t_intmap['vx_type'] = vx_core.t_type
    vx_core.t_intmap['vx_value'] = {
      name          : "intmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_int],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_intmap['vx_type'] = vx_core.t_intmap
    vx_core.e_intmap['vx_value'] = {}

    // (type list)
    vx_core.t_list['vx_type'] = vx_core.t_type
    vx_core.t_list['vx_value'] = {
      name          : "list",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_list['vx_type'] = vx_core.t_list

    // (type listtype)
    vx_core.t_listtype['vx_type'] = vx_core.t_type
    vx_core.t_listtype['vx_value'] = {
      name          : "listtype",
      pkgname       : "vx/core",
      extends       : ":type",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_listtype['vx_type'] = vx_core.t_listtype
    vx_core.e_listtype['vx_value'] = {}

    // (type map)
    vx_core.t_map['vx_type'] = vx_core.t_type
    vx_core.t_map['vx_value'] = {
      name          : "map",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_map['vx_type'] = vx_core.t_map
    vx_core.e_map['vx_value'] = {}

    // (type maptype)
    vx_core.t_maptype['vx_type'] = vx_core.t_type
    vx_core.t_maptype['vx_value'] = {
      name          : "maptype",
      pkgname       : "vx/core",
      extends       : ":type",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_maptype['vx_type'] = vx_core.t_maptype
    vx_core.e_maptype['vx_value'] = {}

    // (type mempool)
    vx_core.t_mempool['vx_type'] = vx_core.t_type
    vx_core.t_mempool['vx_value'] = {
      name          : "mempool",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "valuepool": {
          "name" : "valuepool",
          "type" : vx_core.t_value,
          "multi": false
        }
      },
      proplast      : {
        "name" : "valuepool",
        "type" : vx_core.t_value,
        "multi": false
      }
    }
    vx_core.e_mempool['vx_type'] = vx_core.t_mempool
    vx_core.e_mempool['vx_value'] = {}

    // (type msg)
    vx_core.t_msg['vx_type'] = vx_core.t_type
    vx_core.t_msg['vx_value'] = {
      name          : "msg",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "code": {
          "name" : "code",
          "type" : vx_core.t_string,
          "multi": false
        },
        "severity": {
          "name" : "severity",
          "type" : vx_core.t_int,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_core.e_msg['vx_type'] = vx_core.t_msg
    vx_core.e_msg['vx_value'] = {}

    // (type msgblock)
    vx_core.t_msgblock['vx_type'] = vx_core.t_type
    vx_core.t_msgblock['vx_value'] = {
      name          : "msgblock",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "msgs": {
          "name" : "msgs",
          "type" : vx_core.t_msglist,
          "multi": false
        },
        "msgblocks": {
          "name" : "msgblocks",
          "type" : vx_core.t_msgblocklist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "msgblocks",
        "type" : vx_core.t_msgblocklist,
        "multi": false
      }
    }
    vx_core.e_msgblock['vx_type'] = vx_core.t_msgblock
    vx_core.e_msgblock['vx_value'] = {}

    // (type msgblocklist)
    vx_core.t_msgblocklist['vx_type'] = vx_core.t_type
    vx_core.t_msgblocklist['vx_value'] = {
      name          : "msgblocklist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_msgblock],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_msgblocklist['vx_type'] = vx_core.t_msgblocklist

    // (type msglist)
    vx_core.t_msglist['vx_type'] = vx_core.t_type
    vx_core.t_msglist['vx_value'] = {
      name          : "msglist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_msg],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_msglist['vx_type'] = vx_core.t_msglist

    // (type none)
    vx_core.t_none['vx_type'] = vx_core.t_type
    vx_core.t_none['vx_value'] = {
      name          : "none",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_none['vx_type'] = vx_core.t_none
    vx_core.e_none['vx_value'] = {}

    // (type notype)
    vx_core.t_notype['vx_type'] = vx_core.t_type
    vx_core.t_notype['vx_value'] = {
      name          : "notype",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_notype['vx_type'] = vx_core.t_notype
    vx_core.e_notype['vx_value'] = {}

    // (type number)
    vx_core.t_number['vx_type'] = vx_core.t_type
    vx_core.t_number['vx_value'] = {
      name          : "number",
      pkgname       : "vx/core",
      extends       : "",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_int, vx_core.t_float, vx_core.t_decimal],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_number['vx_type'] = vx_core.t_number
    vx_core.e_number['vx_value'] = {}

    // (type numberlist)
    vx_core.t_numberlist['vx_type'] = vx_core.t_type
    vx_core.t_numberlist['vx_value'] = {
      name          : "numberlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_number],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_numberlist['vx_type'] = vx_core.t_numberlist

    // (type numbermap)
    vx_core.t_numbermap['vx_type'] = vx_core.t_type
    vx_core.t_numbermap['vx_value'] = {
      name          : "numbermap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_number],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_numbermap['vx_type'] = vx_core.t_numbermap
    vx_core.e_numbermap['vx_value'] = {}

    // (type package)
    vx_core.t_package['vx_type'] = vx_core.t_type
    vx_core.t_package['vx_value'] = {
      name          : "package",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_package['vx_type'] = vx_core.t_package
    vx_core.e_package['vx_value'] = {}

    // (type packagemap)
    vx_core.t_packagemap['vx_type'] = vx_core.t_type
    vx_core.t_packagemap['vx_value'] = {
      name          : "packagemap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_package],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_packagemap['vx_type'] = vx_core.t_packagemap
    vx_core.e_packagemap['vx_value'] = {}

    // (type permission)
    vx_core.t_permission['vx_type'] = vx_core.t_type
    vx_core.t_permission['vx_value'] = {
      name          : "permission",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "id",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_core.e_permission['vx_type'] = vx_core.t_permission
    vx_core.e_permission['vx_value'] = {}

    // (type permissionlist)
    vx_core.t_permissionlist['vx_type'] = vx_core.t_type
    vx_core.t_permissionlist['vx_value'] = {
      name          : "permissionlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_permission],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_permissionlist['vx_type'] = vx_core.t_permissionlist

    // (type permissionmap)
    vx_core.t_permissionmap['vx_type'] = vx_core.t_type
    vx_core.t_permissionmap['vx_value'] = {
      name          : "permissionmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_permission],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_permissionmap['vx_type'] = vx_core.t_permissionmap
    vx_core.e_permissionmap['vx_value'] = {}

    // (type security)
    vx_core.t_security['vx_type'] = vx_core.t_type
    vx_core.t_security['vx_value'] = {
      name          : "security",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "permissions": {
          "name" : "permissions",
          "type" : vx_core.t_permissionlist,
          "multi": false
        },
        "permissionmap": {
          "name" : "permissionmap",
          "type" : vx_core.t_permissionmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "permissionmap",
        "type" : vx_core.t_permissionmap,
        "multi": false
      }
    }
    vx_core.e_security['vx_type'] = vx_core.t_security
    vx_core.e_security['vx_value'] = {}

    // (type session)
    vx_core.t_session['vx_type'] = vx_core.t_type
    vx_core.t_session['vx_value'] = {
      name          : "session",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "user": {
          "name" : "user",
          "type" : vx_core.t_user,
          "multi": false
        },
        "connectlist": {
          "name" : "connectlist",
          "type" : vx_core.t_connectlist,
          "multi": false
        },
        "connectmap": {
          "name" : "connectmap",
          "type" : vx_core.t_connectmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "connectmap",
        "type" : vx_core.t_connectmap,
        "multi": false
      }
    }
    vx_core.e_session['vx_type'] = vx_core.t_session
    vx_core.e_session['vx_value'] = {}

    // (type setting)
    vx_core.t_setting['vx_type'] = vx_core.t_type
    vx_core.t_setting['vx_value'] = {
      name          : "setting",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "pathmap": {
          "name" : "pathmap",
          "type" : vx_core.t_stringmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "pathmap",
        "type" : vx_core.t_stringmap,
        "multi": false
      }
    }
    vx_core.e_setting['vx_type'] = vx_core.t_setting
    vx_core.e_setting['vx_value'] = {}

    // (type state)
    vx_core.t_state['vx_type'] = vx_core.t_type
    vx_core.t_state['vx_value'] = {
      name          : "state",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_statelistener],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_state['vx_type'] = vx_core.t_state
    vx_core.e_state['vx_value'] = {}

    // (type statelistener)
    vx_core.t_statelistener['vx_type'] = vx_core.t_type
    vx_core.t_statelistener['vx_value'] = {
      name          : "statelistener",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "path": {
          "name" : "path",
          "type" : vx_core.t_string,
          "multi": false
        },
        "value": {
          "name" : "value",
          "type" : vx_core.t_any,
          "multi": false
        },
        "fn-boolean": {
          "name" : "fn-boolean",
          "type" : vx_core.t_boolean_from_none,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-boolean",
        "type" : vx_core.t_boolean_from_none,
        "multi": false
      }
    }
    vx_core.e_statelistener['vx_type'] = vx_core.t_statelistener
    vx_core.e_statelistener['vx_value'] = {}

    // (type string)
    vx_core.t_string['vx_type'] = vx_core.t_type
    vx_core.t_string['vx_value'] = {
      name          : "string",
      pkgname       : "vx/core",
      extends       : "string",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    // (type stringlist)
    vx_core.t_stringlist['vx_type'] = vx_core.t_type
    vx_core.t_stringlist['vx_value'] = {
      name          : "stringlist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_string],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_stringlist['vx_type'] = vx_core.t_stringlist

    // (type stringmap)
    vx_core.t_stringmap['vx_type'] = vx_core.t_type
    vx_core.t_stringmap['vx_value'] = {
      name          : "stringmap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_string],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_stringmap['vx_type'] = vx_core.t_stringmap
    vx_core.e_stringmap['vx_value'] = {}

    // (type struct)
    vx_core.t_struct['vx_type'] = vx_core.t_type
    vx_core.t_struct['vx_value'] = {
      name          : "struct",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_struct['vx_type'] = vx_core.t_struct
    vx_core.e_struct['vx_value'] = {}

    // (type thenelse)
    vx_core.t_thenelse['vx_type'] = vx_core.t_type
    vx_core.t_thenelse['vx_value'] = {
      name          : "thenelse",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "code": {
          "name" : "code",
          "type" : vx_core.t_string,
          "multi": false
        },
        "value": {
          "name" : "value",
          "type" : vx_core.t_any,
          "multi": false
        },
        "values": {
          "name" : "values",
          "type" : vx_core.t_list,
          "multi": false
        },
        "fn-cond": {
          "name" : "fn-cond",
          "type" : vx_core.t_boolean_from_func,
          "multi": false
        },
        "fn-any": {
          "name" : "fn-any",
          "type" : vx_core.t_any_from_func,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-any",
        "type" : vx_core.t_any_from_func,
        "multi": false
      }
    }
    vx_core.e_thenelse['vx_type'] = vx_core.t_thenelse
    vx_core.e_thenelse['vx_value'] = {}

    // (type thenelselist)
    vx_core.t_thenelselist['vx_type'] = vx_core.t_type
    vx_core.t_thenelselist['vx_value'] = {
      name          : "thenelselist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_thenelse],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_thenelselist['vx_type'] = vx_core.t_thenelselist

    // (type type)
    vx_core.t_type['vx_type'] = vx_core.t_type
    vx_core.t_type['vx_value'] = {
      name          : "type",
      pkgname       : "vx/core",
      extends       : ":type",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_type['vx_type'] = vx_core.t_type
    vx_core.e_type['vx_value'] = {}

    // (type typedef)
    vx_core.t_typedef['vx_type'] = vx_core.t_type
    vx_core.t_typedef['vx_value'] = {
      name          : "typedef",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "pkgname": {
          "name" : "pkgname",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "extends": {
          "name" : "extends",
          "type" : vx_core.t_string,
          "multi": false
        },
        "allowfuncs": {
          "name" : "allowfuncs",
          "type" : vx_core.t_funclist,
          "multi": false
        },
        "allowtypes": {
          "name" : "allowtypes",
          "type" : vx_core.t_typelist,
          "multi": false
        },
        "allowvalues": {
          "name" : "allowvalues",
          "type" : vx_core.t_anylist,
          "multi": false
        },
        "disallowfuncs": {
          "name" : "disallowfuncs",
          "type" : vx_core.t_funclist,
          "multi": false
        },
        "disallowtypes": {
          "name" : "disallowtypes",
          "type" : vx_core.t_typelist,
          "multi": false
        },
        "disallowvalues": {
          "name" : "disallowvalues",
          "type" : vx_core.t_anylist,
          "multi": false
        },
        "properties": {
          "name" : "properties",
          "type" : vx_core.t_argmap,
          "multi": false
        },
        "proplast": {
          "name" : "proplast",
          "type" : vx_core.t_arg,
          "multi": false
        },
        "traits": {
          "name" : "traits",
          "type" : vx_core.t_typelist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "traits",
        "type" : vx_core.t_typelist,
        "multi": false
      }
    }
    vx_core.e_typedef['vx_type'] = vx_core.t_typedef
    vx_core.e_typedef['vx_value'] = {}

    // (type typelist)
    vx_core.t_typelist['vx_type'] = vx_core.t_type
    vx_core.t_typelist['vx_value'] = {
      name          : "typelist",
      pkgname       : "vx/core",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_typelist['vx_type'] = vx_core.t_typelist

    // (type typemap)
    vx_core.t_typemap['vx_type'] = vx_core.t_type
    vx_core.t_typemap['vx_value'] = {
      name          : "typemap",
      pkgname       : "vx/core",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_core.e_typemap['vx_type'] = vx_core.t_typemap
    vx_core.e_typemap['vx_value'] = {}

    // (type user)
    vx_core.t_user['vx_type'] = vx_core.t_type
    vx_core.t_user['vx_value'] = {
      name          : "user",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "security": {
          "name" : "security",
          "type" : vx_core.t_security,
          "multi": false
        },
        "username": {
          "name" : "username",
          "type" : vx_core.t_string,
          "multi": false
        },
        "token": {
          "name" : "token",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "token",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_core.e_user['vx_type'] = vx_core.t_user
    vx_core.e_user['vx_value'] = {}

    // (type value)
    vx_core.t_value['vx_type'] = vx_core.t_type
    vx_core.t_value['vx_value'] = {
      name          : "value",
      pkgname       : "vx/core",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "next": {
          "name" : "next",
          "type" : vx_core.t_any,
          "multi": false
        },
        "refs": {
          "name" : "refs",
          "type" : vx_core.t_int,
          "multi": false
        }
      },
      proplast      : {
        "name" : "refs",
        "type" : vx_core.t_int,
        "multi": false
      }
    }
    vx_core.e_value['vx_type'] = vx_core.t_value
    vx_core.e_value['vx_value'] = {}

    // (const mempool-active)
    Object.assign(vx_core.c_mempool_active, {
      "valuepool": {
        "next": "",
        "refs": 0,
      },
    })

    // (func not)
    vx_core.t_not['vx_type'] = vx_core.t_type
    vx_core.t_not['vx_value'] = {
      name          : "!",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_not
    }

    // (func notempty)
    vx_core.t_notempty['vx_type'] = vx_core.t_type
    vx_core.t_notempty['vx_value'] = {
      name          : "!-empty",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_notempty
    }

    // (func notempty_1)
    vx_core.t_notempty_1['vx_type'] = vx_core.t_type
    vx_core.t_notempty_1['vx_value'] = {
      name          : "!-empty",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_notempty_1
    }

    // (func ne)
    vx_core.t_ne['vx_type'] = vx_core.t_type
    vx_core.t_ne['vx_value'] = {
      name          : "!=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_ne
    }

    // (func multiply)
    vx_core.t_multiply['vx_type'] = vx_core.t_type
    vx_core.t_multiply['vx_value'] = {
      name          : "*",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_multiply
    }

    // (func multiply_1)
    vx_core.t_multiply_1['vx_type'] = vx_core.t_type
    vx_core.t_multiply_1['vx_value'] = {
      name          : "*",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_multiply_1
    }

    // (func multiply_2)
    vx_core.t_multiply_2['vx_type'] = vx_core.t_type
    vx_core.t_multiply_2['vx_value'] = {
      name          : "*",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 2,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_multiply_2
    }

    // (func multiply_3)
    vx_core.t_multiply_3['vx_type'] = vx_core.t_type
    vx_core.t_multiply_3['vx_value'] = {
      name          : "*",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 3,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_multiply_3
    }

    // (func plus)
    vx_core.t_plus['vx_type'] = vx_core.t_type
    vx_core.t_plus['vx_value'] = {
      name          : "+",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_plus
    }

    // (func plus_1)
    vx_core.t_plus_1['vx_type'] = vx_core.t_type
    vx_core.t_plus_1['vx_value'] = {
      name          : "+",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_plus_1
    }

    // (func plus_2)
    vx_core.t_plus_2['vx_type'] = vx_core.t_type
    vx_core.t_plus_2['vx_value'] = {
      name          : "+",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 2,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_plus_2
    }

    // (func plus_3)
    vx_core.t_plus_3['vx_type'] = vx_core.t_type
    vx_core.t_plus_3['vx_value'] = {
      name          : "+",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 3,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_plus_3
    }

    // (func plus1)
    vx_core.t_plus1['vx_type'] = vx_core.t_type
    vx_core.t_plus1['vx_value'] = {
      name          : "+1",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_plus1
    }

    // (func minus)
    vx_core.t_minus['vx_type'] = vx_core.t_type
    vx_core.t_minus['vx_value'] = {
      name          : "-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_minus
    }

    // (func minus_1)
    vx_core.t_minus_1['vx_type'] = vx_core.t_type
    vx_core.t_minus_1['vx_value'] = {
      name          : "-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_minus_1
    }

    // (func minus_2)
    vx_core.t_minus_2['vx_type'] = vx_core.t_type
    vx_core.t_minus_2['vx_value'] = {
      name          : "-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 2,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_minus_2
    }

    // (func minus_3)
    vx_core.t_minus_3['vx_type'] = vx_core.t_type
    vx_core.t_minus_3['vx_value'] = {
      name          : "-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 3,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_minus_3
    }

    // (func dotmethod)
    vx_core.t_dotmethod['vx_type'] = vx_core.t_type
    vx_core.t_dotmethod['vx_value'] = {
      name          : ".",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_dotmethod
    }

    // (func divide)
    vx_core.t_divide['vx_type'] = vx_core.t_type
    vx_core.t_divide['vx_value'] = {
      name          : "/",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_divide
    }

    // (func lt)
    vx_core.t_lt['vx_type'] = vx_core.t_type
    vx_core.t_lt['vx_value'] = {
      name          : "<",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_lt
    }

    // (func lt_1)
    vx_core.t_lt_1['vx_type'] = vx_core.t_type
    vx_core.t_lt_1['vx_value'] = {
      name          : "<",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_lt_1
    }

    // (func chainfirst)
    vx_core.t_chainfirst['vx_type'] = vx_core.t_type
    vx_core.t_chainfirst['vx_value'] = {
      name          : "<-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_chainfirst
    }

    // (func chainlast)
    vx_core.t_chainlast['vx_type'] = vx_core.t_type
    vx_core.t_chainlast['vx_value'] = {
      name          : "<<-",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_chainlast
    }

    // (func le)
    vx_core.t_le['vx_type'] = vx_core.t_type
    vx_core.t_le['vx_value'] = {
      name          : "<=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_le
    }

    // (func le_1)
    vx_core.t_le_1['vx_type'] = vx_core.t_type
    vx_core.t_le_1['vx_value'] = {
      name          : "<=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_le_1
    }

    // (func eq)
    vx_core.t_eq['vx_type'] = vx_core.t_type
    vx_core.t_eq['vx_value'] = {
      name          : "=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_eq
    }

    // (func eq_1)
    vx_core.t_eq_1['vx_type'] = vx_core.t_type
    vx_core.t_eq_1['vx_value'] = {
      name          : "=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_eq_1
    }

    // (func gt)
    vx_core.t_gt['vx_type'] = vx_core.t_type
    vx_core.t_gt['vx_value'] = {
      name          : ">",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_gt
    }

    // (func gt_1)
    vx_core.t_gt_1['vx_type'] = vx_core.t_type
    vx_core.t_gt_1['vx_value'] = {
      name          : ">",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_gt_1
    }

    // (func ge)
    vx_core.t_ge['vx_type'] = vx_core.t_type
    vx_core.t_ge['vx_value'] = {
      name          : ">=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_ge
    }

    // (func ge_1)
    vx_core.t_ge_1['vx_type'] = vx_core.t_type
    vx_core.t_ge_1['vx_value'] = {
      name          : ">=",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_ge_1
    }

    // (func allowtypenames_from_typedef)
    vx_core.t_allowtypenames_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_allowtypenames_from_typedef['vx_value'] = {
      name          : "allowtypenames<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_allowtypenames_from_typedef
    }

    // (func allowtypes_from_typedef)
    vx_core.t_allowtypes_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_allowtypes_from_typedef['vx_value'] = {
      name          : "allowtypes<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_allowtypes_from_typedef
    }

    // (func and)
    vx_core.t_and['vx_type'] = vx_core.t_type
    vx_core.t_and['vx_value'] = {
      name          : "and",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_and
    }

    // (func and_1)
    vx_core.t_and_1['vx_type'] = vx_core.t_type
    vx_core.t_and_1['vx_value'] = {
      name          : "and",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_and_1
    }

    // (func any_from_any)
    vx_core.t_any_from_any['vx_type'] = vx_core.t_type
    vx_core.t_any_from_any['vx_value'] = {
      name          : "any<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_any
    }

    // (func any_from_any_async)
    vx_core.t_any_from_any_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_any_async['vx_value'] = {
      name          : "any<-any-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_any_async
    }

    // (func any_from_any_context)
    vx_core.t_any_from_any_context['vx_type'] = vx_core.t_type
    vx_core.t_any_from_any_context['vx_value'] = {
      name          : "any<-any-context",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_any_context
    }

    // (func any_from_any_context_async)
    vx_core.t_any_from_any_context_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_any_context_async['vx_value'] = {
      name          : "any<-any-context-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_any_context_async
    }

    // (func any_from_func)
    vx_core.t_any_from_func['vx_type'] = vx_core.t_type
    vx_core.t_any_from_func['vx_value'] = {
      name          : "any<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_func
    }

    // (func any_from_func_async)
    vx_core.t_any_from_func_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_func_async['vx_value'] = {
      name          : "any<-func-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_func_async
    }

    // (func any_from_key_value)
    vx_core.t_any_from_key_value['vx_type'] = vx_core.t_type
    vx_core.t_any_from_key_value['vx_value'] = {
      name          : "any<-key-value",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_key_value
    }

    // (func any_from_key_value_async)
    vx_core.t_any_from_key_value_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_key_value_async['vx_value'] = {
      name          : "any<-key-value-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_key_value_async
    }

    // (func any_from_list)
    vx_core.t_any_from_list['vx_type'] = vx_core.t_type
    vx_core.t_any_from_list['vx_value'] = {
      name          : "any<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_list
    }

    // (func any_from_list_reduce)
    vx_core.t_any_from_list_reduce['vx_type'] = vx_core.t_type
    vx_core.t_any_from_list_reduce['vx_value'] = {
      name          : "any<-list-reduce",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_list_reduce
    }

    // (func any_from_list_reduce_next)
    vx_core.t_any_from_list_reduce_next['vx_type'] = vx_core.t_type
    vx_core.t_any_from_list_reduce_next['vx_value'] = {
      name          : "any<-list-reduce-next",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_list_reduce_next
    }

    // (func any_from_map)
    vx_core.t_any_from_map['vx_type'] = vx_core.t_type
    vx_core.t_any_from_map['vx_value'] = {
      name          : "any<-map",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_map
    }

    // (func any_from_none)
    vx_core.t_any_from_none['vx_type'] = vx_core.t_type
    vx_core.t_any_from_none['vx_value'] = {
      name          : "any<-none",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_none
    }

    // (func any_from_none_async)
    vx_core.t_any_from_none_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_none_async['vx_value'] = {
      name          : "any<-none-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_none_async
    }

    // (func any_from_reduce)
    vx_core.t_any_from_reduce['vx_type'] = vx_core.t_type
    vx_core.t_any_from_reduce['vx_value'] = {
      name          : "any<-reduce",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_reduce
    }

    // (func any_from_reduce_async)
    vx_core.t_any_from_reduce_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_reduce_async['vx_value'] = {
      name          : "any<-reduce-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_reduce_async
    }

    // (func any_from_reduce_next)
    vx_core.t_any_from_reduce_next['vx_type'] = vx_core.t_type
    vx_core.t_any_from_reduce_next['vx_value'] = {
      name          : "any<-reduce-next",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_reduce_next
    }

    // (func any_from_reduce_next_async)
    vx_core.t_any_from_reduce_next_async['vx_type'] = vx_core.t_type
    vx_core.t_any_from_reduce_next_async['vx_value'] = {
      name          : "any<-reduce-next-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_reduce_next_async
    }

    // (func any_from_struct)
    vx_core.t_any_from_struct['vx_type'] = vx_core.t_type
    vx_core.t_any_from_struct['vx_value'] = {
      name          : "any<-struct",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_any_from_struct
    }

    // (func async)
    vx_core.t_async['vx_type'] = vx_core.t_type
    vx_core.t_async['vx_value'] = {
      name          : "async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_async
    }

    // (func boolean_from_any)
    vx_core.t_boolean_from_any['vx_type'] = vx_core.t_type
    vx_core.t_boolean_from_any['vx_value'] = {
      name          : "boolean<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_boolean_from_any
    }

    // (func boolean_from_func)
    vx_core.t_boolean_from_func['vx_type'] = vx_core.t_type
    vx_core.t_boolean_from_func['vx_value'] = {
      name          : "boolean<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_boolean_from_func
    }

    // (func boolean_from_none)
    vx_core.t_boolean_from_none['vx_type'] = vx_core.t_type
    vx_core.t_boolean_from_none['vx_value'] = {
      name          : "boolean<-none",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_boolean_from_none
    }

    // (func case)
    vx_core.t_case['vx_type'] = vx_core.t_type
    vx_core.t_case['vx_value'] = {
      name          : "case",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_case
    }

    // (func case_1)
    vx_core.t_case_1['vx_type'] = vx_core.t_type
    vx_core.t_case_1['vx_value'] = {
      name          : "case",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_case_1
    }

    // (func compare)
    vx_core.t_compare['vx_type'] = vx_core.t_type
    vx_core.t_compare['vx_value'] = {
      name          : "compare",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_compare
    }

    // (func contains)
    vx_core.t_contains['vx_type'] = vx_core.t_type
    vx_core.t_contains['vx_value'] = {
      name          : "contains",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_contains
    }

    // (func contains_1)
    vx_core.t_contains_1['vx_type'] = vx_core.t_type
    vx_core.t_contains_1['vx_value'] = {
      name          : "contains",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_contains_1
    }

    // (func copy)
    vx_core.t_copy['vx_type'] = vx_core.t_type
    vx_core.t_copy['vx_value'] = {
      name          : "copy",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_copy
    }

    // (func else)
    vx_core.t_else['vx_type'] = vx_core.t_type
    vx_core.t_else['vx_value'] = {
      name          : "else",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_else
    }

    // (func empty)
    vx_core.t_empty['vx_type'] = vx_core.t_type
    vx_core.t_empty['vx_value'] = {
      name          : "empty",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_empty
    }

    // (func extends_from_any)
    vx_core.t_extends_from_any['vx_type'] = vx_core.t_type
    vx_core.t_extends_from_any['vx_value'] = {
      name          : "extends<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_extends_from_any
    }

    // (func extends_from_typedef)
    vx_core.t_extends_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_extends_from_typedef['vx_value'] = {
      name          : "extends<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_extends_from_typedef
    }

    // (func first_from_list)
    vx_core.t_first_from_list['vx_type'] = vx_core.t_type
    vx_core.t_first_from_list['vx_value'] = {
      name          : "first<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_first_from_list
    }

    // (func first_from_list_fn_any_from_any)
    vx_core.t_first_from_list_fn_any_from_any['vx_type'] = vx_core.t_type
    vx_core.t_first_from_list_fn_any_from_any['vx_value'] = {
      name          : "first<-list-fn-any<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_first_from_list_fn_any_from_any
    }

    // (func fn)
    vx_core.t_fn['vx_type'] = vx_core.t_type
    vx_core.t_fn['vx_value'] = {
      name          : "fn",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_fn
    }

    // (func funcdef_from_func)
    vx_core.t_funcdef_from_func['vx_type'] = vx_core.t_type
    vx_core.t_funcdef_from_func['vx_value'] = {
      name          : "funcdef<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_funcdef_from_func
    }

    // (func funcname_from_funcdef)
    vx_core.t_funcname_from_funcdef['vx_type'] = vx_core.t_type
    vx_core.t_funcname_from_funcdef['vx_value'] = {
      name          : "funcname<-funcdef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_funcname_from_funcdef
    }

    // (func global_package_get)
    vx_core.t_global_package_get['vx_type'] = vx_core.t_type
    vx_core.t_global_package_get['vx_value'] = {
      name          : "global-package-get",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_global_package_get
    }

    // (func global_package_set)
    vx_core.t_global_package_set['vx_type'] = vx_core.t_type
    vx_core.t_global_package_set['vx_value'] = {
      name          : "global-package-set",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_global_package_set
    }

    // (func if)
    vx_core.t_if['vx_type'] = vx_core.t_type
    vx_core.t_if['vx_value'] = {
      name          : "if",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_if
    }

    // (func if_1)
    vx_core.t_if_1['vx_type'] = vx_core.t_type
    vx_core.t_if_1['vx_value'] = {
      name          : "if",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_if_1
    }

    // (func if_2)
    vx_core.t_if_2['vx_type'] = vx_core.t_type
    vx_core.t_if_2['vx_value'] = {
      name          : "if",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 2,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_if_2
    }

    // (func int_from_func)
    vx_core.t_int_from_func['vx_type'] = vx_core.t_type
    vx_core.t_int_from_func['vx_value'] = {
      name          : "int<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_int_from_func
    }

    // (func int_from_string)
    vx_core.t_int_from_string['vx_type'] = vx_core.t_type
    vx_core.t_int_from_string['vx_value'] = {
      name          : "int<-string",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_int_from_string
    }

    // (func is_empty)
    vx_core.t_is_empty['vx_type'] = vx_core.t_type
    vx_core.t_is_empty['vx_value'] = {
      name          : "is-empty",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_empty
    }

    // (func is_empty_1)
    vx_core.t_is_empty_1['vx_type'] = vx_core.t_type
    vx_core.t_is_empty_1['vx_value'] = {
      name          : "is-empty",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_empty_1
    }

    // (func is_endswith)
    vx_core.t_is_endswith['vx_type'] = vx_core.t_type
    vx_core.t_is_endswith['vx_value'] = {
      name          : "is-endswith",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_endswith
    }

    // (func is_func)
    vx_core.t_is_func['vx_type'] = vx_core.t_type
    vx_core.t_is_func['vx_value'] = {
      name          : "is-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_func
    }

    // (func is_int)
    vx_core.t_is_int['vx_type'] = vx_core.t_type
    vx_core.t_is_int['vx_value'] = {
      name          : "is-int",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_int
    }

    // (func is_number)
    vx_core.t_is_number['vx_type'] = vx_core.t_type
    vx_core.t_is_number['vx_value'] = {
      name          : "is-number",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_number
    }

    // (func is_pass_from_permission)
    vx_core.t_is_pass_from_permission['vx_type'] = vx_core.t_type
    vx_core.t_is_pass_from_permission['vx_value'] = {
      name          : "is-pass<-permission",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_is_pass_from_permission
    }

    // (func last_from_list)
    vx_core.t_last_from_list['vx_type'] = vx_core.t_type
    vx_core.t_last_from_list['vx_value'] = {
      name          : "last<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_last_from_list
    }

    // (func length_from_list)
    vx_core.t_length_from_list['vx_type'] = vx_core.t_type
    vx_core.t_length_from_list['vx_value'] = {
      name          : "length<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_length_from_list
    }

    // (func let)
    vx_core.t_let['vx_type'] = vx_core.t_type
    vx_core.t_let['vx_value'] = {
      name          : "let",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_let
    }

    // (func let_async)
    vx_core.t_let_async['vx_type'] = vx_core.t_type
    vx_core.t_let_async['vx_value'] = {
      name          : "let-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_let_async
    }

    // (func list_join_from_list)
    vx_core.t_list_join_from_list['vx_type'] = vx_core.t_type
    vx_core.t_list_join_from_list['vx_value'] = {
      name          : "list-join<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_join_from_list
    }

    // (func list_from_list)
    vx_core.t_list_from_list['vx_type'] = vx_core.t_type
    vx_core.t_list_from_list['vx_value'] = {
      name          : "list<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_from_list
    }

    // (func list_from_list_async)
    vx_core.t_list_from_list_async['vx_type'] = vx_core.t_type
    vx_core.t_list_from_list_async['vx_value'] = {
      name          : "list<-list-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_from_list_async
    }

    // (func list_from_map)
    vx_core.t_list_from_map['vx_type'] = vx_core.t_type
    vx_core.t_list_from_map['vx_value'] = {
      name          : "list<-map",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_from_map
    }

    // (func list_from_map_async)
    vx_core.t_list_from_map_async['vx_type'] = vx_core.t_type
    vx_core.t_list_from_map_async['vx_value'] = {
      name          : "list<-map-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_from_map_async
    }

    // (func list_from_type)
    vx_core.t_list_from_type['vx_type'] = vx_core.t_type
    vx_core.t_list_from_type['vx_value'] = {
      name          : "list<-type",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_list_from_type
    }

    // (func log)
    vx_core.t_log['vx_type'] = vx_core.t_type
    vx_core.t_log['vx_value'] = {
      name          : "log",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_log
    }

    // (func map_from_list)
    vx_core.t_map_from_list['vx_type'] = vx_core.t_type
    vx_core.t_map_from_list['vx_value'] = {
      name          : "map<-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_map_from_list
    }

    // (func mempool_addref)
    vx_core.t_mempool_addref['vx_type'] = vx_core.t_type
    vx_core.t_mempool_addref['vx_value'] = {
      name          : "mempool-addref",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_mempool_addref
    }

    // (func mempool_release)
    vx_core.t_mempool_release['vx_type'] = vx_core.t_type
    vx_core.t_mempool_release['vx_value'] = {
      name          : "mempool-release",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_mempool_release
    }

    // (func mempool_removeref)
    vx_core.t_mempool_removeref['vx_type'] = vx_core.t_type
    vx_core.t_mempool_removeref['vx_value'] = {
      name          : "mempool-removeref",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_mempool_removeref
    }

    // (func mempool_removerefchildren)
    vx_core.t_mempool_removerefchildren['vx_type'] = vx_core.t_type
    vx_core.t_mempool_removerefchildren['vx_value'] = {
      name          : "mempool-removerefchildren",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_mempool_removerefchildren
    }

    // (func mempool_reserve)
    vx_core.t_mempool_reserve['vx_type'] = vx_core.t_type
    vx_core.t_mempool_reserve['vx_value'] = {
      name          : "mempool-reserve",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_mempool_reserve
    }

    // (func msg_from_error)
    vx_core.t_msg_from_error['vx_type'] = vx_core.t_type
    vx_core.t_msg_from_error['vx_value'] = {
      name          : "msg<-error",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_msg_from_error
    }

    // (func msgblock_from_msgblock_msg)
    vx_core.t_msgblock_from_msgblock_msg['vx_type'] = vx_core.t_type
    vx_core.t_msgblock_from_msgblock_msg['vx_value'] = {
      name          : "msgblock<-msgblock-msg",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_msgblock_from_msgblock_msg
    }

    // (func msgblock_from_msgblock_msgblock)
    vx_core.t_msgblock_from_msgblock_msgblock['vx_type'] = vx_core.t_type
    vx_core.t_msgblock_from_msgblock_msgblock['vx_value'] = {
      name          : "msgblock<-msgblock-msgblock",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_msgblock_from_msgblock_msgblock
    }

    // (func name_from_typedef)
    vx_core.t_name_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_name_from_typedef['vx_value'] = {
      name          : "name<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_name_from_typedef
    }

    // (func native)
    vx_core.t_native['vx_type'] = vx_core.t_type
    vx_core.t_native['vx_value'] = {
      name          : "native",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_native
    }

    // (func native_from_any)
    vx_core.t_native_from_any['vx_type'] = vx_core.t_type
    vx_core.t_native_from_any['vx_value'] = {
      name          : "native<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_native_from_any
    }

    // (func new)
    vx_core.t_new['vx_type'] = vx_core.t_type
    vx_core.t_new['vx_value'] = {
      name          : "new",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_new
    }

    // (func number_from_func)
    vx_core.t_number_from_func['vx_type'] = vx_core.t_type
    vx_core.t_number_from_func['vx_value'] = {
      name          : "number<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_number_from_func
    }

    // (func or)
    vx_core.t_or['vx_type'] = vx_core.t_type
    vx_core.t_or['vx_value'] = {
      name          : "or",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_or
    }

    // (func or_1)
    vx_core.t_or_1['vx_type'] = vx_core.t_type
    vx_core.t_or_1['vx_value'] = {
      name          : "or",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_or_1
    }

    // (func packagename_from_typedef)
    vx_core.t_packagename_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_packagename_from_typedef['vx_value'] = {
      name          : "packagename<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_packagename_from_typedef
    }

    // (func path_from_context_path)
    vx_core.t_path_from_context_path['vx_type'] = vx_core.t_type
    vx_core.t_path_from_context_path['vx_value'] = {
      name          : "path<-context-path",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_path_from_context_path
    }

    // (func path_from_setting_path)
    vx_core.t_path_from_setting_path['vx_type'] = vx_core.t_type
    vx_core.t_path_from_setting_path['vx_value'] = {
      name          : "path<-setting-path",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_path_from_setting_path
    }

    // (func permission_from_id_context)
    vx_core.t_permission_from_id_context['vx_type'] = vx_core.t_type
    vx_core.t_permission_from_id_context['vx_value'] = {
      name          : "permission<-id-context",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_permission_from_id_context
    }

    // (func properties_from_typedef)
    vx_core.t_properties_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_properties_from_typedef['vx_value'] = {
      name          : "properties<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_properties_from_typedef
    }

    // (func proplast_from_typedef)
    vx_core.t_proplast_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_proplast_from_typedef['vx_value'] = {
      name          : "proplast<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_proplast_from_typedef
    }

    // (func resolve)
    vx_core.t_resolve['vx_type'] = vx_core.t_type
    vx_core.t_resolve['vx_value'] = {
      name          : "resolve",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_resolve
    }

    // (func resolve_1)
    vx_core.t_resolve_1['vx_type'] = vx_core.t_type
    vx_core.t_resolve_1['vx_value'] = {
      name          : "resolve",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_resolve_1
    }

    // (func resolve_async)
    vx_core.t_resolve_async['vx_type'] = vx_core.t_type
    vx_core.t_resolve_async['vx_value'] = {
      name          : "resolve-async",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_resolve_async
    }

    // (func resolve_first)
    vx_core.t_resolve_first['vx_type'] = vx_core.t_type
    vx_core.t_resolve_first['vx_value'] = {
      name          : "resolve-first",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_resolve_first
    }

    // (func resolve_list)
    vx_core.t_resolve_list['vx_type'] = vx_core.t_type
    vx_core.t_resolve_list['vx_value'] = {
      name          : "resolve-list",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_resolve_list
    }

    // (func session_from_context)
    vx_core.t_session_from_context['vx_type'] = vx_core.t_type
    vx_core.t_session_from_context['vx_value'] = {
      name          : "session<-context",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_session_from_context
    }

    // (func setting_from_context)
    vx_core.t_setting_from_context['vx_type'] = vx_core.t_type
    vx_core.t_setting_from_context['vx_value'] = {
      name          : "setting<-context",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_setting_from_context
    }

    // (func string_repeat)
    vx_core.t_string_repeat['vx_type'] = vx_core.t_type
    vx_core.t_string_repeat['vx_value'] = {
      name          : "string-repeat",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_string_repeat
    }

    // (func string_from_any)
    vx_core.t_string_from_any['vx_type'] = vx_core.t_type
    vx_core.t_string_from_any['vx_value'] = {
      name          : "string<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_string_from_any
    }

    // (func string_from_any_indent)
    vx_core.t_string_from_any_indent['vx_type'] = vx_core.t_type
    vx_core.t_string_from_any_indent['vx_value'] = {
      name          : "string<-any-indent",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_string_from_any_indent
    }

    // (func string_from_func)
    vx_core.t_string_from_func['vx_type'] = vx_core.t_type
    vx_core.t_string_from_func['vx_value'] = {
      name          : "string<-func",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_string_from_func
    }

    // (func switch)
    vx_core.t_switch['vx_type'] = vx_core.t_type
    vx_core.t_switch['vx_value'] = {
      name          : "switch",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_switch
    }

    // (func then)
    vx_core.t_then['vx_type'] = vx_core.t_type
    vx_core.t_then['vx_value'] = {
      name          : "then",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_then
    }

    // (func traits_from_typedef)
    vx_core.t_traits_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_traits_from_typedef['vx_value'] = {
      name          : "traits<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_traits_from_typedef
    }

    // (func type_from_any)
    vx_core.t_type_from_any['vx_type'] = vx_core.t_type
    vx_core.t_type_from_any['vx_value'] = {
      name          : "type<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_type_from_any
    }

    // (func typedef_from_any)
    vx_core.t_typedef_from_any['vx_type'] = vx_core.t_type
    vx_core.t_typedef_from_any['vx_value'] = {
      name          : "typedef<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typedef_from_any
    }

    // (func typedef_from_type)
    vx_core.t_typedef_from_type['vx_type'] = vx_core.t_type
    vx_core.t_typedef_from_type['vx_value'] = {
      name          : "typedef<-type",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typedef_from_type
    }

    // (func typename_from_any)
    vx_core.t_typename_from_any['vx_type'] = vx_core.t_type
    vx_core.t_typename_from_any['vx_value'] = {
      name          : "typename<-any",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typename_from_any
    }

    // (func typename_from_type)
    vx_core.t_typename_from_type['vx_type'] = vx_core.t_type
    vx_core.t_typename_from_type['vx_value'] = {
      name          : "typename<-type",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typename_from_type
    }

    // (func typename_from_typedef)
    vx_core.t_typename_from_typedef['vx_type'] = vx_core.t_type
    vx_core.t_typename_from_typedef['vx_value'] = {
      name          : "typename<-typedef",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typename_from_typedef
    }

    // (func typenames_from_typelist)
    vx_core.t_typenames_from_typelist['vx_type'] = vx_core.t_type
    vx_core.t_typenames_from_typelist['vx_value'] = {
      name          : "typenames<-typelist",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_typenames_from_typelist
    }

    // (func user_from_context)
    vx_core.t_user_from_context['vx_type'] = vx_core.t_type
    vx_core.t_user_from_context['vx_value'] = {
      name          : "user<-context",
      pkgname       : "vx/core",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_core.f_user_from_context
    }

  }
}
