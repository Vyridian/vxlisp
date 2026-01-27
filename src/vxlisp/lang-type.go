package vxlisp

import "strings"

func LangType(lang *vxlang, typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangType")
	output := ""
	path := typ.pkgname + "/" + typ.name
	g_ifuncdepth = 0
	typename := LangFromName(typ.alias)
	typepath := NameFromType(typ)
	instancefuncs := ""
	createtext, msgs := LangFromValue(lang, 2,
		typ.createvalue, "", emptyfunc, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	switch NameFromType(typ) {
	case "vx/core/func":
		instancefuncs += "" +
			LangTypeVxFuncdef(lang, typ, false)
	}
	switch typ.extends {
	case ":list":
		allowtype := anytype
		allowname := "any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype = allowtypes[0]
			allowname = LangNameFromType(lang, allowtype)
		}
		if allowname == "any" {
			allowname = ""
		}
		instancefuncs += "" +
			LangVarProp(lang, 2, rawlisttype, allowtype,
				"vx_p_list",
				LangPkgNameDot(lang, "vx/core")+"immutablelist("+
					"\n      "+LangVarListNew(lang, allowtype, "")+
					"\n    )") +
			"\n" +
			LangTypeVxList(lang, typ, false) +
			LangTypeVxAllowList(lang, typ, false)
	case ":map":
		allowtype := anytype
		allowname := "any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype = allowtypes[0]
			allowname = LangNameFromType(lang, allowtype)
		}
		if allowname == "any" {
			allowname = ""
		}
		instancefuncs += "" +
			LangVarProp(lang, 2, rawmaptype, allowtype,
				"vx_p_map",
				LangPkgNameDot(lang, "vx/core")+
					"immutablemap("+
					LangVarMapNew(lang, allowtype, "")+
					")") +
			"\n" +
			LangNativeTypeVxMap(lang, allowtype) +
			LangTypeVxSet(lang, typ) +
			LangTypeVxAllowMap(lang, typ, false) +
			LangTypeVxNewMap(lang, typ, false)
	case ":struct":
		vx_any := ""
		valcopyend := ""
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
		default:
			validkeys := LangVarCollection(lang, 3, rawlisttype, rawstringtype,
				"validkeys", ":new")
			valnewswitch := ""
			for _, arg := range props {
				validkeys += LangVarListAdd(lang, 3,
					"validkeys", "\":"+arg.name+"\"")
				argname := LangFromName(arg.name)
				valcopyend += LangVarSet(lang, 4,
					"work.vx_p_"+argname,
					"vx_p_"+argname)
				vx_any += "" +
					LangIfElseIf(lang, 3,
						LangIfClause(lang, rawstringtype,
							"==",
							"skey",
							"\":"+arg.name+"\""),
						LangVarSet(lang, 4,
							"output", LangTypeThis(lang)+"."+argname+"()"))
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawbooleantype),
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+argname,
									LangPkgNameDot(lang,
										"vx/core")+
										"vx_new("+
										LangTypeT(lang, booleantype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/int":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawintegertype),
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+argname,
									LangPkgNameDot(lang,
										"vx/core")+
										"vx_new("+
										LangTypeT(lang, inttype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/float":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawfloattype),
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+argname,
									LangPkgNameDot(lang,
										"vx/core")+
										"vx_new("+
										LangTypeT(lang, floattype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/string":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawstringtype),
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+argname,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new("+
										LangTypeT(lang, stringtype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				}
				valnewswitcherr := ""
				switch NameFromType(typ) {
				case "vx/core/msg":
				default:
					valnewswitcherr = "" +
						LangIfElse(lang, 6,
							LangIfThen(lang, 7,
								"false", "")+
								LangIfElseType(lang, 7,
									anytype, emptytype, "valsub", "valinvalid", false,
									LangVarSet(lang, 8,
										"msgval", "valinvalid"))+
								LangIfElse(lang, 7,
									LangVarSet(lang, 8,
										"msgval",
										LangPkgNameDot(lang, "vx/core")+
											"vx_new_string("+LangVarToString(lang, "valsub")))+
								LangIfEnd(lang, 7)+
								LangVarCollection(lang, 7, rawmaptype, anytype,
									"mapany",
									LangVarMapNew(lang, anytype, ""))+
								LangVarMapSet(lang, 7,
									"mapany",
									"\"key\"",
									LangPkgNameDot(lang, "vx/core")+"vx_new_string(\""+arg.name+"\"))")+
								LangVarMapSet(lang, 7,
									"mapany", "\"value\"", "msgval")+
								LangVar(lang, 7, maptype,
									"msgmap",
									LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)")+
								LangVarSet(lang, 7,
									"msg",
									LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", msgmap)")+
								LangVarSet(lang, 7,
									"msgblock",
									LangPkgNameDot(lang, "vx/core")+
										"vx_copy(msgblock, "+
										LangVarArg1(lang, "msg")+
										")"))
				}
				valnewswitch += "" +
					LangIfElseIf(lang, 5,
						LangIfClause(lang, rawstringtype,
							"==", "key", "\":"+arg.name+"\""),
						LangIfThen(lang, 6,
							"valsub == vx_p_"+argname, "")+
							LangIfElseType(lang, 6,
								arg.vxtype, emptytype, "valsub", "val"+argname, false,
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+argname, "val"+argname)+
									argalt+
									valnewswitcherr)+
							LangIfEnd(lang, 6))
				instancefuncs += "" +
					LangVarProp(lang, 2, arg.vxtype, emptytype,
						"vx_p_"+argname, "null") +
					"\n" +
					LangVxArgFromArg(lang, LangNameFromType(lang, typ), arg)
			}
			defaultkey := ""
			defaultstring := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := LangFromName(lastarg.name)
				lastargtype := lastarg.vxtype
				defaultkey += "" +
					LangIfElseIf(lang, 5,
						LangIsType(lang, "valsub", lastarg.vxtype),
						LangVarSet(lang, 6,
							"ischanged", "true")+
							LangVarSet(lang, 6,
								"vx_p_"+lastargname,
								LangVarAsType(lang, "valsub", lastargtype)))
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						LangIfElseIf(lang, 5,
							LangIsType(lang, "valsub", rawbooleantype),
							LangVarSet(lang, 6,
								"ischanged", "true")+
								LangVarSet(lang, 6,
									"vx_p_"+lastargname,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new("+
										LangTypeT(lang, booleantype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/int":
					defaultkey += "" +
						LangIfElseIf(lang, 5,
							LangIsType(lang, "valsub", rawintegertype),
							LangVarSet(lang, 6,
								"ischanged", "true")+
								LangVarSet(lang, 6,
									"vx_p_"+lastargname,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new("+
										LangTypeT(lang, inttype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/float":
					defaultkey += "" +
						LangIfElseIf(lang, 5,
							LangIsType(lang, "valsub", rawfloattype),
							LangVarSet(lang, 6,
								"ischanged", "true")+
								LangVarSet(lang, 6,
									"vx_p_"+lastargname,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new("+
										LangTypeT(lang, floattype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				case "vx/core/string":
					defaultstring += "" +
						LangIfElseType(lang, 6,
							stringtype, emptytype, "valsub", "valstr", false,
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+lastargname, "valstr")) +
						LangIfElseType(lang, 6,
							rawstringtype, emptytype, "valsub", "", false,
							LangVarSet(lang, 7,
								"ischanged", "true")+
								LangVarSet(lang, 7,
									"vx_p_"+lastargname,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new("+
										LangTypeT(lang, stringtype)+
										", "+
										LangVarArg1(lang, "valsub")+
										")"))
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", allowtype),
								LangVar(lang, 6, allowtype,
									"valdefault",
									LangVarAsType(lang, "valsub", allowtype))+
									LangVar(lang, 6, lastargtype,
										"vallist", "")+
									LangVarSet(lang, 6,
										"vallist", "vx_p_"+lastargname)+
									LangIfThen(lang, 6,
										"vallist == null",
										LangVarSet(lang, 7,
											"vallist",
											LangPkgNameDot(lang, "vx/core")+
												"vx_new("+
												LangTypeT(lang, lastarg.vxtype)+
												", "+
												LangVarArg1(lang, "valdefault")+
												")"))+
									LangIfElse(lang, 6,
										LangVarSet(lang, 7,
											"vallist",
											LangPkgNameDot(lang, "vx/core")+
												"vx_copy(vallist, "+
												LangVarArg1(lang, "valdefault")+
												")"))+
									LangIfEnd(lang, 6)+
									LangVarSet(lang, 6,
										"ischanged", "true")+
									LangVarSet(lang, 6,
										"vx_p_"+lastargname, "vallist"))
					}
				}
			}
		}
		prefix := LangNameFromType(lang, typ)
		argkey := NewArg("key")
		argkey.vxtype = stringtype
		listarg := NewListArg()
		listarg = append(listarg, argkey)
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.isimplement = true
		funcvxany.vxtype = anytype
		funcvxany.listarg = listarg
		skeyswitch := ""
		if len(vx_any) > 0 {
			skeyswitch = "" +
				LangVar(lang, 3, rawstringtype,
					"skey", "key.vx_string()") +
				LangIfThen(lang, 3,
					"false", "") +
				vx_any +
				LangIfEnd(lang, 3)
		}
		instancefuncs += "" +
			LangFuncHeader(lang, 2,
				prefix, funcvxany, 0,
				LangVar(lang, 3, anytype,
					"output",
					LangTypeE(lang, anytype))+
					skeyswitch) +
			LangTypeVxMapStruct(lang, typ, false)
	}
	e_type := ""
	switch NameFromType(typ) {
	case "vx/core/boolean":
	default:
		e_type = LangValStatic(lang, 1, typ,
			"e_"+typename, ":new")
	}
	t_type := LangValStatic(lang, 1, typ,
		"t_"+typename, ":new")
	doc := LangTypeDoc(lang, typ)
	output = "" +
		doc +
		LangTypeInterface(lang, typ) +
		LangTypeClassHeader(lang, 1, typ) +
		"\n" +
		instancefuncs +
		LangTypeVxNew(lang, typ, false) +
		LangTypeVxCopy(lang, typ, false) +
		LangTypeVxMsgblock(lang, typ, false) +
		LangTypeVxEmpty(lang, typ, false) +
		LangTypeVxType(lang, typ, false) +
		LangTypeVxTypedef(lang, typ, false) +
		"\n  }" +
		"\n" +
		e_type +
		t_type +
		"\n" +
		"\n"
	return output, msgblock
}

func LangTypeClass(lang *vxlang, typ *vxtype) string {
	name := "Class_" + LangNameFromType(lang, typ)
	return name
}

func LangTypeClassFull(lang *vxlang, typ *vxtype) string {
	name := LangTypeClass(lang, typ)
	if typ.pkgname != "" {
		name = LangPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangTypeDef(
	lang *vxlang,
	typ *vxtype,
	indent int) string {
	lineindent := LangIndent(lang, indent, true)
	allowtypes := LangTypeListFromListType(lang, typ.allowtypes)
	disallowtypes := LangTypeListFromListType(lang, typ.disallowtypes)
	allowfuncs := LangPkgNameDot(lang, "vx/core") + "e_funclist"
	disallowfuncs := LangPkgNameDot(lang, "vx/core") + "e_funclist"
	allowvalues := LangPkgNameDot(lang, "vx/core") + "e_anylist"
	disallowvalues := LangPkgNameDot(lang, "vx/core") + "e_anylist"
	properties := LangPkgNameDot(lang, "vx/core") + "e_argmap"
	traits := LangTypeListFromListType(lang, typ.traits)
	output := "" +
		LangPkgNameDot(lang, "vx/core") + "typedef_new(" +
		lineindent + "  \"" + typ.pkgname + "\", // pkgname" +
		lineindent + "  \"" + typ.name + "\", // name" +
		lineindent + "  \"" + typ.extends + "\", // extends" +
		lineindent + "  " + traits + ", // traits" +
		lineindent + "  " + allowtypes + ", // allowtypes" +
		lineindent + "  " + disallowtypes + ", // disallowtypes" +
		lineindent + "  " + allowfuncs + ", // allowfuncs" +
		lineindent + "  " + disallowfuncs + ", // disallowfuncs" +
		lineindent + "  " + allowvalues + ", // allowvalues" +
		lineindent + "  " + disallowvalues + ", // disallowvalues" +
		lineindent + "  " + properties + " // properties" +
		lineindent + ")"
	return output
}

func LangTypeE(lang *vxlang, typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = LangPkgName(lang, typ.pkgname) + lang.pkgref
		vxempty := LangNativeTypeVxEmpty(lang)
		output += vxempty
		output += "(generic_" + LangFromName(typ.name) + ")"
	} else {
		output = "e_" + LangNameFromType(lang, typ)
		if typ.pkgname != "" {
			output = LangPkgName(lang, typ.pkgname) + lang.pkgref + output
		}
	}
	return output
}

func LangTypeEmptyValue(lang *vxlang, typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = LangPkgNameDot(lang, "vx/core") + "f_type_to_list(" + LangPkgName(lang, typ.pkgname) + ".t_" + typ.name + ")"
		default:
			if len(typ.properties) > 0 {
				output = "{\n"
				for _, property := range typ.properties {
					propdefault := LangTypeEmptyValue(lang, property.vxtype, indent+"  ")
					output += indent + "    " + LangFromName(property.name) + ": " + propdefault + ","
					if property.doc != "" {
						output += " // " + property.doc
					}
					output += "\n"
				}
				output += "" +
					indent + "    vxtype: " + LangPkgName(lang, typ.pkgname) + ".t_" + LangFromName(typ.name) +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
			}
		}
	}
	return output
}

func LangTypeInterface(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	typename := LangNameTypeFullFromType(lang, typ)
	isbasics := LangTypeInterfaceBasics(lang, typ)
	basics := ""
	if isbasics {
		basics = "" +
			LangTypeVxNew(lang, typ, true) +
			LangTypeVxCopy(lang, typ, true) +
			LangTypeVxEmpty(lang, typ, true) +
			LangTypeVxType(lang, typ, true)
	}
	createtext, _ := LangFromValue(lang, 0,
		typ.createvalue, "", emptyfunc, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(
			createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if (createline == "@Override") || (createline == "// :implements") {
				isoverride = true
			} else if isoverride {
				ipos1 := 0
				if BooleanFromStringStarts(createline, "override ") {
					ipos1 += 9
				}
				ipos2 := IntFromStringFindLast(
					createline, "{")
				createline = createline[ipos1:ipos2-1] + lang.lineend
				basics += "\n    " + createline
				isoverride = false
			}
		}
	}
	switch NameFromType(typ) {
	case "vx/core/any":
		funcvxtypedef := NewFunc()
		funcvxtypedef.name = "vx_typedef"
		funcvxtypedef.vxtype = typedeftype
		funcvxconstdef := NewFunc()
		funcvxconstdef.name = "vx_constdef"
		funcvxconstdef.vxtype = constdeftype
		funcvxdispose := NewFunc()
		funcvxdispose.name = "vx_dispose"
		funcvxdispose.vxtype = rawlistanytype
		funcvxrelease := NewFunc()
		funcvxrelease.name = "vx_release"
		funcvxrelease.vxtype = rawbooltype
		funcvxreserve := NewFunc()
		funcvxreserve.name = "vx_reserve"
		funcvxreserve.vxtype = nonetype
		output = "" +
			LangTypeInterfaceHeader(lang, anytype, emptylisttype, 1,
				basics+
					LangFuncHeaderOld(lang, typename, funcvxtypedef, true, false)+
					LangFuncHeaderOld(lang, typename, funcvxconstdef, true, false)+
					LangFuncHeaderOld(lang, typename, funcvxdispose, true, false)+
					LangTypeVxMsgblock(lang, typ, true)+
					LangFuncHeaderOld(lang, typename, funcvxrelease, true, false)+
					LangFuncHeaderOld(lang, typename, funcvxreserve, true, false))
	case "vx/core/boolean":
		output = "" +
			LangTypeInterfaceHeader(lang, booleantype, []*vxtype{anytype}, 1, basics)
	case "vx/core/decimal":
		output = "" +
			LangTypeInterfaceHeader(lang, decimaltype, []*vxtype{numbertype}, 1, basics)
	case "vx/core/float":
		output = "" +
			LangTypeInterfaceHeader(lang, floattype, []*vxtype{numbertype}, 1, basics)
	case "vx/core/func":
		output = "" +
			LangTypeInterfaceHeader(lang, functype, []*vxtype{anytype}, 1,
				basics+
					LangTypeVxFuncdef(lang, typ, true))
	case "vx/core/int":
		output = "" +
			LangTypeInterfaceHeader(lang, inttype, []*vxtype{numbertype}, 1, basics)
	case "vx/core/string":
		output = "" +
			LangTypeInterfaceHeader(lang, stringtype, []*vxtype{anytype}, 1, basics)
	case "vx/core/list":
		funcvxlist := NewFunc()
		funcvxlist.name = "vx_list"
		funcvxlist.vxtype = rawlistanytype
		argindex := NewArg("index")
		argindex.vxtype = inttype
		arglist := NewListArg()
		arglist = append(arglist, argindex)
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.vxtype = anytype
		funcvxany.listarg = arglist
		output = "" +
			LangTypeInterfaceHeader(lang, listtype, []*vxtype{anytype}, 1,
				basics+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxlist)+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxany))
	case "vx/core/map":
		argindex := NewArg("key")
		argindex.vxtype = stringtype
		arglist := NewListArg()
		arglist = append(arglist, argindex)
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.vxtype = anytype
		funcvxany.listarg = arglist
		funcvxmap := NewFunc()
		funcvxmap.name = "vx_map"
		funcvxmap.vxtype = rawmapanytype
		argmapval := NewArg("mapval")
		argmapval.vxtype = rawmapanytype
		arglist = NewListArg()
		arglist = append(arglist, argmapval)
		funcvxnewfrommap := NewFunc()
		funcvxnewfrommap.name = "vx_new_from_map"
		funcvxnewfrommap.vxtype = maptype
		funcvxnewfrommap.listarg = arglist
		argname := NewArg("name")
		argname.vxtype = stringtype
		argvalue := NewArg("value")
		argvalue.vxtype = anytype
		arglist = NewListArg()
		arglist = append(arglist, argname)
		arglist = append(arglist, argvalue)
		funcvxset := NewFunc()
		funcvxset.name = "vx_set"
		funcvxset.vxtype = booleantype
		funcvxset.listarg = arglist
		output = "" +
			LangTypeInterfaceHeader(lang, maptype, []*vxtype{anytype}, 1,
				basics+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxnewfrommap)+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxany)+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxmap)+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxset))
	case "vx/core/struct":
		argindex := NewArg("key")
		argindex.vxtype = stringtype
		arglist := NewListArg()
		arglist = append(arglist, argindex)
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.vxtype = anytype
		funcvxany.listarg = arglist
		funcvxmap := NewFunc()
		funcvxmap.name = "vx_map"
		funcvxmap.vxtype = rawmapanytype
		output = "" +
			LangTypeInterfaceHeader(lang, structtype, []*vxtype{anytype}, 1,
				basics+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxany)+
					LangFuncHeaderInterface(lang, 2,
						typename, funcvxmap))
	default:
		extras := ""
		var extends []*vxtype
		switch typ.extends {
		case "boolean":
			extends = append(extends, booleantype)
		case "decimal":
			extends = append(extends, decimaltype)
		case "float":
			extends = append(extends, floattype)
		case "int":
			extends = append(extends, inttype)
		case "string":
			extends = append(extends, stringtype)
		case ":list":
			extends = append(extends, listtype)
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowname := LangNameFromType(lang, allowtype)
				if allowname != "any" {
					argindex := NewArg("index")
					argindex.vxtype = inttype
					arglist := NewListArg()
					arglist = append(arglist, argindex)
					funcvxallow := NewFunc()
					funcvxallow.name = LangFromName("vx_" + allowname)
					funcvxallow.vxtype = allowtype
					funcvxallow.listarg = arglist
					funcvxlistallow := NewFunc()
					funcvxlistallow.name = LangFromName("vx_list" + allowname)
					funcvxlistallow.vxtype = NewTypeSubtype(rawlisttype, allowtype)
					extras += "" +
						LangFuncHeaderInterface(lang, 2,
							typename, funcvxlistallow) +
						LangFuncHeaderInterface(lang, 2,
							typename, funcvxallow)
				}
			}
		case ":map":
			extends = append(extends, maptype)
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowname := LangNameFromType(lang, allowtype)
				if allowname != "any" {
					argkey := NewArg("key")
					argkey.vxtype = stringtype
					arglist := NewListArg()
					arglist = append(arglist, argkey)
					funcvxallow := NewFunc()
					funcvxallow.name = LangFromName("vx_" + allowname)
					funcvxallow.vxtype = allowtype
					funcvxallow.listarg = arglist
					funcvxmapallow := NewFunc()
					funcvxmapallow.name = LangFromName("vx_map" + allowname)
					funcvxmapallow.vxtype = NewTypeSubtype(rawmaptype, allowtype)
					extras += "" +
						LangFuncHeaderInterface(lang, 2,
							typename, funcvxmapallow) +
						LangFuncHeaderInterface(lang, 2,
							typename, funcvxallow)
				}
			}
		case ":struct":
			extends = append(extends, structtype)
			if len(typ.traits) > 0 {
				extends = append(extends, typ.traits...)
			}
			typeproperties := LangTypeProperties(
				lang, typ)
			for _, arg := range typeproperties {
				funcvxprop := NewFunc()
				funcvxprop.name = LangFromName(arg.alias)
				funcvxprop.vxtype = arg.vxtype
				extras += "" +
					LangFuncHeaderOld(
						lang, typename, funcvxprop, true, false)
			}
		default:
			extends = append(extends, anytype)
		}
		output = "" +
			LangTypeInterfaceHeader(lang, typ, extends, 1,
				basics+
					extras)
	}
	return output
}

