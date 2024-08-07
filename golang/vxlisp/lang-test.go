package vxlisp

import "strings"

func LangTestApp(
	lang *vxlang,
	project *vxproject,
	command *vxcommand,
	pkgprefix string) string {
	imports := ""
	imports += LangImport(lang, project, "vx/core", imports)
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
			MsgLog("Error! Context Not Found: (project (cmd :context " + command.context + "))")
		}
		if contextfunc != emptyfunc {
			switch contextfunc.pkgname {
			case "vx/test":
			default:
				imports += LangImport(lang, project, contextfunc.pkgname, imports)
			}
			if contextfunc.async {
				contexttext += "" +
					LangVarStaticFuture(
						lang,
						"asynccontext",
						contexttype,
						1,
						LangNameFFromFunc(lang, contextfunc)+"(arglist)") +
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
						LangNameFFromFunc(lang, contextfunc)+"(arglist)")
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
						LangVar(lang, "testpackage", testpackagetype, 2,
							"Test"+
								LangNameFromPkgName(lang, pkg.name)+
								"Test.test_package(context)") +
						"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
						"\n  }" +
						"\n"
				case "java", "kotlin":
					tests += "" +
						"\n  @Test" +
						"\n  @DisplayName(\"" + pkg.name + "\")" +
						"\n  void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
						"\n    com.vxlisp.vx.Test.Type_testpackage testpackage = " + LangNameFromPkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
						"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
						"\n  }" +
						"\n"
				}
			}
		}
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "AppTest")
	writetestsuite := ""
	testbasics := ""
	switch lang.name {
	case "csharp":
		namespaceopen = "" +
			"\n" +
			"\nnamespace AppTest" + lang.lineend +
			"\n" +
			"\npublic class AppTest(Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n" +
			"\n  bool isconsole = TestLib.EnableConsole(output)" + lang.lineend +
			"\n"
		namespaceclose = "" +
			"\n}" +
			"\n"
		testpackagedata := "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testpackagelisttype) + "," +
			testpackages +
			"\n    )"
		testbasics = "" +
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
		writetestsuite = "" +
			"\n  [Fact]" +
			"\n  public void test_writetestsuite() {" +
			LangVar(lang, "testpackagelist", testpackagelisttype, 2, testpackagedata) +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" + lang.lineend +
			"\n  }" +
			"\n"
	case "java", "kotlin":
		imports += "" +
			"\nimport org.junit.jupiter.api.DisplayName" + lang.lineend +
			"\nimport org.junit.jupiter.api.Test" + lang.lineend
		testbasics = "" +
			"\n  @Test" +
			"\n  void test_basics() {" +
			"\n    TestLib.test_helloworld()" + lang.lineend +
			"\n    TestLib.test_async_new_from_value()" + lang.lineend +
			"\n    TestLib.test_async_from_async_fn()" + lang.lineend +
			"\n    TestLib.test_list_from_list_async()" + lang.lineend +
			"\n    TestLib.test_pathfull_from_file()" + lang.lineend +
			"\n    TestLib.test_read_file()" + lang.lineend +
			"\n    TestLib.test_write_file()" + lang.lineend +
			"\n  }"
		writetestsuite = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"writetestsuite\")" +
			"\n  void test_writetestsuite() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      com.vxlisp.vx.Test.t_testpackagelist," +
			testpackages +
			"\n    )" + lang.lineend +
			"\n    TestLib.write_testpackagelist_async(context, testpackagelist)" + lang.lineend +
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
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := LangFromValue(lang, testvalue, testpkg, fnc, 6, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
				"\n          " + LangTypeT(lang, testdescribetype) + "," +
				"\n          \":describename\", \"" + LangTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
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
				LangVar(lang, "output", testcasetype, 2, varoutput))
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
		scovertype = LangTypeE(lang, intmaptype)
	} else {
		scovertype = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(covertype, ",\n  ") +
			"\n)"
	}
	scoverconst := ""
	if len(coverconst) == 0 {
		scoverconst = LangTypeE(lang, intmaptype)
	} else {
		scoverconst = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(coverconst, ",\n  ") +
			"\n)"
	}
	scoverfunc := ""
	if len(coverfunc) == 0 {
		scoverfunc = LangTypeE(lang, intmaptype)
	} else {
		scoverfunc = "" +
			LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n  " + LangPkgNameDot(lang, "vx/core") + "t_intmap," +
			"\n  " + strings.Join(coverfunc, ",\n  ") +
			"\n      )"
	}
	//	vararraylisttestcase1 := "new ArrayList<>(Arrays.asList(" +
	//		"\n      " + strings.Join(testall, ",\n      ") +
	//		"\n    ))"
	vartestcases := ""
	varoutput := ""
	if len(testall) == 0 {
		varoutput = LangTypeE(lang, testcaselisttype)
	} else {
		varoutput = LangPkgNameDot(lang, "vx/core") + "vx_new(" +
			"\n      " + LangTypeT(lang, testcaselisttype) + "," +
			"\n      testcases" +
			"\n    )"
		switch lang.name {
		case "csharp":
			vararraylisttestcase := "[" +
				"\n      " + strings.Join(testall, ",\n      ") +
				"\n    ]"
			vartestcases = "\n    object[] testcases = " + vararraylisttestcase + lang.lineend
		case "java":
			vararraylisttestcase := LangPkgNameDot(lang, "vx/core") + "arraylist_from_array(" +
				"\n      " + strings.Join(testall, ",\n      ") +
				"\n    )"
			vartestcases = "" +
				LangVarCollection(lang, "testcases", rawlisttype, anytype, 2, vararraylisttestcase)
		}
	}
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  public static " + LangTypeName(lang, testcaselisttype) + " test_cases(" + LangFinalArg(lang) + LangTypeName(lang, contexttype) + " context) {" +
		vartestcases +
		LangVar(lang, "output", testcaselisttype, 2, varoutput) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n" +
		"\n  public static " + LangTypeName(lang, testcoveragesummarytype) + " test_coveragesummary() {" +
		"\n    return " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
		"\n      " + LangTypeT(lang, testcoveragesummarytype) + "," +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":constnums\", " + LangTypeCoverageNumsValNew(lang, coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \":docnums\", " + LangTypeCoverageNumsValNew(lang, coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \":funcnums\", " + LangTypeCoverageNumsValNew(lang, coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \":bigospacenums\", " + LangTypeCoverageNumsValNew(lang, coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \":bigotimenums\", " + LangTypeCoverageNumsValNew(lang, coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \":totalnums\", " + LangTypeCoverageNumsValNew(lang, coverpct, covercnt, covertotal) + ", " +
		"\n      \":typenums\", " + LangTypeCoverageNumsValNew(lang, covertypepct, covertypecnt, covertypetotal) +
		"\n    )" + lang.lineend +
		"\n  }" +
		"\n" +
		"\n  public static " + LangTypeName(lang, testcoveragedetailtype) + " test_coveragedetail() {" +
		"\n    return " + LangPkgNameDot(lang, "vx/core") + "vx_new(" +
		LangTypeT(lang, testcoveragedetailtype) + ", " +
		"\":testpkg\", \"" + pkg.name + "\", " +
		"\":typemap\", " + scovertype + ", " +
		"\":constmap\", " + scoverconst + ", " +
		"\":funcmap\", " + scoverfunc +
		")" + lang.lineend +
		"\n  }" +
		"\n" +
		"\n  public static " + LangTypeName(lang, testpackagetype) + " test_package(" + LangFinalArg(lang) + LangTypeName(lang, contexttype) + " context) {" +
		LangVar(lang, "testcaselist", testcaselisttype, 2, "test_cases(context)") +
		LangVar(lang, "output", testpackagetype, 2,
			LangPkgNameDot(lang, "vx/core")+"vx_new("+
				"\n      "+LangTypeT(lang, testpackagetype)+","+
				"\n      \":testpkg\", \""+pkg.name+"\", "+
				"\n      \":caselist\", testcaselist,"+
				"\n      \":coveragesummary\", test_coveragesummary(),"+
				"\n      \":coveragedetail\", test_coveragedetail()"+
				"\n    )") +
		"\n    return output" + lang.lineend +
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
