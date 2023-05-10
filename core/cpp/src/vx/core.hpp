#pragma once
#include <any>
#include <exception>
#include <functional>
#include <future>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace vx_core {

  // forward declarations
  class Type_any;
  extern Type_any* e_any;
  extern Type_any* t_any;
  class Type_any_async_from_func;
  extern Type_any_async_from_func* e_any_async_from_func;
  extern Type_any_async_from_func* t_any_async_from_func;
  class Type_any_from_anylist;
  extern Type_any_from_anylist* e_any_from_anylist;
  extern Type_any_from_anylist* t_any_from_anylist;
  class Type_anylist;
  extern Type_anylist* e_anylist;
  extern Type_anylist* t_anylist;
  class Type_anytype;
  extern Type_anytype* e_anytype;
  extern Type_anytype* t_anytype;
  class Type_arg;
  extern Type_arg* e_arg;
  extern Type_arg* t_arg;
  class Type_arglist;
  extern Type_arglist* e_arglist;
  extern Type_arglist* t_arglist;
  class Type_argmap;
  extern Type_argmap* e_argmap;
  extern Type_argmap* t_argmap;
  class Type_boolean;
  extern Type_boolean* e_boolean;
  extern Type_boolean* t_boolean;
  class Type_booleanlist;
  extern Type_booleanlist* e_booleanlist;
  extern Type_booleanlist* t_booleanlist;
  class Type_collection;
  extern Type_collection* e_collection;
  extern Type_collection* t_collection;
  class Type_compilelanguages;
  extern Type_compilelanguages* e_compilelanguages;
  extern Type_compilelanguages* t_compilelanguages;
  class Type_connect;
  extern Type_connect* e_connect;
  extern Type_connect* t_connect;
  class Type_connectlist;
  extern Type_connectlist* e_connectlist;
  extern Type_connectlist* t_connectlist;
  class Type_connectmap;
  extern Type_connectmap* e_connectmap;
  extern Type_connectmap* t_connectmap;
  class Type_const;
  extern Type_const* e_const;
  extern Type_const* t_const;
  class Type_constdef;
  extern Type_constdef* e_constdef;
  extern Type_constdef* t_constdef;
  class Type_constlist;
  extern Type_constlist* e_constlist;
  extern Type_constlist* t_constlist;
  class Type_constmap;
  extern Type_constmap* e_constmap;
  extern Type_constmap* t_constmap;
  class Type_context;
  extern Type_context* e_context;
  extern Type_context* t_context;
  class Type_decimal;
  extern Type_decimal* e_decimal;
  extern Type_decimal* t_decimal;
  class Type_error;
  extern Type_error* e_error;
  extern Type_error* t_error;
  class Type_float;
  extern Type_float* e_float;
  extern Type_float* t_float;
  class Type_func;
  extern Type_func* e_func;
  extern Type_func* t_func;
  class Type_funcdef;
  extern Type_funcdef* e_funcdef;
  extern Type_funcdef* t_funcdef;
  class Type_funclist;
  extern Type_funclist* e_funclist;
  extern Type_funclist* t_funclist;
  class Type_funcmap;
  extern Type_funcmap* e_funcmap;
  extern Type_funcmap* t_funcmap;
  class Type_int;
  extern Type_int* e_int;
  extern Type_int* t_int;
  class Type_intlist;
  extern Type_intlist* e_intlist;
  extern Type_intlist* t_intlist;
  class Type_intmap;
  extern Type_intmap* e_intmap;
  extern Type_intmap* t_intmap;
  class Type_list;
  extern Type_list* e_list;
  extern Type_list* t_list;
  class Type_listtype;
  extern Type_listtype* e_listtype;
  extern Type_listtype* t_listtype;
  class Type_map;
  extern Type_map* e_map;
  extern Type_map* t_map;
  class Type_maptype;
  extern Type_maptype* e_maptype;
  extern Type_maptype* t_maptype;
  class Type_mempool;
  extern Type_mempool* e_mempool;
  extern Type_mempool* t_mempool;
  class Type_msg;
  extern Type_msg* e_msg;
  extern Type_msg* t_msg;
  class Type_msgblock;
  extern Type_msgblock* e_msgblock;
  extern Type_msgblock* t_msgblock;
  class Type_msgblocklist;
  extern Type_msgblocklist* e_msgblocklist;
  extern Type_msgblocklist* t_msgblocklist;
  class Type_msglist;
  extern Type_msglist* e_msglist;
  extern Type_msglist* t_msglist;
  class Type_none;
  extern Type_none* e_none;
  extern Type_none* t_none;
  class Type_notype;
  extern Type_notype* e_notype;
  extern Type_notype* t_notype;
  class Type_number;
  extern Type_number* e_number;
  extern Type_number* t_number;
  class Type_numberlist;
  extern Type_numberlist* e_numberlist;
  extern Type_numberlist* t_numberlist;
  class Type_numbermap;
  extern Type_numbermap* e_numbermap;
  extern Type_numbermap* t_numbermap;
  class Type_package;
  extern Type_package* e_package;
  extern Type_package* t_package;
  class Type_packagemap;
  extern Type_packagemap* e_packagemap;
  extern Type_packagemap* t_packagemap;
  class Type_permission;
  extern Type_permission* e_permission;
  extern Type_permission* t_permission;
  class Type_permissionlist;
  extern Type_permissionlist* e_permissionlist;
  extern Type_permissionlist* t_permissionlist;
  class Type_permissionmap;
  extern Type_permissionmap* e_permissionmap;
  extern Type_permissionmap* t_permissionmap;
  class Type_security;
  extern Type_security* e_security;
  extern Type_security* t_security;
  class Type_session;
  extern Type_session* e_session;
  extern Type_session* t_session;
  class Type_setting;
  extern Type_setting* e_setting;
  extern Type_setting* t_setting;
  class Type_state;
  extern Type_state* e_state;
  extern Type_state* t_state;
  class Type_statelistener;
  extern Type_statelistener* e_statelistener;
  extern Type_statelistener* t_statelistener;
  class Type_string;
  extern Type_string* e_string;
  extern Type_string* t_string;
  class Type_stringlist;
  extern Type_stringlist* e_stringlist;
  extern Type_stringlist* t_stringlist;
  class Type_stringmap;
  extern Type_stringmap* e_stringmap;
  extern Type_stringmap* t_stringmap;
  class Type_struct;
  extern Type_struct* e_struct;
  extern Type_struct* t_struct;
  class Type_thenelse;
  extern Type_thenelse* e_thenelse;
  extern Type_thenelse* t_thenelse;
  class Type_thenelselist;
  extern Type_thenelselist* e_thenelselist;
  extern Type_thenelselist* t_thenelselist;
  class Type_type;
  extern Type_type* e_type;
  extern Type_type* t_type;
  class Type_typedef;
  extern Type_typedef* e_typedef;
  extern Type_typedef* t_typedef;
  class Type_typelist;
  extern Type_typelist* e_typelist;
  extern Type_typelist* t_typelist;
  class Type_typemap;
  extern Type_typemap* e_typemap;
  extern Type_typemap* t_typemap;
  class Type_user;
  extern Type_user* e_user;
  extern Type_user* t_user;
  class Type_value;
  extern Type_value* e_value;
  extern Type_value* t_value;
  class Const_false;
  extern Const_false* c_false;
  class Const_globalpackagemap;
  extern Const_globalpackagemap* c_globalpackagemap;
  class Const_infinity;
  extern Const_infinity* c_infinity;
  class Const_mempool_active;
  extern Const_mempool_active* c_mempool_active;
  class Const_msg_error;
  extern Const_msg_error* c_msg_error;
  class Const_msg_info;
  extern Const_msg_info* c_msg_info;
  class Const_msg_severe;
  extern Const_msg_severe* c_msg_severe;
  class Const_msg_warning;
  extern Const_msg_warning* c_msg_warning;
  class Const_neginfinity;
  extern Const_neginfinity* c_neginfinity;
  class Const_newline;
  extern Const_newline* c_newline;
  class Const_notanumber;
  extern Const_notanumber* c_notanumber;
  class Const_nothing;
  extern Const_nothing* c_nothing;
  class Const_quote;
  extern Const_quote* c_quote;
  class Const_true;
  extern Const_true* c_true;
  class Func_not;
  extern Func_not* e_not;
  extern Func_not* t_not;
  class Func_notempty;
  extern Func_notempty* e_notempty;
  extern Func_notempty* t_notempty;
  class Func_notempty;
  extern Func_notempty* e_notempty;
  extern Func_notempty* t_notempty;
  class Func_ne;
  extern Func_ne* e_ne;
  extern Func_ne* t_ne;
  class Func_multiply;
  extern Func_multiply* e_multiply;
  extern Func_multiply* t_multiply;
  class Func_multiply;
  extern Func_multiply* e_multiply;
  extern Func_multiply* t_multiply;
  class Func_multiply;
  extern Func_multiply* e_multiply;
  extern Func_multiply* t_multiply;
  class Func_multiply;
  extern Func_multiply* e_multiply;
  extern Func_multiply* t_multiply;
  class Func_plus;
  extern Func_plus* e_plus;
  extern Func_plus* t_plus;
  class Func_plus;
  extern Func_plus* e_plus;
  extern Func_plus* t_plus;
  class Func_plus;
  extern Func_plus* e_plus;
  extern Func_plus* t_plus;
  class Func_plus;
  extern Func_plus* e_plus;
  extern Func_plus* t_plus;
  class Func_plus1;
  extern Func_plus1* e_plus1;
  extern Func_plus1* t_plus1;
  class Func_minus;
  extern Func_minus* e_minus;
  extern Func_minus* t_minus;
  class Func_minus;
  extern Func_minus* e_minus;
  extern Func_minus* t_minus;
  class Func_minus;
  extern Func_minus* e_minus;
  extern Func_minus* t_minus;
  class Func_minus;
  extern Func_minus* e_minus;
  extern Func_minus* t_minus;
  class Func_dotmethod;
  extern Func_dotmethod* e_dotmethod;
  extern Func_dotmethod* t_dotmethod;
  class Func_divide;
  extern Func_divide* e_divide;
  extern Func_divide* t_divide;
  class Func_lt;
  extern Func_lt* e_lt;
  extern Func_lt* t_lt;
  class Func_lt;
  extern Func_lt* e_lt;
  extern Func_lt* t_lt;
  class Func_chainfirst;
  extern Func_chainfirst* e_chainfirst;
  extern Func_chainfirst* t_chainfirst;
  class Func_chainlast;
  extern Func_chainlast* e_chainlast;
  extern Func_chainlast* t_chainlast;
  class Func_le;
  extern Func_le* e_le;
  extern Func_le* t_le;
  class Func_le;
  extern Func_le* e_le;
  extern Func_le* t_le;
  class Func_eq;
  extern Func_eq* e_eq;
  extern Func_eq* t_eq;
  class Func_eq;
  extern Func_eq* e_eq;
  extern Func_eq* t_eq;
  class Func_gt;
  extern Func_gt* e_gt;
  extern Func_gt* t_gt;
  class Func_gt;
  extern Func_gt* e_gt;
  extern Func_gt* t_gt;
  class Func_ge;
  extern Func_ge* e_ge;
  extern Func_ge* t_ge;
  class Func_ge;
  extern Func_ge* e_ge;
  extern Func_ge* t_ge;
  class Func_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef* e_allowtypenames_from_typedef;
  extern Func_allowtypenames_from_typedef* t_allowtypenames_from_typedef;
  class Func_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef* e_allowtypes_from_typedef;
  extern Func_allowtypes_from_typedef* t_allowtypes_from_typedef;
  class Func_and;
  extern Func_and* e_and;
  extern Func_and* t_and;
  class Func_and;
  extern Func_and* e_and;
  extern Func_and* t_and;
  class Func_any_from_any;
  extern Func_any_from_any* e_any_from_any;
  extern Func_any_from_any* t_any_from_any;
  class Func_any_from_any_async;
  extern Func_any_from_any_async* e_any_from_any_async;
  extern Func_any_from_any_async* t_any_from_any_async;
  class Func_any_from_any_context;
  extern Func_any_from_any_context* e_any_from_any_context;
  extern Func_any_from_any_context* t_any_from_any_context;
  class Func_any_from_any_context_async;
  extern Func_any_from_any_context_async* e_any_from_any_context_async;
  extern Func_any_from_any_context_async* t_any_from_any_context_async;
  class Func_any_from_func;
  extern Func_any_from_func* e_any_from_func;
  extern Func_any_from_func* t_any_from_func;
  class Func_any_from_func_async;
  extern Func_any_from_func_async* e_any_from_func_async;
  extern Func_any_from_func_async* t_any_from_func_async;
  class Func_any_from_key_value;
  extern Func_any_from_key_value* e_any_from_key_value;
  extern Func_any_from_key_value* t_any_from_key_value;
  class Func_any_from_key_value_async;
  extern Func_any_from_key_value_async* e_any_from_key_value_async;
  extern Func_any_from_key_value_async* t_any_from_key_value_async;
  class Func_any_from_list;
  extern Func_any_from_list* e_any_from_list;
  extern Func_any_from_list* t_any_from_list;
  class Func_any_from_list_reduce;
  extern Func_any_from_list_reduce* e_any_from_list_reduce;
  extern Func_any_from_list_reduce* t_any_from_list_reduce;
  class Func_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next* e_any_from_list_reduce_next;
  extern Func_any_from_list_reduce_next* t_any_from_list_reduce_next;
  class Func_any_from_map;
  extern Func_any_from_map* e_any_from_map;
  extern Func_any_from_map* t_any_from_map;
  class Func_any_from_none;
  extern Func_any_from_none* e_any_from_none;
  extern Func_any_from_none* t_any_from_none;
  class Func_any_from_none_async;
  extern Func_any_from_none_async* e_any_from_none_async;
  extern Func_any_from_none_async* t_any_from_none_async;
  class Func_any_from_reduce;
  extern Func_any_from_reduce* e_any_from_reduce;
  extern Func_any_from_reduce* t_any_from_reduce;
  class Func_any_from_reduce_async;
  extern Func_any_from_reduce_async* e_any_from_reduce_async;
  extern Func_any_from_reduce_async* t_any_from_reduce_async;
  class Func_any_from_reduce_next;
  extern Func_any_from_reduce_next* e_any_from_reduce_next;
  extern Func_any_from_reduce_next* t_any_from_reduce_next;
  class Func_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async* e_any_from_reduce_next_async;
  extern Func_any_from_reduce_next_async* t_any_from_reduce_next_async;
  class Func_any_from_struct;
  extern Func_any_from_struct* e_any_from_struct;
  extern Func_any_from_struct* t_any_from_struct;
  class Func_async;
  extern Func_async* e_async;
  extern Func_async* t_async;
  class Func_boolean_from_any;
  extern Func_boolean_from_any* e_boolean_from_any;
  extern Func_boolean_from_any* t_boolean_from_any;
  class Func_boolean_from_func;
  extern Func_boolean_from_func* e_boolean_from_func;
  extern Func_boolean_from_func* t_boolean_from_func;
  class Func_boolean_from_none;
  extern Func_boolean_from_none* e_boolean_from_none;
  extern Func_boolean_from_none* t_boolean_from_none;
  class Func_case;
  extern Func_case* e_case;
  extern Func_case* t_case;
  class Func_case;
  extern Func_case* e_case;
  extern Func_case* t_case;
  class Func_compare;
  extern Func_compare* e_compare;
  extern Func_compare* t_compare;
  class Func_contains;
  extern Func_contains* e_contains;
  extern Func_contains* t_contains;
  class Func_contains;
  extern Func_contains* e_contains;
  extern Func_contains* t_contains;
  class Func_copy;
  extern Func_copy* e_copy;
  extern Func_copy* t_copy;
  class Func_else;
  extern Func_else* e_else;
  extern Func_else* t_else;
  class Func_empty;
  extern Func_empty* e_empty;
  extern Func_empty* t_empty;
  class Func_extends_from_any;
  extern Func_extends_from_any* e_extends_from_any;
  extern Func_extends_from_any* t_extends_from_any;
  class Func_extends_from_typedef;
  extern Func_extends_from_typedef* e_extends_from_typedef;
  extern Func_extends_from_typedef* t_extends_from_typedef;
  class Func_first_from_list;
  extern Func_first_from_list* e_first_from_list;
  extern Func_first_from_list* t_first_from_list;
  class Func_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any* e_first_from_list_fn_any_from_any;
  extern Func_first_from_list_fn_any_from_any* t_first_from_list_fn_any_from_any;
  class Func_fn;
  extern Func_fn* e_fn;
  extern Func_fn* t_fn;
  class Func_funcdef_from_func;
  extern Func_funcdef_from_func* e_funcdef_from_func;
  extern Func_funcdef_from_func* t_funcdef_from_func;
  class Func_funcname_from_funcdef;
  extern Func_funcname_from_funcdef* e_funcname_from_funcdef;
  extern Func_funcname_from_funcdef* t_funcname_from_funcdef;
  class Func_global_package_get;
  extern Func_global_package_get* e_global_package_get;
  extern Func_global_package_get* t_global_package_get;
  class Func_global_package_set;
  extern Func_global_package_set* e_global_package_set;
  extern Func_global_package_set* t_global_package_set;
  class Func_if;
  extern Func_if* e_if;
  extern Func_if* t_if;
  class Func_if;
  extern Func_if* e_if;
  extern Func_if* t_if;
  class Func_if;
  extern Func_if* e_if;
  extern Func_if* t_if;
  class Func_int_from_func;
  extern Func_int_from_func* e_int_from_func;
  extern Func_int_from_func* t_int_from_func;
  class Func_int_from_string;
  extern Func_int_from_string* e_int_from_string;
  extern Func_int_from_string* t_int_from_string;
  class Func_is_empty;
  extern Func_is_empty* e_is_empty;
  extern Func_is_empty* t_is_empty;
  class Func_is_empty;
  extern Func_is_empty* e_is_empty;
  extern Func_is_empty* t_is_empty;
  class Func_is_endswith;
  extern Func_is_endswith* e_is_endswith;
  extern Func_is_endswith* t_is_endswith;
  class Func_is_func;
  extern Func_is_func* e_is_func;
  extern Func_is_func* t_is_func;
  class Func_is_int;
  extern Func_is_int* e_is_int;
  extern Func_is_int* t_is_int;
  class Func_is_number;
  extern Func_is_number* e_is_number;
  extern Func_is_number* t_is_number;
  class Func_is_pass_from_permission;
  extern Func_is_pass_from_permission* e_is_pass_from_permission;
  extern Func_is_pass_from_permission* t_is_pass_from_permission;
  class Func_last_from_list;
  extern Func_last_from_list* e_last_from_list;
  extern Func_last_from_list* t_last_from_list;
  class Func_length_from_list;
  extern Func_length_from_list* e_length_from_list;
  extern Func_length_from_list* t_length_from_list;
  class Func_let;
  extern Func_let* e_let;
  extern Func_let* t_let;
  class Func_let_async;
  extern Func_let_async* e_let_async;
  extern Func_let_async* t_let_async;
  class Func_list_join_from_list;
  extern Func_list_join_from_list* e_list_join_from_list;
  extern Func_list_join_from_list* t_list_join_from_list;
  class Func_list_from_list;
  extern Func_list_from_list* e_list_from_list;
  extern Func_list_from_list* t_list_from_list;
  class Func_list_from_list_async;
  extern Func_list_from_list_async* e_list_from_list_async;
  extern Func_list_from_list_async* t_list_from_list_async;
  class Func_list_from_map;
  extern Func_list_from_map* e_list_from_map;
  extern Func_list_from_map* t_list_from_map;
  class Func_list_from_map_async;
  extern Func_list_from_map_async* e_list_from_map_async;
  extern Func_list_from_map_async* t_list_from_map_async;
  class Func_list_from_type;
  extern Func_list_from_type* e_list_from_type;
  extern Func_list_from_type* t_list_from_type;
  class Func_log;
  extern Func_log* e_log;
  extern Func_log* t_log;
  class Func_map_from_list;
  extern Func_map_from_list* e_map_from_list;
  extern Func_map_from_list* t_map_from_list;
  class Func_mempool_addref;
  extern Func_mempool_addref* e_mempool_addref;
  extern Func_mempool_addref* t_mempool_addref;
  class Func_mempool_release;
  extern Func_mempool_release* e_mempool_release;
  extern Func_mempool_release* t_mempool_release;
  class Func_mempool_removeref;
  extern Func_mempool_removeref* e_mempool_removeref;
  extern Func_mempool_removeref* t_mempool_removeref;
  class Func_mempool_removerefchildren;
  extern Func_mempool_removerefchildren* e_mempool_removerefchildren;
  extern Func_mempool_removerefchildren* t_mempool_removerefchildren;
  class Func_mempool_reserve;
  extern Func_mempool_reserve* e_mempool_reserve;
  extern Func_mempool_reserve* t_mempool_reserve;
  class Func_msg_from_error;
  extern Func_msg_from_error* e_msg_from_error;
  extern Func_msg_from_error* t_msg_from_error;
  class Func_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg* e_msgblock_from_msgblock_msg;
  extern Func_msgblock_from_msgblock_msg* t_msgblock_from_msgblock_msg;
  class Func_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock* e_msgblock_from_msgblock_msgblock;
  extern Func_msgblock_from_msgblock_msgblock* t_msgblock_from_msgblock_msgblock;
  class Func_name_from_typedef;
  extern Func_name_from_typedef* e_name_from_typedef;
  extern Func_name_from_typedef* t_name_from_typedef;
  class Func_native;
  extern Func_native* e_native;
  extern Func_native* t_native;
  class Func_native_from_any;
  extern Func_native_from_any* e_native_from_any;
  extern Func_native_from_any* t_native_from_any;
  class Func_new;
  extern Func_new* e_new;
  extern Func_new* t_new;
  class Func_number_from_func;
  extern Func_number_from_func* e_number_from_func;
  extern Func_number_from_func* t_number_from_func;
  class Func_or;
  extern Func_or* e_or;
  extern Func_or* t_or;
  class Func_or;
  extern Func_or* e_or;
  extern Func_or* t_or;
  class Func_packagename_from_typedef;
  extern Func_packagename_from_typedef* e_packagename_from_typedef;
  extern Func_packagename_from_typedef* t_packagename_from_typedef;
  class Func_path_from_context_path;
  extern Func_path_from_context_path* e_path_from_context_path;
  extern Func_path_from_context_path* t_path_from_context_path;
  class Func_path_from_setting_path;
  extern Func_path_from_setting_path* e_path_from_setting_path;
  extern Func_path_from_setting_path* t_path_from_setting_path;
  class Func_permission_from_id_context;
  extern Func_permission_from_id_context* e_permission_from_id_context;
  extern Func_permission_from_id_context* t_permission_from_id_context;
  class Func_properties_from_typedef;
  extern Func_properties_from_typedef* e_properties_from_typedef;
  extern Func_properties_from_typedef* t_properties_from_typedef;
  class Func_proplast_from_typedef;
  extern Func_proplast_from_typedef* e_proplast_from_typedef;
  extern Func_proplast_from_typedef* t_proplast_from_typedef;
  class Func_resolve;
  extern Func_resolve* e_resolve;
  extern Func_resolve* t_resolve;
  class Func_resolve;
  extern Func_resolve* e_resolve;
  extern Func_resolve* t_resolve;
  class Func_resolve_async;
  extern Func_resolve_async* e_resolve_async;
  extern Func_resolve_async* t_resolve_async;
  class Func_resolve_first;
  extern Func_resolve_first* e_resolve_first;
  extern Func_resolve_first* t_resolve_first;
  class Func_resolve_list;
  extern Func_resolve_list* e_resolve_list;
  extern Func_resolve_list* t_resolve_list;
  class Func_session_from_context;
  extern Func_session_from_context* e_session_from_context;
  extern Func_session_from_context* t_session_from_context;
  class Func_setting_from_context;
  extern Func_setting_from_context* e_setting_from_context;
  extern Func_setting_from_context* t_setting_from_context;
  class Func_string_repeat;
  extern Func_string_repeat* e_string_repeat;
  extern Func_string_repeat* t_string_repeat;
  class Func_string_from_any;
  extern Func_string_from_any* e_string_from_any;
  extern Func_string_from_any* t_string_from_any;
  class Func_string_from_any_indent;
  extern Func_string_from_any_indent* e_string_from_any_indent;
  extern Func_string_from_any_indent* t_string_from_any_indent;
  class Func_string_from_func;
  extern Func_string_from_func* e_string_from_func;
  extern Func_string_from_func* t_string_from_func;
  class Func_switch;
  extern Func_switch* e_switch;
  extern Func_switch* t_switch;
  class Func_then;
  extern Func_then* e_then;
  extern Func_then* t_then;
  class Func_traits_from_typedef;
  extern Func_traits_from_typedef* e_traits_from_typedef;
  extern Func_traits_from_typedef* t_traits_from_typedef;
  class Func_type_from_any;
  extern Func_type_from_any* e_type_from_any;
  extern Func_type_from_any* t_type_from_any;
  class Func_typedef_from_any;
  extern Func_typedef_from_any* e_typedef_from_any;
  extern Func_typedef_from_any* t_typedef_from_any;
  class Func_typedef_from_type;
  extern Func_typedef_from_type* e_typedef_from_type;
  extern Func_typedef_from_type* t_typedef_from_type;
  class Func_typename_from_any;
  extern Func_typename_from_any* e_typename_from_any;
  extern Func_typename_from_any* t_typename_from_any;
  class Func_typename_from_type;
  extern Func_typename_from_type* e_typename_from_type;
  extern Func_typename_from_type* t_typename_from_type;
  class Func_typename_from_typedef;
  extern Func_typename_from_typedef* e_typename_from_typedef;
  extern Func_typename_from_typedef* t_typename_from_typedef;
  class Func_typenames_from_typelist;
  extern Func_typenames_from_typelist* e_typenames_from_typelist;
  extern Func_typenames_from_typelist* t_typenames_from_typelist;
  class Func_user_from_context;
  extern Func_user_from_context* e_user_from_context;
  extern Func_user_from_context* t_user_from_context;