func LangTypeIntValNew(
	lang *vxlang,
	val int) string {
	return LangPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(val) + ")"
}

func LangTypeListFromListType(
	lang *vxlang,
	listtype []*vxtype) string {
	output := LangPkgNameDot(lang, "vx/core") + "e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := LangTypeT(lang, typ)
			listtext = append(listtext, typetext)
		}
		output = "" +
			LangPkgNameDot(lang, "vx/core") +
			"vx_new(" +
			LangPkgNameDot(lang, "vx/core") +
			"t_typelist, " +
			StringFromListStringJoin(listtext, ", ") +
			")"
	}
	return output
}

func LangTypeName(
	lang *vxlang,
	typ *vxtype) string {
	return LangNameTypeFromTypeSimple(
		lang, typ, false)
}

func LangTypeStringValNew(
	lang *vxlang,
	val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + valstr + "\")"
}

func LangTypeT(
	lang *vxlang,
	typ *vxtype) string {
	return LangTypeTSimple(lang, typ, false)
}

func LangTypeTGeneric(
	lang *vxlang,
	typ *vxtype) string {
	name := ""
	if typ.isgeneric {
		name = "generic_" + LangFromName(typ.name)
	} else {
		name = LangTypeT(lang, typ)
	}
	return name
}

func LangTypeTSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := "t_" + LangTypeNameSimple(lang, typ, simple)
	if typ.pkgname != "" {
		name = LangPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangTypeVxAllowList(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	output := ""
	typename := LangNameFromType(lang, typ)
	allowname := "any"
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype := allowtypes[0]
		allowname = LangNameFromType(lang, allowtype)
		listarg := NewListArg()
		argindex := NewArg("index")
		argindex.vxtype = inttype
		listarg = append(listarg, argindex)
		funcvxallow := NewFunc()
		funcvxallow.name = "vx_" + allowname
		funcvxallow.vxtype = allowtype
		funcvxallow.listarg = listarg
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.vxtype = anytype
		funcvxany.listarg = listarg
		funcvxlistallow := NewFunc()
		funcvxlistallow.name = "vx_list" + allowname
		funcvxlistallow.vxtype = NewTypeSubtype(rawlisttype, allowtype)
		funcvxany.listarg = listarg
		if isinterface {
			output = LangFuncHeaderInterface(lang, 2,
				typename, funcvxallow)
			if allowname != "any" {
				output = LangFuncHeaderInterface(lang, 2,
					typename, funcvxany)
			}
		} else {
			funcvxallow.isimplement = true
			funcvxany.isimplement = true
			funcvxlistallow.isimplement = true
			output = "" +
				LangFuncHeader(lang, 2,
					typename, funcvxallow, 0,
					LangVar(lang, 3, allowtype,
						"output",
						LangTypeE(lang, allowtype))+
						LangVarClass(lang, 3, typ,
							"list",
							LangTypeThis(lang))+
						LangVar(lang, 3, rawinttype,
							"iindex",
							"index.vx_int()")+
						LangVarCollection(lang, 3, rawlisttype, allowtype,
							"listval",
							"list.vx_p_list")+
						LangIfThen(lang, 3,
							"iindex < "+LangVarListSize(lang, "listval"),
							LangVarSet(lang, 4,
								"output",
								LangVarListGet(lang, "listval", "iindex")))+
						LangIfEnd(lang, 3))
		}
		if allowname != "any" {
			output += "" +
				LangFuncHeader(lang, 2,
					typename, funcvxlistallow, 0,
					LangVarCollection(lang, 3, rawlisttype, allowtype,
						"output", LangTypeThis(lang)+".vx_p_list")) +
				LangFuncHeader(lang, 2,
					typename, funcvxany, 0,
					LangVar(lang, 3, allowtype,
						"output", LangTypeThis(lang)+".vx_"+allowname+"(index)"))
		}
	}
	return output
}

