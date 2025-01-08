package vxlisp

import (
	"strings"
)

var langcpp = NewLangCpp()
var langcsharp = NewLangCsharp()
var langjava = NewLangJava()
var langjs = NewLangJs()
var langkotlin = NewLangKotlin()
var langswift = NewLangSwift()

var listlang = []*vxlang{
	langcpp,
	langcsharp,
	langjava,
	langjs,
	langkotlin,
	langswift}

var maplang = NewMapLangFromList(listlang)

func NewLangCpp() *vxlang {
	output := new(vxlang)
	output.name = "cpp"
	output.sourcename = "core"
	output.sourcefile = ".cpp"
	output.headerfile = ".hpp"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "::"
	output.future = "Async"
	output.indent = "  "
	output.lineend = ";"
	output.typeref = "->"
	output.memmanage = true
	output.forcemulti = true
	return output
}

func NewLangCsharp() *vxlang {
	output := new(vxlang)
	output.name = "csharp"
	output.sourcename = "Core"
	output.sourcefile = ".cs"
	output.pkgpath = "Vx.Core"
	output.pkgname = "Vx.Core"
	output.pkgref = "."
	output.future = "Task"
	output.indent = "  "
	output.lineend = ";"
	output.itfext = ":"
	output.classext = ":"
	output.typeref = "."
	return output
}

func NewLangJava() *vxlang {
	output := new(vxlang)
	output.name = "java"
	output.sourcename = "Core"
	output.sourcefile = ".java"
	output.pkgpath = "vx_core"
	output.pkgname = "Core"
	output.pkgref = "."
	output.future = "CompletableFuture"
	output.indent = "  "
	output.lineend = ";"
	output.itfext = "extends"
	output.classext = "extends"
	output.typeref = "."
	return output
}

func NewLangJs() *vxlang {
	output := new(vxlang)
	output.name = "js"
	output.sourcename = "core"
	output.sourcefile = ".js"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ""
	output.typeref = "."
	return output
}

func NewLangKotlin() *vxlang {
	output := new(vxlang)
	output.name = "kotlin"
	output.sourcename = "Core"
	output.sourcefile = ".kt"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.future = "CompletableFuture"
	output.indent = "  "
	output.lineend = ""
	output.classext = ":"
	output.typeref = "."
	return output
}

func NewLangSwift() *vxlang {
	output := new(vxlang)
	output.name = "swift"
	output.sourcename = "Core"
	output.sourcefile = ".swift"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ""
	output.typeref = "."
	return output
}

func NewMapLangFromList(listlang []*vxlang) map[string]*vxlang {
	output := make(map[string]*vxlang)
	for _, lang := range listlang {
		key := ":" + lang.name
		output[key] = lang
	}
	return output
}

