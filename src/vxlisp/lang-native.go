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

var maplang = LangNewMapLangFromList(listlang)

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
	output.serror = "err"
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
	output.serror = "err"
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
	output.serror = "err"
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
	output.serror = "err"
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
	output.serror = "err"
	return output
}

func NewLangSwift() *vxlang {
	output := new(vxlang)
	output.name = "swift"
	output.sourcename = "Core"
	output.sourcefile = ".swift"
	output.pkgpath = "Vx_Core"
	output.pkgname = "Vx_Core"
	output.pkgref = "."
	output.future = "Vx_Core.Future"
	output.indent = "  "
	output.lineend = ""
	output.classext = ":"
	output.typeref = "."
	output.genericcount = 1
	output.argjoin = ",\n"
	output.serror = "error"
	output.filewhitelist = []string{
		"vx/core",
		"vx/collection",
		"vx/event",
		"vx/test",
		"vx/translate",
		"vx/type",
		"vx/data/file",
		"vx/translation/en",
		"vx/web/html"}
	return output
}

func LangNewMapLangFromList(listlang []*vxlang) map[string]*vxlang {
	output := make(map[string]*vxlang)
	for _, lang := range listlang {
		key := ":" + lang.name
		output[key] = lang
	}
	return output
}

func LangAppArgListInit(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = LangVar(lang, 3, anylisttype,
			"arglist",
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
	case langjava, langswift:
		output = LangVal(lang, 3, anylisttype,
			"arglist",
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
	case langkotlin:
		output = LangVal(lang, 3, anylisttype,
			"arglist",
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(*args)")
	}
	return output
}

func LangAppClassOpenClose(
	lang *vxlang) (string, string) {
	classopen := ""
	classclose := ""
	indent := LangIndent(lang, 0, true)
	switch lang {
	case langcsharp:
		classopen = indent + "class App {\n"
		classclose = indent + "}\n"
	case langjava:
		classopen = indent + "public final class App {\n"
		classclose = indent + "}\n"
	case langkotlin:
	case langswift:
		classopen = indent + "public enum App {\n"
		classclose = "" +
			indent + "}\n" +
			indent + "App.main(App.args())\n"
	}
	return classopen, classclose
}

func LangAppMainOpenClose(
	lang *vxlang,
	project *vxproject) (string, string) {
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
	case langswift:
		mainopen = "" +
			indent1 + "public static func main(_ args : [String]) {" +
			indent1 + "  Vx.initialize()"
		mainclose = "" +
			indent1 + "}" +
			"\n" +
			"\n" +
			indent1 + "public static func args() -> [String] {" +
			indent1 + "  let args1 : [String] = CommandLine.arguments" +
			indent1 + "  let args2 : [String] = Array(args1.dropFirst())" +
			indent1 + "  let output = args2.filter { $0 != \"--args\" }" +
			indent1 + "  return output" +
			indent1 + "}" +
			"\n"
	}
	return mainopen, mainclose
}

func LangAppOutputPrint(
	lang *vxlang) string {
	indent3 := LangIndent(lang, 3, true)
	printline := LangPrintLine(lang)
	output := indent3 + printline + "(output)" + lang.lineend
	return output
}

func LangAppTestPath(
	lang *vxlang,
	spath string) string {
	output := ""
	switch lang {
	case langswift:
		output = spath + "/AppTest"
	default:
		output = spath
	}
	return output
}

func LangAppTryOpenClose(
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
	case langswift:
		tryopen = indent2 + "do {"
		tryclose = "" +
			indent2 + "} catch {" +
			indent3 + "print(error)" +
			indent2 + "}"
	}
	return tryopen, tryclose
}

func LangFuncArgHeader(
	lang *vxlang,
	fnc *vxfunc,
	idx int,
	arg vxarg,
	isallowgeneric bool) string {
	output := ""
	sfinal := ""
	if arg.isfinal {
		sfinal = LangFinalArg(lang)
	}
	sargname := LangFromName(arg.name)
	typ := arg.vxtype
	stypename := ""
	if typ.isgeneric {
		switch lang.genericcount {
		case 1:
			isconverttoany := false
			if idx == 0 {
				switch NameFromFunc(fnc) {
				case "vx/core/new", "vx/core/empty", "vx/core/new<-type",
					"f_new", "f_empty", "f_new_from_type":
				default:
					isconverttoany = true
				}
			} else if idx > 0 {
				isconverttoany = true
			}
			if isconverttoany {
				returntypename := ""
				if fnc.generictype != nil {
					returntypename = fnc.generictype.name
					if typ.name == returntypename {
						sargname += "_generic"
					}
				}
				switch typ.name {
				case "any-1", "any-2", "any-3":
					stypename = LangTypeName(lang, anytype)
				case "list-1", "list-2", "list-3":
					stypename = LangTypeName(lang, listtype)
				case "map-1", "map-2", "map-3":
					stypename = LangTypeName(lang, maptype)
				case "struct-1", "struct-2", "struct-3":
					stypename = LangTypeName(lang, structtype)
				}
			}
		}
		if stypename != "" {
		} else if isallowgeneric {
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
			case langjava:
				smulti2 = "..."
			case langkotlin:
				smulti1 = "vararg "
			case langswift:
				smulti1 = "["
				smulti2 = "]"
			}
		}
	}
	switch lang {
	case langkotlin:
		output = "" + sfinal + smulti1 + sargname + smulti2 + " : " + stypename
	case langswift:
		output = "" + sfinal + "_ " + sargname + " : " + smulti1 + stypename + smulti2
	default:
		output = "" + sfinal + smulti1 + stypename + smulti2 + " " + sargname
	}
	return output
}

func LangArgTypeName(
	lang *vxlang,
	argname string,
	argtype *vxtype) string {
	argtypename := LangTypeName(lang, argtype)
	output := ""
	switch lang {
	case langkotlin, langswift:
		output = argname + " : " + argtypename
	default:
		output = argtypename + " " + argname
	}
	return output
}

func LangArgTypeNameValue(
	lang *vxlang,
	argname string,
	typ *vxtype) string {
	argtypename := LangTypeName(lang, typ)
	output := ""
	switch lang {
	case langkotlin, langswift:
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
		case langswift:
			typetext = "[Any]"
		default:
			typetext = LangTypeClassFull(lang, typ)
		}
	default:
		typetext = LangTypeClassFull(lang, typ)
	}
	return LangVarAsTypeText(lang, svar, typetext)
}

func LangClause(
	lang *vxlang,
	paren bool,
	op string,
	leftclause string,
	rightclause string) string {
	output := ""
	if rightclause == "null" {
		rightclause = LangNull(lang)
	}
	switch lang {
	case langswift:
		switch op {
		case "==":
			if rightclause == "nil" {
				output = leftclause + " == " + rightclause
			} else {
				output = "Vx_Core.vx_issame(" + leftclause + ", " + rightclause + ")"
			}
		case "!=":
			if rightclause == "nil" {
				output = leftclause + " != " + rightclause
			} else {
				output = "!Vx_Core.vx_issame(" + leftclause + ", " + rightclause + ")"
			}
		}
	}
	if output == "" {
		if paren {
			output = "(" + leftclause + " " + op + " " + rightclause + ")"
		} else {
			output = leftclause + " " + op + " " + rightclause
		}
	}
	return output
}

func LangConstClassHeader(
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
	case langswift:
		output = lineindent + "public class " + constname + " {"
	}
	return output
}

func LangConstDoc(
	lang *vxlang,
	cnst *vxconst) string {
	output := ""
	doc := ""
	switch lang {
	case langswift:
	default:
		doc = "Constant: " + cnst.name + "\n"
		if cnst.doc != "" {
			doc += cnst.doc + "\n"
		}
		if cnst.deprecated != "" {
			doc += cnst.deprecated + "\n"
		}
		doc += "{" + cnst.vxtype.name + "}"
		output = "" +
			"  /**" +
			"\n   * " + StringFromStringIndent(doc, "   * ") +
			"\n   */"
	}
	return output
}

