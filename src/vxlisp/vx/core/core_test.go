package vx_core

import (
	"testing"
)

func V_test_listlang() []*Type_lang {
	var output = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	return output
}

func V_test_scope() *Type_scope {
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var output *Type_scope = V_scope_create()
	output.P_package = type_package
	return output
}

func A_const_declare_x(
	type_const *Type_const) map[string]string {
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var listany []*Type_any = []*Type_any{
		A_const_declare_new_from_const_part(
			type_const,
			C_enum_const_startup),
		A_const_declare_new_from_const_part(
			type_const,
			C_enum_c_const)}
	var output map[string]string = map[string]string{}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(
			type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = V_code_from_listany(
			type_scope,
			0,
			"",
			listany)
		output[langname] = actualn
	}
	return output
}

func A_type_declare_x(
	type_type *Type_type) map[string]string {
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			type_type,
			E_enum),
		A_type_declare_new_from_type_part(
			type_type,
			C_enum_t_type),
		A_type_declare_new_from_type_part(
			type_type,
			C_enum_e_type)}
	var output map[string]string = map[string]string{}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(
			type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = V_code_from_listany(
			type_scope,
			0,
			"",
			listany)
		output[langname] = actualn
	}
	return output
}

func Test_code_from_any(
	t *testing.T) {
	var path = "Test_V_code_from_any"
	var listany []*Type_any = []*Type_any{
		T_any.P_any,
		E_any,
		T_type.P_any,
		E_type.P_any,
		T_const.P_any,
		E_const.P_any}
	var listlang []*Type_lang = V_test_listlang()
	var type_scope *Type_scope = V_test_scope()
	type_scope.P_lang = C_lang_go
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		var actualn = "" +
			"\n// :" + V_namen_from_lang(
			type_lang)
		for _, type_any := range listany {
			actualn += "" +
				"\n" + V_code_any(
				type_scope,
				0,
				path,
				type_any) +
				"\n"
		}
		V_test_from_file(
			t,
			"code-from-any-"+V_namen_from_lang(
				type_lang),
			actualn)
	}
}

func Test_func_declare_v(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var actualn string = ""
	var index int = 0
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		switch type_lang {
		case C_lang_go:
			index = 0
		default:
			index = 1
		}
		var type_any = A_func_declare(
			T_boolean_from_booleann)
		actualn += "" +
			"\n// :" + V_namen_from_lang(
			type_lang) +
			V_code_any(
				type_scope,
				index,
				"",
				type_any)
	}
	V_test_from_file(
		t,
		"func-declare-v",
		actualn)
}

func Test_if_from_type_if_then(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_java,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var boolean1_var = V_var_new_from_namen_type(
		"var1",
		T_booleann)
	var actualn = ""
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		var type_any = A_if_from_type_if_then( // if var1 {
			T_boolean,
			boolean1_var.P_any,
			E_any)
		actualn += "" +
			"\n// :" + V_namen_from_lang(type_lang) +
			V_code_any(
				type_scope,
				0,
				"",
				type_any)
	}
	V_test_from_file(
		t,
		"if-from-type-if-then",
		actualn)
}

func Test_type_declare_constructor(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_constructor)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-constructor-"+
				langname,
			actualn)
	}
}

func Test_type_declare_create(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_create)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-create-"+langname,
			actualn)
	}
}

func Test_type_declare_initialize(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_initialize)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-initialize-"+langname,
			actualn)
	}
}

func Test_type_declare_shutdown(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_shutdown)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-shutdown-"+langname,
			actualn)
	}
}

func Test_type_declare_struct(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_boolean,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_float,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_generic,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_int,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_string,
			C_enum_struct),
		A_type_declare_new_from_type_part(
			T_type,
			C_enum_struct)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(
			type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-struct-"+langname,
			actualn)
	}
}

func Test_type_declare_startup(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var listany []*Type_any = []*Type_any{
		A_type_declare_new_from_type_part(
			T_any,
			C_enum_startup)}
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(type_lang.P_name)
		type_scope.P_lang = type_lang
		var actualn = "" +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
		V_test_from_file(
			t,
			"type-declare-startup-"+langname,
			actualn)
	}
}

