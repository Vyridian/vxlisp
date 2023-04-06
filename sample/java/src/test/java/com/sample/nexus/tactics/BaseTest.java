
package com.sample.nexus.tactics;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.sample.vx.*;
import com.sample.vx.web.*;
import com.sample.vx.data.*;


public final class BaseTest {

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "nexus/tactics/base", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 6), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 39), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 39), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 33)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
      ":testpkg", "nexus/tactics/base",
      ":typemap", Core.t_intmap.vx_new(
        ":ability", 0,
        ":abilitylist", 0,
        ":book", 0,
        ":booklist", 0,
        ":card", 0,
        ":cardlist", 0,
        ":chapter", 0,
        ":chapterlist", 0,
        ":deck", 0,
        ":decklist", 0,
        ":item", 0,
        ":itemlist", 0,
        ":location", 0,
        ":locationlist", 0,
        ":playingcard", 0,
        ":power", 0,
        ":powerlist", 0,
        ":rank", 0,
        ":rating", 0,
        ":rule", 0,
        ":rulelist", 0,
        ":scenario", 0,
        ":scenariolist", 0,
        ":section", 0,
        ":sectionlist", 0,
        ":skill", 0,
        ":skilllist", 0,
        ":specialty", 0,
        ":specialtylist", 0,
        ":suit", 0,
        ":suitlist", 0,
        ":unit", 0,
        ":unitlist", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":card-ace-spade", 0,
        ":rank-ace", 0,
        ":suit-club", 0,
        ":suit-diamond", 0,
        ":suit-heart", 0,
        ":suit-spade", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
  
      )
    );
  }

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "nexus/tactics/base", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
