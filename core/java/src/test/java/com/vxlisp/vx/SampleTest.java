
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public final class SampleTest {

  static com.vxlisp.vx.Test.Type_testcase c_myconst(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
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

  static com.vxlisp.vx.Test.Type_testcase f_myfunc(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
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

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      Samplecom.vxlisp.vx.Test.c_myconst(context),
      Samplecom.vxlisp.vx.Test.f_myfunc(context)
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/sample", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 1, ":total", 1), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 2, ":total", 4), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 1, ":total", 2), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 2, ":total", 4), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
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

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/sample", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
