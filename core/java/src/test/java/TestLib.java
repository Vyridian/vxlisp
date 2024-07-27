
import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;

public final class TestLib {


  public static String spath = Core.c_path_test_resources.vx_string();

  public static File.Type_file file_test(final File.Type_file file) {
    File.Type_file output = Core.vx_copy(
      file,
      Core.vx_new_string(":path"), spath);
			 return output;
  }

  public static String read_test_file(final String path, final String filename) {
    File.Type_file file = Core.vx_new(
      File.t_file,
      Core.vx_new_string(":path"), Core.vx_new_string(spath + "/vx"),
      Core.vx_new_string(":name"), Core.vx_new_string("string_read_from_file.txt"));
    Core.Type_string string_file = File.vx_string_read_from_file(file);
    String output = string_file.vx_string();
			 return output;
  }

  public static boolean test(final String testname, final String expected, final String actual) {
    assertEquals(expected, actual);
    boolean output = false;
    if (expected.equals(actual)) {
      output = true;
    } else {
      System.out.println(testname);
      System.out.println(expected);
      System.out.println(actual);
    }
    return output;
  }

  public static boolean test_helloworld() {
    String testname = "test_helloworld";
    Core.Type_string helloworld = Core.vx_new_string("Hello World");
    String expected = "Hello World";
    String actual = helloworld.vx_string();
    boolean output = TestLib.test(testname, expected, actual);
  		return output;
  }

  public static boolean test_async_new_from_value() {
    String testname = "test_async_new_from_value";
    Core.Type_string helloworld = Core.vx_new_string("Hello World");
    CompletableFuture<Core.Type_string> async = Core.vx_async_new_from_value(helloworld);
    Core.Type_string sync = Core.vx_sync_from_async(Core.t_string, async);
    String expected = "Hello World";
    String actual = sync.vx_string();
    boolean output = TestLib.test(testname, expected, actual);
  		return output;
  }

  public static boolean test_async_from_async_fn() {
    String testname = "test_async_from_async_fn";
    Core.Type_string helloworld = Core.vx_new_string("Hello World");
    CompletableFuture<Core.Type_string> async = Core.vx_async_new_from_value(helloworld);
    CompletableFuture<Core.Type_string> async1 = Core.vx_async_from_async_fn(async, (any) -> {
     	return any;
    });
    Core.Type_string sync = Core.vx_sync_from_async(Core.t_string, async1);
    String expected = "Hello World";
    String actual = sync.vx_string();
    boolean output = TestLib.test(testname, expected, actual);
  		return output;
  }

  public static boolean test_list_from_list_async() {
    String testname = "test_list_from_list_async";
    Core.Type_anylist sparams = Core.vx_anylist_from_arraystring("hello", "world");
    Core.Type_stringlist slist = Core.f_new(Core.t_stringlist, sparams);
    Core.Func_any_from_any_async fn_async = Core.t_any_from_any_async.vx_fn_new((anyval) -> {
      Core.Type_string stringval = (Core.Type_string)anyval;
      String sout = stringval.vx_string() + "!";
      Core.Type_any outval = Core.vx_new_string(sout);
      CompletableFuture<Core.Type_any> output = Core.vx_async_new_from_value(outval);
      return output;
    });
    CompletableFuture<Core.Type_stringlist> asynclist = Core.vx_list_from_list_async(Core.t_stringlist, slist, fn_async);
    Core.Type_stringlist sync = Core.vx_sync_from_async(Core.t_stringlist, asynclist);
    String expected = "(stringlist\n \"hello!\"\n \"world!\")";
    String actual = Core.vx_string_from_any(sync);
    boolean output = TestLib.test(testname, expected, actual);
  		return output;
  }

  public static boolean test_pathfull_from_file() {
    String testname = "test_pathfull_from_file";
    File.Type_file file = Core.vx_new(
      File.t_file,
      Core.vx_new_string(":path"), Core.vx_new_string(spath + "/vx"),
      Core.vx_new_string(":name"), Core.vx_new_string("string_read_from_file.txt"));
    Core.Type_string string_path = File.f_pathfull_from_file(file);
    String expected = spath + "/vx/string_read_from_file.txt";
    String actual = string_path.vx_string();
    boolean output = TestLib.test(testname, expected, actual);
			 return output;
  }

  public static boolean test_read_file() {
    String testname = "test_read_file";
    String expected = "testdata";
    String actual = read_test_file(spath + "/vx", "string_read_from_file.txt");
    boolean output = TestLib.test(testname, expected, actual);
			 return output;
  }

  public static boolean test_write_file() {
    String testname = "test_write_file";
    File.Type_file file = Core.vx_new(File.t_file, 
    Core.vx_new_string(":path"), Core.vx_new_string(spath + "/vx"),
    Core.vx_new_string(":name"), Core.vx_new_string("string_read_from_file.txt")
  );
    Core.Type_string string_path = File.f_pathfull_from_file(file);
    String expected = spath + "/vx/string_read_from_file.txt";
    String actual = string_path.vx_string();
    boolean output = TestLib.test(testname, expected, actual);
			 return output;
  }