func LangTypeVxAllowMap(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	output := ""
	getorelse := ""
	typename := LangNameFromType(lang, typ)
	allowname := "any"
	allowtype := anytype
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowempty := LangTypeE(lang, allowtype)
		getorelse = LangTypeMapGetOrElse(
			lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
		argkey := NewArg("key")
		argkey.vxtype = stringtype
		listarg := NewListArg()
		listarg = append(listarg, argkey)
		funcvxallow := NewFunc()
		funcvxallow.name = "vx_" + allowname
		funcvxallow.vxtype = allowtype
		funcvxallow.listarg = listarg
		if isinterface {
			output += LangFuncInterface(lang, funcvxallow)
		} else {
			funcvxallow.isimplement = true
			output += "" +
				LangFuncHeader(lang, 2,
					typename, funcvxallow, 0,
					LangVar(lang, 3, allowtype,
						"output", allowempty)+
						LangVarClass(lang, 3, typ,
							"map", LangTypeThis(lang))+
						LangVar(lang, 3, rawstringtype,
							"skey", "key.vx_string()")+
						LangVarCollection(lang, 3, rawmaptype, allowtype,
							"mapval", "map.vx_p_map")+
						LangVarSet(lang, 3,
							"output", getorelse))
		}
	}
	if allowname == "any" {
	} else {
		argkey := NewArg("key")
		argkey.vxtype = stringtype
		listarg := NewListArg()
		listarg = append(listarg, argkey)
		funcvxany := NewFunc()
		funcvxany.name = "vx_any"
		funcvxany.vxtype = anytype
		funcvxany.listarg = listarg
		funcvxmapallow := NewFunc()
		funcvxmapallow.name = "vx_map" + allowname
		funcvxmapallow.vxtype = NewTypeSubtype(rawmaptype, allowtype)
		if isinterface {
			output += "" +
				LangFuncHeaderInterface(lang, 2,
					typename, funcvxany) +
				LangFuncHeaderInterface(lang, 2,
					typename, funcvxmapallow)
		} else {
			funcvxmapallow.isimplement = true
			funcvxany.isimplement = true
			output += "" +
				LangFuncHeader(lang, 2,
					typename, funcvxmapallow, 0,
					LangVarCollection(lang, 3, rawmaptype, allowtype,
						"output", LangTypeThis(lang)+".vx_p_map")) +
				LangFuncHeader(lang, 2,
					typename, funcvxany, 0,
					LangVar(lang, 3, anytype,
						"output", LangTypeThis(lang)+".vx_"+allowname+"(key)")) +
				"\n"
		}
	}
	return output
}

