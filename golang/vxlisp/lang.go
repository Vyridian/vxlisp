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
	lineend    string
	itfext     string
	classext   string
	typeref    string
	memmanage  bool
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
	output.lineend = ";"
	output.typeref = "->"
	output.memmanage = true
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

func LangAsClass(lang *vxlang, svar string, typ *vxtype) string {
	typetext := ""
	// SomeClass obj2 = (SomeClass)Convert.ChangeType(t, typeof(SomeClass));
	switch typ {
	case rawlistunknowntype:
		switch lang.name {
		case "csharp":
			typetext = "List<object>"
		case "java":
			typetext = "List<?>"
		case "kotlin":
			typetext = "List<Any>"
		default:
			typetext = LangTypeClassFull(lang, typ)
		}
	default:
		typetext = LangTypeClassFull(lang, typ)
	}
	return LangAsTypeText(lang, svar, typetext)
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
		case "kotlin":
			typetext = "List<Any>"
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
			output = "(" + stype + ")" + svar
		}
	case "java":
		output = "(" + stype + ")" + svar
	case "kotlin":
		output = svar + " as " + stype
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
		file.text = LangTestApp(lang, project, command, pkgprefix)
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

func LangForList(
	lang *vxlang,
	forvar string,
	typ *vxtype,
	listvar string,
	indent int,
	body string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	header := LangForListHeader(lang, forvar, typ, listvar, indent)
	footer := sindent + "}"
	output := "" +
		header +
		body +
		footer
	return output
}

func LangForListHeader(
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

func LangFromPackage(
	lang *vxlang,
	pkg *vxpackage,
	project *vxproject,
	pkgprefix string) (string, *vxmsgblock) {
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
	case "java", "kotlin":
		packageline = "package " + pkgpath + lang.lineend + "\n"
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	packagestatic := "" +
		LangVarCollection(lang, "maptype", rawmaptype, anytype, 2, ":new") +
		LangVarCollection(lang, "mapconst", rawmaptype, anytype, 2, ":new") +
		LangVarCollection(lang, "mapfunc", rawmaptype, functype, 2, ":new")
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, msgs := LangType(lang, typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
		packagestatic += "" +
			"\n    maptype.put(\"" + typ.name + "\", " + LangTypeT(lang, typ) + ")" + lang.lineend
	}
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	consttexts := ""
	statics := ""
	afterstatics := ""
	switch lang.name {
	case "csharp":
		statics = "" +
			"\n  public static class PackageRunOnce {" +
			"\n    public static bool RunOnce() {"
		afterstatics = "" +
			"\n      return true" + lang.lineend +
			"\n    }" +
			"\n  }" +
			"\n" +
			"\n  public static bool ranonce = PackageRunOnce.RunOnce()" + lang.lineend +
			"\n"
	case "java":
		statics = "\n  static {"
		afterstatics += "" +
			"\n  }" +
			"\n"
	case "kotlin":
		statics = "\n  init {"
		afterstatics += "" +
			"\n  }" +
			"\n"
	}
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constlate, msgs := LangConst(lang, cnst, project, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		statics += constlate
		packagestatic += "" +
			"\n    mapconst.put(\"" + cnst.name + "\", " + LangConstC(lang, cnst) + ")" + lang.lineend
	}
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	functexts := ""
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, msgs := LangFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
			packagestatic += "" +
				"\n    mapfunc.put(\"" + fnc.name + LangIndexFromFunc(fnc) + "\", " + LangFuncT(lang, fnc) + ")" + lang.lineend
		}
	}
	packagestatic += "" +
		"\n    " + LangPkgNameDot(lang, "vx/core") + "vx_global_package_set(\"" + pkg.name + "\", maptype, mapconst, mapfunc)" + lang.lineend
	statics += packagestatic
	body := "" +
		specialcode +
		typetexts +
		consttexts +
		functexts +
		statics +
		afterstatics
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

