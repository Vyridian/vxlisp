'strict mode'

import vx_data_file from "../../../src/vx/data/file.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_data_textblock from "../../../src/vx/data/textblock.js"
import vx_type from "../../../src/vx/type.js"

export default class vx_data_file_test {


  static test_package(context) {
    const testcaselist = vx_data_file_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/file",
      ":caselist", testcaselist,
      ":coveragesummary", vx_data_file_test.test_coveragesummary(),
      ":coveragedetail", vx_data_file_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/data/file", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 85, ":tests", 6, ":total", 7), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 25, ":tests", 1, ":total", 4), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/data/file",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "file", 0,
          "fileformat", 0,
          "filelist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "file<-path", 0,
          "name<-file", 0,
          "path<-file", 0,
          "pathfull<-file", 2
        )
    )
  }

  static f_pathfull_from_file(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "pathfull<-file",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"fname\"\n (pathfull<-file\n  (file\n   :name \"fname\")))",
            ":testresult",
            vx_test.f_test(
              context,
              "fname",
              vx_data_file.f_pathfull_from_file(
                vx_core.f_new(
                  vx_data_file.t_file,
                  ":name",
                  "fname"
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"fpath/fname\"\n (pathfull<-file\n  (file\n   :path \"fpath\"\n   :name \"fname\")))",
            ":testresult",
            vx_test.f_test(
              context,
              "fpath/fname",
              vx_data_file.f_pathfull_from_file(
                vx_core.f_new(
                  vx_data_file.t_file,
                  ":path",
                  "fpath",
                  ":name",
                  "fname"
                )
              )
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_data_file_test.f_pathfull_from_file(context)
    )
    return output
  }
}
