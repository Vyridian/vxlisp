package vxlisp

func LangTestLib(lang *vxlang) string {
	commontests := "" +
		LangTestLib_file_test(lang) +
		LangTestLib_read_test_file(lang) +
		LangTestLib_test(lang) +
		LangTestLib_test_helloworld(lang) +
		LangTestLib_test_async_new_from_value(lang) +
		LangTestLib_test_async_from_async_fn(lang) +
		LangTestLib_test_list_from_list_async(lang) +
		/*
			test_lib::test_run_testresult(context);
			test_lib::test_run_testdescribe(context);
			test_lib::test_run_testdescribelist(context);
			test_lib::test_run_testcase(context);
			test_lib::test_run_testcaselist(context);
			test_lib::test_run_testpackage(context);
			test_lib::test_run_testpackagelist(context);
			test_lib::test_resolve_testresult_anyfromfunc(context);
			test_lib::test_resolve_testresult_then(context);
			test_lib::test_resolve_testresult_thenelselist(context);
			test_lib::test_resolve_testresult_if(context);
			test_lib::test_resolve_testresult_f_resolve_testresult_async(context);
			test_lib::test_resolve_testresult_f_resolve_testresult(context);
			test_lib::test_run_testresult_async(context);
			test_lib::test_run_testdescribe_async(context);
			test_lib::test_run_testdescribelist_async_f_list_from_list_async(context);
			test_lib::test_run_testdescribelist_async(context);
			test_lib::test_run_testcase_async_f_resolvetestcase(context);
			test_lib::test_run_testcase_async_syncvalue(context);
			test_lib::test_run_testcase_async(context);
			test_lib::test_run_testcaselist_async(context);
			test_lib::test_run_testpackage_async(context);
			test_lib::test_run_testpackagelist_async(context);
		*/
		LangTestLib_test_pathfull_from_file(lang) +
		LangTestLib_test_read_file(lang) +
		LangTestLib_test_write_file(lang) +
		//
		/*
			test_lib::test_tr_from_testdescribe_casename(context);
			test_lib::test_trlist_from_testcase(context);
			test_lib::test_trlist_from_testcaselist(context);
			test_lib::test_div_from_testcaselist(context);
			test_lib::test_div_from_testpackage(context);
			test_lib::test_div_from_testpackagelist(context);
			test_lib::test_node_from_testpackagelist(context);
			test_lib::test_html_from_testpackagelist(context);
			test_lib::test_write_testpackagelist(context);
			test_lib::test_write_node(context);
			test_lib::test_write_html(context);
			test_lib::test_write_testpackagelist_async(context);
		*/
		LangTestLib_run_testcase(lang) +
		LangTestLib_run_testcase_async(lang) +
		LangTestLib_run_testcaselist(lang) +
		LangTestLib_run_testdescribe(lang) +
		LangTestLib_run_testdescribelist(lang) +
		LangTestLib_run_testpackage(lang) +
		LangTestLib_run_testpackage_async(lang) +
		LangTestLib_run_testresult(lang) +
		LangTestLib_write_testpackagelist_async(lang)
	spath := LangPkgNameDot(lang, "vx/core") + "c_path_test_resources.vx_string()"
	namespaceopen, namespaceclose := LangSpecificNamespaceFromPackage(
		lang, "TestLib")
	output := LangSpecificTestLib(
		lang, namespaceopen, namespaceclose, commontests, spath)
	return output
}

func LangTestLib_file_test(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "file_test"
	fnc.vxtype = filetype
	arg := NewArg("file")
	arg.vxtype = filetype
	fnc.listarg = append(fnc.listarg, arg)
	paramsopen, paramsclose := LangTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      file," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), spath" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			//	long irefcount = vx_core::refcount;
			LangVar(lang, "output", filetype, 2,
				LangPkgNameDot(lang, "vx/core")+"vx_copy("+fileparams+")"))
		//vx_core::vx_release(string_file);
	return output
}

