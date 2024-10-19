package vxlisp

import "strings"

func LangTestApp(
	lang *vxlang,
	project *vxproject,
	command *vxcommand,
	pkgprefix string) string {
	imports := ""
	imports += LangSpecificImport(
		lang,
		PackageCoreFromProject(project),
		imports)
	contexttext := LangVarStatic(
		lang, "arglist",
		anylisttype,
		1,
		LangTypeE(lang, anylisttype))
	if command.context == "" {
		contexttext += "" +
			LangVarStatic(
				lang,
				"context",
				contexttype,
				2,
				pkgprefix+LangPkgNameDot(lang, "vx/test")+"f_context_test(arglist)")
	} else {
		contextfunc := FuncFromProjectFuncname(project, command.context)
		if command.context != "" && contextfunc == emptyfunc {
			MsgLog(
				"Error! Context Not Found: (project (cmd :context " + command.context + "))")
		}
		if contextfunc != emptyfunc {
			packagecontext, ok := PackageFromProjectName(
				project, contextfunc.pkgname)
			if ok {
				imports += LangSpecificImport(
					lang,
					packagecontext,
					imports)
			}
			if contextfunc.async {
				contexttext += "" +
					LangVarStaticFuture(
						lang,
						"asynccontext",
						contexttype,
						1,
						LangFuncF(lang, contextfunc)+"(arglist)") +
					LangVarStatic(
						lang,
						"context",
						contexttype,
						1,
						LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, contexttype)+", asynccontext)")
			} else {
				contexttext += "" +
					LangVarStatic(
						lang,
						"context",
						contexttype,
						1,
						LangFuncF(lang, contextfunc)+"(arglist)")
			}
		}
	}
	tests := ""
	listpackage := project.listpackage
	testpackageprefix := LangSpecificTestPackagePrefix(lang)
	var listtestpackage []string
	for _, pkg := range listpackage {
		iscontinue := true
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			if pkg.name != "" {
				imports += LangSpecificTestImport(lang, pkg, imports)
				testpackage := "\n      " + testpackageprefix + LangSpecificPkgName(lang, pkg.name) + "Test.test_package(context)"
				listtestpackage = append(
					listtestpackage, testpackage)
				tests += LangSpecificTestPackage(lang, pkg, testpackagetype)
			}
		}
	}
	testpackages := StringFromListStringJoin(
		listtestpackage, ",")
	namespaceopen, namespaceclose := LangSpecificNamespaceOpenClose(
		lang, "AppTest")
	imports += LangSpecificTestImportExtra(lang)
	testbasics := LangSpecificTestAppBasic(lang)
	writetestsuite := LangSpecificTestWriteTestSuite(
		lang, testpackages)
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
		testbasics +
		tests +
		writetestsuite +
		namespaceclose
	return output
}

