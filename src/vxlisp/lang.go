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
	indent int,
	forvar string,
	typ *vxtype,
	listvar string,
	body string) string {
	sindent := "\n" + StringRepeat("  ", indent)
	header := LangForListHeader(lang, indent,
		forvar, typ, listvar)
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
	pkgpath, pkgname := LangPackagePathFromPrefixName(
		lang, pkgprefix, pkg.name)
	specialcode := project.mapnative[pkg.name+"_"+lang.name+".txt"]
	if specialcode != "" {
		specialcode += "\n"
	}
	typkeys := ListKeyFromMapType(pkg.maptype)
	typetexts := ""
	packageline := LangNativePackageLine(
		lang, pkg.name, pkgpath)
	namespaceopen, namespaceclose := LangNativeNamespaceOpenClose(
		lang, pkgname, pkgpath)
	packagestatic := "" +
		LangVarCollection(lang, 2, rawmaptype, anytype,
			"maptype", ":new") +
		LangVarCollection(lang, 2, rawmaptype, anytype,
			"mapconst", ":new") +
		LangVarCollection(lang, 2, rawmaptype, functype,
			"mapfunc", ":new")
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
	indent int,
	value vxvalue,
	pkgname string,
	parentfn *vxfunc,
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
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangPkgName(lang, "vx/core") + lang.pkgref + "vx_new_decimal(\"" + valstr + "\")"
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
	return LangIsTypeText(
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
				corepkgname := LangPkgName(lang, "vx/core")
				lambdavar := LangVal(lang, 1, argtype,
					lambdaargname,
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
	return LangTypeNameSimple(
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
	output := LangPkgName(lang, pkgname) + lang.pkgref
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

func LangVal(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
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
	indent int,
	varname string,
	vartype *vxtype,
	varvalue string) string {
	output := LangVarClassAll(lang, indent,
		varname, vartype, true, false, varvalue)
	return output
}

func LangVar(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
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
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
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
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
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
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
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
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarAll(
		lang,
		indent,
		vartype,
		emptytype,
		varname,
		varvalue,
		false,
		false,
		false,
		false,
		false,
		true)
	return output
}

func LangVarOld(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	subtype *vxtype,
	varname string,
	varvalue string,
	isconst bool,
	isfuture bool) string {
	return LangVarAll(
		lang, indent, vartype, subtype, varname, varvalue, isconst, isfuture, false, false, false, false)
}

func LangVarClass(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	output := LangVarClassAll(lang, indent,
		varname, vartype, false, false, varvalue)
	return output
}

func LangVarClassNullable(
	lang *vxlang,
	indent int,
	varname string,
	vartype *vxtype,
	varvalue string) string {
	output := LangVarClassAll(lang, indent,
		varname, vartype, false, true, varvalue)
	return output
}

func LangVarCollection(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	subtype *vxtype,
	varname string,
	varvalue string) string {
	return LangVarAll(
		lang, indent, vartype, subtype, varname, varvalue, false, false, false, false, false, false)
}

func LangVarProp(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	subtype *vxtype,
	varname string,
	varvalue string) string {
	return LangVarAll(
		lang, indent, vartype, subtype, varname, varvalue, false, false, false, true, false, false)
}

func LangValStatic(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	return LangVarAll(
		lang, indent, vartype, emptytype, varname, varvalue, true, false, true, false, false, false)
}

func LangVarStatic(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	return LangVarAll(
		lang, indent, vartype, emptytype, varname, varvalue, false, false, true, false, false, false)
}

func LangVarStaticFuture(
	lang *vxlang,
	indent int,
	vartype *vxtype,
	varname string,
	varvalue string) string {
	return LangVarAll(
		lang, indent, vartype, emptytype, varname, varvalue, false, true, true, false, false, false)
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
		LangFuncHeader(lang, 2,
			prefix, funcvxargname, 0,
			LangVar(lang, 3, arg.vxtype,
				"output",
				LangTypeE(lang, arg.vxtype))+
				LangVarNull(lang, 3, arg.vxtype,
					"testnull",
					"vx_p_"+argname)+
				LangIfThen(lang, 3,
					"testnull != null",
					LangVarSet(lang, 4,
						"output", "testnull"))+
				LangIfEnd(lang, 3))
	return output
}

func LangApp(
	lang *vxlang,
	project *vxproject,
	cmd *vxcommand) string {
	imports := LangImport(
		lang,
		PackageCoreFromProject(project),
		"")
	contexttext := LangVar(lang, 3, contexttype,
		"context",
		LangPkgNameDot(lang, "vx/core")+"f_context_main(arglist)")
	maintext := "" +
		LangVar(lang, 3, stringtype,
			"mainval",
			LangPkgNameDot(lang, "vx/core")+"f_main(arglist)") +
		LangVarSet(lang, 3,
			"output",
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
				imports += LangImport(
					lang,
					PackageFromProjectFunc(project, contextfunc),
					imports)
			}
			if contextfunc.async {
				contexttext = "" +
					LangVarFuture(lang, 3, contexttype,
						"asynccontext",
						LangFuncF(lang, contextfunc)+"(arglist)") +
					LangVal(lang, 3, contexttype,
						"context",
						LangPkgNameDot(lang, "vx/core")+
							"vx_sync_from_async("+LangTypeT(lang, contexttype)+", asynccontext)")
			} else {
				contexttext = LangVal(lang, 3, contexttype,
					"context",
					LangFuncF(lang, contextfunc)+"(arglist)")
			}
		}
		if mainfunc != emptyfunc {
			if mainfunc.pkgname != "" {
				imports += LangImport(
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
					LangVarFuture(lang, 3, stringtype,
						"asyncstring", mainfunctext) +
					LangVal(lang, 3, stringtype,
						"mainstring",
						LangPkgNameDot(lang, "vx/core")+
							"vx_sync_from_async("+LangTypeT(lang, stringtype)+
							", asyncstring)")
			} else {
				maintext = LangVal(lang, 3, stringtype,
					"mainstring",
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
	outputopen := LangVar(lang, 3, rawstringtype,
		"output", "\"\"")
	outputclose := LangVarSet(lang, 3,
		"output",
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