func LangNativeAppArgListInit(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = LangVar(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
	case langjava:
		output = LangVal(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
	case langkotlin:
		output = LangVal(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(*args)")
	}
	return output
}

func LangNativeAppClassOpenClose(
	lang *vxlang) (string, string) {
	classopen := ""
	classclose := ""
	indent0 := LangIndent(lang, 0, true)
	switch lang {
	case langcsharp:
		classopen = indent0 + "class App {\n"
		classclose = indent0 + "}\n"
	case langjava:
		classopen = indent0 + "public final class App {\n"
		classclose = indent0 + "}\n"
	case langkotlin:
	}
	return classopen, classclose
}

func LangNativeAppMainOpenClose(
	lang *vxlang) (string, string) {
	mainopen := ""
	mainclose := ""
	indent1 := LangIndent(lang, 1, true)
	switch lang {
	case langcsharp:
		mainopen = indent1 + "static void Main(string[] args) {"
		mainclose = indent1 + "}\n"
	case langjava:
		mainopen = indent1 + "public static void main(String[] args) {"
		mainclose = indent1 + "}\n"
	case langkotlin:
		mainopen = indent1 + "fun main(args : Array<String>) {"
		mainclose = indent1 + "}\n"
	}
	return mainopen, mainclose
}

func LangNativeAppOutputPrint(
	lang *vxlang) string {
	indent3 := LangIndent(lang, 3, true)
	printline := LangNativePrintLine(lang)
	output := indent3 + printline + "(output)" + lang.lineend
	return output
}

func LangNativeAppTryOpenClose(
	lang *vxlang) (string, string) {
	tryopen := ""
	tryclose := ""
	indent2 := LangIndent(lang, 2, true)
	indent3 := LangIndent(lang, 3, true)
	switch lang {
	case langcsharp:
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.Console.WriteLine(\"Untrapped Error!\" + e.ToString())" + lang.lineend +
			indent2 + "}"
	case langjava:
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.out.println(\"Untrapped Error!\" + e.toString())" + lang.lineend +
			indent2 + "}"
	case langkotlin:
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (e : Exception) {" +
			indent3 + "println(e.toString())" +
			indent2 + "}"
	}
	return tryopen, tryclose
}

func LangNativeArgHeader(
	lang *vxlang,
	arg vxarg,
	isallowgeneric bool) string {
	output := ""
	sfinal := ""
	if arg.isfinal {
		sfinal = LangNativeFinalArg(lang)
	}
	sargname := LangFromName(arg.name)
	typ := arg.vxtype
	stypename := ""
	if typ.isgeneric {
		if isallowgeneric {
			stypename = LangGenericFromType(lang, typ)
		} else {
			stypename = LangNameTypeFromTypeSimple(lang, typ, true)
		}
	} else {
		stypename = LangTypeName(lang, typ)
	}
	smulti1 := ""
	smulti2 := ""
	if arg.multi {
		if arg.vxtype.extends != ":list" {
			switch lang {
			case langcsharp:
				smulti1 = "params "
				smulti2 = "[]"
			case langjava, langswift:
				smulti2 = "..."
			case langkotlin:
				smulti1 = "vararg "
			}
		}
	}
	switch lang {
	case langkotlin, langswift:
		output = "" + sfinal + smulti1 + sargname + smulti2 + " : " + stypename
	default:
		output = "" + sfinal + smulti1 + stypename + smulti2 + " " + sargname
	}
	return output
}

func LangNativeArgTypeName(
	lang *vxlang,
	argname string,
	argtype *vxtype) string {
	argtypename := LangTypeName(lang, argtype)
	output := ""
	switch lang {
	case langkotlin:
		output = argname + " : " + argtypename
	default:
		output = argtypename + " " + argname
	}
	return output
}

func LangNativeArgTypeNameValue(
	lang *vxlang,
	argname string,
	typ *vxtype) string {
	argtypename := LangTypeName(lang, typ)
	output := ""
	switch lang {
	case langkotlin:
		output = argname + "_any : " + argtypename
	default:
		output = argtypename + " " + argname + "_any"
	}
	return output
}

func LangNativeAsClass(
	lang *vxlang,
	svar string,
	typ *vxtype) string {
	typetext := ""
	// SomeClass obj2 = (SomeClass)Convert.ChangeType(t, typeof(SomeClass));
	switch typ {
	case rawlistunknowntype:
		switch lang {
		case langcsharp:
			typetext = "List<object>"
		case langjava:
			typetext = "List<?>"
		case langkotlin:
			typetext = "List<Any>"
		default:
			typetext = LangTypeClassFull(lang, typ)
		}
	default:
		typetext = LangTypeClassFull(lang, typ)
	}
	return LangNativeAsTypeText(lang, svar, typetext)
}

func LangNativeAsType(
	lang *vxlang,
	svar string,
	typ *vxtype) string {
	typetext := ""
	// SomeClass obj2 = (SomeClass)Convert.ChangeType(t, typeof(SomeClass));
	switch typ {
	case rawlistunknowntype:
		switch lang {
		case langcsharp:
			typetext = "List<object>"
		case langjava:
			typetext = "List<?>"
		case langkotlin:
			typetext = "List<Any>"
		default:
			typetext = LangNameTypeFullFromType(lang, typ)
		}
	default:
		typetext = LangNameTypeFullFromType(lang, typ)
	}
	return LangNativeAsTypeText(lang, svar, typetext)
}

func LangNativeAsTypeText(
	lang *vxlang,
	svar string,
	stype string) string {
	output := ""
	switch lang {
	case langcsharp:
		switch stype {
		case "bool":
			output = "(bool)" + svar
		case "float":
			output = "(float)" + svar
		case "int":
			output = "Convert.ToInt32(" + svar + ")"
		default:
			output = "(" + stype + ")" + svar
		}
	case langjava:
		output = "(" + stype + ")" + svar
	case langkotlin:
		output = svar + " as " + stype
	}
	return output
}

func LangNativeConstClassHeader(
	lang *vxlang,
	cnst *vxconst,
	indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	constname := "Const_" + LangFromName(cnst.alias)
	switch lang {
	case langcsharp:
		output = lineindent + "public class " + constname + " {"
	case langjava:
		output = lineindent + "public static class " + constname + " {"
	case langkotlin:
		output = "" +
			lineindent + "class " + constname + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangNativeConstStaticOpenClose(
	lang *vxlang) (string, string) {
	staticopen := ""
	staticclose := ""
	switch lang {
	case langkotlin:
		staticopen = "" +
			"\n    companion object {" +
			"\n"
		staticclose = "\n    }"
	}
	return staticopen, staticclose
}

func LangNativeElseIfType(
	lang *vxlang,
	typ *vxtype,
	subtype *vxtype,
	svar string,
	scastvar string,
	indent int,
	isfuture bool) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langcsharp:
		if scastvar == "" {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		} else {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + " " + scastvar + ") {"
		}
	case langjava, langkotlin:
		output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		if scastvar != "" {
			output += LangVarOld(lang, scastvar, typ, subtype, LangNativeAsType(lang, svar, typ), indent+1, false, isfuture)
		}
	}
	return output
}

func LangNativeFinalArg(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangNativeFinalClass(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangNativeFinalVar(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangNativeForListHeader(
	lang *vxlang,
	forvar string,
	typ *vxtype,
	listvar string,
	indent int) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langcsharp:
		output = sindent + "foreach (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " in " + listvar + ") {"
	case langjava:
		output = sindent + "for (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " : " + listvar + ") {"
	case langkotlin:
		output = sindent + "for (" + forvar + " : " + LangNameTypeFullFromType(lang, typ) + " in " + listvar + ") {"
	}
	return output
}

func LangNativeFromText(
	lang *vxlang,
	text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\r", "")
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	switch lang {
	case langkotlin:
		output = strings.ReplaceAll(output, "$", "\\$")
	}
	return output
}

func LangNativeFuncClassHeader(
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

func LangNativeFuncGenericDefinition(
	lang *vxlang,
	mapgeneric map[string]string) (string, string, string) {
	output1 := ""
	output2 := ""
	output3 := ""
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
	return output1, output2, output3
}

func LangNativeFuncIFnHeader(
	lang *vxlang,
	ifn string,
	vxreturntype string,
	isinterface bool) string {
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
	return header
}

func LangNativeFuncIFnVars(
	lang *vxlang,
	ifn string) string {
	vars := ""
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
	return vars
}

func LangNativeFuncInstanceStatic(
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

func LangNativeFuncInterface(
	lang *vxlang,
	fnc *vxfunc,
	extends string,
	interfaces string,
	indent int) string {
	output := ""
	funcname := LangFuncName(fnc)
	lineindent := LangIndent(lang, indent, true)
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

func LangNativeFuncInterfaceFn(
	lang *vxlang,
	fnc *vxfunc) string {
	interfaces := ""
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
		"vx/core/boolean<-any",
		"vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/none<-any":
		returntype := LangTypeName(lang, anytype)
		if fnc.async {
			returntype = lang.future + "<" + LangTypeName(lang, anytype) + ">"
		}
		//		}
		var args []string
		if fnc.context {
			contextarg := ""
			switch lang {
			case langkotlin:
				contextarg = "context : " + LangTypeName(lang, contexttype)
			default:
				contextarg = LangTypeName(lang, contexttype) + " context"
			}
			args = append(args, contextarg)
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argname := LangFromName(arg.alias)
			argtypename := LangNameTypeFromTypeSimple(
				lang, argtype, true)
			argtext := ""
			switch lang {
			case langkotlin:
				argtext = argname + " : " + argtypename
			default:
				argtext = argtypename + " " + argname
			}
			args = append(args, argtext)
		}
		argnames := StringFromListStringJoin(args, ", ")
		switch lang {
		case langcsharp:
			interfaces = "" +
				"\n    public delegate " + returntype + " IFn(" + argnames + ")" + lang.lineend +
				"\n"
		case langjava:
			interfaces = "" +
				"\n    @FunctionalInterface" +
				"\n    public interface IFn {" +
				"\n      public " + returntype + " resolve(" + argnames + ")" + lang.lineend +
				"\n    }" +
				"\n"
		case langkotlin:
			interfaces = "" +
				"\n    fun interface IFn {" +
				"\n      fun resolve(" + argnames + ") : " + returntype +
				"\n    }" +
				"\n"
		}
	}
	return interfaces
}

func LangNativeFuncLambdaArgName(
	lang *vxlang,
	lambdaarg vxarg) string {
	output := lambdaarg.name + "_any"
	switch lang {
	case langkotlin:
		output += " : vx_core.Type_any"
	}
	return output
}

func LangNativeFuncLambdaFooter(
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

func LangNativeFuncLambdaHeader(
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
	case langjava, langjs:
		output = "(" + args + ") -> {"
	case langkotlin:
		output = "{" + args + " ->"
	}
	return output
}

func LangNativeFuncNativeAuto(
	lang *vxlang,
	fnc *vxfunc) string {
	output := ""
	var listargname []string
	if fnc.generictype != nil {
		argname := LangTypeTGeneric(lang, fnc.generictype)
		listargname = append(listargname, argname)
	}
	if fnc.context {
		argname := "context"
		listargname = append(listargname, argname)
	}
	for _, arg := range fnc.listarg {
		argname := LangNameFromArg(lang, arg)
		listargname = append(listargname, argname)
	}
	argnames := StringFromListStringJoin(listargname, ", ")
	output = LangNativePkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangFuncName(fnc) + "(" + argnames + ")" + lang.lineend
	switch lang {
	case langcpp:
		if fnc.generictype != nil {
			argname := LangTypeTGeneric(lang, fnc.generictype)
			output = "" +
				"vx_core::Type_any result = " + output +
				"\noutput = vx_core::vx_any_from_any(" + argname + ", result)" + lang.lineend
		}
	}
	return output
}

func LangNativeFuncNewSuppressWarnings(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langjava:
		output = "\n  @SuppressWarnings(\"unchecked\")"
	}
	return output
}

func LangNativeFuncOverride(
	lang *vxlang,
	fnc *vxfunc,
	sindent string) (string, string, string) {
	override1 := ""
	override2 := ""
	override3 := ""
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
	return override1, override2, override3
}

func LangNativeFuncPrefixReturnTypes(
	lang *vxlang,
	prefix string,
	returntype string) (string, string, string) {
	funcprefix := ""
	returntype1 := ""
	returntype2 := ""
	switch lang {
	case langcpp:
		funcprefix = prefix + "::"
	}
	switch lang {
	case langcpp, langcsharp, langjava:
		returntype1 = returntype + " "
	case langkotlin:
		returntype2 = " : " + returntype
	case langswift:
		returntype2 = " -> " + returntype
	}
	return funcprefix, returntype1, returntype2
}

func LangNativeFuncSuppressWarnings(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langjava:
		output = "\n      @SuppressWarnings(\"unchecked\")"
	}
	return output
}

func LangNativeFuncTryCatch(
	lang *vxlang,
	linesubindent string) (string, string) {
	try := ""
	catch := ""
	switch lang {
	case langkotlin:
		try = linesubindent + "try {"
		catch = linesubindent + "} catch (err : Exception) {"
	default:
		try = linesubindent + "try {"
		catch = linesubindent + "} catch (Exception err) {"
	}
	return try, catch
}

func LangNativeFuncVxAsyncAnyFromAny(
	lang *vxlang) string {
	vxasyncanyfromany := ""
	switch lang {
	case langcsharp:
		vxasyncanyfromany = LangPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future)"
	case langjava:
		vxasyncanyfromany = "(" + lang.future + "<T>)future"
	case langkotlin:
		vxasyncanyfromany = "future as (" + lang.future + "<T>)"
	}
	return vxasyncanyfromany
}

func LangNativeFuncVxFuncResolve(
	lang *vxlang,
	listargname []string) string {
	output := ""
	switch lang {
	case langjava, langkotlin:
		output = "fnlocal.resolve(" + strings.Join(listargname, ", ") + ")"
	default:
		output = "fnlocal(" + strings.Join(listargname, ", ") + ")"
	}
	return output
}

func LangNativeIfClause(
	lang *vxlang,
	typ *vxtype,
	op string,
	left string,
	right string) string {
	sop := op
	sleft := left
	sright := right
	switch lang {
	case langjava:
		switch op {
		case "==":
			switch typ {
			case rawstringtype:
				sop = ".equals(" + sright + ")"
				sright = ""
			}
		}
	default:
		sop = " " + op + " "
	}
	output := "(" + sleft + sop + sright + ")"
	return output
}

func LangNativeImport(
	lang *vxlang,
	pkg *vxpackage,
	imports string) string {
	output := ""
	pkgname := pkg.name
	project := pkg.project
	importline := ""
	switch lang {
	case langcpp:
		importline = "#include \"" + pkgname + ".hpp\""
	case langcsharp:
	case langjava:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name
		importline = "import " + importname + lang.lineend
	case langkotlin:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		importname := project.javadomain + "." + path + ".*"
		importline = "import " + importname
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangNativeIsTypeText(
	lang *vxlang,
	svar string,
	stype string) string {
	output := ""
	switch lang {
	case langcpp:
		output = "vx_core::vx_boolean_from_type_trait(" + svar + ", " + stype + ")"
	case langcsharp, langkotlin:
		output = svar + " is " + stype
	case langjava:
		output = svar + " instanceof " + stype
	}
	return output
}

func LangNativeNamespaceOpenClose(
	lang *vxlang,
	pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang {
	case langcpp:
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langcsharp:
		if pkgname == "AppTest" {
			namespaceopen = "" +
				"\n" +
				"\nnamespace AppTest" + lang.lineend +
				"\n" +
				"\npublic class AppTest(Xunit.Abstractions.ITestOutputHelper output) {" +
				"\n" +
				"\n  bool isconsole = TestLib.EnableConsole(output)" + lang.lineend +
				"\n"
			namespaceclose = "\n}\n"
		} else {
			ipos := IntFromStringFindLast(pkgname, ".")
			after := StringSubstring(pkgname, ipos+1, len(pkgname))
			namespaceopen = "\npublic static class " + after + " {\n\n"
			namespaceclose = "\n}\n"
		}
	case langjava:
		namespaceopen = "\npublic final class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langjs:
		namespaceopen = "\nexport default class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langkotlin:
		namespaceopen = "" +
			"\nobject " + pkgname + " {" +
			"\n" +
			"\n"
		namespaceclose = "\n}\n"
	}
	return namespaceopen, namespaceclose
}

func LangNativeOverride(
	lang *vxlang,
	indent int,
	isinterface bool) (string, string, string) {
	override1 := ""
	override2 := ""
	override3 := ""
	switch lang {
	case langcsharp:
		if !isinterface {
			override3 = "override "
		}
	case langjava:
		override1 = "\n" + StringRepeat("  ", indent) + "@Override"
	case langkotlin:
		if !isinterface {
			override2 = "override "
		}
	}
	return override1, override2, override3
}

func LangNativePackageImports(
	lang *vxlang,
	pkg *vxpackage,
	pkgprefix string,
	body string,
	test bool) string {
	output := ""
	switch lang {
	case langjava:
		if BooleanFromStringContains(body, "Arrays.") {
			output += "\nimport java.util.Arrays" + lang.lineend
		}
		if BooleanFromStringContains(body, " ArrayList<") {
			output += "\nimport java.util.ArrayList" + lang.lineend
		}
		if BooleanFromStringContains(body, "Collections.") {
			output += "\nimport java.util.Collections" + lang.lineend
		}
		if BooleanFromStringContains(body, " CompletableFuture<") {
			output += "\nimport java.util.concurrent.CompletableFuture" + lang.lineend
		}
		if BooleanFromStringContains(body, " ConcurrentLinkedDeque<") {
			output += "\nimport java.util.concurrent.ConcurrentLinkedDeque" + lang.lineend
		}
		if BooleanFromStringContains(body, " ConcurrentHashMap<") {
			output += "\nimport java.util.concurrent.ConcurrentHashMap" + lang.lineend
		}
		if BooleanFromStringContains(body, " Deque<") {
			output += "\nimport java.util.Deque" + lang.lineend
		}
		if BooleanFromStringContains(body, " LinkedHashMap<") {
			output += "\nimport java.util.LinkedHashMap" + lang.lineend
		}
		if BooleanFromStringContains(body, " List<") {
			output += "\nimport java.util.List" + lang.lineend
		}
		if BooleanFromStringContains(body, " Map<") {
			output += "\nimport java.util.Map" + lang.lineend
		}
		if BooleanFromStringContains(body, " Set<") {
			output += "\nimport java.util.Set" + lang.lineend
		}
	case langkotlin:
		if BooleanFromStringContains(body, " CompletableFuture<") {
			output += "\nimport java.util.concurrent.CompletableFuture" + lang.lineend
		}
	}
	pkgpath, _ := PackagePathNameFromName(pkg.name)
	if len(pkg.listlib) > 0 {
		for _, lib := range pkg.listlib {
			isskip := false
			libpath := lib.path
			libpkgpath, _ := PackagePathNameFromName(lib.path)
			if lib.lang != "" {
				if test {
					isskip = true
				} else if lib.lang == (":" + lang.name) {
				} else {
					isskip = true
				}
			} else if libpkgpath == pkgpath {
				isskip = true
			} else {
				if lib.pkg != nil {
					switch lang {
					case langcsharp:
						libpath = StringUCaseFirstFromStringDelim(libpkgpath, "/")
					case langjava, langkotlin:
						libprefix := pkgpath
						libprefix = lib.pkg.project.javadomain
						libpath = libprefix + "/" + libpkgpath + "*"
					}
				}
				libpath = StringFromStringFindReplace(libpath, "/", ".")
			}
			if !isskip {
				importline := ""
				switch lang {
				case langcsharp:
				case langjava, langkotlin:
					importline = "\nimport " + libpath + lang.lineend
				}
				if IntFromStringFind(output, importline) < 0 {
					output += importline
				}
			}
		}
		if output != "" {
			output += "\n"
		}
	}
	return output
}

func LangNativePackageLine(
	lang *vxlang,
	pkgname string,
	pkgpath string) string {
	output := ""
	switch lang {
	case langcsharp:
		ipos := IntFromStringFindLast(pkgname, "/")
		csnamespace := StringSubstring(pkgname, 0, ipos)
		csnamespace = StringFromStringFindReplace(csnamespace, "/", ".")
		csnamespace = StringUCaseFirstFromStringDelim(csnamespace, ".")
		output = "namespace " + csnamespace + lang.lineend + "\n"
	case langjava, langkotlin:
		output = "package " + pkgpath + lang.lineend + "\n"
	}
	return output
}

func LangNativePackagePathFromPrefixName(
	lang *vxlang,
	pkgprefix string,
	pkgname string) (string, string) {
	pkgpath := ""
	name := ""
	switch lang {
	case langcsharp:
		pkgpath = pkgprefix + StringUCaseFirstFromStringDelim(pkgname, "/")
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNativePkgName(lang, name)
	case langkotlin:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = StringFromStringFindReplace(pkgname, "/", "_")
		name = LangNativePkgName(lang, name)
	default:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNativePkgName(lang, name)
	}
	return pkgpath, name
}

func LangNativePackageStaticOpenClose(
	lang *vxlang) (string, string) {
	staticopen := ""
	staticclose := ""
	switch lang {
	case langcsharp:
		staticopen = "" +
			"\n  public static class PackageRunOnce {" +
			"\n    public static bool RunOnce() {"
		staticclose = "" +
			"\n      return true" + lang.lineend +
			"\n    }" +
			"\n  }" +
			"\n" +
			"\n  public static bool ranonce = PackageRunOnce.RunOnce()" + lang.lineend +
			"\n"
	case langjava:
		staticopen = "\n  static {"
		staticclose += "" +
			"\n  }" +
			"\n"
	case langkotlin:
		staticopen = "\n  init {"
		staticclose += "" +
			"\n  }" +
			"\n"
	}
	return staticopen, staticclose
}

func LangNativePackageSubPrefixSubDomainPath(
	lang *vxlang,
	command *vxcommand,
	pkg *vxpackage) (string, string) {
	subprefix := ""
	subdomainpath := ""
	switch lang {
	case langcsharp:
		switch command.code {
		case ":test":
			subprefix = "AppTest.Test"
			subdomainpath = "Test"
		}
	case langjava, langkotlin:
		subproject := pkg.project
		subprefix = subproject.javadomain + "/"
		subdomainpath = StringFromStringFindReplace(subprefix, ".", "/")
	}
	return subprefix, subdomainpath
}

func LangNativePathtext(
	lang *vxlang,
	code string) string {
	output := ""
	switch code {
	case ":doc":
		output = "build/doc"
	case ":source":
		switch lang {
		case langjava:
			output = "build/java/src"
		case langjs:
			output = "build/js/test"
		}
	case ":test":
		switch lang {
		case langjava:
			output = "build/java/src"
		case langjs:
			output = "build/js/test"
		}
	}
	return output
}

func LangNativePkgName(
	lang *vxlang,
	pkgname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = StringUCaseFirstFromStringDelim(pkgname, "/")
		output = StringFromStringFindReplace(output, "/", ".")
	case langjava:
		ipos := IntFromStringFindLast(pkgname, "/")
		output = StringSubstring(pkgname, ipos+1, len(pkgname))
		output = StringUCaseFirst(output)
	default:
		output = pkgname
	}
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func LangNativePkgpath(
	lang *vxlang,
	pkgpath string) string {
	output := pkgpath
	switch lang {
	case langcsharp:
		output = StringUCaseFirstFromStringDelim(
			pkgpath, "/")
	}
	return output
}

func LangNativePrintLine(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "System.Console.WriteLine"
	case langjava:
		output = "System.out.println"
	case langkotlin:
		output = "println"
	}
	return output
}

func LangNativeProjectPkgPrefixAppPathTestPath(
	lang *vxlang,
	project *vxproject,
	command *vxcommand,
	cmdpath string) (string, string, string) {
	pkgprefix := ""
	apppath := cmdpath
	testpath := cmdpath
	switch lang {
	case langcsharp:
		apppath += "/App"
		testpath += "/AppTest"
		switch command.code {
		case ":test":
			pkgprefix = "AppTest.Test"
		}
	case langjava, langkotlin:
		pkgprefix = project.javadomain + "."
	}
	return pkgprefix, apppath, testpath
}

func LangNativeTestAppBasic(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_basics() {" +
			"\n    TestLib.test_helloworld()" + lang.lineend +
			"\n    TestLib.test_async_new_from_value()" + lang.lineend +
			"\n    TestLib.test_async_from_async_fn()" + lang.lineend +
			"\n    TestLib.test_list_from_list_async()" + lang.lineend +
			"\n    TestLib.test_pathfull_from_file()" + lang.lineend +
			"\n    TestLib.test_read_file()" + lang.lineend +
			"\n    TestLib.test_write_file()" + lang.lineend +
			"\n  }" +
			"\n"
	case langjava:
		output = "" +
			"\n  @Test" +
			"\n  void test_basics() {" +
			"\n    TestLib.test_helloworld()" + lang.lineend +
			"\n    TestLib.test_async_new_from_value()" + lang.lineend +
			"\n    TestLib.test_async_from_async_fn()" + lang.lineend +
			"\n    TestLib.test_list_from_list_async()" + lang.lineend +
			"\n    TestLib.test_pathfull_from_file()" + lang.lineend +
			"\n    TestLib.test_read_file()" + lang.lineend +
			"\n    TestLib.test_write_file()" + lang.lineend +
			"\n  }" +
			"\n"
	case langkotlin:
		output = "" +
			"\n  @Test" +
			"\n  fun test_basics() {" +
			"\n    TestLib.test_helloworld()" +
			"\n    TestLib.test_async_new_from_value()" +
			"\n    TestLib.test_async_from_async_fn()" +
			"\n    TestLib.test_list_from_list_async()" +
			"\n    TestLib.test_pathfull_from_file()" +
			"\n    TestLib.test_read_file()" +
			"\n    TestLib.test_write_file()" +
			"\n  }" +
			"\n"
	}
	return output
}

func LangNativeTestAssertEquals(
	lang *vxlang,
	ismsg bool,
	indent int) string {
	lineindent := LangIndent(
		lang, indent, true)
	smsg := ""
	if ismsg {
		smsg = ", msg"
	}
	output := ""
	switch lang {
	case langcsharp:
		output = lineindent + "Assert.Equal(expected, actual)" + lang.lineend
	case langjava:
		output = lineindent + "assertEquals(expected, actual" + smsg + ")" + lang.lineend
	case langkotlin:
		output = lineindent + "assertEquals(expected, actual" + smsg + ")" + lang.lineend
	}
	return output
}

func LangNativeTestAssertNotEquals(
	lang *vxlang,
	ismsg bool,
	indent int) string {
	lineindent := LangIndent(
		lang, indent, true)
	smsg := ""
	if ismsg {
		smsg = ", msg"
	}
	output := ""
	switch lang {
	case langcsharp:
		output = lineindent + "Assert.NotEqual(expected, actual)" + lang.lineend
	case langjava:
		output = lineindent + "assertNotEquals(expected, actual" + smsg + ")" + lang.lineend
	case langkotlin:
		output = lineindent + "assertNotEquals(expected, actual" + smsg + ")" + lang.lineend
	}
	return output
}

func LangNativeTestImport(
	lang *vxlang,
	pkg *vxpackage,
	imports string) string {
	project := pkg.project
	pkgname := pkg.name
	output := ""
	importline := ""
	switch lang {
	case langcpp:
		importline = "#include \"" + pkgname + "test.hpp\""
	case langcsharp:
		importline = "using Xunit" + lang.lineend
	case langjava:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name + "Test"
		importline = "import " + importname + lang.lineend
	case langkotlin:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		importname := project.javadomain + "." + path + ".*"
		importline = "import " + importname + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangNativeTestImportExtra(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
	case langjava:
		output = "" +
			"\nimport org.junit.jupiter.api.DisplayName" + lang.lineend +
			"\nimport org.junit.jupiter.api.Test" + lang.lineend
	case langkotlin:
		output = "" +
			"\nimport org.junit.jupiter.api.DisplayName" +
			"\nimport org.junit.jupiter.api.Test"
	}
	return output
}

func LangNativeTestLib(
	lang *vxlang,
	namespaceopen string,
	namespaceclose string,
	commontests string,
	spath string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"using Xunit;" +
			"\n" +
			"\nnamespace AppTest;" +
			"\n" +
			namespaceopen +
			"\n  public class TestOutputWriter : TextWriter {" +
			"\n" +
			"\n    private readonly Xunit.Abstractions.ITestOutputHelper _output;" +
			"\n" +
			"\n    public TestOutputWriter(Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n      _output = output;" +
			"\n    }" +
			"\n" +
			"\n    public override System.Text.Encoding Encoding => System.Text.Encoding.UTF8;" +
			"\n" +
			"\n			 public override void WriteLine(int message) {" +
			"\n				  _output.WriteLine(\"\" + message);" +
			"\n  		}" +
			"\n" +
			"\n  		public override void WriteLine(string? message) {" +
			"\n  				_output.WriteLine(message);" +
			"\n  		}" +
			"\n" +
			"\n  }" +
			"\n" +
			"\n  public static bool EnableConsole(" +
			"\n    Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n    TestOutputWriter converter = new TestOutputWriter(output);" +
			"\n    System.Console.SetOut(converter);" +
			"\n    return true;" +
			"\n  }" +
			"\n" +
			"\n  public static string spath = " + spath + ";" +
			"\n" +
			commontests +
			namespaceclose
	case langjava:
		output = "" +
			"import java.util.*;" +
			"\nimport java.util.concurrent.CompletableFuture;" +
			"\nimport static org.junit.jupiter.api.Assertions.*;" +
			"\nimport com.vxlisp.vx.*;" +
			"\nimport com.vxlisp.vx.data.File;" +
			"\nimport com.vxlisp.vx.Test;" +
			"\nimport com.vxlisp.vx.web.Html;" +
			"\n" +
			namespaceopen +
			"\n  public static String spath = " + spath + ";" +
			"\n" +
			commontests +
			"\n" +
			"\n  // Blocking" +
			"\n  // Only use if running a single testdescribe" +
			"\n  public static " + LangTypeName(lang, rawbooltype) +
			" run_testdescribe_async(final " + LangTypeName(lang, rawstringtype) + " testpkg, final " + LangTypeName(lang, rawstringtype) + " casename, final Test.Type_testdescribe testdescribe) {" +
			"\n    " + lang.future + "<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);" +
			"\n    Test.Type_testdescribe testdescribe_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testdescribe, async_testdescribe);" +
			"\n    return run_testdescribe(testpkg, casename, testdescribe_resolved);" +
			"\n  }" +
			"\n" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {" +
			"\n    " + LangTypeName(lang, rawbooltype) + " output = true;" +
			"\n    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();" +
			"\n    for (Test.Type_testpackage testpackage : listtestpackage) {" +
			"\n      " + LangTypeName(lang, rawbooltype) + " testoutput = run_testpackage(testpackage);" +
			"\n      if (!testoutput) {" +
			"\n        output = false;" +
			"\n      }" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  // Blocking" +
			"\n  // This is the preferred way of calling testsuite (1 block per testsuite)" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {" +
			"\n    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);" +
			"\n    Test.Type_testpackagelist testpackagelist_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);" +
			"\n    return run_testpackagelist(testpackagelist_resolved);" +
			"\n  }" +
			"\n" +
			"\n  // Blocking" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testresult_async(final " + LangTypeName(lang, rawstringtype) + " testpkg, final " + LangTypeName(lang, rawstringtype) + " testname, final " + LangTypeName(lang, rawstringtype) + " message, Test.Type_testresult testresult) {" +
			"\n    " + lang.future + "<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);" +
			"\n    Test.Type_testresult testresult_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testresult, async_testresult);" +
			"\n    return run_testresult(testpkg, testname, message, testresult_resolved);" +
			"\n  }" +
			"\n" +
			namespaceclose
	case langkotlin:
		output = "" +
			"import java.util.*" +
			"\nimport java.util.concurrent.CompletableFuture" +
			"\nimport org.junit.jupiter.api.Assertions.*" +
			"\nimport com.vxlisp.vx.*" +
			"\nimport com.vxlisp.vx.data.*" +
			"\nimport com.vxlisp.vx.web.*" +
			"\n" +
			namespaceopen +
			"\n  val spath : String = " + spath +
			"\n" +
			commontests +
			namespaceclose

	}
	return output
}

func LangNativeTestLibFnAsync(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n    Vx.Core.Func_any_from_any_async fn_async = Vx.Core.t_any_from_any_async.vx_fn_new((anyval) => {" +
			"\n      Vx.Core.Type_string stringval = (Vx.Core.Type_string)anyval;" +
			"\n      string sout = stringval.vx_string() + \"!\";" +
			"\n      Vx.Core.Type_any outval = Vx.Core.vx_new_string(sout);" +
			"\n      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case langjava:
		output = "" +
			"\n    Core.Func_any_from_any_async fn_async = Core.t_any_from_any_async.vx_fn_new((anyval) -> {" +
			"\n      Core.Type_string stringval = (Core.Type_string)anyval;" +
			"\n      String sout = stringval.vx_string() + \"!\";" +
			"\n      Core.Type_any outval = Core.vx_new_string(sout);" +
			"\n      CompletableFuture<Core.Type_any> output = Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case langkotlin:
		output = "" +
			"\n    val fn_async : vx_core.Func_any_from_any_async = vx_core.t_any_from_any_async.vx_fn_new({" +
			"\n      anyval ->" +
			"\n      val stringval : vx_core.Type_string = anyval as vx_core.Type_string" +
			"\n      val sout : String = stringval.vx_string() + \"!\"" +
			"\n      val outval : vx_core.Type_any = vx_core.vx_new_string(sout)" +
			"\n      val output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(outval)" +
			"\n      output" +
			"\n    });"
	}
	return output
}

func LangNativeTestLibLambda(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcpp:
		output = "" +
			"{}," +
			"\n[](vx_core::Type_any any) {" +
			"\n 		return any;" +
			"\n}"
	case langcsharp:
		output = "" +
			"(any) => {" +
			"\n     	return any;" +
			"\n    }"
	case langjava, langjs:
		output = "" +
			"(any) -> {" +
			"\n     	return any;" +
			"\n    }"
	case langkotlin:
		output = "" +
			"{any ->" +
			"\n     	any" +
			"\n    }"
	}
	return output
}

func LangNativeTestLibParamsOpenClose(
	lang *vxlang) (string, string) {
	paramsopen := ""
	paramsclose := ""
	switch lang {
	case langcpp:
		paramsopen = "{"
		paramsclose = "}"
	}
	return paramsopen, paramsclose
}

func LangNativeTestNamespaceOpenClose(
	lang *vxlang,
	pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang {
	case langcsharp:
		namespaceopen = "" +
			"\nnamespace " + pkgname + lang.lineend +
			"\n"
	case langjava:
		namespaceopen = "" +
			"\npackage " + pkgname + lang.lineend +
			"\n"
	case langkotlin:
		namespaceopen = "" +
			"\npackage " + pkgname + lang.lineend +
			"\n"
	}
	return namespaceopen, namespaceclose
}

func LangNativeTestPackage(
	lang *vxlang,
	pkg *vxpackage,
	testpackagetype *vxtype) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			LangVar(lang, "testpackage", testpackagetype, 2,
				"Test"+
					LangNativePkgName(lang, pkg.name)+
					"Test.test_package(context)") +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langjava:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackage testpackage = " + LangNativePkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langkotlin:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  fun test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() : Unit {" +
			"\n    val testpackage : vx_test.Type_testpackage = " + LangNativePkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	}
	return output
}

func LangNativeTestPackageOpenClose(
	lang *vxlang,
	pkgname string) (string, string) {
	packageopen := ""
	packageclose := ""
	switch lang {
	case langcsharp:
		packageopen = "" +
			"\npublic " + LangNativeFinalClass(lang) + "class " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	case langjava:
		packageopen = "" +
			"\npublic " + LangNativeFinalClass(lang) + "class " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	case langkotlin:
		packageopen = "" +
			"\nobject " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	}
	return packageopen, packageclose
}

func LangNativeTestPackagePrefix(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Test"
	}
	return output
}

func LangNativeTestResourcesPath(
	lang *vxlang,
	cmd *vxcommand) string {
	path := cmd.path
	switch lang {
	case langjava:
		ipos := IntFromStringFindLast(path, "/test/")
		if ipos >= 0 {
			path = path[0 : ipos+5]
		}
	}
	ipos := IntFromStringFind(path, "/"+lang.name+"/")
	if ipos >= 0 {
		path = path[ipos+len(lang.name)+2:]
	}
	switch lang {
	case langkotlin:
		if BooleanFromStringStarts(path, "app/") {
			path = path[4:]
		}
	}
	return path
}

func LangNativeTestTargetPath(
	lang *vxlang,
	targetpath string) string {
	output := targetpath
	switch lang {
	case langjava:
		if BooleanFromStringEnds(targetpath, "/java") {
			output = targetpath[0 : len(targetpath)-5]
		}
	}
	return output
}

func LangNativeTestVarTestCases(
	lang *vxlang,
	testall []string) string {
	output := ""
	switch lang {
	case langcsharp:
		vararraylisttestcase := "[" +
			"\n      " + strings.Join(testall, ",\n      ") +
			"\n    ]"
		output = "\n    object[] testcases = " + vararraylisttestcase + lang.lineend
	default:
		vararraylisttestcase := LangPkgNameDot(lang, "vx/core") + "arraylist_from_array(" +
			"\n      " + strings.Join(testall, ",\n      ") +
			"\n    )"
		output = "" +
			LangVarCollection(
				lang, "testcases", rawlisttype, anytype, 2, vararraylisttestcase)
	}
	return output
}

func LangNativeTestWriteTestSuite(
	lang *vxlang,
	testpackages string) string {
	output := ""
	switch lang {
	case langcsharp:
		testpackagedata := "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testpackagelisttype) + "," +
			testpackages +
			"\n    )"
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_writetestsuite() {" +
			LangVar(lang, "testpackagelist", testpackagelisttype, 2, testpackagedata) +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" + lang.lineend +
			"\n  }" +
			"\n"
	case langjava:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"writetestsuite\")" +
			"\n  void test_writetestsuite() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      com.vxlisp.vx.Test.t_testpackagelist," +
			testpackages +
			"\n    )" + lang.lineend +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" + lang.lineend +
			"\n  }"
	case langkotlin:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"writetestsuite\")" +
			"\n  fun test_writetestsuite() {" +
			"\n    val testpackagelist : vx_test.Type_testpackagelist = " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      vx_test.t_testpackagelist," +
			testpackages +
			"\n    )" +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" +
			"\n  }"
	}
	return output
}

func LangNativeTypeBoolean(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "bool"
	default:
		output = "Boolean"
	}
	return output
}

func LangNativeTypeClassHeader(
	lang *vxlang,
	typ *vxtype,
	indent int) string {
	output := ""
	lineindent := LangIndent(
		lang, indent, true)
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

func LangNativeTypeElseIfListAny(
	lang *vxlang,
	allowtype *vxtype) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			LangNativeElseIfType(
				lang, rawlistanytype, emptytype, "valsub", "listany", 4, false) +
			LangNativeForListHeader(
				lang, "item", anytype, "listany", 5) +
			LangIf(
				lang, 6, "false", "") +
			LangNativeElseIfType(
				lang, allowtype, emptytype, "item", "valitem", 6, false) +
			LangNativeVarSet(
				lang, "ischanged", 7, "true") +
			LangNativeVxListAdd(
				lang, "listval", 7, "valitem") +
			"\n            }" +
			"\n          }"
	case langjava, langkotlin:
		output = "" +
			LangNativeElseIfType(
				lang, rawlistunknowntype, emptytype, "valsub", "listunknown", 4, false) +
			LangNativeForListHeader(
				lang, "item", rawobjecttype, "listunknown", 5) +
			LangIf(
				lang, 6, "false", "") +
			LangNativeElseIfType(
				lang, allowtype, emptytype, "item", "valitem", 6, false) +
			LangNativeVarSet(
				lang, "ischanged", 7, "true") +
			LangNativeVxListAdd(
				lang, "listval", 7, "valitem") +
			"\n            }" +
			"\n          }"
	}
	return output
}

func LangNativeTypeFloat(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "float"
	default:
		output = "Float"
	}
	return output
}

func LangNativeTypeInt(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "int"
	case langkotlin:
		output = "Int"
	default:
		output = "Integer"
	}
	return output
}

func LangNativeTypeInterfaceBasics(
	lang *vxlang,
	typ *vxtype) bool {
	output := true
	switch lang {
	case langcsharp, langjava, langkotlin:
		switch NameFromType(typ) {
		case "vx/core/any":
		default:
			output = false
		}
	}
	return output
}

func LangNativeTypeInterfaceHeader(
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

func LangNativeTypeMapGetOrElse(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "mapval.getOrElse(skey, " + LangTypeE(lang, typ) + ")"
	default:
		output = "mapval.getOrDefault(skey, " + LangTypeE(lang, typ) + ")"
	}
	return output
}

func LangNativeTypeMapKeysetGet(
	lang *vxlang) (string, string) {
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
	return keyset, mapget
}

func LangNativeTypeNameFullSimple(
	lang *vxlang,
	typ *vxtype,
	simple bool) string {
	name := ""
	switch typ {
	case anylisttype:
		name = lang.pkgname + lang.pkgref + "Type_anylist"
	case contexttype:
		name = lang.pkgname + lang.pkgref + "Type_context"
	case nonetype:
		switch lang {
		case langkotlin:
			name = "Unit"
		default:
			name = "void"
		}
	case stringtype:
		name = lang.pkgname + lang.pkgref + "Type_string"
	case rawbooltype:
		switch lang {
		case langcpp, langcsharp:
			name = "bool"
		case langjava:
			name = "boolean"
		case langkotlin:
			name = "Boolean"
		}
	case rawbooleantype:
		switch lang {
		case langcpp, langcsharp:
			name = "bool"
		case langjava, langkotlin:
			name = "Boolean"
		}
	case rawfloattype:
		switch lang {
		case langcpp, langcsharp:
			name = "float"
		case langjava:
			name = "Float"
		case langkotlin:
			name = "Float"
		}
	case rawifntype:
		name = "IFn"
	case rawinttype:
		switch lang {
		case langkotlin:
			name = "Int"
		default:
			name = "int"
		}
	case rawintegertype:
		switch lang {
		case langcpp, langcsharp:
			name = "int"
		case langjava:
			name = "Integer"
		case langkotlin:
			name = "Int"
		}
	case rawlisttype:
		switch lang {
		case langcpp:
			name = "std::vector<object>"
		case langcsharp:
			name = "List<object>"
		case langjava:
			name = "List"
		case langkotlin:
			name = "List<Any>"
		}
	case rawlistanytype:
		name = "List<" + LangNativeTypeNameFullSimple(lang, anytype, true) + ">"
	case rawmaptype:
		switch lang {
		case langcpp:
			name = "std::map"
		case langcsharp:
			name = "Vx.Core.Map"
		case langjava, langkotlin:
			name = "Map"
		}
	case rawlistunknowntype:
		switch lang {
		case langcpp:
			name = "std::vector<object>"
		case langcsharp:
			name = "List<object>"
		case langjava:
			name = "List<?>"
		case langkotlin:
			name = "List<*>"
		}
	case rawmapanytype:
		switch lang {
		case langcpp:
			name = "std::map<std::string, " + LangNativeTypeNameFullSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangNativeTypeNameFullSimple(lang, anytype, true) + ">"
		default:
			name = "Map<String, " + LangNativeTypeNameFullSimple(lang, anytype, true) + ">"
		}
	case rawobjecttype:
		switch lang {
		case langcpp:
			name = "object"
		case langcsharp:
			name = "object"
		case langkotlin:
			name = "Any"
		default:
			name = "Object"
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
	case rawvoidtype:
		switch lang {
		case langkotlin:
			name = "Unit"
		default:
			name = "void"
		}
	default:
		switch typ.name {
		case "rawlist":
			subtype := typ.subtype
			subtypename := LangTypeName(lang, subtype)
			name = "List<" + subtypename + ">"
		case "rawmap":
			subtype := typ.subtype
			subtypename := LangTypeName(lang, subtype)
			switch lang {
			case langcpp:
				name = "std::Map<std::string, " + subtypename + ">"
			case langcsharp:
				name = "Vx.Core.Map<string, " + subtypename + ">"
			default:
				name = "Map<String, " + subtypename + ">"
			}
		default:
			if typ.isgeneric && !simple {
				name = LangNativeTypeNameSimple(
					lang, typ, simple)
			} else {
				name = LangNativePkgName(
					lang, typ.pkgname)
				if typ.isfunc {
					name += lang.pkgref + "Func_"
				} else {
					name += lang.pkgref + "Type_"
				}
				name += LangNativeTypeNameSimple(
					lang, typ, simple)
			}
		}
	}
	return name
}

func LangNativeTypeNameSimple(
	lang *vxlang,
	typ *vxtype,
	simple bool) string {
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
			name = "List<" + LangNativeTypeNameSimple(lang, anytype, true) + ">"
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
			name = "std::map<string, " + LangNativeTypeNameSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangNativeTypeNameSimple(lang, anytype, true) + ">"
		case langjava, langkotlin:
			name = "Map<String, " + LangNativeTypeNameSimple(lang, anytype, true) + ">"
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

func LangNativeTypeNameSubtype(
	lang *vxlang,
	typ *vxtype,
	subtype *vxtype) string {
	output := LangNameTypeFromTypeSimple(
		lang, subtype, false)
	switch typ {
	case rawlisttype:
		output = "List<" + output + ">"
	case rawmaptype:
		switch lang {
		case langcpp:
			output = "std::map<std::string, " + output + ">"
		case langcsharp:
			output = "Vx.Core.Map<string, " + output + ">"
		default:
			output = "Map<String, " + output + ">"
		}
	}
	return output
}

func LangNativeTypeProperties(
	lang *vxlang,
	typ *vxtype) []vxarg {
	var typeproperties []vxarg
	switch lang {
	case langcsharp, langkotlin, langswift:
		typeproperties = typ.properties
	default:
		typeproperties = ListPropertyTraitFromType(typ)
	}
	return typeproperties
}

func LangNativeTypeString(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcpp:
		output = "std::string"
	case langcsharp:
		output = "string"
	default:
		output = "String"
	}
	return output
}

func LangNativeTypeStringbuilder(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n      System.Text.StringBuilder sb = new System.Text.StringBuilder(value.vx_string())" + lang.lineend
	case langjava:
		output = "" +
			"\n      StringBuilder sb = new StringBuilder(value.vx_string())" + lang.lineend
	case langkotlin:
		output = "" +
			"\n      var sb : kotlin.text.StringBuilder = StringBuilder(value.vx_string())"
	}
	return output
}

func LangNativeTypeStringbuilderAppend(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = ".Append"
	case langjava, langkotlin:
		output = ".append"
	}
	return output
}

func LangNativeTypeThis(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langswift:
		output = "self"
	default:
		output = "this"
	}
	return output
}

func LangNativeTypeVxEmpty(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcpp:
		output += "vx_empty"
	default:
		output += "f_empty"
	}
	return output
}