func LangTypeVxCopy(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	argvals := NewArg("vals")
	argvals.vxtype = rawobjecttype
	argvals.multi = true
	argvals.isfinal = true
	arglist := NewListArg()
	arglist = append(arglist, argvals)
	funcvxcopy := NewFunc()
	funcvxcopy.name = "vx_copy"
	funcvxcopy.vxtype = anytype
	funcvxcopy.listarg = arglist
	typename := LangNameFromType(lang, typ)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			typename, funcvxcopy)
	} else {
		typepath := NameFromType(typ)
		valnew := ""
		valcopy := "" +
			LangVar(lang, 3, rawbooltype,
				"ischanged", "false") +
			LangVarClass(lang, 3, typ,
				"value",
				LangTypeThis(lang)) +
			LangVar(lang, 3, msgblocktype,
				"msgblock",
				LangPkgNameDot(lang, "vx/core")+"vx_msgblock_from_copy_arrayval(value, vals)") +
			LangIfThen(lang, 3,
				LangClause(lang, false,
					"!=",
					LangTypeThis(lang)+".vx_constdef()",
					LangTypeE(lang, constdeftype)),
				LangVarSet(lang, 4,
					"ischanged", "true")) +
			LangIfEnd(lang, 3)
		switch NameFromType(typ) {
		case "vx/core/any":
			valnew += "" +
				LangForList(lang, 3,
					"valsub", rawobjecttype, "vals",
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))+
						LangIfElseIf(lang, 4,
							LangIsType(lang, "valsub", msgtype),
							LangVarSet(lang, 5,
								"msgblock",
								LangPkgNameDot(lang, "vx/core")+
									"vx_copy(msgblock, "+
									LangVarArg1(lang, "valsub")+
									")"))+
						LangIfEnd(lang, 4)) +
				LangIfThen(lang, 3,
					LangClause(lang, false,
						"||",
						"ischanged",
						LangClause(lang, true,
							"!=", "msgblock", LangTypeE(lang, msgblocktype))),
					LangVarClass(lang, 4, anytype,
						"work", ":new")+
						LangIfThen(lang, 4,
							LangClause(lang, false,
								"!=",
								"msgblock",
								LangTypeE(lang, msgblocktype)),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
		case "vx/core/anytype":
		case "vx/core/const":
		case "vx/core/list":
		case "vx/core/map":
		case "vx/core/struct":
		case "vx/core/func":
		case "vx/core/type":
		case "vx/core/boolean":
			valcopy += "" +
				LangVar(lang, 3, rawbooltype,
					"booleanval", "value.vx_boolean()")
			valnew = "" +
				LangForList(lang, 3,
					"valsub", rawobjecttype, "vals",
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))+
						LangIfElseIf(lang, 4,
							LangIsType(lang, "valsub", msgtype),
							LangVarSet(lang, 5,
								"msgblock",
								LangPkgNameDot(lang, "vx/core")+
									"vx_copy(msgblock, "+
									LangVarArg1(lang, "valsub")+
									")"))+
						LangIfElseType(lang, 4,
							booleantype, emptytype, "valsub", "valboolean", false,
							LangVarSet(lang, 5,
								"booleanval",
								"booleanval || valboolean.vx_boolean()"))+
						LangIfElseType(lang, 4,
							rawbooleantype, emptytype, "valsub", "issubval", false,
							LangVarSet(lang, 5,
								"booleanval",
								"booleanval || issubval"))+
						LangIfEnd(lang, 4)) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, booleantype,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vxboolean",
							"booleanval")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfElseIf(lang, 3,
					"booleanval",
					LangVarSet(lang, 4,
						"output",
						LangPkgNameDot(lang, "vx/core")+"c_true")) +
				LangIfElse(lang, 3,
					LangVarSet(lang, 4,
						"output",
						LangPkgNameDot(lang, "vx/core")+"c_false")) +
				LangIfEnd(lang, 3)
		case "vx/core/decimal":
			valcopy += "" +
				LangVar(lang, 3, rawstringtype,
					"sval", "value.vx_string()")
			valnew = "" +
				LangForListHeader(lang, 3,
					"valsub", rawobjecttype, "vals") +
				LangIfThen(lang, 4,
					LangIsType(lang, "valsub", msgblocktype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseIf(lang, 4,
					LangIsType(lang, "valsub", msgtype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseType(lang, 4,
					stringtype, emptytype, "valsub", "valstring", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarSet(lang, 5,
							"sval", "valstring.vx_string()")) +
				LangIfElseType(lang, 4,
					rawstringtype, emptytype, "valsub", "svalsub", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarSet(lang, 5,
							"sval", "svalsub")) +
				LangIfEnd(lang, 4) +
				LangIfEnd(lang, 3) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, decimaltype,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vxdecimal", "sval")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
		case "vx/core/float":
			valcopy += "" +
				LangVar(lang, 3, rawfloattype,
					"floatval", "value.vx_float()")
			valnew = "" +
				LangForListHeader(lang, 3,
					"valsub", rawobjecttype,
					"vals") +
				LangIfThen(lang, 4,
					LangIsType(lang, "valsub", msgblocktype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseIf(lang, 4,
					LangIsType(lang, "valsub", msgtype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseType(lang, 4,
					decimaltype, emptytype, "valsub", "valdecimal", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", "valdecimal.vx_float()")) +
				LangIfElseType(lang, 4,
					floattype, emptytype, "valsub", "valfloat", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", "valfloat.vx_float()")) +
				LangIfElseType(lang, 4,
					inttype, emptytype, "valsub", "valint", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", "valint.vx_int()")) +
				LangIfElseType(lang, 4,
					stringtype, emptytype, "valsub", "valstring", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", LangFloatFromString(lang, "valstring.vx_string()"))) +
				LangIfElseType(lang, 4,
					rawfloattype, emptytype, "valsub", "fval", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", "fval")) +
				LangIfElseType(lang, 4,
					rawintegertype, emptytype, "valsub", "ival", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", "ival")) +
				LangIfElseType(lang, 4,
					rawstringtype, emptytype, "valsub", "sval", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarFloatPlus(lang, 5,
							"floatval", LangFloatFromString(lang, "sval"))) +
				LangIfEnd(lang, 4) +
				LangIfEnd(lang, 3) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, floattype,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vxfloat", "floatval")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
		case "vx/core/int":
			valcopy += "" +
				LangVar(lang, 3, rawinttype,
					"intval", "value.vx_int()")
			valnew = "" +
				LangForList(lang, 3,
					"valsub", rawobjecttype, "vals",
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))+
						LangIfElseIf(lang, 4,
							LangIsType(lang, "valsub", msgtype),
							LangVarSet(lang, 5,
								"msgblock",
								LangPkgNameDot(lang, "vx/core")+
									"vx_copy(msgblock, "+
									LangVarArg1(lang, "valsub")+
									")"))+
						LangIfElseType(lang, 4,
							inttype, emptytype, "valsub", "valint", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarIntPlus(lang, 5,
									"intval", "valint.vx_int()"))+
						LangIfElseType(lang, 4,
							rawintegertype, emptytype, "valsub", "ival", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarIntPlus(lang, 5,
									"intval", "ival"))+
						LangIfElseType(lang, 4,
							rawstringtype, emptytype, "valsub", "sval", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarIntPlus(lang, 5,
									"intval", LangIntFromString(lang, "sval")))+
						LangIfEnd(lang, 4)) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, inttype,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vxint", "intval")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
		case "vx/core/msg":
		case "vx/core/msgblock":
		case "vx/core/string":
			vxstringbuilder := LangTypeStringbuilder(lang)
			valcopy += vxstringbuilder
			valnew = "" +
				LangVar(lang, 3, msgtype,
					"msg", "") +
				LangForList(lang, 3,
					"valsub", rawobjecttype, "vals",
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))+
						LangIfElseIf(lang, 4,
							LangIsType(lang, "valsub", msgtype),
							LangVarSet(lang, 5,
								"msgblock",
								LangPkgNameDot(lang, "vx/core")+
									"vx_copy(msgblock, "+
									LangVarArg1(lang, "valsub")+
									")"))+
						LangIfElseType(lang, 4,
							stringtype, emptytype, "valsub", "valstring", false,
							LangVar(lang, 5, rawstringtype,
								"ssub",
								"valstring.vx_string()")+
								LangIfThen(lang, 5,
									LangVxEqualsString(lang, "ssub", "\"\""),
									"")+
								LangIfElse(lang, 5,
									LangVarSet(lang, 6,
										"ischanged", "true")+
										LangVarStringBuilderPlus(lang, 6,
											"sb", "ssub"))+
								LangIfEnd(lang, 5))+
						LangIfElseType(lang, 4,
							inttype, emptytype, "valsub", "valint", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarStringBuilderPlus(lang, 5,
									"sb", "valint.vx_int()"))+
						LangIfElseType(lang, 4,
							floattype, emptytype, "valsub", "valfloat", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarStringBuilderPlus(lang, 5,
									"sb", "valfloat.vx_float()"))+
						LangIfElseType(lang, 4,
							decimaltype, emptytype, "valsub", "valdecimal", false,
							LangVarSet(lang, 5,
								"ischanged", "true")+
								LangVarStringBuilderPlus(lang, 5,
									"sb", "valdecimal.vx_string()"))+
						LangIfElseType(lang, 4,
							rawstringtype, emptytype, "valsub", "sval", false,
							LangIfThen(lang, 5,
								LangVxEqualsString(lang, "sval", "\"\""),
								"")+
								LangIfElse(lang, 5,
									LangVarSet(lang, 6,
										"ischanged", "true")+
										LangVarStringBuilderPlus(lang, 6,
											"sb", "sval"))+
								LangIfEnd(lang, 5))+
						LangIfElseType(lang, 4,
							rawintegertype, emptytype, "valsub", "ival", false,
							LangVarSet(lang, 5, "ischanged", "true")+
								LangVarStringBuilderPlus(lang, 5,
									"sb", "ival"))+
						LangIfElseType(lang, 4,
							rawfloattype, emptytype, "valsub", "fval", false,
							LangVarSet(lang, 5, "ischanged", "true")+
								LangVarStringBuilderPlus(lang, 5,
									"sb", "fval"))+
						LangIfElseType(lang, 4,
							anytype, emptytype, "valsub", "anysub", false,
							LangVarSet(lang, 5,
								"msg",
								LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidtype\", anysub)")+
								LangVarSet(lang, 5,
									"msgblock",
									LangPkgNameDot(lang, "vx/core")+
										"vx_copy(msgblock, "+
										LangVarArg1(lang, "msg")+
										")"))+
						LangIfElse(lang, 4,
							LangVarSet(lang, 5,
								"msg",
								LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidtype\", "+LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVarToString(lang, "valsub")+"))")+
								LangVarSet(lang, 5,
									"msgblock",
									LangPkgNameDot(lang, "vx/core")+
										"vx_copy(msgblock, "+
										LangVarArg1(lang, "msg")+
										")"))+
						LangIfEnd(lang, 4)) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVar(lang, 4, rawstringtype,
						"vxstring",
						LangVarToString(lang, "sb"))+
						LangVarClass(lang, 4, stringtype,
							"work", ":new")+
						LangVarSet(lang, 4,
							"work.vxstring", "vxstring")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
		}
		switch typ.extends {
		case ":list":
			allowtype := anytype
			allowname := "any"
			allowclass := LangTypeName(lang, anytype)
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype = allowtypes[0]
				allowclass = LangNameTypeFullFromType(lang, allowtype)
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname == "any" {
				allowname = ""
			}
			valcopy += "" +
				LangVarCollection(lang, 3, rawlisttype, allowtype,
					"listval",
					LangVarListNew(lang,
						allowtype, "value.vx_list"+allowname+"()"))
			switch NameFromType(typ) {
			case "vx/core/anylist":
				valnew = "" +
					LangVar(lang, 3, msgtype,
						"msg", "") +
					LangForListHeader(lang, 3,
						"valsub", rawobjecttype, "vals") +
					LangIfThen(lang, 4,
						"false", "")
			case "vx/core/msgblocklist":
				valnew = "" +
					LangVar(lang, 3, msgtype,
						"msg", "") +
					LangForListHeader(lang, 3,
						"valsub", rawobjecttype, "vals") +
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgtype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))
			case "vx/core/msglist":
				valnew = "" +
					LangVar(lang, 3, msgtype,
						"msg", "") +
					LangForListHeader(lang, 3,
						"valsub", rawobjecttype, "vals") +
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))
			default:
				valnew = "" +
					LangVar(lang, 3, msgtype,
						"msg", "") +
					LangForListHeader(lang, 3,
						"valsub", rawobjecttype, "vals") +
					LangIfThen(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")")) +
					LangIfElseIf(lang, 4,
						LangIsType(lang, "valsub", msgtype),
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "valsub")+
								")"))
			}
			valnew += "" +
				LangIfElseType(lang, 4,
					typ, emptytype, "valsub", "multi", false,
					LangVarSet(lang, 5,
						"ischanged", "true")+
						LangVarListAddList(lang, 5,
							"listval", "multi.vx_list"+allowname+"()"))
			switch NameFromType(typ) {
			case "vx/core/msgblocklist", "vx/core/msglist":
			default:
				valnew += "" +
					LangIfElseType(lang, 4,
						allowtype, emptytype, "valsub", "allowsub", false,
						LangVarSet(lang, 5,
							"ischanged", "true")+
							LangVarListAdd(lang, 5,
								"listval", "allowsub"))
			}
			for _, allowedtype := range typ.allowtypes {
				allowedtypename := LangTypeName(lang, allowedtype)
				castval := LangVarAsType(lang, "valsub", allowedtype)
				if allowedtypename == allowclass {
					switch NameFromType(allowedtype) {
					case "vx/core/boolean":
						allowedtypename = LangNativeTypeBoolean(lang)
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, booleantype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/int":
						allowedtypename = LangNativeTypeInt(lang)
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, inttype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/float":
						allowedtypename = LangNativeTypeFloat(lang)
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, floattype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/string":
						allowedtypename = LangNativeTypeString(lang)
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, stringtype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					}
				}
				switch NameFromType(allowedtype) {
				case "":
				case "vx/core/any":
				default:
					subname := "subitem"
					valnew += "" +
						LangIfElseIf(lang, 4,
							LangIsTypeText(lang, "valsub", allowedtypename),
							LangVar(lang, 5, allowedtype,
								subname, castval))
					switch NameFromType(typ) {
					case "vx/core/msglist", "vx/core/msgblocklist":
						valnew += "" +
							LangIfThen(lang, 5,
								"!"+LangVarListContains(lang, "listval", subname),
								LangVarSet(lang, 6,
									"ischanged", "true")+
									LangVarListAdd(lang, 6,
										"listval", subname)) +
							LangIfEnd(lang, 5)
					default:
						valnew += "" +
							LangVarSet(lang, 5,
								"ischanged", "true") +
							LangVarListAdd(lang, 5,
								"listval", subname)
					}
				}
			}
			elseiflistany := LangNativeTypeElseIfListAny(
				lang, allowtype)
			valnew += "" +
				elseiflistany +
				LangIfElseType(lang, 4,
					anytype, emptytype, "valsub", "anyinvalid", false,
					LangVarSet(lang, 5,
						"msg",
						LangPkgNameDot(lang, "vx/core")+
							"vx_msg_from_error(\""+
							typepath+
							"\", \":invalidtype\", anyinvalid)")+
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "msg")+
								")")) +
				LangIfElse(lang, 4,
					LangVarSet(lang, 5,
						"msg",
						LangPkgNameDot(lang, "vx/core")+
							"vx_msg_from_error(\""+
							typepath+
							"\", \":invalidtype\", "+
							LangPkgNameDot(lang, "vx/core")+
							"vx_new_string("+
							LangVarToString(lang, "valsub")+
							"))")+
						LangVarSet(lang, 5,
							"msgblock",
							LangPkgNameDot(lang, "vx/core")+
								"vx_copy(msgblock, "+
								LangVarArg1(lang, "msg")+
								")")) +
				LangIfEnd(lang, 4) +
				LangIfEnd(lang, 3) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, typ,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vx_p_list",
							LangPkgNameDot(lang, "vx/core")+"immutablelist(listval)")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
			if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
				MsgLog(
					"Missing allowed types", typ.name)
			}
		case ":map":
			allowtype := anytype
			allowname := "any"
			allowclass := LangTypeName(lang, anytype)
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype = allowtypes[0]
				allowclass = LangNameTypeFullFromType(lang, allowtype)
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname == "any" {
				allowname = ""
			}
			valcopy += "" +
				LangVarCollection(lang, 3, rawmaptype, allowtype,
					"mapval",
					LangVarMapNew(lang, allowtype, "value.vx_map"+allowname+"()"))
			valnew = "" +
				LangVar(lang, 3, rawstringtype,
					"key", "\"\"") +
				LangVar(lang, 3, msgtype,
					"msg", LangTypeE(lang, msgtype)) +
				LangVar(lang, 3, anytype,
					"msgval", LangTypeE(lang, anytype)) +
				LangForListHeader(lang, 3,
					"valsub", rawobjecttype, "vals") +
				LangIfThen(lang, 4,
					LangIsType(lang, "valsub", msgblocktype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseIf(lang, 4,
					LangIsType(lang, "valsub", msgtype),
					LangVarSet(lang, 5,
						"msgblock",
						LangPkgNameDot(lang, "vx/core")+
							"vx_copy(msgblock, "+
							LangVarArg1(lang, "valsub")+
							")")) +
				LangIfElseIf(lang, 4,
					LangVxEqualsString(lang, "key", "\"\""),
					LangIfThen(lang, 5,
						"false", "")+
						LangIfElseType(lang, 5,
							stringtype, emptytype, "valsub", "valstring", false,
							LangVarSet(lang, 6,
								"key", "valstring.vx_string()"))+
						LangIfElseType(lang, 5,
							rawstringtype, emptytype, "valsub", "sval", false,
							LangVarSet(lang, 6,
								"key", "sval"))+
						LangIfElse(lang, 5,
							LangIfThen(lang, 6,
								"false", "")+
								LangIfElseType(lang, 6,
									anytype, emptytype, "valsub", "valinvalid", false,
									LangVarSet(lang, 7,
										"msgval", "valinvalid"))+
								LangIfElse(lang, 6,
									LangVarSet(lang, 7,
										"msgval",
										LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVarToString(lang, "valsub")+")"))+
								LangIfEnd(lang, 6)+
								LangVarSet(lang, 6,
									"msg",
									LangPkgNameDot(lang, "vx/core")+
										"vx_msg_from_error(\""+
										typepath+
										"\", \":keyexpected\", msgval)")+
								LangVarSet(lang, 6,
									"msgblock",
									LangPkgNameDot(lang, "vx/core")+
										"vx_copy(msgblock, "+
										LangVarArg1(lang, "msg")+
										")")+
								LangIfEnd(lang, 5))) +
				LangIfElse(lang, 4,
					LangVar(lang, 5, allowtype,
						"valany", LangTypeE(lang, allowtype))+
						LangIfThen(lang, 5,
							"false", "")+
						LangIfElseType(lang, 5,
							allowtype, emptytype, "valsub", "valallowed", false,
							LangVarSet(lang, 6,
								"valany", "valallowed")))
			for _, allowedtype := range typ.allowtypes {
				allowedtypename := LangTypeName(lang, allowedtype)
				castval := LangVarAsType(lang, "valsub", allowedtype)
				if allowedtypename == allowclass {
					switch NameFromType(allowedtype) {
					case "vx/core/boolean":
						allowedtype = rawbooltype
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, booleantype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/int":
						allowedtype = rawintegertype
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, inttype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/float":
						allowedtype = rawfloattype
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, floattype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					case "vx/core/string":
						allowedtype = rawstringtype
						castval = LangPkgNameDot(lang, "vx/core") +
							"vx_new(" +
							LangTypeT(lang, stringtype) +
							", " +
							LangVarArg1(lang, "valsub") +
							")"
					}
				}
				if allowedtypename != "" {
					valnew += "" +
						//	LangElseIfType(lang, allowedtype, emptytype, "valsub", "valany", 5, false)
						LangIfElseIf(lang, 5,
							LangIsType(lang, "valsub", allowedtype),
							LangVarSet(lang, 6,
								"valany", castval))
				}
			}
			valnew += "" +
				"\n          } else {" +
				LangIfThen(lang, 6,
					"false", "") +
				LangIfElseType(lang, 6,
					anytype, emptytype, "valsub", "valinvalid", false,
					LangVarSet(lang, 7,
						"msgval", "valinvalid")) +
				LangIfElse(lang, 6,
					LangVarSet(lang, 7,
						"msgval", LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVarToString(lang, "valsub")+")")) +
				LangIfEnd(lang, 6) +
				LangVarCollection(lang, 6, rawmaptype, anytype,
					"mapany", LangVarMapNew(lang, anytype, "")) +
				LangVarMapSet(lang, 6,
					"mapany",
					"\"key\"",
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(key)") +
				LangVarMapSet(lang, 6,
					"mapany",
					"\"value\"",
					"msgval") +
				LangVar(lang, 6, maptype,
					"msgmap",
					LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)") +
				LangVarSet(lang, 6,
					"msg",
					LangPkgNameDot(lang, "vx/core")+
						"vx_msg_from_error(\""+
						typepath+"\", \":invalidkeyvalue\", msgmap)") +
				LangVarSet(lang, 6,
					"msgblock",
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy(msgblock, "+
						LangVarArg1(lang, "msg")+
						")") +
				LangIfEnd(lang, 5) +
				LangIfThen(lang, 5,
					"valany != "+LangTypeE(lang, anytype),
					LangVarSet(lang, 6,
						"ischanged", "true")+
						LangIfThen(lang, 6,
							LangVarStringStarts(lang, "key", "\":\""),
							LangVarSet(lang, 7,
								"key",
								LangVarSubstring(lang, "key", "1", "")))+
						LangIfEnd(lang, 6)+
						LangVarMapSet(lang, 6,
							"mapval", "key", "valany")+
						LangVarSet(lang, 6,
							"key", "\"\"")) +
				LangIfEnd(lang, 5) +
				LangIfEnd(lang, 4) +
				LangIfEnd(lang, 3) +
				LangIfThen(lang, 3,
					"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
					LangVarClass(lang, 4, typ,
						"work", ":new")+
						LangVarSet(lang, 4,
							"work.vx_p_map",
							LangPkgNameDot(lang, "vx/core")+"immutablemap(mapval)")+
						LangIfThen(lang, 4,
							"msgblock != "+LangTypeE(lang, msgblocktype),
							LangVarSet(lang, 5,
								"work.vxmsgblock", "msgblock"))+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							"output", "work")) +
				LangIfEnd(lang, 3)
			if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
				MsgLog(
					"Missing allowed types", typ.name)
			}
		case ":struct":
			vx_any := ""
			valcopyend := ""
			switch NameFromType(typ) {
			case "vx/core/msg":
				valcopy = "" +
					LangVar(lang, 3, rawbooltype,
						"ischanged", "false") +
					LangVarClass(lang, 3, typ,
						"value", LangTypeThis(lang)) +
					LangIfThen(lang, 3,
						LangTypeThis(lang)+".vx_constdef() != "+LangTypeE(lang, constdeftype),
						LangVarSet(lang, 4,
							"ischanged", "true")) +
					LangIfEnd(lang, 3)
			case "vx/core/msgblock":
				valcopy = "" +
					LangVar(lang, 3, rawbooltype,
						"ischanged", "false") +
					LangVarClass(lang, 3, msgblocktype,
						"value", LangTypeThis(lang)) +
					LangVar(lang, 3, msgblocktype,
						"msgblock", LangTypeThis(lang)) +
					LangIfThen(lang, 3,
						LangTypeThis(lang)+".vx_constdef() != "+LangTypeE(lang, constdeftype),
						LangVarSet(lang, 4,
							"ischanged", "true")) +
					LangIfEnd(lang, 3)
			}
			props := ListPropertyTraitFromType(typ)
			switch len(props) {
			case 0:
				valnew = "" +
					LangIfThen(lang, 3,
						"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
						LangVarClass(lang, 4, typ,
							"work", ":new")+
							LangIfThen(lang, 4,
								"msgblock != "+LangTypeE(lang, msgblocktype),
								LangVarSet(lang, 5,
									"work.vxmsgblock", "msgblock"))+
							LangIfEnd(lang, 4)+
							LangVarSet(lang, 4,
								"output", "work")) +
					LangIfEnd(lang, 3)
			default:
				validkeys := LangVarCollection(lang, 3, rawlisttype, rawstringtype,
					"validkeys", ":new")
				valnewswitch := ""
				for _, arg := range props {
					validkeys += LangVarListAdd(lang, 3,
						"validkeys", "\":"+arg.name+"\"")
					argname := LangFromName(arg.name)
					valcopy += "" +
						LangVar(lang, 3, arg.vxtype,
							"vx_p_"+argname,
							"value."+argname+"()")
					valcopyend += "" +
						LangVarSet(lang, 4,
							"work.vx_p_"+argname, "vx_p_"+argname)
					vx_any += "" +
						LangSwitchCase(lang, 3,
							"\":"+arg.name+"\"",
							LangVarSet(lang, 4,
								"output", LangTypeThis(lang)+"."+argname+"()"))
					argalt := ""
					switch NameFromType(arg.vxtype) {
					case "vx/core/boolean":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawbooleantype),
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+argname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangPkgNameDot(lang, "vx/core")+
											"t_boolean, "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/int":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawintegertype),
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+argname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangPkgNameDot(lang, "vx/core")+
											"t_int, "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/float":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawfloattype),
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+argname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangPkgNameDot(lang, "vx/core")+
											"t_float, "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/string":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawstringtype),
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+argname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangPkgNameDot(lang, "vx/core")+
											"t_string, "+
											LangVarArg1(lang, "valsub")+
											")"))
					}
					valnewswitcherr := ""
					switch NameFromType(typ) {
					case "vx/core/msg":
					default:
						valnewswitcherr = "" +
							LangIfElse(lang, 6,
								LangIfThen(lang, 7,
									"false", "")+
									LangIfElseType(lang, 7,
										anytype, emptytype, "valsub", "valinvalid", false,
										LangVarSet(lang, 8,
											"msgval", "valinvalid"))+
									LangIfElse(lang, 7,
										LangVarSet(lang, 8,
											"msgval",
											LangPkgNameDot(lang, "vx/core")+
												"vx_new_string("+LangVarToString(lang, "valsub")+")"))+
									LangIfEnd(lang, 7)+
									LangVarCollection(lang, 7, rawmaptype, anytype,
										"mapany",
										LangVarMapNew(lang, anytype, ""))+
									LangVarMapSet(lang, 7,
										"mapany",
										"\"key\"",
										LangPkgNameDot(lang, "vx/core")+"vx_new_string(\""+arg.name+"\")")+
									LangVarMapSet(lang, 7,
										"mapany", "\"value\"", "msgval")+
									LangVar(lang, 7, maptype,
										"msgmap",
										LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)")+
									LangVarSet(lang, 7,
										"msg",
										LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", msgmap)")+
									LangVarSet(lang, 7,
										"msgblock",
										LangPkgNameDot(lang, "vx/core")+
											"vx_copy(msgblock, "+
											LangVarArg1(lang, "msg")+
											")"))
					}
					valnewswitch += "" +
						LangIfElseIf(lang, 5,
							LangIfClause(lang, rawstringtype,
								"==", "key", "\":"+arg.name+"\""),
							//"\n          case \":" + arg.name + "\":" +
							LangIfThen(lang, 6,
								"valsub == vx_p_"+argname, "")+
								LangIfElseType(lang, 6,
									arg.vxtype, emptytype, "valsub", "val"+argname, false,
									LangVarSet(lang, 7,
										"ischanged", "true")+
										LangVarSet(lang, 7,
											"vx_p_"+argname, "val"+argname))+
								argalt+
								valnewswitcherr+
								LangIfEnd(lang, 6))
				}
				defaultkey := ""
				defaultstring := ""
				lastarg := props[len(props)-1]
				if lastarg.isdefault {
					lastargname := LangFromName(lastarg.name)
					lasttype := lastarg.vxtype
					defaultkey += "" +
						LangIfElseIf(lang, 5,
							LangIsType(lang, "valsub", lastarg.vxtype),
							LangVarSet(lang, 6,
								"ischanged", "true")+
								LangVarSet(lang, 6,
									"vx_p_"+lastargname,
									LangVarAsType(lang, "valsub", lasttype)))
					switch NameFromType(lastarg.vxtype) {
					case "vx/core/boolean":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawbooleantype),
								LangVarSet(lang, 6,
									"ischanged", "true")+
									LangVarSet(lang, 6,
										"vx_p_"+lastargname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangTypeT(lang, booleantype)+
											", "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/int":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawintegertype),
								LangVarSet(lang, 6,
									"ischanged", "true")+
									LangVarSet(lang, 6,
										"vx_p_"+lastargname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+LangTypeT(lang, inttype)+
											", "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/float":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawfloattype),
								LangVarSet(lang, 6,
									"ischanged", "true")+
									LangVarSet(lang, 6,
										"vx_p_"+lastargname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangTypeT(lang, floattype)+
											", "+
											LangVarArg1(lang, "valsub")+
											")"))
					case "vx/core/string":
						defaultstring += "" +
							LangIfElseType(lang, 6,
								stringtype, emptytype, "valsub", "valstr", false,
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+lastargname, "valstr")) +
							LangIfElseType(lang, 6,
								rawstringtype, emptytype, "valsub", "", false,
								LangVarSet(lang, 7,
									"ischanged", "true")+
									LangVarSet(lang, 7,
										"vx_p_"+lastargname,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangTypeT(lang, stringtype)+
											", "+
											LangVarArg1(lang, "valsub")+
											")"))
					}
					if lastarg.vxtype.extends == ":list" {
						lastargtype := lastarg.vxtype
						for _, allowtype := range lastarg.vxtype.allowtypes {
							defaultkey += "" +
								LangIfElseIf(lang, 5,
									LangIsType(lang, "valsub", allowtype),
									LangVar(lang, 6, allowtype,
										"valdefault",
										LangVarAsType(lang, "valsub", allowtype))+
										LangVar(lang, 6, lastargtype,
											"vallist", "")+
										LangVarSet(lang, 6,
											"vallist", "vx_p_"+lastargname)+
										LangIfThen(lang, 6,
											"vallist == null",
											LangVarSet(lang, 7,
												"vallist",
												LangPkgNameDot(lang, "vx/core")+
													"vx_new("+
													LangTypeT(lang, lastarg.vxtype)+
													", "+
													LangVarArg1(lang, "valdefault")+
													")"))+
										LangIfElse(lang, 6,
											LangVarSet(lang, 7,
												"vallist",
												LangPkgNameDot(lang, "vx/core")+
													"vx_copy(vallist, "+
													LangVarArg1(lang, "valdefault")+
													")"))+
										LangIfEnd(lang, 6)+
										LangVarSet(lang, 6,
											"ischanged", "true")+
										LangVarSet(lang, 6,
											"vx_p_"+lastargname, "vallist"))
						}
					}
				}
				switch NameFromType(typ) {
				case "vx/core/msg":
					valnew = "" +
						LangVar(lang, 3, rawstringtype,
							"key", "\"\"") +
						LangForList(lang, 3,
							"valsub", rawobjecttype, "vals",
							LangIfThen(lang, 4,
								LangVxEqualsString(lang, "key", "\"\""),
								LangIfThen(lang, 5,
									"false", "")+
									LangIfElseType(lang, 5,
										stringtype, emptytype, "valsub", "valstr", false,
										LangVarSet(lang, 6,
											"key", "valstr.vx_string()"))+
									LangIfElseType(lang, 5,
										rawstringtype, emptytype, "valsub", "sval", false,
										LangVarSet(lang, 6,
											"key", "sval"))+
									LangIfEnd(lang, 5))+
								LangIfElse(lang, 4,
									LangIfThen(lang, 5,
										"false", "")+
										valnewswitch+
										LangIfEnd(lang, 5)+
										LangVarSet(lang, 5,
											"key",
											"\"\""))+
								LangIfEnd(lang, 4)) +
						LangIfThen(lang, 3,
							"ischanged",
							LangVarClass(lang, 4, typ,
								"work", ":new")+
								valcopyend+
								LangVarSet(lang, 4,
									"output", "work")) +
						LangIfEnd(lang, 3)
				case "vx/core/msgblock":
					valnew = "" +
						LangVar(lang, 3, rawstringtype,
							"key", "\"\"") +
						LangVar(lang, 3, msgtype,
							"msg", LangTypeE(lang, msgtype)) +
						LangVar(lang, 3, anytype,
							"msgval", LangTypeE(lang, anytype)) +
						LangForList(lang, 3,
							"valsub", rawobjecttype, "vals",
							LangIfThen(lang, 4,
								LangIsType(lang, "valsub", msgblocktype),
								LangIfThen(lang, 5,
									"valsub == "+LangTypeE(lang, msgblocktype), "")+
									LangIfElseIf(lang, 5,
										"valsub == msgblock", "")+
									LangIfElse(lang, 5,
										LangVarSet(lang, 6,
											"vx_p_msgblocks",
											LangPkgNameDot(lang, "vx/core")+
												"vx_copy(vx_p_msgblocks, "+
												LangVarArg1(lang, "valsub")+
												")"))+
									LangIfEnd(lang, 5))+
								LangIfElseIf(lang, 4,
									LangIsType(lang, "valsub", msgblocklisttype),
									LangIfThen(lang, 5,
										"valsub != "+LangTypeE(lang, msgblocklisttype),
										LangVarSet(lang, 6,
											"vx_p_msgblocks",
											LangPkgNameDot(lang, "vx/core")+
												"vx_copy(vx_p_msgblocks, "+
												LangVarArg1(lang, "valsub")+
												")"))+
										LangIfEnd(lang, 5))+
								LangIfElseIf(lang, 4,
									LangIsType(lang, "valsub", msgtype),
									LangIfThen(lang, 5,
										"valsub != "+LangTypeE(lang, msgtype),
										LangVarSet(lang, 6,
											"vx_p_msgs",
											LangPkgNameDot(lang, "vx/core")+
												"vx_copy(vx_p_msgs, "+
												LangVarArg1(lang, "valsub")+
												")"))+
										LangIfEnd(lang, 5))+
								LangIfElseIf(lang, 4,
									LangIsType(lang, "valsub", msglisttype),
									LangIfThen(lang, 5,
										"valsub != "+LangTypeE(lang, msglisttype),
										LangVarSet(lang, 6,
											"vx_p_msgs",
											LangPkgNameDot(lang, "vx/core")+
												"vx_copy(vx_p_msgs, "+
												LangVarArg1(lang, "valsub")+
												")"))+
										LangIfEnd(lang, 5))+
								LangIfElseIf(lang, 4,
									LangVxEqualsString(lang, "key", "\"\""),
									LangIfThen(lang, 5,
										"false", "")+
										LangIfElseType(lang, 5,
											stringtype, emptytype, "valsub", "valstr", false,
											LangVarSet(lang, 6,
												"key", "valstr.vx_string()"))+
										LangIfElseType(lang, 5,
											rawstringtype, emptytype, "valsub", "sval", false,
											LangVarSet(lang, 6,
												"key", "sval"))+
										LangIfEnd(lang, 5))+
								LangIfElse(lang, 4,
									LangIfThen(lang, 5, "false", "")+
										valnewswitch+
										LangIfEnd(lang, 5)+
										LangVarSet(lang, 5,
											"key", "\"\""))+
								LangIfEnd(lang, 4)) +
						LangVar(lang, 3, rawbooltype,
							"ischangemsgs", "vx_p_msgs != value.msgs()") +
						LangVar(lang, 3, rawbooltype,
							"ischangemsgblocks", "vx_p_msgblocks != value.msgblocks()") +
						LangVarSet(lang, 3,
							"ischanged", "ischangemsgs || ischangemsgblocks") +
						LangIfThen(lang, 3,
							"ischanged",
							LangIfThen(lang, 4,
								"(vx_p_msgs == "+
									LangTypeE(lang, msglisttype)+
									") && ("+
									LangVarListSize(lang, "vx_p_msgblocks.vx_list()")+
									" == 1)",
								LangVarSet(lang, 5,
									"output",
									LangVarListGet(lang, "vx_p_msgblocks.vx_listmsgblock()", "0")))+
								LangIfElse(lang, 4,
									LangVarClass(lang, 5, typ,
										"work", ":new")+
										LangVarSet(lang, 5,
											"work.vx_p_msgs", "vx_p_msgs")+
										LangVarSet(lang, 5,
											"work.vx_p_msgblocks", "vx_p_msgblocks")+
										LangVarSet(lang, 5,
											"output", "work"))) +
						LangIfEnd(lang, 4) +
						LangIfEnd(lang, 3)
				default:
					valnew = "" +
						validkeys +
						LangVar(lang, 3, rawstringtype,
							"key", "\"\"") +
						LangVar(lang, 3, msgtype,
							"msg", LangTypeE(lang, msgtype)) +
						LangVar(lang, 3, anytype,
							"msgval", LangTypeE(lang, anytype)) +
						LangForList(lang, 3,
							"valsub", rawobjecttype, "vals",
							LangIfThen(lang, 4,
								LangIsType(lang, "valsub", msgblocktype),
								LangVarSet(lang, 5,
									"msgblock",
									LangPkgNameDot(lang, "vx/core")+
										"vx_copy(msgblock, "+
										LangVarArg1(lang, "valsub")+
										")"))+
								LangIfElseIf(lang, 4,
									LangIsType(lang, "valsub", msgtype),
									LangVarSet(lang, 5,
										"msgblock",
										LangPkgNameDot(lang, "vx/core")+
											"vx_copy(msgblock, "+
											LangVarArg1(lang, "valsub")+
											")"))+
								LangIfElseIf(lang, 4,
									LangVxEqualsString(lang, "key", "\"\""),
									LangVar(lang, 5, rawbooltype,
										"istestkey", "false")+
										LangVar(lang, 5, rawstringtype,
											"testkey", "\"\"")+
										LangIfThen(lang, 5,
											"false", "")+
										LangIfElseType(lang, 5,
											stringtype, emptytype, "valsub", "valstr", false,
											LangVarSet(lang, 6,
												"testkey", "valstr.vx_string()")+
												LangVarSet(lang, 6,
													"istestkey", "true"))+
										LangIfElseType(lang, 5,
											rawstringtype, emptytype, "valsub", "sval", false,
											LangVarSet(lang, 6,
												"testkey", "sval")+
												LangVarSet(lang, 6,
													"istestkey", "true")+
												defaultkey)+
										LangIfElse(lang, 5,
											LangIfThen(lang, 6,
												"false", "")+
												LangIfElseType(lang, 6,
													anytype, emptytype, "valsub", "valmsg", false,
													LangVarSet(lang, 7,
														"msgval", "valmsg"))+
												LangIfElse(lang, 6,
													LangVarSet(lang, 7,
														"msgval",
														LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVarToString(lang, "valsub")+")"))+
												LangIfEnd(lang, 6)+
												LangVarSet(lang, 6,
													"msg",
													LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidkeytype\", msgval)")+
												LangVarSet(lang, 6,
													"msgblock",
													LangPkgNameDot(lang, "vx/core")+
														"vx_copy(msgblock, "+
														LangVarArg1(lang, "msg")+
														")"))+
										LangIfEnd(lang, 5)+
										LangIfThen(lang, 5,
											"istestkey",
											LangIfThen(lang, 6,
												"!"+LangVarStringStarts(lang, "testkey", "\":\""),
												LangVarSet(lang, 7,
													"testkey", "\":\" + testkey"))+
												LangIfEnd(lang, 6)+
												LangVar(lang, 6, rawbooltype,
													"isvalidkey",
													LangVxContains(lang, "validkeys", "testkey"))+
												LangIfThen(lang, 6,
													"isvalidkey",
													LangVarSet(lang, 7,
														"key", "testkey")+
														defaultstring)+
												LangIfElse(lang, 6,
													LangVarSet(lang, 7,
														"msgval",
														LangPkgNameDot(lang, "vx/core")+"vx_new_string(testkey)")+
														LangVarSet(lang, 7,
															"msg",
															LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidkey\", msgval)")+
														LangVarSet(lang, 7,
															"msgblock",
															LangPkgNameDot(lang, "vx/core")+
																"vx_copy(msgblock, "+
																LangVarArg1(lang, "msg")+
																")"))+
												LangIfEnd(lang, 6)+
												LangIfEnd(lang, 5))+
										LangIfElse(lang, 4,
											LangIfThen(lang, 5, "false", "")+
												valnewswitch+
												LangIfElse(lang, 5,
													LangVarSet(lang, 6,
														"msgval",
														LangPkgNameDot(lang, "vx/core")+"vx_new_string(key)")+
														LangVarSet(lang, 6,
															"msg",
															LangPkgNameDot(lang, "vx/core")+
																"vx_msg_from_error(\""+
																typepath+
																"\", \":invalidkey\", msgval)")+
														LangVarSet(lang, 6,
															"msgblock",
															LangPkgNameDot(lang, "vx/core")+
																"vx_copy(msgblock, "+
																LangVarArg1(lang, "msg")+
																")"))+
												LangIfEnd(lang, 5)+
												LangVarSet(lang, 5,
													"key", "\"\""))+
										LangIfEnd(lang, 4))) +
						LangIfThen(lang, 3,
							"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
							LangVarClass(lang, 4, typ,
								"work", ":new")+
								valcopyend+
								LangIfThen(lang, 4,
									"msgblock != "+LangTypeE(lang, msgblocktype),
									LangVarSet(lang, 5,
										"work.vxmsgblock", "msgblock"))+
								LangIfEnd(lang, 4)+
								LangVarSet(lang, 4,
									"output", "work")) +
						LangIfEnd(lang, 3)
				}
			}
		default:
			if valnew == "" {
				valnew = "" +
					LangIfThen(lang, 3,
						"ischanged || (msgblock != "+LangTypeE(lang, msgblocktype)+")",
						LangVarClass(lang, 4, typ,
							"work", ":new")+
							LangIfThen(lang, 4,
								"msgblock != "+LangTypeE(lang, msgblocktype),
								LangVarSet(lang, 5,
									"work.vxmsgblock", "msgblock"))+
							LangIfEnd(lang, 4)+
							LangVarSet(lang, 4,
								"output", "work")) +
					LangIfEnd(lang, 3)
			}
		}
		funcvxcopy.isoverride = true
		output = "" +
			LangFuncHeader(lang, 2,
				typename, funcvxcopy, 0,
				LangVar(lang, 3, typ,
					"output", LangTypeThis(lang))+
					valcopy+
					valnew)
	}
	return output
}

