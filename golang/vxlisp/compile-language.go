package vxlisp

import (
	"strings"
)

type vxlang struct {
	name       string
	sourcename string
	sourcefile string
	headerfile string
	pkgpath    string
	pkgname    string
	pkgref     string
	future     string
	indent     string
	lambdafunc string
	lineend    string
	itfext     string
	classext   string
	typeref    string
}

var g_ifuncdepth = 0

var langcpp = NewLangCpp()
var langcsharp = NewLangCsharp()
var langjava = NewLangJava()
var langjs = NewLangJs()
var langkotlin = NewLangKotlin()
var langswift = NewLangSwift()

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
	output.lambdafunc = "->"
	output.lineend = ";"
	output.typeref = "->"
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
	output.lambdafunc = "=>"
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
	output.lambdafunc = "->"
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

func LangAsType(lang *vxlang, svar string, typ *vxtype) string {
	typetext := ""
	// SomeClass obj2 = (SomeClass)Convert.ChangeType(t, typeof(SomeClass));
	switch typ {
	case rawlistunknowntype:
		switch lang.name {
		case "csharp":
			typetext = "List<object>"
		case "java":
			typetext = "List<?>"
		default:
			typetext = LangNameTypeFullFromType(lang, typ)
		}
	default:
		typetext = LangNameTypeFullFromType(lang, typ)
	}
	return LangAsTypeText(lang, svar, typetext)
}

func LangAsTypeText(lang *vxlang, svar string, stype string) string {
	output := ""
	switch lang.name {
	case "csharp":
		switch stype {
		case "bool":
			output = "(bool)" + svar
		case "float":
			output = "(float)" + svar
		case "int":
			output = "Convert.ToInt32(" + svar + ")"
		default:
			output = svar + " as " + stype
		}
	case "java":
		output = "(" + stype + ")" + svar
	}
	return output
}

func LangClassHeaderFromConst(lang *vxlang, cnst *vxconst, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	constname := "Const_" + LangFromName(cnst.alias)
	extends := LangNameClassFullFromType(lang, cnst.vxtype)
	switch lang.name {
	case "csharp", "kotlin":
		output = lineindent + "public class " + constname + " : " + extends + ", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_Type_const {"
	case "java":
		output = lineindent + "public static class " + constname + " extends " + extends + " implements " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_Type_const {"
	}
	return output
}

func LangClassHeaderFromFunc(lang *vxlang, fnc *vxfunc, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	funcname := LangNameFromFunc(fnc)
	extends := LangNameFromPkgNameDot(lang, "vx/core") + "Class_base"
	switch lang.name {
	case "csharp", "kotlin":
		output = lineindent + "public class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {"
	case "java":
		output = lineindent + "public static class Class_" + funcname + " extends " + extends + " implements Func_" + funcname + " {"
	}
	return output
}

func LangClassHeaderFromType(lang *vxlang, typ *vxtype, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	typename := LangFromName(typ.alias)
	switch lang.name {
	case "csharp":
		output = lineindent + "public class Class_" + typename + " : " + LangNameFromPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	case "java":
		output = lineindent + "public static class Class_" + typename + " extends " + LangNameFromPkgNameDot(lang, "vx/core") + "Class_base implements Type_" + LangNameFromType(lang, typ) + " {"
	case "kotlin":
		output = lineindent + "class Class_" + typename + " : " + LangNameFromPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	}
	return output
}

func LangConstDefsFromListConst(lang *vxlang, values []*vxconst, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	var outputvalues []string
	if len(values) > 0 {
		for _, val := range values {
			name := "" +
				lineindent + LangNameFromPkgNameDot(lang, "vx/core") + "constdef_new(" +
				lineindent + "  \"" + val.pkgname + "\"," +
				lineindent + "  \"" + val.name + "\"," +
				lineindent + "  null" +
				lineindent + ")"
			outputvalues = append(outputvalues, name)
		}
		output = LangNameFromPkgNameDot(lang, "vx/core") + "arraylist_from_array(" + strings.Join(outputvalues, ",") + lineindent + ")"
	}
	return output
}

func LangDebugFromFunc(lang *vxlang, fnc *vxfunc, lineindent string) (string, string) {
	debugstart := ""
	debugend := ""
	if fnc.debug {
		debugstart = lineindent + LangNameFromPkgNameDot(lang, "vx/core") + "vx_log(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			debugstart += ", " + LangTypeStringValNew(lang, arg.name+"=") + ", " + LangFromName(arg.alias)
		}
		debugstart += ")" + lang.lineend
		debugend = lineindent + LangNameFromPkgNameDot(lang, "vx/core") + "vx_log(\"" + fnc.name + "\", \"end\", output)" + lang.lineend
	}
	return debugstart, debugend
}

func LangDocFromFunc(fnc *vxfunc) string {
	var doc = ""
	var argsdoc = ""
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
	return output
}

func LangEmptyValueFromType(lang *vxlang, typ *vxtype) string {
	return LangEmptyValueFromTypeIndent(lang, typ, "")
}

func LangEmptyValueFromTypeIndent(lang *vxlang, typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = LangNameFromPkgNameDot(lang, "vx/core") + "f_type_to_list(" + LangNameFromPkgName(lang, typ.pkgname) + ".t_" + typ.name + ")"
		default:
			if len(typ.properties) > 0 {
				output = "{\n"
				for _, property := range typ.properties {
					propdefault := LangEmptyValueFromTypeIndent(lang, property.vxtype, indent+"  ")
					output += indent + "    " + LangFromName(property.name) + ": " + propdefault + ","
					if property.doc != "" {
						output += " // " + property.doc
					}
					output += "\n"
				}
				output += "" +
					indent + "    vxtype: " + LangNameFromPkgName(lang, typ.pkgname) + ".t_" + LangFromName(typ.name) +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
			}
		}
	}
	return output
}

func LangFilesFromProjectCmd(lang *vxlang, project *vxproject, command *vxcommand) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFilesFromProjectCmd")
	var files []*vxfile
	cmdpath := PathFromProjectCmd(project, command)
	pkgprefix := ""
	apppath := cmdpath
	testpath := cmdpath
	switch lang.name {
	case "csharp":
		apppath += "/App"
		testpath += "/AppTest"
		switch command.code {
		case ":test":
			pkgprefix = "AppTest.Test"
		}
	case "java", "kotlin":
		pkgprefix = project.javadomain + "."
	}
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "App" + lang.sourcefile
		file.path = apppath
		file.text = LangApp(lang, project, command)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "AppTest" + lang.sourcefile
		file.path = testpath
		file.text = LangAppTest(lang, project, command, pkgprefix)
		files = append(files, file)
		file = NewFile()
		file.name = "TestLib" + lang.sourcefile
		file.path = testpath
		file.text = LangTestLib(lang)
		files = append(files, file)
	}
	pkgs := ListPackageFromProject(project)
	for _, pkg := range pkgs {
		subproject := pkg.project
		subprefix := ""
		subdomainpath := ""
		switch lang.name {
		case "csharp":
			switch command.code {
			case ":test":
				subprefix = "AppTest.Test"
				subdomainpath = "Test"
			}
		case "java", "kotlin":
			subprefix = subproject.javadomain + "/"
			subdomainpath = StringFromStringFindReplace(subprefix, ".", "/")
		}
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
		switch lang.name {
		case "csharp":
			pkgpath = StringUCaseFirstFromStringDelim(pkgpath, "/")
		}
		switch command.code {
		case ":source":
			text, msgs := LangFromPackage(lang, pkg, project, subprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + lang.sourcefile
			file.path = cmdpath + "/" + subdomainpath + pkgpath
			file.text = text
			files = append(files, file)
		case ":test":
			text, msgs := LangTestFromPackage(lang, pkg, project, command, subprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "Test" + lang.sourcefile
			file.path = testpath + "/" + subdomainpath + pkgpath
			file.text = text
			files = append(files, file)
		}
	}
	return files, msgblock
}

func LangFinalArg(lang *vxlang) string {
	var output = ""
	switch lang.name {
	case "java":
		output = "final "
	}
	return output
}

func LangFinalClass(lang *vxlang) string {
	var output = ""
	switch lang.name {
	case "java":
		output = "final "
	}
	return output
}

func LangFinalVar(lang *vxlang) string {
	var output = ""
	switch lang.name {
	case "java":
		output = "final "
	}
	return output
}

func LangFolderCopyTestdataFromProjectPath(project *vxproject, targetpath string) *vxmsgblock {
	msgblock := NewMsgBlock("LangFileCopyTestdataFromProjectPath")
	sourcepath := PathFromProjectPath(project, "./testdata")
	if BooleanExistsFromPath(sourcepath) {
		msgs := FolderCopyFromSourceTarget(sourcepath, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, subproject := range project.listproject {
		msgs := LangFolderCopyTestdataFromProjectPath(subproject, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func LangForListHeader(lang *vxlang, forvar string, typ *vxtype, listvar string, indent int) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang.name {
	case "csharp":
		output = sindent + "foreach (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " in " + listvar + ") {"
	case "java":
		output = sindent + "for (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " : " + listvar + ") {"
	}
	return output
}

func LangFromConst(lang *vxlang, cnst *vxconst, pkg *vxpackage) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromConst")
	output := ""
	g_ifuncdepth = 0
	path := cnst.pkgname + "/" + cnst.name
	doc := ""
	doc += "Constant: " + cnst.name + "\n"
	if cnst.doc != "" {
		doc += cnst.doc + "\n"
	}
	if cnst.deprecated != "" {
		doc += cnst.deprecated + "\n"
	}
	cnsttype := cnst.vxtype
	doc += "{" + cnsttype.name + "}"
	cnstname := LangFromName(cnst.alias)
	cnstclassname := "Const_" + cnstname
	cnsttypeclassname := LangNameTypeFullFromType(lang, cnsttype)
	initval := ""
	const_new := ""
	cnstval := StringValueFromValue(cnst.value)
	switch NameFromType(cnsttype) {
	case "vx/core/boolean":
		constvxboolean := NewFunc()
		constvxboolean.name = "vx_boolean"
		constvxboolean.vxtype = rawbooltype
		constvxboolean.isimplement = true
		constvxboolean.isimplement2 = true
		if cnstval == "" {
			switch NameFromConst(cnst) {
			case "vx/core/true":
				cnstval = "true"
			default:
				cnstval = "false"
			}
		}
		cnstval = "\n      this.vxboolean = " + cnstval + ";"
		initval = "" +
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxboolean, false, false) +
			cnstval +
			"\n      return this.vxboolean;" +
			"\n    }"
	case "vx/core/decimal":
		constvxdecimal := NewFunc()
		constvxdecimal.name = "vx_decimal"
		constvxdecimal.vxtype = rawstringtype
		constvxdecimal.isimplement = true
		constvxdecimal.isimplement2 = true
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxdecimal = " + cnstval + ";"
		initval = "" +
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxdecimal, false, false) +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/float":
		constvxfloat := NewFunc()
		constvxfloat.name = "vx_float"
		constvxfloat.vxtype = rawfloattype
		constvxfloat.isimplement = true
		constvxfloat.isimplement2 = true
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      this.vxfloat = " + cnstval + ";"
		initval = "" +
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxfloat, false, false) +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/int":
		constvxint := NewFunc()
		constvxint.name = "vx_int"
		constvxint.vxtype = rawinttype
		constvxint.isimplement = true
		constvxint.isimplement2 = true
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxint = " + cnstval + ";"
		initval = "" +
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxint, false, false) +
			cnstval +
			"\n      return this.vxint;" +
			"\n    }"
	case "vx/core/string":
		constvxstring := NewFunc()
		constvxstring.name = "vx_string"
		constvxstring.vxtype = rawstringtype
		constvxstring.isimplement = true
		constvxstring.isimplement2 = true
		if BooleanFromStringStartsEnds(cnstval, "\"", "\"") {
			cnstval = cnstval[1 : len(cnstval)-1]
			cnstval = LangFromText(cnstval)
			cnstval = "\"" + cnstval + "\""
		}
		cnstval = "\n      this.vxstring = " + cnstval + ";"
		initval = "" +
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxstring, false, false) +
			cnstval +
			"\n      return this.vxstring;" +
			"\n    }"
	default:
		switch cnsttype.extends {
		case ":list":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				listtypename := LangNameFromType(lang, allowtype)
				if listtypename == "any" {
					listtypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + lang.lineend +
					"\n      output.vx_p_list = val.vx_list" + listtypename + "()" + lang.lineend
			}
		case ":map":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				maptypename := LangNameFromType(lang, allowtype)
				if maptypename == "any" {
					maptypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vx_p_map = val.vx_map" + maptypename + "();"
			}
		case ":struct":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      output.vx_p_" + LangFromName(prop.name) + " = val." + LangFromName(prop.name) + "();"
				}
			}
		}
	}
	e_type := ""
	switch NameFromConst(cnst) {
	case "vx/core/false":
		final := LangFinalVar(lang)
		e_type = "\n  public static " + final + "Type_boolean e_boolean = c_false;"
	}
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		LangClassHeaderFromConst(lang, cnst, 1) +
		LangVxConstdef(lang, cnst) +
		"\n    public static void const_new(" + cnstclassname + " output) {" +
		const_new +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static " + LangFinalVar(lang) + cnstclassname + " c_" + cnstname + " = new " + cnstclassname + "();" +
		"\n" +
		e_type +
		"\n"
	constlate := "" +
		"\n    " + cnstclassname + ".const_new(c_" + cnstname + ");"
	return output, constlate, msgblock
}

func LangFromFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromFunc")
	g_ifuncdepth = 0
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	f_func, msgs := LangVxFFromFunc(lang, fnc, true)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	vx_func, msgs := LangVxFFromFunc(lang, fnc, false)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	override1, override2 := LangOverride(lang, 2, false)
	output := "" +
		LangDocFromFunc(fnc) +
		LangInterfaceFromFunc(lang, fnc) +
		LangClassHeaderFromFunc(lang, fnc, 1) +
		"\n" +
		LangVxNewFromFunc(lang, fnc, false) +
		LangVxCopyFromFunc(lang, fnc, false) +
		LangVxTypedefFromFunc(lang, fnc) +
		LangVxFuncdefFromFunc(lang, fnc) +
		override1 +
		"\n    public " + override2 + LangNameTypeFullFromType(lang, anytype) + " vx_empty() {" +
		"\n      return e_" + funcname + ";" +
		"\n    }" +
		"\n" +
		override1 +
		"\n    public " + override2 + LangNameTypeFullFromType(lang, anytype) + " vx_type() {" +
		"\n      return t_" + funcname + ";" +
		"\n    }" +
		"\n" +
		LangInterfaceFnFromFunc(lang, fnc) +
		LangVxFnNewFromFunc(lang, fnc, false) +
		LangReplFromFunc(lang, fnc) +
		vx_func +
		"\n  public static " + LangFinalVar(lang) + "Func_" + funcname + " e_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n  public static " + LangFinalVar(lang) + "Func_" + funcname + " t_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n" +
		f_func
	return output, msgblock
}

func LangFromName(name string) string {
	output := name
	if output == "extends" {
		output = "extend"
	}
	output = StringFromStringFindReplace(output, "->", "_to_")
	output = StringFromStringFindReplace(output, "<-", "_from_")
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func LangFromPackage(lang *vxlang, pkg *vxpackage, project *vxproject, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromPackage")
	pkgpath, pkgname := LangPackagePathFromPrefixName(lang, pkgprefix, pkg.name)
	specialcode := project.mapnative[pkg.name+"_"+lang.name+".txt"]
	typkeys := ListKeyFromMapType(pkg.maptype)
	typetexts := ""
	packageline := ""
	switch lang.name {
	case "csharp":
		ipos := IntFromStringFindLast(pkg.name, "/")
		csnamespace := StringSubstring(pkg.name, 0, ipos)
		csnamespace = StringFromStringFindReplace(csnamespace, "/", ".")
		csnamespace = StringUCaseFirstFromStringDelim(csnamespace, ".")
		packageline = "namespace " + csnamespace + lang.lineend + "\n"
	case "java":
		packageline = "package " + pkgpath + lang.lineend + "\n"
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	packagestatic := "" +
		LangVar(lang, "maptype", rawmaptype, anytype, LangVxNewMap(lang, anytype, ""), 2, false, false) +
		LangVar(lang, "mapconst", rawmaptype, anytype, LangVxNewMap(lang, anytype, ""), 2, false, false) +
		LangVar(lang, "mapfunc", rawmaptype, functype, LangVxNewMap(lang, functype, ""), 2, false, false)
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, msgs := LangFromType(typ, lang)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
		packagestatic += "" +
			"\n    maptype.put(\"" + typ.name + "\", " + LangNameTFromType(lang, typ) + ");"
	}
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	consttexts := ""
	statics := ""
	switch lang.name {
	case "csharp":
		statics = "" +
			"\n  public static class PackageRunOnce {" +
			"\n    public static void RunOnce() {"
	case "java":
		statics = "\n  static {"
	}
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constlate, msgs := LangFromConst(lang, cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		statics += constlate
		packagestatic += "" +
			"\n    mapconst.put(\"" + cnst.name + "\", " + LangNameCFromConst(lang, cnst) + ");"
	}
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	functexts := ""
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, msgs := LangFromFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
			packagestatic += "" +
				"\n    mapfunc.put(\"" + fnc.name + LangIndexFromFunc(fnc) + "\", " + LangNameTFromFunc(lang, fnc) + ");"
		}
	}
	packagestatic += "" +
		"\n    " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_global_package_set(\"" + pkg.name + "\", maptype, mapconst, mapfunc);"
	statics += packagestatic
	switch lang.name {
	case "csharp":
		statics += "" +
			"\n    }" +
			"\n  }" +
			"\n"
	case "java":
		statics += "" +
			"\n  }" +
			"\n"
	}
	body := "" +
		specialcode +
		typetexts +
		consttexts +
		functexts +
		statics
		//		emptytypes
	imports := LangImportsFromPackage(lang, pkg, pkgprefix, body, false)
	output := "" +
		packageline +
		imports +
		namespaceopen +
		body +
		namespaceclose
	return output, msgblock
}

func LangFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func LangFromType(typ *vxtype, lang *vxlang) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromType")
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
	override1, override2 := LangOverride(lang, 2, false)
	typename := LangFromName(typ.alias)
	typepath := NameFromType(typ)
	instancefuncs := ""
	createtext, msgs := LangFromValue(lang, typ.createvalue, "", emptyfunc, 2, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	valnew := ""
	valcopy := "" +
		"\n      " + LangNameTypeFromType(lang, rawbooltype) + " ischanged = false;" +
		"\n      Class_" + typename + " val = this;" +
		"\n      " + LangNameTypeFromType(lang, msgblocktype) + " msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msgblock_from_copy_arrayval(val, vals);" +
		"\n      if (" + LangIsTypeText(lang, "this", LangNameFromPkgNameDot(lang, "vx/core")+"vx_Type_const") + ") {" +
		"\n        ischanged = true;" +
		"\n      }"
	switch NameFromType(typ) {
	case "vx/core/any":
		valnew += "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_any work = new Class_any();" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/anytype":
	case "vx/core/const":
	case "vx/core/list":
	case "vx/core/map":
	case "vx/core/struct":
	case "vx/core/func":
		instancefuncs += "" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_funcdef vx_funcdef() {" +
			"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "e_funcdef;" +
			"\n    }"
	case "vx/core/type":
	case "vx/core/boolean":
		valcopy += "" +
			"\n      " + LangNameTypeFromType(lang, rawbooltype) + " booleanval = val.vx_boolean();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			LangElseIfType(lang, booleantype, emptytype, "valsub", "valboolean", 4, false) +
			"\n          booleanval = booleanval || valboolean.vx_boolean();" +
			LangElseIfType(lang, rawbooleantype, emptytype, "valsub", "issubval", 4, false) +
			"\n          booleanval = booleanval || issubval" + lang.lineend +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_boolean work = new Class_boolean();" +
			"\n        work.vxboolean = booleanval;" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      } else if (booleanval) {" +
			"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "c_true;" +
			"\n      } else {" +
			"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "c_false;" +
			"\n      }"
	case "vx/core/decimal":
		valcopy += "" +
			"\n      " + LangNameTypeFromType(lang, rawstringtype) + " sval = val.vx_string();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 4, false) +
			"\n          ischanged = true;" +
			"\n          sval = valstring.vx_string();" +
			LangElseIfType(lang, rawstringtype, emptytype, "valsub", "svalsub", 4, false) +
			"\n          ischanged = true" + lang.lineend +
			"\n          sval = svalsub" + lang.lineend +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_decimal work = new Class_decimal();" +
			"\n        work.vxdecimal = sval;" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/float":
		valcopy += "" +
			"\n      float floatval = val.vx_float();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub)" + lang.lineend +
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
			"\n          ischanged = true;" +
			"\n          floatval += " + LangVxFloatFromString(lang, "sval") + lang.lineend +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_float work = new Class_float();" +
			"\n        work.vxfloat = floatval;" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/int":
		valcopy += "" +
			"\n      int intval = val.vx_int();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			LangElseIfType(lang, inttype, emptytype, "valsub", "valint", 4, false) +
			"\n          ischanged = true" + lang.lineend +
			"\n          intval += valint.vx_int()" + lang.lineend +
			LangElseIfType(lang, rawintegertype, emptytype, "valsub", "ival", 4, false) +
			"\n          ischanged = true" + lang.lineend +
			"\n          intval += ival" + lang.lineend +
			LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 4, false) +
			"\n          ischanged = true;" +
			"\n          intval += " + LangVxIntFromString(lang, "sval") + lang.lineend +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_int work = new Class_int();" +
			"\n        work.vxint = intval;" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		vxappend := ""
		switch lang.name {
		case "csharp":
			vxappend = ".Append"
			valcopy += "" +
				"\n      System.Text.StringBuilder sb = new System.Text.StringBuilder(val.vx_string());"
		case "java":
			vxappend = ".append"
			valcopy += "" +
				"\n      StringBuilder sb = new StringBuilder(val.vx_string());"
		}
		valnew = "" +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 4, false) +
			LangVar(lang, "ssub", rawstringtype, emptytype, "valstring.vx_string()", 5, false, false) +
			"\n          if (" + LangVxEquals(lang, "ssub", "\"\"") + ") {" +
			"\n          } else {" +
			"\n            ischanged = true" + lang.lineend +
			"\n            sb" + vxappend + "(ssub)" + lang.lineend +
			"\n          }" +
			LangElseIfType(lang, inttype, emptytype, "valsub", "valint", 4, false) +
			"\n          ischanged = true;" +
			"\n          sb" + vxappend + "(valint.vx_int());" +
			LangElseIfType(lang, floattype, emptytype, "valsub", "valfloat", 4, false) +
			"\n          ischanged = true;" +
			"\n          sb" + vxappend + "(valfloat.vx_float());" +
			LangElseIfType(lang, decimaltype, emptytype, "valsub", "valdecimal", 4, false) +
			"\n          ischanged = true;" +
			"\n          sb" + vxappend + "(valdecimal.vx_string());" +
			LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 4, false) +
			"\n          if (" + LangVxEquals(lang, "sval", "\"\"") + ") {" +
			"\n          } else {" +
			"\n            ischanged = true;" +
			"\n            sb" + vxappend + "(sval);" +
			"\n          }" +
			LangElseIfType(lang, rawintegertype, emptytype, "valsub", "ival", 4, false) +
			"\n          ischanged = true;" +
			"\n          sb" + vxappend + "(ival);" +
			LangElseIfType(lang, rawfloattype, emptytype, "valsub", "fval", 4, false) +
			"\n          ischanged = true;" +
			"\n          sb" + vxappend + "(fval);" +
			LangElseIfType(lang, anytype, emptytype, "valsub", "anysub", 4, false) +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anysub);" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        } else {" +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + "))" + lang.lineend +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			LangVar(lang, "vxstring", rawstringtype, emptytype, LangVxToString(lang, "sb"), 4, false, false) +
			"\n        Class_string work = new Class_string();" +
			"\n        work.vxstring = vxstring;" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	}
	switch typ.extends {
	case ":list":
		allowtype := anytype
		allowname := "any"
		allowclass := LangNameTypeFromType(lang, anytype)
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype = allowtypes[0]
			allowclass = LangNameTypeFullFromType(lang, allowtype)
			allowname = LangNameFromType(lang, allowtype)
		}
		if allowname == "any" {
			allowname = ""
		}
		castlist := ""
		switch lang.name {
		case "csharp":
			castlist = "this.vx_p_list"
		case "java":
			castlist = "this.vx_p_list"
		}
		vxlistbody := "" +
			"\n      " + LangNameTypeFromType(lang, rawlistanytype) + " output = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(" +
			"\n        " + LangVxNewList(lang, anytype, castlist) +
			"\n      )" + lang.lineend +
			"\n      return output" + lang.lineend
		instancefuncs += "" +
			"\n    public List<" + allowclass + "> vx_p_list = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(" + LangVxNewList(lang, allowtype, "") + ")" + lang.lineend +
			"\n" +
			LangVxListFromType(lang, typ, vxlistbody) +
			LangVxAllowCodeFromList(lang, typ)
		valcopy += "" +
			"\n      List<" + allowclass + "> listval = " + LangVxNewList(lang, allowtype, "val.vx_list"+allowname+"()") + lang.lineend
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
				"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);"
		case "msglist":
			valnew = "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
				"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);"
		default:
			valnew = "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
				LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
				"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
				"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
				"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
				"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
				LangElseIfType(lang, allowtype, emptytype, "valsub", "allowsub", 4, false) +
				"\n          ischanged = true;" +
				"\n          " + LangVxListAdd(lang, "listval", "allowsub") + lang.lineend
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := LangNameTypeFromType(lang, allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					switch lang.name {
					case "java":
						allowedtypename = "Boolean"
					}
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, valsub)"
				case "vx/core/int":
					switch lang.name {
					case "java":
						allowedtypename = "Integer"
					}
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub)"
				case "vx/core/float":
					switch lang.name {
					case "java":
						allowedtypename = "Float"
					}
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_float, valsub)"
				case "vx/core/string":
					switch lang.name {
					case "java":
						allowedtypename = "String"
					}
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, valsub)"
				}
			}
			if allowedtypename == "" {
			} else if allowedtype.name == "any" {
			} else {
				valnew += "" +
					"\n        } else if (" + LangIsTypeText(lang, "valsub", allowedtypename) + ") {" +
					"\n          ischanged = true;" +
					"\n          " + LangVxListAdd(lang, "listval", castval) + lang.lineend
			}
		}
		valnew += "" +
			LangElseIfType(lang, typ, emptytype, "valsub", "multi", 4, false) +
			"\n          ischanged = true;" +
			"\n          " + LangVxListAddList(lang, "listval", "multi.vx_list"+allowname+"()") + lang.lineend +
			LangElseIfType(lang, rawlistunknowntype, emptytype, "valsub", "listunknown", 4, false) +
			LangForListHeader(lang, "item", rawobjecttype, "listunknown", 5) +
			"\n            if (false) {" +
			LangElseIfType(lang, allowtype, emptytype, "item", "valitem", 6, false) +
			"\n              ischanged = true;" +
			"\n              " + LangVxListAdd(lang, "listval", "valitem") + lang.lineend +
			"\n            }" +
			"\n          }" +
			LangElseIfType(lang, anytype, emptytype, "valsub", "anyinvalid", 4, false) +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anyinvalid);" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        } else {" +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + "))" + lang.lineend +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_list = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(listval);" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":map":
		allowtype := anytype
		allowname := "any"
		allowclass := LangNameFromPkgNameDot(lang, "vx/core") + "Type_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype = allowtypes[0]
			allowclass = LangNameTypeFullFromType(lang, allowtype)
			allowname = LangNameFromType(lang, allowtype)
		}
		if allowname == "any" {
			allowname = ""
		}
		instancefuncs += "" +
			"\n    public " + LangNameTypeFromTypeSubtype(lang, rawmaptype, allowtype) + " vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(" + LangVxNewMap(lang, allowtype, "") + ");" +
			"\n" +
			LangVxMapFromType(lang, allowtype) +
			LangVxSetFromType(lang, typ) +
			LangVxAllowCodeFromMap(lang, typ) +
			LangVxNewFromMap(lang, typ)
		valcopy += "" +
			LangVar(lang, "mapval", rawmaptype, allowtype, LangVxNewMap(lang, allowtype, "val.vx_map"+allowname+"()"), 3, false, false)
		valnew = "" +
			LangVar(lang, "msg", msgtype, emptytype, "null", 3, false, false) +
			LangVar(lang, "key", rawstringtype, emptytype, "\"\"", 3, false, false) +
			LangVar(lang, "msgval", anytype, emptytype, "null", 3, false, false) +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangVxEquals(lang, "key", "\"\"") + ") {" +
			"\n          if (false) {" +
			LangElseIfType(lang, stringtype, emptytype, "valsub", "valstring", 5, false) +
			"\n            key = valstring.vx_string();" +
			LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false) +
			LangVarSet(lang, "key", "sval", 6) +
			"\n          } else {" +
			"\n            if (false) {" +
			LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 6, false) +
			LangVarSet(lang, "msgval", "valinvalid", 7) +
			"\n            } else {" +
			"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + ")" + lang.lineend +
			"\n            }" +
			"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":keyexpected\", msgval);" +
			"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			LangVar(lang, "valany", allowtype, emptytype, "null", 5, false, false) +
			"\n          if (false) {" +
			LangElseIfType(lang, allowtype, emptytype, "valsub", "valallowed", 5, false) +
			//"\n          if (" + LangIsType(lang, "valsub", allowtype) + ") {" +
			"\n            valany = valallowed" + lang.lineend
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := LangNameTypeFromType(lang, allowedtype)
			castval := LangAsType(lang, "valsub", allowedtype)
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtype = rawbooltype
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, valsub)"
				case "vx/core/int":
					allowedtype = rawintegertype
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub)"
				case "vx/core/float":
					allowedtype = rawfloattype
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_float, valsub)"
				case "vx/core/string":
					allowedtype = rawstringtype
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, valsub)"
				}
			}
			if allowedtypename != "" {
				valnew += "" +
					//	LangElseIfType(lang, allowtype, emptytype, "valsub", "valany", 5, false)
					"\n          } else if (" + LangIsType(lang, "valsub", allowedtype) + ") {" +
					LangVarSet(lang, "valany", castval, 6)
			}
		}
		valnew += "" +
			"\n          } else {" +
			"\n            if (false) {" +
			LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 6, false) +
			LangVarSet(lang, "msgval", "valinvalid", 7) +
			"\n            } else {" +
			"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + ")" + lang.lineend +
			"\n            }" +
			LangVar(lang, "mapany", rawmaptype, anytype, LangVxNewMap(lang, anytype, ""), 6, false, false) +
			"\n            mapany.put(\"key\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(key));" +
			"\n            mapany.put(\"value\", msgval);" +
			"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map msgmap = " + LangNameFromPkgNameDot(lang, "vx/core") + "t_anymap.vx_new_from_map(mapany);" +
			"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkeyvalue\", msgmap);" +
			"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != null) {" +
			"\n            ischanged = true;" +
			"\n            if (" + LangVxStartswith(lang, "key", "\":\"") + ") {" +
			"\n              key = " + LangVxSubstring(lang, "key", "1", "") + lang.lineend +
			"\n            }" +
			"\n            mapval.put(key, valany);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(mapval);" +
			"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
			//		if extendinterface == "" {
			//			extendinterface = LangNameFromPkgNameDot(lang, "vx/core") + "Type_map"
			//		}
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":struct":
		vx_any := ""
		valcopyend := ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			valcopy = "" +
				"\n      " + LangNameTypeFromType(lang, rawbooltype) + " ischanged = false;" +
				"\n      Class_" + typename + " val = this;" +
				"\n      if (" + LangIsTypeText(lang, "this", LangNameFromPkgNameDot(lang, "vx/core")+"vx_Type_const") + ") {" +
				"\n        ischanged = true;" +
				"\n      }"
		case "vx/core/msgblock":
			valcopy = "" +
				"\n      " + LangNameTypeFromType(lang, rawbooltype) + " ischanged = false;" +
				"\n      Class_" + typename + " val = this;" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msgblock msgblock = this;" +
				"\n      if (" + LangIsTypeText(lang, "this", LangNameFromPkgNameDot(lang, "vx/core")+"vx_Type_const") + ") {" +
				"\n        ischanged = true;" +
				"\n      }"
		}
		//if extendinterface == "" {
		//	extendinterface = LangNameFromPkgNameDot(lang, "vx/core") + "Type_struct"
		//}
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
			valnew = "" +
				"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
		default:
			validkeys := "\n      List<" + LangNameTypeFromType(lang, rawstringtype) + "> validkeys = " + LangVxNewList(lang, rawstringtype, "") + lang.lineend
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      " + LangVxListAdd(lang, "validkeys", "\":"+arg.name+"\"") + lang.lineend
				argname := LangFromName(arg.name)
				valcopy += "\n      " + LangNameTypeFromType(lang, arg.vxtype) + " vx_p_" + argname + " = val." + argname + "();"
				valcopyend += "\n        work.vx_p_" + argname + " = vx_p_" + argname + ";"
				vx_any += "" +
					"\n      case \":" + arg.name + "\":" +
					"\n        output = this." + argname + "();" +
					"\n        break;"
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						"\n            } else if (" + LangIsType(lang, "valsub", rawbooleantype) + ") {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, valsub);"
				case "vx/core/int":
					argalt = "" +
						"\n            } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub);"
				case "vx/core/float":
					argalt = "" +
						"\n            } else if (" + LangIsType(lang, "valsub", rawfloattype) + ") {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_float, valsub);"
				case "vx/core/string":
					argalt = "" +
						"\n            } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, valsub);"
				}
				valnewswitcherr := ""
				switch NameFromType(typ) {
				case "vx/core/msg":
				default:
					valnewswitcherr = "" +
						"\n            } else {" +
						"\n              if (false) {" +
						LangElseIfType(lang, anytype, emptytype, "valsub", "valinvalid", 7, false) +
						LangVarSet(lang, "msgval", "valinvalid", 8) +
						"\n              } else {" +
						"\n                msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + ")" + lang.lineend +
						"\n              }" +
						LangVar(lang, "mapany", rawmaptype, anytype, LangVxNewMap(lang, anytype, ""), 7, false, false) +
						"\n              mapany.put(\"key\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + arg.name + "\"));" +
						"\n              mapany.put(\"value\", msgval);" +
						"\n              " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map msgmap = " + LangNameFromPkgNameDot(lang, "vx/core") + "t_anymap.vx_new_from_map(mapany);" +
						"\n              msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", msgmap);" +
						"\n              msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);"
				}
				valnewswitch += "" +
					"\n          case \":" + arg.name + "\":" +
					"\n            if (valsub == vx_p_" + argname + ") {" +
					LangElseIfType(lang, arg.vxtype, emptytype, "valsub", "val"+argname, 6, false) +
					//"\n            } else if (" + LangIsType(lang, "valsub", arg.vxtype) + ") {" +
					"\n              ischanged = true;" +
					"\n              vx_p_" + argname + " = val" + argname + lang.lineend +
					argalt +
					valnewswitcherr +
					"\n            }" +
					"\n            break;"
				instancefuncs += "" +
					LangVarProp(lang, "vx_p_"+argname, arg.vxtype, emptytype, "null", 2, false) +
					//					"\n    public " + argclassname + " vx_p_" + argname + ";" +
					"\n" +
					LangVxArgFromArg(lang, LangNameFromType(lang, typ), arg)
			}
			defaultkey := ""
			defaultstring := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := LangFromName(lastarg.name)
				argclassname := LangNameTypeFromType(lang, lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (" + LangIsType(lang, "valsub", lastarg.vxtype) + ") { // default property" +
					"\n            ischanged = true;" +
					"\n            vx_p_" + lastargname + " = (" + argclassname + ")valsub;"
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawbooleantype) + ") { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, valsub);"
				case "vx/core/int":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub);"
				case "vx/core/float":
					defaultkey += "" +
						"\n          } else if (" + LangIsType(lang, "valsub", rawfloattype) + ") { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub);"
				case "vx/core/string":
					defaultstring += "" +
						"\n            } else if (" + LangIsType(lang, "valsub", stringtype) + ") { // default property" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + lastargname + " = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string)valsub;" +
						"\n            } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") { // default property" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + lastargname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, valsub);"
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						subargclassname := LangNameTypeFromType(lang, allowtype)
						defaultkey += "" +
							"\n          } else if (" + LangIsType(lang, "valsub", allowtype) + ") { // default property" +
							"\n            " + subargclassname + " valdefault = (" + subargclassname + ")valsub;" +
							"\n            " + argclassname + " vallist = vx_p_" + lastargname + ";" +
							"\n            if (vallist == null) {" +
							"\n              vallist = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameTFromType(lang, lastarg.vxtype) + ", valdefault);" +
							"\n            } else {" +
							"\n              vallist = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vallist, valdefault);" +

							"\n            }" +
							"\n            ischanged = true;" +
							"\n            vx_p_" + lastargname + " = vallist;"
					}
				}
			}
			switch NameFromType(typ) {
			case "vx/core/msg":
				valnew = "" +
					LangVar(lang, "key", rawstringtype, emptytype, "\"\"", 3, false, false) +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (key == \"\") {" +
					"\n          if (false) {" +
					LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false) +
					"\n            key = valstr.vx_string()" + lang.lineend +
					LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false) +
					"\n            key = sval" + lang.lineend +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\"" + lang.lineend +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "()" + lang.lineend +
					valcopyend +
					"\n        output = work" + lang.lineend +
					"\n      }"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      " + LangNameTypeFromType(lang, rawstringtype) + " key = \"\";" +
					"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
					"\n      " + LangNameTypeFromType(lang, anytype) + " msgval;" +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
					"\n          if (valsub != " + LangNameEFromType(lang, msgblocktype) + ") {" +
					"\n            vx_p_msgblocks = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgblocks, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgblocklisttype) + ") {" +
					"\n          if (valsub != " + LangNameEFromType(lang, msgblocklisttype) + ") {" +
					"\n            vx_p_msgblocks = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgblocks, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
					"\n          if (valsub != " + LangNameEFromType(lang, msgtype) + ") {" +
					"\n            vx_p_msgs = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgs, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msglisttype) + ") {" +
					"\n          if (valsub != " + LangNameEFromType(lang, msglisttype) + ") {" +
					"\n            vx_p_msgs = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgs, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (key == \"\") {" +
					"\n          if (false) {" +
					LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false) +
					"\n            key = valstr.vx_string()" + lang.lineend +
					LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false) +
					"\n            key = sval" + lang.lineend +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\"" + lang.lineend +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        if ((" + LangVxListSize(lang, "vx_p_msgs.vx_list()") + " == 0) && (" + LangVxListSize(lang, "vx_p_msgblocks.vx_list()") + " == 1)) {" +
					"\n          output = " + LangVxListGet(lang, "vx_p_msgblocks.vx_listmsgblock()", "0") + lang.lineend +
					"\n        } else {" +
					"\n          Class_" + typename + " work = new Class_" + typename + "();" +
					"\n          work.vx_p_msgs = vx_p_msgs;" +
					"\n          work.vx_p_msgblocks = vx_p_msgblocks;" +
					"\n          output = work;" +
					"\n        }" +
					"\n      }"
			default:
				valnew = "" +
					validkeys +
					"\n      " + LangNameTypeFromType(lang, rawstringtype) + " key = \"\";" +
					"\n      " + LangNameTypeFromType(lang, msgtype) + " msg;" +
					"\n      " + LangNameTypeFromType(lang, anytype) + " msgval;" +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
					"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
					"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          " + LangNameTypeFromType(lang, rawbooltype) + " istestkey = false;" +
					"\n          " + LangNameTypeFromType(lang, rawstringtype) + " testkey = \"\";" +
					"\n          if (false) {" +
					LangElseIfType(lang, stringtype, emptytype, "valsub", "valstr", 5, false) +
					"\n            testkey = valstr.vx_string();" +
					"\n            istestkey = true;" +
					LangElseIfType(lang, rawstringtype, emptytype, "valsub", "sval", 5, false) +
					"\n            testkey = sval;" +
					"\n            istestkey = true;" +
					defaultkey +
					"\n          } else {" +
					"\n            if (false) {" +
					LangElseIfType(lang, anytype, emptytype, "valsub", "valmsg", 6, false) +
					"\n              msgval = valmsg" + lang.lineend +
					"\n            } else {" +
					"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(" + LangVxToString(lang, "valsub") + ")" + lang.lineend +
					"\n            }" +
					"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkeytype\", msgval);" +
					"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n          }" +
					"\n          if (istestkey) {" +
					"\n            if (!" + LangVxStartswith(lang, "testkey", "\":\"") + ") {" +
					"\n              testkey = \":\" + testkey;" +
					"\n            }" +
					"\n            " + LangNameTypeFromType(lang, rawbooltype) + " isvalidkey = " + LangVxContains(lang, "validkeys", "testkey") + lang.lineend +
					"\n            if (isvalidkey) {" +
					"\n              key = testkey;" +
					defaultstring +
					"\n            } else {" +
					"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(testkey);" +
					"\n              msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n              msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n            }" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          default:" +
					"\n            msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(key);" +
					"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n            break;" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "();" +
					valcopyend +
					"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
					"\n          work.vxmsgblock = msgblock;" +
					"\n        }" +
					"\n        output = work;" +
					"\n      }"
			}
		}
		prefix := LangNameFromType(lang, typ)
		argkey := NewArg("key")
		argkey.vxtype = stringtype
		argkey.isfinal = true
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
				LangVar(lang, "skey", rawstringtype, emptytype, "key.vx_string()", 3, false, false) +
				"\n      switch (skey) {" +
				vx_any +
				"\n      }"
		}
		instancefuncs += "" +
			LangFuncHeader(lang, prefix, funcvxany, false, false) +
			LangVar(lang, "output", anytype, emptytype, LangNameEFromType(lang, anytype), 3, false, false) +
			skeyswitch +
			"\n      return output" + lang.lineend +
			"\n    }" +
			"\n" +
			LangVxMapFromStruct(lang, typ)
	default:
		//if extendinterface == "" {
		//	extendinterface = LangNameFromPkgNameDot(lang, "vx/core") + "Type_anytype"
		//}
		if valnew == "" {
			valnew = "" +
				"\n      if (ischanged || (msgblock != " + LangNameEFromType(lang, msgblocktype) + ")) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
		}
	}
	sinterface := LangInterfaceFromType(lang, typ)
	typedef := "" +
		override1 +
		"\n    public " + override2 + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef() {" +
		"\n      return " + LangTypeDefFromType(lang, typ, "      ") + ";" +
		"\n    }" +
		"\n"
	e_type := ""
	switch NameFromType(typ) {
	case "vx/core/boolean":
	default:
		e_type = "\n  public static " + LangFinalVar(lang) + "Type_" + typename + " e_" + typename + " = new Class_" + typename + "();"
	}
	funcvxcopy := LangFuncVxCopy(typ)
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */" +
		sinterface +
		LangClassHeaderFromType(lang, typ, 1) +
		"\n" +
		instancefuncs +
		LangVxNewFromType(lang, typ, false) +
		LangFuncHeader(lang, typename, funcvxcopy, false, false) +
		"\n      Type_" + typename + " output = this;" +
		valcopy +
		valnew +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		LangVxMsgblockFromType(lang, typ) +
		override1 +
		"\n    public " + override2 + LangNameTypeFullFromType(lang, anytype) + " vx_empty() {" +
		"\n      return e_" + typename + ";" +
		"\n    }" +
		override1 +
		"\n    public " + override2 + LangNameTypeFullFromType(lang, anytype) + " vx_type() {" +
		"\n      return t_" + typename + ";" +
		"\n    }" +
		"\n" +
		typedef +
		"\n  }" +
		"\n" +
		e_type +
		"\n  public static " + LangFinalVar(lang) + "Type_" + typename + " t_" + typename + " = new Class_" + typename + "();" +
		"\n"
	return output, msgblock
}