func LangConstStaticOpenClose(
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

func LangFilesCustom(
	lang *vxlang,
	project *vxproject,
	command *vxcommand,
	cmdpath string) []*vxfile {
	var files []*vxfile
	switch lang {
	case langswift:
		switch command.code {
		case ":source":
			packageinit := ""
			pkgs := ListPackageFromProject(project)
			for _, pkg := range pkgs {
				iscontinue := true
				if len(lang.filewhitelist) > 0 {
					iscontinue = BooleanFromListStringContains(lang.filewhitelist, pkg.name)
				}
				if len(lang.fileblacklist) > 0 {
					iscontinue = !BooleanFromListStringContains(lang.fileblacklist, pkg.name)
				}
				if iscontinue {
					packageinit += "\n    " + LangPkgNameDot(lang, pkg.name) + "vx_initialize()"
				}
			}
			text := "" +
				"public enum Vx {" +
				"\n" +
				"\n  private static let initialized : Void = {" +
				packageinit +
				"\n  }()" +
				"\n" +
				"\n  public static func initialize() {" +
				"\n    _ = initialized" +
				"\n  }" +
				"\n" +
				"\n}" +
				"\n"
			file := NewFile()
			file.name = "Vx" + lang.sourcefile
			file.path = cmdpath + "/Vx"
			file.text = text
			files = append(files, file)
		}
	}
	return files
}

func LangFinalArg(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangFinalClass(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangFinalVar(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangFloatFromString(
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
	case langswift:
		output = "Vx_Core.vx_float_from_string(" + text + ")"
	}
	return output
}

func LangForListHeader(
	lang *vxlang,
	indent int,
	forvar string,
	typ *vxtype,
	listvar string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langcsharp:
		output = sindent + "foreach (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " in " + listvar + ") {"
	case langjava:
		output = sindent + "for (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " : " + listvar + ") {"
	case langkotlin:
		output = sindent + "for (" + forvar + " : " + LangNameTypeFullFromType(lang, typ) + " in " + listvar + ") {"
	case langswift:
		output = sindent + "for " + forvar + " in " + listvar + " {"
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

func LangFuncCall(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	params ...string) string {
	output := ""
	funcname := fnc.alias
	switch fnc {
	case func_f_copy, func_vx_copy:
		if lang.genericcount != 1 {
			params = params[1:]
		}
	}
	sparams := StringFromListStringJoin(params, ", ")
	if indent > 0 && len(sparams) > 20 {
		lineindent1 := LangIndent(lang, indent, true)
		lineindent2 := LangIndent(lang, indent+1, true)
		sparams = lineindent2 + StringFromListStringJoin(params, ","+lineindent2) + lineindent1
	}
	output += LangPkgNameDot(lang, fnc.pkgname) + funcname + "(" + sparams + ")"
	return output
}

func LangFuncCallMethod(
	lang *vxlang,
	indent int,
	varname string,
	funcname string,
	params ...string) string {
	output := ""
	sparams := StringFromListStringJoin(params, ", ")
	if indent > 0 && len(sparams) > 20 {
		lineindent1 := LangIndent(lang, indent, true)
		lineindent2 := LangIndent(lang, indent+1, true)
		sparams = lineindent2 + StringFromListStringJoin(params, ","+lineindent2) + lineindent1
	}
	output += varname + lang.typeref + funcname + "(" + sparams + ")"
	return output
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
	case langswift:
		output = lineindent + "public class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {"
	}
	return output
}

func LangFuncCleanup(
	lang *vxlang,
	fnc *vxfunc,
	text string) string {
	output := text
	switch lang {
	case langswift:
		if fnc.isgeneric {
			generictype := fnc.generictype
			if generictype != nil {
				generictypename := NameFromType(generictype)
				switch generictypename {
				case "vx/core/any-1":
					arglist := fnc.listarg
					for _, arg := range arglist {
						if arg.isgeneric {
							switch NameFromType(arg.generictype) {
							case "vx/core/list-1":
								output = StringFromStringFindReplace(output, " : X", " : any Vx_Core.Type_list")
							case "vx/core/map-1":
								output = StringFromStringFindReplace(output, " : N", " : any Vx_Core.Type_map")
							}
						}
					}
				}
			}
		}
	}
	return output
}

func LangFuncDefaultOutput(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	valuetext string) string {
	var returntype *vxtype
	if fnc.generictype == nil {
		returntype = fnc.vxtype
	} else {
		returntype = fnc.generictype
	}
	defaultvalue := ""
	isskipdefault := false
	switch lang {
	case langswift:
		if BooleanFromStringContains(valuetext, "let output ") {
			isskipdefault = true
		}
	}
	switch NameFromFunc(fnc) {
	case "vx/core/new<-type", "vx/core/copy", "vx/core/empty":
		isskipdefault = true
	}
	if isskipdefault {
	} else if fnc.async {
		defaultvalue =
			LangVarFutureGeneric(lang, indent, returntype,
				"output",
				LangPkgNameDot(lang, "vx/core")+
					"vx_async_new_from_value("+
					LangTypeE(lang, fnc.vxtype)+")")
	} else if fnc.generictype != nil {
		defaultvalue =
			LangVarGeneric(lang, 2, returntype,
				"output",
				LangPkgNameDot(lang, "vx/core")+
					"f_empty("+
					LangTypeTGeneric(lang, fnc.generictype)+
					")")
	} else {
		defaultvalue =
			LangVar(lang, 2, returntype,
				"output", LangTypeE(lang, fnc.vxtype))
	}
	return defaultvalue
}

func LangFuncDoc(
	lang *vxlang,
	fnc *vxfunc) string {
	var output = ""
	var doc = ""
	var argsdoc = ""
	switch lang {
	case langswift:
	case langjs:
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty":
		default:
			if fnc.vxtype.isgeneric || fnc.generictype != nil {
				argsdoc += "\n@param  {typemap} generic"
			}
		}
		for _, arg := range fnc.listarg {
			argsdoc += "\n@param "
			if arg.vxtype.name != "" {
				argsdoc += " {" + LangFromName(arg.vxtype.alias) + "}"
			}
			if arg.multi {
				argsdoc += " ..."
			}
			argsdoc += " " + LangFromName(arg.alias)
			if arg.doc != "" {
				argsdoc += " " + arg.doc
			}
		}
		if fnc.async {
			doc += "\n@async "
		}
		doc += "@function " + LangFromName(fnc.alias)
		if fnc.doc != "" {
			doc += "\n" + fnc.doc
		}
		if fnc.deprecated != "" {
			doc += "\n" + fnc.deprecated
		}
		doc += "" +
			argsdoc +
			"\n@return {" + fnc.vxtype.name + "}"
		output = "" +
			"  /**" +
			"\n   * " + StringFromStringIndent(doc, "   * ") +
			"\n   */"
	default:
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new<-type":
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
		output = "" +
			"  /**" +
			"\n   * " + StringFromStringIndent(doc, "   * ") +
			"\n   * (func " + fnc.name + ")" +
			"\n   */"
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
		returntypename, returngeneric := LangTypeGeneric(lang, fnc.generictype)
		mapgeneric[returntypename] = returngeneric
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !argtype.isfunc {
				if argtype.isgeneric {
					argtypename, arggeneric := LangTypeGeneric(lang, argtype)
					_, ok := mapgeneric[argtypename]
					if !ok {
						mapgeneric[argtypename] = arggeneric
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
		case langswift:
			_, returngeneric := LangTypeGeneric(lang, fnc.generictype)
			output2 = "<" + returngeneric + ">"
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

func LangFuncGenericVars(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	isinterface bool) string {
	output := ""
	if !isinterface {
		lineindent := LangIndent(lang, indent, true)
		if !fnc.isgeneric {
		} else if fnc.generictype != nil {
			returntype := LangFromName(fnc.generictype.alias)
			switch lang.genericcount {
			case 1:
				listarg := fnc.listarg
				for argidx, arg := range listarg {
					isskip := false
					if argidx == 0 {
						switch NameFromFunc(fnc) {
						case "vx/core/copy", "f_copy":
						case "vx/core/new", "vx/core/empty", "vx/core/new<-type",
							"f_new", "f_empty", "f_new_from_type":
							isskip = true
						}
					}
					if isskip {
					} else if !arg.isgeneric {
					} else if arg.generictype == nil {
					} else if returntype == LangFromName(arg.generictype.alias) {
						genericname := returntype
						output += lineindent + "let " + arg.alias + " = Vx_Core.vx_any_from_any(" + genericname + ", " + arg.alias + "_generic)"
					}
				}
			}
		}
	}
	return output
}

func LangFuncIFnHeader(
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
	case langswift:
		header = "func vx_fn_new(_ fn : @escaping " + ifn + ") -> " + vxreturntype
		if isinterface {
			header = "\n    " + header
		} else {
			header = "\n    public " + header
		}
	default:
		header = "\n    public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
	}
	return header
}

func LangFuncIFnVars(
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
	case langswift:
		vars += "" +
			"\n    var fn : " + ifn + "? = nil" +
			"\n"
	default:
		vars += "" +
			"\n    public " + ifn + " fn = null" + lang.lineend +
			"\n"
	}
	return vars
}

func LangFuncInstanceStatic(
	lang *vxlang,
	isinterface bool) (string, string) {
	funcinstance := ""
	funcstatic := ""
	switch lang {
	case langcpp, langcsharp, langjava:
		funcinstance = "public "
		funcstatic = "public static "
	case langkotlin:
		funcinstance = "fun "
		funcstatic = "fun "
	case langswift:
		if isinterface {
			funcinstance = "func "
		} else {
			funcinstance = "public func "
		}
		funcstatic = "public static func "
	default:
		funcinstance = "function "
		funcstatic = "function "
	}
	return funcinstance, funcstatic
}

func LangFuncInterfaceNative(
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
	case langswift:
		if extends != "" {
			extends += ", "
		}
		extends += "AnyObject"
		extends = " : " + extends
		output = lineindent + "public protocol Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	}
	return output
}

func LangFuncInterfaceFn(
	lang *vxlang,
	fnc *vxfunc) string {
	output := ""
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
			switch lang {
			case langswift:
				returntype = lang.future
			default:
				returntype = lang.future + "<" + returntype + ">"
			}
		}
		var args []string
		if fnc.context {
			contextarg := ""
			switch lang {
			case langkotlin, langswift:
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
			case langkotlin, langswift:
				argtext = argname + " : " + argtypename
			default:
				argtext = argtypename + " " + argname
			}
			args = append(args, argtext)
		}
		argnames := StringFromListStringJoin(args, ", ")
		switch lang {
		case langcsharp:
			output = "" +
				"\n    public delegate " + returntype + " IFn(" + argnames + ")" + lang.lineend +
				"\n"
		case langjava:
			output = "" +
				"\n    @FunctionalInterface" +
				"\n    public interface IFn {" +
				"\n      public " + returntype + " resolve(" + argnames + ")" + lang.lineend +
				"\n    }" +
				"\n"
		case langkotlin:
			output = "" +
				"\n    fun interface IFn {" +
				"\n      fun resolve(" + argnames + ") : " + returntype +
				"\n    }" +
				"\n"
		case langswift:
			argnames := StringFromListStringJoin(args, ", _ ")
			if argnames != "" {
				argnames = "_ " + argnames
			}
			output = "" +
				"\n    public typealias IFn = (" + argnames + ") -> " + returntype +
				"\n"
		}
	}
	return output
}

func LangFuncLambdaArgAny(
	lang *vxlang,
	indent int,
	lambdaarg vxarg) (string, string) {
	lambdaargname := LangFromName(lambdaarg.name)
	lambdaconvert := ""
	switch lang {
	case langswift:
		lambdaconvert =
			LangVal(lang, indent, lambdaarg.vxtype,
				lambdaargname,
				LangFuncCall(lang, indent,
					func_vx_any_from_any,
					LangTypeT(lang, lambdaarg.vxtype),
					lambdaargname+"_any"))
		lambdaargname += "_any"
	}
	return lambdaargname, lambdaconvert
}

func LangFuncLambdaArgName(
	lang *vxlang,
	lambdaarg vxarg) string {
	output := lambdaarg.name + "_any"
	switch lang {
	case langkotlin:
		output += " : vx_core.Type_any"
	}
	return output
}

func LangFuncLambdaFooter(
	lang *vxlang,
	indent int,
	outputnum int) string {
	output := ""
	lineindent1 := LangIndent(lang, indent, true)
	lineindent2 := LangIndent(lang, indent+1, true)
	sreturn := ""
	lineend := lineindent1 + "}"
	if outputnum >= 0 {
		switch lang {
		case langkotlin:
			sreturn = lineindent2 + "output"
			if outputnum > 0 {
				sreturn += "_" + StringFromInt(outputnum)
			}
		default:
			sreturn = lineindent2 + "return output"
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
	case langjava, langjs:
		output = "(" + args + ") -> {"
	case langkotlin:
		output = "{" + args + " ->"
	case langswift:
		output = "{(" + args + ") in"
	}
	return output
}

func LangFuncNativeAuto(
	lang *vxlang,
	fnc *vxfunc) string {
	output := ""
	var listargname []string
	if fnc.generictype != nil {
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
			argname := LangTypeTGeneric(lang, fnc.generictype)
			listargname = append(listargname, argname)
		}
	}
	if fnc.context {
		argname := "context"
		listargname = append(listargname, argname)
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let", "vx/core/let-async":
		for _, arg := range fnc.listarg {
			argname := LangNameFromArg(lang, arg)
			if argname != "args" {
				listargname = append(listargname, argname)
			}
		}
	default:
		for _, arg := range fnc.listarg {
			argname := LangNameFromArg(lang, arg)
			listargname = append(listargname, argname)
		}
	}
	argnames := StringFromListStringJoin(listargname, ", ")
	output = LangPkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangFuncName(fnc) + "(" + argnames + ")" + lang.lineend
	switch lang {
	case langcpp:
		if fnc.generictype != nil {
			argname := LangTypeTGeneric(lang, fnc.generictype)
			output = "" +
				"vx_core::Type_any result = " + output +
				"\noutput = vx_core::vx_any_from_any(" + argname + ", result)" + lang.lineend
		}
	case langswift:
		if fnc.generictype != nil {
			output = "let output = " + output
		}
	}
	return output
}

func LangFuncNewSuppressWarnings(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langjava:
		output = "\n  @SuppressWarnings(\"unchecked\")"
	}
	return output
}

func LangFuncOverride(
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
		case langswift:
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

func LangFuncPrefixReturnTypes(
	lang *vxlang,
	fnc *vxfunc,
	prefix string) (string, string, string) {
	returntype := LangTypeNameFullSimple(
		lang, fnc.vxtype, false)
	if fnc.generictype != nil {
		returntype = LangGenericFromType(
			lang, fnc.generictype)
	}
	funcprefix := ""
	returntype1 := ""
	returntype2 := ""
	switch lang {
	case langcpp:
		funcprefix = prefix + "::"
	}
	switch lang {
	case langcpp, langcsharp, langjava:
		if fnc.async {
			returntype = lang.future + "<" + returntype + ">"
		}
		returntype1 = returntype + " "
	case langkotlin:
		if fnc.async {
			returntype = lang.future + "<" + returntype + ">"
		}
		returntype2 = " : " + returntype
	case langswift:
		if fnc.async {
			returntype = lang.future
		}
		returntype2 = " -> " + returntype
	}
	return funcprefix, returntype1, returntype2
}

func LangFuncSuppressWarnings(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langjava:
		output = "\n      @SuppressWarnings(\"unchecked\")"
	}
	return output
}

func LangFuncTryCatch(
	lang *vxlang,
	linesubindent string) (string, string) {
	try := ""
	catch := ""
	switch lang {
	case langkotlin:
		try = linesubindent + "try {"
		catch = linesubindent + "} catch (err : Exception) {"
	case langswift:
		try = linesubindent + "do {"
		catch = linesubindent + "} catch {"
	default:
		try = linesubindent + "try {"
		catch = linesubindent + "} catch (Exception err) {"
	}
	return try, catch
}

func LangFuncVxAsyncAnyFromAny(
	lang *vxlang) string {
	vxasyncanyfromany := ""
	switch lang {
	case langcsharp, langswift:
		vxasyncanyfromany = LangPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future)"
	case langjava:
		vxasyncanyfromany = "(" + lang.future + "<T>)future"
	case langkotlin:
		vxasyncanyfromany = "future as (" + lang.future + "<T>)"
	}
	return vxasyncanyfromany
}

func LangFuncVxAnyFromAny(
	lang *vxlang,
	fnc *vxfunc) *vxfunc {
	funcvxanyfromany := NewFunc()
	funcvxanyfromany.async = fnc.async
	funcvxanyfromany.context = fnc.context
	funcvxanyfromany.isgeneric = true
	funcvxanyfromany.generictype = anytype1
	funcvxanyfromany.vxtype = anytype1
	funcvxanyfromany.isimplement = true
	funcvxanyfromanyname := "vx_any_from_any"
	if fnc.context {
		contextname := "-context"
		funcvxanyfromanyname += LangFromName(contextname)
	}
	if fnc.async {
		asyncname := "-async"
		funcvxanyfromanyname += LangFromName(asyncname)
	}
	funcvxanyfromany.name = funcvxanyfromanyname
	listargsfuncvxanyfromany := NewListArg()
	argvxanyfromanyvalue := NewArg("value")
	argvxanyfromanyvalue.isgeneric = true
	argvxanyfromanyvalue.vxtype = anytype2
	listargsfuncvxanyfromany = append(listargsfuncvxanyfromany, argvxanyfromanyvalue)
	funcvxanyfromany.listarg = listargsfuncvxanyfromany
	return funcvxanyfromany
}

func LangFuncVxFuncResolve(
	lang *vxlang,
	indent int,
	fnc *vxfunc,
	listargname []string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	fntype := LangFuncIFnType(lang, fnc)
	var returntype *vxtype
	if fnc.generictype == nil {
		returntype = fnc.vxtype
	} else {
		returntype = fnc.generictype
	}
	emptytype := ""
	generictype := ""
	if fnc.generictype == nil {
		switch NameFromType(returntype) {
		case "vx/core/boolean":
			emptytype = LangPkgNameDot(lang, "vx/core") + "c_false"
		default:
			emptytype = LangTypeE(lang, returntype)
		}
		generictype = LangTypeT(lang, returntype)
	} else {
		emptytype = LangPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1)"
		generictype = "generic_any_1"
	}
	resolve := ""
	resolveasync := ""
	resolvesync := ""
	switch lang {
	case langjava, langkotlin:
		resolve = "fnlocal.resolve(" + strings.Join(listargname, ", ") + ")"
	case langswift:
		resolve = "fnlocal(" + strings.Join(listargname, ", ") + ")"
		resolvesync = "" +
			sindent + "if let fnlocal = self.fn {" +
			LangVal(lang, 4, anytype,
				"anyoutput",
				resolve) +
			LangVarSet(lang, 4,
				"output",
				LangPkgNameDot(lang, "vx/core")+"f_any_from_any("+generictype+", anyoutput)") +
			LangIfEnd(lang, 3)
		resolveasync = "" +
			sindent + "if let fnlocal = self.fn {" +
			LangVarSet(lang, 4,
				"output",
				resolve) +
			LangIfElse(lang, 3,
				LangVarSet(lang, 4,
					"output",
					LangTypeEFuture(lang, returntype))) +
			LangIfEnd(lang, 3)
	default:
		resolve = "fnlocal(" + strings.Join(listargname, ", ") + ")"
	}
	if resolvesync == "" {
		resolvesync = "" +
			LangVarClassNullable(lang, 3,
				"fnlocal", fntype,
				LangTypeThis(lang)+".fn") +
			LangIfThen(lang, 3,
				LangClause(lang, false,
					"!=",
					"fnlocal",
					"null"),
				LangVal(lang, 4, anytype,
					"anyoutput",
					resolve)+
					LangVarSet(lang, 4,
						"output",
						LangPkgNameDot(lang, "vx/core")+"f_any_from_any("+generictype+", anyoutput)")) +
			LangIfEnd(lang, 3)
	}
	if resolveasync == "" {
		resolveasync = "" +
			LangVarClassNullable(lang, 3,
				"fnlocal",
				fntype,
				LangTypeThis(lang)+".fn") +
			LangIfThen(lang, 3,
				LangClause(lang, false,
					"==",
					"fnlocal",
					"null"),
				LangVarSet(lang, 4,
					"output",
					LangTypeEFuture(lang, returntype))) +
			LangIfElse(lang, 3,
				LangVarFuture(lang, 4, anytype,
					"future", resolve)+
					LangVarSet(lang, 4,
						"output",
						LangPkgNameDot(lang, "vx/core")+
							"vx_async_from_async(generic_any_1, future)")) +
			LangIfEnd(lang, 3)
	}
	if fnc.async {
		output = "" +
			LangVarFutureGeneric(lang, 3, returntype,
				"output", "") +
			resolveasync
	} else {
		output = "" +
			LangVarGeneric(lang, 3, returntype,
				"output",
				emptytype) +
			resolvesync
	}
	return output
}

