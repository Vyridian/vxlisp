'strict mode'

import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_web_html from "../../src/vx/web/html.js"
import vx_collection_test from "../vx/collection_test.js"
import vx_core_test from "../vx/core_test.js"
import vx_data_csv_test from "../vx/data/csv_test.js"
import vx_data_db_test from "../vx/data/db_test.js"
import vx_data_file_test from "../vx/data/file_test.js"
import vx_data_table_test from "../vx/data/table_test.js"
import vx_data_textblock_test from "../vx/data/textblock_test.js"
import vx_data_tree_test from "../vx/data/tree_test.js"
import vx_data_xml_test from "../vx/data/xml_test.js"
import vx_repl_test from "../vx/repl_test.js"
import vx_sample_test from "../vx/sample_test.js"
import vx_state_test from "../vx/state_test.js"
import vx_test_test from "../vx/test_test.js"
import vx_type_test from "../vx/type_test.js"
import vx_web_html_test from "../vx/web/html_test.js"
import vx_web_http_test from "../vx/web/http_test.js"
import crypto_cryptosheet_test from "../crypto/cryptosheet_test.js"
import tactics_base_test from "../tactics/base_test.js"

export default class testlib {

  static async f_displaytestsuite() {
    const context = vx_core.e_context
    const stylesheet = vx_test.c_stylesheet_test
    const testpackagelist = testlib.f_testpackagelist_from_all_test(context)
    const resolvedtestpackagelist = await vx_test.f_resolve_testpackagelist(testpackagelist)
    const div = vx_test.f_div_from_testpackagelist(resolvedtestpackagelist)
    const htmltext = vx_web_html.f_string_from_div_indent(div, 0)
    vx_web_html.f_boolean_write_from_stylesheet(stylesheet)
    vx_web_html.f_boolean_write_from_id_htmltext("testdisplay", htmltext)
  }

  static f_testpackagelist_from_all_test(context) {
    const testpackagelist = vx_core.f_new(
      vx_test.t_testpackagelist,
			      vx_collection_test.test_package(context),
      vx_core_test.test_package(context),
      vx_data_csv_test.test_package(context),
      vx_data_db_test.test_package(context),
      vx_data_file_test.test_package(context),
      vx_data_table_test.test_package(context),
      vx_data_textblock_test.test_package(context),
      vx_data_tree_test.test_package(context),
      vx_data_xml_test.test_package(context),
      vx_repl_test.test_package(context),
      vx_sample_test.test_package(context),
      vx_state_test.test_package(context),
      vx_test_test.test_package(context),
      vx_type_test.test_package(context),
      vx_web_html_test.test_package(context),
      vx_web_http_test.test_package(context),
      crypto_cryptosheet_test.test_package(context),
      tactics_base_test.test_package(context)
    )
    return testpackagelist
  }

}