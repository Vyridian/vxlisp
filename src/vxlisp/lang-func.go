package vxlisp

import (
	"strings"
)

func LangFunc(
	lang *vxlang,
	fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFunc")
	g_ifuncdepth = 0
	funcname := LangFuncName(fnc)
	f_func, msgs := LangFuncFFunc(lang, fnc, false)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	typefnc := NewTypeFromFunc(fnc)
	path := fnc.pkgname + "/" + fnc.name + StringIndexFromFunc(fnc)
	output := "" +
		LangFuncDoc(lang, fnc) +
		LangFuncInterface(lang, path, fnc) +
		LangFuncClassHeader(lang, fnc, 1) +
		"\n" +
		LangFuncVxNew(lang, path, fnc, false) +
		LangFuncVxCopy(lang, path, fnc, false) +
		LangFuncVxTypedef(lang, path, fnc, false) +
		LangFuncVxFuncdef(lang, path, fnc, false) +
		LangFuncVxEmpty(lang, path, fnc, false) +
		LangFuncVxType(lang, path, fnc, false) +
		LangFuncInterfaceFn(lang, fnc) +
		LangFuncVxFnNew(lang, path, fnc, false) +
		LangFuncVxRepl(lang, path, fnc, false) +
		LangFuncVxFunc(lang, path, fnc, false) +
		"\n  }" +
		"\n" +
		LangValStatic(lang, 1, typefnc,
			"e_"+funcname, ":new") +
		LangValStatic(lang, 1, typefnc,
			"t_"+funcname, ":new") +
		"\n" +
		f_func
	output = LangFuncCleanup(lang, fnc, output)
	return output, msgblock
}

