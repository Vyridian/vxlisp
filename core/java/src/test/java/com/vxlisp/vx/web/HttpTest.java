
package com.vxlisp.vx.web;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;


public final class HttpTest {

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/web/http", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 88, ":tests", 8, ":total", 9), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 8), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 8), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 8), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 9), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/web/http",
      ":typemap", Core.t_intmap.vx_new(
        ":response", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":csv<-httpget", 0,
        ":json<-httpget", 0,
        ":response<-httpget", 0,
        ":text<-httpget", 0,
        ":text<-response", 0,
        ":textblock<-httpget", 0,
        ":textblock<-response", 0,
        ":xml<-httpget", 0
      )
    );
  }

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/web/http", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
