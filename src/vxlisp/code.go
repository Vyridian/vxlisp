package vxlisp

import (
	vx_core "vxlisp/vxlisp/vx/core"
)

func const_from_vxconst(
	vxconst *vxconst) *vx_core.Type_const {
	var output *vx_core.Type_const = vx_core.V_const_create()
	var pkgname string = vxconst.pkgname
	var name string = vxconst.name
	var alias string = vxconst.alias
	if alias == "" {
		alias = name
	}
	var path string = name
	if pkgname != "" {
		path = pkgname + "/" + name
	}
	output.P_path = path
	output.P_pkgname = pkgname
	output.P_name = name
	output.P_alias = alias
	return output
}

/*
func const_link_from_project_vxproject(
	type_const *vx_core.Type_const,
	type_project *vx_core.Type_project,
	vxproject *vxproject) {
}
*/

func lang_from_vxpackage(
	vxlang *vxlang,
	vxpackage *vxpackage,
	vxproject *vxproject,
	pkgprefix string) (string, *vxmsgblock) {
	var output string = ""
	var path string = "lang<-package"
	var indent int = 0
	var type_scope *vx_core.Type_scope = scope_from_vxlang(
		vxlang)
	msgblock := NewMsgBlock("lang<-package")
	pkgpath, pkgname := LangPackagePathFromPrefixName(
		vxlang, pkgprefix, vxpackage.name)
	specialcode := vxproject.mapnative[vxpackage.name+"_"+vxlang.name+".txt"]
	if specialcode != "" {
		specialcode += "\n"
	}
	switch vxpackage.name {
	case "vx/core":
	default:
		specialcode = ""
	}
	var pkgnamen string = vxpackage.name
	packageline := LangNativePackageLine(
		vxlang, pkgnamen, pkgpath)
	namespaceopen, namespaceclose := LangNamespaceOpenClose(
		vxlang, pkgname, pkgpath)
	var type_project *vx_core.Type_project = vxproject.P_project
	var type_package *vx_core.Type_package = vx_core.V_package_from_project_pkgnamen(
		type_project,
		pkgnamen)
	type_scope.P_package = type_package
	var packageall string = vx_core.V_code_all_from_package(
		type_scope,
		indent,
		path,
		type_package)
	body := "" +
		specialcode +
		packageall
		//		emptytypes
	imports := LangPackageImports(
		vxlang, vxpackage, pkgprefix, body, false)
	output = "" +
		packageline +
		imports +
		namespaceopen +
		body +
		namespaceclose
	return output, msgblock
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

func listpackage_from_listvxpackage(
	listvxpackage []*vxpackage) []*vx_core.Type_package {
	var output []*vx_core.Type_package
	for _, vxpackage := range listvxpackage {
		var type_package *vx_core.Type_package = package_from_vxpackage(
			vxpackage)
		output = append(output, type_package)
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

func package_from_vxpackage(
	vxpackage *vxpackage) *vx_core.Type_package {
	var output *vx_core.Type_package = vx_core.V_package_create()
	var listvxconst []*vxconst = vxpackage.listconst
	var listconst []*vx_core.Type_const = listconst_from_listvxconst(
		listvxconst)
	var listtype []*vxtype = vxpackage.listtype
	var listfunc []*vxfunc = vxpackage.listfunc
	var listtypefunc []*vxtype = ListTypeFromListFunc(
		listfunc)
	var listvxtype []*vxtype = append(listtype, listtypefunc...)
	var listalltype []*vx_core.Type_type = listtype_from_listvxtype(
		listvxtype)
	output.P_path = vxpackage.name
	output.P_typemap = vx_core.V_typemap_from_listtype(
		listalltype)
	output.P_constmap = vx_core.V_constmap_from_listconst(
		listconst)
	return output
}

/*
func package_link_from_project_vxproject(
	type_package *vx_core.Type_package,
	type_project *vx_core.Type_project,
	vxproject *vxproject) {
	//var type_typemap *vx_core.Type_typemap = type_package.P_typemap
	println("!!!!")
	var type_constmap *vx_core.Type_constmap = type_package.P_constmap
	var pkgnamen string = type_package.P_path
	var mapvxpackage map[string]*vxpackage = vxpackagemap_from_vxproject(
		vxproject)
	var vxpackage *vxpackage = mapvxpackage[pkgnamen]
	var mapvxconst map[string]*vxconst = vxpackage.mapconst
	var listkey []string = type_constmap.P_listkey
	for _, keyn := range listkey {
		println("!!!key-" + keyn)
		var type_const *vx_core.Type_const = vx_core.V_const_from_constmap_keyn(
			type_constmap,
			keyn)
		var vxconst *vxconst = mapvxconst[keyn]
		var lookup_vxtype *vxtype = vxconst.vxtype
		var lookuppkgnamen string = lookup_vxtype.pkgname
		var lookupnamen string = lookup_vxtype.name
		println("!!!lookup_pkgnamen-" + lookuppkgnamen)
		println("!!!lookup_namen-" + lookupnamen)
		var lookup_type *vx_core.Type_type = vx_core.V_type_from_project_pkgnamen_typenamen(
			type_project,
			lookuppkgnamen,
			lookupnamen)
		println("!!!lookup_type-" + lookup_type.P_name)
		type_const.P_type = lookup_type
	}
}
*/

func project_from_vxproject(
	vxproject *vxproject) *vx_core.Type_project {
	var output *vx_core.Type_project = vxproject.P_project
	if output == nil {
		var output *vx_core.Type_project = vx_core.V_project_create()
		output.P_name = vxproject.name
		var listvxpackage []*vxpackage = vxproject.listpackage
		var listpackage []*vx_core.Type_package = listpackage_from_listvxpackage(
			listvxpackage)
		var type_packagemap *vx_core.Type_packagemap = vx_core.V_packagemap_from_listpackage(
			listpackage)
		output.P_packagemap = type_packagemap
		project_link_from_vxproject(
			output,
			vxproject)
		vxproject.P_project = output
	}
	return output
}

func project_link_from_vxproject(
	type_project *vx_core.Type_project,
	vxproject *vxproject) {
	var listvxpackage []*vxpackage = vxproject.listpackage
	for _, vxpackage := range listvxpackage {
		project_link_package(
			type_project,
			vxpackage)
	}
}

func project_link_package(
	type_project *vx_core.Type_project,
	vxpackage *vxpackage) {
	var type_package *vx_core.Type_package = vx_core.V_package_from_project_pkgnamen(
		type_project,
		vxpackage.name)
	project_linktype_package(
		type_project,
		type_package,
		vxpackage)
	project_linkconst_package(
		type_project,
		type_package,
		vxpackage)
}

func project_linkconst_package(
	type_project *vx_core.Type_project,
	type_package *vx_core.Type_package,
	vxpackage *vxpackage) {
	var type_constmap *vx_core.Type_constmap = type_package.P_constmap
	var listkey []string = type_constmap.P_listkey
	var mapvxconst map[string]*vxconst = vxpackage.mapconst
	for _, keyn := range listkey {
		var type_const *vx_core.Type_const = vx_core.V_const_from_constmap_keyn(
			type_constmap,
			keyn)
		var namen string = vx_core.V_stringn_from_stringn_afterlastn(
			keyn,
			"/")
		var vxconst *vxconst = mapvxconst[namen]
		var vxtype *vxtype = vxconst.vxtype
		var pkgnamen = vxtype.pkgname
		var typenamen = vxtype.name
		var type_type *vx_core.Type_type = vx_core.V_type_from_project_pkgnamen_typenamen(
			type_project,
			pkgnamen,
			typenamen)
		if type_type == vx_core.E_type {
			println("Lost Const Type")
			println(pkgnamen + "/" + typenamen)
		} else {
			type_const.P_type = type_type
		}
	}
}

func project_linktype_package(
	type_project *vx_core.Type_project,
	type_package *vx_core.Type_package,
	vxpackage *vxpackage) {
	var type_typemap *vx_core.Type_typemap = type_package.P_typemap
	var listkey []string = type_typemap.P_listkey
	var mapvxtype map[string]*vxtype = vxpackage.maptype
	for _, keyn := range listkey {
		var type_type *vx_core.Type_type = vx_core.V_type_from_typemap_keyn(
			type_typemap,
			keyn)
		var namen string = vx_core.V_stringn_from_stringn_afterlastn(
			keyn,
			"/")
		var vxtype, oktype = mapvxtype[namen]
		if oktype {
			var p_allowtypes = type_type.P_allowtypes
			var p_listallowtypes = p_allowtypes.P_listtype
			var vxallowtypes = vxtype.allowtypes
			if len(vxallowtypes) > 0 {
				for _, vxsubtype := range vxallowtypes {
					var lookuppkgnamen = vxsubtype.pkgname
					var lookuptypenamen = vxsubtype.name
					var lookup_type *vx_core.Type_type = vx_core.V_type_from_project_pkgnamen_typenamen(
						type_project,
						lookuppkgnamen,
						lookuptypenamen)
					if type_type == vx_core.E_type {
						println("Error:Missing (type :allowtype)")
						println(lookuppkgnamen + "/" + lookuptypenamen)
					} else {
						p_listallowtypes = append(p_listallowtypes, lookup_type)
					}
				}
			}
			var vxallowfuncs = vxtype.allowfuncs
			if len(vxallowfuncs) > 0 {
				for _, vxsubtype := range vxallowfuncs {
					var lookuppkgnamen string = vxsubtype.pkgname
					var lookuptypenamen string = vxsubtype.name
					var lookup_type *vx_core.Type_type = vx_core.V_type_from_project_pkgnamen_typenamen(
						type_project,
						lookuppkgnamen,
						lookuptypenamen)
					if type_type == vx_core.E_type {
						println("Error:Missing (type :allowfunc)")
						println(lookuppkgnamen + "/" + lookuptypenamen)
					} else {
						p_listallowtypes = append(p_listallowtypes, lookup_type)
					}
				}
			}
			if len(p_listallowtypes) == 1 {
				type_type.P_container = p_listallowtypes[0]
			} else {
				type_type.P_container = vx_core.T_any
			}
			var propertymap *vx_core.Type_varmap = type_type.P_propertymap
			var listvxarg []vxarg = vxtype.properties
			for _, vxarg := range listvxarg {
				var argnamen string = vxarg.name
				var vxsubtype = vxarg.vxtype
				var lookuppkgnamen string = vxsubtype.pkgname
				var lookuptypenamen string = vxsubtype.name
				var lookup_type *vx_core.Type_type = vx_core.V_type_from_project_pkgnamen_typenamen(
					type_project,
					lookuppkgnamen,
					lookuptypenamen)
				if type_type == vx_core.E_type {
					println("Error: Missing (property :type)")
					println(lookuppkgnamen + "/" + lookuptypenamen)
				} else {
					var property_var *vx_core.Type_var = vx_core.V_var_from_varmap_keyn(
						propertymap,
						argnamen)
					property_var.P_type = lookup_type
				}
			}
		} else {
			println("!!!(error :code typenotfound :name " + namen + " :func project_linktype_package)")
		}
	}
}

func scope_from_vxlang(
	lang *vxlang) *vx_core.Type_scope {
	var output *vx_core.Type_scope = vx_core.V_create_scope()
	switch lang {
	case langgo:
		output.P_lang = vx_core.C_lang_go
	case langswift:
		output.P_lang = vx_core.C_lang_swift
	}
	return output
}

func type_from_vxtype(
	type_vxtype *vxtype) *vx_core.Type_type {
	var output *vx_core.Type_type = vx_core.E_type
	switch NameFromType(type_vxtype) {
	case "vx/core/any":
		output = vx_core.T_any
	case "vx/core/boolean":
		output = vx_core.T_boolean
	case "vx/core/float":
		output = vx_core.T_float
	case "vx/core/int":
		output = vx_core.T_int
	case "vx/core/string":
		output = vx_core.T_string
	case "vx/core/type":
		output = vx_core.T_type
	default:
		output = vx_core.V_create_type()
		var suffix string = ""
		if type_vxtype.isfunc {
			var idx int = type_vxtype.vxfunc.idx
			if idx > 0 {
				suffix = "_" + vx_core.V_stringn_cast_intn(
					idx)
			}
		}
		var name string = type_vxtype.name + suffix
		var alias string = type_vxtype.alias + suffix
		if alias == "" {
			alias = name
		}
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
		output.P_alias = alias
		output.P_extends = extends
		output.P_path = path
		output.P_propertymap = varmap_from_listvxarg(
			type_vxtype.properties)
	}
	return output
}

/*
func type_link_from_project_vxproject(
	type_type *vx_core.Type_type,
	type_project *vx_core.Type_project,
	vxproject *vxproject) {
}
*/

func varmap_from_listvxarg(
	listvxarg []vxarg) *vx_core.Type_varmap {
	var output *vx_core.Type_varmap = vx_core.E_varmap
	if len(listvxarg) > 0 {
		var listvar []*vx_core.Type_var = []*vx_core.Type_var{}
		for _, type_vxarg := range listvxarg {
			var type_var = vx_core.V_create_var()
			type_var.P_name = vx_core.V_string_cast_stringn(
				type_vxarg.name)
			listvar = append(listvar, type_var)
		}
		output = vx_core.V_varmap_from_listvar(
			listvar)
	}
	return output
}

func vxpackagemap_from_vxproject(
	vxproject *vxproject) map[string]*vxpackage {
	var listpackage []*vxpackage = vxproject.listpackage
	var output map[string]*vxpackage = MapPackageFromListPackage(
		listpackage)
	return output
}

/*
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
						var container_type *vx_core.Type_type = type_type.P_container
						var allownamen = vx_core.V_code_type_name(
							type_scope,
							container_type)
						var allowtypen = vx_core.V_code_type_typename(
							type_scope,
							container_type)
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
						var container_type *vx_core.Type_type = type_type.P_container
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
									lineindent + "      \"" + vx_core.V_stringn_cast_string(property.P_name) + "\"" +
									lineindent + "    )"
							default:
								letpropn = "" +
									lineindent + "    let " + ppropname + "_any : Vx_Core.Type_any = Vx_Core.v_any_from_anymap_keyn(" +
									lineindent + "      merged_anymap," +
									lineindent + "      \"" + vx_core.V_stringn_cast_string(property.P_name) + "\"" +
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
*/
