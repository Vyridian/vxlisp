package vxlisp

import "strings"

func LangType(lang *vxlang, typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangType")
	output := ""
	path := typ.pkgname + "/" + typ.name
	g_ifuncdepth = 0
	doc := "" +
		"type: " + typ.name
	if typ.doc != "" {
		doc += "\n" + typ.doc
	}
	if typ.deprecated != "" {
		doc += "\n" + typ.deprecated
	}
	typename := LangFromName(typ.alias)
	typepath := NameFromType(typ)
	instancefuncs := ""
	createtext, msgs := LangFromValue(lang, typ.createvalue, "", emptyfunc, 2, true, false, path)
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
			LangVarProp(lang, "vx_p_list", rawlisttype, allowtype, 2,
				LangPkgNameDot(lang, "vx/core")+"immutablelist("+
					"\n      "+LangVxNewList(lang, allowtype, "")+
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
			LangVarProp(lang, "vx_p_map", rawmaptype, allowtype, 2,
				LangPkgNameDot(lang, "vx/core")+
					"immutablemap("+
					LangVxNewMap(lang, allowtype, "")+
					")") +
			"\n" +
			LangTypeVxMap(lang, allowtype) +
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
			validkeys := LangVarCollection(lang, "validkeys", rawlisttype, rawstringtype, 3, ":new")
			valnewswitch := ""
			for _, arg := range props {
				validkeys += LangVxListAdd(lang, "validkeys", 3, "\":"+arg.name+"\"")
				argname := LangFromName(arg.name)
				valcopyend += "" +
					"\n        work.vx_p_" + argname + " = vx_p_" + argname + lang.lineend
				vx_any += "" +
					LangIfElseIf(lang, 3,
						LangIfClause(lang, rawstringtype,
							"==",
							"skey",
							"\":"+arg.name+"\""),
						LangVarSet(lang, "output", 4, "this."+argname+"()"))
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawbooleantype),
							LangVarSet(lang, "ischanged", 7, "true")+
								LangVarSet(lang, "vx_p_"+argname, 7,
									LangPkgNameDot(lang, "vx/core")+"vx_new("+LangTypeT(lang, booleantype)+", valsub)"))
				case "vx/core/int":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawintegertype),
							LangVarSet(lang, "ischanged", 7, "true")+
								LangVarSet(lang, "vx_p_"+argname, 7,
									LangPkgNameDot(lang, "vx/core")+"vx_new("+LangTypeT(lang, inttype)+", valsub)"))
				case "vx/core/float":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawfloattype),
							LangVarSet(lang, "ischanged", 7, "true")+
								LangVarSet(lang, "vx_p_"+argname, 7,
									LangPkgNameDot(lang, "vx/core")+"vx_new("+LangTypeT(lang, floattype)+", valsub)"))
				case "vx/core/string":
					argalt = "" +
						LangIfElseIf(lang, 6,
							LangIsType(lang, "valsub", rawstringtype),
							LangVarSet(lang, "ischanged", 7, "true")+
								LangVarSet(lang, "vx_p_"+argname, 7,
									LangPkgNameDot(lang, "vx/core")+"vx_new("+LangTypeT(lang, stringtype)+", valsub)"))
				}
				valnewswitcherr := ""
				switch NameFromType(typ) {
				case "vx/core/msg":
				default:
					valnewswitcherr = "" +
						"\n            } else {" +
						"\n              if (false) {" +
						LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 7, false) +
						LangVarSet(lang, "msgval", 8, "valinvalid") +
						"\n              } else {" +
						LangVarSet(lang, "msgval", 8,
							LangPkgNameDot(lang, "vx/core")+
								"vx_new_string("+LangVxToString(lang, "valsub")+")") +
						"\n              }" +
						LangVarCollection(lang, "mapany", rawmaptype, anytype, 7,
							LangVxNewMap(lang, anytype, "")) +
						"\n              mapany.put(\"key\", " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + arg.name + "\"))" + lang.lineend +
						"\n              mapany.put(\"value\", msgval)" + lang.lineend +
						LangVar(lang, "msgmap", maptype, 7,
							LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)") +
						LangVarSet(lang, "msg", 7,
							LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", msgmap)") +
						LangVarSet(lang, "msgblock", 7,
							LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)")
				}
				valnewswitch += "" +
					LangIfElseIf(lang, 5,
						LangIfClause(lang, rawstringtype,
							"==", "key", "\":"+arg.name+"\""),
						//"\n          case \":" + arg.name + "\":" +
						LangIf(lang, 6, "valsub == vx_p_"+argname, "")+
							LangElseIfType(lang, arg.vxtype, emptytype, "valsub", "val"+argname, 6, false)+
							LangVarSet(lang, "ischanged", 7, "true")+
							LangVarSet(lang, "vx_p_"+argname, 7, "val"+argname)+
							argalt+
							valnewswitcherr+
							LangIfEnd(lang, 6))
					//"\n            break" + lang.lineend
				instancefuncs += "" +
					LangVarProp(lang, "vx_p_"+argname, arg.vxtype, emptytype, 2, "null") +
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
					"\n          } else if (" + LangIsType(lang, "valsub", lastarg.vxtype) + ") { // default property" +
					LangVarSet(lang, "ischanged", 6, "true") +
					LangVarSet(lang, "vx_p_"+lastargname, 6,
						LangAsType(lang, "valsub", lastargtype))
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawbooleantype) + ") { // default property" +
						LangVarSet(lang, "ischanged", 6, "true") +
						LangVarSet(lang, "vx_p_"+lastargname, 6,
							LangPkgNameDot(lang, "vx/core")+
								"vx_new("+LangTypeT(lang, booleantype)+", valsub)")
				case "vx/core/int":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") { // default property" +
						LangVarSet(lang, "ischanged", 6, "true") +
						LangVarSet(lang, "vx_p_"+lastargname, 6,
							LangPkgNameDot(lang, "vx/core")+
								"vx_new("+LangTypeT(lang, inttype)+", valsub)")
				case "vx/core/float":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawfloattype) + ") { // default property" +
						LangVarSet(lang, "ischanged", 6, "true") +
						LangVarSet(lang, "vx_p_"+lastargname, 6,
							LangPkgNameDot(lang, "vx/core")+
								"vx_new("+LangTypeT(lang, floattype)+", valsub)")
				case "vx/core/string":
					defaultstring += "" +
						LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 6, false) +
						LangVarSet(lang, "ischanged", 7, "true") +
						LangVarSet(lang, "vx_p_"+lastargname, 7, "valstr") +
						LangElseIfType(lang, rawstringtype, emptytype, "valsub", "", 6, false) +
						LangVarSet(lang, "ischanged", 7, "true") +
						LangVarSet(lang, "vx_p_"+lastargname, 7,
							LangPkgNameDot(lang, "vx/core")+
								"vx_new("+LangTypeT(lang, stringtype)+", valsub)")
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						defaultkey += "" +
							"\n          } else if (" + LangIsType(lang, "valsub", allowtype) + ") { // default property" +
							LangVar(lang, "valdefault", allowtype, 6,
								LangAsType(lang, "valsub", allowtype)) +
							LangVar(lang, "vallist", lastargtype, 6, "") +
							LangVarSet(lang, "vallist", 6, "vx_p_"+lastargname) +
							"\n            if (vallist == null) {" +
							LangVarSet(lang, "vallist", 7,
								LangPkgNameDot(lang, "vx/core")+
									"vx_new("+
									LangTypeT(lang, lastarg.vxtype)+
									", valdefault)") +
							"\n            } else {" +
							LangVarSet(lang, "vallist", 7,
								LangPkgNameDot(lang, "vx/core")+
									"vx_copy(vallist, valdefault)") +
							"\n            }" +
							LangVarSet(lang, "ischanged", 6, "true") +
							LangVarSet(lang, "vx_p_"+lastargname, 6, "vallist")
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
				LangVar(lang, "skey", rawstringtype, 3, "key.vx_string()") +
				LangIf(lang, 3, "false", "") +
				vx_any +
				LangIfEnd(lang, 3)
		}
		instancefuncs += "" +
			LangFuncHeader(lang, prefix, funcvxany, 2, 0,
				LangVar(lang, "output", anytype, 3,
					LangTypeE(lang, anytype))+
					skeyswitch) +
			LangTypeVxMapStruct(lang, typ, false)
	}
	e_type := ""
	switch NameFromType(typ) {
	case "vx/core/boolean":
	default:
		e_type = LangValStatic(lang, "e_"+typename, typ, 1, ":new")
	}
	t_type := LangValStatic(lang, "t_"+typename, typ, 1, ":new")
	doc = "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */"
	/// FIXME
	switch lang {
	case langkotlin:
		doc = ""
	}
	output += "" +
		doc +
		LangTypeInterface(lang, typ) +
		LangTypeClassHeader(lang, typ, 1) +
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

