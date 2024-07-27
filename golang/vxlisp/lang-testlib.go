package vxlisp

func LangTestLib(lang *vxlang) string {
	output := ""
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "TestLib")
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
	switch lang.name {
	case "csharp":
		output = "" +
			"\nusing Xunit;" +
			"\n" +
			"\nnamespace AppTest;" +
			"\n" +
			namespaceopen +
			"\n  public class TestOutputWriter : TextWriter {" +
			"\n" +
			"\n    private readonly Xunit.Abstractions.ITestOutputHelper _output;" +
			"\n" +
			"\n    public TestOutputWriter(Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n      _output = output;" +
			"\n    }" +
			"\n" +
			"\n    public override System.Text.Encoding Encoding => System.Text.Encoding.UTF8;" +
			"\n" +
			"\n			 public override void WriteLine(int message) {" +
			"\n				  _output.WriteLine(\"\" + message);" +
			"\n  		}" +
			"\n" +
			"\n  		public override void WriteLine(string? message) {" +
			"\n  				_output.WriteLine(message);" +
			"\n  		}" +
			"\n" +
			"\n  }" +
			"\n" +
			"\n  public static bool EnableConsole(" +
			"\n    Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n    TestOutputWriter converter = new TestOutputWriter(output);" +
			"\n    System.Console.SetOut(converter);" +
			"\n    return true;" +
			"\n  }" +
			"\n" +
			"\n  public static string spath = " + spath + ";" +
			"\n" +
			commontests +
			namespaceclose
	case "java":
		output = `
import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;
` +
			namespaceopen +
			"\n  public static String spath = " + spath + ";" +
			"\n" +
			commontests +
			"\n" +
			`
  // Blocking
  // Only use if running a single testdescribe
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testdescribe_async(final ` + LangNameTypeFromType(lang, rawstringtype) + ` testpkg, final ` + LangNameTypeFromType(lang, rawstringtype) + ` casename, final Test.Type_testdescribe testdescribe) {
    ` + lang.future + `<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    ` + LangNameTypeFromType(lang, rawbooltype) + ` output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
      ` + LangNameTypeFromType(lang, rawbooltype) + ` testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  // Blocking
  public static ` + LangNameTypeFromType(lang, rawbooltype) + ` run_testresult_async(final ` + LangNameTypeFromType(lang, rawstringtype) + ` testpkg, final ` + LangNameTypeFromType(lang, rawstringtype) + ` testname, final ` + LangNameTypeFromType(lang, rawstringtype) + ` message, Test.Type_testresult testresult) {
    ` + lang.future + `<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }
` +
			namespaceclose
	}
	return output
}

