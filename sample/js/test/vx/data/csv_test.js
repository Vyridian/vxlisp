'strict mode'

import vx_data_csv from "../../../src/vx/data/csv.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_collection from "../../../src/vx/collection.js"
import vx_type from "../../../src/vx/type.js"
import vx_data_textblock from "../../../src/vx/data/textblock.js"

export default class vx_data_csv_test {

  static test_package(context) {
    const testcaselist = vx_data_csv_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/csv",
      ":caselist", testcaselist,
      ":coveragesummary", vx_data_csv_test.test_coveragesummary(),
      ":coveragedetail", vx_data_csv_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/data/csv", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 5), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 5), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/data/csv",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "csv", 0,
          "csvrows", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "delims", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "csv<-textblock", 0,
          "csvrows<-textblock", 0
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
