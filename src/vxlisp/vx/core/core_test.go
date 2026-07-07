package vx_core

import (
	"testing"
)

func Test_V_stringn_display_from_any(
	t *testing.T) {
	var listany []*Type_any = []*Type_any{
		T_any.type_any,
		E_any,
		A_string_from_stringn("Hello World"),
		A_stringlist_from_liststringn(
			[]string{
				"Hello",
				"World"}),
		A_stringmap_from_liststringn(
			[]string{
				":a", "1",
				":b", "2"}),
		A_anylist_from_listany(
			[]*Type_any{
				A_string_from_stringn(
					"Hello"),
				A_string_from_stringn(
					"World")}),
		A_var_cast_any(
			V_var_from_namen_type(
				"myvar",
				T_string)),
		A_func_from_type(
			T_boolean_from_booleann),
		A_func_declare_v(T_boolean_from_booleann)}
	var actualn = ""
	for _, type_any := range listany {
		var type_type = V_type_from_any(type_any)
		actualn += "" +
			"// :" + type_type.P_name +
			"\n" + V_stringn_display_from_any(type_any) +
			"\n"
	}
	V_test_from_file(
		t,
		"V_stringn_display_from_any",
		actualn)
}

func Test_A_func_boolean_from_booleann(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var actualn = ""
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		var type_any = A_func_declare_v(T_boolean_from_booleann)
		actualn += "" +
			"\n// :" + V_namen_from_lang(type_lang) +
			V_code_from_any(
				type_scope,
				0,
				"",
				type_any)
	}
	V_test_from_file(
		t,
		"a_func_boolean_from_booleann",
		actualn)
}
