
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.data.*;


public final class ReplTest {

  static Test.Type_testcase f_any_from_repl(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("HelloWorld"),
              Repl.f_any_from_repl(
                Core.f_new(
                  Repl.t_repl,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":type"),
                    Core.t_string,
                    Core.t_string.vx_new_from_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string(":val"),
                            Core.t_string.vx_new_from_string("Hello")
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string(":val"),
                            Core.t_string.vx_new_from_string("World")
                          )
                        )
                      )
                    )
                  )
                ),
                context
              ),
              context
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))",
          ":testresult",
            Test.f_test(
              Core.t_int.vx_new_from_int(5),
              Repl.f_any_from_repl(
                Core.f_new(
                  Repl.t_repl,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":type"),
                    Core.t_plus,
                    Core.t_string.vx_new_from_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string(":val"),
                            Core.t_int.vx_new_from_int(2)
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string(":val"),
                            Core.t_int.vx_new_from_int(3)
                          )
                        )
                      )
                    )
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
      ReplTest.f_any_from_repl(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/repl", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 10, ":total", 10), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 14, ":tests", 1, ":total", 7), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 10, ":tests", 1, ":total", 10), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/repl",
      ":typemap", Core.t_intmap.vx_new(
        ":liblist", 0,
        ":repl", 0,
        ":repllist", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":any-repl<-functype-args", 0,
        ":any<-liblist-string", 0,
        ":any<-liblist-string-async", 0,
        ":any<-repl", 2,
        ":any<-repl-async", 0,
        ":anylist<-repllist", 0,
        ":repl<-liblist-string", 0
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/repl", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
