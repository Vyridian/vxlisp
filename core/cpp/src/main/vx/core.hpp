#ifndef VX_CORE_HPP
#define VX_CORE_HPP
#include <exception>
#include <functional>
#include <future>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace vx_core {

  // forward declarations
  class Abstract_any;
  typedef Abstract_any* Type_any;
  extern Type_any e_any;
  extern Type_any t_any;
  class Abstract_any_async_from_func;
  typedef Abstract_any_async_from_func* Type_any_async_from_func;
  extern Type_any_async_from_func e_any_async_from_func;
  extern Type_any_async_from_func t_any_async_from_func;
  class Abstract_any_from_anylist;
  typedef Abstract_any_from_anylist* Type_any_from_anylist;
  extern Type_any_from_anylist e_any_from_anylist;
  extern Type_any_from_anylist t_any_from_anylist;
  class Abstract_anylist;
  typedef Abstract_anylist* Type_anylist;
  extern Type_anylist e_anylist;
  extern Type_anylist t_anylist;
  class Abstract_anytype;
  typedef Abstract_anytype* Type_anytype;
  extern Type_anytype e_anytype;
  extern Type_anytype t_anytype;
  class Abstract_arg;
  typedef Abstract_arg* Type_arg;
  extern Type_arg e_arg;
  extern Type_arg t_arg;
  class Abstract_arglist;
  typedef Abstract_arglist* Type_arglist;
  extern Type_arglist e_arglist;
  extern Type_arglist t_arglist;
  class Abstract_argmap;
  typedef Abstract_argmap* Type_argmap;
  extern Type_argmap e_argmap;
  extern Type_argmap t_argmap;
  class Abstract_boolean;
  typedef Abstract_boolean* Type_boolean;
  extern Type_boolean e_boolean;
  extern Type_boolean t_boolean;
  class Abstract_booleanlist;
  typedef Abstract_booleanlist* Type_booleanlist;
  extern Type_booleanlist e_booleanlist;
  extern Type_booleanlist t_booleanlist;
  class Abstract_collection;
  typedef Abstract_collection* Type_collection;
  extern Type_collection e_collection;
  extern Type_collection t_collection;
  class Abstract_compilelanguages;
  typedef Abstract_compilelanguages* Type_compilelanguages;
  extern Type_compilelanguages e_compilelanguages;
  extern Type_compilelanguages t_compilelanguages;
  class Abstract_connect;
  typedef Abstract_connect* Type_connect;
  extern Type_connect e_connect;
  extern Type_connect t_connect;
  class Abstract_connectlist;
  typedef Abstract_connectlist* Type_connectlist;
  extern Type_connectlist e_connectlist;
  extern Type_connectlist t_connectlist;
  class Abstract_connectmap;
  typedef Abstract_connectmap* Type_connectmap;
  extern Type_connectmap e_connectmap;
  extern Type_connectmap t_connectmap;
  class Abstract_const;
  typedef Abstract_const* Type_const;
  extern Type_const e_const;
  extern Type_const t_const;
  class Abstract_constdef;
  typedef Abstract_constdef* Type_constdef;
  extern Type_constdef e_constdef;
  extern Type_constdef t_constdef;
  class Abstract_constlist;
  typedef Abstract_constlist* Type_constlist;
  extern Type_constlist e_constlist;
  extern Type_constlist t_constlist;
  class Abstract_constmap;
  typedef Abstract_constmap* Type_constmap;
  extern Type_constmap e_constmap;
  extern Type_constmap t_constmap;
  class Abstract_context;
  typedef Abstract_context* Type_context;
  extern Type_context e_context;
  extern Type_context t_context;
  class Abstract_decimal;
  typedef Abstract_decimal* Type_decimal;
  extern Type_decimal e_decimal;
  extern Type_decimal t_decimal;
  class Abstract_error;
  typedef Abstract_error* Type_error;
  extern Type_error e_error;
  extern Type_error t_error;
  class Abstract_float;
  typedef Abstract_float* Type_float;
  extern Type_float e_float;
  extern Type_float t_float;
  class Abstract_func;
  typedef Abstract_func* Type_func;
  extern Type_func e_func;
  extern Type_func t_func;
  class Abstract_funcdef;
  typedef Abstract_funcdef* Type_funcdef;
  extern Type_funcdef e_funcdef;
  extern Type_funcdef t_funcdef;
  class Abstract_funclist;
  typedef Abstract_funclist* Type_funclist;
  extern Type_funclist e_funclist;
  extern Type_funclist t_funclist;
  class Abstract_funcmap;
  typedef Abstract_funcmap* Type_funcmap;
  extern Type_funcmap e_funcmap;
  extern Type_funcmap t_funcmap;
  class Abstract_int;
  typedef Abstract_int* Type_int;
  extern Type_int e_int;
  extern Type_int t_int;
  class Abstract_intlist;
  typedef Abstract_intlist* Type_intlist;
  extern Type_intlist e_intlist;
  extern Type_intlist t_intlist;
  class Abstract_intmap;
  typedef Abstract_intmap* Type_intmap;
  extern Type_intmap e_intmap;
  extern Type_intmap t_intmap;
  class Abstract_list;
  typedef Abstract_list* Type_list;
  extern Type_list e_list;
  extern Type_list t_list;
  class Abstract_listtype;
  typedef Abstract_listtype* Type_listtype;
  extern Type_listtype e_listtype;
  extern Type_listtype t_listtype;
  class Abstract_map;
  typedef Abstract_map* Type_map;
  extern Type_map e_map;
  extern Type_map t_map;
  class Abstract_maptype;
  typedef Abstract_maptype* Type_maptype;
  extern Type_maptype e_maptype;
  extern Type_maptype t_maptype;
  class Abstract_mempool;
  typedef Abstract_mempool* Type_mempool;
  extern Type_mempool e_mempool;
  extern Type_mempool t_mempool;
  class Abstract_msg;
  typedef Abstract_msg* Type_msg;
  extern Type_msg e_msg;
  extern Type_msg t_msg;
  class Abstract_msgblock;
  typedef Abstract_msgblock* Type_msgblock;
  extern Type_msgblock e_msgblock;
  extern Type_msgblock t_msgblock;
  class Abstract_msgblocklist;
  typedef Abstract_msgblocklist* Type_msgblocklist;
  extern Type_msgblocklist e_msgblocklist;
  extern Type_msgblocklist t_msgblocklist;
  class Abstract_msglist;
  typedef Abstract_msglist* Type_msglist;
  extern Type_msglist e_msglist;
  extern Type_msglist t_msglist;
  class Abstract_none;
  typedef Abstract_none* Type_none;
  extern Type_none e_none;
  extern Type_none t_none;
  class Abstract_notype;
  typedef Abstract_notype* Type_notype;
  extern Type_notype e_notype;
  extern Type_notype t_notype;
  class Abstract_number;
  typedef Abstract_number* Type_number;
  extern Type_number e_number;
  extern Type_number t_number;
  class Abstract_numberlist;
  typedef Abstract_numberlist* Type_numberlist;
  extern Type_numberlist e_numberlist;
  extern Type_numberlist t_numberlist;
  class Abstract_numbermap;
  typedef Abstract_numbermap* Type_numbermap;
  extern Type_numbermap e_numbermap;
  extern Type_numbermap t_numbermap;
  class Abstract_package;
  typedef Abstract_package* Type_package;
  extern Type_package e_package;
  extern Type_package t_package;
  class Abstract_packagemap;
  typedef Abstract_packagemap* Type_packagemap;
  extern Type_packagemap e_packagemap;
  extern Type_packagemap t_packagemap;
  class Abstract_permission;
  typedef Abstract_permission* Type_permission;
  extern Type_permission e_permission;
  extern Type_permission t_permission;
  class Abstract_permissionlist;
  typedef Abstract_permissionlist* Type_permissionlist;
  extern Type_permissionlist e_permissionlist;
  extern Type_permissionlist t_permissionlist;
  class Abstract_permissionmap;
  typedef Abstract_permissionmap* Type_permissionmap;
  extern Type_permissionmap e_permissionmap;
  extern Type_permissionmap t_permissionmap;
  class Abstract_security;
  typedef Abstract_security* Type_security;
  extern Type_security e_security;
  extern Type_security t_security;
  class Abstract_session;
  typedef Abstract_session* Type_session;
  extern Type_session e_session;
  extern Type_session t_session;
  class Abstract_setting;
  typedef Abstract_setting* Type_setting;
  extern Type_setting e_setting;
  extern Type_setting t_setting;
  class Abstract_state;
  typedef Abstract_state* Type_state;
  extern Type_state e_state;
  extern Type_state t_state;
  class Abstract_statelistener;
  typedef Abstract_statelistener* Type_statelistener;
  extern Type_statelistener e_statelistener;
  extern Type_statelistener t_statelistener;
  class Abstract_string;
  typedef Abstract_string* Type_string;
  extern Type_string e_string;
  extern Type_string t_string;
  class Abstract_stringlist;
  typedef Abstract_stringlist* Type_stringlist;
  extern Type_stringlist e_stringlist;
  extern Type_stringlist t_stringlist;
  class Abstract_stringmap;
  typedef Abstract_stringmap* Type_stringmap;
  extern Type_stringmap e_stringmap;
  extern Type_stringmap t_stringmap;
  class Abstract_struct;
  typedef Abstract_struct* Type_struct;
  extern Type_struct e_struct;
  extern Type_struct t_struct;
  class Abstract_thenelse;
  typedef Abstract_thenelse* Type_thenelse;
  extern Type_thenelse e_thenelse;
  extern Type_thenelse t_thenelse;
  class Abstract_thenelselist;
  typedef Abstract_thenelselist* Type_thenelselist;
  extern Type_thenelselist e_thenelselist;
  extern Type_thenelselist t_thenelselist;
  class Abstract_type;
  typedef Abstract_type* Type_type;
  extern Type_type e_type;
  extern Type_type t_type;
  class Abstract_typedef;
  typedef Abstract_typedef* Type_typedef;
  extern Type_typedef e_typedef;
  extern Type_typedef t_typedef;
  class Abstract_typelist;
  typedef Abstract_typelist* Type_typelist;
  extern Type_typelist e_typelist;
  extern Type_typelist t_typelist;
  class Abstract_typemap;
  typedef Abstract_typemap* Type_typemap;
  extern Type_typemap e_typemap;
  extern Type_typemap t_typemap;
  class Abstract_user;
  typedef Abstract_user* Type_user;
  extern Type_user e_user;
  extern Type_user t_user;
  class Abstract_value;
  typedef Abstract_value* Type_value;
  extern Type_value e_value;
  extern Type_value t_value;
  class Class_false;
  typedef Class_false* Const_false;
  extern Const_false c_false;
  class Class_globalpackagemap;
  typedef Class_globalpackagemap* Const_globalpackagemap;
  extern Const_globalpackagemap c_globalpackagemap;
  class Class_infinity;
  typedef Class_infinity* Const_infinity;
  extern Const_infinity c_infinity;
  class Class_mempool_active;
  typedef Class_mempool_active* Const_mempool_active;
  extern Const_mempool_active c_mempool_active;
  class Class_msg_error;
  typedef Class_msg_error* Const_msg_error;
  extern Const_msg_error c_msg_error;
  class Class_msg_info;
  typedef Class_msg_info* Const_msg_info;
  extern Const_msg_info c_msg_info;
  class Class_msg_severe;
  typedef Class_msg_severe* Const_msg_severe;
  extern Const_msg_severe c_msg_severe;
  class Class_msg_warning;
  typedef Class_msg_warning* Const_msg_warning;
  extern Const_msg_warning c_msg_warning;
  class Class_neginfinity;
  typedef Class_neginfinity* Const_neginfinity;
  extern Const_neginfinity c_neginfinity;
  class Class_newline;
  typedef Class_newline* Const_newline;
  extern Const_newline c_newline;
  class Class_notanumber;
  typedef Class_notanumber* Const_notanumber;
  extern Const_notanumber c_notanumber;
  class Class_nothing;
  typedef Class_nothing* Const_nothing;
  extern Const_nothing c_nothing;
  class Class_quote;
  typedef Class_quote* Const_quote;
  extern Const_quote c_quote;
  class Class_true;
  typedef Class_true* Const_true;
  extern Const_true c_true;
  class Abstract_not;
  typedef Abstract_not* Func_not;
  extern Func_not e_not;
  extern Func_not t_not;
  class Abstract_notempty;
  typedef Abstract_notempty* Func_notempty;
  extern Func_notempty e_notempty;
  extern Func_notempty t_notempty;
  class Abstract_notempty_1;
  typedef Abstract_notempty_1* Func_notempty_1;
  extern Func_notempty_1 e_notempty_1;
  extern Func_notempty_1 t_notempty_1;
  class Abstract_ne;
  typedef Abstract_ne* Func_ne;
  extern Func_ne e_ne;
  extern Func_ne t_ne;
  class Abstract_neqeq;
  typedef Abstract_neqeq* Func_neqeq;
  extern Func_neqeq e_neqeq;
  extern Func_neqeq t_neqeq;
  class Abstract_multiply;
  typedef Abstract_multiply* Func_multiply;
  extern Func_multiply e_multiply;
  extern Func_multiply t_multiply;
  class Abstract_multiply_1;
  typedef Abstract_multiply_1* Func_multiply_1;
  extern Func_multiply_1 e_multiply_1;
  extern Func_multiply_1 t_multiply_1;
  class Abstract_multiply_2;
  typedef Abstract_multiply_2* Func_multiply_2;
  extern Func_multiply_2 e_multiply_2;
  extern Func_multiply_2 t_multiply_2;
  class Abstract_multiply_3;
  typedef Abstract_multiply_3* Func_multiply_3;
  extern Func_multiply_3 e_multiply_3;
  extern Func_multiply_3 t_multiply_3;
  class Abstract_plus;
  typedef Abstract_plus* Func_plus;
  extern Func_plus e_plus;
  extern Func_plus t_plus;
  class Abstract_plus_1;
  typedef Abstract_plus_1* Func_plus_1;
  extern Func_plus_1 e_plus_1;
  extern Func_plus_1 t_plus_1;
  class Abstract_plus_2;
  typedef Abstract_plus_2* Func_plus_2;
  extern Func_plus_2 e_plus_2;
  extern Func_plus_2 t_plus_2;
  class Abstract_plus_3;
  typedef Abstract_plus_3* Func_plus_3;
  extern Func_plus_3 e_plus_3;
  extern Func_plus_3 t_plus_3;
  class Abstract_plus1;
  typedef Abstract_plus1* Func_plus1;
  extern Func_plus1 e_plus1;
  extern Func_plus1 t_plus1;
  class Abstract_minus;
  typedef Abstract_minus* Func_minus;
  extern Func_minus e_minus;
  extern Func_minus t_minus;
  class Abstract_minus_1;
  typedef Abstract_minus_1* Func_minus_1;
  extern Func_minus_1 e_minus_1;
  extern Func_minus_1 t_minus_1;
  class Abstract_minus_2;
  typedef Abstract_minus_2* Func_minus_2;
  extern Func_minus_2 e_minus_2;
  extern Func_minus_2 t_minus_2;
  class Abstract_minus_3;
  typedef Abstract_minus_3* Func_minus_3;
  extern Func_minus_3 e_minus_3;
  extern Func_minus_3 t_minus_3;
  class Abstract_dotmethod;
  typedef Abstract_dotmethod* Func_dotmethod;
  extern Func_dotmethod e_dotmethod;
  extern Func_dotmethod t_dotmethod;
  class Abstract_divide;
  typedef Abstract_divide* Func_divide;
  extern Func_divide e_divide;
  extern Func_divide t_divide;
  class Abstract_lt;
  typedef Abstract_lt* Func_lt;
  extern Func_lt e_lt;
  extern Func_lt t_lt;
  class Abstract_lt_1;
  typedef Abstract_lt_1* Func_lt_1;
  extern Func_lt_1 e_lt_1;
  extern Func_lt_1 t_lt_1;
  class Abstract_chainfirst;
  typedef Abstract_chainfirst* Func_chainfirst;
  extern Func_chainfirst e_chainfirst;
  extern Func_chainfirst t_chainfirst;
  class Abstract_chainlast;
  typedef Abstract_chainlast* Func_chainlast;
  extern Func_chainlast e_chainlast;
  extern Func_chainlast t_chainlast;
  class Abstract_le;
  typedef Abstract_le* Func_le;
  extern Func_le e_le;
  extern Func_le t_le;
  class Abstract_le_1;
  typedef Abstract_le_1* Func_le_1;
  extern Func_le_1 e_le_1;
  extern Func_le_1 t_le_1;
  class Abstract_eq;
  typedef Abstract_eq* Func_eq;
  extern Func_eq e_eq;
  extern Func_eq t_eq;
  class Abstract_eq_1;
  typedef Abstract_eq_1* Func_eq_1;
  extern Func_eq_1 e_eq_1;
  extern Func_eq_1 t_eq_1;
  class Abstract_eqeq;
  typedef Abstract_eqeq* Func_eqeq;
  extern Func_eqeq e_eqeq;
  extern Func_eqeq t_eqeq;
  class Abstract_gt;
  typedef Abstract_gt* Func_gt;
  extern Func_gt e_gt;
  extern Func_gt t_gt;
  class Abstract_gt_1;
  typedef Abstract_gt_1* Func_gt_1;
  extern Func_gt_1 e_gt_1;
  extern Func_gt_1 t_gt_1;
  class Abstract_ge;
  typedef Abstract_ge* Func_ge;
  extern Func_ge e_ge;
  extern Func_ge t_ge;
  class Abstract_ge_1;
  typedef Abstract_ge_1* Func_ge_1;
  extern Func_ge_1 e_ge_1;
  extern Func_ge_1 t_ge_1;
  class Abstract_allowfuncs_from_security;
  typedef Abstract_allowfuncs_from_security* Func_allowfuncs_from_security;
  extern Func_allowfuncs_from_security e_allowfuncs_from_security;
  extern Func_allowfuncs_from_security t_allowfuncs_from_security;
  class Abstract_allowtypenames_from_typedef;
  typedef Abstract_allowtypenames_from_typedef* Func_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef e_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef t_allowtypenames_from_typedef;
  class Abstract_allowtypes_from_typedef;
  typedef Abstract_allowtypes_from_typedef* Func_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef e_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef t_allowtypes_from_typedef;
  class Abstract_and;
  typedef Abstract_and* Func_and;
  extern Func_and e_and;
  extern Func_and t_and;
  class Abstract_and_1;
  typedef Abstract_and_1* Func_and_1;
  extern Func_and_1 e_and_1;
  extern Func_and_1 t_and_1;
  class Abstract_any_from_any;
  typedef Abstract_any_from_any* Func_any_from_any;
  extern Func_any_from_any e_any_from_any;
  extern Func_any_from_any t_any_from_any;
  class Abstract_any_from_any_async;
  typedef Abstract_any_from_any_async* Func_any_from_any_async;
  extern Func_any_from_any_async e_any_from_any_async;
  extern Func_any_from_any_async t_any_from_any_async;
  class Abstract_any_from_any_context;
  typedef Abstract_any_from_any_context* Func_any_from_any_context;
  extern Func_any_from_any_context e_any_from_any_context;
  extern Func_any_from_any_context t_any_from_any_context;
  class Abstract_any_from_any_context_async;
  typedef Abstract_any_from_any_context_async* Func_any_from_any_context_async;
  extern Func_any_from_any_context_async e_any_from_any_context_async;
  extern Func_any_from_any_context_async t_any_from_any_context_async;
  class Abstract_any_from_func;
  typedef Abstract_any_from_func* Func_any_from_func;
  extern Func_any_from_func e_any_from_func;
  extern Func_any_from_func t_any_from_func;
  class Abstract_any_from_func_async;
  typedef Abstract_any_from_func_async* Func_any_from_func_async;
  extern Func_any_from_func_async e_any_from_func_async;
  extern Func_any_from_func_async t_any_from_func_async;
  class Abstract_any_from_int;
  typedef Abstract_any_from_int* Func_any_from_int;
  extern Func_any_from_int e_any_from_int;
  extern Func_any_from_int t_any_from_int;
  class Abstract_any_from_key_value;
  typedef Abstract_any_from_key_value* Func_any_from_key_value;
  extern Func_any_from_key_value e_any_from_key_value;
  extern Func_any_from_key_value t_any_from_key_value;
  class Abstract_any_from_key_value_async;
  typedef Abstract_any_from_key_value_async* Func_any_from_key_value_async;
  extern Func_any_from_key_value_async e_any_from_key_value_async;
  extern Func_any_from_key_value_async t_any_from_key_value_async;
  class Abstract_any_from_list;
  typedef Abstract_any_from_list* Func_any_from_list;
  extern Func_any_from_list e_any_from_list;
  extern Func_any_from_list t_any_from_list;
  class Abstract_any_from_list_reduce;
  typedef Abstract_any_from_list_reduce* Func_any_from_list_reduce;
  extern Func_any_from_list_reduce e_any_from_list_reduce;
  extern Func_any_from_list_reduce t_any_from_list_reduce;
  class Abstract_any_from_list_reduce_next;
  typedef Abstract_any_from_list_reduce_next* Func_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next e_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next t_any_from_list_reduce_next;
  class Abstract_any_from_map;
  typedef Abstract_any_from_map* Func_any_from_map;
  extern Func_any_from_map e_any_from_map;
  extern Func_any_from_map t_any_from_map;
  class Abstract_any_from_none;
  typedef Abstract_any_from_none* Func_any_from_none;
  extern Func_any_from_none e_any_from_none;
  extern Func_any_from_none t_any_from_none;
  class Abstract_any_from_none_async;
  typedef Abstract_any_from_none_async* Func_any_from_none_async;
  extern Func_any_from_none_async e_any_from_none_async;
  extern Func_any_from_none_async t_any_from_none_async;
  class Abstract_any_from_reduce;
  typedef Abstract_any_from_reduce* Func_any_from_reduce;
  extern Func_any_from_reduce e_any_from_reduce;
  extern Func_any_from_reduce t_any_from_reduce;
  class Abstract_any_from_reduce_async;
  typedef Abstract_any_from_reduce_async* Func_any_from_reduce_async;
  extern Func_any_from_reduce_async e_any_from_reduce_async;
  extern Func_any_from_reduce_async t_any_from_reduce_async;
  class Abstract_any_from_reduce_next;
  typedef Abstract_any_from_reduce_next* Func_any_from_reduce_next;
  extern Func_any_from_reduce_next e_any_from_reduce_next;
  extern Func_any_from_reduce_next t_any_from_reduce_next;
  class Abstract_any_from_reduce_next_async;
  typedef Abstract_any_from_reduce_next_async* Func_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async e_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async t_any_from_reduce_next_async;
  class Abstract_any_from_struct;
  typedef Abstract_any_from_struct* Func_any_from_struct;
  extern Func_any_from_struct e_any_from_struct;
  extern Func_any_from_struct t_any_from_struct;
  class Abstract_async;
  typedef Abstract_async* Func_async;
  extern Func_async e_async;
  extern Func_async t_async;
  class Abstract_boolean_permission_from_func;
  typedef Abstract_boolean_permission_from_func* Func_boolean_permission_from_func;
  extern Func_boolean_permission_from_func e_boolean_permission_from_func;
  extern Func_boolean_permission_from_func t_boolean_permission_from_func;
  class Abstract_boolean_from_any;
  typedef Abstract_boolean_from_any* Func_boolean_from_any;
  extern Func_boolean_from_any e_boolean_from_any;
  extern Func_boolean_from_any t_boolean_from_any;
  class Abstract_boolean_from_func;
  typedef Abstract_boolean_from_func* Func_boolean_from_func;
  extern Func_boolean_from_func e_boolean_from_func;
  extern Func_boolean_from_func t_boolean_from_func;
  class Abstract_boolean_from_none;
  typedef Abstract_boolean_from_none* Func_boolean_from_none;
  extern Func_boolean_from_none e_boolean_from_none;
  extern Func_boolean_from_none t_boolean_from_none;
  class Abstract_case;
  typedef Abstract_case* Func_case;
  extern Func_case e_case;
  extern Func_case t_case;
  class Abstract_case_1;
  typedef Abstract_case_1* Func_case_1;
  extern Func_case_1 e_case_1;
  extern Func_case_1 t_case_1;
  class Abstract_compare;
  typedef Abstract_compare* Func_compare;
  extern Func_compare e_compare;
  extern Func_compare t_compare;
  class Abstract_contains;
  typedef Abstract_contains* Func_contains;
  extern Func_contains e_contains;
  extern Func_contains t_contains;
  class Abstract_contains_1;
  typedef Abstract_contains_1* Func_contains_1;
  extern Func_contains_1 e_contains_1;
  extern Func_contains_1 t_contains_1;
  class Abstract_context_main;
  typedef Abstract_context_main* Func_context_main;
  extern Func_context_main e_context_main;
  extern Func_context_main t_context_main;
  class Abstract_copy;
  typedef Abstract_copy* Func_copy;
  extern Func_copy e_copy;
  extern Func_copy t_copy;
  class Abstract_else;
  typedef Abstract_else* Func_else;
  extern Func_else e_else;
  extern Func_else t_else;
  class Abstract_empty;
  typedef Abstract_empty* Func_empty;
  extern Func_empty e_empty;
  extern Func_empty t_empty;
  class Abstract_extends_from_any;
  typedef Abstract_extends_from_any* Func_extends_from_any;
  extern Func_extends_from_any e_extends_from_any;
  extern Func_extends_from_any t_extends_from_any;
  class Abstract_extends_from_typedef;
  typedef Abstract_extends_from_typedef* Func_extends_from_typedef;
  extern Func_extends_from_typedef e_extends_from_typedef;
  extern Func_extends_from_typedef t_extends_from_typedef;
  class Abstract_first_from_list;
  typedef Abstract_first_from_list* Func_first_from_list;
  extern Func_first_from_list e_first_from_list;
  extern Func_first_from_list t_first_from_list;
  class Abstract_first_from_list_fn_any_from_any;
  typedef Abstract_first_from_list_fn_any_from_any* Func_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any e_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any t_first_from_list_fn_any_from_any;
  class Abstract_fn;
  typedef Abstract_fn* Func_fn;
  extern Func_fn e_fn;
  extern Func_fn t_fn;
  class Abstract_funcdef_from_func;
  typedef Abstract_funcdef_from_func* Func_funcdef_from_func;
  extern Func_funcdef_from_func e_funcdef_from_func;
  extern Func_funcdef_from_func t_funcdef_from_func;
  class Abstract_funcname_from_funcdef;
  typedef Abstract_funcname_from_funcdef* Func_funcname_from_funcdef;
  extern Func_funcname_from_funcdef e_funcname_from_funcdef;
  extern Func_funcname_from_funcdef t_funcname_from_funcdef;
  class Abstract_global_package_get;
  typedef Abstract_global_package_get* Func_global_package_get;
  extern Func_global_package_get e_global_package_get;
  extern Func_global_package_get t_global_package_get;
  class Abstract_global_package_set;
  typedef Abstract_global_package_set* Func_global_package_set;
  extern Func_global_package_set e_global_package_set;
  extern Func_global_package_set t_global_package_set;
  class Abstract_if;
  typedef Abstract_if* Func_if;
  extern Func_if e_if;
  extern Func_if t_if;
  class Abstract_if_1;
  typedef Abstract_if_1* Func_if_1;
  extern Func_if_1 e_if_1;
  extern Func_if_1 t_if_1;
  class Abstract_if_2;
  typedef Abstract_if_2* Func_if_2;
  extern Func_if_2 e_if_2;
  extern Func_if_2 t_if_2;
  class Abstract_int_from_func;
  typedef Abstract_int_from_func* Func_int_from_func;
  extern Func_int_from_func e_int_from_func;
  extern Func_int_from_func t_int_from_func;
  class Abstract_int_from_string;
  typedef Abstract_int_from_string* Func_int_from_string;
  extern Func_int_from_string e_int_from_string;
  extern Func_int_from_string t_int_from_string;
  class Abstract_is_empty;
  typedef Abstract_is_empty* Func_is_empty;
  extern Func_is_empty e_is_empty;
  extern Func_is_empty t_is_empty;
  class Abstract_is_empty_1;
  typedef Abstract_is_empty_1* Func_is_empty_1;
  extern Func_is_empty_1 e_is_empty_1;
  extern Func_is_empty_1 t_is_empty_1;
  class Abstract_is_endswith;
  typedef Abstract_is_endswith* Func_is_endswith;
  extern Func_is_endswith e_is_endswith;
  extern Func_is_endswith t_is_endswith;
  class Abstract_is_func;
  typedef Abstract_is_func* Func_is_func;
  extern Func_is_func e_is_func;
  extern Func_is_func t_is_func;
  class Abstract_is_int;
  typedef Abstract_is_int* Func_is_int;
  extern Func_is_int e_is_int;
  extern Func_is_int t_is_int;
  class Abstract_is_number;
  typedef Abstract_is_number* Func_is_number;
  extern Func_is_number e_is_number;
  extern Func_is_number t_is_number;
  class Abstract_is_pass_from_permission;
  typedef Abstract_is_pass_from_permission* Func_is_pass_from_permission;
  extern Func_is_pass_from_permission e_is_pass_from_permission;
  extern Func_is_pass_from_permission t_is_pass_from_permission;
  class Abstract_last_from_list;
  typedef Abstract_last_from_list* Func_last_from_list;
  extern Func_last_from_list e_last_from_list;
  extern Func_last_from_list t_last_from_list;
  class Abstract_length_from_list;
  typedef Abstract_length_from_list* Func_length_from_list;
  extern Func_length_from_list e_length_from_list;
  extern Func_length_from_list t_length_from_list;
  class Abstract_let;
  typedef Abstract_let* Func_let;
  extern Func_let e_let;
  extern Func_let t_let;
  class Abstract_let_async;
  typedef Abstract_let_async* Func_let_async;
  extern Func_let_async e_let_async;
  extern Func_let_async t_let_async;
  class Abstract_list_join_from_list;
  typedef Abstract_list_join_from_list* Func_list_join_from_list;
  extern Func_list_join_from_list e_list_join_from_list;
  extern Func_list_join_from_list t_list_join_from_list;
  class Abstract_list_from_list;
  typedef Abstract_list_from_list* Func_list_from_list;
  extern Func_list_from_list e_list_from_list;
  extern Func_list_from_list t_list_from_list;
  class Abstract_list_from_list_async;
  typedef Abstract_list_from_list_async* Func_list_from_list_async;
  extern Func_list_from_list_async e_list_from_list_async;
  extern Func_list_from_list_async t_list_from_list_async;
  class Abstract_list_from_map;
  typedef Abstract_list_from_map* Func_list_from_map;
  extern Func_list_from_map e_list_from_map;
  extern Func_list_from_map t_list_from_map;
  class Abstract_list_from_map_async;
  typedef Abstract_list_from_map_async* Func_list_from_map_async;
  extern Func_list_from_map_async e_list_from_map_async;
  extern Func_list_from_map_async t_list_from_map_async;
  class Abstract_list_from_type;
  typedef Abstract_list_from_type* Func_list_from_type;
  extern Func_list_from_type e_list_from_type;
  extern Func_list_from_type t_list_from_type;
  class Abstract_log;
  typedef Abstract_log* Func_log;
  extern Func_log e_log;
  extern Func_log t_log;
  class Abstract_log_1;
  typedef Abstract_log_1* Func_log_1;
  extern Func_log_1 e_log_1;
  extern Func_log_1 t_log_1;
  class Abstract_main;
  typedef Abstract_main* Func_main;
  extern Func_main e_main;
  extern Func_main t_main;
  class Abstract_map_from_list;
  typedef Abstract_map_from_list* Func_map_from_list;
  extern Func_map_from_list e_map_from_list;
  extern Func_map_from_list t_map_from_list;
  class Abstract_mempool_addref;
  typedef Abstract_mempool_addref* Func_mempool_addref;
  extern Func_mempool_addref e_mempool_addref;
  extern Func_mempool_addref t_mempool_addref;
  class Abstract_mempool_release;
  typedef Abstract_mempool_release* Func_mempool_release;
  extern Func_mempool_release e_mempool_release;
  extern Func_mempool_release t_mempool_release;
  class Abstract_mempool_removeref;
  typedef Abstract_mempool_removeref* Func_mempool_removeref;
  extern Func_mempool_removeref e_mempool_removeref;
  extern Func_mempool_removeref t_mempool_removeref;
  class Abstract_mempool_removerefchildren;
  typedef Abstract_mempool_removerefchildren* Func_mempool_removerefchildren;
  extern Func_mempool_removerefchildren e_mempool_removerefchildren;
  extern Func_mempool_removerefchildren t_mempool_removerefchildren;
  class Abstract_mempool_reserve;
  typedef Abstract_mempool_reserve* Func_mempool_reserve;
  extern Func_mempool_reserve e_mempool_reserve;
  extern Func_mempool_reserve t_mempool_reserve;
  class Abstract_msg_from_error;
  typedef Abstract_msg_from_error* Func_msg_from_error;
  extern Func_msg_from_error e_msg_from_error;
  extern Func_msg_from_error t_msg_from_error;
  class Abstract_msg_from_warning;
  typedef Abstract_msg_from_warning* Func_msg_from_warning;
  extern Func_msg_from_warning e_msg_from_warning;
  extern Func_msg_from_warning t_msg_from_warning;
  class Abstract_msgblock_from_msgblock_msg;
  typedef Abstract_msgblock_from_msgblock_msg* Func_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg;
  class Abstract_msgblock_from_msgblock_msgblock;
  typedef Abstract_msgblock_from_msgblock_msgblock* Func_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock;
  class Abstract_name_from_typedef;
  typedef Abstract_name_from_typedef* Func_name_from_typedef;
  extern Func_name_from_typedef e_name_from_typedef;
  extern Func_name_from_typedef t_name_from_typedef;
  class Abstract_native;
  typedef Abstract_native* Func_native;
  extern Func_native e_native;
  extern Func_native t_native;
  class Abstract_native_from_any;
  typedef Abstract_native_from_any* Func_native_from_any;
  extern Func_native_from_any e_native_from_any;
  extern Func_native_from_any t_native_from_any;
  class Abstract_new;
  typedef Abstract_new* Func_new;
  extern Func_new e_new;
  extern Func_new t_new;
  class Abstract_number_from_func;
  typedef Abstract_number_from_func* Func_number_from_func;
  extern Func_number_from_func e_number_from_func;
  extern Func_number_from_func t_number_from_func;
  class Abstract_or;
  typedef Abstract_or* Func_or;
  extern Func_or e_or;
  extern Func_or t_or;
  class Abstract_or_1;
  typedef Abstract_or_1* Func_or_1;
  extern Func_or_1 e_or_1;
  extern Func_or_1 t_or_1;
  class Abstract_packagename_from_typedef;
  typedef Abstract_packagename_from_typedef* Func_packagename_from_typedef;
  extern Func_packagename_from_typedef e_packagename_from_typedef;
  extern Func_packagename_from_typedef t_packagename_from_typedef;
  class Abstract_path_from_context_path;
  typedef Abstract_path_from_context_path* Func_path_from_context_path;
  extern Func_path_from_context_path e_path_from_context_path;
  extern Func_path_from_context_path t_path_from_context_path;
  class Abstract_path_from_setting_path;
  typedef Abstract_path_from_setting_path* Func_path_from_setting_path;
  extern Func_path_from_setting_path e_path_from_setting_path;
  extern Func_path_from_setting_path t_path_from_setting_path;
  class Abstract_permission_from_id_context;
  typedef Abstract_permission_from_id_context* Func_permission_from_id_context;
  extern Func_permission_from_id_context e_permission_from_id_context;
  extern Func_permission_from_id_context t_permission_from_id_context;
  class Abstract_properties_from_typedef;
  typedef Abstract_properties_from_typedef* Func_properties_from_typedef;
  extern Func_properties_from_typedef e_properties_from_typedef;
  extern Func_properties_from_typedef t_properties_from_typedef;
  class Abstract_proplast_from_typedef;
  typedef Abstract_proplast_from_typedef* Func_proplast_from_typedef;
  extern Func_proplast_from_typedef e_proplast_from_typedef;
  extern Func_proplast_from_typedef t_proplast_from_typedef;
  class Abstract_resolve;
  typedef Abstract_resolve* Func_resolve;
  extern Func_resolve e_resolve;
  extern Func_resolve t_resolve;
  class Abstract_resolve_1;
  typedef Abstract_resolve_1* Func_resolve_1;
  extern Func_resolve_1 e_resolve_1;
  extern Func_resolve_1 t_resolve_1;
  class Abstract_resolve_async;
  typedef Abstract_resolve_async* Func_resolve_async;
  extern Func_resolve_async e_resolve_async;
  extern Func_resolve_async t_resolve_async;
  class Abstract_resolve_first;
  typedef Abstract_resolve_first* Func_resolve_first;
  extern Func_resolve_first e_resolve_first;
  extern Func_resolve_first t_resolve_first;
  class Abstract_resolve_list;
  typedef Abstract_resolve_list* Func_resolve_list;
  extern Func_resolve_list e_resolve_list;
  extern Func_resolve_list t_resolve_list;
  class Abstract_security_from_context;
  typedef Abstract_security_from_context* Func_security_from_context;
  extern Func_security_from_context e_security_from_context;
  extern Func_security_from_context t_security_from_context;
  class Abstract_security_from_user;
  typedef Abstract_security_from_user* Func_security_from_user;
  extern Func_security_from_user e_security_from_user;
  extern Func_security_from_user t_security_from_user;
  class Abstract_session_from_context;
  typedef Abstract_session_from_context* Func_session_from_context;
  extern Func_session_from_context e_session_from_context;
  extern Func_session_from_context t_session_from_context;
  class Abstract_setting_from_context;
  typedef Abstract_setting_from_context* Func_setting_from_context;
  extern Func_setting_from_context e_setting_from_context;
  extern Func_setting_from_context t_setting_from_context;
  class Abstract_string_repeat;
  typedef Abstract_string_repeat* Func_string_repeat;
  extern Func_string_repeat e_string_repeat;
  extern Func_string_repeat t_string_repeat;
  class Abstract_string_from_any;
  typedef Abstract_string_from_any* Func_string_from_any;
  extern Func_string_from_any e_string_from_any;
  extern Func_string_from_any t_string_from_any;
  class Abstract_string_from_any_indent;
  typedef Abstract_string_from_any_indent* Func_string_from_any_indent;
  extern Func_string_from_any_indent e_string_from_any_indent;
  extern Func_string_from_any_indent t_string_from_any_indent;
  class Abstract_string_from_func;
  typedef Abstract_string_from_func* Func_string_from_func;
  extern Func_string_from_func e_string_from_func;
  extern Func_string_from_func t_string_from_func;
  class Abstract_switch;
  typedef Abstract_switch* Func_switch;
  extern Func_switch e_switch;
  extern Func_switch t_switch;
  class Abstract_then;
  typedef Abstract_then* Func_then;
  extern Func_then e_then;
  extern Func_then t_then;
  class Abstract_traits_from_typedef;
  typedef Abstract_traits_from_typedef* Func_traits_from_typedef;
  extern Func_traits_from_typedef e_traits_from_typedef;
  extern Func_traits_from_typedef t_traits_from_typedef;
  class Abstract_type_from_any;
  typedef Abstract_type_from_any* Func_type_from_any;
  extern Func_type_from_any e_type_from_any;
  extern Func_type_from_any t_type_from_any;
  class Abstract_typedef_from_any;
  typedef Abstract_typedef_from_any* Func_typedef_from_any;
  extern Func_typedef_from_any e_typedef_from_any;
  extern Func_typedef_from_any t_typedef_from_any;
  class Abstract_typedef_from_type;
  typedef Abstract_typedef_from_type* Func_typedef_from_type;
  extern Func_typedef_from_type e_typedef_from_type;
  extern Func_typedef_from_type t_typedef_from_type;
  class Abstract_typename_from_any;
  typedef Abstract_typename_from_any* Func_typename_from_any;
  extern Func_typename_from_any e_typename_from_any;
  extern Func_typename_from_any t_typename_from_any;
  class Abstract_typename_from_type;
  typedef Abstract_typename_from_type* Func_typename_from_type;
  extern Func_typename_from_type e_typename_from_type;
  extern Func_typename_from_type t_typename_from_type;
  class Abstract_typename_from_typedef;
  typedef Abstract_typename_from_typedef* Func_typename_from_typedef;
  extern Func_typename_from_typedef e_typename_from_typedef;
  extern Func_typename_from_typedef t_typename_from_typedef;
  class Abstract_typenames_from_typelist;
  typedef Abstract_typenames_from_typelist* Func_typenames_from_typelist;
  extern Func_typenames_from_typelist e_typenames_from_typelist;
  extern Func_typenames_from_typelist t_typenames_from_typelist;
  class Abstract_user_from_context;
  typedef Abstract_user_from_context* Func_user_from_context;
  extern Func_user_from_context e_user_from_context;
  extern Func_user_from_context t_user_from_context;// :headerfirst

