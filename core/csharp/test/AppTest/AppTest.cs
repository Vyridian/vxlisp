/**
 * Unit test for whole App.
 */
using Xunit;



namespace AppTest;

public class AppTest(Xunit.Abstractions.ITestOutputHelper output) {

  bool isconsole = TestLib.EnableConsole(output);

  public static Vx.Core.Type_anylist arglist = Vx.Core.e_anylist;
  public static Vx.Core.Type_context context = Vx.Translation.En.f_context_test(arglist);

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
      Vx.Test.t_testpackagelist,
      TestVx.CoreTest.test_package(context),
      TestVx.Data.DbTest.test_package(context),
      TestVx.Data.TableTest.test_package(context),
      TestVx.Data.TreeTest.test_package(context),
      TestVx.EventTest.test_package(context),
      TestVx.SampleTest.test_package(context),
      TestVx.StateTest.test_package(context),
      TestVx.TypeTest.test_package(context),
      TestVx.Web.HtmlTest.test_package(context),
      TestVx.CollectionTest.test_package(context),
      TestVx.Data.TextblockTest.test_package(context),
      TestVx.ReplTest.test_package(context),
      TestVx.Data.FileTest.test_package(context),
      TestVx.Data.XmlTest.test_package(context),
      TestVx.TestTest.test_package(context),
      TestVx.Ui.UiTest.test_package(context),
      TestVx.Web.HtmldocTest.test_package(context),
      TestVx.Data.CsvTest.test_package(context),
      TestVx.TranslateTest.test_package(context),
      TestVx.Translation.EnTest.test_package(context),
      TestVx.Translation.EsTest.test_package(context),
      TestVx.Ui.Html.UihtmlTest.test_package(context),
      TestVx.Ui.Svg.UisvgTest.test_package(context),
      TestVx.Web.HttpTest.test_package(context),
      TestVx.Translation.AllTest.test_package(context)
    );
    TestLib.write_testpackagelist_async(context, testpackagelist);
  }

}