func LangFromValue(
	lang *vxlang,
	value vxvalue,
	pkgname string,
	parentfn *vxfunc,
	indent int,
	encode bool,
	test bool,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromValue")
	output := ""
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
			valstr = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = LangFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = LangPkgName(lang, valconst.pkgname) + ".c_" + LangFromName(valconst.alias)
			}
		}
		output = valstr
	case ":func":
		fnc := FuncFromValue(value)
		sfuncvalue, msgs := LangFuncValue(
			lang,
			fnc,
			pkgname,
			parentfn,
			indent,
			encode,
			test,
			path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = sfuncvalue
	case ":funcref":
		valfunc := FuncFromValue(value)
		valstr = ""
		valstr += LangPkgName(lang, valfunc.pkgname) + lang.typeref + "t_" + LangFromName(valfunc.alias)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = LangPkgName(lang, valtype.pkgname) + lang.typeref + "t_" + LangFromName(valtype.alias)
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
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "t_decimal" + lang.typeref + "vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_int(" + valstr + ")"
		}
	case "number":
		if encode {
			valstr = StringValueFromValue(value)
			output = valstr
		}
	default:
	}
	return output, msgblock
}

func LangArgGenericFromType(lang *vxlang, typ *vxtype) vxarg {
	typename := StringFromStringFindReplace(typ.name, "-", "_")
	output := NewArg("generic_" + typename)
	output.vxtype = typ
	output.isgeneric = true
	return output
}

func LangArgHeader(lang *vxlang, arg vxarg, isallowgeneric bool) string {
	output := ""
	sfinal := ""
	if arg.isfinal {
		sfinal = LangFinalArg(lang)
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
			switch lang.name {
			case "csharp":
				smulti1 = "params "
				smulti2 = "[]"
			case "java", "swift":
				smulti2 = "..."
			case "kotlin":
				smulti1 = "vararg "
			}
		}
	}
	switch lang.name {
	case "kotlin", "swift":
		output = "" + sfinal + smulti1 + sargname + smulti2 + " : " + stypename
	default:
		output = "" + sfinal + smulti1 + stypename + smulti2 + " " + sargname
	}
	return output
}

func LangIf(
	lang *vxlang,
	indent int,
	ifclause string,
	thenclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "if (" + ifclause + ") {" + thenclause
	return output
}

func LangIfClause(
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
	}
	output := "(" + sleft + sop + sright + ")"
	return output
}

func LangIfElse(
	lang *vxlang,
	indent int,
	thenclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "} else {" + thenclause
	return output
}

func LangIfElseIf(
	lang *vxlang,
	indent int,
	ifclause string,
	thenclause string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "} else if (" + ifclause + ") {" + thenclause
	return output
}

func LangIfEnd(
	lang *vxlang,
	indent int) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := sindent + "}"
	return output
}

func LangElseIfType(
	lang *vxlang,
	typ *vxtype,
	subtype *vxtype,
	svar string,
	scastvar string,
	indent int,
	isfuture bool) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang.name {
	case "csharp":
		if scastvar == "" {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		} else {
			output = sindent + "} else if (" + LangIsType(lang, svar, typ) + " " + scastvar + ") {"
		}
	case "java", "kotlin":
		output = sindent + "} else if (" + LangIsType(lang, svar, typ) + ") {"
		if scastvar != "" {
			output += LangVarOld(lang, scastvar, typ, subtype, LangAsType(lang, svar, typ), indent+1, false, isfuture)
		}
	}
	return output
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
			output = "Map<" + LangTypeName(lang, rawstringtype) + ", T>"
		case "struct-1":
			output = "Q"
		case "struct-2":
			output = "R"
		case "struct-3":
			output = "S"
		}
	} else {
		output = LangTypeName(lang, typ)
	}
	return output
}

