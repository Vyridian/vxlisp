
using Xunit;

namespace AppTest;

public static class TestLib {


  public class TestOutputWriter : TextWriter {

    private readonly Xunit.Abstractions.ITestOutputHelper _output;

    public TestOutputWriter(Xunit.Abstractions.ITestOutputHelper output) {
      _output = output;
    }

    public override System.Text.Encoding Encoding => System.Text.Encoding.UTF8;

			 public override void WriteLine(int message) {
				  _output.WriteLine("" + message);
  		}

  		public override void WriteLine(string? message) {
  				_output.WriteLine(message);
  		}

  }

  public static bool EnableConsole(Xunit.Abstractions.ITestOutputHelper output) {
    TestOutputWriter converter = new TestOutputWriter(output);
    System.Console.SetOut(converter);
    return true;
  }

  public static bool run_testcase(Vx.Test.Type_testcase testcase) {
    string testpkg = testcase.testpkg().vx_string();
    string casename = testcase.casename().vx_string();
    Vx.Test.Type_testdescribelist testdescribelist = testcase.describelist();
    bool output = run_testdescribelist(testpkg, casename, testdescribelist);
    return output;
  }

  public static bool run_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
    List<Vx.Test.Type_testcase> listtestcase = testcaselist.vx_listtestcase();
    foreach (Vx.Test.Type_testcase testcase in listtestcase) {
      run_testcase(testcase);
    }
    return true;
  }

  public static bool run_testdescribe(string testpkg, string casename, Vx.Test.Type_testdescribe describe) {
    Vx.Core.Type_string testcode = describe.describename();
    string message = testcode.vx_string();
    Vx.Test.Type_testresult testresult = describe.testresult();
    bool output = run_testresult(testpkg, casename, message, testresult);
    return output;
  }

  public static bool run_testdescribelist(string testpkg, string casename, Vx.Test.Type_testdescribelist testdescribelist) {
    bool output = true;
    List<Vx.Test.Type_testdescribe> listtestdescribe = testdescribelist.vx_listtestdescribe();
    foreach (Vx.Test.Type_testdescribe testdescribe in listtestdescribe) {
      bool testoutput = run_testdescribe(testpkg, casename, testdescribe);
 	    if (!testoutput) {
   			  output = false;
      }
    }
    return output;
  }

  public static bool run_testpackage(Vx.Test.Type_testpackage testpackage) {
    Vx.Test.Type_testcaselist testcaselist = testpackage.caselist();
    bool output = run_testcaselist(testcaselist);
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  public static bool run_testpackage_async(Vx.Test.Type_testpackage testpackage) {
    Task<Vx.Test.Type_testpackage> async_testpackage = Vx.Test.f_resolve_testpackage(testpackage);
    Vx.Test.Type_testpackage testpackage_resolved = Vx.Core.vx_sync_from_async(Vx.Test.t_testpackage, async_testpackage);
    bool output = run_testpackage(testpackage_resolved);
    return output;
  }

  public static bool run_testresult(string testpkg, string testname, string message, Vx.Test.Type_testresult testresult) {
    Vx.Core.Type_any valexpected = testresult.expected();
    Vx.Core.Type_any valactual = testresult.actual();
    bool passfail = testresult.passfail().vx_boolean();
    string code = testresult.code().vx_string();
    string expected = Vx.Core.f_string_from_any(valexpected).vx_string();
    string actual = Vx.Core.f_string_from_any(valactual).vx_string();
    string msg = testpkg + "/" + testname + " " + message;
  		if (!passfail) {
  				System.Console.WriteLine(msg);
  				System.Console.WriteLine(expected);
  				System.Console.WriteLine(actual);
      Vx.Core.f_log(testresult);
		  }
  		switch (code) {
		  case ":ne":
	  			Assert.NotEqual(expected, actual);
  				break;
  		default:
  				Assert.Equal(expected, actual);
  				break;
  		}
  		return true;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  public static bool write_testpackagelist_async(Vx.Core.Type_context context, Vx.Test.Type_testpackagelist testpackagelist) {
    bool output = false;
    Task<Vx.Test.Type_testpackagelist> async_testpackagelist = Vx.Test.f_resolve_testpackagelist(testpackagelist);
    Vx.Test.Type_testpackagelist testpackagelist_resolved = Vx.Core.vx_sync_from_async(Vx.Test.t_testpackagelist, async_testpackagelist);
    Vx.Data.File.Type_file filetest = Vx.Test.f_file_test();
    Vx.Core.Type_boolean valboolean = Vx.Data.File.f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved);
    output = valboolean.vx_boolean();
    Vx.Web.Html.Type_div divtest = Vx.Test.f_div_from_testpackagelist(testpackagelist_resolved);
    Vx.Web.Html.Type_html htmlnode = Vx.Test.f_html_from_divtest(divtest);
    Vx.Data.File.Type_file filenode = Vx.Test.f_file_testnode();
    valboolean = Vx.Data.File.f_boolean_write_from_file_any(context, filenode, htmlnode);
    output = output && valboolean.vx_boolean();
    Vx.Data.File.Type_file filehtml = Vx.Test.f_file_testhtml();
    Vx.Core.Type_string shtml = Vx.Web.Html.f_string_from_html(htmlnode);
    valboolean = Vx.Data.File.f_boolean_write_from_file_string(context, filehtml, shtml);
    output = output && valboolean.vx_boolean();
			 return output;
  }

}
