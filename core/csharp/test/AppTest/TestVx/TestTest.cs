
namespace AppTest.TestVx;

public class TestTest {

  public static Vx.Test.Type_testcase f_file_test(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-test",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_file_test_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_file_test_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path path-test-resources)))",
      ":testresult", Vx.Test.f_test_true(
        context,
        Vx.Data.File.f_boolean_exists_from_file(
          Vx.Core.f_new(
            Vx.Data.File.t_file,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":name"),
              Vx.Core.vx_new_string("testsuite.vxlisp"),
              Vx.Core.vx_new_string(":path"),
              Vx.Core.c_path_test_resources
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_file_testhtml(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testhtml",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_file_testhtml_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_file_testhtml_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path path-test-resources)))",
      ":testresult", Vx.Test.f_test_true(
        context,
        Vx.Data.File.f_boolean_exists_from_file(
          Vx.Core.f_new(
            Vx.Data.File.t_file,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":name"),
              Vx.Core.vx_new_string("testsuite.html"),
              Vx.Core.vx_new_string(":path"),
              Vx.Core.c_path_test_resources
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_file_testnode(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testnode",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_file_testnode_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_file_testnode_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path path-test-resources)))",
      ":testresult", Vx.Test.f_test_true(
        context,
        Vx.Data.File.f_boolean_exists_from_file(
          Vx.Core.f_new(
            Vx.Data.File.t_file,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":name"),
              Vx.Core.vx_new_string("testsuitenode.vxlisp"),
              Vx.Core.vx_new_string(":path"),
              Vx.Core.c_path_test_resources
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      TestTest.f_file_test(context),
      TestTest.f_file_testhtml(context),
      TestTest.f_file_testnode(context)
    ];
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/test", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 93, ":tests", 43, ":total", 46), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 10, ":tests", 3, ":total", 28), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 7, ":tests", 3, ":total", 40), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/test",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":testcase", 0,
        ":testcaselist", 0,
        ":testcoveragedetail", 0,
        ":testcoveragenums", 0,
        ":testcoveragesummary", 0,
        ":testdescribe", 0,
        ":testdescribelist", 0,
        ":testpackage", 0,
        ":testpackagelist", 0,
        ":testresult", 0,
        ":testresultlist", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":stylesheet-test", 0
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":context-test", 0,
        ":div<-testcaselist", 0,
        ":div<-testpackage", 0,
        ":div<-testpackagelist", 0,
        ":divchildlist<-testpackagelist", 0,
        ":file-test", 1,
        ":file-testhtml", 1,
        ":file-testnode", 1,
        ":html<-divtest", 0,
        ":p<-passfail", 0,
        ":p<-testcoveragenums", 0,
        ":resolve-testcase", 0,
        ":resolve-testcaselist", 0,
        ":resolve-testdescribe", 0,
        ":resolve-testdescribelist", 0,
        ":resolve-testpackage", 0,
        ":resolve-testpackagelist", 0,
        ":resolve-testresult", 0,
        ":security-test", 0,
        ":test", 0,
        ":test_1", 0,
        ":test-false", 0,
        ":test-false_1", 0,
        ":test-gt", 0,
        ":test-gt_1", 0,
        ":test-ne", 0,
        ":test-ne_1", 0,
        ":test-string", 0,
        ":test-string_1", 0,
        ":test-true", 0,
        ":test-true_1", 0,
        ":tr<-testdescribe-casename", 0,
        ":trlist<-testcase", 0,
        ":trlist<-testcaselist", 0
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/test", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