func LangFromValue(lang *vxlang, value vxvalue, pkgname string, parentfn *vxfunc, indent int, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromValue")
	var output = ""
	valstr := ""
	sindent := StringRepeat("  ", indent)
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = LangFromName(valarg.name)
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = LangFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = LangNameFromPkgName(lang, valconst.pkgname) + ".c_" + LangFromName(valconst.alias)
			}
		}
		output = valstr
	case ":func":
		fnc := FuncFromValue(value)
		subpath := path + "/" + fnc.name
		funcname := NameFromFunc(fnc)
		if fnc.debug {
			output += LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "f_log_1(" + LangNameTFromType(lang, fnc.vxtype) + ", " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_string(\"" + funcname + "\"), "
		}
		switch fnc.name {
		case "native":
			// (native)
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
						clstext, msgs := LangFromValue(lang, argvalue, pkgname, parentfn, 0, false, test, subpath)
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
					output += StringFromStringIndent(StringFromListStringJoin(argtexts, ""), sindent)
				} else {
					output += StringFromListStringJoin(argtexts, "")
				}
			}
		default:
			var argtexts []string
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
					argtexts = append(argtexts, work)
					isskip = true
				}
			case "vx/core/fn":
			case "vx/core/let":
				if fnc.async {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_let_async("
				} else {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc) + "("
				}
			default:
				if fnc.argname != "" {
					output += LangNameFromPkgNameDot(lang, "vx/core") + "vx_any_from_func("
					argtexts = append(argtexts, LangNameTFromType(lang, fnc.vxtype))
					argtexts = append(argtexts, LangFromName(fnc.argname))
					if lang == langcpp {
						multiflag = true
					}
				} else {
					output += LangNameFromPkgNameDot(lang, fnc.pkgname) + "f_" + LangNameFromFunc(fnc) + "("
				}
			}
			if !isskip {
				if fnc.isgeneric {
					switch funcname {
					case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
					default:
						if fnc.generictype != nil {
							genericarg := LangNameTFromTypeGeneric(lang, fnc.vxtype)
							argtexts = append(argtexts, genericarg)
						}
					}
				}
				if fnc.context {
					argtexts = append(argtexts, "context")
				}
				subindent := indent + 1
				ssubindent := StringRepeat("  ", subindent)
				for fncidx, funcarg := range funcargs {
					argsubpath := subpath + "/:arg/" + funcarg.name
					if fncidx == 0 && funcname == "vx/core/fn" {
					} else {
						var argvalue = funcarg.value
						argtext := ""
						if argvalue.code == ":func" && argvalue.name == "fn" {
							argfunc := FuncFromValue(argvalue)
							var lambdaargs []string
							var lambdavars []string
							arglist := ListLocalArgFromFunc(argfunc)
							for _, lambdaarg := range arglist {
								lambdaargs = append(lambdaargs, lambdaarg.name+"_any")
								argvaltype := ""
								argvalinstance := ""
								argtype := lambdaarg.vxtype
								argvaltype = LangNameTypeFullFromType(lang, argtype)
								argvalinstance = LangNameTFromType(lang, argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringFromListStringJoin(lambdaargs, ", ")
							lambdavartext := "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
							g_ifuncdepth += 1
							outputname := "output_" + StringFromInt(g_ifuncdepth)
							if argfunc.async {
								workvalue, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work := "" +
									LangVar(lang, outputname, anytype, emptytype, workvalue, 1, false, false) +
									"\n  return " + outputname + lang.lineend
								switch funcarg.vxtype.name {
								case "any<-any-key-value-async", "any<-key-value-async",
									"any<-reduce-async", "any<-reduce-next-async":
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											LangNameFromPkgNameDot(lang, "vx/core") + "t_any_from_any_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangNameFromPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								workvalue, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work := "" +
									LangVar(lang, outputname, anytype, emptytype, workvalue, 1, false, false) +
									"\n  return " + outputname + lang.lineend
								switch funcarg.vxtype.name {
								case "any<-int", "any<-int-any",
									"any<-any-key-value", "any<-key-value",
									"any<-reduce", "any<-reduce-next",
									"boolean<-any":
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_any" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							}
						} else if funcname == "vx/core/let" {
							switch fncidx {
							case 0:
								argtext = ""
							case 1:
								var argasync = false
								arglist := ListLocalArgFromFunc(fnc)
								for _, lambdaarg := range arglist {
									if lambdaarg.async {
										argasync = true
									}
								}
								lambdatext := ""
								aftertext := ""
								if argasync {
									argindent := 1
									for _, lambdaarg := range arglist {
										arglineindent := "\n" + StringRepeat("  ", argindent)
										if lambdaarg.async {
											g_ifuncdepth += 1
											outputname := "output_" + StringFromInt(g_ifuncdepth)
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + LangFinalArg(lang) + lang.future + "<" + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + "> future_" + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + lang.lineend +
												LangVar(lang, outputname, anytype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_async_from_async_fn(future_"+LangFromName(lambdaarg.name)+", ("+LangFromName(lambdaarg.name)+") "+lang.lambdafunc+" {", argindent, false, true)
											aftertext += "" +
												arglineindent + "})" + lang.lineend +
												arglineindent + "return " + outputname + lang.lineend
											argindent += 1
										} else {
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + LangFinalArg(lang) + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 2, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangNameFromPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										LangVar(lang, outputname, anytype, emptytype, work, 2, false, false) +
										"\n    return " + outputname + lang.lineend +
										aftertext +
										"\n})"
								} else {
									argindent := 1
									arglineindent := "\n" + StringRepeat("  ", argindent)
									for _, lambdaarg := range arglist {
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += LangVar(lang, LangFromName(lambdaarg.name), lambdaarg.vxtype, emptytype, lambdavaluetext, argindent, false, false)
										//lambdatext += arglineindent + LangFinalArg(lang) + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangNameFromPkgNameDot(lang, "vx/core") + "t_any_from_func" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										LangVar(lang, outputname, anytype, emptytype, work, argindent, false, false) +
										arglineindent + "return " + outputname + lang.lineend +
										"\n})"
								}
							}
						} else if funcname == "vx/core/fn" {
						} else if funcarg.vxtype.isfunc {
							switch argvalue.code {
							case ":arg":
								argvaluearg := ArgFromValue(argvalue)
								if !argvaluearg.vxtype.isfunc {
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argvaluefuncname := "any_from_func"
									switch NameFromType(funcarg.vxtype) {
									case "vx/core/boolean<-func":
										argvaluefuncname = "boolean_from_func"
									}
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_" + argvaluefuncname + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										"\n  return " + work + ";" +
										"\n})"
								}
							case ":funcref":
								switch funcarg.vxtype.name {
								case "any<-any-key-value", "any<-any-key-value-async",
									"any<-key-value", "any<-key-value-async",
									"any<-reduce", "any<-reduce-async",
									"any<-reduce-next", "any<-reduce-next-async":
									funcargfunc := FuncFromValue(argvalue)
									funcarglist := funcargfunc.listarg
									lambdatext, lambdavartext, lambdaargtext := LangLambdaFromArgList(lang, funcarglist, funcargfunc.isgeneric)
									work := LangNameFFromFunc(lang, funcargfunc) + "(" + lambdaargtext + ")"
									outputtype := LangNameTypeFromType(lang, anytype)
									if funcargfunc.async {
										outputtype = lang.future + "<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any>"
									}
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
										lambdavartext +
										"\n  " + outputtype + " " + outputname + " = " + work + lang.lineend +
										"\n  return " + outputname + lang.lineend +
										"\n})"
								}
							default:
								funcargasync := funcarg.vxtype.vxfunc.async
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
									work = LangNameFromPkgNameDot(lang, "vx/core") + "f_async(" + LangNameTFromType(lang, argfunctype) + ",\n" + sworkindent + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "\n  return " + work + ";"
								}
								argtext = "" +
									LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
							argtext = work
							msgblock = MsgblockAddBlock(msgblock, msgs)
						}
						if !multiline {
							if BooleanFromStringContains(argtext, "\n") {
								multiline = true
							} else if argvalue.name != "" {
								multiline = true
							} else if multiflag {
								multiline = true
							}
						}
						if funcarg.multi {
							ismultiarg := false
							if argvalue.code == ":arg" {
								argvaluearg := ArgFromValue(argvalue)
								if argvaluearg.multi {
									ismultiarg = true
								} else if funcarg.vxtype == argvaluearg.vxtype {
									ismultiarg = true
								}
							}
							if ismultiarg {
							} else if multiflag {
								argtext = ssubindent + StringFromStringIndent(argtext, ssubindent)
							} else {
								multiflag = true
								argtext = "" +
									LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameTFromType(lang, funcarg.vxtype) + "," +
									"\n" + ssubindent + StringFromStringIndent(argtext, ssubindent)
							}
						}
						if argtext != "" {
							argtexts = append(argtexts, argtext)
						}
					}
				}
			}
			if multiline {
				output += "\n" + sindent + "  " + StringFromStringIndent(StringFromListStringJoin(argtexts, ",\n"), sindent+"  ")
				if multiflag {
					output += "\n" + sindent + "  )"
				}
				switch fnc.name {
				case "fn":
				default:
					output += "\n" + sindent + ")"
				}
			} else {
				output += StringFromListStringJoin(argtexts, ", ")
				if multiflag {
					output += ")"
				}
				switch funcname {
				case "vx/core/fn":
				default:
					if !isskip {
						output += ")"
					}
				}
			}
		}
		if fnc.debug {
			output += ")"
		}
	case ":funcref":
		valfunc := FuncFromValue(value)
		valstr = ""
		valstr += LangNameFromPkgName(lang, valfunc.pkgname) + lang.typeref + "t_" + LangFromName(valfunc.alias)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = LangNameFromPkgName(lang, valtype.pkgname) + lang.typeref + "t_" + LangFromName(valtype.alias)
	case "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = valstr
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			valstr = valstr[1 : len(valstr)-1]
			if encode {
				output = LangFromText(valstr)
			} else {
				output = valstr
			}
		} else if BooleanIsNumberFromString(valstr) {
			output = valstr
		} else {
			output = valstr
		}
		if encode {
			output = LangTypeStringValNew(lang, output)
		}
	case "boolean":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_decimal" + lang.typeref + "vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_int(" + valstr + ")"
		}
	case "number":
		if encode {
			valstr = StringValueFromValue(value)
			output = valstr
		}
	default:
		//msg := MsgNew("Invalid Value Code:", value.code, ValueToText(value))
		//msgblock = MsgBlockAddError(msgblock, msg)
	}
	return output, msgblock
}

func LangArgHeader(lang *vxlang, arg vxarg) string {
	output := ""
	sfinal := ""
	if arg.isfinal {
		sfinal = LangFinalArg(lang)
	}
	sargname := arg.name
	typ := arg.vxtype
	stypename := LangNameFromType(lang, typ)
	smulti1 := ""
	smulti2 := ""
	if arg.multi {
		switch lang.name {
		case "csharp":
			smulti1 = "params "
			smulti2 = "[]"
		case "java":
			smulti2 = "..."
		}
	}
	output = "" + sfinal + smulti1 + stypename + smulti2 + " " + sargname
	return output
}

func LangElseIfType(lang *vxlang, typ *vxtype, subtype *vxtype, svar string, scastvar string, indent int, isfuture bool) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang.name {
	case "csharp":
		if scastvar == "" {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		} else {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + " " + scastvar + ") {"
		}
	case "java":
		output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		if scastvar != "" {
			output += LangVar(lang, scastvar, typ, subtype, LangAsType(lang, svar, typ), indent+1, false, isfuture) + lang.lineend
		}
	}
	return output
}

func LangFuncHeader(lang *vxlang, prefix string, fnc *vxfunc, isinterface bool, isstatic bool) string {
	return LangFuncHeaderAll(lang, prefix, fnc, 2, isinterface, isstatic)
}

func LangFuncHeaderAll(lang *vxlang, prefix string, fnc *vxfunc, indent int, isinterface bool, isstatic bool) string {
	output := ""
	funcname := fnc.name
	final := LangFinalArg(lang)
	static := ""
	if isstatic {
		static = "static "
	}
	returntype := LangNameTypeFullFromTypeSimple(lang, fnc.vxtype, false)
	var listargtext []string
	if fnc.generictype != nil {
		returntype = LangGenericFromType(lang, fnc.generictype)
		generictype := returntype
		switch fnc.generictype {
		case rawlisttype1, rawmaptype1:
			generictype = "T"
		}
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, final+generictype+" generic_any_1")
		}
		if fnc.context {
			listargtext = append(listargtext, final+LangNameTypeFromType(lang, contexttype)+" context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = LangGenericFromType(lang, argtype)
			} else {
				argtypename = LangNameTypeFromType(lang, argtype)
			}
			argname := LangFromName(arg.alias)
			isskip := false
			switch NameFromFunc(fnc) {
			case "vx/core/let", "vx/core/let-async":
				// args is not included in let
				if argname == "args" {
					isskip = true
				}
			}
			if !isskip {
				listargtext = append(listargtext, final+argtypename+" "+argname)
			}
		}
	} else {
		if fnc.context {
			listargtext = append(listargtext, final+LangNameTypeFromType(lang, contexttype)+" context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
			argname := LangFromName(arg.alias)
			params1 := ""
			params2 := ""
			if arg.multi {
				switch lang.name {
				case "csharp":
					params1 = "params "
					params2 = "[]"
				case "java":
					params2 = "..."
				}
			}
			listargtext = append(listargtext, final+params1+argtypename+params2+" "+argname)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
	genericdefinition1, genericdefinition2, genericdefinition3 := LangGenericDefinitionFromFunc(lang, fnc)
	override1 := ""
	override2 := ""
	sindent := "\n" + StringRepeat("  ", indent)
	if fnc.isoverride {
		switch lang.name {
		case "csharp":
			override2 = "override "
		case "java":
			override1 = sindent + "@Override"
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
			override2 = sindent + "new "
		}
	}
	sinterface := ""
	sopen := ""
	if isinterface {
		sinterface = ";"
	} else {
		sopen = " {"
	}
	funcprefix := ""
	switch lang.name {
	case "cpp":
		funcprefix = prefix + "::"
	}
	if fnc.async {
		returntype = lang.future + "<" + returntype + ">"
	}
	output = "" +
		override1 +
		sindent + "public " + static + override2 + genericdefinition1 + returntype + " " + funcprefix + funcname + genericdefinition2 + "(" + argtext + ")" + genericdefinition3 + sinterface + sopen
	return output
}

func LangFuncHeaderCall(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangFuncHeaderInterface(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangGenericDefinitionFromFunc(lang *vxlang, fnc *vxfunc) (string, string, string) {
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
		case "java":
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

func LangGenericFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	if typ.isgeneric {
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
			output = "Map<" + LangNameTypeFromType(lang, rawstringtype) + ", T>"
		case "struct-1":
			output = "Q"
		case "struct-2":
			output = "R"
		case "struct-3":
			output = "S"
		}
	} else {
		output = LangNameTypeFromType(lang, typ)
	}
	return output
}

func LangImport(lang *vxlang, project *vxproject, pkgname string, imports string) string {
	output := ""
	importline := ""
	switch lang.name {
	case "cpp":
		importline = "#include \"" + pkgname + ".hpp\""
	case "csharp":
		//path := StringFromStringFindReplace(pkgname, "/", ".")
		//path = StringUCaseFirstFromStringDelim(path, ".")
		//importline = "using static " + path + ";"
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name
		importline = "import " + importname + lang.lineend
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangImportTest(lang *vxlang, project *vxproject, pkgname string, imports string) string {
	output := ""
	importline := ""
	switch lang.name {
	case "cpp":
		importline = "#include \"" + pkgname + "test.hpp\""
	case "csharp":
		importline = "using Xunit;"
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name + "Test"
		importline = "import " + importname + lang.lineend
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + "test" + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangImportsFromPackage(lang *vxlang, pkg *vxpackage, pkgprefix string, body string, test bool) string {
	output := ""
	switch lang.name {
	case "java":
		if BooleanFromStringContains(body, "Arrays.") {
			output += "\nimport java.util.Arrays;"
		}
		if BooleanFromStringContains(body, " ArrayList<") {
			output += "\nimport java.util.ArrayList;"
		}
		if BooleanFromStringContains(body, "Collections.") {
			output += "\nimport java.util.Collections;"
		}
		if BooleanFromStringContains(body, " CompletableFuture<") {
			output += "\nimport java.util.concurrent.CompletableFuture;"
		}
		if BooleanFromStringContains(body, " ConcurrentLinkedDeque<") {
			output += "\nimport java.util.concurrent.ConcurrentLinkedDeque;"
		}
		if BooleanFromStringContains(body, " ConcurrentHashMap<") {
			output += "\nimport java.util.concurrent.ConcurrentHashMap;"
		}
		if BooleanFromStringContains(body, " Deque<") {
			output += "\nimport java.util.Deque;"
		}
		if BooleanFromStringContains(body, " LinkedHashMap<") {
			output += "\nimport java.util.LinkedHashMap;"
		}
		if BooleanFromStringContains(body, " List<") {
			output += "\nimport java.util.List;"
		}
		if BooleanFromStringContains(body, " Map<") {
			output += "\nimport java.util.Map;"
		}
		if BooleanFromStringContains(body, " Set<") {
			output += "\nimport java.util.Set;"
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
					switch lang.name {
					case "csharp":
						//libpath = StringSubstring(pkgpath, 0, -1)
						libpath = StringUCaseFirstFromStringDelim(libpkgpath, "/")
					case "java", "kotlin":
						libprefix := pkgpath
						libprefix = lib.pkg.project.javadomain
						libpath = libprefix + "/" + libpkgpath + "*"
					}
				}
				libpath = StringFromStringFindReplace(libpath, "/", ".")
			}
			if !isskip {
				importline := ""
				switch lang.name {
				case "csharp":
					//importline = "\nusing static " + libpath + lang.lineend
				case "java", "kotlin":
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

func LangIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func LangInterfaceFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	typename := LangNameTypeFullFromType(lang, typ)
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
	funcvxcopy := NewFunc()
	funcvxcopy.name = "vx_copy"
	funcvxcopy.vxtype = anytype
	funcvxcopy.listarg = arglist
	basics := "" +
		LangFuncHeader(lang, typename, funcvxnew, true, false) +
		LangFuncHeader(lang, typename, funcvxcopy, true, false) +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty();" +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type();"
	switch lang.name {
	case "csharp":
		switch NameFromType(typ) {
		case "vx/core/any":
		default:
			basics = ""
		}
	}
	createtext, _ := LangFromValue(lang, typ.createvalue, "", emptyfunc, 0, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if (createline == "@Override") || (createline == "// :implements") {
				isoverride = true
			} else if isoverride {
				ipos := IntFromStringFindLast(createline, ")")
				createline = createline[0:ipos+1] + lang.lineend
				basics += "\n    " + createline
				isoverride = false
			}
		}
	}
	switch NameFromType(typ) {
	case "vx/core/any":
		funcvxrelease := NewFunc()
		funcvxrelease.name = "vx_release"
		funcvxrelease.vxtype = rawbooltype
		output = "" +
			LangInterfaceHeader(lang, anytype, emptylisttype, 1) +
			basics +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef();" +
			"\n    public List<Type_any> vx_dispose();" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msgblock vx_msgblock();" +
			LangFuncHeader(lang, LangNameFromType(lang, typ), funcvxrelease, true, false) +
			"\n    public void vx_reserve();" +
			"\n  }" +
			"\n"
	case "vx/core/boolean":
		output = "" +
			LangInterfaceHeader(lang, booleantype, []*vxtype{anytype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			LangInterfaceHeader(lang, decimaltype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/float":
		output = "" +
			LangInterfaceHeader(lang, floattype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/func":
		output = "" +
			LangInterfaceHeader(lang, functype, []*vxtype{anytype}, 1) +
			basics +
			"\n	   public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_funcdef vx_funcdef();" +
			"\n  }" +
			"\n"
	case "vx/core/int":
		output = "" +
			LangInterfaceHeader(lang, inttype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/string":
		output = "" +
			LangInterfaceHeader(lang, stringtype, []*vxtype{anytype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/list":
		output = "" +
			LangInterfaceHeader(lang, listtype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public List<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> vx_list();" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any vx_any(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_int index);" +
			"\n  }" +
			"\n"
	case "vx/core/map":
		output = "" +
			LangInterfaceHeader(lang, maptype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map vx_new_from_map(" + LangFinalArg(lang) + LangNameTypeFromType(lang, rawmapanytype) + " mapval);" +
			"\n    public " + LangNameTypeFromType(lang, anytype) + " vx_any(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " key);" +
			"\n    public " + LangNameTypeFromType(lang, rawmapanytype) + " vx_map();" +
			"\n    public " + LangNameTypeFromType(lang, booleantype) + " vx_set(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " name, " + LangFinalArg(lang) + LangNameTypeFromType(lang, anytype) + " value);" +
			"\n  }" +
			"\n"
	case "vx/core/struct":
		output = "" +
			LangInterfaceHeader(lang, structtype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public " + LangNameTypeFromType(lang, anytype) + " vx_any(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " key);" +
			"\n    public " + LangNameTypeFromType(lang, rawmapanytype) + " vx_map();" +
			"\n  }" +
			"\n"
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
			allowclass := LangNameFromPkgNameDot(lang, "vx/core") + "Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = LangNameTypeFullFromType(lang, allowtype)
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public List<" + allowclass + "> vx_list" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_int index);"
			}
		case ":map":
			extends = append(extends, maptype)
			allowtype := anytype
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype = allowtypes[0]
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public " + LangNameTypeFromTypeSubtype(lang, rawmaptype, allowtype) + " vx_map" + allowname + "();" +
					"\n    public " + LangNameTypeFromType(lang, allowtype) + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string key);"
			}
		case ":struct":
			extends = append(extends, structtype)
			if len(typ.traits) > 0 {
				extends = append(extends, typ.traits...)
			}
			var typeproperties []vxarg
			switch lang.name {
			case "csharp":
				typeproperties = typ.properties
			case "java":
				typeproperties = ListPropertyTraitFromType(typ)
			}
			for _, arg := range typeproperties {
				extras += "\n    public " + LangNameTypeFromType(lang, arg.vxtype) + " " + LangFromName(arg.alias) + "();"
			}
		default:
			extends = append(extends, anytype)
		}
		switch lang.name {
		case "csharp":
			basics = ""
		}
		output = "" +
			LangInterfaceHeader(lang, typ, extends, 1) +
			basics +
			extras +
			"\n  }" +
			"\n"
	}
	return output
}

func LangInterfaceFnFromFunc(lang *vxlang, fnc *vxfunc) string {
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
		returntype := LangNameFromPkgNameDot(lang, "vx/core") + "Type_any"
		switch NameFromType(fnc.vxtype) {
		case "vx/core/none":
			returntype = "void"
		default:
			if fnc.async {
				returntype = lang.future + "<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any>"
			}
		}
		var args []string
		/*
			if fnc.generictype != nil {
				argname := LangFromName(fnc.generictype.alias)
				argtypename := LangNameTypeFromTypeSimple(lang, fnc.generictype, true)
				args = append(args, argtypename+" "+argname)
			}
		*/
		if fnc.context {
			args = append(args, LangNameTypeFromType(lang, contexttype)+" context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argname := LangFromName(arg.alias)
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
			args = append(args, argtypename+" "+argname)
		}
		argnames := StringFromListStringJoin(args, ", ")
		switch lang.name {
		case "csharp":
			interfaces = "" +
				"\n    public delegate " + returntype + " IFn(" + argnames + ");" +
				"\n"
		case "java":
			interfaces = "" +
				"\n    @FunctionalInterface" +
				"\n    public interface IFn {" +
				"\n      public " + returntype + " resolve(" + argnames + ");" +
				"\n    }" +
				"\n"
		}
	}
	return interfaces
}

func LangInterfaceFromFunc(lang *vxlang, fnc *vxfunc) string {
	funcname := LangNameFromFunc(fnc)
	extends := ""
	interfaces := ""
	genericdefinition1, genericdefinition2, genericdefinition3 := LangGenericDefinitionFromFunc(lang, fnc)
	returntype := LangNameTypeFromType(lang, fnc.vxtype)
	var listargtext []string
	if fnc.generictype != nil {
		returntype = LangGenericFromType(lang, fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, LangFinalArg(lang)+returntype+" generic_any_1")
		}
		if fnc.context {
			listargtext = append(listargtext, LangFinalArg(lang)+LangNameTypeFromType(lang, contexttype)+" context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = LangGenericFromType(lang, argtype)
			} else {
				argtypename = LangNameTypeFromType(lang, argtype)
			}
			argname := LangFromName(arg.alias)
			isskip := false
			switch NameFromFunc(fnc) {
			case "vx/core/let", "vx/core/let-async":
				// args is not included in let
				if argname == "args" {
					isskip = true
				}
			}
			if !isskip {
				listargtext = append(listargtext, LangFinalArg(lang)+argtypename+" "+argname)
			}
		}
	} else {
		if fnc.context {
			listargtext = append(listargtext, LangFinalArg(lang)+LangNameTypeFromType(lang, contexttype)+" context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
			argname := LangFromName(arg.alias)
			listargtext = append(listargtext, LangFinalArg(lang)+argtypename+" "+argname)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
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
		extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += LangVxFnNewFromFunc(lang, fnc, true)
	case "vx/core/none<-any":
	default:
		if extends == "" {
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
			default:
				switch len(fnc.listarg) {
				case 1:
					extends = LangNameFromPkgNameDot(lang, "vx/core") + "Func_any_from_any"
					if fnc.context {
						extends += "_context"
					}
					if fnc.async {
						extends += "_async"
					}
				default:
					extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
				}
			}
		}
	}
	if fnc.async {
		switch lang.name {
		case "csharp":
			returntype = "Task<" + returntype + ">"
		case "java":
			returntype = "CompletableFuture<" + returntype + ">"
		default:
			returntype = "Future<" + returntype + ">"
		}
	}
	if extends == LangNameFromPkgNameDot(lang, "vx/core")+"Type_func" {
		if fnc.async {
			extends += ", " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_replfunc_async"
		} else {
			extends += ", " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_replfunc"
		}
	}
	interfaces += "" +
		"\n    public " + genericdefinition1 + returntype + " vx_" + funcname + genericdefinition2 + "(" + argtext + ")" + genericdefinition3 + ";"
	output := "" +
		"\n  public interface Func_" + funcname + " " + lang.itfext + " " + extends + " {" +
		interfaces +
		"\n  }" +
		"\n"
	return output
}

func LangInterfaceHeader(lang *vxlang, typ *vxtype, extendtypes []*vxtype, indent int) string {
	lineindent := LangIndent(lang, indent, true)
	output := ""
	extendtext := ""
	var extendtexts []string
	for _, extendtype := range extendtypes {
		extendpart := LangNameTypeFromType(lang, extendtype)
		extendtexts = append(extendtexts, extendpart)
	}
	extendtext = StringFromListStringJoin(extendtexts, ", ")
	switch lang.name {
	case "csharp":
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	case "java":
		if extendtext != "" {
			extendtext = " extends " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	case "kotlin":
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	}
	return output
}

func LangIsType(lang *vxlang, svar string, typ *vxtype) string {
	return LangIsTypeText(lang, svar, LangNameTypeFullFromType(lang, typ))
}

func LangIsTypeText(lang *vxlang, svar string, stype string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = svar + " is " + stype
	case "java":
		output = svar + " instanceof " + stype
	}
	return output
}

func LangLambdaFromArgList(lang *vxlang, arglist []vxarg, isgeneric bool) (string, string, string) {
	var lambdatypenames []string
	var lambdavars []string
	var lambdaargnames []string
	if isgeneric {
		lambdaargname := LangNameTFromType(lang, anytype)
		lambdaargnames = append(lambdaargnames, lambdaargname)
	}
	for _, lambdaarg := range arglist {
		argvaltype := ""
		argtype := lambdaarg.vxtype
		lambdaargname := LangFromName(lambdaarg.alias) + "_lmb"
		lambdaargnames = append(lambdaargnames, lambdaargname)
		switch NameFromType(argtype) {
		case "vx/core/any", "vx/core/any-1":
			argtypename := LangNameTypeFromType(lang, anytype)
			lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
		default:
			switch lambdaarg.name {
			case "key":
				argtypename := LangNameTypeFromType(lang, argtype)
				lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
			default:
				argvaltype = LangNameTypeFullFromType(lang, argtype)
				argvaltname := LangNameTFromType(lang, argtype)
				argtypename := LangNameTypeFromType(lang, anytype)
				lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname+"_any")
				corepkgname := LangNameFromPkgName(lang, "vx/core")
				lambdavar := argvaltype + " " + lambdaargname + " = " + corepkgname + lang.pkgref + "f_any_from_any(" + argvaltname + ", " + lambdaargname + "_any)" + lang.lineend
				lambdavars = append(lambdavars, lambdavar)
			}
		}
	}
	lambdanames := StringFromListStringJoin(lambdaargnames, ", ")
	lambdatext := StringFromListStringJoin(lambdatypenames, ", ")
	lambdavartext := ""
	if len(lambdavars) > 0 {
		lambdavartext = "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
	}
	return lambdatext, lambdavartext, lambdanames
}

func LangNameCFromConst(lang *vxlang, cnst *vxconst) string {
	name := "c_" + LangFromName(cnst.alias)
	if cnst.pkgname != "" {
		name = LangNameFromPkgName(lang, cnst.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameClassFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "Class_" + LangNameFromFunc(fnc)
	return name
}

func LangNameClassFromType(lang *vxlang, typ *vxtype) string {
	name := "Class_" + LangNameFromType(lang, typ)
	return name
}

func LangNameClassFullFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := LangNameClassFromFunc(lang, fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameClassFullFromType(lang *vxlang, typ *vxtype) string {
	name := LangNameClassFromType(lang, typ)
	if typ.pkgname != "" {
		name = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameEFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref
		if lang == langcpp {
			output += "vx_empty"
		} else {
			output += "f_empty"
		}
		output += "(generic_" + LangFromName(typ.name) + ")"
	} else {
		output = "e_" + LangNameFromType(lang, typ)
		if typ.pkgname != "" {
			output = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + output
		}
	}
	return output
}

func LangNameEFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "e_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "f_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFromArg(lang *vxlang, arg vxarg) string {
	return LangFromName(arg.alias)
}

func LangNameFromConst(cnst *vxconst) string {
	return LangFromName(cnst.alias)
}

func LangNameFromFunc(fnc *vxfunc) string {
	output := LangFromName(fnc.alias)
	if output == "" {
		output = LangFromName(fnc.name)
	}
	output += LangIndexFromFunc(fnc)
	return output
}

func LangNameFromPkgName(lang *vxlang, pkgname string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = StringUCaseFirstFromStringDelim(pkgname, "/")
		output = StringFromStringFindReplace(output, "/", ".")
	case "java":
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

func LangNameFromPkgNameDot(lang *vxlang, pkgname string) string {
	output := LangNameFromPkgName(lang, pkgname) + lang.pkgref
	return output
}

func LangNameFromType(lang *vxlang, typ *vxtype) string {
	return LangNameFromTypeSimple(lang, typ, false)
}

func LangNameFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	alias := typ.alias
	switch typ {
	case rawbooltype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java":
			name = "boolean"
		}
	case rawbooleantype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java":
			name = "Boolean"
		}
	case rawfloattype:
		switch lang.name {
		case "csharp", "java":
			name = "Float"
		}
	case rawifntype:
		switch lang.name {
		case "csharp", "java":
			name = "IFn"
		}
	case rawinttype:
		switch lang.name {
		case "csharp", "java":
			name = "int"
		}
	case rawintegertype:
		switch lang.name {
		case "csharp", "java":
			name = "Integer"
		}
	case rawlisttype:
		switch lang.name {
		case "csharp", "java":
			name = "List"
		}
	case rawlistanytype:
		switch lang.name {
		case "csharp", "java":
			name = "List<" + LangNameFromTypeSimple(lang, anytype, true) + ">"
		}
	case rawlistunknowntype:
		switch lang.name {
		case "csharp":
			name = "List<object>"
		case "java":
			name = "List<?>"
		}
	case rawmaptype:
		switch lang.name {
		case "csharp":
			name = "Vx.Core.Map"
		case "java":
			name = "Map"
		}
	case rawmapanytype:
		switch lang.name {
		case "cpp":
			name = "std::map<string, " + LangNameFromTypeSimple(lang, anytype, true) + ">"
		case "csharp":
			name = "Vx.Core.Map<string, " + LangNameFromTypeSimple(lang, anytype, true) + ">"
		case "java":
			name = "Map<String, " + LangNameFromTypeSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		switch lang.name {
		case "cpp":
			name = "std::string"
		case "csharp":
			name = "string"
		case "java":
			name = "String"
		}
	case rawobjecttype:
		switch lang.name {
		case "csharp", "java":
			name = "Object"
		}
	default:
		if typ.isfunc {
			name = LangNameFromFunc(typ.vxfunc)
		} else if alias == "" {
			name += LangFromName(typ.name)
		} else {
			if simple && BooleanFromStringStarts(alias, "generic-") {
				alias = StringFromStringFindReplace(alias, "generic-", "")
				ipos := IntFromStringFindLast(alias, "-")
				alias = alias[0:ipos]
			}
			name += LangFromName(alias)
		}
	}
	return name
}

func LangNameFuncFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "Func_" + LangNameFromFunc(fnc)
	return name
}

func LangNameFuncFullFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := LangNameFuncFromFunc(lang, fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameTFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "t_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameTFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTFromTypeSimple(lang, typ, false)
}

func LangNameTFromTypeGeneric(lang *vxlang, typ *vxtype) string {
	name := ""
	if typ.isgeneric {
		name = "generic_" + LangFromName(typ.name)
	} else {
		name = LangNameTFromType(lang, typ)
	}
	return name
}

func LangNameTFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := "t_" + LangNameFromTypeSimple(lang, typ, simple)
	if typ.pkgname != "" {
		name = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameTypeFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFromTypeSimple(lang, typ, false)
}

func LangNameTypeFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := LangNameTypeFullFromTypeSimple(lang, typ, simple)
	switch NameFromType(typ) {
	case "vx/core/none":
		name = "void"
	}
	return name
}

func LangNameTypeFullFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFullFromTypeSimple(lang, typ, false)
}

func LangNameTypeFullFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	switch typ {
	case anylisttype:
		name = lang.pkgname + lang.pkgref + "Type_anylist"
	case contexttype:
		name = lang.pkgname + lang.pkgref + "Type_context"
	case stringtype:
		name = lang.pkgname + lang.pkgref + "Type_string"
	case rawbooltype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java":
			name = "boolean"
		}
	case rawbooleantype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java":
			name = "Boolean"
		}
	case rawfloattype:
		switch lang.name {
		case "csharp":
			name = "float"
		case "java":
			name = "Float"
		}
	case rawifntype:
		name = "IFn"
	case rawinttype:
		name = "int"
	case rawintegertype:
		switch lang.name {
		case "csharp":
			name = "int"
		case "java":
			name = "Integer"
		}
	case rawlisttype:
		switch lang.name {
		case "csharp":
			name = "List<object>"
		case "java":
			name = "List"
		}
	case rawlistanytype:
		name = "List<" + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
	case rawmaptype:
		switch lang.name {
		case "csharp":
			name = "Vx.Core.Map"
		case "java", "kotlin":
			name = "Map"
		}
	case rawlistunknowntype:
		switch lang.name {
		case "csharp":
			name = "List<object>"
		case "java":
			name = "List<?>"
		}
	case rawmapanytype:
		switch lang.name {
		case "csharp":
			name = "Vx.Core.Map<string, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
		case "java", "kotlin":
			name = "Map<String, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
		}
	case rawobjecttype:
		name = "Object"
	case rawstringtype:
		switch lang.name {
		case "cpp":
			name = "std::string"
		case "csharp":
			name = "string"
		case "java":
			name = "String"
		}
	default:
		name = LangNameFromPkgName(lang, typ.pkgname)
		if typ.isfunc {
			name += lang.pkgref + "Func_"
		} else {
			name += lang.pkgref + "Type_"
		}
		name += LangNameFromTypeSimple(lang, typ, simple)
	}
	return name
}

func LangNameTypeFromTypeSubtype(lang *vxlang, typ *vxtype, subtype *vxtype) string {
	output := LangNameTypeFromTypeSimple(lang, subtype, false)
	switch typ {
	case rawlisttype:
		output = "List<" + output + ">"
	case rawmaptype:
		switch lang.name {
		case "cpp":
			output = "std::map<std::string, " + output + ">"
		case "csharp":
			output = "Vx.Core.Map<string, " + output + ">"
		case "java":
			output = "Map<String, " + output + ">"
		}
	}
	return output
}

func LangNamespaceFromPackage(lang *vxlang, pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang.name {
	case "cpp":
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "csharp":
		ipos := IntFromStringFindLast(pkgname, ".")
		after := StringSubstring(pkgname, ipos+1, len(pkgname))
		namespaceopen = "\npublic static class " + after + " {\n\n"
		namespaceclose = "\n}\n"
	case "java":
		namespaceopen = "\npublic final class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "js":
		namespaceopen = "\nexport default class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "kotlin":
		namespaceopen = "" +
			"\nclass final class " + pkgname + " {" +
			"\n		companion object {\n\n"
		namespaceclose = "\n}\n}\n"
	}
	return namespaceopen, namespaceclose
}

func LangNativeAutoFromFunc(lang *vxlang, fnc *vxfunc) string {
	output := ""
	var listargname []string
	if fnc.generictype != nil {
		argname := LangNameTFromTypeGeneric(lang, fnc.generictype)
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
	output = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangNameFromFunc(fnc) + "(" + argnames + ")" + lang.lineend
	switch lang.name {
	case "cpp":
		if fnc.generictype != nil {
			argname := LangNameTFromTypeGeneric(lang, fnc.generictype)
			output = "" +
				"vx_core::Type_any result = " + output +
				"\noutput = vx_core::vx_any_from_any(" + argname + ", result);"
		}
	}
	return output
}

func LangOverride(lang *vxlang, indent int, isinterface bool) (string, string) {
	override1 := ""
	override2 := ""
	switch lang.name {
	case "csharp":
		if !isinterface {
			override2 = "override "
		}
	case "java":
		override1 = "\n" + StringRepeat("  ", indent) + "@Override"
	}
	return override1, override2
}

func LangPackagePathFromPrefixName(lang *vxlang, pkgprefix string, pkgname string) (string, string) {
	pkgpath := ""
	name := ""
	switch lang.name {
	case "csharp":
		pkgpath = pkgprefix + StringUCaseFirstFromStringDelim(pkgname, "/")
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNameFromPkgName(lang, name)
	case "java":
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNameFromPkgName(lang, name)
	case "kotlin":
		name = LangNameFromPkgName(lang, pkgname)
		pkgpath = name
	default:
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNameFromPkgName(lang, name)
	}
	return pkgpath, name
}

func LangReplFromFunc(lang *vxlang, fnc *vxfunc) string {
	output := ""
	replparams := ""
	argidx := 0
	var listargname []string
	pkgname := LangNameFromPkgName(lang, fnc.pkgname)
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	outputtype := ""
	outputttype := ""
	//emptytype := ""
	returnvalue := ""
	switch NameFromType(fnc.vxtype) {
	case "vx/core/none":
		outputtype = LangNameFromPkgNameDot(lang, "vx/core") + "Type_any"
		outputttype = LangNameFromPkgNameDot(lang, "vx/core") + "t_any"
		//emptytype = LangNameFromPkgNameDot(lang, "vx/core") + "e_any"
	default:
		outputtype = LangNameTypeFromTypeSimple(lang, fnc.vxtype, true)
		outputttype = LangNameTFromTypeSimple(lang, fnc.vxtype, true)
		//emptytype = LangNameEFromType(fnc.vxtype)
		returnvalue = "output = "
	}
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		default:
			if fnc.generictype != nil {
				replparam := outputtype + " generic_" + LangFromName(fnc.generictype.name) + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + outputttype + ", arglist.vx_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+LangFromName(fnc.generictype.name))
			}
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := LangNameTypeFromType(lang, contexttype) + " context = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_context, arglist.vx_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := LangFromName(arg.alias)
			replparam := LangNameTypeFromTypeSimple(lang, arg.vxtype, true) + " " + argname + " = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameTFromTypeSimple(lang, arg.vxtype, true) + ", arglist.vx_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
	}
	if fnc.async {
		output = "" +
			"\n    public " + lang.future + "<" + LangNameTypeFromType(lang, anytype) + "> vx_repl(" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_anylist arglist) {" +
			"\n      " + lang.future + "<" + LangNameTypeFromType(lang, anytype) + "> output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_new_completed(" + LangNameFromPkgNameDot(lang, "vx/core") + "e_any);" +
			replparams +
			"\n      " + lang.future + "<" + outputtype + "> future = " + pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_from_async(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_any, future);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	} else {
		output = "" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any vx_repl(" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_anylist arglist) {" +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any output = " + LangNameFromPkgNameDot(lang, "vx/core") + "e_any;" +
			replparams +
			"\n      " + returnvalue + pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	return output
}

func LangTestCase(lang *vxlang, testvalues []vxvalue, testpkg string, testname string, testcasename string, fnc *vxfunc, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestCase")
	output := ""
	g_ifuncdepth = 0
	if len(testvalues) > 0 {
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := LangFromValue(lang, testvalue, testpkg, fnc, 6, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
				"\n          " + LangNameTFromType(lang, testdescribetype) + "," +
				"\n          \":describename\", \"" + LangTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		varoutput := LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangNameTFromType(lang, testcasetype) + "," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        " + LangNameTFromType(lang, testdescribelisttype) + "," + describelist +
			"\n      )" +
			"\n    )"
		output = "" +
			"\n  static " + LangNameTypeFromType(lang, testcasetype) + " " + testcasename + "(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
			LangVar(lang, "output", testcasetype, emptytype, varoutput, 2, false, false) +
			"\n    return output;" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func LangTestFromConst(lang *vxlang, cnst *vxconst) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromConst")
	testvalues := cnst.listtestvalue
	testpkg := cnst.pkgname
	testname := cnst.name
	testcasename := "c_" + LangFromName(cnst.alias)
	path := cnst.pkgname + "/" + cnst.name
	fnc := emptyfunc
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromFunc")
	testvalues := fnc.listtestvalue
	testpkg := fnc.pkgname
	idx := LangIndexFromFunc(fnc)
	testname := fnc.name + idx
	funcname := LangFromName(fnc.alias) + idx
	testcasename := "f_" + funcname
	path := fnc.pkgname + "/" + fnc.name
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromPackage(lang *vxlang, pkg *vxpackage, prj *vxproject, command *vxcommand, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromPackage")
	pkgpath, pkgname := LangPackagePathFromPrefixName(lang, pkgprefix, pkg.name)
	typkeys := ListKeyFromMapType(pkg.maptype)
	var coverdoccnt = 0
	var coverdoctotal = 0
	var covertypecnt = 0
	var covertypetotal = 0
	var testall []string
	var covertype []string
	typetexts := ""
	for _, typid := range typkeys {
		covertypetotal += 1
		typ := pkg.maptype[typid]
		test, msgs := LangTestFromType(lang, typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "      \":"+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if command.filter == "" {
		} else if NameFromType(typ) != command.filter {
			test = ""
		}
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"Test.t_"+LangFromName(typ.alias)+"(context)")
		}
		coverdoctotal += 1
		if typ.doc != "" {
			coverdoccnt += 1
		}
	}
	var coverconstcnt = 0
	var coverconsttotal = 0
	var coverconst []string
	var coverfunc []string
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	consttexts := ""
	for _, cnstid := range cnstkeys {
		coverconsttotal += 1
		cnst := pkg.mapconst[cnstid]
		test, msgs := LangTestFromConst(lang, cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "      \":"+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if command.filter == "" {
		} else if NameFromConst(cnst) != command.filter {
			test = ""
		}
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"Test.c_"+LangFromName(cnst.alias)+"(context)")
		}
		coverdoctotal += 1
		if cnst.doc != "" {
			coverdoccnt += 1
		}
	}
	var coverbigospacecnt = 0
	var coverbigospacetotal = 0
	var coverbigotimecnt = 0
	var coverbigotimetotal = 0
	var coverfunccnt = 0
	var coverfunctotal = 0
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	functexts := ""
	for _, fncid := range fnckeys {
		coverfunctotal += 1
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			test, msgs := LangTestFromFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			coverfunc = append(coverfunc, "      \":"+fncid+LangIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
			if command.filter == "" {
			} else if NameFromFunc(fnc) != command.filter {
				test = ""
			}
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"Test.f_"+LangFromName(fnc.alias)+LangIndexFromFunc(fnc)+"(context)")
			}
			coverdoctotal += 1
			if fnc.doc != "" {
				coverdoccnt += 1
			}
			coverbigospacetotal += 1
			if fnc.bigospace != "" {
				coverbigospacecnt += 1
			}
			coverbigotimetotal += 1
			if fnc.bigotime != "" {
				coverbigotimecnt += 1
			}
		}
	}
	coverconstpct := 100
	if coverconsttotal > 0 {
		coverconstpct = (coverconstcnt * 100 / coverconsttotal)
	}
	coverfuncpct := 100
	if coverfunctotal > 0 {
		coverfuncpct = (coverfunccnt * 100 / coverfunctotal)
	}
	covertypepct := 100
	if covertypetotal > 0 {
		covertypepct = (covertypecnt * 100 / covertypetotal)
	}
	coverbigospacepct := 100
	if coverbigospacetotal > 0 {
		coverbigospacepct = (coverbigospacecnt * 100 / coverbigospacetotal)
	}
	coverbigotimepct := 100
	if coverbigotimetotal > 0 {
		coverbigotimepct = (coverbigotimecnt * 100 / coverbigotimetotal)
	}
	coverdocpct := 100
	if coverdoctotal > 0 {
		coverdocpct = (coverdoccnt * 100 / coverdoctotal)
	}
	var covercnt = coverconstcnt + coverfunccnt + covertypecnt
	var covertotal = covertypetotal + coverconsttotal + coverfunctotal
	var coverpct = 100
	if covertotal > 0 {
		coverpct = (covercnt * 100 / covertotal)
	}
	scovertype := ""
	if len(covertype) == 0 {
		scovertype = LangNameEFromType(lang, intmaptype)
	} else {
		scovertype = "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangNameFromPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(covertype, ",\n  ") +
			"\n)"
	}
	scoverconst := ""
	if len(coverconst) == 0 {
		scoverconst = LangNameEFromType(lang, intmaptype)
	} else {
		scoverconst = "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangNameFromPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(coverconst, ",\n  ") +
			"\n)"
	}
	scoverfunc := ""
	if len(coverfunc) == 0 {
		scoverfunc = LangNameEFromType(lang, intmaptype)
	} else {
		scoverfunc = "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangNameFromPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(coverfunc, ",\n  ") +
			"\n      )"
	}
	//	vararraylisttestcase1 := "new ArrayList<>(Arrays.asList(" +
	//		"\n      " + strings.Join(testall, ",\n      ") +
	//		"\n    ))"
	testcasesbody := ""
	if len(testall) == 0 {
		testcasesbody = LangVar(lang, "output", testcaselisttype, emptytype, LangNameEFromType(lang, testcaselisttype), 2, false, false)
	} else {
		vararraylisttestcase := LangNameFromPkgNameDot(lang, "vx/core") + "arraylist_from_array(" +
			"\n      " + strings.Join(testall, ",\n      ") +
			"\n    )"
		varoutput := LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangNameTFromType(lang, testcaselisttype) + "," +
			"\n      arraylisttestcase" +
			"\n    )"
		testcasesbody = "" +
			LangVar(lang, "arraylisttestcase", rawlisttype, anytype, vararraylisttestcase, 2, false, false) +
			LangVar(lang, "output", testcaselisttype, emptytype, varoutput, 2, false, false)
	}
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  public static " + LangNameTypeFromType(lang, testcaselisttype) + " test_cases(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
		testcasesbody +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  public static " + LangNameTypeFromType(lang, testcoveragesummarytype) + " test_coveragesummary() {" +
		"\n    return " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		"\n      " + LangNameTFromType(lang, testcoveragesummarytype) + "," +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":constnums\", " + LangTypeCoverageNumsValNew(lang, coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \":docnums\", " + LangTypeCoverageNumsValNew(lang, coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \":funcnums\", " + LangTypeCoverageNumsValNew(lang, coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \":bigospacenums\", " + LangTypeCoverageNumsValNew(lang, coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \":bigotimenums\", " + LangTypeCoverageNumsValNew(lang, coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \":totalnums\", " + LangTypeCoverageNumsValNew(lang, coverpct, covercnt, covertotal) + ", " +
		"\n      \":typenums\", " + LangTypeCoverageNumsValNew(lang, covertypepct, covertypecnt, covertypetotal) +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  public static " + LangNameTypeFromType(lang, testcoveragedetailtype) + " test_coveragedetail() {" +
		"\n    return " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		LangNameTFromType(lang, testcoveragedetailtype) + ", " +
		"\":testpkg\", \"" + pkg.name + "\", " +
		"\":typemap\", " + scovertype + ", " +
		"\":constmap\", " + scoverconst + ", " +
		"\":funcmap\", " + scoverfunc +
		");" +
		"\n  }" +
		"\n" +
		"\n  public static " + LangNameTypeFromType(lang, testpackagetype) + " test_package(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
		LangVar(lang, "testcaselist", testcaselisttype, emptytype, "test_cases(context)", 2, false, false) +
		LangVar(lang, "output", testpackagetype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_new("+
			"\n      "+LangNameTFromType(lang, testpackagetype)+","+
			"\n      \":testpkg\", \""+pkg.name+"\", "+
			"\n      \":caselist\", testcaselist,"+
			"\n      \":coveragesummary\", test_coveragesummary(),"+
			"\n      \":coveragedetail\", test_coveragedetail()"+
			"\n    )", 2, false, false) +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := LangImportsFromPackage(lang, pkg, pkgprefix, body, true)
	namespace := ""
	switch lang.name {
	case "csharp":
		namespace = "\nnamespace " + pkgpath + lang.lineend
	case "java":
		namespace = "\npackage " + pkgpath + lang.lineend
	}
	output := "" +
		namespace +
		"\n" +
		imports +
		"\npublic " + LangFinalClass(lang) + "class " + pkgname + "Test {" +
		"\n" +
		body +
		"\n}\n"
	return output, msgblock
}

func LangTestFromType(lang *vxlang, typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromType")
	testvalues := typ.testvalues
	testpkg := typ.pkgname
	testname := typ.name
	testcasename := "t_" + LangFromName(typ.alias)
	fnc := emptyfunc
	path := typ.pkgname + "/" + typ.name
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromValue(value vxvalue) string {
	var output = ""
	output = LangFromText(value.textblock.text)
	return output
}

func LangTypeCoverageNumsValNew(lang *vxlang, pct int, tests int, total int) string {
	return "" +
		LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		LangNameTFromType(lang, testcoveragenumstype) + ", " +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func LangTypeDefFromType(lang *vxlang, typ *vxtype, indent string) string {
	lineindent := "\n" + indent
	allowtypes := LangTypeListFromListType(lang, typ.allowtypes)
	disallowtypes := LangTypeListFromListType(lang, typ.disallowtypes)
	allowfuncs := LangNameFromPkgNameDot(lang, "vx/core") + "e_funclist"
	disallowfuncs := LangNameFromPkgNameDot(lang, "vx/core") + "e_funclist"
	allowvalues := LangNameFromPkgNameDot(lang, "vx/core") + "e_anylist"
	disallowvalues := LangNameFromPkgNameDot(lang, "vx/core") + "e_anylist"
	properties := LangNameFromPkgNameDot(lang, "vx/core") + "e_argmap"
	traits := LangTypeListFromListType(lang, typ.traits)
	output := "" +
		LangNameFromPkgNameDot(lang, "vx/core") + "typedef_new(" +
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

func LangTypeDefMapFromProperties(lang *vxlang, args []vxarg, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(args) > 0 {
		var props []string
		for _, arg := range args {
			key := LangFromName(arg.alias)
			typ := LangTypeDefFromType(lang, arg.vxtype, indent+"  ")
			props = append(props, LangNameFromPkgNameDot(lang, "vx/core")+"keyvalue_from_key_value(\":"+key+"\", "+typ+")")
		}
		output = "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "hashmap_from_keyvalues(" +
			lineindent + "  " + StringFromListStringJoin(props, ","+lineindent+"  ") +
			lineindent + ")"
	}
	return output
}

func LangTypeIntValNew(lang *vxlang, val int) string {
	return LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_int(" + StringFromInt(val) + ")"
}

func LangTypeListFromListType(lang *vxlang, listtype []*vxtype) string {
	output := LangNameFromPkgNameDot(lang, "vx/core") + "e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := LangNameTFromType(lang, typ)
			listtext = append(listtext, typetext)
		}
		output = "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_typelist, " + StringFromListStringJoin(listtext, ", ") + ")"
	}
	return output
}

func LangTypeStringValNew(lang *vxlang, val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + valstr + "\")"
}

func LangWriteFromProjectCmd(lang *vxlang, prj *vxproject, cmd *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("LangWriteFromProjectCmd")
	files, msgs := LangFilesFromProjectCmd(lang, prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	msgs = WriteListFile(files)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	switch cmd.code {
	case ":test":
		targetpath := PathFromProjectCmd(prj, cmd)
		ipos := IntFromStringFindLast(targetpath, "/")
		if ipos > 0 {
			targetpath = targetpath[0:ipos]
		}
		targetpath += "/resources"
		msgs := LangFolderCopyTestdataFromProjectPath(prj, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func LangIndent(lang *vxlang, indent int, line bool) string {
	output := ""
	if line {
		output += "\n"
	}
	output += StringRepeat(lang.indent, indent)
	return output
}

func LangVar(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype,
	varvalue string, indent int, isconst bool, isfuture bool) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, isconst, isfuture, false, false)
}

func LangVarAll(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype, varvalue string, indent int, isconst bool, isfuture bool, isstatic bool, isprop bool) string {
	output := LangIndent(lang, indent, true)
	switch lang.name {
	case "csharp":
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "List<" + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawmaptype:
			typetext = "Vx.Core.Map<string, " + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawlistunknowntype:
			typetext = "List<object>"
		default:
			typetext = LangNameTypeFullFromType(lang, vartype)
		}
		if isfuture {
			typetext = "Task<" + typetext + ">"
		}
		if varvalue == "null" {
			output += typetext + "? " + varname + " = " + varvalue
		} else if varvalue == "" {
			output += typetext + " " + varname
		} else {
			output += typetext + " " + varname + " = " + varvalue
		}
		output += lang.lineend
	case "java":
		if isstatic {
			output += "public static "
		} else if isprop {
			output += "public "
		}
		typetext := ""
		switch vartype {
		case rawlisttype:
			typetext = "List<" + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawmaptype:
			typetext = "Map<String, " + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawlistunknowntype:
			typetext = "List<?>"
		default:
			typetext = LangNameTypeFullFromType(lang, vartype)
		}
		if isfuture {
			typetext = lang.future + "<" + typetext + ">"
		}
		output += typetext + " " + varname
		if varvalue != "" {
			output += " = " + varvalue
		}
		output += lang.lineend
	case "kotlin":
		if isconst {
			output += "val"
		} else {
			output += "var"
		}
		output += " " + varname
		output += " : " + LangNameTypeFullFromType(lang, vartype)
		if varvalue != "" {
			if isfuture {
				output += " = await " + varvalue
			} else if (varvalue == "\"\"") && (vartype == rawstringtype) {
			} else {
				output += " = " + varvalue
			}
		}
	}
	return output
}

func LangVarProp(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype,
	varvalue string, indent int, isfuture bool) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, false, isfuture, false, true)
}

func LangVarStatic(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype,
	varvalue string, indent int, isconst bool, isfuture bool) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, isconst, isfuture, true, false)
}

func LangVarSet(lang *vxlang, varname string, varvalue string, indent int) string {
	output := LangIndent(lang, indent, true)
	output += varname
	output += " = " + varvalue
	switch lang.name {
	case "csharp", "java":
		output += ";"
	}
	return output
}

func LangFuncVxCopy(returntype *vxtype) *vxfunc {
	argvals := NewArg("vals")
	argvals.vxtype = rawobjecttype
	argvals.multi = true
	argvals.isfinal = true
	arglist := NewListArg()
	arglist = append(arglist, argvals)
	funcvxcopy := NewFunc()
	funcvxcopy.name = "vx_copy"
	funcvxcopy.isoverride = true
	funcvxcopy.vxtype = returntype
	funcvxcopy.listarg = arglist
	return funcvxcopy
}

func LangFuncVxNew(returntype *vxtype) *vxfunc {
	argvals := NewArg("vals")
	argvals.vxtype = rawobjecttype
	argvals.multi = true
	argvals.isfinal = true
	arglist := NewListArg()
	arglist = append(arglist, argvals)
	funcvxnew := NewFunc()
	funcvxnew.isoverride = true
	funcvxnew.name = "vx_new"
	funcvxnew.vxtype = returntype
	funcvxnew.listarg = arglist
	return funcvxnew
}

func LangVxAllowCodeFromList(lang *vxlang, typ *vxtype) string {
	output := ""
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	allowname := "any"
	allowclass := LangNameTypeFromType(lang, anytype)
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype := allowtypes[0]
		allowclass = LangNameTypeFullFromType(lang, allowtype)
		allowempty := LangNameEFromType(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
		output = "" +
			override +
			"\n    public " + allowclass + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameTypeFromType(lang, inttype) + " index) {" +
			"\n      " + allowclass + " output = " + allowempty + ";" +
			"\n      " + LangNameClassFullFromType(lang, typ) + " list = this;" +
			"\n      int iindex = index.vx_int();" +
			"\n      List<" + allowclass + "> listval = list.vx_p_list;" +
			"\n      if (iindex < " + LangVxListSize(lang, "listval") + ") {" +
			"\n        output = " + LangVxListGet(lang, "listval", "iindex") + lang.lineend +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	if allowname != "any" {
		output += "" +
			override +
			"\n    public List<" + allowclass + "> vx_list" + allowname + "() {" +
			"\n      return vx_p_list;" +
			"\n    }" +
			"\n" +
			override +
			"\n    public " + LangNameTypeFromType(lang, anytype) + " vx_any(" + LangFinalArg(lang) + LangNameTypeFromType(lang, inttype) + " index) {" +
			"\n      return this.vx_" + allowname + "(index);" +
			"\n    }" +
			"\n"
	}
	return output
}

func LangVxAllowCodeFromMap(lang *vxlang, typ *vxtype) string {
	output := ""
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	allowname := "any"
	allowtype := anytype
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowclass := LangNameTypeFullFromType(lang, allowtype)
		allowempty := LangNameEFromType(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
		output = "" +
			override +
			"\n    public " + allowclass + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " key) {" +
			LangVar(lang, "output", allowtype, emptytype, allowempty, 3, false, false) +
			"\n      " + LangNameClassFullFromType(lang, typ) + " map = this;" +
			LangVar(lang, "skey", rawstringtype, emptytype, "key.vx_string()", 3, false, false) +
			LangVar(lang, "mapval", rawmaptype, allowtype, "map.vx_p_map", 3, false, false) +
			LangVarSet(lang, "output", "mapval.getOrDefault(skey, "+allowempty+")", 3) +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	if allowname == "any" {
		allowname = ""
	} else {
		output += "" +
			override +
			"\n    public " + LangNameTypeFromTypeSubtype(lang, rawmaptype, allowtype) + " vx_map" + allowname + "() {" +
			"\n      return vx_p_map;" +
			"\n    }" +
			"\n" +
			override +
			"\n    public " + LangNameTypeFromType(lang, anytype) + " vx_any(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " key) {" +
			"\n      return this.vx_" + allowname + "(key);" +
			"\n    }" +
			"\n"
	}
	return output
}

func LangVxArgFromArg(lang *vxlang, prefix string, arg vxarg) string {
	argname := LangNameFromArg(lang, arg)
	funcvxargname := NewFunc()
	funcvxargname.name = argname
	funcvxargname.vxtype = arg.vxtype
	funcvxargname.isimplement = true
	output := "" +
		LangFuncHeader(lang, prefix, funcvxargname, false, false) +
		LangVar(lang, "output", arg.vxtype, emptytype, LangNameEFromType(lang, arg.vxtype), 3, false, false) +
		"\n      if (this.vx_p_" + argname + " != null) {" +
		"\n        output = this.vx_p_" + argname + lang.lineend +
		"\n      }" +
		"\n      return output" + lang.lineend +
		"\n    }" +
		"\n"
	return output
}

func LangVxCopyFromFunc(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	returntype := NewTypeFromFunc(fnc)
	funcvxcopy := LangFuncVxCopy(returntype)
	funcname := LangNameFromFunc(fnc)
	funcprefix := LangNameFromFunc(fnc)
	output := "" +
		LangFuncHeader(lang, funcprefix, funcvxcopy, false, false) +
		"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
		"\n      return output;" +
		"\n    }" +
		"\n"
	return output
}

func LangVxConstdef(lang *vxlang, cnst *vxconst) string {
	override := ""
	cnsttype := cnst.vxtype
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	output := "" +
		"\n    " + override +
		"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_constdef vx_constdef() {" +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + LangTypeDefFromType(lang, cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n"
	return output
}

func LangVxContains(lang *vxlang, text string, contains string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = text + ".Contains(" + contains + ")"
	case "java":
		output = text + ".contains(" + contains + ")"
	}
	return output
}

func LangVxEquals(lang *vxlang, text1 string, text2 string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = text1 + " == " + text2
	case "java":
		output = text1 + ".equals(" + text2 + ")"
	}
	return output
}

func LangVxFFromFunc(lang *vxlang, fnc *vxfunc, ismain bool) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangVxFFromFunc")
	var listargtype []string
	var listargname []string
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	returntype := ""
	if fnc.generictype == nil {
		returntype = LangGenericFromType(lang, fnc.vxtype)
	} else {
		returntype = LangGenericFromType(lang, fnc.generictype)
	}
	pkgname := LangNameFromPkgName(lang, fnc.pkgname)
	path := fnc.pkgname + "/" + fnc.name + LangIndexFromFunc(fnc)
	genericdefinition1, genericdefinition2, genericdefinition3 := LangGenericDefinitionFromFunc(lang, fnc)
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
				genericargname := LangNameTFromTypeGeneric(lang, fnc.generictype)
				argtext := LangFinalArg(lang) + LangGenericFromType(lang, fnc.generictype) + " " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, LangFinalArg(lang)+LangNameTypeFromType(lang, contexttype)+" context")
		listargname = append(listargname, "context")
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let":
		argtext := LangNameFromPkgNameDot(lang, "vx/core") + "Func_any_from_func fn_any"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any")
	case "vx/core/let-async":
		argtext := LangNameFromPkgNameDot(lang, "vx/core") + "Func_any_from_func_async fn_any_async"
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
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = LangGenericFromType(lang, fnc.generictype)
	} else {
		functypetext = returntype
	}
	if fnc.async {
		functypetext = lang.future + "<" + functypetext + ">"
	}
	indent := "    "
	subindent := indent
	lineindent := "\n" + indent
	msgtop := ""
	msgbottom := ""
	permissiontop := ""
	permissionbottom := ""
	if fnc.permission {
		permissiontop = lineindent + "if (" + LangNameFromPkgNameDot(lang, "vx/core") + "f_boolean_permission_from_func(context, " + LangNameTFromFunc(lang, fnc) + ").vx_boolean()) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			LangVar(lang, "msg", msgtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\"vx/core/func\", \":permissiondenied\", "+LangNameFromPkgNameDot(lang, "vx/core")+"vx_new_string(\""+fnc.name+"\"))", 3, true, false) +
			lineindent + "  output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(output, msg);" +
			lineindent + "}"
		subindent += "  "
	}
	linesubindent := "\n" + subindent
	if fnc.messages {
		msgtop = linesubindent + "try {"
		msgbottom = "" +
			linesubindent + "} catch (Exception err) {" +
			linesubindent + "  " + LangNameTypeFromType(lang, msgtype) + " msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_exception(\"" + fnc.pkgname + "/" + fnc.name + "\", err);" +
			linesubindent + "  output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(output, msg);" +
			linesubindent + "}"
		subindent += "  "
	}
	linesubindent = "\n" + subindent
	interfacefn := LangInterfaceFnFromFunc(lang, fnc)
	output := ""
	if ismain {
		valuetext, msgs := LangFromValue(lang, fnc.value, fnc.pkgname, fnc, 0, true, false, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		debugtop, debugbottom := LangDebugFromFunc(lang, fnc, lineindent)
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
			valuetext += ";"
		}
		if valuetext != "" {
			valuetext = linesubindent + StringFromStringIndent(valuetext, subindent)
		}
		defaultvalue := ""
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			if fnc.vxtype.name == "none" {
			} else if fnc.async {
				defaultvalue = lineindent + lang.future + "<" + returntype + "> output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_new_completed(" + LangNameEFromType(lang, fnc.vxtype) + ");"
			} else if fnc.generictype != nil {
				defaultvalue = lineindent + returntype + " output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(" + LangNameTFromTypeGeneric(lang, fnc.generictype) + ");"
			} else {
				defaultvalue = lineindent + returntype + " output = " + LangNameEFromType(lang, fnc.vxtype) + ";"
			}
		}
		after := ""
		if fnc.vxtype.name == "none" {
		} else {
			after += lineindent + "return output;"
		}
		after += "\n  }\n\n"
		output = "" +
			f_suppresswarnings +
			"\n  public static " + genericdefinition1 + functypetext + " f_" + funcname + genericdefinition2 + "(" + strings.Join(listargtype, ", ") + ")" + genericdefinition3 + " {" +
			debugtop +
			defaultvalue +
			permissiontop +
			msgtop +
			valuetext +
			msgbottom +
			permissionbottom +
			debugbottom +
			after
	} else {
		returnvalue := ""
		if interfacefn == "" {
			if returntype != "void" {
				returnvalue += "\n      return "
			}
			returnvalue += pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");"
		} else if fnc.async {
			resolve := ""
			switch lang.name {
			case "csharp":
				resolve = "fn(" + strings.Join(listargname, ", ") + ")"
			case "java":
				resolve = "fn.resolve(" + strings.Join(listargname, ", ") + ")"
			}
			returnvalue += "" +
				"\n      " + lang.future + "<T> output;" +
				"\n      if (fn == null) {" +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_new_completed(" + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1));" +
				"\n      } else {" +
				LangVar(lang, "future", anytype, emptytype, resolve, 4, false, true) +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future);" +
				"\n      }" +
				"\n      return output;"
		} else {
			resolve := ""
			switch lang.name {
			case "csharp":
				resolve = "fn(" + strings.Join(listargname, ", ") + ")"
			case "java":
				resolve = "fn.resolve(" + strings.Join(listargname, ", ") + ")"
			}
			if BooleanFromStringStarts(fnc.name, "boolean<-") {
				returnvalue += "" +
					LangVar(lang, "output", booleantype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"c_false", 3, false, false) +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, emptytype, resolve, 4, false, false) +
					"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameTFromType(lang, booleantype) + ", anyoutput);" +
					"\n      }"
			} else if BooleanFromStringStarts(fnc.name, "int<-") {
				returnvalue += "" +
					LangVar(lang, "output", inttype, emptytype, LangNameEFromType(lang, inttype), 3, false, false) +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, emptytype, resolve, 4, false, false) +
					"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, anyoutput);" +
					"\n      }"
			} else if BooleanFromStringStarts(fnc.name, "string<-") {
				returnvalue += "" +
					LangVar(lang, "output", stringtype, emptytype, LangNameEFromType(lang, stringtype), 3, false, false) +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, emptytype, resolve, 4, false, false) +
					"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, anyoutput);" +
					"\n      }"
			} else {
				returnvalue += "" +
					"\n      T output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1);" +
					"\n      if (fn != null) {" +
					LangVar(lang, "anyoutput", anytype, emptytype, resolve, 4, false, false) +
					"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(generic_any_1, anyoutput);" +
					"\n      }"
			}
			if returntype != "void" {
				returnvalue += "\n      return output;"
			}
		}
		override1, override2 := LangOverride(lang, 2, true)
		output = "" +
			override1 +
			"\n    public " + override2 + genericdefinition1 + functypetext + " vx_" + funcname + genericdefinition2 + "(" + strings.Join(listargtype, ", ") + ")" + genericdefinition3 + " {" +
			returnvalue +
			"\n    }" +
			"\n" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func LangVxFloatFromString(lang *vxlang, text string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "float.Parse(" + text + ")"
	case "java":
		output = "Float.parseFloat(" + text + ")"
	}
	return output
}

func LangVxFnNewFromFunc(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	output := ""
	ifn := ""
	vars := ""
	body := ""
	funcs := ""
	vxreturntype := LangNameFuncFullFromFunc(lang, fnc)
	classname := LangNameClassFromFunc(lang, fnc)
	contextname := ""
	if fnc.context {
		contextname = "-context"
	}
	asyncname := ""
	if fnc.async {
		asyncname = "-async"
	}
	override := ""
	if !isinterface {
		switch lang.name {
		case "java":
			override = "\n    @Override"
		}
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
			vars += "" +
				LangVarProp(lang, "fn", rawifntype, emptytype, "null", 2, false) +
				"\n"
			body = "" +
				"\n      " + classname + " output = new " + classname + "()" + lang.lineend +
				"\n      output.fn = fn" + lang.lineend +
				"\n      return output" + lang.lineend
		}
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		ifn = LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_func" + lang.typeref + "IFn" + snullable
		if !isinterface {
			vars += "" +
				"\n    public " + ifn + " fn = null" + lang.lineend +
				"\n"
			body = "" +
				"\n      " + classname + " output = new " + classname + "()" + lang.lineend +
				"\n      output.fn = fn" + lang.lineend +
				"\n      return output" + lang.lineend
		}
	default:
		returntype := ""
		if fnc.generictype == nil {
			returntype = LangGenericFromType(lang, fnc.vxtype)
		} else {
			returntype = LangGenericFromType(lang, fnc.generictype)
		}
		switch returntype {
		case "void":
		default:
			switch len(fnc.listarg) {
			case 1:
				argtypename := ""
				arg := fnc.listarg[0]
				argtypename = LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
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
						arginputnames = LangNameTFromTypeSimple(lang, fnc.vxtype, true) + ", " + arginputnames
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
							"\n      T inputval = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(generic_any_1, value);" +
							"\n      " + lang.future + "<T> output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_async(generic_any_1, inputval);"
					} else {
						suppresswarnings := ""
						switch lang.name {
						case "java":
							suppresswarnings = "\n      @SuppressWarnings(\"unchecked\")"
						}
						vxasyncanyfromany := ""
						switch lang.name {
						case "csharp":
							vxasyncanyfromany = LangNameFromPkgNameDot(lang, "vx/core") + "vx_async_from_async(generic_any_1, future)"
						case "java":
							vxasyncanyfromany = "(" + lang.future + "<T>)future"
						}
						asyncbody += "" +
							"\n      " + LangNameTypeFromType(lang, arg.vxtype) + " inputval = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameTFromType(lang, arg.vxtype) + ", value);" +
							"\n      " + lang.future + "<" + LangNameTypeFromType(lang, fnc.vxtype) + "> future = " + LangNameFFromFunc(lang, fnc) + "(" + arginputnames + ")" + lang.lineend +
							suppresswarnings +
							"\n      " + lang.future + "<T> output = " + vxasyncanyfromany + lang.lineend
					}
					funcs += "" +
						LangFuncHeader(lang, LangNameFFromFunc(lang, fnc), funcvxanyfromany, false, false) +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					funcs = "" +
						LangFuncHeader(lang, LangNameFFromFunc(lang, fnc), funcvxanyfromany, false, false) +
						"\n      T output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1);" +
						"\n      " + argtypename + " inputval = (" + argtypename + ")value;" +
						"\n      " + LangNameTypeFromType(lang, anytype) + " outputval = " + LangNameFFromFunc(lang, fnc) + "(" + arginputnames + ");" +
						"\n      output = " + LangNameFFromFunc(lang, funcanyfromany) + "(generic_any_1, " + argoutputnames + ");" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				}
			}
		}
	}
	if ifn != "" {
		header := "\n    public " + vxreturntype + " vx_fn_new(" + ifn + " fn)"
		if isinterface {
			output += "" +
				header + lang.lineend
		} else {
			output += "" +
				vars +
				override +
				header + " {" +
				body +
				"\n    }" +
				"\n" +
				funcs
		}
	}
	return output
}

func LangVxFuncdefFromFunc(lang *vxlang, fnc *vxfunc) string {
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	output := "" +
		override +
		"\n    public " + LangNameTypeFromType(lang, funcdeftype) + " vx_funcdef() {" +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        " + LangTypeDefFromType(lang, fnc.vxtype, "        ") + " // typedef" +
		"\n      );" +
		"\n    }" +
		"\n"
	return output
}

func LangVxIntFromString(lang *vxlang, text string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "Int32.Parse(" + text + ")"
	case "java":
		output = "Integer.parseInt(" + text + ")"
	}
	return output
}

func LangVxListFromType(lang *vxlang, typ *vxtype, body string) string {
	funcvxlist := NewFunc()
	funcvxlist.name = "vx_list"
	funcvxlist.vxtype = rawlistanytype
	funcvxlist.isimplement = true
	prefix := LangNameTypeFromType(lang, typ)
	output := "" +
		LangFuncHeader(lang, prefix, funcvxlist, false, false) +
		body +
		"\n    }" +
		"\n"
	return output
}

func LangVxListAdd(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Add(" + value + ")"
	case "java":
		output = varname + ".add(" + value + ")"
	}
	return output
}

func LangVxListAddList(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".AddRange(" + value + ")"
	case "java":
		output = varname + ".addAll(" + value + ")"
	}
	return output
}

func LangVxListGet(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + "[" + value + "]"
	case "java":
		output = varname + ".get(" + value + ")"
	}
	return output
}

func LangVxListSize(lang *vxlang, varname string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Count"
	case "java":
		output = varname + ".size()"
	}
	return output
}

func LangVxMapFromStruct(lang *vxlang, typ *vxtype) string {
	output := ""
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	vx_map := ""
	props := ListPropertyTraitFromType(typ)
	for _, arg := range props {
		argname := LangFromName(arg.name)
		vx_map += "\n      output.put(\":" + arg.name + "\", this." + argname + "());"
	}
	output += "" +
		override +
		"\n    public " + LangNameTypeFromType(lang, rawmapanytype) + " vx_map() {" +
		LangVar(lang, "output", rawmaptype, anytype, LangVxNewMap(lang, anytype, ""), 3, false, false) +
		vx_map +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(output);" +
		"\n    }" +
		"\n"
	return output
}

func LangVxMapFromType(lang *vxlang, typ *vxtype) string {
	funcvxmap := NewFunc()
	funcvxmap.name = "vx_map"
	funcvxmap.vxtype = rawmapanytype
	funcvxmap.isimplement = true
	copymap := ""
	switch lang.name {
	case "csharp":
		convertmap := ""
		if typ.name == "any" {
			convertmap = "this.vx_p_map"
		} else {
			convertmap = LangNameFromPkgNameDot(lang, "vx/core") + "vx_map_from_map<" + LangNameTypeFromType(lang, anytype) + ", " + LangNameTypeFromType(lang, typ) + ">(this.vx_p_map)"
		}
		copymap = "" +
			LangVar(lang, "anymap", rawmaptype, anytype, convertmap, 3, false, false) +
			LangVar(lang, "map", rawmaptype, anytype, "anymap.copy()", 3, false, false)
	case "java":
		copymap = "" +
			LangVar(lang, "map", rawmaptype, anytype, LangVxNewMap(lang, anytype, "this.vx_p_map"), 3, false, false)
	}
	prefix := LangNameTypeFromType(lang, typ)
	output := "" +
		LangFuncHeader(lang, prefix, funcvxmap, false, false) +
		copymap +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(map)" + lang.lineend +
		"\n    }" +
		"\n"
	return output
}

func LangVxMsgblockFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	override1 := ""
	override2 := ""
	switch lang.name {
	case "csharp":
		override2 = "new "
	case "java":
		override1 = "\n    @Override"
	}
	switch NameFromType(typ) {
	case "vx/core/msg":
		output = "" +
			override1 +
			"\n    public " + override2 + LangNameTypeFromType(lang, msgblocktype) + " vx_msgblock() {" +
			"\n      return " + LangNameEFromType(lang, msgblocktype) + lang.lineend +
			"\n    }" +
			"\n"
	case "vx/core/msgblock":
		output = "" +
			override1 +
			"\n    public " + override2 + LangNameTypeFromType(lang, msgblocktype) + " vx_msgblock() {" +
			"\n      return this" + lang.lineend +
			"\n    }" +
			"\n"
	}
	return output
}

func LangVxNewFromFunc(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	returntype := NewTypeFromFunc(fnc)
	funcvxnew := LangFuncVxNew(returntype)
	funcname := LangNameFromFunc(fnc)
	funcprefix := LangNameFromFunc(fnc)
	output := "" +
		LangFuncHeader(lang, funcprefix, funcvxnew, false, false) +
		"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
		"\n      return output;" +
		"\n    }" +
		"\n"
	return output
}

func LangVxNewFromMap(lang *vxlang, typ *vxtype) string {
	output := ""
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
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
	switch lang.name {
	case "csharp":
		keyset = "\n      List<string> keys = mapval.keys();"
	case "java":
		keyset = "\n      Set<String> keys = mapval.keySet();"
	}
	output += "" +
		override +
		"\n    public " + LangNameTypeFromType(lang, maptype) + " vx_new_from_map(" + LangFinalArg(lang) + LangNameTypeFromType(lang, rawmapanytype) + " mapval) {" +
		"\n      " + LangNameClassFullFromType(lang, typ) + " output = new " + LangNameClassFullFromType(lang, typ) + "();" +
		LangVar(lang, "msgblock", msgblocktype, emptytype, LangNameEFromType(lang, msgblocktype), 3, false, false) +
		LangVar(lang, "map", rawmaptype, allowtype, LangVxNewMap(lang, allowtype, ""), 3, false, false) +
		keyset +
		LangForListHeader(lang, "key", rawstringtype, "keys", 3) +
		LangVar(lang, "val", anytype, emptytype, "mapval.get(key)", 4, false, false) +
		"\n        if (false) {" +
		LangElseIfType(lang, allowtype, emptytype, "val", "castval", 4, false) +
		"\n          map.put(key, castval);" +
		"\n        } else {" +
		LangVar(lang, "msg", msgtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\""+typepath+"\", \":invalidvalue\", val)", 5, false, false) +
		"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
		"\n        }" +
		"\n      }" +
		"\n      output.vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(map);" +
		"\n      if (msgblock != " + LangNameEFromType(lang, msgblocktype) + ") {" +
		"\n        output.vxmsgblock = msgblock;" +
		"\n      }" +
		"\n      return output;" +
		"\n    }" +
		"\n"
	return output
}

func LangVxNewFromType(lang *vxlang, typ *vxtype, isinterface bool) string {
	funcvxnew := LangFuncVxNew(typ)
	typename := LangNameFromType(lang, typ)
	output := "" +
		LangFuncHeader(lang, typename, funcvxnew, false, false) +
		LangVar(lang, "output", typ, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_copy("+LangNameEFromType(lang, typ)+", vals)", 3, false, false) +
		"\n      return output" + lang.lineend +
		"\n    }" +
		"\n"
	return output
}

func LangVxNewList(lang *vxlang, typ *vxtype, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "new List<" + LangNameTypeFromType(lang, typ) + ">(" + value + ")"
	case "java":
		output = "new ArrayList<" + LangNameTypeFromType(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVxNewMap(lang *vxlang, typ *vxtype, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "new Vx.Core.LinkedHashMap<string, " + LangNameTypeFromType(lang, typ) + ">(" + value + ")"
	case "java":
		output = "new LinkedHashMap<String, " + LangNameTypeFromType(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVxSetFromType(lang *vxlang, typ *vxtype) string {
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
	prefix := LangNameTypeFromType(lang, typ)
	allowtype := anytype
	allowname := "any"
	allowtypes := ListAllowTypeFromType(typ)
	allowempty := LangNameEFromType(lang, anytype)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowempty = LangNameEFromType(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
	}
	if allowname == "any" {
		allowname = ""
	}
	body := "" +
		LangVar(lang, "output", booleantype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"c_false", 3, false, false) +
		"\n      if (false) {" +
		LangElseIfType(lang, allowtype, emptytype, "value", "castval", 3, false) +
		"\n        " + LangNameTypeFromType(lang, rawstringtype) + " key = name.vx_string();" +
		"\n        if (" + LangVxStartswith(lang, "key", "\":\"") + ") {" +
		"\n          key = " + LangVxSubstring(lang, "key", "1", "") + lang.lineend +
		"\n        }" +
		LangVar(lang, "map", rawmaptype, allowtype, LangVxNewMap(lang, allowtype, "this.vx_p_map"), 4, false, false) +
		"\n        if (castval == " + allowempty + ") {" +
		"\n          map.remove(key);" +
		"\n        } else {" +
		"\n          map.put(key, castval);" +
		"\n        }" +
		"\n        this.vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(map);" +
		"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "c_true;" +
		"\n      }" +
		"\n      return output;"
	output := "" +
		LangFuncHeader(lang, prefix, funcvxmap, false, false) +
		body +
		"\n    }" +
		"\n"
	return output
}

func LangVxStartswith(lang *vxlang, varname string, starts string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".StartsWith(" + starts + ")"
	case "java":
		output = varname + ".startsWith(" + starts + ")"
	}
	return output
}

func LangVxSubstring(lang *vxlang, varname string, from string, to string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	case "java":
		output = varname + ".substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	}
	return output
}

func LangVxToString(lang *vxlang, varname string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "Vx.Core.vx_string_from_object(" + varname + ")"
	case "java":
		output = varname + ".toString()"
	}
	return output
}

func LangVxTypedefFromFunc(lang *vxlang, fnc *vxfunc) string {
	override1 := ""
	override2 := ""
	switch lang.name {
	case "csharp":
		override2 = "override "
	case "java":
		override1 = "\n    @Override"
	}
	output := "" +
		override1 +
		"\n    public " + override2 + LangNameTypeFromType(lang, typedeftype) + " vx_typedef() {" +
		"\n      return " + LangNameTFromType(lang, functype) + lang.typeref + "vx_typedef();" +
		"\n    }" +
		"\n"
	return output
}

func LangApp(lang *vxlang, project *vxproject, cmd *vxcommand) string {
	indent0 := LangIndent(lang, 0, true)
	indent1 := LangIndent(lang, 1, true)
	indent2 := LangIndent(lang, 2, true)
	indent3 := LangIndent(lang, 3, true)
	imports := ""
	imports = LangImport(lang, project, "vx/core", imports)
	contexttext := LangVar(lang, "context", contexttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"f_context_main(arglist)", 3, true, false)
	maintext := "" +
		LangVar(lang, "mainval", stringtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"f_main(arglist)", 3, true, false) +
		LangVarSet(lang, "output", "mainval.vx_string()", 3)
	if cmd.context == "" && cmd.main == "" {
	} else {
		contextfunc := FuncFromProjectFuncname(project, cmd.context)
		mainfunc := FuncFromProjectFuncname(project, cmd.main)
		if cmd.context != "" && contextfunc == emptyfunc {
			MsgLog("Error! Context Not Found: (project (cmd :context " + cmd.context + "))")
		}
		if cmd.main != "" && mainfunc == emptyfunc {
			MsgLog("Error! Main Not Found: (project (cmd :main " + cmd.main + "))")
		}
		if contextfunc != emptyfunc {
			if contextfunc.pkgname == "" {
			} else if contextfunc.pkgname != mainfunc.pkgname {
				imports += LangImport(lang, project, contextfunc.pkgname, imports)
			}
			if contextfunc.async {
				contexttext = "" +
					LangVar(lang, "asynccontext", contexttype, emptytype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, true) +
					LangVar(lang, "context", contexttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async(vx_core::t_context, asynccontext)", 3, true, false)
			} else {
				contexttext = LangVar(lang, "context", contexttype, emptytype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, false)
			}
		}
		if mainfunc != emptyfunc {
			if mainfunc.pkgname != "" {
				imports += LangImport(lang, project, mainfunc.pkgname, imports)
			}
			params := "arglist"
			if mainfunc.context {
				params = "context, arglist"
			}
			mainfunctext := LangNameFFromFunc(lang, mainfunc) + "(" + params + ")"
			if mainfunc.async {
				maintext = "" +
					LangVar(lang, "asyncstring", stringtype, emptytype, mainfunctext, 3, true, true) +
					LangVar(lang, "mainstring", stringtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameFromPkgNameDot(lang, "vx/core")+"t_string, asyncstring)", 3, true, false)
			} else {
				maintext = LangVar(lang, "mainstring", stringtype, emptytype, mainfunctext, 3, true, false)
			}
		}
	}
	packageopen := ""
	classopen := ""
	classclose := ""
	mainopen := ""
	mainclose := ""
	tryopen := ""
	tryclose := ""
	outputopen := ""
	outputclose := ""
	outputprint := ""
	arglistinit := ""
	outputopen = LangVar(lang, "output", rawstringtype, emptytype, "\"\"", 3, false, false)
	outputclose = LangVarSet(lang, "output", "mainstring.vx_string()", 3)
	switch lang.name {
	case "csharp":
		classopen = indent0 + "class App {\n"
		classclose = indent0 + "}\n"
		mainopen = indent1 + "static void Main(string[] args) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.Console.WriteLine(\"Untrapped Error!\" + e.ToString());" +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", anylisttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)", 3, true, false)
		outputprint = indent3 + "System.Console.WriteLine(output);"
	case "java":
		classopen = indent0 + "public final class App {\n"
		classclose = indent0 + "}\n"
		mainopen = indent1 + "public static void main(String[] args) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.out.println(\"Untrapped Error!\" + e.toString());" +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", anylisttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)", 3, true, false)
		outputprint = indent3 + "System.out.println(output);"
	case "kotlin":
		packageopen = indent0 + "package App\n"
		mainopen = indent1 + "fun main(args : Array<String>) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (e : Exception) {" +
			indent3 + "println(e.toString())" +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", listtype, anytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)", 3, true, false)
		outputprint = indent3 + "println(output)"
	}
	output := `/**
 * App
 */
` +
		imports +
		packageopen +
		classopen +
		mainopen +
		tryopen +
		outputopen +
		arglistinit +
		contexttext +
		maintext +
		outputclose +
		outputprint +
		tryclose +
		mainclose +
		classclose
	return output
}

func LangAppTest(lang *vxlang, project *vxproject, command *vxcommand, pkgprefix string) string {
	imports := ""
	imports += LangImport(lang, project, "vx/core", imports)
	contexttext := LangVarStatic(lang, "arglist", anylisttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"e_anylist", 1, false, false)
	if command.context == "" {
		contexttext += "" +
			LangVarStatic(lang, "context", contexttype, emptytype, pkgprefix+LangNameFromPkgNameDot(lang, "vx/test")+"f_context_test(arglist)", 2, false, false)
	} else {
		contextfunc := FuncFromProjectFuncname(project, command.context)
		if command.context != "" && contextfunc == emptyfunc {
			MsgLog("Error! Context Not Found: (project (cmd :context " + command.context + "))")
		}
		if contextfunc != emptyfunc {
			switch contextfunc.pkgname {
			case "vx/test":
			default:
				imports += LangImport(lang, project, contextfunc.pkgname, imports)
			}
			//libprefix := ""
			//switch lang.name {
			//case "java", "kotlin":
			//	libprefix = project.javadomain + "."
			//}
			//			pkgname := contextfunc.pkgname
			//			pkgpath := ""
			//			pos := strings.LastIndex(pkgname, "/")
			//			if pos >= 0 {
			//				pkgpath = pkgname[0:pos]
			//				pkgpath = libprefix + StringFromStringFindReplace(pkgpath, "/", ".")
			//			}
			if contextfunc.async {
				contexttext += "" +
					LangVarStatic(lang, "asynccontext", contexttype, emptytype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 1, false, true) +
					LangVarStatic(lang, "context", contexttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async(vx_core.t_context, asynccontext)", 1, false, false)
			} else {
				contexttext += "" +
					LangVarStatic(lang, "context", contexttype, emptytype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 1, false, false)
			}
		}
	}
	tests := ""
	listpackage := project.listpackage
	testpackageprefix := ""
	switch lang.name {
	case "csharp":
		testpackageprefix = "Test"
	}
	var listtestpackage []string
	for _, pkg := range listpackage {
		iscontinue := true
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			if pkg.name != "" {
				imports += LangImportTest(lang, project, pkg.name, imports)
				testpackage := "\n      " + testpackageprefix + LangNameFromPkgName(lang, pkg.name) + "Test.test_package(context)"
				listtestpackage = append(listtestpackage, testpackage)
				switch lang.name {
				case "csharp":
					tests += "" +
						"\n  [Fact]" +
						"\n  public void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
						LangVar(lang, "testpackage", testpackagetype, emptytype, "Test"+LangNameFromPkgName(lang, pkg.name)+"Test.test_package(context)", 2, false, false) +
						"\n    TestLib.run_testpackage_async(testpackage);" +
						"\n  }" +
						"\n"
				case "java":
					tests += "" +
						"\n  @Test" +
						"\n  @DisplayName(\"" + pkg.name + "\")" +
						"\n  void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
						"\n    com.vxlisp.vx.Test.Type_testpackage testpackage = " + LangNameFromPkgName(lang, pkg.name) + "Test.test_package(context);" +
						"\n    TestLib.run_testpackage_async(testpackage);" +
						"\n  }" +
						"\n"
				}
			}
		}
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "AppTest")
	writetestsuite := ""
	switch lang.name {
	case "csharp":
		namespaceopen = "" +
			"\n" +
			"\nnamespace AppTest;" +
			"\n" +
			"\npublic class AppTest {" +
			"\n"
		namespaceclose = "" +
			"\n}" +
			"\n"
		testpackagedata := "" +
			LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangNameTFromType(lang, testpackagelisttype) + "," +
			testpackages +
			"\n    )"
		writetestsuite = "" +
			"\n  [Fact]" +
			"\n  public void test_writetestsuite() {" +
			LangVar(lang, "testpackagelist", testpackagelisttype, emptytype, testpackagedata, 2, false, false) +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist);" +
			"\n  }" +
			"\n"
	case "java":
		imports += "" +
			"\nimport org.junit.jupiter.api.DisplayName;" +
			"\nimport org.junit.jupiter.api.Test;"
		writetestsuite = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"writetestsuite\")" +
			"\n  void test_writetestsuite() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      com.vxlisp.vx.Test.t_testpackagelist," +
			testpackages +
			"\n    );" +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist);" +
			"\n  }"
	}
	output := "" +
		"/**" +
		"\n * Unit test for whole App." +
		"\n */" +
		"\n" +
		imports +
		"\n" +
		namespaceopen +
		contexttext +
		"\n" +
		tests +
		writetestsuite +
		namespaceclose
	return output
}

func LangTestLib(lang *vxlang) string {
	output := ""
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "TestLib")
	switch lang.name {
	case "csharp":
		output = "" +
			"\nusing Xunit;" +
			"\n" +
			"\nnamespace AppTest;" +
			"\n" +
			namespaceopen +
			LangTestLib_run_testcase(lang) +
			LangTestLib_run_testcaselist(lang) +
			LangTestLib_run_testdescribe(lang) +
			LangTestLib_run_testdescribelist(lang) +
			LangTestLib_run_testpackage(lang) +
			LangTestLib_run_testpackage_async(lang) +
			LangTestLib_run_testresult(lang) +
			LangTestLib_write_testpackagelist_async(lang) +
			namespaceclose
	case "java":
		output = `
import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;
` +
			namespaceopen +
			LangTestLib_run_testcase(lang) + `
  // Blocking
  // Only use if running a single testcase
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testcase_async(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> async_testcase = Test.f_resolve_testcase(testcase);
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_any work = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testcase, async_testcase);
    Test.Type_testcase testcase_resolved = (Test.Type_testcase)work;
    return run_testcase(testcase_resolved);
  }
` +
			LangTestLib_run_testcaselist(lang) +
			LangTestLib_run_testdescribe(lang) +
			`
  // Blocking
  // Only use if running a single testdescribe
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testdescribe_async(final ` + LangNameTypeFromType(lang, rawstringtype) + ` testpkg, final ` + LangNameTypeFromType(lang, rawstringtype) + ` casename, final Test.Type_testdescribe testdescribe) {
    ` + lang.future + `<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }
` +
			LangTestLib_run_testdescribelist(lang) +
			LangTestLib_run_testpackage(lang) + `

  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    ` + LangNameTypeFromType(lang, rawbooltype) + ` output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
      ` + LangNameTypeFromType(lang, rawbooltype) + ` testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }
` + LangTestLib_run_testpackage_async(lang) + `

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

		` + LangTestLib_run_testresult(lang) + `

  // Blocking
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testresult_async(final ` + LangNameTypeFromType(lang, rawstringtype) + ` testpkg, final ` + LangNameTypeFromType(lang, rawstringtype) + ` testname, final ` + LangNameTypeFromType(lang, rawstringtype) + ` message, Test.Type_testresult testresult) {
    ` + lang.future + `<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }
` + LangTestLib_write_testpackagelist_async(lang) +
			namespaceclose
	}
	return output
}

func LangTestLib_run_testcase(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testcase"
	fnc.vxtype = rawbooltype
	arg := NewArg("testcase")
	arg.vxtype = testcasetype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testpkg", rawstringtype, emptytype, "testcase.testpkg().vx_string()", 2, false, false) +
		LangVar(lang, "casename", rawstringtype, emptytype, "testcase.casename().vx_string()", 2, false, false) +
		LangVar(lang, "testdescribelist", testdescribelisttype, emptytype, "testcase.describelist()", 2, false, false) +
		LangVar(lang, "output", rawbooleantype, emptytype, "run_testdescribelist(testpkg, casename, testdescribelist)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testcaselist(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testcaselist"
	fnc.vxtype = rawbooltype
	arg := NewArg("testcaselist")
	arg.vxtype = testcaselisttype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "listtestcase", rawlisttype, testcasetype, "testcaselist.vx_listtestcase()", 2, false, false) +
		LangForListHeader(lang, "testcase", testcasetype, "listtestcase", 2) +
		"\n      run_testcase(testcase)" + lang.lineend +
		"\n    }" +
		"\n    return true;" +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testdescribe(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testdescribe"
	fnc.vxtype = rawbooltype
	arg := NewArg("testpkg")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("casename")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("describe")
	arg.vxtype = testdescribetype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testcode", stringtype, emptytype, "describe.describename()", 2, false, false) +
		LangVar(lang, "message", rawstringtype, emptytype, "testcode.vx_string()", 2, false, false) +
		LangVar(lang, "testresult", testresulttype, emptytype, "describe.testresult()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testresult(testpkg, casename, message, testresult)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testdescribelist(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testdescribelist"
	fnc.vxtype = rawbooltype
	arg := NewArg("testpkg")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("casename")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("testdescribelist")
	arg.vxtype = testdescribelisttype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "output", rawbooltype, emptytype, "true", 2, false, false) +
		LangVar(lang, "listtestdescribe", rawlisttype, testdescribetype, "testdescribelist.vx_listtestdescribe()", 2, false, false) +
		LangForListHeader(lang, "testdescribe", testdescribetype, "listtestdescribe", 2) +
		LangVar(lang, "testoutput", rawbooltype, emptytype, "run_testdescribe(testpkg, casename, testdescribe)", 3, false, false) +
		"\n 	    if (!testoutput) {" +
		"\n   			  output = false" + lang.lineend +
		"\n      }" +
		"\n    }" +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testpackage(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testpackage"
	fnc.vxtype = rawbooltype
	arg := NewArg("testpackage")
	arg.vxtype = testpackagetype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testcaselist", testcaselisttype, emptytype, "testpackage.caselist()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testcaselist(testcaselist)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testpackage_async(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testpackage_async"
	fnc.vxtype = rawbooltype
	arg := NewArg("testpackage")
	arg.vxtype = testpackagetype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		"\n  // Blocking" +
		"\n  // This is the preferred way of calling test (1 block per package)" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "async_testpackage", testpackagetype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_resolve_testpackage(testpackage)", 2, false, true) +
		LangVar(lang, "testpackage_resolved", testpackagetype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, testpackagetype)+", async_testpackage)", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testpackage(testpackage_resolved)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_run_testresult(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testresult"
	fnc.vxtype = rawbooltype
	arg := NewArg("testpkg")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("testname")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("message")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("testresult")
	arg.vxtype = testresulttype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	assertequals := ""
	assertnotequals := ""
	println := ""
	switch lang.name {
	case "csharp":
		assertequals = "\n  				Assert.Equal(expected, actual)" + lang.lineend
		assertnotequals = "\n	  			Assert.NotEqual(expected, actual)" + lang.lineend
		println = "System.Console.WriteLine"
	case "java":
		assertequals = "\n  				assertEquals(expected, actual, msg)" + lang.lineend
		assertnotequals = "\n	  			assertNotEquals(expected, actual, msg)" + lang.lineend
		println = "System.out.println"
	}
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "valexpected", anytype, emptytype, "testresult.expected()", 2, false, false) +
		LangVar(lang, "valactual", anytype, emptytype, "testresult.actual()", 2, false, false) +
		LangVar(lang, "passfail", rawbooltype, emptytype, "testresult.passfail().vx_boolean()", 2, false, false) +
		LangVar(lang, "code", rawstringtype, emptytype, "testresult.code().vx_string()", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"f_string_from_any(valexpected).vx_string()", 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"f_string_from_any(valactual).vx_string()", 2, false, false) +
		LangVar(lang, "msg", rawstringtype, emptytype, "testpkg + \"/\" + testname + \" \" + message", 2, false, false) +
		"\n  		if (!passfail) {" +
		"\n  				" + println + "(msg)" + lang.lineend +
		"\n  				" + println + "(expected)" + lang.lineend +
		"\n  				" + println + "(actual)" + lang.lineend +
		"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "f_log(testresult)" + lang.lineend +
		"\n		  }" +
		"\n  		switch (code) {" +
		"\n		  case \":ne\":" +
		assertnotequals +
		"\n  				break" + lang.lineend +
		"\n  		default:" +
		assertequals +
		"\n  				break" + lang.lineend +
		"\n  		}" +
		"\n  		return true" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_write_testpackagelist_async(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "write_testpackagelist_async"
	fnc.vxtype = rawbooltype
	argcontext := NewArg("context")
	argcontext.vxtype = contexttype
	argcontext.isfinal = true
	fnc.listarg = append(fnc.listarg, argcontext)
	arg := NewArg("testpackagelist")
	arg.vxtype = testpackagelisttype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		"\n  // Blocking" +
		"\n  // This is the preferred way of writing testsuite (1 block per testsuite)" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "output", rawbooltype, emptytype, "false", 2, false, false) +
		LangVar(lang, "async_testpackagelist", testpackagelisttype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_resolve_testpackagelist(testpackagelist)", 2, false, true) +
		LangVar(lang, "testpackagelist_resolved", testpackagelisttype, emptytype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, testpackagelisttype)+", async_testpackagelist)", 2, false, false) +
		LangVar(lang, "filetest", filetype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_file_test()", 2, false, false) +
		LangVar(lang, "valboolean", booleantype, emptytype, LangNameFromPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved)", 2, false, false) +
		LangVarSet(lang, "output", "valboolean.vx_boolean()", 2) +
		LangVar(lang, "divtest", htmldivtype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_div_from_testpackagelist(testpackagelist_resolved)", 2, false, false) +
		LangVar(lang, "htmlnode", htmltype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_html_from_divtest(divtest)", 2, false, false) +
		LangVar(lang, "filenode", filetype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_file_testnode()", 2, false, false) +
		LangVarSet(lang, "valboolean", LangNameFromPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filenode, htmlnode)", 2) +
		LangVarSet(lang, "output", "output && valboolean.vx_boolean()", 2) +
		LangVar(lang, "filehtml", filetype, emptytype, LangNameFromPkgNameDot(lang, "vx/test")+"f_file_testhtml()", 2, false, false) +
		LangVar(lang, "shtml", stringtype, emptytype, LangNameFromPkgNameDot(lang, "vx/web/html")+"f_string_from_html(htmlnode)", 2, false, false) +
		LangVarSet(lang, "valboolean", LangNameFromPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_string(context, filehtml, shtml)", 2) +
		LangVarSet(lang, "output", "output && valboolean.vx_boolean()", 2) +
		"\n			 return output;" +
		"\n  }" +
		"\n"
	return output
}