func LangGenericFromType(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		switch lang {
		case langswift:
			switch typ.name {
			case "any-1":
				output = "T"
			case "list-1":
				output = "X"
			case "list-2", "list-3":
				output = "any Vx_Core.Type_list"
			case "map-1":
				output = "N"
			case "map-2", "map-3":
				output = "any Vx_Core.Type_map"
			case "rawlist-1":
				output = "[any Vx_Core.Type_any]"
			case "rawmap-1":
				output = "Vx_Core.Map<any Vx_Core.Type_any>"
			default:
				output = "any Vx_Core.Type_any"
			}
		default:
			switch typ.name {
			case "any-1":
				output = "T"
			case "any-2":
				output = "U"
			case "any-3":
				output = "V"
			case "list-1":
				output = "X"
			case "list-2":
				output = "Y"
			case "list-3":
				output = "Z"
			case "map-1":
				output = "N"
			case "map-2":
				output = "O"
			case "map-3":
				output = "P"
			case "rawlist-1":
				output = "List<T>"
			case "rawmap-1":
				output = "Map<" + LangTypeName(lang, rawstringtype) + ", T>"
			case "struct-1":
				output = "Q"
			case "struct-2":
				output = "R"
			case "struct-3":
				output = "S"
			}
		}
	} else {
		output = LangTypeName(lang, typ)
	}
	return output
}

