
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;


public final class TestTest {

  static com.vxlisp.vx.Test.Type_testcase f_file_test(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-test",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("testsuite.vxlisp"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources")
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_file_testhtml(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testhtml",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("testsuite.html"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources")
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_file_testnode(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testnode",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path \"src/test/resources\")))",
          ":testresult",
            Test.f_test_true(
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("testsuitenode.vxlisp"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources")
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      Testcom.vxlisp.vx.Test.f_file_test(context),
      Testcom.vxlisp.vx.Test.f_file_testhtml(context),
      Testcom.vxlisp.vx.Test.f_file_testnode(context)
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/test", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 93, ":tests", 41, ":total", 44), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 11, ":tests", 3, ":total", 26), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 32), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 32), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 7, ":tests", 3, ":total", 38), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
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

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/test", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
