package vxlisp

import (
	"strings"
)

func LangFunc(
	lang *vxlang,
	fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFunc")
	g_ifuncdepth = 0
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	f_func, msgs := LangFuncFFunc(lang, fnc, false)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	typefnc := NewTypeFromFunc(fnc)
	output := "" +
		LangFuncDoc(lang, fnc) +
		LangFuncInterface(lang, fnc) +
		LangFuncClassHeader(lang, fnc, 1) +
		"\n" +
		LangFuncVxNew(lang, fnc, false) +
		LangFuncVxCopy(lang, fnc, false) +
		LangFuncVxTypedef(lang, fnc, false) +
		LangFuncVxFuncdef(lang, fnc, false) +
		LangFuncVxEmpty(lang, fnc, false) +
		LangFuncVxType(lang, fnc, false) +
		LangFuncInterfaceFn(lang, fnc) +
		LangFuncVxFnNew(lang, fnc, false) +
		LangFuncVxRepl(lang, fnc, false) +
		LangFuncVxFunc(lang, fnc, false) +
		"\n  }" +
		"\n" +
		LangValStatic(lang, "e_"+funcname, typefnc, 1, ":new") +
		LangValStatic(lang, "t_"+funcname, typefnc, 1, ":new") +
		"\n" +
		f_func
	return output, msgblock
}

func LangFuncClass(lang *vxlang, fnc *vxfunc) string {
	name := "Class_" + LangFuncName(fnc)
	return name
}

func LangFuncClassFull(
	lang *vxlang,
	fnc *vxfunc) string {
	name := LangFuncClass(lang, fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncClassHeader(
	lang *vxlang,
	fnc *vxfunc,
	indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	funcname := LangFuncName(fnc)
	extends := LangPkgNameDot(lang, "vx/core") + "Class_base"
	switch lang {
	case langcsharp:
		output = lineindent + "public class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {"
	case langjava:
		output = lineindent + "public static class Class_" + funcname + " extends " + extends + " implements Func_" + funcname + " {"
	case langkotlin:
		output = "" +
			lineindent + "class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangFuncDebug(
	lang *vxlang,
	fnc *vxfunc,
	lineindent string) (string, string) {
	debugstart := ""
	debugend := ""
	if fnc.debug {
		debugstart = lineindent + LangPkgNameDot(lang, "vx/core") + "vx_log(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			debugstart += ", " + LangTypeStringValNew(lang, arg.name+"=") + ", " + LangFromName(arg.alias)
		}
		debugstart += ")" + lang.lineend
		debugend = lineindent + LangPkgNameDot(lang, "vx/core") + "vx_log(\"" + fnc.name + "\", \"end\", output)" + lang.lineend
	}
	return debugstart, debugend
}

func LangFuncDefFromFunc(
	lang *vxlang,
	fnc *vxfunc,
	indent int) string {
	lineindent := "\n" + StringRepeat("  ", indent)
	output := "" +
		LangPkgNameDot(lang, "vx/core") + "funcdef_new(" +
		lineindent + "  \"" + fnc.pkgname + "\", // pkgname" +
		lineindent + "  \"" + fnc.name + "\", // name" +
		lineindent + "  " + StringFromInt(fnc.idx) + ", // idx" +
		lineindent + "  " + StringFromBoolean(fnc.async) + ", // async" +
		lineindent + "  " + LangTypeDef(lang, fnc.vxtype, 4) + " // typedef" +
		lineindent + ")"
	return output
}

func LangFuncDoc(
	lang *vxlang,
	fnc *vxfunc) string {
	doc := ""
	argsdoc := ""
	switch NameFromFunc(fnc) {
	case "vx/core/copy", "vx/core/empty", "vx/core/new":
	default:
		//if fnc.isgeneric {
		//	argsdoc += "\n@param  {generic} generic_any_1"
		//}
	}
	for _, arg := range fnc.listarg {
		argsdoc += "\n@param "
		if arg.vxtype.name != "" {
			argsdoc += " {" + arg.vxtype.name + "}"
		}
		argsdoc += " " + arg.alias
		if arg.doc != "" {
			argsdoc += " " + arg.doc
		}
	}
	if fnc.async {
		doc += "" +
			"\n@async" +
			"\n"
	}
	doc += "@function " + LangFromName(fnc.alias)
	if fnc.idx > 0 {
		doc += " " + StringFromInt(fnc.idx)
	}
	if fnc.doc != "" {
		doc += "\n" + fnc.doc
	}
	if fnc.deprecated != "" {
		doc += "\n" + fnc.deprecated
	}
	doc += "" +
		argsdoc +
		"\n@return {" + fnc.vxtype.name + "}"
	output := "" +
		"  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (func " + fnc.name + ")" +
		"\n   */"
	/// FIXME
	switch lang {
	case langkotlin:
		output = ""
	}
	return output
}

func LangFuncE(
	lang *vxlang,
	fnc *vxfunc) string {
	name := "e_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncF(
	lang *vxlang,
	fnc *vxfunc) string {
	name := "f_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncFFunc(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncVxromFunc")
	var listargtype []string
	var listargname []string
	path := fnc.pkgname + "/" + fnc.name + LangIndexFromFunc(fnc)
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		case "vx/core/any<-any", "vx/core/any<-any-async",
			"vx/core/any<-any-context", "vx/core/any<-any-context-async",
			"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
			"vx/core/any<-int", "vx/core/any<-int-any",
			"vx/core/any<-func", "vx/core/any<-func-async",
			"vx/core/any<-key-value", "vx/core/any<-key-value-async",
			"vx/core/any<-none", "vx/core/any<-none-async",
			"vx/core/any<-reduce", "vx/core/any<-reduce-async",
			"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
			arggeneric := arggenericany1
			argtext := LangArgHeader(lang, arggeneric, true)
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				arggeneric := LangArgGenericFromType(lang, fnc.generictype)
				argtext := LangArgHeader(lang, arggeneric, true)
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, arggeneric.alias)
			}
		}
	}
	if fnc.context {
		argtext := LangArgHeader(lang, argcontext, false)
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "context")
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let":
		argtext := LangPkgNameDot(lang, "vx/core") + "Func_any_from_func fn_any"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any")
	case "vx/core/let-async":
		argtext := LangPkgNameDot(lang, "vx/core") + "Func_any_from_func_async fn_any_async"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any_async")
	default:
		isallowgeneric := false
		if fnc.generictype != nil {
			isallowgeneric = true
		}
		for _, arg := range fnc.listarg {
			argtext := LangArgHeader(lang, arg, isallowgeneric)
			listargname = append(listargname, LangFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	var returntype *vxtype
	//	sreturntype := ""
	if fnc.generictype == nil {
		returntype = fnc.vxtype
		//		sreturntype = LangGenericFromType(lang, fnc.vxtype)
	} else {
		returntype = fnc.generictype
		//		sreturntype = LangGenericFromType(lang, fnc.generictype)
	}
	/*
		functypetext := ""
		if fnc.generictype != nil {
			functypetext = LangGenericFromType(lang, fnc.generictype)
		} else {
			functypetext = sreturntype
		}
		if fnc.async {
			functypetext = lang.future + "<" + functypetext + ">"
		}
	*/
	indent := 2
	subindent := indent
	sindent := "    "
	ssubindent := sindent
	lineindent := "\n" + sindent
	msgtop := ""
	msgbottom := ""
	permissiontop := ""
	permissionbottom := ""
	if fnc.permission {
		permissiontop = lineindent + "if (" + LangPkgNameDot(lang, "vx/core") + "f_boolean_permission_from_func(context, " + LangFuncT(lang, fnc) + ").vx_boolean()) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			LangVar(lang, "msg", msgtype, 3,
				LangPkgNameDot(lang, "vx/core")+
					"vx_msg_from_error(\"vx/core/func\", \":permissiondenied\", "+
					LangPkgNameDot(lang, "vx/core")+
					"vx_new_string(\""+fnc.name+"\"))") +
			LangVarSet(lang, "output", 3, LangPkgNameDot(lang, "vx/core")+"vx_copy(output, msg)") +
			lineindent + "}"
		subindent += 1
		ssubindent += "  "
	}
	linesubindent := "\n" + ssubindent
	if fnc.messages {
		stry := ""
		scatch := ""
		switch lang {
		case langkotlin:
			stry = linesubindent + "try {"
			scatch = linesubindent + "} catch (err : Exception) {"
		default:
			stry = linesubindent + "try {"
			scatch = linesubindent + "} catch (Exception err) {"
		}
		msgtop = stry
		msgbottom = "" +
			scatch +
			LangVar(lang, "msg", msgtype, subindent+1,
				LangPkgNameDot(lang, "vx/core")+
					"vx_msg_from_exception(\""+
					fnc.pkgname+"/"+fnc.name+
					"\", err)") +
			LangVarSet(lang, "output", subindent+1,
				LangPkgNameDot(lang, "vx/core")+"vx_copy(output, msg)") +
			linesubindent + "}"
		subindent += 1
		ssubindent += "  "
	}
	linesubindent = "\n" + ssubindent
	output := ""
	if isinterface {
	} else {
		valuetext, msgs := LangFromValue(
			lang, fnc.value, fnc.pkgname, fnc, 0, true, false, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		debugtop, debugbottom := LangFuncDebug(lang, fnc, lineindent)
		valuetexts := ListStringFromStringSplit(valuetext, "\n")
		var chgvaluetexts []string
		f_suppresswarnings := ""
		for _, item := range valuetexts {
			if BooleanFromStringContains(item, "@SuppressWarnings") {
				f_suppresswarnings += "\n  " + StringTrim(StringFromStringFindReplace(item, "\\\"", "\""))
			} else {
				chgvaluetexts = append(chgvaluetexts, item)
			}
		}
		switch NameFromFunc(fnc) {
		case "vx/core/new":
			switch lang {
			case langjava:
				f_suppresswarnings = "\n  @SuppressWarnings(\"unchecked\")"
			}
		}
		valuetext = StringFromListStringJoin(
			chgvaluetexts, "\n")
		if IntFromStringFind(valuetext, "output ") >= 0 {
		} else if IntFromStringFind(valuetext, "output.") >= 0 {
		} else if fnc.vxtype.name == "none" {
		} else if valuetext == "" {
		} else {
			valuetext = "output = " + valuetext
		}
		if valuetext == "" {
		} else if !BooleanFromStringEnds(valuetext, ";") {
			valuetext += lang.lineend
		}
		if valuetext != "" {
			valuetext = linesubindent + StringFromStringIndent(
				valuetext, ssubindent)
		}
		defaultvalue := ""
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			if fnc.async {
				defaultvalue =
					LangVarFutureGeneric(lang, "output", returntype, indent,
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_new_from_value("+
							LangTypeE(lang, fnc.vxtype)+")")
			} else if fnc.generictype != nil {
				defaultvalue =
					LangVarGeneric(lang, "output", returntype, 2,
						LangPkgNameDot(lang, "vx/core")+
							"f_empty("+
							LangTypeTGeneric(lang, fnc.generictype)+
							")")
			} else {
				defaultvalue =
					LangVar(lang, "output", returntype, 2,
						LangTypeE(lang, fnc.vxtype))
			}
		}
		output = "" +
			f_suppresswarnings +
			LangFuncFFuncHelper(lang, fnc, false, ""+
				debugtop+
				defaultvalue+
				permissiontop+
				msgtop+
				valuetext+
				msgbottom+
				permissionbottom+
				debugbottom)
	}
	return output, msgblock
}

func LangFuncFFuncHelper(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool,
	sbody string) string {
	funcname := "f_" + LangFuncName(fnc)
	funcf := NewFuncCopy(fnc)
	funcf.pkgname = ""
	funcf.name = funcname
	funcf.alias = funcname
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcf, 2)
	} else {
		body := sbody
		output = "" +
			LangFuncHeaderStatic(lang, "", funcf, 1, 0, body) +
			"\n"
	}
	return output
}