func LangIfThen(
	lang *vxlang,
	indent int,
	ifclause string,
	thenclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langswift:
		output = sindent + "if " + ifclause + " {" + thenclause
	default:
		output = sindent + "if (" + ifclause + ") {" + thenclause
	}
	return output
}

func LangIfClause(
	lang *vxlang,
	typ *vxtype,
	op string,
	left string,
	right string) string {
	output := ""
	if right == "null" {
		right = LangNull(lang)
	}
	switch lang {
	case langjava:
		switch op {
		case "!":
			output = "(!" + left + ")"
		case "==":
			switch typ {
			case rawstringtype:
				sop := ".equals(" + right + ")"
				output = "(" + left + sop + ")"
			default:
				output = "(" + left + " " + op + " " + right + ")"
			}
		default:
			output = "(" + left + " " + op + " " + right + ")"
		}
	case langswift:
		switch op {
		case "!":
			output = "(!" + left + ")"
		default:
			output = left + " " + op + " " + right
		}
	default:
		switch op {
		case "!":
			output = "(!" + left + ")"
		default:
			output = "(" + left + " " + op + " " + right + ")"
		}
	}
	return output
}

func LangIfElse(
	lang *vxlang,
	indent int,
	elseclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "} else {" + elseclause
	return output
}

func LangIfElseIf(
	lang *vxlang,
	indent int,
	ifclause string,
	thenclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langswift:
		output = sindent + "} else if " + ifclause + " {" + thenclause
	default:
		output = sindent + "} else if (" + ifclause + ") {" + thenclause
	}
	return output
}

func LangIfElseType(
	lang *vxlang,
	indent int,
	typ *vxtype,
	subtype *vxtype,
	svar string,
	scastvar string,
	isfuture bool,
	thenclause string) string {
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
			output += LangVarOld(lang, indent+1, typ, subtype,
				scastvar, LangVarAsType(lang, svar, typ), false, isfuture)
		}
	case langswift:
		if scastvar != "" {
			output = sindent + "} else if let " + scastvar + " = " + svar + " as? " + LangTypeName(lang, typ) + " {"
		} else {
			output = sindent + "} else if " + LangIsType(lang, svar, typ) + " {"
		}
	}
	output += thenclause
	return output
}

func LangIfEnd(
	lang *vxlang,
	indent int) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "}"
	return output
}

func LangImport(
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
	case langswift:
		ipos := IntFromStringFind(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringUCaseFirst(path)
		importline = "import " + path
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangIndent(
	lang *vxlang,
	indent int,
	line bool) string {
	output := ""
	if line {
		output += "\n"
	}
	output += StringRepeat(lang.indent, indent)
	return output
}

func LangIntFromString(
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
	case langswift:
		output = "Vx_Core.vx_int_from_string(" + text + ")"
	}
	return output
}

func LangIsTypeText(
	lang *vxlang,
	svar string,
	stype string) string {
	output := ""
	switch lang {
	case langcpp:
		output = "vx_core::vx_boolean_from_type_trait(" + svar + ", " + stype + ")"
	case langcsharp, langkotlin, langswift:
		output = svar + " is " + stype
	case langjava:
		output = svar + " instanceof " + stype
	}
	return output
}

func LangNamespaceOpenClose(
	lang *vxlang,
	pkgname string,
	pkgpath string) (string, string) {
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
	case langswift:
		namespaceopen += "" +
			"\npublic enum " + pkgname + " {" +
			"\n" +
			"\n"
		namespaceclose += "" +
			"\n}" +
			"\n"
		if pkgname == "AppTest" {
			namespaceopen += "" +
				"\n  static func main(_ args : [String]) {" +
				"\n    Vx.initialize()" +
				"\n    test_basics(context)" +
				"\n    test_writetestsuite(context)" +
				"\n  }" +
				"\n"
			namespaceclose += "" +
				"\nAppTest.main(CommandLine.arguments)" +
				"\n"
		}
	}
	return namespaceopen, namespaceclose
}

func LangOverride(
	lang *vxlang,
	indent int,
	isinterface bool) (string, string, string) {
	override1 := ""
	override2 := ""
	override3 := ""
	switch lang {
	case langcsharp, langswift:
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

func LangNull(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langswift:
		output = "nil"
	default:
		output = "null"
	}
	return output
}

func LangPackageImports(
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
		if BooleanFromStringContains(body, " "+lang.future+"<") {
			output += "\nimport java.util.concurrent." + lang.future + lang.lineend
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
		if BooleanFromStringContains(body, " "+lang.future+"<") {
			output += "\nimport java.util.concurrent." + lang.future + lang.lineend
		}
	case langswift:
		if test {
			output += "" +
				"\nimport Vx"
		} else {
			output += "\nimport Foundation"
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
					case langcsharp, langswift:
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
				case langcsharp, langswift:
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
	case langswift:
	}
	return output
}

func LangPackagePathFromPrefixName(
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
		name = LangPkgName(lang, name)
	case langkotlin:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = StringFromStringFindReplace(pkgname, "/", "_")
		name = LangPkgName(lang, name)
	case langswift:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", "_")
		pkgpath = LangFromName(pkgpath)
		name = LangPkgName(lang, pkgname)
	default:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangPkgName(lang, name)
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
			"  public static class PackageRunOnce {" +
			"\n    public static bool RunOnce() {"
		staticclose = "" +
			"\n      return true" + lang.lineend +
			"\n    }" +
			"\n  }" +
			"\n" +
			"\n  public static bool ranonce = PackageRunOnce.RunOnce()" + lang.lineend +
			"\n"
	case langjava:
		staticopen = "  static {"
		staticclose += "" +
			"\n  }" +
			"\n"
	case langkotlin:
		staticopen = "  init {"
		staticclose += "" +
			"\n  }" +
			"\n"
	case langswift:
		staticopen = "" +
			"  private static var initialized : Bool = false" +
			"\n" +
			"\n  public static func vx_initialize() {" +
			"\n    guard !initialized else { return }" +
			"\n    initialized = true"
		staticclose = "" +
			"\n  }" +
			"\n"
	}
	return staticopen, staticclose
}

func LangPackageSubPrefixSubDomainPath(
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
	case langswift:
	}
	return subprefix, subdomainpath
}