func LangNativeTypeVxMap(
	lang *vxlang,
	typ *vxtype) string {
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
				LangNativeVxNewMap(lang, anytype, "this.vx_p_map"))
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

func LangNativeTypeVxNewVals(
	lang *vxlang) string {
	output := "vals"
	switch lang {
	case langkotlin:
		output = "*vals"
	}
	return output
}

func LangNativeVarAll(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	varvalue string,
	indent int,
	isconst bool,
	isfuture bool,
	isstatic bool,
	isprop bool,
	isgeneric bool,
	isnullable bool) string {
	output := LangIndent(lang, indent, true)
	svalue := LangNativeVarValue(lang, vartype, varvalue)
	switch lang {
	case langcpp:
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		if isconst {
			output += "final "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "std::list<" + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new std::list<" + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawmaptype:
			typetext = "std::map<std::string, " + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new std::map<std::string, " + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawlistunknowntype:
			typetext = "std::list<?>"
		default:
			if isgeneric && vartype.isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
		}
		if isfuture {
			typetext = lang.future + "<" + typetext + ">"
		}
		output += typetext + " " + varname
		if svalue != "" {
			output += " = " + svalue
		}
		output += lang.lineend
	case langcsharp:
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "List<" + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new List<" + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawmaptype:
			typetext = "Vx.Core.Map<string, " + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new Vx.Core.LinkedHashMap<string, " + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawlistunknowntype:
			typetext = "List<object>"
			if varvalue == ":new" {
				svalue = "List<object>()"
			}
		default:
			if isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
		}
		if isfuture {
			typetext = "Task<" + typetext + ">"
		}
		if isnullable || varvalue == "null" {
			output += typetext + "? " + varname + " = " + varvalue
		} else if varvalue == "" {
			output += typetext + " " + varname
		} else {
			output += typetext + " " + varname + " = " + svalue
		}
		output += lang.lineend
	case langjava:
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		if isconst {
			output += "final "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "List<" + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new ArrayList<" + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawmaptype:
			typetext = "Map<String, " + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				svalue = "new LinkedHashMap<String, " + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawlistunknowntype:
			typetext = "List<?>"
		default:
			if isgeneric && vartype.isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
		}
		if isfuture {
			typetext = lang.future + "<" + typetext + ">"
		}
		output += typetext + " " + varname
		if svalue != "" {
			output += " = " + svalue
		}
		output += lang.lineend
	case langkotlin:
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "List<" + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				typetext = "Mutable" + typetext
				svalue = "ArrayList<" + LangNameTypeFullFromType(lang, subtype) + ">()"
			} else if BooleanFromStringStarts(svalue, "ArrayList<") {
				typetext = "Mutable" + typetext
			}
		case rawmaptype:
			typetext = "Map<String, " + LangNameTypeFullFromType(lang, subtype) + ">"
			if varvalue == ":new" {
				typetext = "Mutable" + typetext
				svalue = "LinkedHashMap<String, " + LangNameTypeFullFromType(lang, subtype) + ">()"
			} else if BooleanFromStringStarts(svalue, "LinkedHashMap<") {
				typetext = "Mutable" + typetext
			}
		case rawlistunknowntype:
			typetext = "List<Any>"
			if varvalue == ":new" {
				typetext = "Mutable" + typetext
				svalue = "ArrayList<Any>()"
			} else if BooleanFromStringStarts(svalue, "ArrayList<") {
				typetext = "Mutable" + typetext
			}
		default:
			if isgeneric && vartype.isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
		}
		if isfuture {
			typetext = "CompletableFuture<" + typetext + ">"
		}
		if isconst {
			output += "val"
		} else {
			output += "var"
		}
		output += " " + varname
		output += " : " + typetext
		if isnullable || varvalue == "null" {
			output += "?"
		}
		if varvalue != "" {
			output += " = " + svalue
		}
	}
	return output
}