func LangTypeVxEmpty(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxempty := NewFunc()
	funcvxempty.name = "vx_empty"
	funcvxempty.vxtype = anytype
	typename := LangTypeName(lang, typ)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			typename, funcvxempty)
	} else {
		funcvxempty.isoverride = true
		output = "" +
			LangFuncHeader(lang, 2,
				typename, funcvxempty, 0,
				LangVar(lang, 3, anytype,
					"output",
					LangTypeE(lang, typ)))
	}
	return output
}

func LangTypeVxFuncdef(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxfuncdef := NewFunc()
	funcvxfuncdef.name = "vx_funcdef"
	funcvxfuncdef.vxtype = funcdeftype
	prefix := LangNameFromType(lang, typ)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			prefix, funcvxfuncdef)
	} else {
		funcvxfuncdef.isimplement = true
		output = "" +
			LangFuncHeader(lang, 2,
				prefix, funcvxfuncdef, 0,
				LangVar(lang, 3, funcdeftype,
					"output",
					LangTypeE(lang, funcdeftype)))
	}
	return output
}

func LangTypeVxList(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxlist := NewFunc()
	funcvxlist.name = "vx_list"
	funcvxlist.vxtype = rawlistanytype
	funcvxlist.isimplement = true
	typename := LangTypeName(lang, typ)
	output := ""
	if isinterface {
		output = LangFuncInterface(lang, funcvxlist)
	} else {
		castlist := LangTypeThis(lang) + lang.typeref + "vx_p_list"
		output = "" +
			LangFuncHeader(lang, 2,
				typename, funcvxlist, 0,
				LangVarCollection(lang, 3, rawlisttype, anytype,
					"output",
					LangPkgNameDot(lang, "vx/core")+
						"immutablelist("+
						"\n        "+LangVarListNew(lang, anytype, castlist)+
						"\n      )"))
	}
	return output
}