func LangFuncArgText(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	path string) string {
	isreturngeneric := fnc.vxtype.isgeneric
	var listargtext []string
	if fnc.generictype != nil {
		isaddgeneric := true
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "f_copy":
			if lang.genericcount != 1 {
				isaddgeneric = false
			}
		case "vx/core/empty", "vx/core/new<-type", "f_empty", "f_new_from_type":
			isaddgeneric = false
		}
		if isaddgeneric {
			arggeneric := NewArg(
				"generic-" + fnc.generictype.name)
			arggeneric.vxtype = fnc.generictype
			argtext := LangFuncArgHeader(lang,
				fnc, -1, arggeneric, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	if fnc.context {
		argtext := LangFuncArgHeader(lang,
			fnc, -2, argcontext, isreturngeneric)
		listargtext = append(listargtext, argtext)
	}
	for argidx, arg := range fnc.listarg {
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
			argtext := LangFuncArgHeader(lang,
				fnc, argidx, arg, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	output := ""
	if len(listargtext) > 0 {
		argjoin := lang.argjoin
		switch argjoin {
		case "":
			output = StringFromListStringJoin(
				listargtext, ", ")
		case ",\n":
			lineindent1 := StringRepeat("  ", indent)
			lineindent2 := lineindent1 + "  "
			output = StringFromListStringJoin(
				listargtext, argjoin+lineindent2)
			output = "\n" + lineindent2 + output + "\n" + lineindent1
		default:
			output = StringFromListStringJoin(
				listargtext, argjoin)
		}
	}
	return output
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
	indent int,
	fnc *vxfunc) string {
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
	if !fnc.isgeneric {
	} else if fnc.generictype != nil {
		ioption := 0
		switch NameFromFunc(fnc) {
		case "vx/core/copy":
			if lang.genericcount != 1 {
				ioption = 1
			}
		case "vx/core/empty", "vx/core/new<-type":
			ioption = 1
		case "vx/core/any<-any", "vx/core/any<-any-async",
			"vx/core/any<-any-context", "vx/core/any<-any-context-async",
			"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
			"vx/core/any<-int", "vx/core/any<-int-any",
			"vx/core/any<-func", "vx/core/any<-func-async",
			"vx/core/any<-key-value", "vx/core/any<-key-value-async",
			"vx/core/any<-none", "vx/core/any<-none-async",
			"vx/core/any<-reduce", "vx/core/any<-reduce-async",
			"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
			ioption = 2
		}
		switch ioption {
		case 1:
		case 2:
			arggeneric := arggenericany1
			argtext := LangFuncArgHeader(lang,
				fnc, -1, arggeneric, true)
			listargtype = append(listargtype, argtext)
		default:
			arggeneric := LangArgGenericFromType(lang, fnc.generictype)
			argtext := LangFuncArgHeader(lang,
				fnc, -1, arggeneric, true)
			listargtype = append(listargtype, argtext)
			listargname = append(listargname, arggeneric.alias)
		}
	}
	if fnc.context {
		argtext := LangFuncArgHeader(lang,
			fnc, -2, argcontext, false)
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
		for argidx, arg := range fnc.listarg {
			argtext := LangFuncArgHeader(lang,
				fnc, argidx, arg, isallowgeneric)
			listargname = append(listargname, LangFromName(arg.alias))
			listargtype = append(listargtype, argtext)
		}
	}
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
		permissiontop = LangIfThen(lang, 2,
			LangFuncCallMethod(lang, 3,
				LangFuncCallF(lang, 2,
					func_boolean_permission_from_func,
					"context",
					LangFuncT(lang, fnc)),
				"vx_boolean"),
			"")
		permissionbottom = "" +
			LangIfElse(lang, 2,
				LangVar(lang, 3, msgtype,
					"msg",
					LangFuncCallVx(lang, 3,
						func_msg_from_error,
						"\"vx/core/func\"",
						"\":permissiondenied\"",
						LangFuncCallVx(lang, 4,
							func_new_string,
							"\""+fnc.name+"\"")))+
					LangVarSet(lang, 3,
						"output",
						LangFuncCallVariadicVx(lang, 3,
							func_copy,
							[]string{
								LangTypeT(lang, fnc.vxtype),
								"output"},
							[]string{
								"msg"}))) +
			LangIfEnd(lang, 2)
		subindent += 1
		ssubindent += "  "
	}
	linesubindent := "\n" + ssubindent
	if fnc.messages {
		stry, scatch := LangFuncTryCatch(
			lang, linesubindent)
		msgtop = stry
		msgbottom = "" +
			scatch +
			LangVar(lang, subindent+1, msgtype,
				"msg",
				LangFuncCallVx(lang, subindent+1,
					func_msg_from_exception,
					"\""+fnc.pkgname+"/"+fnc.name+"\"",
					lang.serror)) +
			LangVarSet(lang, subindent+1,
				"output",
				LangFuncCallVariadicVx(lang, subindent+1,
					func_copy,
					[]string{
						LangTypeT(lang, fnc.vxtype),
						"output"},
					[]string{
						"msg"})) +
			linesubindent + "}"
		subindent += 1
		ssubindent += "  "
	}
	linesubindent = "\n" + ssubindent
	output := ""
	if isinterface {
	} else {
		valuetext, msgs := LangFromValue(
			lang, 0, fnc.value, fnc.pkgname, fnc, true, false, path)
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
		case "vx/core/new", "vx/core/new<-type":
			f_suppresswarnings = LangFuncNewSuppressWarnings(lang)
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
		if valuetext != "" {
			if !BooleanFromStringEnds(valuetext, ";") {
				valuetext += lang.lineend
			}
			valuetext = linesubindent + StringFromStringIndent(
				valuetext, ssubindent)
		}
		defaultvalue := LangFuncDefaultOutput(lang, indent,
			fnc, valuetext)
		output = "" +
			f_suppresswarnings +
			LangFuncFFuncHelper(lang, path,
				fnc,
				false,
				""+
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
	path string,
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
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcf)
	} else {
		output = "" +
			LangFuncHeaderStatic(lang, path, 1,
				"", funcf, 0, sbody) +
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

func LangFuncHeader(
	lang *vxlang,
	path string,
	indent int,
	prefix string,
	fnc *vxfunc,
	outputnum int,
	value string) string {
	return LangFuncHeaderAll(lang, path, indent,
		prefix, fnc, false, false, outputnum, value)
}

/*
func LangFuncHeaderOld(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	isinterface bool,
	isstatic bool) string {
	return LangFuncHeaderAll(
		lang, 2, prefix, fnc, isinterface, isstatic, 0, "")
}
*/

func LangFuncHeaderAll(
	lang *vxlang,
	path string,
	indent int,
	prefix string,
	fnc *vxfunc,
	isinterface bool,
	isstatic bool,
	outputnum int,
	value string) string {
	output := ""
	funcname := LangFromName(fnc.alias)
	if funcname == "" {
		funcname = LangFuncName(fnc)
	}
	funcinstance, funcstatic := LangFuncInstanceStatic(lang, isinterface)
	funcdeclare := funcinstance
	if isstatic {
		funcdeclare = funcstatic
	}
	argtext := LangFuncArgText(lang, indent, fnc, path)
	genericvars := LangFuncGenericVars(lang, indent+1, fnc, isinterface)
	genericdef1, genericdef2, genericdef3 := LangFuncGenericDefinition(
		lang, fnc)
	sindent := "\n" + StringRepeat("  ", indent)
	override1, override2, override3 := LangFuncOverride(
		lang, fnc, sindent)
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
			isskip := false
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				isskip = false
				if fnc.name == "const_new" {
					isskip = true
				}
			}
			if !isskip {
				sreturn = sindent + "  return " + soutput + lang.lineend
			}
			sclose = sindent + "}\n"
		}
	}
	funcprefix, returntype1, returntype2 := LangFuncPrefixReturnTypes(
		lang, fnc, prefix)
	output = "" +
		override1 +
		sindent + override2 + funcdeclare + override3 + genericdef1 + returntype1 + funcprefix + funcname + genericdef2 + "(" + argtext + ")" + returntype2 + genericdef3 + sinterface + sopen +
		genericvars +
		value +
		sreturn +
		sclose
	return output
}

func LangFuncHeaderInterface(
	lang *vxlang,
	path string,
	indent int,
	prefix string,
	fnc *vxfunc) string {
	output := LangFuncHeaderAll(lang, path, indent,
		prefix, fnc, true, false, 0, "")
	return output
}

func LangFuncHeaderStatic(
	lang *vxlang,
	path string,
	indent int,
	prefix string,
	fnc *vxfunc,
	outputnum int,
	value string) string {
	return LangFuncHeaderAll(lang, path, indent,
		prefix, fnc, false, true, outputnum, value)
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

func LangFuncInterface(
	lang *vxlang,
	path string,
	fnc *vxfunc) string {
	extends := ""
	indent := 1
	interfaces := LangFuncVxFunc(lang, path,
		fnc, true)
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
		interfaces += LangFuncVxFnNew(lang, path,
			fnc, true)
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
	output := LangFuncInterfaceNative(
		lang, fnc, extends, interfaces, indent)
	return output
}

func LangFuncLambda(
	lang *vxlang,
	indent int,
	outputnum int,
	bindings string,
	args string,
	body string,
	path string) string {
	output := "" +
		LangFuncLambdaHeader(
			lang, indent, outputnum, bindings, args) +
		body +
		LangFuncLambdaFooter(
			lang, indent, outputnum)
	return output
}

func LangFuncName(
	fnc *vxfunc) string {
	output := LangFromName(fnc.alias)
	if output == "" {
		output = LangFromName(fnc.name)
	}
	output += LangIndexFromFunc(fnc)
	return output
}

func LangFuncT(
	lang *vxlang, fnc *vxfunc) string {
	name := "t_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangFuncLambdaArgIndex(
	lang *vxlang,
	indent int,
	listarglambda []vxarg,
	indexarglambda int,
	isstart bool,
	pkgname string,
	fnc *vxfunc,
	argvalue vxvalue,
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
		sreturnoutput := ""
		iswrapped := isstart
		if iswrapped {
			g_ifuncdepth += 1
			ioutputnum = g_ifuncdepth
			outputname = "output_" + StringFromInt(ioutputnum)
			listarg := fnc.listarg
			lastarg := listarg[len(listarg)-1]
			if !fnc.async {
				sfncvalue, msgs := LangFromValue(
					lang, indent+2, lastarg.value, pkgname, fnc, true, test, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				sreturnoutput = LangVal(lang, indent+2, anytype,
					outputname, sfncvalue)
			}
		}
		if lambdaarg.async {
			lastoutputnum := g_ifuncdepth
			lastoutputname := "output_" + StringFromInt(lastoutputnum)
			listarg := fnc.listarg
			lastarg := listarg[len(listarg)-1]
			sfncvalue, msgs := LangFromValue(
				lang, indent+3, lastarg.value, pkgname, fnc, true, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			g_ifuncdepth += 1
			ioutputargnum := g_ifuncdepth
			outputname := "output_" + StringFromInt(ioutputargnum)
			lambdavaluetext, msgs := LangFromValue(lang, indent+1,
				lambdaarg.value, pkgname, fnc, true, test, argsubpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			svalueoutput := LangVal(lang, indent+3, anytype,
				outputname, sfncvalue)
			slambdarest := ""
			work, msgs := LangFuncLambdaArgIndex(lang, indent+2,
				listarglambda, indexarglambda+1, false, pkgname, fnc, argvalue, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest = work
			sfuturevar := LangValFuture(lang, indent+1, lambdaarg.vxtype,
				"future_"+LangFromName(lambdaarg.name),
				lambdavaluetext)
			lambdaargname, lambdaconvert := LangFuncLambdaArgAny(lang, indent+3, lambdaarg)
			slambdaoutput := "" +
				LangFuncLambda(lang, indent+2, ioutputargnum, "", lambdaargname,
					lambdaconvert+
						slambdarest+
						svalueoutput,
					argsubpath)
			sfutureoutput := "" +
				LangValFuture(lang, indent+1, anytype,
					lastoutputname,
					LangFuncCallVx(lang, indent+1,
						func_async_from_async_fn,
						LangTypeT(lang, anytype),
						"future_"+LangFromName(lambdaarg.name),
						slambdaoutput))
			slambdavars += "" +
				sfuturevar +
				sfutureoutput
		} else {
			lambdavaluetext, msgs := LangFromValue(lang, indent+2,
				lambdaarg.value, pkgname, fnc, true, test, argsubpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest := ""
			work, msgs := LangFuncLambdaArgIndex(lang, indent,
				listarglambda, indexarglambda+1, false, pkgname, fnc, argvalue, test, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			slambdarest = work
			slambdavar := LangVal(lang, indent+2, lambdaarg.vxtype,
				LangFromName(lambdaarg.name), lambdavaluetext)
			slambdavars +=
				slambdavar +
					slambdarest
		}
		if iswrapped {
			lambda := LangFuncLambda(lang, indent, ioutputnum, "", "",
				slambdavars+
					sreturnoutput,
				argsubpath)
			var fn_anyfromfunc *vxfunc
			if fnc.async {
				fn_anyfromfunc = func_any_from_func_async
			} else {
				fn_anyfromfunc = func_any_from_func
			}
			output = "" +
				LangFuncCallMethod(lang, indent,
					LangFuncT(lang, fn_anyfromfunc),
					"vx_fn_new",
					lambda)
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
	subpath := path + "/" + fnc.name
	funcname := NameFromFunc(fnc)
	output := ""
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
		output = snative
	default:
		func_value := fnc
		var listargtext []string
		funcargs := fnc.listarg
		isskip := false
		isvariadic := false
		var variadictype *vxtype
		var variadics []string
		funcprefix := ""
		switch funcname {
		case "vx/core/any<-struct":
			propvalue := funcargs[1].value
			switch propvalue.code {
			case "string":
				propname := StringValueFromValue(propvalue)
				if BooleanFromStringStartsEnds(propname, "\"", "\"") {
					propname = propname[1 : len(propname)-1]
				}
				if BooleanFromStringStarts(propname, ":") {
					propname = propname[1:]
				}
				structvalue := funcargs[0].value
				work, msgs := LangFromValue(lang, 0,
					structvalue, pkgname, fnc, true, test, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				output = LangFuncCallMethod(lang, 0,
					work,
					LangFromName(propname))
				//				listargtext = append(listargtext, work)
				//				isskip = true
			}
		case "vx/core/fn":
		case "vx/core/let":
			if fnc.async {
				funcprefix = "f"
				func_value = func_let_async
			} else {
				funcprefix = "f"
				func_value = fnc
			}
		default:
			if fnc.argname != "" {
				funcprefix = "vx"
				func_value = func_any_from_func
				listargtext = append(listargtext, LangTypeT(lang, fnc.vxtype))
				listargtext = append(listargtext, LangFromName(fnc.argname))
				if lang.forcemulti {
					variadictype = anylisttype
					isvariadic = true
				}
			} else {
				funcprefix = "f"
				func_value = fnc
			}
		}
		if !isskip {
			if !fnc.isgeneric {
			} else if fnc.generictype != nil {
				isaddgeneric := true
				switch funcname {
				case "vx/core/copy":
					if lang.genericcount != 1 {
						isaddgeneric = false
					}
				case "vx/core/empty", "vx/core/fn", "vx/core/new<-type":
					isaddgeneric = false
				}
				if isaddgeneric {
					genericarg := LangTypeTGeneric(lang, fnc.vxtype)
					listargtext = append(listargtext, genericarg)
				}
			}
			if fnc.context {
				listargtext = append(listargtext, "context")
			}
			for argidx, arg := range fnc.listarg {
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
					if !ismultiarg {
						if !isvariadic {
							isvariadic = true
							variadictype = arg.vxtype
						}
					}
				}
				argindent := indent + 1
				if isvariadic {
					argindent += 2
				}
				sargvalue, msgs := LangFuncValueArgIndex(lang, argindent,
					fnc, pkgname, argidx, test, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if isvariadic {
					variadics = append(variadics, sargvalue)
				} else {
					if sargvalue != "" {
						listargtext = append(listargtext, sargvalue)
					}
				}
			}
		}
		if isvariadic {
			svariadicvar := "" +
				LangFuncCallVariadicVx(lang, indent+1,
					func_new,
					[]string{LangTypeT(lang, variadictype)},
					variadics)
			listargtext = append(listargtext, svariadicvar)
		}
		if output == "" {
			outputindent := indent
			if fnc.debug {
				outputindent += 1
			}
			output = "" +
				LangFuncCall(lang, outputindent,
					funcprefix,
					func_value,
					listargtext...)
		}
	}
	if fnc.debug {
		output = "" +
			LangFuncCallF(lang, indent,
				func_log_1,
				LangTypeT(lang, fnc.vxtype),
				LangFuncCallVx(lang, indent+1,
					func_new_string,
					"\""+funcname+"\""),
				output)
	}
	return output, msgblock
}

func LangFuncValueArgIndex(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	pkgname string,
	argindex int,
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
					lambdaargname := LangFuncLambdaArgName(
						lang, lambdaarg)
					lambdaargs = append(
						lambdaargs, lambdaargname)
					argtype := lambdaarg.vxtype
					lambdavar :=
						LangVal(lang, indent+2, argtype,
							lambdaarg.name,
							LangFuncCallF(lang, indent+2,
								func_any_from_any,
								LangTypeT(lang, argtype),
								lambdaarg.name+"_any"))
					lambdavars = append(lambdavars, lambdavar)
				}
				slambdaargs := StringFromListStringJoin(lambdaargs, ", ")
				slambdavars := StringFromListStringJoin(lambdavars, "")
				argfn := argfunc.listarg[1]
				argfnvalue := argfn.value
				if argfunc.async {
					workvalue, msgs := LangFromValue(lang, indent,
						argfnvalue, pkgname, fnc, true, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					lambda := LangFuncLambda(lang, indent,
						ioutputnum,
						"",
						slambdaargs,
						slambdavars+
							LangVal(lang, indent, anytype,
								outputname, workvalue),
						argsubpath)
					switch arg.vxtype.name {
					case "any<-any-key-value-async", "any<-key-value-async",
						"any<-reduce-async", "any<-reduce-next-async":
						output = "" +
							LangFuncCallMethod(lang, indent,
								LangTypeT(lang, arg.vxtype),
								"vx_fn_new",
								lambda)
					default:
						if len(arglist) == 1 {
							output = "" +
								LangFuncCallMethod(lang, indent,
									LangFuncT(lang, func_any_from_any_async),
									"vx_fn_new",
									lambda)
						} else {
							output = "" +
								LangFuncCallMethod(lang, indent,
									LangFuncT(lang, func_any_from_func_async),
									"vx_fn_new",
									lambda)
						}
					}
				} else {
					work, msgs := LangFromValue(lang, indent+2,
						argfnvalue, pkgname, fnc, true, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					lambda := LangFuncLambda(lang, indent, ioutputnum, "",
						slambdaargs,
						slambdavars+
							LangVar(lang, indent+2, anytype,
								outputname, work),
						argsubpath)
					switch arg.vxtype.name {
					case "any<-int", "any<-int-any",
						"any<-any-key-value", "any<-key-value",
						"any<-reduce", "any<-reduce-next",
						"boolean<-any":
						output = "" +
							LangFuncCallMethod(lang, indent,
								LangTypeT(lang, arg.vxtype),
								"vx_fn_new",
								lambda)
					default:
						if len(arglist) == 1 {
							output = "" +
								LangFuncCallMethod(lang, indent,
									LangFuncT(lang, func_any_from_any),
									"vx_fn_new",
									lambda)
						} else {
							output = "" +
								LangFuncCallMethod(lang, indent,
									LangFuncT(lang, func_any_from_func),
									"vx_fn_new",
									lambda)
						}
					}
				}
			} else if funcname == "vx/core/let" {
				switch argindex {
				case 0:
					output = ""
				case 1:
					lambdaarglist := ListArgLocalFromFunc(fnc)
					lambdaargs, msgs := LangFuncLambdaArgIndex(lang, indent,
						lambdaarglist, 0, true, pkgname, fnc, argvalue, test, argsubpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					output = lambdaargs
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
						work, msgs := LangFromValue(lang, indent+2,
							argvalue, pkgname, fnc, true, test, argsubpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						argvaluefunc := func_any_from_func
						switch NameFromType(arg.vxtype) {
						case "vx/core/boolean<-func":
							argvaluefunc = func_boolean_from_func
						}
						lambda := LangFuncLambda(lang, indent+1, ioutputnum, "", "",
							LangVal(lang, 1, anytype,
								outputname, work),
							argsubpath)
						output = "" +
							LangFuncCallMethod(lang, indent,
								LangFuncT(lang, argvaluefunc),
								"vx_fn_new",
								lambda)
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
						work := "" +
							LangFuncCallF(lang, indent+3,
								funcargfunc,
								lambdaargtext)
						soutput := ""
						g_ifuncdepth += 1
						ioutputnum := g_ifuncdepth
						outputname := "output_" + StringFromInt(ioutputnum)
						if funcargfunc.async {
							soutput = LangVarFuture(lang, indent+2, anytype,
								outputname, work)
						} else {
							soutput = LangVar(lang, indent+2, anytype,
								outputname, work)
						}
						lambda := LangFuncLambda(lang, indent+1,
							ioutputnum, "",
							lambdatext,
							lambdavartext+
								soutput,
							argsubpath)
						output = "" +
							LangFuncCallMethod(lang, indent,
								LangTypeT(lang, arg.vxtype),
								"vx_fn_new",
								lambda)
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
					nativefunc := false
					if funcargasync && !argfuncasync {
						converttoasync = true
					}
					if argvalue.code == ":func" && argvalue.name == "native" {
						nativefunc = true
					}
					asyncindent := indent + 2
					workindent := indent + 2
					if converttoasync {
						workindent += 1
					}
					if !nativefunc {
						asyncindent += 1
						workindent += 1
					}
					work, msgs := LangFromValue(lang, workindent,
						argvalue, pkgname, fnc, true, test, argsubpath)
					if converttoasync {
						work = LangFuncCallF(lang, asyncindent,
							func_async,
							LangTypeT(lang, argfunctype),
							work)
					}
					msgblock = MsgblockAddBlock(msgblock, msgs)
					if nativefunc {
						work = "\n  " + work
						ioutputnum = -1
					} else {
						work = LangVar(lang, indent+2, anytype,
							outputname, work)
					}
					lambda := LangFuncLambda(lang, indent+1,
						ioutputnum,
						"",
						"",
						work,
						argsubpath)
					output = "" +
						LangFuncCallMethod(lang, indent,
							LangTypeT(lang, arg.vxtype),
							"vx_fn_new",
							lambda)
				}
			}
			if output == "" {
				work, msgs := LangFromValue(lang, indent,
					argvalue, pkgname, fnc, true, test, argsubpath)
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
	var argtexts []string
	multiline := false
	nativeindent := "undefined"
	islangfound := false
	isgetnative := false
	nativetext := ""
	for _, arg := range fnc.listarg {
		var argvalue = arg.value
		valuetext := ""
		if argvalue.code == "string" {
			valuetext = StringValueFromValue(argvalue)
		}
		if valuetext == ":else" {
			if !islangfound {
				islangfound = true
				isgetnative = true
			}
		} else if valuetext == (":" + lang.name) {
			if islangfound {
				msgtext := "" +
					"Duplicate Native Language Found:\n" +
					":path " + path + "\n" +
					":lang " + valuetext + "\n"
				msg := NewMsg(msgtext)
				msgblock = MsgblockAddError(msgblock, msg)
			}
			islangfound = true
			isgetnative = true
		} else if isgetnative {
			if valuetext == ":auto" {
				nativetext = valuetext
			} else if BooleanFromStringStarts(valuetext, ":") {
			} else {
				if argvalue.name == "newline" {
					nativetext = "\n"
				} else {
					clstext, msgs := LangFromValue(lang, 0,
						argvalue, pkgname, parentfn, false, test, path)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					nativetext = clstext
					if nativeindent == "undefined" {
						nativeindent = "\n" + StringRepeat(" ", argvalue.textblock.charnum)
					} else if nativeindent != "" {
						nativetext = StringFromStringFindReplace(nativetext, nativeindent, "\n")
					}
				}
				if !multiline {
					if BooleanFromStringContains(nativetext, "\n") {
						multiline = true
					} else if argvalue.name != "" {
						multiline = true
					}
					nativetext = StringRemoveQuotes(nativetext)
				}
			}
			isgetnative = false
		}
	}
	if !islangfound && nativetext == "" {
		nativetext = ":auto"
	}
	if nativetext != "" {
		if nativetext == ":auto" {
			nativetext = LangFuncNativeAuto(lang, parentfn)
		}
		argtexts = append(argtexts, nativetext)
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
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxcopy := LangFuncVxCopyModel()
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxcopy)
	} else {
		funcvxcopy.isoverride = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname,
				funcvxcopy,
				0,
				LangValClass(lang, 3,
					"output", NewTypeFromFunc(fnc), ":new"))
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
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxempty := NewFunc()
	funcvxempty.name = "vx_empty"
	funcvxempty.vxtype = anytype
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxempty)
	} else {
		funcvxempty.isoverride = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, funcvxempty, 0,
				LangVal(lang, 3, anytype,
					"output",
					LangFuncE(lang, fnc)))
	}
	return output
}

func LangFuncVxFnNew(
	lang *vxlang,
	path string,
	fnc *vxfunc,
	isinterface bool) string {
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
			vars = LangFuncIFnVars(
				lang, ifn)
			body = "" +
				LangValClass(lang, 3,
					"output", typefunc, ":new") +
				LangVarSet(lang, 3,
					"output.fn",
					"fn") +
				"\n      return output" + lang.lineend
		}
	} else {
		switch NameFromType(fnc.vxtype) {
		case "vx/core/none":
		default:
			switch len(fnc.listarg) {
			case 1:
				arg := fnc.listarg[0]
				var arginputnames []string
				var argoutputnames []string
				if !fnc.async {
					argoutputnames = append(argoutputnames, "generic_any_1")
				}
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						arginputnames = append(arginputnames,
							LangTypeTSimple(lang, fnc.vxtype, true))
					}
				}
				if fnc.context {
					arginputnames = append(arginputnames, "context")
					//argoutputnames = append(argoutputnames, "context")
				}
				arginputnames = append(arginputnames, "inputval")
				argoutputnames = append(argoutputnames, "outputval")
				funcvxanyfromany := LangFuncVxAnyFromAny(lang, fnc)
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
							LangValGeneric(lang, 3, anytype1,
								"inputval",
								LangFuncCallF(lang, 3,
									func_any_from_any,
									"generic_any_1",
									"value")) +
							LangValFutureGeneric(lang, 3, anytype1,
								"output",
								LangFuncCallF(lang, 3,
									func_async,
									"generic_any_1",
									"inputval"))
					} else {
						suppresswarnings := LangFuncSuppressWarnings(lang)
						vxasyncanyfromany := LangFuncVxAsyncAnyFromAny(lang)
						asyncbody += "" +
							LangVal(lang, 3, arg.vxtype,
								"inputval",
								LangFuncCallF(lang, 3,
									func_any_from_any,
									LangTypeT(lang, arg.vxtype),
									"value")) +
							LangValFuture(lang, 3, fnc.vxtype,
								"future",
								LangFuncCallF(lang, 3,
									fnc,
									arginputnames...)) +
							suppresswarnings +
							LangValFutureGeneric(lang, 3, anytype1,
								"output", vxasyncanyfromany)
					}
					funcs += "" +
						LangFuncHeader(lang, path, 2,
							LangFuncF(lang, fnc),
							funcvxanyfromany,
							0,
							asyncbody)
				} else {
					funcs = "" +
						LangFuncHeader(lang, path, 2,
							LangFuncF(lang, fnc),
							funcvxanyfromany,
							0,
							LangVarGeneric(lang, 3, anytype1,
								"output",
								LangFuncCallF(lang, 3,
									func_empty,
									"generic_any_1"))+
								LangVal(lang, 3, arg.vxtype,
									"inputval",
									LangVarAsType(lang,
										"value", arg.vxtype))+
								LangVal(lang, 3, anytype,
									"outputval",
									LangFuncCallF(lang, 3,
										fnc,
										arginputnames...))+
								LangVarSet(lang, 3,
									"output",
									LangFuncCallF(lang, 3,
										func_any_from_any,
										argoutputnames...)))
				}
			}
		}
	}
	if ifn != "" {
		header := LangFuncIFnHeader(
			lang, ifn, vxreturntype, isinterface)
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
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	output := ""
	funcvxfunc := NewFuncCopy(fnc)
	funcvxfunc.alias = "vx_" + LangFuncName(fnc)
	if !funcvxfunc.vxtype.isgeneric {
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
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxfunc)
	} else {
		var listargtype []string
		var listargname []string
		if !fnc.isgeneric {
		} else if fnc.generictype != nil {
			ioption := 0
			switch NameFromFunc(fnc) {
			case "vx/core/copy":
				if lang.genericcount != 1 {
					ioption = 1
				}
			case "vx/core/empty", "vx/core/new<-type":
				ioption = 1
			case "vx/core/any<-any", "vx/core/any<-any-async",
				"vx/core/any<-any-context", "vx/core/any<-any-context-async",
				"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
				"vx/core/any<-int", "vx/core/any<-int-any",
				"vx/core/any<-func", "vx/core/any<-func-async",
				"vx/core/any<-key-value", "vx/core/any<-key-value-async",
				"vx/core/any<-none", "vx/core/any<-none-async",
				"vx/core/any<-reduce", "vx/core/any<-reduce-async",
				"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
				ioption = 2
			}
			switch ioption {
			case 1:
			case 2:
				arggeneric := arggenericany1
				argtext := LangFuncArgHeader(lang,
					fnc, -1, arggeneric, true)
				listargtype = append(listargtype, argtext)
			default:
				arggeneric := LangArgGenericFromType(lang, fnc.generictype)
				argtext := LangFuncArgHeader(lang,
					fnc, -1, arggeneric, true)
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, arggeneric.alias)
			}
		}
		if fnc.context {
			argtext := LangFuncArgHeader(lang,
				fnc, -2, argcontext, false)
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
			for argidx, arg := range fnc.listarg {
				argtext := LangFuncArgHeader(lang,
					fnc, argidx, arg, isallowgeneric)
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
		funcname := LangFuncName(fnc)
		interfacefn := LangFuncInterfaceFn(lang, fnc)
		if interfacefn == "" {
			if fnc.async {
				body = "" +
					LangVarFutureGeneric(lang, 3, returntype,
						"output",
						LangPkgNameDot(lang, fnc.pkgname)+"f_"+funcname+"("+strings.Join(listargname, ", ")+")")
			} else {
				body = "" +
					LangValGeneric(lang, 3, returntype,
						"output",
						LangPkgNameDot(lang, fnc.pkgname)+"f_"+funcname+"("+strings.Join(listargname, ", ")+")")
			}
		} else {
			body = LangFuncVxFuncResolve(lang, 3,
				fnc, listargname)
		}
		funcvxfunc.isimplement = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, funcvxfunc, 0, body)
	}
	return output
}

func LangFuncVxFuncdef(
	lang *vxlang,
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxfuncdef := NewFunc()
	funcvxfuncdef.name = "vx_funcdef"
	funcvxfuncdef.vxtype = funcdeftype
	output := ""
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxfuncdef)
	} else {
		funcvxfuncdef.isimplement = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, funcvxfuncdef, 0,
				LangVal(lang, 3, funcdeftype,
					"output",
					LangFuncDefFromFunc(lang, 3, fnc)))
	}
	return output
}

