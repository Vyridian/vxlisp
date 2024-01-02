
import com.vxlisp.vx.Core;
import com.vxlisp.vx.translation.En;
import com.vxlisp.vx.CollectionTest;
import com.vxlisp.vx.CoreTest;
import com.vxlisp.vx.data.CsvTest;
import com.vxlisp.vx.data.DbTest;
import com.vxlisp.vx.data.FileTest;
import com.vxlisp.vx.data.TableTest;
import com.vxlisp.vx.data.TextblockTest;
import com.vxlisp.vx.data.TreeTest;
import com.vxlisp.vx.data.XmlTest;
import com.vxlisp.vx.EventTest;
import com.vxlisp.vx.ReplTest;
import com.vxlisp.vx.SampleTest;
import com.vxlisp.vx.StateTest;
import com.vxlisp.vx.TestTest;
import com.vxlisp.vx.TranslateTest;
import com.vxlisp.vx.translation.AllTest;
import com.vxlisp.vx.translation.EnTest;
import com.vxlisp.vx.translation.EsTest;
import com.vxlisp.vx.TypeTest;
import com.vxlisp.vx.web.HtmlTest;
import com.vxlisp.vx.web.HtmldocTest;
import com.vxlisp.vx.web.HttpTest;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */
public final class AppTest {


  Core.Type_anylist arglist = Core.e_anylist;
  Core.Type_context context = com.vxlisp.vx.translation.En.f_context_test(arglist);

  @Test
  @DisplayName("vx/collection")
  void test_vx_collection() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = CollectionTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/core")
  void test_vx_core() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = CoreTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/csv")
  void test_vx_data_csv() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = CsvTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/db")
  void test_vx_data_db() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = DbTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/file")
  void test_vx_data_file() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = FileTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/table")
  void test_vx_data_table() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TableTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/textblock")
  void test_vx_data_textblock() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TextblockTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/tree")
  void test_vx_data_tree() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TreeTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/data/xml")
  void test_vx_data_xml() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = XmlTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/event")
  void test_vx_event() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = EventTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/repl")
  void test_vx_repl() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = ReplTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/sample")
  void test_vx_sample() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = SampleTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/state")
  void test_vx_state() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = StateTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/test")
  void test_vx_test() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TestTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/translate")
  void test_vx_translate() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TranslateTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/translation/all")
  void test_vx_translation_all() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = AllTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/translation/en")
  void test_vx_translation_en() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = EnTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/translation/es")
  void test_vx_translation_es() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = EsTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/type")
  void test_vx_type() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = TypeTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/web/html")
  void test_vx_web_html() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = HtmlTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/web/htmldoc")
  void test_vx_web_htmldoc() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = HtmldocTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("vx/web/http")
  void test_vx_web_http() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = HttpTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
  @DisplayName("writetestsuite")
  void test_writetestsuite() {
    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = com.vxlisp.vx.Test.t_testpackagelist.vx_new(
    CollectionTest.test_package(context),
    CoreTest.test_package(context),
    CsvTest.test_package(context),
    DbTest.test_package(context),
    FileTest.test_package(context),
    TableTest.test_package(context),
    TextblockTest.test_package(context),
    TreeTest.test_package(context),
    XmlTest.test_package(context),
    EventTest.test_package(context),
    ReplTest.test_package(context),
    SampleTest.test_package(context),
    StateTest.test_package(context),
    TestTest.test_package(context),
    TranslateTest.test_package(context),
    AllTest.test_package(context),
    EnTest.test_package(context),
    EsTest.test_package(context),
    TypeTest.test_package(context),
    HtmlTest.test_package(context),
    HtmldocTest.test_package(context),
    HttpTest.test_package(context)
    );
    TestLib.write_testpackagelist_async(context, testpackagelist);
  }
}