  public static boolean run_testcase(final Test.Type_testcase testcase) {
    String testpkg = testcase.testpkg().vx_string();
    String casename = testcase.casename().vx_string();
    Test.Type_testdescribelist testdescribelist = testcase.describelist();
    Boolean output = run_testdescribelist(testpkg, casename, testdescribelist);
    return output;
  }

  // Blocking
  // Only use if running a single testcase
  public static boolean run_testcase_async(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> async_testcase = Test.f_resolve_testcase(testcase);
    Test.Type_testcase testcase_resolved = Core.vx_sync_from_async(Test.t_testcase, async_testcase);
    boolean output = run_testcase(testcase_resolved);
    return output;
  }

  public static boolean run_testcaselist(final Test.Type_testcaselist testcaselist) {
    List<Test.Type_testcase> listtestcase = testcaselist.vx_listtestcase();
    for (Test.Type_testcase testcase : listtestcase) {
      run_testcase(testcase);
    }
    return true;
  }

  public static boolean run_testdescribe(final String testpkg, final String casename, final Test.Type_testdescribe describe) {
    Core.Type_string testcode = describe.describename();
    String message = testcode.vx_string();
    Test.Type_testresult testresult = describe.testresult();
    boolean output = run_testresult(testpkg, casename, message, testresult);
    return output;
  }

  public static boolean run_testdescribelist(final String testpkg, final String casename, final Test.Type_testdescribelist testdescribelist) {
    boolean output = true;
    List<Test.Type_testdescribe> listtestdescribe = testdescribelist.vx_listtestdescribe();
    for (Test.Type_testdescribe testdescribe : listtestdescribe) {
      boolean testoutput = run_testdescribe(testpkg, casename, testdescribe);
 	    if (!testoutput) {
   			  output = false;
      }
    }
    return output;
  }

  public static boolean run_testpackage(final Test.Type_testpackage testpackage) {
    Test.Type_testcaselist testcaselist = testpackage.caselist();
    boolean output = run_testcaselist(testcaselist);
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  public static boolean run_testpackage_async(final Test.Type_testpackage testpackage) {
    CompletableFuture<Test.Type_testpackage> async_testpackage = Test.f_resolve_testpackage(testpackage);
    Test.Type_testpackage testpackage_resolved = Core.vx_sync_from_async(Test.t_testpackage, async_testpackage);
    boolean output = run_testpackage(testpackage_resolved);
    return output;
  }

  public static boolean run_testresult(final String testpkg, final String testname, final String message, final Test.Type_testresult testresult) {
    Core.Type_any valexpected = testresult.expected();
    Core.Type_any valactual = testresult.actual();
    boolean passfail = testresult.passfail().vx_boolean();
    String code = testresult.code().vx_string();
    String expected = Core.f_string_from_any(valexpected).vx_string();
    String actual = Core.f_string_from_any(valactual).vx_string();
    String msg = testpkg + "/" + testname + " " + message;
  		if (!passfail) {
  				System.out.println(msg);
  				System.out.println(expected);
  				System.out.println(actual);
      Core.f_log(testresult);
		  }
  		switch (code) {
		  case ":ne":
	  			assertNotEquals(expected, actual, msg);
  				break;
  		default:
  				assertEquals(expected, actual, msg);
  				break;
  		}
  		return true;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  public static boolean write_testpackagelist_async(final Core.Type_context context, final Test.Type_testpackagelist testpackagelist) {
    boolean output = false;
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    File.Type_file filetest = file_test(Test.f_file_test());
    Core.Type_boolean valboolean = File.f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved);
    output = valboolean.vx_boolean();
    Html.Type_div divtest = Test.f_div_from_testpackagelist(testpackagelist_resolved);
    Html.Type_html htmlnode = Test.f_html_from_divtest(divtest);
    File.Type_file filenode = file_test(Test.f_file_testnode());
    valboolean = File.f_boolean_write_from_file_any(context, filenode, htmlnode);
    output = output && valboolean.vx_boolean();
    File.Type_file filehtml = file_test(Test.f_file_testhtml());
    Core.Type_string shtml = Html.f_string_from_html(htmlnode);
    valboolean = File.f_boolean_write_from_file_string(context, filehtml, shtml);
    output = output && valboolean.vx_boolean();
			 return output;
  }


  // Blocking
  // Only use if running a single testdescribe
  public static boolean run_testdescribe_async(final String testpkg, final String casename, final Test.Type_testdescribe testdescribe) {
    CompletableFuture<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = Core.vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  public static boolean run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    boolean output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
      boolean testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static boolean run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  // Blocking
  public static boolean run_testresult_async(final String testpkg, final String testname, final String message, Test.Type_testresult testresult) {
    CompletableFuture<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = Core.vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

}
