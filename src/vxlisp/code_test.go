package vxlisp

import (
	"testing"
	vx_core "vxlisp/vxlisp/vx/core"
)

/*

import (
	"testing"
	"vxlisp/vxlisp/vx_core"
)

func TestCode_const_all_false(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_const *vx_core.Type_const = vx_core.C_false.P_type_any.P_type_const
	for _, type_lang := range listlang {
		var actualn string = lang_const_all(
			type_lang, type_const)
		vx_core.V_test_from_file(
			t,
			"code-const-all-false-"+langswift.name,
			actualn)
	}
}
*/

func TestCode_type_all_any(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_go,
		vx_core.C_lang_swift}
	var type_package *vx_core.Type_package = vx_core.V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *vx_core.Type_scope = vx_core.V_scope_create()
	type_scope.P_package = type_package
	var type_type *vx_core.Type_type = vx_core.T_any
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		var actualn string = code_type_all(
			type_scope,
			type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-any-"+langswift.name,
			actualn)
	}
}

/*
func TestCode_type_all_async(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_async
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-async-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_copy(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_copy
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-copy-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_decimal(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_decimal
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-decimal-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_empty(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_empty
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-empty-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_func(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_func
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-func-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_list(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_list
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-list-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_new(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_new
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-new-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_map(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_map
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-map-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_msg(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_msg
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-msg-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_msgblock_any(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_msgblock
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-msgblock-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_string(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_string
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-string-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_stringlist(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_stringlist
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-stringlist-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_stringmap(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_stringmap
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-stringmap-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_struct(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_struct
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-struct-"+langswift.name,
			actualn)
	}
}

func TestCode_type_all_type(
	t *testing.T) {
	var listlang = []*vx_core.Type_lang{
		vx_core.C_lang_swift}
	var type_type *vx_core.Type_type = vx_core.T_type
	for _, type_lang := range listlang {
		var actualn string = lang_type_all(
			type_lang, type_type)
		vx_core.V_test_from_file(
			t,
			"code-type-all-type-"+langswift.name,
			actualn)
	}
}
*/