func Test_var_declare(
	t *testing.T) {
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	var immutable_booleann1_var = V_var_new_from_namen_type(
		"immutable_booleann",
		T_booleann)
	var mutable_booleann1_var = V_var_new_mutable_from_namen_type(
		"mutable_booleann",
		T_booleann)
	var default_any_var = V_var_new_mutable_from_namen_type(
		"default_any",
		T_any)
	var nullable_any_var = V_var_new_nullable_from_namen_type(
		"nullable_any",
		T_any)
	var listany []*Type_any = []*Type_any{
		A_var_declare(
			immutable_booleann1_var,
			E_any),
		A_var_declare(
			mutable_booleann1_var,
			E_any),
		A_var_declare(
			default_any_var,
			E_any),
		A_var_declare(
			nullable_any_var,
			E_any)}
	var actualn = ""
	for _, type_lang := range listlang {
		type_scope.P_lang = type_lang
		actualn += "" +
			"\n// :" + V_namen_from_lang(type_lang) +
			V_code_from_listany(
				type_scope,
				0,
				"",
				listany)
	}
	V_test_from_file(
		t,
		"var-declare",
		actualn)
}

func Test_type_declare_any(
	t *testing.T) {
	var mapactualn map[string]string = A_type_declare_x(
		T_any)
	V_test_file_from_testnamen_mapactualn(
		t,
		"type-declare-any",
		mapactualn)
}

func Test_type_declare_string(
	t *testing.T) {
	var mapactualn map[string]string = A_type_declare_x(
		T_string)
	V_test_file_from_testnamen_mapactualn(
		t,
		"type-declare-string",
		mapactualn)
}

func Test_type_declare_type(
	t *testing.T) {
	var mapactualn map[string]string = A_type_declare_x(
		T_type)
	V_test_file_from_testnamen_mapactualn(
		t,
		"type-declare-type",
		mapactualn)
}

func Test_code_all_from_package(
	t *testing.T) {
	var path string = "code-all-from-package"
	var listlang = []*Type_lang{
		C_lang_go,
		C_lang_swift}
	var type_typemap *Type_typemap = V_typemap_from_listtype(
		[]*Type_type{
			T_boolean})
	var type_constmap *Type_constmap = V_constmap_from_listconst(
		[]*Type_const{
			V_const_from_any(
				C_false.P_any)})
	var listkey []string = []string{
		"false"}
	var listany []*Type_any = []*Type_any{
		C_false.P_any}
	var type_anymap *Type_anymap = V_anymap_from_listkey_listany(
		listkey,
		listany)
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	type_package.P_typemap = type_typemap
	type_package.P_constmap = type_constmap
	type_package.P_anymap = type_anymap
	var type_scope *Type_scope = V_scope_create()
	type_scope.P_package = type_package
	for _, type_lang := range listlang {
		var langname string = V_stringn_cast_string(
			type_lang.P_name)
		type_scope.P_lang = type_lang
		var subpath string = path +
			"-" +
			langname
		var actualn = V_code_all_from_package(
			type_scope,
			0,
			subpath,
			type_package)
		V_test_from_file(
			t,
			subpath,
			actualn)
	}
}

func Test_const_declare_false(
	t *testing.T) {
	var mapactualn map[string]string = A_const_declare_x(
		V_const_from_any(
			C_false.P_any))
	V_test_file_from_testnamen_mapactualn(
		t,
		"const-declare-false",
		mapactualn)
}

func Test_stringn_display_from_any(
	t *testing.T) {
	var type_typemap *Type_typemap = V_typemap_from_listtype(
		[]*Type_type{
			T_string})
	var type_constmap *Type_constmap = V_constmap_from_listconst(
		[]*Type_const{
			V_const_from_any(
				C_false.P_any)})
	var type_anymap *Type_anymap = V_anymap_from_listkey_listany(
		[]string{
			"false"},
		[]*Type_any{
			C_false.P_any})
	var type_package *Type_package = V_package_create()
	type_package.P_path = "vx/core"
	type_package.P_typemap = type_typemap
	type_package.P_constmap = type_constmap
	type_package.P_anymap = type_anymap
	var type_packagemap *Type_packagemap = V_packagemap_from_listpackage(
		[]*Type_package{
			type_package})
	var type_project *Type_project = V_project_create()
	type_project.P_packagemap = type_packagemap
	var listany []*Type_any = []*Type_any{
		T_any.P_any,
		E_any,
		A_string_cast_stringn(
			"Hello World"),
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
				A_string_cast_stringn(
					"Hello"),
				A_string_cast_stringn(
					"World")}),
		V_cast_anymap(
			V_anymap_from_listkey_listany(
				[]string{
					"a",
					"b"},
				[]*Type_any{
					A_string_cast_stringn(
						"Hello"),
					A_string_cast_stringn(
						"World")})),
		type_typemap.P_any,
		type_constmap.P_any,
		type_package.P_any,
		type_project.P_any,
		V_cast_var(
			V_var_new_from_namen_type(
				"myvar",
				T_string)),
		A_func_from_type(
			T_boolean_from_booleann),
		A_func_declare(
			T_boolean_from_booleann)}
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
		"stringn-display-from-any",
		actualn)
}
