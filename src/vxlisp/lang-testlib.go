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
	namespaceopen, namespaceclose := LangNativeNamespaceOpenClose(
		lang, "TestLib", "")
	output := LangNativeTestLib(
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
	paramsopen, paramsclose := LangNativeTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      file," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), spath" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			//	long irefcount = vx_core::refcount;
			LangVar(lang, 2, filetype,
				"output",
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
	paramsopen, paramsclose := LangNativeTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      " + LangTypeT(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			//	long irefcount = vx_core::refcount;
			LangVar(lang, 2, filetype,
				"file",
				LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")")+
				LangVar(lang, 2, stringtype,
					"string_file",
					LangPkgNameDot(lang, "vx/data/file")+"vx_string_read_from_file(file)")+
				LangVar(lang, 2, rawstringtype,
					"output",
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
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			LangVar(lang, 2, rawstringtype,
				"testpkg",
				"testcase.testpkg().vx_string()")+
				LangVar(lang, 2, rawstringtype,
					"casename",
					"testcase.casename().vx_string()")+
				LangVar(lang, 2, testdescribelisttype,
					"testdescribelist",
					"testcase.describelist()")+
				LangVar(lang, 2, rawbooleantype,
					"output",
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
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			LangVarFuture(lang, 2, testcasetype,
				"async_testcase",
				LangPkgNameDot(lang, "vx/test")+"f_resolve_testcase(testcase)")+
				LangVar(lang, 2, testcasetype,
					"testcase_resolved",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, testcasetype)+", async_testcase)")+
				LangVar(lang, 2, rawbooltype,
					"output", "run_testcase(testcase_resolved)"))
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
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			LangVarCollection(lang, 2, rawlisttype, testcasetype,
				"listtestcase",
				"testcaselist.vx_listtestcase()")+
				LangForList(lang, 2,
					"testcase", testcasetype, "listtestcase",
					"\n      run_testcase(testcase)"+lang.lineend)+
				LangVar(lang, 2, rawbooltype,
					"output", "true"))
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, stringtype,
				"testcode", "describe.describename()")+
				LangVar(lang, 2, rawstringtype,
					"message", "testcode.vx_string()")+
				LangVar(lang, 2, testresulttype,
					"testresult", "describe.testresult()")+
				LangVar(lang, 2, rawbooltype,
					"output",
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawbooltype,
				"output", "true")+
				LangVarCollection(lang, 2, rawlisttype, testdescribetype,
					"listtestdescribe",
					"testdescribelist.vx_listtestdescribe()")+
				LangForList(lang, 2,
					"testdescribe", testdescribetype, "listtestdescribe",
					LangVar(lang, 3, rawbooltype,
						"testoutput",
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, testcaselisttype,
				"testcaselist",
				"testpackage.caselist()")+
				LangVar(lang, 2, rawbooltype,
					"output",
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVarFuture(lang, 2, testpackagetype,
				"async_testpackage",
				LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackage(testpackage)")+
				LangVar(lang, 2, testpackagetype,
					"testpackage_resolved",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, testpackagetype)+", async_testpackage)")+
				LangVar(lang, 2, rawbooltype,
					"output",
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
	assertequals := LangNativeTestAssertEquals(lang, true, 3)
	assertnotequals := LangNativeTestAssertNotEquals(lang, true, 3)
	println := LangNativePrintLine(lang)
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, anytype,
				"valexpected",
				"testresult.expected()")+
				LangVar(lang, 2, anytype,
					"valactual",
					"testresult.actual()")+
				LangVar(lang, 2, rawbooltype,
					"passfail",
					"testresult.passfail().vx_boolean()")+
				LangVar(lang, 2, rawstringtype,
					"code",
					"testresult.code().vx_string()")+
				LangVar(lang, 2, rawstringtype,
					"expected",
					LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valexpected).vx_string()")+
				LangVar(lang, 2, rawstringtype,
					"actual",
					LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valactual).vx_string()")+
				LangVar(lang, 2, rawstringtype,
					"msg",
					"testpkg + \"/\" + testname + \" \" + message")+
				"\n    if (!passfail) {"+
				"\n      "+println+"(msg)"+lang.lineend+
				"\n      "+println+"(expected)"+lang.lineend+
				"\n      "+println+"(actual)"+lang.lineend+
				"\n      "+LangPkgNameDot(lang, "vx/core")+"f_log(testresult)"+lang.lineend+
				"\n    }"+
				LangIfThen(lang, 2,
					LangIfClause(lang, rawstringtype, "==", "code", "\":ne\""),
					assertnotequals)+
				LangIfElse(lang, 2, assertequals)+
				LangIfEnd(lang, 2)+
				LangVal(lang, 2, rawbooltype,
					"output", "true"))
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
	assertequals := LangNativeTestAssertEquals(lang, false, 2)
	println := LangNativePrintLine(lang)
	output := "" +
		LangFuncHeaderAll(lang, 1,
			"", fnc, false, true, 0,
			assertequals+
				LangVar(lang, 2, rawbooltype,
					"output", "false")+
				"\n    if ("+LangVxEqualsString(lang, "expected", "actual")+") {"+
				LangVarSet(lang, 3, "output", "true")+
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
	slambda := LangNativeTestLibLambda(lang)
	sasync1 := "" +
		LangPkgNameDot(lang, "vx/core") +
		"vx_async_from_async_fn(async, " +
		slambda +
		")"
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname", "\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, 2, stringtype,
					"helloworld",
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVarFuture(lang, 2, stringtype,
					"async",
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVarFuture(lang, 2, stringtype,
					"async1", sasync1)+
				LangVar(lang, 2, stringtype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async1)")+
				LangVar(lang, 2, rawstringtype,
					"expected",
					"\"Hello World\"")+
				LangVar(lang, 2, rawstringtype,
					"actual",
					"sync"+lang.typeref+"vx_string()")+
				LangVar(lang, 2, rawbooltype,
					"output", "TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_async_new_from_value(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_new_from_value"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, 1, "", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname",
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, 2, stringtype,
					"helloworld",
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVarFuture(lang, 2, stringtype,
					"async",
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVar(lang, 2, stringtype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async)")+
				LangVar(lang, 2, rawstringtype,
					"expected", "\"Hello World\"")+
				LangVar(lang, 2, rawstringtype,
					"actual",
					"sync"+lang.typeref+"vx_string()")+
				LangVar(lang, 2, rawbooltype,
					"output",
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname",
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, 2, stringtype,
					"helloworld",
					LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVar(lang, 2, rawstringtype,
					"expected", "\"Hello World\"")+
				LangVar(lang, 2, rawstringtype,
					"actual",
					"helloworld"+lang.typeref+"vx_string()")+
				LangVar(lang, 2, rawbooltype,
					"output",
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
	fn_async := LangNativeTestLibFnAsync(lang)
	asynclist := LangPkgNameDot(lang, "vx/core") + "vx_list_from_list_async(" + LangTypeT(lang, stringlisttype) + ", slist, fn_async)"
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname", "\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, 2, anylisttype,
					"sparams",
					LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(\"hello\", \"world\")")+
				LangVar(lang, 2, stringlisttype,
					"slist",
					LangPkgNameDot(lang, "vx/core")+"f_new_from_type("+LangTypeT(lang, stringlisttype)+", sparams)")+
				fn_async+
				LangVarFuture(lang, 2, stringlisttype,
					"asynclist", asynclist)+
				LangVar(lang, 2, stringlisttype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringlisttype)+", asynclist)")+
				LangVar(lang, 2, rawstringtype,
					"expected",
					`"(stringlist\n \"hello!\"\n \"world!\")"`)+
				LangVar(lang, 2, rawstringtype,
					"actual",
					LangPkgNameDot(lang, "vx/core")+"vx_string_from_any(sync)")+
				LangVar(lang, 2, rawbooltype,
					"output",
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_pathfull_from_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_pathfull_from_file"
	fnc.vxtype = rawbooltype
	paramsopen, paramsclose := LangNativeTestLibParamsOpenClose(lang)
	fileparams := "" +
		"\n      " + LangTypeT(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname",
				"\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, 2, filetype,
					"file",
					LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")")+
				LangVar(lang, 2, stringtype,
					"string_path",
					LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)")+
				LangVar(lang, 2, rawstringtype,
					"expected",
					`spath + "/vx/string_read_from_file.txt"`)+
				LangVar(lang, 2, rawstringtype,
					"actual",
					"string_path"+lang.typeref+"vx_string()")+
				// vx_core::vx_release(string_path);
				LangVar(lang, 2, rawbooltype,
					"output",
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_read_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_read_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname", "\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, 2, rawstringtype,
					"expected", `"testdata"`)+
				LangVar(lang, 2, rawstringtype,
					"actual",
					`read_test_file(spath + "/vx", "string_read_from_file.txt")`)+
				// vx_core::vx_release(string_path);
				LangVar(lang, 2, rawbooltype,
					"output",
					"TestLib"+lang.pkgref+"test(testname, expected, actual)"))
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
	return output
}

func LangTestLib_test_write_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_write_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawstringtype,
				"testname", "\""+fnc.name+"\"")+
				//	long irefcount = vx_core::refcount;
				LangVar(lang, 2, filetype,
					"file",
					LangPkgNameDot(lang, "vx/core")+"vx_new("+
						"\n      "+LangTypeT(lang, filetype)+", "+
						"\n      "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":path\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(spath + \"/vx\"),"+
						"\n      "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":name\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"string_read_from_file.txt\")"+
						"\n    )")+
				LangVar(lang, 2, stringtype,
					"string_path",
					LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)")+
				LangVar(lang, 2, rawstringtype,
					"expected",
					`spath + "/vx/string_read_from_file.txt"`)+
				LangVar(lang, 2, rawstringtype,
					"actual", "string_path"+lang.typeref+"vx_string()")+
				// vx_core::vx_release(string_path);
				LangVar(lang, 2, rawbooltype,
					"output", "TestLib"+lang.pkgref+"test(testname, expected, actual)"))
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
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			LangVar(lang, 2, rawbooltype,
				"output", "false")+
				LangVarFuture(lang, 2, testpackagelisttype,
					"async_testpackagelist",
					LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackagelist(testpackagelist)")+
				LangVar(lang, 2, testpackagelisttype,
					"testpackagelist_resolved",
					LangPkgNameDot(lang, "vx/core")+
						"vx_sync_from_async("+
						LangTypeT(lang, testpackagelisttype)+
						", async_testpackagelist)")+
				LangVar(lang, 2, filetype,
					"filetest",
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_test())")+
				LangVar(lang, 2, booleantype,
					"valboolean",
					LangPkgNameDot(lang, "vx/data/file")+
						"f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved)")+
				LangVarSet(lang, 2,
					"output", "valboolean.vx_boolean()")+
				LangVar(lang, 2, htmldivtype,
					"divtest",
					LangPkgNameDot(lang, "vx/test")+"f_div_from_testpackagelist(testpackagelist_resolved)")+
				LangVar(lang, 2, htmltype,
					"htmlnode",
					LangPkgNameDot(lang, "vx/test")+"f_html_from_divtest(divtest)")+
				LangVar(lang, 2, filetype,
					"filenode",
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testnode())")+
				LangVarSet(lang, 2,
					"valboolean",
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filenode, htmlnode)")+
				LangVarSet(lang, 2,
					"output",
					"output && valboolean.vx_boolean()")+
				LangVar(lang, 2, filetype,
					"filehtml",
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testhtml())")+
				LangVar(lang, 2, stringtype,
					"shtml",
					LangPkgNameDot(lang, "vx/web/html")+"f_string_from_html(htmlnode)")+
				LangVarSet(lang, 2,
					"valboolean",
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_string(context, filehtml, shtml)")+
				LangVarSet(lang, 2,
					"output", "output && valboolean.vx_boolean()"))
	return output
}
