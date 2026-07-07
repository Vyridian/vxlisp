package vxlisp

import (
	vx_core "vxlisp/vxlisp/vx/core"
)

func lang_all_from_package(
	type_lang *vx_core.Type_scope,
	type_package *vxpackage) string {
	var listoutput []string
	var listvxconst []*vxconst = type_package.listconst
	var listtype []*vxtype = type_package.listtype
	var listfunc []*vxfunc = type_package.listfunc
	var listtypefunc []*vxtype = ListTypeFromListFunc(listfunc)
	var listvxtype []*vxtype = append(listtype, listtypefunc...)
	var listconst []*vx_core.Type_const = listconst_from_listvxconst(
		listvxconst)
	var listall = listtype_from_listvxtype(listvxtype)
	var text string = ""
	for _, type_type := range listall {
		text = code_type_class(type_lang, type_type)
		listoutput = append(listoutput, text)
		text = code_type_generic(type_lang, type_type)
		listoutput = append(listoutput, text)
		text = code_type_funcs(type_lang, type_type)
		listoutput = append(listoutput, text)
	}
	text = lang_const_funcs_from_listconst(type_lang, listconst)
	listoutput = append(listoutput, text)
	text = lang_type_t_from_listtype(type_lang, listall)
	listoutput = append(listoutput, text)
	text = lang_type_e_from_listtype(type_lang, listall)
	listoutput = append(listoutput, text)
	text = lang_const_c_from_listconst(type_lang, listconst)
	listoutput = append(listoutput, text)
	text = lang_package_startup(type_lang, type_package, listall, listconst)
	listoutput = append(listoutput, text)
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func lang_const_all(
	type_lang *vx_core.Type_scope,
	type_const *vx_core.Type_const) string {
	var output = "" +
		code_const_funcs(type_lang, type_const) +
		code_const_c(type_lang, type_const)
	return output
}

func code_const_c(
	type_scope *vx_core.Type_scope,
	type_const *vx_core.Type_const) string {
	var output = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var constname = vx_core.V_code_namen(type_scope, type_const.P_name)
	var type_type = type_const.P_const_type
	switch type_lang {
	case vx_core.C_lang_swift:
		output = lineindent + "public static let c_" + constname + " : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " + vx_core.V_code_type_pkgname(type_scope, type_type) + "v_" + vx_core.V_code_type_name(type_scope, type_type) + "_constructor()"
	}
	return output
}

func lang_const_c_from_listconst(
	type_lang *vx_core.Type_scope,
	listconst []*vx_core.Type_const) string {
	var listoutput []string
	for _, type_const := range listconst {
		listoutput = append(listoutput, code_const_c(type_lang, type_const))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func code_const_funcs(
	type_scope *vx_core.Type_scope,
	type_const *vx_core.Type_const) string {
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
	var constname = LangFromName(type_const.P_name)
	var type_type = type_const.P_const_type
	var typename = vx_core.V_code_type_typename(type_scope, type_type)
	var output = ""
	var value = ""
	switch type_lang {
	case vx_core.C_lang_swift:
		switch type_const.P_name {
		case "vx/core/false":
			value = lineindent + "  value.booleann = false"
		}
		output = "" +
			lineindent + "// V_" + constname + "_register - mutating" +
			lineindent + "public static func V_" + constname + "_register(" +
			lineindent + ") -> " + vxcore + "Type_any {" +
			lineindent + "  var value : " + typename + " = c_" + constname +
			lineindent + "  value.type_any.type_const = " + vxcore + "v_const_new_from_namen(\"" + type_const.P_name + "\")" +
			value +
			lineindent + "  return value.type_any" +
			lineindent + "}"
	}
	return output
}

func lang_const_name(
	type_lang *vx_core.Type_scope,
	type_const *vx_core.Type_const) string {
	var output = ""
	output = LangFromName(type_const.P_name)
	return output
}

func lang_const_funcs_from_listconst(
	type_lang *vx_core.Type_scope,
	listconst []*vx_core.Type_const) string {
	var listoutput []string
	for _, type_const := range listconst {
		listoutput = append(listoutput, code_const_funcs(type_lang, type_const))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func scope_from_vxlang(
	lang *vxlang) *vx_core.Type_scope {
	var output *vx_core.Type_scope = vx_core.V_scope_create()
	switch lang {
	case langgo:
		output.P_lang = vx_core.C_lang_go
	case langswift:
		output.P_lang = vx_core.C_lang_swift
	}
	return output
}

func lang_from_package(
	lang *vxlang,
	type_package *vxpackage,
	type_project *vxproject,
	pkgprefix string) (string, *vxmsgblock) {
	var output string = ""
	var type_scope *vx_core.Type_scope = scope_from_vxlang(lang)
	msgblock := NewMsgBlock("lang_from_package")
	pkgpath, pkgname := LangPackagePathFromPrefixName(
		lang, pkgprefix, type_package.name)
	specialcode := type_project.mapnative[type_package.name+"_"+lang.name+".txt"]
	if specialcode != "" {
		specialcode += "\n"
	}
	switch type_package.name {
	case "vx/core":
	default:
		specialcode = ""
	}
	packageline := LangNativePackageLine(
		lang, type_package.name, pkgpath)
	namespaceopen, namespaceclose := LangNamespaceOpenClose(
		lang, pkgname, pkgpath)
	packageall := lang_all_from_package(
		type_scope,
		type_package)
	body := "" +
		specialcode +
		packageall
		//		emptytypes
	imports := LangPackageImports(
		lang, type_package, pkgprefix, body, false)
	output = "" +
		packageline +
		imports +
		namespaceopen +
		body +
		namespaceclose
	return output, msgblock
}

/*
func lang_func_var(
	type_lang *vx_core.Type_lang,
	indent int,
	type_var *vx_core.Type_var) string {
	var lineindent = vx_core.V_lang_lineindent(type_lang, indent)
	var propname string = vx_core.V_lang_var_name(type_lang, type_var)
	var output string = lineindent + "_ " + propname + " : " + vx_core.V_lang_type_typename(type_lang, type_var.P_var_type)
	return output
}
*/

func lang_func_var_from_name_type(
	type_lang *vx_core.Type_scope,
	indent int,
	name string,
	type_type *vx_core.Type_type) string {
	var type_var *vx_core.Type_var = vx_core.V_var_create()
	type_var.P_name = vx_core.V_string_from_stringn(name)
	switch type_type.P_path {
	case "vx/core/any-1", "vx/core/any-2", "vx/core/any-3":
		type_var.P_type = vx_core.T_any
	case "vx/core/list-1", "vx/core/list-2", "vx/core/list-3":
		type_var.P_type = vx_core.T_list
	case "vx/core/map-1", "vx/core/map-2", "vx/core/map-3":
		type_var.P_type = vx_core.T_map
	case "vx/core/struct-1", "vx/core/struct-2", "vx/core/struct-3":
		type_var.P_type = vx_core.T_struct
	default:
		MsgLog(type_type.P_path)
	}
	var output string = vx_core.V_code_func_var(type_lang, indent, type_var)
	return output
}

func lang_func_body(
	type_lang *vx_core.Type_scope,
	indent int,
	type_func *vx_core.Type_func) string {
	var lineindent = vx_core.V_code_lineindent(type_lang, indent)
	var output string = "" +
		lineindent + "var output : " +
		vx_core.V_code_type_typename(type_lang, type_func.P_return_type) +
		" = " +
		vx_core.V_code_e(type_lang, type_func.P_return_type)
	return output
}

func code_func_code(
	type_scope *vx_core.Type_scope,
	indent int,
	type_func *vx_core.Type_func) string {
	var output string = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent string = vx_core.V_code_lineindent(type_scope, indent)
	var value *vx_core.Type_any = type_func.P_value_any
	var func_type *vx_core.Type_type = type_func.P_func_type
	switch func_type.P_path {
	case "vx/core/var":
		var type_var *vx_core.Type_var = vx_core.V_var_cast(value)
		var varname string = vx_core.V_stringn_from_string(type_var.P_name)
		var type_return *vx_core.Type_type = type_func.P_return_type
		var vartype string = vx_core.V_code_type_name(type_scope, type_return)
		var varvalue string = ""
		/*
			switch value.code {
			case ":func", ":funcref":
				var sub_func *vxfunc = FuncFromValue(value)
				varvalue = lang_func_code(
					type_lang, indent+1, sub_func)
			case ":string":
				var valuen string = StringFromValue(value)
				varvalue = "\"" + valuen + "\""
			}
		*/
		switch type_lang {
		case vx_core.C_lang_swift:
			output = "" +
				lineindent + "var " + varname + " : " + vartype + " = " + varvalue
		}
	}
	return output
}

func lang_func_name(
	type_lang *vx_core.Type_scope,
	type_func *vx_core.Type_func) string {
	var output = ""
	var type_type *vx_core.Type_type = type_func.P_func_type
	output = LangFromName(type_type.P_name)
	if type_type.P_idx > 0 {
		output += "_" + vx_core.V_stringn_from_intn(type_type.P_idx)
	}
	return output
}

func code_func_pkgname(
	type_scope *vx_core.Type_scope,
	type_func *vx_core.Type_func) string {
	var type_type *vx_core.Type_type = type_func.P_func_type
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	return vx_core.V_code_namen(type_scope, type_type.P_pkgname) + type_lang.P_pkgref
}

func code_type_generic(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output string = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
	var props string = code_generic_props(
		type_scope,
		type_type)
	switch type_type.P_path {
	case "vx/core/type":
		switch type_lang {
		case vx_core.C_lang_swift:
			output += "" +
				lineindent + "// Type_generic" +
				lineindent + "public class Type_generic {" +
				lineindent + "  // p_any_from_any" +
				lineindent + "  public func p_any_from_any(" +
				lineindent + "    _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
				lineindent + "    _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "    return f_empty(type_type)" +
				lineindent + "  }" +
				lineindent + "  // p_any_from_func" +
				lineindent + "  public func p_any_from_func(" +
				lineindent + "    _ return_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
				lineindent + "    _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "    return self.p_new(return_type, anylist)" +
				lineindent + "  }" +
				lineindent + "  // p_empty" +
				lineindent + "  public func p_empty(" +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "    return e_any" +
				lineindent + "  }" +
				lineindent + "  // p_copy" +
				lineindent + "  public func p_copy(" +
				lineindent + "    _ copyval : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "," +
				lineindent + "    _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "    return vx_core.V_empty_from_any(type_any)" +
				lineindent + "  }" +
				lineindent + "  // p_new" +
				lineindent + "  public func p_new(" +
				lineindent + "    _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
				lineindent + "    _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "    return " + vxcore + "f_empty(type_type)" +
				lineindent + "  }" +
				lineindent + "  // p_shutdown" +
				lineindent + "  public func p_shutdown(" +
				lineindent + "    _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
				lineindent + "  ) {" +
				/*
					lineindent + "  }" +
					lineindent + "  // p_type_list" +
					lineindent + "  public func p_type_list(" +
					lineindent + "    _ type_any : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_any) +
					lineindent + "  ) -> " + vx_core.V_lang_type_typename(type_lang, vx_core.T_list) + " {" +
					lineindent + "    let output : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_list) + " = " + vx_core.V_lang_e(type_lang, vx_core.T_list) +
					lineindent + "    return output" +
					lineindent + "  }" +
					lineindent + "  // p_type_map" +
					lineindent + "  public func p_type_map(" +
					lineindent + "    _ type_any : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_any) +
					lineindent + "  ) -> " + vx_core.V_lang_type_typename(type_lang, vx_core.T_map) + " {" +
					lineindent + "    let output : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_map) + " = " + lang_type_e(type_lang, maptype) +
					lineindent + "    return output" +
					lineindent + "  }" +
					lineindent + "  // p_type_struct" +
					lineindent + "  public func p_type_struct(" +
					lineindent + "    _ type_any : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_any) +
					lineindent + "  ) -> " + vx_core.V_lang_type_typename(type_lang, vx_core.T_struct) + " {" +
					lineindent + "    let output : " + vx_core.V_lang_type_typename(type_lang, vx_core.T_struct) + " = " + lang_type_e(type_lang, structtype) +
					lineindent + "    return output" +
					lineindent + "  }" +
				*/
				lineindent + "  // p_anylist" +
				lineindent + "  public func p_anylist(" +
				lineindent + "    _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
				lineindent + "  ) -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) + " {" +
				lineindent + "    let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) + " = " + vx_core.V_code_e(type_scope, vx_core.T_anylist) +
				lineindent + "    return output" +
				lineindent + "  }" +
				lineindent + "}"
		}
	}
	switch type_lang {
	case vx_core.C_lang_swift:
		output += "" +
			lineindent + "// Type_" + typename + "_generic" +
			lineindent + "public class Type_" + typename + "_generic : " + vxcore + "Type_generic {" +
			props +
			lineindent + "}"
	}
	return output
}

func lang_generic_from_listtype(
	type_lang *vx_core.Type_scope,
	listtype []*vx_core.Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		listoutput = append(listoutput, code_type_generic(type_lang, type_type))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func code_generic_props(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var path = type_type.P_path
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var listoutput []string
	var lineindent = vx_core.V_code_lineindent(type_scope, 2)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	switch type_lang {
	case vx_core.C_lang_swift:
		var prop = "" +
			lineindent + "// p_any_from_func" +
			lineindent + "override public func p_any_from_func(" +
			lineindent + "  _ return_type : " + vx_core.V_code_type_typename(type_scope, type_type) + "," +
			lineindent + "  _ type_anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = " + vx_core.V_code_e(type_scope, vx_core.T_any) +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// p_shutdown" +
			lineindent + "override public func p_shutdown(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") {" +
			lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " +
			vx_core.V_code_from_any(type_scope, 1, path,
				vx_core.A_if_run_from_type_listthenelse(
					vx_core.T_string,
					[]*vx_core.Type_thenelse{
						vx_core.V_then_from_booleann(
							type_type.P_path == "vx/core/any",
							vx_core.A_string_from_stringn("type_any")),
						vx_core.V_else(
							vx_core.A_string_from_stringn("v_" + typename + "_from_any(type_any)"))})) +
			lineindent + "  vx_core.V_" + typename + "_shutdown(value)" +
			lineindent + "}"
		listoutput = append(listoutput, prop)
	}
	if vx_core.V_func_from_type(type_type) != vx_core.E_func {
		/*
		    	switch vx_core.V_type_name(type_type) {
		   	 case "vx/core/copy", "vx/core/empty", "vx/core/new":
		   		switch lang {
		   		case langswift:
		   			var prop = "" +
		   				lineindent + "// p_any_from_any" +
		   				lineindent + "override public func p_any_from_any(" +
		   				lineindent + "  _ type_type : " + vx_core.V_lang_type_typename(lang, vx_core.T_type) + "," +
		   				lineindent + "  _ type_any : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) +
		   				lineindent + ") -> " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " {" +
		   				lineindent + "  let value : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " = vx_core.V_" + typename + "_any_from_any(type_type, type_any)" +
		   				lineindent + "  let output : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " = value.type_any" +
		   				lineindent + "  return output" +
		   				lineindent + "}" +
		   				lineindent + "// p_copy" +
		   				lineindent + "override public func p_copy(" +
		   				lineindent + "  _ copyany : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + "," +
		   				lineindent + "  _ anylist : " + vx_core.V_lang_type_typename(lang, vx_core.T_anylist) +
		   				lineindent + ") -> " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " {" +
		   				lineindent + "  let copyval : " + vx_core.V_lang_type_typename(lang, type_type) + " = vx_core.V_" + typename + "_from_any(copyany)" +
		   				lineindent + "  let value : " + vx_core.V_lang_type_typename(lang, type_type) + " = vx_core.V_" + typename + "_copy(copyval, type_anylist)" +
		   				lineindent + "  let output : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " = value.type_any" +
		   				lineindent + "  return output" +
		   				lineindent + "}" +
		   				lineindent + "// p_new" +
		   				lineindent + "override public func p_new(" +
		   				lineindent + "  _ type_type : " + vx_core.V_lang_type_typename(lang, vx_core.T_type) + "," +
		   				lineindent + "  _ anylist : " + vx_core.V_lang_type_typename(lang, vx_core.T_anylist) +
		   				lineindent + ") -> " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " {" +
		   				lineindent + "  let value : " + vx_core.V_lang_type_typename(lang, type_type) + " = vx_core.V_" + typename + "_new(type_type, type_anylist)" +
		   				lineindent + "  let output : " + vx_core.V_lang_type_typename(lang, vx_core.T_any) + " = value.type_any" +
		   				lineindent + "  return output" +
		   				lineindent + "}"
		   			listoutput = append(listoutput, prop)
		   		}
		*/
		switch type_type.P_path {
		case "vx/core/any":
		default:
			var output_new = ""
			var return_type = vx_core.V_type_return_from_type(type_type)
			var returnvalue = "f_" + typename + "(type_anylist)"
			switch return_type.P_path {
			case "vx/core/any":
				output_new = "" +
					lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = " + returnvalue
			default:
				output_new = "" +
					lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " + returnvalue +
					lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any"
			}
			switch type_lang {
			case vx_core.C_lang_swift:
				var prop = "" +
					lineindent + "// p_any_from_any" +
					lineindent + "override public func p_any_from_any(" +
					lineindent + "  _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
					lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
					lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
					lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_from_any(type_any)" +
					lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
					lineindent + "  return output" +
					lineindent + "}" +
					lineindent + "// p_copy" +
					lineindent + "override public func p_copy(" +
					lineindent + "  _ copyany : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "," +
					lineindent + "  _ type_anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
					lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
					lineindent + "  let copyval : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_from_any(copyany)" +
					lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_copy(copyval, type_anylist)" +
					lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
					lineindent + "  return output" +
					lineindent + "}" +
					lineindent + "// p_new" +
					lineindent + "override public func p_new(" +
					lineindent + "  _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
					lineindent + "  _ type_anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
					lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
					output_new +
					lineindent + "  return output" +
					lineindent + "}"
				listoutput = append(listoutput, prop)
				switch type_type.P_extends {
				case vx_core.C_extends_list:
					switch type_type.P_path {
					case "vx/core/list":
					default:
						var prop = "" +
							lineindent + "// p_type_list" +
							lineindent + "override public func p_type_list(" +
							lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
							lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_list) + " {" +
							lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_from_any(type_any)" +
							lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_list) + " = value.type_list" +
							lineindent + "  return output" +
							lineindent + "}"
						listoutput = append(listoutput, prop)
					}
				case vx_core.C_extends_map:
					var prop = "" +
						lineindent + "// p_type_map" +
						lineindent + "override public func p_type_map(" +
						lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
						lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " {" +
						lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " + vx_core.V_code_type_pkgname(type_scope, type_type) + "v_" + typename + "_from_any(" +
						lineindent + "    type_any" +
						lineindent + "  )" +
						lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " = value.type_map" +
						lineindent + "  return output" +
						lineindent + "}"
					listoutput = append(listoutput, prop)
				case vx_core.C_extends_struct:
					var prop = "" +
						lineindent + "// p_type_struct" +
						lineindent + "override public func p_type_struct(" +
						lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
						lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " {" +
						lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_from_any(type_any)" +
						lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " = value.type_struct" +
						lineindent + "  return output" +
						lineindent + "}"
					listoutput = append(listoutput, prop)
				}
			}
		}
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func lang_generics_from_type(
	type_lang *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = ""
	/*
		var output = "" +
			lang_generic_any(lang, type_type) +
			lang_generic_list(lang, type_type) +
			lang_generic_map(lang, type_type) +
			lang_generic_struct(lang, type_type)
	*/
	return output
}

func lang_generics_from_listtype(
	type_lang *vx_core.Type_scope,
	listtype []*vx_core.Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		listoutput = append(listoutput, lang_generics_from_type(type_lang, type_type))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(
		listoutput,
		"")
	return output
}

func lang_package_startup(
	type_lang *vx_core.Type_scope,
	type_package *vxpackage,
	listtype []*vx_core.Type_type,
	listconst []*vx_core.Type_const) string {
	var listtypes []string
	for _, type_type := range listtype {
		listtypes = append(
			listtypes,
			"v_"+vx_core.V_code_type_name(type_lang, type_type)+"_register()")
	}
	var types = "\n          " + vx_core.V_stringn_from_liststringn_joinn(
		listtypes,
		",\n          ")
	var listconsts []string
	for _, type_const := range listconst {
		listconsts = append(
			listconsts,
			"v_"+lang_const_name(type_lang, type_const)+"_register()")
	}
	var consts = "\n          " + vx_core.V_stringn_from_liststringn_joinn(
		listconsts,
		",\n          ")
	var output = "" +
		"\n  // V_startup" +
		"\n  public static func V_startup() {" +
		"\n    Vx_Core.v_packageregistry_register(" +
		"\n      Vx_Core.v_package_new_from_namen_listtype_listconst(" +
		"\n        \"" + type_package.name + "\"," +
		"\n        [" +
		types +
		"\n        ]," +
		"\n        [" +
		consts +
		"\n        ]" +
		"\n      )" +
		"\n    )" +
		"\n  }"
	return output
}

func code_type_all(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = "" +
		code_type_class(type_scope, type_type) +
		code_type_generic(type_scope, type_type) +
		code_type_funcs(type_scope, type_type) +
		code_type_t_const(type_scope, type_type) +
		code_type_e_const(type_scope, type_type)
	return output
}

func code_type_class(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output string = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	var props string = code_type_props(
		type_scope,
		type_type)
	switch type_lang {
	case vx_core.C_lang_swift:
		output = "" +
			lineindent + "// Type_" + typename +
			lineindent + "public class Type_" + typename + " {" +
			props +
			lineindent + "}"
	}
	return output
}

func code_type_e_const(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	switch type_lang {
	case vx_core.C_lang_swift:
		output = lineindent + "public static let e_" + typename + " : " + vx_core.V_code_type_typename(type_scope, type_type) + " = v_" + typename + "_constructor()"
	}
	return output
}

func lang_type_func_cast(
	type_scope *vx_core.Type_scope,
	path string,
	type_type *vx_core.Type_type) string {
	var type_lang = type_scope.P_lang
	var indent = 1
	var lineindent = vx_core.V_code_lineindent(type_scope, indent)
	var listoutput []string
	var vxcore = vx_core.V_code_type_typename(type_scope, vx_core.T_any)
	var funcs = ""
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	switch type_type.P_path {
	case "vx/core/any":
		switch type_lang {
		case vx_core.C_lang_swift:
			funcs = "" +
				lineindent + "// V_any_from_any" +
				lineindent + "public static func V_any_from_any(" +
				lineindent + "  _ type_type : Type_type," +
				lineindent + "  _ type_any : Type_any" +
				lineindent + ") -> Type_any {" +
				lineindent + "  let type_generic : Type_generic = vx_core.V_generic_from_type(type_type)" +
				lineindent + "  let output : Type_any = type_generic.p_any_from_any(type_type, type_any)" +
				lineindent + "  return output" +
				lineindent + "}"
			listoutput = append(listoutput, funcs)
		}
	case "vx/core/boolean":
		funcs = "" +
			vx_core.V_code_from_any(type_scope, indent, path,
				vx_core.A_func_declare_v(vx_core.T_boolean_from_booleann))
		switch type_lang {
		case vx_core.C_lang_swift:
			funcs += "" +
				lineindent + "// V_any_from_boolean" +
				lineindent + "public static func V_any_from_boolean(" +
				lineindent + "  _ type_boolean : " + vx_core.V_code_type_name(type_scope, vx_core.T_boolean) +
				lineindent + ") -> " + vx_core.V_code_type_name(type_scope, vx_core.T_any) + " {" +
				lineindent + "  var output : " + vxcore + "Type_boolean = " + vxcore + "c_false" +
				lineindent + "  if type_boolean.booleann {" +
				lineindent + "    output = " + vxcore + "c_true" +
				lineindent + "  }" +
				lineindent + "  return output" +
				lineindent + "}" +
				lineindent + "// V_booleann_from_boolean" +
				lineindent + "public static func V_booleann_from_boolean(" +
				lineindent + "  _ type_boolean : " + vxcore + "Type_boolean" +
				lineindent + ") -> Bool {" +
				lineindent + "  var output : Bool = false" +
				lineindent + "  if type_boolean === c_true {" +
				lineindent + "    output = true" +
				lineindent + "  }" +
				lineindent + "  return output" +
				lineindent + "}"
			listoutput = append(listoutput, funcs)
		}
	case "vx/core/list":
		funcs = "" +
			lineindent + "// V_any_from_list" +
			lineindent + "public static func V_any_from_list(" +
			lineindent + "  _ value : " + vxcore + "Type_list" +
			lineindent + ") -> " + vxcore + "Type_any {" +
			lineindent + "  let output : " + vxcore + "Type_any = value.type_any" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_list_from_any" +
			lineindent + "public static func V_list_from_any(" +
			lineindent + "  _ type_any : " + vxcore + "Type_any" +
			lineindent + ") -> " + vxcore + "Type_list {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(" +
			lineindent + "    type_any" +
			lineindent + "  )" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_list) + " = " + vxcore + "v_list_from_type(" +
			lineindent + "    type_type" +
			lineindent + "  )" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_list_new_from_any" +
			lineindent + "public static func V_list_new_from_any(" +
			lineindent + "  _ type_any : Type_any" +
			lineindent + ") -> Type_list {" +
			lineindent + "  let output : Type_list = Type_list()" +
			lineindent + "  output.type_any = type_any" +
			lineindent + "  generic_list.type_any = type_any" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	case "vx/core/map":
		funcs = "" +
			lineindent + "// V_any_from_map" +
			lineindent + "public static func V_any_from_map(" +
			lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_map_from_any" +
			lineindent + "public static func V_map_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(" +
			lineindent + "    type_any" +
			lineindent + "  )" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " = " + vxcore + "v_map_from_type(" +
			lineindent + "    type_type" +
			lineindent + "  )" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_map_new_from_any" +
			lineindent + "public static func V_map_new_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " {" +
			lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " = " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + "()" +
			lineindent + "  output.type_any = type_any" +
			lineindent + "  generic_map.type_any = type_any" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	case "vx/core/string":
		switch type_lang {
		case vx_core.C_lang_swift:
			funcs = "" +
				lineindent + "// V_any_from_" + typename +
				lineindent + "public static func V_any_from_" + typename + "(" +
				lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) +
				lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "  return value.type_any" +
				lineindent + "}" +
				lineindent + "// V_" + typename + "_from_any" +
				lineindent + "public static func V_" + typename + "_from_any(" +
				lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
				lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, type_type) + " {" +
				lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " + vx_core.V_code_e(type_scope, type_type) +
				lineindent + "  if type_any.type_type === " + code_type_t(type_scope, type_type) + " {" +
				lineindent + "    output = unsafeBitCast(type_any.backref, to: " + vx_core.V_code_type_typename(type_scope, type_type) + ".self)" +
				lineindent + "  }" +
				lineindent + "  return output" +
				lineindent + "}" +
				lineindent + "// V_any_from_stringn" +
				lineindent + "public static func V_any_from_stringn(" +
				lineindent + "  _ stringn : String" +
				lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
				lineindent + "  let value : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " = " + vxcore + "v_string_from_stringn(stringn)" +
				lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = " + vxcore + "v_any_from_string(value)" +
				lineindent + "  return output" +
				lineindent + "}" +
				lineindent + "// V_string_from_stringn" +
				lineindent + "public static func vx_core.V_string_from_stringn(" +
				lineindent + "  _ stringn : String" +
				lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " {" +
				lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " = vx_core.V_string_create()" +
				lineindent + "  output.stringn = stringn" +
				lineindent + "  return output" +
				lineindent + "}" +
				lineindent + "// V_stringn_from_string" +
				lineindent + "public static func vx_core.V_stringn_from_string(" +
				lineindent + "  _ type_string : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) +
				lineindent + ") -> String {" +
				lineindent + "  return type_string.stringn" +
				lineindent + "}"
			listoutput = append(listoutput, funcs)
		}
	case "vx/core/struct":
		funcs = "" +
			lineindent + "// V_any_from_struct" +
			lineindent + "public static func V_any_from_struct(" +
			lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_struct_from_any" +
			lineindent + "public static func V_struct_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(" +
			lineindent + "    type_any" +
			lineindent + "  )" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " = " + vxcore + "v_struct_from_type(" +
			lineindent + "    type_type" +
			lineindent + "  )" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	case "vx/core/type":
		funcs = "" +
			lineindent + "// V_any_from_type" +
			lineindent + "public static func V_any_from_type(" +
			lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_type_from_any" +
			lineindent + "public static func V_type_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " {" +
			lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vx_core.V_code_e(type_scope, vx_core.T_type) +
			lineindent + "  if let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = type_any.type_type {" +
			lineindent + "    output = type_type" +
			lineindent + "  }" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_typename_from_any" +
			lineindent + "public static func V_typename_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(type_any)" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " = " + vxcore + "v_typename_from_type(type_type)" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_typename_from_type" +
			lineindent + "public static func V_typename_from_type(" +
			lineindent + "  _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " {" +
			lineindent + "  return type_type.p_name" +
			lineindent + "}" +
			lineindent + "// V_typenamen_from_any" +
			lineindent + "public static func V_typenamen_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> String {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(type_any)" +
			lineindent + "  let output : String = " + vxcore + "v_typenamen_from_type(type_type)" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_typenamen_from_type" +
			lineindent + "public static func V_typenamen_from_type(" +
			lineindent + "  _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) +
			lineindent + ") -> String {" +
			lineindent + "  let type_string : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " = " + vxcore + "v_typename_from_type(type_type)" +
			lineindent + "  let output : String = " + vxcore + "v_stringn_from_string(type_string)" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	default:
		funcs = "" +
			lineindent + "// V_any_from_" + typename +
			lineindent + "public static func V_any_from_" + typename + "(" +
			lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, type_type) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = value.type_any" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_" + typename + "_from_any" +
			lineindent + "public static func V_" + typename + "_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, type_type) + " {" +
			lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, type_type) + " = " + vx_core.V_code_e(type_scope, type_type) +
			lineindent + "  if type_any.type_type === " + code_type_t(type_scope, type_type) + " {" +
			lineindent + "    output = unsafeBitCast(type_any.backref, to: " + vx_core.V_code_type_typename(type_scope, type_type) + ".self)" +
			lineindent + "  }" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func code_type_func_shutdown(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var listoutput []string
	var vxcore = vx_core.V_code_type_typename(type_scope, vx_core.T_any)
	var funcn = ""
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	switch type_type.P_path {
	case "vx/core/any":
		switch type_lang {
		case vx_core.C_lang_swift:
			funcn = "" +
				lineindent + "// V_" + typename + "_shutdown - mutating" +
				lineindent + "public static func V_" + typename + "_shutdown(" +
				lineindent + "  _ value : Type_" + typename +
				lineindent + ") {" +
				lineindent + "  if let type_msgblock : Vx_Core.Type_msgblock = value.type_msgblock {" +
				lineindent + "    value.type_msgblock = nil" +
				lineindent + "    Vx_Core.v_release_any(type_msgblock.type_any)" +
				lineindent + "  }" +
				lineindent + "  if let type_const : Vx_Core.Type_const = value.type_const {" +
				lineindent + "    value.type_const = nil" +
				lineindent + "    Vx_Core.v_const_shutdown(type_const)" +
				lineindent + "  }" +
				lineindent + "  value.type_type = nil" +
				lineindent + "  Vx_Core.v_global_release()" +
				lineindent + "}" +
				lineindent + "// V_" + typename + "_startup - mutating" +
				lineindent + "public static func V_" + typename + "_startup(" +
				lineindent + "  _ value : Type_" + typename +
				lineindent + ") {" +
				lineindent + "}"
			listoutput = append(listoutput, funcn)
		}
	default:
		var subtypen = ""
		switch type_type.P_path {
		case "vx/core/list":
			subtypen = "" +
				lineindent + "  value.type_list = Vx_Core.e_list"
		case "vx/core/map":
			subtypen = "" +
				lineindent + "  value.type_map = Vx_Core.e_map"
		case "vx/core/string":
			subtypen = "" +
				lineindent + "  value.stringn = \"\""
		case "vx/core/struct":
			subtypen = "" +
				lineindent + "  value.type_struct = Vx_Core.e_struct"
		default:
			var containertype = type_type.P_container_type
			var containername = vx_core.V_code_type_name(type_scope, containertype)
			switch type_lang {
			case vx_core.C_lang_swift:
				switch type_type.P_extends {
				case vx_core.C_extends_list:
					subtypen = "" +
						lineindent + "  value.type_list = " + vx_core.V_code_e(type_scope, vx_core.T_list) +
						lineindent + "  let listany : [" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] = vx_core.V_" + typename + "_listany_from_" + typename + "(value)" +
						lineindent + "  value.list" + containername + " = []" +
						lineindent + "  " + vxcore + "v_release_listany(listany)"
				case vx_core.C_extends_map:
					subtypen = "" +
						lineindent + "  value.type_map = " + vx_core.V_code_e(type_scope, vx_core.T_map) +
						lineindent + "  let mapany : [String:" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] = vx_core.V_" + typename + "_mapany_from_" + typename + "(value)" +
						lineindent + "  value.map" + containername + " = [:]" +
						lineindent + "  " + vxcore + "v_release_mapany(mapany)"
				case vx_core.C_extends_struct:
					subtypen += "" +
						lineindent + "  value.type_struct = " + vxcore + "e_struct"
					var letpropn = ""
					var setpropn = ""
					var listreleasepropn []string
					var properties *vx_core.Type_varlist = type_type.P_propertylist
					var listproperty []*vx_core.Type_var = properties.P_listvar
					for _, prop := range listproperty {
						/*
							if prop.name == "constmap" {
								if type_type.name == "package" {
									prop.vxtype = anymaptype
								}
							}
						*/
						letpropn += "" +
							lineindent + "  let p_" + vx_core.V_code_name(type_scope, prop.P_name) + " : " + vx_core.V_code_type_typename(type_scope, prop.P_type) + " = value.p_" + vx_core.V_code_name(type_scope, prop.P_name)
						setpropn += "" +
							lineindent + "  value.p_" + vx_core.V_code_name(type_scope, prop.P_name) + " = " + vx_core.V_code_e(type_scope, prop.P_type)
						var releasepropn = "" +
							lineindent + "      p_" + vx_core.V_code_name(type_scope, prop.P_name) + ".type_any"
						listreleasepropn = append(listreleasepropn, releasepropn)
					}
					subtypen += "" +
						letpropn +
						setpropn +
						lineindent + "  " + vxcore + "v_release_listany(" +
						lineindent + "    [" +
						vx_core.V_stringn_from_liststringn_joinn(listreleasepropn, ",") +
						lineindent + "    ]" +
						lineindent + "  )"
				}
			}
		}
		funcn = "" +
			lineindent + "// V_" + typename + "_shutdown - mutating" +
			lineindent + "public static func V_" + typename + "_shutdown(" +
			lineindent + "  _ value : Type_" + typename +
			lineindent + ") {" +
			lineindent + "  let type_any : " + vxcore + "Type_any = value.type_any" +
			lineindent + "  value.type_any = " + vx_core.V_code_e(type_scope, vx_core.T_any) +
			subtypen +
			lineindent + "}"
		listoutput = append(listoutput, funcn)
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func code_type_func_startup(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var listoutput []string
	var vxcore = vx_core.V_code_type_typename(type_scope, vx_core.T_any)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	var funcstartup = ""
	switch type_type.P_path {
	case "vx/core/any":
		switch type_lang {
		case vx_core.C_lang_swift:
			funcstartup = "" +
				lineindent + "// V_" + typename + "_startup - mutating" +
				lineindent + "public static func V_" + typename + "_startup(" +
				lineindent + "  _ value : Type_" + typename +
				lineindent + ") {" +
				lineindent + "}"
		}
		/*
			default:
				var subtypen = ""
				switch type_type.P_path {
				case "vx/core/list", "vx/core/map", "vx/core/struct":
				default:
					switch type_lang {
					case vx_core.C_lang_swift:
						switch extendsn {
						case ":list":
							subtypen = "" +
								lineindent + "  value.type_list = " + vxcore + "v_list_new_from_any(" +
								lineindent + "    value.type_any" +
								lineindent + "  )"
						case ":map":
							subtypen = "" +
								lineindent + "  value.type_map = " + vxcore + "v_map_new_from_any(" +
								lineindent + "    value.type_any" +
								lineindent + "  )"
						case ":struct":
							subtypen = "" +
								lineindent + "  value.type_struct = " + vxcore + "v_struct_new_from_any(" +
								lineindent + "    value.type_any" +
								lineindent + "  )"
						}
					}
				}
		*/
		funcstartup = "" +
			lineindent + "// V_" + typename + "_startup - mutating" +
			lineindent + "public static func V_" + typename + "_startup(" +
			lineindent + "  _ value : " + vx_core.V_code_type_typename(type_scope, type_type) +
			lineindent + ") {" +
			lineindent + "  value.type_any = " + vxcore + "v_any_new_from_type_backref(" +
			lineindent + "    " + code_type_t(type_scope, type_type) + "," +
			lineindent + "    value" +
			lineindent + "  )" +
			lineindent + "}"
		listoutput = append(listoutput, funcstartup)
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func code_type_funcs(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var indent = 1
	var path = type_type.P_path
	var lineindent = vx_core.V_code_lineindent(type_scope, indent)
	var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
	var listoutput []string
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	var extends = ""
	switch type_type.P_extends {
	case vx_core.E_string:
		extends = vxcore + "e_string"
	case vx_core.C_extends_func:
		extends = vxcore + "e_extends_func"
	case vx_core.C_extends_list:
		extends = vxcore + "e_extends_list"
	case vx_core.C_extends_map:
		extends = vxcore + "e_extends_map"
	case vx_core.C_extends_struct:
		extends = vxcore + "e_extends_struct"
	}
	var e_typeany = "e_" + typename + ".type_any"
	switch type_type.P_path {
	case "vx/core/any":
		e_typeany = "e_any"
	}
	var funcs = "" +
		lineindent + "// V_" + typename + "_constructor" +
		lineindent + "public static func V_" + typename + "_constructor(" +
		lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, type_type) + " {" +
		lineindent + "  " + vxcore + "v_global_reserve()" +
		lineindent + "  return Type_" + typename + "()" +
		lineindent + "}" +
		lineindent + "// V_" + typename + "_create" +
		lineindent + "public static func V_" + typename + "_create(" +
		lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, type_type) + " {" +
		lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, type_type) + " = vx_core.V_" + typename + "_constructor()" +
		lineindent + "  V_" + typename + "_startup(output)" +
		lineindent + "  return output" +
		lineindent + "}" +
		lineindent + "// V_" + typename + "_register" +
		lineindent + "public static func V_" + typename + "_register(" +
		lineindent + ") -> Vx_Core.Type_type {" +
		lineindent + "  V_" + typename + "_startup_type()" +
		lineindent + "  V_" + typename + "_startup_empty()" +
		lineindent + "  return " + code_type_t(type_scope, type_type) +
		lineindent + "}"
	listoutput = append(listoutput, funcs)
	funcs = code_type_func_shutdown(type_scope, type_type)
	listoutput = append(listoutput, funcs)
	funcs = code_type_func_startup(type_scope, type_type)
	listoutput = append(listoutput, funcs)
	funcs = "" +
		lineindent + "// V_" + typename + "_startup_empty" +
		lineindent + "public static func V_" + typename + "_startup_empty() {" +
		lineindent + "  V_" + typename + "_startup(e_" + typename + ")" +
		lineindent + "  " + vxcore + "v_startup_e(" +
		lineindent + "    t_" + typename + "," +
		lineindent + "    " + e_typeany +
		lineindent + "  )" +
		lineindent + "}" +
		lineindent + "// V_" + typename + "_startup_type" +
		lineindent + "public static func V_" + typename + "_startup_type() -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " {" +
		lineindent + "  let type_type = " + code_type_t(type_scope, type_type) +
		lineindent + "  type_type.p_name = " + vxcore + "v_string_from_stringn(" +
		lineindent + "    \"" + type_type.P_path + "\"" +
		lineindent + "  )" +
		lineindent + "  type_type.p_extends = " + extends +
		lineindent + "  let type_generic : " + vxcore + "Type_generic = Type_" + typename + "_generic()" +
		lineindent + "  " + vxcore + "v_startup_t(" +
		lineindent + "    type_type," +
		lineindent + "    type_generic" +
		lineindent + "  )" +
		lineindent + "  return type_type" +
		lineindent + "}"
	listoutput = append(listoutput, funcs)
	var funccast = lang_type_func_cast(type_scope, path, type_type)
	listoutput = append(listoutput, funccast)
	switch type_type.P_path {
	case "vx/core/any":
		funcs = "" +
			lineindent + "// V_copy" +
			lineindent + "public static func V_copy(" +
			lineindent + "  _ type_any : " + vxcore + "Type_any," +
			lineindent + "  _ anylist : " + vxcore + "Type_anylist" +
			lineindent + ") -> Type_any {" +
			lineindent + "  let type_type : " + vxcore + "Type_type = " + vxcore + "v_type_from_any(type_any)" +
			lineindent + "  let type_generic : " + vxcore + "Type_generic = vx_core.V_generic_from_type(type_type)" +
			lineindent + "  let output : " + vxcore + "Type_any = type_generic.p_copy(type_any, anylist)" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_empty_from_any" +
			lineindent + "public static func V_empty_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_from_any(type_any)" +
			lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " = " + vxcore + "v_empty(type_type)" +
			lineindent + "  return output" +
			lineindent + "}" +
			lineindent + "// V_new" +
			lineindent + "public static func V_new(" +
			lineindent + "  _ type_type : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + "," +
			lineindent + "  _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + " {" +
			lineindent + "  let type_generic : " + vxcore + "Type_generic = vx_core.V_generic_from_type(type_type)" +
			lineindent + "  let output : " + vxcore + "Type_any = type_generic.p_new(type_type, anylist)" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	case "vx/core/struct":
		funcs = "" +
			lineindent + "// V_struct_new_from_any" +
			lineindent + "public static func V_struct_new_from_any(" +
			lineindent + "  _ type_any : " + vx_core.V_code_type_typename(type_scope, vx_core.T_any) +
			lineindent + ") -> " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " {" +
			lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " = " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + "()" +
			lineindent + "  output.type_any = type_any" +
			lineindent + "  generic_struct.type_any = type_any" +
			lineindent + "  return output" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	case "vx/core/type":
		funcs = "" +
			lineindent + "// V_empty" +
			lineindent + "public static func V_empty(" +
			lineindent + "  _ type_type : " + vxcore + "Type_type" +
			lineindent + ") -> " + vxcore + "Type_any {" +
			lineindent + "  let type_generic : " + vxcore + "Type_generic = V_generic_from_type(type_type)" +
			lineindent + "  return type_generic.p_empty()" +
			lineindent + "}"
		listoutput = append(listoutput, funcs)
	}
	funcs = code_type_func_copy(type_scope, type_type)
	listoutput = append(listoutput, funcs)
	funcs = lang_type_func_list(type_scope, indent, path, type_type)
	listoutput = append(listoutput, funcs)
	funcs = code_type_func_map(type_scope, indent, path, type_type)
	listoutput = append(listoutput, funcs)
	funcs = lang_type_f(type_scope, type_type)
	listoutput = append(listoutput, funcs)
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func lang_type_func_list(
	type_lang *vx_core.Type_scope,
	indent int,
	path string,
	type_type *vx_core.Type_type) string {
	var output = ""
	var extendsn = type_type.P_extends
	switch extendsn {
	case vx_core.C_extends_list:
		var typename = vx_core.V_code_type_name(type_lang, type_type)
		var liststring []string
		var list_type = type_type.P_container_type
		var maintypename = vx_core.V_code_type_name(type_lang, list_type)
		var prop = "" +
			vx_core.V_code_from_any(type_lang, indent, path,
				vx_core.A_string_from_stringn(
					"\n// V_"+typename+"_listany_from_"+typename+
						"\npublic static func V_"+typename+"_listany_from_"+typename+"("+
						"\n  _ type_"+typename+" : "+vx_core.V_code_type_typename(type_lang, type_type)+
						"\n) -> ["+vx_core.V_code_type_typename(type_lang, vx_core.T_any)+"] {"+
						"\n  var output : ["+vx_core.V_code_type_typename(type_lang, vx_core.T_any)+"] = []"+
						"\n  var listvalue : ["+vx_core.V_code_type_typename(type_lang, list_type)+"] = type_"+typename+".list"+maintypename+
						"\n  for value : "+vx_core.V_code_type_typename(type_lang, list_type)+" in listvalue {"+
						"\n    output.append(value.type_any)"+
						"\n  }"+
						"\n  return output"+
						"\n}"))
		liststring = append(liststring, prop)
		var allowtypes *vx_core.Type_typelist = type_type.P_allowtypes
		var listallowtypes []*vx_core.Type_type = allowtypes.P_listtype
		for _, allow_type := range listallowtypes {
			switch allow_type.P_path {
			case "vx/core/any":
			default:
				var allowtypename = vx_core.V_code_type_name(type_lang, allow_type)
				var prop = "" +
					vx_core.V_code_from_any(type_lang, indent, path,
						vx_core.A_if_run_from_type_listthenelse(
							vx_core.T_string,
							[]*vx_core.Type_thenelse{
								vx_core.V_then_from_booleann(
									type_type.P_path == "vx/core/any",
									vx_core.V_string_cast_any(vx_core.E_string)),
								vx_core.V_then_from_booleann(
									vx_core.V_func_from_type(type_type) != vx_core.E_func,
									vx_core.A_anylist_run_from_listany(
										[]*vx_core.Type_any{
											vx_core.A_string_from_stringn(
												"\n// V_" + typename + "_listany_from_list" + allowtypename +
													"\npublic static func V_" + typename + "_listany_from_list" + allowtypename + "(" +
													"\n  _ listvalue : [" + vx_core.V_code_type_typename(type_lang, allow_type) + "]" +
													"\n) -> [" + vx_core.V_code_type_typename(type_lang, vx_core.T_any) + "] {" +
													"\n  var output : [" + vx_core.V_code_type_typename(type_lang, vx_core.T_any) + "] = []" +
													"\n  for value : " + vx_core.V_code_type_typename(type_lang, allow_type) + " in listvalue {" +
													"\n    output.append(value.type_any)" +
													"\n  }" +
													"\n  return output" +
													"\n}"),
											vx_core.A_string_from_stringn(
												"\n// V_" + typename + "_list" + allowtypename + "_from_listany" +
													"\npublic static func V_" + typename + "_list" + allowtypename + "_from_listany(" +
													"\n  _ listany : [" + vx_core.V_code_type_typename(type_lang, vx_core.T_any) + "]" +
													"\n) -> [" + vx_core.V_code_type_typename(type_lang, allow_type) + "] {" +
													"\n  var output : [" + vx_core.V_code_type_typename(type_lang, allow_type) + "] = []" +
													"\n  for type_any : " + vx_core.V_code_type_typename(type_lang, vx_core.T_any) + " in listany {" +
													"\n    let value : " + vx_core.V_code_type_typename(type_lang, allow_type) + " = " +
													vx_core.V_code_from_any(type_lang, indent+2, path,
														vx_core.A_if_run_from_type_listthenelse(
															vx_core.T_string,
															[]*vx_core.Type_thenelse{
																vx_core.V_then_from_booleann(
																	type_type.P_path == "vx/core/any",
																	vx_core.A_string_from_stringn("type_any")),
																vx_core.V_else(
																	vx_core.A_string_from_stringn("v_" + allowtypename + "_from_any(type_any)"))})) +
													"\n    if value !== " + vx_core.V_code_e(type_lang, allow_type) + " {" +
													"\n      output.append(value)" +
													"\n    }" +
													"\n  }" +
													"\n  return output" +
													"\n}")}))}))
				liststring = append(liststring, prop)
			}
		}
		output = vx_core.V_stringn_from_liststringn_joinn(liststring, "")
	}
	return output
}

func code_type_func_map(
	type_scope *vx_core.Type_scope,
	indent int,
	path string,
	type_type *vx_core.Type_type) string {
	var output = ""
	var extends = type_type.P_extends
	switch extends {
	case vx_core.C_extends_map:
		var typename = vx_core.V_code_type_name(type_scope, type_type)
		var liststring []string
		var main_type = type_type.P_container_type
		var maintypename = vx_core.V_code_type_name(
			type_scope,
			main_type)
		var prop = "" +
			vx_core.V_code_from_any(type_scope, indent, path,
				vx_core.A_string_from_stringn(
					"\n// V_"+typename+"_mapany_from_"+typename+
						"\npublic static func V_"+typename+"_mapany_from_"+typename+"("+
						"\n  _ type_"+typename+" : "+vx_core.V_code_type_typename(type_scope, type_type)+
						"\n) -> [String:"+vx_core.V_code_type_typename(type_scope, vx_core.T_any)+"] {"+
						"\n  var output : [String:"+vx_core.V_code_type_typename(type_scope, vx_core.T_any)+"] = [:]"+
						"\n  var mapvalue : [String:"+vx_core.V_code_type_typename(type_scope, main_type)+"] = type_"+typename+".map"+maintypename+
						"\n  for (key, value) in mapvalue {"+
						"\n    output[key] = value.type_any"+
						"\n  }"+
						"\n  return output"+
						"\n}"))
		liststring = append(liststring, prop)
		var allowtypes *vx_core.Type_typelist = type_type.P_allowtypes
		var listallowtype []*vx_core.Type_type = allowtypes.P_listtype
		for _, allow_type := range listallowtype {
			switch allow_type.P_path {
			case "vx/core/any":
			default:
				var allowtypename = vx_core.V_code_type_name(type_scope, allow_type)
				var allowpkg = vx_core.V_code_type_pkgname(type_scope, allow_type)
				var prop = "" +
					vx_core.V_code_from_any(type_scope, indent, path,
						vx_core.A_if_run_from_type_listthenelse(
							vx_core.T_string,
							[]*vx_core.Type_thenelse{
								vx_core.V_then_from_booleann(
									type_type.P_path == "vx/core/any",
									vx_core.V_string_cast_any(vx_core.E_string)),
								vx_core.V_then_from_booleann(
									vx_core.V_func_from_type(type_type) != vx_core.E_func,
									vx_core.A_anylist_run_from_listany(
										[]*vx_core.Type_any{
											vx_core.A_string_from_stringn(
												"\n// V_" + typename + "_map_from_map" + allowtypename +
													"\npublic static func V_" + typename + "_mapany_from_map" + allowtypename + "(" +
													"\n  _ mapvalue : [String:" + vx_core.V_code_type_typename(type_scope, allow_type) + "]" +
													"\n) -> [String:" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] {" +
													"\n  var output : [String:" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] = [:]" +
													"\n  for (key, value) in mapvalue {" +
													"\n    output[key] = value.type_any" +
													"\n  }" +
													"\n  return output" +
													"\n}"),
											vx_core.A_string_from_stringn(
												"\n// V_" + typename + "_map" + allowtypename + "_from_mapany" +
													"\npublic static func V_" + typename + "_map" + allowtypename + "_from_mapany(" +
													"\n  _ mapany : [String:" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "]" +
													"\n) -> [String:" + vx_core.V_code_type_typename(type_scope, allow_type) + "] {" +
													"\n  var output : [String:" + vx_core.V_code_type_typename(type_scope, allow_type) + "] = [:]" +
													"\n  for (key, type_any) in mapany {" +
													"\n    let value : " + vx_core.V_code_type_typename(type_scope, allow_type) + " = " +
													vx_core.V_code_from_any(type_scope, indent+2, path,
														vx_core.A_if_run_from_type_listthenelse(
															vx_core.T_string,
															[]*vx_core.Type_thenelse{
																vx_core.V_then_from_booleann(
																	type_type.P_path == "vx/core/any",
																	vx_core.A_string_from_stringn("type_any")),
																vx_core.V_else(
																	vx_core.A_string_from_stringn(allowpkg + "v_" + allowtypename + "_from_any(type_any)"))})) +
													"\n    if value !== " + vx_core.V_code_e(type_scope, allow_type) + " {" +
													"\n      output[key] = value" +
													"\n    }" +
													"\n  }" +
													"\n  return output" +
													"\n}")}))}))
				liststring = append(liststring, prop)
			}
		}
		output = vx_core.V_stringn_from_liststringn_joinn(liststring, "")
	}
	return output
}

func lang_type_e_from_listtype(
	type_lang *vx_core.Type_scope,
	listtype []*vx_core.Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		listoutput = append(listoutput, code_type_e_const(type_lang, type_type))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func lang_type_f(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var indent = 1
	var lineindent = vx_core.V_code_lineindent(type_scope, indent)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	switch type_lang {
	case vx_core.C_lang_swift:
		var type_return *vx_core.Type_type = type_type
		var props string = ""
		var body string = ""
		var type_func *vx_core.Type_func = vx_core.V_func_from_type(
			type_type)
		if type_func != vx_core.E_func {
			type_return = type_func.P_return_type
			body = lang_func_body(type_scope, indent+1, type_func)
			var listprop []string
			if type_func.P_generic_type != nil {
				switch type_type.P_path {
				case "vx/core/empty":
				default:
					var prop = lang_func_var_from_name_type(type_scope, indent+1,
						"return_type",
						type_func.P_generic_type)
					listprop = append(listprop, prop)
				}
			}
			if type_func.P_context {
				var prop string = vx_core.V_code_func_var(type_scope, indent+1, vx_core.C_var_context)
				listprop = append(listprop, prop)
			}
			var varlist *vx_core.Type_varlist = type_func.P_type_varlist
			if varlist != vx_core.E_varlist {
				var listvar []*vx_core.Type_var = varlist.P_listvar
				for _, type_var := range listvar {
					var prop string = vx_core.V_code_func_var(type_scope, indent+1, type_var)
					listprop = append(listprop, prop)
				}
			}
			props = vx_core.V_stringn_from_liststringn_joinn(listprop, ",")
		} else {
			props = "" +
				lineindent + "  _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist)
			body = "" +
				lineindent + "  let output : " + vx_core.V_code_type_typename(type_scope, type_return) + " = vx_core.V_" + typename + "_copy(" +
				lineindent + "    " + vx_core.V_code_e(type_scope, type_type) + "," +
				lineindent + "    anylist" +
				lineindent + "  )"
		}
		returntype := vx_core.V_code_type_typename(type_scope, type_return)
		output = "" +
			lineindent + "// f_" + typename +
			lineindent + "public static func f_" + typename + "(" +
			props +
			lineindent + ") -> " + returntype + " {" +
			body +
			lineindent + "  return output" +
			lineindent + "}"
	}
	return output
}

func code_type_func_copy(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	if vx_core.V_func_from_type(type_type) != vx_core.E_func {
		var indent = 1
		var lineindent = vx_core.V_code_lineindent(type_scope, indent)
		var typename = vx_core.V_code_type_name(type_scope, type_type)
		var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
		switch type_lang {
		case vx_core.C_lang_swift:
			var type_return *vx_core.Type_type = type_type
			var props string = ""
			var header1 string = ""
			var header2 string = ""
			var loopopen string = ""
			var loopcustom string = ""
			var loopclose string = ""
			var footer1 string = ""
			var footer2 string = ""
			var footer3 string = ""
			props = "" +
				lineindent + "  _ copyval : " + vx_core.V_code_type_typename(type_scope, type_type) + "," +
				lineindent + "  _ anylist : " + vx_core.V_code_type_typename(type_scope, vx_core.T_anylist)
			switch type_type.P_path {
			case "vx/core/any", "vx/core/list", "vx/core/map", "vx/core/struct", "vx/core/type":
				footer3 += "" +
					lineindent + "  return copyval"
			default:
				header1 = "" +
					lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, type_type) + " = copyval" +
					lineindent + "  " + vxcore + "v_reserve_listany(" +
					lineindent + "    [" +
					lineindent + "      copyval.type_any," +
					lineindent + "      anylist.type_any" +
					lineindent + "    ]" +
					lineindent + "  )"
				footer1 = "" +
					lineindent + "  var ischanged : Vx_Core.Type_boolean = Vx_Core.c_false" +
					lineindent + "  let orig_msgblock : " + vxcore + "Type_msgblock = " + vxcore + "v_msgblock_from_any(" +
					lineindent + "    copyval.type_any" +
					lineindent + "  )" +
					lineindent + "  if msgblock !== orig_msgblock {" +
					lineindent + "    ischanged = Vx_Core.c_true" +
					lineindent + "  }"
				footer3 = "" +
					lineindent + "  return output"
				switch type_type.P_path {
				case "vx/core/string":
					header2 = "" +
						lineindent + "  let filter_anylist : " + vxcore + "Type_anylist = " + vxcore + "v_anylist_from_listtype_anylist(" +
						lineindent + "    [" + vxcore + "t_string]," +
						lineindent + "    anylist" +
						lineindent + "  )" +
						lineindent + "  let msgblock : " + vxcore + "Type_msgblock = " + vxcore + "v_msgblock_from_any(" +
						lineindent + "    filter_anylist.type_any" +
						lineindent + "  )"
					footer2 = "" +
						lineindent + "  var stringn : String = \"\"" +
						lineindent + "  if filter_anylist !== " + vxcore + "e_anylist {" +
						lineindent + "    let stringlist : " + vxcore + "Type_stringlist = " + vxcore + "v_stringlist_from_anylist(filter_anylist)" +
						lineindent + "    let liststringn : [String] = " + vxcore + "v_liststringn_from_liststring(stringlist.liststring)" +
						lineindent + "    " + vxcore + "v_release(stringlist.type_any)" +
						lineindent + "    stringn = vx_core.V_stringn_from_liststringn_joinn(liststringn, \"\")" +
						lineindent + "  }" +
						lineindent + "  if ischanged === Vx_Core.c_false {" +
						lineindent + "    if stringn != copyval.stringn {" +
						lineindent + "      ischanged = Vx_Core.c_true" +
						lineindent + "    }" +
						lineindent + "  }" +
						lineindent + "  var output : " + vx_core.V_code_type_typename(type_scope, vx_core.T_string) + " = copyval" +
						lineindent + "  if ischanged === Vx_Core.c_true {" +
						lineindent + "    let type_delta : " + vxcore + "Type_delta = " + vxcore + "v_delta_from_any(" +
						lineindent + "      filter_anylist.type_any" +
						lineindent + "    )" +
						lineindent + "    " + vxcore + "v_reserve_msgblock(msgblock)" +
						lineindent + "    " + vxcore + "v_reserve_delta(type_delta)" +
						lineindent + "    output = " + vxcore + "v_string_create()" +
						lineindent + "    output.stringn = stringn" +
						lineindent + "    output.type_any.type_msgblock = msgblock" +
						lineindent + "    output.type_any.type_delta = type_delta" +
						lineindent + "  }" +
						lineindent + "  Vx_Core.v_release_except_listany(" +
						lineindent + "    output.type_any," +
						lineindent + "    [" +
						lineindent + "      copyval.type_any," +
						lineindent + "      anylist.type_any," +
						lineindent + "      filter_anylist.type_any" +
						lineindent + "    ]" +
						lineindent + "  )"
				default:
					switch type_type.P_extends {
					case vx_core.C_extends_list:
						var container_type *vx_core.Type_type = type_type.P_container_type
						var allownamen = vx_core.V_code_type_name(type_scope, container_type)
						var allowtypen = vx_core.V_code_type_typename(type_scope, container_type)
						header2 = "" +
							lineindent + "  let type_type : Vx_Core.Type_type = " + vxcore + "v_type_from_any(copyval.type_any)" +
							lineindent + "  let orig_anylist : Vx_Core.Type_anylist = Vx_Core.v_anylist_from_any(" +
							lineindent + "    copyval.type_any" +
							lineindent + "  )" +
							lineindent + "  let merged_anylist : Vx_Core.Type_anylist = Vx_Core.v_anylist_from_type_anylist_anylist(" +
							lineindent + "    type_type," +
							lineindent + "    orig_anylist," +
							lineindent + "    anylist" +
							lineindent + "  )" +
							lineindent + "  let msgblock : Vx_Core.Type_msgblock = Vx_Core.v_msgblock_from_any(" +
							lineindent + "    merged_anylist.type_any" +
							lineindent + "  )"
						footer2 = "" +
							lineindent + "  if ischanged === Vx_Core.c_false {" +
							lineindent + "    ischanged = Vx_Core.v_boolean_issame_from_anylist_anylist(" +
							lineindent + "      orig_anylist," +
							lineindent + "      merged_anylist" +
							lineindent + "    )" +
							lineindent + "  }" +
							lineindent + "  if ischanged === Vx_Core.c_true {" +
							lineindent + "    let type_delta : Vx_Core.Type_delta = Vx_Core.v_delta_from_any(" +
							lineindent + "      merged_anylist.type_any" +
							lineindent + "    )" +
							lineindent + "    let listany : [" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] = " + vxcore + "v_listany_from_anylist(" +
							lineindent + "      merged_anylist" +
							lineindent + "    )" +
							lineindent + "    let list" + allownamen + " : [" + allowtypen + "] = vx_core.V_" + typename + "_list" + allownamen + "_from_listany(" +
							lineindent + "      listany" +
							lineindent + "    )" +
							lineindent + "    Vx_Core.v_reserve_listany(listany)" +
							lineindent + "    Vx_Core.v_reserve_msgblock(msgblock)" +
							lineindent + "    Vx_Core.v_reserve_delta(type_delta)" +
							lineindent + "    output = vx_core.V_" + typename + "_create()" +
							lineindent + "    output.list" + allownamen + " = list" + allownamen +
							lineindent + "    output.type_any.type_msgblock = msgblock" +
							lineindent + "    output.type_any.type_delta = type_delta" +
							lineindent + "  }" +
							lineindent + "  Vx_Core.v_release_except_listany(" +
							lineindent + "    output.type_any," +
							lineindent + "    [" +
							lineindent + "      copyval.type_any," +
							lineindent + "      anylist.type_any," +
							lineindent + "      merged_anylist.type_any" +
							lineindent + "    ]" +
							lineindent + "  )"
					case vx_core.C_extends_map:
						var container_type *vx_core.Type_type = type_type.P_container_type
						var allownamen = vx_core.V_code_type_name(type_scope, container_type)
						var allowtypen = vx_core.V_code_type_typename(type_scope, container_type)
						header2 = "" +
							lineindent + "  let type_type : Vx_Core.Type_type = " + vxcore + "v_type_from_any(copyval.type_any)" +
							lineindent + "  let orig_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_any(" +
							lineindent + "    copyval.type_any" +
							lineindent + "  )" +
							lineindent + "  let merged_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_type_anymap_anylist(" +
							lineindent + "    type_type," +
							lineindent + "    orig_anymap," +
							lineindent + "    anylist" +
							lineindent + "  )" +
							lineindent + "  let msgblock : Vx_Core.Type_msgblock = Vx_Core.v_msgblock_from_any(" +
							lineindent + "    merged_anymap.type_any" +
							lineindent + "  )"
						footer2 = "" +
							lineindent + "  if ischanged === Vx_Core.c_false {" +
							lineindent + "    ischanged = Vx_Core.v_boolean_issame_from_anymap_anymap(" +
							lineindent + "      orig_anymap," +
							lineindent + "      merged_anymap" +
							lineindent + "    )" +
							lineindent + "  }" +
							lineindent + "  if ischanged === Vx_Core.c_true {" +
							lineindent + "    let type_delta : Vx_Core.Type_delta = Vx_Core.v_delta_from_any(" +
							lineindent + "      merged_anymap.type_any" +
							lineindent + "    )" +
							lineindent + "    let listkeyn : [String] = " + vxcore + "v_listkeyn_from_map(" +
							lineindent + "      merged_anymap.type_map" +
							lineindent + "    )" +
							lineindent + "    let mapany : [String:" + vx_core.V_code_type_typename(type_scope, vx_core.T_any) + "] = " + vxcore + "v_mapany_from_anymap(" +
							lineindent + "      merged_anymap" +
							lineindent + "    )" +
							lineindent + "    let map" + allownamen + " : [String:" + allowtypen + "] = vx_core.V_" + typename + "_map" + allownamen + "_from_mapany(" +
							lineindent + "      mapany" +
							lineindent + "    )" +
							lineindent + "    Vx_Core.v_reserve_mapany(mapany)" +
							lineindent + "    Vx_Core.v_reserve_msgblock(msgblock)" +
							lineindent + "    Vx_Core.v_reserve_delta(type_delta)" +
							lineindent + "    output = vx_core.V_" + typename + "_create()" +
							lineindent + "    output.map" + allownamen + " = map" + allownamen +
							lineindent + "    output.type_map.listkeyn = listkeyn" +
							lineindent + "    output.type_any.type_msgblock = msgblock" +
							lineindent + "    output.type_any.type_delta = type_delta" +
							lineindent + "  }" +
							lineindent + "  Vx_Core.v_release_except_listany(" +
							lineindent + "    output.type_any," +
							lineindent + "    [" +
							lineindent + "      copyval.type_any," +
							lineindent + "      anylist.type_any," +
							lineindent + "      merged_anymap.type_any" +
							lineindent + "    ]" +
							lineindent + "  )"
					case vx_core.C_extends_struct:
						var propertylist *vx_core.Type_varlist = type_type.P_propertylist
						var listproperty []*vx_core.Type_var = propertylist.P_listvar
						var listletpropn []string
						var listsetpropn []string
						for _, property := range listproperty {
							var propname string = vx_core.V_code_name(type_scope, property.P_name)
							var var_type = property.P_type
							var ppropname = "p_" + propname
							var letpropn = ""
							switch var_type.P_path {
							case "vx/core/any":
								letpropn = "" +
									lineindent + "    var " + ppropname + " : Vx_Core.Type_any = Vx_Core.v_any_from_anymap_keyn(" +
									lineindent + "      merged_anymap," +
									lineindent + "      \"" + vx_core.V_stringn_from_string(property.P_name) + "\"" +
									lineindent + "    )"
							default:
								letpropn = "" +
									lineindent + "    let " + ppropname + "_any : Vx_Core.Type_any = Vx_Core.v_any_from_anymap_keyn(" +
									lineindent + "      merged_anymap," +
									lineindent + "      \"" + vx_core.V_stringn_from_string(property.P_name) + "\"" +
									lineindent + "    )" +
									lineindent + "    var " + ppropname + " : " + vx_core.V_code_type_typename(type_scope, var_type) + " = " + vx_core.V_code_type_pkgname(type_scope, var_type) + "v_" + vx_core.V_code_type_name(type_scope, var_type) + "_from_any(" +
									lineindent + "      " + ppropname + "_any" +
									lineindent + "    )"
							}
							listletpropn = append(listletpropn, letpropn)
							var setpropn = "" +
								lineindent + "    if " + ppropname + " !== copyval." + ppropname + " {" +
								lineindent + "      Vx_Core.v_reserve_any(" + ppropname + ".type_any)" +
								lineindent + "      output." + ppropname + " = " + ppropname +
								lineindent + "    }"
							listsetpropn = append(listsetpropn, setpropn)
						}
						var letpropsn string = vx_core.V_stringn_from_liststringn_joinn(listletpropn, "")
						var setpropsn string = vx_core.V_stringn_from_liststringn_joinn(listsetpropn, "")
						var setdefaultn = "" +
							lineindent + "    Vx_Core.v_reserve_msgblock(msgblock)" +
							lineindent + "    Vx_Core.v_reserve_delta(type_delta)" +
							lineindent + "    output.type_any.type_msgblock = msgblock" +
							lineindent + "    output.type_any.type_delta = type_delta"
						header2 += "" +
							lineindent + "  let type_type : Vx_Core.Type_type = " + vxcore + "v_type_from_any(copyval.type_any)" +
							lineindent + "  let orig_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_any(" +
							lineindent + "    copyval.type_any" +
							lineindent + "  )" +
							lineindent + "  let merged_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_type_anymap_anylist(" +
							lineindent + "    type_type," +
							lineindent + "    orig_anymap," +
							lineindent + "    anylist" +
							lineindent + "  )" +
							lineindent + "  let msgblock : Vx_Core.Type_msgblock = Vx_Core.v_msgblock_from_any(" +
							lineindent + "    merged_anymap.type_any" +
							lineindent + "  )"
						switch type_type.P_path {
						case "vx/core/msg":
							header2 = "" +
								lineindent + "  let orig_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_any(" +
								lineindent + "    copyval.type_any" +
								lineindent + "  )" +
								lineindent + "  let type_type : Vx_Core.Type_type = " + vxcore + "v_type_from_any(copyval.type_any)" +
								lineindent + "  let merged_anymap : Vx_Core.Type_anymap = Vx_Core.v_anymap_from_type_anymap_anylist(" +
								lineindent + "    type_type," +
								lineindent + "    orig_anymap," +
								lineindent + "    anylist" +
								lineindent + "  )"
							setdefaultn = ""
							footer1 = "" +
								lineindent + "  var ischanged : Vx_Core.Type_boolean = Vx_Core.c_false"
						case "vx/core/msgblock":
							footer1 = "" +
								lineindent + "  var ischanged : Vx_Core.Type_boolean = Vx_Core.c_false" +
								lineindent + "  if msgblock !== Vx_Core.e_msgblock {" +
								lineindent + "    ischanged = Vx_Core.c_true" +
								lineindent + "  }"
							letpropsn += "" +
								lineindent + "    if msgblock !== Vx_Core.e_msgblock {" +
								lineindent + "      let msgblocks : Vx_Core.Type_msgblocklist = Vx_Core.f_msgblocklist(" +
								lineindent + "        Vx_Core.f_anylist(" +
								lineindent + "          p_msgblocks_any," +
								lineindent + "          msgblock.type_any" +
								lineindent + "        )" +
								lineindent + "      )" +
								lineindent + "      p_msgs = msgblock.p_msgs" +
								lineindent + "      p_msgblocks = msgblocks" +
								lineindent + "    }"
							setdefaultn = "" +
								lineindent + "    Vx_Core.v_reserve_delta(type_delta)" +
								lineindent + "    output.type_any.type_delta = type_delta"
						}
						footer2 = "" +
							lineindent + "  if ischanged === Vx_Core.c_false {" +
							lineindent + "    ischanged = Vx_Core.v_boolean_issame_from_anymap_anymap(" +
							lineindent + "      orig_anymap," +
							lineindent + "      merged_anymap" +
							lineindent + "    )" +
							lineindent + "  }" +
							lineindent + "  if ischanged === Vx_Core.c_true {" +
							lineindent + "    let type_delta : Vx_Core.Type_delta = Vx_Core.v_delta_from_any(" +
							lineindent + "      merged_anymap.type_any" +
							lineindent + "    )" +
							letpropsn +
							lineindent + "    output = vx_core.V_" + typename + "_create()" +
							setpropsn +
							setdefaultn +
							lineindent + "  }" +
							lineindent + "  Vx_Core.v_release_except_listany(" +
							lineindent + "    output.type_any," +
							lineindent + "    [" +
							lineindent + "      copyval.type_any," +
							lineindent + "      anylist.type_any," +
							lineindent + "      merged_anymap.type_any" +
							lineindent + "    ]" +
							lineindent + "  )"
					}
				}
			}
			body := "" +
				header1 +
				header2 +
				loopopen +
				loopcustom +
				loopclose +
				footer1 +
				footer2 +
				footer3
			returntype := vx_core.V_code_type_typename(type_scope, type_return)
			switch type_lang {
			case vx_core.C_lang_swift:
				output = "" +
					lineindent + "// V_" + typename + "_copy" +
					lineindent + "public static func V_" + typename + "_copy(" +
					props +
					lineindent + ") -> " + returntype + " {" +
					body +
					lineindent + "}"
			}
		}
	}
	return output
}

func code_type_props(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var listoutput []string
	var lineindent = vx_core.V_code_lineindent(type_scope, 2)
	var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
	switch type_type.P_path {
	case "vx/core/any":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_type : Type_type?" +
				lineindent + "var type_const : Type_const?" +
				lineindent + "var type_msgblock : Type_msgblock?" +
				lineindent + "var type_delta : Type_delta?" +
				lineindent + "var backref : AnyObject? = nil" +
				lineindent + "var refcount : Int = 0" +
				lineindent + "public init() {}"
			listoutput = append(listoutput, props)
		}
	case "vx/core/async":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : Type_any = e_any" +
				lineindent + "var resolved : Bool = false" +
				lineindent + "var result : Type_any = e_any" +
				lineindent + "var listasync : [Type_async] = []"
			listoutput = append(listoutput, props)
		}
	case "vx/core/boolean":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var booleann : Bool = false"
			listoutput = append(listoutput, props)
		}
	case "vx/core/const":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var name : String = \"\"" +
				lineindent + "var isempty : Bool = false" +
				lineindent + "var istype : Bool = false"
			listoutput = append(listoutput, props)
		}
	case "vx/core/list":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any"
			listoutput = append(listoutput, props)
		}
	case "vx/core/map":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var listkeyn : [String] = []"
			listoutput = append(listoutput, props)
		}
	case "vx/core/string":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var stringn : String = \"\""
			listoutput = append(listoutput, props)
		}
	case "vx/core/struct":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var listkeyn : [String] = []"
			listoutput = append(listoutput, props)
		}
	case "vx/core/type":
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any" +
				lineindent + "var type_generic : Type_generic?" +
				lineindent + "var p_name : Type_string = e_string" +
				lineindent + "var p_extends : Type_string = e_string"
			listoutput = append(listoutput, props)
		}
	default:
		var props = ""
		switch type_lang {
		case vx_core.C_lang_swift:
			props = "" +
				lineindent + "var type_any : " + vxcore + "Type_any = " + vxcore + "e_any"
			listoutput = append(listoutput, props)
		}
		switch type_type.P_extends {
		case vx_core.C_extends_list:
			var list_type *vx_core.Type_type = type_type.P_container_type
			props = "" +
				lineindent + "var type_list : " + vx_core.V_code_type_typename(type_scope, vx_core.T_list) + " = " + vx_core.V_code_e(type_scope, vx_core.T_list) +
				lineindent + "var list" + vx_core.V_code_type_name(type_scope, list_type) + " : [" + vx_core.V_code_t(type_scope, list_type) + "] = []"
			listoutput = append(listoutput, props)
		case vx_core.C_extends_map:
			var map_type *vx_core.Type_type = type_type.P_container_type
			props = "" +
				lineindent + "var type_map : " + vx_core.V_code_type_typename(type_scope, vx_core.T_map) + " = " + vx_core.V_code_e(type_scope, vx_core.T_map) +
				lineindent + "var map" + vx_core.V_code_type_name(type_scope, map_type) + " : [String:" + vx_core.V_code_type_typename(type_scope, map_type) + "] = [:]"
			listoutput = append(listoutput, props)
		case vx_core.C_extends_struct:
			props = "" +
				lineindent + "var type_struct : " + vx_core.V_code_type_typename(type_scope, vx_core.T_struct) + " = " + vx_core.V_code_e(type_scope, vx_core.T_struct)
			listoutput = append(listoutput, props)
			for _, prop := range type_type.P_propertylist.P_listvar {
				/*
					if prop.P_name == "constmap" {
						if type_type.P_name == "package" {
							prop.vxtype = anymaptype
						}
					}
				*/
				props = "" +
					lineindent + "var p_" + vx_core.V_code_name(type_scope, prop.P_name) + " : " + vx_core.V_code_type_typename(type_scope, prop.P_type) + " = " + vx_core.V_code_e(type_scope, prop.P_type)
				listoutput = append(listoutput, props)
			}
		default:
			var allowtypes *vx_core.Type_typelist = type_type.P_allowtypes
			var listallowtype []*vx_core.Type_type = allowtypes.P_listtype
			for _, allow_type := range listallowtype {
				props = "" +
					lineindent + "var type_" + vx_core.V_code_type_name(type_scope, allow_type) + " : " + vx_core.V_code_type_typename(type_scope, allow_type) + " = " + vx_core.V_code_e(type_scope, allow_type)
				listoutput = append(listoutput, props)
			}
		}
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(
		listoutput,
		"")
	return output
}

func code_type_t(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = vx_core.V_code_t(
		type_scope,
		type_type)
	return output
}

func code_type_t_const(
	type_scope *vx_core.Type_scope,
	type_type *vx_core.Type_type) string {
	var output = ""
	var type_lang *vx_core.Type_lang = type_scope.P_lang
	var lineindent = vx_core.V_code_lineindent(type_scope, 1)
	var typename = vx_core.V_code_type_name(type_scope, type_type)
	var vxcore = vx_core.V_code_type_pkgname(type_scope, vx_core.T_any)
	switch type_lang {
	case vx_core.C_lang_swift:
		output = lineindent + "public static let t_" + typename + " : " + vx_core.V_code_type_typename(type_scope, vx_core.T_type) + " = " + vxcore + "v_type_constructor()"
	}
	return output
}

func lang_type_t_from_listtype(
	type_lang *vx_core.Type_scope,
	listtype []*vx_core.Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		listoutput = append(listoutput, code_type_t_const(type_lang, type_type))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func lang_types_from_listtype(
	lang *vx_core.Type_scope,
	listtype []*vx_core.Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		listoutput = append(listoutput, code_type_class(lang, type_type))
	}
	var output = vx_core.V_stringn_from_liststringn_joinn(listoutput, "")
	return output
}

func V_type_name(
	type_type *vxtype) string {
	return NameFromType(type_type)
}

func const_from_vxconst(
	type_vxconst *vxconst) *vx_core.Type_const {
	var output *vx_core.Type_const = vx_core.V_const_create()
	var name string = type_vxconst.name
	var pkgname string = type_vxconst.pkgname
	var path string = name
	if pkgname != "" {
		path = pkgname + "/" + name
	}
	output.P_name = path
	return output
}

func type_from_vxtype(
	type_vxtype *vxtype) *vx_core.Type_type {
	var output *vx_core.Type_type = vx_core.V_type_create()
	var name string = type_vxtype.name
	var pkgname string = type_vxtype.pkgname
	var path string = name
	if pkgname != "" {
		path = pkgname + "/" + name
	}
	var extends *vx_core.Type_string = vx_core.E_string
	switch type_vxtype.extends {
	case ":func":
		extends = vx_core.C_extends_func
	case ":list":
		extends = vx_core.C_extends_list
	case ":map":
		extends = vx_core.C_extends_map
	case ":struct":
		extends = vx_core.C_extends_struct
	}
	output.P_name = name
	output.P_pkgname = pkgname
	output.P_alias = type_vxtype.alias
	output.P_extends = extends
	output.P_path = path
	return output
}

func listconst_from_listvxconst(
	listvxconst []*vxconst) []*vx_core.Type_const {
	var output []*vx_core.Type_const
	for _, vxconst := range listvxconst {
		var type_const *vx_core.Type_const = const_from_vxconst(
			vxconst)
		output = append(output, type_const)
	}
	return output
}

func listtype_from_listvxtype(
	listvxtype []*vxtype) []*vx_core.Type_type {
	var output []*vx_core.Type_type
	for _, vxtype := range listvxtype {
		var type_type *vx_core.Type_type = type_from_vxtype(
			vxtype)
		output = append(output, type_type)
	}
	return output
}
