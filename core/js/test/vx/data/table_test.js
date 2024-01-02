'strict mode'

import vx_data_table from "../../../src/vx/data/table.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"

export default class vx_data_table_test {


  static test_package(context) {
    const testcaselist = vx_data_table_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/table",
      ":caselist", testcaselist,
      ":coveragesummary", vx_data_table_test.test_coveragesummary(),
      ":coveragedetail", vx_data_table_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/data/table", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/data/table",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "cell", 0,
          "celllist", 0,
          "cellmap", 0,
          "field", 0,
          "fieldlist", 0,
          "fieldmap", 0,
          "filter", 0,
          "row", 0,
          "rowlist", 0,
          "rowmap", 0,
          "sort", 0,
          "table", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap
        )
    )
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist
    )
    return output
  }
}
