package com.vxlisp.vx;

import com.sample.vx.*;
import com.sample.vx.data.*;
import com.sample.vx.web.*;
import com.sample.nexus.crypto.*;
import com.sample.nexus.tactics.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */
public class AppTest {

  Core.Type_context context = Core.t_context.vx_new();

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
  @DisplayName("vx/web/http")
  void test_vx_web_http() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = HttpTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("nexus/crypto/cryptosheet")
  void test_nexus_crypto_cryptosheet() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = CryptosheetTest.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("nexus/tactics/base")
  void test_nexus_tactics_base() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = BaseTest.test_package(context);
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
    ReplTest.test_package(context),
    SampleTest.test_package(context),
    StateTest.test_package(context),
    TestTest.test_package(context),
    TypeTest.test_package(context),
    HtmlTest.test_package(context),
    HttpTest.test_package(context),
    CryptosheetTest.test_package(context),
    BaseTest.test_package(context)
    );
    TestLib.write_testpackagelist_async(testpackagelist, context);
  }

}