func LangNativeVarClassAll(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	isconst bool,
	isnullable bool,
	varvalue string) string {
	classname := LangTypeClassFull(lang, vartype)
	sindent := "\n" + StringRepeat("  ", indent)
	svalue := LangNativeVarValue(lang, vartype, varvalue)
	output := sindent
	switch lang {
	case langcsharp:
		nullable := ""
		if isnullable {
			nullable = "?"
		}
		output += "" +
			classname + nullable + " " + varname + " = " + svalue + lang.lineend
	case langkotlin:
		nullable := ""
		if isnullable {
			nullable = "?"
		}
		prefix := "var"
		if isconst {
			prefix = "val"
		}
		output += "" +
			prefix + " " + varname + " : " + classname + nullable + " = " + svalue
	case langswift:
		prefix := "var"
		if isconst {
			prefix = "val"
		}
		output += "" +
			prefix + " " + varname + " : " + classname + " = " + svalue
	default:
		output += "" +
			classname + " " + varname + " = " + svalue + lang.lineend
	}
	return output
}

func LangNativeVarSet(
	lang *vxlang,
	varname string,
	indent int,
	varvalue string) string {
	output := LangIndent(lang, indent, true)
	output += varname
	output += " = " + varvalue
	switch lang {
	case langcpp, langcsharp, langjava:
		output += lang.lineend
	}
	return output
}