func LangTestCase(
	lang *vxlang,
	testvalues []vxvalue,
	testpkg string,
	testname string,
	testcasename string,
	fnc *vxfunc,
	path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestCase")
	output := ""
	g_ifuncdepth = 0
	if len(testvalues) > 0 {
		var listtestdescribe []string
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := LangFromValue(lang, testvalue, testpkg, fnc, 3, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			testdescribename := testcasename + "_testdescribe_" + StringFromInt(idx+1)
			desctext := "" +
				LangPkgNameDot(lang, "vx/core") + "vx_new(" +
				"\n      " + LangTypeT(lang, testdescribetype) + "," +
				"\n      \":describename\", \"" + LangTestFromValue(lang, testvalue) + "\"," +
				"\n      \":testresult\", " + descvaluetext +
				"\n    )"
			argcontext := NewArgContext()
			listarg := NewListArg()
			listarg = append(listarg, argcontext)
			fnc := NewFunc()
			fnc.name = testdescribename
			fnc.vxtype = testdescribetype
			fnc.listarg = listarg
			testdescribe := "" +
				LangFuncHeaderStatic(lang, "", fnc, 1, 0,
					LangVar(lang, "output", testdescribetype, 2, desctext))
			desctexts = append(desctexts, "\n        "+testdescribename+"(context)")
			listtestdescribe = append(listtestdescribe, testdescribe)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		testdescribes := StringFromListStringJoin(listtestdescribe, "")
		varoutput := LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testcasetype) + "," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        " + LangTypeT(lang, testdescribelisttype) + "," + describelist +
			"\n      )" +
			"\n    )"
		argcontext := NewArgContext()
		listarg := NewListArg()
		listarg = append(listarg, argcontext)
		fnc := NewFunc()
		fnc.name = testcasename
		fnc.vxtype = testcasetype
		fnc.listarg = listarg
		output = "" +
			LangFuncHeaderStatic(lang, "", fnc, 1, 0,
				LangVar(lang, "output", testcasetype, 2, varoutput)) +
			testdescribes
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

func LangTestFromFunc(
	lang *vxlang,
	fnc *vxfunc) (string, *vxmsgblock) {
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

func LangTestFromPackage(
	lang *vxlang,
	pkg *vxpackage,
	prj *vxproject,
	command *vxcommand,
	pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromPackage")
	pkgpath, pkgname := LangSpecificPackagePathFromPrefixName(
		lang, pkgprefix, pkg.name)
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
		covertype = append(
			covertype,
			"\":"+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if command.filter == "" {
		} else if NameFromType(typ) != command.filter {
			test = ""
		}
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(
				testall,
				pkgname+"Test.t_"+LangFromName(typ.alias)+"(context)")
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
		coverconst = append(
			coverconst,
			"\":"+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if command.filter == "" {
		} else if NameFromConst(cnst) != command.filter {
			test = ""
		}
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(
				testall,
				pkgname+"Test.c_"+LangFromName(cnst.alias)+"(context)")
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
			coverfunc = append(
				coverfunc,
				"\":"+fncid+LangIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
			if command.filter == "" {
			} else if NameFromFunc(fnc) != command.filter {
				test = ""
			}
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(
					testall,
					pkgname+"Test.f_"+LangFromName(fnc.alias)+LangIndexFromFunc(fnc)+"(context)")
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
		scovertype = LangTypeE(lang, intmaptype)
	} else {
		scovertype = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n        " + strings.Join(covertype, ",\n        ") +
			"\n      )"
	}
	scoverconst := ""
	if len(coverconst) == 0 {
		scoverconst = LangTypeE(lang, intmaptype)
	} else {
		scoverconst = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n        " + strings.Join(coverconst, ",\n        ") +
			"\n      )"
	}
	scoverfunc := ""
	if len(coverfunc) == 0 {
		scoverfunc = LangTypeE(lang, intmaptype)
	} else {
		scoverfunc = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n        " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n        " + strings.Join(coverfunc, ",\n        ") +
			"\n      )"
	}
	vartestcases := ""
	varoutput := ""
	if len(testall) == 0 {
		varoutput = LangTypeE(lang, testcaselisttype)
	} else {
		varoutput = LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testcaselisttype) + "," +
			"\n      testcases" +
			"\n    )"
		vartestcases = LangSpecificTestVarTestCases(
			lang, testall)
	}
	argcontext := NewArgContext()
	listarg := NewListArg()
	listarg = append(listarg, argcontext)
	fnctestcases := NewFunc()
	fnctestcases.name = "test_cases"
	fnctestcases.vxtype = testcaselisttype
	fnctestcases.listarg = listarg
	testcases := "" +
		LangFuncHeaderStatic(lang, "", fnctestcases, 1, 0,
			vartestcases+
				LangVar(lang, "output", testcaselisttype, 2, varoutput))
	fnctestcoveragesummary := NewFunc()
	fnctestcoveragesummary.name = "test_coveragesummary"
	fnctestcoveragesummary.vxtype = testcoveragesummarytype
	testcoveragesummary := "" +
		LangFuncHeaderStatic(lang, "", fnctestcoveragesummary, 1, 0,
			LangVar(lang, "output", testcoveragesummarytype, 2,
				LangPkgNameDot(lang, "vx/core")+"vx_new("+
					"\n      "+LangTypeT(lang, testcoveragesummarytype)+","+
					"\n      \":testpkg\", \""+pkg.name+"\", "+
					"\n      \":constnums\", "+LangTypeCoverageNumsValNew(lang, coverconstpct, coverconstcnt, coverconsttotal)+", "+
					"\n      \":docnums\", "+LangTypeCoverageNumsValNew(lang, coverdocpct, coverdoccnt, coverdoctotal)+", "+
					"\n      \":funcnums\", "+LangTypeCoverageNumsValNew(lang, coverfuncpct, coverfunccnt, coverfunctotal)+", "+
					"\n      \":bigospacenums\", "+LangTypeCoverageNumsValNew(lang, coverbigospacepct, coverbigospacecnt, coverbigospacetotal)+", "+
					"\n      \":bigotimenums\", "+LangTypeCoverageNumsValNew(lang, coverbigotimepct, coverbigotimecnt, coverbigotimetotal)+", "+
					"\n      \":totalnums\", "+LangTypeCoverageNumsValNew(lang, coverpct, covercnt, covertotal)+", "+
					"\n      \":typenums\", "+LangTypeCoverageNumsValNew(lang, covertypepct, covertypecnt, covertypetotal)+
					"\n    )"))
	fnctestcoveragedetail := NewFunc()
	fnctestcoveragedetail.name = "test_coveragedetail"
	fnctestcoveragedetail.vxtype = testcoveragedetailtype
	testcoveragedetail := "" +
		LangFuncHeaderStatic(lang, "", fnctestcoveragedetail, 1, 0,
			LangVar(lang, "output", testcoveragedetailtype, 2,
				LangPkgNameDot(lang, "vx/core")+"vx_new("+
					"\n      "+LangTypeT(lang, testcoveragedetailtype)+","+
					"\n      \":testpkg\", \""+pkg.name+"\","+
					"\n      \":typemap\", "+scovertype+", "+
					"\n      \":constmap\", "+scoverconst+", "+
					"\n      \":funcmap\", "+scoverfunc+
					"\n    )"))
	fnctestpackage := NewFunc()
	fnctestpackage.name = "test_package"
	fnctestpackage.vxtype = testpackagetype
	fnctestpackage.listarg = listarg
	testpackage := "" +
		LangFuncHeaderStatic(lang, "", fnctestpackage, 1, 0,
			LangVar(lang, "testcaselist", testcaselisttype, 2, "test_cases(context)")+
				LangVar(lang, "output", testpackagetype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new("+
						"\n      "+LangTypeT(lang, testpackagetype)+","+
						"\n      \":testpkg\", \""+pkg.name+"\", "+
						"\n      \":caselist\", testcaselist,"+
						"\n      \":coveragesummary\", test_coveragesummary(),"+
						"\n      \":coveragedetail\", test_coveragedetail()"+
						"\n    )"))
	body := "" +
		typetexts +
		consttexts +
		functexts +
		testcases +
		testcoveragesummary +
		testcoveragedetail +
		testpackage
	imports := LangSpecificPackageImports(
		lang, pkg, pkgprefix, body, true)
	namespaceopen, namespaceclose := LangSpecificTestNamespaceOpenClose(
		lang, pkgpath)
	packageopen, packageclose := LangSpecificTestPackageOpenClose(
		lang, pkgname)
	output := "" +
		namespaceopen +
		imports +
		packageopen +
		body +
		packageclose +
		namespaceclose
	return output, msgblock
}

func LangTestFromType(
	lang *vxlang,
	typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromType")
	testvalues := typ.testvalues
	testpkg := typ.pkgname
	testname := typ.name
	testcasename := "t_" + LangFromName(typ.alias)
	fnc := emptyfunc
	path := typ.pkgname + "/" + typ.name
	output, msgs := LangTestCase(
		lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromValue(
	lang *vxlang,
	value vxvalue) string {
	var output = ""
	output = LangSpecificFromText(lang, value.textblock.text)
	return output
}