func LangTypeClassHeader(lang *vxlang, typ *vxtype, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	typename := LangFromName(typ.alias)
	switch lang {
	case langcsharp:
		output = lineindent + "public class Class_" + typename + " : " + LangPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	case langjava:
		output = lineindent + "public static class Class_" + typename + " extends " + LangPkgNameDot(lang, "vx/core") + "Class_base implements Type_" + LangNameFromType(lang, typ) + " {"
	case langkotlin:
		output = "" +
			lineindent + "class Class_" + typename + " : " + LangPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangTypeDef(lang *vxlang, typ *vxtype, indent int) string {
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
		switch lang {
		case langcpp:
			output += "vx_empty"
		default:
			output += "f_empty"
		}
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

func LangTypeInterface(lang *vxlang, typ *vxtype) string {
	output := ""
	typename := LangNameTypeFullFromType(lang, typ)
	isbasics := true
	switch lang {
	case langcsharp, langjava, langkotlin:
		switch NameFromType(typ) {
		case "vx/core/any":
		default:
			isbasics = false
		}
	}
	basics := ""
	if isbasics {
		basics = "" +
			LangTypeVxNew(lang, typ, true) +
			LangTypeVxCopy(lang, typ, true) +
			LangTypeVxEmpty(lang, typ, true) +
			LangTypeVxType(lang, typ, true)
	}
	createtext, _ := LangFromValue(lang, typ.createvalue, "", emptyfunc, 0, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if (createline == "@Override") || (createline == "// :implements") {
				isoverride = true
			} else if isoverride {
				ipos1 := 0
				if BooleanFromStringStarts(createline, "override ") {
					ipos1 += 9
				}
				ipos2 := IntFromStringFindLast(createline, "{")
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
					LangFuncHeaderInterface(lang, typename, funcvxlist, 2)+
					LangFuncHeaderInterface(lang, typename, funcvxany, 2))
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
					LangFuncHeaderInterface(lang, typename, funcvxnewfrommap, 2)+
					LangFuncHeaderInterface(lang, typename, funcvxany, 2)+
					LangFuncHeaderInterface(lang, typename, funcvxmap, 2)+
					LangFuncHeaderInterface(lang, typename, funcvxset, 2))
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
					LangFuncHeaderInterface(lang, typename, funcvxany, 2)+
					LangFuncHeaderInterface(lang, typename, funcvxmap, 2))
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
						LangFuncHeaderInterface(lang, typename, funcvxlistallow, 2) +
						LangFuncHeaderInterface(lang, typename, funcvxallow, 2)
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
						LangFuncHeaderInterface(lang, typename, funcvxmapallow, 2) +
						LangFuncHeaderInterface(lang, typename, funcvxallow, 2)
				}
			}
		case ":struct":
			extends = append(extends, structtype)
			if len(typ.traits) > 0 {
				extends = append(extends, typ.traits...)
			}
			var typeproperties []vxarg
			switch lang {
			case langcsharp, langkotlin, langswift:
				typeproperties = typ.properties
			default:
				typeproperties = ListPropertyTraitFromType(typ)
			}
			for _, arg := range typeproperties {
				funcvxprop := NewFunc()
				funcvxprop.name = LangFromName(arg.alias)
				funcvxprop.vxtype = arg.vxtype
				extras += "" +
					LangFuncHeaderOld(lang, typename, funcvxprop, true, false)
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

func LangTypeInterfaceHeader(
	lang *vxlang,
	typ *vxtype,
	extendtypes []*vxtype,
	indent int,
	body string) string {
	lineindent := LangIndent(lang, indent, true)
	output := ""
	extendtext := ""
	var extendtexts []string
	for _, extendtype := range extendtypes {
		extendpart := LangTypeName(lang, extendtype)
		extendtexts = append(extendtexts, extendpart)
	}
	extendtext = StringFromListStringJoin(extendtexts, ", ")
	switch lang {
	case langcsharp:
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	case langjava:
		if extendtext != "" {
			extendtext = " extends " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	case langkotlin:
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	}
	return output
}

func LangTypeIntValNew(lang *vxlang, val int) string {
	return LangPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(val) + ")"
}

func LangTypeListFromListType(lang *vxlang, listtype []*vxtype) string {
	output := LangPkgNameDot(lang, "vx/core") + "e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := LangTypeT(lang, typ)
			listtext = append(listtext, typetext)
		}
		output = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangPkgNameDot(lang, "vx/core") + "t_typelist, " + StringFromListStringJoin(listtext, ", ") + ")"
	}
	return output
}

func LangTypeName(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFromTypeSimple(lang, typ, false)
}

func LangTypeNameSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	alias := typ.alias
	switch typ {
	case rawbooltype:
		switch lang {
		case langcsharp:
			name = "bool"
		case langjava:
			name = "boolean"
		case langkotlin:
			name = "Boolean"
		}
	case rawbooleantype:
		switch lang {
		case langcsharp:
			name = "bool"
		case langjava:
			name = "Boolean"
		case langkotlin:
			name = "Boolean"
		}
	case rawfloattype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "Float"
		}
	case rawifntype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "IFn"
		}
	case rawinttype:
		switch lang {
		case langcsharp, langjava:
			name = "int"
		case langkotlin:
			name = "Int"
		}
	case rawintegertype:
		switch lang {
		case langcsharp, langjava:
			name = "Integer"
		case langkotlin:
			name = "Int"
		}
	case rawlisttype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List"
		}
	case rawlistanytype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List<" + LangTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawlistunknowntype:
		switch lang {
		case langcsharp:
			name = "List<object>"
		case langjava:
			name = "List<?>"
		case langkotlin:
			name = "List<*>"
		}
	case rawmaptype:
		switch lang {
		case langcsharp:
			name = "Vx.Core.Map"
		case langjava, langkotlin:
			name = "Map"
		}
	case rawmapanytype:
		switch lang {
		case langcpp:
			name = "std::map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case langjava, langkotlin:
			name = "Map<String, " + LangTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		switch lang {
		case langcpp:
			name = "std::string"
		case langcsharp:
			name = "string"
		default:
			name = "String"
		}
	case rawobjecttype:
		switch lang {
		case langcsharp:
			name = "object"
		case langjava:
			name = "Object"
		case langkotlin:
			name = "Any"
		}
	case rawvoidtype:
		switch lang {
		case langkotlin:
			name = "Unit"
		default:
			name = "void"
		}
	default:
		if typ.isfunc {
			name = LangFuncName(typ.vxfunc)
		} else if alias == "" {
			name = LangFromName(typ.name)
		} else if typ.isgeneric {
			if simple {
				if BooleanFromStringStarts(alias, "generic-") {
					alias = StringFromStringFindReplace(alias, "generic-", "")
					ipos := IntFromStringFindLast(alias, "-")
					alias = alias[0:ipos]
				}
			} else {
				alias = LangGenericFromType(lang, typ)
			}
			name = LangFromName(alias)
		} else {
			name = LangFromName(alias)
		}
	}
	return name
}

