
package com.vxlisp.vx;

import java.util.List;

public final class SampleTest {

  public static Test.Type_testcase c_myconst(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n myconst\n myconst)",
          ":testresult",
            Test.f_test(
              context,
              Sample.c_myconst,
              Sample.c_myconst
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_myfunc(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test 5 (myfunc 1))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Sample.f_myfunc(
                Core.vx_new_int(1)
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> testcases = Core.arraylist_from_array(
      SampleTest.c_myconst(context),
      SampleTest.f_myfunc(context)
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
      ":testpkg", "vx/sample", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 1, ":total", 1), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/sample", ":typemap", Core.vx_new(
  Core.t_intmap,
        ":mytype", 0
), ":constmap", Core.vx_new(
  Core.t_intmap,
        ":myconst", 1
), ":funcmap", Core.vx_new(
  Core.t_intmap,
        ":main", 0,
        ":myfunc", 1
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/sample", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
