
import java.util.*
import java.util.concurrent.CompletableFuture
import org.junit.jupiter.api.Assertions.*
import com.vxlisp.vx.*
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*

object TestLib {


  val spath : String = vx_core.c_path_test_resources.vx_string()

  fun file_test(file : vx_data_file.Type_file) : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_core.vx_copy(
      file,
      vx_core.vx_new_string(":path"), spath)
    return output
  }

  fun read_test_file(path : String, filename : String) : String {
    var file : vx_data_file.Type_file = vx_core.vx_new(
      vx_data_file.t_file,
      vx_core.vx_new_string(":path"), vx_core.vx_new_string(spath + "/vx"),
      vx_core.vx_new_string(":name"), vx_core.vx_new_string("string_read_from_file.txt"))
    var string_file : vx_core.Type_string = vx_data_file.vx_string_read_from_file(file)
    var output : String = string_file.vx_string()
    return output
  }

  fun test(testname : String, expected : String, actual : String) : Boolean {
    assertEquals(expected, actual)
    var output : Boolean = false
    if (expected.equals(actual)) {
      output = true
    } else {
      println(testname)
      println(expected)
      println(actual)
    }
    return output
  }

  fun test_helloworld() : Boolean {
    var testname : String = "test_helloworld"
    var helloworld : vx_core.Type_string = vx_core.vx_new_string("Hello World")
    var expected : String = "Hello World"
    var actual : String = helloworld.vx_string()
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_async_new_from_value() : Boolean {
    var testname : String = "test_async_new_from_value"
    var helloworld : vx_core.Type_string = vx_core.vx_new_string("Hello World")
    var async : CompletableFuture<vx_core.Type_string> = vx_core.vx_async_new_from_value(helloworld)
    var sync : vx_core.Type_string = vx_core.vx_sync_from_async(vx_core.t_string, async)
    var expected : String = "Hello World"
    var actual : String = sync.vx_string()
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_async_from_async_fn() : Boolean {
    var testname : String = "test_async_from_async_fn"
    var helloworld : vx_core.Type_string = vx_core.vx_new_string("Hello World")
    var async : CompletableFuture<vx_core.Type_string> = vx_core.vx_async_new_from_value(helloworld)
    var async1 : CompletableFuture<vx_core.Type_string> = vx_core.vx_async_from_async_fn(async, {any ->
     	any
    })
    var sync : vx_core.Type_string = vx_core.vx_sync_from_async(vx_core.t_string, async1)
    var expected : String = "Hello World"
    var actual : String = sync.vx_string()
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_list_from_list_async() : Boolean {
    var testname : String = "test_list_from_list_async"
    var sparams : vx_core.Type_anylist = vx_core.vx_anylist_from_arraystring("hello", "world")
    var slist : vx_core.Type_stringlist = vx_core.f_new(vx_core.t_stringlist, sparams)
    val fn_async : vx_core.Func_any_from_any_async = vx_core.t_any_from_any_async.vx_fn_new({
      anyval ->
      val stringval : vx_core.Type_string = anyval as vx_core.Type_string
      val sout : String = stringval.vx_string() + "!"
      val outval : vx_core.Type_any = vx_core.vx_new_string(sout)
      val output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(outval)
      output
    });
    var asynclist : CompletableFuture<vx_core.Type_stringlist> = vx_core.vx_list_from_list_async(vx_core.t_stringlist, slist, fn_async)
    var sync : vx_core.Type_stringlist = vx_core.vx_sync_from_async(vx_core.t_stringlist, asynclist)
    var expected : String = "(stringlist\n \"hello!\"\n \"world!\")"
    var actual : String = vx_core.vx_string_from_any(sync)
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_pathfull_from_file() : Boolean {
    var testname : String = "test_pathfull_from_file"
    var file : vx_data_file.Type_file = vx_core.vx_new(
      vx_data_file.t_file,
      vx_core.vx_new_string(":path"), vx_core.vx_new_string(spath + "/vx"),
      vx_core.vx_new_string(":name"), vx_core.vx_new_string("string_read_from_file.txt"))
    var string_path : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
    var expected : String = spath + "/vx/string_read_from_file.txt"
    var actual : String = string_path.vx_string()
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_read_file() : Boolean {
    var testname : String = "test_read_file"
    var expected : String = "testdata"
    var actual : String = read_test_file(spath + "/vx", "string_read_from_file.txt")
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun test_write_file() : Boolean {
    var testname : String = "test_write_file"
    var file : vx_data_file.Type_file = vx_core.vx_new(
      vx_data_file.t_file, 
      vx_core.vx_new_string(":path"), vx_core.vx_new_string(spath + "/vx"),
      vx_core.vx_new_string(":name"), vx_core.vx_new_string("string_read_from_file.txt")
    )
    var string_path : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
    var expected : String = spath + "/vx/string_read_from_file.txt"
    var actual : String = string_path.vx_string()
    var output : Boolean = TestLib.test(testname, expected, actual)
    return output
  }

  fun run_testcase(testcase : vx_test.Type_testcase) : Boolean {
    var testpkg : String = testcase.testpkg().vx_string()
    var casename : String = testcase.casename().vx_string()
    var testdescribelist : vx_test.Type_testdescribelist = testcase.describelist()
    var output : Boolean = run_testdescribelist(testpkg, casename, testdescribelist)
    return output
  }

  // Blocking
  // Only use if running a single testcase
  fun run_testcase_async(testcase : vx_test.Type_testcase) : Boolean {
    var async_testcase : CompletableFuture<vx_test.Type_testcase> = vx_test.f_resolve_testcase(testcase)
    var testcase_resolved : vx_test.Type_testcase = vx_core.vx_sync_from_async(vx_test.t_testcase, async_testcase)
    var output : Boolean = run_testcase(testcase_resolved)
    return output
  }

  fun run_testcaselist(testcaselist : vx_test.Type_testcaselist) : Boolean {
    var listtestcase : List<vx_test.Type_testcase> = testcaselist.vx_listtestcase()
    for (testcase : vx_test.Type_testcase in listtestcase) {
      run_testcase(testcase)
    }
    var output : Boolean = true
    return output
  }

  fun run_testdescribe(testpkg : String, casename : String, describe : vx_test.Type_testdescribe) : Boolean {
    var testcode : vx_core.Type_string = describe.describename()
    var message : String = testcode.vx_string()
    var testresult : vx_test.Type_testresult = describe.testresult()
    var output : Boolean = run_testresult(testpkg, casename, message, testresult)
    return output
  }

  fun run_testdescribelist(testpkg : String, casename : String, testdescribelist : vx_test.Type_testdescribelist) : Boolean {
    var output : Boolean = true
    var listtestdescribe : List<vx_test.Type_testdescribe> = testdescribelist.vx_listtestdescribe()
    for (testdescribe : vx_test.Type_testdescribe in listtestdescribe) {
      var testoutput : Boolean = run_testdescribe(testpkg, casename, testdescribe)
 	    if (!testoutput) {
   			  output = false
      }
    }
    return output
  }

  fun run_testpackage(testpackage : vx_test.Type_testpackage) : Boolean {
    var testcaselist : vx_test.Type_testcaselist = testpackage.caselist()
    var output : Boolean = run_testcaselist(testcaselist)
    return output
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  fun run_testpackage_async(testpackage : vx_test.Type_testpackage) : Boolean {
    var async_testpackage : CompletableFuture<vx_test.Type_testpackage> = vx_test.f_resolve_testpackage(testpackage)
    var testpackage_resolved : vx_test.Type_testpackage = vx_core.vx_sync_from_async(vx_test.t_testpackage, async_testpackage)
    var output : Boolean = run_testpackage(testpackage_resolved)
    return output
  }

  fun run_testresult(testpkg : String, testname : String, message : String, testresult : vx_test.Type_testresult) : Boolean {
    var valexpected : vx_core.Type_any = testresult.expected()
    var valactual : vx_core.Type_any = testresult.actual()
    var passfail : Boolean = testresult.passfail().vx_boolean()
    var code : String = testresult.code().vx_string()
    var expected : String = vx_core.f_string_from_any(valexpected).vx_string()
    var actual : String = vx_core.f_string_from_any(valactual).vx_string()
    var msg : String = testpkg + "/" + testname + " " + message
  		if (!passfail) {
  				println(msg)
  				println(expected)
  				println(actual)
      vx_core.f_log(testresult)
		  }
    if ((code==":ne")) {
	  			assertNotEquals(expected, actual, msg)
    } else {
  				assertEquals(expected, actual, msg)
    }
    val output : Boolean = true
    return output
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  fun write_testpackagelist_async(context : vx_core.Type_context, testpackagelist : vx_test.Type_testpackagelist) : Boolean {
    var output : Boolean = false
    var async_testpackagelist : CompletableFuture<vx_test.Type_testpackagelist> = vx_test.f_resolve_testpackagelist(testpackagelist)
    var testpackagelist_resolved : vx_test.Type_testpackagelist = vx_core.vx_sync_from_async(vx_test.t_testpackagelist, async_testpackagelist)
    var filetest : vx_data_file.Type_file = file_test(vx_test.f_file_test())
    var valboolean : vx_core.Type_boolean = vx_data_file.f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved)
    output = valboolean.vx_boolean()
    var divtest : vx_web_html.Type_div = vx_test.f_div_from_testpackagelist(testpackagelist_resolved)
    var htmlnode : vx_web_html.Type_html = vx_test.f_html_from_divtest(divtest)
    var filenode : vx_data_file.Type_file = file_test(vx_test.f_file_testnode())
    valboolean = vx_data_file.f_boolean_write_from_file_any(context, filenode, htmlnode)
    output = output && valboolean.vx_boolean()
    var filehtml : vx_data_file.Type_file = file_test(vx_test.f_file_testhtml())
    var shtml : vx_core.Type_string = vx_web_html.f_string_from_html(htmlnode)
    valboolean = vx_data_file.f_boolean_write_from_file_string(context, filehtml, shtml)
    output = output && valboolean.vx_boolean()
    return output
  }

}