func LangTestLib_read_test_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "read_test_file"
	fnc.vxtype = rawstringtype
	arg := NewArg("path")
	arg.vxtype = rawstringtype
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("filename")
	arg.vxtype = rawstringtype
	fnc.listarg = append(fnc.listarg, arg)
	paramsopen, paramsclose := LangTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      " + LangTypeT(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			//	long irefcount = vx_core::refcount;
			LangVar(lang, "file", filetype, 2,
				LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")")+
				LangVar(lang, "string_file", stringtype, 2,
					LangPkgNameDot(lang, "vx/data/file")+"vx_string_read_from_file(file)")+
				LangVar(lang, "output", rawstringtype, 2,
					"string_file"+lang.typeref+"vx_string()"))
		//vx_core::vx_release(string_file);
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			LangVar(lang, "testpkg", rawstringtype, 2,
				"testcase.testpkg().vx_string()")+
				LangVar(lang, "casename", rawstringtype, 2,
					"testcase.casename().vx_string()")+
				LangVar(lang, "testdescribelist", testdescribelisttype, 2,
					"testcase.describelist()")+
				LangVar(lang, "output", rawbooleantype, 2,
					"run_testdescribelist(testpkg, casename, testdescribelist)"))
	return output
}

func LangTestLib_run_testcase_async(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "run_testcase_async"
	fnc.vxtype = rawbooltype
	arg := NewArg("testcase")
	arg.vxtype = testcasetype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	output := "" +
		"\n  // Blocking" +
		"\n  // Only use if running a single testcase" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			LangVarFuture(lang, "async_testcase", testcasetype, 2,
				LangPkgNameDot(lang, "vx/test")+"f_resolve_testcase(testcase)")+
				LangVar(lang, "testcase_resolved", testcasetype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, testcasetype)+", async_testcase)")+
				LangVar(lang, "output", rawbooltype, 2, "run_testcase(testcase_resolved)"))
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			LangVarCollection(lang, "listtestcase", rawlisttype, testcasetype, 2,
				"testcaselist.vx_listtestcase()")+
				LangForList(lang, "testcase", testcasetype, "listtestcase", 2,
					"\n      run_testcase(testcase)"+lang.lineend)+
				LangVar(lang, "output", rawbooltype, 2, "true"))
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
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testcode", stringtype, 2,
				"describe.describename()")+
				LangVar(lang, "message", rawstringtype, 2,
					"testcode.vx_string()")+
				LangVar(lang, "testresult", testresulttype, 2,
					"describe.testresult()")+
				LangVar(lang, "output", rawbooltype, 2,
					"run_testresult(testpkg, casename, message, testresult)"))
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
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "output", rawbooltype, 2, "true")+
				LangVarCollection(lang, "listtestdescribe", rawlisttype, testdescribetype, 2,
					"testdescribelist.vx_listtestdescribe()")+
				LangForList(lang, "testdescribe", testdescribetype, "listtestdescribe", 2,
					LangVar(lang, "testoutput", rawbooltype, 3,
						"run_testdescribe(testpkg, casename, testdescribe)")+
						"\n 	    if (!testoutput) {"+
						"\n   			  output = false"+lang.lineend+
						"\n      }"))
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
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testcaselist", testcaselisttype, 2,
				"testpackage.caselist()")+
				LangVar(lang, "output", rawbooltype, 2,
					"run_testcaselist(testcaselist)"))
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
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVarFuture(lang, "async_testpackage", testpackagetype, 2,
				LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackage(testpackage)")+
				LangVar(lang, "testpackage_resolved", testpackagetype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, testpackagetype)+", async_testpackage)")+
				LangVar(lang, "output", rawbooltype, 2,
					"run_testpackage(testpackage_resolved)"))
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
	assertequals := LangSpecificTestAssertEquals(lang)
	assertnotequals := LangSpecificTestAssertNotEquals(lang)
	println := LangSpecificPrintLine(lang)
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "valexpected", anytype, 2,
				"testresult.expected()")+
				LangVar(lang, "valactual", anytype, 2,
					"testresult.actual()")+
				LangVar(lang, "passfail", rawbooltype, 2,
					"testresult.passfail().vx_boolean()")+
				LangVar(lang, "code", rawstringtype, 2,
					"testresult.code().vx_string()")+
				LangVar(lang, "expected", rawstringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valexpected).vx_string()")+
				LangVar(lang, "actual", rawstringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valactual).vx_string()")+
				LangVar(lang, "msg", rawstringtype, 2,
					"testpkg + \"/\" + testname + \" \" + message")+
				"\n  		if (!passfail) {"+
				"\n  				"+println+"(msg)"+lang.lineend+
				"\n  				"+println+"(expected)"+lang.lineend+
				"\n  				"+println+"(actual)"+lang.lineend+
				"\n      "+LangPkgNameDot(lang, "vx/core")+"f_log(testresult)"+lang.lineend+
				"\n		  }"+
				LangIf(lang, 2,
					LangSpecificIfClause(lang, rawstringtype, "==", "code", "\":ne\""),
					assertnotequals)+
				LangIfElse(lang, 2, assertequals)+
				LangIfEnd(lang, 2)+
				LangVal(lang, "output", rawbooltype, 2, "true"))
	return output
}

