package vxlisp

func LangTestLib(
	lang *vxlang) string {
	commontests := "" +
		LangTestLib_file_test(lang) +
		LangTestLib_read_test_file(lang) +
		LangTestLib_sample_testdescribe1(lang) +
		LangTestLib_sample_testdescribe2(lang) +
		LangTestLib_sample_testdescribelist(lang) +
		LangTestLib_sample_testresult1(lang) +
		LangTestLib_sample_testresult2(lang) +
		LangTestLib_test(lang) +
		LangTestLib_test_helloworld(lang) +
		LangTestLib_test_async_new_from_value(lang) +
		LangTestLib_test_async_from_async_fn(lang) +
		LangTestLib_test_list_from_list_async(lang) +
		LangTestLib_test_run_testresult(lang) +
		LangTestLib_test_run_testdescribe(lang) +
		LangTestLib_test_run_testdescribelist(lang) +
		/*
			LangTestLib_test_run_testcase(lang) +
			LangTestLib_test_run_testcaselist(lang) +
			LangTestLib_test_run_testpackage(lang) +
			LangTestLib_test_run_testpackagelist(lang) +
				test_lib::test_resolve_testresult_anyfromfunc(context);
				test_lib::test_resolve_testresult_then(context);
				test_lib::test_resolve_testresult_thenelselist(context);
				test_lib::test_resolve_testresult_if(context);
				test_lib::test_resolve_testresult_f_resolve_testresult_async(context);
				test_lib::test_resolve_testresult_f_resolve_testresult(context);*/
		LangTestLib_test_run_testresult_async(lang) +
		/*
			test_lib::test_run_testdescribe_async(context);
			test_lib::test_run_testdescribelist_async_f_list_from_list_async(context);
		*/
		LangTestLib_test_run_testdescribelist_async(lang) +
		/*
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
	namespaceopen, namespaceclose := LangNamespaceOpenClose(
		lang, "TestLib", "")
	output := LangTestLibNative(
		lang, namespaceopen, namespaceclose, commontests, spath)
	return output
}

func LangTestLib_file_test(
	lang *vxlang) string {
	func_file_test := NewFunc()
	func_file_test.name = "file_test"
	func_file_test.vxtype = filetype
	arg := NewArg("file")
	arg.vxtype = filetype
	func_file_test.listarg = append(func_file_test.listarg, arg)
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_file_test,
			LangVal(lang, 2, filetype,
				"output",
				LangFuncCall(lang, 2,
					func_vx_copy,
					LangTypeT(lang, filetype),
					"file",
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":path\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"spath")))+
				LangTestLib_release(lang, 2, "string_file"))
	return output
}

func LangTestLib_read_test_file(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_read_test_file,
			LangVar(lang, 2, filetype,
				"file",
				LangFuncCall(lang, 2,
					func_vx_new,
					LangTypeT(lang, filetype),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":path\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"path"),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":name\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"filename")))+
				LangVar(lang, 2, stringtype,
					"string_file",
					LangFuncCall(lang, 2,
						func_vx_string_read_from_file,
						"file"))+
				LangVal(lang, 2, rawstringtype,
					"output",
					LangFuncCallMethod(lang, 2,
						"string_file",
						"vx_string"))+
				LangTestLib_release(lang, 2,
					"string_file"))
	return output
}

func LangTestLib_release(
	lang *vxlang,
	indent int,
	varname string) string {
	output := ""
	switch lang {
	case langcpp:
		sindent := LangIndent(lang, indent, true)
		output += sindent + "vx_core::vx_release(" + varname + ");"
	}
	return output
}

func LangTestLib_release_one_except(
	lang *vxlang,
	indent int,
	varname string,
	except string) string {
	output := ""
	switch lang {
	case langcpp:
		sindent := LangIndent(lang, indent, true)
		output += sindent + "vx_core::vx_release_one_except(" + varname + ", " + except + ");"
	}
	return output
}

func LangTestLib_reserve(
	lang *vxlang,
	indent int,
	varname string) string {
	output := ""
	switch lang {
	case langcpp:
		sindent := LangIndent(lang, indent, true)
		output += sindent + "vx_core::vx_reserve(" + varname + ");"
	}
	return output
}

func LangTestLib_run_testcase(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testcase,
			LangTestLib_reserve(lang, 2, "testcase")+
				LangVal(lang, 2, stringtype,
					"testpkg",
					LangFuncCallMethod(lang, 2,
						"testcase",
						"testpkg"))+
				LangVal(lang, 2, rawstringtype,
					"stestpkg",
					LangFuncCallMethod(lang, 2,
						"testpkg",
						"vx_string"))+
				LangVal(lang, 2, stringtype,
					"casename",
					LangFuncCallMethod(lang, 2,
						"testcase",
						"casename"))+
				LangVal(lang, 2, rawstringtype,
					"scasename",
					LangFuncCallMethod(lang, 2,
						"casename",
						"vx_string"))+
				LangVal(lang, 2, testdescribelisttype,
					"testdescribelist",
					LangFuncCallMethod(lang, 2,
						"testcase",
						"describelist"))+
				LangVal(lang, 2, testdescribelisttype,
					"testdescribelist_resolved",
					LangFuncCall(lang, 2,
						func_run_testdescribelist,
						"stestpkg",
						"scasename",
						"testdescribelist"))+
				LangVal(lang, 2, testcasetype,
					"output",
					LangFuncCall(lang, 2,
						func_vx_copy,
						LangTypeT(lang, testcasetype),
						"testcase",
						LangFuncCall(lang, 2,
							func_vx_new_string,
							"\":describelist\""),
						"testdescribelist_resolved"))+
				LangTestLib_release_one_except(lang, 2,
					"testcase", "output"))
	return output
}

func LangTestLib_run_testcase_async(
	lang *vxlang) string {
	output := "" +
		"\n  // Blocking" +
		"\n  // Only use if running a single testcase" +
		LangTestLib_testfunc_helper(lang,
			func_run_testcase_async,
			LangVarFuture(lang, 2, testcasetype,
				"async_testcase",
				LangFuncCall(lang, 2,
					func_f_resolve_testcase,
					"testcase"))+
				LangVar(lang, 2, testcasetype,
					"testcase_resolved",
					LangFuncCall(lang, 2,
						func_vx_sync_from_async,
						LangTypeT(lang, testcasetype),
						"async_testcase"))+
				LangVal(lang, 2, testcasetype,
					"output",
					LangFuncCall(lang, 2,
						func_run_testcase,
						"testcase_resolved")))
	return output
}

func LangTestLib_run_testcaselist(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testcaselist,
			LangTestLib_reserve(lang, 2,
				"testcaselist")+
				LangValCollection(lang, 2, rawlisttype, testcasetype,
					"listtestcase",
					LangFuncCallMethod(lang, 2,
						"testcaselist",
						"vx_listtestcase"))+
				LangVarCollection(lang, 2, rawlisttype, testcasetype,
					"listtestcase_resolved",
					":new")+
				LangForList(lang, 2,
					"testcase", testcasetype, "listtestcase",
					LangVal(lang, 3, testcasetype,
						"testcase_resolved",
						LangFuncCall(lang, 3,
							func_run_testcase,
							"testcase"))+
						LangVarListAdd(lang, 3,
							"listtestcase_resolved",
							"testcase_resolved"))+
				LangVal(lang, 2, testcaselisttype,
					"output",
					LangFuncCall(lang, 2,
						func_vx_any_from_any,
						LangTypeT(lang, testcaselisttype),
						LangFuncCallMethod(lang, 3,
							"testcaselist",
							"vx_new",
							"listtestcase_resolved")))+
				LangTestLib_release_one_except(lang, 2,
					"testcaselist", "output"))
	return output
}

func LangTestLib_run_testdescribe(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testdescribe,
			LangVal(lang, 2, stringtype,
				"testcode",
				LangFuncCallMethod(lang, 2,
					"describe",
					"describename"))+
				LangVal(lang, 2, rawstringtype,
					"message",
					LangFuncCallMethod(lang, 2,
						"testcode",
						"vx_string"))+
				LangVal(lang, 2, testresulttype,
					"testresult",
					LangFuncCallMethod(lang, 2,
						"describe",
						"testresult"))+
				LangVal(lang, 2, testdescribetype,
					"output",
					LangFuncCall(lang, 2,
						func_vx_copy,
						LangTypeT(lang, testdescribetype),
						"describe",
						"\":testresult\"",
						LangFuncCall(lang, 3,
							func_run_testresult,
							"testpkg",
							"casename",
							"message",
							"testresult"))))
	return output
}

func LangTestLib_run_testdescribelist(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testdescribelist,
			LangTestLib_reserve(lang, 2,
				"testdescribelist")+
				LangValCollection(lang, 2, rawlisttype, testdescribetype,
					"listtestdescribe",
					LangFuncCallMethod(lang, 2,
						"testdescribelist",
						"vx_listtestdescribe"))+
				LangVarCollection(lang, 2, rawlisttype, testdescribetype,
					"listtestdescribe_resolved",
					":new")+
				LangForList(lang, 2,
					"testdescribe", testdescribetype, "listtestdescribe",
					LangVal(lang, 3, testdescribetype,
						"testdescribe_resolved",
						LangFuncCall(lang, 3,
							func_run_testdescribe,
							"testpkg",
							"casename",
							"testdescribe"))+
						LangVarListAdd(lang, 3,
							"listtestdescribe_resolved",
							"testdescribe_resolved"))+
				LangVal(lang, 2, testdescribelisttype,
					"output",
					LangFuncCall(lang, 2,
						func_vx_any_from_any,
						LangTypeT(lang, testdescribelisttype),
						LangFuncCallMethod(lang, 3,
							"testdescribelist",
							"vx_new",
							"listtestdescribe_resolved")))+
				LangTestLib_release_one_except(lang, 2,
					"testdescribelist", "output"))
	return output
}

func LangTestLib_run_testpackage(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testpackage,
			LangVal(lang, 2, testcaselisttype,
				"testcaselist",
				LangFuncCallMethod(lang, 2,
					"testpackage",
					"caselist"))+
				LangVal(lang, 2, testcaselisttype,
					"testcaselist_resolved",
					LangFuncCall(lang, 2,
						func_run_testcaselist,
						"testcaselist"))+
				LangVal(lang, 2, testpackagetype,
					"output",
					LangFuncCall(lang, 2,
						func_vx_copy,
						LangTypeT(lang, testpackagetype),
						"testpackage",
						LangFuncCall(lang, 3,
							func_vx_new_string,
							"\":caselist\""),
						"testcaselist_resolved"))+
				LangTestLib_release_one_except(lang, 2, "testpackage", "output"))
	return output
}

func LangTestLib_run_testpackage_async(
	lang *vxlang) string {
	output := "" +
		"\n  // Blocking" +
		"\n  // This is the preferred way of calling test (1 block per package)" +
		LangFuncHeaderStatic(lang, 1,
			"", func_run_testpackage_async, 0,
			LangVarFuture(lang, 2, testpackagetype,
				"async_testpackage",
				LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackage(testpackage)")+
				LangVar(lang, 2, testpackagetype,
					"testpackage_resolved",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, testpackagetype)+", async_testpackage)")+
				LangVar(lang, 2, testpackagetype,
					"output",
					LangFuncCall(lang, 2,
						func_run_testpackage,
						"testpackage_resolved")))
	return output
}

func LangTestLib_run_testresult(
	lang *vxlang) string {
	assertequals := LangTestAssertEquals(lang, true, 3)
	assertnotequals := LangTestAssertNotEquals(lang, true, 3)
	println := LangPrintLine(lang)
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_run_testresult,
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
				LangIfThen(lang, 2,
					LangIfClause(lang, booleantype,
						"!", "passfail", ""),
					"\n      "+println+"(msg)"+lang.lineend+
						"\n      "+println+"(expected)"+lang.lineend+
						"\n      "+println+"(actual)"+lang.lineend+
						"\n      "+LangPkgNameDot(lang, "vx/core")+"f_log(testresult)"+lang.lineend)+
				LangIfEnd(lang, 2)+
				LangIfThen(lang, 2,
					LangIfClause(lang, rawstringtype, "==", "code", "\":ne\""),
					assertnotequals)+
				LangIfElse(lang, 2, assertequals)+
				LangIfEnd(lang, 2)+
				LangVal(lang, 2, testresulttype,
					"output", "testresult"))
	return output
}

func LangTestLib_sample_testdescribe1(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_sample_testdescribe1,
			LangVar(lang, 2, testdescribetype,
				"output",
				LangFuncCall(lang, 2,
					func_vx_new,
					LangTypeT(lang, testdescribetype),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":describename\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\"(test-true true)\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":testpkg\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\"vx/core\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":testresult\""),
					LangFuncCall(lang, 3,
						func_sample_testresult1,
						"context")))+
				LangTestLib_memory_leak_test(lang, 2, 5))
	return output
}

func LangTestLib_sample_testdescribe2(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_sample_testdescribe2,
			LangVar(lang, 2, testdescribetype,
				"output",
				LangFuncCall(lang, 2,
					func_vx_new,
					LangTypeT(lang, testdescribetype),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":describename\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\"(test-false false)\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":testpkg\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\"vx/core\""),
					LangFuncCall(lang, 3,
						func_vx_new_string,
						"\":testresult\""),
					LangFuncCall(lang, 3,
						func_sample_testresult2,
						"context")))+
				LangTestLib_memory_leak_test(lang, 2, 5))
	return output
}

func LangTestLib_sample_testdescribelist(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_sample_testdescribelist,
			LangVar(lang, 2, testdescribelisttype,
				"output",
				LangFuncCall(lang, 2,
					func_vx_any_from_any,
					LangTypeT(lang, testdescribelisttype),
					LangFuncCallMethod(lang, 3,
						LangTypeT(lang, testdescribelisttype),
						"vx_new",
						LangFuncCall(lang, 4,
							func_sample_testdescribe1,
							"context"),
						LangFuncCall(lang, 4,
							func_sample_testdescribe2,
							"context"))))+
				LangTestLib_memory_leak_test(lang, 2, 5))
	return output
}

func LangTestLib_sample_testresult1(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_sample_testresult1,
			LangVar(lang, 2, testresulttype,
				"output",
				LangFuncCall(lang, 2,
					func_f_test_true,
					"context",
					LangFuncCall(lang, 3,
						func_vx_new_boolean,
						"true")))+
				LangTestLib_memory_leak_test(lang, 2, 2))
	return output
}

func LangTestLib_sample_testresult2(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_sample_testresult2,
			LangVar(lang, 2, testresulttype,
				"output",
				LangFuncCall(lang, 2,
					func_f_test_false,
					"context",
					LangFuncCall(lang, 3,
						func_vx_new_boolean,
						"false")))+
				LangTestLib_memory_leak_test(lang, 2, 2))
	return output
}

func LangTestLib_test(
	lang *vxlang) string {
	assertequals := LangTestAssertEquals(lang, false, 2)
	println := LangPrintLine(lang)
	spass := "\n      " + println + "(\"Test Pass: \" + testname)" + lang.lineend
	sfail := "\n      " + println + "(\"Test Fail: \" + testname)" + lang.lineend
	sexpected := "\n      " + println + "(expected)" + lang.lineend
	sactual := "\n      " + println + "(actual)" + lang.lineend
	output := "" +
		LangTestLib_testfunc_helper(lang,
			func_test,
			assertequals+
				LangVar(lang, 2, rawbooltype,
					"output", "false")+
				LangIfThen(lang, 2,
					LangVxEqualsString(lang, "expected", "actual"),
					spass+
						LangVarSet(lang, 3, "output", "true"))+
				LangIfElse(lang, 2,
					sfail+
						sexpected+
						sactual)+
				LangIfEnd(lang, 2))
	return output
}

func LangTestLib_test_async_from_async_fn(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_async_from_async_fn,
			LangVal(lang, 2, stringtype,
				"helloworld",
				LangFuncCall(lang, 2,
					func_vx_new_string,
					"\"Hello World\""))+
				LangVarFuture(lang, 2, stringtype,
					"async",
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVarFuture(lang, 2, stringtype,
					"async1",
					LangFuncCall(lang, 2,
						func_vx_async_from_async_fn,
						LangTypeT(lang, stringtype),
						"async",
						LangTestLibLambda(lang, 3)))+
				LangVal(lang, 2, stringtype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async1)")+
				LangVal(lang, 2, rawstringtype,
					"expected",
					"\"Hello World\"")+
				LangVal(lang, 2, rawstringtype,
					"actual",
					"sync"+lang.typeref+"vx_string()")+
				LangTestLib_release(lang, 2, "helloworld"))
	return output
}

func LangTestLib_test_async_new_from_value(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_async_new_from_value,
			//long irefcount = vx_core::refcount;
			LangVal(lang, 2, stringtype,
				"helloworld",
				LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangValFuture(lang, 2, stringtype,
					"async",
					LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)")+
				LangVal(lang, 2, stringtype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringtype)+", async)")+
				LangVal(lang, 2, rawstringtype,
					"expected", "\"Hello World\"")+
				LangVal(lang, 2, rawstringtype,
					"actual",
					"sync"+lang.typeref+"vx_string()")+
				LangTestLib_release(lang, 2, "helloworld"))
	return output
}

func LangTestLib_test_helloworld(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_helloworld,
			LangVal(lang, 2, stringtype,
				"helloworld",
				LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")")+
				LangVal(lang, 2, rawstringtype,
					"expected", "\"Hello World\"")+
				LangVal(lang, 2, rawstringtype,
					"actual",
					LangFuncCallMethod(lang, 2,
						"helloworld",
						"vx_string")))
	return output
}

func LangTestLib_test_list_from_list_async(
	lang *vxlang) string {
	fn_async := LangTestLibFnAsync(lang)
	asynclist := LangPkgNameDot(lang, "vx/core") + "vx_list_from_list_async(" + LangTypeT(lang, stringlisttype) + ", slist, fn_async)"
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_list_from_list_async,
			LangVal(lang, 2, anylisttype,
				"sparams",
				LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(\"hello\", \"world\")")+
				LangVal(lang, 2, stringlisttype,
					"slist",
					LangPkgNameDot(lang, "vx/core")+"f_new_from_type("+LangTypeT(lang, stringlisttype)+", sparams)")+
				fn_async+
				LangValFuture(lang, 2, stringlisttype,
					"asynclist", asynclist)+
				LangVal(lang, 2, stringlisttype,
					"sync",
					LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangTypeT(lang, stringlisttype)+", asynclist)")+
				LangVal(lang, 2, rawstringtype,
					"expected",
					`"(stringlist\n \"hello!\"\n \"world!\")"`)+
				LangVal(lang, 2, rawstringtype,
					"actual",
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"sync"))+
				LangTestLib_release(lang, 2, "helloworld"))
	return output
}

func LangTestLib_test_pathfull_from_file(
	lang *vxlang) string {
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
		LangTestLib_testfunc(lang, fnc,
			LangVar(lang, 2, filetype,
				"file",
				LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")")+
				LangVar(lang, 2, stringtype,
					"string_path",
					LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)")+
				LangTestLib_expected(lang, 2,
					`spath + "/vx/string_read_from_file.txt"`)+
				LangTestLib_actual(lang, 2,
					LangFuncCallMethod(lang, 2,
						"string_path",
						"vx_string"))+
				LangTestLib_release(lang, 2,
					"string_path"))
	return output
}

func LangTestLib_test_read_file(
	lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_read_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangTestLib_testfunc(lang, fnc,
			LangTestLib_expected(lang, 2,
				`"testdata"`)+
				LangTestLib_actual(lang, 2,
					`read_test_file(spath + "/vx", "string_read_from_file.txt")`)+
				LangTestLib_release(lang, 2,
					"string_path"))
	return output
}

func LangTestLib_test_run_testdescribe(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang, func_test_run_testdescribe,
			LangVal(lang, 2, testdescribetype,
				"testdescribe",
				LangFuncCall(lang, 2,
					func_sample_testdescribe1,
					"context"))+
				LangVal(lang, 2, testdescribetype,
					"testdescribe_resolved",
					LangFuncCall(lang, 2,
						func_run_testdescribe,
						"\"vx/core\"",
						"\"boolean\"",
						"testdescribe"))+
				LangTestLib_expected(lang, 2,
					LangTestLib_testfunc_read_test_file(
						lang, 2, func_test_run_testdescribe))+
				LangTestLib_actual(lang, 2,
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"testdescribe_resolved"))+
				LangTestLib_release(lang, 2,
					"testdescribe_resolved"))
	return output
}

func LangTestLib_test_run_testdescribelist(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang, func_test_run_testdescribelist,
			LangVar(lang, 2, testresulttype,
				"testresult",
				LangFuncCall(lang, 2,
					func_sample_testresult1,
					"context"))+
				LangVar(lang, 2, testresulttype,
					"testresult_resolved",
					LangFuncCall(lang, 2,
						func_run_testresult,
						"\"vx/core\"",
						"\"boolean\"",
						"\"\"",
						"testresult"))+
				LangTestLib_expected(lang, 2,
					LangTestLib_testfunc_read_test_file(
						lang, 2, func_test_run_testdescribelist))+
				LangTestLib_actual(lang, 2,
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"testresult_resolved"))+
				LangTestLib_release(lang, 2,
					"testresult_resolved"))
	return output
}

func LangTestLib_test_run_testdescribelist_async(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_run_testdescribelist_async,
			LangVar(lang, 2, testdescribelisttype,
				"testdescribelist",
				LangFuncCall(lang, 2,
					func_sample_testdescribelist,
					"context"))+
				LangVar(lang, 2, testdescribelisttype,
					"testdescribelist_resolved",
					LangFuncCall(lang, 2,
						func_run_testdescribelist,
						"\"vx/core\"",
						"\"boolean\"",
						"testdescribelist"))+
				LangTestLib_expected(lang, 2,
					LangTestLib_testfunc_read_test_file(
						lang, 2, func_test_run_testdescribelist_async))+
				LangTestLib_actual(lang, 2,
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"testdescribelist_resolved"))+
				LangTestLib_release(lang, 2,
					"testdescribe_resolved"))
	return output
}

func LangTestLib_test_run_testresult(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_run_testresult,
			LangVar(lang, 2, testresulttype,
				"testresult",
				LangFuncCall(lang, 2,
					func_sample_testresult1,
					"context"))+
				LangVar(lang, 2, testresulttype,
					"testresult_resolved",
					LangFuncCall(lang, 2,
						func_run_testresult,
						"\"vx/core\"",
						"\"boolean\"",
						"\"\"",
						"testresult"))+
				LangTestLib_expected(lang, 2,
					LangTestLib_testfunc_read_test_file(
						lang, 2, func_test_run_testresult))+
				LangTestLib_actual(lang, 2,
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"testresult_resolved"))+
				LangTestLib_release(lang, 2,
					"testresult_resolved"))
	return output
}

func LangTestLib_test_run_testresult_async(
	lang *vxlang) string {
	output := "" +
		LangTestLib_testfunc(lang,
			func_test_run_testresult_async,
			LangVar(lang, 2, testresulttype,
				"testresult",
				LangFuncCall(lang, 2,
					func_sample_testresult1,
					"context"))+
				LangVar(lang, 2, testresulttype,
					"testresult_resolved",
					LangFuncCall(lang, 2,
						func_run_testresult,
						"\"vx/core\"",
						"\"boolean\"",
						"\"\"",
						"testresult"))+
				LangTestLib_expected(lang, 2,
					LangTestLib_testfunc_read_test_file(
						lang, 2, func_test_run_testresult_async))+
				LangTestLib_actual(lang, 2,
					LangFuncCall(lang, 2,
						func_vx_string_from_any,
						"testresult_resolved"))+
				LangTestLib_release(lang, 2,
					"testresult_resolved"))
	return output
}

func LangTestLib_test_write_file(
	lang *vxlang) string {
	fnc := NewFuncFromPkgnameName("TestLib", "test_write_file")
	fnc.vxtype = rawbooltype
	output := "" +
		LangTestLib_testfunc(lang, fnc,
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
				LangTestLib_expected(lang, 2,
					`spath + "/vx/string_read_from_file.txt"`)+
				LangTestLib_actual(lang, 2,
					"string_path"+lang.typeref+"vx_string()")+
				LangTestLib_release(lang, 2, "string_path"))
	return output
}

func LangTestLib_actual(
	lang *vxlang,
	indent int,
	value string) string {
	return LangVar(lang, 2, rawstringtype,
		"actual",
		value)
}

func LangTestLib_expected(
	lang *vxlang,
	indent int,
	value string) string {
	return LangVar(lang, 2, rawstringtype,
		"expected",
		value)
}

func LangTestLib_memory_leak_test(
	lang *vxlang,
	indent int,
	expected int) string {
	output := ""
	switch lang {
	case langcpp:
		sindent := LangIndent(lang, 2, true)
		if expected == -1 {
			output = "" +
				sindent + "output = output && vx_core::vx_memory_leak_test(testname, irefcount)" + lang.lineend
		} else {
			output = "" +
				sindent + "vx_core::vx_memory_leak_test(testname, irefcount, " + StringFromInt(expected) + ")" + lang.lineend

		}
	}
	return output
}

func LangTestLib_memory_refcount(
	lang *vxlang,
	indent int) string {
	output := ""
	switch lang {
	case langcpp:
		sindent := LangIndent(lang, 2, true)
		output = sindent + "long irefcount = vx_core::refcount" + lang.lineend
	}
	return output
}

func LangTestLib_testfunc(
	lang *vxlang,
	fnc *vxfunc,
	body string) string {
	header := "" +
		LangVal(lang, 2, rawstringtype,
			"testname",
			"\""+fnc.name+"\"") +
		LangTestLib_memory_refcount(lang, 2)
	footer := "" +
		LangVal(lang, 2, rawbooltype,
			"output",
			LangFuncCall(lang, 2,
				func_test,
				"testname",
				"expected",
				"actual")) +
		LangTestLib_memory_leak_test(lang, 2, 0)
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			header+
				body+
				footer)
	return output
}

func LangTestLib_testfunc_helper(
	lang *vxlang,
	fnc *vxfunc,
	body string) string {
	header := ""
	LangTestLib_memory_refcount(lang, 2)
	footer := "" +
		LangTestLib_memory_leak_test(lang, 2, 0)
	output := "" +
		LangFuncHeaderStatic(lang, 1,
			"", fnc, 0,
			header+
				body+
				footer)
	return output
}

func LangTestLib_testfunc_read_test_file(
	lang *vxlang,
	indent int,
	fnc *vxfunc) string {
	filename := fnc.alias + ".txt"
	output := LangFuncCall(lang, indent,
		func_read_test_file,
		"spath + \"/vx\"",
		"\""+filename+"\"")
	return output
}

func LangTestLib_write_testpackagelist_async(
	lang *vxlang) string {
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
