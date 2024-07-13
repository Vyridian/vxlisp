/**
 * Unit test for whole App.
 */



namespace AppTest;

public class AppTest {

  Vx.Core.Type_anylist arglist = Vx.Core.e_anylist;
  Vx.Core.Type_context context = vx.translation.Vx.Translation.En.f_context_test(arglist);

  [Fact]
  public void test_vx_core() {
    Vx.Test.Type_testpackage testpackage = TestVx.CoreTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_db() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.DbTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_table() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.TableTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_tree() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.TreeTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_event() {
    Vx.Test.Type_testpackage testpackage = TestVx.EventTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_sample() {
    Vx.Test.Type_testpackage testpackage = TestVx.SampleTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_state() {
    Vx.Test.Type_testpackage testpackage = TestVx.StateTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_type() {
    Vx.Test.Type_testpackage testpackage = TestVx.TypeTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_web_html() {
    Vx.Test.Type_testpackage testpackage = TestVx.Web.HtmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_collection() {
    Vx.Test.Type_testpackage testpackage = TestVx.CollectionTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_textblock() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.TextblockTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_repl() {
    Vx.Test.Type_testpackage testpackage = TestVx.ReplTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_file() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.FileTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_xml() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.XmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_test() {
    Vx.Test.Type_testpackage testpackage = TestVx.TestTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_ui_ui() {
    Vx.Test.Type_testpackage testpackage = TestVx.Ui.UiTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_web_htmldoc() {
    Vx.Test.Type_testpackage testpackage = TestVx.Web.HtmldocTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_data_csv() {
    Vx.Test.Type_testpackage testpackage = TestVx.Data.CsvTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_translate() {
    Vx.Test.Type_testpackage testpackage = TestVx.TranslateTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_translation_en() {
    Vx.Test.Type_testpackage testpackage = TestVx.Translation.EnTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_translation_es() {
    Vx.Test.Type_testpackage testpackage = TestVx.Translation.EsTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_ui_html_uihtml() {
    Vx.Test.Type_testpackage testpackage = TestVx.Ui.Html.UihtmlTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_ui_svg_uisvg() {
    Vx.Test.Type_testpackage testpackage = TestVx.Ui.Svg.UisvgTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_web_http() {
    Vx.Test.Type_testpackage testpackage = TestVx.Web.HttpTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
  public void test_vx_translation_all() {
    Vx.Test.Type_testpackage testpackage = TestVx.Translation.AllTest.test_package(context);
    TestLib.run_testpackage_async(testpackage);
  }

  [Fact]
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
    );
    TestLib.write_testpackagelist_async(context, testpackagelist);
  }

}
