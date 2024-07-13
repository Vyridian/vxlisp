
namespace AppTest.TestVx.Ui.Html;

public class UihtmlTest {

  public static Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    List<Vx.Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    Test.Type_testcaselist output = Vx.Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Vx.Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/ui/html/uihtml", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 66, ":tests", 30, ":total", 45), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 37), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 38), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 38), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 44), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/ui/html/uihtml", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":layout-app-html", 0,
        ":layout-else-html", 0,
        ":layout-image-html", 0,
        ":layout-label-html", 0,
        ":layoutenginehtml", 0,
        ":style-hidden", 0,
        ":style-selected", 0
), ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":boolean-layoutremove-html", 0,
        ":boolean-layoutselected-html", 0,
        ":boolean-layoutvisible-html", 0,
        ":boolean-print-html", 0,
        ":boolean-writeclass<-ui", 0,
        ":boolean-writeeventsall<-ui", 0,
        ":boolean-writeeventsall<-uimap", 0,
        ":boolean-writeselected<-ui", 0,
        ":boolean-writevisible<-ui", 0,
        ":context-write", 0,
        ":divchild<-ui", 0,
        ":divchildlist<-uimap", 0,
        ":divchildlist<-uimap_1", 0,
        ":divchildlist<-uimap-origmap-parent", 0,
        ":node-app<-ui-orig-parent", 0,
        ":node-default<-ui-orig-parent", 0,
        ":node-image<-ui-orig-parent", 0,
        ":node-label<-ui-orig-parent", 0,
        ":node-layout<-node-ui-parent", 0,
        ":node<-ui-orig-parent", 0,
        ":string-class<-ui", 0,
        ":string-style<-font", 0,
        ":string-style<-image", 0,
        ":string-stylename<-name-styletype", 0,
        ":style<-fontface", 0,
        ":style<-style", 0,
        ":stylelist-extra<-ui", 0,
        ":stylelist-reset", 0,
        ":stylelist<-fontfacemap", 0,
        ":stylelist<-stylelist", 0,
        ":stylelist<-stylemap", 0,
        ":stylemap<-stylemap", 0,
        ":stylesheet-layout-html", 0,
        ":stylesheet<-stylesheet", 0,
        ":ui-layout-app<-ui-orig-parent", 0,
        ":ui-layout-default<-ui-orig-parent", 0,
        ":ui-layout-image<-ui-orig-parent", 0,
        ":ui-layout-label<-ui-orig-parent", 0
      ));
  }

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/ui/html/uihtml", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
