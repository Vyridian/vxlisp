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
	switch lang {
	case langcsharp:
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
	case langjava:
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
  public static ` + LangTypeName(lang, rawbooltype) + ` run_testdescribe_async(final ` + LangTypeName(lang, rawstringtype) + ` testpkg, final ` + LangTypeName(lang, rawstringtype) + ` casename, final Test.Type_testdescribe testdescribe) {
    ` + lang.future + `<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  public static ` + LangTypeName(lang, rawbooltype) + ` run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    ` + LangTypeName(lang, rawbooltype) + ` output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
      ` + LangTypeName(lang, rawbooltype) + ` testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static ` + LangTypeName(lang, rawbooltype) + ` run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  // Blocking
  public static ` + LangTypeName(lang, rawbooltype) + ` run_testresult_async(final ` + LangTypeName(lang, rawstringtype) + ` testpkg, final ` + LangTypeName(lang, rawstringtype) + ` testname, final ` + LangTypeName(lang, rawstringtype) + ` message, Test.Type_testresult testresult) {
    ` + lang.future + `<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = ` + LangPkgNameDot(lang, "vx/core") + `vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }
` +
			namespaceclose
	case langkotlin:
		output = `
import java.util.*
import java.util.concurrent.CompletableFuture
import org.junit.jupiter.api.Assertions.*
import com.vxlisp.vx.*
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*
` +
			namespaceopen +
			"\n  val spath : String = " + spath +
			"\n" +
			commontests +
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
	switch lang {
	case langcpp:
		paramsopen = "{"
		paramsclose = "}"
	}
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
	paramsopen := ""
	paramsclose := ""
	switch lang {
	case langcpp:
		paramsopen = "{"
		paramsclose = "}"
	}
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
	assertequals := ""
	assertnotequals := ""
	println := ""
	switch lang {
	case langcsharp:
		assertequals = "\n  				Assert.Equal(expected, actual)" + lang.lineend
		assertnotequals = "\n	  			Assert.NotEqual(expected, actual)" + lang.lineend
		println = "System.Console.WriteLine"
	case langjava:
		assertequals = "\n  				assertEquals(expected, actual, msg)" + lang.lineend
		assertnotequals = "\n	  			assertNotEquals(expected, actual, msg)" + lang.lineend
		println = "System.out.println"
	case langkotlin:
		assertequals = "\n  				assertEquals(expected, actual, msg)" + lang.lineend
		assertnotequals = "\n	  			assertNotEquals(expected, actual, msg)" + lang.lineend
		println = "println"
	}
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
					LangIfClause(lang, rawstringtype, "==", "code", "\":ne\""),
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
				"\n    if ("+LangVxEqualsString(lang, "expected", "actual")+") {"+
				LangVarSet(lang, "output", 3, "true")+
				"\n    } else {"+
				"\n      "+println+"(testname)"+lang.lineend+
				"\n      "+println+"(expected)"+lang.lineend+
				"\n      "+println+"(actual)"+lang.lineend+
				"\n    }")
	return output
}

func LangTestLib_test_async_from_async_fn(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_async_from_async_fn"
	fnc.vxtype = rawbooltype
	slambda := ""
	switch lang {
	case langcpp:
		slambda = "" +
			"{}," +
			"\n[](vx_core::Type_any any) {" +
			"\n 		return any;" +
			"\n}"
	case langcsharp:
		slambda = "" +
			"(any) => {" +
			"\n     	return any;" +
			"\n    }"
	case langjava:
		slambda = "" +
			"(any) -> {" +
			"\n     	return any;" +
			"\n    }"
	case langkotlin:
		slambda = "" +
			"{any ->" +
			"\n     	any" +
			"\n    }"
	}
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

func LangTestLib_test_list_from_list_async(lang *vxlang) string {
	fnc := NewFunc()
	fnc.name = "test_list_from_list_async"
	fnc.vxtype = rawbooltype
	fn_async := ""
	switch lang {
	case langcsharp:
		fn_async = "" +
			"\n    Vx.Core.Func_any_from_any_async fn_async = Vx.Core.t_any_from_any_async.vx_fn_new((anyval) => {" +
			"\n      Vx.Core.Type_string stringval = (Vx.Core.Type_string)anyval;" +
			"\n      string sout = stringval.vx_string() + \"!\";" +
			"\n      Vx.Core.Type_any outval = Vx.Core.vx_new_string(sout);" +
			"\n      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case langjava:
		fn_async = "" +
			"\n    Core.Func_any_from_any_async fn_async = Core.t_any_from_any_async.vx_fn_new((anyval) -> {" +
			"\n      Core.Type_string stringval = (Core.Type_string)anyval;" +
			"\n      String sout = stringval.vx_string() + \"!\";" +
			"\n      Core.Type_any outval = Core.vx_new_string(sout);" +
			"\n      CompletableFuture<Core.Type_any> output = Core.vx_async_new_from_value(outval);" +
			"\n      return output;" +
			"\n    });"
	case langkotlin:
		fn_async = "" +
			"\n    val fn_async : vx_core.Func_any_from_any_async = vx_core.t_any_from_any_async.vx_fn_new({" +
			"\n      anyval ->" +
			"\n      val stringval : vx_core.Type_string = anyval as vx_core.Type_string" +
			"\n      val sout : String = stringval.vx_string() + \"!\"" +
			"\n      val outval : vx_core.Type_any = vx_core.vx_new_string(sout)" +
			"\n      val output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(outval)" +
			"\n      output" +
			"\n    });"
	}
	asynclist := LangPkgNameDot(lang, "vx/core") + "vx_list_from_list_async(" + LangTypeT(lang, stringlisttype) + ", slist, fn_async)"
	output := "" +
		LangFuncHeaderStatic(lang, "", fnc, 1, 0,
			LangVar(lang, "testname", rawstringtype, 2,
				"\""+fnc.name+"\"")+
				//long irefcount = vx_core::refcount;
				LangVar(lang, "sparams", anylisttype, 2,
					LangPkgNameDot(lang, "vx/core")+"vx_anylist_from_arraystring(\"hello\", \"world\")")+
				LangVar(lang, "slist", stringlisttype, 2,
					LangPkgNameDot(lang, "vx/core")+"f_new("+LangTypeT(lang, stringlisttype)+", sparams)")+
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
	paramsopen := ""
	paramsclose := ""
	switch lang {
	case langcpp:
		paramsopen = "{"
		paramsclose = "}"
	}
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
				LangVarSet(lang, "output", 2,
					"valboolean.vx_boolean()")+
				LangVar(lang, "divtest", htmldivtype, 2,
					LangPkgNameDot(lang, "vx/test")+"f_div_from_testpackagelist(testpackagelist_resolved)")+
				LangVar(lang, "htmlnode", htmltype, 2,
					LangPkgNameDot(lang, "vx/test")+"f_html_from_divtest(divtest)")+
				LangVar(lang, "filenode", filetype, 2,
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testnode())")+
				LangVarSet(lang, "valboolean", 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_any(context, filenode, htmlnode)")+
				LangVarSet(lang, "output", 2,
					"output && valboolean.vx_boolean()")+
				LangVar(lang, "filehtml", filetype, 2,
					"file_test("+LangPkgNameDot(lang, "vx/test")+"f_file_testhtml())")+
				LangVar(lang, "shtml", stringtype, 2, LangPkgNameDot(lang, "vx/web/html")+"f_string_from_html(htmlnode)")+
				LangVarSet(lang, "valboolean", 2,
					LangPkgNameDot(lang, "vx/data/file")+"f_boolean_write_from_file_string(context, filehtml, shtml)")+
				LangVarSet(lang, "output", 2, "output && valboolean.vx_boolean()"))
	return output
}
