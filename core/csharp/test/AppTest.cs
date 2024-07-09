/**
 * Unit test for whole App.
 */


namespace Test.Vx;

public class AppTest {

  Vx.Core.Type_anylist arglist = Vx.Core.e_anylist;
  Vx.Core.Type_context context = vx.translation.Vx.Translation.En.f_context_test(arglist);

  [TestMethod]
  public void test_vx_core() {
    Vx.Test.Type_testpackage testpackage = Vx.CoreTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_db() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.DbTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_table() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.TableTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_tree() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.TreeTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_event() {
    Vx.Test.Type_testpackage testpackage = Vx.EventTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_sample() {
    Vx.Test.Type_testpackage testpackage = Vx.SampleTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_state() {
    Vx.Test.Type_testpackage testpackage = Vx.StateTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_type() {
    Vx.Test.Type_testpackage testpackage = Vx.TypeTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_web_html() {
    Vx.Test.Type_testpackage testpackage = Vx.Web.HtmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_collection() {
    Vx.Test.Type_testpackage testpackage = Vx.CollectionTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_textblock() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.TextblockTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_repl() {
    Vx.Test.Type_testpackage testpackage = Vx.ReplTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_file() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.FileTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_xml() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.XmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_test() {
    Vx.Test.Type_testpackage testpackage = Vx.TestTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_ui_ui() {
    Vx.Test.Type_testpackage testpackage = Vx.Ui.UiTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_web_htmldoc() {
    Vx.Test.Type_testpackage testpackage = Vx.Web.HtmldocTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_data_csv() {
    Vx.Test.Type_testpackage testpackage = Vx.Data.CsvTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_translate() {
    Vx.Test.Type_testpackage testpackage = Vx.TranslateTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_translation_en() {
    Vx.Test.Type_testpackage testpackage = Vx.Translation.EnTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_translation_es() {
    Vx.Test.Type_testpackage testpackage = Vx.Translation.EsTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_ui_html_uihtml() {
    Vx.Test.Type_testpackage testpackage = Vx.Ui.Html.UihtmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_ui_svg_uisvg() {
    Vx.Test.Type_testpackage testpackage = Vx.Ui.Svg.UisvgTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_web_http() {
    Vx.Test.Type_testpackage testpackage = Vx.Web.HttpTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [TestMethod]
  public void test_vx_translation_all() {
    Vx.Test.Type_testpackage testpackage = Vx.Translation.AllTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

 	[TestClass]
  public class AppTest {
    [TestMethod]
    public void test_writetestsuite() {
      Vx.Test.Type_testpackagelist testpackagelist = Vx.Core.vx_new(
      com.vxlisp.vx.Test.t_testpackagelist,
      Vx.CoreTest.test_package(context),
      Vx.Data.DbTest.test_package(context),
      Vx.Data.TableTest.test_package(context),
      Vx.Data.TreeTest.test_package(context),
      Vx.EventTest.test_package(context),
      Vx.SampleTest.test_package(context),
      Vx.StateTest.test_package(context),
      Vx.TypeTest.test_package(context),
      Vx.Web.HtmlTest.test_package(context),
      Vx.CollectionTest.test_package(context),
      Vx.Data.TextblockTest.test_package(context),
      Vx.ReplTest.test_package(context),
      Vx.Data.FileTest.test_package(context),
      Vx.Data.XmlTest.test_package(context),
      Vx.TestTest.test_package(context),
      Vx.Ui.UiTest.test_package(context),
      Vx.Web.HtmldocTest.test_package(context),
      Vx.Data.CsvTest.test_package(context),
      Vx.TranslateTest.test_package(context),
      Vx.Translation.EnTest.test_package(context),
      Vx.Translation.EsTest.test_package(context),
      Vx.Ui.Html.UihtmlTest.test_package(context),
      Vx.Ui.Svg.UisvgTest.test_package(context),
      Vx.Web.HttpTest.test_package(context),
      Vx.Translation.AllTest.test_package(context)
    );;
    TestLib.write_testpackagelist_async(context, testpackagelist);
    }
  }

}