// :header

  extern long refcount;

  typedef std::vector<vx_core::Type_any> vx_Type_listany;
  typedef std::map<std::string, vx_core::Type_any> vx_Type_mapany;
  typedef std::map<std::string, vx_core::Type_func> vx_Type_mapfunc;

  typedef std::initializer_list<Type_any> vx_Type_listarg;

  extern vx_Type_listany emptylistany;
  extern vx_Type_mapany emptymapany;

  typedef std::future<vx_core::Type_any>* vx_Type_future;
  typedef std::function<vx_core::Type_any(vx_core::Type_any)> vx_Type_fn_any_from_any;

  // class vx_Abstract_package
  class vx_Abstract_package {
  public:
    virtual vx_core::vx_Type_mapany maptype() = 0;
    virtual vx_core::vx_Type_mapany mapconst() = 0;
    virtual vx_core::vx_Type_mapfunc mapfunc() = 0;
  };

  // class vx_Class_async
  class vx_Class_async {
  public:
    vx_Class_async() {
      vx_core::refcount += 1;
    }
    ~vx_Class_async() {
      vx_core::refcount -= 1;
      vx_dispose();
    }
    long vx_p_iref = 0;
    vx_core::Type_any type = NULL;
    vx_core::Type_any value = NULL;
    vx_core::vx_Type_future future = NULL;
    vx_core::vx_Class_async* async_parent = NULL;
    std::vector<vx_core::vx_Class_async*> listasync;
    std::map<std::string, vx_core::vx_Class_async*> mapasync;
    vx_core::vx_Type_fn_any_from_any fn = NULL;
    vx_core::vx_Type_listany lambdavars;
    void vx_dispose();
    vx_core::Type_any sync_value();
  };

  typedef vx_Class_async* vx_Type_async;
  typedef std::vector<vx_Type_async> vx_Type_listasync;
  typedef std::map<std::string, vx_Type_async> vx_Type_mapasync;
  typedef std::function<vx_core::vx_Type_async(vx_core::Type_any)> vx_Type_fn_async_from_any;

  // vx_any_from_list_result_next(generic_any_1, list, any<-reduce-next)
  vx_core::Type_any vx_any_from_list_result_next(vx_core::Type_any generic_any_1, vx_core::Type_list list, vx_core::Type_any valstart, vx_core::Func_any_from_reduce_next fn_reduce_next);

  // vx_anylist_from_arraystring(long, array<string>)
  vx_core::Type_anylist vx_anylist_from_arraystring(long ilen, char* arraystring[]);

  // vx_argmap_from_listarg(List<arg>)
  vx_core::Type_argmap vx_argmap_from_listarg(std::initializer_list<vx_core::Type_arg> listarg);

  // vx_async_from_async_fn(async, type, fn<any>(any))
  vx_core::vx_Type_async vx_async_from_async_fn(vx_core::vx_Type_async async, vx_core::Type_any type, vx_core::vx_Type_listany lambavars, vx_core::vx_Type_fn_any_from_any fn);

  // vx_async_new_from_future(T, future<T>)
  vx_core::vx_Type_async vx_async_new_from_future(vx_core::Type_any generic_any_1, vx_core::vx_Type_future future);

  // vx_async_new_from_listasync(T, List<async>)
  vx_core::vx_Type_async vx_async_new_from_listasync(vx_core::Type_any generic_list_1, vx_core::vx_Type_listasync listasync);

  // vx_async_new_from_value(any)
  vx_core::vx_Type_async vx_async_new_from_value(vx_core::Type_any value);

  // vx_boolean_from_string_ends(string, string)
  bool vx_boolean_from_string_ends(std::string text, std::string ends);

  // vx_boolean_from_string_find(string, string)
  bool vx_boolean_from_string_find(std::string text, std::string find);

  // vx_boolean_from_string_starts(string, string)
  bool vx_boolean_from_string_starts(std::string text, std::string starts);

  // vx_boolean_from_type_trait(type, type)
  bool vx_boolean_from_type_trait(vx_core::Type_any type, vx_core::Type_any trait);

  // vx_compare(any, any)
  long vx_compare(vx_core::Type_any val1, vx_core::Type_any val2);

  // vx_eqeq(any, any)
  bool vx_eqeq(vx_core::Type_any val1, vx_core::Type_any val2);

  // vx_float_from_number(number)
  float vx_float_from_number(vx_core::Type_number num);

  // vx_float_from_string(string)
  float vx_float_from_string(std::string text);

  // vx_funclist_from_listfunc(List<func>)
  vx_core::Type_funclist vx_funclist_from_listfunc(std::initializer_list<vx_core::Type_func> listfunc);

  // vx_if_thenelselist(type, thenelselist)
  vx_core::Type_any vx_if_thenelselist(vx_core::Type_any generic_any_1, vx_core::Type_thenelselist thenelselist);

  // vx_int_from_sizet(size_t)
  long vx_int_from_sizet(std::size_t size);

  // vx_int_from_string(string)
  int vx_int_from_string(std::string text);

  // vx_is_float(string)
  bool vx_is_float(std::string value);

  // vx_is_int(string)
  bool vx_is_int(std::string value);

  // vx_is_int(any)
  bool vx_is_int(vx_core::Type_any value);

  // vx_list_from_array(arrayval)
  vx_core::vx_Type_listany vx_list_from_array(vx_core::vx_Type_listarg vals);

  // vx_list_from_map_fn(generic_list_1, map, fn-any<-key-value)
  vx_core::Type_any vx_list_from_map_fn(vx_core::Type_any generic_list_1, vx_core::Type_map valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value);

  // vx_list_join_from_list_fn(generic_list_1, list, fn-any<-any)
  vx_core::Type_any vx_list_join_from_list_fn(vx_core::Type_any generic_list_1, vx_core::Type_list values, vx_core::Func_any_from_any fn_any_from_any);

  // vx_listany_from_listany_fn(List<any>, (Function (any) : any))
  vx_core::vx_Type_listany vx_listany_from_listany_fn(vx_core::vx_Type_listany list_any, vx_core::vx_Type_fn_any_from_any fn);

  // vx_listasync_from_listany_fn(List<any>, (Function (any) : any))
  vx_core::vx_Type_listasync vx_listasync_from_listany_fn(vx_core::vx_Type_listany list_any, vx_core::vx_Type_fn_async_from_any fn);

  // vx_liststring_from_arraystring(long, array<string>)
  std::vector<std::string> vx_liststring_from_arraystring(long ilen, char* arraystring[]);

  // vx_log()
  void vx_log();

  // vx_log(int)
  void vx_log(long ival);

  // vx_log(text)
  void vx_log(std::string sval);

  // vx_log(any)
  void vx_log(vx_core::Type_any val);

  // vx_log(async)
  void vx_log(vx_core::vx_Type_async async);

  // vx_log(list<any>)
  void vx_log(vx_core::vx_Type_listany listany);

  // vx_log(string, string)
  void vx_log(std::string code, std::string text);

  // vx_log(string, any)
  void vx_log(std::string code, vx_core::Type_any val);

  // vx_log(string, async)
  void vx_log(std::string code, vx_core::vx_Type_async async);

  // vx_map_from_list(listany, any<-any)
  vx_core::vx_Type_mapany vx_map_from_list(vx_core::vx_Type_listany listany, vx_core::Func_any_from_any fn_any_from_any);

  // vx_memory_leak_test()
  bool vx_memory_leak_test();

  // vx_memory_leak_test(string, int)
  bool vx_memory_leak_test(std::string id, long initialcount);

  // vx_memory_leak_test(string, int, int)
  bool vx_memory_leak_test(std::string id, long initialcount, long expectedcount);

  // vx_msg_from_errortext(string)
  vx_core::Type_msg vx_msg_from_errortext(const std::string errortext);

  // vx_msg_from_exception(string, exception)
  vx_core::Type_msg vx_msg_from_exception(const std::string text, std::exception err);

  // vx_msgblock_from_copy_listval(msgblock, List<any>)
  vx_core::Type_msgblock vx_msgblock_from_copy_listval(vx_core::Type_msgblock msgblock, vx_core::vx_Type_listany vals);

  // vx_new_arg(string, type)
  vx_core::Type_arg vx_new_arg(std::string name, vx_core::Type_any type);

  // vx_new_boolean(boolean)
  vx_core::Type_boolean vx_new_boolean(bool isval);

  // vx_new_decimal_from_float(float)
  vx_core::Type_decimal vx_new_decimal_from_float(float fval);

  // vx_new_decimal_from_string(string)
  vx_core::Type_decimal vx_new_decimal_from_string(std::string sval);

  // vx_new_float(float)
  vx_core::Type_float vx_new_float(float fval);

  // vx_new_int(long)
  vx_core::Type_int vx_new_int(long ival);

  // vx_new_string(string)
  vx_core::Type_string vx_new_string(std::string text);

  // vx_ref(any)
  long vx_ref(vx_core::Type_any any);

  // vx_ref_minus(any)
  long vx_ref_minus(vx_core::Type_any any);

  // vx_ref_plus(any)
  long vx_ref_plus(vx_core::Type_any any);

  // vx_release(any)
  void vx_release(vx_core::Type_any any);

  // vx_release(any...)
  void vx_release(vx_core::vx_Type_listany listany);

  // vx_release_async(async)
  void vx_release_async(vx_core::vx_Type_async async);

  // vx_release_except(any, except)
  void vx_release_except(vx_core::Type_any any, vx_core::Type_any except);

  // vx_release_except(any..., except)
  void vx_release_except(vx_core::vx_Type_listany listany, vx_core::Type_any except);

  // vx_release_except_async(async, except)
  void vx_release_except_async(vx_core::vx_Type_async async, vx_core::Type_any except);

  // vx_release_one(any)
  void vx_release_one(vx_core::Type_any any);

  // vx_release_one(any...)
  void vx_release_one(vx_core::vx_Type_listany listany);

  // vx_release_one_async(async)
  void vx_release_one_async(vx_core::vx_Type_async async);

  // vx_release_one_async(async...)
  void vx_release_one_async(vx_core::vx_Type_listasync listasync);

  // vx_release_one_except(any, except)
  void vx_release_one_except(vx_core::Type_any any, vx_core::Type_any except);

  // vx_release_one_except(any..., except)
  void vx_release_one_except(vx_core::vx_Type_listany listany, vx_core::Type_any except);

  // vx_release_one_except_async(async, except)
  void vx_release_one_except_async(vx_core::vx_Type_async async, vx_core::Type_any except);

  // vx_release_one_except_async(async..., except)
  void vx_release_one_except_async(vx_core::vx_Type_listasync listasync, vx_core::Type_any except);

  // vx_reserve(any)
  void vx_reserve(vx_core::Type_any any);

  // vx_reserve(any...)
  void vx_reserve(vx_core::vx_Type_listany listany);

  // vx_reserve_async(async)
  void vx_reserve_async(vx_core::vx_Type_async async);

  // vx_reserve_async(listasync)
  void vx_reserve_async(vx_core::vx_Type_listasync listasync);

  // vx_reserve_context(context)
  void vx_reserve_context(vx_core::Type_context context);

  // vx_reserve_empty(any)
  void vx_reserve_empty(vx_core::Type_any any);

  // vx_reserve_type(any)
  void vx_reserve_type(vx_core::Type_any any);

  // vx_string_from_any(value)
  std::string vx_string_from_any(vx_core::Type_any value);

  // vx_string_from_any_indent(any, int, boolean, boolean)
  std::string vx_string_from_any_indent(vx_core::Type_any value, long indent, bool linefeed, bool refcount);

  // vx_string_from_any_refcount(value)
  std::string vx_string_from_any_refcount(vx_core::Type_any value);

  // vx_string_from_async(async)
  std::string vx_string_from_async(vx_core::vx_Type_async async);

  // vx_string_from_async_indent(async, indent, linefeed, refcount)
  std::string vx_string_from_async_indent(vx_core::vx_Type_async async, long indent, bool linefeed, bool refcount);

  // vx_string_from_async_refcount(async)
  std::string vx_string_from_async_refcount(vx_core::vx_Type_async async);

  // vx_string_from_int(long)
  std::string vx_string_from_int(long value);

  // vx_string_from_float(float)
  std::string vx_string_from_float(float value);

  // vx_string_from_liststring_pos(list<string>, long)
  std::string vx_string_from_liststring_pos(std::vector<std::string> liststring, long pos);

  // vx_string_from_string_find_replace(string, string, string)
  std::string vx_string_from_string_find_replace(std::string text, std::string find, std::string replace);

  // vx_string_from_string_find_replacefirst(string, string, string)
  std::string vx_string_from_string_find_replacefirst(std::string text, std::string find, std::string replacefirst);

  // vx_string_from_string_repeat(string, int)
  std::string vx_string_from_string_repeat(std::string text, long repeat);

  // vx_string_from_string_start_end(string, int, int)
  std::string vx_string_from_string_start_end(std::string text, long start, long end);

  // vx_switch(type, val, thenelselist)
  vx_core::Type_any vx_switch(vx_core::Type_any generic_any_1, vx_core::Type_any val, vx_core::Type_thenelselist thenelselist);

  // vx_typelist_from_listany(list<any>)
  vx_core::Type_typelist vx_typelist_from_listany(vx_core::vx_Type_listany listany);

  // vx_any_from_any(T, val)
  template <class T> static T* vx_any_from_any(T* generic_any_1, vx_core::Type_any val) {
    T* output = dynamic_cast<T*>(val);
    return output;
  }

  // vx_any_from_map(T, key, defaultval)
  template <class T> static T* vx_any_from_map(const std::map<std::string, T*> &map, const std::string key, T* defaultval) {
    T* output = defaultval;
    auto iter = map.find(key);
    if (iter != map.end()) {
      output = iter->second;
    }
    return output;
  }

  // vx_boolean_contains_from_set_val(set<T>, val)
  template <class T> static bool vx_boolean_contains_from_set_val(std::set<T> set, T val) {
    const bool output = set.find(val) != set.end();
    return output;
  }

  // vx_copy(T, args)
  template <class T> static T* vx_copy(T* copyval, vx_core::vx_Type_listany vals) {
    T* output;
    vx_core::Type_any val = copyval->vx_copy(copyval, vals);
    output = vx_core::vx_any_from_any(copyval, val);
    return output;
  }

  // vx_copy(T, copyval, args)
  template <class T, class U> static T* vx_copy(T* generic_any_1, U* copyval, vx_core::vx_Type_listany vals) {
    T* output;
    vx_core::Type_any val = copyval->vx_copy(copyval, vals);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_empty(T)
  template <class T> static T* vx_empty(T* generic_any_1) {
    T* output;
    vx_core::Type_any val = generic_any_1->vx_empty();
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_listaddall(list, listadd)
  template <class T> static std::vector<T*> vx_listaddall(std::vector<T*> listtarget, std::vector<T*> listadd) {
    std::vector<T*> list;
    list.insert(list.end(), listtarget.begin(), listtarget.end());
    list.insert(list.end(), listadd.begin(), listadd.end());
    return list;
  }

  // vx_list_from_list(T, list<U>)
  template <class T, class U> static std::vector<T*> vx_list_from_list(T* generic_any_1, std::vector<U*> list) {
    std::vector<T*> output;
    long len = vx_core::vx_int_from_sizet(list.size());
    for (int i = 0; i < len; ++i) {
      U* itemu = list[i];
      T* itemt = static_cast<T*>(itemu);
      output.push_back(itemt);
    }
    return output;
  }

  // vx_map_from_map(T, map<U>)
  template <class T, class U> static std::map<std::string, T*> vx_map_from_map(T* generic_any_1, std::map<std::string, U*> map) {
    std::map<std::string, T*> output;
    for (auto const& [key, itemu] : map) {
      T* itemt = static_cast<T*>(itemu);
      output[key] = itemu;
    }
    return output;
  }

  // vx_new(T, args)
  template <class T> static T* vx_new(T* generic_any_1, vx_core::vx_Type_listany vals) {
    T* output;
    vx_core::Type_any val = generic_any_1->vx_new(vals);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_new_from_list(T, List<any>)
  template <class T> static T* vx_new_from_list(T* generic_any_1, vx_core::vx_Type_listany listval) {
    T* output;
    vx_core::Type_any val = generic_any_1->vx_new(listval);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_new_from_map(T, Map<string, any>)
  template <class T> static T* vx_new_from_map(T* generic_any_1, vx_core::vx_Type_mapany mapval) {
    T* output;
    vx_core::Type_any val = generic_any_1->vx_new_from_map(mapval);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  // vx_sync_from_async(async)
  template <class T> static T* vx_sync_from_async(T* generic_any_1, vx_core::vx_Type_async async) {
    vx_core::Type_any value = async->sync_value();
    vx_core::vx_release_except_async(async, value);
    T* output = vx_core::vx_any_from_any(generic_any_1, value);
    return output;
  }

  // vx_type(T)
  template <class T> static T* vx_type(T* generic_any_1) {
    T* output;
    vx_core::Type_any val = generic_any_1->vx_type();
    output = vx_core::vx_any_from_any(generic_any_1, val);
    return output;
  }

  class Abstract_replfunc {
  public:
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
  };
  typedef Abstract_replfunc* Type_replfunc;
  
  class Abstract_replfunc_async {
  public:
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist);
  };
  typedef Abstract_replfunc_async* Type_replfunc_async;


  // (type any)
  class Abstract_any {
  public:
    Abstract_any() {};
    virtual ~Abstract_any() = 0;
    long vx_p_iref = 0;
    vx_core::Type_msgblock vx_p_msgblock = NULL;
    virtual vx_core::Type_msgblock vx_msgblock() const {return this->vx_p_msgblock;};
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const = 0;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const = 0;
    virtual vx_core::Type_any vx_empty() const = 0;
    virtual vx_core::Type_any vx_type() const = 0;
    virtual vx_core::Type_typedef vx_typedef() const = 0;
    virtual vx_core::vx_Type_listany vx_dispose() = 0;
  };
  class Class_any : public virtual Abstract_any {
  public:
    Class_any();
    virtual ~Class_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type list)
  class Abstract_list : public virtual vx_core::Abstract_any {
  public:
    Abstract_list() {};
    virtual ~Abstract_list() = 0;
    vx_core::vx_Type_listany vx_p_list;
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
  };
  class Class_list : public virtual vx_core::Abstract_list {
  public:
    Class_list();
    virtual ~Class_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
  };

  // (type map)
  class Abstract_map : public virtual vx_core::Abstract_any {
  public:
    Abstract_map() {};
    virtual ~Abstract_map() = 0;
    std::vector<std::string> vx_p_keys;
    vx_core::vx_Type_mapany vx_p_map;
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
  };
  class Class_map : public virtual vx_core::Abstract_map {
  public:
    Class_map();
    virtual ~Class_map() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
  };

  // (type struct)
  class Abstract_struct : public virtual vx_core::Abstract_any {
  public:
    Abstract_struct() {};
    virtual ~Abstract_struct() = 0;
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_struct : public virtual vx_core::Abstract_struct {
  public:
    Class_struct();
    virtual ~Class_struct() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type msg)
  class Abstract_msg : public virtual vx_core::Abstract_struct {
  public:
    Abstract_msg() {};
    virtual ~Abstract_msg() = 0;
    std::exception err;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // code()
    vx_core::Type_string vx_p_code = NULL;
    virtual vx_core::Type_string code() const = 0;
    // severity()
    vx_core::Type_int vx_p_severity = NULL;
    virtual vx_core::Type_int severity() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_msg : public virtual Abstract_msg {
  public:
    Class_msg();
    virtual ~Class_msg() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string code() const override;
    virtual vx_core::Type_int severity() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type msglist)
  class Abstract_msglist : public virtual vx_core::Abstract_list {
  public:
    Abstract_msglist() {};
    virtual ~Abstract_msglist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_msg> vx_p_list;
    // vx_listmsg()
    virtual std::vector<vx_core::Type_msg> vx_listmsg() const = 0;
    // vx_get_msg(index)
    virtual vx_core::Type_msg vx_get_msg(vx_core::Type_int index) const = 0;
  };
  class Class_msglist : public virtual Abstract_msglist {
  public:
    Class_msglist();
    virtual ~Class_msglist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_msg> vx_listmsg() const override;
    virtual vx_core::Type_msg vx_get_msg(vx_core::Type_int index) const override;
  };

  // (type msgblock)
  class Abstract_msgblock : public virtual vx_core::Abstract_struct {
  public:
    Abstract_msgblock() {};
    virtual ~Abstract_msgblock() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // msgs()
    vx_core::Type_msglist vx_p_msgs = NULL;
    virtual vx_core::Type_msglist msgs() const = 0;
    // msgblocks()
    vx_core::Type_msgblocklist vx_p_msgblocks = NULL;
    virtual vx_core::Type_msgblocklist msgblocks() const = 0;
  };
  class Class_msgblock : public virtual Abstract_msgblock {
  public:
    Class_msgblock();
    virtual ~Class_msgblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_msglist msgs() const override;
    virtual vx_core::Type_msgblocklist msgblocks() const override;
  };

  // (type msgblocklist)
  class Abstract_msgblocklist : public virtual vx_core::Abstract_list {
  public:
    Abstract_msgblocklist() {};
    virtual ~Abstract_msgblocklist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_msgblock> vx_p_list;
    // vx_listmsgblock()
    virtual std::vector<vx_core::Type_msgblock> vx_listmsgblock() const = 0;
    // vx_get_msgblock(index)
    virtual vx_core::Type_msgblock vx_get_msgblock(vx_core::Type_int index) const = 0;
  };
  class Class_msgblocklist : public virtual Abstract_msgblocklist {
  public:
    Class_msgblocklist();
    virtual ~Class_msgblocklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_msgblock> vx_listmsgblock() const override;
    virtual vx_core::Type_msgblock vx_get_msgblock(vx_core::Type_int index) const override;
  };

  // (type boolean)
  class Abstract_boolean : public virtual vx_core::Abstract_any {
  public:
    Abstract_boolean() {};
    virtual ~Abstract_boolean() = 0;
    bool vx_p_boolean = false;
    virtual bool vx_boolean() const = 0;
  };
  class Class_boolean : public virtual vx_core::Abstract_boolean {
  public:
    Class_boolean();
    virtual ~Class_boolean() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual bool vx_boolean() const override;
  };

  // (type number)
  class Abstract_number : public virtual vx_core::Abstract_any {
  public:
    Abstract_number() {};
    virtual ~Abstract_number() = 0;
  };
  class Class_number : public virtual Abstract_number {
  public:
    Class_number();
    virtual ~Class_number() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type decimal)
  class Abstract_decimal : public virtual vx_core::Abstract_number {
  public:
    Abstract_decimal() {};
    virtual ~Abstract_decimal() = 0;
    std::string vx_p_decimal = "0.0";
    virtual float vx_float() const = 0;
    virtual std::string vx_string() const = 0;
  };
  class Class_decimal : public virtual vx_core::Abstract_decimal {
  public:
    Class_decimal();
    virtual ~Class_decimal() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual float vx_float() const override;
    virtual std::string vx_string() const override;
  };

  // (type float)
  class Abstract_float : public virtual vx_core::Abstract_number {
  public:
    Abstract_float() {};
    virtual ~Abstract_float() = 0;
    float vx_p_float = 0;
    virtual float vx_float() const = 0;
  };
  class Class_float : public virtual vx_core::Abstract_float {
  public:
    Class_float();
    virtual ~Class_float() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual float vx_float() const override;
  };

  // (type int)
  class Abstract_int : public virtual vx_core::Abstract_number {
  public:
    Abstract_int() {};
    virtual ~Abstract_int() = 0;
    long vx_p_int = 0;
    virtual long vx_int() const = 0;
  };
  class Class_int : public virtual vx_core::Abstract_int {
  public:
    Class_int();
    virtual ~Class_int() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual long vx_int() const override;
  };

  // (type string)
  class Abstract_string : public virtual vx_core::Abstract_any {
  public:
    Abstract_string() {};
    virtual ~Abstract_string() = 0;
    std::string vx_p_string = "";
    virtual std::string vx_string() const = 0;
  };
  class Class_string : public virtual vx_core::Abstract_string {
  public:
    Class_string();
    virtual ~Class_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual std::string vx_string() const override;
  };

  // (type func)
  class Abstract_func : public virtual vx_core::Abstract_any {
  public:
    Abstract_func() {};
    virtual ~Abstract_func() = 0;
    virtual vx_core::Type_funcdef vx_funcdef() const = 0;
  };
  class Class_func : public virtual vx_core::Abstract_func {
  public:
    Class_func();
    virtual ~Class_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
  };

  // (type typedef)
  class Abstract_typedef : public virtual vx_core::Abstract_struct {
  public:
    Abstract_typedef() {};
    virtual ~Abstract_typedef() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // pkgname()
    vx_core::Type_string vx_p_pkgname = NULL;
    virtual vx_core::Type_string pkgname() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // extends()
    vx_core::Type_string vx_p_extend = NULL;
    virtual vx_core::Type_string extend() const = 0;
    // allowfuncs()
    vx_core::Type_funclist vx_p_allowfuncs = NULL;
    virtual vx_core::Type_funclist allowfuncs() const = 0;
    // allowtypes()
    vx_core::Type_typelist vx_p_allowtypes = NULL;
    virtual vx_core::Type_typelist allowtypes() const = 0;
    // allowvalues()
    vx_core::Type_anylist vx_p_allowvalues = NULL;
    virtual vx_core::Type_anylist allowvalues() const = 0;
    // disallowfuncs()
    vx_core::Type_funclist vx_p_disallowfuncs = NULL;
    virtual vx_core::Type_funclist disallowfuncs() const = 0;
    // disallowtypes()
    vx_core::Type_typelist vx_p_disallowtypes = NULL;
    virtual vx_core::Type_typelist disallowtypes() const = 0;
    // disallowvalues()
    vx_core::Type_anylist vx_p_disallowvalues = NULL;
    virtual vx_core::Type_anylist disallowvalues() const = 0;
    // properties()
    vx_core::Type_argmap vx_p_properties = NULL;
    virtual vx_core::Type_argmap properties() const = 0;
    // proplast()
    vx_core::Type_arg vx_p_proplast = NULL;
    virtual vx_core::Type_arg proplast() const = 0;
    // traits()
    vx_core::Type_typelist vx_p_traits = NULL;
    virtual vx_core::Type_typelist traits() const = 0;
  };
  class Class_typedef : public virtual Abstract_typedef {
  public:
    Class_typedef();
    virtual ~Class_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
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
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string pkgname() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_string extend() const override;
    virtual vx_core::Type_funclist allowfuncs() const override;
    virtual vx_core::Type_typelist allowtypes() const override;
    virtual vx_core::Type_anylist allowvalues() const override;
    virtual vx_core::Type_funclist disallowfuncs() const override;
    virtual vx_core::Type_typelist disallowtypes() const override;
    virtual vx_core::Type_anylist disallowvalues() const override;
    virtual vx_core::Type_argmap properties() const override;
    virtual vx_core::Type_arg proplast() const override;
    virtual vx_core::Type_typelist traits() const override;
  };

  // (type funcdef)
  class Abstract_funcdef : public virtual vx_core::Abstract_struct {
  public:
    Abstract_funcdef() {};
    virtual ~Abstract_funcdef() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // pkgname()
    vx_core::Type_string vx_p_pkgname = NULL;
    virtual vx_core::Type_string pkgname() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // idx()
    vx_core::Type_int vx_p_idx = NULL;
    virtual vx_core::Type_int idx() const = 0;
    // type()
    vx_core::Type_any vx_p_type = NULL;
    virtual vx_core::Type_any type() const = 0;
    // async()
    vx_core::Type_boolean vx_p_async = NULL;
    virtual vx_core::Type_boolean async() const = 0;
  };
  class Class_funcdef : public virtual Abstract_funcdef {
  public:
    Class_funcdef();
    virtual ~Class_funcdef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    static vx_core::Type_funcdef vx_funcdef_new(
      std::string pkgname,
      std::string name,
      long idx,
      bool async,
      vx_core::Type_any typ
    );
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string pkgname() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_int idx() const override;
    virtual vx_core::Type_any type() const override;
    virtual vx_core::Type_boolean async() const override;
  };

  // (func any<-any)
  class Abstract_any_from_any : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_any() {};
    virtual ~Abstract_any_from_any() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_any : public virtual Abstract_any_from_any {
  public:
    Class_any_from_any();
    virtual ~Class_any_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-any-async)
  class Abstract_any_from_any_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_any_async() {};
    virtual ~Abstract_any_from_any_async() = 0;
    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any value) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_any_async : public virtual Abstract_any_from_any_async {
  public:
    Class_any_from_any_async();
    virtual ~Class_any_from_any_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any value) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-any-context)
  class Abstract_any_from_any_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_any_context() {};
    virtual ~Abstract_any_from_any_context() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_context)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_any_context : public virtual Abstract_any_from_any_context {
  public:
    Class_any_from_any_context();
    virtual ~Class_any_from_any_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-any-context-async)
  class Abstract_any_from_any_context_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_any_context_async() {};
    virtual ~Abstract_any_from_any_context_async() = 0;
    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_context)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_any_context_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_any value, vx_core::Type_context context) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_any_context_async : public virtual Abstract_any_from_any_context_async {
  public:
    Class_any_from_any_context_async();
    virtual ~Class_any_from_any_context_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_any value, vx_core::Type_context context) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-func)
  class Abstract_any_from_func : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_func() {};
    virtual ~Abstract_any_from_func() = 0;
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_func::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_func() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_func : public virtual Abstract_any_from_func {
  public:
    Class_any_from_func();
    virtual ~Class_any_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_func::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_func() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-func-async)
  class Abstract_any_from_func_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_func_async() {};
    virtual ~Abstract_any_from_func_async() = 0;
    typedef std::function<vx_core::vx_Type_async()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_func_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_func_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_func_async(vx_core::Type_any generic_any_1) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_func_async : public virtual Abstract_any_from_func_async {
  public:
    Class_any_from_func_async();
    virtual ~Class_any_from_func_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_func_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_func_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_func_async(vx_core::Type_any generic_any_1) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-key-value)
  class Abstract_any_from_key_value : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_key_value() {};
    virtual ~Abstract_any_from_key_value() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_string, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_key_value vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_key_value::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_key_value(vx_core::Type_string key, vx_core::Type_any val) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_key_value : public virtual Abstract_any_from_key_value {
  public:
    Class_any_from_key_value();
    virtual ~Class_any_from_key_value() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_key_value vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_key_value::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_key_value(vx_core::Type_string key, vx_core::Type_any val) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-key-value-async)
  class Abstract_any_from_key_value_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_key_value_async() {};
    virtual ~Abstract_any_from_key_value_async() = 0;
    typedef std::function<vx_core::vx_Type_async(vx_core::Type_string, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_key_value_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_key_value_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_key_value_async(vx_core::Type_any generic_any_1, vx_core::Type_string key, vx_core::Type_any val) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_key_value_async : public virtual Abstract_any_from_key_value_async {
  public:
    Class_any_from_key_value_async();
    virtual ~Class_any_from_key_value_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_key_value_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_key_value_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_key_value_async(vx_core::Type_any generic_any_1, vx_core::Type_string key, vx_core::Type_any val) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-list)
  class Abstract_any_from_list : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_list() {};
    virtual ~Abstract_any_from_list() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_list : public virtual Abstract_any_from_list {
  public:
    Class_any_from_list();
    virtual ~Class_any_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-list-reduce)
  class Abstract_any_from_list_reduce : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_list_reduce() {};
    virtual ~Abstract_any_from_list_reduce() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_list, vx_core::Type_any, vx_core::Func_any_from_reduce)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_list_reduce vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_list_reduce::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_list_reduce(vx_core::Type_list list, vx_core::Type_any valstart, vx_core::Func_any_from_reduce fn_reduce) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_list_reduce : public virtual Abstract_any_from_list_reduce {
  public:
    Class_any_from_list_reduce();
    virtual ~Class_any_from_list_reduce() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_list_reduce vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_list_reduce::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_list_reduce(vx_core::Type_list list, vx_core::Type_any valstart, vx_core::Func_any_from_reduce fn_reduce) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-list-reduce-next)
  class Abstract_any_from_list_reduce_next : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_list_reduce_next() {};
    virtual ~Abstract_any_from_list_reduce_next() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_list, vx_core::Type_any, vx_core::Func_any_from_reduce_next)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_list_reduce_next vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_list_reduce_next::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_list_reduce_next(vx_core::Type_list list, vx_core::Type_any valstart, vx_core::Func_any_from_reduce_next fn_reduce_next) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_list_reduce_next : public virtual Abstract_any_from_list_reduce_next {
  public:
    Class_any_from_list_reduce_next();
    virtual ~Class_any_from_list_reduce_next() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_list_reduce_next vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_list_reduce_next::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_list_reduce_next(vx_core::Type_list list, vx_core::Type_any valstart, vx_core::Func_any_from_reduce_next fn_reduce_next) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-map)
  class Abstract_any_from_map : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_map() {};
    virtual ~Abstract_any_from_map() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_map : public virtual Abstract_any_from_map {
  public:
    Class_any_from_map();
    virtual ~Class_any_from_map() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-none)
  class Abstract_any_from_none : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_none() {};
    virtual ~Abstract_any_from_none() = 0;
    typedef std::function<vx_core::Type_any()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_none vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_none::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_none() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_none : public virtual Abstract_any_from_none {
  public:
    Class_any_from_none();
    virtual ~Class_any_from_none() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_none vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_none::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_none() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-none-async)
  class Abstract_any_from_none_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_none_async() {};
    virtual ~Abstract_any_from_none_async() = 0;
    typedef std::function<vx_core::vx_Type_async()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_none_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_none_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_none_async(vx_core::Type_any generic_any_1) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_none_async : public virtual Abstract_any_from_none_async {
  public:
    Class_any_from_none_async();
    virtual ~Class_any_from_none_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_none_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_none_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_none_async(vx_core::Type_any generic_any_1) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-reduce)
  class Abstract_any_from_reduce : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_reduce() {};
    virtual ~Abstract_any_from_reduce() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_reduce vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_reduce(vx_core::Type_any result, vx_core::Type_any item) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_reduce : public virtual Abstract_any_from_reduce {
  public:
    Class_any_from_reduce();
    virtual ~Class_any_from_reduce() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_reduce vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_reduce(vx_core::Type_any result, vx_core::Type_any item) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-reduce-async)
  class Abstract_any_from_reduce_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_reduce_async() {};
    virtual ~Abstract_any_from_reduce_async() = 0;
    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_reduce_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_reduce_async(vx_core::Type_any generic_any_1, vx_core::Type_any result, vx_core::Type_any item) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_reduce_async : public virtual Abstract_any_from_reduce_async {
  public:
    Class_any_from_reduce_async();
    virtual ~Class_any_from_reduce_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_reduce_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_reduce_async(vx_core::Type_any generic_any_1, vx_core::Type_any result, vx_core::Type_any item) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-reduce-next)
  class Abstract_any_from_reduce_next : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_reduce_next() {};
    virtual ~Abstract_any_from_reduce_next() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_reduce_next vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_next::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_reduce_next(vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_reduce_next : public virtual Abstract_any_from_reduce_next {
  public:
    Class_any_from_reduce_next();
    virtual ~Class_any_from_reduce_next() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_reduce_next vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_next::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_reduce_next(vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-reduce-next-async)
  class Abstract_any_from_reduce_next_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_any_from_reduce_next_async() {};
    virtual ~Abstract_any_from_reduce_next_async() = 0;
    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_reduce_next_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_next_async::IFn fn) const = 0;
    virtual vx_core::vx_Type_async vx_any_from_reduce_next_async(vx_core::Type_any generic_any_1, vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_reduce_next_async : public virtual Abstract_any_from_reduce_next_async {
  public:
    Class_any_from_reduce_next_async();
    virtual ~Class_any_from_reduce_next_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_reduce_next_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_reduce_next_async::IFn fn) const;
    virtual vx_core::vx_Type_async vx_any_from_reduce_next_async(vx_core::Type_any generic_any_1, vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-struct)
  class Abstract_any_from_struct : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_struct() {};
    virtual ~Abstract_any_from_struct() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_struct : public virtual Abstract_any_from_struct {
  public:
    Class_any_from_struct();
    virtual ~Class_any_from_struct() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func async)
  class Abstract_async : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_async() {};
    virtual ~Abstract_async() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_async : public virtual Abstract_async {
  public:
    Class_async();
    virtual ~Class_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean<-any)
  class Abstract_boolean_from_any : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_from_any() {};
    virtual ~Abstract_boolean_from_any() = 0;
    typedef std::function<vx_core::Type_boolean(vx_core::Type_any)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_boolean_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_any::IFn fn) const = 0;
    virtual vx_core::Type_boolean vx_boolean_from_any(vx_core::Type_any value) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_from_any : public virtual Abstract_boolean_from_any {
  public:
    Class_boolean_from_any();
    virtual ~Class_boolean_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_boolean_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_any::IFn fn) const;
    virtual vx_core::Type_boolean vx_boolean_from_any(vx_core::Type_any value) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean<-func)
  class Abstract_boolean_from_func : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_from_func() {};
    virtual ~Abstract_boolean_from_func() = 0;
    typedef std::function<vx_core::Type_boolean()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_boolean_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_func::IFn fn) const = 0;
    virtual vx_core::Type_boolean vx_boolean_from_func() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_from_func : public virtual Abstract_boolean_from_func {
  public:
    Class_boolean_from_func();
    virtual ~Class_boolean_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_boolean_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_func::IFn fn) const;
    virtual vx_core::Type_boolean vx_boolean_from_func() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean<-none)
  class Abstract_boolean_from_none : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_from_none() {};
    virtual ~Abstract_boolean_from_none() = 0;
    typedef std::function<vx_core::Type_boolean()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_boolean_from_none vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_func::IFn fn) const = 0;
    virtual vx_core::Type_boolean vx_boolean_from_none() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_from_none : public virtual Abstract_boolean_from_none {
  public:
    Class_boolean_from_none();
    virtual ~Class_boolean_from_none() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_boolean_from_none vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_func::IFn fn) const;
    virtual vx_core::Type_boolean vx_boolean_from_none() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func empty)
  class Abstract_empty : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_empty() {};
    virtual ~Abstract_empty() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_empty : public virtual Abstract_empty {
  public:
    Class_empty();
    virtual ~Class_empty() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func new)
  class Abstract_new : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_new() {};
    virtual ~Abstract_new() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_new : public virtual Abstract_new {
  public:
    Class_new();
    virtual ~Class_new() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func copy)
  class Abstract_copy : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_copy() {};
    virtual ~Abstract_copy() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_copy : public virtual Abstract_copy {
  public:
    Class_copy();
    virtual ~Class_copy() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-empty)
  class Abstract_is_empty : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_empty() {};
    virtual ~Abstract_is_empty() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_empty : public virtual Abstract_is_empty {
  public:
    Class_is_empty();
    virtual ~Class_is_empty() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-empty)
  class Abstract_is_empty_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_empty_1() {};
    virtual ~Abstract_is_empty_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_empty_1 : public virtual Abstract_is_empty_1 {
  public:
    Class_is_empty_1();
    virtual ~Class_is_empty_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func !)
  class Abstract_not : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_not() {};
    virtual ~Abstract_not() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_not : public virtual Abstract_not {
  public:
    Class_not();
    virtual ~Class_not() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func !-empty)
  class Abstract_notempty : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_notempty() {};
    virtual ~Abstract_notempty() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_notempty : public virtual Abstract_notempty {
  public:
    Class_notempty();
    virtual ~Class_notempty() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func !-empty)
  class Abstract_notempty_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_notempty_1() {};
    virtual ~Abstract_notempty_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_notempty_1 : public virtual Abstract_notempty_1 {
  public:
    Class_notempty_1();
    virtual ~Class_notempty_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func =)
  class Abstract_eq : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_eq() {};
    virtual ~Abstract_eq() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_eq : public virtual Abstract_eq {
  public:
    Class_eq();
    virtual ~Class_eq() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func =)
  class Abstract_eq_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_eq_1() {};
    virtual ~Abstract_eq_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_eq_1 : public virtual Abstract_eq_1 {
  public:
    Class_eq_1();
    virtual ~Class_eq_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func !=)
  class Abstract_ne : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ne() {};
    virtual ~Abstract_ne() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ne : public virtual Abstract_ne {
  public:
    Class_ne();
    virtual ~Class_ne() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func then)
  class Abstract_then : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_then() {};
    virtual ~Abstract_then() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_then : public virtual Abstract_then {
  public:
    Class_then();
    virtual ~Class_then() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func else)
  class Abstract_else : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_else() {};
    virtual ~Abstract_else() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_else : public virtual Abstract_else {
  public:
    Class_else();
    virtual ~Class_else() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func if)
  class Abstract_if : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_if() {};
    virtual ~Abstract_if() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_if : public virtual Abstract_if {
  public:
    Class_if();
    virtual ~Class_if() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func if)
  class Abstract_if_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_if_1() {};
    virtual ~Abstract_if_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_if_1 : public virtual Abstract_if_1 {
  public:
    Class_if_1();
    virtual ~Class_if_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func if)
  class Abstract_if_2 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_if_2() {};
    virtual ~Abstract_if_2() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_if_2 : public virtual Abstract_if_2 {
  public:
    Class_if_2();
    virtual ~Class_if_2() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func case)
  class Abstract_case : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_case() {};
    virtual ~Abstract_case() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_case : public virtual Abstract_case {
  public:
    Class_case();
    virtual ~Class_case() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func case)
  class Abstract_case_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_case_1() {};
    virtual ~Abstract_case_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_case_1 : public virtual Abstract_case_1 {
  public:
    Class_case_1();
    virtual ~Class_case_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func switch)
  class Abstract_switch : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_switch() {};
    virtual ~Abstract_switch() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_switch : public virtual Abstract_switch {
  public:
    Class_switch();
    virtual ~Class_switch() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func length<-list)
  class Abstract_length_from_list : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_length_from_list() {};
    virtual ~Abstract_length_from_list() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_length_from_list : public virtual Abstract_length_from_list {
  public:
    Class_length_from_list();
    virtual ~Class_length_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func and)
  class Abstract_and : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_and() {};
    virtual ~Abstract_and() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_and : public virtual Abstract_and {
  public:
    Class_and();
    virtual ~Class_and() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func and)
  class Abstract_and_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_and_1() {};
    virtual ~Abstract_and_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_and_1 : public virtual Abstract_and_1 {
  public:
    Class_and_1();
    virtual ~Class_and_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func or)
  class Abstract_or : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_or() {};
    virtual ~Abstract_or() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_or : public virtual Abstract_or {
  public:
    Class_or();
    virtual ~Class_or() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func or)
  class Abstract_or_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_or_1() {};
    virtual ~Abstract_or_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_or_1 : public virtual Abstract_or_1 {
  public:
    Class_or_1();
    virtual ~Class_or_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func let)
  class Abstract_let : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_let() {};
    virtual ~Abstract_let() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_let : public virtual Abstract_let {
  public:
    Class_let();
    virtual ~Class_let() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func let-async)
  class Abstract_let_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_let_async() {};
    virtual ~Abstract_let_async() = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_let_async : public virtual Abstract_let_async {
  public:
    Class_let_async();
    virtual ~Class_let_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean<-any)
  vx_core::Type_boolean f_boolean_from_any(vx_core::Type_any value);

  // (func boolean<-func)
  vx_core::Type_boolean f_boolean_from_func();

  // (func boolean<-none)
  vx_core::Type_boolean f_boolean_from_none();

  // (func is-empty)
  vx_core::Type_boolean f_is_empty(vx_core::Type_string text);

  // (func is-empty)
  vx_core::Type_boolean f_is_empty_1(vx_core::Type_any value);

  // (func !)
  vx_core::Type_boolean f_not(vx_core::Type_boolean val);

  // (func !-empty)
  vx_core::Type_boolean f_notempty(vx_core::Type_string text);

  // (func !-empty)
  vx_core::Type_boolean f_notempty_1(vx_core::Type_any val);

  // (func =)
  vx_core::Type_boolean f_eq(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func =)
  vx_core::Type_boolean f_eq_1(vx_core::Type_anylist values);

  // (func !=)
  vx_core::Type_boolean f_ne(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func then)
  vx_core::Type_thenelse f_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any);

  // (func else)
  vx_core::Type_thenelse f_else(vx_core::Func_any_from_func fn_any);

  // (func case)
  vx_core::Type_thenelse f_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any);

  // (func case)
  vx_core::Type_thenelse f_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any);

  // (func length<-list)
  vx_core::Type_int f_length_from_list(vx_core::Type_list values);

  // (func and)
  vx_core::Type_boolean f_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2);

  // (func and)
  vx_core::Type_boolean f_and_1(vx_core::Type_booleanlist values);

  // (func or)
  vx_core::Type_boolean f_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2);

  // (func or)
  vx_core::Type_boolean f_or_1(vx_core::Type_booleanlist values);

  // (func !==)
  vx_core::Type_boolean f_neqeq(vx_core::Type_any val1, vx_core::Type_any val2);

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

  // (func <=)
  vx_core::Type_boolean f_le(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func <=)
  vx_core::Type_boolean f_le_1(vx_core::Type_anylist args);

  // (func ==)
  vx_core::Type_boolean f_eqeq(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func >)
  vx_core::Type_boolean f_gt(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func >)
  vx_core::Type_boolean f_gt_1(vx_core::Type_anylist values);

  // (func >=)
  vx_core::Type_boolean f_ge(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func >=)
  vx_core::Type_boolean f_ge_1(vx_core::Type_anylist args);

  // (func allowfuncs<-security)
  vx_core::Type_funclist f_allowfuncs_from_security(vx_core::Type_security security);

  // (func allowtypenames<-typedef)
  vx_core::Type_stringlist f_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef);

  // (func allowtypes<-typedef)
  vx_core::Type_typelist f_allowtypes_from_typedef(vx_core::Type_typedef vtypedef);

  // (func boolean-permission<-func)
  vx_core::Type_boolean f_boolean_permission_from_func(vx_core::Type_func func, vx_core::Type_context context);

  // (func compare)
  vx_core::Type_int f_compare(vx_core::Type_any val1, vx_core::Type_any val2);

  // (func contains)
  vx_core::Type_boolean f_contains(vx_core::Type_string text, vx_core::Type_string find);

  // (func contains)
  vx_core::Type_boolean f_contains_1(vx_core::Type_list values, vx_core::Type_any find);

  // (func context-main)
  vx_core::Type_context f_context_main(vx_core::Type_anylist args);

  // (func extends<-any)
  vx_core::Type_string f_extends_from_any(vx_core::Type_any val);

  // (func extends<-typedef)
  vx_core::Type_string f_extends_from_typedef(vx_core::Type_typedef vtypedef);

  // (func funcdef<-func)
  vx_core::Type_funcdef f_funcdef_from_func(vx_core::Type_func val);

  // (func funcname<-funcdef)
  vx_core::Type_string f_funcname_from_funcdef(vx_core::Type_funcdef funcdef);

  // (func global-package-get)
  vx_core::Type_package f_global_package_get(vx_core::Type_string pkgname);

  // (func global-package-set)
  void f_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg);

  // (func int<-func)
  vx_core::Type_int f_int_from_func();

  // (func int<-string)
  vx_core::Type_int f_int_from_string(vx_core::Type_string val);

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

  // (func list<-type)
  vx_core::Type_any f_list_from_type(vx_core::Type_any type);

  // (func log)
  vx_core::Type_any f_log(vx_core::Type_any value);

  // (func log)
  vx_core::Type_any f_log_1(vx_core::Type_string text, vx_core::Type_any value);

  // (func main)
  vx_core::Type_string f_main(vx_core::Type_anylist args);

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

  // (func msg<-warning)
  vx_core::Type_msg f_msg_from_warning(vx_core::Type_string warning);

  // (func msgblock<-msgblock-msg)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg);

  // (func msgblock<-msgblock-msgblock)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock);

  // (func name<-typedef)
  vx_core::Type_string f_name_from_typedef(vx_core::Type_typedef vtypedef);

  // (func native<-any)
  vx_core::Type_any f_native_from_any(vx_core::Type_any value);

  // (func number<-func)
  vx_core::Type_number f_number_from_func();

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

  // (func security<-context)
  vx_core::Type_security f_security_from_context(vx_core::Type_context context);

  // (func security<-user)
  vx_core::Type_security f_security_from_user(vx_core::Type_user user);

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

  // (type any-async<-func)
  class Abstract_any_async_from_func : public virtual vx_core::Abstract_any {
  public:
    Abstract_any_async_from_func() {};
    virtual ~Abstract_any_async_from_func() = 0;
  };
  class Class_any_async_from_func : public virtual Abstract_any_async_from_func {
  public:
    Class_any_async_from_func();
    virtual ~Class_any_async_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type any<-anylist)
  class Abstract_any_from_anylist : public virtual vx_core::Abstract_list {
  public:
    Abstract_any_from_anylist() {};
    virtual ~Abstract_any_from_anylist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Func_any_from_any> vx_p_list;
    // vx_listany_from_any()
    virtual std::vector<vx_core::Func_any_from_any> vx_listany_from_any() const = 0;
    // vx_get_any_from_any(index)
    virtual vx_core::Func_any_from_any vx_get_any_from_any(vx_core::Type_int index) const = 0;
  };
  class Class_any_from_anylist : public virtual Abstract_any_from_anylist {
  public:
    Class_any_from_anylist();
    virtual ~Class_any_from_anylist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Func_any_from_any> vx_listany_from_any() const override;
    virtual vx_core::Func_any_from_any vx_get_any_from_any(vx_core::Type_int index) const override;
  };

  // (type anylist)
  class Abstract_anylist : public virtual vx_core::Abstract_list {
  public:
    Abstract_anylist() {};
    virtual ~Abstract_anylist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_any> vx_p_list;
  };
  class Class_anylist : public virtual Abstract_anylist {
  public:
    Class_anylist();
    virtual ~Class_anylist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
  };

  // (type anytype)
  class Abstract_anytype : public virtual vx_core::Abstract_any {
  public:
    Abstract_anytype() {};
    virtual ~Abstract_anytype() = 0;
  };
  class Class_anytype : public virtual Abstract_anytype {
  public:
    Class_anytype();
    virtual ~Class_anytype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type arg)
  class Abstract_arg : public virtual vx_core::Abstract_struct {
  public:
    Abstract_arg() {};
    virtual ~Abstract_arg() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // argtype()
    vx_core::Type_type vx_p_argtype = NULL;
    virtual vx_core::Type_type argtype() const = 0;
    // fn-any()
    vx_core::Func_any_from_func vx_p_fn_any = NULL;
    virtual vx_core::Func_any_from_func fn_any() const = 0;
  };
  class Class_arg : public virtual Abstract_arg {
  public:
    Class_arg();
    virtual ~Class_arg() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_type argtype() const override;
    virtual vx_core::Func_any_from_func fn_any() const override;
  };

  // (type arglist)
  class Abstract_arglist : public virtual vx_core::Abstract_list {
  public:
    Abstract_arglist() {};
    virtual ~Abstract_arglist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_arg> vx_p_list;
    // vx_listarg()
    virtual std::vector<vx_core::Type_arg> vx_listarg() const = 0;
    // vx_get_arg(index)
    virtual vx_core::Type_arg vx_get_arg(vx_core::Type_int index) const = 0;
  };
  class Class_arglist : public virtual Abstract_arglist {
  public:
    Class_arglist();
    virtual ~Class_arglist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_arg> vx_listarg() const override;
    virtual vx_core::Type_arg vx_get_arg(vx_core::Type_int index) const override;
  };

  // (type argmap)
  class Abstract_argmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_argmap() {};
    virtual ~Abstract_argmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_arg> vx_p_map;
    // vx_maparg()
    virtual std::map<std::string, vx_core::Type_arg> vx_maparg() const = 0;
    // vx_get_arg(key)
    virtual vx_core::Type_arg vx_get_arg(vx_core::Type_string key) const = 0;
  };
  class Class_argmap : public virtual Abstract_argmap {
  public:
    Class_argmap();
    virtual ~Class_argmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_arg> vx_maparg() const override;
    virtual vx_core::Type_arg vx_get_arg(vx_core::Type_string key) const override;
  };

  // (type booleanlist)
  class Abstract_booleanlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_booleanlist() {};
    virtual ~Abstract_booleanlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_boolean> vx_p_list;
    // vx_listboolean()
    virtual std::vector<vx_core::Type_boolean> vx_listboolean() const = 0;
    // vx_get_boolean(index)
    virtual vx_core::Type_boolean vx_get_boolean(vx_core::Type_int index) const = 0;
  };
  class Class_booleanlist : public virtual Abstract_booleanlist {
  public:
    Class_booleanlist();
    virtual ~Class_booleanlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_boolean> vx_listboolean() const override;
    virtual vx_core::Type_boolean vx_get_boolean(vx_core::Type_int index) const override;
  };

  // (type collection)
  class Abstract_collection : public virtual vx_core::Abstract_any {
  public:
    Abstract_collection() {};
    virtual ~Abstract_collection() = 0;
  };
  class Class_collection : public virtual Abstract_collection {
  public:
    Class_collection();
    virtual ~Class_collection() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type compilelanguages)
  class Abstract_compilelanguages : public virtual vx_core::Abstract_any {
  public:
    Abstract_compilelanguages() {};
    virtual ~Abstract_compilelanguages() = 0;
  };
  class Class_compilelanguages : public virtual Abstract_compilelanguages {
  public:
    Class_compilelanguages();
    virtual ~Class_compilelanguages() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type connect)
  class Abstract_connect : public virtual vx_core::Abstract_any {
  public:
    Abstract_connect() {};
    virtual ~Abstract_connect() = 0;
  };
  class Class_connect : public virtual Abstract_connect {
  public:
    Class_connect();
    virtual ~Class_connect() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type connectlist)
  class Abstract_connectlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_connectlist() {};
    virtual ~Abstract_connectlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_connect> vx_p_list;
    // vx_listconnect()
    virtual std::vector<vx_core::Type_connect> vx_listconnect() const = 0;
    // vx_get_connect(index)
    virtual vx_core::Type_connect vx_get_connect(vx_core::Type_int index) const = 0;
  };
  class Class_connectlist : public virtual Abstract_connectlist {
  public:
    Class_connectlist();
    virtual ~Class_connectlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_connect> vx_listconnect() const override;
    virtual vx_core::Type_connect vx_get_connect(vx_core::Type_int index) const override;
  };

  // (type connectmap)
  class Abstract_connectmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_connectmap() {};
    virtual ~Abstract_connectmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_connect> vx_p_map;
    // vx_mapconnect()
    virtual std::map<std::string, vx_core::Type_connect> vx_mapconnect() const = 0;
    // vx_get_connect(key)
    virtual vx_core::Type_connect vx_get_connect(vx_core::Type_string key) const = 0;
  };
  class Class_connectmap : public virtual Abstract_connectmap {
  public:
    Class_connectmap();
    virtual ~Class_connectmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_connect> vx_mapconnect() const override;
    virtual vx_core::Type_connect vx_get_connect(vx_core::Type_string key) const override;
  };

  // (type const)
  class Abstract_const : public virtual vx_core::Abstract_any {
  public:
    Abstract_const() {};
    virtual ~Abstract_const() = 0;
  };
  class Class_const : public virtual Abstract_const {
  public:
    Class_const();
    virtual ~Class_const() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type constdef)
  class Abstract_constdef : public virtual vx_core::Abstract_struct {
  public:
    Abstract_constdef() {};
    virtual ~Abstract_constdef() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // pkgname()
    vx_core::Type_string vx_p_pkgname = NULL;
    virtual vx_core::Type_string pkgname() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // type()
    vx_core::Type_any vx_p_type = NULL;
    virtual vx_core::Type_any type() const = 0;
  };
  class Class_constdef : public virtual Abstract_constdef {
  public:
    Class_constdef();
    virtual ~Class_constdef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    static vx_core::Type_constdef vx_constdef_new(
      std::string pkgname,
      std::string name,
      vx_core::Type_typedef typ
    );
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string pkgname() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_any type() const override;
  };

  // (type constlist)
  class Abstract_constlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_constlist() {};
    virtual ~Abstract_constlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_const> vx_p_list;
    // vx_listconst()
    virtual std::vector<vx_core::Type_const> vx_listconst() const = 0;
    // vx_get_const(index)
    virtual vx_core::Type_const vx_get_const(vx_core::Type_int index) const = 0;
  };
  class Class_constlist : public virtual Abstract_constlist {
  public:
    Class_constlist();
    virtual ~Class_constlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_const> vx_listconst() const override;
    virtual vx_core::Type_const vx_get_const(vx_core::Type_int index) const override;
  };

  // (type constmap)
  class Abstract_constmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_constmap() {};
    virtual ~Abstract_constmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_const> vx_p_map;
    // vx_mapconst()
    virtual std::map<std::string, vx_core::Type_const> vx_mapconst() const = 0;
    // vx_get_const(key)
    virtual vx_core::Type_const vx_get_const(vx_core::Type_string key) const = 0;
  };
  class Class_constmap : public virtual Abstract_constmap {
  public:
    Class_constmap();
    virtual ~Class_constmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_const> vx_mapconst() const override;
    virtual vx_core::Type_const vx_get_const(vx_core::Type_string key) const override;
  };

  // (type context)
  class Abstract_context : public virtual vx_core::Abstract_struct {
  public:
    Abstract_context() {};
    virtual ~Abstract_context() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // code()
    vx_core::Type_string vx_p_code = NULL;
    virtual vx_core::Type_string code() const = 0;
    // session()
    vx_core::Type_session vx_p_session = NULL;
    virtual vx_core::Type_session session() const = 0;
    // setting()
    vx_core::Type_setting vx_p_setting = NULL;
    virtual vx_core::Type_setting setting() const = 0;
    // state()
    vx_core::Type_state vx_p_state = NULL;
    virtual vx_core::Type_state state() const = 0;
  };
  class Class_context : public virtual Abstract_context {
  public:
    Class_context();
    virtual ~Class_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string code() const override;
    virtual vx_core::Type_session session() const override;
    virtual vx_core::Type_setting setting() const override;
    virtual vx_core::Type_state state() const override;
  };

  // (type error)
  class Abstract_error : public virtual vx_core::Abstract_any {
  public:
    Abstract_error() {};
    virtual ~Abstract_error() = 0;
  };
  class Class_error : public virtual Abstract_error {
  public:
    Class_error();
    virtual ~Class_error() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type funclist)
  class Abstract_funclist : public virtual vx_core::Abstract_list {
  public:
    Abstract_funclist() {};
    virtual ~Abstract_funclist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_func> vx_p_list;
    // vx_listfunc()
    virtual std::vector<vx_core::Type_func> vx_listfunc() const = 0;
    // vx_get_func(index)
    virtual vx_core::Type_func vx_get_func(vx_core::Type_int index) const = 0;
  };
  class Class_funclist : public virtual Abstract_funclist {
  public:
    Class_funclist();
    virtual ~Class_funclist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_func> vx_listfunc() const override;
    virtual vx_core::Type_func vx_get_func(vx_core::Type_int index) const override;
  };

  // (type funcmap)
  class Abstract_funcmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_funcmap() {};
    virtual ~Abstract_funcmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_func> vx_p_map;
    // vx_mapfunc()
    virtual std::map<std::string, vx_core::Type_func> vx_mapfunc() const = 0;
    // vx_get_func(key)
    virtual vx_core::Type_func vx_get_func(vx_core::Type_string key) const = 0;
  };
  class Class_funcmap : public virtual Abstract_funcmap {
  public:
    Class_funcmap();
    virtual ~Class_funcmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_func> vx_mapfunc() const override;
    virtual vx_core::Type_func vx_get_func(vx_core::Type_string key) const override;
  };

  // (type intlist)
  class Abstract_intlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_intlist() {};
    virtual ~Abstract_intlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_int> vx_p_list;
    // vx_listint()
    virtual std::vector<vx_core::Type_int> vx_listint() const = 0;
    // vx_get_int(index)
    virtual vx_core::Type_int vx_get_int(vx_core::Type_int index) const = 0;
  };
  class Class_intlist : public virtual Abstract_intlist {
  public:
    Class_intlist();
    virtual ~Class_intlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_int> vx_listint() const override;
    virtual vx_core::Type_int vx_get_int(vx_core::Type_int index) const override;
  };

  // (type intmap)
  class Abstract_intmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_intmap() {};
    virtual ~Abstract_intmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_int> vx_p_map;
    // vx_mapint()
    virtual std::map<std::string, vx_core::Type_int> vx_mapint() const = 0;
    // vx_get_int(key)
    virtual vx_core::Type_int vx_get_int(vx_core::Type_string key) const = 0;
  };
  class Class_intmap : public virtual Abstract_intmap {
  public:
    Class_intmap();
    virtual ~Class_intmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_int> vx_mapint() const override;
    virtual vx_core::Type_int vx_get_int(vx_core::Type_string key) const override;
  };

  // (type listtype)
  class Abstract_listtype : public virtual vx_core::Abstract_any {
  public:
    Abstract_listtype() {};
    virtual ~Abstract_listtype() = 0;
  };
  class Class_listtype : public virtual Abstract_listtype {
  public:
    Class_listtype();
    virtual ~Class_listtype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type maptype)
  class Abstract_maptype : public virtual vx_core::Abstract_any {
  public:
    Abstract_maptype() {};
    virtual ~Abstract_maptype() = 0;
  };
  class Class_maptype : public virtual Abstract_maptype {
  public:
    Class_maptype();
    virtual ~Class_maptype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type mempool)
  class Abstract_mempool : public virtual vx_core::Abstract_struct {
  public:
    Abstract_mempool() {};
    virtual ~Abstract_mempool() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // valuepool()
    vx_core::Type_value vx_p_valuepool = NULL;
    virtual vx_core::Type_value valuepool() const = 0;
  };
  class Class_mempool : public virtual Abstract_mempool {
  public:
    Class_mempool();
    virtual ~Class_mempool() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_value valuepool() const override;
  };

  // (type none)
  class Abstract_none : public virtual vx_core::Abstract_any {
  public:
    Abstract_none() {};
    virtual ~Abstract_none() = 0;
  };
  class Class_none : public virtual Abstract_none {
  public:
    Class_none();
    virtual ~Class_none() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type notype)
  class Abstract_notype : public virtual vx_core::Abstract_any {
  public:
    Abstract_notype() {};
    virtual ~Abstract_notype() = 0;
  };
  class Class_notype : public virtual Abstract_notype {
  public:
    Class_notype();
    virtual ~Class_notype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type numberlist)
  class Abstract_numberlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_numberlist() {};
    virtual ~Abstract_numberlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_number> vx_p_list;
    // vx_listnumber()
    virtual std::vector<vx_core::Type_number> vx_listnumber() const = 0;
    // vx_get_number(index)
    virtual vx_core::Type_number vx_get_number(vx_core::Type_int index) const = 0;
  };
  class Class_numberlist : public virtual Abstract_numberlist {
  public:
    Class_numberlist();
    virtual ~Class_numberlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_number> vx_listnumber() const override;
    virtual vx_core::Type_number vx_get_number(vx_core::Type_int index) const override;
  };

  // (type numbermap)
  class Abstract_numbermap : public virtual vx_core::Abstract_map {
  public:
    Abstract_numbermap() {};
    virtual ~Abstract_numbermap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_number> vx_p_map;
    // vx_mapnumber()
    virtual std::map<std::string, vx_core::Type_number> vx_mapnumber() const = 0;
    // vx_get_number(key)
    virtual vx_core::Type_number vx_get_number(vx_core::Type_string key) const = 0;
  };
  class Class_numbermap : public virtual Abstract_numbermap {
  public:
    Class_numbermap();
    virtual ~Class_numbermap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_number> vx_mapnumber() const override;
    virtual vx_core::Type_number vx_get_number(vx_core::Type_string key) const override;
  };

  // (type package)
  class Abstract_package : public virtual vx_core::Abstract_struct {
  public:
    Abstract_package() {};
    virtual ~Abstract_package() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_package : public virtual Abstract_package {
  public:
    Class_package();
    virtual ~Class_package() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type packagemap)
  class Abstract_packagemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_packagemap() {};
    virtual ~Abstract_packagemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_package> vx_p_map;
    // vx_mappackage()
    virtual std::map<std::string, vx_core::Type_package> vx_mappackage() const = 0;
    // vx_get_package(key)
    virtual vx_core::Type_package vx_get_package(vx_core::Type_string key) const = 0;
  };
  class Class_packagemap : public virtual Abstract_packagemap {
  public:
    Class_packagemap();
    virtual ~Class_packagemap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_package> vx_mappackage() const override;
    virtual vx_core::Type_package vx_get_package(vx_core::Type_string key) const override;
  };

  // (type permission)
  class Abstract_permission : public virtual vx_core::Abstract_struct {
  public:
    Abstract_permission() {};
    virtual ~Abstract_permission() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
  };
  class Class_permission : public virtual Abstract_permission {
  public:
    Class_permission();
    virtual ~Class_permission() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string id() const override;
  };

  // (type permissionlist)
  class Abstract_permissionlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_permissionlist() {};
    virtual ~Abstract_permissionlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_permission> vx_p_list;
    // vx_listpermission()
    virtual std::vector<vx_core::Type_permission> vx_listpermission() const = 0;
    // vx_get_permission(index)
    virtual vx_core::Type_permission vx_get_permission(vx_core::Type_int index) const = 0;
  };
  class Class_permissionlist : public virtual Abstract_permissionlist {
  public:
    Class_permissionlist();
    virtual ~Class_permissionlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_permission> vx_listpermission() const override;
    virtual vx_core::Type_permission vx_get_permission(vx_core::Type_int index) const override;
  };

  // (type permissionmap)
  class Abstract_permissionmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_permissionmap() {};
    virtual ~Abstract_permissionmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_permission> vx_p_map;
    // vx_mappermission()
    virtual std::map<std::string, vx_core::Type_permission> vx_mappermission() const = 0;
    // vx_get_permission(key)
    virtual vx_core::Type_permission vx_get_permission(vx_core::Type_string key) const = 0;
  };
  class Class_permissionmap : public virtual Abstract_permissionmap {
  public:
    Class_permissionmap();
    virtual ~Class_permissionmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_permission> vx_mappermission() const override;
    virtual vx_core::Type_permission vx_get_permission(vx_core::Type_string key) const override;
  };

  // (type security)
  class Abstract_security : public virtual vx_core::Abstract_struct {
  public:
    Abstract_security() {};
    virtual ~Abstract_security() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // allowfuncs()
    vx_core::Type_funclist vx_p_allowfuncs = NULL;
    virtual vx_core::Type_funclist allowfuncs() const = 0;
    // permissions()
    vx_core::Type_permissionlist vx_p_permissions = NULL;
    virtual vx_core::Type_permissionlist permissions() const = 0;
    // permissionmap()
    vx_core::Type_permissionmap vx_p_permissionmap = NULL;
    virtual vx_core::Type_permissionmap permissionmap() const = 0;
  };
  class Class_security : public virtual Abstract_security {
  public:
    Class_security();
    virtual ~Class_security() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_funclist allowfuncs() const override;
    virtual vx_core::Type_permissionlist permissions() const override;
    virtual vx_core::Type_permissionmap permissionmap() const override;
  };

  // (type session)
  class Abstract_session : public virtual vx_core::Abstract_struct {
  public:
    Abstract_session() {};
    virtual ~Abstract_session() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // user()
    vx_core::Type_user vx_p_user = NULL;
    virtual vx_core::Type_user user() const = 0;
    // connectlist()
    vx_core::Type_connectlist vx_p_connectlist = NULL;
    virtual vx_core::Type_connectlist connectlist() const = 0;
    // connectmap()
    vx_core::Type_connectmap vx_p_connectmap = NULL;
    virtual vx_core::Type_connectmap connectmap() const = 0;
  };
  class Class_session : public virtual Abstract_session {
  public:
    Class_session();
    virtual ~Class_session() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_user user() const override;
    virtual vx_core::Type_connectlist connectlist() const override;
    virtual vx_core::Type_connectmap connectmap() const override;
  };

  // (type setting)
  class Abstract_setting : public virtual vx_core::Abstract_struct {
  public:
    Abstract_setting() {};
    virtual ~Abstract_setting() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // pathmap()
    vx_core::Type_stringmap vx_p_pathmap = NULL;
    virtual vx_core::Type_stringmap pathmap() const = 0;
  };
  class Class_setting : public virtual Abstract_setting {
  public:
    Class_setting();
    virtual ~Class_setting() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_stringmap pathmap() const override;
  };

  // (type state)
  class Abstract_state : public virtual vx_core::Abstract_map {
  public:
    Abstract_state() {};
    virtual ~Abstract_state() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_statelistener> vx_p_map;
    // vx_mapstatelistener()
    virtual std::map<std::string, vx_core::Type_statelistener> vx_mapstatelistener() const = 0;
    // vx_get_statelistener(key)
    virtual vx_core::Type_statelistener vx_get_statelistener(vx_core::Type_string key) const = 0;
  };
  class Class_state : public virtual Abstract_state {
  public:
    Class_state();
    virtual ~Class_state() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_statelistener> vx_mapstatelistener() const override;
    virtual vx_core::Type_statelistener vx_get_statelistener(vx_core::Type_string key) const override;
  };

  // (type statelistener)
  class Abstract_statelistener : public virtual vx_core::Abstract_struct {
  public:
    Abstract_statelistener() {};
    virtual ~Abstract_statelistener() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // path()
    vx_core::Type_string vx_p_path = NULL;
    virtual vx_core::Type_string path() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
    // fn-boolean()
    vx_core::Func_boolean_from_none vx_p_fn_boolean = NULL;
    virtual vx_core::Func_boolean_from_none fn_boolean() const = 0;
  };
  class Class_statelistener : public virtual Abstract_statelistener {
  public:
    Class_statelistener();
    virtual ~Class_statelistener() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string path() const override;
    virtual vx_core::Type_any value() const override;
    virtual vx_core::Func_boolean_from_none fn_boolean() const override;
  };

  // (type stringlist)
  class Abstract_stringlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_stringlist() {};
    virtual ~Abstract_stringlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_string> vx_p_list;
    // vx_liststring()
    virtual std::vector<vx_core::Type_string> vx_liststring() const = 0;
    // vx_get_string(index)
    virtual vx_core::Type_string vx_get_string(vx_core::Type_int index) const = 0;
  };
  class Class_stringlist : public virtual Abstract_stringlist {
  public:
    Class_stringlist();
    virtual ~Class_stringlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_string> vx_liststring() const override;
    virtual vx_core::Type_string vx_get_string(vx_core::Type_int index) const override;
  };

  // (type stringmap)
  class Abstract_stringmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_stringmap() {};
    virtual ~Abstract_stringmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_string> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring() const = 0;
    // vx_get_string(key)
    virtual vx_core::Type_string vx_get_string(vx_core::Type_string key) const = 0;
  };
  class Class_stringmap : public virtual Abstract_stringmap {
  public:
    Class_stringmap();
    virtual ~Class_stringmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring() const override;
    virtual vx_core::Type_string vx_get_string(vx_core::Type_string key) const override;
  };

  // (type thenelse)
  class Abstract_thenelse : public virtual vx_core::Abstract_struct {
  public:
    Abstract_thenelse() {};
    virtual ~Abstract_thenelse() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // code()
    vx_core::Type_string vx_p_code = NULL;
    virtual vx_core::Type_string code() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
    // values()
    vx_core::Type_list vx_p_values = NULL;
    virtual vx_core::Type_list values() const = 0;
    // fn-cond()
    vx_core::Func_boolean_from_func vx_p_fn_cond = NULL;
    virtual vx_core::Func_boolean_from_func fn_cond() const = 0;
    // fn-any()
    vx_core::Func_any_from_func vx_p_fn_any = NULL;
    virtual vx_core::Func_any_from_func fn_any() const = 0;
  };
  class Class_thenelse : public virtual Abstract_thenelse {
  public:
    Class_thenelse();
    virtual ~Class_thenelse() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string code() const override;
    virtual vx_core::Type_any value() const override;
    virtual vx_core::Type_list values() const override;
    virtual vx_core::Func_boolean_from_func fn_cond() const override;
    virtual vx_core::Func_any_from_func fn_any() const override;
  };

  // (type thenelselist)
  class Abstract_thenelselist : public virtual vx_core::Abstract_list {
  public:
    Abstract_thenelselist() {};
    virtual ~Abstract_thenelselist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_thenelse> vx_p_list;
    // vx_listthenelse()
    virtual std::vector<vx_core::Type_thenelse> vx_listthenelse() const = 0;
    // vx_get_thenelse(index)
    virtual vx_core::Type_thenelse vx_get_thenelse(vx_core::Type_int index) const = 0;
  };
  class Class_thenelselist : public virtual Abstract_thenelselist {
  public:
    Class_thenelselist();
    virtual ~Class_thenelselist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_thenelse> vx_listthenelse() const override;
    virtual vx_core::Type_thenelse vx_get_thenelse(vx_core::Type_int index) const override;
  };

  // (type type)
  class Abstract_type : public virtual vx_core::Abstract_any {
  public:
    Abstract_type() {};
    virtual ~Abstract_type() = 0;
  };
  class Class_type : public virtual Abstract_type {
  public:
    Class_type();
    virtual ~Class_type() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type typelist)
  class Abstract_typelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_typelist() {};
    virtual ~Abstract_typelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_any> vx_p_list;
  };
  class Class_typelist : public virtual Abstract_typelist {
  public:
    Class_typelist();
    virtual ~Class_typelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
  };

  // (type typemap)
  class Abstract_typemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_typemap() {};
    virtual ~Abstract_typemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
  };
  class Class_typemap : public virtual Abstract_typemap {
  public:
    Class_typemap();
    virtual ~Class_typemap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
  };

  // (type user)
  class Abstract_user : public virtual vx_core::Abstract_struct {
  public:
    Abstract_user() {};
    virtual ~Abstract_user() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // security()
    vx_core::Type_security vx_p_security = NULL;
    virtual vx_core::Type_security security() const = 0;
    // username()
    vx_core::Type_string vx_p_username = NULL;
    virtual vx_core::Type_string username() const = 0;
    // token()
    vx_core::Type_string vx_p_token = NULL;
    virtual vx_core::Type_string token() const = 0;
  };
  class Class_user : public virtual Abstract_user {
  public:
    Class_user();
    virtual ~Class_user() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_security security() const override;
    virtual vx_core::Type_string username() const override;
    virtual vx_core::Type_string token() const override;
  };

  // (type value)
  class Abstract_value : public virtual vx_core::Abstract_struct {
  public:
    Abstract_value() {};
    virtual ~Abstract_value() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // next()
    vx_core::Type_any vx_p_next = NULL;
    virtual vx_core::Type_any next() const = 0;
    // refs()
    vx_core::Type_int vx_p_refs = NULL;
    virtual vx_core::Type_int refs() const = 0;
  };
  class Class_value : public virtual Abstract_value {
  public:
    Class_value();
    virtual ~Class_value() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_any next() const override;
    virtual vx_core::Type_int refs() const override;
  };

  // (const false)
  class Class_false : public vx_core::Class_boolean {
  public:
    static void vx_const_new(vx_core::Const_false output);
    vx_core::Type_constdef vx_constdef() const;
    bool vx_boolean() const override;
  };

  // (const globalpackagemap)
  class Class_globalpackagemap : public vx_core::Class_packagemap {
  public:
    static void vx_const_new(vx_core::Const_globalpackagemap output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const infinity)
  class Class_infinity : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_infinity output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const mempool-active)
  class Class_mempool_active : public vx_core::Class_mempool {
  public:
    static void vx_const_new(vx_core::Const_mempool_active output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const msg-error)
  class Class_msg_error : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_msg_error output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const msg-info)
  class Class_msg_info : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_msg_info output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const msg-severe)
  class Class_msg_severe : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_msg_severe output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const msg-warning)
  class Class_msg_warning : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_msg_warning output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const neginfinity)
  class Class_neginfinity : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_neginfinity output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const newline)
  class Class_newline : public vx_core::Class_string {
  public:
    static void vx_const_new(vx_core::Const_newline output);
    vx_core::Type_constdef vx_constdef() const;
    std::string vx_string() const override;
  };

  // (const notanumber)
  class Class_notanumber : public vx_core::Class_int {
  public:
    static void vx_const_new(vx_core::Const_notanumber output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (const nothing)
  class Class_nothing : public vx_core::Class_string {
  public:
    static void vx_const_new(vx_core::Const_nothing output);
    vx_core::Type_constdef vx_constdef() const;
    std::string vx_string() const override;
  };

  // (const quote)
  class Class_quote : public vx_core::Class_string {
  public:
    static void vx_const_new(vx_core::Const_quote output);
    vx_core::Type_constdef vx_constdef() const;
    std::string vx_string() const override;
  };

  // (const true)
  class Class_true : public vx_core::Class_boolean {
  public:
    static void vx_const_new(vx_core::Const_true output);
    vx_core::Type_constdef vx_constdef() const;
    bool vx_boolean() const override;
  };

  // (func !==)
  class Abstract_neqeq : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_neqeq() {};
    virtual ~Abstract_neqeq() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_neqeq : public virtual Abstract_neqeq {
  public:
    Class_neqeq();
    virtual ~Class_neqeq() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func *)
  class Abstract_multiply : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_multiply() {};
    virtual ~Abstract_multiply() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_multiply : public virtual Abstract_multiply {
  public:
    Class_multiply();
    virtual ~Class_multiply() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func *)
  class Abstract_multiply_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_multiply_1() {};
    virtual ~Abstract_multiply_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_multiply_1 : public virtual Abstract_multiply_1 {
  public:
    Class_multiply_1();
    virtual ~Class_multiply_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func *)
  class Abstract_multiply_2 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_multiply_2() {};
    virtual ~Abstract_multiply_2() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_multiply_2 : public virtual Abstract_multiply_2 {
  public:
    Class_multiply_2();
    virtual ~Class_multiply_2() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func *)
  class Abstract_multiply_3 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_multiply_3() {};
    virtual ~Abstract_multiply_3() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_multiply_3 : public virtual Abstract_multiply_3 {
  public:
    Class_multiply_3();
    virtual ~Class_multiply_3() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func +)
  class Abstract_plus : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_plus() {};
    virtual ~Abstract_plus() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_plus : public virtual Abstract_plus {
  public:
    Class_plus();
    virtual ~Class_plus() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func +)
  class Abstract_plus_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_plus_1() {};
    virtual ~Abstract_plus_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_plus_1 : public virtual Abstract_plus_1 {
  public:
    Class_plus_1();
    virtual ~Class_plus_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func +)
  class Abstract_plus_2 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_plus_2() {};
    virtual ~Abstract_plus_2() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_plus_2 : public virtual Abstract_plus_2 {
  public:
    Class_plus_2();
    virtual ~Class_plus_2() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func +)
  class Abstract_plus_3 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_plus_3() {};
    virtual ~Abstract_plus_3() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_plus_3 : public virtual Abstract_plus_3 {
  public:
    Class_plus_3();
    virtual ~Class_plus_3() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func +1)
  class Abstract_plus1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_plus1() {};
    virtual ~Abstract_plus1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_plus1 : public virtual Abstract_plus1 {
  public:
    Class_plus1();
    virtual ~Class_plus1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func -)
  class Abstract_minus : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_minus() {};
    virtual ~Abstract_minus() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_minus : public virtual Abstract_minus {
  public:
    Class_minus();
    virtual ~Class_minus() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func -)
  class Abstract_minus_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_minus_1() {};
    virtual ~Abstract_minus_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_minus_1 : public virtual Abstract_minus_1 {
  public:
    Class_minus_1();
    virtual ~Class_minus_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func -)
  class Abstract_minus_2 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_minus_2() {};
    virtual ~Abstract_minus_2() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_minus_2 : public virtual Abstract_minus_2 {
  public:
    Class_minus_2();
    virtual ~Class_minus_2() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func -)
  class Abstract_minus_3 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_minus_3() {};
    virtual ~Abstract_minus_3() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_minus_3 : public virtual Abstract_minus_3 {
  public:
    Class_minus_3();
    virtual ~Class_minus_3() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func .)
  class Abstract_dotmethod : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_dotmethod() {};
    virtual ~Abstract_dotmethod() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_dotmethod : public virtual Abstract_dotmethod {
  public:
    Class_dotmethod();
    virtual ~Class_dotmethod() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func /)
  class Abstract_divide : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_divide() {};
    virtual ~Abstract_divide() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_divide : public virtual Abstract_divide {
  public:
    Class_divide();
    virtual ~Class_divide() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <)
  class Abstract_lt : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_lt() {};
    virtual ~Abstract_lt() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_lt : public virtual Abstract_lt {
  public:
    Class_lt();
    virtual ~Class_lt() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <)
  class Abstract_lt_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_lt_1() {};
    virtual ~Abstract_lt_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_lt_1 : public virtual Abstract_lt_1 {
  public:
    Class_lt_1();
    virtual ~Class_lt_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <-)
  class Abstract_chainfirst : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_chainfirst() {};
    virtual ~Abstract_chainfirst() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_chainfirst : public virtual Abstract_chainfirst {
  public:
    Class_chainfirst();
    virtual ~Class_chainfirst() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <<-)
  class Abstract_chainlast : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_chainlast() {};
    virtual ~Abstract_chainlast() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_chainlast : public virtual Abstract_chainlast {
  public:
    Class_chainlast();
    virtual ~Class_chainlast() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <=)
  class Abstract_le : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_le() {};
    virtual ~Abstract_le() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_le : public virtual Abstract_le {
  public:
    Class_le();
    virtual ~Class_le() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func <=)
  class Abstract_le_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_le_1() {};
    virtual ~Abstract_le_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_le_1 : public virtual Abstract_le_1 {
  public:
    Class_le_1();
    virtual ~Class_le_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ==)
  class Abstract_eqeq : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_eqeq() {};
    virtual ~Abstract_eqeq() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_eqeq : public virtual Abstract_eqeq {
  public:
    Class_eqeq();
    virtual ~Class_eqeq() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func >)
  class Abstract_gt : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_gt() {};
    virtual ~Abstract_gt() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_gt : public virtual Abstract_gt {
  public:
    Class_gt();
    virtual ~Class_gt() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func >)
  class Abstract_gt_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_gt_1() {};
    virtual ~Abstract_gt_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_gt_1 : public virtual Abstract_gt_1 {
  public:
    Class_gt_1();
    virtual ~Class_gt_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func >=)
  class Abstract_ge : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ge() {};
    virtual ~Abstract_ge() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ge : public virtual Abstract_ge {
  public:
    Class_ge();
    virtual ~Class_ge() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func >=)
  class Abstract_ge_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ge_1() {};
    virtual ~Abstract_ge_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ge_1 : public virtual Abstract_ge_1 {
  public:
    Class_ge_1();
    virtual ~Class_ge_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func allowfuncs<-security)
  class Abstract_allowfuncs_from_security : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_allowfuncs_from_security() {};
    virtual ~Abstract_allowfuncs_from_security() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_allowfuncs_from_security : public virtual Abstract_allowfuncs_from_security {
  public:
    Class_allowfuncs_from_security();
    virtual ~Class_allowfuncs_from_security() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func allowtypenames<-typedef)
  class Abstract_allowtypenames_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_allowtypenames_from_typedef() {};
    virtual ~Abstract_allowtypenames_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_allowtypenames_from_typedef : public virtual Abstract_allowtypenames_from_typedef {
  public:
    Class_allowtypenames_from_typedef();
    virtual ~Class_allowtypenames_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func allowtypes<-typedef)
  class Abstract_allowtypes_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_allowtypes_from_typedef() {};
    virtual ~Abstract_allowtypes_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_allowtypes_from_typedef : public virtual Abstract_allowtypes_from_typedef {
  public:
    Class_allowtypes_from_typedef();
    virtual ~Class_allowtypes_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-int)
  class Abstract_any_from_int : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_int() {};
    virtual ~Abstract_any_from_int() = 0;
    typedef std::function<vx_core::Type_any(vx_core::Type_int)> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_any_from_int vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_int::IFn fn) const = 0;
    virtual vx_core::Type_any vx_any_from_int(vx_core::Type_int value) const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_int : public virtual Abstract_any_from_int {
  public:
    Class_any_from_int();
    virtual ~Class_any_from_int() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_int vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_int::IFn fn) const;
    virtual vx_core::Type_any vx_any_from_int(vx_core::Type_int value) const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-permission<-func)
  class Abstract_boolean_permission_from_func : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_permission_from_func() {};
    virtual ~Abstract_boolean_permission_from_func() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_permission_from_func : public virtual Abstract_boolean_permission_from_func {
  public:
    Class_boolean_permission_from_func();
    virtual ~Class_boolean_permission_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func compare)
  class Abstract_compare : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_compare() {};
    virtual ~Abstract_compare() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_compare : public virtual Abstract_compare {
  public:
    Class_compare();
    virtual ~Class_compare() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func contains)
  class Abstract_contains : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_contains() {};
    virtual ~Abstract_contains() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_contains : public virtual Abstract_contains {
  public:
    Class_contains();
    virtual ~Class_contains() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func contains)
  class Abstract_contains_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_contains_1() {};
    virtual ~Abstract_contains_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_contains_1 : public virtual Abstract_contains_1 {
  public:
    Class_contains_1();
    virtual ~Class_contains_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func context-main)
  class Abstract_context_main : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_context_main() {};
    virtual ~Abstract_context_main() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_context_main : public virtual Abstract_context_main {
  public:
    Class_context_main();
    virtual ~Class_context_main() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func extends<-any)
  class Abstract_extends_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_extends_from_any() {};
    virtual ~Abstract_extends_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_extends_from_any : public virtual Abstract_extends_from_any {
  public:
    Class_extends_from_any();
    virtual ~Class_extends_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func extends<-typedef)
  class Abstract_extends_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_extends_from_typedef() {};
    virtual ~Abstract_extends_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_extends_from_typedef : public virtual Abstract_extends_from_typedef {
  public:
    Class_extends_from_typedef();
    virtual ~Class_extends_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func first<-list)
  class Abstract_first_from_list : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_first_from_list() {};
    virtual ~Abstract_first_from_list() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_first_from_list : public virtual Abstract_first_from_list {
  public:
    Class_first_from_list();
    virtual ~Class_first_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func first<-list-fn-any<-any)
  class Abstract_first_from_list_fn_any_from_any : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_first_from_list_fn_any_from_any() {};
    virtual ~Abstract_first_from_list_fn_any_from_any() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_first_from_list_fn_any_from_any : public virtual Abstract_first_from_list_fn_any_from_any {
  public:
    Class_first_from_list_fn_any_from_any();
    virtual ~Class_first_from_list_fn_any_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func fn)
  class Abstract_fn : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_fn() {};
    virtual ~Abstract_fn() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_fn : public virtual Abstract_fn {
  public:
    Class_fn();
    virtual ~Class_fn() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func funcdef<-func)
  class Abstract_funcdef_from_func : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_funcdef_from_func() {};
    virtual ~Abstract_funcdef_from_func() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_funcdef_from_func : public virtual Abstract_funcdef_from_func {
  public:
    Class_funcdef_from_func();
    virtual ~Class_funcdef_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func funcname<-funcdef)
  class Abstract_funcname_from_funcdef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_funcname_from_funcdef() {};
    virtual ~Abstract_funcname_from_funcdef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_funcname_from_funcdef : public virtual Abstract_funcname_from_funcdef {
  public:
    Class_funcname_from_funcdef();
    virtual ~Class_funcname_from_funcdef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func global-package-get)
  class Abstract_global_package_get : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_global_package_get() {};
    virtual ~Abstract_global_package_get() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_global_package_get : public virtual Abstract_global_package_get {
  public:
    Class_global_package_get();
    virtual ~Class_global_package_get() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func global-package-set)
  class Abstract_global_package_set : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_global_package_set() {};
    virtual ~Abstract_global_package_set() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_global_package_set : public virtual Abstract_global_package_set {
  public:
    Class_global_package_set();
    virtual ~Class_global_package_set() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func int<-func)
  class Abstract_int_from_func : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_func() {};
    virtual ~Abstract_int_from_func() = 0;
    typedef std::function<vx_core::Type_int()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_int_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_int_from_func::IFn fn) const = 0;
    virtual vx_core::Type_int vx_int_from_func() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_func : public virtual Abstract_int_from_func {
  public:
    Class_int_from_func();
    virtual ~Class_int_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_int_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_int_from_func::IFn fn) const;
    virtual vx_core::Type_int vx_int_from_func() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func int<-string)
  class Abstract_int_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_string() {};
    virtual ~Abstract_int_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_string : public virtual Abstract_int_from_string {
  public:
    Class_int_from_string();
    virtual ~Class_int_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-endswith)
  class Abstract_is_endswith : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_endswith() {};
    virtual ~Abstract_is_endswith() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_endswith : public virtual Abstract_is_endswith {
  public:
    Class_is_endswith();
    virtual ~Class_is_endswith() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-func)
  class Abstract_is_func : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_func() {};
    virtual ~Abstract_is_func() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_func : public virtual Abstract_is_func {
  public:
    Class_is_func();
    virtual ~Class_is_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-int)
  class Abstract_is_int : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_int() {};
    virtual ~Abstract_is_int() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_int : public virtual Abstract_is_int {
  public:
    Class_is_int();
    virtual ~Class_is_int() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-number)
  class Abstract_is_number : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_number() {};
    virtual ~Abstract_is_number() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_number : public virtual Abstract_is_number {
  public:
    Class_is_number();
    virtual ~Class_is_number() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-pass<-permission)
  class Abstract_is_pass_from_permission : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_pass_from_permission() {};
    virtual ~Abstract_is_pass_from_permission() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_pass_from_permission : public virtual Abstract_is_pass_from_permission {
  public:
    Class_is_pass_from_permission();
    virtual ~Class_is_pass_from_permission() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func last<-list)
  class Abstract_last_from_list : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_last_from_list() {};
    virtual ~Abstract_last_from_list() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_last_from_list : public virtual Abstract_last_from_list {
  public:
    Class_last_from_list();
    virtual ~Class_last_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list-join<-list)
  class Abstract_list_join_from_list : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_join_from_list() {};
    virtual ~Abstract_list_join_from_list() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_join_from_list : public virtual Abstract_list_join_from_list {
  public:
    Class_list_join_from_list();
    virtual ~Class_list_join_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list<-list)
  class Abstract_list_from_list : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list() {};
    virtual ~Abstract_list_from_list() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list : public virtual Abstract_list_from_list {
  public:
    Class_list_from_list();
    virtual ~Class_list_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list<-list-async)
  class Abstract_list_from_list_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_list_from_list_async() {};
    virtual ~Abstract_list_from_list_async() = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_async : public virtual Abstract_list_from_list_async {
  public:
    Class_list_from_list_async();
    virtual ~Class_list_from_list_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list<-map)
  class Abstract_list_from_map : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_map() {};
    virtual ~Abstract_list_from_map() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_map : public virtual Abstract_list_from_map {
  public:
    Class_list_from_map();
    virtual ~Class_list_from_map() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list<-map-async)
  class Abstract_list_from_map_async : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_list_from_map_async() {};
    virtual ~Abstract_list_from_map_async() = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_map_async : public virtual Abstract_list_from_map_async {
  public:
    Class_list_from_map_async();
    virtual ~Class_list_from_map_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func list<-type)
  class Abstract_list_from_type : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_type() {};
    virtual ~Abstract_list_from_type() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_type : public virtual Abstract_list_from_type {
  public:
    Class_list_from_type();
    virtual ~Class_list_from_type() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func log)
  class Abstract_log : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_log() {};
    virtual ~Abstract_log() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_log : public virtual Abstract_log {
  public:
    Class_log();
    virtual ~Class_log() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func log)
  class Abstract_log_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_log_1() {};
    virtual ~Abstract_log_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_log_1 : public virtual Abstract_log_1 {
  public:
    Class_log_1();
    virtual ~Class_log_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func main)
  class Abstract_main : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_main() {};
    virtual ~Abstract_main() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_main : public virtual Abstract_main {
  public:
    Class_main();
    virtual ~Class_main() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func map<-list)
  class Abstract_map_from_list : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_map_from_list() {};
    virtual ~Abstract_map_from_list() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_map_from_list : public virtual Abstract_map_from_list {
  public:
    Class_map_from_list();
    virtual ~Class_map_from_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func mempool-addref)
  class Abstract_mempool_addref : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_mempool_addref() {};
    virtual ~Abstract_mempool_addref() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_mempool_addref : public virtual Abstract_mempool_addref {
  public:
    Class_mempool_addref();
    virtual ~Class_mempool_addref() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func mempool-release)
  class Abstract_mempool_release : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_mempool_release() {};
    virtual ~Abstract_mempool_release() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_mempool_release : public virtual Abstract_mempool_release {
  public:
    Class_mempool_release();
    virtual ~Class_mempool_release() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func mempool-removeref)
  class Abstract_mempool_removeref : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_mempool_removeref() {};
    virtual ~Abstract_mempool_removeref() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_mempool_removeref : public virtual Abstract_mempool_removeref {
  public:
    Class_mempool_removeref();
    virtual ~Class_mempool_removeref() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func mempool-removerefchildren)
  class Abstract_mempool_removerefchildren : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_mempool_removerefchildren() {};
    virtual ~Abstract_mempool_removerefchildren() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_mempool_removerefchildren : public virtual Abstract_mempool_removerefchildren {
  public:
    Class_mempool_removerefchildren();
    virtual ~Class_mempool_removerefchildren() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func mempool-reserve)
  class Abstract_mempool_reserve : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_mempool_reserve() {};
    virtual ~Abstract_mempool_reserve() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_mempool_reserve : public virtual Abstract_mempool_reserve {
  public:
    Class_mempool_reserve();
    virtual ~Class_mempool_reserve() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func msg<-error)
  class Abstract_msg_from_error : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_msg_from_error() {};
    virtual ~Abstract_msg_from_error() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_msg_from_error : public virtual Abstract_msg_from_error {
  public:
    Class_msg_from_error();
    virtual ~Class_msg_from_error() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func msg<-warning)
  class Abstract_msg_from_warning : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_msg_from_warning() {};
    virtual ~Abstract_msg_from_warning() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_msg_from_warning : public virtual Abstract_msg_from_warning {
  public:
    Class_msg_from_warning();
    virtual ~Class_msg_from_warning() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func msgblock<-msgblock-msg)
  class Abstract_msgblock_from_msgblock_msg : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_msgblock_from_msgblock_msg() {};
    virtual ~Abstract_msgblock_from_msgblock_msg() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_msgblock_from_msgblock_msg : public virtual Abstract_msgblock_from_msgblock_msg {
  public:
    Class_msgblock_from_msgblock_msg();
    virtual ~Class_msgblock_from_msgblock_msg() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func msgblock<-msgblock-msgblock)
  class Abstract_msgblock_from_msgblock_msgblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_msgblock_from_msgblock_msgblock() {};
    virtual ~Abstract_msgblock_from_msgblock_msgblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_msgblock_from_msgblock_msgblock : public virtual Abstract_msgblock_from_msgblock_msgblock {
  public:
    Class_msgblock_from_msgblock_msgblock();
    virtual ~Class_msgblock_from_msgblock_msgblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func name<-typedef)
  class Abstract_name_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_name_from_typedef() {};
    virtual ~Abstract_name_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_name_from_typedef : public virtual Abstract_name_from_typedef {
  public:
    Class_name_from_typedef();
    virtual ~Class_name_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func native)
  class Abstract_native : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_native() {};
    virtual ~Abstract_native() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_native : public virtual Abstract_native {
  public:
    Class_native();
    virtual ~Class_native() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func native<-any)
  class Abstract_native_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_native_from_any() {};
    virtual ~Abstract_native_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_native_from_any : public virtual Abstract_native_from_any {
  public:
    Class_native_from_any();
    virtual ~Class_native_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func number<-func)
  class Abstract_number_from_func : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_number_from_func() {};
    virtual ~Abstract_number_from_func() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_number_from_func : public virtual Abstract_number_from_func {
  public:
    Class_number_from_func();
    virtual ~Class_number_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func packagename<-typedef)
  class Abstract_packagename_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_packagename_from_typedef() {};
    virtual ~Abstract_packagename_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_packagename_from_typedef : public virtual Abstract_packagename_from_typedef {
  public:
    Class_packagename_from_typedef();
    virtual ~Class_packagename_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func path<-context-path)
  class Abstract_path_from_context_path : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_path_from_context_path() {};
    virtual ~Abstract_path_from_context_path() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_path_from_context_path : public virtual Abstract_path_from_context_path {
  public:
    Class_path_from_context_path();
    virtual ~Class_path_from_context_path() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func path<-setting-path)
  class Abstract_path_from_setting_path : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_path_from_setting_path() {};
    virtual ~Abstract_path_from_setting_path() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_path_from_setting_path : public virtual Abstract_path_from_setting_path {
  public:
    Class_path_from_setting_path();
    virtual ~Class_path_from_setting_path() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func permission<-id-context)
  class Abstract_permission_from_id_context : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_permission_from_id_context() {};
    virtual ~Abstract_permission_from_id_context() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_permission_from_id_context : public virtual Abstract_permission_from_id_context {
  public:
    Class_permission_from_id_context();
    virtual ~Class_permission_from_id_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func properties<-typedef)
  class Abstract_properties_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_properties_from_typedef() {};
    virtual ~Abstract_properties_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_properties_from_typedef : public virtual Abstract_properties_from_typedef {
  public:
    Class_properties_from_typedef();
    virtual ~Class_properties_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func proplast<-typedef)
  class Abstract_proplast_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_proplast_from_typedef() {};
    virtual ~Abstract_proplast_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_proplast_from_typedef : public virtual Abstract_proplast_from_typedef {
  public:
    Class_proplast_from_typedef();
    virtual ~Class_proplast_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve)
  class Abstract_resolve : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_resolve() {};
    virtual ~Abstract_resolve() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve : public virtual Abstract_resolve {
  public:
    Class_resolve();
    virtual ~Class_resolve() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve)
  class Abstract_resolve_1 : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_resolve_1() {};
    virtual ~Abstract_resolve_1() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_1 : public virtual Abstract_resolve_1 {
  public:
    Class_resolve_1();
    virtual ~Class_resolve_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-async)
  class Abstract_resolve_async : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_async() {};
    virtual ~Abstract_resolve_async() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_async : public virtual Abstract_resolve_async {
  public:
    Class_resolve_async();
    virtual ~Class_resolve_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-first)
  class Abstract_resolve_first : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_resolve_first() {};
    virtual ~Abstract_resolve_first() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_first : public virtual Abstract_resolve_first {
  public:
    Class_resolve_first();
    virtual ~Class_resolve_first() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-list)
  class Abstract_resolve_list : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_resolve_list() {};
    virtual ~Abstract_resolve_list() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_list : public virtual Abstract_resolve_list {
  public:
    Class_resolve_list();
    virtual ~Class_resolve_list() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func security<-context)
  class Abstract_security_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_security_from_context() {};
    virtual ~Abstract_security_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_security_from_context : public virtual Abstract_security_from_context {
  public:
    Class_security_from_context();
    virtual ~Class_security_from_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func security<-user)
  class Abstract_security_from_user : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_security_from_user() {};
    virtual ~Abstract_security_from_user() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_security_from_user : public virtual Abstract_security_from_user {
  public:
    Class_security_from_user();
    virtual ~Class_security_from_user() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func session<-context)
  class Abstract_session_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_session_from_context() {};
    virtual ~Abstract_session_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_session_from_context : public virtual Abstract_session_from_context {
  public:
    Class_session_from_context();
    virtual ~Class_session_from_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func setting<-context)
  class Abstract_setting_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_setting_from_context() {};
    virtual ~Abstract_setting_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_setting_from_context : public virtual Abstract_setting_from_context {
  public:
    Class_setting_from_context();
    virtual ~Class_setting_from_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string-repeat)
  class Abstract_string_repeat : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_repeat() {};
    virtual ~Abstract_string_repeat() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_repeat : public virtual Abstract_string_repeat {
  public:
    Class_string_repeat();
    virtual ~Class_string_repeat() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string<-any)
  class Abstract_string_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_any() {};
    virtual ~Abstract_string_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_any : public virtual Abstract_string_from_any {
  public:
    Class_string_from_any();
    virtual ~Class_string_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string<-any-indent)
  class Abstract_string_from_any_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_any_indent() {};
    virtual ~Abstract_string_from_any_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_any_indent : public virtual Abstract_string_from_any_indent {
  public:
    Class_string_from_any_indent();
    virtual ~Class_string_from_any_indent() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string<-func)
  class Abstract_string_from_func : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_func() {};
    virtual ~Abstract_string_from_func() = 0;
    typedef std::function<vx_core::Type_string()> IFn;
    IFn fn;
    vx_core::vx_Type_listany lambdavars;
    virtual vx_core::Func_string_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_string_from_func::IFn fn) const = 0;
    virtual vx_core::Type_string vx_string_from_func() const = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_func : public virtual Abstract_string_from_func {
  public:
    Class_string_from_func();
    virtual ~Class_string_from_func() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_string_from_func vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_string_from_func::IFn fn) const;
    virtual vx_core::Type_string vx_string_from_func() const;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func traits<-typedef)
  class Abstract_traits_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_traits_from_typedef() {};
    virtual ~Abstract_traits_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_traits_from_typedef : public virtual Abstract_traits_from_typedef {
  public:
    Class_traits_from_typedef();
    virtual ~Class_traits_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func type<-any)
  class Abstract_type_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_type_from_any() {};
    virtual ~Abstract_type_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_type_from_any : public virtual Abstract_type_from_any {
  public:
    Class_type_from_any();
    virtual ~Class_type_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typedef<-any)
  class Abstract_typedef_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typedef_from_any() {};
    virtual ~Abstract_typedef_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typedef_from_any : public virtual Abstract_typedef_from_any {
  public:
    Class_typedef_from_any();
    virtual ~Class_typedef_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typedef<-type)
  class Abstract_typedef_from_type : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typedef_from_type() {};
    virtual ~Abstract_typedef_from_type() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typedef_from_type : public virtual Abstract_typedef_from_type {
  public:
    Class_typedef_from_type();
    virtual ~Class_typedef_from_type() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typename<-any)
  class Abstract_typename_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typename_from_any() {};
    virtual ~Abstract_typename_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typename_from_any : public virtual Abstract_typename_from_any {
  public:
    Class_typename_from_any();
    virtual ~Class_typename_from_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typename<-type)
  class Abstract_typename_from_type : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typename_from_type() {};
    virtual ~Abstract_typename_from_type() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typename_from_type : public virtual Abstract_typename_from_type {
  public:
    Class_typename_from_type();
    virtual ~Class_typename_from_type() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typename<-typedef)
  class Abstract_typename_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typename_from_typedef() {};
    virtual ~Abstract_typename_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typename_from_typedef : public virtual Abstract_typename_from_typedef {
  public:
    Class_typename_from_typedef();
    virtual ~Class_typename_from_typedef() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func typenames<-typelist)
  class Abstract_typenames_from_typelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typenames_from_typelist() {};
    virtual ~Abstract_typenames_from_typelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typenames_from_typelist : public virtual Abstract_typenames_from_typelist {
  public:
    Class_typenames_from_typelist();
    virtual ~Class_typenames_from_typelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func user<-context)
  class Abstract_user_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_user_from_context() {};
    virtual ~Abstract_user_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_user_from_context : public virtual Abstract_user_from_context {
  public:
    Class_user_from_context();
    virtual ~Class_user_from_context() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-any)
  template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(value);
    output = vx_core::vx_any_from_any(generic_any_1, value);
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func any<-any-async)
  template <class T, class U> vx_core::vx_Type_async f_any_from_any_async(T* generic_any_1, U* value) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(value);
    vx_core::vx_release_one(value);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-any-context)
  template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context context) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(value);
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func any<-any-context-async)
  template <class T, class U> vx_core::vx_Type_async f_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context context) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(value);
    vx_core::vx_release_one(value);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-func)
  template <class T> T* f_any_from_func(T* generic_any_1) {
    T* output = vx_core::vx_empty(generic_any_1);
    return output;
  }

  // (func any<-func-async)
  template <class T> vx_core::vx_Type_async f_any_from_func_async(T* generic_any_1) {
    vx_core::vx_Type_async output = NULL;
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-key-value)
  template <class T, class U> T* f_any_from_key_value(T* generic_any_1, vx_core::Type_string key, U* val) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({key, val});
    vx_core::vx_release_one_except({key, val}, output);
    return output;
  }

  // (func any<-key-value-async)
  template <class T, class U> vx_core::vx_Type_async f_any_from_key_value_async(T* generic_any_1, vx_core::Type_string key, U* val) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({key, val});
    vx_core::vx_release_one({key, val});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-list)
  template <class T, class X> T* f_any_from_list(T* generic_any_1, X* values, vx_core::Type_int index) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({values, index});
    long intindex = index->vx_int();
    vx_core::vx_Type_listany listvalue = values->vx_list();
    long intsize = vx_core::vx_int_from_sizet(listvalue.size());
    if (intindex < intsize) {
      vx_core::Type_any value = listvalue[intindex];
      output = vx_core::vx_any_from_any(generic_any_1, value);
    };
    vx_core::vx_release_one_except({values, index}, output);
    return output;
  }

  // (func any<-list-reduce)
  template <class T, class Y> T* f_any_from_list_reduce(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce fn_reduce) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({list, valstart, fn_reduce});
    vx_core::Type_any work = valstart;
    std::vector<vx_core::Type_any> listval = list->vx_list();
    for (vx_core::Type_any item : listval) {
      work = fn_reduce->vx_any_from_reduce(work, item);
    };
    output = vx_core::vx_any_from_any(generic_any_1, work);
    vx_core::vx_release_one_except({list, valstart, fn_reduce}, output);
    return output;
  }

  // (func any<-list-reduce-next)
  template <class T, class Y> T* f_any_from_list_reduce_next(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce_next fn_reduce_next) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({list, valstart, fn_reduce_next});
    vx_core::Type_any result = vx_core::vx_any_from_list_result_next(generic_any_1, list, valstart, fn_reduce_next);
    output = vx_core::vx_any_from_any(generic_any_1, result);
    vx_core::vx_release_one_except({list, valstart, fn_reduce_next}, output);
    return output;
  }

  // (func any<-map)
  template <class T, class N> T* f_any_from_map(T* generic_any_1, N* valuemap, vx_core::Type_string key) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({valuemap, key});
    vx_core::Type_any val = valuemap->vx_get_any(key);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    vx_core::vx_release_one_except({valuemap, key}, output);
    return output;
  }

  // (func any<-none)
  template <class T> T* f_any_from_none(T* generic_any_1) {
    T* output = vx_core::vx_empty(generic_any_1);
    return output;
  }

  // (func any<-none-async)
  template <class T> vx_core::vx_Type_async f_any_from_none_async(T* generic_any_1) {
    vx_core::vx_Type_async output = NULL;
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-reduce)
  template <class T, class U> T* f_any_from_reduce(T* generic_any_1, T* result, U* item) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({result, item});
    vx_core::vx_release_one_except({result, item}, output);
    return output;
  }

  // (func any<-reduce-async)
  template <class T, class U> vx_core::vx_Type_async f_any_from_reduce_async(T* generic_any_1, T* result, U* item) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({result, item});
    vx_core::vx_release_one({result, item});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-reduce-next)
  template <class T, class U> T* f_any_from_reduce_next(T* generic_any_1, T* result, U* current, U* next) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({result, current, next});
    vx_core::vx_release_one_except({result, current, next}, output);
    return output;
  }

  // (func any<-reduce-next-async)
  template <class T, class U> vx_core::vx_Type_async f_any_from_reduce_next_async(T* generic_any_1, T* result, U* current, U* next) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({result, current, next});
    vx_core::vx_release_one({result, current, next});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func any<-struct)
  template <class T, class R> T* f_any_from_struct(T* generic_any_1, R* vstruct, vx_core::Type_string key) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({vstruct, key});
    vx_core::Type_any val = vstruct->vx_get_any(key);
    output = vx_core::vx_any_from_any(generic_any_1, val);
    vx_core::vx_release_one_except({vstruct, key}, output);
    return output;
  }

  // (func async)
  template <class T> vx_core::vx_Type_async f_async(T* generic_any_1, T* value) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(value);
    vx_core::vx_release_one(value);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func empty)
  template <class T> T* f_empty(T* type) {
    vx_core::vx_reserve(type);
    T* output = vx_core::vx_any_from_any(type, type->vx_empty());
    vx_core::vx_release_one_except(type, output);
    return output;
  }

  // (func new)
  template <class T> T* f_new(T* type, vx_core::Type_anylist values) {
    vx_core::vx_reserve({type, values});
    T* output = vx_core::vx_new(type, values->vx_list());
    vx_core::vx_release_one_except({type, values}, output);
    return output;
  }

  // (func copy)
  template <class T> T* f_copy(T* generic_any_1, vx_core::Type_any value, vx_core::Type_anylist values) {
    vx_core::vx_reserve({value, values});
    T* output = vx_core::vx_copy(generic_any_1, value, values->vx_list());
    vx_core::vx_release_one_except({value, values}, output);
    return output;
  }

  // (func if)
  template <class T> T* f_if(T* generic_any_1, vx_core::Type_boolean clause, T* then) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({clause, then});
    if (clause->vx_boolean()) {
      output = then;
    };
    vx_core::vx_release_one_except({clause, then}, output);
    return output;
  }

  // (func if)
  template <class T> T* f_if_1(T* generic_any_1, vx_core::Type_boolean clause, T* thenval, T* elseval) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({clause, thenval, elseval});
    if (clause->vx_boolean()) {
      output = thenval;
    } else {
      output = elseval;
    };
    vx_core::vx_release_one_except({clause, thenval, elseval}, output);
    return output;
  }

  // (func if)
  template <class T> T* f_if_2(T* generic_any_1, vx_core::Type_thenelselist thenelselist) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(thenelselist);
    vx_core::Type_any any = vx_core::vx_if_thenelselist(generic_any_1, thenelselist);
    output = vx_core::vx_any_from_any(generic_any_1, any);
    vx_core::vx_release_one_except(thenelselist, output);
    return output;
  }

  // (func switch)
  template <class T, class U> T* f_switch(T* generic_any_1, U* val, vx_core::Type_thenelselist thenelselist) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({val, thenelselist});
    vx_core::Type_any any = vx_core::vx_switch(generic_any_1, val, thenelselist);
    output = vx_core::vx_any_from_any(generic_any_1, any);
    vx_core::vx_release_one_except({val, thenelselist}, output);
    return output;
  }

  // (func let)
  template <class T> T* f_let(T* generic_any_1, vx_core::Func_any_from_func fn_any) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(fn_any);
    vx_core::Type_any any = fn_any->vx_any_from_func();
    output = vx_core::vx_any_from_any(generic_any_1, any);
    vx_core::vx_release_one_except(fn_any, output);
    return output;
  }

  // (func let-async)
  template <class T> vx_core::vx_Type_async f_let_async(T* generic_any_1, vx_core::Func_any_from_func_async fn_any_async) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(fn_any_async);
    output = fn_any_async->vx_any_from_func_async(generic_any_1);
    vx_core::vx_release_one(fn_any_async);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func <-)
  template <class T> T* f_chainfirst(T* generic_any_1, T* value, vx_core::Type_any_from_anylist fnlist) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({value, fnlist});
    vx_core::vx_release_one_except({value, fnlist}, output);
    return output;
  }

  // (func <<-)
  template <class T> T* f_chainlast(T* generic_any_1, T* value, vx_core::Type_any_from_anylist fnlist) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({value, fnlist});
    vx_core::vx_release_one_except({value, fnlist}, output);
    return output;
  }

  // (func any<-int)
  template <class T> T* f_any_from_int(T* generic_any_1, vx_core::Type_int value) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(value);
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func first<-list)
  template <class T, class X> T* f_first_from_list(T* generic_any_1, X* values) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(values);
    output = vx_core::f_any_from_list(generic_any_1, values, vx_core::vx_new_int(0));
    vx_core::vx_release_one_except(values, output);
    return output;
  }

  // (func first<-list-fn-any<-any)
  template <class T, class X> T* f_first_from_list_fn_any_from_any(T* generic_any_1, X* values, vx_core::Func_any_from_any fn_any_from_any) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({values, fn_any_from_any});
    std::vector<vx_core::Type_any> listvalue = values->vx_list();
    for (vx_core::Type_any value : listvalue) {
      if (value != vx_core::c_nothing) {
        vx_core::Type_any any = fn_any_from_any->vx_any_from_any(value);
        output = vx_core::vx_any_from_any(generic_any_1, any);
        break;
      }
    };
    vx_core::vx_release_one_except({values, fn_any_from_any}, output);
    return output;
  }

  // (func fn)
  template <class T> T* f_fn(T* generic_any_1, vx_core::Type_arglist params, vx_core::Func_any_from_func fn_any) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({params, fn_any});
    vx_core::vx_release_one_except({params, fn_any}, output);
    return output;
  }

  // (func last<-list)
  template <class T, class X> T* f_last_from_list(T* generic_any_1, X* values) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(values);
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({values, generic_any_1}, [values, generic_any_1]() {
        vx_core::Type_int len = vx_core::f_length_from_list(values);
        vx_core::vx_ref_plus(len);
        vx_core::Type_int last = vx_core::f_minus(len, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(last);
        vx_core::Type_any output_1 = vx_core::f_any_from_list(generic_any_1, values, last);
        vx_core::vx_release_one_except({len, last}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(values, output);
    return output;
  }

  // (func list-join<-list)
  template <class X, class Y> X* f_list_join_from_list(X* generic_list_1, Y* values, vx_core::Func_any_from_any fn_any_from_any) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({values, fn_any_from_any});
    vx_core::Type_any list = vx_core::vx_list_join_from_list_fn(generic_list_1, values, fn_any_from_any);
    output = vx_core::vx_any_from_any(generic_list_1, list);
    vx_core::vx_release_one_except({values, fn_any_from_any}, output);
    return output;
  }

  // (func list<-list)
  template <class X, class Y> X* f_list_from_list(X* generic_list_1, Y* values, vx_core::Func_any_from_any fn_any_from_any) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({values, fn_any_from_any});
    vx_core::vx_Type_listany list_value = values->vx_list();
    vx_core::vx_Type_listany list_result = vx_core::vx_listany_from_listany_fn(list_value, [fn_any_from_any](vx_core::Type_any val) {
      return fn_any_from_any->vx_any_from_any(val);
    });
    vx_core::Type_any anylist = generic_list_1->vx_new(list_result);
    output = vx_core::vx_any_from_any(generic_list_1, anylist);
    vx_core::vx_release_one_except({values, fn_any_from_any}, output);
    return output;
  }

  // (func list<-list-async)
  template <class X, class Y> vx_core::vx_Type_async f_list_from_list_async(X* generic_list_1, Y* values, vx_core::Func_any_from_any_async fn_any_from_any_async) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({values, fn_any_from_any_async});
    vx_core::vx_Type_listany list_value = values->vx_list();
    vx_core::vx_Type_listasync list_async_result = vx_core::vx_listasync_from_listany_fn(list_value, [fn_any_from_any_async](vx_core::Type_any val) {
      return fn_any_from_any_async->vx_any_from_any_async(vx_core::vx_type(val), val);
    });
    output = vx_core::vx_async_new_from_listasync(generic_list_1, list_async_result);
    vx_core::vx_release_one({values, fn_any_from_any_async});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_list_1));
    }
    return output;
  }

  // (func list<-map)
  template <class X, class O> X* f_list_from_map(X* generic_list_1, O* valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({valuemap, fn_any_from_key_value});
    vx_core::Type_any list = vx_core::vx_list_from_map_fn(generic_list_1, valuemap, fn_any_from_key_value);
    output = vx_core::vx_any_from_any(generic_list_1, list);
    vx_core::vx_release_one_except({valuemap, fn_any_from_key_value}, output);
    return output;
  }

  // (func list<-map-async)
  template <class X, class O> vx_core::vx_Type_async f_list_from_map_async(X* generic_list_1, O* valuemap, vx_core::Func_any_from_key_value_async fn_any_from_key_value_async) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({valuemap, fn_any_from_key_value_async});
    vx_core::vx_release_one({valuemap, fn_any_from_key_value_async});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_list_1));
    }
    return output;
  }

  // (func map<-list)
  template <class Y, class N> N* f_map_from_list(N* generic_map_1, Y* vallist, vx_core::Func_any_from_any fn_any_from_any) {
    N* output = vx_core::vx_empty(generic_map_1);
    vx_core::vx_reserve({vallist, fn_any_from_any});
    vx_core::vx_Type_listany listany = vallist->vx_list();
    vx_core::vx_Type_mapany mapany = vx_core::vx_map_from_list(listany, fn_any_from_any);
    output = vx_core::vx_new_from_map(generic_map_1, mapany);
    vx_core::vx_release_one_except({vallist, fn_any_from_any}, output);
    return output;
  }

  // (func native)
  template <class T> T* f_native(T* generic_any_1, vx_core::Type_anylist clauses) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(clauses);
    vx_core::vx_release_one_except(clauses, output);
    return output;
  }

  // (func resolve)
  template <class T> T* f_resolve(T* generic_any_1, T* value) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(value);
    output = value;
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func resolve)
  template <class T> T* f_resolve_1(T* generic_any_1, vx_core::Func_any_from_func fn_any) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(fn_any);
    if (fn_any) {
      vx_core::Type_any any = fn_any->vx_any_from_func();
      output = vx_core::vx_any_from_any(generic_any_1, any);
    };
    vx_core::vx_release_one_except(fn_any, output);
    return output;
  }

  // (func resolve-async)
  template <class T> vx_core::vx_Type_async f_resolve_async(T* generic_any_1, vx_core::Func_any_from_func_async fn_any) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(fn_any);
    if (fn_any) {
      output = fn_any->vx_any_from_func_async(generic_any_1);
    };
    vx_core::vx_release_one(fn_any);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));
    }
    return output;
  }

  // (func resolve-first)
  template <class T, class X> T* f_resolve_first(T* generic_any_1, X* clauses) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(clauses);
    output = vx_core::f_first_from_list_fn_any_from_any(
      generic_any_1,
      clauses,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any value) {
        vx_core::Type_any output_1 = vx_core::f_resolve(vx_core::t_any, value);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(clauses, output);
    return output;
  }

  // (func resolve-list)
  template <class X> X* f_resolve_list(X* generic_list_1, X* clauses) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve(clauses);
    output = vx_core::f_list_from_list(
      generic_list_1,
      clauses,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any value) {
        vx_core::Type_any output_1 = vx_core::f_resolve(vx_core::t_any, value);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(clauses, output);
    return output;
  }

  class vx_Class_package : vx_core::vx_Abstract_package {
  public:
    vx_Class_package();
    void init();
    vx_core::vx_Type_mapany maptype();
    vx_core::vx_Type_mapany mapconst();
    vx_core::vx_Type_mapfunc mapfunc();
  };
  inline vx_Class_package const vx_package;

}
#endif