func LangTypeVxMapStruct(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	output := ""
	typename := LangNameFromType(lang, typ)
	funcvxmap := NewFunc()
	funcvxmap.name = "vx_map"
	funcvxmap.vxtype = NewTypeSubtype(rawmaptype, anytype)
	if isinterface {
		output = LangFuncInterface(lang, funcvxmap)
	} else {
		vx_map := ""
		props := ListPropertyTraitFromType(typ)
		for _, arg := range props {
			argname := LangFromName(arg.name)
			vx_map += LangVarMapSet(lang, 3,
				"map",
				"\":"+arg.name+"\"",
				LangTypeThis(lang)+"."+argname+"()")
		}
		funcvxmap.isimplement = true
		output += "" +
			LangFuncHeader(lang, 2,
				typename, funcvxmap, 0,
				LangVarCollection(lang, 3, rawmaptype, anytype,
					"map",
					LangVarMapNew(lang, anytype, ""))+
					vx_map+
					LangVarCollection(lang, 3, rawmaptype, anytype,
						"output",
						LangPkgNameDot(lang, "vx/core")+"immutablemap(map)"))
	}
	return output
}

func LangTypeVxMsgblock(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	output := ""
	funcvxmsgblock := NewFunc()
	funcvxmsgblock.name = "vx_msgblock"
	funcvxmsgblock.vxtype = msgblocktype
	typename := LangNameFromType(lang, typ)
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			typename, funcvxmsgblock)
		/*
			} else {
				switch NameFromType(typ) {
				case "vx/core/msg", "vx/core/msgblock":
					funcvxmsgblock.isoverride = true
					output = "" +
						LangFuncHeader(lang, typename, funcvxmsgblock, 2, 0,
							LangVar(lang, "output", msgblocktype, 3,
								LangTypeE(lang, msgblocktype)))
				}
		*/
	}
	return output
}

