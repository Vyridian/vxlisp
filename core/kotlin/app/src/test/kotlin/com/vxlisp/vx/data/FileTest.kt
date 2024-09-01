
package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_fileTest {

  fun f_boolean_exists_from_file(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-exists<-file",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"boolean_exists_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_data_file.f_boolean_exists_from_file(
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("boolean_exists_from_file.txt"),
                    vx_core.vx_new_string(":path"),
                    vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.c_path_test_resources,
                        vx_core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    )
    return output
  }

  fun f_boolean_write_from_file_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-write<-file-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (boolean-write<-file-string\n  (file\n   :name \"boolean_write_from_file_string.txt\"\n   :path (string path-test-resources \"/vx\"))\n  \"writetext\"))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_data_file.f_boolean_write_from_file_string(
                context,
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("boolean_write_from_file_string.txt"),
                    vx_core.vx_new_string(":path"),
                    vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.c_path_test_resources,
                        vx_core.vx_new_string("/vx")
                      )
                    )
                  )
                ),
                vx_core.vx_new_string("writetext")
              )
            )
        )
      )
    )
    return output
  }

  fun f_file_read_from_file(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "file-read<-file",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n (file\n  :name \"string_read_from_file.txt\"\n  :path (string path-test-resources \"/vx\")\n  :text \"testdata\")\n (file-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_data_file.t_file,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":name"),
                  vx_core.vx_new_string("string_read_from_file.txt"),
                  vx_core.vx_new_string(":path"),
                  vx_core.f_new(
                    vx_core.t_string,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.c_path_test_resources,
                      vx_core.vx_new_string("/vx")
                    )
                  ),
                  vx_core.vx_new_string(":text"),
                  vx_core.vx_new_string("testdata")
                )
              ),
              vx_data_file.f_file_read_from_file(
                context,
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("string_read_from_file.txt"),
                    vx_core.vx_new_string(":path"),
                    vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.c_path_test_resources,
                        vx_core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    )
    return output
  }

  fun f_pathfull_from_file(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "pathfull<-file",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"fname\"\n (pathfull<-file\n  (file\n   :name \"fname\")))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("fname"),
              vx_data_file.f_pathfull_from_file(
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("fname")
                  )
                )
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"fpath/fname\"\n (pathfull<-file\n  (file\n   :path \"fpath\"\n   :name \"fname\")))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("fpath/fname"),
              vx_data_file.f_pathfull_from_file(
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":path"),
                    vx_core.vx_new_string("fpath"),
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("fname")
                  )
                )
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_read_from_file(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "string-read<-file",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"testdata\"\n (string-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("testdata"),
              vx_data_file.f_string_read_from_file(
                context,
                vx_core.f_new(
                  vx_data_file.t_file,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("string_read_from_file.txt"),
                    vx_core.vx_new_string(":path"),
                    vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.c_path_test_resources,
                        vx_core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_data_fileTest.f_boolean_exists_from_file(context),
      vx_data_fileTest.f_boolean_write_from_file_string(context),
      vx_data_fileTest.f_file_read_from_file(context),
      vx_data_fileTest.f_pathfull_from_file(context),
      vx_data_fileTest.f_string_read_from_file(context)
    )
    var output : vx_test.Type_testcaselist = vx_core.vx_new(
      vx_test.t_testcaselist,
      testcases
    )
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/data/file", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 92, ":tests", 13, ":total", 14), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 45, ":tests", 5, ":total", 11), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 35, ":tests", 5, ":total", 14), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/data/file",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":file", 0,
        ":fileformat", 0,
        ":filelist", 0
      ), 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":boolean-exists<-file", 1,
        ":boolean-write<-file", 0,
        ":boolean-write<-file-any", 0,
        ":boolean-write<-file-string", 1,
        ":file-read<-file", 1,
        ":file<-path", 0,
        ":name<-file", 0,
        ":path<-file", 0,
        ":pathcurrent<-os", 0,
        ":pathfull<-file", 2,
        ":string-read<-file", 1
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/file", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
