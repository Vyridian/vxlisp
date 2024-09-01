
package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_dbTest {

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var output : vx_test.Type_testcaselist = vx_test.e_testcaselist
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/data/db", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 12, ":total", 12), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/data/db",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":db", 0,
        ":dbcell", 0,
        ":dbcellmap", 0,
        ":dbfield", 0,
        ":dbfieldmap", 0,
        ":dbid", 0,
        ":dblink", 0,
        ":dblinklist", 0,
        ":dbnode", 0,
        ":dbnote", 0,
        ":dbtable", 0,
        ":dbvalue", 0
      ), 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.e_intmap
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/db", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
