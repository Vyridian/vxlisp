
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;

public final class TestTest {

  static Test.Type_testcase f_file_test(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-test",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuite.vxlisp"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_file_testhtml(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testhtml",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuite.html"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_file_testnode(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testnode",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("testsuitenode.vxlisp"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources")
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
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      TestTest.f_file_test(context),
      TestTest.f_file_testhtml(context),
      TestTest.f_file_testnode(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/test", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 93, ":tests", 43, ":total", 46), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 10, ":tests", 3, ":total", 28), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 34), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 34), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 7, ":tests", 3, ":total", 40), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/test",
      ":typemap", Core.t_intmap.vx_new(
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
      ":constmap", Core.t_intmap.vx_new(
        ":stylesheet-test", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
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
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/test", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