func LangTypeStringValNew(lang *vxlang, val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + valstr + "\")"
}

func LangTypeT(lang *vxlang, typ *vxtype) string {
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
			output = LangFuncHeaderInterface(lang, typename, funcvxallow, 2)
			if allowname != "any" {
				output = LangFuncHeaderInterface(lang, typename, funcvxany, 2)
			}
		} else {
			funcvxallow.isimplement = true
			funcvxany.isimplement = true
			funcvxlistallow.isimplement = true
			output = "" +
				LangFuncHeader(lang, typename, funcvxallow, 2, 0,
					LangVar(lang, "output", allowtype, 3,
						LangTypeE(lang, allowtype))+
						LangVarClass(lang, "list", typ, 3, "this")+
						LangVar(lang, "iindex", rawinttype, 3, "index.vx_int()")+
						LangVarCollection(lang, "listval", rawlisttype, allowtype, 3,
							"list.vx_p_list")+
						"\n      if (iindex < "+LangVxListSize(lang, "listval")+") {"+
						LangVarSet(lang, "output", 4,
							LangVxListGet(lang, "listval", "iindex"))+
						"\n      }")
		}
		if allowname != "any" {
			output += "" +
				LangFuncHeader(lang, typename, funcvxlistallow, 2, 0,
					LangVarCollection(lang, "output", rawlisttype, allowtype, 3,
						"this.vx_p_list")) +
				LangFuncHeader(lang, typename, funcvxany, 2, 0,
					LangVar(lang, "output", allowtype, 3,
						"this.vx_"+allowname+"(index)"))
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
		switch lang {
		case langcsharp:
			getorelse = "mapval.getOrElse(skey, " + LangTypeE(lang, allowtype) + ")"
		default:
			getorelse = "mapval.getOrDefault(skey, " + LangTypeE(lang, allowtype) + ")"
		}
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
				LangFuncHeader(lang, typename, funcvxallow, 2, 0,
					LangVar(lang, "output", allowtype, 3, allowempty)+
						LangVarClass(lang, "map", typ, 3, "this")+
						LangVar(lang, "skey", rawstringtype, 3, "key.vx_string()")+
						LangVarCollection(lang, "mapval", rawmaptype, allowtype, 3, "map.vx_p_map")+
						LangVarSet(lang, "output", 3, getorelse))
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
				LangFuncHeaderInterface(lang, typename, funcvxany, 2) +
				LangFuncHeaderInterface(lang, typename, funcvxmapallow, 2)
		} else {
			funcvxmapallow.isimplement = true
			funcvxany.isimplement = true
			output += "" +
				LangFuncHeader(lang, typename, funcvxmapallow, 2, 0,
					LangVarCollection(lang, "output", rawmaptype, allowtype, 3, "this.vx_p_map")) +
				LangFuncHeader(lang, typename, funcvxany, 2, 0,
					LangVar(lang, "output", anytype, 3, "this.vx_"+allowname+"(key)")) +
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
		output = LangFuncHeaderInterface(lang, typename, funcvxcopy, 2)
	} else {
		typepath := NameFromType(typ)
		valnew := ""
		valcopy := "" +
			LangVar(lang, "ischanged", rawbooltype, 3, "false") +
			LangVarClass(lang, "value", typ, 3, "this") +
			LangVar(lang, "msgblock", msgblocktype, 3,
				LangPkgNameDot(lang, "vx/core")+"vx_msgblock_from_copy_arrayval(value, vals)") +
			"\n      if (this.vx_constdef() != " + LangTypeE(lang, constdeftype) + ") {" +
			LangVarSet(lang, "ischanged", 4, "true") +
			"\n      }"
		switch NameFromType(typ) {
		case "vx/core/any":
			valnew += "" +
				LangForList(lang, "valsub", rawobjecttype, "vals", 3,
					"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						"\n        }") +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", anytype, 4, ":new") +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      }"
		case "vx/core/anytype":
		case "vx/core/const":
		case "vx/core/list":
		case "vx/core/map":
		case "vx/core/struct":
		case "vx/core/func":
		case "vx/core/type":
		case "vx/core/boolean":
			valcopy += "" +
				LangVar(lang, "booleanval", rawbooltype, 3, "value.vx_boolean()")
			valnew = "" +
				LangForList(lang, "valsub", rawobjecttype, "vals", 3,
					"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						LangElseIfType(lang, booleantype, emptytype, "valsub", "valboolean", 4, false)+
						"\n          booleanval = booleanval || valboolean.vx_boolean()"+lang.lineend+
						LangElseIfType(lang, rawbooleantype, emptytype, "valsub", "issubval", 4, false)+
						"\n          booleanval = booleanval || issubval"+lang.lineend+
						"\n        }") +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", booleantype, 4, ":new") +
				"\n        work.vxboolean = booleanval" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      } else if (booleanval) {" +
				"\n        output = " + LangPkgNameDot(lang, "vx/core") + "c_true" + lang.lineend +
				"\n      } else {" +
				"\n        output = " + LangPkgNameDot(lang, "vx/core") + "c_false" + lang.lineend +
				"\n      }"
		case "vx/core/decimal":
			valcopy += "" +
				LangVar(lang, "sval", rawstringtype, 3, "value.vx_string()")
			valnew = "" +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
				"\n          msgblock = " + LangPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
				"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
				"\n          msgblock = " + LangPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
				LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          sval = valstring.vx_string()" + lang.lineend +
				LangElseIfType(lang, rawstringtype, emptytype, "valsub", "svalsub", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          sval = svalsub" + lang.lineend +
				"\n        }" +
				"\n      }" +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", decimaltype, 4, ":new") +
				"\n        work.vxdecimal = sval" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      }"
		case "vx/core/float":
			valcopy += "" +
				LangVar(lang, "floatval", rawfloattype, 3, "value.vx_float()")
			valnew = "" +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
				"\n          msgblock = " + LangPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
				"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
				"\n          msgblock = " + LangPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
				LangElseIfType(lang, decimaltype, emptytype, "valsub", "valdecimal", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += valdecimal.vx_float()" + lang.lineend +
				LangElseIfType(lang, floattype, emptytype, "valsub", "valfloat", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += valfloat.vx_float()" + lang.lineend +
				LangElseIfType(lang, inttype, emptytype, "valsub", "valint", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += valint.vx_int()" + lang.lineend +
				LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += " + LangVxFloatFromString(lang, "valstring.vx_string()") + lang.lineend +
				LangElseIfType(lang, rawfloattype, emptytype, "valsub", "fval", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += fval" + lang.lineend +
				LangElseIfType(lang, rawintegertype, emptytype, "valsub", "ival", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += ival" + lang.lineend +
				LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 4, false) +
				"\n          ischanged = true" + lang.lineend +
				"\n          floatval += " + LangVxFloatFromString(lang, "sval") + lang.lineend +
				"\n        }" +
				"\n      }" +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", floattype, 4, ":new") +
				"\n        work.vxfloat = floatval" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      }"
		case "vx/core/int":
			valcopy += "" +
				LangVar(lang, "intval", rawinttype, 3, "value.vx_int()")
			valnew = "" +
				LangForList(lang, "valsub", rawobjecttype, "vals", 3,
					"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						LangElseIfType(lang, inttype, emptytype, "valsub", "valint", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          intval += valint.vx_int()"+lang.lineend+
						LangElseIfType(lang, rawintegertype, emptytype, "valsub", "ival", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          intval += ival"+lang.lineend+
						LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          intval += "+LangVxIntFromString(lang, "sval")+lang.lineend+
						"\n        }") +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", inttype, 4, ":new") +
				"\n        work.vxint = intval" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      }"
		case "vx/core/msg":
		case "vx/core/msgblock":
		case "vx/core/string":
			vxappend := ""
			switch lang {
			case langcsharp:
				vxappend = ".Append"
				valcopy += "" +
					"\n      System.Text.StringBuilder sb = new System.Text.StringBuilder(value.vx_string())" + lang.lineend
			case langjava:
				vxappend = ".append"
				valcopy += "" +
					"\n      StringBuilder sb = new StringBuilder(value.vx_string())" + lang.lineend
			case langkotlin:
				vxappend = ".append"
				valcopy += "" +
					"\n      var sb : kotlin.text.StringBuilder = StringBuilder(value.vx_string())"
			}
			valnew = "" +
				LangVar(lang, "msg", msgtype, 3, "") +
				LangForList(lang, "valsub", rawobjecttype, "vals", 3,
					"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
						LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 4, false)+
						LangVar(lang, "ssub", rawstringtype, 5, "valstring.vx_string()")+
						"\n          if ("+LangVxEqualsString(lang, "ssub", "\"\"")+") {"+
						"\n          } else {"+
						LangVarSet(lang, "ischanged", 6, "true")+
						"\n            sb"+vxappend+"(ssub)"+lang.lineend+
						"\n          }"+
						LangElseIfType(lang, inttype, emptytype, "valsub", "valint", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          sb"+vxappend+"(valint.vx_int())"+lang.lineend+
						LangElseIfType(lang, floattype, emptytype, "valsub", "valfloat", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          sb"+vxappend+"(valfloat.vx_float())"+lang.lineend+
						LangElseIfType(lang, decimaltype, emptytype, "valsub", "valdecimal", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          sb"+vxappend+"(valdecimal.vx_string())"+lang.lineend+
						LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 4, false)+
						"\n          if ("+LangVxEqualsString(lang, "sval", "\"\"")+") {"+
						"\n          } else {"+
						LangVarSet(lang, "ischanged", 6, "true")+
						"\n            sb"+vxappend+"(sval)"+lang.lineend+
						"\n          }"+
						LangElseIfType(lang, rawintegertype, emptytype, "valsub", "ival", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          sb"+vxappend+"(ival)"+lang.lineend+
						LangElseIfType(lang, rawfloattype, emptytype, "valsub", "fval", 4, false)+
						LangVarSet(lang, "ischanged", 5, "true")+
						"\n          sb"+vxappend+"(fval)"+lang.lineend+
						LangElseIfType(lang, anytype, emptytype, "valsub", "anysub", 4, false)+
						"\n          msg = "+LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidtype\", anysub)"+lang.lineend+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)"+lang.lineend+
						"\n        } else {"+
						"\n          msg = "+LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidtype\", "+LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVxToString(lang, "valsub")+"))"+lang.lineend+
						"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)"+lang.lineend+
						"\n        }") +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVar(lang, "vxstring", rawstringtype, 4,
					LangVxToString(lang, "sb")) +
				LangVarClass(lang, "work", stringtype, 4, ":new") +
				"\n        work.vxstring = vxstring" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				"\n        output = work" + lang.lineend +
				"\n      }"
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
				LangVarCollection(lang, "listval", rawlisttype, allowtype, 3,
					LangVxNewList(lang, allowtype, "value.vx_list"+allowname+"()"))
			switch typ.name {
			case "msgblocklist":
				valnew = "" +
					LangVar(lang, "msg", msgtype, 3, "") +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					LangIf(lang, 4,
						LangIsType(lang, "valsub", msgtype),
						LangVarSet(lang, "msgblock", 5,
							LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"))
			case "msglist":
				valnew = "" +
					LangVar(lang, "msg", msgtype, 3, "") +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					LangIf(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, "msgblock", 5,
							LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"))
			default:
				valnew = "" +
					LangVar(lang, "msg", msgtype, 3, "") +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					LangIf(lang, 4,
						LangIsType(lang, "valsub", msgblocktype),
						LangVarSet(lang, "msgblock", 5,
							LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)")) +
					LangIfElseIf(lang, 4,
						LangIsType(lang, "valsub", msgtype),
						LangVarSet(lang, "msgblock", 5,
							LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"))
			}
			valnew += "" +
				LangElseIfType(lang, typ, emptytype, "valsub", "multi", 4, false) +
				LangVarSet(lang, "ischanged", 5, "true") +
				LangVxListAddList(lang, "listval", 5, "multi.vx_list"+allowname+"()")
			switch typ.name {
			case "msgblocklist", "msglist":
			default:
				valnew += "" +
					LangElseIfType(lang, allowtype, emptytype, "valsub", "allowsub", 4, false) +
					LangVarSet(lang, "ischanged", 5, "true") +
					LangVxListAdd(lang, "listval", 5, "allowsub")
			}
			for _, allowedtype := range typ.allowtypes {
				allowedtypename := LangTypeName(lang, allowedtype)
				castval := LangAsType(lang, "valsub", allowedtype)
				if allowedtypename == allowclass {
					switch NameFromType(allowedtype) {
					case "vx/core/boolean":
						switch lang {
						case langcsharp:
							allowedtypename = "bool"
						default:
							allowedtypename = "Boolean"
						}
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, booleantype) + ", valsub)"
					case "vx/core/int":
						switch lang {
						case langcsharp:
							allowedtypename = "int"
						case langkotlin:
							allowedtypename = "Int"
						default:
							allowedtypename = "Integer"
						}
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, inttype) + ", valsub)"
					case "vx/core/float":
						switch lang {
						case langcsharp:
							allowedtypename = "float"
						default:
							allowedtypename = "Float"
						}
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, floattype) + ", valsub)"
					case "vx/core/string":
						switch lang {
						case langcpp:
							allowedtypename = "std::string"
						case langcsharp:
							allowedtypename = "string"
						default:
							allowedtypename = "String"
						}
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, stringtype) + ", valsub)"
					}
				}
				if allowedtypename == "" {
				} else if allowedtype.name == "any" {
				} else {
					valnew += "" +
						"\n        } else if (" + LangIsTypeText(lang, "valsub", allowedtypename) + ") {" +
						LangVarSet(lang, "ischanged", 5, "true") +
						LangVxListAdd(lang, "listval", 5, castval)
				}
			}
			elseiflistany := ""
			switch lang {
			case langcsharp:
				elseiflistany = "" +
					LangElseIfType(lang, rawlistanytype, emptytype, "valsub", "listany", 4, false) +
					LangForListHeader(lang, "item", anytype, "listany", 5) +
					LangIf(lang, 6, "false", "") +
					LangElseIfType(lang, allowtype, emptytype, "item", "valitem", 6, false) +
					LangVarSet(lang, "ischanged", 7, "true") +
					LangVxListAdd(lang, "listval", 7, "valitem") +
					"\n            }" +
					"\n          }"
			case langjava, langkotlin:
				elseiflistany = "" +
					LangElseIfType(lang, rawlistunknowntype, emptytype, "valsub", "listunknown", 4, false) +
					LangForListHeader(lang, "item", rawobjecttype, "listunknown", 5) +
					LangIf(lang, 6, "false", "") +
					LangElseIfType(lang, allowtype, emptytype, "item", "valitem", 6, false) +
					LangVarSet(lang, "ischanged", 7, "true") +
					LangVxListAdd(lang, "listval", 7, "valitem") +
					"\n            }" +
					"\n          }"
			}
			valnew += "" +
				elseiflistany +
				LangElseIfType(lang, anytype, emptytype, "valsub", "anyinvalid", 4, false) +
				LangVarSet(lang, "msg", 5,
					LangPkgNameDot(lang, "vx/core")+
						"vx_msg_from_error(\""+
						typepath+
						"\", \":invalidtype\", anyinvalid)") +
				LangVarSet(lang, "msgblock", 5,
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy(msgblock, msg)") +
				"\n        } else {" +
				LangVarSet(lang, "msg", 5,
					LangPkgNameDot(lang, "vx/core")+
						"vx_msg_from_error(\""+
						typepath+
						"\", \":invalidtype\", "+
						LangPkgNameDot(lang, "vx/core")+
						"vx_new_string("+
						LangVxToString(lang, "valsub")+
						"))") +
				LangVarSet(lang, "msgblock", 5,
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy(msgblock, msg)") +
				"\n        }" +
				"\n      }" +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", typ, 4, ":new") +
				"\n        work.vx_p_list = " + LangPkgNameDot(lang, "vx/core") + "immutablelist(listval)" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				LangVarSet(lang, "output", 4, "work") +
				"\n      }"
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
				LangVarCollection(lang, "mapval", rawmaptype, allowtype, 3,
					LangVxNewMap(lang, allowtype, "value.vx_map"+allowname+"()"))
			valnew = "" +
				LangVar(lang, "key", rawstringtype, 3, "\"\"") +
				LangVar(lang, "msg", msgtype, 3, LangTypeE(lang, msgtype)) +
				LangVar(lang, "msgval", anytype, 3, LangTypeE(lang, anytype)) +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
				LangVarSet(lang, "msgblock", 5,
					LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)") +
				"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
				LangVarSet(lang, "msgblock", 5,
					LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)") +
				"\n        } else if (" + LangVxEqualsString(lang, "key", "\"\"") + ") {" +
				"\n          if (false) {" +
				LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 5, false) +
				LangVarSet(lang, "key", 6, "valstring.vx_string()") +
				LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false) +
				LangVarSet(lang, "key", 6, "sval") +
				"\n          } else {" +
				"\n            if (false) {" +
				LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 6, false) +
				LangVarSet(lang, "msgval", 7, "valinvalid") +
				"\n            } else {" +
				LangVarSet(lang, "msgval", 7,
					LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVxToString(lang, "valsub")+")") +
				"\n            }" +
				LangVarSet(lang, "msg", 6,
					LangPkgNameDot(lang, "vx/core")+
						"vx_msg_from_error(\""+
						typepath+
						"\", \":keyexpected\", msgval)") +
				LangVarSet(lang, "msgblock", 6,
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy(msgblock, msg)") +
				"\n          }" +
				"\n        } else {" +
				LangVar(lang, "valany", allowtype, 5, LangTypeE(lang, allowtype)) +
				"\n          if (false) {" +
				LangElseIfType(lang, allowtype, emptytype, "valsub", "valallowed", 5, false) +
				LangVarSet(lang, "valany", 6, "valallowed")
			for _, allowedtype := range typ.allowtypes {
				allowedtypename := LangTypeName(lang, allowedtype)
				castval := LangAsType(lang, "valsub", allowedtype)
				if allowedtypename == allowclass {
					switch NameFromType(allowedtype) {
					case "vx/core/boolean":
						allowedtype = rawbooltype
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, booleantype) + ", valsub)"
					case "vx/core/int":
						allowedtype = rawintegertype
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, inttype) + ", valsub)"
					case "vx/core/float":
						allowedtype = rawfloattype
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, floattype) + ", valsub)"
					case "vx/core/string":
						allowedtype = rawstringtype
						castval = LangPkgNameDot(lang, "vx/core") + "vx_new(" + LangTypeT(lang, stringtype) + ", valsub)"
					}
				}
				if allowedtypename != "" {
					valnew += "" +
						//	LangElseIfType(lang, allowedtype, emptytype, "valsub", "valany", 5, false)
						"\n          } else if (" + LangIsType(lang, "valsub", allowedtype) + ") {" +
						LangVarSet(lang, "valany", 6, castval)
				}
			}
			valnew += "" +
				"\n          } else {" +
				"\n            if (false) {" +
				LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 6, false) +
				LangVarSet(lang, "msgval", 7, "valinvalid") +
				"\n            } else {" +
				LangVarSet(lang, "msgval", 7, LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVxToString(lang, "valsub")+")") +
				"\n            }" +
				LangVarCollection(lang, "mapany", rawmaptype, anytype, 6, LangVxNewMap(lang, anytype, "")) +
				"\n            mapany.put(\"key\", " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(key))" + lang.lineend +
				"\n            mapany.put(\"value\", msgval)" + lang.lineend +
				LangVar(lang, "msgmap", maptype, 6,
					LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)") +
				LangVarSet(lang, "msg", 6,
					LangPkgNameDot(lang, "vx/core")+
						"vx_msg_from_error(\""+
						typepath+"\", \":invalidkeyvalue\", msgmap)") +
				LangVarSet(lang, "msgblock", 6,
					LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)") +
				"\n          }" +
				"\n          if (valany != " + LangTypeE(lang, anytype) + ") {" +
				LangVarSet(lang, "ischanged", 6, "true") +
				"\n            if (" + LangVxStartswith(lang, "key", "\":\"") + ") {" +
				LangVarSet(lang, "key", 7,
					LangVxSubstring(lang, "key", "1", "")) +
				"\n            }" +
				"\n            mapval.put(key, valany)" + lang.lineend +
				LangVarSet(lang, "key", 6, "\"\"") +
				"\n          }" +
				"\n        }" +
				"\n      }" +
				"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
				LangVarClass(lang, "work", typ, 4, ":new") +
				"\n        work.vx_p_map = " + LangPkgNameDot(lang, "vx/core") + "immutablemap(mapval)" + lang.lineend +
				"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock" + lang.lineend +
				"\n        }" +
				LangVarSet(lang, "output", 4, "work") +
				"\n      }"
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
					LangVar(lang, "ischanged", rawbooltype, 3, "false") +
					LangVarClass(lang, "value", typ, 3, "this") +
					LangIf(lang, 3,
						"this.vx_constdef() != "+LangTypeE(lang, constdeftype),
						LangVarSet(lang, "ischanged", 4, "true")) +
					LangIfEnd(lang, 3)
			case "vx/core/msgblock":
				valcopy = "" +
					LangVar(lang, "ischanged", rawbooltype, 3, "false") +
					LangVarClass(lang, "value", msgblocktype, 3, "this") +
					LangVar(lang, "msgblock", msgblocktype, 3, "this") +
					LangIf(lang, 3,
						"this.vx_constdef() != "+LangTypeE(lang, constdeftype),
						LangVarSet(lang, "ischanged", 4, "true")) +
					LangIfEnd(lang, 3)
			}
			props := ListPropertyTraitFromType(typ)
			switch len(props) {
			case 0:
				valnew = "" +
					"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
					LangVarClass(lang, "work", typ, 4, ":new") +
					"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
					"\n          work.vxmsgblock = msgblock" + lang.lineend +
					"\n        }" +
					LangVarSet(lang, "output", 4, "work") +
					"\n      }"
			default:
				validkeys := LangVarCollection(lang, "validkeys", rawlisttype, rawstringtype, 3, ":new")
				valnewswitch := ""
				for _, arg := range props {
					validkeys += LangVxListAdd(lang, "validkeys", 3, "\":"+arg.name+"\"")
					argname := LangFromName(arg.name)
					valcopy += "" +
						LangVar(lang, "vx_p_"+argname, arg.vxtype, 3,
							"value."+argname+"()")
					valcopyend += "" +
						"\n        work.vx_p_" + argname + " = vx_p_" + argname + lang.lineend
					vx_any += "" +
						"\n      case \":" + arg.name + "\":" +
						"\n        output = this." + argname + "()" + lang.lineend +
						"\n        break" + lang.lineend
					argalt := ""
					switch NameFromType(arg.vxtype) {
					case "vx/core/boolean":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawbooleantype),
								LangVarSet(lang, "ischanged", 7, "true")+
									LangVarSet(lang, "vx_p_"+argname, 7,
										LangPkgNameDot(lang, "vx/core")+"vx_new("+LangPkgNameDot(lang, "vx/core")+"t_boolean, valsub)"))
					case "vx/core/int":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawintegertype),
								LangVarSet(lang, "ischanged", 7, "true")+
									LangVarSet(lang, "vx_p_"+argname, 7,
										LangPkgNameDot(lang, "vx/core")+"vx_new("+LangPkgNameDot(lang, "vx/core")+"t_int, valsub)"))
					case "vx/core/float":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawfloattype),
								LangVarSet(lang, "ischanged", 7, "true")+
									LangVarSet(lang, "vx_p_"+argname, 7,
										LangPkgNameDot(lang, "vx/core")+"vx_new("+LangPkgNameDot(lang, "vx/core")+"t_float, valsub)"))
					case "vx/core/string":
						argalt = "" +
							LangIfElseIf(lang, 6,
								LangIsType(lang, "valsub", rawstringtype),
								LangVarSet(lang, "ischanged", 7, "true")+
									LangVarSet(lang, "vx_p_"+argname, 7,
										LangPkgNameDot(lang, "vx/core")+"vx_new("+LangPkgNameDot(lang, "vx/core")+"t_string, valsub)"))
					}
					valnewswitcherr := ""
					switch NameFromType(typ) {
					case "vx/core/msg":
					default:
						valnewswitcherr = "" +
							"\n            } else {" +
							"\n              if (false) {" +
							LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 7, false) +
							LangVarSet(lang, "msgval", 8, "valinvalid") +
							LangIfElse(lang, 7,
								LangVarSet(lang, "msgval", 8,
									LangPkgNameDot(lang, "vx/core")+
										"vx_new_string("+LangVxToString(lang, "valsub")+")")) +
							LangIfEnd(lang, 7) +
							LangVarCollection(lang, "mapany", rawmaptype, anytype, 7,
								LangVxNewMap(lang, anytype, "")) +
							"\n              mapany.put(\"key\", " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + arg.name + "\"))" + lang.lineend +
							"\n              mapany.put(\"value\", msgval)" + lang.lineend +
							LangVar(lang, "msgmap", maptype, 7,
								LangTypeT(lang, anymaptype)+".vx_new_from_map(mapany)") +
							"\n              msg = " + LangPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", msgmap)" + lang.lineend +
							"\n              msgblock = " + LangPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg)" + lang.lineend
					}
					valnewswitch += "" +
						LangIfElseIf(lang, 5,
							LangIfClause(lang, rawstringtype,
								"==", "key", "\":"+arg.name+"\""),
							//"\n          case \":" + arg.name + "\":" +
							"\n            if (valsub == vx_p_"+argname+") {"+
								LangElseIfType(lang, arg.vxtype, emptytype, "valsub", "val"+argname, 6, false)+
								LangVarSet(lang, "ischanged", 7, "true")+
								"\n              vx_p_"+argname+" = val"+argname+lang.lineend+
								argalt+
								valnewswitcherr+
								"\n            }")
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
							LangVarSet(lang, "ischanged", 6, "true")+
								LangVarSet(lang, "vx_p_"+lastargname, 6,
									LangAsType(lang, "valsub", lasttype)))
					switch NameFromType(lastarg.vxtype) {
					case "vx/core/boolean":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawbooleantype),
								LangVarSet(lang, "ischanged", 6, "true")+
									LangVarSet(lang, "vx_p_"+lastargname, 6,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangTypeT(lang, booleantype)+
											", valsub)"))
					case "vx/core/int":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawintegertype),
								LangVarSet(lang, "ischanged", 6, "true")+
									LangVarSet(lang, "vx_p_"+lastargname, 6,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+LangTypeT(lang, inttype)+
											", valsub)"))
					case "vx/core/float":
						defaultkey += "" +
							LangIfElseIf(lang, 5,
								LangIsType(lang, "valsub", rawfloattype),
								LangVarSet(lang, "ischanged", 6, "true")+
									LangVarSet(lang, "vx_p_"+lastargname, 6,
										LangPkgNameDot(lang, "vx/core")+
											"vx_new("+
											LangTypeT(lang, floattype)+
											", valsub)"))
					case "vx/core/string":
						defaultstring += "" +
							LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 6, false) +
							LangVarSet(lang, "ischanged", 7, "true") +
							LangVarSet(lang, "vx_p_"+lastargname, 7, "valstr") +
							LangElseIfType(lang, rawstringtype, emptytype, "valsub", "", 6, false) +
							LangVarSet(lang, "ischanged", 7, "true") +
							LangVarSet(lang, "vx_p_"+lastargname, 7,
								LangPkgNameDot(lang, "vx/core")+
									"vx_new("+
									LangTypeT(lang, stringtype)+
									", valsub)")
					}
					if lastarg.vxtype.extends == ":list" {
						lastargtype := lastarg.vxtype
						for _, allowtype := range lastarg.vxtype.allowtypes {
							defaultkey += "" +
								LangIfElseIf(lang, 5,
									LangIsType(lang, "valsub", allowtype),
									LangVar(lang, "valdefault", allowtype, 6,
										LangAsType(lang, "valsub", allowtype))+
										LangVar(lang, "vallist", lastargtype, 6, "")+
										LangVarSet(lang, "vallist", 6, "vx_p_"+lastargname)+
										LangIf(lang, 6,
											"vallist == null",
											LangVarSet(lang, "vallist", 7,
												LangPkgNameDot(lang, "vx/core")+
													"vx_new("+
													LangTypeT(lang, lastarg.vxtype)+
													", valdefault)"))+
										LangIfElse(lang, 6,
											LangVarSet(lang, "vallist", 7,
												LangPkgNameDot(lang, "vx/core")+
													"vx_copy(vallist, valdefault)"))+
										LangIfEnd(lang, 6)+
										LangVarSet(lang, "ischanged", 6, "true")+
										LangVarSet(lang, "vx_p_"+lastargname, 6, "vallist"))
						}
					}
				}
				switch NameFromType(typ) {
				case "vx/core/msg":
					valnew = "" +
						LangVar(lang, "key", rawstringtype, 3, "\"\"") +
						LangForList(lang, "valsub", rawobjecttype, "vals", 3,
							"\n        if ("+LangVxEqualsString(lang, "key", "\"\"")+") {"+
								"\n          if (false) {"+
								LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false)+
								LangVarSet(lang, "key", 6, "valstr.vx_string()")+
								LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false)+
								LangVarSet(lang, "key", 6, "sval")+
								"\n          }"+
								"\n        } else {"+
								LangIf(lang, 5, "false", "")+
								valnewswitch+
								LangIfEnd(lang, 5)+
								LangVarSet(lang, "key", 5, "\"\"")+
								"\n        }") +
						"\n      if (ischanged) {" +
						LangVarClass(lang, "work", typ, 4, ":new") +
						valcopyend +
						LangVarSet(lang, "output", 4, "work") +
						"\n      }"
				case "vx/core/msgblock":
					valnew = "" +
						LangVar(lang, "key", rawstringtype, 3, "\"\"") +
						LangVar(lang, "msg", msgtype, 3, LangTypeE(lang, msgtype)) +
						LangVar(lang, "msgval", anytype, 3, LangTypeE(lang, anytype)) +
						LangForList(lang, "valsub", rawobjecttype, "vals", 3,
							"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
								"\n          if (valsub != "+LangTypeE(lang, msgblocktype)+") {"+
								"\n            vx_p_msgblocks = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(vx_p_msgblocks, valsub)"+lang.lineend+
								LangVarSet(lang, "ischanged", 6, "true")+
								"\n          }"+
								"\n        } else if ("+LangIsType(lang, "valsub", msgblocklisttype)+") {"+
								"\n          if (valsub != "+LangTypeE(lang, msgblocklisttype)+") {"+
								"\n            vx_p_msgblocks = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(vx_p_msgblocks, valsub)"+lang.lineend+
								LangVarSet(lang, "ischanged", 6, "true")+
								"\n          }"+
								"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
								"\n          if (valsub != "+LangTypeE(lang, msgtype)+") {"+
								"\n            vx_p_msgs = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(vx_p_msgs, valsub)"+lang.lineend+
								LangVarSet(lang, "ischanged", 6, "true")+
								"\n          }"+
								"\n        } else if ("+LangIsType(lang, "valsub", msglisttype)+") {"+
								"\n          if (valsub != "+LangTypeE(lang, msglisttype)+") {"+
								"\n            vx_p_msgs = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(vx_p_msgs, valsub)"+lang.lineend+
								LangVarSet(lang, "ischanged", 6, "true")+
								"\n          }"+
								"\n        } else if ("+LangVxEqualsString(lang, "key", "\"\"")+") {"+
								"\n          if (false) {"+
								LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false)+
								LangVarSet(lang, "key", 6, "valstr.vx_string()")+
								LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false)+
								LangVarSet(lang, "key", 6, "sval")+
								"\n          }"+
								"\n        } else {"+
								LangIf(lang, 5, "false", "")+
								valnewswitch+
								LangIfEnd(lang, 5)+
								LangVarSet(lang, "key", 5, "\"\"")+
								"\n        }") +
						"\n      if (ischanged) {" +
						"\n        if ((" + LangVxListSize(lang, "vx_p_msgs.vx_list()") + " == 0) && (" + LangVxListSize(lang, "vx_p_msgblocks.vx_list()") + " == 1)) {" +
						"\n          output = " + LangVxListGet(lang, "vx_p_msgblocks.vx_listmsgblock()", "0") + lang.lineend +
						"\n        } else {" +
						LangVarClass(lang, "work", typ, 5, ":new") +
						"\n          work.vx_p_msgs = vx_p_msgs" + lang.lineend +
						"\n          work.vx_p_msgblocks = vx_p_msgblocks" + lang.lineend +
						"\n          output = work" + lang.lineend +
						"\n        }" +
						"\n      }"
				default:
					valnew = "" +
						validkeys +
						LangVar(lang, "key", rawstringtype, 3, "\"\"") +
						LangVar(lang, "msg", msgtype, 3, LangTypeE(lang, msgtype)) +
						LangVar(lang, "msgval", anytype, 3, LangTypeE(lang, anytype)) +
						LangForList(lang, "valsub", rawobjecttype, "vals", 3,
							"\n        if ("+LangIsType(lang, "valsub", msgblocktype)+") {"+
								"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
								"\n        } else if ("+LangIsType(lang, "valsub", msgtype)+") {"+
								"\n          msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, valsub)"+lang.lineend+
								"\n        } else if ("+LangVxEqualsString(lang, "key", "\"\"")+") {"+
								LangVar(lang, "istestkey", rawbooltype, 5, "false")+
								LangVar(lang, "testkey", rawstringtype, 5, "\"\"")+
								"\n          if (false) {"+
								LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false)+
								"\n            testkey = valstr.vx_string()"+lang.lineend+
								"\n            istestkey = true"+lang.lineend+
								LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false)+
								"\n            testkey = sval"+lang.lineend+
								"\n            istestkey = true"+lang.lineend+
								defaultkey+
								"\n          } else {"+
								"\n            if (false) {"+
								LangElseIfType(lang, anytype, emptytype, "valsub", "valmsg", 6, false)+
								"\n              msgval = valmsg"+lang.lineend+
								"\n            } else {"+
								"\n              msgval = "+LangPkgNameDot(lang, "vx/core")+"vx_new_string("+LangVxToString(lang, "valsub")+")"+lang.lineend+
								"\n            }"+
								"\n            msg = "+LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidkeytype\", msgval)"+lang.lineend+
								"\n            msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)"+lang.lineend+
								"\n          }"+
								"\n          if (istestkey) {"+
								"\n            if (!"+LangVxStartswith(lang, "testkey", "\":\"")+") {"+
								"\n              testkey = \":\" + testkey"+lang.lineend+
								"\n            }"+
								LangVar(lang, "isvalidkey", rawbooltype, 6,
									LangVxContains(lang, "validkeys", "testkey"))+
								"\n            if (isvalidkey) {"+
								"\n              key = testkey"+lang.lineend+
								defaultstring+
								"\n            } else {"+
								"\n              msgval = "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(testkey)"+lang.lineend+
								"\n              msg = "+LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidkey\", msgval)"+lang.lineend+
								"\n              msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)"+lang.lineend+
								"\n            }"+
								"\n          }"+
								"\n        } else {"+
								LangIf(lang, 5, "false", "")+
								valnewswitch+
								LangIfElse(lang, 5,
									"\n            msgval = "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(key)"+lang.lineend+
										"\n            msg = "+LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidkey\", msgval)"+lang.lineend+
										"\n            msgblock = "+LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)"+lang.lineend)+
								LangIfEnd(lang, 5)+
								"\n          key = \"\""+lang.lineend+
								"\n        }") +
						"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
						LangVarClass(lang, "work", typ, 4, ":new") +
						valcopyend +
						"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
						"\n          work.vxmsgblock = msgblock" + lang.lineend +
						"\n        }" +
						"\n        output = work" + lang.lineend +
						"\n      }"
				}
			}
		default:
			if valnew == "" {
				valnew = "" +
					"\n      if (ischanged || (msgblock != " + LangTypeE(lang, msgblocktype) + ")) {" +
					LangVarClass(lang, "work", typ, 4, ":new") +
					"\n        if (msgblock != " + LangTypeE(lang, msgblocktype) + ") {" +
					"\n          work.vxmsgblock = msgblock" + lang.lineend +
					"\n        }" +
					"\n        output = work" + lang.lineend +
					"\n      }"
			}
		}
		funcvxcopy.isoverride = true
		output = "" +
			LangFuncHeader(lang, typename, funcvxcopy, 2, 0,
				LangVar(lang, "output", typ, 3, "this")+
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
		output = LangFuncHeaderInterface(lang, typename, funcvxempty, 2)
	} else {
		funcvxempty.isoverride = true
		output = "" +
			LangFuncHeader(lang, typename, funcvxempty, 2, 0,
				LangVar(lang, "output", anytype, 3,
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
		output = LangFuncHeaderInterface(lang, prefix, funcvxfuncdef, 2)
	} else {
		funcvxfuncdef.isimplement = true
		output = "" +
			LangFuncHeader(lang, prefix, funcvxfuncdef, 2, 0,
				LangVar(lang, "output", funcdeftype, 3,
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
		castlist := ""
		switch lang {
		case langswift:
			castlist = "self.vx_p_list"
		default:
			castlist = "this.vx_p_list"
		}
		output = "" +
			LangFuncHeader(lang, typename, funcvxlist, 2, 0,
				LangVarCollection(lang, "output", rawlisttype, anytype, 3,
					LangPkgNameDot(lang, "vx/core")+
						"immutablelist("+
						"\n        "+LangVxNewList(lang, anytype, castlist)+
						"\n      )"))
	}
	return output
}

func LangTypeVxMap(lang *vxlang, typ *vxtype) string {
	funcvxmap := NewFunc()
	funcvxmap.name = "vx_map"
	funcvxmap.vxtype = rawmapanytype
	funcvxmap.isimplement = true
	copymap := ""
	switch lang {
	case langcsharp:
		convertmap := ""
		if typ.name == "any" {
			convertmap = "this.vx_p_map"
		} else {
			convertmap = LangPkgNameDot(lang, "vx/core") + "vx_map_from_map<" + LangTypeName(lang, anytype) + ", " + LangTypeName(lang, typ) + ">(this.vx_p_map)"
		}
		copymap = "" +
			LangVarCollection(lang, "anymap", rawmaptype, anytype, 3, convertmap) +
			LangVarCollection(lang, "map", rawmaptype, anytype, 3, "anymap.copy()")
	default:
		copymap = "" +
			LangVarCollection(lang, "map", rawmaptype, anytype, 3,
				LangVxNewMap(lang, anytype, "this.vx_p_map"))
	}
	prefix := LangTypeName(lang, typ)
	output := "" +
		LangFuncHeaderOld(lang, prefix, funcvxmap, false, false) +
		copymap +
		"\n      return " + LangPkgNameDot(lang, "vx/core") + "immutablemap(map)" + lang.lineend +
		"\n    }" +
		"\n"
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
			vx_map += "\n      map.put(\":" + arg.name + "\", this." + argname + "())" + lang.lineend
		}
		funcvxmap.isimplement = true
		output += "" +
			LangFuncHeader(lang, typename, funcvxmap, 2, 0,
				LangVarCollection(lang, "map", rawmaptype, anytype, 3,
					LangVxNewMap(lang, anytype, ""))+
					vx_map+
					LangVarCollection(lang, "output", rawmaptype, anytype, 3,
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
		output = LangFuncHeaderInterface(lang, typename, funcvxmsgblock, 2)
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
		output = LangFuncHeaderInterface(lang, typename, funcvxnew, 2)
	} else {
		funcvxnew.isoverride = true
		vals := "vals"
		switch lang {
		case langkotlin:
			vals = "*vals"
		}
		output = "" +
			LangFuncHeader(lang, typename, funcvxnew, 2, 0,
				LangVar(lang, "output", typ, 3,
					LangPkgNameDot(lang, "vx/core")+
						"vx_copy("+
						LangTypeE(lang, typ)+
						", "+vals+")"))
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
	keyset := ""
	mapget := ""
	switch lang {
	case langcsharp:
		keyset = "\n      List<string> keys = mapval.keys()" + lang.lineend
		mapget = "mapval.get(key)"
	case langjava:
		keyset = "\n      Set<String> keys = mapval.keySet()" + lang.lineend
		mapget = "mapval.get(key)"
	case langkotlin:
		keyset = "\n      val keys : Set<String> = mapval.keys"
		mapget = "mapval.getOrDefault(key, vx_core.e_any)"
	}
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
			LangFuncHeaderInterface(lang, typename, funcvxnewmap, 2)
	} else {
		funcvxnewmap.isimplement = true
		output += "" +
			LangFuncHeader(lang, typename, funcvxnewmap, 2, 0,
				LangVarClass(lang, "output", typ, 3, ":new")+
					LangVar(lang, "msgblock", msgblocktype, 3,
						LangTypeE(lang, msgblocktype))+
					LangVarCollection(lang, "map", rawmaptype, allowtype, 3, LangVxNewMap(lang, allowtype, ""))+
					keyset+
					LangForList(lang, "key", rawstringtype, "keys", 3,
						LangVar(lang, "value", anytype, 4, mapget)+
							"\n        if (false) {"+
							LangElseIfType(lang, allowtype, emptytype, "value", "castval", 4, false)+
							"\n          map.put(key, castval)"+lang.lineend+
							"\n        } else {"+
							LangVar(lang, "msg", msgtype, 5,
								LangPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", value)")+
							LangVarSet(lang, "msgblock", 5,
								LangPkgNameDot(lang, "vx/core")+"vx_copy(msgblock, msg)")+
							"\n        }")+
					"\n      output.vx_p_map = "+LangPkgNameDot(lang, "vx/core")+"immutablemap(map)"+lang.lineend+
					"\n      if (msgblock != "+LangTypeE(lang, msgblocktype)+") {"+
					"\n        output.vxmsgblock = msgblock"+lang.lineend+
					"\n      }")
	}
	return output
}

func LangTypeVxSet(lang *vxlang, typ *vxtype) string {
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
		LangVar(lang, "output", booleantype, 3, LangPkgNameDot(lang, "vx/core")+"c_false") +
		"\n      if (false) {" +
		LangElseIfType(lang, allowtype, emptytype, "value", "castval", 3, false) +
		LangVar(lang, "key", rawstringtype, 4, "name.vx_string()") +
		"\n        if (" + LangVxStartswith(lang, "key", "\":\"") + ") {" +
		LangVarSet(lang, "key", 5, LangVxSubstring(lang, "key", "1", "")) +
		"\n        }" +
		LangVarCollection(lang, "map", rawmaptype, allowtype, 4,
			LangVxNewMap(lang, allowtype, "this.vx_p_map")) +
		"\n        if (castval == " + allowempty + ") {" +
		"\n          map.remove(key)" + lang.lineend +
		"\n        } else {" +
		"\n          map.put(key, castval)" + lang.lineend +
		"\n        }" +
		"\n        this.vx_p_map = " + LangPkgNameDot(lang, "vx/core") + "immutablemap(map)" + lang.lineend +
		LangVarSet(lang, "output", 4, LangPkgNameDot(lang, "vx/core")+"c_true") +
		"\n      }"
	output := "" +
		LangFuncHeader(lang, prefix, funcvxmap, 2, 0, body)
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
		output = LangFuncHeaderInterface(lang, typename, funcvxtype, 2)
	} else {
		funcvxtype.isoverride = true
		output = "" +
			LangFuncHeader(lang, typename, funcvxtype, 2, 0,
				LangVar(lang, "output", anytype, 3,
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
			LangFuncHeader(lang, prefix, funcvxtypedef, 2, 0,
				LangVar(lang, "output", typedeftype, 3,
					LangTypeDef(lang, typ, 3)))
	}
	return output
}