func LangFuncVxNew(
	lang *vxlang,
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	returntype := NewTypeFromFunc(fnc)
	funcvxnew := LangTypeVxNewModel(returntype)
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 3,
			funcname, funcvxnew)
	} else {
		funcvxnew.isoverride = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, funcvxnew, 0,
				LangValClass(lang, 3,
					"output", NewTypeFromFunc(fnc), ":new"))
	}
	return output
}

func LangFuncVxType(
	lang *vxlang,
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxtype := NewFunc()
	funcvxtype.name = "vx_type"
	funcvxtype.vxtype = anytype
	funcname := LangFuncName(fnc)
	output := ""
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxtype)
	} else {
		funcvxtype.isoverride = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, funcvxtype, 0,
				LangVal(lang, 3, anytype,
					"output",
					LangFuncT(lang, fnc)))
	}
	return output
}

func LangFuncVxRepl(
	lang *vxlang,
	path string,
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
	funcname := LangFuncName(fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, funcvxrepl)
	} else {
		funcvxrepl.isimplement = true
		replparams := ""
		argidx := 0
		var listargname []string
		pkgname := LangPkgName(
			lang, fnc.pkgname)
		outputtype := fnc.vxtype
		outputttype := LangTypeTSimple(lang, fnc.vxtype, true)
		if !fnc.isgeneric {
		} else if fnc.generictype != nil {
			isaddgeneric := true
			switch NameFromFunc(fnc) {
			case "vx/core/copy":
				if lang.genericcount != 1 {
					isaddgeneric = false
				}
			case "vx/core/empty", "vx/core/new<-type":
				isaddgeneric = false
			}
			if isaddgeneric {
				replparam := "" +
					LangVal(lang, 3, fnc.vxtype,
						"generic_"+LangFromName(fnc.generictype.name),
						LangFuncCallF(lang, 3,
							func_any_from_any,
							outputttype,
							LangFuncCallMethod(lang, 4,
								"arglist",
								"vx_any",
								LangFuncCallVx(lang, 4,
									func_new_int,
									StringFromInt(argidx)))))
				replparams += replparam
				listargname = append(
					listargname, "generic_"+LangFromName(fnc.generictype.name))
			}
		}
		if fnc.context {
			listargname = append(
				listargname, "context")
			replparam := LangVal(lang, 3, contexttype,
				"context",
				LangFuncCallF(lang, 3,
					func_any_from_any,
					LangTypeT(lang, contexttype),
					LangFuncCallMethod(lang, 4,
						"arglist",
						"vx_any",
						LangFuncCallVx(lang, 4,
							func_new_int,
							StringFromInt(argidx)))))
			replparams += replparam
			argidx += 1
		}
		for _, arg := range fnc.listarg {
			if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
			} else {
				argname := LangFromName(arg.alias)
				replparam := "" +
					LangVal(lang, 3, arg.vxtype,
						argname,
						LangFuncCallF(lang, 3,
							func_any_from_any,
							LangTypeTSimple(lang, arg.vxtype, true),
							LangFuncCallMethod(lang, 4,
								"arglist",
								"vx_any",
								LangFuncCallVx(lang, 4,
									func_new_int,
									StringFromInt(argidx)))))
				replparams += replparam
				listargname = append(listargname, argname)
				argidx += 1
			}
		}
		if fnc.async {
			output = "" +
				LangFuncHeader(lang, path, 2,
					LangFuncName(fnc), funcvxrepl, 0,
					LangVarFuture(lang, 3, anytype,
						"output",
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_new_from_value("+
							LangTypeE(lang, anytype)+
							")")+
						replparams+
						LangVarFuture(lang, 3, outputtype,
							"future",
							pkgname+
								".f_"+funcname+
								"("+strings.Join(listargname, ", ")+")")+
						LangVarSet(lang, 3,
							"output",
							LangFuncCallVx(lang, 3,
								func_async_from_async,
								LangTypeT(lang, anytype),
								"future")))
		} else {
			output = "" +
				LangFuncHeader(lang, path, 2,
					funcname, funcvxrepl, 0,
					LangVar(lang, 3, anytype,
						"output",
						LangTypeE(lang, anytype))+
						replparams+
						LangVarSet(lang, 3,
							"output",
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
	path string,
	fnc *vxfunc,
	isinterface bool) string {
	functypedef := NewFunc()
	functypedef.name = "vx_typedef"
	functypedef.vxtype = typedeftype
	output := ""
	funcname := LangFuncFuncFull(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, path, 2,
			funcname, functypedef)
	} else {
		functypedef.isoverride = true
		output = "" +
			LangFuncHeader(lang, path, 2,
				funcname, functypedef, 0,
				LangVal(lang, 3, typedeftype,
					"output",
					LangTypeT(
						lang, functype)+lang.typeref+"vx_typedef()"))
	}
	return output
}