func LangTypeVxNew(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxnew := LangTypeVxNewModel(typ)
	typename := LangNameFromType(lang, typ)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			typename, funcvxnew)
	} else {
		funcvxnew.isoverride = true
		vals := LangNativeTypeVxNewVals(lang)
		output = "" +
			LangFuncHeader(lang, 2,
				typename, funcvxnew, 0,
				LangVar(lang, 3, typ,
					"output",
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy("+
						LangTypeE(lang, typ)+
						", "+
						vals+
						")"))
	}
	return output
}

func LangTypeVxNewModel(
	returntype *vxtype) *vxfunc {
	argvals := NewArg("vals")
	argvals.vxtype = rawobjecttype
	argvals.multi = true
	argvals.isfinal = true
	arglist := NewListArg()
	arglist = append(arglist, argvals)
	funcvxnew := NewFunc()
	funcvxnew.name = "vx_new"
	funcvxnew.vxtype = anytype
	funcvxnew.listarg = arglist
	return funcvxnew
}

func LangTypeVxNewMap(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	output := ""
	allowname := "any"
	allowtype := anytype
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowname = LangNameFromType(lang, allowtype)
	}
	if allowname == "any" {
		allowname = ""
	}
	typepath := NameFromType(typ)
	keyset, mapget := LangTypeMapKeysetGet(lang)
	argmapval := NewArg("mapval")
	argmapval.vxtype = rawmapanytype
	listarg := NewListArg()
	listarg = append(listarg, argmapval)
	funcvxnewmap := NewFunc()
	funcvxnewmap.name = "vx_new_from_map"
	funcvxnewmap.vxtype = maptype
	funcvxnewmap.listarg = listarg
	typename := LangTypeName(lang, typ)
	if isinterface {
		output += "" +
			LangFuncHeaderInterface(lang, 2,
				typename, funcvxnewmap)
	} else {
		funcvxnewmap.isimplement = true
		output += "" +
			LangFuncHeader(lang, 2,
				typename, funcvxnewmap, 0,
				LangVarClass(lang, 3, typ,
					"output", ":new")+
					LangVar(lang, 3, msgblocktype,
						"msgblock",
						LangTypeE(lang, msgblocktype))+
					LangVarCollection(lang, 3, rawmaptype, allowtype,
						"map", LangVarMapNew(lang, allowtype, ""))+
					keyset+
					LangForList(lang, 3,
						"key", rawstringtype, "keys",
						LangVar(lang, 4, anytype,
							"value", mapget)+
							LangIfThen(lang, 4,
								"false", "")+
							LangIfElseType(lang, 4,
								allowtype, emptytype, "value", "castval", false,
								LangVarMapSet(lang, 5,
									"map", "key", "castval"))+
							LangIfElse(lang, 4,
								LangVar(lang, 5, msgtype,
									"msg",
									LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", value)")+
									LangVarSet(lang, 5,
										"msgblock",
										LangPkgNameDot(lang, "vx/core")+
											"vx_copy(msgblock, "+
											LangVarArg1(lang, "msg")+
											")"))+
							LangIfEnd(lang, 4))+
					LangVarSet(lang, 3,
						"output.vx_p_map",
						LangPkgNameDot(lang, "vx/core")+"immutablemap(map)")+
					LangIfThen(lang, 3,
						"msgblock != "+LangTypeE(lang, msgblocktype),
						LangVarSet(lang, 4,
							"output.vxmsgblock", "msgblock"))+
					LangIfEnd(lang, 3))
	}
	return output
}