// :headerfirst
  int refcount = 0;

// :header
  extern vx_core::Type_any* t_nativeboolean;
  extern vx_core::Type_any* t_nativefloat;
  extern vx_core::Type_any* t_nativeint;
  extern vx_core::Type_any* t_nativelist;
  extern vx_core::Type_any* t_nativemap;
  extern vx_core::Type_any* t_nativestring;
  extern std::vector<vx_core::Type_any*> emptylistany;
  extern std::map<std::string, vx_core::Type_any*> emptymapany;

  // any_from_any(T, U)
  template <class T, class U> T* any_from_any(T* generic_any_1, U* value);
  // any_from_map(T, T)
  template <class T> T* any_from_map(const std::map<std::string, T*> &map, const std::string key, const T* defaultval);

  // class Async
  template <class T> class Async {
  public:
    std::shared_future<T>* future;
    vx_core::Async<std::any*>* async_parent;
    std::function<T(std::any*)>* fn;
  };

  // async_await(T, async<T>)
  template <class T> static vx_core::Async<T>* async_await(T generic_any_1, vx_core::Async<T>* async);
  // async_from_async(T, async<U>)
  template <class T, class U> static vx_core::Async<T>* async_from_async(T generic_any_1, vx_core::Async<U>* async);
  // async_from_async_fn(T, async<U>, fn<T>(U))
  template <class T, class U> static vx_core::Async<T>* async_from_async_fn(T generic_any_1, vx_core::Async<U>* async, std::function<T(U)> fn);
  // async_new_from_val (T)
  template <class T> static vx_core::Async<T>* async_new_from_val (T val);

  // boolean_contains_from_set_val(set<T>, val)
  template <class T> bool boolean_contains_from_set_val(std::set<T> set, T val);
  // keyset_from_map(map)
  template <class T> std::set<T> keyset_from_map(std::map<std::string, T> map);
  // list_from_list(T, list<U>)
  template <class T, class U> std::vector<T*> list_from_list(T* generic_any_1, std::vector<U*> list);
  // listaddall(list, listadd)
  template <class T> std::vector<T*> listaddall(std::vector<T*> listtarget, std::vector<T*> listadd);
  // map_from_map(T, map<U>)
  template <class T, class U> std::map<std::string, T*> map_from_map(T* generic_any_1, std::map<std::string, U*> map);
  // string_from_any(val)
  std::string string_from_any(std::any);

  // sync_from_async(generic_any_1, async)
  template <class T> T sync_from_async(T generic_any_1, Async<T>* async);

  class Type_replfunc {
  public:
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
  };

  class Type_replfunc_async {
  public:
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
  };


  // (type any)
  class Type_any : public std::any {
  public:
    int vx_iref;
    vx_core::Type_msgblock* vx_p_msgblock;
    virtual vx_core::Type_msgblock* vx_msgblock();
    virtual std::vector<vx_core::Type_any*> vx_dispose();
    virtual bool vx_release();
    virtual void vx_reserve();
    template<class... Args> vx_core::Type_any* vx_new(Args*... args);
    template<class... Args> vx_core::Type_any* vx_copy(Args*... args);
    virtual vx_core::Type_any* vx_empty();
    virtual vx_core::Type_any* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Type_any* vx_type_from_any(std::any* value);
  };

  // (type list)
  class Type_list : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_list* vx_new(Args*... args);
    template<class... Args> vx_core::Type_list* vx_copy(Args*... args);
    virtual vx_core::Type_list* vx_empty();
    virtual vx_core::Type_list* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    std::vector<vx_core::Type_any*> vx_p_list;
    virtual std::vector<vx_core::Type_any*> vx_list();
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
  };

  // (type map)
  class Type_map : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_map* vx_new(Args*... args);
    template<class... Args> vx_core::Type_map* vx_copy(Args*... args);
    virtual vx_core::Type_map* vx_empty();
    virtual vx_core::Type_map* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    std::map<std::string, vx_core::Type_any*> vx_p_map;
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    virtual vx_core::Type_map* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type struct)
  class Type_struct : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_struct* vx_new(Args*... args);
    template<class... Args> vx_core::Type_struct* vx_copy(Args*... args);
    virtual vx_core::Type_struct* vx_empty();
    virtual vx_core::Type_struct* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };

  // (type boolean)
  class Type_boolean : public virtual vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_boolean* vx_new(Args*... args);
    template<class... Args> vx_core::Type_boolean* vx_copy(Args*... args);
    virtual vx_core::Type_boolean* vx_empty();
    virtual vx_core::Type_boolean* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    bool vx_p_boolean = false;
    bool vx_boolean();
    vx_core::Type_boolean* vx_new_from_boolean(bool isval);
  };

  // (type number)
  class Type_number : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_number* vx_new(Args*... args);
    template<class... Args> vx_core::Type_number* vx_copy(Args*... args);
    virtual vx_core::Type_number* vx_empty();
    virtual vx_core::Type_number* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type decimal)
  class Type_decimal : public virtual vx_core::Type_number {
  public:
    template<class... Args> vx_core::Type_decimal* vx_new(Args*... args);
    template<class... Args> vx_core::Type_decimal* vx_copy(Args*... args);
    virtual vx_core::Type_decimal* vx_empty();
    virtual vx_core::Type_decimal* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    std::string vx_decimal = "0.0";
    float vx_float();
    std::string vx_string();
    vx_core::Type_decimal* vx_new_from_string(std::string sval);
  };

  // (type float)
  class Type_float : public virtual vx_core::Type_number {
  public:
    template<class... Args> vx_core::Type_float* vx_new(Args*... args);
    template<class... Args> vx_core::Type_float* vx_copy(Args*... args);
    virtual vx_core::Type_float* vx_empty();
    virtual vx_core::Type_float* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    float vx_p_float = 0;
    float vx_float();
    vx_core::Type_float* vx_new_from_float(float fval);
  };

  // (type int)
  class Type_int : public vx_core::Type_number {
  public:
    template<class... Args> vx_core::Type_int* vx_new(Args*... args);
    template<class... Args> vx_core::Type_int* vx_copy(Args*... args);
    virtual vx_core::Type_int* vx_empty();
    virtual vx_core::Type_int* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    int vx_p_int = 0;
    int vx_int();
    vx_core::Type_int* vx_new_from_int(int ival);
  };

  // (type string)
  class Type_string : public virtual vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_string* vx_new(Args*... args);
    template<class... Args> vx_core::Type_string* vx_copy(Args*... args);
    virtual vx_core::Type_string* vx_empty();
    virtual vx_core::Type_string* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    std::string vx_p_string = "";
    std::string vx_string();
    vx_core::Type_string* vx_new_from_string(std::string text);
  };

  // (type func)
  class Type_func : public virtual vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_func* vx_new(Args*... args);
    template<class... Args> vx_core::Type_func* vx_copy(Args*... args);
    virtual vx_core::Type_func* vx_empty();
    virtual vx_core::Type_func* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Type_funcdef* vx_funcdef();
  };

  // (func any<-any)
  class Func_any_from_any : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_any* vx_empty();
    virtual vx_core::Func_any_from_any* vx_type();
    typedef std::function<vx_core::Type_any*(vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_any_from_any(T* generic_any_1, U* value);
  };

  // (func any<-func)
  class Func_any_from_func : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_func* vx_empty();
    virtual vx_core::Func_any_from_func* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_func* fn_new(vx_core::Func_any_from_func::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_any_from_func(T* generic_any_1);
  };

  // (type any-async<-func)
  class Type_any_async_from_func : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_any_async_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Type_any_async_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_any_async_from_func* vx_empty();
    virtual vx_core::Type_any_async_from_func* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type any<-anylist)
  class Type_any_from_anylist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_any_from_anylist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_any_from_anylist* vx_copy(Args*... args);
    virtual vx_core::Type_any_from_anylist* vx_empty();
    virtual vx_core::Type_any_from_anylist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Func_any_from_any*> vx_p_list;

    // vx_listany_from_any()
    virtual std::vector<vx_core::Func_any_from_any*> vx_listany_from_any();
    // vx_any_from_any(index)
    virtual vx_core::Func_any_from_any* vx_any_from_any(vx_core::Type_int* index);
  };

  // (type anylist)
  class Type_anylist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_anylist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_anylist* vx_copy(Args*... args);
    virtual vx_core::Type_anylist* vx_empty();
    virtual vx_core::Type_anylist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_any*> vx_p_list;

  };

  // (type anytype)
  class Type_anytype : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_anytype* vx_new(Args*... args);
    template<class... Args> vx_core::Type_anytype* vx_copy(Args*... args);
    virtual vx_core::Type_anytype* vx_empty();
    virtual vx_core::Type_anytype* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type arg)
  class Type_arg : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_arg* vx_new(Args*... args);
    template<class... Args> vx_core::Type_arg* vx_copy(Args*... args);
    virtual vx_core::Type_arg* vx_empty();
    virtual vx_core::Type_arg* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // argtype()
    vx_core::Type_type* vx_p_argtype;
    virtual vx_core::Type_type* argtype();
    // fn-any()
    vx_core::Func_any_from_func* vx_p_fn_any;
    virtual vx_core::Func_any_from_func* fn_any();
  };

  // (type arglist)
  class Type_arglist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_arglist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_arglist* vx_copy(Args*... args);
    virtual vx_core::Type_arglist* vx_empty();
    virtual vx_core::Type_arglist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_arg*> vx_p_list;

    // vx_listarg()
    virtual std::vector<vx_core::Type_arg*> vx_listarg();
    // vx_arg(index)
    virtual vx_core::Type_arg* vx_arg(vx_core::Type_int* index);
  };

  // (type argmap)
  class Type_argmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_argmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_argmap* vx_copy(Args*... args);
    virtual vx_core::Type_argmap* vx_empty();
    virtual vx_core::Type_argmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_arg*> vx_p_map;
    // vx_maparg()
    virtual std::map<std::string, vx_core::Type_arg*> vx_maparg();
    // vx_arg(key)
    virtual vx_core::Type_arg* vx_arg(vx_core::Type_string* key);
    virtual vx_core::Type_argmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type booleanlist)
  class Type_booleanlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_booleanlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_booleanlist* vx_copy(Args*... args);
    virtual vx_core::Type_booleanlist* vx_empty();
    virtual vx_core::Type_booleanlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_boolean*> vx_p_list;

    // vx_listboolean()
    virtual std::vector<vx_core::Type_boolean*> vx_listboolean();
    // vx_boolean(index)
    virtual vx_core::Type_boolean* vx_boolean(vx_core::Type_int* index);
  };

  // (type collection)
  class Type_collection : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_collection* vx_new(Args*... args);
    template<class... Args> vx_core::Type_collection* vx_copy(Args*... args);
    virtual vx_core::Type_collection* vx_empty();
    virtual vx_core::Type_collection* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type compilelanguages)
  class Type_compilelanguages : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_compilelanguages* vx_new(Args*... args);
    template<class... Args> vx_core::Type_compilelanguages* vx_copy(Args*... args);
    virtual vx_core::Type_compilelanguages* vx_empty();
    virtual vx_core::Type_compilelanguages* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type connect)
  class Type_connect : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_connect* vx_new(Args*... args);
    template<class... Args> vx_core::Type_connect* vx_copy(Args*... args);
    virtual vx_core::Type_connect* vx_empty();
    virtual vx_core::Type_connect* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type connectlist)
  class Type_connectlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_connectlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_connectlist* vx_copy(Args*... args);
    virtual vx_core::Type_connectlist* vx_empty();
    virtual vx_core::Type_connectlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_connect*> vx_p_list;

    // vx_listconnect()
    virtual std::vector<vx_core::Type_connect*> vx_listconnect();
    // vx_connect(index)
    virtual vx_core::Type_connect* vx_connect(vx_core::Type_int* index);
  };

  // (type connectmap)
  class Type_connectmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_connectmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_connectmap* vx_copy(Args*... args);
    virtual vx_core::Type_connectmap* vx_empty();
    virtual vx_core::Type_connectmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_connect*> vx_p_map;
    // vx_mapconnect()
    virtual std::map<std::string, vx_core::Type_connect*> vx_mapconnect();
    // vx_connect(key)
    virtual vx_core::Type_connect* vx_connect(vx_core::Type_string* key);
    virtual vx_core::Type_connectmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type const)
  class Type_const : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_const* vx_new(Args*... args);
    template<class... Args> vx_core::Type_const* vx_copy(Args*... args);
    virtual vx_core::Type_const* vx_empty();
    virtual vx_core::Type_const* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type constdef)
  class Type_constdef : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_constdef* vx_new(Args*... args);
    template<class... Args> vx_core::Type_constdef* vx_copy(Args*... args);
    virtual vx_core::Type_constdef* vx_empty();
    virtual vx_core::Type_constdef* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    static vx_core::Type_constdef* vx_constdef_new(
      std::string pkgname,
      std::string name,
      vx_core::Type_typedef* typ
    );
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // pkgname()
    vx_core::Type_string* vx_p_pkgname;
    virtual vx_core::Type_string* pkgname();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // type()
    vx_core::Type_any* vx_p_type;
    virtual vx_core::Type_any* type();
  };

  // (type constlist)
  class Type_constlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_constlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_constlist* vx_copy(Args*... args);
    virtual vx_core::Type_constlist* vx_empty();
    virtual vx_core::Type_constlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_const*> vx_p_list;

    // vx_listconst()
    virtual std::vector<vx_core::Type_const*> vx_listconst();
    // vx_const(index)
    virtual vx_core::Type_const* vx_const(vx_core::Type_int* index);
  };

  // (type constmap)
  class Type_constmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_constmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_constmap* vx_copy(Args*... args);
    virtual vx_core::Type_constmap* vx_empty();
    virtual vx_core::Type_constmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_const*> vx_p_map;
    // vx_mapconst()
    virtual std::map<std::string, vx_core::Type_const*> vx_mapconst();
    // vx_const(key)
    virtual vx_core::Type_const* vx_const(vx_core::Type_string* key);
    virtual vx_core::Type_constmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type context)
  class Type_context : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_context* vx_new(Args*... args);
    template<class... Args> vx_core::Type_context* vx_copy(Args*... args);
    virtual vx_core::Type_context* vx_empty();
    virtual vx_core::Type_context* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // code()
    vx_core::Type_string* vx_p_code;
    virtual vx_core::Type_string* code();
    // session()
    vx_core::Type_session* vx_p_session;
    virtual vx_core::Type_session* session();
    // setting()
    vx_core::Type_setting* vx_p_setting;
    virtual vx_core::Type_setting* setting();
    // state()
    vx_core::Type_state* vx_p_state;
    virtual vx_core::Type_state* state();
  };

  // (type error)
  class Type_error : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_error* vx_new(Args*... args);
    template<class... Args> vx_core::Type_error* vx_copy(Args*... args);
    virtual vx_core::Type_error* vx_empty();
    virtual vx_core::Type_error* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type funcdef)
  class Type_funcdef : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_funcdef* vx_new(Args*... args);
    template<class... Args> vx_core::Type_funcdef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_empty();
    virtual vx_core::Type_funcdef* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    static vx_core::Type_funcdef* vx_funcdef_new(
      std::string pkgname,
      std::string name,
      int idx,
      bool async,
      vx_core::Type_any* typ
    ) {
      vx_core::Type_funcdef* output;
      output->vx_p_pkgname = vx_core::t_string->vx_new_from_string(pkgname);
      output->vx_p_name = vx_core::t_string->vx_new_from_string(name);
      output->vx_p_idx = vx_core::t_int->vx_new_from_int(idx);
      output->vx_p_async = vx_core::t_boolean->vx_new_from_boolean(async);
      output->vx_p_type = typ;
      return output;
    };
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // pkgname()
    vx_core::Type_string* vx_p_pkgname;
    virtual vx_core::Type_string* pkgname();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // idx()
    vx_core::Type_int* vx_p_idx;
    virtual vx_core::Type_int* idx();
    // type()
    vx_core::Type_any* vx_p_type;
    virtual vx_core::Type_any* type();
    // async()
    vx_core::Type_boolean* vx_p_async;
    virtual vx_core::Type_boolean* async();
  };

  // (type funclist)
  class Type_funclist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_funclist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_funclist* vx_copy(Args*... args);
    virtual vx_core::Type_funclist* vx_empty();
    virtual vx_core::Type_funclist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_func*> vx_p_list;

    // vx_listfunc()
    virtual std::vector<vx_core::Type_func*> vx_listfunc();
    // vx_func(index)
    virtual vx_core::Type_func* vx_func(vx_core::Type_int* index);
  };

  // (type funcmap)
  class Type_funcmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_funcmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_funcmap* vx_copy(Args*... args);
    virtual vx_core::Type_funcmap* vx_empty();
    virtual vx_core::Type_funcmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_func*> vx_p_map;
    // vx_mapfunc()
    virtual std::map<std::string, vx_core::Type_func*> vx_mapfunc();
    // vx_func(key)
    virtual vx_core::Type_func* vx_func(vx_core::Type_string* key);
    virtual vx_core::Type_funcmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type intlist)
  class Type_intlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_intlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_intlist* vx_copy(Args*... args);
    virtual vx_core::Type_intlist* vx_empty();
    virtual vx_core::Type_intlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_int*> vx_p_list;

    // vx_listint()
    virtual std::vector<vx_core::Type_int*> vx_listint();
    // vx_int(index)
    virtual vx_core::Type_int* vx_int(vx_core::Type_int* index);
  };

  // (type intmap)
  class Type_intmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_intmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_intmap* vx_copy(Args*... args);
    virtual vx_core::Type_intmap* vx_empty();
    virtual vx_core::Type_intmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_int*> vx_p_map;
    // vx_mapint()
    virtual std::map<std::string, vx_core::Type_int*> vx_mapint();
    // vx_int(key)
    virtual vx_core::Type_int* vx_int(vx_core::Type_string* key);
    virtual vx_core::Type_intmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type listtype)
  class Type_listtype : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_listtype* vx_new(Args*... args);
    template<class... Args> vx_core::Type_listtype* vx_copy(Args*... args);
    virtual vx_core::Type_listtype* vx_empty();
    virtual vx_core::Type_listtype* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type maptype)
  class Type_maptype : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_maptype* vx_new(Args*... args);
    template<class... Args> vx_core::Type_maptype* vx_copy(Args*... args);
    virtual vx_core::Type_maptype* vx_empty();
    virtual vx_core::Type_maptype* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type mempool)
  class Type_mempool : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_mempool* vx_new(Args*... args);
    template<class... Args> vx_core::Type_mempool* vx_copy(Args*... args);
    virtual vx_core::Type_mempool* vx_empty();
    virtual vx_core::Type_mempool* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // valuepool()
    vx_core::Type_value* vx_p_valuepool;
    virtual vx_core::Type_value* valuepool();
  };

  // (type msg)
  class Type_msg : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_msg* vx_new(Args*... args);
    template<class... Args> vx_core::Type_msg* vx_copy(Args*... args);
    virtual vx_core::Type_msg* vx_empty();
    virtual vx_core::Type_msg* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    std::exception* err;
    virtual vx_core::Type_msg* vx_new_error(std::string text);
    virtual vx_core::Type_msg* vx_new_from_exception(std::string text, std::exception err);
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // code()
    vx_core::Type_string* vx_p_code;
    virtual vx_core::Type_string* code();
    // severity()
    vx_core::Type_int* vx_p_severity;
    virtual vx_core::Type_int* severity();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };

  // (type msgblock)
  class Type_msgblock : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_msgblock* vx_new(Args*... args);
    template<class... Args> vx_core::Type_msgblock* vx_copy(Args*... args);
    virtual vx_core::Type_msgblock* vx_empty();
    virtual vx_core::Type_msgblock* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Type_msgblock* vx_msgblock_from_copy_arrayval(vx_core::Type_any* copy, std::vector<std::any*> vals);
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // msgs()
    vx_core::Type_msglist* vx_p_msgs;
    virtual vx_core::Type_msglist* msgs();
    // msgblocks()
    vx_core::Type_msgblocklist* vx_p_msgblocks;
    virtual vx_core::Type_msgblocklist* msgblocks();
  };

  // (type msgblocklist)
  class Type_msgblocklist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_msgblocklist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_msgblocklist* vx_copy(Args*... args);
    virtual vx_core::Type_msgblocklist* vx_empty();
    virtual vx_core::Type_msgblocklist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_msgblock*> vx_p_list;

    // vx_listmsgblock()
    virtual std::vector<vx_core::Type_msgblock*> vx_listmsgblock();
    // vx_msgblock(index)
    virtual vx_core::Type_msgblock* vx_msgblock(vx_core::Type_int* index);
  };

  // (type msglist)
  class Type_msglist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_msglist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_msglist* vx_copy(Args*... args);
    virtual vx_core::Type_msglist* vx_empty();
    virtual vx_core::Type_msglist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_msg*> vx_p_list;

    // vx_listmsg()
    virtual std::vector<vx_core::Type_msg*> vx_listmsg();
    // vx_msg(index)
    virtual vx_core::Type_msg* vx_msg(vx_core::Type_int* index);
  };

  // (type none)
  class Type_none : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_none* vx_new(Args*... args);
    template<class... Args> vx_core::Type_none* vx_copy(Args*... args);
    virtual vx_core::Type_none* vx_empty();
    virtual vx_core::Type_none* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type notype)
  class Type_notype : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_notype* vx_new(Args*... args);
    template<class... Args> vx_core::Type_notype* vx_copy(Args*... args);
    virtual vx_core::Type_notype* vx_empty();
    virtual vx_core::Type_notype* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type numberlist)
  class Type_numberlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_numberlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_numberlist* vx_copy(Args*... args);
    virtual vx_core::Type_numberlist* vx_empty();
    virtual vx_core::Type_numberlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_number*> vx_p_list;

    // vx_listnumber()
    virtual std::vector<vx_core::Type_number*> vx_listnumber();
    // vx_number(index)
    virtual vx_core::Type_number* vx_number(vx_core::Type_int* index);
  };

  // (type numbermap)
  class Type_numbermap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_numbermap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_numbermap* vx_copy(Args*... args);
    virtual vx_core::Type_numbermap* vx_empty();
    virtual vx_core::Type_numbermap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_number*> vx_p_map;
    // vx_mapnumber()
    virtual std::map<std::string, vx_core::Type_number*> vx_mapnumber();
    // vx_number(key)
    virtual vx_core::Type_number* vx_number(vx_core::Type_string* key);
    virtual vx_core::Type_numbermap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type package)
  class Type_package : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_package* vx_new(Args*... args);
    template<class... Args> vx_core::Type_package* vx_copy(Args*... args);
    virtual vx_core::Type_package* vx_empty();
    virtual vx_core::Type_package* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };

  // (type packagemap)
  class Type_packagemap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_packagemap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_packagemap* vx_copy(Args*... args);
    virtual vx_core::Type_packagemap* vx_empty();
    virtual vx_core::Type_packagemap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_package*> vx_p_map;
    // vx_mappackage()
    virtual std::map<std::string, vx_core::Type_package*> vx_mappackage();
    // vx_package(key)
    virtual vx_core::Type_package* vx_package(vx_core::Type_string* key);
    virtual vx_core::Type_packagemap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type permission)
  class Type_permission : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_permission* vx_new(Args*... args);
    template<class... Args> vx_core::Type_permission* vx_copy(Args*... args);
    virtual vx_core::Type_permission* vx_empty();
    virtual vx_core::Type_permission* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
  };

  // (type permissionlist)
  class Type_permissionlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_permissionlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_permissionlist* vx_copy(Args*... args);
    virtual vx_core::Type_permissionlist* vx_empty();
    virtual vx_core::Type_permissionlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_permission*> vx_p_list;

    // vx_listpermission()
    virtual std::vector<vx_core::Type_permission*> vx_listpermission();
    // vx_permission(index)
    virtual vx_core::Type_permission* vx_permission(vx_core::Type_int* index);
  };

  // (type permissionmap)
  class Type_permissionmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_permissionmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_permissionmap* vx_copy(Args*... args);
    virtual vx_core::Type_permissionmap* vx_empty();
    virtual vx_core::Type_permissionmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_permission*> vx_p_map;
    // vx_mappermission()
    virtual std::map<std::string, vx_core::Type_permission*> vx_mappermission();
    // vx_permission(key)
    virtual vx_core::Type_permission* vx_permission(vx_core::Type_string* key);
    virtual vx_core::Type_permissionmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type security)
  class Type_security : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_security* vx_new(Args*... args);
    template<class... Args> vx_core::Type_security* vx_copy(Args*... args);
    virtual vx_core::Type_security* vx_empty();
    virtual vx_core::Type_security* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // permissions()
    vx_core::Type_permissionlist* vx_p_permissions;
    virtual vx_core::Type_permissionlist* permissions();
    // permissionmap()
    vx_core::Type_permissionmap* vx_p_permissionmap;
    virtual vx_core::Type_permissionmap* permissionmap();
  };

  // (type session)
  class Type_session : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_session* vx_new(Args*... args);
    template<class... Args> vx_core::Type_session* vx_copy(Args*... args);
    virtual vx_core::Type_session* vx_empty();
    virtual vx_core::Type_session* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // user()
    vx_core::Type_user* vx_p_user;
    virtual vx_core::Type_user* user();
    // connectlist()
    vx_core::Type_connectlist* vx_p_connectlist;
    virtual vx_core::Type_connectlist* connectlist();
    // connectmap()
    vx_core::Type_connectmap* vx_p_connectmap;
    virtual vx_core::Type_connectmap* connectmap();
  };

  // (type setting)
  class Type_setting : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_setting* vx_new(Args*... args);
    template<class... Args> vx_core::Type_setting* vx_copy(Args*... args);
    virtual vx_core::Type_setting* vx_empty();
    virtual vx_core::Type_setting* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // pathmap()
    vx_core::Type_stringmap* vx_p_pathmap;
    virtual vx_core::Type_stringmap* pathmap();
  };

  // (type state)
  class Type_state : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_state* vx_new(Args*... args);
    template<class... Args> vx_core::Type_state* vx_copy(Args*... args);
    virtual vx_core::Type_state* vx_empty();
    virtual vx_core::Type_state* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_statelistener*> vx_p_map;
    // vx_mapstatelistener()
    virtual std::map<std::string, vx_core::Type_statelistener*> vx_mapstatelistener();
    // vx_statelistener(key)
    virtual vx_core::Type_statelistener* vx_statelistener(vx_core::Type_string* key);
    virtual vx_core::Type_state* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type statelistener)
  class Type_statelistener : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_statelistener* vx_new(Args*... args);
    template<class... Args> vx_core::Type_statelistener* vx_copy(Args*... args);
    virtual vx_core::Type_statelistener* vx_empty();
    virtual vx_core::Type_statelistener* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // path()
    vx_core::Type_string* vx_p_path;
    virtual vx_core::Type_string* path();
    // value()
    vx_core::Type_any* vx_p_value;
    virtual vx_core::Type_any* value();
    // fn-boolean()
    vx_core::Func_boolean_from_none* vx_p_fn_boolean;
    virtual vx_core::Func_boolean_from_none* fn_boolean();
  };

  // (type stringlist)
  class Type_stringlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_stringlist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_stringlist* vx_copy(Args*... args);
    virtual vx_core::Type_stringlist* vx_empty();
    virtual vx_core::Type_stringlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_string*> vx_p_list;

    // vx_liststring()
    virtual std::vector<vx_core::Type_string*> vx_liststring();
    // vx_string(index)
    virtual vx_core::Type_string* vx_string(vx_core::Type_int* index);
  };

  // (type stringmap)
  class Type_stringmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_stringmap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_stringmap* vx_copy(Args*... args);
    virtual vx_core::Type_stringmap* vx_empty();
    virtual vx_core::Type_stringmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_string*> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string*> vx_mapstring();
    // vx_string(key)
    virtual vx_core::Type_string* vx_string(vx_core::Type_string* key);
    virtual vx_core::Type_stringmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type thenelse)
  class Type_thenelse : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_thenelse* vx_new(Args*... args);
    template<class... Args> vx_core::Type_thenelse* vx_copy(Args*... args);
    virtual vx_core::Type_thenelse* vx_empty();
    virtual vx_core::Type_thenelse* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // code()
    vx_core::Type_string* vx_p_code;
    virtual vx_core::Type_string* code();
    // value()
    vx_core::Type_any* vx_p_value;
    virtual vx_core::Type_any* value();
    // values()
    vx_core::Type_list* vx_p_values;
    virtual vx_core::Type_list* values();
    // fn-cond()
    vx_core::Func_boolean_from_func* vx_p_fn_cond;
    virtual vx_core::Func_boolean_from_func* fn_cond();
    // fn-any()
    vx_core::Func_any_from_func* vx_p_fn_any;
    virtual vx_core::Func_any_from_func* fn_any();
  };

  // (type thenelselist)
  class Type_thenelselist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_thenelselist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_thenelselist* vx_copy(Args*... args);
    virtual vx_core::Type_thenelselist* vx_empty();
    virtual vx_core::Type_thenelselist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_thenelse*> vx_p_list;

    // vx_listthenelse()
    virtual std::vector<vx_core::Type_thenelse*> vx_listthenelse();
    // vx_thenelse(index)
    virtual vx_core::Type_thenelse* vx_thenelse(vx_core::Type_int* index);
  };

  // (type type)
  class Type_type : public vx_core::Type_any {
  public:
    template<class... Args> vx_core::Type_type* vx_new(Args*... args);
    template<class... Args> vx_core::Type_type* vx_copy(Args*... args);
    virtual vx_core::Type_type* vx_empty();
    virtual vx_core::Type_type* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type typedef)
  class Type_typedef : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Type_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_typedef* vx_empty();
    virtual vx_core::Type_typedef* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    static vx_core::Type_typedef* vx_typedef_new(
      std::string pkgname,
      std::string name,
      std::string extend,
      vx_core::Type_typelist* traits,
      vx_core::Type_typelist* allowtypes,
      vx_core::Type_typelist* disallowtypes,
      vx_core::Type_funclist* allowfuncs,
      vx_core::Type_funclist* disallowfuncs,
      vx_core::Type_anylist* allowvalues,
      vx_core::Type_anylist* disallowvalues,
      vx_core::Type_argmap* properties
    );
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // pkgname()
    vx_core::Type_string* vx_p_pkgname;
    virtual vx_core::Type_string* pkgname();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // extends()
    vx_core::Type_string* vx_p_extend;
    virtual vx_core::Type_string* extend();
    // allowfuncs()
    vx_core::Type_funclist* vx_p_allowfuncs;
    virtual vx_core::Type_funclist* allowfuncs();
    // allowtypes()
    vx_core::Type_typelist* vx_p_allowtypes;
    virtual vx_core::Type_typelist* allowtypes();
    // allowvalues()
    vx_core::Type_anylist* vx_p_allowvalues;
    virtual vx_core::Type_anylist* allowvalues();
    // disallowfuncs()
    vx_core::Type_funclist* vx_p_disallowfuncs;
    virtual vx_core::Type_funclist* disallowfuncs();
    // disallowtypes()
    vx_core::Type_typelist* vx_p_disallowtypes;
    virtual vx_core::Type_typelist* disallowtypes();
    // disallowvalues()
    vx_core::Type_anylist* vx_p_disallowvalues;
    virtual vx_core::Type_anylist* disallowvalues();
    // properties()
    vx_core::Type_argmap* vx_p_properties;
    virtual vx_core::Type_argmap* properties();
    // proplast()
    vx_core::Type_arg* vx_p_proplast;
    virtual vx_core::Type_arg* proplast();
    // traits()
    vx_core::Type_typelist* vx_p_traits;
    virtual vx_core::Type_typelist* traits();
  };

  // (type typelist)
  class Type_typelist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_core::Type_typelist* vx_new(Args*... args);
    template<class... Args> vx_core::Type_typelist* vx_copy(Args*... args);
    virtual vx_core::Type_typelist* vx_empty();
    virtual vx_core::Type_typelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_any*> vx_p_list;

  };

  // (type typemap)
  class Type_typemap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_core::Type_typemap* vx_new(Args*... args);
    template<class... Args> vx_core::Type_typemap* vx_copy(Args*... args);
    virtual vx_core::Type_typemap* vx_empty();
    virtual vx_core::Type_typemap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };

  // (type user)
  class Type_user : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_user* vx_new(Args*... args);
    template<class... Args> vx_core::Type_user* vx_copy(Args*... args);
    virtual vx_core::Type_user* vx_empty();
    virtual vx_core::Type_user* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // security()
    vx_core::Type_security* vx_p_security;
    virtual vx_core::Type_security* security();
    // username()
    vx_core::Type_string* vx_p_username;
    virtual vx_core::Type_string* username();
    // token()
    vx_core::Type_string* vx_p_token;
    virtual vx_core::Type_string* token();
  };

  // (type value)
  class Type_value : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_core::Type_value* vx_new(Args*... args);
    template<class... Args> vx_core::Type_value* vx_copy(Args*... args);
    virtual vx_core::Type_value* vx_empty();
    virtual vx_core::Type_value* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // next()
    vx_core::Type_any* vx_p_next;
    virtual vx_core::Type_any* next();
    // refs()
    vx_core::Type_int* vx_p_refs;
    virtual vx_core::Type_int* refs();
  };

  // (const false)
  class Const_false : public vx_core::Type_boolean {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_false* vx_const_new();
  };

  // (const globalpackagemap)
  class Const_globalpackagemap : public vx_core::Type_packagemap {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_globalpackagemap* vx_const_new();
  };

  // (const infinity)
  class Const_infinity : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_infinity* vx_const_new();
  };

  // (const mempool-active)
  class Const_mempool_active : public vx_core::Type_mempool {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_mempool_active* vx_const_new();
  };

  // (const msg-error)
  class Const_msg_error : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_msg_error* vx_const_new();
  };

  // (const msg-info)
  class Const_msg_info : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_msg_info* vx_const_new();
  };

  // (const msg-severe)
  class Const_msg_severe : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_msg_severe* vx_const_new();
  };

  // (const msg-warning)
  class Const_msg_warning : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_msg_warning* vx_const_new();
  };

  // (const neginfinity)
  class Const_neginfinity : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_neginfinity* vx_const_new();
  };

  // (const newline)
  class Const_newline : public vx_core::Type_string {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_newline* vx_const_new();
  };

  // (const notanumber)
  class Const_notanumber : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_notanumber* vx_const_new();
  };

  // (const nothing)
  class Const_nothing : public vx_core::Type_string {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_nothing* vx_const_new();
  };

  // (const quote)
  class Const_quote : public vx_core::Type_string {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_quote* vx_const_new();
  };

  // (const true)
  class Const_true : public vx_core::Type_boolean {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_true* vx_const_new();
  };

  // (func !)
  class Func_not : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_not* vx_new(Args*... args);
    template<class... Args> vx_core::Func_not* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_not* vx_empty();
    virtual vx_core::Func_not* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_not(vx_core::Type_boolean* val);
  };

  // (func !-empty)
  class Func_notempty : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_notempty* vx_new(Args*... args);
    template<class... Args> vx_core::Func_notempty* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_notempty* vx_empty();
    virtual vx_core::Func_notempty* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_notempty(vx_core::Type_string* text);
  };

  // (func !-empty)
  class Func_notempty_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_notempty_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_notempty_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_notempty_1* vx_empty();
    virtual vx_core::Func_notempty_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_notempty_1(vx_core::Type_any* val);
  };

  // (func !=)
  class Func_ne : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_ne* vx_new(Args*... args);
    template<class... Args> vx_core::Func_ne* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_ne* vx_empty();
    virtual vx_core::Func_ne* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_ne(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func *)
  class Func_multiply : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_multiply* vx_new(Args*... args);
    template<class... Args> vx_core::Func_multiply* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_multiply* vx_empty();
    virtual vx_core::Func_multiply* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_multiply(vx_core::Type_int* num1, vx_core::Type_int* num2);
  };

  // (func *)
  class Func_multiply_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_multiply_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_multiply_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_multiply_1* vx_empty();
    virtual vx_core::Func_multiply_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_multiply_1(vx_core::Type_number* num1, vx_core::Type_number* num2);
  };

  // (func *)
  class Func_multiply_2 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_multiply_2* vx_new(Args*... args);
    template<class... Args> vx_core::Func_multiply_2* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_multiply_2* vx_empty();
    virtual vx_core::Func_multiply_2* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_multiply_2(vx_core::Type_intlist* nums);
  };

  // (func *)
  class Func_multiply_3 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_multiply_3* vx_new(Args*... args);
    template<class... Args> vx_core::Func_multiply_3* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_multiply_3* vx_empty();
    virtual vx_core::Func_multiply_3* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_multiply_3(vx_core::Type_numberlist* nums);
  };

  // (func +)
  class Func_plus : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_plus* vx_new(Args*... args);
    template<class... Args> vx_core::Func_plus* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_plus* vx_empty();
    virtual vx_core::Func_plus* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_plus(vx_core::Type_int* num1, vx_core::Type_int* num2);
  };

  // (func +)
  class Func_plus_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_plus_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_plus_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_plus_1* vx_empty();
    virtual vx_core::Func_plus_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_plus_1(vx_core::Type_number* num1, vx_core::Type_number* num2);
  };

  // (func +)
  class Func_plus_2 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_plus_2* vx_new(Args*... args);
    template<class... Args> vx_core::Func_plus_2* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_plus_2* vx_empty();
    virtual vx_core::Func_plus_2* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_plus_2(vx_core::Type_intlist* nums);
  };

  // (func +)
  class Func_plus_3 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_plus_3* vx_new(Args*... args);
    template<class... Args> vx_core::Func_plus_3* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_plus_3* vx_empty();
    virtual vx_core::Func_plus_3* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_plus_3(vx_core::Type_numberlist* nums);
  };

  // (func +1)
  class Func_plus1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_plus1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_plus1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_plus1* vx_empty();
    virtual vx_core::Func_plus1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_plus1(vx_core::Type_int* num);
  };

  // (func -)
  class Func_minus : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_minus* vx_new(Args*... args);
    template<class... Args> vx_core::Func_minus* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_minus* vx_empty();
    virtual vx_core::Func_minus* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_minus(vx_core::Type_int* num1, vx_core::Type_int* num2);
  };

  // (func -)
  class Func_minus_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_minus_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_minus_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_minus_1* vx_empty();
    virtual vx_core::Func_minus_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_minus_1(vx_core::Type_number* num1, vx_core::Type_number* num2);
  };

  // (func -)
  class Func_minus_2 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_minus_2* vx_new(Args*... args);
    template<class... Args> vx_core::Func_minus_2* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_minus_2* vx_empty();
    virtual vx_core::Func_minus_2* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_minus_2(vx_core::Type_intlist* nums);
  };

  // (func -)
  class Func_minus_3 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_minus_3* vx_new(Args*... args);
    template<class... Args> vx_core::Func_minus_3* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_minus_3* vx_empty();
    virtual vx_core::Func_minus_3* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_minus_3(vx_core::Type_numberlist* nums);
  };

  // (func .)
  class Func_dotmethod : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_dotmethod* vx_new(Args*... args);
    template<class... Args> vx_core::Func_dotmethod* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_dotmethod* vx_empty();
    virtual vx_core::Func_dotmethod* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_dotmethod(vx_core::Type_any* object, vx_core::Type_string* method, vx_core::Type_anylist* params);
  };

  // (func /)
  class Func_divide : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_divide* vx_new(Args*... args);
    template<class... Args> vx_core::Func_divide* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_divide* vx_empty();
    virtual vx_core::Func_divide* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_divide(vx_core::Type_number* num1, vx_core::Type_number* num2);
  };

  // (func <)
  class Func_lt : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_lt* vx_new(Args*... args);
    template<class... Args> vx_core::Func_lt* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_lt* vx_empty();
    virtual vx_core::Func_lt* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_lt(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func <)
  class Func_lt_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_lt_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_lt_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_lt_1* vx_empty();
    virtual vx_core::Func_lt_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_lt_1(vx_core::Type_anylist* values);
  };

  // (func <-)
  class Func_chainfirst : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_chainfirst* vx_new(Args*... args);
    template<class... Args> vx_core::Func_chainfirst* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_chainfirst* vx_empty();
    virtual vx_core::Func_chainfirst* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_chainfirst(T* generic_any_1, T* value, vx_core::Type_any_from_anylist* fnlist);
  };

  // (func <<-)
  class Func_chainlast : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_chainlast* vx_new(Args*... args);
    template<class... Args> vx_core::Func_chainlast* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_chainlast* vx_empty();
    virtual vx_core::Func_chainlast* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_chainlast(T* generic_any_1, T* value, vx_core::Type_any_from_anylist* fnlist);
  };

  // (func <=)
  class Func_le : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_le* vx_new(Args*... args);
    template<class... Args> vx_core::Func_le* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_le* vx_empty();
    virtual vx_core::Func_le* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_le(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func <=)
  class Func_le_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_le_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_le_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_le_1* vx_empty();
    virtual vx_core::Func_le_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_le_1(vx_core::Type_anylist* args);
  };

  // (func =)
  class Func_eq : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_eq* vx_new(Args*... args);
    template<class... Args> vx_core::Func_eq* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_eq* vx_empty();
    virtual vx_core::Func_eq* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_eq(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func =)
  class Func_eq_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_eq_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_eq_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_eq_1* vx_empty();
    virtual vx_core::Func_eq_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_eq_1(vx_core::Type_anylist* values);
  };

  // (func >)
  class Func_gt : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_gt* vx_new(Args*... args);
    template<class... Args> vx_core::Func_gt* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_gt* vx_empty();
    virtual vx_core::Func_gt* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_gt(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func >)
  class Func_gt_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_gt_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_gt_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_gt_1* vx_empty();
    virtual vx_core::Func_gt_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_gt_1(vx_core::Type_anylist* values);
  };

  // (func >=)
  class Func_ge : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_ge* vx_new(Args*... args);
    template<class... Args> vx_core::Func_ge* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_ge* vx_empty();
    virtual vx_core::Func_ge* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_ge(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func >=)
  class Func_ge_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_ge_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_ge_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_ge_1* vx_empty();
    virtual vx_core::Func_ge_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_ge_1(vx_core::Type_anylist* args);
  };

  // (func allowtypenames<-typedef)
  class Func_allowtypenames_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_allowtypenames_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_allowtypenames_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_allowtypenames_from_typedef* vx_empty();
    virtual vx_core::Func_allowtypenames_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_stringlist* vx_allowtypenames_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func allowtypes<-typedef)
  class Func_allowtypes_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_allowtypes_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_allowtypes_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_allowtypes_from_typedef* vx_empty();
    virtual vx_core::Func_allowtypes_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_typelist* vx_allowtypes_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func and)
  class Func_and : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_and* vx_new(Args*... args);
    template<class... Args> vx_core::Func_and* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_and* vx_empty();
    virtual vx_core::Func_and* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_and(vx_core::Type_boolean* val1, vx_core::Type_boolean* val2);
  };

  // (func and)
  class Func_and_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_and_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_and_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_and_1* vx_empty();
    virtual vx_core::Func_and_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_and_1(vx_core::Type_booleanlist* values);
  };

  // (func any<-any-async)
  class Func_any_from_any_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_any_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_any_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_any_async* vx_empty();
    virtual vx_core::Func_any_from_any_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>(vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> vx_core::Async<T*>* vx_any_from_any_async(T* generic_any_1, U* value);
  };

  // (func any<-any-context)
  class Func_any_from_any_context : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_any_context* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_any_context* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_any_context* vx_empty();
    virtual vx_core::Func_any_from_any_context* vx_type();
    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_context*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
  };

  // (func any<-any-context-async)
  class Func_any_from_any_context_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_any_context_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_any_context_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_any_context_async* vx_empty();
    virtual vx_core::Func_any_from_any_context_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_context*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_any_context_async* fn_new(vx_core::Func_any_from_any_context_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> vx_core::Async<T*>* vx_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context* context);
  };

  // (func any<-func-async)
  class Func_any_from_func_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_func_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_func_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_func_async* vx_empty();
    virtual vx_core::Func_any_from_func_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_func_async* fn_new(vx_core::Func_any_from_func_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> vx_core::Async<T*>* vx_any_from_func_async(T* generic_any_1);
  };

  // (func any<-key-value)
  class Func_any_from_key_value : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_key_value* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_key_value* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_key_value* vx_empty();
    virtual vx_core::Func_any_from_key_value* vx_type();
    typedef std::function<vx_core::Type_any*(vx_core::Type_string*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_key_value* fn_new(vx_core::Func_any_from_key_value::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_any_from_key_value(T* generic_any_1, vx_core::Type_string* key, U* val);
  };

  // (func any<-key-value-async)
  class Func_any_from_key_value_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_key_value_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_key_value_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_key_value_async* vx_empty();
    virtual vx_core::Func_any_from_key_value_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_string*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_key_value_async* fn_new(vx_core::Func_any_from_key_value_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> vx_core::Async<T*>* vx_any_from_key_value_async(T* generic_any_1, vx_core::Type_string* key, U* val);
  };

  // (func any<-list)
  class Func_any_from_list : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_list* vx_empty();
    virtual vx_core::Func_any_from_list* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class X> T* vx_any_from_list(T* generic_any_1, X* values, vx_core::Type_int* index);
  };

  // (func any<-list-reduce)
  class Func_any_from_list_reduce : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_list_reduce* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_list_reduce* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_list_reduce* vx_empty();
    virtual vx_core::Func_any_from_list_reduce* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class Y> T* vx_any_from_list_reduce(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce* fn_reduce);
  };

  // (func any<-list-reduce-next)
  class Func_any_from_list_reduce_next : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_list_reduce_next* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_list_reduce_next* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_list_reduce_next* vx_empty();
    virtual vx_core::Func_any_from_list_reduce_next* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class Y> T* vx_any_from_list_reduce_next(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce_next* fn_reduce_next);
  };

  // (func any<-map)
  class Func_any_from_map : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_map* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_map* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_map* vx_empty();
    virtual vx_core::Func_any_from_map* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class N> T* vx_any_from_map(T* generic_any_1, N* valuemap, vx_core::Type_string* key);
  };

  // (func any<-none)
  class Func_any_from_none : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_none* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_none* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_none* vx_empty();
    virtual vx_core::Func_any_from_none* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_none* fn_new(vx_core::Func_any_from_none::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_any_from_none(T* generic_any_1);
  };

  // (func any<-none-async)
  class Func_any_from_none_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_none_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_none_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_none_async* vx_empty();
    virtual vx_core::Func_any_from_none_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*()> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_none_async* fn_new(vx_core::Func_any_from_none_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> vx_core::Async<T*>* vx_any_from_none_async(T* generic_any_1);
  };

  // (func any<-reduce)
  class Func_any_from_reduce : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_reduce* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_reduce* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_reduce* vx_empty();
    virtual vx_core::Func_any_from_reduce* vx_type();
    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce* fn_new(vx_core::Func_any_from_reduce::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_any_from_reduce(T* generic_any_1, T* result, U* item);
  };

  // (func any<-reduce-async)
  class Func_any_from_reduce_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_reduce_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_reduce_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_reduce_async* vx_empty();
    virtual vx_core::Func_any_from_reduce_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_async* fn_new(vx_core::Func_any_from_reduce_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> vx_core::Async<T*>* vx_any_from_reduce_async(T* generic_any_1, T* result, U* item);
  };

  // (func any<-reduce-next)
  class Func_any_from_reduce_next : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_reduce_next* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_reduce_next* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_reduce_next* vx_empty();
    virtual vx_core::Func_any_from_reduce_next* vx_type();
    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_any*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_next* fn_new(vx_core::Func_any_from_reduce_next::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_any_from_reduce_next(T* generic_any_1, T* result, U* current, U* next);
  };

  // (func any<-reduce-next-async)
  class Func_any_from_reduce_next_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_any_from_reduce_next_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_reduce_next_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_reduce_next_async* vx_empty();
    virtual vx_core::Func_any_from_reduce_next_async* vx_type();
    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_any*, vx_core::Type_any*)> IFn;
    IFn fn;
    virtual vx_core::Func_any_from_reduce_next_async* fn_new(vx_core::Func_any_from_reduce_next_async::IFn fn);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> vx_core::Async<T*>* vx_any_from_reduce_next_async(T* generic_any_1, T* result, U* current, U* next);
  };

  // (func any<-struct)
  class Func_any_from_struct : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_any_from_struct* vx_new(Args*... args);
    template<class... Args> vx_core::Func_any_from_struct* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_any_from_struct* vx_empty();
    virtual vx_core::Func_any_from_struct* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class R> T* vx_any_from_struct(T* generic_any_1, R* vstruct, vx_core::Type_string* key);
  };

  // (func async)
  class Func_async : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_async* vx_empty();
    virtual vx_core::Func_async* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> vx_core::Async<T*>* vx_async(T* generic_any_1, T* value);
  };

  // (func boolean<-any)
  class Func_boolean_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_boolean_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_boolean_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_boolean_from_any* vx_empty();
    virtual vx_core::Func_boolean_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_from_any(vx_core::Type_any* value);
  };

  // (func boolean<-func)
  class Func_boolean_from_func : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_boolean_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_boolean_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_boolean_from_func* vx_empty();
    virtual vx_core::Func_boolean_from_func* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_boolean_from_func* fn_new(vx_core::Func_any_from_func::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_from_func();
  };

  // (func boolean<-none)
  class Func_boolean_from_none : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_boolean_from_none* vx_new(Args*... args);
    template<class... Args> vx_core::Func_boolean_from_none* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_boolean_from_none* vx_empty();
    virtual vx_core::Func_boolean_from_none* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_boolean_from_none* fn_new(vx_core::Func_any_from_func::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_from_none();
  };

  // (func case)
  class Func_case : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_case* vx_new(Args*... args);
    template<class... Args> vx_core::Func_case* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_case* vx_empty();
    virtual vx_core::Func_case* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_thenelse* vx_case(vx_core::Type_list* values, vx_core::Func_any_from_func* fn_any);
  };

  // (func case)
  class Func_case_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_case_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_case_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_case_1* vx_empty();
    virtual vx_core::Func_case_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_thenelse* vx_case_1(vx_core::Type_any* value, vx_core::Func_any_from_func* fn_any);
  };

  // (func compare)
  class Func_compare : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_compare* vx_new(Args*... args);
    template<class... Args> vx_core::Func_compare* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_compare* vx_empty();
    virtual vx_core::Func_compare* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_compare(vx_core::Type_any* val1, vx_core::Type_any* val2);
  };

  // (func contains)
  class Func_contains : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_contains* vx_new(Args*... args);
    template<class... Args> vx_core::Func_contains* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_contains* vx_empty();
    virtual vx_core::Func_contains* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_contains(vx_core::Type_string* text, vx_core::Type_string* find);
  };

  // (func contains)
  class Func_contains_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_contains_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_contains_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_contains_1* vx_empty();
    virtual vx_core::Func_contains_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_contains_1(vx_core::Type_list* values, vx_core::Type_any* find);
  };

  // (func copy)
  class Func_copy : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_copy* vx_new(Args*... args);
    template<class... Args> vx_core::Func_copy* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_copy* vx_empty();
    virtual vx_core::Func_copy* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_copy(T* value, vx_core::Type_anylist* values);
  };

  // (func else)
  class Func_else : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_else* vx_new(Args*... args);
    template<class... Args> vx_core::Func_else* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_else* vx_empty();
    virtual vx_core::Func_else* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_thenelse* vx_else(vx_core::Func_any_from_func* fn_any);
  };

  // (func empty)
  class Func_empty : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_empty* vx_new(Args*... args);
    template<class... Args> vx_core::Func_empty* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_empty* vx_empty();
    virtual vx_core::Func_empty* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_empty(T* type);
  };

  // (func extends<-any)
  class Func_extends_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_extends_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_extends_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_extends_from_any* vx_empty();
    virtual vx_core::Func_extends_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_extends_from_any(vx_core::Type_any* val);
  };

  // (func extends<-typedef)
  class Func_extends_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_extends_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_extends_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_extends_from_typedef* vx_empty();
    virtual vx_core::Func_extends_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_extends_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func first<-list)
  class Func_first_from_list : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_first_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_first_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_first_from_list* vx_empty();
    virtual vx_core::Func_first_from_list* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class X> T* vx_first_from_list(T* generic_any_1, X* values);
  };

  // (func first<-list-fn-any<-any)
  class Func_first_from_list_fn_any_from_any : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_first_from_list_fn_any_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_first_from_list_fn_any_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_first_from_list_fn_any_from_any* vx_empty();
    virtual vx_core::Func_first_from_list_fn_any_from_any* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class X> T* vx_first_from_list_fn_any_from_any(T* generic_any_1, X* values, vx_core::Func_any_from_any* fn_any_from_any);
  };

  // (func fn)
  class Func_fn : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_fn* vx_new(Args*... args);
    template<class... Args> vx_core::Func_fn* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_fn* vx_empty();
    virtual vx_core::Func_fn* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_fn(T* generic_any_1, vx_core::Type_arglist* params, vx_core::Func_any_from_func* fn_any);
  };

  // (func funcdef<-func)
  class Func_funcdef_from_func : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_funcdef_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_funcdef_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_funcdef_from_func* vx_empty();
    virtual vx_core::Func_funcdef_from_func* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_funcdef* vx_funcdef_from_func(vx_core::Type_func* val);
  };

  // (func funcname<-funcdef)
  class Func_funcname_from_funcdef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_funcname_from_funcdef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_funcname_from_funcdef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_funcname_from_funcdef* vx_empty();
    virtual vx_core::Func_funcname_from_funcdef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_funcname_from_funcdef(vx_core::Type_funcdef* funcdef);
  };

  // (func global-package-get)
  class Func_global_package_get : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_global_package_get* vx_new(Args*... args);
    template<class... Args> vx_core::Func_global_package_get* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_global_package_get* vx_empty();
    virtual vx_core::Func_global_package_get* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_package* vx_global_package_get(vx_core::Type_string* pkgname);
  };

  // (func global-package-set)
  class Func_global_package_set : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_global_package_set* vx_new(Args*... args);
    template<class... Args> vx_core::Func_global_package_set* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_global_package_set* vx_empty();
    virtual vx_core::Func_global_package_set* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_global_package_set(vx_core::Type_string* pkgname, vx_core::Type_package* pkg);
  };

  // (func if)
  class Func_if : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_if* vx_new(Args*... args);
    template<class... Args> vx_core::Func_if* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_if* vx_empty();
    virtual vx_core::Func_if* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_if(T* generic_any_1, vx_core::Type_boolean* clause, T* then);
  };

  // (func if)
  class Func_if_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_if_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_if_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_if_1* vx_empty();
    virtual vx_core::Func_if_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_if_1(T* generic_any_1, vx_core::Type_boolean* clause, T* thenval, T* elseval);
  };

  // (func if)
  class Func_if_2 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_if_2* vx_new(Args*... args);
    template<class... Args> vx_core::Func_if_2* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_if_2* vx_empty();
    virtual vx_core::Func_if_2* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_if_2(T* generic_any_1, vx_core::Type_thenelselist* thenelselist);
  };

  // (func int<-func)
  class Func_int_from_func : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_int_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_int_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_int_from_func* vx_empty();
    virtual vx_core::Func_int_from_func* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_int_from_func* fn_new(vx_core::Func_any_from_func::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_int_from_func();
  };

  // (func int<-string)
  class Func_int_from_string : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_int_from_string* vx_new(Args*... args);
    template<class... Args> vx_core::Func_int_from_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_int_from_string* vx_empty();
    virtual vx_core::Func_int_from_string* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_int_from_string(vx_core::Type_string* val);
  };

  // (func is-empty)
  class Func_is_empty : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_empty* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_empty* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_empty* vx_empty();
    virtual vx_core::Func_is_empty* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_empty(vx_core::Type_string* text);
  };

  // (func is-empty)
  class Func_is_empty_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_empty_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_empty_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_empty_1* vx_empty();
    virtual vx_core::Func_is_empty_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_empty_1(vx_core::Type_any* value);
  };

  // (func is-endswith)
  class Func_is_endswith : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_endswith* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_endswith* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_endswith* vx_empty();
    virtual vx_core::Func_is_endswith* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_endswith(vx_core::Type_string* text, vx_core::Type_string* find);
  };

  // (func is-func)
  class Func_is_func : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_func* vx_empty();
    virtual vx_core::Func_is_func* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_func(vx_core::Type_any* val);
  };

  // (func is-int)
  class Func_is_int : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_int* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_int* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_int* vx_empty();
    virtual vx_core::Func_is_int* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_int(vx_core::Type_any* value);
  };

  // (func is-number)
  class Func_is_number : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_number* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_number* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_number* vx_empty();
    virtual vx_core::Func_is_number* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_number(vx_core::Type_any* value);
  };

  // (func is-pass<-permission)
  class Func_is_pass_from_permission : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_is_pass_from_permission* vx_new(Args*... args);
    template<class... Args> vx_core::Func_is_pass_from_permission* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_is_pass_from_permission* vx_empty();
    virtual vx_core::Func_is_pass_from_permission* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_pass_from_permission(vx_core::Type_permission* permission, vx_core::Type_context* context);
  };

  // (func last<-list)
  class Func_last_from_list : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_last_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_last_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_last_from_list* vx_empty();
    virtual vx_core::Func_last_from_list* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class X> T* vx_last_from_list(T* generic_any_1, X* values);
  };

  // (func length<-list)
  class Func_length_from_list : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_length_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_length_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_length_from_list* vx_empty();
    virtual vx_core::Func_length_from_list* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_length_from_list(vx_core::Type_list* values);
  };

  // (func let)
  class Func_let : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_let* vx_new(Args*... args);
    template<class... Args> vx_core::Func_let* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_let* vx_empty();
    virtual vx_core::Func_let* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_let(T* generic_any_1, vx_core::Func_any_from_func* fn_any);
  };

  // (func let-async)
  class Func_let_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_let_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_let_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_let_async* vx_empty();
    virtual vx_core::Func_let_async* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> vx_core::Async<T*>* vx_let_async(T* generic_any_1, vx_core::Func_any_from_func_async* fn_any_async);
  };

  // (func list-join<-list)
  class Func_list_join_from_list : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_list_join_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_join_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_join_from_list* vx_empty();
    virtual vx_core::Func_list_join_from_list* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class Y> X* vx_list_join_from_list(X* generic_any_1, Y* values, vx_core::Func_any_from_any* fn_any_from_any);
  };

  // (func list<-list)
  class Func_list_from_list : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_list_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_from_list* vx_empty();
    virtual vx_core::Func_list_from_list* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class Y> X* vx_list_from_list(X* generic_any_1, Y* values, vx_core::Func_any_from_any* fn_any_from_any);
  };

  // (func list<-list-async)
  class Func_list_from_list_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_list_from_list_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_from_list_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_from_list_async* vx_empty();
    virtual vx_core::Func_list_from_list_async* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class Y> vx_core::Async<X*>* vx_list_from_list_async(X* generic_any_1, Y* values, vx_core::Func_any_from_any_async* fn_any_from_any_async);
  };

  // (func list<-map)
  class Func_list_from_map : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_list_from_map* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_from_map* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_from_map* vx_empty();
    virtual vx_core::Func_list_from_map* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class O> X* vx_list_from_map(X* generic_any_1, O* valuemap, vx_core::Func_any_from_key_value* fn_any_from_key_value);
  };

  // (func list<-map-async)
  class Func_list_from_map_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_list_from_map_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_from_map_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_from_map_async* vx_empty();
    virtual vx_core::Func_list_from_map_async* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class O> vx_core::Async<X*>* vx_list_from_map_async(X* generic_any_1, O* valuemap, vx_core::Func_any_from_key_value_async* fn_any_from_key_value_async);
  };

  // (func list<-type)
  class Func_list_from_type : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_list_from_type* vx_new(Args*... args);
    template<class... Args> vx_core::Func_list_from_type* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_list_from_type* vx_empty();
    virtual vx_core::Func_list_from_type* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_list_from_type(vx_core::Type_any* type);
  };

  // (func log)
  class Func_log : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_log* vx_new(Args*... args);
    template<class... Args> vx_core::Func_log* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_log* vx_empty();
    virtual vx_core::Func_log* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_log(vx_core::Type_any* value);
  };

  // (func map<-list)
  class Func_map_from_list : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_map_from_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_map_from_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_map_from_list* vx_empty();
    virtual vx_core::Func_map_from_list* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class Y, class N> N* vx_map_from_list(N* generic_any_1, Y* vallist, vx_core::Func_any_from_any* fn_any_from_any);
  };

  // (func mempool-addref)
  class Func_mempool_addref : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_mempool_addref* vx_new(Args*... args);
    template<class... Args> vx_core::Func_mempool_addref* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_mempool_addref* vx_empty();
    virtual vx_core::Func_mempool_addref* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_mempool_addref(vx_core::Type_anylist* values);
  };

  // (func mempool-release)
  class Func_mempool_release : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_mempool_release* vx_new(Args*... args);
    template<class... Args> vx_core::Func_mempool_release* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_mempool_release* vx_empty();
    virtual vx_core::Func_mempool_release* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_mempool_release(vx_core::Type_value* value);
  };

  // (func mempool-removeref)
  class Func_mempool_removeref : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_mempool_removeref* vx_new(Args*... args);
    template<class... Args> vx_core::Func_mempool_removeref* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_mempool_removeref* vx_empty();
    virtual vx_core::Func_mempool_removeref* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_mempool_removeref(vx_core::Type_anylist* values);
  };

  // (func mempool-removerefchildren)
  class Func_mempool_removerefchildren : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_mempool_removerefchildren* vx_new(Args*... args);
    template<class... Args> vx_core::Func_mempool_removerefchildren* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_mempool_removerefchildren* vx_empty();
    virtual vx_core::Func_mempool_removerefchildren* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_mempool_removerefchildren(vx_core::Type_anylist* values);
  };

  // (func mempool-reserve)
  class Func_mempool_reserve : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_mempool_reserve* vx_new(Args*... args);
    template<class... Args> vx_core::Func_mempool_reserve* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_mempool_reserve* vx_empty();
    virtual vx_core::Func_mempool_reserve* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_value* vx_mempool_reserve();
  };

  // (func msg<-error)
  class Func_msg_from_error : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_msg_from_error* vx_new(Args*... args);
    template<class... Args> vx_core::Func_msg_from_error* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_msg_from_error* vx_empty();
    virtual vx_core::Func_msg_from_error* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_msg* vx_msg_from_error(vx_core::Type_string* error);
  };

  // (func msgblock<-msgblock-msg)
  class Func_msgblock_from_msgblock_msg : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_msgblock_from_msgblock_msg* vx_new(Args*... args);
    template<class... Args> vx_core::Func_msgblock_from_msgblock_msg* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_msgblock_from_msgblock_msg* vx_empty();
    virtual vx_core::Func_msgblock_from_msgblock_msg* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_msgblock* vx_msgblock_from_msgblock_msg(vx_core::Type_msgblock* origblock, vx_core::Type_msg* addmsg);
  };

  // (func msgblock<-msgblock-msgblock)
  class Func_msgblock_from_msgblock_msgblock : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_msgblock_from_msgblock_msgblock* vx_new(Args*... args);
    template<class... Args> vx_core::Func_msgblock_from_msgblock_msgblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_msgblock_from_msgblock_msgblock* vx_empty();
    virtual vx_core::Func_msgblock_from_msgblock_msgblock* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_msgblock* vx_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock* origblock, vx_core::Type_msgblock* addblock);
  };

  // (func name<-typedef)
  class Func_name_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_name_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_name_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_name_from_typedef* vx_empty();
    virtual vx_core::Func_name_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_name_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func native)
  class Func_native : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_native* vx_new(Args*... args);
    template<class... Args> vx_core::Func_native* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_native* vx_empty();
    virtual vx_core::Func_native* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_native(T* generic_any_1, vx_core::Type_anylist* clauses);
  };

  // (func native<-any)
  class Func_native_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_native_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_native_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_native_from_any* vx_empty();
    virtual vx_core::Func_native_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_native_from_any(vx_core::Type_any* value);
  };

  // (func new)
  class Func_new : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_new* vx_new(Args*... args);
    template<class... Args> vx_core::Func_new* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_new* vx_empty();
    virtual vx_core::Func_new* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_new(T* type, vx_core::Type_anylist* values);
  };

  // (func number<-func)
  class Func_number_from_func : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_number_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_number_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_number_from_func* vx_empty();
    virtual vx_core::Func_number_from_func* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_number* vx_number_from_func();
  };

  // (func or)
  class Func_or : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_or* vx_new(Args*... args);
    template<class... Args> vx_core::Func_or* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_or* vx_empty();
    virtual vx_core::Func_or* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_or(vx_core::Type_boolean* val1, vx_core::Type_boolean* val2);
  };

  // (func or)
  class Func_or_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_or_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_or_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_or_1* vx_empty();
    virtual vx_core::Func_or_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_or_1(vx_core::Type_booleanlist* values);
  };

  // (func packagename<-typedef)
  class Func_packagename_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_packagename_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_packagename_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_packagename_from_typedef* vx_empty();
    virtual vx_core::Func_packagename_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_packagename_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func path<-context-path)
  class Func_path_from_context_path : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_path_from_context_path* vx_new(Args*... args);
    template<class... Args> vx_core::Func_path_from_context_path* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_path_from_context_path* vx_empty();
    virtual vx_core::Func_path_from_context_path* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_path_from_context_path(vx_core::Type_string* path, vx_core::Type_context* context);
  };

  // (func path<-setting-path)
  class Func_path_from_setting_path : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_path_from_setting_path* vx_new(Args*... args);
    template<class... Args> vx_core::Func_path_from_setting_path* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_path_from_setting_path* vx_empty();
    virtual vx_core::Func_path_from_setting_path* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_path_from_setting_path(vx_core::Type_setting* session, vx_core::Type_string* path);
  };

  // (func permission<-id-context)
  class Func_permission_from_id_context : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_permission_from_id_context* vx_new(Args*... args);
    template<class... Args> vx_core::Func_permission_from_id_context* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_permission_from_id_context* vx_empty();
    virtual vx_core::Func_permission_from_id_context* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_permission* vx_permission_from_id_context(vx_core::Type_string* id, vx_core::Type_context* context);
  };

  // (func properties<-typedef)
  class Func_properties_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_properties_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_properties_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_properties_from_typedef* vx_empty();
    virtual vx_core::Func_properties_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_argmap* vx_properties_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func proplast<-typedef)
  class Func_proplast_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_proplast_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_proplast_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_proplast_from_typedef* vx_empty();
    virtual vx_core::Func_proplast_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_arg* vx_proplast_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func resolve)
  class Func_resolve : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_resolve* vx_new(Args*... args);
    template<class... Args> vx_core::Func_resolve* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_resolve* vx_empty();
    virtual vx_core::Func_resolve* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_resolve(T* generic_any_1, T* value);
  };

  // (func resolve)
  class Func_resolve_1 : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_resolve_1* vx_new(Args*... args);
    template<class... Args> vx_core::Func_resolve_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_resolve_1* vx_empty();
    virtual vx_core::Func_resolve_1* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> T* vx_resolve_1(T* generic_any_1, vx_core::Func_any_from_func* fn_any);
  };

  // (func resolve-async)
  class Func_resolve_async : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_core::Func_resolve_async* vx_new(Args*... args);
    template<class... Args> vx_core::Func_resolve_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_resolve_async* vx_empty();
    virtual vx_core::Func_resolve_async* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    template <class T> vx_core::Async<T*>* vx_resolve_async(T* generic_any_1, vx_core::Func_any_from_func_async* fn_any);
  };

  // (func resolve-first)
  class Func_resolve_first : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_resolve_first* vx_new(Args*... args);
    template<class... Args> vx_core::Func_resolve_first* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_resolve_first* vx_empty();
    virtual vx_core::Func_resolve_first* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class X> T* vx_resolve_first(T* generic_any_1, X* clauses);
  };

  // (func resolve-list)
  class Func_resolve_list : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_resolve_list* vx_new(Args*... args);
    template<class... Args> vx_core::Func_resolve_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_resolve_list* vx_empty();
    virtual vx_core::Func_resolve_list* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X> X* vx_resolve_list(X* generic_any_1, X* clauses);
  };

  // (func session<-context)
  class Func_session_from_context : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_session_from_context* vx_new(Args*... args);
    template<class... Args> vx_core::Func_session_from_context* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_session_from_context* vx_empty();
    virtual vx_core::Func_session_from_context* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_session* vx_session_from_context(vx_core::Type_context* context);
  };

  // (func setting<-context)
  class Func_setting_from_context : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_setting_from_context* vx_new(Args*... args);
    template<class... Args> vx_core::Func_setting_from_context* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_setting_from_context* vx_empty();
    virtual vx_core::Func_setting_from_context* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_setting* vx_setting_from_context(vx_core::Type_context* context);
  };

  // (func string-repeat)
  class Func_string_repeat : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_string_repeat* vx_new(Args*... args);
    template<class... Args> vx_core::Func_string_repeat* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_string_repeat* vx_empty();
    virtual vx_core::Func_string_repeat* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_repeat(vx_core::Type_string* text, vx_core::Type_int* repeat);
  };

  // (func string<-any)
  class Func_string_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_string_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_string_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_string_from_any* vx_empty();
    virtual vx_core::Func_string_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_any(vx_core::Type_any* value);
  };

  // (func string<-any-indent)
  class Func_string_from_any_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_string_from_any_indent* vx_new(Args*... args);
    template<class... Args> vx_core::Func_string_from_any_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_string_from_any_indent* vx_empty();
    virtual vx_core::Func_string_from_any_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_any_indent(vx_core::Type_any* value, vx_core::Type_int* indent, vx_core::Type_boolean* linefeed);
  };

  // (func string<-func)
  class Func_string_from_func : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_string_from_func* vx_new(Args*... args);
    template<class... Args> vx_core::Func_string_from_func* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_string_from_func* vx_empty();
    virtual vx_core::Func_string_from_func* vx_type();
    typedef std::function<vx_core::Type_any*()> IFn;
    IFn fn;
    virtual vx_core::Func_string_from_func* fn_new(vx_core::Func_any_from_func::IFn fn);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_func();
  };

  // (func switch)
  class Func_switch : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_switch* vx_new(Args*... args);
    template<class... Args> vx_core::Func_switch* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_switch* vx_empty();
    virtual vx_core::Func_switch* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class T, class U> T* vx_switch(T* generic_any_1, U* val, vx_core::Type_thenelselist* thenelselist);
  };

  // (func then)
  class Func_then : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_then* vx_new(Args*... args);
    template<class... Args> vx_core::Func_then* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_then* vx_empty();
    virtual vx_core::Func_then* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_thenelse* vx_then(vx_core::Func_boolean_from_func* fn_cond, vx_core::Func_any_from_func* fn_any);
  };

  // (func traits<-typedef)
  class Func_traits_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_traits_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_traits_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_traits_from_typedef* vx_empty();
    virtual vx_core::Func_traits_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_typelist* vx_traits_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func type<-any)
  class Func_type_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_type_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_type_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_type_from_any* vx_empty();
    virtual vx_core::Func_type_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_type_from_any(vx_core::Type_any* value);
  };

  // (func typedef<-any)
  class Func_typedef_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typedef_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typedef_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typedef_from_any* vx_empty();
    virtual vx_core::Func_typedef_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_typedef* vx_typedef_from_any(vx_core::Type_any* val);
  };

  // (func typedef<-type)
  class Func_typedef_from_type : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typedef_from_type* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typedef_from_type* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typedef_from_type* vx_empty();
    virtual vx_core::Func_typedef_from_type* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_typedef* vx_typedef_from_type(vx_core::Type_any* val);
  };

  // (func typename<-any)
  class Func_typename_from_any : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typename_from_any* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typename_from_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typename_from_any* vx_empty();
    virtual vx_core::Func_typename_from_any* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_typename_from_any(vx_core::Type_any* value);
  };

  // (func typename<-type)
  class Func_typename_from_type : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typename_from_type* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typename_from_type* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typename_from_type* vx_empty();
    virtual vx_core::Func_typename_from_type* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_typename_from_type(vx_core::Type_any* type);
  };

  // (func typename<-typedef)
  class Func_typename_from_typedef : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typename_from_typedef* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typename_from_typedef* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typename_from_typedef* vx_empty();
    virtual vx_core::Func_typename_from_typedef* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_typename_from_typedef(vx_core::Type_typedef* vtypedef);
  };

  // (func typenames<-typelist)
  class Func_typenames_from_typelist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_typenames_from_typelist* vx_new(Args*... args);
    template<class... Args> vx_core::Func_typenames_from_typelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_typenames_from_typelist* vx_empty();
    virtual vx_core::Func_typenames_from_typelist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_stringlist* vx_typenames_from_typelist(vx_core::Type_typelist* typelist);
  };

  // (func user<-context)
  class Func_user_from_context : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_core::Func_user_from_context* vx_new(Args*... args);
    template<class... Args> vx_core::Func_user_from_context* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_core::Func_user_from_context* vx_empty();
    virtual vx_core::Func_user_from_context* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_user* vx_user_from_context(vx_core::Type_context* context);
  };

  // (func any<-any)
  template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);

  // (func any<-func)
  template <class T> T* f_any_from_func(T* generic_any_1);

  // (func !)
  vx_core::Type_boolean* f_not(vx_core::Type_boolean* val);

  // (func !-empty)
  vx_core::Type_boolean* f_notempty(vx_core::Type_string* text);

  // (func !-empty)
  vx_core::Type_boolean* f_notempty_1(vx_core::Type_any* val);

  // (func !=)
  vx_core::Type_boolean* f_ne(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func *)
  vx_core::Type_int* f_multiply(vx_core::Type_int* num1, vx_core::Type_int* num2);

  // (func *)
  vx_core::Type_number* f_multiply_1(vx_core::Type_number* num1, vx_core::Type_number* num2);

  // (func *)
  vx_core::Type_int* f_multiply_2(vx_core::Type_intlist* nums);

  // (func *)
  vx_core::Type_number* f_multiply_3(vx_core::Type_numberlist* nums);

  // (func +)
  vx_core::Type_int* f_plus(vx_core::Type_int* num1, vx_core::Type_int* num2);

  // (func +)
  vx_core::Type_number* f_plus_1(vx_core::Type_number* num1, vx_core::Type_number* num2);

  // (func +)
  vx_core::Type_int* f_plus_2(vx_core::Type_intlist* nums);

  // (func +)
  vx_core::Type_number* f_plus_3(vx_core::Type_numberlist* nums);

  // (func +1)
  vx_core::Type_int* f_plus1(vx_core::Type_int* num);

  // (func -)
  vx_core::Type_int* f_minus(vx_core::Type_int* num1, vx_core::Type_int* num2);

  // (func -)
  vx_core::Type_number* f_minus_1(vx_core::Type_number* num1, vx_core::Type_number* num2);

  // (func -)
  vx_core::Type_int* f_minus_2(vx_core::Type_intlist* nums);

  // (func -)
  vx_core::Type_number* f_minus_3(vx_core::Type_numberlist* nums);

  // (func .)
  vx_core::Type_any* f_dotmethod(vx_core::Type_any* object, vx_core::Type_string* method, vx_core::Type_anylist* params);

  // (func /)
  vx_core::Type_number* f_divide(vx_core::Type_number* num1, vx_core::Type_number* num2);

  // (func <)
  vx_core::Type_boolean* f_lt(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func <)
  vx_core::Type_boolean* f_lt_1(vx_core::Type_anylist* values);

  // (func <-)
  template <class T> T* f_chainfirst(T* generic_any_1, T* value, vx_core::Type_any_from_anylist* fnlist);

  // (func <<-)
  template <class T> T* f_chainlast(T* generic_any_1, T* value, vx_core::Type_any_from_anylist* fnlist);

  // (func <=)
  vx_core::Type_boolean* f_le(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func <=)
  vx_core::Type_boolean* f_le_1(vx_core::Type_anylist* args);

  // (func =)
  vx_core::Type_boolean* f_eq(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func =)
  vx_core::Type_boolean* f_eq_1(vx_core::Type_anylist* values);

  // (func >)
  vx_core::Type_boolean* f_gt(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func >)
  vx_core::Type_boolean* f_gt_1(vx_core::Type_anylist* values);

  // (func >=)
  vx_core::Type_boolean* f_ge(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func >=)
  vx_core::Type_boolean* f_ge_1(vx_core::Type_anylist* args);

  // (func allowtypenames<-typedef)
  vx_core::Type_stringlist* f_allowtypenames_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func allowtypes<-typedef)
  vx_core::Type_typelist* f_allowtypes_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func and)
  vx_core::Type_boolean* f_and(vx_core::Type_boolean* val1, vx_core::Type_boolean* val2);

  // (func and)
  vx_core::Type_boolean* f_and_1(vx_core::Type_booleanlist* values);

  // (func any<-any-async)
  template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);

  // (func any<-any-context)
  template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);

  // (func any<-any-context-async)
  template <class T, class U> vx_core::Async<T*>* f_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context* context);

  // (func any<-func-async)
  template <class T> vx_core::Async<T*>* f_any_from_func_async(T* generic_any_1);

  // (func any<-key-value)
  template <class T, class U> T* f_any_from_key_value(T* generic_any_1, vx_core::Type_string* key, U* val);

  // (func any<-key-value-async)
  template <class T, class U> vx_core::Async<T*>* f_any_from_key_value_async(T* generic_any_1, vx_core::Type_string* key, U* val);

  // (func any<-list)
  template <class T, class X> T* f_any_from_list(T* generic_any_1, X* values, vx_core::Type_int* index);

  // (func any<-list-reduce)
  template <class T, class Y> T* f_any_from_list_reduce(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce* fn_reduce);

  // (func any<-list-reduce-next)
  template <class T, class Y> T* f_any_from_list_reduce_next(T* generic_any_1, Y* list, T* valstart, vx_core::Func_any_from_reduce_next* fn_reduce_next);

  // (func any<-map)
  template <class T, class N> T* f_any_from_map(T* generic_any_1, N* valuemap, vx_core::Type_string* key);

  // (func any<-none)
  template <class T> T* f_any_from_none(T* generic_any_1);

  // (func any<-none-async)
  template <class T> vx_core::Async<T*>* f_any_from_none_async(T* generic_any_1);

  // (func any<-reduce)
  template <class T, class U> T* f_any_from_reduce(T* generic_any_1, T* result, U* item);

  // (func any<-reduce-async)
  template <class T, class U> vx_core::Async<T*>* f_any_from_reduce_async(T* generic_any_1, T* result, U* item);

  // (func any<-reduce-next)
  template <class T, class U> T* f_any_from_reduce_next(T* generic_any_1, T* result, U* current, U* next);

  // (func any<-reduce-next-async)
  template <class T, class U> vx_core::Async<T*>* f_any_from_reduce_next_async(T* generic_any_1, T* result, U* current, U* next);

  // (func any<-struct)
  template <class T, class R> T* f_any_from_struct(T* generic_any_1, R* vstruct, vx_core::Type_string* key);

  // (func async)
  template <class T> vx_core::Async<T*>* f_async(T* generic_any_1, T* value);

  // (func boolean<-any)
  vx_core::Type_boolean* f_boolean_from_any(vx_core::Type_any* value);

  // (func boolean<-func)
  vx_core::Type_boolean* f_boolean_from_func();

  // (func boolean<-none)
  vx_core::Type_boolean* f_boolean_from_none();

  // (func case)
  vx_core::Type_thenelse* f_case(vx_core::Type_list* values, vx_core::Func_any_from_func* fn_any);

  // (func case)
  vx_core::Type_thenelse* f_case_1(vx_core::Type_any* value, vx_core::Func_any_from_func* fn_any);

  // (func compare)
  vx_core::Type_int* f_compare(vx_core::Type_any* val1, vx_core::Type_any* val2);

  // (func contains)
  vx_core::Type_boolean* f_contains(vx_core::Type_string* text, vx_core::Type_string* find);

  // (func contains)
  vx_core::Type_boolean* f_contains_1(vx_core::Type_list* values, vx_core::Type_any* find);

  // (func copy)
  template <class T> T* f_copy(T* value, vx_core::Type_anylist* values);

  // (func else)
  vx_core::Type_thenelse* f_else(vx_core::Func_any_from_func* fn_any);

  // (func empty)
  template <class T> T* f_empty(T* type);

  // (func extends<-any)
  vx_core::Type_string* f_extends_from_any(vx_core::Type_any* val);

  // (func extends<-typedef)
  vx_core::Type_string* f_extends_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func first<-list)
  template <class T, class X> T* f_first_from_list(T* generic_any_1, X* values);

  // (func first<-list-fn-any<-any)
  template <class T, class X> T* f_first_from_list_fn_any_from_any(T* generic_any_1, X* values, vx_core::Func_any_from_any* fn_any_from_any);

  // (func fn)
  template <class T> T* f_fn(T* generic_any_1, vx_core::Type_arglist* params, vx_core::Func_any_from_func* fn_any);

  // (func funcdef<-func)
  vx_core::Type_funcdef* f_funcdef_from_func(vx_core::Type_func* val);

  // (func funcname<-funcdef)
  vx_core::Type_string* f_funcname_from_funcdef(vx_core::Type_funcdef* funcdef);

  // (func global-package-get)
  vx_core::Type_package* f_global_package_get(vx_core::Type_string* pkgname);

  // (func global-package-set)
  void* f_global_package_set(vx_core::Type_string* pkgname, vx_core::Type_package* pkg);

  // (func if)
  template <class T> T* f_if(T* generic_any_1, vx_core::Type_boolean* clause, T* then);

  // (func if)
  template <class T> T* f_if_1(T* generic_any_1, vx_core::Type_boolean* clause, T* thenval, T* elseval);

  // (func if)
  template <class T> T* f_if_2(T* generic_any_1, vx_core::Type_thenelselist* thenelselist);

  // (func int<-func)
  vx_core::Type_int* f_int_from_func();

  // (func int<-string)
  vx_core::Type_int* f_int_from_string(vx_core::Type_string* val);

  // (func is-empty)
  vx_core::Type_boolean* f_is_empty(vx_core::Type_string* text);

  // (func is-empty)
  vx_core::Type_boolean* f_is_empty_1(vx_core::Type_any* value);

  // (func is-endswith)
  vx_core::Type_boolean* f_is_endswith(vx_core::Type_string* text, vx_core::Type_string* find);

  // (func is-func)
  vx_core::Type_boolean* f_is_func(vx_core::Type_any* val);

  // (func is-int)
  vx_core::Type_boolean* f_is_int(vx_core::Type_any* value);

  // (func is-number)
  vx_core::Type_boolean* f_is_number(vx_core::Type_any* value);

  // (func is-pass<-permission)
  vx_core::Type_boolean* f_is_pass_from_permission(vx_core::Type_permission* permission, vx_core::Type_context* context);

  // (func last<-list)
  template <class T, class X> T* f_last_from_list(T* generic_any_1, X* values);

  // (func length<-list)
  vx_core::Type_int* f_length_from_list(vx_core::Type_list* values);

  // (func let)
  template <class T> T* f_let(T* generic_any_1, vx_core::Func_any_from_func* fn_any);

  // (func let-async)
  template <class T> vx_core::Async<T*>* f_let_async(T* generic_any_1, vx_core::Func_any_from_func_async* fn_any_async);

  // (func list-join<-list)
  template <class X, class Y> X* f_list_join_from_list(X* generic_any_1, Y* values, vx_core::Func_any_from_any* fn_any_from_any);

  // (func list<-list)
  template <class X, class Y> X* f_list_from_list(X* generic_any_1, Y* values, vx_core::Func_any_from_any* fn_any_from_any);

  // (func list<-list-async)
  template <class X, class Y> vx_core::Async<X*>* f_list_from_list_async(X* generic_any_1, Y* values, vx_core::Func_any_from_any_async* fn_any_from_any_async);

  // (func list<-map)
  template <class X, class O> X* f_list_from_map(X* generic_any_1, O* valuemap, vx_core::Func_any_from_key_value* fn_any_from_key_value);

  // (func list<-map-async)
  template <class X, class O> vx_core::Async<X*>* f_list_from_map_async(X* generic_any_1, O* valuemap, vx_core::Func_any_from_key_value_async* fn_any_from_key_value_async);

  // (func list<-type)
  vx_core::Type_any* f_list_from_type(vx_core::Type_any* type);

  // (func log)
  vx_core::Type_any* f_log(vx_core::Type_any* value);

  // (func map<-list)
  template <class Y, class N> N* f_map_from_list(N* generic_any_1, Y* vallist, vx_core::Func_any_from_any* fn_any_from_any);

  // (func mempool-addref)
  void* f_mempool_addref(vx_core::Type_anylist* values);

  // (func mempool-release)
  void* f_mempool_release(vx_core::Type_value* value);

  // (func mempool-removeref)
  void* f_mempool_removeref(vx_core::Type_anylist* values);

  // (func mempool-removerefchildren)
  void* f_mempool_removerefchildren(vx_core::Type_anylist* values);

  // (func mempool-reserve)
  vx_core::Type_value* f_mempool_reserve();

  // (func msg<-error)
  vx_core::Type_msg* f_msg_from_error(vx_core::Type_string* error);

  // (func msgblock<-msgblock-msg)
  vx_core::Type_msgblock* f_msgblock_from_msgblock_msg(vx_core::Type_msgblock* origblock, vx_core::Type_msg* addmsg);

  // (func msgblock<-msgblock-msgblock)
  vx_core::Type_msgblock* f_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock* origblock, vx_core::Type_msgblock* addblock);

  // (func name<-typedef)
  vx_core::Type_string* f_name_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func native)
  template <class T> T* f_native(T* generic_any_1, vx_core::Type_anylist* clauses);

  // (func native<-any)
  vx_core::Type_any* f_native_from_any(vx_core::Type_any* value);

  // (func new)
  template <class T> T* f_new(T* type, vx_core::Type_anylist* values);

  // (func number<-func)
  vx_core::Type_number* f_number_from_func();

  // (func or)
  vx_core::Type_boolean* f_or(vx_core::Type_boolean* val1, vx_core::Type_boolean* val2);

  // (func or)
  vx_core::Type_boolean* f_or_1(vx_core::Type_booleanlist* values);

  // (func packagename<-typedef)
  vx_core::Type_string* f_packagename_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func path<-context-path)
  vx_core::Type_string* f_path_from_context_path(vx_core::Type_string* path, vx_core::Type_context* context);

  // (func path<-setting-path)
  vx_core::Type_string* f_path_from_setting_path(vx_core::Type_setting* session, vx_core::Type_string* path);

  // (func permission<-id-context)
  vx_core::Type_permission* f_permission_from_id_context(vx_core::Type_string* id, vx_core::Type_context* context);

  // (func properties<-typedef)
  vx_core::Type_argmap* f_properties_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func proplast<-typedef)
  vx_core::Type_arg* f_proplast_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func resolve)
  template <class T> T* f_resolve(T* generic_any_1, T* value);

  // (func resolve)
  template <class T> T* f_resolve_1(T* generic_any_1, vx_core::Func_any_from_func* fn_any);

  // (func resolve-async)
  template <class T> vx_core::Async<T*>* f_resolve_async(T* generic_any_1, vx_core::Func_any_from_func_async* fn_any);

  // (func resolve-first)
  template <class T, class X> T* f_resolve_first(T* generic_any_1, X* clauses);

  // (func resolve-list)
  template <class X> X* f_resolve_list(X* generic_any_1, X* clauses);

  // (func session<-context)
  vx_core::Type_session* f_session_from_context(vx_core::Type_context* context);

  // (func setting<-context)
  vx_core::Type_setting* f_setting_from_context(vx_core::Type_context* context);

  // (func string-repeat)
  vx_core::Type_string* f_string_repeat(vx_core::Type_string* text, vx_core::Type_int* repeat);

  // (func string<-any)
  vx_core::Type_string* f_string_from_any(vx_core::Type_any* value);

  // (func string<-any-indent)
  vx_core::Type_string* f_string_from_any_indent(vx_core::Type_any* value, vx_core::Type_int* indent, vx_core::Type_boolean* linefeed);

  // (func string<-func)
  vx_core::Type_string* f_string_from_func();

  // (func switch)
  template <class T, class U> T* f_switch(T* generic_any_1, U* val, vx_core::Type_thenelselist* thenelselist);

  // (func then)
  vx_core::Type_thenelse* f_then(vx_core::Func_boolean_from_func* fn_cond, vx_core::Func_any_from_func* fn_any);

  // (func traits<-typedef)
  vx_core::Type_typelist* f_traits_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func type<-any)
  vx_core::Type_any* f_type_from_any(vx_core::Type_any* value);

  // (func typedef<-any)
  vx_core::Type_typedef* f_typedef_from_any(vx_core::Type_any* val);

  // (func typedef<-type)
  vx_core::Type_typedef* f_typedef_from_type(vx_core::Type_any* val);

  // (func typename<-any)
  vx_core::Type_string* f_typename_from_any(vx_core::Type_any* value);

  // (func typename<-type)
  vx_core::Type_string* f_typename_from_type(vx_core::Type_any* type);

  // (func typename<-typedef)
  vx_core::Type_string* f_typename_from_typedef(vx_core::Type_typedef* vtypedef);

  // (func typenames<-typelist)
  vx_core::Type_stringlist* f_typenames_from_typelist(vx_core::Type_typelist* typelist);

  // (func user<-context)
  vx_core::Type_user* f_user_from_context(vx_core::Type_context* context);

}
