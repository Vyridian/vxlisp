/**
 * Unit test for whole App.
 */
import com.vxlisp.vx.*
import com.vxlisp.vx.translation.*
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*
import com.vxlisp.vx.ui.*
import com.vxlisp.vx.ui.html.*
import com.vxlisp.vx.ui.svg.*

import org.junit.jupiter.api.DisplayName
import org.junit.jupiter.api.Test

object AppTest {


  var arglist : vx_core.Type_anylist = vx_core.e_anylist
  var context : vx_core.Type_context = vx_translation_en.f_context_test(arglist)

  @Test
  fun test_basics() {
    TestLib.test_helloworld()
    TestLib.test_async_new_from_value()
    TestLib.test_async_from_async_fn()
    TestLib.test_list_from_list_async()
    TestLib.test_pathfull_from_file()
    TestLib.test_read_file()
    TestLib.test_write_file()
  }

  @Test
  @DisplayName("vx/core")
  fun test_vx_core() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_coreTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/db")
  fun test_vx_data_db() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_dbTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/table")
  fun test_vx_data_table() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_tableTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/tree")
  fun test_vx_data_tree() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_treeTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/event")
  fun test_vx_event() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_eventTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/sample")
  fun test_vx_sample() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_sampleTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/state")
  fun test_vx_state() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_stateTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/type")
  fun test_vx_type() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_typeTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/web/html")
  fun test_vx_web_html() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_web_htmlTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/collection")
  fun test_vx_collection() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_collectionTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/textblock")
  fun test_vx_data_textblock() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_textblockTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/repl")
  fun test_vx_repl() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_replTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/file")
  fun test_vx_data_file() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_fileTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/xml")
  fun test_vx_data_xml() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_xmlTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/test")
  fun test_vx_test() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_testTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/ui/ui")
  fun test_vx_ui_ui() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_ui_uiTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/web/htmldoc")
  fun test_vx_web_htmldoc() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_web_htmldocTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/data/csv")
  fun test_vx_data_csv() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_data_csvTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/translate")
  fun test_vx_translate() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_translateTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/translation/en")
  fun test_vx_translation_en() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_translation_enTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/translation/es")
  fun test_vx_translation_es() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_translation_esTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/ui/html/uihtml")
  fun test_vx_ui_html_uihtml() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_ui_html_uihtmlTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/ui/svg/uisvg")
  fun test_vx_ui_svg_uisvg() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_ui_svg_uisvgTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/web/http")
  fun test_vx_web_http() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_web_httpTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("vx/translation/all")
  fun test_vx_translation_all() : Unit {
    val testpackage : vx_test.Type_testpackage = vx_translation_allTest.test_package(context)
    TestLib.run_testpackage_async(testpackage)
  }

  @Test
  @DisplayName("writetestsuite")
  fun test_writetestsuite() {
    val testpackagelist : vx_test.Type_testpackagelist = vx_core.vx_new(
      vx_test.t_testpackagelist,
      vx_coreTest.test_package(context),
      vx_data_dbTest.test_package(context),
      vx_data_tableTest.test_package(context),
      vx_data_treeTest.test_package(context),
      vx_eventTest.test_package(context),
      vx_sampleTest.test_package(context),
      vx_stateTest.test_package(context),
      vx_typeTest.test_package(context),
      vx_web_htmlTest.test_package(context),
      vx_collectionTest.test_package(context),
      vx_data_textblockTest.test_package(context),
      vx_replTest.test_package(context),
      vx_data_fileTest.test_package(context),
      vx_data_xmlTest.test_package(context),
      vx_testTest.test_package(context),
      vx_ui_uiTest.test_package(context),
      vx_web_htmldocTest.test_package(context),
      vx_data_csvTest.test_package(context),
      vx_translateTest.test_package(context),
      vx_translation_enTest.test_package(context),
      vx_translation_esTest.test_package(context),
      vx_ui_html_uihtmlTest.test_package(context),
      vx_ui_svg_uisvgTest.test_package(context),
      vx_web_httpTest.test_package(context),
      vx_translation_allTest.test_package(context)
    )
    TestLib.write_testpackagelist_async(context, testpackagelist)
  }
}