func LangImport(lang *vxlang,
	project *vxproject,
	pkgname string,
	imports string) string {
	output := ""
	importline := ""
	switch lang.name {
	case "cpp":
		importline = "#include \"" + pkgname + ".hpp\""
	case "csharp":
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name
		importline = "import " + importname + lang.lineend
	case "kotlin":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := pkgname
		name = StringFromStringFindReplace(name, "/", "_")
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
		importline = "using Xunit" + lang.lineend
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
	case "kotlin":
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
					switch lang.name {
					case "csharp":
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

func LangFuncInterfaceFn(lang *vxlang, fnc *vxfunc) string {
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
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
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
		switch lang.name {
		case "csharp":
			interfaces = "" +
				"\n    public delegate " + returntype + " IFn(" + argnames + ")" + lang.lineend +
				"\n"
		case "java":
			interfaces = "" +
				"\n    @FunctionalInterface" +
				"\n    public interface IFn {" +
				"\n      public " + returntype + " resolve(" + argnames + ")" + lang.lineend +
				"\n    }" +
				"\n"
		case "kotlin":
			interfaces = "" +
				"\n    fun interface IFn {" +
				"\n      fun resolve(" + argnames + ") : " + returntype +
				"\n    }" +
				"\n"
		}
	}
	return interfaces
}

func LangIsType(lang *vxlang, svar string, typ *vxtype) string {
	return LangIsTypeText(lang, svar, LangNameTypeFullFromType(lang, typ))
}

func LangIsTypeText(lang *vxlang, svar string, stype string) string {
	output := ""
	switch lang.name {
	case "csharp", "kotlin":
		output = svar + " is " + stype
	case "java":
		output = svar + " instanceof " + stype
	}
	return output
}

func LangLambdaFromArgList(
	lang *vxlang,
	arglist []vxarg,
	isgeneric bool) (string, string, string) {
	var lambdatypenames []string
	var lambdavars []string
	var lambdaargnames []string
	if isgeneric {
		lambdaargname := LangTypeT(lang, anytype)
		lambdaargnames = append(lambdaargnames, lambdaargname)
	}
	for _, lambdaarg := range arglist {
		argvaltype := ""
		argtype := lambdaarg.vxtype
		lambdaargname := LangFromName(lambdaarg.alias) + "_lmb"
		lambdaargnames = append(lambdaargnames, lambdaargname)
		switch NameFromType(argtype) {
		case "vx/core/any", "vx/core/any-1":
			argtypename := LangTypeName(lang, anytype)
			lambdatypename := ""
			switch lang {
			case langkotlin:
				lambdatypename = lambdaargname + " : " + argtypename
			default:
				lambdatypename = argtypename + " " + lambdaargname
			}
			lambdatypenames = append(lambdatypenames, lambdatypename)
		default:
			switch lambdaarg.name {
			case "key":
				argtypename := LangTypeName(lang, argtype)
				lambdatypename := ""
				switch lang {
				case langkotlin:
					lambdatypename = lambdaargname + " : " + argtypename
				default:
					lambdatypename = argtypename + " " + lambdaargname
				}
				lambdatypenames = append(lambdatypenames, lambdatypename)
			default:
				argvaltype = LangNameTypeFullFromType(lang, argtype)
				argvaltname := LangTypeT(lang, argtype)
				argtypename := LangTypeName(lang, anytype)
				lambdatypename := ""
				switch lang {
				case langkotlin:
					lambdatypename = lambdaargname + "_any : " + argtypename
				default:
					lambdatypename = argtypename + " " + lambdaargname + "_any"
				}
				lambdatypenames = append(lambdatypenames, lambdatypename)
				corepkgname := LangPkgName(lang, "vx/core")
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

func LangNameFromArg(lang *vxlang, arg vxarg) string {
	return LangFromName(arg.alias)
}

func LangNameFromType(lang *vxlang, typ *vxtype) string {
	return LangTypeNameSimple(lang, typ, false)
}

func LangNameTypeFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	output := LangNameTypeFullFromTypeSimple(lang, typ, simple)
	return output
}

func LangNameTypeFullFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFullFromTypeSimple(lang, typ, true)
}

func LangNameTypeFullFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	switch typ {
	case anylisttype:
		name = lang.pkgname + lang.pkgref + "Type_anylist"
	case contexttype:
		name = lang.pkgname + lang.pkgref + "Type_context"
	case nonetype:
		switch lang.name {
		case "kotlin":
			name = "Unit"
		default:
			name = "void"
		}
	case stringtype:
		name = lang.pkgname + lang.pkgref + "Type_string"
	case rawbooltype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java":
			name = "boolean"
		case "kotlin":
			name = "Boolean"
		}
	case rawbooleantype:
		switch lang.name {
		case "csharp":
			name = "bool"
		case "java", "kotlin":
			name = "Boolean"
		}
	case rawfloattype:
		switch lang.name {
		case "csharp":
			name = "float"
		case "java":
			name = "Float"
		case "kotlin":
			name = "Float"
		}
	case rawifntype:
		name = "IFn"
	case rawinttype:
		switch lang.name {
		case "kotlin":
			name = "Int"
		default:
			name = "int"
		}
	case rawintegertype:
		switch lang {
		case langcsharp:
			name = "int"
		case langjava:
			name = "Integer"
		case langkotlin:
			name = "Int"
		}
	case rawlisttype:
		switch lang.name {
		case "csharp":
			name = "List<object>"
		case "java":
			name = "List"
		case "kotlin":
			name = "List<Any>"
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
		case "cpp":
			name = "std::Map<std::string, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
		case "csharp":
			name = "Vx.Core.Map<string, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
		default:
			name = "Map<String, " + LangNameTypeFullFromTypeSimple(lang, anytype, true) + ">"
		}
	case rawobjecttype:
		switch lang.name {
		case "csharp":
			name = "object"
		case "kotlin":
			name = "Any"
		default:
			name = "Object"
		}
	case rawstringtype:
		switch lang.name {
		case "cpp":
			name = "std::string"
		case "csharp":
			name = "string"
		default:
			name = "String"
		}
	case rawvoidtype:
		switch lang.name {
		case "kotlin":
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
			switch lang.name {
			case "cpp":
				name = "std::Map<std::string, " + subtypename + ">"
			case "csharp":
				name = "Vx.Core.Map<string, " + subtypename + ">"
			default:
				name = "Map<String, " + subtypename + ">"
			}
		default:
			if typ.isgeneric && !simple {
				name = LangTypeNameSimple(lang, typ, simple)
			} else {
				name = LangPkgName(lang, typ.pkgname)
				if typ.isfunc {
					name += lang.pkgref + "Func_"
				} else {
					name += lang.pkgref + "Type_"
				}
				name += LangTypeNameSimple(lang, typ, simple)
			}
		}
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
		default:
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
			"\nobject " + pkgname + " {" +
			"\n" +
			"\n"
		namespaceclose = "\n}\n"
	}
	return namespaceopen, namespaceclose
}

func LangNativeAutoFromFunc(lang *vxlang, fnc *vxfunc) string {
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
	output = LangPkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangFuncName(fnc) + "(" + argnames + ")" + lang.lineend
	switch lang.name {
	case "cpp":
		if fnc.generictype != nil {
			argname := LangTypeTGeneric(lang, fnc.generictype)
			output = "" +
				"vx_core::Type_any result = " + output +
				"\noutput = vx_core::vx_any_from_any(" + argname + ", result)" + lang.lineend
		}
	}
	return output
}

func LangOverride(lang *vxlang, indent int, isinterface bool) (string, string, string) {
	override1 := ""
	override2 := ""
	override3 := ""
	switch lang.name {
	case "csharp":
		if !isinterface {
			override3 = "override "
		}
	case "java":
		override1 = "\n" + StringRepeat("  ", indent) + "@Override"
	case "kotlin":
		if !isinterface {
			override2 = "override "
		}
	}
	return override1, override2, override3
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
		name = LangPkgName(lang, name)
	case "kotlin":
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = StringFromStringFindReplace(pkgname, "/", "_")
		name = LangPkgName(lang, name)
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

func LangPkgName(lang *vxlang, pkgname string) string {
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

func LangPkgNameDot(lang *vxlang, pkgname string) string {
	output := LangPkgName(lang, pkgname) + lang.pkgref
	return output
}

func LangTypeCoverageNumsValNew(lang *vxlang, pct int, tests int, total int) string {
	return "" +
		LangPkgNameDot(lang, "vx/core") + "vx_new(" +
		LangTypeT(lang, testcoveragenumstype) + ", " +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func LangStaticClose(lang *vxlang) string {
	output := ""
	switch lang.name {
	case "kotlin":
		output = "\n    }"
	}
	return output
}

func LangStaticOpen(lang *vxlang) string {
	output := ""
	switch lang.name {
	case "kotlin":
		output = "" +
			"\n    companion object {" +
			"\n"
	}
	return output
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
		switch lang.name {
		case "java":
			if BooleanFromStringEnds(targetpath, "/java") {
				targetpath = targetpath[0 : len(targetpath)-5]
			}
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

func LangVal(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		true,
		false,
		false,
		false,
		false,
		false)
	return output
}

func LangValClass(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarClassAll(
		lang, varname, vartype, indent, true, false, varvalue)
	return output
}

func LangVar(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		false,
		false,
		false,
		false,
		false,
		false)
	return output
}

func LangVarFuture(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		false,
		true,
		false,
		false,
		false,
		false)
	return output
}

func LangVarFutureGeneric(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		false,
		true,
		false,
		false,
		true,
		false)
	return output
}

func LangVarGeneric(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		false,
		false,
		false,
		false,
		true,
		false)
	return output
}

func LangVarNull(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarAll(
		lang,
		varname,
		vartype,
		emptytype,
		varvalue,
		indent,
		false,
		false,
		false,
		false,
		false,
		true)
	return output
}

func LangVarOld(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype,
	varvalue string, indent int, isconst bool, isfuture bool) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, isconst, isfuture, false, false, false, false)
}

