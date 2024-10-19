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
	forcemulti bool
}

var g_ifuncdepth = 0

func LangFilesFromProjectCmd(
	lang *vxlang,
	project *vxproject,
	command *vxcommand) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFilesFromProjectCmd")
	var files []*vxfile
	cmdpath := PathFromProjectCmd(project, command)
	pkgprefix, apppath, testpath := LangNativeProjectPkgPrefixAppPathTestPath(
		lang, project, command, cmdpath)
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "App" + lang.sourcefile
		file.path = apppath
		file.text = LangApp(
			lang, project, command)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "AppTest" + lang.sourcefile
		file.path = testpath
		file.text = LangTestApp(
			lang, project, command, pkgprefix)
		files = append(files, file)
		file = NewFile()
		file.name = "TestLib" + lang.sourcefile
		file.path = testpath
		file.text = LangTestLib(lang)
		files = append(files, file)
	}
	pkgs := ListPackageFromProject(project)
	for _, pkg := range pkgs {
		subprefix, subdomainpath := LangNativePackageSubPrefixSubDomainPath(
			lang, command, pkg)
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
		pkgpath = LangNativePkgpath(lang, pkgpath)
		switch command.code {
		case ":source":
			text, msgs := LangFromPackage(
				lang, pkg, project, subprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + lang.sourcefile
			file.path = cmdpath + "/" + subdomainpath + pkgpath
			file.text = text
			files = append(files, file)
		case ":test":
			text, msgs := LangTestFromPackage(
				lang, pkg, project, command, subprefix)
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

func LangFolderCopyTestdataFromProjectPath(
	project *vxproject,
	targetpath string) *vxmsgblock {
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
	header := LangNativeForListHeader(
		lang, forvar, typ, listvar, indent)
	footer := sindent + "}"
	output := "" +
		header +
		body +
		footer
	return output
}

func LangFromName(
	name string) string {
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
	pkgpath, pkgname := LangNativePackagePathFromPrefixName(
		lang, pkgprefix, pkg.name)
	specialcode := project.mapnative[pkg.name+"_"+lang.name+".txt"]
	typkeys := ListKeyFromMapType(pkg.maptype)
	typetexts := ""
	packageline := LangNativePackageLine(
		lang, pkg.name, pkgpath)
	namespaceopen, namespaceclose := LangNativeNamespaceOpenClose(
		lang, pkgname)
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
	staticopen, staticclose := LangNativePackageStaticOpenClose(lang)
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constlate, msgs := LangConst(lang, cnst, project, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		staticopen += constlate
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
	staticopen += packagestatic
	body := "" +
		specialcode +
		typetexts +
		consttexts +
		functexts +
		staticopen +
		staticclose
		//		emptytypes
	imports := LangNativePackageImports(
		lang, pkg, pkgprefix, body, false)
	output := "" +
		packageline +
		imports +
		namespaceopen +
		body +
		namespaceclose
	return output, msgblock
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
			valstr = LangNativePkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = LangFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = LangNativePkgName(lang, valconst.pkgname) + ".c_" + LangFromName(valconst.alias)
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
		valstr += LangNativePkgName(lang, valfunc.pkgname) + lang.typeref + "t_" + LangFromName(valfunc.alias)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = LangNativePkgName(lang, valtype.pkgname) + lang.typeref + "t_" + LangFromName(valtype.alias)
	case "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = valstr
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			valstr = valstr[1 : len(valstr)-1]
			if encode {
				output = LangNativeFromText(lang, valstr)
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
			output = LangNativePkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNativePkgName(lang, "vx/core") + lang.pkgref + "vx_new_decimal(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNativePkgName(lang, "vx/core") + lang.pkgref + "vx_new_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNativePkgName(lang, "vx/core") + lang.pkgref + "vx_new_int(" + valstr + ")"
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

func LangArgGenericFromType(
	lang *vxlang,
	typ *vxtype) vxarg {
	typename := StringFromStringFindReplace(
		typ.name, "-", "_")
	output := NewArg("generic_" + typename)
	output.vxtype = typ
	output.isgeneric = true
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

func LangGenericFromType(
	lang *vxlang,
	typ *vxtype) string {
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

func LangIndexFromFunc(
	fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func LangIsType(
	lang *vxlang,
	svar string,
	typ *vxtype) string {
	return LangNativeIsTypeText(
		lang, svar, LangNameTypeFullFromType(lang, typ))
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
		argtype := lambdaarg.vxtype
		lambdaargname := LangFromName(lambdaarg.alias) + "_lmb"
		lambdaargnames = append(lambdaargnames, lambdaargname)
		switch NameFromType(argtype) {
		case "vx/core/any", "vx/core/any-1":
			lambdatypename := LangNativeArgTypeName(
				lang, lambdaargname, anytype)
			lambdatypenames = append(
				lambdatypenames, lambdatypename)
		default:
			switch lambdaarg.name {
			case "key":
				lambdatypename := LangNativeArgTypeName(
					lang, lambdaargname, argtype)
				lambdatypenames = append(
					lambdatypenames, lambdatypename)
			default:
				argvaltname := LangTypeT(lang, argtype)
				lambdatypename := LangNativeArgTypeNameValue(
					lang, lambdaargname, anytype)
				lambdatypenames = append(lambdatypenames, lambdatypename)
				corepkgname := LangNativePkgName(lang, "vx/core")
				lambdavar := LangVal(lang, lambdaargname, argtype, 1,
					corepkgname+lang.pkgref+"f_any_from_any("+argvaltname+", "+lambdaargname+"_any)")
				lambdavars = append(lambdavars, lambdavar)
			}
		}
	}
	lambdanames := StringFromListStringJoin(lambdaargnames, ", ")
	lambdatext := StringFromListStringJoin(lambdatypenames, ", ")
	lambdavartext := ""
	if len(lambdavars) > 0 {
		lambdavartext = StringFromListStringJoin(lambdavars, "")
	}
	return lambdatext, lambdavartext, lambdanames
}

func LangNameFromArg(
	lang *vxlang,
	arg vxarg) string {
	return LangFromName(arg.alias)
}

func LangNameFromType(
	lang *vxlang,
	typ *vxtype) string {
	return LangNativeTypeNameSimple(
		lang, typ, false)
}

func LangNameTypeFromTypeSimple(
	lang *vxlang,
	typ *vxtype,
	simple bool) string {
	output := LangNativeTypeNameFullSimple(
		lang, typ, simple)
	return output
}

func LangNameTypeFullFromType(
	lang *vxlang,
	typ *vxtype) string {
	return LangNativeTypeNameFullSimple(
		lang, typ, true)
}

func LangPkgNameDot(
	lang *vxlang,
	pkgname string) string {
	output := LangNativePkgName(lang, pkgname) + lang.pkgref
	return output
}

func LangTypeCoverageNumsValNew(
	lang *vxlang,
	pct int,
	tests int,
	total int) string {
	return "" +
		LangPkgNameDot(lang, "vx/core") + "vx_new(" +
		LangTypeT(lang, testcoveragenumstype) + ", " +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func LangWriteFromProjectCmd(
	lang *vxlang,
	project *vxproject,
	command *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("LangWriteFromProjectCmd")
	files, msgs := LangFilesFromProjectCmd(
		lang, project, command)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	msgs = WriteListFile(files)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	switch command.code {
	case ":test":
		targetpath := PathFromProjectCmd(project, command)
		targetpath = LangNativeTestTargetPath(
			lang, targetpath)
		targetpath += "/resources"
		msgs := LangFolderCopyTestdataFromProjectPath(project, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
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

func LangVal(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangNativeVarAll(
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
	output := LangNativeVarClassAll(
		lang, varname, vartype, indent, true, false, varvalue)
	return output
}

func LangVar(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangNativeVarAll(
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
	output := LangNativeVarAll(
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
	output := LangNativeVarAll(
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
	output := LangNativeVarAll(
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
	output := LangNativeVarAll(
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
	return LangNativeVarAll(lang, varname, vartype, subtype, varvalue, indent, isconst, isfuture, false, false, false, false)
}

func LangVarClass(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangNativeVarClassAll(
		lang, varname, vartype, indent, false, false, varvalue)
	return output
}

func LangVarClassNullable(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	output := LangNativeVarClassAll(
		lang, varname, vartype, indent, false, true, varvalue)
	return output
}

func LangVarCollection(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	indent int,
	varvalue string) string {
	return LangNativeVarAll(
		lang, varname, vartype, subtype, varvalue, indent, false, false, false, false, false, false)
}

func LangVarProp(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	subtype *vxtype,
	indent int,
	varvalue string) string {
	return LangNativeVarAll(lang, varname, vartype, subtype, varvalue, indent, false, false, false, true, false, false)
}

func LangValStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangNativeVarAll(lang, varname, vartype, emptytype, varvalue, indent, true, false, true, false, false, false)
}

func LangVarStatic(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangNativeVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, false, true, false, false, false)
}

func LangVarStaticFuture(
	lang *vxlang,
	varname string,
	vartype *vxtype,
	indent int,
	varvalue string) string {
	return LangNativeVarAll(lang, varname, vartype, emptytype, varvalue, indent, false, true, true, false, false, false)
}

func LangVxArgFromArg(
	lang *vxlang,
	prefix string,
	arg vxarg) string {
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
				LangNativeVarSet(lang, "output", 4, "testnull")+
				"\n      }")
	return output
}

func LangApp(
	lang *vxlang,
	project *vxproject,
	cmd *vxcommand) string {
	imports := LangNativeImport(
		lang,
		PackageCoreFromProject(project),
		"")
	contexttext := LangVar(lang, "context", contexttype, 3,
		LangPkgNameDot(lang, "vx/core")+"f_context_main(arglist)")
	maintext := "" +
		LangVar(lang, "mainval", stringtype, 3,
			LangPkgNameDot(lang, "vx/core")+"f_main(arglist)") +
		LangNativeVarSet(lang, "output", 3,
			"mainval.vx_string()")
	if cmd.context == "" && cmd.main == "" {
	} else {
		contextfunc := FuncFromProjectFuncname(project, cmd.context)
		mainfunc := FuncFromProjectFuncname(project, cmd.main)
		if cmd.context != "" && contextfunc == emptyfunc {
			MsgLog(
				"Error! Context Not Found: (project (cmd :context " + cmd.context + "))")
		}
		if cmd.main != "" && mainfunc == emptyfunc {
			MsgLog(
				"Error! Main Not Found: (project (cmd :main " + cmd.main + "))")
		}
		if contextfunc != emptyfunc {
			if contextfunc.pkgname == "" {
			} else if contextfunc.pkgname != mainfunc.pkgname {
				imports += LangNativeImport(
					lang,
					PackageFromProjectFunc(project, contextfunc),
					imports)
			}
			if contextfunc.async {
				contexttext = "" +
					LangVarFuture(lang, "asynccontext", contexttype, 3,
						LangFuncF(lang, contextfunc)+"(arglist)") +
					LangVal(lang, "context", contexttype, 3,
						LangPkgNameDot(lang, "vx/core")+
							"vx_sync_from_async("+LangTypeT(lang, contexttype)+", asynccontext)")
			} else {
				contexttext = LangVal(lang, "context", contexttype, 3,
					LangFuncF(lang, contextfunc)+"(arglist)")
			}
		}
		if mainfunc != emptyfunc {
			if mainfunc.pkgname != "" {
				imports += LangNativeImport(
					lang,
					PackageFromProjectFunc(project, mainfunc),
					imports)
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
						LangPkgNameDot(lang, "vx/core")+
							"vx_sync_from_async("+LangTypeT(lang, stringtype)+
							", asyncstring)")
			} else {
				maintext = LangVal(lang, "mainstring", stringtype, 3,
					mainfunctext)
			}
		}
	}
	packageopen := ""
	classopen, classclose := LangNativeAppClassOpenClose(lang)
	mainopen, mainclose := LangNativeAppMainOpenClose(lang)
	tryopen, tryclose := LangNativeAppTryOpenClose(lang)
	outputprint := LangNativeAppOutputPrint(lang)
	arglistinit := LangNativeAppArgListInit(lang)
	outputopen := LangVar(
		lang, "output", rawstringtype, 3, "\"\"")
	outputclose := LangNativeVarSet(lang, "output", 3,
		"mainstring.vx_string()")
	output := "" +
		"/**" +
		"\n * App" +
		"\n */" +
		"\n" +
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
