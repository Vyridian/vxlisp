
package com.vxlisp.vx.data;

import java.util.List;
import com.vxlisp.vx.*;

public final class FileTest {

  static Test.Type_testcase f_boolean_exists_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-exists<-file",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"boolean_exists_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_exists_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("boolean_exists_from_file.txt"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources/vx")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_boolean_write_from_file_string(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-write<-file-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-write<-file-string\n  (file\n   :name \"boolean_write_from_file_string.txt\"\n   :path \"src/test/resources/vx\")\n  \"writetext\"))",
          ":testresult",
            Test.f_test_true(
              context,
              File.f_boolean_write_from_file_string(
                context,
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("boolean_write_from_file_string.txt"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources/vx")
                  )
                ),
                Core.vx_new_string("writetext")
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_file_read_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "file-read<-file",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (file\n  :name \"string_read_from_file.txt\"\n  :path \"src/test/resources/vx\"\n  :text \"testdata\")\n (file-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                File.t_file,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":name"),
                  Core.vx_new_string("string_read_from_file.txt"),
                  Core.vx_new_string(":path"),
                  Core.vx_new_string("src/test/resources/vx"),
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("testdata")
                )
              ),
              File.f_file_read_from_file(
                context,
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("string_read_from_file.txt"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources/vx")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_pathfull_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "pathfull<-file",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"fname\"\n (pathfull<-file\n  (file\n   :name \"fname\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("fname"),
              File.f_pathfull_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("fname")
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"fpath/fname\"\n (pathfull<-file\n  (file\n   :path \"fpath\"\n   :name \"fname\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("fpath/fname"),
              File.f_pathfull_from_file(
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("fpath"),
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("fname")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_read_from_file(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "string-read<-file",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"testdata\"\n (string-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("testdata"),
              File.f_string_read_from_file(
                context,
                Core.f_new(
                  File.t_file,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("string_read_from_file.txt"),
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("src/test/resources/vx")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = Core.arraylist_from_array(
      FileTest.f_boolean_exists_from_file(context),
      FileTest.f_boolean_write_from_file_string(context),
      FileTest.f_file_read_from_file(context),
      FileTest.f_pathfull_from_file(context),
      FileTest.f_string_read_from_file(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/data/file", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 92, ":tests", 13, ":total", 14), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 45, ":tests", 5, ":total", 11), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 35, ":tests", 5, ":total", 14), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/data/file", ":typemap", Core.vx_new(
  Core.t_intmap,
        ":file", 0,
        ":fileformat", 0,
        ":filelist", 0
), ":constmap", Core.e_intmap, ":funcmap", Core.vx_new(
  Core.t_intmap,
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
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/data/file", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
