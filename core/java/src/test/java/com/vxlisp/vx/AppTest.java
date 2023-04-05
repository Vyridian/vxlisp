package com.vxlisp.vx;

import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;

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
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Collectioncom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/core")
  void test_vx_core() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Corecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/csv")
  void test_vx_data_csv() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Csvcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/db")
  void test_vx_data_db() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Dbcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/file")
  void test_vx_data_file() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Filecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/table")
  void test_vx_data_table() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Tablecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/textblock")
  void test_vx_data_textblock() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Textblockcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/tree")
  void test_vx_data_tree() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Treecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/xml")
  void test_vx_data_xml() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Xmlcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/repl")
  void test_vx_repl() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Replcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/sample")
  void test_vx_sample() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Samplecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/state")
  void test_vx_state() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Statecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/test")
  void test_vx_test() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Testcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/type")
  void test_vx_type() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Typecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/web/html")
  void test_vx_web_html() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Htmlcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/web/http")
  void test_vx_web_http() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Httpcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/collection")
  void test_vx_collection() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Collectioncom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/core")
  void test_vx_core() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Corecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/csv")
  void test_vx_data_csv() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Csvcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/db")
  void test_vx_data_db() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Dbcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/file")
  void test_vx_data_file() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Filecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/table")
  void test_vx_data_table() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Tablecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/textblock")
  void test_vx_data_textblock() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Textblockcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/tree")
  void test_vx_data_tree() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Treecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/data/xml")
  void test_vx_data_xml() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Xmlcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/repl")
  void test_vx_repl() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Replcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/sample")
  void test_vx_sample() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Samplecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/state")
  void test_vx_state() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Statecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/test")
  void test_vx_test() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Testcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/type")
  void test_vx_type() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Typecom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/web/html")
  void test_vx_web_html() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Htmlcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

  @Test
  @DisplayName("vx/web/http")
  void test_vx_web_http() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = Httpcom.vxlisp.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }


  @Test
	@DisplayName("writetestsuite")
  void test_writetestsuite() {
    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = com.vxlisp.vx.Test.t_testpackagelist.vx_new(
    Collectioncom.vxlisp.vx.Test.test_package(context),
    Corecom.vxlisp.vx.Test.test_package(context),
    Csvcom.vxlisp.vx.Test.test_package(context),
    Dbcom.vxlisp.vx.Test.test_package(context),
    Filecom.vxlisp.vx.Test.test_package(context),
    Tablecom.vxlisp.vx.Test.test_package(context),
    Textblockcom.vxlisp.vx.Test.test_package(context),
    Treecom.vxlisp.vx.Test.test_package(context),
    Xmlcom.vxlisp.vx.Test.test_package(context),
    Replcom.vxlisp.vx.Test.test_package(context),
    Samplecom.vxlisp.vx.Test.test_package(context),
    Statecom.vxlisp.vx.Test.test_package(context),
    Testcom.vxlisp.vx.Test.test_package(context),
    Typecom.vxlisp.vx.Test.test_package(context),
    Htmlcom.vxlisp.vx.Test.test_package(context),
    Httpcom.vxlisp.vx.Test.test_package(context),
    Collectioncom.vxlisp.vx.Test.test_package(context),
    Corecom.vxlisp.vx.Test.test_package(context),
    Csvcom.vxlisp.vx.Test.test_package(context),
    Dbcom.vxlisp.vx.Test.test_package(context),
    Filecom.vxlisp.vx.Test.test_package(context),
    Tablecom.vxlisp.vx.Test.test_package(context),
    Textblockcom.vxlisp.vx.Test.test_package(context),
    Treecom.vxlisp.vx.Test.test_package(context),
    Xmlcom.vxlisp.vx.Test.test_package(context),
    Replcom.vxlisp.vx.Test.test_package(context),
    Samplecom.vxlisp.vx.Test.test_package(context),
    Statecom.vxlisp.vx.Test.test_package(context),
    Testcom.vxlisp.vx.Test.test_package(context),
    Typecom.vxlisp.vx.Test.test_package(context),
    Htmlcom.vxlisp.vx.Test.test_package(context),
    Httpcom.vxlisp.vx.Test.test_package(context)
    );
    TestLib.write_testpackagelist_async(testpackagelist, context);
  }

}
