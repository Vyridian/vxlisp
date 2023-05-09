#include <any>
#include <exception>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/file.hpp"
#include "../vx/web/html.hpp"
#include "vx/test.hpp"

//namespace vx_test {

  /**
   * type: testcase
   * Structure to describe a test case
   * (type testcase)
   */
  //class Type_testcase {
    // passfail()
    vx_core::Type_boolean* vx_test::Type_testcase::passfail() {
      vx_core::Type_boolean* output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testcase::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // casename()
    vx_core::Type_string* vx_test::Type_testcase::casename() {
      vx_core::Type_string* output = this->vx_p_casename;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // describelist()
    vx_test::Type_testdescribelist* vx_test::Type_testcase::describelist() {
      vx_test::Type_testdescribelist* output = this->vx_p_describelist;
      if (output == NULL) {
        output = vx_test::t_testdescribelist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testcase::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":passfail") {
        output = this->passfail();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":casename") {
        output = this->casename();
      } else if (skey == ":describelist") {
        output = this->describelist();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testcase::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":passfail"] = this->passfail();
      output[":testpkg"] = this->testpkg();
      output[":casename"] = this->casename();
      output[":describelist"] = this->describelist();
      return output;
    }

    template<typename... Args> vx_test::Type_testcase* vx_test::Type_testcase::vx_new(Args*... args) {return vx_test::e_testcase->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testcase* vx_test::Type_testcase::vx_copy(Args*... args) {
      vx_test::Type_testcase* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testcase* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_passfail = val->passfail();
      output->vx_p_testpkg = val->testpkg();
      output->vx_p_casename = val->casename();
      output->vx_p_describelist = val->describelist();
      std::set<std::string> validkeys;
      validkeys.insert(":passfail");
      validkeys.insert(":testpkg");
      validkeys.insert(":casename");
      validkeys.insert(":describelist");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_passfail = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else if (valsubtype == vx_core::t_nativeboolean) {
              output->vx_p_passfail = vx_core::t_boolean->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase :passfail " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":casename") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_casename = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_casename = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase :casename " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":describelist") {
            if (valsubtype == vx_test::t_testdescribelist) {
              output->vx_p_describelist = vx_core::any_from_any(vx_test::t_testdescribelist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase :describelist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcase) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testcase* vx_test::Type_testcase::vx_empty() {return vx_test::e_testcase;}
    vx_test::Type_testcase* vx_test::Type_testcase::vx_type() {return vx_test::t_testcase;}

    vx_core::Type_typedef* vx_test::Type_testcase::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcase", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testcaselist
   * List of test cases
   * (type testcaselist)
   */
  //class Type_testcaselist {
    std::vector<vx_core::Type_any*> vx_test::Type_testcaselist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testcase* vx_test::Type_testcaselist::vx_testcase(vx_core::Type_int* index) {
      vx_test::Type_testcase* output = vx_test::e_testcase;
      vx_test::Type_testcaselist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_test::Type_testcase*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testcase*> vx_test::Type_testcaselist::vx_listtestcase() {return vx_p_list;}

    vx_core::Type_any* vx_test::Type_testcaselist::vx_any(vx_core::Type_int* index) {
      return this->vx_testcase(index);
    }

    template<typename... Args> vx_test::Type_testcaselist* vx_test::Type_testcaselist::vx_new(Args*... args) {return vx_test::e_testcaselist->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testcaselist* vx_test::Type_testcaselist::vx_copy(Args*... args) {
      vx_test::Type_testcaselist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_test::Type_testcaselist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_test::Type_testcase*> listval = val->vx_listtestcase();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_test::t_testcase) {
          listval.push_back(vx_core::any_from_any(vx_test::t_testcase, valsub));
        } else if (valsubtype == vx_test::t_testcaselist) {
          vx_test::Type_testcaselist* multi = vx_core::any_from_any(vx_test::t_testcaselist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtestcase());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_test::t_testcase) {
              vx_test::Type_testcase* valitem = vx_core::any_from_any(vx_test::t_testcase, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcaselist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testcaselist* vx_test::Type_testcaselist::vx_empty() {return vx_test::e_testcaselist;}
    vx_test::Type_testcaselist* vx_test::Type_testcaselist::vx_type() {return vx_test::t_testcaselist;}

    vx_core::Type_typedef* vx_test::Type_testcaselist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_test::t_testcase), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testcoveragedetail
   * Structure to describe a test coverage detail
   * (type testcoveragedetail)
   */
  //class Type_testcoveragedetail {
    // constmap()
    vx_core::Type_intmap* vx_test::Type_testcoveragedetail::constmap() {
      vx_core::Type_intmap* output = this->vx_p_constmap;
      if (output == NULL) {
        output = vx_core::t_intmap;
      }
    }

    // funcmap()
    vx_core::Type_intmap* vx_test::Type_testcoveragedetail::funcmap() {
      vx_core::Type_intmap* output = this->vx_p_funcmap;
      if (output == NULL) {
        output = vx_core::t_intmap;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testcoveragedetail::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // typemap()
    vx_core::Type_intmap* vx_test::Type_testcoveragedetail::typemap() {
      vx_core::Type_intmap* output = this->vx_p_typemap;
      if (output == NULL) {
        output = vx_core::t_intmap;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testcoveragedetail::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":constmap") {
        output = this->constmap();
      } else if (skey == ":funcmap") {
        output = this->funcmap();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":typemap") {
        output = this->typemap();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testcoveragedetail::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":constmap"] = this->constmap();
      output[":funcmap"] = this->funcmap();
      output[":testpkg"] = this->testpkg();
      output[":typemap"] = this->typemap();
      return output;
    }

    template<typename... Args> vx_test::Type_testcoveragedetail* vx_test::Type_testcoveragedetail::vx_new(Args*... args) {return vx_test::e_testcoveragedetail->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testcoveragedetail* vx_test::Type_testcoveragedetail::vx_copy(Args*... args) {
      vx_test::Type_testcoveragedetail* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testcoveragedetail* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_constmap = val->constmap();
      output->vx_p_funcmap = val->funcmap();
      output->vx_p_testpkg = val->testpkg();
      output->vx_p_typemap = val->typemap();
      std::set<std::string> validkeys;
      validkeys.insert(":constmap");
      validkeys.insert(":funcmap");
      validkeys.insert(":testpkg");
      validkeys.insert(":typemap");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":constmap") {
            if (valsubtype == vx_core::t_intmap) {
              output->vx_p_constmap = vx_core::any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail :constmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":funcmap") {
            if (valsubtype == vx_core::t_intmap) {
              output->vx_p_funcmap = vx_core::any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail :funcmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":typemap") {
            if (valsubtype == vx_core::t_intmap) {
              output->vx_p_typemap = vx_core::any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail :typemap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragedetail) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testcoveragedetail* vx_test::Type_testcoveragedetail::vx_empty() {return vx_test::e_testcoveragedetail;}
    vx_test::Type_testcoveragedetail* vx_test::Type_testcoveragedetail::vx_type() {return vx_test::t_testcoveragedetail;}

    vx_core::Type_typedef* vx_test::Type_testcoveragedetail::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testcoveragenums
   * Structure to describe a test coverage summary
   * (type testcoveragenums)
   */
  //class Type_testcoveragenums {
    // pct()
    vx_core::Type_int* vx_test::Type_testcoveragenums::pct() {
      vx_core::Type_int* output = this->vx_p_pct;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testcoveragenums::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // tests()
    vx_core::Type_int* vx_test::Type_testcoveragenums::tests() {
      vx_core::Type_int* output = this->vx_p_tests;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // total()
    vx_core::Type_int* vx_test::Type_testcoveragenums::total() {
      vx_core::Type_int* output = this->vx_p_total;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testcoveragenums::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pct") {
        output = this->pct();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":tests") {
        output = this->tests();
      } else if (skey == ":total") {
        output = this->total();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testcoveragenums::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":pct"] = this->pct();
      output[":testpkg"] = this->testpkg();
      output[":tests"] = this->tests();
      output[":total"] = this->total();
      return output;
    }

    template<typename... Args> vx_test::Type_testcoveragenums* vx_test::Type_testcoveragenums::vx_new(Args*... args) {return vx_test::e_testcoveragenums->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testcoveragenums* vx_test::Type_testcoveragenums::vx_copy(Args*... args) {
      vx_test::Type_testcoveragenums* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testcoveragenums* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_pct = val->pct();
      output->vx_p_testpkg = val->testpkg();
      output->vx_p_tests = val->tests();
      output->vx_p_total = val->total();
      std::set<std::string> validkeys;
      validkeys.insert(":pct");
      validkeys.insert(":testpkg");
      validkeys.insert(":tests");
      validkeys.insert(":total");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":pct") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_pct = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_pct = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums :pct " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":tests") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_tests = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_tests = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums :tests " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":total") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_total = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_total = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums :total " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragenums) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragenums::vx_empty() {return vx_test::e_testcoveragenums;}
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragenums::vx_type() {return vx_test::t_testcoveragenums;}

    vx_core::Type_typedef* vx_test::Type_testcoveragenums::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testcoveragesummary
   * Structure to describe a test coverage summary
   * (type testcoveragesummary)
   */
  //class Type_testcoveragesummary {
    // bigospacenums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::bigospacenums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_bigospacenums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // bigotimenums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::bigotimenums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_bigotimenums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // constnums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::constnums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_constnums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // docnums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::docnums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_docnums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // funcnums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::funcnums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_funcnums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testcoveragesummary::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // totalnums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::totalnums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_totalnums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // typenums()
    vx_test::Type_testcoveragenums* vx_test::Type_testcoveragesummary::typenums() {
      vx_test::Type_testcoveragenums* output = this->vx_p_typenums;
      if (output == NULL) {
        output = vx_test::t_testcoveragenums;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testcoveragesummary::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":bigospacenums") {
        output = this->bigospacenums();
      } else if (skey == ":bigotimenums") {
        output = this->bigotimenums();
      } else if (skey == ":constnums") {
        output = this->constnums();
      } else if (skey == ":docnums") {
        output = this->docnums();
      } else if (skey == ":funcnums") {
        output = this->funcnums();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":totalnums") {
        output = this->totalnums();
      } else if (skey == ":typenums") {
        output = this->typenums();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testcoveragesummary::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":bigospacenums"] = this->bigospacenums();
      output[":bigotimenums"] = this->bigotimenums();
      output[":constnums"] = this->constnums();
      output[":docnums"] = this->docnums();
      output[":funcnums"] = this->funcnums();
      output[":testpkg"] = this->testpkg();
      output[":totalnums"] = this->totalnums();
      output[":typenums"] = this->typenums();
      return output;
    }

    template<typename... Args> vx_test::Type_testcoveragesummary* vx_test::Type_testcoveragesummary::vx_new(Args*... args) {return vx_test::e_testcoveragesummary->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testcoveragesummary* vx_test::Type_testcoveragesummary::vx_copy(Args*... args) {
      vx_test::Type_testcoveragesummary* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testcoveragesummary* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_bigospacenums = val->bigospacenums();
      output->vx_p_bigotimenums = val->bigotimenums();
      output->vx_p_constnums = val->constnums();
      output->vx_p_docnums = val->docnums();
      output->vx_p_funcnums = val->funcnums();
      output->vx_p_testpkg = val->testpkg();
      output->vx_p_totalnums = val->totalnums();
      output->vx_p_typenums = val->typenums();
      std::set<std::string> validkeys;
      validkeys.insert(":bigospacenums");
      validkeys.insert(":bigotimenums");
      validkeys.insert(":constnums");
      validkeys.insert(":docnums");
      validkeys.insert(":funcnums");
      validkeys.insert(":testpkg");
      validkeys.insert(":totalnums");
      validkeys.insert(":typenums");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":bigospacenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_bigospacenums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :bigospacenums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":bigotimenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_bigotimenums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :bigotimenums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":constnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_constnums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :constnums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":docnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_docnums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :docnums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":funcnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_funcnums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :funcnums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":totalnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_totalnums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :totalnums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":typenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              output->vx_p_typenums = vx_core::any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary :typenums " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testcoveragesummary) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testcoveragesummary* vx_test::Type_testcoveragesummary::vx_empty() {return vx_test::e_testcoveragesummary;}
    vx_test::Type_testcoveragesummary* vx_test::Type_testcoveragesummary::vx_type() {return vx_test::t_testcoveragesummary;}

    vx_core::Type_typedef* vx_test::Type_testcoveragesummary::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testdescribe
   * Structure to describe test results
   * (type testdescribe)
   */
  //class Type_testdescribe {
    // describename()
    vx_core::Type_string* vx_test::Type_testdescribe::describename() {
      vx_core::Type_string* output = this->vx_p_describename;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testdescribe::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // testresult()
    vx_test::Type_testresult* vx_test::Type_testdescribe::testresult() {
      vx_test::Type_testresult* output = this->vx_p_testresult;
      if (output == NULL) {
        output = vx_test::t_testresult;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testdescribe::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":describename") {
        output = this->describename();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":testresult") {
        output = this->testresult();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testdescribe::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":describename"] = this->describename();
      output[":testpkg"] = this->testpkg();
      output[":testresult"] = this->testresult();
      return output;
    }

    template<typename... Args> vx_test::Type_testdescribe* vx_test::Type_testdescribe::vx_new(Args*... args) {return vx_test::e_testdescribe->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testdescribe* vx_test::Type_testdescribe::vx_copy(Args*... args) {
      vx_test::Type_testdescribe* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testdescribe* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_describename = val->describename();
      output->vx_p_testpkg = val->testpkg();
      output->vx_p_testresult = val->testresult();
      std::set<std::string> validkeys;
      validkeys.insert(":describename");
      validkeys.insert(":testpkg");
      validkeys.insert(":testresult");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribe) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":describename") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_describename = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_describename = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribe :describename " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribe :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testresult") {
            if (valsubtype == vx_test::t_testresult) {
              output->vx_p_testresult = vx_core::any_from_any(vx_test::t_testresult, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribe :testresult " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribe) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testdescribe* vx_test::Type_testdescribe::vx_empty() {return vx_test::e_testdescribe;}
    vx_test::Type_testdescribe* vx_test::Type_testdescribe::vx_type() {return vx_test::t_testdescribe;}

    vx_core::Type_typedef* vx_test::Type_testdescribe::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testdescribelist
   * List of testdescribe
   * (type testdescribelist)
   */
  //class Type_testdescribelist {
    std::vector<vx_core::Type_any*> vx_test::Type_testdescribelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testdescribe* vx_test::Type_testdescribelist::vx_testdescribe(vx_core::Type_int* index) {
      vx_test::Type_testdescribe* output = vx_test::e_testdescribe;
      vx_test::Type_testdescribelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_test::Type_testdescribe*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testdescribe*> vx_test::Type_testdescribelist::vx_listtestdescribe() {return vx_p_list;}

    vx_core::Type_any* vx_test::Type_testdescribelist::vx_any(vx_core::Type_int* index) {
      return this->vx_testdescribe(index);
    }

    template<typename... Args> vx_test::Type_testdescribelist* vx_test::Type_testdescribelist::vx_new(Args*... args) {return vx_test::e_testdescribelist->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testdescribelist* vx_test::Type_testdescribelist::vx_copy(Args*... args) {
      vx_test::Type_testdescribelist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_test::Type_testdescribelist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_test::Type_testdescribe*> listval = val->vx_listtestdescribe();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_test::t_testdescribe) {
          listval.push_back(vx_core::any_from_any(vx_test::t_testdescribe, valsub));
        } else if (valsubtype == vx_test::t_testdescribelist) {
          vx_test::Type_testdescribelist* multi = vx_core::any_from_any(vx_test::t_testdescribelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtestdescribe());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_test::t_testdescribe) {
              vx_test::Type_testdescribe* valitem = vx_core::any_from_any(vx_test::t_testdescribe, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testdescribelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testdescribelist* vx_test::Type_testdescribelist::vx_empty() {return vx_test::e_testdescribelist;}
    vx_test::Type_testdescribelist* vx_test::Type_testdescribelist::vx_type() {return vx_test::t_testdescribelist;}

    vx_core::Type_typedef* vx_test::Type_testdescribelist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_test::t_testdescribe), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testpackage
   * Structure to hold all tests for a package
   * (type testpackage)
   */
  //class Type_testpackage {
    // caselist()
    vx_test::Type_testcaselist* vx_test::Type_testpackage::caselist() {
      vx_test::Type_testcaselist* output = this->vx_p_caselist;
      if (output == NULL) {
        output = vx_test::t_testcaselist;
      }
    }

    // coveragedetail()
    vx_test::Type_testcoveragedetail* vx_test::Type_testpackage::coveragedetail() {
      vx_test::Type_testcoveragedetail* output = this->vx_p_coveragedetail;
      if (output == NULL) {
        output = vx_test::t_testcoveragedetail;
      }
    }

    // coveragesummary()
    vx_test::Type_testcoveragesummary* vx_test::Type_testpackage::coveragesummary() {
      vx_test::Type_testcoveragesummary* output = this->vx_p_coveragesummary;
      if (output == NULL) {
        output = vx_test::t_testcoveragesummary;
      }
    }

    // passfail()
    vx_core::Type_boolean* vx_test::Type_testpackage::passfail() {
      vx_core::Type_boolean* output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
    }

    // testpkg()
    vx_core::Type_string* vx_test::Type_testpackage::testpkg() {
      vx_core::Type_string* output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testpackage::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":caselist") {
        output = this->caselist();
      } else if (skey == ":coveragedetail") {
        output = this->coveragedetail();
      } else if (skey == ":coveragesummary") {
        output = this->coveragesummary();
      } else if (skey == ":passfail") {
        output = this->passfail();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testpackage::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":caselist"] = this->caselist();
      output[":coveragedetail"] = this->coveragedetail();
      output[":coveragesummary"] = this->coveragesummary();
      output[":passfail"] = this->passfail();
      output[":testpkg"] = this->testpkg();
      return output;
    }

    template<typename... Args> vx_test::Type_testpackage* vx_test::Type_testpackage::vx_new(Args*... args) {return vx_test::e_testpackage->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testpackage* vx_test::Type_testpackage::vx_copy(Args*... args) {
      vx_test::Type_testpackage* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testpackage* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_caselist = val->caselist();
      output->vx_p_coveragedetail = val->coveragedetail();
      output->vx_p_coveragesummary = val->coveragesummary();
      output->vx_p_passfail = val->passfail();
      output->vx_p_testpkg = val->testpkg();
      std::set<std::string> validkeys;
      validkeys.insert(":caselist");
      validkeys.insert(":coveragedetail");
      validkeys.insert(":coveragesummary");
      validkeys.insert(":passfail");
      validkeys.insert(":testpkg");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":caselist") {
            if (valsubtype == vx_test::t_testcaselist) {
              output->vx_p_caselist = vx_core::any_from_any(vx_test::t_testcaselist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage :caselist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":coveragedetail") {
            if (valsubtype == vx_test::t_testcoveragedetail) {
              output->vx_p_coveragedetail = vx_core::any_from_any(vx_test::t_testcoveragedetail, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage :coveragedetail " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":coveragesummary") {
            if (valsubtype == vx_test::t_testcoveragesummary) {
              output->vx_p_coveragesummary = vx_core::any_from_any(vx_test::t_testcoveragesummary, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage :coveragesummary " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_passfail = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else if (valsubtype == vx_core::t_nativeboolean) {
              output->vx_p_passfail = vx_core::t_boolean->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage :passfail " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_testpkg = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_testpkg = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage :testpkg " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackage) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testpackage* vx_test::Type_testpackage::vx_empty() {return vx_test::e_testpackage;}
    vx_test::Type_testpackage* vx_test::Type_testpackage::vx_type() {return vx_test::t_testpackage;}

    vx_core::Type_typedef* vx_test::Type_testpackage::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testpackagelist
   * List of testpackage
   * (type testpackagelist)
   */
  //class Type_testpackagelist {
    std::vector<vx_core::Type_any*> vx_test::Type_testpackagelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testpackage* vx_test::Type_testpackagelist::vx_testpackage(vx_core::Type_int* index) {
      vx_test::Type_testpackage* output = vx_test::e_testpackage;
      vx_test::Type_testpackagelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_test::Type_testpackage*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testpackage*> vx_test::Type_testpackagelist::vx_listtestpackage() {return vx_p_list;}

    vx_core::Type_any* vx_test::Type_testpackagelist::vx_any(vx_core::Type_int* index) {
      return this->vx_testpackage(index);
    }

    template<typename... Args> vx_test::Type_testpackagelist* vx_test::Type_testpackagelist::vx_new(Args*... args) {return vx_test::e_testpackagelist->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testpackagelist* vx_test::Type_testpackagelist::vx_copy(Args*... args) {
      vx_test::Type_testpackagelist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_test::Type_testpackagelist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_test::Type_testpackage*> listval = val->vx_listtestpackage();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_test::t_testpackage) {
          listval.push_back(vx_core::any_from_any(vx_test::t_testpackage, valsub));
        } else if (valsubtype == vx_test::t_testpackagelist) {
          vx_test::Type_testpackagelist* multi = vx_core::any_from_any(vx_test::t_testpackagelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtestpackage());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_test::t_testpackage) {
              vx_test::Type_testpackage* valitem = vx_core::any_from_any(vx_test::t_testpackage, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testpackagelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testpackagelist* vx_test::Type_testpackagelist::vx_empty() {return vx_test::e_testpackagelist;}
    vx_test::Type_testpackagelist* vx_test::Type_testpackagelist::vx_type() {return vx_test::t_testpackagelist;}

    vx_core::Type_typedef* vx_test::Type_testpackagelist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_test::t_testpackage), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testresult
   * Structure to hold test results
   * (type testresult)
   */
  //class Type_testresult {
    // code()
    vx_core::Type_string* vx_test::Type_testresult::code() {
      vx_core::Type_string* output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // passfail()
    vx_core::Type_boolean* vx_test::Type_testresult::passfail() {
      vx_core::Type_boolean* output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
    }

    // expected()
    vx_core::Type_any* vx_test::Type_testresult::expected() {
      vx_core::Type_any* output = this->vx_p_expected;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // actual()
    vx_core::Type_any* vx_test::Type_testresult::actual() {
      vx_core::Type_any* output = this->vx_p_actual;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // fn_actual()
    vx_core::Func_any_from_func_async* vx_test::Type_testresult::fn_actual() {
      vx_core::Func_any_from_func_async* output = this->vx_p_fn_actual;
      if (output == NULL) {
        output = vx_core::t_any_from_func_async;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_test::Type_testresult::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":passfail") {
        output = this->passfail();
      } else if (skey == ":expected") {
        output = this->expected();
      } else if (skey == ":actual") {
        output = this->actual();
      } else if (skey == ":fn-actual") {
        output = this->fn_actual();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_test::Type_testresult::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":code"] = this->code();
      output[":passfail"] = this->passfail();
      output[":expected"] = this->expected();
      output[":actual"] = this->actual();
      output[":fn-actual"] = this->fn_actual();
      return output;
    }

    template<typename... Args> vx_test::Type_testresult* vx_test::Type_testresult::vx_new(Args*... args) {return vx_test::e_testresult->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testresult* vx_test::Type_testresult::vx_copy(Args*... args) {
      vx_test::Type_testresult* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_testresult* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_code = val->code();
      output->vx_p_passfail = val->passfail();
      output->vx_p_expected = val->expected();
      output->vx_p_actual = val->actual();
      output->vx_p_fn_actual = val->fn_actual();
      std::set<std::string> validkeys;
      validkeys.insert(":code");
      validkeys.insert(":passfail");
      validkeys.insert(":expected");
      validkeys.insert(":actual");
      validkeys.insert(":fn-actual");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_code = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_code = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult :code " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_passfail = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else if (valsubtype == vx_core::t_nativeboolean) {
              output->vx_p_passfail = vx_core::t_boolean->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult :passfail " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":expected") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_expected = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult :expected " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":actual") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_actual = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult :actual " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":fn-actual") {
            if (valsubtype == vx_core::t_any_from_func_async) {
              output->vx_p_fn_actual = vx_core::any_from_any(vx_core::t_any_from_func_async, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult :fn-actual " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresult) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testresult* vx_test::Type_testresult::vx_empty() {return vx_test::e_testresult;}
    vx_test::Type_testresult* vx_test::Type_testresult::vx_type() {return vx_test::t_testresult;}

    vx_core::Type_typedef* vx_test::Type_testresult::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: testresultlist
   * List of test results
   * (type testresultlist)
   */
  //class Type_testresultlist {
    std::vector<vx_core::Type_any*> vx_test::Type_testresultlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testresult* vx_test::Type_testresultlist::vx_testresult(vx_core::Type_int* index) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
      vx_test::Type_testresultlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_test::Type_testresult*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testresult*> vx_test::Type_testresultlist::vx_listtestresult() {return vx_p_list;}

    vx_core::Type_any* vx_test::Type_testresultlist::vx_any(vx_core::Type_int* index) {
      return this->vx_testresult(index);
    }

    template<typename... Args> vx_test::Type_testresultlist* vx_test::Type_testresultlist::vx_new(Args*... args) {return vx_test::e_testresultlist->vx_copy(args...);}
    template<typename... Args> vx_test::Type_testresultlist* vx_test::Type_testresultlist::vx_copy(Args*... args) {
      vx_test::Type_testresultlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_test::Type_testresultlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_test::Type_testresult*> listval = val->vx_listtestresult();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_test::t_testresult) {
          listval.push_back(vx_core::any_from_any(vx_test::t_testresult, valsub));
        } else if (valsubtype == vx_test::t_testresultlist) {
          vx_test::Type_testresultlist* multi = vx_core::any_from_any(vx_test::t_testresultlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtestresult());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_test::t_testresult) {
              vx_test::Type_testresult* valitem = vx_core::any_from_any(vx_test::t_testresult, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new testresultlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_test::Type_testresultlist* vx_test::Type_testresultlist::vx_empty() {return vx_test::e_testresultlist;}
    vx_test::Type_testresultlist* vx_test::Type_testresultlist::vx_type() {return vx_test::t_testresultlist;}

    vx_core::Type_typedef* vx_test::Type_testresultlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_test::t_testresult), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * Constant: stylesheet-test
   * The default Test Stylesheet
   * {stylesheet}
   */
  //class Const_stylesheet_test {

    // vx_constdef()
    vx_core::Type_constdef* vx_test::Const_stylesheet_test::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_headchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        )
      );
    }

    // vx_const_new()
    vx_test::Const_stylesheet_test* vx_test::Const_stylesheet_test::vx_const_new() {
      vx_test::Const_stylesheet_test* output = new vx_test::Const_stylesheet_test();
      vx_web_html::Type_stylesheet* val = vx_web_html::f_stylesheet_loadmap(
        vx_core::f_new(
          vx_web_html::t_stylesheet,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":name"),
            vx_core::t_string->vx_new_from_string("Test Suite"),
            vx_core::t_string->vx_new_from_string(":styles"),
            vx_core::f_new(
              vx_web_html::t_stylelist,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("details summary"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("cursor"),
                        vx_core::t_string->vx_new_from_string("pointer"),
                        vx_core::t_string->vx_new_from_string("display"),
                        vx_core::t_string->vx_new_from_string("inline-flex"),
                        vx_core::t_string->vx_new_from_string("gap"),
                        vx_core::t_string->vx_new_from_string("10px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("table"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("vertical-align"),
                        vx_core::t_string->vx_new_from_string("top"),
                        vx_core::t_string->vx_new_from_string("border-collapse"),
                        vx_core::t_string->vx_new_from_string("collapse"),
                        vx_core::t_string->vx_new_from_string("margin"),
                        vx_core::t_string->vx_new_from_string("25px 0"),
                        vx_core::t_string->vx_new_from_string("font-size"),
                        vx_core::t_string->vx_new_from_string("0.9em"),
                        vx_core::t_string->vx_new_from_string("font-family"),
                        vx_core::t_string->vx_new_from_string("sans-serif"),
                        vx_core::t_string->vx_new_from_string("min-width"),
                        vx_core::t_string->vx_new_from_string("400px"),
                        vx_core::t_string->vx_new_from_string("box-shadow"),
                        vx_core::t_string->vx_new_from_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("thead tr"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("#009879"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("#ffffff"),
                        vx_core::t_string->vx_new_from_string("text-align"),
                        vx_core::t_string->vx_new_from_string("left")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("td"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("padding"),
                        vx_core::t_string->vx_new_from_string("10px 10px"),
                        vx_core::t_string->vx_new_from_string("vertical-align"),
                        vx_core::t_string->vx_new_from_string("top")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("tbody tr"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("border-bottom"),
                        vx_core::t_string->vx_new_from_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("tbody tr:nth-of-type(even)"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("#f3f3f3")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("tbody tr:last-of-type"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("border-bottom"),
                        vx_core::t_string->vx_new_from_string("2px solid #009879")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("tbody tr.active-row"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("font-weight"),
                        vx_core::t_string->vx_new_from_string("bold"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("#009879")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".failflag"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("red"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("white"),
                        vx_core::t_string->vx_new_from_string("padding-left"),
                        vx_core::t_string->vx_new_from_string("4px"),
                        vx_core::t_string->vx_new_from_string("padding-right"),
                        vx_core::t_string->vx_new_from_string("4px"),
                        vx_core::t_string->vx_new_from_string("padding-top"),
                        vx_core::t_string->vx_new_from_string("1px"),
                        vx_core::t_string->vx_new_from_string("padding-bottom"),
                        vx_core::t_string->vx_new_from_string("1px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".passflag"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("green"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("white"),
                        vx_core::t_string->vx_new_from_string("padding-left"),
                        vx_core::t_string->vx_new_from_string("4px"),
                        vx_core::t_string->vx_new_from_string("padding-right"),
                        vx_core::t_string->vx_new_from_string("4px"),
                        vx_core::t_string->vx_new_from_string("padding-top"),
                        vx_core::t_string->vx_new_from_string("1px"),
                        vx_core::t_string->vx_new_from_string("padding-bottom"),
                        vx_core::t_string->vx_new_from_string("1px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".coveragenums"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("width"),
                        vx_core::t_string->vx_new_from_string("90px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".coveragepct"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("text-align"),
                        vx_core::t_string->vx_new_from_string("right")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".coveragepctgreen"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("green"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("white"),
                        vx_core::t_string->vx_new_from_string("text-align"),
                        vx_core::t_string->vx_new_from_string("right")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".coveragepctred"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("background-color"),
                        vx_core::t_string->vx_new_from_string("red"),
                        vx_core::t_string->vx_new_from_string("color"),
                        vx_core::t_string->vx_new_from_string("white"),
                        vx_core::t_string->vx_new_from_string("text-align"),
                        vx_core::t_string->vx_new_from_string("right")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".pkgheader"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("display"),
                        vx_core::t_string->vx_new_from_string("inline-flex"),
                        vx_core::t_string->vx_new_from_string("gap"),
                        vx_core::t_string->vx_new_from_string("10px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".pkgname"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("font-weight"),
                        vx_core::t_string->vx_new_from_string("bold"),
                        vx_core::t_string->vx_new_from_string("width"),
                        vx_core::t_string->vx_new_from_string("180px")
                      )
                    )
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string(".preformatted"),
                    vx_core::t_string->vx_new_from_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::t_anylist->vx_new(
                        vx_core::t_string->vx_new_from_string("display"),
                        vx_core::t_string->vx_new_from_string("block"),
                        vx_core::t_string->vx_new_from_string("unicode-bidi"),
                        vx_core::t_string->vx_new_from_string("embed"),
                        vx_core::t_string->vx_new_from_string("font-family"),
                        vx_core::t_string->vx_new_from_string("monospace"),
                        vx_core::t_string->vx_new_from_string("white-space"),
                        vx_core::t_string->vx_new_from_string("pre")
                      )
                    )
                  )
                )
              )
            )
          )
        )
      );
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_name = val->name();
      output->vx_p_styles = val->styles();
      output->vx_p_stylemap = val->stylemap();
      return output;
    }


  //}

  extern vx_test::Const_stylesheet_test* vx_test::c_stylesheet_test = vx_test::Const_stylesheet_test::vx_const_new();

  /**
   * @function div_from_testcaselist
   * @param  {testcaselist} testcaselist
   * @return {div}
   * (func div<-testcaselist)
   */
  //class Func_div_from_testcaselist {

    template<typename... Args> vx_test::Func_div_from_testcaselist* vx_test::Func_div_from_testcaselist::vx_new(Args*... args) {
      vx_test::Func_div_from_testcaselist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_div_from_testcaselist* vx_test::Func_div_from_testcaselist::vx_copy(Args*... args) {
      vx_test::Func_div_from_testcaselist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_div_from_testcaselist::vx_typedef() {return vx_test::t_div_from_testcaselist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_div_from_testcaselist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_div_from_testcaselist* vx_test::Func_div_from_testcaselist::vx_empty() {return vx_test::e_div_from_testcaselist;}
    vx_test::Func_div_from_testcaselist* vx_test::Func_div_from_testcaselist::vx_type() {return vx_test::t_div_from_testcaselist;}

    vx_core::Func_any_from_any* vx_test::Func_div_from_testcaselist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_div_from_testcaselist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testcaselist* inputval = (vx_test::Type_testcaselist)value;
      vx_core::Type_any* outputval = vx_test::f_div_from_testcaselist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_div_from_testcaselist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testcaselist* testcaselist = vx_core::f_any_from_any(vx_test::t_testcaselist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_div_from_testcaselist(testcaselist);
      return output;
    }

    vx_web_html::Type_div* vx_test::Func_div_from_testcaselist::vx_div_from_testcaselist(vx_test::Type_testcaselist* testcaselist) {
      return vx_test::f_div_from_testcaselist(testcaselist);
    }

  //}

  vx_test::Func_div_from_testcaselist* vx_test::e_div_from_testcaselist = new vx_test::Func_div_from_testcaselist();
  vx_test::Func_div_from_testcaselist* vx_test::t_div_from_testcaselist = new vx_test::Func_div_from_testcaselist();

  vx_web_html::Type_div* vx_test::f_div_from_testcaselist(vx_test::Type_testcaselist* testcaselist) {
    vx_web_html::Type_div* output = vx_web_html::e_div;
    output = vx_core::f_new(
      vx_web_html::t_div,
      vx_core::t_anylist->vx_new(
        vx_core::f_new(
          vx_web_html::t_table,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":thead"),
            vx_core::f_new(
              vx_web_html::t_thead,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_tr,
                  vx_core::t_anylist->vx_new(
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::t_anylist->vx_new(
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::t_anylist->vx_new(
                            vx_core::t_string->vx_new_from_string(":text"),
                            vx_core::t_string->vx_new_from_string("Pass?")
                          )
                        )
                      )
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::t_anylist->vx_new(
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::t_anylist->vx_new(
                            vx_core::t_string->vx_new_from_string(":text"),
                            vx_core::t_string->vx_new_from_string("Name")
                          )
                        )
                      )
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::t_anylist->vx_new(
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::t_anylist->vx_new(
                            vx_core::t_string->vx_new_from_string(":text"),
                            vx_core::t_string->vx_new_from_string("Test")
                          )
                        )
                      )
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::t_anylist->vx_new(
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::t_anylist->vx_new(
                            vx_core::t_string->vx_new_from_string(":text"),
                            vx_core::t_string->vx_new_from_string("Expected")
                          )
                        )
                      )
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::t_anylist->vx_new(
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::t_anylist->vx_new(
                            vx_core::t_string->vx_new_from_string(":text"),
                            vx_core::t_string->vx_new_from_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            vx_core::t_string->vx_new_from_string(":tbody"),
            vx_core::f_new(
              vx_web_html::t_tbody,
              vx_core::t_anylist->vx_new(
                vx_test::f_trlist_from_testcaselist(testcaselist)
              )
            )
          )
        )
      )
    );
    return output;
  }

  /**
   * @function div_from_testpackage
   * Retuns a div from a test package
   * @param  {testpackage} testpackage
   * @return {div}
   * (func div<-testpackage)
   */
  //class Func_div_from_testpackage {

    template<typename... Args> vx_test::Func_div_from_testpackage* vx_test::Func_div_from_testpackage::vx_new(Args*... args) {
      vx_test::Func_div_from_testpackage* output;
      return output;
    }

    template<typename... Args> vx_test::Func_div_from_testpackage* vx_test::Func_div_from_testpackage::vx_copy(Args*... args) {
      vx_test::Func_div_from_testpackage* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_div_from_testpackage::vx_typedef() {return vx_test::t_div_from_testpackage->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_div_from_testpackage::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_div_from_testpackage* vx_test::Func_div_from_testpackage::vx_empty() {return vx_test::e_div_from_testpackage;}
    vx_test::Func_div_from_testpackage* vx_test::Func_div_from_testpackage::vx_type() {return vx_test::t_div_from_testpackage;}

    vx_core::Func_any_from_any* vx_test::Func_div_from_testpackage::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_div_from_testpackage::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testpackage* inputval = (vx_test::Type_testpackage)value;
      vx_core::Type_any* outputval = vx_test::f_div_from_testpackage(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_div_from_testpackage::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testpackage* testpackage = vx_core::f_any_from_any(vx_test::t_testpackage, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_div_from_testpackage(testpackage);
      return output;
    }

    vx_web_html::Type_div* vx_test::Func_div_from_testpackage::vx_div_from_testpackage(vx_test::Type_testpackage* testpackage) {
      return vx_test::f_div_from_testpackage(testpackage);
    }

  //}

  vx_test::Func_div_from_testpackage* vx_test::e_div_from_testpackage = new vx_test::Func_div_from_testpackage();
  vx_test::Func_div_from_testpackage* vx_test::t_div_from_testpackage = new vx_test::Func_div_from_testpackage();

  vx_web_html::Type_div* vx_test::f_div_from_testpackage(vx_test::Type_testpackage* testpackage) {
    vx_web_html::Type_div* output = vx_web_html::e_div;
    output = vx_core::f_let(
      vx_web_html::t_div,
      vx_core::t_any_from_func->fn_new([testpackage]() {
        vx_test::Type_testcoveragesummary* testcoveragesummary = testpackage->coveragesummary();
        vx_core::Type_string* pkgname = testpackage->testpkg();
        vx_test::Type_testcaselist* caselist = testpackage->caselist();
        vx_core::Type_boolean* passfail = testpackage->passfail();
        vx_web_html::Type_style* pkgnamestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".pkgname")
        );
        vx_web_html::Type_div* node = vx_test::f_div_from_testcaselist(caselist);
        vx_web_html::Type_divchildlist* nodes = vx_core::f_new(
          vx_web_html::t_divchildlist,
          vx_core::t_anylist->vx_new(
            node
          )
        );
        vx_web_html::Type_p* p_passfail = vx_test::f_p_from_passfail(passfail);
        vx_web_html::Type_p* p_pkgname = vx_core::f_new(
          vx_web_html::t_p,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":style"),
            pkgnamestyle,
            vx_core::t_string->vx_new_from_string(":text"),
            pkgname
          )
        );
        vx_web_html::Type_p* p_totalnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->totalnums()
        );
        vx_web_html::Type_p* p_coveragenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->typenums()
        );
        vx_web_html::Type_p* p_constnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->constnums()
        );
        vx_web_html::Type_p* p_funcnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->funcnums()
        );
        vx_web_html::Type_p* p_docnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->docnums()
        );
        vx_web_html::Type_p* p_bigospacenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigospacenums()
        );
        vx_web_html::Type_p* p_bigotimenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigotimenums()
        );
        vx_web_html::Type_divchildlist* summary = vx_core::f_new(
          vx_web_html::t_divchildlist,
          vx_core::t_anylist->vx_new(
            p_passfail,
            p_pkgname,
            p_totalnums,
            p_coveragenums,
            p_constnums,
            p_funcnums,
            p_docnums,
            p_bigospacenums,
            p_bigotimenums
          )
        );
        vx_web_html::Type_details* details = vx_core::f_new(
          vx_web_html::t_details,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":summary"),
            summary,
            vx_core::t_string->vx_new_from_string(":nodes"),
            nodes
          )
        );
        return vx_core::f_new(
          vx_web_html::t_div,
          vx_core::t_anylist->vx_new(
            details
          )
        );
      })
    );
    return output;
  }

  /**
   * @function div_from_testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {div}
   * (func div<-testpackagelist)
   */
  //class Func_div_from_testpackagelist {

    template<typename... Args> vx_test::Func_div_from_testpackagelist* vx_test::Func_div_from_testpackagelist::vx_new(Args*... args) {
      vx_test::Func_div_from_testpackagelist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_div_from_testpackagelist* vx_test::Func_div_from_testpackagelist::vx_copy(Args*... args) {
      vx_test::Func_div_from_testpackagelist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_div_from_testpackagelist::vx_typedef() {return vx_test::t_div_from_testpackagelist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_div_from_testpackagelist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_div_from_testpackagelist* vx_test::Func_div_from_testpackagelist::vx_empty() {return vx_test::e_div_from_testpackagelist;}
    vx_test::Func_div_from_testpackagelist* vx_test::Func_div_from_testpackagelist::vx_type() {return vx_test::t_div_from_testpackagelist;}

    vx_core::Func_any_from_any* vx_test::Func_div_from_testpackagelist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_div_from_testpackagelist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testpackagelist* inputval = (vx_test::Type_testpackagelist)value;
      vx_core::Type_any* outputval = vx_test::f_div_from_testpackagelist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_div_from_testpackagelist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testpackagelist* testpackagelist = vx_core::f_any_from_any(vx_test::t_testpackagelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_div_from_testpackagelist(testpackagelist);
      return output;
    }

    vx_web_html::Type_div* vx_test::Func_div_from_testpackagelist::vx_div_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
      return vx_test::f_div_from_testpackagelist(testpackagelist);
    }

  //}

  vx_test::Func_div_from_testpackagelist* vx_test::e_div_from_testpackagelist = new vx_test::Func_div_from_testpackagelist();
  vx_test::Func_div_from_testpackagelist* vx_test::t_div_from_testpackagelist = new vx_test::Func_div_from_testpackagelist();

  vx_web_html::Type_div* vx_test::f_div_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
    vx_web_html::Type_div* output = vx_web_html::e_div;
    output = vx_core::f_let(
      vx_web_html::t_div,
      vx_core::t_any_from_func->fn_new([testpackagelist]() {
        vx_web_html::Type_style* stylepassfail = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".passfail")
        );
        vx_web_html::Type_style* stylepkgname = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".pkgname")
        );
        vx_web_html::Type_style* stylepkgheader = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".pkgheader")
        );
        vx_web_html::Type_style* stylecoveragenum = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".coveragenums")
        );
        return vx_core::f_new(
          vx_web_html::t_div,
          vx_core::t_anylist->vx_new(
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::t_anylist->vx_new(
                vx_core::t_string->vx_new_from_string(":style"),
                stylepkgheader,
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylepassfail,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("Pass?")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylepkgname,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("Package Name")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("Coverage")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("(type)")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("(const)")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("(func)")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string(":doc")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string(":bigospace")
                  )
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    stylecoveragenum,
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string(":bigotime")
                  )
                )
              )
            ),
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::t_anylist->vx_new(
                vx_test::f_divchildlist_from_testpackagelist(testpackagelist)
              )
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_testpackagelist
   * Returns a divlist from a testpackagelist.
   * @param  {testpackagelist} testpackagelist
   * @return {divchildlist}
   * (func divchildlist<-testpackagelist)
   */
  //class Func_divchildlist_from_testpackagelist {

    template<typename... Args> vx_test::Func_divchildlist_from_testpackagelist* vx_test::Func_divchildlist_from_testpackagelist::vx_new(Args*... args) {
      vx_test::Func_divchildlist_from_testpackagelist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_divchildlist_from_testpackagelist* vx_test::Func_divchildlist_from_testpackagelist::vx_copy(Args*... args) {
      vx_test::Func_divchildlist_from_testpackagelist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_divchildlist_from_testpackagelist::vx_typedef() {return vx_test::t_divchildlist_from_testpackagelist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_divchildlist_from_testpackagelist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_divchild), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_divchildlist_from_testpackagelist* vx_test::Func_divchildlist_from_testpackagelist::vx_empty() {return vx_test::e_divchildlist_from_testpackagelist;}
    vx_test::Func_divchildlist_from_testpackagelist* vx_test::Func_divchildlist_from_testpackagelist::vx_type() {return vx_test::t_divchildlist_from_testpackagelist;}

    vx_core::Func_any_from_any* vx_test::Func_divchildlist_from_testpackagelist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_divchildlist_from_testpackagelist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testpackagelist* inputval = (vx_test::Type_testpackagelist)value;
      vx_core::Type_any* outputval = vx_test::f_divchildlist_from_testpackagelist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_divchildlist_from_testpackagelist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testpackagelist* testpackagelist = vx_core::f_any_from_any(vx_test::t_testpackagelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

    vx_web_html::Type_divchildlist* vx_test::Func_divchildlist_from_testpackagelist::vx_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
      return vx_test::f_divchildlist_from_testpackagelist(testpackagelist);
    }

  //}

  vx_test::Func_divchildlist_from_testpackagelist* vx_test::e_divchildlist_from_testpackagelist = new vx_test::Func_divchildlist_from_testpackagelist();
  vx_test::Func_divchildlist_from_testpackagelist* vx_test::t_divchildlist_from_testpackagelist = new vx_test::Func_divchildlist_from_testpackagelist();

  vx_web_html::Type_divchildlist* vx_test::f_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
    vx_web_html::Type_divchildlist* output = vx_web_html::e_divchildlist;
    output = vx_core::f_list_from_list(
      vx_web_html::t_divchildlist,
      testpackagelist,
      vx_test::t_div_from_testpackage
    );
    return output;
  }

  /**
   * @function file_test
   * Default file location for testsuite.vxlisp
   * @return {file}
   * (func file-test)
   */
  //class Func_file_test {

    template<typename... Args> vx_test::Func_file_test* vx_test::Func_file_test::vx_new(Args*... args) {
      vx_test::Func_file_test* output;
      return output;
    }

    template<typename... Args> vx_test::Func_file_test* vx_test::Func_file_test::vx_copy(Args*... args) {
      vx_test::Func_file_test* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_file_test::vx_typedef() {return vx_test::t_file_test->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_file_test::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_file_test* vx_test::Func_file_test::vx_empty() {return vx_test::e_file_test;}
    vx_test::Func_file_test* vx_test::Func_file_test::vx_type() {return vx_test::t_file_test;}

    vx_core::Type_any* vx_test::Func_file_test::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      output = vx_test::f_file_test();
      return output;
    }

    vx_data_file::Type_file* vx_test::Func_file_test::vx_file_test() {
      return vx_test::f_file_test();
    }

  //}

  vx_test::Func_file_test* vx_test::e_file_test = new vx_test::Func_file_test();
  vx_test::Func_file_test* vx_test::t_file_test = new vx_test::Func_file_test();

  vx_data_file::Type_file* vx_test::f_file_test() {
    vx_data_file::Type_file* output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":name"),
        vx_core::t_string->vx_new_from_string("testsuite.vxlisp"),
        vx_core::t_string->vx_new_from_string(":path"),
        vx_core::t_string->vx_new_from_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function file_testhtml
   * Default file location for testsuite.html
   * @return {file}
   * (func file-testhtml)
   */
  //class Func_file_testhtml {

    template<typename... Args> vx_test::Func_file_testhtml* vx_test::Func_file_testhtml::vx_new(Args*... args) {
      vx_test::Func_file_testhtml* output;
      return output;
    }

    template<typename... Args> vx_test::Func_file_testhtml* vx_test::Func_file_testhtml::vx_copy(Args*... args) {
      vx_test::Func_file_testhtml* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_file_testhtml::vx_typedef() {return vx_test::t_file_testhtml->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_file_testhtml::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_file_testhtml* vx_test::Func_file_testhtml::vx_empty() {return vx_test::e_file_testhtml;}
    vx_test::Func_file_testhtml* vx_test::Func_file_testhtml::vx_type() {return vx_test::t_file_testhtml;}

    vx_core::Type_any* vx_test::Func_file_testhtml::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      output = vx_test::f_file_testhtml();
      return output;
    }

    vx_data_file::Type_file* vx_test::Func_file_testhtml::vx_file_testhtml() {
      return vx_test::f_file_testhtml();
    }

  //}

  vx_test::Func_file_testhtml* vx_test::e_file_testhtml = new vx_test::Func_file_testhtml();
  vx_test::Func_file_testhtml* vx_test::t_file_testhtml = new vx_test::Func_file_testhtml();

  vx_data_file::Type_file* vx_test::f_file_testhtml() {
    vx_data_file::Type_file* output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":name"),
        vx_core::t_string->vx_new_from_string("testsuite.html"),
        vx_core::t_string->vx_new_from_string(":path"),
        vx_core::t_string->vx_new_from_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function file_testnode
   * Default file location for testsuitenode.vxlisp
   * @return {file}
   * (func file-testnode)
   */
  //class Func_file_testnode {

    template<typename... Args> vx_test::Func_file_testnode* vx_test::Func_file_testnode::vx_new(Args*... args) {
      vx_test::Func_file_testnode* output;
      return output;
    }

    template<typename... Args> vx_test::Func_file_testnode* vx_test::Func_file_testnode::vx_copy(Args*... args) {
      vx_test::Func_file_testnode* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_file_testnode::vx_typedef() {return vx_test::t_file_testnode->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_file_testnode::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_file_testnode* vx_test::Func_file_testnode::vx_empty() {return vx_test::e_file_testnode;}
    vx_test::Func_file_testnode* vx_test::Func_file_testnode::vx_type() {return vx_test::t_file_testnode;}

    vx_core::Type_any* vx_test::Func_file_testnode::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      output = vx_test::f_file_testnode();
      return output;
    }

    vx_data_file::Type_file* vx_test::Func_file_testnode::vx_file_testnode() {
      return vx_test::f_file_testnode();
    }

  //}

  vx_test::Func_file_testnode* vx_test::e_file_testnode = new vx_test::Func_file_testnode();
  vx_test::Func_file_testnode* vx_test::t_file_testnode = new vx_test::Func_file_testnode();

  vx_data_file::Type_file* vx_test::f_file_testnode() {
    vx_data_file::Type_file* output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":name"),
        vx_core::t_string->vx_new_from_string("testsuitenode.vxlisp"),
        vx_core::t_string->vx_new_from_string(":path"),
        vx_core::t_string->vx_new_from_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function html_from_divtest
   * Returns html from test div
   * @param  {div} divtest
   * @return {html}
   * (func html<-divtest)
   */
  //class Func_html_from_divtest {

    template<typename... Args> vx_test::Func_html_from_divtest* vx_test::Func_html_from_divtest::vx_new(Args*... args) {
      vx_test::Func_html_from_divtest* output;
      return output;
    }

    template<typename... Args> vx_test::Func_html_from_divtest* vx_test::Func_html_from_divtest::vx_copy(Args*... args) {
      vx_test::Func_html_from_divtest* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_html_from_divtest::vx_typedef() {return vx_test::t_html_from_divtest->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_html_from_divtest::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "html", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_html_from_divtest* vx_test::Func_html_from_divtest::vx_empty() {return vx_test::e_html_from_divtest;}
    vx_test::Func_html_from_divtest* vx_test::Func_html_from_divtest::vx_type() {return vx_test::t_html_from_divtest;}

    vx_core::Func_any_from_any* vx_test::Func_html_from_divtest::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_html_from_divtest::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_div* inputval = (vx_web_html::Type_div)value;
      vx_core::Type_any* outputval = vx_test::f_html_from_divtest(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_html_from_divtest::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_div* divtest = vx_core::f_any_from_any(vx_web_html::t_div, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_html_from_divtest(divtest);
      return output;
    }

    vx_web_html::Type_html* vx_test::Func_html_from_divtest::vx_html_from_divtest(vx_web_html::Type_div* divtest) {
      return vx_test::f_html_from_divtest(divtest);
    }

  //}

  vx_test::Func_html_from_divtest* vx_test::e_html_from_divtest = new vx_test::Func_html_from_divtest();
  vx_test::Func_html_from_divtest* vx_test::t_html_from_divtest = new vx_test::Func_html_from_divtest();

  vx_web_html::Type_html* vx_test::f_html_from_divtest(vx_web_html::Type_div* divtest) {
    vx_web_html::Type_html* output = vx_web_html::e_html;
    output = vx_core::f_new(
      vx_web_html::t_html,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":lang"),
        vx_core::t_string->vx_new_from_string("en"),
        vx_core::t_string->vx_new_from_string(":head"),
        vx_core::f_new(
          vx_web_html::t_head,
          vx_core::t_anylist->vx_new(
            vx_core::f_new(
              vx_web_html::t_meta,
              vx_core::t_anylist->vx_new(
                vx_core::t_string->vx_new_from_string(":charset"),
                vx_core::t_string->vx_new_from_string("utf-8")
              )
            ),
            vx_core::f_new(
              vx_web_html::t_title,
              vx_core::t_anylist->vx_new(
                vx_core::t_string->vx_new_from_string(":text"),
                vx_core::t_string->vx_new_from_string("Test Suite")
              )
            ),
            vx_test::c_stylesheet_test
          )
        ),
        vx_core::t_string->vx_new_from_string(":body"),
        vx_core::f_new(
          vx_web_html::t_body,
          vx_core::t_anylist->vx_new(
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_h1,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string("Test Suite")
                  )
                )
              )
            ),
            divtest
          )
        )
      )
    );
    return output;
  }

  /**
   * @function p_from_passfail
   * Returns a <p> tag from a passfail boolean value
   * @param  {boolean} passfail
   * @return {p}
   * (func p<-passfail)
   */
  //class Func_p_from_passfail {

    template<typename... Args> vx_test::Func_p_from_passfail* vx_test::Func_p_from_passfail::vx_new(Args*... args) {
      vx_test::Func_p_from_passfail* output;
      return output;
    }

    template<typename... Args> vx_test::Func_p_from_passfail* vx_test::Func_p_from_passfail::vx_copy(Args*... args) {
      vx_test::Func_p_from_passfail* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_p_from_passfail::vx_typedef() {return vx_test::t_p_from_passfail->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_p_from_passfail::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_p_from_passfail* vx_test::Func_p_from_passfail::vx_empty() {return vx_test::e_p_from_passfail;}
    vx_test::Func_p_from_passfail* vx_test::Func_p_from_passfail::vx_type() {return vx_test::t_p_from_passfail;}

    vx_core::Func_any_from_any* vx_test::Func_p_from_passfail::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_p_from_passfail::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_boolean* inputval = (vx_core::Type_boolean)value;
      vx_core::Type_any* outputval = vx_test::f_p_from_passfail(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_p_from_passfail::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_boolean* passfail = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_p_from_passfail(passfail);
      return output;
    }

    vx_web_html::Type_p* vx_test::Func_p_from_passfail::vx_p_from_passfail(vx_core::Type_boolean* passfail) {
      return vx_test::f_p_from_passfail(passfail);
    }

  //}

  vx_test::Func_p_from_passfail* vx_test::e_p_from_passfail = new vx_test::Func_p_from_passfail();
  vx_test::Func_p_from_passfail* vx_test::t_p_from_passfail = new vx_test::Func_p_from_passfail();

  vx_web_html::Type_p* vx_test::f_p_from_passfail(vx_core::Type_boolean* passfail) {
    vx_web_html::Type_p* output = vx_web_html::e_p;
    output = vx_core::f_let(
      vx_web_html::t_p,
      vx_core::t_any_from_func->fn_new([passfail]() {
        vx_core::Type_string* text = vx_core::f_if_1(vx_core::t_string, passfail, vx_core::t_string->vx_new_from_string("Pass"), vx_core::t_string->vx_new_from_string("Fail"));
        vx_core::Type_string* stylename = vx_core::f_if_1(vx_core::t_string, passfail, vx_core::t_string->vx_new_from_string(".passflag"), vx_core::t_string->vx_new_from_string(".failflag"));
        vx_web_html::Type_style* style = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          stylename
        );
        return vx_core::f_new(
          vx_web_html::t_p,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":style"),
            style,
            vx_core::t_string->vx_new_from_string(":text"),
            text
          )
        );
      })
    );
    return output;
  }

  /**
   * @function p_from_testcoveragenums
   * Returns <p>tests / total (pct%)</p> from testcoveragenums
   * @param  {testcoveragenums} nums
   * @return {p}
   * (func p<-testcoveragenums)
   */
  //class Func_p_from_testcoveragenums {

    template<typename... Args> vx_test::Func_p_from_testcoveragenums* vx_test::Func_p_from_testcoveragenums::vx_new(Args*... args) {
      vx_test::Func_p_from_testcoveragenums* output;
      return output;
    }

    template<typename... Args> vx_test::Func_p_from_testcoveragenums* vx_test::Func_p_from_testcoveragenums::vx_copy(Args*... args) {
      vx_test::Func_p_from_testcoveragenums* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_p_from_testcoveragenums::vx_typedef() {return vx_test::t_p_from_testcoveragenums->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_p_from_testcoveragenums::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_p_from_testcoveragenums* vx_test::Func_p_from_testcoveragenums::vx_empty() {return vx_test::e_p_from_testcoveragenums;}
    vx_test::Func_p_from_testcoveragenums* vx_test::Func_p_from_testcoveragenums::vx_type() {return vx_test::t_p_from_testcoveragenums;}

    vx_core::Func_any_from_any* vx_test::Func_p_from_testcoveragenums::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_p_from_testcoveragenums::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testcoveragenums* inputval = (vx_test::Type_testcoveragenums)value;
      vx_core::Type_any* outputval = vx_test::f_p_from_testcoveragenums(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_p_from_testcoveragenums::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testcoveragenums* nums = vx_core::f_any_from_any(vx_test::t_testcoveragenums, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_p_from_testcoveragenums(nums);
      return output;
    }

    vx_web_html::Type_p* vx_test::Func_p_from_testcoveragenums::vx_p_from_testcoveragenums(vx_test::Type_testcoveragenums* nums) {
      return vx_test::f_p_from_testcoveragenums(nums);
    }

  //}

  vx_test::Func_p_from_testcoveragenums* vx_test::e_p_from_testcoveragenums = new vx_test::Func_p_from_testcoveragenums();
  vx_test::Func_p_from_testcoveragenums* vx_test::t_p_from_testcoveragenums = new vx_test::Func_p_from_testcoveragenums();

  vx_web_html::Type_p* vx_test::f_p_from_testcoveragenums(vx_test::Type_testcoveragenums* nums) {
    vx_web_html::Type_p* output = vx_web_html::e_p;
    output = vx_core::f_new(
      vx_web_html::t_p,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":style"),
        vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".coveragenums")
        ),
        vx_core::t_string->vx_new_from_string(":text"),
        vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            nums->pct(),
            vx_core::t_string->vx_new_from_string("% "),
            nums->tests(),
            vx_core::t_string->vx_new_from_string("/"),
            nums->total()
          )
        )
      )
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testcase
   * Resolves a testcase
   * @param  {testcase} testcase
   * @return {testcase}
   * (func resolve-testcase)
   */
  //class Func_resolve_testcase {

    template<typename... Args> vx_test::Func_resolve_testcase* vx_test::Func_resolve_testcase::vx_new(Args*... args) {
      vx_test::Func_resolve_testcase* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testcase* vx_test::Func_resolve_testcase::vx_copy(Args*... args) {
      vx_test::Func_resolve_testcase* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testcase::vx_typedef() {return vx_test::t_resolve_testcase->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testcase::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testcase", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testcase* vx_test::Func_resolve_testcase::vx_empty() {return vx_test::e_resolve_testcase;}
    vx_test::Func_resolve_testcase* vx_test::Func_resolve_testcase::vx_type() {return vx_test::t_resolve_testcase;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testcase::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testcase::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testcase* inputval = vx_core::f_any_from_any(vx_test::t_testcase, value);
      vx_core::Async<vx_test::Type_testcase*>* future = vx_test::f_resolve_testcase(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testcase::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testcase* testcase = vx_core::f_any_from_any(vx_test::t_testcase, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testcase*>* future = vx_test::f_resolve_testcase(testcase);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testcase*>* vx_test::Func_resolve_testcase::vx_resolve_testcase(vx_test::Type_testcase* testcase) {
      return vx_test::f_resolve_testcase(testcase);
    }

  //}

  vx_test::Func_resolve_testcase* vx_test::e_resolve_testcase = new vx_test::Func_resolve_testcase();
  vx_test::Func_resolve_testcase* vx_test::t_resolve_testcase = new vx_test::Func_resolve_testcase();

  vx_core::Async<vx_test::Type_testcase*>* vx_test::f_resolve_testcase(vx_test::Type_testcase* testcase) {
    vx_core::Async<vx_test::Type_testcase*>* output = vx_core::async_new_from_val(vx_test::e_testcase);
    vx_core::f_let_async(
      vx_test::t_testcase,
      vx_core::t_any_from_func_async->fn_new([testcase]() {
        vx_test::Type_testdescribelist* describelist = testcase->describelist();
        vx_core::Async<vx_test::Type_testdescribelist*>* future_resolvedlist = vx_test::f_resolve_testdescribelist(describelist);
        vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, vx_test::Type_testdescribelist*>(vx_core::t_any, future_resolvedlist, [testcase](vx_test::Type_testdescribelist* resolvedlist) {
          vx_core::Type_booleanlist* passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist,
            resolvedlist,
            vx_core::t_any_from_any->fn_new([](vx_core::Type_any* testdescribe_any) {
              vx_test::Type_testdescribe* testdescribe = vx_core::f_any_from_any(vx_test::t_testdescribe, testdescribe_any);
              return 
                vx_core::f_let(
                  vx_core::t_boolean,
                  vx_core::t_any_from_func->fn_new([testdescribe]() {
                    vx_test::Type_testresult* testresult = testdescribe->testresult();
                    return testresult->passfail();
                  })
                );
            })
          );
          vx_core::Type_boolean* passfail = vx_core::f_and_1(passfaillist);
          return vx_core::f_copy(
            testcase,
            vx_core::t_anylist->vx_new(
              vx_core::t_string->vx_new_from_string(":passfail"),
              passfail,
              vx_core::t_string->vx_new_from_string(":describelist"),
              resolvedlist
            )
          );
        });
        return output;
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testcaselist
   * Resolves a testcaselist
   * @param  {testcaselist} testcaselist
   * @return {testcaselist}
   * (func resolve-testcaselist)
   */
  //class Func_resolve_testcaselist {

    template<typename... Args> vx_test::Func_resolve_testcaselist* vx_test::Func_resolve_testcaselist::vx_new(Args*... args) {
      vx_test::Func_resolve_testcaselist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testcaselist* vx_test::Func_resolve_testcaselist::vx_copy(Args*... args) {
      vx_test::Func_resolve_testcaselist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testcaselist::vx_typedef() {return vx_test::t_resolve_testcaselist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testcaselist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testcaselist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_test::t_testcase), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testcaselist* vx_test::Func_resolve_testcaselist::vx_empty() {return vx_test::e_resolve_testcaselist;}
    vx_test::Func_resolve_testcaselist* vx_test::Func_resolve_testcaselist::vx_type() {return vx_test::t_resolve_testcaselist;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testcaselist::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testcaselist::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testcaselist* inputval = vx_core::f_any_from_any(vx_test::t_testcaselist, value);
      vx_core::Async<vx_test::Type_testcaselist*>* future = vx_test::f_resolve_testcaselist(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testcaselist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testcaselist* testcaselist = vx_core::f_any_from_any(vx_test::t_testcaselist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testcaselist*>* future = vx_test::f_resolve_testcaselist(testcaselist);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testcaselist*>* vx_test::Func_resolve_testcaselist::vx_resolve_testcaselist(vx_test::Type_testcaselist* testcaselist) {
      return vx_test::f_resolve_testcaselist(testcaselist);
    }

  //}

  vx_test::Func_resolve_testcaselist* vx_test::e_resolve_testcaselist = new vx_test::Func_resolve_testcaselist();
  vx_test::Func_resolve_testcaselist* vx_test::t_resolve_testcaselist = new vx_test::Func_resolve_testcaselist();

  vx_core::Async<vx_test::Type_testcaselist*>* vx_test::f_resolve_testcaselist(vx_test::Type_testcaselist* testcaselist) {
    vx_core::Async<vx_test::Type_testcaselist*>* output = vx_core::async_new_from_val(vx_test::e_testcaselist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testcaselist,
      testcaselist,
      vx_test::t_resolve_testcase
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testdescribe
   * Resolves a testdescribe
   * @param  {testdescribe} testdescribe
   * @return {testdescribe}
   * (func resolve-testdescribe)
   */
  //class Func_resolve_testdescribe {

    template<typename... Args> vx_test::Func_resolve_testdescribe* vx_test::Func_resolve_testdescribe::vx_new(Args*... args) {
      vx_test::Func_resolve_testdescribe* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testdescribe* vx_test::Func_resolve_testdescribe::vx_copy(Args*... args) {
      vx_test::Func_resolve_testdescribe* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testdescribe::vx_typedef() {return vx_test::t_resolve_testdescribe->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testdescribe::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testdescribe", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testdescribe* vx_test::Func_resolve_testdescribe::vx_empty() {return vx_test::e_resolve_testdescribe;}
    vx_test::Func_resolve_testdescribe* vx_test::Func_resolve_testdescribe::vx_type() {return vx_test::t_resolve_testdescribe;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testdescribe::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testdescribe::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testdescribe* inputval = vx_core::f_any_from_any(vx_test::t_testdescribe, value);
      vx_core::Async<vx_test::Type_testdescribe*>* future = vx_test::f_resolve_testdescribe(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testdescribe::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testdescribe* testdescribe = vx_core::f_any_from_any(vx_test::t_testdescribe, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testdescribe*>* future = vx_test::f_resolve_testdescribe(testdescribe);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testdescribe*>* vx_test::Func_resolve_testdescribe::vx_resolve_testdescribe(vx_test::Type_testdescribe* testdescribe) {
      return vx_test::f_resolve_testdescribe(testdescribe);
    }

  //}

  vx_test::Func_resolve_testdescribe* vx_test::e_resolve_testdescribe = new vx_test::Func_resolve_testdescribe();
  vx_test::Func_resolve_testdescribe* vx_test::t_resolve_testdescribe = new vx_test::Func_resolve_testdescribe();

  vx_core::Async<vx_test::Type_testdescribe*>* vx_test::f_resolve_testdescribe(vx_test::Type_testdescribe* testdescribe) {
    vx_core::Async<vx_test::Type_testdescribe*>* output = vx_core::async_new_from_val(vx_test::e_testdescribe);
    vx_core::f_let_async(
      vx_test::t_testdescribe,
      vx_core::t_any_from_func_async->fn_new([testdescribe]() {
        vx_test::Type_testresult* testresult = testdescribe->testresult();
        vx_core::Async<vx_test::Type_testresult*>* future_resolved = vx_test::f_resolve_testresult(testresult);
        vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, vx_test::Type_testresult*>(vx_core::t_any, future_resolved, [testdescribe](vx_test::Type_testresult* resolved) {
          return vx_core::f_copy(
            testdescribe,
            vx_core::t_anylist->vx_new(
              vx_core::t_string->vx_new_from_string(":testresult"),
              resolved
            )
          );
        });
        return output;
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testdescribelist
   * Resolves a testdescribelist
   * @param  {testdescribelist} testdescribelist
   * @return {testdescribelist}
   * (func resolve-testdescribelist)
   */
  //class Func_resolve_testdescribelist {

    template<typename... Args> vx_test::Func_resolve_testdescribelist* vx_test::Func_resolve_testdescribelist::vx_new(Args*... args) {
      vx_test::Func_resolve_testdescribelist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testdescribelist* vx_test::Func_resolve_testdescribelist::vx_copy(Args*... args) {
      vx_test::Func_resolve_testdescribelist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testdescribelist::vx_typedef() {return vx_test::t_resolve_testdescribelist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testdescribelist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testdescribelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_test::t_testdescribe), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testdescribelist* vx_test::Func_resolve_testdescribelist::vx_empty() {return vx_test::e_resolve_testdescribelist;}
    vx_test::Func_resolve_testdescribelist* vx_test::Func_resolve_testdescribelist::vx_type() {return vx_test::t_resolve_testdescribelist;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testdescribelist::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testdescribelist::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testdescribelist* inputval = vx_core::f_any_from_any(vx_test::t_testdescribelist, value);
      vx_core::Async<vx_test::Type_testdescribelist*>* future = vx_test::f_resolve_testdescribelist(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testdescribelist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testdescribelist* testdescribelist = vx_core::f_any_from_any(vx_test::t_testdescribelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testdescribelist*>* future = vx_test::f_resolve_testdescribelist(testdescribelist);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testdescribelist*>* vx_test::Func_resolve_testdescribelist::vx_resolve_testdescribelist(vx_test::Type_testdescribelist* testdescribelist) {
      return vx_test::f_resolve_testdescribelist(testdescribelist);
    }

  //}

  vx_test::Func_resolve_testdescribelist* vx_test::e_resolve_testdescribelist = new vx_test::Func_resolve_testdescribelist();
  vx_test::Func_resolve_testdescribelist* vx_test::t_resolve_testdescribelist = new vx_test::Func_resolve_testdescribelist();

  vx_core::Async<vx_test::Type_testdescribelist*>* vx_test::f_resolve_testdescribelist(vx_test::Type_testdescribelist* testdescribelist) {
    vx_core::Async<vx_test::Type_testdescribelist*>* output = vx_core::async_new_from_val(vx_test::e_testdescribelist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testdescribelist,
      testdescribelist,
      vx_test::t_resolve_testdescribe
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testpackage
   * Resolves a testpackage
   * @param  {testpackage} testpackage
   * @return {testpackage}
   * (func resolve-testpackage)
   */
  //class Func_resolve_testpackage {

    template<typename... Args> vx_test::Func_resolve_testpackage* vx_test::Func_resolve_testpackage::vx_new(Args*... args) {
      vx_test::Func_resolve_testpackage* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testpackage* vx_test::Func_resolve_testpackage::vx_copy(Args*... args) {
      vx_test::Func_resolve_testpackage* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testpackage::vx_typedef() {return vx_test::t_resolve_testpackage->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testpackage::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testpackage", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testpackage* vx_test::Func_resolve_testpackage::vx_empty() {return vx_test::e_resolve_testpackage;}
    vx_test::Func_resolve_testpackage* vx_test::Func_resolve_testpackage::vx_type() {return vx_test::t_resolve_testpackage;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testpackage::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testpackage::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testpackage* inputval = vx_core::f_any_from_any(vx_test::t_testpackage, value);
      vx_core::Async<vx_test::Type_testpackage*>* future = vx_test::f_resolve_testpackage(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testpackage::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testpackage* testpackage = vx_core::f_any_from_any(vx_test::t_testpackage, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testpackage*>* future = vx_test::f_resolve_testpackage(testpackage);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testpackage*>* vx_test::Func_resolve_testpackage::vx_resolve_testpackage(vx_test::Type_testpackage* testpackage) {
      return vx_test::f_resolve_testpackage(testpackage);
    }

  //}

  vx_test::Func_resolve_testpackage* vx_test::e_resolve_testpackage = new vx_test::Func_resolve_testpackage();
  vx_test::Func_resolve_testpackage* vx_test::t_resolve_testpackage = new vx_test::Func_resolve_testpackage();

  vx_core::Async<vx_test::Type_testpackage*>* vx_test::f_resolve_testpackage(vx_test::Type_testpackage* testpackage) {
    vx_core::Async<vx_test::Type_testpackage*>* output = vx_core::async_new_from_val(vx_test::e_testpackage);
    vx_core::f_let_async(
      vx_test::t_testpackage,
      vx_core::t_any_from_func_async->fn_new([testpackage]() {
        vx_test::Type_testcaselist* testcaselist = testpackage->caselist();
        vx_core::Async<vx_test::Type_testcaselist*>* future_resolvedlist = vx_test::f_resolve_testcaselist(testcaselist);
        vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, vx_test::Type_testcaselist*>(vx_core::t_any, future_resolvedlist, [testpackage](vx_test::Type_testcaselist* resolvedlist) {
          vx_core::Type_booleanlist* passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist,
            resolvedlist,
            vx_core::t_any_from_any->fn_new([](vx_core::Type_any* testcase_any) {
              vx_test::Type_testcase* testcase = vx_core::f_any_from_any(vx_test::t_testcase, testcase_any);
              return 
                testcase->passfail();
            })
          );
          vx_core::Type_boolean* passfail = vx_core::f_and_1(passfaillist);
          return vx_core::f_copy(
            testpackage,
            vx_core::t_anylist->vx_new(
              vx_core::t_string->vx_new_from_string(":passfail"),
              passfail,
              vx_core::t_string->vx_new_from_string(":caselist"),
              resolvedlist
            )
          );
        });
        return output;
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testpackagelist
   * Resolves a testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {testpackagelist}
   * (func resolve-testpackagelist)
   */
  //class Func_resolve_testpackagelist {

    template<typename... Args> vx_test::Func_resolve_testpackagelist* vx_test::Func_resolve_testpackagelist::vx_new(Args*... args) {
      vx_test::Func_resolve_testpackagelist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testpackagelist* vx_test::Func_resolve_testpackagelist::vx_copy(Args*... args) {
      vx_test::Func_resolve_testpackagelist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testpackagelist::vx_typedef() {return vx_test::t_resolve_testpackagelist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testpackagelist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testpackagelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_test::t_testpackage), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testpackagelist* vx_test::Func_resolve_testpackagelist::vx_empty() {return vx_test::e_resolve_testpackagelist;}
    vx_test::Func_resolve_testpackagelist* vx_test::Func_resolve_testpackagelist::vx_type() {return vx_test::t_resolve_testpackagelist;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testpackagelist::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testpackagelist::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testpackagelist* inputval = vx_core::f_any_from_any(vx_test::t_testpackagelist, value);
      vx_core::Async<vx_test::Type_testpackagelist*>* future = vx_test::f_resolve_testpackagelist(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testpackagelist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testpackagelist* testpackagelist = vx_core::f_any_from_any(vx_test::t_testpackagelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testpackagelist*>* future = vx_test::f_resolve_testpackagelist(testpackagelist);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testpackagelist*>* vx_test::Func_resolve_testpackagelist::vx_resolve_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
      return vx_test::f_resolve_testpackagelist(testpackagelist);
    }

  //}

  vx_test::Func_resolve_testpackagelist* vx_test::e_resolve_testpackagelist = new vx_test::Func_resolve_testpackagelist();
  vx_test::Func_resolve_testpackagelist* vx_test::t_resolve_testpackagelist = new vx_test::Func_resolve_testpackagelist();

  vx_core::Async<vx_test::Type_testpackagelist*>* vx_test::f_resolve_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
    vx_core::Async<vx_test::Type_testpackagelist*>* output = vx_core::async_new_from_val(vx_test::e_testpackagelist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testpackagelist,
      testpackagelist,
      vx_test::t_resolve_testpackage
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testresult
   * Resolves a testresult
   * @param  {testresult} testresult
   * @return {testresult}
   * (func resolve-testresult)
   */
  //class Func_resolve_testresult {

    template<typename... Args> vx_test::Func_resolve_testresult* vx_test::Func_resolve_testresult::vx_new(Args*... args) {
      vx_test::Func_resolve_testresult* output;
      return output;
    }

    template<typename... Args> vx_test::Func_resolve_testresult* vx_test::Func_resolve_testresult::vx_copy(Args*... args) {
      vx_test::Func_resolve_testresult* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_resolve_testresult::vx_typedef() {return vx_test::t_resolve_testresult->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_resolve_testresult::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_resolve_testresult* vx_test::Func_resolve_testresult::vx_empty() {return vx_test::e_resolve_testresult;}
    vx_test::Func_resolve_testresult* vx_test::Func_resolve_testresult::vx_type() {return vx_test::t_resolve_testresult;}

    vx_core::Func_any_from_any_async* vx_test::Func_resolve_testresult::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_test::Func_resolve_testresult::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_test::Type_testresult* inputval = vx_core::f_any_from_any(vx_test::t_testresult, value);
      vx_core::Async<vx_test::Type_testresult*>* future = vx_test::f_resolve_testresult(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_test::Func_resolve_testresult::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_test::Type_testresult* testresult = vx_core::f_any_from_any(vx_test::t_testresult, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_test::Type_testresult*>* future = vx_test::f_resolve_testresult(testresult);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_test::Type_testresult*>* vx_test::Func_resolve_testresult::vx_resolve_testresult(vx_test::Type_testresult* testresult) {
      return vx_test::f_resolve_testresult(testresult);
    }

  //}

  vx_test::Func_resolve_testresult* vx_test::e_resolve_testresult = new vx_test::Func_resolve_testresult();
  vx_test::Func_resolve_testresult* vx_test::t_resolve_testresult = new vx_test::Func_resolve_testresult();

  vx_core::Async<vx_test::Type_testresult*>* vx_test::f_resolve_testresult(vx_test::Type_testresult* testresult) {
    vx_core::Async<vx_test::Type_testresult*>* output = vx_core::async_new_from_val(vx_test::e_testresult);
    vx_core::f_let_async(
      vx_test::t_testresult,
      vx_core::t_any_from_func_async->fn_new([testresult]() {
        vx_core::Func_any_from_func_async* fn_actual = testresult->fn_actual();
        vx_core::Type_any* expected = testresult->expected();
        vx_core::Async<vx_core::Type_any*>* future_actual = vx_core::f_resolve_async(vx_core::t_any, fn_actual);
        vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, vx_core::Type_any*>(vx_core::t_any, future_actual, [fn_actual, testresult, expected](vx_core::Type_any* actual) {
          return vx_core::f_if_2(
            vx_test::t_testresult,
            vx_core::t_thenelselist->vx_new(
              vx_core::f_then(
                vx_core::t_boolean_from_func->fn_new([fn_actual]() {
                  return vx_core::f_is_empty_1(fn_actual);
                }),
                vx_core::t_any_from_func->fn_new([testresult]() {
                  return testresult;
                })
              ),
              vx_core::f_else(
                vx_core::t_any_from_func->fn_new([expected, actual, testresult]() {
                  return vx_core::f_let(
                    vx_test::t_testresult,
                    vx_core::t_any_from_func->fn_new([expected, actual, testresult]() {
                      vx_core::Type_boolean* passfail = vx_core::f_eq(expected, actual);
                      return vx_core::f_copy(
                        testresult,
                        vx_core::t_anylist->vx_new(
                          vx_core::t_string->vx_new_from_string(":passfail"),
                          passfail,
                          vx_core::t_string->vx_new_from_string(":actual"),
                          actual
                        )
                      );
                    })
                  );
                })
              )
            )
          );
        });
        return output;
      })
    );
    return output;
  }

  /**
   * @function test
   * Test expected equal actual
   * @param  {any-1} expected
   * @param  {any-2} actual
   * @return {testresult}
   * (func test)
   */
  //class Func_test {

    template<typename... Args> vx_test::Func_test* vx_test::Func_test::vx_new(Args*... args) {
      vx_test::Func_test* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test* vx_test::Func_test::vx_copy(Args*... args) {
      vx_test::Func_test* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test::vx_typedef() {return vx_test::t_test->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test* vx_test::Func_test::vx_empty() {return vx_test::e_test;}
    vx_test::Func_test* vx_test::Func_test::vx_type() {return vx_test::t_test;}

    vx_core::Type_any* vx_test::Func_test::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test(expected, actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test::vx_test(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test(expected, actual, context);
    }

  //}

  vx_test::Func_test* vx_test::e_test = new vx_test::Func_test();
  vx_test::Func_test* vx_test::t_test = new vx_test::Func_test();

  vx_test::Type_testresult* vx_test::f_test(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":eq"),
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_eq(expected, actual),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test 1
   * Async Test expected equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test)
   */
  //class Func_test_1 {

    template<typename... Args> vx_test::Func_test_1* vx_test::Func_test_1::vx_new(Args*... args) {
      vx_test::Func_test_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_1* vx_test::Func_test_1::vx_copy(Args*... args) {
      vx_test::Func_test_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_1::vx_typedef() {return vx_test::t_test_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_1* vx_test::Func_test_1::vx_empty() {return vx_test::e_test_1;}
    vx_test::Func_test_1* vx_test::Func_test_1::vx_type() {return vx_test::t_test_1;}

    vx_core::Type_any* vx_test::Func_test_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_1(expected, fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_1::vx_test_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_1(expected, fn_actual, context);
    }

  //}

  vx_test::Func_test_1* vx_test::e_test_1 = new vx_test::Func_test_1();
  vx_test::Func_test_1* vx_test::t_test_1 = new vx_test::Func_test_1();

  vx_test::Type_testresult* vx_test::f_test_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":eq"),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_false
   * Test expected to be false
   * @param  {any} actual
   * @return {testresult}
   * (func test-false)
   */
  //class Func_test_false {

    template<typename... Args> vx_test::Func_test_false* vx_test::Func_test_false::vx_new(Args*... args) {
      vx_test::Func_test_false* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_false* vx_test::Func_test_false::vx_copy(Args*... args) {
      vx_test::Func_test_false* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_false::vx_typedef() {return vx_test::t_test_false->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_false::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_false* vx_test::Func_test_false::vx_empty() {return vx_test::e_test_false;}
    vx_test::Func_test_false* vx_test::Func_test_false::vx_type() {return vx_test::t_test_false;}

    vx_core::Func_any_from_any_context* vx_test::Func_test_false::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_test::Func_test_false::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any* inputval = (vx_core::Type_any)value;
      vx_core::Type_any* outputval = vx_test::f_test_false(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_test_false::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_test::f_test_false(actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_false::vx_test_false(vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test_false(actual, context);
    }

  //}

  vx_test::Func_test_false* vx_test::e_test_false = new vx_test::Func_test_false();
  vx_test::Func_test_false* vx_test::t_test_false = new vx_test::Func_test_false();

  vx_test::Type_testresult* vx_test::f_test_false(vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":false"),
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_eq(
            vx_core::t_boolean->vx_new_from_boolean(false),
            actual
          ),
          vx_core::t_string->vx_new_from_string(":expected"),
          vx_core::t_boolean->vx_new_from_boolean(false),
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-false", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_false 1
   * Async Test expected to be false
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-false)
   */
  //class Func_test_false_1 {

    template<typename... Args> vx_test::Func_test_false_1* vx_test::Func_test_false_1::vx_new(Args*... args) {
      vx_test::Func_test_false_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_false_1* vx_test::Func_test_false_1::vx_copy(Args*... args) {
      vx_test::Func_test_false_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_false_1::vx_typedef() {return vx_test::t_test_false_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_false_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_false_1* vx_test::Func_test_false_1::vx_empty() {return vx_test::e_test_false_1;}
    vx_test::Func_test_false_1* vx_test::Func_test_false_1::vx_type() {return vx_test::t_test_false_1;}

    vx_core::Func_any_from_any_context* vx_test::Func_test_false_1::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_test::Func_test_false_1::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Func_any_from_func_async* inputval = (vx_core::Func_any_from_func_async)value;
      vx_core::Type_any* outputval = vx_test::f_test_false_1(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_test_false_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_test::f_test_false_1(fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_false_1::vx_test_false_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_false_1(fn_actual, context);
    }

  //}

  vx_test::Func_test_false_1* vx_test::e_test_false_1 = new vx_test::Func_test_false_1();
  vx_test::Func_test_false_1* vx_test::t_test_false_1 = new vx_test::Func_test_false_1();

  vx_test::Type_testresult* vx_test::f_test_false_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":false"),
          vx_core::t_string->vx_new_from_string(":expected"),
          vx_core::t_boolean->vx_new_from_boolean(false),
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-false", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_gt
   * Test expected greater than actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-gt)
   */
  //class Func_test_gt {

    template<typename... Args> vx_test::Func_test_gt* vx_test::Func_test_gt::vx_new(Args*... args) {
      vx_test::Func_test_gt* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_gt* vx_test::Func_test_gt::vx_copy(Args*... args) {
      vx_test::Func_test_gt* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_gt::vx_typedef() {return vx_test::t_test_gt->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_gt::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_gt* vx_test::Func_test_gt::vx_empty() {return vx_test::e_test_gt;}
    vx_test::Func_test_gt* vx_test::Func_test_gt::vx_type() {return vx_test::t_test_gt;}

    vx_core::Type_any* vx_test::Func_test_gt::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_gt(expected, actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_gt::vx_test_gt(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test_gt(expected, actual, context);
    }

  //}

  vx_test::Func_test_gt* vx_test::e_test_gt = new vx_test::Func_test_gt();
  vx_test::Func_test_gt* vx_test::t_test_gt = new vx_test::Func_test_gt();

  vx_test::Type_testresult* vx_test::f_test_gt(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":gt"),
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_gt(expected, actual),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-gt", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_gt 1
   * Async Test expected greater than actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-gt)
   */
  //class Func_test_gt_1 {

    template<typename... Args> vx_test::Func_test_gt_1* vx_test::Func_test_gt_1::vx_new(Args*... args) {
      vx_test::Func_test_gt_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_gt_1* vx_test::Func_test_gt_1::vx_copy(Args*... args) {
      vx_test::Func_test_gt_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_gt_1::vx_typedef() {return vx_test::t_test_gt_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_gt_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_gt_1* vx_test::Func_test_gt_1::vx_empty() {return vx_test::e_test_gt_1;}
    vx_test::Func_test_gt_1* vx_test::Func_test_gt_1::vx_type() {return vx_test::t_test_gt_1;}

    vx_core::Type_any* vx_test::Func_test_gt_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_gt_1(expected, fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_gt_1::vx_test_gt_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_gt_1(expected, fn_actual, context);
    }

  //}

  vx_test::Func_test_gt_1* vx_test::e_test_gt_1 = new vx_test::Func_test_gt_1();
  vx_test::Func_test_gt_1* vx_test::t_test_gt_1 = new vx_test::Func_test_gt_1();

  vx_test::Type_testresult* vx_test::f_test_gt_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":gt"),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-gt", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_ne
   * Test expected not equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-ne)
   */
  //class Func_test_ne {

    template<typename... Args> vx_test::Func_test_ne* vx_test::Func_test_ne::vx_new(Args*... args) {
      vx_test::Func_test_ne* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_ne* vx_test::Func_test_ne::vx_copy(Args*... args) {
      vx_test::Func_test_ne* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_ne::vx_typedef() {return vx_test::t_test_ne->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_ne::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_ne* vx_test::Func_test_ne::vx_empty() {return vx_test::e_test_ne;}
    vx_test::Func_test_ne* vx_test::Func_test_ne::vx_type() {return vx_test::t_test_ne;}

    vx_core::Type_any* vx_test::Func_test_ne::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_ne(expected, actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_ne::vx_test_ne(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test_ne(expected, actual, context);
    }

  //}

  vx_test::Func_test_ne* vx_test::e_test_ne = new vx_test::Func_test_ne();
  vx_test::Func_test_ne* vx_test::t_test_ne = new vx_test::Func_test_ne();

  vx_test::Type_testresult* vx_test::f_test_ne(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":ne"),
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_ne(expected, actual),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-ne", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_ne 1
   * Async Test expected not equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-ne)
   */
  //class Func_test_ne_1 {

    template<typename... Args> vx_test::Func_test_ne_1* vx_test::Func_test_ne_1::vx_new(Args*... args) {
      vx_test::Func_test_ne_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_ne_1* vx_test::Func_test_ne_1::vx_copy(Args*... args) {
      vx_test::Func_test_ne_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_ne_1::vx_typedef() {return vx_test::t_test_ne_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_ne_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_ne_1* vx_test::Func_test_ne_1::vx_empty() {return vx_test::e_test_ne_1;}
    vx_test::Func_test_ne_1* vx_test::Func_test_ne_1::vx_type() {return vx_test::t_test_ne_1;}

    vx_core::Type_any* vx_test::Func_test_ne_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_ne_1(expected, fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_ne_1::vx_test_ne_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_ne_1(expected, fn_actual, context);
    }

  //}

  vx_test::Func_test_ne_1* vx_test::e_test_ne_1 = new vx_test::Func_test_ne_1();
  vx_test::Func_test_ne_1* vx_test::t_test_ne_1 = new vx_test::Func_test_ne_1();

  vx_test::Type_testresult* vx_test::f_test_ne_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":ne"),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-ne", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_string
   * Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-string)
   */
  //class Func_test_string {

    template<typename... Args> vx_test::Func_test_string* vx_test::Func_test_string::vx_new(Args*... args) {
      vx_test::Func_test_string* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_string* vx_test::Func_test_string::vx_copy(Args*... args) {
      vx_test::Func_test_string* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_string::vx_typedef() {return vx_test::t_test_string->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_string::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_string* vx_test::Func_test_string::vx_empty() {return vx_test::e_test_string;}
    vx_test::Func_test_string* vx_test::Func_test_string::vx_type() {return vx_test::t_test_string;}

    vx_core::Type_any* vx_test::Func_test_string::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_string(expected, actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_string::vx_test_string(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test_string(expected, actual, context);
    }

  //}

  vx_test::Func_test_string* vx_test::e_test_string = new vx_test::Func_test_string();
  vx_test::Func_test_string* vx_test::t_test_string = new vx_test::Func_test_string();

  vx_test::Type_testresult* vx_test::f_test_string(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_eq(
            vx_core::f_string_from_any(expected),
            vx_core::f_string_from_any(actual)
          ),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-string", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_string 1
   * Async Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-string)
   */
  //class Func_test_string_1 {

    template<typename... Args> vx_test::Func_test_string_1* vx_test::Func_test_string_1::vx_new(Args*... args) {
      vx_test::Func_test_string_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_string_1* vx_test::Func_test_string_1::vx_copy(Args*... args) {
      vx_test::Func_test_string_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_string_1::vx_typedef() {return vx_test::t_test_string_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_string_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_string_1* vx_test::Func_test_string_1::vx_empty() {return vx_test::e_test_string_1;}
    vx_test::Func_test_string_1* vx_test::Func_test_string_1::vx_type() {return vx_test::t_test_string_1;}

    vx_core::Type_any* vx_test::Func_test_string_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* expected = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_test::f_test_string_1(expected, fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_string_1::vx_test_string_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_string_1(expected, fn_actual, context);
    }

  //}

  vx_test::Func_test_string_1* vx_test::e_test_string_1 = new vx_test::Func_test_string_1();
  vx_test::Func_test_string_1* vx_test::t_test_string_1 = new vx_test::Func_test_string_1();

  vx_test::Type_testresult* vx_test::f_test_string_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":string"),
          vx_core::t_string->vx_new_from_string(":expected"),
          expected,
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-string", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_true
   * Test expected to be true
   * @param  {any} actual
   * @return {testresult}
   * (func test-true)
   */
  //class Func_test_true {

    template<typename... Args> vx_test::Func_test_true* vx_test::Func_test_true::vx_new(Args*... args) {
      vx_test::Func_test_true* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_true* vx_test::Func_test_true::vx_copy(Args*... args) {
      vx_test::Func_test_true* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_true::vx_typedef() {return vx_test::t_test_true->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_true::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_true* vx_test::Func_test_true::vx_empty() {return vx_test::e_test_true;}
    vx_test::Func_test_true* vx_test::Func_test_true::vx_type() {return vx_test::t_test_true;}

    vx_core::Func_any_from_any_context* vx_test::Func_test_true::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_test::Func_test_true::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any* inputval = (vx_core::Type_any)value;
      vx_core::Type_any* outputval = vx_test::f_test_true(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_test_true::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* actual = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_test::f_test_true(actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_true::vx_test_true(vx_core::Type_any* actual, vx_core::Type_context* context) {
      return vx_test::f_test_true(actual, context);
    }

  //}

  vx_test::Func_test_true* vx_test::e_test_true = new vx_test::Func_test_true();
  vx_test::Func_test_true* vx_test::t_test_true = new vx_test::Func_test_true();

  vx_test::Type_testresult* vx_test::f_test_true(vx_core::Type_any* actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":true"),
          vx_core::t_string->vx_new_from_string(":passfail"),
          vx_core::f_eq(
            vx_core::t_boolean->vx_new_from_boolean(true),
            actual
          ),
          vx_core::t_string->vx_new_from_string(":expected"),
          vx_core::t_boolean->vx_new_from_boolean(true),
          vx_core::t_string->vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-true", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function test_true 1
   * Async Test expected to be true
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-true)
   */
  //class Func_test_true_1 {

    template<typename... Args> vx_test::Func_test_true_1* vx_test::Func_test_true_1::vx_new(Args*... args) {
      vx_test::Func_test_true_1* output;
      return output;
    }

    template<typename... Args> vx_test::Func_test_true_1* vx_test::Func_test_true_1::vx_copy(Args*... args) {
      vx_test::Func_test_true_1* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_test_true_1::vx_typedef() {return vx_test::t_test_true_1->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_test_true_1::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/test", // pkgname
          "testresult", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_test_true_1* vx_test::Func_test_true_1::vx_empty() {return vx_test::e_test_true_1;}
    vx_test::Func_test_true_1* vx_test::Func_test_true_1::vx_type() {return vx_test::t_test_true_1;}

    vx_core::Func_any_from_any_context* vx_test::Func_test_true_1::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_test::Func_test_true_1::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Func_any_from_func_async* inputval = (vx_core::Func_any_from_func_async)value;
      vx_core::Type_any* outputval = vx_test::f_test_true_1(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_test_true_1::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Func_any_from_func_async* fn_actual = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_test::f_test_true_1(fn_actual, context);
      return output;
    }

    vx_test::Type_testresult* vx_test::Func_test_true_1::vx_test_true_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      return vx_test::f_test_true_1(fn_actual, context);
    }

  //}

  vx_test::Func_test_true_1* vx_test::e_test_true_1 = new vx_test::Func_test_true_1();
  vx_test::Func_test_true_1* vx_test::t_test_true_1 = new vx_test::Func_test_true_1();

  vx_test::Type_testresult* vx_test::f_test_true_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context) {
      vx_test::Type_testresult* output = vx_test::e_testresult;
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":code"),
          vx_core::t_string->vx_new_from_string(":true"),
          vx_core::t_string->vx_new_from_string(":expected"),
          vx_core::t_boolean->vx_new_from_boolean(true),
          vx_core::t_string->vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (std::exception err) {
      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception("test-true", err);
      output = output->vx_copy(msg);
    }
      return output;
  }

  /**
   * @function tr_from_testdescribe_casename
   * Returns tr from a testdescribe
   * @param  {testdescribe} testdescribe
   * @param  {string} casename
   * @return {tr}
   * (func tr<-testdescribe-casename)
   */
  //class Func_tr_from_testdescribe_casename {

    template<typename... Args> vx_test::Func_tr_from_testdescribe_casename* vx_test::Func_tr_from_testdescribe_casename::vx_new(Args*... args) {
      vx_test::Func_tr_from_testdescribe_casename* output;
      return output;
    }

    template<typename... Args> vx_test::Func_tr_from_testdescribe_casename* vx_test::Func_tr_from_testdescribe_casename::vx_copy(Args*... args) {
      vx_test::Func_tr_from_testdescribe_casename* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_tr_from_testdescribe_casename::vx_typedef() {return vx_test::t_tr_from_testdescribe_casename->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_tr_from_testdescribe_casename::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "tr", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_tr_from_testdescribe_casename* vx_test::Func_tr_from_testdescribe_casename::vx_empty() {return vx_test::e_tr_from_testdescribe_casename;}
    vx_test::Func_tr_from_testdescribe_casename* vx_test::Func_tr_from_testdescribe_casename::vx_type() {return vx_test::t_tr_from_testdescribe_casename;}

    vx_core::Type_any* vx_test::Func_tr_from_testdescribe_casename::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testdescribe* testdescribe = vx_core::f_any_from_any(vx_test::t_testdescribe, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* casename = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

    vx_web_html::Type_tr* vx_test::Func_tr_from_testdescribe_casename::vx_tr_from_testdescribe_casename(vx_test::Type_testdescribe* testdescribe, vx_core::Type_string* casename) {
      return vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
    }

  //}

  vx_test::Func_tr_from_testdescribe_casename* vx_test::e_tr_from_testdescribe_casename = new vx_test::Func_tr_from_testdescribe_casename();
  vx_test::Func_tr_from_testdescribe_casename* vx_test::t_tr_from_testdescribe_casename = new vx_test::Func_tr_from_testdescribe_casename();

  vx_web_html::Type_tr* vx_test::f_tr_from_testdescribe_casename(vx_test::Type_testdescribe* testdescribe, vx_core::Type_string* casename) {
    vx_web_html::Type_tr* output = vx_web_html::e_tr;
    output = vx_core::f_let(
      vx_web_html::t_tr,
      vx_core::t_any_from_func->fn_new([testdescribe, casename]() {
        vx_core::Type_string* describename = testdescribe->describename();
        vx_test::Type_testresult* result = testdescribe->testresult();
        vx_core::Type_boolean* passfail = result->passfail();
        vx_core::Type_string* expected = vx_core::f_string_from_any(
          result->expected()
        );
        vx_core::Type_string* actual = vx_core::f_string_from_any(
          result->actual()
        );
        vx_web_html::Type_style* prestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::t_string->vx_new_from_string(".preformatted")
        );
        return vx_core::f_new(
          vx_web_html::t_tr,
          vx_core::t_anylist->vx_new(
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::t_anylist->vx_new(
                vx_test::f_p_from_passfail(passfail)
              )
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    prestyle,
                    vx_core::t_string->vx_new_from_string(":text"),
                    casename
                  )
                )
              )
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    prestyle,
                    vx_core::t_string->vx_new_from_string(":text"),
                    describename
                  )
                )
              )
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    prestyle,
                    vx_core::t_string->vx_new_from_string(":text"),
                    expected
                  )
                )
              )
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::t_anylist->vx_new(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(
                    vx_core::t_string->vx_new_from_string(":style"),
                    prestyle,
                    vx_core::t_string->vx_new_from_string(":text"),
                    actual
                  )
                )
              )
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function trlist_from_testcase
   * @param  {testcase} testcase
   * @return {trlist}
   * (func trlist<-testcase)
   */
  //class Func_trlist_from_testcase {

    template<typename... Args> vx_test::Func_trlist_from_testcase* vx_test::Func_trlist_from_testcase::vx_new(Args*... args) {
      vx_test::Func_trlist_from_testcase* output;
      return output;
    }

    template<typename... Args> vx_test::Func_trlist_from_testcase* vx_test::Func_trlist_from_testcase::vx_copy(Args*... args) {
      vx_test::Func_trlist_from_testcase* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_trlist_from_testcase::vx_typedef() {return vx_test::t_trlist_from_testcase->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_trlist_from_testcase::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_tr), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_trlist_from_testcase* vx_test::Func_trlist_from_testcase::vx_empty() {return vx_test::e_trlist_from_testcase;}
    vx_test::Func_trlist_from_testcase* vx_test::Func_trlist_from_testcase::vx_type() {return vx_test::t_trlist_from_testcase;}

    vx_core::Func_any_from_any* vx_test::Func_trlist_from_testcase::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_trlist_from_testcase::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testcase* inputval = (vx_test::Type_testcase)value;
      vx_core::Type_any* outputval = vx_test::f_trlist_from_testcase(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_trlist_from_testcase::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testcase* testcase = vx_core::f_any_from_any(vx_test::t_testcase, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_trlist_from_testcase(testcase);
      return output;
    }

    vx_web_html::Type_trlist* vx_test::Func_trlist_from_testcase::vx_trlist_from_testcase(vx_test::Type_testcase* testcase) {
      return vx_test::f_trlist_from_testcase(testcase);
    }

  //}

  vx_test::Func_trlist_from_testcase* vx_test::e_trlist_from_testcase = new vx_test::Func_trlist_from_testcase();
  vx_test::Func_trlist_from_testcase* vx_test::t_trlist_from_testcase = new vx_test::Func_trlist_from_testcase();

  vx_web_html::Type_trlist* vx_test::f_trlist_from_testcase(vx_test::Type_testcase* testcase) {
    vx_web_html::Type_trlist* output = vx_web_html::e_trlist;
    output = vx_core::f_let(
      vx_web_html::t_trlist,
      vx_core::t_any_from_func->fn_new([testcase]() {
        vx_test::Type_testdescribelist* describelist = testcase->describelist();
        vx_core::Type_string* casename = testcase->casename();
        return vx_core::f_list_from_list(
          vx_web_html::t_trlist,
          describelist,
          vx_core::t_any_from_any->fn_new([casename](vx_core::Type_any* testdescribe_any) {
            vx_test::Type_testdescribe* testdescribe = vx_core::f_any_from_any(vx_test::t_testdescribe, testdescribe_any);
            return 
              vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
          })
        );
      })
    );
    return output;
  }

  /**
   * @function trlist_from_testcaselist
   * Returns a trlist from a testcaselist.
   * @param  {testcaselist} testcaselist
   * @return {trlist}
   * (func trlist<-testcaselist)
   */
  //class Func_trlist_from_testcaselist {

    template<typename... Args> vx_test::Func_trlist_from_testcaselist* vx_test::Func_trlist_from_testcaselist::vx_new(Args*... args) {
      vx_test::Func_trlist_from_testcaselist* output;
      return output;
    }

    template<typename... Args> vx_test::Func_trlist_from_testcaselist* vx_test::Func_trlist_from_testcaselist::vx_copy(Args*... args) {
      vx_test::Func_trlist_from_testcaselist* output;
      return output;
    }

    vx_core::Type_typedef* vx_test::Func_trlist_from_testcaselist::vx_typedef() {return vx_test::t_trlist_from_testcaselist->vx_typedef();}

    vx_core::Type_funcdef* vx_test::Func_trlist_from_testcaselist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_tr), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_test::Func_trlist_from_testcaselist* vx_test::Func_trlist_from_testcaselist::vx_empty() {return vx_test::e_trlist_from_testcaselist;}
    vx_test::Func_trlist_from_testcaselist* vx_test::Func_trlist_from_testcaselist::vx_type() {return vx_test::t_trlist_from_testcaselist;}

    vx_core::Func_any_from_any* vx_test::Func_trlist_from_testcaselist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_test::Func_trlist_from_testcaselist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_test::Type_testcaselist* inputval = (vx_test::Type_testcaselist)value;
      vx_core::Type_any* outputval = vx_test::f_trlist_from_testcaselist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_test::Func_trlist_from_testcaselist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_test::Type_testcaselist* testcaselist = vx_core::f_any_from_any(vx_test::t_testcaselist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_test::f_trlist_from_testcaselist(testcaselist);
      return output;
    }

    vx_web_html::Type_trlist* vx_test::Func_trlist_from_testcaselist::vx_trlist_from_testcaselist(vx_test::Type_testcaselist* testcaselist) {
      return vx_test::f_trlist_from_testcaselist(testcaselist);
    }

  //}

  vx_test::Func_trlist_from_testcaselist* vx_test::e_trlist_from_testcaselist = new vx_test::Func_trlist_from_testcaselist();
  vx_test::Func_trlist_from_testcaselist* vx_test::t_trlist_from_testcaselist = new vx_test::Func_trlist_from_testcaselist();

  vx_web_html::Type_trlist* vx_test::f_trlist_from_testcaselist(vx_test::Type_testcaselist* testcaselist) {
    vx_web_html::Type_trlist* output = vx_web_html::e_trlist;
    output = vx_core::f_list_join_from_list(
      vx_web_html::t_trlist,
      testcaselist,
      vx_test::t_trlist_from_testcase
    );
    return output;
  }


//}