func LangVarAll(
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
	svalue := LangVarValue(lang, vartype, varvalue)
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
	case "java":
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
	case "kotlin":
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

func LangVarClass(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarClassAll(
		lang, varname, vartype, indent, false, false, varvalue)
	return output
}

func LangVarClassNullable(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangVarClassAll(
		lang, varname, vartype, indent, false, true, varvalue)
	return output
}

func LangVarClassAll(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	isconst bool,
	isnullable bool,
	varvalue string) string {
	classname := LangTypeClassFull(lang, vartype)
	sindent := "\n" + StringRepeat("  ", indent)
	svalue := LangVarValue(lang, vartype, varvalue)
	output := sindent
	switch lang.name {
	case "csharp":
		nullable := ""
		if isnullable {
			nullable = "?"
		}
		output += "" +
			classname + nullable + " " + varname + " = " + svalue + lang.lineend
	case "kotlin":
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
	case "swift":
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

func LangVarCollection(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, false, false, false, false, false, false)
}

func LangVarProp(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, false, false, false, true, false, false)
}

func LangValStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, true, false, true, false, false, false)
}

func LangVarStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, false, true, false, false, false)
}

func LangVarStaticFuture(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, true, true, false, false, false)
}

func LangVarSet(
	lang *vxlang,
	varname string,
	indent int,
	varvalue string) string {
	output := LangIndent(lang, indent, true)
	output += varname
	output += " = " + varvalue
	switch lang.name {
	case "csharp", "java":
		output += lang.lineend
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
		switch lang.name {
		case "kotlin":
			output = classname + "()"
		case "swift":
			output = classname + "()"
		default:
			output = "new " + classname + "()"
		}
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
		LangFuncHeader(lang, prefix, funcvxargname, 2, 0,
			LangVar(lang, "output", arg.vxtype, 3,
				LangTypeE(lang, arg.vxtype))+
				LangVarNull(lang, "testnull", arg.vxtype, 3, "vx_p_"+argname)+
				"\n      if (testnull != null) {"+
				LangVarSet(lang, "output", 4, "testnull")+
				"\n      }")
	return output
}

func LangVxContains(lang *vxlang, text string, contains string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = text + ".Contains(" + contains + ")"
	default:
		output = text + ".contains(" + contains + ")"
	}
	return output
}

