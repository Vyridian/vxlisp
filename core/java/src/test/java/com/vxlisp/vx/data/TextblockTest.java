
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;


public final class TextblockTest {

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/data/textblock", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 42, ":tests", 3, ":total", 7), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 4), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 4), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 4), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/data/textblock",
      ":typemap", Core.t_intmap.vx_new(
        ":delimset", 0,
        ":textblock", 0,
        ":textblocklist", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":parse", 0,
        ":stringlist<-textblocklist", 0,
        ":text<-textblock", 0,
        ":textblocks<-textblock", 0
      )
    );
  }

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/data/textblock", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
