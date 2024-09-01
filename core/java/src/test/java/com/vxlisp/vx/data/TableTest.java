
package com.vxlisp.vx.data;

import com.vxlisp.vx.*;

public final class TableTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    Test.Type_testcaselist output = Test.e_testcaselist;
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/data/table", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/data/table",
      ":typemap", Core.vx_new(
        Core.t_intmap,
        ":cell", 0,
        ":celllist", 0,
        ":cellmap", 0,
        ":field", 0,
        ":fieldlist", 0,
        ":fieldmap", 0,
        ":filter", 0,
        ":row", 0,
        ":rowlist", 0,
        ":rowmap", 0,
        ":sort", 0,
        ":table", 0
      ), 
      ":constmap", Core.e_intmap, 
      ":funcmap", Core.e_intmap
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/data/table", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
