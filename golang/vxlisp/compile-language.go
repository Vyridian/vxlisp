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
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
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
	switch typ {
	case rawlisttype:
		switch lang.name {
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
		output = svar + " as " + stype
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
		output = lineindent + "public class " + constname + " : " + extends + ", vx_core.vx_Type_const {"
	case "java":
		output = lineindent + "public static class " + constname + " extends " + extends + " implements Core.vx_Type_const {"
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
		output = lineindent + "public class Class_" + typename + " : vx_core.Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	case "java":
		output = lineindent + "public static class Class_" + typename + " extends " + LangNameFromPkgNameDot(lang, "vx/core") + "Class_base implements Type_" + LangNameFromType(lang, typ) + " {"
	case "kotlin":
		output = lineindent + "class Class_" + typename + " : vx_core.Class_base, Type_" + LangNameFromType(lang, typ) + " {"
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
	switch lang.name {
	case "csharp":
	case "java", "kotlin":
		pkgprefix = project.javadomain + "."
	}
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "App" + lang.sourcefile
		file.path = cmdpath
		file.text = LangApp(lang, project, command)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "AppTest" + lang.sourcefile
		file.path = cmdpath
		file.text = LangAppTest(lang, project, command, pkgprefix)
		files = append(files, file)
		file = NewFile()
		file.name = "TestLib" + lang.sourcefile
		file.path = cmdpath
		file.text = LangTestLib(lang)
		files = append(files, file)
	}
	pkgs := ListPackageFromProject(project)
	for _, pkg := range pkgs {
		subproject := pkg.project
		subprefix := ""
		switch lang.name {
		case "csharp":
		case "java", "kotlin":
			subprefix = subproject.javadomain + "/"
		}
		subdomainpath := StringFromStringFindReplace(subprefix, ".", "/")
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
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
			file.path = cmdpath + "/" + subdomainpath + pkgpath
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
	doc := ""
	override := LangOverride(lang)
	path := cnst.pkgname + "/" + cnst.name
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
		constvxboolean.isoverride = true
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
			LangFuncHeader(lang, LangNameFromConst(cnst), constvxboolean, false) +
			cnstval +
			"\n      return this.vxboolean;" +
			"\n    }"
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxdecimal = " + cnstval + ";"
		initval = "" +
			"\n    " + override +
			"\n    public String vx_decimal() {" +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      this.vxfloat = " + cnstval + ";"
		initval = "" +
			"\n    " + override +
			"\n    public float vx_float() {" +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxint = " + cnstval + ";"
		initval = "" +
			"\n    " + override +
			"\n    public int vx_int() {" +
			cnstval +
			"\n      return this.vxint;" +
			"\n    }"
	case "vx/core/string":
		if BooleanFromStringStartsEnds(cnstval, "\"", "\"") {
			cnstval = cnstval[1 : len(cnstval)-1]
			cnstval = LangFromText(cnstval)
			cnstval = "\"" + cnstval + "\""
		}
		cnstval = "\n      this.vxstring = " + cnstval + ";"
		initval = "" +
			"\n    " + override +
			"\n    public String vx_string() {" +
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
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vx_p_list = val.vx_list" + listtypename + "();"
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
		"\n" +
		"\n    " + override +
		"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_constdef vx_constdef() {" +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + LangTypeDefFromType(lang, cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
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
	override := LangOverride(lang)
	instancevars := ""
	staticvars := ""
	instancefuncs := ""
	staticfuncs := ""
	f_suppresswarnings := ""
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
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = LangGenericFromType(lang, fnc.generictype)
	} else {
		functypetext = returntype
	}
	if fnc.async {
		functypetext = lang.future + "<" + functypetext + ">"
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
		instancevars += "" +
			"\n    public IFn fn = null;" +
			"\n" +
			"\n    " + override +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_" + funcname + ".IFn fn) {" +
			"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/string<-func":
		instancefuncs += "" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_func.IFn fn = null;" +
			"\n" +
			"\n    " + override +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_func.IFn fn) {" +
			"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	default:
		switch returntype {
		case "void":
		default:
			switch len(fnc.listarg) {
			case 1:
				argtypename := ""
				arg := fnc.listarg[0]
				argtypename = LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
				subargnames := "inputval"
				contextname := ""
				if fnc.context {
					contextname = "_context"
					subargnames = "context, inputval"
				}
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						subargnames = LangNameTFromTypeSimple(lang, fnc.vxtype, true) + ", " + subargnames
					}
				}
				funcvxanyfromany := NewFunc()
				funcvxanyfromany.async = fnc.async
				funcvxanyfromany.context = fnc.context
				funcvxanyfromany.isgeneric = true
				funcvxanyfromany.generictype = anytype1
				funcvxanyfromany.vxtype = anytype1
				funcvxanyfromany.isoverride = true
				funcvxanyfromanyname := "vx_any_from_any"
				if fnc.context {
					funcvxanyfromanyname += "_context"
				}
				if fnc.async {
					funcvxanyfromanyname += "_async"
				}
				funcvxanyfromany.name = funcvxanyfromanyname
				argvxanyfromanyvalue := NewArg("value")
				argvxanyfromanyvalue.isgeneric = true
				argvxanyfromanyvalue.vxtype = anytype2
				listargsfuncvxanyfromany := NewListArg()
				listargsfuncvxanyfromany = append(listargsfuncvxanyfromany, argvxanyfromanyvalue)
				funcvxanyfromany.listarg = listargsfuncvxanyfromany
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
						asyncbody += "" +
							"\n      " + LangNameTypeFromType(lang, arg.vxtype) + " inputval = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameTFromType(lang, arg.vxtype) + ", value);" +
							"\n      " + lang.future + "<" + returntype + "> future = " + pkgname + ".f_" + funcname + "(" + subargnames + ");" +
							"\n      @SuppressWarnings(\"unchecked\")" +
							"\n      " + lang.future + "<T> output = (" + lang.future + "<T>)future;"
					}
					instancefuncs += "" +
						"\n    " + override +
						"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Func_any_from_any" + contextname + "_async vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_any" + contextname + "_async.IFn fn) {return " + LangNameFromPkgNameDot(lang, "vx/core") + "e_any_from_any" + contextname + "_async;}" +
						"\n" +
						LangFuncHeader(lang, LangNameFromFuncFull(lang, fnc), funcvxanyfromany, false) +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    " + override +
						"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Func_any_from_any" + contextname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_any" + contextname + ".IFn fn) {" +
						"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "e_any_from_any" + contextname + ";" +
						"\n    }" +
						"\n" +
						LangFuncHeader(lang, LangNameFromFuncFull(lang, fnc), funcvxanyfromany, false) +
						"\n      T output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1);" +
						"\n      " + argtypename + " inputval = (" + argtypename + ")value;" +
						"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any outputval = " + pkgname + ".f_" + funcname + "(" + subargnames + ");" +
						"\n      output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(generic_any_1, outputval);" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				}
			}
		}
	}
	repltext := LangReplFromFunc(lang, fnc)
	instancefuncs += repltext
	valuetext, msgs := LangFromValue(lang, fnc.value, fnc.pkgname, fnc, 0, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	valuetexts := ListStringFromStringSplit(valuetext, "\n")
	var chgvaluetexts []string
	for _, item := range valuetexts {
		if BooleanFromStringContains(item, "@SuppressWarnings") {
			f_suppresswarnings += "\n  " + StringTrim(StringFromStringFindReplace(item, "\\\"", "\""))
		} else {
			chgvaluetexts = append(chgvaluetexts, item)
		}
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
			LangVar(lang, "msg", msgtype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_msg_from_error(\"vx/core/func\", \":permissiondenied\", "+LangNameFromPkgNameDot(lang, "vx/core")+"vx_new_string(\""+fnc.name+"\"))", 3, true, false) +
			lineindent + "  output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(output, msg);" +
			lineindent + "}"
		subindent += "  "
	}
	linesubindent := "\n" + subindent
	if fnc.messages {
		msgtop = linesubindent + "try {"
		msgbottom = "" +
			linesubindent + "} catch (Exception err) {" +
			linesubindent + "  " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_exception(\"" + fnc.pkgname + "/" + fnc.name + "\", err);" +
			linesubindent + "  output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(output, msg);" +
			linesubindent + "}"
		subindent += "  "
	}
	linesubindent = "\n" + subindent
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
	interfacefn := LangInterfaceFnFromFunc(lang, fnc)
	debugtop, debugbottom := LangDebugFromFunc(lang, fnc, lineindent)
	switch NameFromFunc(fnc) {
	case "vx/core/new":
		f_suppresswarnings = "\n  @SuppressWarnings(\"unchecked\")"
	}
	returnvalue := ""
	if interfacefn == "" {
		if returntype != "void" {
			returnvalue += "\n      return "
		}
		returnvalue += pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");"
	} else if fnc.async {
		returnvalue += "" +
			"\n      " + lang.future + "<T> output;" +
			"\n      if (fn == null) {" +
			"\n        output = " + lang.future + ".completedFuture(" + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1));" +
			"\n      } else {" +
			"\n        " + lang.future + "<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> future = fn.resolve(" + strings.Join(listargname, ", ") + ");" +
			"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "async_from_async(generic_any_1, future);" +
			"\n      }" +
			"\n      return output;"
	} else {
		anyoutput := "\n        " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any anyoutput = fn.resolve(" + strings.Join(listargname, ", ") + ");"
		if BooleanFromStringStarts(fnc.name, "boolean<-") {
			returnvalue += "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_boolean output = " + LangNameFromPkgNameDot(lang, "vx/core") + "c_false;" +
				"\n      if (fn != null) {" +
				anyoutput +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, anyoutput);" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "int<-") {
			returnvalue += "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_int output = " + LangNameFromPkgNameDot(lang, "vx/core") + "e_int;" +
				"\n      if (fn != null) {" +
				anyoutput +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, anyoutput);" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "string<-") {
			returnvalue += "" +
				"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string output = " + LangNameFromPkgNameDot(lang, "vx/core") + "e_string;" +
				"\n      if (fn != null) {" +
				anyoutput +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, anyoutput);" +
				"\n      }"
		} else {
			returnvalue += "" +
				"\n      T output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(generic_any_1);" +
				"\n      if (fn != null) {" +
				anyoutput +
				"\n        output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(generic_any_1, anyoutput);" +
				"\n      }"
		}
		if returntype != "void" {
			returnvalue += "\n      return output;"
		}
	}
	after := ""
	if fnc.vxtype.name == "none" {
	} else {
		after += lineindent + "return output;"
	}
	after += "\n  }\n\n"
	defaultvalue := ""
	switch NameFromFunc(fnc) {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
	default:
		if fnc.vxtype.name == "none" {
		} else if fnc.async {
			defaultvalue = lineindent + lang.future + "<" + returntype + "> output = " + LangNameFromPkgNameDot(lang, "vx/core") + "async_new_completed(" + LangNameEFromType(lang, fnc.vxtype) + ");"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + " output = " + LangNameFromPkgNameDot(lang, "vx/core") + "f_empty(" + LangNameTFromTypeGeneric(lang, fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + " output = " + LangNameEFromType(lang, fnc.vxtype) + ";"
		}
	}
	interfacefunc := LangInterfaceFromFunc(lang, fnc)
	doc := LangDocFromFunc(fnc)
	output := "" +
		doc +
		interfacefunc +
		LangClassHeaderFromFunc(lang, fnc, 1) +
		"\n" +
		instancevars +
		LangVxNewFromFunc(lang, fnc, false) +
		LangVxCopyFromFunc(lang, fnc, false) +
		"\n    " + override +
		"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef() {return " + LangNameFromPkgNameDot(lang, "vx/core") + "t_func.vx_typedef();}" +
		"\n" +
		"\n    " + override +
		"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_funcdef vx_funcdef() {" +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        " + LangTypeDefFromType(lang, fnc.vxtype, "        ") + " // typedef" +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    " + override +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty() {" +
		"\n      return e_" + funcname + ";" +
		"\n    }" +
		"\n    " + override +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type() {" +
		"\n      return t_" + funcname + ";" +
		"\n    }" +
		"\n" +
		staticvars +
		interfacefn +
		instancefuncs +
		"\n    " + override +
		"\n    public " + genericdefinition1 + functypetext + " vx_" + funcname + genericdefinition2 + "(" + strings.Join(listargtype, ", ") + ")" + genericdefinition3 + " {" +
		staticfuncs +
		returnvalue +
		"\n    }" +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static " + LangFinalVar(lang) + "Func_" + funcname + " e_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n  public static " + LangFinalVar(lang) + "Func_" + funcname + " t_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n" +
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
		packageline = "namespace " + pkgpath + lang.lineend + "\n"
	case "java":
		packageline = "package " + pkgpath + lang.lineend + "\n"
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	packagestatic := "" +
		"\n    Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> maptype = new LinkedHashMap<>();" +
		"\n    Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> mapconst = new LinkedHashMap<>();" +
		"\n    Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_func> mapfunc = new LinkedHashMap<>();"
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
	doc := "" +
		"type: " + typ.name
	if typ.doc != "" {
		doc += "\n" + typ.doc
	}
	if typ.deprecated != "" {
		doc += "\n" + typ.deprecated
	}
	override := LangOverride(lang)
	typename := LangFromName(typ.alias)
	typepath := NameFromType(typ)
	instancefuncs := ""
	createtext, msgs := LangFromValue(lang, typ.createvalue, "", emptyfunc, 2, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	staticfuncs := ""
	valnew := ""
	valcopy := "" +
		"\n      boolean ischanged = false;" +
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
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_any work = new Class_any();" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
			"\n      boolean booleanval = val.vx_boolean();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", booleantype) + ") {" +
			"\n          " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_boolean valboolean = " + LangAsType(lang, "valsub", booleantype) + ";" +
			"\n          booleanval = booleanval || valboolean.vx_boolean();" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawbooleantype) + ") {" +
			"\n          booleanval = booleanval || " + LangAsType(lang, "valsub", rawbooleantype) + ";" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_boolean work = new Class_boolean();" +
			"\n        work.vxboolean = booleanval;" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
			"\n      String sval = val.vx_string();"
		valnew = "" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
			"\n          " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string valstring = " + LangAsType(lang, "valsub", stringtype) + ";" +
			"\n          ischanged = true;" +
			"\n          sval = valstring.vx_string();" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
			"\n          ischanged = true;" +
			"\n          sval = (String)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_decimal work = new Class_decimal();" +
			"\n        work.vxdecimal = sval;" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", decimaltype) + ") {" +
			LangVar(lang, "valnum", decimaltype, LangAsType(lang, "valsub", decimaltype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (" + LangIsType(lang, "valsub", floattype) + ") {" +
			LangVar(lang, "valnum", floattype, LangAsType(lang, "valsub", floattype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (" + LangIsType(lang, "valsub", inttype) + ") {" +
			LangVar(lang, "valnum", inttype, LangAsType(lang, "valsub", inttype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_int();" +
			"\n        } else if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
			LangVar(lang, "valstring", stringtype, LangAsType(lang, "valsub", stringtype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          floatval += Float.parseFloat(valstring.vx_string());" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawfloattype) + ") {" +
			"\n          ischanged = true;" +
			"\n          floatval += " + LangAsType(lang, "valsub", rawfloattype) + ";" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") {" +
			"\n          ischanged = true;" +
			"\n          floatval += " + LangAsType(lang, "valsub", rawintegertype) + ";" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
			"\n          ischanged = true;" +
			"\n          floatval += Float.parseFloat(" + LangAsType(lang, "valsub", rawstringtype) + ");" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_float work = new Class_float();" +
			"\n        work.vxfloat = floatval;" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
			"\n        } else if (" + LangIsType(lang, "valsub", inttype) + ") {" +
			LangVar(lang, "valnum", inttype, LangAsType(lang, "valsub", inttype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          intval += valnum.vx_int();" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") {" +
			"\n          ischanged = true;" +
			"\n          intval += " + LangAsType(lang, "valsub", rawintegertype) + ";" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
			LangVar(lang, "valstring", rawstringtype, LangAsType(lang, "valsub", rawstringtype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          intval += Integer.parseInt(valstring);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_int work = new Class_int();" +
			"\n        work.vxint = intval;" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy += "" +
			"\n      StringBuilder sb = new StringBuilder(val.vx_string());"
		valnew = "" +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
			LangVar(lang, "valstring", stringtype, LangAsType(lang, "valsub", stringtype), 5, false, false) +
			"\n          String ssub = valstring.vx_string();" +
			"\n          if (!ssub.equals(\"\")) {" +
			"\n            ischanged = true;" +
			"\n            sb.append(ssub);" +
			"\n          }" +
			"\n        } else if (" + LangIsType(lang, "valsub", inttype) + ") {" +
			LangVar(lang, "valint", inttype, LangAsType(lang, "valsub", inttype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          sb.append(valint.vx_int());" +
			"\n        } else if (" + LangIsType(lang, "valsub", floattype) + ") {" +
			LangVar(lang, "valfloat", floattype, LangAsType(lang, "valsub", floattype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          sb.append(valfloat.vx_float());" +
			"\n        } else if (" + LangIsType(lang, "valsub", decimaltype) + ") {" +
			LangVar(lang, "valdecimal", decimaltype, LangAsType(lang, "valsub", decimaltype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          sb.append(valdecimal.vx_string());" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
			LangVar(lang, "ssub2", rawstringtype, LangAsType(lang, "valsub", rawstringtype), 5, false, false) +
			"\n          if (!ssub2.equals(\"\")) {" +
			"\n            ischanged = true;" +
			"\n            sb.append(ssub2);" +
			"\n          }" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawintegertype) + ") {" +
			LangVar(lang, "ssub2", rawinttype, LangAsType(lang, "valsub", rawintegertype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          sb.append(ssub2);" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawfloattype) + ") {" +
			LangVar(lang, "ssub2", rawfloattype, LangAsType(lang, "valsub", rawfloattype), 5, false, false) +
			"\n          ischanged = true;" +
			"\n          sb.append(ssub2);" +
			"\n        } else if (" + LangIsType(lang, "valsub", anytype) + ") {" +
			LangVar(lang, "anysub", anytype, LangAsType(lang, "valsub", anytype), 5, false, false) +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anysub);" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        } else {" +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString()));" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        String vxstring = sb.toString();" +
			"\n        Class_string work = new Class_string();" +
			"\n        work.vxstring = vxstring;" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
		vxlistbody := "" +
			"\n      " + LangNameTypeFromType(lang, rawlistanytype) + " output = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(new ArrayList<" + LangNameTypeFromType(lang, anytype) + ">(this.vx_p_list));" +
			"\n      return output;"
		instancefuncs += "" +
			"\n    protected List<" + allowclass + "> vx_p_list = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(new ArrayList<" + allowclass + ">());" +
			"\n" +
			LangVxListFromType(lang, typ, vxlistbody) +
			LangVxAllowCodeFromList(lang, typ)
		valcopy += "" +
			"\n      List<" + allowclass + "> listval = new ArrayList<>(val.vx_list" + allowname + "());"
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
				"\n        } else if (" + LangIsType(lang, "valsub", allowtype) + ") {" +
				LangVar(lang, "anysub", allowtype, LangAsType(lang, "valsub", allowtype), 5, false, false) +
				"\n          ischanged = true;" +
				"\n          listval.add(anysub);"
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := LangNameTypeFromType(lang, allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "Boolean"
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_boolean, valsub)"
				case "vx/core/int":
					allowedtypename = "Integer"
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_int, valsub)"
				case "vx/core/float":
					allowedtypename = "Float"
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_float, valsub)"
				case "vx/core/string":
					allowedtypename = "String"
					castval = LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_string, valsub)"
				}
			}
			if allowedtypename != "" {
				valnew += "" +
					"\n        } else if (" + LangIsTypeText(lang, "valsub", allowedtypename) + ") {" +
					"\n          ischanged = true;" +
					"\n          listval.add(" + castval + ");"
			}
		}
		valnew += "" +
			"\n        } else if (" + LangIsType(lang, "valsub", typ) + ") {" +
			"\n          Type_" + typename + " multi = (Type_" + typename + ")valsub;" +
			"\n          ischanged = true;" +
			"\n          listval.addAll(multi.vx_list" + allowname + "());" +
			"\n        } else if (" + LangIsType(lang, "valsub", rawlisttype) + ") {" +
			LangVar(lang, "listunknown", rawlisttype, LangAsType(lang, "valsub", rawlisttype), 5, false, false) +
			LangForListHeader(lang, "item", rawobjecttype, "listunknown", 5) +
			"\n            if (" + LangIsType(lang, "item", allowtype) + ") {" +
			"\n              " + allowclass + " valitem = (" + allowclass + ")item;" +
			"\n              ischanged = true;" +
			"\n              listval.add(valitem);" +
			"\n            }" +
			"\n          }" +
			"\n        } else if (" + LangIsType(lang, "valsub", anytype) + ") {" +
			LangVar(lang, "anysub", anytype, LangAsType(lang, "valsub", anytype), 5, false, false) +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anysub);" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        } else {" +
			"\n          msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString()));" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_list = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablelist(listval);" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
			//		if extendinterface == "" {
			//			extendinterface = LangNameFromPkgNameDot(lang, "vx/core") + "Type_list"
			//		}
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
			"\n    protected Map<String, " + allowclass + "> vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(new LinkedHashMap<String, " + allowclass + ">());" +
			"\n" +
			LangVxMapFromType(lang, typ) +
			LangVxSetFromType(lang, typ) +
			LangVxAllowCodeFromMap(lang, typ) +
			LangVxNewFromMap(lang, typ)
		valcopy += "" +
			"\n      Map<String, " + allowclass + "> mapval = new LinkedHashMap<>(val.vx_map" + allowname + "());"
		valnew = "" +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
			"\n      String key = \"\";" +
			LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
			"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
			"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
			"\n        } else if (key.equals(\"\")) {" +
			"\n          if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
			LangVar(lang, "valstring", stringtype, LangAsType(lang, "valsub", stringtype), 6, false, false) +
			"\n            key = valstring.vx_string();" +
			"\n          } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
			LangVarSet(lang, "key", LangAsType(lang, "valsub", rawstringtype), 6) +
			"\n          } else {" +
			"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval;" +
			"\n            if (" + LangIsType(lang, "valsub", anytype) + ") {" +
			LangVarSet(lang, "msgval", LangAsType(lang, "valsub", anytype), 7) +
			"\n            } else {" +
			"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString());" +
			"\n            }" +
			"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":keyexpected\", msgval);" +
			"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			"\n          " + allowclass + " valany = null;" +
			"\n          if (" + LangIsType(lang, "valsub", allowtype) + ") {" +
			"\n            valany = (" + allowclass + ")valsub;"
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
					"\n          } else if (" + LangIsType(lang, "valsub", allowedtype) + ") {" +
					LangVarSet(lang, "valany", castval, 6)
			}
		}
		valnew += "" +
			"\n          } else {" +
			"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval;" +
			"\n            if (" + LangIsType(lang, "valsub", anytype) + ") {" +
			LangVarSet(lang, "msgval", LangAsType(lang, "valsub", anytype), 7) +
			"\n            } else {" +
			"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString());" +
			"\n            }" +
			"\n            Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> mapany = new LinkedHashMap<>();" +
			"\n            mapany.put(\"key\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(key));" +
			"\n            mapany.put(\"value\", msgval);" +
			"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map msgmap = " + LangNameFromPkgNameDot(lang, "vx/core") + "t_anymap.vx_new_from_map(mapany);" +
			"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkeyvalue\", msgmap);" +
			"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != null) {" +
			"\n            ischanged = true;" +
			"\n            if (key.startsWith(\":\")) {" +
			"\n              key = key.substring(1);" +
			"\n            }" +
			"\n            mapval.put(key, valany);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(mapval);" +
			"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
				"\n      boolean ischanged = false;" +
				"\n      Class_" + typename + " val = this;" +
				"\n      if (" + LangIsTypeText(lang, "this", LangNameFromPkgNameDot(lang, "vx/core")+"vx_Type_const") + ") {" +
				"\n        ischanged = true;" +
				"\n      }"
		case "vx/core/msgblock":
			valcopy = "" +
				"\n      boolean ischanged = false;" +
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
				"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
		default:
			validkeys := "\n      ArrayList<String> validkeys = new ArrayList<>();"
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      validkeys.add(\":" + arg.name + "\");"
				argname := LangFromName(arg.name)
				valcopy += "\n      " + LangNameTypeFromType(lang, arg.vxtype) + " vx_p_" + argname + " = val." + argname + "();"
				valcopyend += "\n        work.vx_p_" + argname + " = vx_p_" + argname + ";"
				vx_any += "" +
					"\n      case \":" + arg.name + "\":" +
					"\n        output = this." + argname + "();" +
					"\n        break;"
				argclassname := LangNameTypeFromType(lang, arg.vxtype)
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
						"\n              " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval;" +
						"\n              if (" + LangIsType(lang, "valsub", anytype) + ") {" +
						"\n                msgval = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any)valsub;" +
						"\n              } else {" +
						"\n                msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString());" +
						"\n              }" +
						"\n              Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> mapany = new LinkedHashMap<>();" +
						"\n              mapany.put(\"key\", " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(\"" + arg.name + "\"));" +
						"\n              mapany.put(\"value\", msgval);" +
						"\n              " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map msgmap = " + LangNameFromPkgNameDot(lang, "vx/core") + "t_anymap.vx_new_from_map(mapany);" +
						"\n              msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", msgmap);" +
						"\n              msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);"
				}
				valnewswitch += "" +
					"\n          case \":" + arg.name + "\":" +
					"\n            if (valsub == vx_p_" + argname + ") {" +
					"\n            } else if (" + LangIsType(lang, "valsub", arg.vxtype) + ") {" +
					"\n              ischanged = true;" +
					"\n              vx_p_" + argname + " = (" + argclassname + ")valsub;" +
					argalt +
					valnewswitcherr +
					"\n            }" +
					"\n            break;"
				instancefuncs += "" +
					"\n    protected " + argclassname + " vx_p_" + argname + ";" +
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
					"\n      String key = \"\";" +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (key == \"\") {" +
					"\n          if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
					"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string valstr = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
					"\n            key = (String)valsub;" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "();" +
					valcopyend +
					"\n        output = work;" +
					"\n      }"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      String key = \"\";" +
					"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
					"\n          if (valsub != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
					"\n            vx_p_msgblocks = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgblocks, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgblocklisttype) + ") {" +
					"\n          if (valsub != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblocklist) {" +
					"\n            vx_p_msgblocks = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgblocks, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
					"\n          if (valsub != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msg) {" +
					"\n            vx_p_msgs = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgs, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (" + LangIsType(lang, "valsub", msglisttype) + ") {" +
					"\n          if (valsub != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msglist) {" +
					"\n            vx_p_msgs = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(vx_p_msgs, valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (key == \"\") {" +
					"\n          if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
					"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string valstr = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
					"\n            key = (String)valsub;" +
					//"\n          } else {" +
					//"\n            //" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval;" +
					//"\n            //if (valsub instanceof " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any) {" +
					//"\n            //  msgval = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any)valsub;" +
					//"\n            //} else {" +
					//"\n            //  msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString());" +
					//"\n            //}" +
					//"\n            //msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkeytype\", msgval);" +
					//"\n            //msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        if ((vx_p_msgs.vx_list().size() == 0) && (vx_p_msgblocks.vx_list().size() == 1)) {" +
					"\n          output = vx_p_msgblocks.vx_listmsgblock().get(0);" +
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
					"\n      String key = \"\";" +
					"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg;" +
					LangForListHeader(lang, "valsub", rawobjecttype, "vals", 3) +
					"\n        if (" + LangIsType(lang, "valsub", msgblocktype) + ") {" +
					"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
					"\n        } else if (" + LangIsType(lang, "valsub", msgtype) + ") {" +
					"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          boolean istestkey = false;" +
					"\n          String testkey = \"\";" +
					"\n          if (" + LangIsType(lang, "valsub", stringtype) + ") {" +
					"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string valstr = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string)valsub;" +
					"\n            testkey = valstr.vx_string();" +
					"\n            istestkey = true;" +
					"\n          } else if (" + LangIsType(lang, "valsub", rawstringtype) + ") {" +
					"\n            testkey = (String)valsub;" +
					"\n            istestkey = true;" +
					defaultkey +
					"\n          } else {" +
					"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval;" +
					"\n            if (" + LangIsType(lang, "valsub", anytype) + ") {" +
					"\n              msgval = (" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any)valsub;" +
					"\n            } else {" +
					"\n              msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(valsub.toString());" +
					"\n            }" +
					"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkeytype\", msgval);" +
					"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n          }" +
					"\n          if (istestkey) {" +
					"\n            if (!testkey.startsWith(\":\")) {" +
					"\n              testkey = \":\" + testkey;" +
					"\n            }" +
					"\n            boolean isvalidkey = validkeys.contains(testkey);" +
					"\n            if (isvalidkey) {" +
					"\n              key = testkey;" +
					defaultstring +
					"\n            } else {" +
					"\n              " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(testkey);" +
					"\n              msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n              msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n            }" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          default:" +
					"\n            " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any msgval = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new_string(key);" +
					"\n            msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n            msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "();" +
					valcopyend +
					"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
		instancefuncs += "" +
			LangFuncHeader(lang, prefix, funcvxany, false) +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any output = " + LangNameFromPkgNameDot(lang, "vx/core") + "e_any;" +
			"\n      String skey = key.vx_string();" +
			"\n      switch (skey) {" +
			vx_any +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			LangVxMapFromStruct(lang, typ)
	default:
		//if extendinterface == "" {
		//	extendinterface = LangNameFromPkgNameDot(lang, "vx/core") + "Type_anytype"
		//}
		if valnew == "" {
			valnew = "" +
				"\n      if (ischanged || (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock)) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
		}
	}
	sinterface := LangInterfaceFromType(lang, typ)
	typedef := "" +
		"\n    " + override +
		"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef() {" +
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
		LangFuncHeader(lang, typename, funcvxcopy, false) +
		"\n      Type_" + typename + " output = this;" +
		valcopy +
		valnew +
		"\n      return output;" +
		"\n    }" +
		LangVxMsgblockFromType(lang, typ) +
		"\n" +
		"\n    " + override +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty() {" +
		"\n      return e_" + typename + ";" +
		"\n    }" +
		"\n    " + override +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type() {" +
		"\n      return t_" + typename + ";" +
		"\n    }" +
		"\n" +
		typedef +
		staticfuncs +
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
					output += LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_any_from_func("
					argtexts = append(argtexts, LangNameTFromType(lang, fnc.vxtype))
					argtexts = append(argtexts, LangFromName(fnc.argname))
					if lang == langcpp {
						multiflag = true
					}
				} else {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc) + "("
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
								lambdavar := argvaltype + " " + lambdaarg.name + " = " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringFromListStringJoin(lambdaargs, ", ")
							lambdavartext := "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
							if argfunc.async {
								work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
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
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_any_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, indent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
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
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + LangFinalArg(lang) + lang.future + "<" + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + "> future_" + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";" +
												arglineindent + "return " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "async_from_async_fn(future_" + LangFromName(lambdaarg.name) + ", (" + LangFromName(lambdaarg.name) + ") " + lang.lambdafunc + " {"
											aftertext += "" +
												arglineindent + "});"
											argindent += 1
										} else {
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + LangFinalArg(lang) + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 2, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func_async" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										"\n    return " + work + ";" +
										aftertext +
										"\n})"
								} else {
									argindent := 1
									arglineindent := "\n" + StringRepeat("  ", argindent)
									for _, lambdaarg := range arglist {
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += arglineindent + LangFinalArg(lang) + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										arglineindent + "return " + work + ";" +
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
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
										lambdavartext +
										"\n  " + outputtype + " output_" + StringFromInt(subindent) + " = " + work + lang.lineend +
										"\n  return output_" + StringFromInt(subindent) + lang.lineend +
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

func LangFuncHeader(lang *vxlang, prefix string, fnc *vxfunc, isinterface bool) string {
	output := ""
	funcname := fnc.name
	final := LangFinalArg(lang)
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
	if !isinterface {
		switch lang.name {
		case "csharp":
			genericdefinition3 = ""
		}
	}
	override1 := ""
	override2 := ""
	if fnc.isoverride {
		switch lang.name {
		case "csharp":
			override2 = "override "
		case "java":
			override1 = "\n    @Override"
		}
	}
	if fnc.isimplement {
		switch lang.name {
		case "java":
			override1 = "\n    @Override"
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
		"\n    public " + override2 + genericdefinition1 + returntype + " " + funcprefix + funcname + genericdefinition2 + "(" + argtext + ")" + genericdefinition3 + sinterface + sopen
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
			output = "Map<String, T>"
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
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "using " + path + ";"
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
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "using " + path + ";"
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
				libprefix := pkgpath
				if lib.pkg != nil {
					switch lang.name {
					case "java", "kotlin":
						libprefix = lib.pkg.project.javadomain
					}
				}
				libpath = libprefix + "/" + libpkgpath + "*"
				libpath = StringFromStringFindReplace(libpath, "/", ".")
			}
			if !isskip {
				importline := "\nimport " + libpath + lang.lineend
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
	//funcvxnew.vxtype = typ
	funcvxnew.vxtype = anytype
	funcvxnew.listarg = arglist
	funcvxcopy := NewFunc()
	funcvxcopy.name = "vx_copy"
	//funcvxcopy.vxtype = typ
	funcvxcopy.vxtype = anytype
	funcvxcopy.listarg = arglist
	basics := "" +
		LangFuncHeader(lang, typename, funcvxnew, true) +
		LangFuncHeader(lang, typename, funcvxcopy, true) +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty();" +
		"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type();"
	createtext, _ := LangFromValue(lang, typ.createvalue, "", emptyfunc, 0, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if createline == "@Override" {
				isoverride = true
			} else if isoverride {
				ipos := IntFromStringFindLast(createline, ")")
				createline = createline[0:ipos+1] + ";"
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
			LangFuncHeader(lang, LangNameFromType(lang, typ), funcvxrelease, true) +
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
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_map vx_new_from_map(" + LangFinalArg(lang) + "Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> mapval);" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any vx_any(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string key);" +
			"\n    public Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> vx_map();" +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_boolean vx_set(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string name, " + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any value);" +
			"\n  }" +
			"\n"
	case "vx/core/struct":
		output = "" +
			LangInterfaceHeader(lang, structtype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any vx_any(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string key);" +
			"\n    public Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> vx_map();" +
			"\n  }" +
			"\n"
	default:
		extras := ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			basics = "" +
				LangFuncHeader(lang, typename, funcvxnew, true) +
				LangFuncHeader(lang, typename, funcvxcopy, true) +
				"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty();" +
				"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type();" +
				"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef();"
		case "vx/core/msgblock":
			basics = "" +
				LangFuncHeader(lang, typename, funcvxnew, true) +
				LangFuncHeader(lang, typename, funcvxcopy, true) +
				"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_empty();" +
				"\n    public " + LangNameTypeFullFromType(lang, anytype) + " vx_type();" +
				"\n    public " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_typedef vx_typedef();"
		}
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
					"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameFromPkgNameDot(lang, "vx/core") + "Type_string key);"
			}
		case ":struct":
			extends = append(extends, structtype)
			if len(typ.traits) > 0 {
				extends = append(extends, typ.traits...)
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				extras += "\n    public " + LangNameTypeFromType(lang, arg.vxtype) + " " + LangFromName(arg.alias) + "();"
			}
		default:
			extends = append(extends, anytype)
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
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public interface IFn {" +
			"\n      public " + returntype + " resolve(" + argnames + ");" +
			"\n    }" +
			"\n"
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
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
		extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_" + funcname + ".IFn fn);"
	case "vx/core/any<-int":
		extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_int.IFn fn);"
	case "vx/core/boolean<-any":
		extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_boolean_from_any.IFn fn);"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = LangNameFromPkgNameDot(lang, "vx/core") + "Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(" + LangNameFromPkgNameDot(lang, "vx/core") + "Class_any_from_func.IFn fn);"
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

func LangNameClassFullFromType(lang *vxlang, typ *vxtype) string {
	name := LangNameFromPkgName(lang, typ.pkgname)
	name += lang.pkgref + "Class_"
	name += LangNameFromType(lang, typ)
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

func LangNameFromFuncFull(lang *vxlang, fnc *vxfunc) string {
	return LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc)
}

func LangNameFromPkgName(lang *vxlang, pkgname string) string {
	output := ""
	switch lang.name {
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
	case rawmaptype:
		switch lang.name {
		case "csharp", "java":
			name = "Map"
		}
	case rawmapanytype:
		switch lang.name {
		case "csharp", "java":
			name = "Map<String, " + LangNameFromTypeSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		switch lang.name {
		case "csharp", "java":
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
		name = "Float"
	case rawinttype:
		name = "int"
	case rawintegertype:
		name = "Integer"
	case rawlisttype:
		name = "List"
	case rawlistanytype:
		name = "List<" + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
	case rawstringtype:
		name = "String"
	case rawmaptype:
		name = "Map"
	case rawmapanytype:
		name = "Map<String, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
	case rawobjecttype:
		name = "Object"
	case rawstringtype:
		name = "String"
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

func LangNamespaceFromPackage(lang *vxlang, pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang.name {
	case "cpp":
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "csharp":
		namespaceopen = "\npublic static class " + pkgname + " {\n\n"
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

func LangOverride(lang *vxlang) string {
	var output = ""
	switch lang.name {
	case "csharp":
		output = "override"
	case "java":
		output = "@Override"
	}
	return output
}

func LangPackagePathFromPrefixName(lang *vxlang, pkgprefix string, pkgname string) (string, string) {
	pkgpath := ""
	name := ""
	switch lang.name {
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
		name = LangNameFromPkgName(lang, pkgname)
		pkgpath = name
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
			"\n    public " + lang.future + "<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> vx_repl(" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_anylist arglist) {" +
			"\n      " + lang.future + "<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> output = " + lang.future + ".completedFuture(" + LangNameFromPkgNameDot(lang, "vx/core") + "e_any);" +
			replparams +
			"\n      " + lang.future + "<" + outputtype + "> future = " + pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      output = " + LangNameFromPkgNameDot(lang, "vx/core") + "async_from_async(" + LangNameFromPkgNameDot(lang, "vx/core") + "t_any, future);" +
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

/*
func LangStringFromProjectCmd(prj *vxproject, cmd *vxcommand) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangStringFromProjectCmd")
	files, msgs := LangFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	text := StringFromListFile(files)
	return text, msgblock
}
*/

func LangTestCase(lang *vxlang, testvalues []vxvalue, testpkg string, testname string, testcasename string, fnc *vxfunc, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestCase")
	var output = ""
	if len(testvalues) > 0 {
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := LangFromValue(lang, testvalue, testpkg, fnc, 6, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
				"\n          Test.t_testdescribe," +
				"\n          \":describename\", \"" + LangTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		output = "" +
			"\n  static Test.Type_testcase " + testcasename + "(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
			"\n    Test.Type_testcase output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      Test.t_testcase," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        Test.t_testdescribelist, " + describelist +
			"\n      )" +
			"\n    );" +
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
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  public static Test.Type_testcaselist test_cases(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
		"\n    List<" + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(" +
		"\n      " + strings.Join(testall, ",\n      ") +
		"\n    ));" +
		"\n    Test.Type_testcaselist output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		"\n      Test.t_testcaselist," +
		"\n      arraylisttestcase" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  public static Test.Type_testcoveragesummary test_coveragesummary() {" +
		"\n    return " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		"\n      Test.t_testcoveragesummary," +
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
		"\n  public static Test.Type_testcoveragedetail test_coveragedetail() {" +
		"\n    return " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		"Test.t_testcoveragedetail, " +
		"\":testpkg\", \"" + pkg.name + "\", " +
		"\":typemap\", " + scovertype + ", " +
		"\":constmap\", " + scoverconst + ", " +
		"\":funcmap\", " + scoverfunc +
		");" +
		"\n  }" +
		"\n" +
		"\n  public static Test.Type_testpackage test_package(" + LangFinalArg(lang) + LangNameTypeFromType(lang, contexttype) + " context) {" +
		"\n    Test.Type_testcaselist testcaselist = test_cases(context);" +
		"\n    Test.Type_testpackage output = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_new(" +
		"\n      Test.t_testpackage," +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":caselist\", testcaselist," +
		"\n      \":coveragesummary\", test_coveragesummary()," +
		"\n      \":coveragedetail\", test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := LangImportsFromPackage(lang, pkg, pkgprefix, body, true)
	output := "" +
		"\npackage " + pkgpath + lang.lineend +
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
		"Test.t_testcoveragenums, " +
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

func LangVar(lang *vxlang, varname string, vartype *vxtype, varvalue string, indent int, isconst bool, isfuture bool) string {
	output := LangIndent(lang, indent, true)
	switch lang.name {
	case "csharp":
		typetext := ""
		typetext = LangNameTypeFullFromType(lang, vartype)
		if isfuture {
			typetext = "Task<" + typetext + ">"
		}
		output += typetext + " " + varname
		if varvalue != "" {
			output += " = " + varvalue
		}
		output += ";"
	case "java":
		typetext := ""
		switch vartype {
		case rawlisttype:
			switch lang.name {
			case "java":
				typetext = "List<?>"
			default:
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
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
		output += ";"
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
			"\n      if (iindex < listval.size()) {" +
			"\n        output = listval.get(iindex);" +
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
	allowclass := LangNameTypeFromType(lang, anytype)
	allowtypes := ListAllowTypeFromType(typ)
	if len(allowtypes) > 0 {
		allowtype := allowtypes[0]
		allowclass = LangNameTypeFullFromType(lang, allowtype)
		allowempty := LangNameEFromType(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
		output = "" +
			override +
			"\n    public " + allowclass + " vx_" + allowname + "(" + LangFinalArg(lang) + LangNameTypeFromType(lang, stringtype) + " key) {" +
			"\n      " + allowclass + " output = " + allowempty + ";" +
			"\n      " + LangNameClassFullFromType(lang, typ) + " map = this;" +
			"\n      String skey = key.vx_string();" +
			"\n      Map<String, " + allowclass + "> mapval = map.vx_p_map;" +
			"\n      output = mapval.getOrDefault(skey, " + allowempty + ");" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	if allowname == "any" {
		allowname = ""
	} else {
		output += "" +
			override +
			"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "() {" +
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
		LangFuncHeader(lang, prefix, funcvxargname, false) +
		"\n      return this.vx_p_" + argname + " == null ? " + LangNameEFromType(lang, arg.vxtype) + " : this.vx_p_" + argname + ";" +
		//"\n      "+ LangNameFromPkgNameDot(lang, "vx/core") + "Type_any valsub = this.vx_map().getOrDefault(\":" + arg.name + "\", " + LangNameEFromType(arg.vxtype) + ");" +
		//"\n      return "+ LangNameFromPkgNameDot(lang, "vx/core") + "f_any_from_any(" + LangNameTFromType(arg.vxtype) + ", valsub);" +
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
		LangFuncHeader(lang, funcprefix, funcvxcopy, false) +
		"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
		"\n      return output;" +
		"\n    }" +
		"\n"
	return output
}

func LangVxListFromType(lang *vxlang, typ *vxtype, body string) string {
	funcvxlist := NewFunc()
	funcvxlist.name = "vx_list"
	funcvxlist.vxtype = rawlistanytype
	funcvxlist.isimplement = true
	prefix := LangNameTypeFromType(lang, typ)
	output := "" +
		LangFuncHeader(lang, prefix, funcvxlist, false) +
		body +
		"\n    }" +
		"\n"
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
		"\n      " + LangNameTypeFromType(lang, rawmapanytype) + " output = new LinkedHashMap<>();" +
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
	prefix := LangNameTypeFromType(lang, typ)
	body := "\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(new LinkedHashMap<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any>(this.vx_p_map));"
	output := "" +
		LangFuncHeader(lang, prefix, funcvxmap, false) +
		body +
		"\n    }" +
		"\n"
	return output
}

func LangVxMsgblockFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	override := ""
	switch lang.name {
	case "java":
		override = "\n    @Override"
	}
	switch NameFromType(typ) {
	case "vx/core/msg":
		output = "" +
			"\n    " + override +
			"\n    public " + LangNameTypeFromType(lang, msgblocktype) + " vx_msgblock() {" +
			"\n      return " + LangNameEFromType(lang, msgblocktype) + lang.lineend +
			"\n    }"
	case "vx/core/msgblock":
		output = "" +
			"\n    " + override +
			"\n    public " + LangNameTypeFromType(lang, msgblocktype) + " vx_msgblock() {" +
			"\n      return this" + lang.lineend +
			"\n    }"
	}
	return output
}

func LangVxNewFromFunc(lang *vxlang, fnc *vxfunc, isinterface bool) string {
	returntype := NewTypeFromFunc(fnc)
	funcvxnew := LangFuncVxNew(returntype)
	funcname := LangNameFromFunc(fnc)
	funcprefix := LangNameFromFunc(fnc)
	output := "" +
		LangFuncHeader(lang, funcprefix, funcvxnew, false) +
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
	typepath := NameFromType(typ)
	output += "" +
		override +
		"\n    public " + LangNameTypeFromType(lang, maptype) + " vx_new_from_map(" + LangFinalArg(lang) + "Map<String, " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any> mapval) {" +
		"\n      " + LangNameClassFullFromType(lang, typ) + " output = new " + LangNameClassFullFromType(lang, typ) + "();" +
		"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msgblock msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock;" +
		"\n      Map<String, " + allowclass + "> map = new LinkedHashMap<>();" +
		"\n      Set<String> keys = mapval.keySet();" +
		LangForListHeader(lang, "key", rawstringtype, "keys", 3) +
		"\n        " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_any val = mapval.get(key);" +
		"\n        if (" + LangIsType(lang, "val", allowtype) + ") {" +
		"\n          " + allowclass + " castval = (" + allowclass + ")val;" +
		"\n          map.put(key, castval);" +
		"\n        } else {" +
		"\n          " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_msg msg = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", val);" +
		"\n          msgblock = " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(msgblock, msg);" +
		"\n        }" +
		"\n      }" +
		"\n      output.vx_p_map = " + LangNameFromPkgNameDot(lang, "vx/core") + "immutablemap(map);" +
		"\n      if (msgblock != " + LangNameFromPkgNameDot(lang, "vx/core") + "e_msgblock) {" +
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
		LangFuncHeader(lang, typename, funcvxnew, false) +
		"\n      return " + LangNameFromPkgNameDot(lang, "vx/core") + "vx_copy(" +
		"\n       e_" + typename + "," +
		"\n       vals);" +
		"\n    }" +
		"\n"
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
	allowclass := LangNameFromPkgNameDot(lang, "vx/core") + "Type_any"
	allowtypes := ListAllowTypeFromType(typ)
	allowempty := LangNameEFromType(lang, anytype)
	if len(allowtypes) > 0 {
		allowtype = allowtypes[0]
		allowclass = LangNameTypeFullFromType(lang, allowtype)
		allowempty = LangNameEFromType(lang, allowtype)
		allowname = LangNameFromType(lang, allowtype)
	}
	if allowname == "any" {
		allowname = ""
	}
	body := "" +
		"\n      " + LangNameFromPkgNameDot(lang, "vx/core") + "Type_boolean output = " + LangNameFromPkgNameDot(lang, "vx/core") + "c_false;" +
		"\n      if (" + LangIsType(lang, "value", allowtype) + ") {" +
		"\n        String key = name.vx_string();" +
		"\n        if (key.startsWith(\":\")) {" +
		"\n          key = key.substring(1);" +
		"\n        }" +
		"\n        " + allowclass + " castval = (" + allowclass + ")value;" +
		"\n        Map<String, " + allowclass + "> map = new LinkedHashMap<>(this.vx_p_map);" +
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
		LangFuncHeader(lang, prefix, funcvxmap, false) +
		body +
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
	contexttext := LangVar(lang, "context", contexttype, LangNameFromPkgNameDot(lang, "vx/core")+"f_context_main(arglist)", 3, true, false)
	maintext := "" +
		LangVar(lang, "mainval", stringtype, LangNameFromPkgNameDot(lang, "vx/core")+"f_main(arglist)", 3, true, false) +
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
					LangVar(lang, "asynccontext", contexttype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, true) +
					LangVar(lang, "context", contexttype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async(vx_core::t_context, asynccontext)", 3, true, false)
			} else {
				contexttext = LangVar(lang, "context", contexttype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, false)
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
					LangVar(lang, "asyncstring", stringtype, mainfunctext, 3, true, true) +
					LangVar(lang, "mainstring", stringtype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameFromPkgNameDot(lang, "vx/core")+"t_string, asyncstring)", 3, true, false)
			} else {
				maintext = LangVar(lang, "mainstring", stringtype, mainfunctext, 3, true, false)
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
	outputopen = LangVar(lang, "output", rawstringtype, "\"\"", 3, false, false)
	outputclose = LangVarSet(lang, "output", "mainstring.vx_string()", 3)
	switch lang.name {
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
		arglistinit = LangVar(lang, "arglist", anylisttype, LangNameFromPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)", 3, true, false)
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
		arglistinit = LangVar(lang, "arglist", anylisttype, "vx_core.vx_anylist_from_arraystring(args)", 3, true, false)
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
	contexttext := `
  ` + LangNameTypeFromType(lang, anylisttype) + ` arglist = ` + LangNameFromPkgNameDot(lang, "vx/core") + `e_anylist;
  ` + LangNameTypeFromType(lang, contexttype) + ` context = ` + pkgprefix + `vx.Test.f_context_test(arglist);`
	if command.context == "" {
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
			libprefix := ""
			switch lang.name {
			case "java", "kotlin":
				libprefix = project.javadomain + "."
			}
			pkgname := contextfunc.pkgname
			pkgpath := ""
			pos := strings.LastIndex(pkgname, "/")
			if pos >= 0 {
				pkgpath = pkgname[0:pos]
				pkgpath = libprefix + StringFromStringFindReplace(pkgpath, "/", ".")
			}
			if contextfunc.async {
				contexttext = `
  ` + LangNameTypeFromType(lang, anylisttype) + ` arglist = ` + LangNameFromPkgNameDot(lang, "vx/core") + `e_anylist;
  " + lang.future + "<` + LangNameTypeFromType(lang, contexttype) + `> asynccontext = ` + pkgpath + `.` + LangNameFFromFunc(lang, contextfunc) + `(arglist);
  ` + LangNameTypeFromType(lang, contexttype) + ` context = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(vx_core::t_context, asynccontext);`
			} else {
				contexttext = `
  ` + LangNameTypeFromType(lang, anylisttype) + ` arglist = ` + LangNameFromPkgNameDot(lang, "vx/core") + `e_anylist;
  ` + LangNameTypeFromType(lang, contexttype) + ` context = ` + pkgpath + `.` + LangNameFFromFunc(lang, contextfunc) + `(arglist);`
			}
		}
	}
	tests := ""
	listpackage := project.listpackage
	var listtestpackage []string
	for _, pkg := range listpackage {
		iscontinue := true
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			pkgname := pkg.name
			if pkg.name != "" {
				imports += LangImportTest(lang, project, pkgname, imports)
				pos := strings.LastIndex(pkgname, "/")
				if pos >= 0 {
					pkgname = pkgname[pos+1:]
				}
				pkgname = StringUCaseFirst(pkgname)
				testpackage := "\n    " + pkgname + "Test.test_package(context)"
				listtestpackage = append(listtestpackage, testpackage)
				tests += `
  @Test
  @DisplayName("` + pkg.name + `")
  void test_` + StringFromStringFindReplace(pkg.name, "/", "_") + `() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = ` + pkgname + `Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

`
			}
		}
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "AppTest")
	output := `
` + imports + `
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */` +
		namespaceopen +
		contexttext + `
` + tests + `
  @Test
  @DisplayName("writetestsuite")
  void test_writetestsuite() {
    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_new(com.vxlisp.vx.Test.t_testpackagelist, ` +
		testpackages +
		`
    );
    TestLib.write_testpackagelist_async(context, testpackagelist);
  }` +
		namespaceclose
	return output
}

func LangTestLib(lang *vxlang) string {
	output := ""
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "TestLib")
	switch lang.name {
	case "java":
		output = `
import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;
` + namespaceopen + `
  public static boolean run_testcase(final Test.Type_testcase testcase) {
    String testpkg = testcase.testpkg().vx_string();
    String casename = testcase.casename().vx_string();
    Test.Type_testdescribelist testdescribelist = testcase.describelist();
    return run_testdescribelist(testpkg, casename, testdescribelist);
  }

  // Blocking
  // Only use if running a single testcase
  public static boolean run_testcase_async(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> async_testcase = Test.f_resolve_testcase(testcase);
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_any work = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testcase, async_testcase);
    Test.Type_testcase testcase_resolved = (Test.Type_testcase)work;
    return run_testcase(testcase_resolved);
  }

  public static boolean run_testcaselist(final Test.Type_testcaselist testcaselist) {
    List<Test.Type_testcase> listtestcase = testcaselist.vx_listtestcase();
    for (Test.Type_testcase testcase : listtestcase) {
      run_testcase(testcase);
    }
    return true;
  }

  public static boolean run_testdescribe(final String testpkg, final String casename, final Test.Type_testdescribe describe) {
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_string testcode = describe.describename();
    String message = testcode.vx_string();
    Test.Type_testresult testresult = describe.testresult();
    return run_testresult(testpkg, casename, message, testresult);
  }

  // Blocking
  // Only use if running a single testdescribe
  public static boolean run_testdescribe_async(final String testpkg, final String casename, final Test.Type_testdescribe testdescribe) {
    CompletableFuture<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  public static boolean run_testdescribelist(final String testpkg, final String casename, final Test.Type_testdescribelist testdescribelist) {
    boolean output = true;
    List<Test.Type_testdescribe> listtestdescribe = testdescribelist.vx_listtestdescribe();
    for (Test.Type_testdescribe testdescribe : listtestdescribe) {
      boolean testoutput = run_testdescribe(testpkg, casename, testdescribe);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  public static boolean run_testpackage(final Test.Type_testpackage testpackage) {
    Test.Type_testcaselist testcaselist = testpackage.caselist();
    return run_testcaselist(testcaselist);
  }

  public static boolean run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    boolean output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
      boolean testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  public static boolean run_testpackage_async(final Test.Type_testpackage testpackage) {
    CompletableFuture<Test.Type_testpackage> async_testpackage = Test.f_resolve_testpackage(testpackage);
    Test.Type_testpackage testpackage_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackage, async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static boolean run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  public static boolean run_testresult(final String testpkg, final String testname, final String message, final Test.Type_testresult testresult) {
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_any valexpected = testresult.expected();
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_any valactual = testresult.actual();
    boolean passfail = testresult.passfail().vx_boolean();
    String code = testresult.code().vx_string();
    String expected = ` + LangNameFromPkgNameDot(lang, "vx/core") + `f_string_from_any(valexpected).vx_string();
    String actual = ` + LangNameFromPkgNameDot(lang, "vx/core") + `f_string_from_any(valactual).vx_string();
    String msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
      System.out.println(msg);
      System.out.println(expected);
      System.out.println(actual);
      ` + LangNameFromPkgNameDot(lang, "vx/core") + `f_log(testresult);
    }
    switch (code) {
    case ":ne":
      assertNotEquals(expected, actual, msg);
      break;
    default:
      assertEquals(expected, actual, msg);
      break;
    }
    return true;
  }

  // Blocking
  public static boolean run_testresult_async(final String testpkg, final String testname, final String message, Test.Type_testresult testresult) {
    CompletableFuture<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  public static boolean write_testpackagelist_async(final ` + LangNameTypeFromType(lang, contexttype) + ` context, final Test.Type_testpackagelist testpackagelist) {
    boolean output = false;
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = ` + LangNameFromPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    File.Type_file filetest = Test.f_file_test();
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_boolean valboolean = File.f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved);
    output = valboolean.vx_boolean();
    Html.Type_div divtest = Test.f_div_from_testpackagelist(testpackagelist_resolved);
    Html.Type_html htmlnode = Test.f_html_from_divtest(divtest);
    File.Type_file filenode = Test.f_file_testnode();
    valboolean = File.f_boolean_write_from_file_any(context, filenode, htmlnode);
    output = output && valboolean.vx_boolean();
    File.Type_file filehtml = Test.f_file_testhtml();
    ` + LangNameFromPkgNameDot(lang, "vx/core") + `Type_string shtml = Html.f_string_from_html(htmlnode);
    valboolean = File.f_boolean_write_from_file_string(context, filehtml, shtml);
    output = output && valboolean.vx_boolean();
    return output;
  }
` +
			namespaceclose
	}
	return output
}