func LangNativeVarValue(
	lang *vxlang,
	vartype *vxtype,
	varvalue string) string {
	output := varvalue
	switch varvalue {
	case ":new":
		classname := LangTypeClassFull(lang, vartype)
		switch lang {
		case langkotlin:
			output = classname + "()"
		case langswift:
			output = classname + "()"
		default:
			output = "new " + classname + "()"
		}
	}
	return output
}

func LangNativeVxContains(
	lang *vxlang,
	text string,
	contains string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = text + ".Contains(" + contains + ")"
	default:
		output = text + ".contains(" + contains + ")"
	}
	return output
}

func LangNativeVxEqualsString(
	lang *vxlang,
	text1 string,
	text2 string) string {
	output := ""
	switch lang {
	case langjava, langkotlin:
		output = text1 + ".equals(" + text2 + ")"
	default:
		output = text1 + " == " + text2
	}
	return output
}

func LangNativeVxFloatFromString(
	lang *vxlang,
	text string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "float.Parse(" + text + ")"
	case langjava:
		output = "Float.parseFloat(" + text + ")"
	case langkotlin:
		output = text + ".toFloat()"
	}
	return output
}

func LangNativeVxIntFromString(
	lang *vxlang,
	text string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Int32.Parse(" + text + ")"
	case langjava:
		output = "Integer.parseInt(" + text + ")"
	case langkotlin:
		output = text + ".toInt()"
	}
	return output
}

