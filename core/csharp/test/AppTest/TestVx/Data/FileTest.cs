
namespace AppTest.TestVx.Data;

public class FileTest {

  public static Vx.Test.Type_testcase f_boolean_exists_from_file(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-exists<-file",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"boolean_exists_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Data.File.f_boolean_exists_from_file(
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("boolean_exists_from_file.txt"),
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.f_new(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.c_path_test_resources,
                        Vx.Core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_boolean_write_from_file_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "boolean-write<-file-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (boolean-write<-file-string\n  (file\n   :name \"boolean_write_from_file_string.txt\"\n   :path (string path-test-resources \"/vx\"))\n  \"writetext\"))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Data.File.f_boolean_write_from_file_string(
                context,
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("boolean_write_from_file_string.txt"),
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.f_new(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.c_path_test_resources,
                        Vx.Core.vx_new_string("/vx")
                      )
                    )
                  )
                ),
                Vx.Core.vx_new_string("writetext")
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_file_read_from_file(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "file-read<-file",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (file\n  :name \"string_read_from_file.txt\"\n  :path (string path-test-resources \"/vx\")\n  :text \"testdata\")\n (file-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Data.File.t_file,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":name"),
                  Vx.Core.vx_new_string("string_read_from_file.txt"),
                  Vx.Core.vx_new_string(":path"),
                  Vx.Core.f_new(
                    Vx.Core.t_string,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.c_path_test_resources,
                      Vx.Core.vx_new_string("/vx")
                    )
                  ),
                  Vx.Core.vx_new_string(":text"),
                  Vx.Core.vx_new_string("testdata")
                )
              ),
              Vx.Data.File.f_file_read_from_file(
                context,
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("string_read_from_file.txt"),
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.f_new(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.c_path_test_resources,
                        Vx.Core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_pathfull_from_file(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "pathfull<-file",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"fname\"\n (pathfull<-file\n  (file\n   :name \"fname\")))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("fname"),
              Vx.Data.File.f_pathfull_from_file(
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("fname")
                  )
                )
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"fpath/fname\"\n (pathfull<-file\n  (file\n   :path \"fpath\"\n   :name \"fname\")))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("fpath/fname"),
              Vx.Data.File.f_pathfull_from_file(
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.vx_new_string("fpath"),
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("fname")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_read_from_file(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/file",
      ":casename", "string-read<-file",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"testdata\"\n (string-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path (string path-test-resources \"/vx\"))))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("testdata"),
              Vx.Data.File.f_string_read_from_file(
                context,
                Vx.Core.f_new(
                  Vx.Data.File.t_file,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("string_read_from_file.txt"),
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.f_new(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.c_path_test_resources,
                        Vx.Core.vx_new_string("/vx")
                      )
                    )
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      FileTest.f_boolean_exists_from_file(context),
      FileTest.f_boolean_write_from_file_string(context),
      FileTest.f_file_read_from_file(context),
      FileTest.f_pathfull_from_file(context),
      FileTest.f_string_read_from_file(context)
    ];
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/data/file", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 92, ":tests", 13, ":total", 14), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 45, ":tests", 5, ":total", 11), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 35, ":tests", 5, ":total", 14), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Vx.Test.t_testcoveragedetail, ":testpkg", "vx/data/file", ":typemap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":file", 0,
        ":fileformat", 0,
        ":filelist", 0
), ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
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

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/data/file", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
