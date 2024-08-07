package vxlisp

import (
	"strings"
)

func LangFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFunc")
	g_ifuncdepth = 0
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	f_func, msgs := LangFuncVxFFromFunc(lang, fnc, true)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	vx_func, msgs := LangFuncVxFFromFunc(lang, fnc, false)
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
		vx_func +
		LangValStatic(lang, "e_"+funcname, typefnc, 1, ":new") +
		LangValStatic(lang, "t_"+funcname, typefnc, 1, ":new") +
		"\n" +
		f_func
	return output, msgblock
}

func LangFuncClassHeader(lang *vxlang, fnc *vxfunc, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	funcname := LangFuncName(fnc)
	extends := LangPkgNameDot(lang, "vx/core") + "Class_base"
	switch lang.name {
	case "csharp":
		output = lineindent + "public class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {"
	case "java":
		output = lineindent + "public static class Class_" + funcname + " extends " + extends + " implements Func_" + funcname + " {"
	case "kotlin":
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
	switch lang.name {
	case "kotlin":
		output = ""
	}
	return output
}

func LangFuncFFunc(
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
			typename = LangNameTypeFromTypeSimple(lang, fnc.vxtype, true)
			returntype = LangGenericFromType(lang, fnc.generictype)
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
						argtypename = LangNameTypeFromTypeSimple(lang, anytype, true)
					default:
						arggenericname = LangGenericFromType(lang, argtype)
						argtypename = LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
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
		switch lang.name {
		case "csharp":
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
	return LangFuncHeaderAll(lang, prefix, fnc, indent, false, false, outputnum, value)
}

func LangFuncHeaderOld(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	isinterface bool,
	isstatic bool) string {
	return LangFuncHeaderAll(lang, prefix, fnc, 2, isinterface, isstatic, 0, "")
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
	returntype := LangNameTypeFullFromTypeSimple(lang, fnc.vxtype, false)
	isreturngeneric := fnc.vxtype.isgeneric
	var listargtext []string
	if fnc.generictype != nil {
		returntype = LangGenericFromType(lang, fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty",
			"f_new", "f_copy", "f_empty":
		default:
			arggeneric := NewArg("generic-" + fnc.generictype.name)
			arggeneric.vxtype = fnc.generictype
			argtext := LangArgHeader(lang, arggeneric, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	if fnc.context {
		argtext := LangArgHeader(lang, argcontext, isreturngeneric)
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
			argtext := LangArgHeader(lang, arg, isreturngeneric)
			listargtext = append(listargtext, argtext)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
	genericdef1, genericdef2, genericdef3 := LangFuncGenericDefinition(
		lang, fnc)
	override1 := ""
	override2 := ""
	override3 := ""
	sindent := "\n" + StringRepeat("  ", indent)
	if fnc.isoverride {
		switch lang.name {
		case "csharp":
			override3 = "override "
		case "java":
			override1 = sindent + "@Override"
		case "kotlin":
			override2 = "override "
		}
	}
	if fnc.isimplement {
		switch lang.name {
		case "java":
			override1 = sindent + "@Override"
		}
	}
	if fnc.isimplement2 {
		switch lang.name {
		case "csharp":
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
	switch lang.name {
	case "cpp":
		funcprefix = prefix + "::"
	}
	if fnc.async {
		returntype = lang.future + "<" + returntype + ">"
	}
	returntype1 := ""
	returntype2 := ""
	switch lang.name {
	case "cpp", "csharp", "java":
		returntype1 = returntype + " "
	case "kotlin":
		returntype2 = " : " + returntype
	case "swift":
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

func LangFuncHeaderCall(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangFuncHeaderInterface(lang *vxlang, prefix string, fnc *vxfunc, indent int) string {
	output := LangFuncHeaderAll(lang, prefix, fnc, indent, true, false, 0, "")
	return output
}

func LangFuncHeaderStatic(
	lang *vxlang,
	prefix string,
	fnc *vxfunc,
	indent int,
	outputnum int,
	value string) string {
	return LangFuncHeaderAll(lang, prefix, fnc, indent, false, true, outputnum, value)
}

func LangFuncInstanceStatic(lang *vxlang) (string, string) {
	funcinstance := "function "
	funcstatic := "function "
	switch lang.name {
	case "cpp", "csharp", "java":
		funcinstance = "public "
		funcstatic = "public static "
	case "kotlin":
		funcinstance = "fun "
		funcstatic = "fun "
	case "swift":
		funcinstance = "func "
		funcstatic = "func static "
	}
	return funcinstance, funcstatic
}

func LangFuncInterface(lang *vxlang, fnc *vxfunc) string {
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
	switch lang.name {
	case "csharp":
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case "java":
		if extends != "" {
			extends = " extends " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case "kotlin":
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	}
	return output
}

func LangFuncT(lang *vxlang, fnc *vxfunc) string {
	name := "t_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
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
					LangNameEFromFunc(lang, fnc)))
	}
	return output
}

func LangFuncVxFnNew(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	output := ""
	ifn := ""
	vars := ""
	body := ""
	funcs := ""
	vxreturntype := LangNameFuncFullFromFunc(lang, fnc)
	typefunc := NewTypeFromFunc(fnc)
	contextname := ""
	if fnc.context {
		contextname = "-context"
	}
	asyncname := ""
	if fnc.async {
		asyncname = "-async"
	}
	snullable := ""
	switch lang.name {
	case "csharp":
		snullable = "?"
	}
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
		ifn = LangNameClassFullFromFunc(lang, fnc) + lang.typeref + "IFn"
		if !isinterface {
			switch lang.name {
			case "kotlin":
				vars += "" +
					"\n    var fn : " + ifn + " = null" + lang.lineend +
					"\n"
			default:
				vars += "" +
					"\n    public " + ifn + snullable + " fn = null" + lang.lineend +
					"\n"
			}
			body = "" +
				LangValClass(lang, "output", typefunc, 3, ":new") +
				"\n      output.fn = fn" + lang.lineend +
				"\n      return output" + lang.lineend
		}
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		ifn = LangPkgNameDot(lang, "vx/core") + "Class_any_from_func" + lang.typeref + "IFn" + snullable
		if !isinterface {
			switch lang.name {
			case "kotlin":
				vars += "" +
					"\n    var fn : " + ifn + " = null" + lang.lineend +
					"\n"
			default:
				vars += "" +
					"\n    public " + ifn + " fn = null" + lang.lineend +
					"\n"
			}
			body = "" +
				LangValClass(lang, "output", typefunc, 3, ":new") +
				//"\n      " + classname + " output = new " + classname + "()" + lang.lineend +
				"\n      output.fn = fn" + lang.lineend +
				"\n      return output" + lang.lineend
		}
	default:
		//		returntype := ""
		//		if fnc.generictype == nil {
		//			returntype = LangGenericFromType(lang, fnc.vxtype)
		//		} else {
		//			returntype = LangGenericFromType(lang, fnc.generictype)
		//		}
		switch NameFromType(fnc.vxtype) {
		case "vx/core/none":
		default:
			switch len(fnc.listarg) {
			case 1:
				//argtypename := ""
				arg := fnc.listarg[0]
				//argtypename = LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
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
				vxreturntype = LangNameFuncFullFromFunc(lang, funcanyfromany)
				ifn = LangNameClassFullFromFunc(lang, funcanyfromany) + lang.typeref + "IFn"
				body = "" +
					"\n      return " + LangNameEFromFunc(lang, funcanyfromany) + lang.lineend
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
							"\n      T inputval = " + LangPkgNameDot(lang, "vx/core") + "f_any_from_any(generic_any_1, value)" + lang.lineend +
							"\n      " + lang.future + "<T> output = " + LangPkgNameDot(lang, "vx/core") + "f_async(generic_any_1, inputval)" + lang.lineend
					} else {
						suppresswarnings := ""
						switch lang.name {
						case "java":
							suppresswarnings = "\n      @SuppressWarnings(\"unchecked\")"
						}
						vxasyncanyfromany := ""
						switch lang.name {
						case "csharp":
							vxasyncanyfromany = LangPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future)"
						case "java":
							vxasyncanyfromany = "(" + lang.future + "<T>)future"
						case "kotlin":
							vxasyncanyfromany = "future as (" + lang.future + "<T>)"
						}
						asyncbody += "" +
							LangVar(lang, "inputval", arg.vxtype, 3,
								LangPkgNameDot(lang, "vx/core")+"f_any_from_any("+LangTypeT(lang, arg.vxtype)+", value)") +
							LangVarFuture(lang, "future", fnc.vxtype, 3,
								LangNameFFromFunc(lang, fnc)+"("+arginputnames+")") +
							suppresswarnings +
							"\n      " + lang.future + "<T> output = " + vxasyncanyfromany + lang.lineend
					}
					funcs += "" +
						LangFuncHeader(lang, LangNameFFromFunc(lang, fnc), funcvxanyfromany,
							2, 0, asyncbody)
				} else {
					funcs = "" +
						LangFuncHeader(lang, LangNameFFromFunc(lang, fnc), funcvxanyfromany, 2, 0,
							LangVarGeneric(lang, "output", anytype1, 3,
								LangPkgNameDot(lang, "vx/core")+"f_empty(generic_any_1)")+
								LangVar(lang, "inputval", arg.vxtype, 3,
									LangAsType(lang, "value", arg.vxtype))+
								LangVar(lang, "outputval", anytype, 3,
									LangNameFFromFunc(lang, fnc)+"("+arginputnames+")")+
								LangVarSet(lang, "output", 3,
									LangNameFFromFunc(lang, funcanyfromany)+"(generic_any_1, "+argoutputnames+")"))
				}
			}
		}
	}
	if ifn != "" {
		header := ""
		override := ""
		if !isinterface {
			switch lang.name {
			case "kotlin":
				override = "override "
			case "java":
				override = "\n    @Override"
			}
		}
		switch lang.name {
		case "csharp":
			header = "\n    " + override + "public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		case "java":
			header = "" +
				override +
				"\n    public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		case "kotlin":
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
	funcname := LangNameFuncFullFromFunc(lang, fnc)
	if isinterface {
		output = LangFuncHeaderInterface(lang, funcname, funcvxfunc, 2)
	} else {
		funcvxfunc.isimplement = true
		output = "" +
			LangFuncHeader(lang, funcname, funcvxfunc, 2, 0,
				LangVar(lang, "output", typedeftype, 3,
					LangTypeT(lang, functype)+lang.typeref+"vx_typedef()"))
	}
	return output
}

func LangFuncVxFFromFunc(lang *vxlang, fnc *vxfunc, ismain bool) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFuncVxF")
	var listargtype []string
	var listargname []string
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	pkgname := LangNameFromPkgName(lang, fnc.pkgname)
	path := fnc.pkgname + "/" + fnc.name + LangIndexFromFunc(fnc)
	genericdefinition1, genericdefinition2, genericdefinition3 := LangFuncGenericDefinition(lang, fnc)
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
			argtext := LangFinalArg(lang) + "T generic_any_1"
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				genericargname := LangTypeTGeneric(lang, fnc.generictype)
				argtext := LangFinalArg(lang) + LangGenericFromType(lang, fnc.generictype) + " " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, LangFinalArg(lang)+LangTypeName(lang, contexttype)+" context")
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
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if fnc.generictype != nil && argtype.isgeneric {
				argtypename = LangGenericFromType(lang, argtype)
			} else {
				argtypename = LangNameTypeFromTypeSimple(lang, argtype, true)
			}
			argtext := LangFinalArg(lang) + argtypename + " " + LangFromName(arg.alias)
			listargname = append(listargname, LangFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	var returntype *vxtype
	sreturntype := ""
	if fnc.generictype == nil {
		returntype = fnc.vxtype
		sreturntype = LangGenericFromType(lang, fnc.vxtype)
	} else {
		returntype = fnc.generictype
		sreturntype = LangGenericFromType(lang, fnc.generictype)
	}
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = LangGenericFromType(lang, fnc.generictype)
	} else {
		functypetext = sreturntype
	}
	if fnc.async {
		functypetext = lang.future + "<" + functypetext + ">"
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
		permissiontop = lineindent + "if (" + LangPkgNameDot(lang, "vx/core") + "f_boolean_permission_from_func(context, " + LangFuncT(lang, fnc) + ").vx_boolean()) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			LangVar(lang, "msg", msgtype, 3,
				LangPkgNameDot(lang, "vx/core")+
					"vx_msg_from_error(\"vx/core/func\", \":permissiondenied\", "+
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\""+fnc.name+"\"))") +
			LangVarSet(lang, "output", 3, LangPkgNameDot(lang, "vx/core")+"vx_copy(output, msg)") +
			lineindent + "}"
		subindent += 1
		ssubindent += "  "
	}
	linesubindent := "\n" + ssubindent
	if fnc.messages {
		msgtop = linesubindent + "try {"
		msgbottom = "" +
			linesubindent + "} catch (Exception err) {" +
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
	interfacefn := LangFuncInterfaceFn(lang, fnc)
	output := ""
	if ismain {
		valuetext, msgs := LangFromValue(lang, fnc.value, fnc.pkgname, fnc, 0, true, false, path)
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
			switch lang.name {
			case "java":
				f_suppresswarnings = "\n  @SuppressWarnings(\"unchecked\")"
			}
		}
		valuetext = StringFromListStringJoin(chgvaluetexts, "\n")
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
			valuetext = linesubindent + StringFromStringIndent(valuetext, ssubindent)
		}
		defaultvalue := ""
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			//if fnc.vxtype.name == "none" {
			if fnc.async {
				defaultvalue = lineindent + lang.future + "<" + sreturntype + "> output = " + LangPkgNameDot(lang, "vx/core") + "vx_async_new_from_value(" + LangTypeE(lang, fnc.vxtype) + ")" + lang.lineend
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
			LangFuncFFunc(lang, fnc, false, ""+
				debugtop+
				defaultvalue+
				permissiontop+
				msgtop+
				valuetext+
				msgbottom+
				permissionbottom+
				debugbottom)
	} else {
		returnvalue := ""
		if interfacefn == "" {
			switch sreturntype {
			case "void", "Unit":
			default:
				returnvalue += "\n      return "
			}
			returnvalue += pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ")" + lang.lineend
		} else if fnc.async {
			resolve := ""
			switch lang.name {
			case "java":
				resolve = "fn.resolve(" + strings.Join(listargname, ", ") + ")"
			default:
				resolve = "fn(" + strings.Join(listargname, ", ") + ")"
			}
			returnvalue += "" +
				LangVarFutureGeneric(lang, "output", returntype, 3, "") +
				"\n      if (fn == null) {" +
				LangVarSet(lang, "output", 4,
					LangPkgNameDot(lang, "vx/core")+
						"vx_async_new_from_value("+
						LangPkgNameDot(lang, "vx/core")+
						"f_empty(generic_any_1))") +
				"\n      } else {" +
				LangVarFuture(lang, "future", anytype, 4, resolve) +
				LangVarSet(lang, "output", 4,
					LangPkgNameDot(lang, "vx/core")+
						"vx_async_from_async(generic_any_1, future)") +
				"\n      }" +
				"\n      return output" + lang.lineend
		} else {
			resolve := ""
			switch lang.name {
			case "java":
				resolve = "fn.resolve(" + strings.Join(listargname, ", ") + ")"
			default:
				resolve = "fn(" + strings.Join(listargname, ", ") + ")"
			}
			if BooleanFromStringStarts(fnc.name, "boolean<-") {
				returnvalue += "" +
					LangVar(lang, "output", booleantype, 3,
						LangPkgNameDot(lang, "vx/core")+"c_false") +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, 4, resolve) +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+
							"f_any_from_any("+
							LangTypeT(lang, booleantype)+
							", anyoutput)") +
					"\n      }"
			} else if BooleanFromStringStarts(fnc.name, "int<-") {
				returnvalue += "" +
					LangVar(lang, "output", inttype, 3, LangTypeE(lang, inttype)) +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, 4, resolve) +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+
							"f_any_from_any("+
							LangTypeT(lang, inttype)+
							", anyoutput)") +
					"\n      }"
			} else if BooleanFromStringStarts(fnc.name, "string<-") {
				returnvalue += "" +
					LangVar(lang, "output", stringtype, 3,
						LangTypeE(lang, stringtype)) +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, 4, resolve) +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+
							"f_any_from_any("+
							LangTypeT(lang, stringtype)+
							", anyoutput)") +
					"\n      }"
			} else {
				returnvalue += "" +
					LangVarGeneric(lang, "output", anytype1, 3,
						LangPkgNameDot(lang, "vx/core")+"f_empty(generic_any_1)") +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, 4, resolve) +
					LangVarSet(lang, "output", 4,
						LangPkgNameDot(lang, "vx/core")+"f_any_from_any(generic_any_1, anyoutput)") +
					"\n      }"
			}
			switch sreturntype {
			case "Unit", "void":
			default:
				returnvalue += "\n      return output" + lang.lineend
			}
		}
		override1, override2, override3 := LangOverride(lang, 2, true)
		funcinstance, _ := LangFuncInstanceStatic(lang)
		output = "" +
			override1 +
			"\n    " + override2 + funcinstance + override3 + genericdefinition1 + functypetext + " vx_" + funcname + genericdefinition2 + "(" + strings.Join(listargtype, ", ") + ")" + genericdefinition3 + " {" +
			returnvalue +
			"\n    }" +
			"\n" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func LangFuncVxFuncdef(
	lang *vxlang,
	fnc *vxfunc,
	isinterface bool) string {
	funcvxfuncdef := NewFunc()
	funcvxfuncdef.name = "vx_funcdef"
	funcvxfuncdef.vxtype = funcdeftype
	output := ""
	funcname := LangNameFuncFullFromFunc(lang, fnc)
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
	if isinterface {
	} else {
		replparams := ""
		argidx := 0
		var listargname []string
		pkgname := LangNameFromPkgName(lang, fnc.pkgname)
		funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
		outputtype := anytype
		outputttype := ""
		switch NameFromType(fnc.vxtype) {
		//		case "vx/core/none":
		//outputtype = LangTypeFromType(lang, anytype)
		//			outputttype = LangNameTFromType(lang, anytype)
		default:
			outputtype = fnc.vxtype
			//outputtype = LangNameTypeFromTypeSimple(lang, fnc.vxtype, true)
			outputttype = LangTypeTSimple(lang, fnc.vxtype, true)
		}
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
				LangFuncHeader(lang, LangFuncName(fnc), funcvxrepl, 2, 0,
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
	funcname := LangNameFuncFullFromFunc(lang, fnc)
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