func LangNativeVxListAdd(
	lang *vxlang,
	varname string,
	indent int,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	case langcpp:
		output = sindent + varname + ".push_back(" + value + ")" + lang.lineend
	case langcsharp:
		output = sindent + varname + ".Add(" + value + ")" + lang.lineend
	default:
		output = sindent + varname + ".add(" + value + ")" + lang.lineend
	}
	return output
}

func LangNativeVxListAddList(
	lang *vxlang,
	varname string,
	indent int,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	case langcsharp:
		output = sindent + varname + ".AddRange(" + value + ")" + lang.lineend
	default:
		output = sindent + varname + ".addAll(" + value + ")" + lang.lineend
	}
	return output
}

func LangNativeVxListContains(
	lang *vxlang,
	varname string,
	contains string) string {
	output := ""
	switch lang {
	case langcpp:
		output = "vx_core::vx_boolean_from_list_find(" + varname + ", " + contains + ")"
	case langcsharp:
		output = varname + ".Contains(" + contains + ")"
	default:
		output = varname + ".contains(" + contains + ")"
	}
	return output
}

func LangNativeVxListGet(
	lang *vxlang,
	varname string,
	value string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + "[" + value + "]"
	default:
		output = varname + ".get(" + value + ")"
	}
	return output
}