func LangFuncFunc(
	lang *vxlang,
	fnc *vxfunc) string {
	name := "Func_" + LangFuncName(fnc)
	return name
}

func LangFuncFuncFull(
	lang *vxlang,
	fnc *vxfunc) string {
	name := LangFuncFunc(lang, fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncGenericDefinition(
	lang *vxlang,
	fnc *vxfunc) (string, string, string) {
	output1 := ""
	output2 := ""
	output3 := ""
	var mapgeneric = make(map[string]string)
	if fnc.generictype != nil {
		returntype := ""
		typename := ""
		switch fnc.generictype {
		case rawlisttype1, rawmaptype1:
			typename = LangNameTypeFromTypeSimple(lang, anytype, true)
			returntype = "T"
		default:
			typename = LangNameTypeFromTypeSimple(
				lang, fnc.vxtype, true)
			returntype = LangGenericFromType(
				lang, fnc.generictype)
		}
		mapgeneric[returntype] = returntype + " " + lang.classext + " " + typename
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !argtype.isfunc {
				if argtype.isgeneric {
					arggenericname := ""
					argtypename := ""
					switch argtype {
					case rawlisttype1, rawmaptype1:
						arggenericname = "T"
						argtypename = LangNameTypeFromTypeSimple(
							lang, anytype, true)
					default:
						arggenericname = LangGenericFromType(
							lang, argtype)
						argtypename = LangNameTypeFromTypeSimple(
							lang, arg.vxtype, true)
					}
					_, ok := mapgeneric[arggenericname]
					if !ok {
						worktext := arggenericname + " " + lang.classext + " " + argtypename
						mapgeneric[arggenericname] = worktext
					}
				}
			}
		}
		generickeys := ListStringKeysFromStringMap(mapgeneric)
		switch lang {
		case langcsharp:
			for _, generickey := range generickeys {
				if output2 != "" {
					output2 += ", "
				}
				output2 += generickey
				output3 += " where " + mapgeneric[generickey]
			}
			output2 = "<" + output2 + ">"
		default:
			for _, generickey := range generickeys {
				if output1 != "" {
					output1 += ", "
				}
				output1 += mapgeneric[generickey]
			}
			output1 = "<" + output1 + "> "
		}
	}
	return output1, output2, output3
}

func LangFuncHeader(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	indent int,
	outputnum int,
	value string) string {
	return LangFuncHeaderAll(
		lang, prefix, fnc, indent, false, false, outputnum, value)
}

func LangFuncHeaderOld(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	isinterface bool,
	isstatic bool) string {
	return LangFuncHeaderAll(
		lang, prefix, fnc, 2, isinterface, isstatic, 0, "")
}

func LangFuncHeaderAll(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	indent int,
	isinterface bool,
	isstatic bool,
	outputnum int,
	value string) string {
	output := ""
	funcname := LangFromName(fnc.alias)
	if funcname == "" {
		funcname = LangFuncName(fnc)
	}
	funcinstance, funcstatic := LangFuncInstanceStatic(lang)
	funcdeclare := funcinstance
	if isstatic {
		funcdeclare = funcstatic
	}
	returntype := LangNameTypeFullFromTypeSimple(
		lang, fnc.vxtype, false)
	isreturngeneric := fnc.vxtype.isgeneric
	var listargtext []string
	if fnc.generictype != nil {
		returntype = LangGenericFromType(
			lang, fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty",
			"f_new", "f_copy", "f_empty":
		default:
			arggeneric := NewArg(
				"generic-" + fnc.generictype.name)
			arggeneric.vxtype = fnc.generictype
			argtext := LangArgHeader(
				lang, arggeneric, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	if fnc.context {
		argtext := LangArgHeader(
			lang, argcontext, isreturngeneric)
		listargtext = append(listargtext, argtext)
	}
	for _, arg := range fnc.listarg {
		argname := LangFromName(arg.alias)
		isskip := false
		switch NameFromFunc(fnc) {
		case "vx/core/let", "vx/core/let-async",
			"f_let", "f_let_async":
			// args is not included in let
			if argname == "args" {
				isskip = true
			}
		}
		if !isskip {
			argtext := LangArgHeader(
				lang, arg, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	argtext := StringFromListStringJoin(
		listargtext, ", ")
	genericdef1, genericdef2, genericdef3 := LangFuncGenericDefinition(
		lang, fnc)
	override1 := ""
	override2 := ""
	override3 := ""
	sindent := "\n" + StringRepeat("  ", indent)
	if fnc.isoverride {
		switch lang {
		case langcsharp:
			override3 = "override "
		case langjava:
			override1 = sindent + "@Override"
		case langkotlin:
			override2 = "override "
		}
	}
	if fnc.isimplement {
		switch lang {
		case langjava:
			override1 = sindent + "@Override"
		case langkotlin:
			override2 = "override "
		}
	}
	if fnc.isimplement2 {
		switch lang {
		case langcsharp:
			override3 = sindent + "new "
		}
	}
	sinterface := ""
	sopen := ""
	sclose := ""
	sreturn := ""
	if isinterface {
		sinterface = lang.lineend
	} else {
		sopen = " {"
		if value != "" {
			soutput := "output"
			if outputnum > 0 {
				soutput += "_" + StringFromInt(outputnum)
			}
			switch returntype {
			case "Unit", "void":
			default:
				sreturn = sindent + "  return " + soutput + lang.lineend
			}
			sclose = sindent + "}\n"
		}
	}
	funcprefix := ""
	switch lang {
	case langcpp:
		funcprefix = prefix + "::"
	}
	if fnc.async {
		returntype = lang.future + "<" + returntype + ">"
	}
	returntype1 := ""
	returntype2 := ""
	switch lang {
	case langcpp, langcsharp, langjava:
		returntype1 = returntype + " "
	case langkotlin:
		returntype2 = " : " + returntype
	case langswift:
		returntype2 = " -> " + returntype
	}
	output = "" +
		override1 +
		sindent + override2 + funcdeclare + override3 + genericdef1 + returntype1 + funcprefix + funcname + genericdef2 + "(" + argtext + ")" + returntype2 + genericdef3 + sinterface + sopen +
		value +
		sreturn +
		sclose
	return output
}

func LangFuncHeaderInterface(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	indent int) string {
	output := LangFuncHeaderAll(
		lang, prefix, fnc, indent, true, false, 0, "")
	return output
}

func LangFuncHeaderStatic(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	indent int,
	outputnum int,
	value string) string {
	return LangFuncHeaderAll(
		lang, prefix, fnc, indent, false, true, outputnum, value)
}

func LangFuncIFnType(
	lang *vxlang,
	fnc *vxfunc) *vxtype {
	output := emptytype
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
		"vx/core/any<-int", "vx/core/any<-int-any",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async",
		"vx/core/boolean<-any":
		output = NewType(LangFuncName(fnc) + lang.typeref + "IFn")
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		output = NewType("vx/core/any<-func" + lang.typeref + "IFn")
	}
	return output
}

func LangFuncInstanceStatic(
	lang *vxlang) (string, string) {
	funcinstance := "function "
	funcstatic := "function "
	switch lang {
	case langcpp, langcsharp, langjava:
		funcinstance = "public "
		funcstatic = "public static "
	case langkotlin:
		funcinstance = "fun "
		funcstatic = "fun "
	case langswift:
		funcinstance = "func "
		funcstatic = "func static "
	}
	return funcinstance, funcstatic
}

func LangFuncInterface(
	lang *vxlang,
	fnc *vxfunc) string {
	output := "" +
		LangFuncInterfaceHeader(lang, fnc, 1,
			LangFuncVxFunc(lang, fnc, true))
	return output
}

func LangFuncInterfaceHeader(
	lang *vxlang,
	fnc *vxfunc,
	indent int,
	body string) string {
	lineindent := LangIndent(lang, indent, true)
	output := ""
	extends := ""
	interfaces := body
	funcname := LangFuncName(fnc)
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-int-any",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async",
		"vx/core/any<-int",
		"vx/core/boolean<-any",
		"vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = LangPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += LangFuncVxFnNew(lang, fnc, true)
	case "vx/core/none<-any":
	default:
		if extends == "" {
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				extends = LangPkgNameDot(lang, "vx/core") + "Type_func"
			default:
				switch len(fnc.listarg) {
				case 1:
					extends = LangPkgNameDot(lang, "vx/core") + "Func_any_from_any"
					if fnc.context {
						extends += "_context"
					}
					if fnc.async {
						extends += "_async"
					}
				default:
					extends = LangPkgNameDot(lang, "vx/core") + "Type_func"
				}
			}
		}
	}
	if extends == LangPkgNameDot(lang, "vx/core")+"Type_func" {
		if fnc.async {
			extends += ", " + LangPkgNameDot(lang, "vx/core") + "Type_replfunc_async"
		} else {
			extends += ", " + LangPkgNameDot(lang, "vx/core") + "Type_replfunc"
		}
	}
	switch lang {
	case langcsharp:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case langjava:
		if extends != "" {
			extends = " extends " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case langkotlin:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	}
	return output
}

func LangFuncLambda(
	lang *vxlang,
	indent int,
	outputnum int,
	bindings string,
	args string,
	body string) string {
	output := "" +
		LangFuncLambdaHeader(lang, indent, outputnum, bindings, args) +
		body +
		LangFuncLambdaFooter(lang, indent, outputnum)
	return output
}

func LangFuncLambdaFooter(
	lang *vxlang,
	indent int,
	outputnum int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	sreturn := ""
	lineend := lineindent + "}"
	if outputnum >= 0 {
		switch lang {
		case langkotlin:
			sreturn = lineindent + "  output"
			if outputnum > 0 {
				sreturn += "_" + StringFromInt(outputnum)
			}
		default:
			sreturn = lineindent + "  return output"
			if outputnum > 0 {
				sreturn += "_" + StringFromInt(outputnum)
			}
			sreturn += lang.lineend
		}
	}
	output = "" +
		sreturn +
		lineend
	return output
}

func LangFuncLambdaHeader(
	lang *vxlang,
	indent int,
	outputnum int,
	bindings string,
	args string) string {
	output := ""
	switch lang {
	case langcpp:
		output = "[" + bindings + "](" + args + ") -> {"
	case langcsharp:
		output = "(" + args + ") => {"
	case langjava:
		output = "(" + args + ") -> {"
	case langkotlin:
		output = "{" + args + " ->"
	}
	return output
}

func LangFuncName(fnc *vxfunc) string {
	output := LangFromName(fnc.alias)
	if output == "" {
		output = LangFromName(fnc.name)
	}
	output += LangIndexFromFunc(fnc)
	return output
}

func LangFuncT(lang *vxlang, fnc *vxfunc) string {
	name := "t_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncLambdaArgIndex(
	lang *vxlang,
	listarglambda []vxarg,
	indexarglambda int,
	isstart bool,
	pkgname string,
	fnc *vxfunc,
	argvalue vxvalue,
	indent int,
	test bool,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncLambdaArgIndex")
	output := ""
	if indexarglambda < len(listarglambda) {
		lambdaarg := listarglambda[indexarglambda]
		argsubpath := path + "/:arg/" + lambdaarg.name
		slambdavars := ""
		ioutputnum := 0
		outputname := ""
		sanyfromfunc := ""
		sreturnoutput := ""
		iswrapped := isstart
		if iswrapped {
			g_ifuncdepth += 1
			ioutputnum = g_ifuncdepth
			outputname = "output_" + StringFromInt(ioutputnum)
			listarg := fnc.listarg
			lastarg := listarg[len(listarg)-1]
			if fnc.async {
				sanyfromfunc = LangPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref
			} else {
				sanyfromfunc = LangPkgNameDot(lang, "vx/core") + "t_any_from_func" + lang.typeref
				sfncvalue, msgs := LangFromValue(lang, lastarg.value, pkgname, fnc, indent+1, true, test, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				sreturnoutput = LangVar(lang, outputname, anytype, indent+1, sfncvalue)
			}
		}
		if lambdaarg.async {
			lastoutputnum := g_ifuncdepth
			lastoutputname := "output_" + StringFromInt(lastoutputnum)
			listarg := fnc.listarg
			lastarg := listarg[len(listarg)-1]
			sfncvalue, msgs := LangFromValue(lang, lastarg.value, pkgname, fnc, indent+2, true, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			g_ifuncdepth += 1
			ioutputargnum := g_ifuncdepth
			outputname := "output_" + StringFromInt(ioutputargnum)
			lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, indent+1, true, test, argsubpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			svalueoutput := LangVar(lang, outputname, anytype, indent+2, sfncvalue)
			slambdarest := ""
			work, msgs := LangFuncLambdaArgIndex(lang, listarglambda, indexarglambda+1, false, pkgname, fnc, argvalue, indent+1, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest = work
			sfuturevar := LangVarFuture(lang, "future_"+LangFromName(lambdaarg.name), lambdaarg.vxtype, indent+1,
				lambdavaluetext)
			lambdaargname := LangFromName(lambdaarg.name)
			/*
				switch lang {
				case langkotlin:
					lambdaargname += " : vx_core.Type_any"
				}
			*/
			slambdaoutput := "" +
				LangFuncLambda(lang, indent+1, ioutputargnum, "", lambdaargname,
					slambdarest+
						svalueoutput)
			sfutureoutput := "" +
				LangVarFuture(lang, lastoutputname, anytype, indent+1,
					LangPkgNameDot(lang, "vx/core")+
						"vx_async_from_async_fn(future_"+
						LangFromName(lambdaarg.name)+
						", "+
						slambdaoutput+
						")")
			slambdavars += "" +
				sfuturevar +
				sfutureoutput
		} else {
			lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, indent+1, true, test, argsubpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest := ""
			work, msgs := LangFuncLambdaArgIndex(lang, listarglambda, indexarglambda+1, false, pkgname, fnc, argvalue, indent, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest = work
			slambdavar := LangVar(lang, LangFromName(lambdaarg.name), lambdaarg.vxtype, indent+1,
				lambdavaluetext)
			slambdavars +=
				slambdavar +
					slambdarest
		}
		if iswrapped {
			lambda := LangFuncLambda(lang, indent, ioutputnum, "", "",
				slambdavars+
					sreturnoutput)
			output = "" +
				sanyfromfunc + "vx_fn_new(" + lambda + ")"
		} else {
			output = slambdavars
		}
	}
	return output, msgblock
}

func LangFuncValue(
	lang *vxlang,
	fnc *vxfunc,
	pkgname string,
	parentfn *vxfunc,
	indent int,
	encode bool,
	test bool,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncValue")
	body := ""
	sindent := StringRepeat("  ", indent)
	subpath := path + "/" + fnc.name
	funcname := NameFromFunc(fnc)
	output := ""
	logopen := ""
	logclose := ""
	if fnc.debug {
		logopen += "" +
			LangPkgName(lang, "vx/core") + lang.pkgref + "f_log_1(" +
			LangTypeT(lang, fnc.vxtype) + ", " +
			LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_string(\"" + funcname + "\")," +
			"\n"
		logclose += "\n)"
	}
	switch fnc.name {
	case "native":
		snative, msgs := LangFuncValueNative(
			lang,
			fnc,
			pkgname,
			parentfn,
			indent,
			test,
			subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output =
			logopen +
				snative +
				logclose
	default:
		funcopen := ""
		funcclose := ""
		var listargtext []string
		funcargs := fnc.listarg
		isskip := false
		multiline := false
		multiflag := false
		switch funcname {
		case "vx/core/any<-struct":
			propvalue := funcargs[1].value
			switch propvalue.code {
			case "string":
				propname := StringValueFromValue(propvalue)
				if BooleanFromStringStarts(propname, ":") {
					propname = propname[1:]
				}
				structvalue := funcargs[0].value
				work, msgs := LangFromValue(lang, structvalue, pkgname, fnc, 0, true, test, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				work = work + lang.typeref + LangFromName(propname) + "()"
				listargtext = append(listargtext, work)
				isskip = true
			}
		case "vx/core/fn":
		case "vx/core/let":
			if fnc.async {
				funcopen = LangPkgName(lang, fnc.pkgname) + lang.pkgref + "f_let_async("
			} else {
				funcopen = LangPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangFuncName(fnc) + "("
			}
			funcclose = ")"
		default:
			if fnc.argname != "" {
				funcopen = LangPkgNameDot(lang, "vx/core") + "vx_any_from_func("
				listargtext = append(listargtext, LangTypeT(lang, fnc.vxtype))
				listargtext = append(listargtext, LangFromName(fnc.argname))
				switch lang {
				case langcpp:
					multiflag = true
				}
			} else {
				funcopen = LangPkgNameDot(lang, fnc.pkgname) + "f_" + LangFuncName(fnc) + "("
			}
			funcclose = ")"
		}
		if !isskip {
			multiline = true
			if fnc.isgeneric {
				switch funcname {
				case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
				default:
					if fnc.generictype != nil {
						genericarg := LangTypeTGeneric(lang, fnc.vxtype)
						listargtext = append(listargtext, genericarg)
					}
				}
			}
			if fnc.context {
				listargtext = append(listargtext, "context")
			}
			for argidx, arg := range fnc.listarg {
				sargvalue, msgs := LangFuncValueArgIndex(lang, fnc, pkgname, argidx, 0, test, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if arg.multi {
					ismultiarg := false
					if arg.value.code == ":arg" {
						argvaluearg := ArgFromValue(arg.value)
						if argvaluearg.multi {
							ismultiarg = true
						} else if arg.vxtype == argvaluearg.vxtype {
							ismultiarg = true
						}
					}
					if ismultiarg {
					} else if multiflag {
						sargvalue = "  " + StringFromStringIndent(sargvalue, "  ")
					} else {
						multiflag = true
						sargvalue = "" +
							LangPkgNameDot(lang, "vx/core") + "vx_new(" +
							"\n  " + LangTypeT(lang, arg.vxtype) + "," +
							"\n  " + StringFromStringIndent(sargvalue, "  ")
					}
				}
				if sargvalue != "" {
					if IntFromStringFind(sargvalue, "\n") > 0 {
						multiline = true
					}
					listargtext = append(listargtext, sargvalue)
				}
			}
		}
		if len(listargtext) == 0 {
		} else if multiline {
			body = "" +
				"\n" + sindent +
				"  " +
				StringFromStringIndent(
					StringFromListStringJoin(listargtext, ",\n"),
					sindent+"  ")
			if multiflag {
				body += "\n" + sindent + "  )"
			}
			switch fnc.name {
			case "fn":
			default:
				funcclose = "\n" + sindent + ")"
			}
		} else {
			body = StringFromListStringJoin(listargtext, ", ")
			if multiflag {
				body += ")"
			}
		}
		output = "" +
			logopen +
			funcopen +
			body +
			funcclose
	}
	return output, msgblock
}

func LangFuncValueArgIndex(
	lang *vxlang,
	fnc *vxfunc,
	pkgname string,
	argindex int,
	indent int,
	test bool,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncValueArgIndex")
	output := ""
	if argindex < len(fnc.listarg) {
		arg := fnc.listarg[argindex]
		funcname := NameFromFunc(fnc)
		argsubpath := path + "/:arg/" + arg.name
		if argindex == 0 && funcname == "vx/core/fn" {
		} else {
			var argvalue = arg.value
			if argvalue.code == ":func" && argvalue.name == "fn" {
				g_ifuncdepth += 1
				ioutputnum := g_ifuncdepth
				outputname := "output_" + StringFromInt(ioutputnum)
				argfunc := FuncFromValue(argvalue)
				var lambdaargs []string
				var lambdavars []string
				arglist := ListArgLocalFromFunc(argfunc)
				for _, lambdaarg := range arglist {
					lambdaargname := lambdaarg.name + "_any"
					switch lang {
					case langkotlin:
						lambdaargname += " : vx_core.Type_any"
					}
					lambdaargs = append(lambdaargs, lambdaargname)
					argtype := lambdaarg.vxtype
					lambdavar :=
						LangVar(lang, lambdaarg.name, argtype, 1,
							LangPkgNameDot(lang, "vx/core")+"f_any_from_any("+
								LangTypeT(lang, argtype)+", "+lambdaarg.name+"_any)")
					lambdavars = append(lambdavars, lambdavar)
				}
				slambdaargs := StringFromListStringJoin(lambdaargs, ", ")
				slambdavars := StringFromListStringJoin(lambdavars, "")
				argfn := argfunc.listarg[1]
				argfnvalue := argfn.value
				if argfunc.async {
					workvalue, msgs := LangFromValue(lang, argfnvalue, pkgname, fnc, indent, true, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					lambda := LangFuncLambda(lang, 0, ioutputnum, "", slambdaargs,
						slambdavars+
							LangVar(lang, outputname, anytype, 1, workvalue))
					switch arg.vxtype.name {
					case "any<-any-key-value-async", "any<-key-value-async",
						"any<-reduce-async", "any<-reduce-next-async":
						output = "" +
							LangTypeT(lang, arg.vxtype) + lang.typeref + "vx_fn_new(" + lambda + ")"
					default:
						if len(arglist) == 1 {
							output = "" +
								LangPkgNameDot(lang, "vx/core") + "t_any_from_any_async" + lang.typeref + "vx_fn_new(" + lambda + ")"
						} else {
							output = "" +
								LangPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref + "vx_fn_new(" + lambda + ")"
						}
					}
				} else {
					work, msgs := LangFromValue(lang, argfnvalue, pkgname, fnc, 1, true, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					lambda := LangFuncLambda(lang, 0, ioutputnum, "", slambdaargs,
						slambdavars+
							LangVar(lang, outputname, anytype, 1, work))
					switch arg.vxtype.name {
					case "any<-int", "any<-int-any",
						"any<-any-key-value", "any<-key-value",
						"any<-reduce", "any<-reduce-next",
						"boolean<-any":
						output = "" +
							LangTypeT(lang, arg.vxtype) + lang.typeref + "vx_fn_new(" + lambda + ")"
					default:
						if len(arglist) == 1 {
							output = "" +
								LangPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_any" + lang.typeref + "vx_fn_new(" + lambda + ")"
						} else {
							output = "" +
								LangPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func" + lang.typeref + "vx_fn_new(" + lambda + ")"
						}
					}
				}
			} else if funcname == "vx/core/let" {
				switch argindex {
				case 0:
					output = ""
				case 1:
					lambdaarglist := ListArgLocalFromFunc(fnc)
					lambdaargs, msgs := LangFuncLambdaArgIndex(lang, lambdaarglist, 0, true, pkgname, fnc, argvalue, indent, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					output += lambdaargs
				}
			} else if funcname == "vx/core/fn" {
			} else if arg.vxtype.isfunc {
				switch argvalue.code {
				case ":arg":
					argvaluearg := ArgFromValue(argvalue)
					if !argvaluearg.vxtype.isfunc {
						g_ifuncdepth += 1
						ioutputnum := g_ifuncdepth
						outputname := "output_" + StringFromInt(ioutputnum)
						work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, indent, true, test, argsubpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						argvaluefuncname := "any_from_func"
						switch NameFromType(arg.vxtype) {
						case "vx/core/boolean<-func":
							argvaluefuncname = "boolean_from_func"
						}
						lambda := LangFuncLambda(lang, 0, ioutputnum, "", "",
							LangVar(lang, outputname, anytype, 1, work))
						output = "" +
							LangPkgName(lang, "vx/core") + lang.pkgref + "t_" + argvaluefuncname + lang.typeref + "vx_fn_new(" + lambda + ")"
					}
				case ":funcref":
					switch arg.vxtype.name {
					case "any<-any-key-value", "any<-any-key-value-async",
						"any<-key-value", "any<-key-value-async",
						"any<-reduce", "any<-reduce-async",
						"any<-reduce-next", "any<-reduce-next-async":
						funcargfunc := FuncFromValue(argvalue)
						funcarglist := funcargfunc.listarg
						lambdatext, lambdavartext, lambdaargtext := LangLambdaFromArgList(
							lang, funcarglist, funcargfunc.isgeneric)
						work := LangFuncF(lang, funcargfunc) + "(" + lambdaargtext + ")"
						soutput := ""
						g_ifuncdepth += 1
						ioutputnum := g_ifuncdepth
						outputname := "output_" + StringFromInt(ioutputnum)
						if funcargfunc.async {
							soutput = LangVarFuture(lang, outputname, anytype, 1, work)
						} else {
							soutput = LangVar(lang, outputname, anytype, 1, work)
						}
						lambda := LangFuncLambda(lang, 0, ioutputnum, "", lambdatext,
							lambdavartext+
								soutput)
						output = "" +
							LangTypeT(lang, arg.vxtype) + lang.typeref + "vx_fn_new(" + lambda + ")"
					}
				default:
					g_ifuncdepth += 1
					ioutputnum := g_ifuncdepth
					outputname := "output_" + StringFromInt(ioutputnum)
					funcargasync := arg.vxtype.vxfunc.async
					argfuncasync := false
					argfunctype := emptytype
					switch argvalue.code {
					case ":func":
						argfunc := FuncFromValue(argvalue)
						argfunctype = argfunc.vxtype
						argfuncasync = argfunc.async
					}
					converttoasync := false
					if funcargasync && !argfuncasync {
						converttoasync = true
					}
					workindent := 1
					if converttoasync {
						workindent += 1
					}
					work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, workindent, true, test, argsubpath)
					if converttoasync {
						sworkindent := StringRepeat("  ", workindent)
						work = LangPkgNameDot(lang, "vx/core") + "f_async(" + LangTypeT(lang, argfunctype) + ",\n" + sworkindent + work + "\n  )"
					}
					msgblock = MsgblockAddBlock(msgblock, msgs)
					if argvalue.code == ":func" && argvalue.name == "native" {
						work = "\n  " + work
						ioutputnum = -1
					} else {
						work = LangVar(lang, outputname, anytype, 1, work)
					}
					lambda := LangFuncLambda(lang, 0, ioutputnum, "", "", work)
					output = "" +
						LangTypeT(lang, arg.vxtype) + lang.typeref + "vx_fn_new(" + lambda + ")"
				}
			}
			if output == "" {
				work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				output = work
			}
		}
	}
	return output, msgblock
}

func LangFuncValueNative(
	lang *vxlang,
	fnc *vxfunc,
	pkgname string,
	parentfn *vxfunc,
	indent int,
	test bool,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncValueNative")
	output := ""
	isNative := false
	var argtexts []string
	multiline := false
	argtext := ""
	nativeindent := "undefined"
	for _, arg := range fnc.listarg {
		var argvalue = arg.value
		valuetext := ""
		if argvalue.code == "string" {
			valuetext = StringValueFromValue(argvalue)
		}
		if valuetext == (":" + lang.name) {
			isNative = true
		} else if valuetext != ":auto" && BooleanFromStringStarts(valuetext, ":") {
			isNative = false
		} else if isNative {
			if argvalue.name == "newline" {
				argtext = "\n"
			} else {
				clstext, msgs := LangFromValue(lang, argvalue, pkgname, parentfn, 0, false, test, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				argtext = clstext
				if nativeindent == "undefined" {
					nativeindent = "\n" + StringRepeat(" ", argvalue.textblock.charnum)
				} else if nativeindent != "" {
					argtext = StringFromStringFindReplace(argtext, nativeindent, "\n")
				}
			}
			if !multiline {
				if BooleanFromStringContains(argtext, "\n") {
					multiline = true
				} else if argvalue.name != "" {
					multiline = true
				}
				argtext = StringRemoveQuotes(argtext)
				if argtext == ":auto" {
					argtext = LangNativeAutoFromFunc(lang, parentfn)
				}
			}
			argtexts = append(argtexts, argtext)
		}
	}
	if len(argtexts) > 0 {
		if multiline {
			sindent := StringRepeat("  ", indent)
			alltext := StringFromListStringJoin(argtexts, "")
			output += StringFromStringIndent(alltext, sindent)
		} else {
			output += StringFromListStringJoin(argtexts, "")
		}
	}
	return output, msgblock
}

func LangFuncVxCopy(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxcopy := LangFuncVxCopyModel()
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxcopy, 2)
	} else {
		funcvxcopy.isoverride = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxcopy, 2, 0,
				LangValClass(lang, "output", NewTypeFromFunc(fnc), 3, ":new"))
	}
	return output
}

func LangFuncVxCopyModel() *vxfunc {
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
	return funcvxcopy
}

func LangFuncVxEmpty(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxempty := NewFunc()
	funcvxempty.name = "vx_empty"
	funcvxempty.vxtype = anytype
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxempty, 2)
	} else {
		funcvxempty.isoverride = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxempty, 2, 0,
				LangVar(lang, "output", anytype, 3,
					LangFuncE(lang, fnc)))
	}
	return output
}

func LangFuncVxFnNew(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	output := ""
	vars := ""
	body := ""
	funcs := ""
	vxreturntype := LangFuncFuncFull(lang, fnc)
	typefunc := NewTypeFromFunc(fnc)
	contextname := ""
	if fnc.context {
		contextname = "-context"
	}
	asyncname := ""
	if fnc.async {
		asyncname = "-async"
	}
	ifntype := LangFuncIFnType(lang, fnc)
	ifn := ""
	if ifntype != emptytype {
		ifn = LangTypeClass(lang, ifntype)
		if !isinterface {
			switch lang {
			case langcsharp:
				vars += "" +
					"\n    public " + ifn + "? fn = null" + lang.lineend +
					"\n"
			case langkotlin:
				vars += "" +
					"\n    var fn : " + ifn + "? = null" +
					"\n"
			default:
				vars += "" +
					"\n    public " + ifn + " fn = null" + lang.lineend +
					"\n"
			}
			body = "" +
				LangValClass(lang, "output", typefunc, 3, ":new") +
				"\n      output.fn = fn" + lang.lineend +
				"\n      return output" + lang.lineend
		}
	} else {
		switch NameFromType(fnc.vxtype) {
		case "vx/core/none":
		default:
			switch len(fnc.listarg) {
			case 1:
				arg := fnc.listarg[0]
				arginputnames := "inputval"
				argoutputnames := "outputval"
				if fnc.context {
					arginputnames = "context, " + arginputnames
					argoutputnames = "context, " + argoutputnames
				}
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						arginputnames = LangTypeTSimple(lang, fnc.vxtype, true) + ", " + arginputnames
					}
				}
				funcvxanyfromany := NewFunc()
				funcvxanyfromany.async = fnc.async
				funcvxanyfromany.context = fnc.context
				funcvxanyfromany.isgeneric = true
				funcvxanyfromany.generictype = anytype1
				funcvxanyfromany.vxtype = anytype1
				funcvxanyfromany.isimplement = true
				funcvxanyfromanyname := "vx_any_from_any"
				if fnc.context {
					funcvxanyfromanyname += LangFromName(contextname)
				}
				if fnc.async {
					funcvxanyfromanyname += LangFromName(asyncname)
				}
				funcvxanyfromany.name = funcvxanyfromanyname
				argvxanyfromanyvalue := NewArg("value")
				argvxanyfromanyvalue.isgeneric = true
				argvxanyfromanyvalue.vxtype = anytype2
				listargsfuncvxanyfromany := NewListArg()
				listargsfuncvxanyfromany = append(listargsfuncvxanyfromany, argvxanyfromanyvalue)
				funcvxanyfromany.listarg = listargsfuncvxanyfromany
				funcanyfromany := NewFunc()
				funcanyfromany.pkgname = "vx/core"
				funcanyfromany.name = "any<-any" + contextname + asyncname
				vxreturntype = LangFuncFuncFull(lang, funcanyfromany)
				ifn = LangFuncClassFull(lang, funcanyfromany) + lang.typeref + "IFn"
				body = "" +
					"\n      return " + LangFuncE(lang, funcanyfromany) + lang.lineend
				if fnc.async {
					asyncbody := ""
					issamegeneric := false
					fncgenerictype := fnc.generictype
					argtype := arg.vxtype
					if fncgenerictype == nil {
					} else if fncgenerictype.name == argtype.name {
						issamegeneric = true
					} else if argtype.isfunc && fncgenerictype.name == argtype.vxfunc.vxtype.name {
						// type = (func : generic)
						issamegeneric = true
					}
					if issamegeneric {
						// both generics are the same
						asyncbody += "" +
							LangVarGeneric(lang, "inputval", anytype1, 3,
								LangPkgNameDot(lang, "vx/core")+"f_any_from_any(generic_any_1, value)") +
							LangVarFutureGeneric(lang, "output", anytype1, 3,
								LangPkgNameDot(lang, "vx/core")+"f_async(generic_any_1, inputval)")
					} else {
						suppresswarnings := ""
						switch lang {
						case langjava:
							suppresswarnings = "\n      @SuppressWarnings(\"unchecked\")"
						}
						vxasyncanyfromany := ""
						switch lang {
						case langcsharp:
							vxasyncanyfromany = LangPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future)"
						case langjava:
							vxasyncanyfromany = "(" + lang.future + "<T>)future"
						case langkotlin:
							vxasyncanyfromany = "future as (" + lang.future + "<T>)"
						}
						asyncbody += "" +
							LangVar(lang, "inputval", arg.vxtype, 3,
								LangPkgNameDot(lang, "vx/core")+"f_any_from_any("+LangTypeT(lang, arg.vxtype)+", value)") +
							LangVarFuture(lang, "future", fnc.vxtype, 3,
								LangFuncF(lang, fnc)+"("+arginputnames+")") +
							suppresswarnings +
							LangVarFutureGeneric(lang, "output", anytype1, 3, vxasyncanyfromany)
					}
					funcs += "" +
						LangFuncHeader(lang, LangFuncF(lang, fnc), funcvxanyfromany,
							2, 0, asyncbody)
				} else {
					funcs = "" +
						LangFuncHeader(lang, LangFuncF(lang, fnc), funcvxanyfromany, 2, 0,
							LangVarGeneric(lang, "output", anytype1, 3,
								LangPkgNameDot(lang, "vx/core")+"f_empty(generic_any_1)")+
								LangVar(lang, "inputval", arg.vxtype, 3,
									LangAsType(lang, "value", arg.vxtype))+
								LangVar(lang, "outputval", anytype, 3,
									LangFuncF(lang, fnc)+"("+arginputnames+")")+
								LangVarSet(lang, "output", 3,
									LangFuncF(lang, funcanyfromany)+"(generic_any_1, "+argoutputnames+")"))
				}
			}
		}
	}
	if ifn != "" {
		header := ""
		override := ""
		if !isinterface {
			switch lang {
			case langkotlin:
				override = "override "
			case langjava:
				override = "\n    @Override"
			}
		}
		switch lang {
		case langcsharp:
			header = "\n    " + override + "public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		case langjava:
			header = "" +
				override +
				"\n    public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		case langkotlin:
			header = "\n    " + override + "fun vx_fn_new(fn : " + ifn + ") : " + vxreturntype
		default:
			header = "\n    public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		}
		if isinterface {
			output += "" +
				header + lang.lineend
		} else {
			output += "" +
				vars +
				header + " {" +
				body +
				"\n    }" +
				"\n" +
				funcs
		}
	}
	return output
}

func LangFuncVxFunc(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxfunc := NewFuncCopy(fnc)
	funcvxfunc.alias = "vx_" + LangFuncName(fnc)
	if !fnc.vxtype.isgeneric {
		listarg := NewListArg()
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !arg.isgeneric {
				listarg = append(listarg, arg)
			} else if BooleanFromStringStarts(argtype.name, "any-") {
				argchg := NewArg(arg.name)
				argchg.vxtype = anytype
				listarg = append(listarg, argchg)
			} else if BooleanFromStringStarts(argtype.name, "list-") {
				argchg := NewArg(arg.name)
				argchg.vxtype = listtype
				listarg = append(listarg, argchg)
			} else if BooleanFromStringStarts(argtype.name, "map-") {
				argchg := NewArg(arg.name)
				argchg.vxtype = maptype
				listarg = append(listarg, argchg)
			} else {
				listarg = append(listarg, arg)
			}
		}
		funcvxfunc.listarg = listarg
	}
	output := ""
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxfunc, 2)
	} else {
		var listargtype []string
		var listargname []string
		if fnc.isgeneric {
			switch NameFromFunc(fnc) {
			case "vx/core/copy", "vx/core/empty", "vx/core/new":
			case "vx/core/any<-any", "vx/core/any<-any-async",
				"vx/core/any<-any-context", "vx/core/any<-any-context-async",
				"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
				"vx/core/any<-int", "vx/core/any<-int-any",
				"vx/core/any<-func", "vx/core/any<-func-async",
				"vx/core/any<-key-value", "vx/core/any<-key-value-async",
				"vx/core/any<-none", "vx/core/any<-none-async",
				"vx/core/any<-reduce", "vx/core/any<-reduce-async",
				"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
				arggeneric := arggenericany1
				argtext := LangArgHeader(lang, arggeneric, true)
				listargtype = append(listargtype, argtext)
			default:
				if fnc.generictype != nil {
					arggeneric := LangArgGenericFromType(lang, fnc.generictype)
					argtext := LangArgHeader(lang, arggeneric, true)
					listargtype = append(listargtype, argtext)
					listargname = append(listargname, arggeneric.alias)
				}
			}
		}
		if fnc.context {
			argtext := LangArgHeader(lang, argcontext, false)
			listargtype = append(listargtype, argtext)
			listargname = append(listargname, "context")
		}
		switch NameFromFunc(fnc) {
		case "vx/core/let":
			argtext := LangPkgNameDot(lang, "vx/core") + "Func_any_from_func fn_any"
			listargtype = append(listargtype, argtext)
			listargname = append(listargname, "fn_any")
		case "vx/core/let-async":
			argtext := LangPkgNameDot(lang, "vx/core") + "Func_any_from_func_async fn_any_async"
			listargtype = append(listargtype, argtext)
			listargname = append(listargname, "fn_any_async")
		default:
			isallowgeneric := false
			if fnc.generictype != nil {
				isallowgeneric = true
			}
			for _, arg := range fnc.listarg {
				argtext := LangArgHeader(lang, arg, isallowgeneric)
				listargname = append(listargname, LangFromName(arg.alias))
				if arg.multi {
					listargtype = append(listargtype, argtext)
				} else {
					listargtype = append(listargtype, argtext)
				}
			}
		}
		var returntype *vxtype
		if fnc.generictype == nil {
			returntype = fnc.vxtype
		} else {
			returntype = fnc.generictype
		}
		body := ""
		funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
		interfacefn := LangFuncInterfaceFn(lang, fnc)
		if interfacefn == "" {
			if fnc.async {
				body = "" +
					LangVarFutureGeneric(lang, "output", returntype, 3,
						LangPkgNameDot(lang, fnc.pkgname)+"f_"+funcname+"("+strings.Join(listargname, ", ")+")")
			} else {
				body = "" +
					LangVarGeneric(lang, "output", returntype, 3,
						LangPkgNameDot(lang, fnc.pkgname)+"f_"+funcname+"("+strings.Join(listargname, ", ")+")")
			}
		} else {
			resolve := ""
			switch lang {
			case langjava, langkotlin:
				resolve = "fnlocal.resolve(" + strings.Join(listargname, ", ") + ")"
			default:
				resolve = "fnlocal(" + strings.Join(listargname, ", ") + ")"
			}
			fntype := LangFuncIFnType(lang, fnc)
			if fnc.async {
				body = "" +
					LangVarFutureGeneric(lang, "output", returntype, 3, "") +
					LangVarClassNullable(lang, "fnlocal", fntype, 3, "this.fn") +
					"\n      if (fnlocal == null) {" +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_new_from_value("+
							LangPkgNameDot(lang, "vx/core")+
							"f_empty(generic_any_1))") +
					"\n      } else {" +
					LangVarFuture(lang, "future", anytype, 4,
						resolve) +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_from_async(generic_any_1, future)") +
					"\n      }"
			} else {
				if BooleanFromStringStarts(fnc.name, "boolean<-") {
					body = "" +
						LangVar(lang, "output", booleantype, 3,
							LangPkgNameDot(lang, "vx/core")+"c_false") +
						LangVarClassNullable(lang, "fnlocal", fntype, 3, "this.fn") +
						"\n      if (fnlocal != null) {" +
						LangVar(lang, "anyoutput", anytype, 4, resolve) +
						LangVarSet(lang, "output", 4,
							LangPkgNameDot(lang, "vx/core")+
								"f_any_from_any("+
								LangTypeT(lang, booleantype)+
								", anyoutput)") +
						"\n      }"
				} else if BooleanFromStringStarts(fnc.name, "int<-") {
					body = "" +
						LangVar(lang, "output", inttype, 3, LangTypeE(lang, inttype)) +
						LangVarClassNullable(lang, "fnlocal", fntype, 3, "this.fn") +
						"\n      if (fnlocal != null) {" +
						LangVar(lang, "anyoutput", anytype, 4, resolve) +
						LangVarSet(lang, "output", 4,
							LangPkgNameDot(lang, "vx/core")+
								"f_any_from_any("+
								LangTypeT(lang, inttype)+
								", anyoutput)") +
						"\n      }"
				} else if BooleanFromStringStarts(fnc.name, "string<-") {
					body = "" +
						LangVar(lang, "output", stringtype, 3,
							LangTypeE(lang, stringtype)) +
						LangVarClassNullable(lang, "fnlocal", fntype, 3, "this.fn") +
						"\n      if (fnlocal != null) {" +
						LangVar(lang, "anyoutput", anytype, 4, resolve) +
						LangVarSet(lang, "output", 4,
							LangPkgNameDot(lang, "vx/core")+
								"f_any_from_any("+
								LangTypeT(lang, stringtype)+
								", anyoutput)") +
						"\n      }"
				} else {
					body = "" +
						LangVarGeneric(lang, "output", anytype1, 3,
							LangPkgNameDot(lang, "vx/core")+"f_empty(generic_any_1)") +
						LangVarClassNullable(lang, "fnlocal", fntype, 3, "this.fn") +
						"\n      if (fnlocal != null) {" +
						LangVar(lang, "anyoutput", anytype, 4, resolve) +
						LangVarSet(lang, "output", 4,
							LangPkgNameDot(lang, "vx/core")+"f_any_from_any(generic_any_1, anyoutput)") +
						"\n      }"
				}
			}
		}
		funcvxfunc.isimplement = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxfunc, 2, 0, body)
	}
	return output
}

func LangFuncVxFuncdef(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxfuncdef := NewFunc()
	funcvxfuncdef.name = "vx_funcdef"
	funcvxfuncdef.vxtype = funcdeftype
	output := ""
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxfuncdef, 2)
	} else {
		funcvxfuncdef.isimplement = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxfuncdef, 2, 0,
				LangVar(lang, "output", funcdeftype, 3,
					LangFuncDefFromFunc(lang, fnc, 3)))
	}
	return output
}

func LangFuncVxNew(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	returntype := NewTypeFromFunc(fnc)
	funcvxnew := LangTypeVxNewModel(returntype)
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxnew, 2)
	} else {
		funcvxnew.isoverride = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxnew, 2, 0,
				LangValClass(lang, "output", NewTypeFromFunc(fnc), 3, ":new"))
	}
	return output
}

