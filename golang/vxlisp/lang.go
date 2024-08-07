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
	output.lambdafunc = "->"
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
			typetext = LangTypeClassNameFull(lang, typ)
		}
	default:
		typetext = LangTypeClassNameFull(lang, typ)
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
	switch lang.name {
	case "csharp":
		output = sindent + "foreach (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " in " + listvar + ") {"
	case "java":
		output = sindent + "for (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " : " + listvar + ") {"
	case "kotlin":
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
	case "java", "kotlin":
		packageline = "package " + pkgpath + lang.lineend + "\n"
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	packagestatic := "" +
		LangVarCollection(lang, "maptype", rawmaptype, anytype, 2,
			LangVxNewMap(lang, anytype, "")) +
		LangVarCollection(lang, "mapconst", rawmaptype, anytype, 2,
			LangVxNewMap(lang, anytype, "")) +
		LangVarCollection(lang, "mapfunc", rawmaptype, functype, 2,
			LangVxNewMap(lang, functype, ""))
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
			"\n    mapconst.put(\"" + cnst.name + "\", " + LangNameCFromConst(lang, cnst) + ")" + lang.lineend
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

func LangFromValue(lang *vxlang, value vxvalue, pkgname string, parentfn *vxfunc, indent int, encode bool, test bool, path string) (string, *vxmsgblock) {
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
			output += LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "f_log_1(" + LangTypeT(lang, fnc.vxtype) + ", " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_string(\"" + funcname + "\"), "
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
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangFuncName(fnc) + "("
				}
			default:
				if fnc.argname != "" {
					output += LangPkgNameDot(lang, "vx/core") + "vx_any_from_func("
					argtexts = append(argtexts, LangTypeT(lang, fnc.vxtype))
					argtexts = append(argtexts, LangFromName(fnc.argname))
					if lang == langcpp {
						multiflag = true
					}
				} else {
					output += LangPkgNameDot(lang, fnc.pkgname) + "f_" + LangFuncName(fnc) + "("
				}
			}
			if !isskip {
				if fnc.isgeneric {
					switch funcname {
					case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
					default:
						if fnc.generictype != nil {
							genericarg := LangTypeTGeneric(lang, fnc.vxtype)
							argtexts = append(argtexts, genericarg)
						}
					}
				}
				if fnc.context {
					argtexts = append(argtexts, "context")
				}
				subindent := indent + 1
				//ssubindent := StringRepeat("  ", subindent)
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
								argvalinstance = LangTypeT(lang, argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = " + LangPkgNameDot(lang, "vx/core") + "f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any)" + lang.lineend
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
									LangVar(lang, outputname, anytype, 1, workvalue) +
									"\n  return " + outputname + lang.lineend
								switch funcarg.vxtype.name {
								case "any<-any-key-value-async", "any<-key-value-async",
									"any<-reduce-async", "any<-reduce-next-async":
									argtext = "" +
										LangTypeT(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											LangPkgNameDot(lang, "vx/core") + "t_any_from_any_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								workvalue, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work := "" +
									LangVar(lang, outputname, anytype, 1, workvalue) +
									"\n  return " + outputname + lang.lineend
								switch funcarg.vxtype.name {
								case "any<-int", "any<-int-any",
									"any<-any-key-value", "any<-key-value",
									"any<-reduce", "any<-reduce-next",
									"boolean<-any":
									argtext = "" +
										LangTypeT(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
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
												arglineindent + lang.future + "<" + LangTypeName(lang, anytype) + "> " + outputname + " = " + LangPkgNameDot(lang, "vx/core") + "vx_async_from_async_fn(future_" + LangFromName(lambdaarg.name) + ", (" + LangFromName(lambdaarg.name) + ") " + lang.lambdafunc + " {"
											aftertext += "" +
												arglineindent + "})" + lang.lineend +
												arglineindent + "return " + outputname + lang.lineend
											argindent += 1
										} else {
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + LangFinalArg(lang) + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + lang.lineend
										}
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 2, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangPkgNameDot(lang, "vx/core") + "t_any_from_func_async" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										LangVar(lang, outputname, anytype, 2, work) +
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
										lambdatext += LangVar(lang, LangFromName(lambdaarg.name), lambdaarg.vxtype, argindent,
											lambdavaluetext)
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangPkgNameDot(lang, "vx/core") + "t_any_from_func" + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
										lambdatext +
										LangVar(lang, outputname, anytype, argindent, work) +
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
										"\n  return " + work + lang.lineend +
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
									outputtype := LangTypeName(lang, anytype)
									if funcargfunc.async {
										outputtype = lang.future + "<" + LangTypeName(lang, anytype) + ">"
									}
									g_ifuncdepth += 1
									outputname := "output_" + StringFromInt(g_ifuncdepth)
									argtext = "" +
										LangTypeT(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") " + lang.lambdafunc + " {" +
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
									work = LangPkgNameDot(lang, "vx/core") + "f_async(" + LangTypeT(lang, argfunctype) + ",\n" + sworkindent + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "\n  return " + work + lang.lineend
								}
								argtext = "" +
									LangTypeT(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new(() " + lang.lambdafunc + " {" +
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
								argtext = "  " + StringFromStringIndent(argtext, "  ")
							} else {
								multiflag = true
								argtext = "" +
									LangPkgNameDot(lang, "vx/core") + "vx_new(" +
									"\n  " + LangTypeT(lang, funcarg.vxtype) + "," +
									"\n  " + StringFromStringIndent(argtext, "  ")
							}
						}
						if argtext != "" {
							argtexts = append(argtexts, argtext)
						}
					}
				}
			}
			if multiline {
				output += "" +
					"\n" + sindent +
					"  " +
					StringFromStringIndent(
						StringFromListStringJoin(argtexts, ",\n"),
						sindent+"  ")
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

func LangImport(lang *vxlang, project *vxproject, pkgname string, imports string) string {
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
		/*
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				switch lang.name {
				case "kotlin":
					returntype = "Unit"
				default:
					returntype = "void"
				}
			default:
		*/
		if fnc.async {
			returntype = lang.future + "<" + LangTypeName(lang, anytype) + ">"
		}
		//		}
		var args []string
		/*
			if fnc.generictype != nil {
				argname := LangFromName(fnc.generictype.alias)
				argtypename := LangNameTypeFromTypeSimple(lang, fnc.generictype, true)
				args = append(args, argtypename+" "+argname)
			}
		*/
		if fnc.context {
			args = append(args, LangTypeName(lang, contexttype)+" context")
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
				"\n    fun IFn(" + argnames + ") : " + returntype + lang.lineend +
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
			lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
		default:
			switch lambdaarg.name {
			case "key":
				argtypename := LangTypeName(lang, argtype)
				lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
			default:
				argvaltype = LangNameTypeFullFromType(lang, argtype)
				argvaltname := LangTypeT(lang, argtype)
				argtypename := LangTypeName(lang, anytype)
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
	name := "Class_" + LangFuncName(fnc)
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

func LangTypeClassNameFull(lang *vxlang, typ *vxtype) string {
	name := LangNameClassFromType(lang, typ)
	if typ.pkgname != "" {
		name = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangTypeE(lang *vxlang, typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref
		switch lang.name {
		case "cpp":
			output += "vx_empty"
		default:
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
	name := "e_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "f_" + LangFuncName(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFromArg(lang *vxlang, arg vxarg) string {
	return LangFromName(arg.alias)
}

func LangFuncName(fnc *vxfunc) string {
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

func LangNameFromType(lang *vxlang, typ *vxtype) string {
	return LangTypeNameSimple(lang, typ, false)
}

func LangTypeNameSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	alias := typ.alias
	switch typ {
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
		case "java":
			name = "Boolean"
		case "kotlin":
			name = "Boolean"
		}
	case rawfloattype:
		switch lang.name {
		case "csharp", "java", "kotlin":
			name = "Float"
		}
	case rawifntype:
		switch lang.name {
		case "csharp", "java", "kotlin":
			name = "IFn"
		}
	case rawinttype:
		switch lang.name {
		case "csharp", "java":
			name = "int"
		case "kotlin":
			name = "Int"
		}
	case rawintegertype:
		switch lang.name {
		case "csharp", "java":
			name = "Integer"
		case "kotlin":
			name = "Int"
		}
	case rawlisttype:
		switch lang.name {
		case "csharp", "java", "kotlin":
			name = "List"
		}
	case rawlistanytype:
		switch lang.name {
		case "csharp", "java", "kotlin":
			name = "List<" + LangTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawlistunknowntype:
		switch lang.name {
		case "csharp":
			name = "List<object>"
		case "java":
			name = "List<?>"
		case "kotlin":
			name = "List<Any>"
		}
	case rawmaptype:
		switch lang.name {
		case "csharp":
			name = "Vx.Core.Map"
		case "java", "kotlin":
			name = "Map"
		}
	case rawmapanytype:
		switch lang.name {
		case "cpp":
			name = "std::map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case "csharp":
			name = "Vx.Core.Map<string, " + LangTypeNameSimple(lang, anytype, true) + ">"
		case "java", "kotlin":
			name = "Map<String, " + LangTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		switch lang.name {
		case "cpp":
			name = "std::string"
		case "csharp":
			name = "string"
		case "java", "kotlin", "swift":
			name = "String"
		}
	case rawobjecttype:
		switch lang.name {
		case "csharp":
			name = "object"
		case "java":
			name = "Object"
		case "kotlin":
			name = "Any"
		}
	case rawvoidtype:
		switch lang.name {
		case "kotlin":
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

func LangNameFuncFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "Func_" + LangFuncName(fnc)
	return name
}

func LangNameFuncFullFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := LangNameFuncFromFunc(lang, fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
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
			name = "Integer"
		default:
			name = "int"
		}
	case rawintegertype:
		switch lang.name {
		case "csharp":
			name = "int"
		case "java", "kotlin":
			name = "Integer"
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
				name = LangNameFromPkgName(lang, typ.pkgname)
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
	output = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangFuncName(fnc) + "(" + argnames + ")" + lang.lineend
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
		name = LangNameFromPkgName(lang, name)
	case "kotlin":
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = StringFromStringFindReplace(pkgname, "/", "_")
		name = LangNameFromPkgName(lang, name)
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

func LangPkgNameDot(lang *vxlang, pkgname string) string {
	output := LangNameFromPkgName(lang, pkgname) + lang.pkgref
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
		lang, varname, vartype, indent, true, varvalue)
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
		true)
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
		true)
	return output
}

func LangVarOld(lang *vxlang, varname string, vartype *vxtype, subtype *vxtype,
	varvalue string, indent int, isconst bool, isfuture bool) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, isconst, isfuture, false, false, false)
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
	isgeneric bool) string {
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
		case rawmaptype:
			typetext = "Vx.Core.Map<string, " + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawlistunknowntype:
			typetext = "List<object>"
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
		if varvalue == "null" {
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
		case rawmaptype:
			typetext = "Map<String, " + LangNameTypeFullFromType(lang, subtype) + ">"
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
		case rawmaptype:
			typetext = "Map<String, " + LangNameTypeFullFromType(lang, subtype) + ">"
		case rawlistunknowntype:
			typetext = "List<Any>"
		default:
			if isgeneric && vartype.isgeneric {
				typetext = LangGenericFromType(lang, vartype)
			} else {
				typetext = LangNameTypeFullFromType(lang, vartype)
			}
		}
		if isconst {
			output += "val"
		} else {
			output += "var"
		}
		output += " " + varname
		output += " : " + typetext
		if varvalue != "" {
			if isfuture {
				output += " = await " + svalue
			} else if (svalue == "\"\"") && (vartype == rawstringtype) {
			} else {
				output += " = " + svalue
			}
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
		lang, varname, vartype, indent, false, varvalue)
	return output
}

func LangVarValue(
	lang *vxlang,
	vartype *vxtype,
	varvalue string) string {
	output := varvalue
	switch varvalue {
	case ":new":
		classname := LangTypeClassNameFull(lang, vartype)
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

func LangVarClassAll(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	isconst bool,
	varvalue string) string {
	classname := LangTypeClassNameFull(lang, vartype)
	sindent := "\n" + StringRepeat("  ", indent)
	svalue := LangVarValue(lang, vartype, varvalue)
	output := sindent
	switch lang.name {
	case "kotlin":
		prefix := "var"
		if isconst {
			prefix = "val"
		}
		output += "" +
			prefix + " " + varname + " : " + classname + " = " + svalue
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
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, false, false, false, false, false)
}

func LangVarProp(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, subtype, varvalue, indent, false, false, false, true, false)
}

func LangValStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, true, false, true, false, false)
}

func LangVarStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, false, true, false, false)
}

func LangVarStaticFuture(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, true, true, false, false)
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
				"\n      if (this.vx_p_"+argname+" != null) {"+
				LangVarSet(lang, "output", 4,
					"this.vx_p_"+argname)+
				"\n      }")
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
	}
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
						LangNameFFromFunc(lang, contextfunc)+"(arglist)") +
					LangVal(lang, "context", contexttype, 3,
						LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async(vx_core::t_context, asynccontext)")
			} else {
				contexttext = LangVal(lang, "context", contexttype, 3,
					LangNameFFromFunc(lang, contextfunc)+"(arglist)")
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
					LangVarFuture(lang, "asyncstring", stringtype, 3, mainfunctext) +
					LangVal(lang, "mainstring", stringtype, 3,
						LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangPkgNameDot(lang, "vx/core")+"t_string, asyncstring)")
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