func LangTestLib_test(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test"
	fnc.vxtype = rawbooltype
	arg := NewArg("testname")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("expected")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	arg = NewArg("actual")
	arg.vxtype = rawstringtype
	arg.isfinal = true
	fnc.listarg = append(fnc.listarg, arg)
	assertequals := ""
	println := ""
	switch lang {
	case langcsharp:
		assertequals = "\n    Assert.Equal(expected, actual)" + lang.lineend
		println = "System.Console.WriteLine"
	case langjava:
		assertequals = "\n    assertEquals(expected, actual)" + lang.lineend
		println = "System.out.println"
	case langkotlin:
		assertequals = "\n    assertEquals(expected, actual)" + lang.lineend
		println = "println"
	}
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true, 0,
			assertequals+
				LangVar(lang, "output", rawbooltype, 2, "false")+
				"\n    if ("+LangSpecificVxEqualsString(lang, "expected", "actual")+") {"+
				LangSpecificVarSet(lang, "output", 3, "true")+
				"\n    } else {"+
				"\n      "+println+"(testname)"+lang.lineend+
				"\n      "+println+"(expected)"+lang.lineend+
				"\n      "+println+"(actual)"+lang.lineend+
				"\n    }")
	return output
}

func LangTestLib_test_async_from_async_fn(
	lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_from_async_fn"
	fnc.vxtype = rawbooltype
	slambda := LangSpecificTestLibLambda(lang)
	sasync1 := "" +
		LangPkgNameDot(lang, "vx/core") + "vx_async_from_async_fn(async, " + slambda +
		")"
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2, "\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, "helloworld", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVarFuture(lang, "async", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVarFuture(lang, "async1", stringtype, 2, sasync1)+
				LangVar(lang, "sync", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async1)")+
				LangVar(lang, "expected", rawstringtype, 2,
					"\"Hello World\"")+
				LangVar(lang, "actual", rawstringtype, 2,
					"sync"+lang.typeref+"vx_string()")+
				LangVar(lang, "output", rawbooltype, 2, "TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_async_new_from_value(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_new_from_value"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2,
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, "helloworld", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVarFuture(lang, "async", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVar(lang, "sync", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async)")+
				LangVar(lang, "expected", rawstringtype, 2,
					"\"Hello World\"")+
				LangVar(lang, "actual", rawstringtype, 2,
					"sync"+lang.typeref+"vx_string()")+
				LangVar(lang, "output", rawbooltype, 2,
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_helloworld(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_helloworld"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2,
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, "helloworld", stringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVar(lang, "expected", rawstringtype, 2,
					"\"Hello World\"")+
				LangVar(lang, "actual", rawstringtype, 2,
					"helloworld"+lang.typeref+"vx_string()")+
				LangVar(lang, "output", rawbooltype, 2,
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_list_from_list_async(
	lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_list_from_list_async"
	fnc.vxtype = rawbooltype
	fn_async := LangSpecificTestLibFnAsync(lang)
	asynclist := LangPkgNameDot(lang, "vx/core") + "vx_list_from_list_async(" + LangTypeT(lang, stringlisttype) + ", slist, fn_async)"
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2,
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, "sparams", anylisttype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(\"hello\", \"world\")")+
				LangVar(lang, "slist", stringlisttype, 2,
					LangPkgNameDot(lang, "vx/core")+"f_new_from_type("+LangTypeT(lang, stringlisttype)+", sparams)")+
				fn_async+
				LangVarFuture(lang, "asynclist", stringlisttype, 2, asynclist)+
				LangVar(lang, "sync", stringlisttype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringlisttype)+", asynclist)")+
				LangVar(lang, "expected", rawstringtype, 2,
					`"(stringlist\n \"hello!\"\n \"world!\")"`)+
				LangVar(lang, "actual", rawstringtype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_string_from_any(sync)")+
				LangVar(lang, "output", rawbooltype, 2,
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_pathfull_from_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_pathfull_from_file"
	fnc.vxtype = rawbooltype
	paramsopen, paramsclose := LangTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      " + LangTypeT(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2,
				"\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, "file", filetype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")")+
				LangVar(lang, "string_path", stringtype, 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)")+
				LangVar(lang, "expected", rawstringtype, 2,
					`spath + "/vx/string_read_from_file.txt"`)+
				LangVar(lang, "actual", rawstringtype, 2,
					"string_path"+lang.typeref+"vx_string()")+
				// vx_core::vx_release(string_path);
				LangVar(lang, "output", rawbooltype, 2,
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_read_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_read_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2, "\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, "expected", rawstringtype, 2, `"testdata"`)+
				LangVar(lang, "actual", rawstringtype, 2,
					`read_test_file(spath + "/vx", "string_read_from_file.txt")`)+
				// vx_core::vx_release(string_path);
				LangVar(lang, "output", rawbooltype, 2,
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_write_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_write_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2, "\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, "file", filetype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_new("+
						"\n      "+LangTypeT(lang, filetype)+", "+
						"\n      "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":path\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(spath + \"/vx\"),"+
						"\n      "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":name\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"string_read_from_file.txt\")"+
						"\n    )")+
				LangVar(lang, "string_path", stringtype, 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)")+
				LangVar(lang, "expected", rawstringtype, 2, `spath + "/vx/string_read_from_file.txt"`)+
				LangVar(lang, "actual", rawstringtype, 2, "string_path"+lang.typeref+"vx_string()")+
				// vx_core::vx_release(string_path);
				LangVar(lang, "output", rawbooltype, 2, "TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
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
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "output", rawbooltype, 2, "false")+
				LangVarFuture(lang, "async_testpackagelist", testpackagelisttype, 2,
					LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackagelist(testpackagelist)")+
				LangVar(lang, "testpackagelist_resolved", testpackagelisttype, 2,
					LangPkgNameDot(lang, "vx/core")+
						"vx_sync_from_async("+
						LangTypeT(lang, testpackagelisttype)+
						", async_testpackagelist)")+
				LangVar(lang, "filetest", filetype, 2,
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_test())")+
				LangVar(lang, "valboolean", booleantype, 2,
					LangPkgNameDot(lang, "vx/data/file")+
						"f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved)")+
				LangSpecificVarSet(lang, "output", 2,
					"valboolean.vx_boolean()")+
				LangVar(lang, "divtest", htmldivtype, 2,
					LangPkgNameDot(lang, "vx/test")+"f_div_from_testpackagelist(testpackagelist_resolved)")+
				LangVar(lang, "htmlnode", htmltype, 2,
					LangPkgNameDot(lang, "vx/test")+"f_html_from_divtest(divtest)")+
				LangVar(lang, "filenode", filetype, 2,
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testnode())")+
				LangSpecificVarSet(lang, "valboolean", 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filenode, htmlnode)")+
				LangSpecificVarSet(lang, "output", 2,
					"output && valboolean.vx_boolean()")+
				LangVar(lang, "filehtml", filetype, 2,
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testhtml())")+
				LangVar(lang, "shtml", stringtype, 2, LangPkgNameDot(lang, "vx/web/html")+"f_string_from_html(htmlnode)")+
				LangSpecificVarSet(lang, "valboolean", 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_string(context, filehtml, shtml)")+
				LangSpecificVarSet(lang, "output", 2, "output && valboolean.vx_boolean()"))
	return output
}