func LangFuncVxType(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxtype := NewFunc()
	funcvxtype.name = "vx_type"
	funcvxtype.vxtype = anytype
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxtype, 2)
	} else {
		funcvxtype.isoverride = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxtype, 2, 0,
				LangVar(lang, "output", anytype, 3,
					LangFuncT(lang, fnc)))
	}
	return output
}

func LangFuncVxRepl(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	output := ""
	arganylist := NewArg("arglist")
	arganylist.vxtype = anylisttype
	arganylist.isfinal = false
	listarg := NewListArg()
	listarg = append(listarg, arganylist)
	funcvxrepl := NewFunc()
	funcvxrepl.name = "vx_repl"
	funcvxrepl.vxtype = anytype
	funcvxrepl.listarg = listarg
	funcvxrepl.async = fnc.async
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxrepl, 2)
	} else {
		funcvxrepl.isimplement = true
		replparams := ""
		argidx := 0
		var listargname []string
		pkgname := LangPkgName(lang, fnc.pkgname)
		outputtype := fnc.vxtype
		outputttype := LangTypeTSimple(lang, fnc.vxtype, true)
		if fnc.isgeneric {
			switch NameFromFunc(fnc) {
			case "vx/core/copy", "vx/core/empty", "vx/core/new":
			default:
				if fnc.generictype != nil {
					replparam := LangVar(lang, "generic_"+LangFromName(fnc.generictype.name), fnc.vxtype, 3,
						LangPkgNameDot(lang, "vx/core")+
							"f_any_from_any("+
							outputttype+
							", arglist.vx_any("+LangPkgNameDot(lang, "vx/core")+
							"vx_new_int("+
							StringFromInt(argidx)+
							")))")
					replparams += replparam
					listargname = append(listargname, "generic_"+LangFromName(fnc.generictype.name))
				}
			}
		}
		if fnc.context {
			listargname = append(listargname, "context")
			replparam := LangVar(lang, "context", contexttype, 3,
				LangPkgNameDot(lang, "vx/core")+
					"f_any_from_any("+
					LangTypeT(lang, contexttype)+
					", arglist.vx_any("+
					LangPkgNameDot(lang, "vx/core")+
					"vx_new_int("+
					StringFromInt(argidx)+
					")))")
			replparams += replparam
		}
		for _, arg := range fnc.listarg {
			if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
			} else {
				argname := LangFromName(arg.alias)
				replparam := "" +
					LangVar(lang, argname, arg.vxtype, 3,
						LangPkgNameDot(lang, "vx/core")+
							"f_any_from_any("+
							LangTypeTSimple(lang, arg.vxtype, true)+
							", arglist.vx_any("+
							LangPkgNameDot(lang, "vx/core")+
							"vx_new_int("+StringFromInt(argidx)+")))")
				replparams += replparam
				listargname = append(listargname, argname)
				argidx += 1
			}
		}
		if fnc.async {
			output = "" +
				LangFuncHeader(lang, LangFuncName(fnc), funcvxrepl, 2, 0,
					LangVarFuture(lang, "output", anytype, 3,
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_new_from_value("+
							LangTypeE(lang, anytype)+
							")")+
						replparams+
						LangVarFuture(lang, "future", outputtype, 3,
							pkgname+
								".f_"+funcname+
								"("+strings.Join(listargname, ", ")+")")+
						LangVarSet(lang, "output", 3,
							LangPkgNameDot(lang, "vx/core")+
								"vx_async_from_async("+
								LangTypeT(lang, anytype)+
								", future)"))
		} else {
			output = "" +
				LangFuncHeader(lang, funcname, funcvxrepl, 2, 0,
					LangVar(lang, "output", anytype, 3,
						LangTypeE(lang, anytype))+
						replparams+
						LangVarSet(lang, "output", 3,
							pkgname+
								".f_"+
								funcname+
								"("+
								strings.Join(listargname, ", ")+
								")"))
		}
	}
	return output
}

func LangFuncVxTypedef(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	functypedef := NewFunc()
	functypedef.name = "vx_typedef"
	functypedef.vxtype = typedeftype
	output := ""
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, functypedef, 2)
	} else {
		functypedef.isoverride = true
		output = "" +
			LangFuncHeader(lang, funcname, functypedef, 2, 0,
				LangVar(lang, "output", typedeftype, 3,
					LangTypeT(lang, functype)+lang.typeref+"vx_typedef()"))
	}
	return output
}