func LangTestLib_file_test(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "file_test"
	fnc.vxtype = filetype
	arg := NewArg("file")
	arg.vxtype = filetype
	fnc.listarg = append(fnc.listarg, arg)
	paramsopen := ""
	paramsclose := ""
	switch lang.name {
	case "cpp":
		paramsopen = "{"
		paramsclose = "}"
	}
	fileparams := "" +
		"\n      file," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), spath" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		//	long irefcount = vx_core::refcount;
		LangVar(lang, "output", filetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_copy("+fileparams+")", 2, false, false) +
		//vx_core::vx_release(string_file);
		"\n			 return output;" +
		"\n  }" +
		"\n"
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
	paramsopen := ""
	paramsclose := ""
	switch lang.name {
	case "cpp":
		paramsopen = "{"
		paramsclose = "}"
	}
	fileparams := "" +
		"\n      " + LangNameTFromType(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		//	long irefcount = vx_core::refcount;
		LangVar(lang, "file", filetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")", 2, false, false) +
		LangVar(lang, "string_file", stringtype, emptytype, LangPkgNameDot(lang, "vx/data/file")+"vx_string_read_from_file(file)", 2, false, false) +
		LangVar(lang, "output", rawstringtype, emptytype, "string_file"+lang.typeref+"vx_string()", 2, false, false) +
		//vx_core::vx_release(string_file);
		"\n			 return output;" +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testpkg", rawstringtype, emptytype, "testcase.testpkg().vx_string()", 2, false, false) +
		LangVar(lang, "casename", rawstringtype, emptytype, "testcase.casename().vx_string()", 2, false, false) +
		LangVar(lang, "testdescribelist", testdescribelisttype, emptytype, "testcase.describelist()", 2, false, false) +
		LangVar(lang, "output", rawbooleantype, emptytype, "run_testdescribelist(testpkg, casename, testdescribelist)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "async_testcase", testcasetype, emptytype, LangPkgNameDot(lang, "vx/test")+"f_resolve_testcase(testcase)", 2, false, true) +
		LangVar(lang, "testcase_resolved", testcasetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, testcasetype)+", async_testcase)", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testcase(testcase_resolved)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "listtestcase", rawlisttype, testcasetype, "testcaselist.vx_listtestcase()", 2, false, false) +
		LangForListHeader(lang, "testcase", testcasetype, "listtestcase", 2) +
		"\n      run_testcase(testcase)" + lang.lineend +
		"\n    }" +
		"\n    return true;" +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testcode", stringtype, emptytype, "describe.describename()", 2, false, false) +
		LangVar(lang, "message", rawstringtype, emptytype, "testcode.vx_string()", 2, false, false) +
		LangVar(lang, "testresult", testresulttype, emptytype, "describe.testresult()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testresult(testpkg, casename, message, testresult)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "output", rawbooltype, emptytype, "true", 2, false, false) +
		LangVar(lang, "listtestdescribe", rawlisttype, testdescribetype, "testdescribelist.vx_listtestdescribe()", 2, false, false) +
		LangForListHeader(lang, "testdescribe", testdescribetype, "listtestdescribe", 2) +
		LangVar(lang, "testoutput", rawbooltype, emptytype, "run_testdescribe(testpkg, casename, testdescribe)", 3, false, false) +
		"\n 	    if (!testoutput) {" +
		"\n   			  output = false" + lang.lineend +
		"\n      }" +
		"\n    }" +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testcaselist", testcaselisttype, emptytype, "testpackage.caselist()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testcaselist(testcaselist)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "async_testpackage", testpackagetype, emptytype, LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackage(testpackage)", 2, false, true) +
		LangVar(lang, "testpackage_resolved", testpackagetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, testpackagetype)+", async_testpackage)", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "run_testpackage(testpackage_resolved)", 2, false, false) +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
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
	assertequals := ""
	assertnotequals := ""
	println := ""
	switch lang.name {
	case "csharp":
		assertequals = "\n  				Assert.Equal(expected, actual)" + lang.lineend
		assertnotequals = "\n	  			Assert.NotEqual(expected, actual)" + lang.lineend
		println = "System.Console.WriteLine"
	case "java":
		assertequals = "\n  				assertEquals(expected, actual, msg)" + lang.lineend
		assertnotequals = "\n	  			assertNotEquals(expected, actual, msg)" + lang.lineend
		println = "System.out.println"
	}
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "valexpected", anytype, emptytype, "testresult.expected()", 2, false, false) +
		LangVar(lang, "valactual", anytype, emptytype, "testresult.actual()", 2, false, false) +
		LangVar(lang, "passfail", rawbooltype, emptytype, "testresult.passfail().vx_boolean()", 2, false, false) +
		LangVar(lang, "code", rawstringtype, emptytype, "testresult.code().vx_string()", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valexpected).vx_string()", 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"f_string_from_any(valactual).vx_string()", 2, false, false) +
		LangVar(lang, "msg", rawstringtype, emptytype, "testpkg + \"/\" + testname + \" \" + message", 2, false, false) +
		"\n  		if (!passfail) {" +
		"\n  				" + println + "(msg)" + lang.lineend +
		"\n  				" + println + "(expected)" + lang.lineend +
		"\n  				" + println + "(actual)" + lang.lineend +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "f_log(testresult)" + lang.lineend +
		"\n		  }" +
		"\n  		switch (code) {" +
		"\n		  case \":ne\":" +
		assertnotequals +
		"\n  				break" + lang.lineend +
		"\n  		default:" +
		assertequals +
		"\n  				break" + lang.lineend +
		"\n  		}" +
		"\n  		return true" + lang.lineend +
		"\n  }" +
		"\n"
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
	switch lang.name {
	case "csharp":
		assertequals = "\n    Assert.Equal(expected, actual)" + lang.lineend
		println = "System.Console.WriteLine"
	case "java":
		assertequals = "\n    assertEquals(expected, actual)" + lang.lineend
		println = "System.out.println"
	}
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		assertequals +
		LangVar(lang, "output", rawbooltype, emptytype, "false", 2, false, false) +
		"\n    if (" + LangVxEqualsString(lang, "expected", "actual") + ") {" +
		LangVarSet(lang, "output", "true", 3) +
		"\n    } else {" +
		"\n      " + println + "(testname)" + lang.lineend +
		"\n      " + println + "(expected)" + lang.lineend +
		"\n      " + println + "(actual)" + lang.lineend +
		"\n    }" +
		"\n    return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_async_from_async_fn(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_from_async_fn"
	fnc.vxtype = rawbooltype
	slambda := ""
	switch lang.name {
	case "cpp":
		slambda = "" +
			"{}," +
			"\n[](vx_core::Type_any any) {" +
			"\n 		return any;" +
			"\n}"
	case "csharp":
		slambda = "" +
			"(any) => {" +
			"\n     	return any;" +
			"\n    }"
	case "java":
		slambda = "" +
			"(any) -> {" +
			"\n     	return any;" +
			"\n    }"
	}
	sasync1 := "" +
		LangPkgNameDot(lang, "vx/core") + "vx_async_from_async_fn(async, " + slambda +
		")"
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//long irefcount = vx_core::refcount;
		LangVar(lang, "helloworld", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")", 2, false, false) +
		LangVar(lang, "async", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)", 2, false, true) +
		LangVar(lang, "async1", stringtype, emptytype, sasync1, 2, false, true) +
		LangVar(lang, "sync", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, stringtype)+", async1)", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, "\"Hello World\"", 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, "sync"+lang.typeref+"vx_string()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n  		return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_async_new_from_value(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_new_from_value"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//long irefcount = vx_core::refcount;
		LangVar(lang, "helloworld", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")", 2, false, false) +
		LangVar(lang, "async", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_async_new_from_value(helloworld)", 2, false, true) +
		LangVar(lang, "sync", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, stringtype)+", async)", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, "\"Hello World\"", 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, "sync"+lang.typeref+"vx_string()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n  		return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_helloworld(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_helloworld"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//long irefcount = vx_core::refcount;
		LangVar(lang, "helloworld", stringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"Hello World\")", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, "\"Hello World\"", 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, "helloworld"+lang.typeref+"vx_string()", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n  		return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_list_from_list_async(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_list_from_list_async"
	fnc.vxtype = rawbooltype
	fn_async := ""
	switch lang.name {
	case "csharp":
		fn_async = "" +
			"\n    Vx.Core.Func_any_from_any_async fn_async = Vx.Core.t_any_from_any_async.vx_fn_new((anyval) => {" +
			"\n      Vx.Core.Type_string stringval = (Vx.Core.Type_string)anyval;" +
			"\n      string sout = stringval.vx_string() + \"!\";" +
			"\n      Vx.Core.Type_any outval = Vx.Core.vx_new_string(sout);" +
			"\n      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case "java":
		fn_async = "" +
			"\n    Core.Func_any_from_any_async fn_async = Core.t_any_from_any_async.vx_fn_new((anyval) -> {" +
			"\n      Core.Type_string stringval = (Core.Type_string)anyval;" +
			"\n      String sout = stringval.vx_string() + \"!\";" +
			"\n      Core.Type_any outval = Core.vx_new_string(sout);" +
			"\n      CompletableFuture<Core.Type_any> output = Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	}
	asynclist := LangPkgNameDot(lang, "vx/core") + "vx_list_from_list_async(" + LangNameTFromType(lang, stringlisttype) + ", slist, fn_async)"
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//long irefcount = vx_core::refcount;
		LangVar(lang, "sparams", anylisttype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(\"hello\", \"world\")", 2, false, false) +
		LangVar(lang, "slist", stringlisttype, emptytype, LangPkgNameDot(lang, "vx/core")+"f_new("+LangNameTFromType(lang, stringlisttype)+", sparams)", 2, false, false) +
		fn_async +
		LangVar(lang, "asynclist", stringlisttype, emptytype, asynclist, 2, false, true) +
		LangVar(lang, "sync", stringlisttype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, stringlisttype)+", asynclist)", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, `"(stringlist\n \"hello!\"\n \"world!\")"`, 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_string_from_any(sync)", 2, false, false) +
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//vx_core::vx_release(helloworld);
		//output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n  		return output" + lang.lineend +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_pathfull_from_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_pathfull_from_file"
	fnc.vxtype = rawbooltype
	paramsopen := ""
	paramsclose := ""
	switch lang.name {
	case "cpp":
		paramsopen = "{"
		paramsclose = "}"
	}
	fileparams := "" +
		"\n      " + LangNameTFromType(lang, filetype) + "," +
		paramsopen +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":path\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(spath + \"/vx\")," +
		"\n      " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\":name\"), " + LangPkgNameDot(lang, "vx/core") + "vx_new_string(\"string_read_from_file.txt\")" +
		paramsclose
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//	long irefcount = vx_core::refcount;
		LangVar(lang, "file", filetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new("+fileparams+")", 2, false, false) +
		LangVar(lang, "string_path", stringtype, emptytype, LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, `spath + "/vx/string_read_from_file.txt"`, 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, "string_path"+lang.typeref+"vx_string()", 2, false, false) +
		// vx_core::vx_release(string_path);
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n			 return output;" +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_read_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_read_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//	long irefcount = vx_core::refcount;
		LangVar(lang, "expected", rawstringtype, emptytype, `"testdata"`, 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, `read_test_file(spath + "/vx", "string_read_from_file.txt")`, 2, false, false) +
		// vx_core::vx_release(string_path);
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n			 return output;" +
		"\n  }" +
		"\n"
	return output
}

func LangTestLib_test_write_file(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_write_file"
	fnc.vxtype = rawbooltype
	output := "" +
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "testname", rawstringtype, emptytype, "\""+fnc.name+"\"", 2, false, false) +
		//	long irefcount = vx_core::refcount;
		LangVar(lang, "file", filetype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_new("+LangNameTFromType(lang, filetype)+", "+
			"\n    "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":path\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(spath + \"/vx\"),"+
			"\n    "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\":name\"), "+LangPkgNameDot(lang, "vx/core")+"vx_new_string(\"string_read_from_file.txt\")"+
			"\n  )", 2, false, false) +
		LangVar(lang, "string_path", stringtype, emptytype, LangPkgNameDot(lang, "vx/data/file")+"f_pathfull_from_file(file)", 2, false, false) +
		LangVar(lang, "expected", rawstringtype, emptytype, `spath + "/vx/string_read_from_file.txt"`, 2, false, false) +
		LangVar(lang, "actual", rawstringtype, emptytype, "string_path"+lang.typeref+"vx_string()", 2, false, false) +
		// vx_core::vx_release(string_path);
		LangVar(lang, "output", rawbooltype, emptytype, "TestLib"+lang.pkgref+"test(testname, expected, actual)", 2, false, false) +
		//	output = output && vx_core::vx_memory_leak_test(testname, irefcount);
		"\n			 return output;" +
		"\n  }" +
		"\n"
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
		LangFuncHeaderAll(lang, "", fnc, 1, false, true) +
		LangVar(lang, "output", rawbooltype, emptytype, "false", 2, false, false) +
		LangVar(lang, "async_testpackagelist", testpackagelisttype, emptytype, LangPkgNameDot(lang, "vx/test")+"f_resolve_testpackagelist(testpackagelist)", 2, false, true) +
		LangVar(lang, "testpackagelist_resolved", testpackagelisttype, emptytype, LangPkgNameDot(lang, "vx/core")+"vx_sync_from_async("+LangNameTFromType(lang, testpackagelisttype)+", async_testpackagelist)", 2, false, false) +
		LangVar(lang, "filetest", filetype, emptytype, "file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_test())", 2, false, false) +
		LangVar(lang, "valboolean", booleantype, emptytype, LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved)", 2, false, false) +
		LangVarSet(lang, "output", "valboolean.vx_boolean()", 2) +
		LangVar(lang, "divtest", htmldivtype, emptytype, LangPkgNameDot(lang, "vx/test")+"f_div_from_testpackagelist(testpackagelist_resolved)", 2, false, false) +
		LangVar(lang, "htmlnode", htmltype, emptytype, LangPkgNameDot(lang, "vx/test")+"f_html_from_divtest(divtest)", 2, false, false) +
		LangVar(lang, "filenode", filetype, emptytype, "file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testnode())", 2, false, false) +
		LangVarSet(lang, "valboolean", LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filenode, htmlnode)", 2) +
		LangVarSet(lang, "output", "output && valboolean.vx_boolean()", 2) +
		LangVar(lang, "filehtml", filetype, emptytype, "file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testhtml())", 2, false, false) +
		LangVar(lang, "shtml", stringtype, emptytype, LangPkgNameDot(lang, "vx/web/html")+"f_string_from_html(htmlnode)", 2, false, false) +
		LangVarSet(lang, "valboolean", LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_string(context, filehtml, shtml)", 2) +
		LangVarSet(lang, "output", "output && valboolean.vx_boolean()", 2) +
		"\n			 return output;" +
		"\n  }" +
		"\n"
	return output
}