func LangPathtext(
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

func LangPkgName(
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
	case langswift:
		output = StringUCaseFirstFromStringDelim(pkgname, "/")
		output = StringFromStringFindReplace(output, "/", "_")
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
	case langcsharp, langswift:
		output = StringUCaseFirstFromStringDelim(
			pkgpath, "/")
	}
	return output
}

func LangPrintLine(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "System.Console.WriteLine"
	case langjava:
		output = "System.out.println"
	case langkotlin:
		output = "println"
	case langswift:
		output = "print"
	}
	return output
}

func LangProjectPkgPrefixAppPathTestPath(
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
	case langswift:
		apppath += "/App"
	}
	return pkgprefix, apppath, testpath
}

func LangStringFromFloat(
	lang *vxlang,
	value string) string {
	output := ""
	switch lang {
	case langswift:
		output = "Vx_Core.vx_string_from_float(" + value + ")"
	default:
		output = value
	}
	return output
}

func LangStringFromInt(
	lang *vxlang,
	value string) string {
	output := ""
	switch lang {
	case langswift:
		output = "Vx_Core.vx_string_from_int(" + value + ")"
	default:
		output = value
	}
	return output
}

func LangSwitchCase(
	lang *vxlang,
	indent int,
	value string,
	clause string) string {
	output := ""
	sindent := LangIndent(
		lang, indent, true)
	sindent2 := LangIndent(
		lang, indent+1, true)
	switch lang {
	default:
		output += "" +
			sindent + "case " + value + ":" + lang.lineend +
			clause +
			sindent2 + "break" + lang.lineend
	}
	return output
}

func LangTestAppBasic(
	lang *vxlang) string {
	output := ""
	sindent := LangIndent(lang, 2, true)
	test_helloworld := sindent + LangFuncCall(lang, 2,
		func_test_helloworld) + lang.lineend
	test_run_testdescribe := sindent + LangFuncCall(lang, 2,
		func_test_run_testdescribe,
		"context") + lang.lineend
	test_run_testdescribelist := sindent + LangFuncCall(lang, 2,
		func_test_run_testdescribelist,
		"context") + lang.lineend
	test_run_testresult := sindent + LangFuncCall(lang, 2,
		func_test_run_testresult,
		"context") + lang.lineend
	test_run_testresult_async := sindent + LangFuncCall(lang, 2,
		func_test_run_testresult_async,
		"context") + lang.lineend
	switch lang {
	case langcsharp:
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_basics() {" +
			test_helloworld +
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
			test_helloworld +
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
			test_helloworld +
			"\n    TestLib.test_async_new_from_value()" +
			"\n    TestLib.test_async_from_async_fn()" +
			"\n    TestLib.test_list_from_list_async()" +
			"\n    TestLib.test_pathfull_from_file()" +
			"\n    TestLib.test_read_file()" +
			"\n    TestLib.test_write_file()" +
			"\n  }" +
			"\n"
	case langswift:
		output = "" +
			"\n  public static func test_basics(" +
			"\n    _ context : Vx_Core.Type_context" +
			"\n  ) {" +
			test_helloworld +
			"\n    TestLib.test_async_new_from_value()" +
			"\n    TestLib.test_async_from_async_fn()" +
			"\n    TestLib.test_list_from_list_async()" +
			"\n    TestLib.test_pathfull_from_file()" +
			"\n    TestLib.test_read_file()" +
			"\n    TestLib.test_write_file()" +
			test_run_testresult +
			test_run_testdescribe +
			test_run_testdescribelist +
			test_run_testresult_async +
			"\n  }" +
			"\n"
	}
	return output
}

func LangTestAssertEquals(
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
	case langswift:
	}
	return output
}

func LangTestAssertNotEquals(
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
	case langswift:
	}
	return output
}

func LangTestImport(
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
	case langswift:
		importline = "" +
			"import VxTest" +
			"\nimport TestLib"
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangTestImportExtra(
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
	case langswift:
	}
	return output
}

func LangTestLibNative(
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
			"\nimport java.util.concurrent." + lang.future + ";" +
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
			/*
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
				"\n    " + lang.future + "<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);" +
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
			*/
			namespaceclose
	case langkotlin:
		output = "" +
			"import java.util.*" +
			"\nimport java.util.concurrent." + lang.future +
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
	case langswift:
		output = "" +
			"import Vx" +
			"\n" +
			namespaceopen +
			"  public static let spath : String = " + spath +
			"\n" +
			commontests +
			namespaceclose
	}
	return output
}

func LangTestLibFnAsync(
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
			"\n      " + lang.future + "<Core.Type_any> output = Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case langkotlin:
		output = "" +
			"\n    val fn_async : vx_core.Func_any_from_any_async = vx_core.t_any_from_any_async.vx_fn_new({" +
			"\n      anyval ->" +
			"\n      val stringval : vx_core.Type_string = anyval as vx_core.Type_string" +
			"\n      val sout : String = stringval.vx_string() + \"!\"" +
			"\n      val outval : vx_core.Type_any = vx_core.vx_new_string(sout)" +
			"\n      val output : " + lang.future + "<vx_core.Type_any> = vx_core.vx_async_new_from_value(outval)" +
			"\n      output" +
			"\n    });"
	case langswift:
		output = "" +
			"\n    let fn_async : Vx_Core.Func_any_from_any_async = Vx_Core.t_any_from_any_async.vx_fn_new({" +
			"\n      anyval in" +
			"\n      let stringval : any Vx_Core.Type_string = anyval as! Vx_Core.Type_string" +
			"\n      let sout : String = stringval.vx_string() + \"!\"" +
			"\n      let outval : any Vx_Core.Type_any = Vx_Core.vx_new_string(sout)" +
			"\n      let output : " + lang.future + " = Vx_Core.vx_async_new_from_value(outval)" +
			"\n      return output" +
			"\n    });"
	}
	return output
}

func LangTestLibLambda(
	lang *vxlang,
	indent int) string {
	output := ""
	sindent := LangIndent(lang, indent, true)
	switch lang {
	case langcpp:
		output = "" +
			"{}," +
			sindent + "[](vx_core::Type_any any) {" +
			sindent + " 	return any;" +
			sindent + "}"
	case langcsharp:
		output = "" +
			"(any) => {" +
			sindent + " 	return any;" +
			sindent + "}"
	case langjava, langjs:
		output = "" +
			"(any) -> {" +
			sindent + "  return any;" +
			sindent + "}"
	case langkotlin:
		output = "" +
			"{any ->" +
			sindent + " 	any" +
			sindent + "}"
	case langswift:
		output = "" +
			"{(any) in" +
			sindent + "  return any" +
			sindent + "}"
	}
	return output
}

func LangTestLibParamsOpenClose(
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

func LangTestLibPath(
	lang *vxlang,
	spath string) string {
	output := ""
	switch lang {
	case langswift:
		output = spath + "/TestLib"
	default:
		output = spath
	}
	return output
}

func LangTestNamespaceOpenClose(
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
	case langswift:
	}
	return namespaceopen, namespaceclose
}

func LangTestPackage(
	lang *vxlang,
	pkg *vxpackage,
	testpackagetype *vxtype) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			LangVar(lang, 2, testpackagetype,
				"testpackage",
				"Test"+
					LangPkgName(lang, pkg.name)+
					"Test.test_package(context)") +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langjava:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackage testpackage = " + LangPkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langkotlin:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  fun test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() : Unit {" +
			"\n    val testpackage : vx_test.Type_testpackage = " + LangPkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langswift:
		output = "" +
			"\n  func test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			LangVar(lang, 2, testpackagetype,
				"testpackage",
				LangPkgName(lang, pkg.name)+
					"Test.test_package(context)") +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	}
	return output
}

func LangTestPackageOpenClose(
	lang *vxlang,
	pkgname string) (string, string) {
	packageopen := ""
	packageclose := ""
	switch lang {
	case langcsharp:
		packageopen = "" +
			"\npublic " + LangFinalClass(lang) + "class " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	case langjava:
		packageopen = "" +
			"\npublic " + LangFinalClass(lang) + "class " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	case langkotlin:
		packageopen = "" +
			"\nobject " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	case langswift:
		packageopen = "" +
			"\npublic enum " + pkgname + "Test {" +
			"\n"
		packageclose = "\n}\n"
	}
	return packageopen, packageclose
}

func LangTestPackagePrefix(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Test"
	}
	return output
}

