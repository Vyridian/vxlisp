
package com.vxlisp.vx;

import java.util.List;
import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;

public final class TestTest {

  public static Test.Type_testcase f_file_test(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-test",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path path-test-resources)))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuite.vxlisp"),
                    Core.vx_new_string(":path"),
                    Core.c_path_test_resources
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_file_testhtml(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testhtml",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path path-test-resources)))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuite.html"),
                    Core.vx_new_string(":path"),
                    Core.c_path_test_resources
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_file_testnode(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testnode",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path path-test-resources)))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuitenode.vxlisp"),
                    Core.vx_new_string(":path"),
                    Core.c_path_test_resources
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> testcases = Core.arraylist_from_array(
      TestTest.f_file_test(context),
      TestTest.f_file_testhtml(context),
      TestTest.f_file_testnode(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/test", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 93, ":tests", 43, ":total", 46), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 10, ":tests", 3, ":total", 28), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 7, ":tests", 3, ":total", 40), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/test", ":typemap", Core.vx_new(
  Core.t_intmap,
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
), ":constmap", Core.vx_new(
  Core.t_intmap,
        ":stylesheet-test", 0
), ":funcmap", Core.vx_new(
  Core.t_intmap,
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
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/test", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