func LangNativeVxListSize(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + ".Count"
	case langkotlin:
		output = varname + ".size"
	default:
		output = varname + ".size()"
	}
	return output
}

func LangNativeVxNewList(
	lang *vxlang,
	typ *vxtype,
	value string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "new List<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case langjava:
		output = "new ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case langkotlin:
		output = "ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangNativeVxNewMap(
	lang *vxlang,
	typ *vxtype,
	value string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "new Vx.Core.LinkedHashMap<string, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case langjava:
		output = "new LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case langkotlin:
		output = "LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangNativeVxStartswith(
	lang *vxlang,
	varname string,
	starts string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + ".StartsWith(" + starts + ")"
	case langjava, langkotlin:
		output = varname + ".startsWith(" + starts + ")"
	}
	return output
}

func LangNativeVxSubstring(
	lang *vxlang,
	varname string,
	from string,
	to string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + ".Substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	case langjava, langkotlin:
		output = varname + ".substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	}
	return output
}

func LangNativeVxToString(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Vx.Core.vx_string_from_object(" + varname + ")"
	case langjava, langkotlin:
		output = varname + ".toString()"
	}
	return output
}

func LangNativeWriteFromProjectCmd(
	lang *vxlang,
	project *vxproject,
	command *vxcommand) *vxmsgblock {
	var msgs *vxmsgblock
	switch command.lang {
	case langcpp:
		msgs = CppWriteFromProjectCmd(command.lang, project, command)
	case langjs:
		msgs = JsWriteFromProjectCmd(command.lang, project, command)
	default:
		msgs = LangWriteFromProjectCmd(command.lang, project, command)
	}
	return msgs
}