func LangTestPackages(
	lang *vxlang,
	project *vxproject,
	command *vxcommand) (string, string, string) {
	tests := ""
	imports := ""
	imports += LangImport(
		lang,
		PackageCoreFromProject(project),
		imports)
	listpackage := project.listpackage
	testpackageprefix := LangTestPackagePrefix(lang)
	var listtestpackage []string
	for _, pkg := range listpackage {
		iscontinue := true
		if len(lang.filewhitelist) > 0 {
			iscontinue = BooleanFromListStringContains(lang.filewhitelist, pkg.name)
		}
		if len(lang.fileblacklist) > 0 {
			iscontinue = !BooleanFromListStringContains(lang.fileblacklist, pkg.name)
		}
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			if pkg.name != "" {
				imports += LangTestImport(lang, pkg, imports)
				testpackage := "\n      " + testpackageprefix + LangPkgName(lang, pkg.name) + "Test.test_package(context)"
				listtestpackage = append(
					listtestpackage, testpackage)
				switch lang {
				case langswift:
				default:
					tests += LangTestPackage(lang, pkg, testpackagetype)
				}
			}
		}
	}
	testpackages := StringFromListStringJoin(
		listtestpackage, ",")
	return imports, tests, testpackages
}

func LangTestResourcesPath(
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

func LangTestTargetPath(
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

func LangTestVarTestCases(
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
			LangVarCollection(lang, 2, rawlisttype, anytype,
				"testcases", vararraylisttestcase)
	}
	return output
}

func LangTestWriteTestSuite(
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
			LangVar(lang, 2, testpackagelisttype,
				"testpackagelist",
				testpackagedata) +
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
	case langswift:
		testpackagedata := "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testpackagelisttype) + "," +
			testpackages +
			"\n    )"
		output = "" +
			"\n  public static func test_writetestsuite(" +
			"\n    _ context : Vx_Core.Type_context" +
			"\n  ) {" +
			LangVar(lang, 2, testpackagelisttype,
				"testpackagelist",
				testpackagedata) +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" + lang.lineend +
			"\n  }" +
			"\n"
	}
	return output
}

func LangTypeBoolean(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "bool"
	case langswift:
		output = "Bool"
	default:
		output = "Boolean"
	}
	return output
}

func LangTypeClassHeader(
	lang *vxlang,
	indent int,
	typ *vxtype) string {
	output := ""
	lineindent := LangIndent(
		lang, indent, true)
	typename := LangFromName(typ.alias)
	switch lang {
	case langcsharp, langswift:
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

func LangTypeDoc(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	switch lang {
	case langswift:
	default:
		doc := ""
		doc = "type: " + typ.name
		if typ.doc != "" {
			doc += "\n" + typ.doc
		}
		if typ.deprecated != "" {
			doc += "\n" + typ.deprecated
		}
		output = "" +
			"  /**" +
			"\n   * " + StringFromStringIndent(doc, "   * ") +
			"\n   * (type " + typ.name + ")" +
			"\n   */"
	}
	return output
}

func LangTypeElseIfListAny(
	lang *vxlang,
	allowtype *vxtype) string {
	output := ""
	switch lang {
	case langcsharp, langswift:
		output = "" +
			LangIfElseType(lang, 4,
				rawlistanytype, emptytype, "valsub", "listany", false,
				LangForListHeader(lang, 5,
					"item", anytype, "listany")+
					LangIfThen(lang, 6,
						"false", "")+
					LangIfElseType(lang, 6,
						allowtype, emptytype, "item", "valitem", false,
						LangVarSet(lang, 7,
							"ischanged", "true")+
							LangVarListAdd(lang, 7,
								"listval", "valitem"))+
					LangIfEnd(lang, 6)+
					LangIfEnd(lang, 5))
	case langjava, langkotlin:
		output = "" +
			LangIfElseType(lang, 4,
				rawlistunknowntype, emptytype, "valsub", "listunknown", false,
				LangForListHeader(lang, 5,
					"item", rawobjecttype, "listunknown")+
					LangIfThen(lang, 6,
						"false", "")+
					LangIfElseType(lang, 6,
						allowtype, emptytype, "item", "valitem", false,
						LangVarSet(lang, 7,
							"ischanged", "true")+
							LangVarListAdd(lang, 7,
								"listval", "valitem")+
							LangIfEnd(lang, 6)+
							LangIfEnd(lang, 5)))
	}
	return output
}

func LangTypeFloat(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcpp, langcsharp:
		output = "float"
	default:
		output = "Float"
	}
	return output
}

func LangTypeGeneric(
	lang *vxlang,
	typ *vxtype) (string, string) {
	generictype := ""
	typetext := ""
	if typ != nil {
		typename := ""
		switch typ {
		case rawlisttype1, rawmaptype1:
			typename = LangNameTypeFromTypeSimple(lang, anytype, true)
		default:
			typename = LangNameTypeFromTypeSimple(
				lang, typ, true)
			generictype = LangGenericFromType(
				lang, typ)
			switch lang {
			case langswift:
				if BooleanFromStringStarts(typename, "any ") {
					typename = typename[4:]
				}
			}
		}
		typetext = generictype + " " + lang.classext + " " + typename
	}
	return generictype, typetext
}

func LangTypeInt(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "int"
	case langkotlin, langswift:
		output = "Int"
	default:
		output = "Integer"
	}
	return output
}

func LangTypeInterfaceBasics(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	isbasics := false
	switch NameFromType(typ) {
	case "vx/core/any":
		switch lang {
		case langcsharp, langjava, langkotlin:
			isbasics = true
		case langswift:
			isbasics = true
		}
	}
	if isbasics {
		output += "" +
			LangTypeVxNew(lang, typ, true) +
			LangTypeVxCopy(lang, typ, true) +
			LangTypeVxEmpty(lang, typ, true) +
			LangTypeVxType(lang, typ, true)
	}
	return output
}

func LangTypeInterfaceCustom(
	lang *vxlang,
	customline string) string {
	ipos1 := 0
	switch lang {
	case langswift:
		if BooleanFromStringStarts(customline, "public ") {
			ipos1 += 7
		}
	default:
		if BooleanFromStringStarts(customline, "override ") {
			ipos1 += 9
		}
	}
	ipos2 := IntFromStringFindLast(
		customline, "{")
	output := customline[ipos1:ipos2-1] + lang.lineend
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
	extends := ""
	var extendtexts []string
	for _, extendtype := range extendtypes {
		extendpart := LangTypeNameExtends(lang, extendtype)
		extendtexts = append(extendtexts, extendpart)
	}
	extends = StringFromListStringJoin(extendtexts, ", ")
	switch lang {
	case langcsharp:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extends + " {" +
			body +
			lineindent + "}\n"
	case langjava:
		if extends != "" {
			extends = " extends " + extends
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extends + " {" +
			body +
			lineindent + "}\n"
	case langkotlin:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extends + " {" +
			body +
			lineindent + "}\n"
	case langswift:
		if extends != "" {
			extends += ", "
		}
		extends += "AnyObject"
		extends = " : " + extends
		output = lineindent + "public protocol Type_" + LangNameFromType(lang, typ) + extends + " {" +
			body +
			lineindent + "}\n"
	}
	return output
}

func LangTypeMapGetOrElse(
	lang *vxlang,
	typ *vxtype) string {
	output := ""
	switch lang {
	case langcsharp, langswift:
		output = "mapval.getOrElse(skey, " + LangTypeE(lang, typ) + ")"
	default:
		output = "mapval.getOrDefault(skey, " + LangTypeE(lang, typ) + ")"
	}
	return output
}

func LangTypeMapKeysetGet(
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
	case langswift:
		keyset = "\n      let keys : [String] = mapval.keys()" + lang.lineend
		mapget = "mapval.get(key)"
	}
	return keyset, mapget
}

func LangTypeNameFullSimple(
	lang *vxlang,
	typ *vxtype,
	simple bool) string {
	name := ""
	switch typ {
	case nonetype:
		switch lang {
		case langkotlin:
			name = "Unit"
		case langswift:
			name = "()"
		default:
			name = "void"
		}
	case rawbooltype:
		switch lang {
		case langcpp, langcsharp:
			name = "bool"
		case langjava:
			name = "boolean"
		case langkotlin:
			name = "Boolean"
		case langswift:
			name = "Bool"
		}
	case rawbooleantype:
		switch lang {
		case langcpp, langcsharp:
			name = "bool"
		case langjava, langkotlin:
			name = "Boolean"
		case langswift:
			name = "Bool"
		}
	case rawfloattype:
		name = LangTypeFloat(lang)
	case rawifntype:
		name = "IFn"
	case rawinttype:
		switch lang {
		case langkotlin, langswift:
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
		case langkotlin, langswift:
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
		case langswift:
			name = "[Any]"
		}
	case rawlistanytype:
		switch lang {
		case langswift:
			name = "[" + LangTypeNameFullSimple(lang, anytype, true) + "]"
		default:
			name = "List<" + LangTypeNameFullSimple(lang, anytype, true) + ">"
		}
	case rawmaptype:
		switch lang {
		case langcpp:
			name = "std::map"
		case langcsharp:
			name = "Vx.Core.Map"
		case langjava, langkotlin:
			name = "Map"
		case langswift:
			name = "Vx_Core.Map"
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
		case langswift:
			name = "[Any]"
		}
	case rawmapanytype:
		switch lang {
		case langcpp:
			name = "std::map<std::string, " + LangTypeNameFullSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangTypeNameFullSimple(lang, anytype, true) + ">"
		case langswift:
			name = "Vx_Core.Map<" + LangTypeNameFullSimple(lang, anytype, true) + ">"
		default:
			name = "Map<String, " + LangTypeNameFullSimple(lang, anytype, true) + ">"
		}
	case rawobjecttype:
		switch lang {
		case langcpp:
			name = "object"
		case langcsharp:
			name = "object"
		case langkotlin:
			name = "Any"
		case langswift:
			name = "Any"
		default:
			name = "Object"
		}
	case rawstringtype:
		name = LangTypeString(lang)
	case rawvoidtype:
		switch lang {
		case langkotlin:
			name = "Unit"
		case langswift:
			name = "()"
		default:
			name = "void"
		}
	default:
		switch typ.name {
		case "rawlist":
			subtype := typ.subtype
			subtypename := LangTypeName(lang, subtype)
			switch lang {
			case langswift:
				name = "[" + subtypename + "]"
			default:
				name = "List<" + subtypename + ">"
			}
		case "rawmap":
			subtype := typ.subtype
			subtypename := LangTypeName(lang, subtype)
			switch lang {
			case langcpp:
				name = "std::Map<std::string, " + subtypename + ">"
			case langcsharp:
				name = "Vx.Core.Map<string, " + subtypename + ">"
			case langswift:
				name = "Vx_Core.Map<" + subtypename + ">"
			default:
				name = "Map<String, " + subtypename + ">"
			}
		default:
			if typ.isgeneric && !simple {
				name = LangTypeNameSimple(
					lang, typ, simple)
			} else {
				name = LangPkgName(
					lang, typ.pkgname)
				if typ.isfunc {
					name += lang.pkgref + "Func_"
				} else {
					name += lang.pkgref + "Type_"
				}
				name += LangTypeNameSimple(
					lang, typ, simple)
			}
			switch lang {
			case langswift:
				switch name {
				case "T", "X", "N":
				default:
					name = "any " + name
				}
			}
		}
	}
	return name
}

