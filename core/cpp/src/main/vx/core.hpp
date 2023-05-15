#pragma once
#include <any>
#include <exception>
#include <functional>
#include <future>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace vx_core {

  // forward declarations
  class Class_any;
  typedef std::shared_ptr<Class_any> Type_any;
  extern Type_any e_any;
  extern Type_any t_any;
  class Class_any_async_from_func;
  typedef std::shared_ptr<Class_any_async_from_func> Type_any_async_from_func;
  extern Type_any_async_from_func e_any_async_from_func;
  extern Type_any_async_from_func t_any_async_from_func;
  class Class_any_from_anylist;
  typedef std::shared_ptr<Class_any_from_anylist> Type_any_from_anylist;
  extern Type_any_from_anylist e_any_from_anylist;
  extern Type_any_from_anylist t_any_from_anylist;
  class Class_anylist;
  typedef std::shared_ptr<Class_anylist> Type_anylist;
  extern Type_anylist e_anylist;
  extern Type_anylist t_anylist;
  class Class_anytype;
  typedef std::shared_ptr<Class_anytype> Type_anytype;
  extern Type_anytype e_anytype;
  extern Type_anytype t_anytype;
  class Class_arg;
  typedef std::shared_ptr<Class_arg> Type_arg;
  extern Type_arg e_arg;
  extern Type_arg t_arg;
  class Class_arglist;
  typedef std::shared_ptr<Class_arglist> Type_arglist;
  extern Type_arglist e_arglist;
  extern Type_arglist t_arglist;
  class Class_argmap;
  typedef std::shared_ptr<Class_argmap> Type_argmap;
  extern Type_argmap e_argmap;
  extern Type_argmap t_argmap;
  class Class_boolean;
  typedef std::shared_ptr<Class_boolean> Type_boolean;
  extern Type_boolean e_boolean;
  extern Type_boolean t_boolean;
  class Class_booleanlist;
  typedef std::shared_ptr<Class_booleanlist> Type_booleanlist;
  extern Type_booleanlist e_booleanlist;
  extern Type_booleanlist t_booleanlist;
  class Class_collection;
  typedef std::shared_ptr<Class_collection> Type_collection;
  extern Type_collection e_collection;
  extern Type_collection t_collection;
  class Class_compilelanguages;
  typedef std::shared_ptr<Class_compilelanguages> Type_compilelanguages;
  extern Type_compilelanguages e_compilelanguages;
  extern Type_compilelanguages t_compilelanguages;
  class Class_connect;
  typedef std::shared_ptr<Class_connect> Type_connect;
  extern Type_connect e_connect;
  extern Type_connect t_connect;
  class Class_connectlist;
  typedef std::shared_ptr<Class_connectlist> Type_connectlist;
  extern Type_connectlist e_connectlist;
  extern Type_connectlist t_connectlist;
  class Class_connectmap;
  typedef std::shared_ptr<Class_connectmap> Type_connectmap;
  extern Type_connectmap e_connectmap;
  extern Type_connectmap t_connectmap;
  class Class_const;
  typedef std::shared_ptr<Class_const> Type_const;
  extern Type_const e_const;
  extern Type_const t_const;
  class Class_constdef;
  typedef std::shared_ptr<Class_constdef> Type_constdef;
  extern Type_constdef e_constdef;
  extern Type_constdef t_constdef;
  class Class_constlist;
  typedef std::shared_ptr<Class_constlist> Type_constlist;
  extern Type_constlist e_constlist;
  extern Type_constlist t_constlist;
  class Class_constmap;
  typedef std::shared_ptr<Class_constmap> Type_constmap;
  extern Type_constmap e_constmap;
  extern Type_constmap t_constmap;
  class Class_context;
  typedef std::shared_ptr<Class_context> Type_context;
  extern Type_context e_context;
  extern Type_context t_context;
  class Class_decimal;
  typedef std::shared_ptr<Class_decimal> Type_decimal;
  extern Type_decimal e_decimal;
  extern Type_decimal t_decimal;
  class Class_error;
  typedef std::shared_ptr<Class_error> Type_error;
  extern Type_error e_error;
  extern Type_error t_error;
  class Class_float;
  typedef std::shared_ptr<Class_float> Type_float;
  extern Type_float e_float;
  extern Type_float t_float;
  class Class_func;
  typedef std::shared_ptr<Class_func> Type_func;
  extern Type_func e_func;
  extern Type_func t_func;
  class Class_funcdef;
  typedef std::shared_ptr<Class_funcdef> Type_funcdef;
  extern Type_funcdef e_funcdef;
  extern Type_funcdef t_funcdef;
  class Class_funclist;
  typedef std::shared_ptr<Class_funclist> Type_funclist;
  extern Type_funclist e_funclist;
  extern Type_funclist t_funclist;
  class Class_funcmap;
  typedef std::shared_ptr<Class_funcmap> Type_funcmap;
  extern Type_funcmap e_funcmap;
  extern Type_funcmap t_funcmap;
  class Class_int;
  typedef std::shared_ptr<Class_int> Type_int;
  extern Type_int e_int;
  extern Type_int t_int;
  class Class_intlist;
  typedef std::shared_ptr<Class_intlist> Type_intlist;
  extern Type_intlist e_intlist;
  extern Type_intlist t_intlist;
  class Class_intmap;
  typedef std::shared_ptr<Class_intmap> Type_intmap;
  extern Type_intmap e_intmap;
  extern Type_intmap t_intmap;
  class Class_list;
  typedef std::shared_ptr<Class_list> Type_list;
  extern Type_list e_list;
  extern Type_list t_list;
  class Class_listtype;
  typedef std::shared_ptr<Class_listtype> Type_listtype;
  extern Type_listtype e_listtype;
  extern Type_listtype t_listtype;
  class Class_map;
  typedef std::shared_ptr<Class_map> Type_map;
  extern Type_map e_map;
  extern Type_map t_map;
  class Class_maptype;
  typedef std::shared_ptr<Class_maptype> Type_maptype;
  extern Type_maptype e_maptype;
  extern Type_maptype t_maptype;
  class Class_mempool;
  typedef std::shared_ptr<Class_mempool> Type_mempool;
  extern Type_mempool e_mempool;
  extern Type_mempool t_mempool;
  class Class_msg;
  typedef std::shared_ptr<Class_msg> Type_msg;
  extern Type_msg e_msg;
  extern Type_msg t_msg;
  class Class_msgblock;
  typedef std::shared_ptr<Class_msgblock> Type_msgblock;
  extern Type_msgblock e_msgblock;
  extern Type_msgblock t_msgblock;
  class Class_msgblocklist;
  typedef std::shared_ptr<Class_msgblocklist> Type_msgblocklist;
  extern Type_msgblocklist e_msgblocklist;
  extern Type_msgblocklist t_msgblocklist;
  class Class_msglist;
  typedef std::shared_ptr<Class_msglist> Type_msglist;
  extern Type_msglist e_msglist;
  extern Type_msglist t_msglist;
  class Class_none;
  typedef std::shared_ptr<Class_none> Type_none;
  extern Type_none e_none;
  extern Type_none t_none;
  class Class_notype;
  typedef std::shared_ptr<Class_notype> Type_notype;
  extern Type_notype e_notype;
  extern Type_notype t_notype;
  class Class_number;
  typedef std::shared_ptr<Class_number> Type_number;
  extern Type_number e_number;
  extern Type_number t_number;
  class Class_numberlist;
  typedef std::shared_ptr<Class_numberlist> Type_numberlist;
  extern Type_numberlist e_numberlist;
  extern Type_numberlist t_numberlist;
  class Class_numbermap;
  typedef std::shared_ptr<Class_numbermap> Type_numbermap;
  extern Type_numbermap e_numbermap;
  extern Type_numbermap t_numbermap;
  class Class_package;
  typedef std::shared_ptr<Class_package> Type_package;
  extern Type_package e_package;
  extern Type_package t_package;
  class Class_packagemap;
  typedef std::shared_ptr<Class_packagemap> Type_packagemap;
  extern Type_packagemap e_packagemap;
  extern Type_packagemap t_packagemap;
  class Class_permission;
  typedef std::shared_ptr<Class_permission> Type_permission;
  extern Type_permission e_permission;
  extern Type_permission t_permission;
  class Class_permissionlist;
  typedef std::shared_ptr<Class_permissionlist> Type_permissionlist;
  extern Type_permissionlist e_permissionlist;
  extern Type_permissionlist t_permissionlist;
  class Class_permissionmap;
  typedef std::shared_ptr<Class_permissionmap> Type_permissionmap;
  extern Type_permissionmap e_permissionmap;
  extern Type_permissionmap t_permissionmap;
  class Class_security;
  typedef std::shared_ptr<Class_security> Type_security;
  extern Type_security e_security;
  extern Type_security t_security;
  class Class_session;
  typedef std::shared_ptr<Class_session> Type_session;
  extern Type_session e_session;
  extern Type_session t_session;
  class Class_setting;
  typedef std::shared_ptr<Class_setting> Type_setting;
  extern Type_setting e_setting;
  extern Type_setting t_setting;
  class Class_state;
  typedef std::shared_ptr<Class_state> Type_state;
  extern Type_state e_state;
  extern Type_state t_state;
  class Class_statelistener;
  typedef std::shared_ptr<Class_statelistener> Type_statelistener;
  extern Type_statelistener e_statelistener;
  extern Type_statelistener t_statelistener;
  class Class_string;
  typedef std::shared_ptr<Class_string> Type_string;
  extern Type_string e_string;
  extern Type_string t_string;
  class Class_stringlist;
  typedef std::shared_ptr<Class_stringlist> Type_stringlist;
  extern Type_stringlist e_stringlist;
  extern Type_stringlist t_stringlist;
  class Class_stringmap;
  typedef std::shared_ptr<Class_stringmap> Type_stringmap;
  extern Type_stringmap e_stringmap;
  extern Type_stringmap t_stringmap;
  class Class_struct;
  typedef std::shared_ptr<Class_struct> Type_struct;
  extern Type_struct e_struct;
  extern Type_struct t_struct;
  class Class_thenelse;
  typedef std::shared_ptr<Class_thenelse> Type_thenelse;
  extern Type_thenelse e_thenelse;
  extern Type_thenelse t_thenelse;
  class Class_thenelselist;
  typedef std::shared_ptr<Class_thenelselist> Type_thenelselist;
  extern Type_thenelselist e_thenelselist;
  extern Type_thenelselist t_thenelselist;
  class Class_type;
  typedef std::shared_ptr<Class_type> Type_type;
  extern Type_type e_type;
  extern Type_type t_type;
  class Class_typedef;
  typedef std::shared_ptr<Class_typedef> Type_typedef;
  extern Type_typedef e_typedef;
  extern Type_typedef t_typedef;
  class Class_typelist;
  typedef std::shared_ptr<Class_typelist> Type_typelist;
  extern Type_typelist e_typelist;
  extern Type_typelist t_typelist;
  class Class_typemap;
  typedef std::shared_ptr<Class_typemap> Type_typemap;
  extern Type_typemap e_typemap;
  extern Type_typemap t_typemap;
  class Class_user;
  typedef std::shared_ptr<Class_user> Type_user;
  extern Type_user e_user;
  extern Type_user t_user;
  class Class_value;
  typedef std::shared_ptr<Class_value> Type_value;
  extern Type_value e_value;
  extern Type_value t_value;
  class Class_false;
  typedef std::shared_ptr<Class_false> Const_false;
  extern Const_false c_false;
  class Class_globalpackagemap;
  typedef std::shared_ptr<Class_globalpackagemap> Const_globalpackagemap;
  extern Const_globalpackagemap c_globalpackagemap;
  class Class_infinity;
  typedef std::shared_ptr<Class_infinity> Const_infinity;
  extern Const_infinity c_infinity;
  class Class_mempool_active;
  typedef std::shared_ptr<Class_mempool_active> Const_mempool_active;
  extern Const_mempool_active c_mempool_active;
  class Class_msg_error;
  typedef std::shared_ptr<Class_msg_error> Const_msg_error;
  extern Const_msg_error c_msg_error;
  class Class_msg_info;
  typedef std::shared_ptr<Class_msg_info> Const_msg_info;
  extern Const_msg_info c_msg_info;
  class Class_msg_severe;
  typedef std::shared_ptr<Class_msg_severe> Const_msg_severe;
  extern Const_msg_severe c_msg_severe;
  class Class_msg_warning;
  typedef std::shared_ptr<Class_msg_warning> Const_msg_warning;
  extern Const_msg_warning c_msg_warning;
  class Class_neginfinity;
  typedef std::shared_ptr<Class_neginfinity> Const_neginfinity;
  extern Const_neginfinity c_neginfinity;
  class Class_newline;
  typedef std::shared_ptr<Class_newline> Const_newline;
  extern Const_newline c_newline;
  class Class_notanumber;
  typedef std::shared_ptr<Class_notanumber> Const_notanumber;
  extern Const_notanumber c_notanumber;
  class Class_nothing;
  typedef std::shared_ptr<Class_nothing> Const_nothing;
  extern Const_nothing c_nothing;
  class Class_quote;
  typedef std::shared_ptr<Class_quote> Const_quote;
  extern Const_quote c_quote;
  class Class_true;
  typedef std::shared_ptr<Class_true> Const_true;
  extern Const_true c_true;
  class Class_not;
  typedef std::shared_ptr<Class_not> Func_not;
  extern Func_not e_not;
  extern Func_not t_not;
  class Class_notempty;
  typedef std::shared_ptr<Class_notempty> Func_notempty;
  extern Func_notempty e_notempty;
  extern Func_notempty t_notempty;
  class Class_notempty_1;
  typedef std::shared_ptr<Class_notempty_1> Func_notempty_1;
  extern Func_notempty_1 e_notempty_1;
  extern Func_notempty_1 t_notempty_1;
  class Class_ne;
  typedef std::shared_ptr<Class_ne> Func_ne;
  extern Func_ne e_ne;
  extern Func_ne t_ne;
  class Class_multiply;
  typedef std::shared_ptr<Class_multiply> Func_multiply;
  extern Func_multiply e_multiply;
  extern Func_multiply t_multiply;
  class Class_multiply_1;
  typedef std::shared_ptr<Class_multiply_1> Func_multiply_1;
  extern Func_multiply_1 e_multiply_1;
  extern Func_multiply_1 t_multiply_1;
  class Class_multiply_2;
  typedef std::shared_ptr<Class_multiply_2> Func_multiply_2;
  extern Func_multiply_2 e_multiply_2;
  extern Func_multiply_2 t_multiply_2;
  class Class_multiply_3;
  typedef std::shared_ptr<Class_multiply_3> Func_multiply_3;
  extern Func_multiply_3 e_multiply_3;
  extern Func_multiply_3 t_multiply_3;
  class Class_plus;
  typedef std::shared_ptr<Class_plus> Func_plus;
  extern Func_plus e_plus;
  extern Func_plus t_plus;
  class Class_plus_1;
  typedef std::shared_ptr<Class_plus_1> Func_plus_1;
  extern Func_plus_1 e_plus_1;
  extern Func_plus_1 t_plus_1;
  class Class_plus_2;
  typedef std::shared_ptr<Class_plus_2> Func_plus_2;
  extern Func_plus_2 e_plus_2;
  extern Func_plus_2 t_plus_2;
  class Class_plus_3;
  typedef std::shared_ptr<Class_plus_3> Func_plus_3;
  extern Func_plus_3 e_plus_3;
  extern Func_plus_3 t_plus_3;
  class Class_plus1;
  typedef std::shared_ptr<Class_plus1> Func_plus1;
  extern Func_plus1 e_plus1;
  extern Func_plus1 t_plus1;
  class Class_minus;
  typedef std::shared_ptr<Class_minus> Func_minus;
  extern Func_minus e_minus;
  extern Func_minus t_minus;
  class Class_minus_1;
  typedef std::shared_ptr<Class_minus_1> Func_minus_1;
  extern Func_minus_1 e_minus_1;
  extern Func_minus_1 t_minus_1;
  class Class_minus_2;
  typedef std::shared_ptr<Class_minus_2> Func_minus_2;
  extern Func_minus_2 e_minus_2;
  extern Func_minus_2 t_minus_2;
  class Class_minus_3;
  typedef std::shared_ptr<Class_minus_3> Func_minus_3;
  extern Func_minus_3 e_minus_3;
  extern Func_minus_3 t_minus_3;
  class Class_dotmethod;
  typedef std::shared_ptr<Class_dotmethod> Func_dotmethod;
  extern Func_dotmethod e_dotmethod;
  extern Func_dotmethod t_dotmethod;
  class Class_divide;
  typedef std::shared_ptr<Class_divide> Func_divide;
  extern Func_divide e_divide;
  extern Func_divide t_divide;
  class Class_lt;
  typedef std::shared_ptr<Class_lt> Func_lt;
  extern Func_lt e_lt;
  extern Func_lt t_lt;
  class Class_lt_1;
  typedef std::shared_ptr<Class_lt_1> Func_lt_1;
  extern Func_lt_1 e_lt_1;
  extern Func_lt_1 t_lt_1;
  class Class_chainfirst;
  typedef std::shared_ptr<Class_chainfirst> Func_chainfirst;
  extern Func_chainfirst e_chainfirst;
  extern Func_chainfirst t_chainfirst;
  class Class_chainlast;
  typedef std::shared_ptr<Class_chainlast> Func_chainlast;
  extern Func_chainlast e_chainlast;
  extern Func_chainlast t_chainlast;
  class Class_le;
  typedef std::shared_ptr<Class_le> Func_le;
  extern Func_le e_le;
  extern Func_le t_le;
  class Class_le_1;
  typedef std::shared_ptr<Class_le_1> Func_le_1;
  extern Func_le_1 e_le_1;
  extern Func_le_1 t_le_1;
  class Class_eq;
  typedef std::shared_ptr<Class_eq> Func_eq;
  extern Func_eq e_eq;
  extern Func_eq t_eq;
  class Class_eq_1;
  typedef std::shared_ptr<Class_eq_1> Func_eq_1;
  extern Func_eq_1 e_eq_1;
  extern Func_eq_1 t_eq_1;
  class Class_gt;
  typedef std::shared_ptr<Class_gt> Func_gt;
  extern Func_gt e_gt;
  extern Func_gt t_gt;
  class Class_gt_1;
  typedef std::shared_ptr<Class_gt_1> Func_gt_1;
  extern Func_gt_1 e_gt_1;
  extern Func_gt_1 t_gt_1;
  class Class_ge;
  typedef std::shared_ptr<Class_ge> Func_ge;
  extern Func_ge e_ge;
  extern Func_ge t_ge;
  class Class_ge_1;
  typedef std::shared_ptr<Class_ge_1> Func_ge_1;
  extern Func_ge_1 e_ge_1;
  extern Func_ge_1 t_ge_1;
  class Class_allowtypenames_from_typedef;
  typedef std::shared_ptr<Class_allowtypenames_from_typedef> Func_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef e_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef t_allowtypenames_from_typedef;
  class Class_allowtypes_from_typedef;
  typedef std::shared_ptr<Class_allowtypes_from_typedef> Func_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef e_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef t_allowtypes_from_typedef;
  class Class_and;
  typedef std::shared_ptr<Class_and> Func_and;
  extern Func_and e_and;
  extern Func_and t_and;
  class Class_and_1;
  typedef std::shared_ptr<Class_and_1> Func_and_1;
  extern Func_and_1 e_and_1;
  extern Func_and_1 t_and_1;
  class Class_any_from_any;
  typedef std::shared_ptr<Class_any_from_any> Func_any_from_any;
  extern Func_any_from_any e_any_from_any;
  extern Func_any_from_any t_any_from_any;
  class Class_any_from_any_async;
  typedef std::shared_ptr<Class_any_from_any_async> Func_any_from_any_async;
  extern Func_any_from_any_async e_any_from_any_async;
  extern Func_any_from_any_async t_any_from_any_async;
  class Class_any_from_any_context;
  typedef std::shared_ptr<Class_any_from_any_context> Func_any_from_any_context;
  extern Func_any_from_any_context e_any_from_any_context;
  extern Func_any_from_any_context t_any_from_any_context;
  class Class_any_from_any_context_async;
  typedef std::shared_ptr<Class_any_from_any_context_async> Func_any_from_any_context_async;
  extern Func_any_from_any_context_async e_any_from_any_context_async;
  extern Func_any_from_any_context_async t_any_from_any_context_async;
  class Class_any_from_func;
  typedef std::shared_ptr<Class_any_from_func> Func_any_from_func;
  extern Func_any_from_func e_any_from_func;
  extern Func_any_from_func t_any_from_func;
  class Class_any_from_func_async;
  typedef std::shared_ptr<Class_any_from_func_async> Func_any_from_func_async;
  extern Func_any_from_func_async e_any_from_func_async;
  extern Func_any_from_func_async t_any_from_func_async;
  class Class_any_from_key_value;
  typedef std::shared_ptr<Class_any_from_key_value> Func_any_from_key_value;
  extern Func_any_from_key_value e_any_from_key_value;
  extern Func_any_from_key_value t_any_from_key_value;
  class Class_any_from_key_value_async;
  typedef std::shared_ptr<Class_any_from_key_value_async> Func_any_from_key_value_async;
  extern Func_any_from_key_value_async e_any_from_key_value_async;
  extern Func_any_from_key_value_async t_any_from_key_value_async;
  class Class_any_from_list;
  typedef std::shared_ptr<Class_any_from_list> Func_any_from_list;
  extern Func_any_from_list e_any_from_list;
  extern Func_any_from_list t_any_from_list;
  class Class_any_from_list_reduce;
  typedef std::shared_ptr<Class_any_from_list_reduce> Func_any_from_list_reduce;
  extern Func_any_from_list_reduce e_any_from_list_reduce;
  extern Func_any_from_list_reduce t_any_from_list_reduce;
  class Class_any_from_list_reduce_next;
  typedef std::shared_ptr<Class_any_from_list_reduce_next> Func_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next e_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next t_any_from_list_reduce_next;
  class Class_any_from_map;
  typedef std::shared_ptr<Class_any_from_map> Func_any_from_map;
  extern Func_any_from_map e_any_from_map;
  extern Func_any_from_map t_any_from_map;
  class Class_any_from_none;
  typedef std::shared_ptr<Class_any_from_none> Func_any_from_none;
  extern Func_any_from_none e_any_from_none;
  extern Func_any_from_none t_any_from_none;
  class Class_any_from_none_async;
  typedef std::shared_ptr<Class_any_from_none_async> Func_any_from_none_async;
  extern Func_any_from_none_async e_any_from_none_async;
  extern Func_any_from_none_async t_any_from_none_async;
  class Class_any_from_reduce;
  typedef std::shared_ptr<Class_any_from_reduce> Func_any_from_reduce;
  extern Func_any_from_reduce e_any_from_reduce;
  extern Func_any_from_reduce t_any_from_reduce;
  class Class_any_from_reduce_async;
  typedef std::shared_ptr<Class_any_from_reduce_async> Func_any_from_reduce_async;
  extern Func_any_from_reduce_async e_any_from_reduce_async;
  extern Func_any_from_reduce_async t_any_from_reduce_async;
  class Class_any_from_reduce_next;
  typedef std::shared_ptr<Class_any_from_reduce_next> Func_any_from_reduce_next;
  extern Func_any_from_reduce_next e_any_from_reduce_next;
  extern Func_any_from_reduce_next t_any_from_reduce_next;
  class Class_any_from_reduce_next_async;
  typedef std::shared_ptr<Class_any_from_reduce_next_async> Func_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async e_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async t_any_from_reduce_next_async;
  class Class_any_from_struct;
  typedef std::shared_ptr<Class_any_from_struct> Func_any_from_struct;
  extern Func_any_from_struct e_any_from_struct;
  extern Func_any_from_struct t_any_from_struct;
  class Class_async;
  typedef std::shared_ptr<Class_async> Func_async;
  extern Func_async e_async;
  extern Func_async t_async;
  class Class_boolean_from_any;
  typedef std::shared_ptr<Class_boolean_from_any> Func_boolean_from_any;
  extern Func_boolean_from_any e_boolean_from_any;
  extern Func_boolean_from_any t_boolean_from_any;
  class Class_boolean_from_func;
  typedef std::shared_ptr<Class_boolean_from_func> Func_boolean_from_func;
  extern Func_boolean_from_func e_boolean_from_func;
  extern Func_boolean_from_func t_boolean_from_func;
  class Class_boolean_from_none;
  typedef std::shared_ptr<Class_boolean_from_none> Func_boolean_from_none;
  extern Func_boolean_from_none e_boolean_from_none;
  extern Func_boolean_from_none t_boolean_from_none;
  class Class_case;
  typedef std::shared_ptr<Class_case> Func_case;
  extern Func_case e_case;
  extern Func_case t_case;
  class Class_case_1;
  typedef std::shared_ptr<Class_case_1> Func_case_1;
  extern Func_case_1 e_case_1;
  extern Func_case_1 t_case_1;
  class Class_compare;
  typedef std::shared_ptr<Class_compare> Func_compare;
  extern Func_compare e_compare;
  extern Func_compare t_compare;
  class Class_contains;
  typedef std::shared_ptr<Class_contains> Func_contains;
  extern Func_contains e_contains;
  extern Func_contains t_contains;
  class Class_contains_1;
  typedef std::shared_ptr<Class_contains_1> Func_contains_1;
  extern Func_contains_1 e_contains_1;
  extern Func_contains_1 t_contains_1;
  class Class_copy;
  typedef std::shared_ptr<Class_copy> Func_copy;
  extern Func_copy e_copy;
  extern Func_copy t_copy;
  class Class_else;
  typedef std::shared_ptr<Class_else> Func_else;
  extern Func_else e_else;
  extern Func_else t_else;
  class Class_empty;
  typedef std::shared_ptr<Class_empty> Func_empty;
  extern Func_empty e_empty;
  extern Func_empty t_empty;
  class Class_extends_from_any;
  typedef std::shared_ptr<Class_extends_from_any> Func_extends_from_any;
  extern Func_extends_from_any e_extends_from_any;
  extern Func_extends_from_any t_extends_from_any;
  class Class_extends_from_typedef;
  typedef std::shared_ptr<Class_extends_from_typedef> Func_extends_from_typedef;
  extern Func_extends_from_typedef e_extends_from_typedef;
  extern Func_extends_from_typedef t_extends_from_typedef;
  class Class_first_from_list;
  typedef std::shared_ptr<Class_first_from_list> Func_first_from_list;
  extern Func_first_from_list e_first_from_list;
  extern Func_first_from_list t_first_from_list;
  class Class_first_from_list_fn_any_from_any;
  typedef std::shared_ptr<Class_first_from_list_fn_any_from_any> Func_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any e_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any t_first_from_list_fn_any_from_any;
  class Class_fn;
  typedef std::shared_ptr<Class_fn> Func_fn;
  extern Func_fn e_fn;
  extern Func_fn t_fn;
  class Class_funcdef_from_func;
  typedef std::shared_ptr<Class_funcdef_from_func> Func_funcdef_from_func;
  extern Func_funcdef_from_func e_funcdef_from_func;
  extern Func_funcdef_from_func t_funcdef_from_func;
  class Class_funcname_from_funcdef;
  typedef std::shared_ptr<Class_funcname_from_funcdef> Func_funcname_from_funcdef;
  extern Func_funcname_from_funcdef e_funcname_from_funcdef;
  extern Func_funcname_from_funcdef t_funcname_from_funcdef;
  class Class_global_package_get;
  typedef std::shared_ptr<Class_global_package_get> Func_global_package_get;
  extern Func_global_package_get e_global_package_get;
  extern Func_global_package_get t_global_package_get;
  class Class_global_package_set;
  typedef std::shared_ptr<Class_global_package_set> Func_global_package_set;
  extern Func_global_package_set e_global_package_set;
  extern Func_global_package_set t_global_package_set;
  class Class_if;
  typedef std::shared_ptr<Class_if> Func_if;
  extern Func_if e_if;
  extern Func_if t_if;
  class Class_if_1;
  typedef std::shared_ptr<Class_if_1> Func_if_1;
  extern Func_if_1 e_if_1;
  extern Func_if_1 t_if_1;
  class Class_if_2;
  typedef std::shared_ptr<Class_if_2> Func_if_2;
  extern Func_if_2 e_if_2;
  extern Func_if_2 t_if_2;
  class Class_int_from_func;
  typedef std::shared_ptr<Class_int_from_func> Func_int_from_func;
  extern Func_int_from_func e_int_from_func;
  extern Func_int_from_func t_int_from_func;
  class Class_int_from_string;
  typedef std::shared_ptr<Class_int_from_string> Func_int_from_string;
  extern Func_int_from_string e_int_from_string;
  extern Func_int_from_string t_int_from_string;
  class Class_is_empty;
  typedef std::shared_ptr<Class_is_empty> Func_is_empty;
  extern Func_is_empty e_is_empty;
  extern Func_is_empty t_is_empty;
  class Class_is_empty_1;
  typedef std::shared_ptr<Class_is_empty_1> Func_is_empty_1;
  extern Func_is_empty_1 e_is_empty_1;
  extern Func_is_empty_1 t_is_empty_1;
  class Class_is_endswith;
  typedef std::shared_ptr<Class_is_endswith> Func_is_endswith;
  extern Func_is_endswith e_is_endswith;
  extern Func_is_endswith t_is_endswith;
  class Class_is_func;
  typedef std::shared_ptr<Class_is_func> Func_is_func;
  extern Func_is_func e_is_func;
  extern Func_is_func t_is_func;
  class Class_is_int;
  typedef std::shared_ptr<Class_is_int> Func_is_int;
  extern Func_is_int e_is_int;
  extern Func_is_int t_is_int;
  class Class_is_number;
  typedef std::shared_ptr<Class_is_number> Func_is_number;
  extern Func_is_number e_is_number;
  extern Func_is_number t_is_number;
  class Class_is_pass_from_permission;
  typedef std::shared_ptr<Class_is_pass_from_permission> Func_is_pass_from_permission;
  extern Func_is_pass_from_permission e_is_pass_from_permission;
  extern Func_is_pass_from_permission t_is_pass_from_permission;
  class Class_last_from_list;
  typedef std::shared_ptr<Class_last_from_list> Func_last_from_list;
  extern Func_last_from_list e_last_from_list;
  extern Func_last_from_list t_last_from_list;
  class Class_length_from_list;
  typedef std::shared_ptr<Class_length_from_list> Func_length_from_list;
  extern Func_length_from_list e_length_from_list;
  extern Func_length_from_list t_length_from_list;
  class Class_let;
  typedef std::shared_ptr<Class_let> Func_let;
  extern Func_let e_let;
  extern Func_let t_let;
  class Class_let_async;
  typedef std::shared_ptr<Class_let_async> Func_let_async;
  extern Func_let_async e_let_async;
  extern Func_let_async t_let_async;
  class Class_list_join_from_list;
  typedef std::shared_ptr<Class_list_join_from_list> Func_list_join_from_list;
  extern Func_list_join_from_list e_list_join_from_list;
  extern Func_list_join_from_list t_list_join_from_list;
  class Class_list_from_list;
  typedef std::shared_ptr<Class_list_from_list> Func_list_from_list;
  extern Func_list_from_list e_list_from_list;
  extern Func_list_from_list t_list_from_list;
  class Class_list_from_list_async;
  typedef std::shared_ptr<Class_list_from_list_async> Func_list_from_list_async;
  extern Func_list_from_list_async e_list_from_list_async;
  extern Func_list_from_list_async t_list_from_list_async;
  class Class_list_from_map;
  typedef std::shared_ptr<Class_list_from_map> Func_list_from_map;
  extern Func_list_from_map e_list_from_map;
  extern Func_list_from_map t_list_from_map;
  class Class_list_from_map_async;
  typedef std::shared_ptr<Class_list_from_map_async> Func_list_from_map_async;
  extern Func_list_from_map_async e_list_from_map_async;
  extern Func_list_from_map_async t_list_from_map_async;
  class Class_list_from_type;
  typedef std::shared_ptr<Class_list_from_type> Func_list_from_type;
  extern Func_list_from_type e_list_from_type;
  extern Func_list_from_type t_list_from_type;
  class Class_log;
  typedef std::shared_ptr<Class_log> Func_log;
  extern Func_log e_log;
  extern Func_log t_log;
  class Class_map_from_list;
  typedef std::shared_ptr<Class_map_from_list> Func_map_from_list;
  extern Func_map_from_list e_map_from_list;
  extern Func_map_from_list t_map_from_list;
  class Class_mempool_addref;
  typedef std::shared_ptr<Class_mempool_addref> Func_mempool_addref;
  extern Func_mempool_addref e_mempool_addref;
  extern Func_mempool_addref t_mempool_addref;
  class Class_mempool_release;
  typedef std::shared_ptr<Class_mempool_release> Func_mempool_release;
  extern Func_mempool_release e_mempool_release;
  extern Func_mempool_release t_mempool_release;
  class Class_mempool_removeref;
  typedef std::shared_ptr<Class_mempool_removeref> Func_mempool_removeref;
  extern Func_mempool_removeref e_mempool_removeref;
  extern Func_mempool_removeref t_mempool_removeref;
  class Class_mempool_removerefchildren;
  typedef std::shared_ptr<Class_mempool_removerefchildren> Func_mempool_removerefchildren;
  extern Func_mempool_removerefchildren e_mempool_removerefchildren;
  extern Func_mempool_removerefchildren t_mempool_removerefchildren;
  class Class_mempool_reserve;
  typedef std::shared_ptr<Class_mempool_reserve> Func_mempool_reserve;
  extern Func_mempool_reserve e_mempool_reserve;
  extern Func_mempool_reserve t_mempool_reserve;
  class Class_msg_from_error;
  typedef std::shared_ptr<Class_msg_from_error> Func_msg_from_error;
  extern Func_msg_from_error e_msg_from_error;
  extern Func_msg_from_error t_msg_from_error;
  class Class_msgblock_from_msgblock_msg;
  typedef std::shared_ptr<Class_msgblock_from_msgblock_msg> Func_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg;
  class Class_msgblock_from_msgblock_msgblock;
  typedef std::shared_ptr<Class_msgblock_from_msgblock_msgblock> Func_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock;
  class Class_name_from_typedef;
  typedef std::shared_ptr<Class_name_from_typedef> Func_name_from_typedef;
  extern Func_name_from_typedef e_name_from_typedef;
  extern Func_name_from_typedef t_name_from_typedef;
  class Class_native;
  typedef std::shared_ptr<Class_native> Func_native;
  extern Func_native e_native;
  extern Func_native t_native;
  class Class_native_from_any;
  typedef std::shared_ptr<Class_native_from_any> Func_native_from_any;
  extern Func_native_from_any e_native_from_any;
  extern Func_native_from_any t_native_from_any;
  class Class_new;
  typedef std::shared_ptr<Class_new> Func_new;
  extern Func_new e_new;
  extern Func_new t_new;
  class Class_number_from_func;
  typedef std::shared_ptr<Class_number_from_func> Func_number_from_func;
  extern Func_number_from_func e_number_from_func;
  extern Func_number_from_func t_number_from_func;
  class Class_or;
  typedef std::shared_ptr<Class_or> Func_or;
  extern Func_or e_or;
  extern Func_or t_or;
  class Class_or_1;
  typedef std::shared_ptr<Class_or_1> Func_or_1;
  extern Func_or_1 e_or_1;
  extern Func_or_1 t_or_1;
  class Class_packagename_from_typedef;
  typedef std::shared_ptr<Class_packagename_from_typedef> Func_packagename_from_typedef;
  extern Func_packagename_from_typedef e_packagename_from_typedef;
  extern Func_packagename_from_typedef t_packagename_from_typedef;
  class Class_path_from_context_path;
  typedef std::shared_ptr<Class_path_from_context_path> Func_path_from_context_path;
  extern Func_path_from_context_path e_path_from_context_path;
  extern Func_path_from_context_path t_path_from_context_path;
  class Class_path_from_setting_path;
  typedef std::shared_ptr<Class_path_from_setting_path> Func_path_from_setting_path;
  extern Func_path_from_setting_path e_path_from_setting_path;
  extern Func_path_from_setting_path t_path_from_setting_path;
  class Class_permission_from_id_context;
  typedef std::shared_ptr<Class_permission_from_id_context> Func_permission_from_id_context;
  extern Func_permission_from_id_context e_permission_from_id_context;
  extern Func_permission_from_id_context t_permission_from_id_context;
  class Class_properties_from_typedef;
  typedef std::shared_ptr<Class_properties_from_typedef> Func_properties_from_typedef;
  extern Func_properties_from_typedef e_properties_from_typedef;
  extern Func_properties_from_typedef t_properties_from_typedef;
  class Class_proplast_from_typedef;
  typedef std::shared_ptr<Class_proplast_from_typedef> Func_proplast_from_typedef;
  extern Func_proplast_from_typedef e_proplast_from_typedef;
  extern Func_proplast_from_typedef t_proplast_from_typedef;
  class Class_resolve;
  typedef std::shared_ptr<Class_resolve> Func_resolve;
  extern Func_resolve e_resolve;
  extern Func_resolve t_resolve;
  class Class_resolve_1;
  typedef std::shared_ptr<Class_resolve_1> Func_resolve_1;
  extern Func_resolve_1 e_resolve_1;
  extern Func_resolve_1 t_resolve_1;
  class Class_resolve_async;
  typedef std::shared_ptr<Class_resolve_async> Func_resolve_async;
  extern Func_resolve_async e_resolve_async;
  extern Func_resolve_async t_resolve_async;
  class Class_resolve_first;
  typedef std::shared_ptr<Class_resolve_first> Func_resolve_first;
  extern Func_resolve_first e_resolve_first;
  extern Func_resolve_first t_resolve_first;
  class Class_resolve_list;
  typedef std::shared_ptr<Class_resolve_list> Func_resolve_list;
  extern Func_resolve_list e_resolve_list;
  extern Func_resolve_list t_resolve_list;
  class Class_session_from_context;
  typedef std::shared_ptr<Class_session_from_context> Func_session_from_context;
  extern Func_session_from_context e_session_from_context;
  extern Func_session_from_context t_session_from_context;
  class Class_setting_from_context;
  typedef std::shared_ptr<Class_setting_from_context> Func_setting_from_context;
  extern Func_setting_from_context e_setting_from_context;
  extern Func_setting_from_context t_setting_from_context;
  class Class_string_repeat;
  typedef std::shared_ptr<Class_string_repeat> Func_string_repeat;
  extern Func_string_repeat e_string_repeat;
  extern Func_string_repeat t_string_repeat;
  class Class_string_from_any;
  typedef std::shared_ptr<Class_string_from_any> Func_string_from_any;
  extern Func_string_from_any e_string_from_any;
  extern Func_string_from_any t_string_from_any;
  class Class_string_from_any_indent;
  typedef std::shared_ptr<Class_string_from_any_indent> Func_string_from_any_indent;
  extern Func_string_from_any_indent e_string_from_any_indent;
  extern Func_string_from_any_indent t_string_from_any_indent;
  class Class_string_from_func;
  typedef std::shared_ptr<Class_string_from_func> Func_string_from_func;
  extern Func_string_from_func e_string_from_func;
  extern Func_string_from_func t_string_from_func;
  class Class_switch;
  typedef std::shared_ptr<Class_switch> Func_switch;
  extern Func_switch e_switch;
  extern Func_switch t_switch;
  class Class_then;
  typedef std::shared_ptr<Class_then> Func_then;
  extern Func_then e_then;
  extern Func_then t_then;
  class Class_traits_from_typedef;
  typedef std::shared_ptr<Class_traits_from_typedef> Func_traits_from_typedef;
  extern Func_traits_from_typedef e_traits_from_typedef;
  extern Func_traits_from_typedef t_traits_from_typedef;
  class Class_type_from_any;
  typedef std::shared_ptr<Class_type_from_any> Func_type_from_any;
  extern Func_type_from_any e_type_from_any;
  extern Func_type_from_any t_type_from_any;
  class Class_typedef_from_any;
  typedef std::shared_ptr<Class_typedef_from_any> Func_typedef_from_any;
  extern Func_typedef_from_any e_typedef_from_any;
  extern Func_typedef_from_any t_typedef_from_any;
  class Class_typedef_from_type;
  typedef std::shared_ptr<Class_typedef_from_type> Func_typedef_from_type;
  extern Func_typedef_from_type e_typedef_from_type;
  extern Func_typedef_from_type t_typedef_from_type;
  class Class_typename_from_any;
  typedef std::shared_ptr<Class_typename_from_any> Func_typename_from_any;
  extern Func_typename_from_any e_typename_from_any;
  extern Func_typename_from_any t_typename_from_any;
  class Class_typename_from_type;
  typedef std::shared_ptr<Class_typename_from_type> Func_typename_from_type;
  extern Func_typename_from_type e_typename_from_type;
  extern Func_typename_from_type t_typename_from_type;
  class Class_typename_from_typedef;
  typedef std::shared_ptr<Class_typename_from_typedef> Func_typename_from_typedef;
  extern Func_typename_from_typedef e_typename_from_typedef;
  extern Func_typename_from_typedef t_typename_from_typedef;
  class Class_typenames_from_typelist;
  typedef std::shared_ptr<Class_typenames_from_typelist> Func_typenames_from_typelist;
  extern Func_typenames_from_typelist e_typenames_from_typelist;
  extern Func_typenames_from_typelist t_typenames_from_typelist;
  class Class_user_from_context;
  typedef std::shared_ptr<Class_user_from_context> Func_user_from_context;
  extern Func_user_from_context e_user_from_context;
  extern Func_user_from_context t_user_from_context;