func LangVxEqualsString(lang *vxlang, text1 string, text2 string) string {
	output := ""
	switch lang.name {
	case "java", "kotlin":
		output = text1 + ".equals(" + text2 + ")"
	default:
		output = text1 + " == " + text2
	}
	return output
}

func LangVxFloatFromString(lang *vxlang, text string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "float.Parse(" + text + ")"
	case "java":
		output = "Float.parseFloat(" + text + ")"
	case "kotlin":
		output = text + ".toFloat()"
	}
	return output
}

func LangVxIntFromString(lang *vxlang, text string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "Int32.Parse(" + text + ")"
	case "java":
		output = "Integer.parseInt(" + text + ")"
	case "kotlin":
		output = text + ".toInt()"
	}
	return output
}

func LangVxListAdd(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Add(" + value + ")"
	default:
		output = varname + ".add(" + value + ")"
	}
	return output
}

func LangVxListAddList(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".AddRange(" + value + ")"
	default:
		output = varname + ".addAll(" + value + ")"
	}
	return output
}

func LangVxListGet(lang *vxlang, varname string, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + "[" + value + "]"
	default:
		output = varname + ".get(" + value + ")"
	}
	return output
}

func LangVxListSize(lang *vxlang, varname string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Count"
	case "kotlin":
		output = varname + ".size"
	default:
		output = varname + ".size()"
	}
	return output
}

