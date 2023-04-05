
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;


public final class TableTest {

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/data/table", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 12), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 12), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 12)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/data/table",
      ":typemap", Core.t_intmap.vx_new(
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
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
  
      )
    );
  }

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/data/table", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
