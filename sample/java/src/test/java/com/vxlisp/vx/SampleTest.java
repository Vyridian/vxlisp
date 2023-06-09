
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public final class SampleTest {

  static Test.Type_testcase c_myconst(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test 4 myconst)",
          ":testresult",
            Test.f_test(
              Core.t_int.vx_new_from_int(4),
              Sample.c_myconst,
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_myfunc(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test 5 (myfunc 1))",
          ":testresult",
            Test.f_test(
              Core.t_int.vx_new_from_int(5),
              Sample.f_myfunc(Core.t_int.vx_new_from_int(1)),
              context
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      SampleTest.c_myconst(context),
      SampleTest.f_myfunc(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/sample", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 1, ":total", 1), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 2, ":total", 4), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 1, ":total", 2), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 2, ":total", 4), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/sample",
      ":typemap", Core.t_intmap.vx_new(
        ":mytype", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":myconst", 1
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":main", 0,
        ":myfunc", 1
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/sample", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