func LangTypeVxSet(
	lang *vxlang,
	typ *vxtype) string {
	argname := NewArg("name")
	argname.vxtype = stringtype
	argvalue := NewArg("value")
	argvalue.vxtype = anytype
	listarg := NewListArg()
	listarg = append(listarg, argname, argvalue)
	funcvxmap := NewFunc()
	funcvxmap.name = "vx_set"
	funcvxmap.vxtype = booleantype
	funcvxmap.isimplement = true
	funcvxmap.listarg = listarg
	prefix := LangTypeName(lang, typ)
	allowtype := anytype
	allowname := "any"
	allowtypes := ListAllowTypeFromType(typ)
	allowempty := LangTypeE(lang, anytype)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowempty = LangTypeE(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
	}
	if allowname == "any" {
		allowname = ""
	}
	body := "" +
		LangVar(lang, 3, booleantype,
			"output", LangPkgNameDot(lang, "vx/core")+"c_false") +
		LangIfThen(lang, 3,
			"false", "") +
		LangIfElseType(lang, 3,
			allowtype, emptytype, "value", "castval", false,
			LangVar(lang, 4, rawstringtype,
				"key", "name.vx_string()")+
				LangIfThen(lang, 4,
					LangVarStringStarts(lang, "key", "\":\""),
					LangVarSet(lang, 5,
						"key", LangVarSubstring(lang, "key", "1", "")))+
				LangIfEnd(lang, 4)+
				LangVarCollection(lang, 4, rawmaptype, allowtype,
					"map",
					LangVarMapNew(lang, allowtype, LangTypeThis(lang)+".vx_p_map"))+
				LangIfThen(lang, 4,
					"castval == "+allowempty,
					LangVarMapRemove(lang, 5,
						"map", "key"))+
				LangIfElse(lang, 4,
					LangVarMapSet(lang, 5,
						"map", "key", "castval")+
						LangIfEnd(lang, 4)+
						LangVarSet(lang, 4,
							LangTypeThis(lang)+".vx_p_map",
							LangPkgNameDot(lang, "vx/core")+"immutablemap(map)")+
						LangVarSet(lang, 4,
							"output", LangPkgNameDot(lang, "vx/core")+"c_true"))) +
		LangIfEnd(lang, 3)
	output := "" +
		LangFuncHeader(lang, 2,
			prefix, funcvxmap, 0, body)
	return output
}

func LangTypeVxType(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxtype := NewFunc()
	funcvxtype.name = "vx_type"
	funcvxtype.vxtype = anytype
	output := ""
	typename := LangNameFromType(lang, typ)
	if isinterface {
		output = LangFuncHeaderInterface(lang, 2,
			typename, funcvxtype)
	} else {
		funcvxtype.isoverride = true
		output = "" +
			LangFuncHeader(lang, 2,
				typename, funcvxtype, 0,
				LangVar(lang, 3, anytype,
					"output",
					LangTypeT(lang, typ)))
	}
	return output
}

func LangTypeVxTypedef(
	lang *vxlang,
	typ *vxtype,
	isinterface bool) string {
	funcvxtypedef := NewFunc()
	funcvxtypedef.name = "vx_typedef"
	funcvxtypedef.vxtype = typedeftype
	output := ""
	if isinterface {
		typename := LangNameTypeFullFromType(lang, typ)
		output = LangFuncHeaderOld(lang, typename, funcvxtypedef, true, false)
	} else {
		funcvxtypedef.isoverride = true
		prefix := LangNameFromType(lang, typ)
		output = "" +
			LangFuncHeader(lang, 2,
				prefix, funcvxtypedef, 0,
				LangVar(lang, 3, typedeftype,
					"output",
					LangTypeDef(lang, typ, 3)))
	}
	return output
}