// :headerfirst
  int refcount = 0;

// :header

/*
  template<typename X> X func() {
         cout << "vfunc in derived class\n";
         return static_cast<X>(2);
      }  
;    

int main()

   derived *bptr = new derived;
   cout << bptr->func<int>() << endl;
   cout << dynamic_cast<base*>(bptr)->func<int>() << endl;

  virtual template<class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);

#include <iostream>
#include <string_view>

class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
	Derived d{};
	Base* b{ &d };
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

	return 0;
}
*/

  typedef std::vector<vx_core::Type_any> vx_Type_listany;
  typedef std::map<std::string, vx_core::Type_any> vx_Type_mapany;

  typedef std::initializer_list<Type_any> vx_Type_listarg;

  extern vx_Type_listany emptylistany;
  extern vx_Type_mapany emptymapany;

  // any_from_any(T, U)
  template <class T, class U> std::shared_ptr<T> any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
  // any_from_map(T, T)
  template <class T> std::shared_ptr<T> any_from_map(const std::map<std::string, std::shared_ptr<T>> &map, const std::string key, const std::shared_ptr<T> defaultval);

  // class Async
  template <class T> class Async {
  public:
    std::shared_future<T>* future;
    std::shared_ptr<vx_core::Async<vx_core::Type_any>> async_parent;
    std::function<T(vx_core::Type_any)>* fn;
  };

  // async_await(T, async<T>)
  template <class T> static std::shared_ptr<vx_core::Async<T>> async_await(T generic_any_1, std::shared_ptr<vx_core::Async<T>> async);
  // async_from_async(T, async<U>)
  template <class T, class U> static std::shared_ptr<vx_core::Async<T>> async_from_async(T generic_any_1, std::shared_ptr<vx_core::Async<U>> async);
  // async_from_async_fn(T, async<U>, fn<T>(U))
  template <class T, class U> static std::shared_ptr<vx_core::Async<T>> async_from_async_fn(T generic_any_1, std::shared_ptr<vx_core::Async<U>> async, std::function<T(U)> fn);
  // async_new_from_val (T)
  template <class T> static std::shared_ptr<vx_core::Async<T>> async_new_from_val(T val);

  // boolean_contains_from_set_val(set<T>, val)
  template <class T> bool boolean_contains_from_set_val(std::set<T> set, T val);
  // keyset_from_map(map)
  template <class T> std::set<T> keyset_from_map(std::map<std::string, T> map);
  // list_from_list(T, list<U>)
  template <class T, class U> std::vector<std::shared_ptr<T>> list_from_list(std::shared_ptr<T> generic_any_1, std::vector<std::shared_ptr<U>> list);
  // listaddall(list, listadd)
  template <class T> std::vector<std::shared_ptr<T>> listaddall(std::vector<std::shared_ptr<T>> listtarget, std::vector<std::shared_ptr<T>> listadd);
  // map_from_map(T, map<U>)
  template <class T, class U> std::map<std::string, std::shared_ptr<T>> map_from_map(std::shared_ptr<T> generic_any_1, std::map<std::string, std::shared_ptr<U>> map);
  // string_from_any(val)
  std::string string_from_any(std::any);

  // sync_from_async(generic_any_1, async)
  template <class T> T sync_from_async(T generic_any_1, Async<T>* async);

  class Class_replfunc {
  public:
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
  };

  class Class_replfunc_async {
  public:
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
  };


  // (type any)
  class Class_any : public std::any {
  public:
    int vx_iref;
    vx_core::Type_msgblock vx_p_msgblock;
    virtual vx_core::Type_msgblock vx_msgblock();
    bool vx_release();
    void vx_reserve();
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef();
    virtual vx_core::vx_Type_listany vx_dispose();
    virtual vx_core::Type_any vx_type_from_any(vx_core::Type_any value);
  };

  // (type list)
  class Class_list : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    vx_core::vx_Type_listany vx_p_list;
    virtual vx_core::vx_Type_listany vx_list();
    virtual vx_core::Type_any vx_any(vx_core::Type_int index);
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval);
  };

  // (type map)
  class Class_map : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    vx_core::vx_Type_mapany vx_p_map;
    virtual vx_core::vx_Type_mapany vx_map();
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
  };

  // (type struct)
  class Class_struct : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map();
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
  };

  // (type boolean)
  class Class_boolean : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    bool vx_p_boolean = false;
    bool vx_boolean();
    vx_core::Type_boolean vx_new_from_boolean(bool isval);
  };

  // (type number)
  class Class_number : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type decimal)
  class Class_decimal : public virtual vx_core::Class_number {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    std::string vx_p_decimal = "0.0";
    float vx_float();
    std::string vx_string();
    vx_core::Type_decimal vx_new_from_string(std::string sval);
  };

  // (type float)
  class Class_float : public virtual vx_core::Class_number {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    float vx_p_float = 0;
    float vx_float();
    vx_core::Type_float vx_new_from_float(float fval);
  };

  // (type int)
  class Class_int : public virtual vx_core::Class_number {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    int vx_p_int = 0;
    int vx_int();
    vx_core::Type_int vx_new_from_int(int ival);
  };

  // (type string)
  class Class_string : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    std::string vx_p_string = "";
    std::string vx_string();
    vx_core::Type_string vx_new_from_string(std::string text);
  };

  // (type func)
  class Class_func : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_funcdef vx_funcdef();
  };

  // (func any<-any)
  class Class_any_from_any : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any(vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
  };

  // (func any<-func)
  class Class_any_from_func : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_func fn_new(vx_core::Class_any_from_func::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_any_from_func(std::shared_ptr<T> generic_any_1);
  };

  // (type any-async<-func)
  class Class_any_async_from_func : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type any<-anylist)
  class Class_any_from_anylist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Func_any_from_any> vx_p_list;

    // vx_listany_from_any()
    virtual std::vector<vx_core::Func_any_from_any> vx_listany_from_any();
    // vx_any_from_any(index)
    virtual vx_core::Func_any_from_any vx_any_from_any(vx_core::Type_int index);
  };

  // (type anylist)
  class Class_anylist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_any> vx_p_list;

  };

  // (type anytype)
  class Class_anytype : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type arg)
  class Class_arg : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // argtype()
    vx_core::Type_type vx_p_argtype;
    virtual vx_core::Type_type argtype();
    // fn-any()
    vx_core::Func_any_from_func vx_p_fn_any;
    virtual vx_core::Func_any_from_func fn_any();
  };

  // (type arglist)
  class Class_arglist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_arg> vx_p_list;

    // vx_listarg()
    virtual std::vector<vx_core::Type_arg> vx_listarg();
    // vx_arg(index)
    virtual vx_core::Type_arg vx_arg(vx_core::Type_int index);
  };

  // (type argmap)
  class Class_argmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_arg> vx_p_map;
    // vx_maparg()
    virtual std::map<std::string, vx_core::Type_arg> vx_maparg();
    // vx_arg(key)
    virtual vx_core::Type_arg vx_arg(vx_core::Type_string key);
  };

  // (type booleanlist)
  class Class_booleanlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_boolean> vx_p_list;

    // vx_listboolean()
    virtual std::vector<vx_core::Type_boolean> vx_listboolean();
    // vx_boolean(index)
    virtual vx_core::Type_boolean vx_boolean(vx_core::Type_int index);
  };

  // (type collection)
  class Class_collection : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type compilelanguages)
  class Class_compilelanguages : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type connect)
  class Class_connect : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type connectlist)
  class Class_connectlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_connect> vx_p_list;

    // vx_listconnect()
    virtual std::vector<vx_core::Type_connect> vx_listconnect();
    // vx_connect(index)
    virtual vx_core::Type_connect vx_connect(vx_core::Type_int index);
  };

  // (type connectmap)
  class Class_connectmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_connect> vx_p_map;
    // vx_mapconnect()
    virtual std::map<std::string, vx_core::Type_connect> vx_mapconnect();
    // vx_connect(key)
    virtual vx_core::Type_connect vx_connect(vx_core::Type_string key);
  };

  // (type const)
  class Class_const : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type constdef)
  class Class_constdef : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    static vx_core::Type_constdef vx_constdef_new(
      std::string pkgname,
      std::string name,
      vx_core::Type_typedef typ
    );
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // pkgname()
    vx_core::Type_string vx_p_pkgname;
    virtual vx_core::Type_string pkgname();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // type()
    vx_core::Type_any vx_p_type;
    virtual vx_core::Type_any type();
  };

  // (type constlist)
  class Class_constlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_const> vx_p_list;

    // vx_listconst()
    virtual std::vector<vx_core::Type_const> vx_listconst();
    // vx_const(index)
    virtual vx_core::Type_const vx_const(vx_core::Type_int index);
  };

  // (type constmap)
  class Class_constmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_const> vx_p_map;
    // vx_mapconst()
    virtual std::map<std::string, vx_core::Type_const> vx_mapconst();
    // vx_const(key)
    virtual vx_core::Type_const vx_const(vx_core::Type_string key);
  };

  // (type context)
  class Class_context : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // code()
    vx_core::Type_string vx_p_code;
    virtual vx_core::Type_string code();
    // session()
    vx_core::Type_session vx_p_session;
    virtual vx_core::Type_session session();
    // setting()
    vx_core::Type_setting vx_p_setting;
    virtual vx_core::Type_setting setting();
    // state()
    vx_core::Type_state vx_p_state;
    virtual vx_core::Type_state state();
  };

  // (type error)
  class Class_error : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type funcdef)
  class Class_funcdef : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    static vx_core::Type_funcdef vx_funcdef_new(
      std::string pkgname,
      std::string name,
      int idx,
      bool async,
      vx_core::Type_any typ
    ) {
      vx_core::Type_funcdef output;
      output->vx_p_pkgname = vx_core::t_string->vx_new_from_string(pkgname);
      output->vx_p_name = vx_core::t_string->vx_new_from_string(name);
      output->vx_p_idx = vx_core::t_int->vx_new_from_int(idx);
      output->vx_p_async = vx_core::t_boolean->vx_new_from_boolean(async);
      output->vx_p_type = typ;
      return output;
    };
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // pkgname()
    vx_core::Type_string vx_p_pkgname;
    virtual vx_core::Type_string pkgname();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // idx()
    vx_core::Type_int vx_p_idx;
    virtual vx_core::Type_int idx();
    // type()
    vx_core::Type_any vx_p_type;
    virtual vx_core::Type_any type();
    // async()
    vx_core::Type_boolean vx_p_async;
    virtual vx_core::Type_boolean async();
  };

  // (type funclist)
  class Class_funclist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_func> vx_p_list;

    // vx_listfunc()
    virtual std::vector<vx_core::Type_func> vx_listfunc();
    // vx_func(index)
    virtual vx_core::Type_func vx_func(vx_core::Type_int index);
  };

  // (type funcmap)
  class Class_funcmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_func> vx_p_map;
    // vx_mapfunc()
    virtual std::map<std::string, vx_core::Type_func> vx_mapfunc();
    // vx_func(key)
    virtual vx_core::Type_func vx_func(vx_core::Type_string key);
  };

  // (type intlist)
  class Class_intlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_int> vx_p_list;

    // vx_listint()
    virtual std::vector<vx_core::Type_int> vx_listint();
    // vx_int(index)
    virtual vx_core::Type_int vx_int(vx_core::Type_int index);
  };

  // (type intmap)
  class Class_intmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_int> vx_p_map;
    // vx_mapint()
    virtual std::map<std::string, vx_core::Type_int> vx_mapint();
    // vx_int(key)
    virtual vx_core::Type_int vx_int(vx_core::Type_string key);
  };

  // (type listtype)
  class Class_listtype : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type maptype)
  class Class_maptype : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type mempool)
  class Class_mempool : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // valuepool()
    vx_core::Type_value vx_p_valuepool;
    virtual vx_core::Type_value valuepool();
  };

  // (type msg)
  class Class_msg : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::Type_msgblock vx_msgblock() override;
    std::exception* err;
    virtual vx_core::Type_msg vx_new_error(std::string text);
    virtual vx_core::Type_msg vx_new_from_exception(std::string text, std::exception err);
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // code()
    vx_core::Type_string vx_p_code;
    virtual vx_core::Type_string code();
    // severity()
    vx_core::Type_int vx_p_severity;
    virtual vx_core::Type_int severity();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type msgblock)
  class Class_msgblock : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::Type_msgblock vx_msgblock() override;
    virtual vx_core::Type_msgblock vx_msgblock_from_copy_arrayval(vx_core::Type_any copy, vx_core::vx_Type_listany vals);
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // msgs()
    vx_core::Type_msglist vx_p_msgs;
    virtual vx_core::Type_msglist msgs();
    // msgblocks()
    vx_core::Type_msgblocklist vx_p_msgblocks;
    virtual vx_core::Type_msgblocklist msgblocks();
  };

  // (type msgblocklist)
  class Class_msgblocklist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_msgblock> vx_p_list;

    // vx_listmsgblock()
    virtual std::vector<vx_core::Type_msgblock> vx_listmsgblock();
    // vx_msgblock(index)
    virtual vx_core::Type_msgblock vx_msgblock(vx_core::Type_int index);
  };

  // (type msglist)
  class Class_msglist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_msg> vx_p_list;

    // vx_listmsg()
    virtual std::vector<vx_core::Type_msg> vx_listmsg();
    // vx_msg(index)
    virtual vx_core::Type_msg vx_msg(vx_core::Type_int index);
  };

  // (type none)
  class Class_none : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type notype)
  class Class_notype : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type numberlist)
  class Class_numberlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_number> vx_p_list;

    // vx_listnumber()
    virtual std::vector<vx_core::Type_number> vx_listnumber();
    // vx_number(index)
    virtual vx_core::Type_number vx_number(vx_core::Type_int index);
  };

  // (type numbermap)
  class Class_numbermap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_number> vx_p_map;
    // vx_mapnumber()
    virtual std::map<std::string, vx_core::Type_number> vx_mapnumber();
    // vx_number(key)
    virtual vx_core::Type_number vx_number(vx_core::Type_string key);
  };

  // (type package)
  class Class_package : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
  };

  // (type packagemap)
  class Class_packagemap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_package> vx_p_map;
    // vx_mappackage()
    virtual std::map<std::string, vx_core::Type_package> vx_mappackage();
    // vx_package(key)
    virtual vx_core::Type_package vx_package(vx_core::Type_string key);
  };

  // (type permission)
  class Class_permission : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
  };

  // (type permissionlist)
  class Class_permissionlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_permission> vx_p_list;

    // vx_listpermission()
    virtual std::vector<vx_core::Type_permission> vx_listpermission();
    // vx_permission(index)
    virtual vx_core::Type_permission vx_permission(vx_core::Type_int index);
  };

  // (type permissionmap)
  class Class_permissionmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_permission> vx_p_map;
    // vx_mappermission()
    virtual std::map<std::string, vx_core::Type_permission> vx_mappermission();
    // vx_permission(key)
    virtual vx_core::Type_permission vx_permission(vx_core::Type_string key);
  };

  // (type security)
  class Class_security : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // permissions()
    vx_core::Type_permissionlist vx_p_permissions;
    virtual vx_core::Type_permissionlist permissions();
    // permissionmap()
    vx_core::Type_permissionmap vx_p_permissionmap;
    virtual vx_core::Type_permissionmap permissionmap();
  };

  // (type session)
  class Class_session : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // user()
    vx_core::Type_user vx_p_user;
    virtual vx_core::Type_user user();
    // connectlist()
    vx_core::Type_connectlist vx_p_connectlist;
    virtual vx_core::Type_connectlist connectlist();
    // connectmap()
    vx_core::Type_connectmap vx_p_connectmap;
    virtual vx_core::Type_connectmap connectmap();
  };

  // (type setting)
  class Class_setting : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // pathmap()
    vx_core::Type_stringmap vx_p_pathmap;
    virtual vx_core::Type_stringmap pathmap();
  };

  // (type state)
  class Class_state : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_statelistener> vx_p_map;
    // vx_mapstatelistener()
    virtual std::map<std::string, vx_core::Type_statelistener> vx_mapstatelistener();
    // vx_statelistener(key)
    virtual vx_core::Type_statelistener vx_statelistener(vx_core::Type_string key);
  };

  // (type statelistener)
  class Class_statelistener : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // path()
    vx_core::Type_string vx_p_path;
    virtual vx_core::Type_string path();
    // value()
    vx_core::Type_any vx_p_value;
    virtual vx_core::Type_any value();
    // fn-boolean()
    vx_core::Func_boolean_from_none vx_p_fn_boolean;
    virtual vx_core::Func_boolean_from_none fn_boolean();
  };

  // (type stringlist)
  class Class_stringlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_string> vx_p_list;

    // vx_liststring()
    virtual std::vector<vx_core::Type_string> vx_liststring();
    // vx_string(index)
    virtual vx_core::Type_string vx_string(vx_core::Type_int index);
  };

  // (type stringmap)
  class Class_stringmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_string> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring();
    // vx_string(key)
    virtual vx_core::Type_string vx_string(vx_core::Type_string key);
  };

  // (type thenelse)
  class Class_thenelse : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // code()
    vx_core::Type_string vx_p_code;
    virtual vx_core::Type_string code();
    // value()
    vx_core::Type_any vx_p_value;
    virtual vx_core::Type_any value();
    // values()
    vx_core::Type_list vx_p_values;
    virtual vx_core::Type_list values();
    // fn-cond()
    vx_core::Func_boolean_from_func vx_p_fn_cond;
    virtual vx_core::Func_boolean_from_func fn_cond();
    // fn-any()
    vx_core::Func_any_from_func vx_p_fn_any;
    virtual vx_core::Func_any_from_func fn_any();
  };

  // (type thenelselist)
  class Class_thenelselist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_thenelse> vx_p_list;

    // vx_listthenelse()
    virtual std::vector<vx_core::Type_thenelse> vx_listthenelse();
    // vx_thenelse(index)
    virtual vx_core::Type_thenelse vx_thenelse(vx_core::Type_int index);
  };

  // (type type)
  class Class_type : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type typedef)
  class Class_typedef : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    static vx_core::Type_typedef vx_typedef_new(
      std::string pkgname,
      std::string name,
      std::string extend,
      vx_core::Type_typelist traits,
      vx_core::Type_typelist allowtypes,
      vx_core::Type_typelist disallowtypes,
      vx_core::Type_funclist allowfuncs,
      vx_core::Type_funclist disallowfuncs,
      vx_core::Type_anylist allowvalues,
      vx_core::Type_anylist disallowvalues,
      vx_core::Type_argmap properties
    );
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // pkgname()
    vx_core::Type_string vx_p_pkgname;
    virtual vx_core::Type_string pkgname();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // extends()
    vx_core::Type_string vx_p_extend;
    virtual vx_core::Type_string extend();
    // allowfuncs()
    vx_core::Type_funclist vx_p_allowfuncs;
    virtual vx_core::Type_funclist allowfuncs();
    // allowtypes()
    vx_core::Type_typelist vx_p_allowtypes;
    virtual vx_core::Type_typelist allowtypes();
    // allowvalues()
    vx_core::Type_anylist vx_p_allowvalues;
    virtual vx_core::Type_anylist allowvalues();
    // disallowfuncs()
    vx_core::Type_funclist vx_p_disallowfuncs;
    virtual vx_core::Type_funclist disallowfuncs();
    // disallowtypes()
    vx_core::Type_typelist vx_p_disallowtypes;
    virtual vx_core::Type_typelist disallowtypes();
    // disallowvalues()
    vx_core::Type_anylist vx_p_disallowvalues;
    virtual vx_core::Type_anylist disallowvalues();
    // properties()
    vx_core::Type_argmap vx_p_properties;
    virtual vx_core::Type_argmap properties();
    // proplast()
    vx_core::Type_arg vx_p_proplast;
    virtual vx_core::Type_arg proplast();
    // traits()
    vx_core::Type_typelist vx_p_traits;
    virtual vx_core::Type_typelist traits();
  };

  // (type typelist)
  class Class_typelist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_any> vx_p_list;

  };

  // (type typemap)
  class Class_typemap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
  };

  // (type user)
  class Class_user : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // security()
    vx_core::Type_security vx_p_security;
    virtual vx_core::Type_security security();
    // username()
    vx_core::Type_string vx_p_username;
    virtual vx_core::Type_string username();
    // token()
    vx_core::Type_string vx_p_token;
    virtual vx_core::Type_string token();
  };

  // (type value)
  class Class_value : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // next()
    vx_core::Type_any vx_p_next;
    virtual vx_core::Type_any next();
    // refs()
    vx_core::Type_int vx_p_refs;
    virtual vx_core::Type_int refs();
  };

  // (const false)
  class Class_false : public vx_core::Class_boolean {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_false vx_const_new();
    bool vx_core::Class_false::vx_boolean();
  };

  // (const globalpackagemap)
  class Class_globalpackagemap : public vx_core::Class_packagemap {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_globalpackagemap vx_const_new();
  };

  // (const infinity)
  class Class_infinity : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_infinity vx_const_new();
    int vx_core::Class_infinity::vx_int();
  };

  // (const mempool-active)
  class Class_mempool_active : public vx_core::Class_mempool {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_mempool_active vx_const_new();
  };

  // (const msg-error)
  class Class_msg_error : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_msg_error vx_const_new();
    int vx_core::Class_msg_error::vx_int();
  };

  // (const msg-info)
  class Class_msg_info : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_msg_info vx_const_new();
    int vx_core::Class_msg_info::vx_int();
  };

  // (const msg-severe)
  class Class_msg_severe : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_msg_severe vx_const_new();
    int vx_core::Class_msg_severe::vx_int();
  };

  // (const msg-warning)
  class Class_msg_warning : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_msg_warning vx_const_new();
    int vx_core::Class_msg_warning::vx_int();
  };

  // (const neginfinity)
  class Class_neginfinity : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_neginfinity vx_const_new();
    int vx_core::Class_neginfinity::vx_int();
  };

  // (const newline)
  class Class_newline : public vx_core::Class_string {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_newline vx_const_new();
    std::string vx_core::Class_newline::vx_string();
  };

  // (const notanumber)
  class Class_notanumber : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_notanumber vx_const_new();
    int vx_core::Class_notanumber::vx_int();
  };

  // (const nothing)
  class Class_nothing : public vx_core::Class_string {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_nothing vx_const_new();
    std::string vx_core::Class_nothing::vx_string();
  };

  // (const quote)
  class Class_quote : public vx_core::Class_string {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_quote vx_const_new();
    std::string vx_core::Class_quote::vx_string();
  };

  // (const true)
  class Class_true : public vx_core::Class_boolean {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_core::Const_true vx_const_new();
    bool vx_core::Class_true::vx_boolean();
  };

  // (func !)
  class Class_not : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_not(vx_core::Type_boolean val);
  };

  // (func !-empty)
  class Class_notempty : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_notempty(vx_core::Type_string text);
  };

  // (func !-empty)
  class Class_notempty_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_notempty_1(vx_core::Type_any val);
  };

  // (func !=)
  class Class_ne : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_ne(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func *)
  class Class_multiply : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_multiply(vx_core::Type_int num1, vx_core::Type_int num2);
  };

  // (func *)
  class Class_multiply_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_multiply_1(vx_core::Type_number num1, vx_core::Type_number num2);
  };

  // (func *)
  class Class_multiply_2 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_multiply_2(vx_core::Type_intlist nums);
  };

  // (func *)
  class Class_multiply_3 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_multiply_3(vx_core::Type_numberlist nums);
  };

  // (func +)
  class Class_plus : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_plus(vx_core::Type_int num1, vx_core::Type_int num2);
  };

  // (func +)
  class Class_plus_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_plus_1(vx_core::Type_number num1, vx_core::Type_number num2);
  };

  // (func +)
  class Class_plus_2 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_plus_2(vx_core::Type_intlist nums);
  };

  // (func +)
  class Class_plus_3 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_plus_3(vx_core::Type_numberlist nums);
  };

  // (func +1)
  class Class_plus1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_plus1(vx_core::Type_int num);
  };

  // (func -)
  class Class_minus : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_minus(vx_core::Type_int num1, vx_core::Type_int num2);
  };

  // (func -)
  class Class_minus_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_minus_1(vx_core::Type_number num1, vx_core::Type_number num2);
  };

  // (func -)
  class Class_minus_2 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_minus_2(vx_core::Type_intlist nums);
  };

  // (func -)
  class Class_minus_3 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_minus_3(vx_core::Type_numberlist nums);
  };

  // (func .)
  class Class_dotmethod : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_dotmethod(vx_core::Type_any object, vx_core::Type_string method, vx_core::Type_anylist params);
  };

  // (func /)
  class Class_divide : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_divide(vx_core::Type_number num1, vx_core::Type_number num2);
  };

  // (func <)
  class Class_lt : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_lt(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func <)
  class Class_lt_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_lt_1(vx_core::Type_anylist values);
  };

  // (func <-)
  class Class_chainfirst : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_chainfirst(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist);
  };

  // (func <<-)
  class Class_chainlast : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_chainlast(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist);
  };

  // (func <=)
  class Class_le : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_le(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func <=)
  class Class_le_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_le_1(vx_core::Type_anylist args);
  };

  // (func =)
  class Class_eq : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_eq(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func =)
  class Class_eq_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_eq_1(vx_core::Type_anylist values);
  };

  // (func >)
  class Class_gt : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_gt(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func >)
  class Class_gt_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_gt_1(vx_core::Type_anylist values);
  };

  // (func >=)
  class Class_ge : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_ge(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func >=)
  class Class_ge_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_ge_1(vx_core::Type_anylist args);
  };

  // (func allowtypenames<-typedef)
  class Class_allowtypenames_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_stringlist vx_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func allowtypes<-typedef)
  class Class_allowtypes_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_typelist vx_allowtypes_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func and)
  class Class_and : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2);
  };

  // (func and)
  class Class_and_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_and_1(vx_core::Type_booleanlist values);
  };

  // (func any<-any-async)
  class Class_any_from_any_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>(vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
  };

  // (func any<-any-context)
  class Class_any_from_any_context : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_context)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
  };

  // (func any<-any-context-async)
  class Class_any_from_any_context_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*(vx_core::Type_any, vx_core::Type_context)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_context_async fn_new(vx_core::Class_any_from_any_context_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_any_context_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
  };

  // (func any<-func-async)
  class Class_any_from_func_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_func_async fn_new(vx_core::Class_any_from_func_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_func_async(std::shared_ptr<T> generic_any_1);
  };

  // (func any<-key-value)
  class Class_any_from_key_value : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any(vx_core::Type_string, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_key_value fn_new(vx_core::Class_any_from_key_value::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_any_from_key_value(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val);
  };

  // (func any<-key-value-async)
  class Class_any_from_key_value_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*(vx_core::Type_string, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_key_value_async fn_new(vx_core::Class_any_from_key_value_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_key_value_async(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val);
  };

  // (func any<-list)
  class Class_any_from_list : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class X> std::shared_ptr<T> vx_any_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int index);
  };

  // (func any<-list-reduce)
  class Class_any_from_list_reduce : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class Y> std::shared_ptr<T> vx_any_from_list_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce fn_reduce);
  };

  // (func any<-list-reduce-next)
  class Class_any_from_list_reduce_next : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class Y> std::shared_ptr<T> vx_any_from_list_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce_next fn_reduce_next);
  };

  // (func any<-map)
  class Class_any_from_map : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class N> std::shared_ptr<T> vx_any_from_map(std::shared_ptr<T> generic_any_1, std::shared_ptr<N> valuemap, vx_core::Type_string key);
  };

  // (func any<-none)
  class Class_any_from_none : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_none fn_new(vx_core::Class_any_from_none::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_any_from_none(std::shared_ptr<T> generic_any_1);
  };

  // (func any<-none-async)
  class Class_any_from_none_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_none_async fn_new(vx_core::Class_any_from_none_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_none_async(std::shared_ptr<T> generic_any_1);
  };

  // (func any<-reduce)
  class Class_any_from_reduce : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce fn_new(vx_core::Class_any_from_reduce::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_any_from_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item);
  };

  // (func any<-reduce-async)
  class Class_any_from_reduce_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*(vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_async fn_new(vx_core::Class_any_from_reduce_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_reduce_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item);
  };

  // (func any<-reduce-next)
  class Class_any_from_reduce_next : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_next fn_new(vx_core::Class_any_from_reduce_next::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_any_from_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next);
  };

  // (func any<-reduce-next-async)
  class Class_any_from_reduce_next_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Async<vx_core::Type_any>*(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_next_async fn_new(vx_core::Class_any_from_reduce_next_async::IFn fn);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_any_from_reduce_next_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next);
  };

  // (func any<-struct)
  class Class_any_from_struct : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class R> std::shared_ptr<T> vx_any_from_struct(std::shared_ptr<T> generic_any_1, std::shared_ptr<R> vstruct, vx_core::Type_string key);
  };

  // (func async)
  class Class_async : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value);
  };

  // (func boolean<-any)
  class Class_boolean_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_from_any(vx_core::Type_any value);
  };

  // (func boolean<-func)
  class Class_boolean_from_func : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_boolean_from_func fn_new(vx_core::Class_any_from_func::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_from_func();
  };

  // (func boolean<-none)
  class Class_boolean_from_none : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_boolean_from_none fn_new(vx_core::Class_any_from_func::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_from_none();
  };

  // (func case)
  class Class_case : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_thenelse vx_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any);
  };

  // (func case)
  class Class_case_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_thenelse vx_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any);
  };

  // (func compare)
  class Class_compare : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_compare(vx_core::Type_any val1, vx_core::Type_any val2);
  };

  // (func contains)
  class Class_contains : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_contains(vx_core::Type_string text, vx_core::Type_string find);
  };

  // (func contains)
  class Class_contains_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_contains_1(vx_core::Type_list values, vx_core::Type_any find);
  };

  // (func copy)
  class Class_copy : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> value, vx_core::Type_anylist values);
  };

  // (func else)
  class Class_else : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_thenelse vx_else(vx_core::Func_any_from_func fn_any);
  };

  // (func empty)
  class Class_empty : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> type);
  };

  // (func extends<-any)
  class Class_extends_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_extends_from_any(vx_core::Type_any val);
  };

  // (func extends<-typedef)
  class Class_extends_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_extends_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func first<-list)
  class Class_first_from_list : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class X> std::shared_ptr<T> vx_first_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values);
  };

  // (func first<-list-fn-any<-any)
  class Class_first_from_list_fn_any_from_any : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class X> std::shared_ptr<T> vx_first_from_list_fn_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Func_any_from_any fn_any_from_any);
  };

  // (func fn)
  class Class_fn : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_fn(std::shared_ptr<T> generic_any_1, vx_core::Type_arglist params, vx_core::Func_any_from_func fn_any);
  };

  // (func funcdef<-func)
  class Class_funcdef_from_func : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_funcdef vx_funcdef_from_func(vx_core::Type_func val);
  };

  // (func funcname<-funcdef)
  class Class_funcname_from_funcdef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_funcname_from_funcdef(vx_core::Type_funcdef funcdef);
  };

  // (func global-package-get)
  class Class_global_package_get : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_package vx_global_package_get(vx_core::Type_string pkgname);
  };

  // (func global-package-set)
  class Class_global_package_set : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg);
  };

  // (func if)
  class Class_if : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_if(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> then);
  };

  // (func if)
  class Class_if_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_if_1(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> thenval, std::shared_ptr<T> elseval);
  };

  // (func if)
  class Class_if_2 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_if_2(std::shared_ptr<T> generic_any_1, vx_core::Type_thenelselist thenelselist);
  };

  // (func int<-func)
  class Class_int_from_func : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_int_from_func fn_new(vx_core::Class_any_from_func::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_int_from_func();
  };

  // (func int<-string)
  class Class_int_from_string : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_int_from_string(vx_core::Type_string val);
  };

  // (func is-empty)
  class Class_is_empty : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_empty(vx_core::Type_string text);
  };

  // (func is-empty)
  class Class_is_empty_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_empty_1(vx_core::Type_any value);
  };

  // (func is-endswith)
  class Class_is_endswith : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_endswith(vx_core::Type_string text, vx_core::Type_string find);
  };

  // (func is-func)
  class Class_is_func : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_func(vx_core::Type_any val);
  };

  // (func is-int)
  class Class_is_int : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_int(vx_core::Type_any value);
  };

  // (func is-number)
  class Class_is_number : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_number(vx_core::Type_any value);
  };

  // (func is-pass<-permission)
  class Class_is_pass_from_permission : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_pass_from_permission(vx_core::Type_permission permission, vx_core::Type_context context);
  };

  // (func last<-list)
  class Class_last_from_list : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class X> std::shared_ptr<T> vx_last_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values);
  };

  // (func length<-list)
  class Class_length_from_list : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_int vx_length_from_list(vx_core::Type_list values);
  };

  // (func let)
  class Class_let : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_let(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any);
  };

  // (func let-async)
  class Class_let_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_let_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any_async);
  };

  // (func list-join<-list)
  class Class_list_join_from_list : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X, class Y> std::shared_ptr<X> vx_list_join_from_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any);
  };

  // (func list<-list)
  class Class_list_from_list : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X, class Y> std::shared_ptr<X> vx_list_from_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any);
  };

  // (func list<-list-async)
  class Class_list_from_list_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class X, class Y> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_list_from_list_async(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any_async fn_any_from_any_async);
  };

  // (func list<-map)
  class Class_list_from_map : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X, class O> std::shared_ptr<X> vx_list_from_map(std::shared_ptr<X> generic_any_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value);
  };

  // (func list<-map-async)
  class Class_list_from_map_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class X, class O> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_list_from_map_async(std::shared_ptr<X> generic_any_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value_async fn_any_from_key_value_async);
  };

  // (func list<-type)
  class Class_list_from_type : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_list_from_type(vx_core::Type_any type);
  };

  // (func log)
  class Class_log : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_log(vx_core::Type_any value);
  };

  // (func map<-list)
  class Class_map_from_list : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class Y, class N> std::shared_ptr<N> vx_map_from_list(std::shared_ptr<N> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_any_from_any);
  };

  // (func mempool-addref)
  class Class_mempool_addref : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_mempool_addref(vx_core::Type_anylist values);
  };

  // (func mempool-release)
  class Class_mempool_release : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_mempool_release(vx_core::Type_value value);
  };

  // (func mempool-removeref)
  class Class_mempool_removeref : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_mempool_removeref(vx_core::Type_anylist values);
  };

  // (func mempool-removerefchildren)
  class Class_mempool_removerefchildren : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_mempool_removerefchildren(vx_core::Type_anylist values);
  };

  // (func mempool-reserve)
  class Class_mempool_reserve : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_value vx_mempool_reserve();
  };

  // (func msg<-error)
  class Class_msg_from_error : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_msg vx_msg_from_error(vx_core::Type_string error);
  };

  // (func msgblock<-msgblock-msg)
  class Class_msgblock_from_msgblock_msg : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_msgblock vx_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg);
  };

  // (func msgblock<-msgblock-msgblock)
  class Class_msgblock_from_msgblock_msgblock : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_msgblock vx_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock);
  };

  // (func name<-typedef)
  class Class_name_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_name_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func native)
  class Class_native : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_native(std::shared_ptr<T> generic_any_1, vx_core::Type_anylist clauses);
  };

  // (func native<-any)
  class Class_native_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_native_from_any(vx_core::Type_any value);
  };

  // (func new)
  class Class_new : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> type, vx_core::Type_anylist values);
  };

  // (func number<-func)
  class Class_number_from_func : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_number vx_number_from_func();
  };

  // (func or)
  class Class_or : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2);
  };

  // (func or)
  class Class_or_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_or_1(vx_core::Type_booleanlist values);
  };

  // (func packagename<-typedef)
  class Class_packagename_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_packagename_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func path<-context-path)
  class Class_path_from_context_path : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_path_from_context_path(vx_core::Type_string path, vx_core::Type_context context);
  };

  // (func path<-setting-path)
  class Class_path_from_setting_path : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_path_from_setting_path(vx_core::Type_setting session, vx_core::Type_string path);
  };

  // (func permission<-id-context)
  class Class_permission_from_id_context : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_permission vx_permission_from_id_context(vx_core::Type_string id, vx_core::Type_context context);
  };

  // (func properties<-typedef)
  class Class_properties_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_argmap vx_properties_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func proplast<-typedef)
  class Class_proplast_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_arg vx_proplast_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func resolve)
  class Class_resolve : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_resolve(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value);
  };

  // (func resolve)
  class Class_resolve_1 : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<T> vx_resolve_1(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any);
  };

  // (func resolve-async)
  class Class_resolve_async : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_resolve_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any);
  };

  // (func resolve-first)
  class Class_resolve_first : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class X> std::shared_ptr<T> vx_resolve_first(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> clauses);
  };

  // (func resolve-list)
  class Class_resolve_list : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X> std::shared_ptr<X> vx_resolve_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> clauses);
  };

  // (func session<-context)
  class Class_session_from_context : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_session vx_session_from_context(vx_core::Type_context context);
  };

  // (func setting<-context)
  class Class_setting_from_context : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_setting vx_setting_from_context(vx_core::Type_context context);
  };

  // (func string-repeat)
  class Class_string_repeat : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_repeat(vx_core::Type_string text, vx_core::Type_int repeat);
  };

  // (func string<-any)
  class Class_string_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_any(vx_core::Type_any value);
  };

  // (func string<-any-indent)
  class Class_string_from_any_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_any_indent(vx_core::Type_any value, vx_core::Type_int indent, vx_core::Type_boolean linefeed);
  };

  // (func string<-func)
  class Class_string_from_func : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    virtual vx_core::Func_string_from_func fn_new(vx_core::Class_any_from_func::IFn fn);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_func();
  };

  // (func switch)
  class Class_switch : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class T, class U> std::shared_ptr<T> vx_switch(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> val, vx_core::Type_thenelselist thenelselist);
  };

  // (func then)
  class Class_then : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_thenelse vx_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any);
  };

  // (func traits<-typedef)
  class Class_traits_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_typelist vx_traits_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func type<-any)
  class Class_type_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_type_from_any(vx_core::Type_any value);
  };

  // (func typedef<-any)
  class Class_typedef_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_typedef vx_typedef_from_any(vx_core::Type_any val);
  };

  // (func typedef<-type)
  class Class_typedef_from_type : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_typedef vx_typedef_from_type(vx_core::Type_any val);
  };

  // (func typename<-any)
  class Class_typename_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_typename_from_any(vx_core::Type_any value);
  };

  // (func typename<-type)
  class Class_typename_from_type : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_typename_from_type(vx_core::Type_any type);
  };

  // (func typename<-typedef)
  class Class_typename_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_typename_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func typenames<-typelist)
  class Class_typenames_from_typelist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_stringlist vx_typenames_from_typelist(vx_core::Type_typelist typelist);
  };

  // (func user<-context)
  class Class_user_from_context : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_user vx_user_from_context(vx_core::Type_context context);
  };

  // (func any<-any)
  template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);

  // (func any<-func)
  template <class T> std::shared_ptr<T> f_any_from_func(std::shared_ptr<T> generic_any_1);

  // (func !)
  vx_core::Type_boolean f_not(vx_core::Type_boolean val);

  // (func !-empty)
  vx_core::Type_boolean f_notempty(vx_core::Type_string text);

  // (func !-empty)
  vx_core::Type_boolean f_notempty_1(vx_core::Type_any val);

  // (func !=)
  vx_core::Type_boolean f_ne(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func *)
  vx_core::Type_int f_multiply(vx_core::Type_int num1, vx_core::Type_int num2);

  // (func *)
  vx_core::Type_number f_multiply_1(vx_core::Type_number num1, vx_core::Type_number num2);

  // (func *)
  vx_core::Type_int f_multiply_2(vx_core::Type_intlist nums);

  // (func *)
  vx_core::Type_number f_multiply_3(vx_core::Type_numberlist nums);

  // (func +)
  vx_core::Type_int f_plus(vx_core::Type_int num1, vx_core::Type_int num2);

  // (func +)
  vx_core::Type_number f_plus_1(vx_core::Type_number num1, vx_core::Type_number num2);

  // (func +)
  vx_core::Type_int f_plus_2(vx_core::Type_intlist nums);

  // (func +)
  vx_core::Type_number f_plus_3(vx_core::Type_numberlist nums);

  // (func +1)
  vx_core::Type_int f_plus1(vx_core::Type_int num);

  // (func -)
  vx_core::Type_int f_minus(vx_core::Type_int num1, vx_core::Type_int num2);

  // (func -)
  vx_core::Type_number f_minus_1(vx_core::Type_number num1, vx_core::Type_number num2);

  // (func -)
  vx_core::Type_int f_minus_2(vx_core::Type_intlist nums);

  // (func -)
  vx_core::Type_number f_minus_3(vx_core::Type_numberlist nums);

  // (func .)
  vx_core::Type_any f_dotmethod(vx_core::Type_any object, vx_core::Type_string method, vx_core::Type_anylist params);

  // (func /)
  vx_core::Type_number f_divide(vx_core::Type_number num1, vx_core::Type_number num2);

  // (func <)
  vx_core::Type_boolean f_lt(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func <)
  vx_core::Type_boolean f_lt_1(vx_core::Type_anylist values);

  // (func <-)
  template <class T> std::shared_ptr<T> f_chainfirst(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist);

  // (func <<-)
  template <class T> std::shared_ptr<T> f_chainlast(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist);

  // (func <=)
  vx_core::Type_boolean f_le(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func <=)
  vx_core::Type_boolean f_le_1(vx_core::Type_anylist args);

  // (func =)
  vx_core::Type_boolean f_eq(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func =)
  vx_core::Type_boolean f_eq_1(vx_core::Type_anylist values);

  // (func >)
  vx_core::Type_boolean f_gt(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func >)
  vx_core::Type_boolean f_gt_1(vx_core::Type_anylist values);

  // (func >=)
  vx_core::Type_boolean f_ge(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func >=)
  vx_core::Type_boolean f_ge_1(vx_core::Type_anylist args);

  // (func allowtypenames<-typedef)
  vx_core::Type_stringlist f_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef);

  // (func allowtypes<-typedef)
  vx_core::Type_typelist f_allowtypes_from_typedef(vx_core::Type_typedef vtypedef);

  // (func and)
  vx_core::Type_boolean f_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2);

  // (func and)
  vx_core::Type_boolean f_and_1(vx_core::Type_booleanlist values);

  // (func any<-any-async)
  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);

  // (func any<-any-context)
  template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);

  // (func any<-any-context-async)
  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_context_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);

  // (func any<-func-async)
  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_func_async(std::shared_ptr<T> generic_any_1);

  // (func any<-key-value)
  template <class T, class U> std::shared_ptr<T> f_any_from_key_value(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val);

  // (func any<-key-value-async)
  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_key_value_async(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val);

  // (func any<-list)
  template <class T, class X> std::shared_ptr<T> f_any_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int index);

  // (func any<-list-reduce)
  template <class T, class Y> std::shared_ptr<T> f_any_from_list_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce fn_reduce);

  // (func any<-list-reduce-next)
  template <class T, class Y> std::shared_ptr<T> f_any_from_list_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce_next fn_reduce_next);

  // (func any<-map)
  template <class T, class N> std::shared_ptr<T> f_any_from_map(std::shared_ptr<T> generic_any_1, std::shared_ptr<N> valuemap, vx_core::Type_string key);

  // (func any<-none)
  template <class T> std::shared_ptr<T> f_any_from_none(std::shared_ptr<T> generic_any_1);

  // (func any<-none-async)
  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_none_async(std::shared_ptr<T> generic_any_1);

  // (func any<-reduce)
  template <class T, class U> std::shared_ptr<T> f_any_from_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item);

  // (func any<-reduce-async)
  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_reduce_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item);

  // (func any<-reduce-next)
  template <class T, class U> std::shared_ptr<T> f_any_from_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next);

  // (func any<-reduce-next-async)
  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_reduce_next_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next);

  // (func any<-struct)
  template <class T, class R> std::shared_ptr<T> f_any_from_struct(std::shared_ptr<T> generic_any_1, std::shared_ptr<R> vstruct, vx_core::Type_string key);

  // (func async)
  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value);

  // (func boolean<-any)
  vx_core::Type_boolean f_boolean_from_any(vx_core::Type_any value);

  // (func boolean<-func)
  vx_core::Type_boolean f_boolean_from_func();

  // (func boolean<-none)
  vx_core::Type_boolean f_boolean_from_none();

  // (func case)
  vx_core::Type_thenelse f_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any);

  // (func case)
  vx_core::Type_thenelse f_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any);

  // (func compare)
  vx_core::Type_int f_compare(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func contains)
  vx_core::Type_boolean f_contains(vx_core::Type_string text, vx_core::Type_string find);

  // (func contains)
  vx_core::Type_boolean f_contains_1(vx_core::Type_list values, vx_core::Type_any find);

  // (func copy)
  template <class T> std::shared_ptr<T> f_copy(std::shared_ptr<T> value, vx_core::Type_anylist values);

  // (func else)
  vx_core::Type_thenelse f_else(vx_core::Func_any_from_func fn_any);

  // (func empty)
  template <class T> std::shared_ptr<T> f_empty(std::shared_ptr<T> type);

  // (func extends<-any)
  vx_core::Type_string f_extends_from_any(vx_core::Type_any val);

  // (func extends<-typedef)
  vx_core::Type_string f_extends_from_typedef(vx_core::Type_typedef vtypedef);

  // (func first<-list)
  template <class T, class X> std::shared_ptr<T> f_first_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values);

  // (func first<-list-fn-any<-any)
  template <class T, class X> std::shared_ptr<T> f_first_from_list_fn_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Func_any_from_any fn_any_from_any);

  // (func fn)
  template <class T> std::shared_ptr<T> f_fn(std::shared_ptr<T> generic_any_1, vx_core::Type_arglist params, vx_core::Func_any_from_func fn_any);

  // (func funcdef<-func)
  vx_core::Type_funcdef f_funcdef_from_func(vx_core::Type_func val);

  // (func funcname<-funcdef)
  vx_core::Type_string f_funcname_from_funcdef(vx_core::Type_funcdef funcdef);

  // (func global-package-get)
  vx_core::Type_package f_global_package_get(vx_core::Type_string pkgname);

  // (func global-package-set)
  void f_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg);

  // (func if)
  template <class T> std::shared_ptr<T> f_if(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> then);

  // (func if)
  template <class T> std::shared_ptr<T> f_if_1(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> thenval, std::shared_ptr<T> elseval);

  // (func if)
  template <class T> std::shared_ptr<T> f_if_2(std::shared_ptr<T> generic_any_1, vx_core::Type_thenelselist thenelselist);

  // (func int<-func)
  vx_core::Type_int f_int_from_func();

  // (func int<-string)
  vx_core::Type_int f_int_from_string(vx_core::Type_string val);

  // (func is-empty)
  vx_core::Type_boolean f_is_empty(vx_core::Type_string text);

  // (func is-empty)
  vx_core::Type_boolean f_is_empty_1(vx_core::Type_any value);

  // (func is-endswith)
  vx_core::Type_boolean f_is_endswith(vx_core::Type_string text, vx_core::Type_string find);

  // (func is-func)
  vx_core::Type_boolean f_is_func(vx_core::Type_any val);

  // (func is-int)
  vx_core::Type_boolean f_is_int(vx_core::Type_any value);

  // (func is-number)
  vx_core::Type_boolean f_is_number(vx_core::Type_any value);

  // (func is-pass<-permission)
  vx_core::Type_boolean f_is_pass_from_permission(vx_core::Type_permission permission, vx_core::Type_context context);

  // (func last<-list)
  template <class T, class X> std::shared_ptr<T> f_last_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values);

  // (func length<-list)
  vx_core::Type_int f_length_from_list(vx_core::Type_list values);

  // (func let)
  template <class T> std::shared_ptr<T> f_let(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any);

  // (func let-async)
  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_let_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any_async);

  // (func list-join<-list)
  template <class X, class Y> std::shared_ptr<X> f_list_join_from_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any);

  // (func list<-list)
  template <class X, class Y> std::shared_ptr<X> f_list_from_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any);

  // (func list<-list-async)
  template <class X, class Y> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> f_list_from_list_async(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any_async fn_any_from_any_async);

  // (func list<-map)
  template <class X, class O> std::shared_ptr<X> f_list_from_map(std::shared_ptr<X> generic_any_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value);

  // (func list<-map-async)
  template <class X, class O> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> f_list_from_map_async(std::shared_ptr<X> generic_any_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value_async fn_any_from_key_value_async);

  // (func list<-type)
  vx_core::Type_any f_list_from_type(vx_core::Type_any type);

  // (func log)
  vx_core::Type_any f_log(vx_core::Type_any value);

  // (func map<-list)
  template <class Y, class N> std::shared_ptr<N> f_map_from_list(std::shared_ptr<N> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_any_from_any);

  // (func mempool-addref)
  void f_mempool_addref(vx_core::Type_anylist values);

  // (func mempool-release)
  void f_mempool_release(vx_core::Type_value value);

  // (func mempool-removeref)
  void f_mempool_removeref(vx_core::Type_anylist values);

  // (func mempool-removerefchildren)
  void f_mempool_removerefchildren(vx_core::Type_anylist values);

  // (func mempool-reserve)
  vx_core::Type_value f_mempool_reserve();

  // (func msg<-error)
  vx_core::Type_msg f_msg_from_error(vx_core::Type_string error);

  // (func msgblock<-msgblock-msg)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg);

  // (func msgblock<-msgblock-msgblock)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock);

  // (func name<-typedef)
  vx_core::Type_string f_name_from_typedef(vx_core::Type_typedef vtypedef);

  // (func native)
  template <class T> std::shared_ptr<T> f_native(std::shared_ptr<T> generic_any_1, vx_core::Type_anylist clauses);

  // (func native<-any)
  vx_core::Type_any f_native_from_any(vx_core::Type_any value);

  // (func new)
  template <class T> std::shared_ptr<T> f_new(std::shared_ptr<T> type, vx_core::Type_anylist values);

  // (func number<-func)
  vx_core::Type_number f_number_from_func();

  // (func or)
  vx_core::Type_boolean f_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2);

  // (func or)
  vx_core::Type_boolean f_or_1(vx_core::Type_booleanlist values);

  // (func packagename<-typedef)
  vx_core::Type_string f_packagename_from_typedef(vx_core::Type_typedef vtypedef);

  // (func path<-context-path)
  vx_core::Type_string f_path_from_context_path(vx_core::Type_string path, vx_core::Type_context context);

  // (func path<-setting-path)
  vx_core::Type_string f_path_from_setting_path(vx_core::Type_setting session, vx_core::Type_string path);

  // (func permission<-id-context)
  vx_core::Type_permission f_permission_from_id_context(vx_core::Type_string id, vx_core::Type_context context);

  // (func properties<-typedef)
  vx_core::Type_argmap f_properties_from_typedef(vx_core::Type_typedef vtypedef);

  // (func proplast<-typedef)
  vx_core::Type_arg f_proplast_from_typedef(vx_core::Type_typedef vtypedef);

  // (func resolve)
  template <class T> std::shared_ptr<T> f_resolve(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value);

  // (func resolve)
  template <class T> std::shared_ptr<T> f_resolve_1(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any);

  // (func resolve-async)
  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_resolve_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any);

  // (func resolve-first)
  template <class T, class X> std::shared_ptr<T> f_resolve_first(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> clauses);

  // (func resolve-list)
  template <class X> std::shared_ptr<X> f_resolve_list(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> clauses);

  // (func session<-context)
  vx_core::Type_session f_session_from_context(vx_core::Type_context context);

  // (func setting<-context)
  vx_core::Type_setting f_setting_from_context(vx_core::Type_context context);

  // (func string-repeat)
  vx_core::Type_string f_string_repeat(vx_core::Type_string text, vx_core::Type_int repeat);

  // (func string<-any)
  vx_core::Type_string f_string_from_any(vx_core::Type_any value);

  // (func string<-any-indent)
  vx_core::Type_string f_string_from_any_indent(vx_core::Type_any value, vx_core::Type_int indent, vx_core::Type_boolean linefeed);

  // (func string<-func)
  vx_core::Type_string f_string_from_func();

  // (func switch)
  template <class T, class U> std::shared_ptr<T> f_switch(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> val, vx_core::Type_thenelselist thenelselist);

  // (func then)
  vx_core::Type_thenelse f_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any);

  // (func traits<-typedef)
  vx_core::Type_typelist f_traits_from_typedef(vx_core::Type_typedef vtypedef);

  // (func type<-any)
  vx_core::Type_any f_type_from_any(vx_core::Type_any value);

  // (func typedef<-any)
  vx_core::Type_typedef f_typedef_from_any(vx_core::Type_any val);

  // (func typedef<-type)
  vx_core::Type_typedef f_typedef_from_type(vx_core::Type_any val);

  // (func typename<-any)
  vx_core::Type_string f_typename_from_any(vx_core::Type_any value);

  // (func typename<-type)
  vx_core::Type_string f_typename_from_type(vx_core::Type_any type);

  // (func typename<-typedef)
  vx_core::Type_string f_typename_from_typedef(vx_core::Type_typedef vtypedef);

  // (func typenames<-typelist)
  vx_core::Type_stringlist f_typenames_from_typelist(vx_core::Type_typelist typelist);

  // (func user<-context)
  vx_core::Type_user f_user_from_context(vx_core::Type_context context);

}
