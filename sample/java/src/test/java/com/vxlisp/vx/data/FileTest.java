
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;


public final class FileTest {

  static Test.Type_testcase f_boolean_exists_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-exists<-file",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"boolean_exists_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test_true(
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("boolean_exists_from_file.txt"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources/vx")
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_boolean_write_from_file_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-write<-file-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (boolean-write<-file-string\n  (file\n   :name \"boolean_write_from_file_string.txt\"\n   :path \"src/test/resources/vx\")\n  \"writetext\"))",
          ":testresult",
            Test.f_test_true(
              File.f_boolean_write_from_file_string(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("boolean_write_from_file_string.txt"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources/vx")
                  )
                ),
                Core.t_string.vx_new_from_string("writetext"),
                context
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_file_read_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "file-read<-file",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (file\n  :name \"string_read_from_file.txt\"\n  :path \"src/test/resources/vx\"\n  :text \"testdata\")\n (file-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                File.t_file,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string(":name"),
                  Core.t_string.vx_new_from_string("string_read_from_file.txt"),
                  Core.t_string.vx_new_from_string(":path"),
                  Core.t_string.vx_new_from_string("src/test/resources/vx"),
                  Core.t_string.vx_new_from_string(":text"),
                  Core.t_string.vx_new_from_string("testdata")
                )
              ),
              File.f_file_read_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("string_read_from_file.txt"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources/vx")
                  )
                ),
                context
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_pathcurrent_from_os(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "pathcurrent<-os",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-endswith (pathcurrent<-os) \"\\java\"))",
          ":testresult",
            Test.f_test_true(
              Core.f_is_endswith(
                File.f_pathcurrent_from_os(),
                Core.t_string.vx_new_from_string("\\java")
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_read_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "string-read<-file",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"testdata\"\n (string-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("testdata"),
              File.f_string_read_from_file(
                Core.f_new(
                  File.t_file,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("string_read_from_file.txt"),
                    Core.t_string.vx_new_from_string(":path"),
                    Core.t_string.vx_new_from_string("src/test/resources/vx")
                  )
                ),
                context
              ),
              context
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      FileTest.f_boolean_exists_from_file(context),
      FileTest.f_boolean_write_from_file_string(context),
      FileTest.f_file_read_from_file(context),
      FileTest.f_pathcurrent_from_os(context),
      FileTest.f_string_read_from_file(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/data/file", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 90, ":tests", 10, ":total", 11), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 55, ":tests", 5, ":total", 9), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 9), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 9), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 45, ":tests", 5, ":total", 11), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/data/file",
      ":typemap", Core.t_intmap.vx_new(
        ":file", 0,
        ":fileformat", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":boolean-exists<-file", 1,
        ":boolean-write<-file-any", 0,
        ":boolean-write<-file-string", 1,
        ":file-read<-file", 1,
        ":name<-file", 0,
        ":path<-file", 0,
        ":pathcurrent<-os", 1,
        ":pathfull<-file", 0,
        ":string-read<-file", 1
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/data/file", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