func LangVxNewList(lang *vxlang, typ *vxtype, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "new List<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case "java":
		output = "new ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	case "kotlin":
		output = "ArrayList<" + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVxNewMap(lang *vxlang, typ *vxtype, value string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "new Vx.Core.LinkedHashMap<string, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case "java":
		output = "new LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	case "kotlin":
		output = "LinkedHashMap<String, " + LangTypeName(lang, typ) + ">(" + value + ")"
	}
	return output
}

func LangVxStartswith(
	lang *vxlang,
	varname string,
	starts string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".StartsWith(" + starts + ")"
	case "java", "kotlin":
		output = varname + ".startsWith(" + starts + ")"
	}
	return output
}

func LangVxSubstring(
	lang *vxlang,
	varname string,
	from string,
	to string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = varname + ".Substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	case "java", "kotlin":
		output = varname + ".substring(" + from
		if to != "" {
			output += ", " + to
		}
		output += ")"
	}
	return output
}

func LangVxToString(
	lang *vxlang,
	varname string) string {
	output := ""
	switch lang.name {
	case "csharp":
		output = "Vx.Core.vx_string_from_object(" + varname + ")"
	case "java", "kotlin":
		output = varname + ".toString()"
	}
	return output
}

func LangApp(lang *vxlang, project *vxproject, cmd *vxcommand) string {
	indent0 := LangIndent(lang, 0, true)
	indent1 := LangIndent(lang, 1, true)
	indent2 := LangIndent(lang, 2, true)
	indent3 := LangIndent(lang, 3, true)
	imports := ""
	imports = LangImport(lang, project, "vx/core", imports)
	contexttext := LangVar(lang, "context", contexttype, 3,
		LangPkgNameDot(lang, "vx/core")+"f_context_main(arglist)")
	maintext := "" +
		LangVar(lang, "mainval", stringtype, 3,
			LangPkgNameDot(lang, "vx/core")+"f_main(arglist)") +
		LangVarSet(lang, "output", 3,
			"mainval.vx_string()")
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
					LangVarFuture(lang, "asynccontext", contexttype, 3,
						LangFuncF(lang, contextfunc)+"(arglist)") +
					LangVal(lang, "context", contexttype, 3,
						LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, contexttype)+", asynccontext)")
			} else {
				contexttext = LangVal(lang, "context", contexttype, 3,
					LangFuncF(lang, contextfunc)+"(arglist)")
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
			mainfunctext := LangFuncF(lang, mainfunc) + "(" + params + ")"
			if mainfunc.async {
				maintext = "" +
					LangVarFuture(lang, "asyncstring", stringtype, 3, mainfunctext) +
					LangVal(lang, "mainstring", stringtype, 3,
						LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", asyncstring)")
			} else {
				maintext = LangVal(lang, "mainstring", stringtype, 3,
					mainfunctext)
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
	outputopen = LangVar(lang, "output", rawstringtype, 3, "\"\"")
	outputclose = LangVarSet(lang, "output", 3,
		"mainstring.vx_string()")
	switch lang.name {
	case "csharp":
		classopen = indent0 + "class App {\n"
		classclose = indent0 + "}\n"
		mainopen = indent1 + "static void Main(string[] args) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.Console.WriteLine(\"Untrapped Error!\" + e.ToString())" + lang.lineend +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
		outputprint = indent3 + "System.Console.WriteLine(output)" + lang.lineend
	case "java":
		classopen = indent0 + "public final class App {\n"
		classclose = indent0 + "}\n"
		mainopen = indent1 + "public static void main(String[] args) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.out.println(\"Untrapped Error!\" + e.toString())" + lang.lineend +
			indent2 + "}"
		arglistinit = LangVal(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
		outputprint = indent3 + "System.out.println(output)" + lang.lineend
	case "kotlin":
		mainopen = indent1 + "fun main(args : Array<String>) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (e : Exception) {" +
			indent3 + "println(e.toString())" +
			indent2 + "}"
		arglistinit = LangVal(lang, "arglist", anylisttype, 3,
			LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(args)")
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