func LangTypeNameSimple(
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
		case langswift:
			name = "Bool"
		}
	case rawbooleantype:
		switch lang {
		case langcsharp:
			name = "bool"
		case langjava, langkotlin:
			name = "Boolean"
		case langswift:
			name = "Bool"
		}
	case rawfloattype:
		name = LangTypeFloat(lang)
	case rawifntype:
		switch lang {
		case langcsharp, langjava, langkotlin, langswift:
			name = "IFn"
		}
	case rawinttype:
		switch lang {
		case langcsharp, langjava:
			name = "int"
		case langkotlin, langswift:
			name = "Int"
		}
	case rawintegertype:
		switch lang {
		case langcsharp, langjava:
			name = "Integer"
		case langkotlin, langswift:
			name = "Int"
		}
	case rawlisttype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List"
		case langswift:
			name = "Array"
		}
	case rawlistanytype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List<" + LangTypeNameSimple(lang, anytype, true) + ">"
		case langswift:
			name = "[" + LangTypeNameSimple(lang, anytype, true) + "]"
		}
	case rawlistunknowntype:
		switch lang {
		case langcsharp, langswift:
			name = "List<object>"
		case langjava:
			name = "List<?>"
		case langkotlin:
			name = "List<*>"
		case langswift:
			name = "[Any]"
		}
	case rawmaptype:
		switch lang {
		case langcsharp:
			name = "Vx.Core.Map"
		case langjava, langkotlin:
			name = "Map"
		case langswift:
			name = "Vx_Core.Map"
		}
	case rawmapanytype:
		switch lang {
		case langcpp:
			name = "std::map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case langjava, langkotlin:
			name = "Map<String, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case langswift:
			name = "Vx_Core.Map<" + LangTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		name = LangTypeString(lang)
	case rawobjecttype:
		switch lang {
		case langcsharp:
			name = "object"
		case langjava:
			name = "Object"
		case langkotlin, langswift:
			name = "Any"
		}
	case rawvoidtype:
		switch lang {
		case langkotlin:
			name = "Unit"
		case langswift:
			name = "()"
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

func LangTypeNameSubtype(
	lang *vxlang,
	typ *vxtype,
	subtype *vxtype) string {
	output := LangNameTypeFromTypeSimple(
		lang, subtype, false)
	switch typ {
	case rawlisttype:
		switch lang {
		case langswift:
			output = "[" + output + "]"
		default:
			output = "List<" + output + ">"
		}
	case rawmaptype:
		switch lang {
		case langcpp:
			output = "std::map<std::string, " + output + ">"
		case langcsharp:
			output = "Vx.Core.Map<string, " + output + ">"
		case langswift:
			output = "Vx_Core.Map<" + output + ">"
		default:
			output = "Map<String, " + output + ">"
		}
	}
	return output
}

func LangTypeProperties(
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

func LangTypeString(
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

func LangTypeStringbuilder(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n      System.Text.StringBuilder " + varname + " = new System.Text.StringBuilder(value.vx_string())" + lang.lineend
	case langjava:
		output = "" +
			"\n      StringBuilder " + varname + " = new StringBuilder(value.vx_string())" + lang.lineend
	case langkotlin:
		output = "" +
			"\n      var " + varname + " : kotlin.text.StringBuilder = StringBuilder(value.vx_string())"
	case langswift:
		output = "" +
			"\n      var " + varname + " : String = value.vx_string()" + lang.lineend
	}
	return output
}

func LangTypeThis(
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
	outval := LangFuncCall(lang, 4,
		func_vx_mapimmutable, "map")
	switch lang {
	case langcsharp:
		convertmap := ""
		if typ.name == "any" {
			convertmap = "this.vx_p_map"
		} else {
			convertmap = LangPkgNameDot(lang, "vx/core") + "vx_map_from_map<" + LangTypeName(lang, anytype) + ", " + LangTypeName(lang, typ) + ">(this.vx_p_map)"
		}
		copymap = "" +
			LangVarCollection(lang, 3, rawmaptype, anytype,
				"anymap", convertmap) +
			LangVarCollection(lang, 3, rawmaptype, anytype,
				"map", "anymap.copy()")
	case langswift:
		convertmap := ""
		if typ.name == "any" {
			outval = "self.vx_p_map"
		} else {
			convertmap = "" +
				LangPkgNameDot(lang, "vx/core") +
				"vx_map_from_map(" +
				//				LangTypeName(lang, anytype) + ", " +
				//				LangTypeName(lang, typ) +
				//				"(" +
				LangTypeT(lang, anytype) + ", " +
				"self.vx_p_map" +
				")"
			copymap = "" +
				LangValCollection(lang, 3, rawmaptype, anytype,
					"map", convertmap)
			outval = "map"
		}
	default:
		copymap = "" +
			LangVarCollection(lang, 3, rawmaptype, anytype,
				"map",
				LangVarMapNew(lang, anytype, LangTypeThis(lang)+".vx_p_map"))
	}
	prefix := LangTypeName(lang, typ)
	output := "" +
		LangFuncHeader(lang, 2,
			prefix, funcvxmap, 0,
			copymap+
				LangVal(lang, 3,
					rawmapanytype,
					"output",
					outval))
	return output
}

func LangTypeVxNewVals(
	lang *vxlang) string {
	output := "vals"
	switch lang {
	case langkotlin:
		output = "*vals"
	}
	return output
}

func LangValMapNew(
	lang *vxlang,
	typ *vxtype,
	value string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = LangFuncCall(lang, 0,
			func_vx_mapimmutable,
			"new Vx.Core.LinkedHashMap<string, "+
				LangTypeName(lang, typ)+
				">("+
				value+
				")")
	case langkotlin:
		output = LangFuncCall(lang, 0,
			func_vx_mapimmutable,
			"LinkedHashMap<String, "+
				LangTypeName(lang, typ)+
				">("+
				value+
				")")
	case langswift:
		output = "Vx_Core.Map<" +
			LangTypeName(lang, typ) +
			">(" +
			value +
			")"
	default:
		output = LangFuncCall(lang, 0,
			func_vx_mapimmutable,
			"new LinkedHashMap<String, "+LangTypeName(lang, typ)+">("+value+")")
	}
	return output
}

func LangVarAll(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	subtype *vxtype,
	varname string,
	varvalue string,
	isconst bool,
	isfuture bool,
	isstatic bool,
	isprop bool,
	isgeneric bool,
	isnullable bool) string {
	output := LangIndent(lang, indent, true)
	svalue := LangVarValue(lang, vartype, varvalue)
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
			ismutable := true
			if isconst || isprop {
				ismutable = false
			}
			//			 else if varvalue == ":new" {
			//				ismutable = true
			//			} else if BooleanFromStringStarts(svalue, "LinkedHashMap<") {
			//				ismutable = true
			//			}
			if ismutable {
				typetext = "Mutable" + typetext
			}
			if varvalue == ":new" {
				svalue = "LinkedHashMap<String, " + LangNameTypeFullFromType(lang, subtype) + ">()"
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
			typetext = lang.future + "<" + typetext + ">"
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
	case langswift:
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "[" + LangNameTypeFullFromType(lang, subtype) + "]"
			if varvalue == ":new" {
				svalue = "[]"
			}
		case rawmaptype:
			if isconst || isprop {
				typetext = "Vx_Core.Map<" + LangNameTypeFullFromType(lang, subtype) + ">"
			} else {
				typetext = "Vx_Core.MapMutable<" + LangNameTypeFullFromType(lang, subtype) + ">"
			}
			if varvalue == ":new" {
				svalue = "Vx_Core.MapMutable<" + LangNameTypeFullFromType(lang, subtype) + ">()"
			}
		case rawlistunknowntype:
			typetext = "[]"
			if varvalue == ":new" {
				svalue = "[]"
			}
		default:
			if isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
			switch svalue {
			case "":
				if isnullable {
				} else if isfuture {
					//svalue = "Vx.Core.vx_async_empty(" + LangTypeTGeneric(lang, vartype) + ")"
				} else {
					svalue = LangTypeE(lang, vartype)
				}
			}
		}
		if isfuture {
			if BooleanFromStringStarts(typetext, "any ") {
				typetext = typetext[4:]
			}
			typetext = lang.future
		}
		prefix := "var"
		if isstatic {
			prefix = "let"
		} else if isconst {
			prefix = "let"
		}
		snullable1 := ""
		snullable2 := ""
		if isprop || isnullable {
			switch vartype {
			case rawlisttype:
			case rawmaptype:
			case rawlistunknowntype:
			default:
				snullable1 = "("
				snullable2 = ")?"
			}
		}
		if svalue == "null" {
			svalue = "nil"
		}
		output += prefix + " " + varname + " : " + snullable1 + typetext + snullable2
		if svalue != "" {
			output += " = " + svalue
		}
	}
	return output
}

func LangVarAsType(
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
		case langswift:
			typetext = "[Any]"
		default:
			typetext = LangNameTypeFullFromType(lang, typ)
		}
	default:
		typetext = LangNameTypeFullFromType(lang, typ)
	}
	return LangVarAsTypeText(lang, svar, typetext)
}

func LangVarAsTypeText(
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
	case langswift:
		output = svar + " as! " + stype
	}
	return output
}

func LangVarClassAll(
	lang *vxlang,
	indent int,
	varname string,
	vartype *vxtype,
	isconst bool,
	isnullable bool,
	varvalue string) string {
	classname := LangTypeClassFull(lang, vartype)
	sindent := "\n" + StringRepeat("  ", indent)
	svalue := LangVarValue(lang, vartype, varvalue)
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
			prefix = "let"
		}
		nullable := ""
		if isnullable {
			nullable = "?"
		}
		output += "" +
			prefix + " " + varname + " : " + classname + nullable
		if svalue != "" {
			output += " = " + svalue
		}
	default:
		output += "" +
			classname + " " + varname + " = " + svalue + lang.lineend
	}
	return output
}

func LangVarSetNotNull(
	lang *vxlang,
	indent int,
	typ *vxtype,
	varname string,
	value string) string {
	output := ""
	switch lang {
	case langswift:
		output = "" +
			LangIfThen(lang, indent,
				"let testnull = "+value,
				LangVarSet(lang, indent+1,
					"output", "testnull")) +
			LangIfEnd(lang, indent)
	default:
		output = "" +
			LangVarNull(lang, 3, typ,
				"testnull",
				value) +
			LangIfThen(lang, 3,
				LangClause(lang, false,
					"!=",
					"testnull",
					"null"),
				LangVarSet(lang, 4,
					"output", "testnull")) +
			LangIfEnd(lang, 3)
	}
	return output
}

func LangVarValue(
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
	case ":empty":
		output = LangTypeE(lang, vartype)
	}
	return output
}

func LangStringContains(
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

func LangVxEqualsString(
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

func LangVarFloatPlus(
	lang *vxlang,
	indent int,
	typ *vxtype,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch typ {
	case rawstringtype:
		value = LangFloatFromString(lang, value)
	}
	switch lang {
	case langswift:
		switch typ {
		case rawinttype:
			output = sindent + varname + " += Vx_Core.vx_float_from_int(" + value + ")"
		default:
			output = sindent + varname + " += " + value
		}
	default:
		output = sindent + varname + " += " + value + lang.lineend
	}
	return output
}

func LangVarIntPlus(
	lang *vxlang,
	indent int,
	typ *vxtype,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch typ {
	case rawstringtype:
		value = LangIntFromString(lang, value)
	}
	switch lang {
	default:
		output = sindent + varname + " += " + value + lang.lineend
	}
	return output
}

func LangVarListAdd(
	lang *vxlang,
	indent int,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	case langcpp:
		output = sindent + varname + ".push_back(" + value + ")" + lang.lineend
	case langcsharp:
		output = sindent + varname + ".Add(" + value + ")" + lang.lineend
	case langswift:
		output = sindent + varname + ".append(" + value + ")" + lang.lineend
	default:
		output = sindent + varname + ".add(" + value + ")" + lang.lineend
	}
	return output
}

func LangVarListAddList(
	lang *vxlang,
	indent int,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	case langcsharp:
		output = sindent + varname + ".AddRange(" + value + ")" + lang.lineend
	case langswift:
		output = sindent + varname + ".append(contentsOf: " + value + ")" + lang.lineend
	default:
		output = sindent + varname + ".addAll(" + value + ")" + lang.lineend
	}
	return output
}

func LangVarListContains(
	lang *vxlang,
	varname string,
	contains string) string {
	output := ""
	switch lang {
	case langcpp:
		output = "vx_core::vx_boolean_from_list_find(" + varname + ", " + contains + ")"
	case langcsharp:
		output = varname + ".Contains(" + contains + ")"
	case langswift:
		output = varname + ".contains(where: {item in Vx_Core.vx_issame(item, subitem)})"
	default:
		output = varname + ".contains(" + contains + ")"
	}
	return output
}

func LangVarListGet(
	lang *vxlang,
	varname string,
	value string) string {
	output := ""
	switch lang {
	case langcsharp, langswift:
		output = varname + "[" + value + "]"
	default:
		output = varname + ".get(" + value + ")"
	}
	return output
}

func LangVarListNew(
	lang *vxlang,
	typ *vxtype,
	value string) string {
	output := ""
	switch lang {
	case langjava:
		output = "new ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case langkotlin:
		output = "ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case langswift:
		output = "Array(" + value + ")"
	default:
		output = "new List<" + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVarListSize(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + ".Count"
	case langkotlin:
		output = varname + ".size"
	case langswift:
		output = varname + ".count"
	default:
		output = varname + ".size()"
	}
	return output
}

func LangVarMapNew(
	lang *vxlang,
	typ *vxtype,
	value string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "new Vx.Core.LinkedHashMap<string, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case langkotlin:
		output = "LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case langswift:
		output = "Vx_Core.MapMutable<" + LangTypeName(lang, typ) + ">(" + value + ")"
	default:
		output = "new LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVarMapRemove(
	lang *vxlang,
	indent int,
	varname string,
	key string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	default:
		output = sindent + varname + ".remove(" + key + ")" + lang.lineend
	}
	return output
}

func LangVarMapSet(
	lang *vxlang,
	indent int,
	varname string,
	key string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	default:
		output = sindent + varname + ".put(" + key + ", " + value + ")" + lang.lineend
	}
	return output
}

func LangVarSet(
	lang *vxlang,
	indent int,
	varname string,
	varvalue string) string {
	output := LangIndent(lang, indent, true)
	output += varname
	if varvalue != "" {
		output += " = " + varvalue
	}
	output += lang.lineend
	return output
}

func LangVarStringPlus(
	lang *vxlang,
	indent int,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	default:
		output = sindent + varname + " += " + value + lang.lineend
	}
	return output
}

func LangVarStringStarts(
	lang *vxlang,
	varname string,
	starts string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = varname + ".StartsWith(" + starts + ")"
	case langjava, langkotlin:
		output = varname + ".startsWith(" + starts + ")"
	case langswift:
		output = varname + ".hasPrefix(" + starts + ")"
	}
	return output
}

func LangVarStringBuilderPlus(
	lang *vxlang,
	indent int,
	typ *vxtype,
	varname string,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch typ {
	case rawfloattype:
		value = LangStringFromFloat(lang, value)
	case rawintegertype:
		value = LangStringFromInt(lang, value)
	}
	switch lang {
	case langcsharp:
		output = sindent + varname + ".Append(" + value + ")" + lang.lineend
	case langswift:
		output = sindent + varname + " += " + value
	default:
		output = sindent + varname + ".append(" + value + ")" + lang.lineend
	}
	return output
}

func LangVarSubstring(
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
	case langswift:
		if to == "" {
			output = "String(" + varname + ".dropFirst())"
		} else {
			output = varname + "[" + from + "..<" + to + "]"
		}
	}
	return output
}

func LangVarToString(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Vx.Core.vx_string_from_object(" + varname + ")"
	case langjava, langkotlin:
		output = varname + ".toString()"
	case langswift:
		output = "Vx_Core.vx_string_from_object(" + varname + ")"
	}
	return output
}

func LangVarVarArg(
	lang *vxlang,
	typ *vxtype,
	varname string) string {
	output := ""
	switch lang {
	case langswift:
		if typ == rawlisttype || typ.extends == ":list" {
			output = "[" + varname + "]..."
		} else {
			output = varname
		}
	default:
		output = varname
	}
	return output
}

func LangWriteFromProjectCmdNative(
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
