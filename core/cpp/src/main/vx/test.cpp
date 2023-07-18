#include <exception>
#include <functional>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/file.hpp"
#include "../vx/web/html.hpp"
#include "test.hpp"

namespace vx_test {


  // (type testcase)
  // class Class_testcase {
    Abstract_testcase::~Abstract_testcase() {}

    Class_testcase::Class_testcase() : Abstract_testcase::Abstract_testcase() {
      vx_core::refcount += 1;
    }
    Class_testcase::~Class_testcase() {
      vx_core::refcount -= 1;
    }
    // passfail()
    vx_core::Type_boolean Class_testcase::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::e_boolean();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcase::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // casename()
    vx_core::Type_string Class_testcase::casename() const {
      vx_core::Type_string output = this->vx_p_casename;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // describelist()
    vx_test::Type_testdescribelist Class_testcase::describelist() const {
      vx_test::Type_testdescribelist output = this->vx_p_describelist;
      if (output == NULL) {
        output = vx_test::e_testdescribelist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcase::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testcase::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":passfail"] = this->passfail();
      output[":testpkg"] = this->testpkg();
      output[":casename"] = this->casename();
      output[":describelist"] = this->describelist();
      return output;
    }

    vx_core::Type_any Class_testcase::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcase(), vals);
    }
    vx_core::Type_any Class_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcase output = vx_test::e_testcase();
      vx_test::Type_testcase val = vx_core::vx_any_from_any(vx_test::t_testcase(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_string vx_p_casename = val->casename();
      vx_test::Type_testdescribelist vx_p_describelist = val->describelist();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":passfail") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else if (testkey == ":casename") {
            key = testkey;
          } else if (testkey == ":describelist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean()) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":casename") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_casename = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase :casename " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":describelist") {
            if (valsubtype == vx_test::t_testdescribelist()) {
              vx_p_describelist = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase :describelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcase) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcase();
      output->vx_p_passfail = vx_p_passfail;
      output->vx_p_testpkg = vx_p_testpkg;
      output->vx_p_casename = vx_p_casename;
      output->vx_p_describelist = vx_p_describelist;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcase::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcase::vx_empty() const {return vx_test::e_testcase();}
    vx_core::Type_any Class_testcase::vx_type() const {return vx_test::t_testcase();}

    vx_core::Type_typedef Class_testcase::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcase", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testcaselist)
  // class Class_testcaselist {
    Abstract_testcaselist::~Abstract_testcaselist() {}

    Class_testcaselist::Class_testcaselist() : Abstract_testcaselist::Abstract_testcaselist() {
      vx_core::refcount += 1;
    }
    Class_testcaselist::~Class_testcaselist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_testcaselist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_test::Type_testcase Class_testcaselist::vx_get_testcase(vx_core::Type_int index) const {
      vx_test::Type_testcase output = vx_test::e_testcase();
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testcase> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testcase> Class_testcaselist::vx_listtestcase() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testcaselist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testcase(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testcaselist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testcaselist output = vx_test::e_testcaselist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_test::Type_testcase> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_test::t_testcase()) {
          vx_test::Type_testcase castval = vx_core::vx_any_from_any(vx_test::t_testcase(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(testcaselist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testcaselist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcaselist(), vals);
    }
    vx_core::Type_any Class_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcaselist output = vx_test::e_testcaselist();
      vx_test::Type_testcaselist val = vx_core::vx_any_from_any(vx_test::t_testcaselist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testcase> listval = val->vx_listtestcase();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testcase()) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testcase(), valsub));
        } else if (valsubtype == vx_test::t_testcaselist()) {
          vx_test::Type_testcaselist multi = vx_core::vx_any_from_any(vx_test::t_testcaselist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestcase());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcaselist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testcaselist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcaselist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcaselist::vx_empty() const {return vx_test::e_testcaselist();}
    vx_core::Type_any Class_testcaselist::vx_type() const {return vx_test::t_testcaselist();}

    vx_core::Type_typedef Class_testcaselist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testcase()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testcoveragedetail)
  // class Class_testcoveragedetail {
    Abstract_testcoveragedetail::~Abstract_testcoveragedetail() {}

    Class_testcoveragedetail::Class_testcoveragedetail() : Abstract_testcoveragedetail::Abstract_testcoveragedetail() {
      vx_core::refcount += 1;
    }
    Class_testcoveragedetail::~Class_testcoveragedetail() {
      vx_core::refcount -= 1;
    }
    // constmap()
    vx_core::Type_intmap Class_testcoveragedetail::constmap() const {
      vx_core::Type_intmap output = this->vx_p_constmap;
      if (output == NULL) {
        output = vx_core::e_intmap();
      }
      return output;
    }

    // funcmap()
    vx_core::Type_intmap Class_testcoveragedetail::funcmap() const {
      vx_core::Type_intmap output = this->vx_p_funcmap;
      if (output == NULL) {
        output = vx_core::e_intmap();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragedetail::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // typemap()
    vx_core::Type_intmap Class_testcoveragedetail::typemap() const {
      vx_core::Type_intmap output = this->vx_p_typemap;
      if (output == NULL) {
        output = vx_core::e_intmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragedetail::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testcoveragedetail::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":constmap"] = this->constmap();
      output[":funcmap"] = this->funcmap();
      output[":testpkg"] = this->testpkg();
      output[":typemap"] = this->typemap();
      return output;
    }

    vx_core::Type_any Class_testcoveragedetail::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcoveragedetail(), vals);
    }
    vx_core::Type_any Class_testcoveragedetail::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragedetail output = vx_test::e_testcoveragedetail();
      vx_test::Type_testcoveragedetail val = vx_core::vx_any_from_any(vx_test::t_testcoveragedetail(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_intmap vx_p_constmap = val->constmap();
      vx_core::Type_intmap vx_p_funcmap = val->funcmap();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_intmap vx_p_typemap = val->typemap();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":constmap") {
            key = testkey;
          } else if (testkey == ":funcmap") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else if (testkey == ":typemap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":constmap") {
            if (valsubtype == vx_core::t_intmap()) {
              vx_p_constmap = vx_core::vx_any_from_any(vx_core::t_intmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail :constmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":funcmap") {
            if (valsubtype == vx_core::t_intmap()) {
              vx_p_funcmap = vx_core::vx_any_from_any(vx_core::t_intmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail :funcmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":typemap") {
            if (valsubtype == vx_core::t_intmap()) {
              vx_p_typemap = vx_core::vx_any_from_any(vx_core::t_intmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail :typemap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragedetail) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragedetail();
      output->vx_p_constmap = vx_p_constmap;
      output->vx_p_funcmap = vx_p_funcmap;
      output->vx_p_testpkg = vx_p_testpkg;
      output->vx_p_typemap = vx_p_typemap;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragedetail::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragedetail::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragedetail::vx_empty() const {return vx_test::e_testcoveragedetail();}
    vx_core::Type_any Class_testcoveragedetail::vx_type() const {return vx_test::t_testcoveragedetail();}

    vx_core::Type_typedef Class_testcoveragedetail::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testcoveragenums)
  // class Class_testcoveragenums {
    Abstract_testcoveragenums::~Abstract_testcoveragenums() {}

    Class_testcoveragenums::Class_testcoveragenums() : Abstract_testcoveragenums::Abstract_testcoveragenums() {
      vx_core::refcount += 1;
    }
    Class_testcoveragenums::~Class_testcoveragenums() {
      vx_core::refcount -= 1;
    }
    // pct()
    vx_core::Type_int Class_testcoveragenums::pct() const {
      vx_core::Type_int output = this->vx_p_pct;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragenums::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // tests()
    vx_core::Type_int Class_testcoveragenums::tests() const {
      vx_core::Type_int output = this->vx_p_tests;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // total()
    vx_core::Type_int Class_testcoveragenums::total() const {
      vx_core::Type_int output = this->vx_p_total;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragenums::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testcoveragenums::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":pct"] = this->pct();
      output[":testpkg"] = this->testpkg();
      output[":tests"] = this->tests();
      output[":total"] = this->total();
      return output;
    }

    vx_core::Type_any Class_testcoveragenums::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcoveragenums(), vals);
    }
    vx_core::Type_any Class_testcoveragenums::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragenums output = vx_test::e_testcoveragenums();
      vx_test::Type_testcoveragenums val = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_pct = val->pct();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_int vx_p_tests = val->tests();
      vx_core::Type_int vx_p_total = val->total();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":pct") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else if (testkey == ":tests") {
            key = testkey;
          } else if (testkey == ":total") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pct") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_pct = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums :pct " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tests") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_tests = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums :tests " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":total") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_total = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums :total " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragenums) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragenums();
      output->vx_p_pct = vx_p_pct;
      output->vx_p_testpkg = vx_p_testpkg;
      output->vx_p_tests = vx_p_tests;
      output->vx_p_total = vx_p_total;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragenums::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragenums::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragenums::vx_empty() const {return vx_test::e_testcoveragenums();}
    vx_core::Type_any Class_testcoveragenums::vx_type() const {return vx_test::t_testcoveragenums();}

    vx_core::Type_typedef Class_testcoveragenums::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testcoveragesummary)
  // class Class_testcoveragesummary {
    Abstract_testcoveragesummary::~Abstract_testcoveragesummary() {}

    Class_testcoveragesummary::Class_testcoveragesummary() : Abstract_testcoveragesummary::Abstract_testcoveragesummary() {
      vx_core::refcount += 1;
    }
    Class_testcoveragesummary::~Class_testcoveragesummary() {
      vx_core::refcount -= 1;
    }
    // bigospacenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::bigospacenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_bigospacenums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // bigotimenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::bigotimenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_bigotimenums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // constnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::constnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_constnums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // docnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::docnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_docnums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // funcnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::funcnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_funcnums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragesummary::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // totalnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::totalnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_totalnums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // typenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::typenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_typenums;
      if (output == NULL) {
        output = vx_test::e_testcoveragenums();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragesummary::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testcoveragesummary::vx_map() const {
      vx_core::vx_Type_mapany output;
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

    vx_core::Type_any Class_testcoveragesummary::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcoveragesummary(), vals);
    }
    vx_core::Type_any Class_testcoveragesummary::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragesummary output = vx_test::e_testcoveragesummary();
      vx_test::Type_testcoveragesummary val = vx_core::vx_any_from_any(vx_test::t_testcoveragesummary(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_test::Type_testcoveragenums vx_p_bigospacenums = val->bigospacenums();
      vx_test::Type_testcoveragenums vx_p_bigotimenums = val->bigotimenums();
      vx_test::Type_testcoveragenums vx_p_constnums = val->constnums();
      vx_test::Type_testcoveragenums vx_p_docnums = val->docnums();
      vx_test::Type_testcoveragenums vx_p_funcnums = val->funcnums();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_test::Type_testcoveragenums vx_p_totalnums = val->totalnums();
      vx_test::Type_testcoveragenums vx_p_typenums = val->typenums();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":bigospacenums") {
            key = testkey;
          } else if (testkey == ":bigotimenums") {
            key = testkey;
          } else if (testkey == ":constnums") {
            key = testkey;
          } else if (testkey == ":docnums") {
            key = testkey;
          } else if (testkey == ":funcnums") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else if (testkey == ":totalnums") {
            key = testkey;
          } else if (testkey == ":typenums") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":bigospacenums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_bigospacenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :bigospacenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":bigotimenums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_bigotimenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :bigotimenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":constnums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_constnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :constnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":docnums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_docnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :docnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":funcnums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_funcnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :funcnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":totalnums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_totalnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :totalnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":typenums") {
            if (valsubtype == vx_test::t_testcoveragenums()) {
              vx_p_typenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary :typenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testcoveragesummary) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragesummary();
      output->vx_p_bigospacenums = vx_p_bigospacenums;
      output->vx_p_bigotimenums = vx_p_bigotimenums;
      output->vx_p_constnums = vx_p_constnums;
      output->vx_p_docnums = vx_p_docnums;
      output->vx_p_funcnums = vx_p_funcnums;
      output->vx_p_testpkg = vx_p_testpkg;
      output->vx_p_totalnums = vx_p_totalnums;
      output->vx_p_typenums = vx_p_typenums;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragesummary::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragesummary::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragesummary::vx_empty() const {return vx_test::e_testcoveragesummary();}
    vx_core::Type_any Class_testcoveragesummary::vx_type() const {return vx_test::t_testcoveragesummary();}

    vx_core::Type_typedef Class_testcoveragesummary::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testdescribe)
  // class Class_testdescribe {
    Abstract_testdescribe::~Abstract_testdescribe() {}

    Class_testdescribe::Class_testdescribe() : Abstract_testdescribe::Abstract_testdescribe() {
      vx_core::refcount += 1;
    }
    Class_testdescribe::~Class_testdescribe() {
      vx_core::refcount -= 1;
    }
    // describename()
    vx_core::Type_string Class_testdescribe::describename() const {
      vx_core::Type_string output = this->vx_p_describename;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testdescribe::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // testresult()
    vx_test::Type_testresult Class_testdescribe::testresult() const {
      vx_test::Type_testresult output = this->vx_p_testresult;
      if (output == NULL) {
        output = vx_test::e_testresult();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testdescribe::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testdescribe::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":describename"] = this->describename();
      output[":testpkg"] = this->testpkg();
      output[":testresult"] = this->testresult();
      return output;
    }

    vx_core::Type_any Class_testdescribe::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testdescribe(), vals);
    }
    vx_core::Type_any Class_testdescribe::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testdescribe output = vx_test::e_testdescribe();
      vx_test::Type_testdescribe val = vx_core::vx_any_from_any(vx_test::t_testdescribe(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_describename = val->describename();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_test::Type_testresult vx_p_testresult = val->testresult();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":describename") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else if (testkey == ":testresult") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribe) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":describename") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_describename = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribe :describename " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribe :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testresult") {
            if (valsubtype == vx_test::t_testresult()) {
              vx_p_testresult = vx_core::vx_any_from_any(vx_test::t_testresult(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribe :testresult " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribe) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testdescribe();
      output->vx_p_describename = vx_p_describename;
      output->vx_p_testpkg = vx_p_testpkg;
      output->vx_p_testresult = vx_p_testresult;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testdescribe::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testdescribe::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testdescribe::vx_empty() const {return vx_test::e_testdescribe();}
    vx_core::Type_any Class_testdescribe::vx_type() const {return vx_test::t_testdescribe();}

    vx_core::Type_typedef Class_testdescribe::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testdescribelist)
  // class Class_testdescribelist {
    Abstract_testdescribelist::~Abstract_testdescribelist() {}

    Class_testdescribelist::Class_testdescribelist() : Abstract_testdescribelist::Abstract_testdescribelist() {
      vx_core::refcount += 1;
    }
    Class_testdescribelist::~Class_testdescribelist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_testdescribelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_test::Type_testdescribe Class_testdescribelist::vx_get_testdescribe(vx_core::Type_int index) const {
      vx_test::Type_testdescribe output = vx_test::e_testdescribe();
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testdescribe> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testdescribe> Class_testdescribelist::vx_listtestdescribe() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testdescribelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testdescribe(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testdescribelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testdescribelist output = vx_test::e_testdescribelist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_test::Type_testdescribe> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_test::t_testdescribe()) {
          vx_test::Type_testdescribe castval = vx_core::vx_any_from_any(vx_test::t_testdescribe(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(testdescribelist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testdescribelist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_testdescribelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testdescribelist(), vals);
    }
    vx_core::Type_any Class_testdescribelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testdescribelist output = vx_test::e_testdescribelist();
      vx_test::Type_testdescribelist val = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testdescribe> listval = val->vx_listtestdescribe();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testdescribe()) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testdescribe(), valsub));
        } else if (valsubtype == vx_test::t_testdescribelist()) {
          vx_test::Type_testdescribelist multi = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestdescribe());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testdescribelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testdescribelist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testdescribelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testdescribelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testdescribelist::vx_empty() const {return vx_test::e_testdescribelist();}
    vx_core::Type_any Class_testdescribelist::vx_type() const {return vx_test::t_testdescribelist();}

    vx_core::Type_typedef Class_testdescribelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testdescribe()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testpackage)
  // class Class_testpackage {
    Abstract_testpackage::~Abstract_testpackage() {}

    Class_testpackage::Class_testpackage() : Abstract_testpackage::Abstract_testpackage() {
      vx_core::refcount += 1;
    }
    Class_testpackage::~Class_testpackage() {
      vx_core::refcount -= 1;
    }
    // caselist()
    vx_test::Type_testcaselist Class_testpackage::caselist() const {
      vx_test::Type_testcaselist output = this->vx_p_caselist;
      if (output == NULL) {
        output = vx_test::e_testcaselist();
      }
      return output;
    }

    // coveragedetail()
    vx_test::Type_testcoveragedetail Class_testpackage::coveragedetail() const {
      vx_test::Type_testcoveragedetail output = this->vx_p_coveragedetail;
      if (output == NULL) {
        output = vx_test::e_testcoveragedetail();
      }
      return output;
    }

    // coveragesummary()
    vx_test::Type_testcoveragesummary Class_testpackage::coveragesummary() const {
      vx_test::Type_testcoveragesummary output = this->vx_p_coveragesummary;
      if (output == NULL) {
        output = vx_test::e_testcoveragesummary();
      }
      return output;
    }

    // passfail()
    vx_core::Type_boolean Class_testpackage::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::e_boolean();
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testpackage::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testpackage::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testpackage::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":caselist"] = this->caselist();
      output[":coveragedetail"] = this->coveragedetail();
      output[":coveragesummary"] = this->coveragesummary();
      output[":passfail"] = this->passfail();
      output[":testpkg"] = this->testpkg();
      return output;
    }

    vx_core::Type_any Class_testpackage::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testpackage(), vals);
    }
    vx_core::Type_any Class_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testpackage output = vx_test::e_testpackage();
      vx_test::Type_testpackage val = vx_core::vx_any_from_any(vx_test::t_testpackage(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_test::Type_testcaselist vx_p_caselist = val->caselist();
      vx_test::Type_testcoveragedetail vx_p_coveragedetail = val->coveragedetail();
      vx_test::Type_testcoveragesummary vx_p_coveragesummary = val->coveragesummary();
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":caselist") {
            key = testkey;
          } else if (testkey == ":coveragedetail") {
            key = testkey;
          } else if (testkey == ":coveragesummary") {
            key = testkey;
          } else if (testkey == ":passfail") {
            key = testkey;
          } else if (testkey == ":testpkg") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":caselist") {
            if (valsubtype == vx_test::t_testcaselist()) {
              vx_p_caselist = vx_core::vx_any_from_any(vx_test::t_testcaselist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage :caselist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":coveragedetail") {
            if (valsubtype == vx_test::t_testcoveragedetail()) {
              vx_p_coveragedetail = vx_core::vx_any_from_any(vx_test::t_testcoveragedetail(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage :coveragedetail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":coveragesummary") {
            if (valsubtype == vx_test::t_testcoveragesummary()) {
              vx_p_coveragesummary = vx_core::vx_any_from_any(vx_test::t_testcoveragesummary(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage :coveragesummary " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean()) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackage) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testpackage();
      output->vx_p_caselist = vx_p_caselist;
      output->vx_p_coveragedetail = vx_p_coveragedetail;
      output->vx_p_coveragesummary = vx_p_coveragesummary;
      output->vx_p_passfail = vx_p_passfail;
      output->vx_p_testpkg = vx_p_testpkg;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testpackage::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testpackage::vx_empty() const {return vx_test::e_testpackage();}
    vx_core::Type_any Class_testpackage::vx_type() const {return vx_test::t_testpackage();}

    vx_core::Type_typedef Class_testpackage::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testpackagelist)
  // class Class_testpackagelist {
    Abstract_testpackagelist::~Abstract_testpackagelist() {}

    Class_testpackagelist::Class_testpackagelist() : Abstract_testpackagelist::Abstract_testpackagelist() {
      vx_core::refcount += 1;
    }
    Class_testpackagelist::~Class_testpackagelist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_testpackagelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_test::Type_testpackage Class_testpackagelist::vx_get_testpackage(vx_core::Type_int index) const {
      vx_test::Type_testpackage output = vx_test::e_testpackage();
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testpackage> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testpackage> Class_testpackagelist::vx_listtestpackage() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testpackagelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testpackage(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testpackagelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testpackagelist output = vx_test::e_testpackagelist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_test::Type_testpackage> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_test::t_testpackage()) {
          vx_test::Type_testpackage castval = vx_core::vx_any_from_any(vx_test::t_testpackage(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(testpackagelist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testpackagelist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testpackagelist(), vals);
    }
    vx_core::Type_any Class_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testpackagelist output = vx_test::e_testpackagelist();
      vx_test::Type_testpackagelist val = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testpackage> listval = val->vx_listtestpackage();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testpackage()) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testpackage(), valsub));
        } else if (valsubtype == vx_test::t_testpackagelist()) {
          vx_test::Type_testpackagelist multi = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestpackage());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testpackagelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testpackagelist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testpackagelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testpackagelist::vx_empty() const {return vx_test::e_testpackagelist();}
    vx_core::Type_any Class_testpackagelist::vx_type() const {return vx_test::t_testpackagelist();}

    vx_core::Type_typedef Class_testpackagelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testpackage()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testresult)
  // class Class_testresult {
    Abstract_testresult::~Abstract_testresult() {}

    Class_testresult::Class_testresult() : Abstract_testresult::Abstract_testresult() {
      vx_core::refcount += 1;
    }
    Class_testresult::~Class_testresult() {
      vx_core::refcount -= 1;
    }
    // code()
    vx_core::Type_string Class_testresult::code() const {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // passfail()
    vx_core::Type_boolean Class_testresult::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (output == NULL) {
        output = vx_core::e_boolean();
      }
      return output;
    }

    // expected()
    vx_core::Type_any Class_testresult::expected() const {
      vx_core::Type_any output = this->vx_p_expected;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // actual()
    vx_core::Type_any Class_testresult::actual() const {
      vx_core::Type_any output = this->vx_p_actual;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // fn_actual()
    vx_core::Func_any_from_func_async Class_testresult::fn_actual() const {
      vx_core::Func_any_from_func_async output = this->vx_p_fn_actual;
      if (output == NULL) {
        output = vx_core::e_any_from_func_async();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testresult::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_testresult::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":passfail"] = this->passfail();
      output[":expected"] = this->expected();
      output[":actual"] = this->actual();
      output[":fn-actual"] = this->fn_actual();
      return output;
    }

    vx_core::Type_any Class_testresult::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testresult(), vals);
    }
    vx_core::Type_any Class_testresult::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testresult output = vx_test::e_testresult();
      vx_test::Type_testresult val = vx_core::vx_any_from_any(vx_test::t_testresult(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_code = val->code();
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_any vx_p_expected = val->expected();
      vx_core::Type_any vx_p_actual = val->actual();
      vx_core::Func_any_from_func_async vx_p_fn_actual = val->fn_actual();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":code") {
            key = testkey;
          } else if (testkey == ":passfail") {
            key = testkey;
          } else if (testkey == ":expected") {
            key = testkey;
          } else if (testkey == ":actual") {
            key = testkey;
          } else if (testkey == ":fn-actual") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_code = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult :code " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean()) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":expected") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_expected = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult :expected " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":actual") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_actual = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult :actual " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-actual") {
            if (valsubtype == vx_core::t_any_from_func_async()) {
              vx_p_fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult :fn-actual " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresult) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testresult();
      output->vx_p_code = vx_p_code;
      output->vx_p_passfail = vx_p_passfail;
      output->vx_p_expected = vx_p_expected;
      output->vx_p_actual = vx_p_actual;
      output->vx_p_fn_actual = vx_p_fn_actual;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testresult::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testresult::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testresult::vx_empty() const {return vx_test::e_testresult();}
    vx_core::Type_any Class_testresult::vx_type() const {return vx_test::t_testresult();}

    vx_core::Type_typedef Class_testresult::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type testresultlist)
  // class Class_testresultlist {
    Abstract_testresultlist::~Abstract_testresultlist() {}

    Class_testresultlist::Class_testresultlist() : Abstract_testresultlist::Abstract_testresultlist() {
      vx_core::refcount += 1;
    }
    Class_testresultlist::~Class_testresultlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_testresultlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_test::Type_testresult Class_testresultlist::vx_get_testresult(vx_core::Type_int index) const {
      vx_test::Type_testresult output = vx_test::e_testresult();
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testresult> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_test::Type_testresult> Class_testresultlist::vx_listtestresult() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testresultlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testresult(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testresultlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testresultlist output = vx_test::e_testresultlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_test::Type_testresult> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_test::t_testresult()) {
          vx_test::Type_testresult castval = vx_core::vx_any_from_any(vx_test::t_testresult(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(testresultlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testresultlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_testresultlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testresultlist(), vals);
    }
    vx_core::Type_any Class_testresultlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testresultlist output = vx_test::e_testresultlist();
      vx_test::Type_testresultlist val = vx_core::vx_any_from_any(vx_test::t_testresultlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testresult> listval = val->vx_listtestresult();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testresult()) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testresult(), valsub));
        } else if (valsubtype == vx_test::t_testresultlist()) {
          vx_test::Type_testresultlist multi = vx_core::vx_any_from_any(vx_test::t_testresultlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestresult());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new testresultlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testresultlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_testresultlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testresultlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testresultlist::vx_empty() const {return vx_test::e_testresultlist();}
    vx_core::Type_any Class_testresultlist::vx_type() const {return vx_test::t_testresultlist();}

    vx_core::Type_typedef Class_testresultlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testresult()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (const stylesheet-test)
  // class Class_stylesheet_test {

    // vx_constdef()
    vx_core::Type_constdef vx_test::Class_stylesheet_test::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_headchild()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  // (func div<-testcaselist)
  vx_web_html::Type_div f_div_from_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_web_html::Type_div output = vx_web_html::e_div();
    output = vx_core::f_new(
      vx_web_html::t_div(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::f_new(
          vx_web_html::t_table(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string(":thead"),
            vx_core::f_new(
              vx_web_html::t_thead(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_tr(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::f_new(
                      vx_web_html::t_td(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_web_html::t_p(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Pass?")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_web_html::t_p(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Name")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_web_html::t_p(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Test")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_web_html::t_p(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Expected")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_web_html::t_p(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Actual")
                          })
                        )
                      })
                    )
                  })
                )
              })
            ),
            vx_core::vx_new_string(":tbody"),
            vx_core::f_new(
              vx_web_html::t_tbody(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_test::f_trlist_from_testcaselist(testcaselist)
              })
            )
          })
        )
      })
    );
    return output;
  }

  // (func div<-testcaselist)
  // class Class_div_from_testcaselist {
    Abstract_div_from_testcaselist::~Abstract_div_from_testcaselist() {}

    Class_div_from_testcaselist::Class_div_from_testcaselist() : Abstract_div_from_testcaselist::Abstract_div_from_testcaselist() {
      vx_core::refcount += 1;
    }
    Class_div_from_testcaselist::~Class_div_from_testcaselist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_div_from_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testcaselist output = vx_test::e_div_from_testcaselist();
      return output;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testcaselist output = vx_test::e_div_from_testcaselist();
      return output;
    }

    vx_core::Type_typedef Class_div_from_testcaselist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_div_from_testcaselist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_empty() const {return vx_test::e_div_from_testcaselist();}
    vx_core::Type_any Class_div_from_testcaselist::vx_type() const {return vx_test::t_div_from_testcaselist();}
    vx_core::Type_msgblock Class_div_from_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testcaselist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist(), val);
      output = vx_test::f_div_from_testcaselist(inputval);
      return output;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testcaselist(testcaselist);
      return output;
    }

  //}

  // (func div<-testpackage)
  vx_web_html::Type_div f_div_from_testpackage(vx_test::Type_testpackage testpackage) {
    vx_web_html::Type_div output = vx_web_html::e_div();
    output = vx_core::f_let(
      vx_web_html::t_div(),
      vx_core::t_any_from_func()->vx_fn_new([testpackage]() {
        vx_test::Type_testcoveragesummary testcoveragesummary = testpackage->coveragesummary();
        vx_core::Type_string pkgname = testpackage->testpkg();
        vx_test::Type_testcaselist caselist = testpackage->caselist();
        vx_core::Type_boolean passfail = testpackage->passfail();
        vx_web_html::Type_style pkgnamestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".pkgname")
        );
        vx_web_html::Type_div node = vx_test::f_div_from_testcaselist(caselist);
        vx_web_html::Type_divchildlist nodes = vx_core::f_new(
          vx_web_html::t_divchildlist(),
          vx_core::vx_new(vx_core::t_anylist(), {
            node
          })
        );
        vx_web_html::Type_p p_passfail = vx_test::f_p_from_passfail(passfail);
        vx_web_html::Type_p p_pkgname = vx_core::f_new(
          vx_web_html::t_p(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string(":style"),
            pkgnamestyle,
            vx_core::vx_new_string(":text"),
            pkgname
          })
        );
        vx_web_html::Type_p p_totalnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->totalnums()
        );
        vx_web_html::Type_p p_coveragenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->typenums()
        );
        vx_web_html::Type_p p_constnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->constnums()
        );
        vx_web_html::Type_p p_funcnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->funcnums()
        );
        vx_web_html::Type_p p_docnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->docnums()
        );
        vx_web_html::Type_p p_bigospacenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigospacenums()
        );
        vx_web_html::Type_p p_bigotimenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigotimenums()
        );
        vx_web_html::Type_divchildlist summary = vx_core::f_new(
          vx_web_html::t_divchildlist(),
          vx_core::vx_new(vx_core::t_anylist(), {
            p_passfail,
            p_pkgname,
            p_totalnums,
            p_coveragenums,
            p_constnums,
            p_funcnums,
            p_docnums,
            p_bigospacenums,
            p_bigotimenums
          })
        );
        vx_web_html::Type_details details = vx_core::f_new(
          vx_web_html::t_details(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string(":summary"),
            summary,
            vx_core::vx_new_string(":nodes"),
            nodes
          })
        );
        return vx_core::f_new(
          vx_web_html::t_div(),
          vx_core::vx_new(vx_core::t_anylist(), {
            details
          })
        );
      })
    );
    return output;
  }

  // (func div<-testpackage)
  // class Class_div_from_testpackage {
    Abstract_div_from_testpackage::~Abstract_div_from_testpackage() {}

    Class_div_from_testpackage::Class_div_from_testpackage() : Abstract_div_from_testpackage::Abstract_div_from_testpackage() {
      vx_core::refcount += 1;
    }
    Class_div_from_testpackage::~Class_div_from_testpackage() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_div_from_testpackage::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackage output = vx_test::e_div_from_testpackage();
      return output;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackage output = vx_test::e_div_from_testpackage();
      return output;
    }

    vx_core::Type_typedef Class_div_from_testpackage::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_div_from_testpackage::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_div_from_testpackage::vx_empty() const {return vx_test::e_div_from_testpackage();}
    vx_core::Type_any Class_div_from_testpackage::vx_type() const {return vx_test::t_div_from_testpackage();}
    vx_core::Type_msgblock Class_div_from_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testpackage::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testpackage::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_div_from_testpackage::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackage inputval = vx_core::vx_any_from_any(vx_test::t_testpackage(), val);
      output = vx_test::f_div_from_testpackage(inputval);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testpackage(testpackage);
      return output;
    }

  //}

  // (func div<-testpackagelist)
  vx_web_html::Type_div f_div_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_web_html::Type_div output = vx_web_html::e_div();
    output = vx_core::f_let(
      vx_web_html::t_div(),
      vx_core::t_any_from_func()->vx_fn_new([testpackagelist]() {
        vx_web_html::Type_style stylepassfail = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".passfail")
        );
        vx_web_html::Type_style stylepkgname = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".pkgname")
        );
        vx_web_html::Type_style stylepkgheader = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".pkgheader")
        );
        vx_web_html::Type_style stylecoveragenum = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".coveragenums")
        );
        return vx_core::f_new(
          vx_web_html::t_div(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::f_new(
              vx_web_html::t_div(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::vx_new_string(":style"),
                stylepkgheader,
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylepassfail,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Pass?")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylepkgname,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Package Name")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Coverage")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(type)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(const)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(func)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":doc")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":bigospace")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":bigotime")
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_div(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_test::f_divchildlist_from_testpackagelist(testpackagelist)
              })
            )
          })
        );
      })
    );
    return output;
  }

  // (func div<-testpackagelist)
  // class Class_div_from_testpackagelist {
    Abstract_div_from_testpackagelist::~Abstract_div_from_testpackagelist() {}

    Class_div_from_testpackagelist::Class_div_from_testpackagelist() : Abstract_div_from_testpackagelist::Abstract_div_from_testpackagelist() {
      vx_core::refcount += 1;
    }
    Class_div_from_testpackagelist::~Class_div_from_testpackagelist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_div_from_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackagelist output = vx_test::e_div_from_testpackagelist();
      return output;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackagelist output = vx_test::e_div_from_testpackagelist();
      return output;
    }

    vx_core::Type_typedef Class_div_from_testpackagelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_div_from_testpackagelist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_empty() const {return vx_test::e_div_from_testpackagelist();}
    vx_core::Type_any Class_div_from_testpackagelist::vx_type() const {return vx_test::t_div_from_testpackagelist();}
    vx_core::Type_msgblock Class_div_from_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testpackagelist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), val);
      output = vx_test::f_div_from_testpackagelist(inputval);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testpackagelist(testpackagelist);
      return output;
    }

  //}

  // (func divchildlist<-testpackagelist)
  vx_web_html::Type_divchildlist f_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist();
    output = vx_core::f_list_from_list(
      vx_web_html::t_divchildlist(),
      testpackagelist,
      vx_test::t_div_from_testpackage()
    );
    return output;
  }

  // (func divchildlist<-testpackagelist)
  // class Class_divchildlist_from_testpackagelist {
    Abstract_divchildlist_from_testpackagelist::~Abstract_divchildlist_from_testpackagelist() {}

    Class_divchildlist_from_testpackagelist::Class_divchildlist_from_testpackagelist() : Abstract_divchildlist_from_testpackagelist::Abstract_divchildlist_from_testpackagelist() {
      vx_core::refcount += 1;
    }
    Class_divchildlist_from_testpackagelist::~Class_divchildlist_from_testpackagelist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_divchildlist_from_testpackagelist output = vx_test::e_divchildlist_from_testpackagelist();
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_divchildlist_from_testpackagelist output = vx_test::e_divchildlist_from_testpackagelist();
      return output;
    }

    vx_core::Type_typedef Class_divchildlist_from_testpackagelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_divchild()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_divchildlist_from_testpackagelist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_empty() const {return vx_test::e_divchildlist_from_testpackagelist();}
    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_type() const {return vx_test::t_divchildlist_from_testpackagelist();}
    vx_core::Type_msgblock Class_divchildlist_from_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_divchildlist_from_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_divchildlist_from_testpackagelist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), val);
      output = vx_test::f_divchildlist_from_testpackagelist(inputval);
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

  //}

  // (func file-test)
  vx_data_file::Type_file f_file_test() {
    vx_data_file::Type_file output = vx_data_file::e_file();
    output = vx_core::f_new(
      vx_data_file::t_file(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":name"),
        vx_core::vx_new_string("testsuite.vxlisp"),
        vx_core::vx_new_string(":path"),
        vx_core::vx_new_string("src/test/resources")
      })
    );
    return output;
  }

  // (func file-test)
  // class Class_file_test {
    Abstract_file_test::~Abstract_file_test() {}

    Class_file_test::Class_file_test() : Abstract_file_test::Abstract_file_test() {
      vx_core::refcount += 1;
    }
    Class_file_test::~Class_file_test() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_file_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_test output = vx_test::e_file_test();
      return output;
    }

    vx_core::Type_any Class_file_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_test output = vx_test::e_file_test();
      return output;
    }

    vx_core::Type_typedef Class_file_test::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_file_test::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_file_test::vx_empty() const {return vx_test::e_file_test();}
    vx_core::Type_any Class_file_test::vx_type() const {return vx_test::t_file_test();}
    vx_core::Type_msgblock Class_file_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_test::f_file_test();
      return output;
    }

  //}

  // (func file-testhtml)
  vx_data_file::Type_file f_file_testhtml() {
    vx_data_file::Type_file output = vx_data_file::e_file();
    output = vx_core::f_new(
      vx_data_file::t_file(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":name"),
        vx_core::vx_new_string("testsuite.html"),
        vx_core::vx_new_string(":path"),
        vx_core::vx_new_string("src/test/resources")
      })
    );
    return output;
  }

  // (func file-testhtml)
  // class Class_file_testhtml {
    Abstract_file_testhtml::~Abstract_file_testhtml() {}

    Class_file_testhtml::Class_file_testhtml() : Abstract_file_testhtml::Abstract_file_testhtml() {
      vx_core::refcount += 1;
    }
    Class_file_testhtml::~Class_file_testhtml() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_file_testhtml::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testhtml output = vx_test::e_file_testhtml();
      return output;
    }

    vx_core::Type_any Class_file_testhtml::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testhtml output = vx_test::e_file_testhtml();
      return output;
    }

    vx_core::Type_typedef Class_file_testhtml::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_file_testhtml::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_file_testhtml::vx_empty() const {return vx_test::e_file_testhtml();}
    vx_core::Type_any Class_file_testhtml::vx_type() const {return vx_test::t_file_testhtml();}
    vx_core::Type_msgblock Class_file_testhtml::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_testhtml::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_testhtml::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_test::f_file_testhtml();
      return output;
    }

  //}

  // (func file-testnode)
  vx_data_file::Type_file f_file_testnode() {
    vx_data_file::Type_file output = vx_data_file::e_file();
    output = vx_core::f_new(
      vx_data_file::t_file(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":name"),
        vx_core::vx_new_string("testsuitenode.vxlisp"),
        vx_core::vx_new_string(":path"),
        vx_core::vx_new_string("src/test/resources")
      })
    );
    return output;
  }

  // (func file-testnode)
  // class Class_file_testnode {
    Abstract_file_testnode::~Abstract_file_testnode() {}

    Class_file_testnode::Class_file_testnode() : Abstract_file_testnode::Abstract_file_testnode() {
      vx_core::refcount += 1;
    }
    Class_file_testnode::~Class_file_testnode() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_file_testnode::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testnode output = vx_test::e_file_testnode();
      return output;
    }

    vx_core::Type_any Class_file_testnode::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testnode output = vx_test::e_file_testnode();
      return output;
    }

    vx_core::Type_typedef Class_file_testnode::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_file_testnode::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_file_testnode::vx_empty() const {return vx_test::e_file_testnode();}
    vx_core::Type_any Class_file_testnode::vx_type() const {return vx_test::t_file_testnode();}
    vx_core::Type_msgblock Class_file_testnode::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_testnode::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_testnode::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_test::f_file_testnode();
      return output;
    }

  //}

  // (func html<-divtest)
  vx_web_html::Type_html f_html_from_divtest(vx_web_html::Type_div divtest) {
    vx_web_html::Type_html output = vx_web_html::e_html();
    output = vx_core::f_new(
      vx_web_html::t_html(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":lang"),
        vx_core::vx_new_string("en"),
        vx_core::vx_new_string(":head"),
        vx_core::f_new(
          vx_web_html::t_head(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::f_new(
              vx_web_html::t_meta(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::vx_new_string(":charset"),
                vx_core::vx_new_string("utf-8")
              })
            ),
            vx_core::f_new(
              vx_web_html::t_title(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("Test Suite")
              })
            ),
            vx_test::c_stylesheet_test()
          })
        ),
        vx_core::vx_new_string(":body"),
        vx_core::f_new(
          vx_web_html::t_body(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::f_new(
              vx_web_html::t_div(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_h1(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("Test Suite")
                  })
                )
              })
            ),
            divtest
          })
        )
      })
    );
    return output;
  }

  // (func html<-divtest)
  // class Class_html_from_divtest {
    Abstract_html_from_divtest::~Abstract_html_from_divtest() {}

    Class_html_from_divtest::Class_html_from_divtest() : Abstract_html_from_divtest::Abstract_html_from_divtest() {
      vx_core::refcount += 1;
    }
    Class_html_from_divtest::~Class_html_from_divtest() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_html_from_divtest::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_html_from_divtest output = vx_test::e_html_from_divtest();
      return output;
    }

    vx_core::Type_any Class_html_from_divtest::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_html_from_divtest output = vx_test::e_html_from_divtest();
      return output;
    }

    vx_core::Type_typedef Class_html_from_divtest::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "html", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_html_from_divtest::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_html_from_divtest::vx_empty() const {return vx_test::e_html_from_divtest();}
    vx_core::Type_any Class_html_from_divtest::vx_type() const {return vx_test::t_html_from_divtest();}
    vx_core::Type_msgblock Class_html_from_divtest::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_html_from_divtest::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_html_from_divtest::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_html_from_divtest::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_div inputval = vx_core::vx_any_from_any(vx_web_html::t_div(), val);
      output = vx_test::f_html_from_divtest(inputval);
      return output;
    }

    vx_core::Type_any Class_html_from_divtest::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_div divtest = vx_core::vx_any_from_any(vx_web_html::t_div(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_html_from_divtest(divtest);
      return output;
    }

  //}

  // (func p<-passfail)
  vx_web_html::Type_p f_p_from_passfail(vx_core::Type_boolean passfail) {
    vx_web_html::Type_p output = vx_web_html::e_p();
    output = vx_core::f_let(
      vx_web_html::t_p(),
      vx_core::t_any_from_func()->vx_fn_new([passfail]() {
        vx_core::Type_string text = vx_core::f_if_1(vx_core::t_string(), passfail, vx_core::vx_new_string("Pass"), vx_core::vx_new_string("Fail"));
        vx_core::Type_string stylename = vx_core::f_if_1(vx_core::t_string(), passfail, vx_core::vx_new_string(".passflag"), vx_core::vx_new_string(".failflag"));
        vx_web_html::Type_style style = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          stylename
        );
        return vx_core::f_new(
          vx_web_html::t_p(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string(":style"),
            style,
            vx_core::vx_new_string(":text"),
            text
          })
        );
      })
    );
    return output;
  }

  // (func p<-passfail)
  // class Class_p_from_passfail {
    Abstract_p_from_passfail::~Abstract_p_from_passfail() {}

    Class_p_from_passfail::Class_p_from_passfail() : Abstract_p_from_passfail::Abstract_p_from_passfail() {
      vx_core::refcount += 1;
    }
    Class_p_from_passfail::~Class_p_from_passfail() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_p_from_passfail::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_passfail output = vx_test::e_p_from_passfail();
      return output;
    }

    vx_core::Type_any Class_p_from_passfail::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_passfail output = vx_test::e_p_from_passfail();
      return output;
    }

    vx_core::Type_typedef Class_p_from_passfail::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_p_from_passfail::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_p_from_passfail::vx_empty() const {return vx_test::e_p_from_passfail();}
    vx_core::Type_any Class_p_from_passfail::vx_type() const {return vx_test::t_p_from_passfail();}
    vx_core::Type_msgblock Class_p_from_passfail::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_p_from_passfail::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_p_from_passfail::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_p_from_passfail::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean inputval = vx_core::vx_any_from_any(vx_core::t_boolean(), val);
      output = vx_test::f_p_from_passfail(inputval);
      return output;
    }

    vx_core::Type_any Class_p_from_passfail::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean passfail = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_p_from_passfail(passfail);
      return output;
    }

  //}

  // (func p<-testcoveragenums)
  vx_web_html::Type_p f_p_from_testcoveragenums(vx_test::Type_testcoveragenums nums) {
    vx_web_html::Type_p output = vx_web_html::e_p();
    output = vx_core::f_new(
      vx_web_html::t_p(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":style"),
        vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".coveragenums")
        ),
        vx_core::vx_new_string(":text"),
        vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
            nums->pct(),
            vx_core::vx_new_string("% "),
            nums->tests(),
            vx_core::vx_new_string("/"),
            nums->total()
          })
        )
      })
    );
    return output;
  }

  // (func p<-testcoveragenums)
  // class Class_p_from_testcoveragenums {
    Abstract_p_from_testcoveragenums::~Abstract_p_from_testcoveragenums() {}

    Class_p_from_testcoveragenums::Class_p_from_testcoveragenums() : Abstract_p_from_testcoveragenums::Abstract_p_from_testcoveragenums() {
      vx_core::refcount += 1;
    }
    Class_p_from_testcoveragenums::~Class_p_from_testcoveragenums() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_p_from_testcoveragenums::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_testcoveragenums output = vx_test::e_p_from_testcoveragenums();
      return output;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_testcoveragenums output = vx_test::e_p_from_testcoveragenums();
      return output;
    }

    vx_core::Type_typedef Class_p_from_testcoveragenums::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_p_from_testcoveragenums::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_empty() const {return vx_test::e_p_from_testcoveragenums();}
    vx_core::Type_any Class_p_from_testcoveragenums::vx_type() const {return vx_test::t_p_from_testcoveragenums();}
    vx_core::Type_msgblock Class_p_from_testcoveragenums::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_p_from_testcoveragenums::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_p_from_testcoveragenums::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcoveragenums inputval = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), val);
      output = vx_test::f_p_from_testcoveragenums(inputval);
      return output;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcoveragenums nums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_p_from_testcoveragenums(nums);
      return output;
    }

  //}

  // (func resolve-testcase)
  vx_core::vx_Type_async f_resolve_testcase(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testcase());
    vx_core::f_let_async(
      vx_test::t_testcase(),
      vx_core::t_any_from_func_async()->vx_fn_new([testcase]() {
        vx_test::Type_testdescribelist describelist = testcase->describelist();
        vx_core::vx_Type_async future_resolvedlist = vx_test::f_resolve_testdescribelist(describelist);
        std::function<vx_core::Type_any(vx_core::Type_any)> fn_any_any_resolvedlist = [testcase](vx_core::Type_any any_resolvedlist) {
          vx_test::Type_testdescribelist resolvedlist = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), any_resolvedlist);
          vx_core::Type_booleanlist passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist(),
            resolvedlist,
            vx_core::t_any_from_any()->vx_fn_new([](vx_core::Type_any testdescribe_any) {
              vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe(), testdescribe_any);
              return 
                vx_core::f_let(
                  vx_core::t_boolean(),
                  vx_core::t_any_from_func()->vx_fn_new([testdescribe]() {
                    vx_test::Type_testresult testresult = testdescribe->testresult();
                    return testresult->passfail();
                  })
                );
            })
          );
          vx_core::Type_boolean passfail = vx_core::f_and_1(passfaillist);
          return vx_core::f_copy(
            testcase,
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string(":passfail"),
              passfail,
              vx_core::vx_new_string(":describelist"),
              resolvedlist
            })
          );
        };
        vx_core::vx_Type_async output = vx_core::vx_async_from_async_fn(future_resolvedlist, fn_any_any_resolvedlist);
        return output;
      })
    );
    return output;
  }

  // (func resolve-testcase)
  // class Class_resolve_testcase {
    Abstract_resolve_testcase::~Abstract_resolve_testcase() {}

    Class_resolve_testcase::Class_resolve_testcase() : Abstract_resolve_testcase::Abstract_resolve_testcase() {
      vx_core::refcount += 1;
    }
    Class_resolve_testcase::~Class_resolve_testcase() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testcase::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcase output = vx_test::e_resolve_testcase();
      return output;
    }

    vx_core::Type_any Class_resolve_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcase output = vx_test::e_resolve_testcase();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testcase::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcase", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testcase::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testcase::vx_empty() const {return vx_test::e_resolve_testcase();}
    vx_core::Type_any Class_resolve_testcase::vx_type() const {return vx_test::t_resolve_testcase();}
    vx_core::Type_msgblock Class_resolve_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testcase::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testcase::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testcase::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testcase inputval = vx_core::vx_any_from_any(vx_test::t_testcase(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testcase(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testcase::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testcase(testcase);
      return output;
    }

  //}

  // (func resolve-testcaselist)
  vx_core::vx_Type_async f_resolve_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testcaselist());
    output = vx_core::f_list_from_list_async(
      vx_test::t_testcaselist(),
      testcaselist,
      vx_test::t_resolve_testcase()
    );
    return output;
  }

  // (func resolve-testcaselist)
  // class Class_resolve_testcaselist {
    Abstract_resolve_testcaselist::~Abstract_resolve_testcaselist() {}

    Class_resolve_testcaselist::Class_resolve_testcaselist() : Abstract_resolve_testcaselist::Abstract_resolve_testcaselist() {
      vx_core::refcount += 1;
    }
    Class_resolve_testcaselist::~Class_resolve_testcaselist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcaselist output = vx_test::e_resolve_testcaselist();
      return output;
    }

    vx_core::Type_any Class_resolve_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcaselist output = vx_test::e_resolve_testcaselist();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testcaselist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testcase()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testcaselist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testcaselist::vx_empty() const {return vx_test::e_resolve_testcaselist();}
    vx_core::Type_any Class_resolve_testcaselist::vx_type() const {return vx_test::t_resolve_testcaselist();}
    vx_core::Type_msgblock Class_resolve_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testcaselist::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testcaselist::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testcaselist(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testcaselist(testcaselist);
      return output;
    }

  //}

  // (func resolve-testdescribe)
  vx_core::vx_Type_async f_resolve_testdescribe(vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testdescribe());
    vx_core::f_let_async(
      vx_test::t_testdescribe(),
      vx_core::t_any_from_func_async()->vx_fn_new([testdescribe]() {
        vx_test::Type_testresult testresult = testdescribe->testresult();
        vx_core::vx_Type_async future_resolved = vx_test::f_resolve_testresult(testresult);
        std::function<vx_core::Type_any(vx_core::Type_any)> fn_any_any_resolved = [testdescribe](vx_core::Type_any any_resolved) {
          vx_test::Type_testresult resolved = vx_core::vx_any_from_any(vx_test::t_testresult(), any_resolved);
          return vx_core::f_copy(
            testdescribe,
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string(":testresult"),
              resolved
            })
          );
        };
        vx_core::vx_Type_async output = vx_core::vx_async_from_async_fn(future_resolved, fn_any_any_resolved);
        return output;
      })
    );
    return output;
  }

  // (func resolve-testdescribe)
  // class Class_resolve_testdescribe {
    Abstract_resolve_testdescribe::~Abstract_resolve_testdescribe() {}

    Class_resolve_testdescribe::Class_resolve_testdescribe() : Abstract_resolve_testdescribe::Abstract_resolve_testdescribe() {
      vx_core::refcount += 1;
    }
    Class_resolve_testdescribe::~Class_resolve_testdescribe() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testdescribe::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribe output = vx_test::e_resolve_testdescribe();
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribe::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribe output = vx_test::e_resolve_testdescribe();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testdescribe::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testdescribe::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testdescribe::vx_empty() const {return vx_test::e_resolve_testdescribe();}
    vx_core::Type_any Class_resolve_testdescribe::vx_type() const {return vx_test::t_resolve_testdescribe();}
    vx_core::Type_msgblock Class_resolve_testdescribe::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testdescribe::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testdescribe::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testdescribe::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testdescribe inputval = vx_core::vx_any_from_any(vx_test::t_testdescribe(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testdescribe(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testdescribe::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testdescribe(testdescribe);
      return output;
    }

  //}

  // (func resolve-testdescribelist)
  vx_core::vx_Type_async f_resolve_testdescribelist(vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testdescribelist());
    output = vx_core::f_list_from_list_async(
      vx_test::t_testdescribelist(),
      testdescribelist,
      vx_test::t_resolve_testdescribe()
    );
    return output;
  }

  // (func resolve-testdescribelist)
  // class Class_resolve_testdescribelist {
    Abstract_resolve_testdescribelist::~Abstract_resolve_testdescribelist() {}

    Class_resolve_testdescribelist::Class_resolve_testdescribelist() : Abstract_resolve_testdescribelist::Abstract_resolve_testdescribelist() {
      vx_core::refcount += 1;
    }
    Class_resolve_testdescribelist::~Class_resolve_testdescribelist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testdescribelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribelist output = vx_test::e_resolve_testdescribelist();
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribelist output = vx_test::e_resolve_testdescribelist();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testdescribelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testdescribe()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testdescribelist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testdescribelist::vx_empty() const {return vx_test::e_resolve_testdescribelist();}
    vx_core::Type_any Class_resolve_testdescribelist::vx_type() const {return vx_test::t_resolve_testdescribelist();}
    vx_core::Type_msgblock Class_resolve_testdescribelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testdescribelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testdescribelist::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testdescribelist::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testdescribelist inputval = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testdescribelist(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testdescribelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testdescribelist testdescribelist = vx_core::vx_any_from_any(vx_test::t_testdescribelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testdescribelist(testdescribelist);
      return output;
    }

  //}

  // (func resolve-testpackage)
  vx_core::vx_Type_async f_resolve_testpackage(vx_test::Type_testpackage testpackage) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testpackage());
    vx_core::f_let_async(
      vx_test::t_testpackage(),
      vx_core::t_any_from_func_async()->vx_fn_new([testpackage]() {
        vx_test::Type_testcaselist testcaselist = testpackage->caselist();
        vx_core::vx_Type_async future_resolvedlist = vx_test::f_resolve_testcaselist(testcaselist);
        std::function<vx_core::Type_any(vx_core::Type_any)> fn_any_any_resolvedlist = [testpackage](vx_core::Type_any any_resolvedlist) {
          vx_test::Type_testcaselist resolvedlist = vx_core::vx_any_from_any(vx_test::t_testcaselist(), any_resolvedlist);
          vx_core::Type_booleanlist passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist(),
            resolvedlist,
            vx_core::t_any_from_any()->vx_fn_new([](vx_core::Type_any testcase_any) {
              vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase(), testcase_any);
              return 
                testcase->passfail();
            })
          );
          vx_core::Type_boolean passfail = vx_core::f_and_1(passfaillist);
          return vx_core::f_copy(
            testpackage,
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string(":passfail"),
              passfail,
              vx_core::vx_new_string(":caselist"),
              resolvedlist
            })
          );
        };
        vx_core::vx_Type_async output = vx_core::vx_async_from_async_fn(future_resolvedlist, fn_any_any_resolvedlist);
        return output;
      })
    );
    return output;
  }

  // (func resolve-testpackage)
  // class Class_resolve_testpackage {
    Abstract_resolve_testpackage::~Abstract_resolve_testpackage() {}

    Class_resolve_testpackage::Class_resolve_testpackage() : Abstract_resolve_testpackage::Abstract_resolve_testpackage() {
      vx_core::refcount += 1;
    }
    Class_resolve_testpackage::~Class_resolve_testpackage() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testpackage::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackage output = vx_test::e_resolve_testpackage();
      return output;
    }

    vx_core::Type_any Class_resolve_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackage output = vx_test::e_resolve_testpackage();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testpackage::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testpackage::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testpackage::vx_empty() const {return vx_test::e_resolve_testpackage();}
    vx_core::Type_any Class_resolve_testpackage::vx_type() const {return vx_test::t_resolve_testpackage();}
    vx_core::Type_msgblock Class_resolve_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testpackage::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testpackage::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testpackage::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testpackage inputval = vx_core::vx_any_from_any(vx_test::t_testpackage(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testpackage(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testpackage::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testpackage(testpackage);
      return output;
    }

  //}

  // (func resolve-testpackagelist)
  vx_core::vx_Type_async f_resolve_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testpackagelist());
    output = vx_core::f_list_from_list_async(
      vx_test::t_testpackagelist(),
      testpackagelist,
      vx_test::t_resolve_testpackage()
    );
    return output;
  }

  // (func resolve-testpackagelist)
  // class Class_resolve_testpackagelist {
    Abstract_resolve_testpackagelist::~Abstract_resolve_testpackagelist() {}

    Class_resolve_testpackagelist::Class_resolve_testpackagelist() : Abstract_resolve_testpackagelist::Abstract_resolve_testpackagelist() {
      vx_core::refcount += 1;
    }
    Class_resolve_testpackagelist::~Class_resolve_testpackagelist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackagelist output = vx_test::e_resolve_testpackagelist();
      return output;
    }

    vx_core::Type_any Class_resolve_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackagelist output = vx_test::e_resolve_testpackagelist();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testpackagelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_test::t_testpackage()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testpackagelist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testpackagelist::vx_empty() const {return vx_test::e_resolve_testpackagelist();}
    vx_core::Type_any Class_resolve_testpackagelist::vx_type() const {return vx_test::t_resolve_testpackagelist();}
    vx_core::Type_msgblock Class_resolve_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testpackagelist::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testpackagelist::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testpackagelist(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testpackagelist(testpackagelist);
      return output;
    }

  //}

  // (func resolve-testresult)
  vx_core::vx_Type_async f_resolve_testresult(vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_test::e_testresult());
    vx_core::f_let_async(
      vx_test::t_testresult(),
      vx_core::t_any_from_func_async()->vx_fn_new([testresult]() {
        vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
        vx_core::Type_any expected = testresult->expected();
        vx_core::vx_Type_async future_actual = vx_core::f_resolve_async(vx_core::t_any(), fn_actual);
        std::function<vx_core::Type_any(vx_core::Type_any)> fn_any_any_actual = [fn_actual, testresult, expected](vx_core::Type_any any_actual) {
          vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), any_actual);
          return vx_core::f_if_2(
            vx_test::t_testresult(),
            vx_core::vx_new(vx_core::t_thenelselist(), {
              vx_core::f_then(
                vx_core::t_boolean_from_func()->vx_fn_new([fn_actual]() {
                  return vx_core::f_is_empty_1(fn_actual);
                }),
                vx_core::t_any_from_func()->vx_fn_new([testresult]() {
                  return testresult;
                })
              ),
              vx_core::f_else(
                vx_core::t_any_from_func()->vx_fn_new([expected, actual, testresult]() {
                  return vx_core::f_let(
                    vx_test::t_testresult(),
                    vx_core::t_any_from_func()->vx_fn_new([expected, actual, testresult]() {
                      vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
                      return vx_core::f_copy(
                        testresult,
                        vx_core::vx_new(vx_core::t_anylist(), {
                          vx_core::vx_new_string(":passfail"),
                          passfail,
                          vx_core::vx_new_string(":actual"),
                          actual
                        })
                      );
                    })
                  );
                })
              )
            })
          );
        };
        vx_core::vx_Type_async output = vx_core::vx_async_from_async_fn(future_actual, fn_any_any_actual);
        return output;
      })
    );
    return output;
  }

  // (func resolve-testresult)
  // class Class_resolve_testresult {
    Abstract_resolve_testresult::~Abstract_resolve_testresult() {}

    Class_resolve_testresult::Class_resolve_testresult() : Abstract_resolve_testresult::Abstract_resolve_testresult() {
      vx_core::refcount += 1;
    }
    Class_resolve_testresult::~Class_resolve_testresult() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_testresult::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testresult output = vx_test::e_resolve_testresult();
      return output;
    }

    vx_core::Type_any Class_resolve_testresult::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testresult output = vx_test::e_resolve_testresult();
      return output;
    }

    vx_core::Type_typedef Class_resolve_testresult::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_testresult::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_testresult::vx_empty() const {return vx_test::e_resolve_testresult();}
    vx_core::Type_any Class_resolve_testresult::vx_type() const {return vx_test::t_resolve_testresult();}
    vx_core::Type_msgblock Class_resolve_testresult::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testresult::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testresult::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_testresult::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_test::Type_testresult inputval = vx_core::vx_any_from_any(vx_test::t_testresult(), val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testresult(inputval);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testresult::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_test::Type_testresult testresult = vx_core::vx_any_from_any(vx_test::t_testresult(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testresult(testresult);
      return output;
    }

  //}

  // (func test)
  vx_test::Type_testresult f_test(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":eq"),
        vx_core::vx_new_string(":passfail"),
        vx_core::f_eq(expected, actual),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test)
  // class Class_test {
    Abstract_test::~Abstract_test() {}

    Class_test::Class_test() : Abstract_test::Abstract_test() {
      vx_core::refcount += 1;
    }
    Class_test::~Class_test() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test output = vx_test::e_test();
      return output;
    }

    vx_core::Type_any Class_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test output = vx_test::e_test();
      return output;
    }

    vx_core::Type_typedef Class_test::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test::vx_empty() const {return vx_test::e_test();}
    vx_core::Type_any Class_test::vx_type() const {return vx_test::t_test();}
    vx_core::Type_msgblock Class_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test(expected, actual, context);
      return output;
    }

  //}

  // (func test)
  vx_test::Type_testresult f_test_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":eq"),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test)
  // class Class_test_1 {
    Abstract_test_1::~Abstract_test_1() {}

    Class_test_1::Class_test_1() : Abstract_test_1::Abstract_test_1() {
      vx_core::refcount += 1;
    }
    Class_test_1::~Class_test_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_1 output = vx_test::e_test_1();
      return output;
    }

    vx_core::Type_any Class_test_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_1 output = vx_test::e_test_1();
      return output;
    }

    vx_core::Type_typedef Class_test_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_1::vx_empty() const {return vx_test::e_test_1();}
    vx_core::Type_any Class_test_1::vx_type() const {return vx_test::t_test_1();}
    vx_core::Type_msgblock Class_test_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_1(expected, fn_actual, context);
      return output;
    }

  //}

  // (func test-false)
  vx_test::Type_testresult f_test_false(vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":false"),
        vx_core::vx_new_string(":passfail"),
        vx_core::f_eq(
          vx_core::vx_new_boolean(false),
          actual
        ),
        vx_core::vx_new_string(":expected"),
        vx_core::vx_new_boolean(false),
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-false", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-false)
  // class Class_test_false {
    Abstract_test_false::~Abstract_test_false() {}

    Class_test_false::Class_test_false() : Abstract_test_false::Abstract_test_false() {
      vx_core::refcount += 1;
    }
    Class_test_false::~Class_test_false() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_false::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false output = vx_test::e_test_false();
      return output;
    }

    vx_core::Type_any Class_test_false::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false output = vx_test::e_test_false();
      return output;
    }

    vx_core::Type_typedef Class_test_false::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_false::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_false::vx_empty() const {return vx_test::e_test_false();}
    vx_core::Type_any Class_test_false::vx_type() const {return vx_test::t_test_false();}
    vx_core::Type_msgblock Class_test_false::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_false::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_false::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_test_false::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_test::f_test_false(inputval, context);
      return output;
    }

    vx_core::Type_any Class_test_false::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_false(actual, context);
      return output;
    }

  //}

  // (func test-false)
  vx_test::Type_testresult f_test_false_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":false"),
        vx_core::vx_new_string(":expected"),
        vx_core::vx_new_boolean(false),
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-false", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-false)
  // class Class_test_false_1 {
    Abstract_test_false_1::~Abstract_test_false_1() {}

    Class_test_false_1::Class_test_false_1() : Abstract_test_false_1::Abstract_test_false_1() {
      vx_core::refcount += 1;
    }
    Class_test_false_1::~Class_test_false_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_false_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false_1 output = vx_test::e_test_false_1();
      return output;
    }

    vx_core::Type_any Class_test_false_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false_1 output = vx_test::e_test_false_1();
      return output;
    }

    vx_core::Type_typedef Class_test_false_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_false_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_false_1::vx_empty() const {return vx_test::e_test_false_1();}
    vx_core::Type_any Class_test_false_1::vx_type() const {return vx_test::t_test_false_1();}
    vx_core::Type_msgblock Class_test_false_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_false_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_false_1::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_test_false_1::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func_async inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), val);
      output = vx_test::f_test_false_1(inputval, context);
      return output;
    }

    vx_core::Type_any Class_test_false_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_false_1(fn_actual, context);
      return output;
    }

  //}

  // (func test-gt)
  vx_test::Type_testresult f_test_gt(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":gt"),
        vx_core::vx_new_string(":passfail"),
        vx_core::f_gt(expected, actual),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-gt", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-gt)
  // class Class_test_gt {
    Abstract_test_gt::~Abstract_test_gt() {}

    Class_test_gt::Class_test_gt() : Abstract_test_gt::Abstract_test_gt() {
      vx_core::refcount += 1;
    }
    Class_test_gt::~Class_test_gt() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_gt::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt output = vx_test::e_test_gt();
      return output;
    }

    vx_core::Type_any Class_test_gt::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt output = vx_test::e_test_gt();
      return output;
    }

    vx_core::Type_typedef Class_test_gt::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_gt::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_gt::vx_empty() const {return vx_test::e_test_gt();}
    vx_core::Type_any Class_test_gt::vx_type() const {return vx_test::t_test_gt();}
    vx_core::Type_msgblock Class_test_gt::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_gt::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_gt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_gt(expected, actual, context);
      return output;
    }

  //}

  // (func test-gt)
  vx_test::Type_testresult f_test_gt_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":gt"),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-gt", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-gt)
  // class Class_test_gt_1 {
    Abstract_test_gt_1::~Abstract_test_gt_1() {}

    Class_test_gt_1::Class_test_gt_1() : Abstract_test_gt_1::Abstract_test_gt_1() {
      vx_core::refcount += 1;
    }
    Class_test_gt_1::~Class_test_gt_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_gt_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt_1 output = vx_test::e_test_gt_1();
      return output;
    }

    vx_core::Type_any Class_test_gt_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt_1 output = vx_test::e_test_gt_1();
      return output;
    }

    vx_core::Type_typedef Class_test_gt_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_gt_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_gt_1::vx_empty() const {return vx_test::e_test_gt_1();}
    vx_core::Type_any Class_test_gt_1::vx_type() const {return vx_test::t_test_gt_1();}
    vx_core::Type_msgblock Class_test_gt_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_gt_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_gt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_gt_1(expected, fn_actual, context);
      return output;
    }

  //}

  // (func test-ne)
  vx_test::Type_testresult f_test_ne(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":ne"),
        vx_core::vx_new_string(":passfail"),
        vx_core::f_ne(expected, actual),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-ne", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-ne)
  // class Class_test_ne {
    Abstract_test_ne::~Abstract_test_ne() {}

    Class_test_ne::Class_test_ne() : Abstract_test_ne::Abstract_test_ne() {
      vx_core::refcount += 1;
    }
    Class_test_ne::~Class_test_ne() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_ne::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne output = vx_test::e_test_ne();
      return output;
    }

    vx_core::Type_any Class_test_ne::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne output = vx_test::e_test_ne();
      return output;
    }

    vx_core::Type_typedef Class_test_ne::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_ne::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_ne::vx_empty() const {return vx_test::e_test_ne();}
    vx_core::Type_any Class_test_ne::vx_type() const {return vx_test::t_test_ne();}
    vx_core::Type_msgblock Class_test_ne::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_ne::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_ne::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_ne(expected, actual, context);
      return output;
    }

  //}

  // (func test-ne)
  vx_test::Type_testresult f_test_ne_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":ne"),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-ne", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-ne)
  // class Class_test_ne_1 {
    Abstract_test_ne_1::~Abstract_test_ne_1() {}

    Class_test_ne_1::Class_test_ne_1() : Abstract_test_ne_1::Abstract_test_ne_1() {
      vx_core::refcount += 1;
    }
    Class_test_ne_1::~Class_test_ne_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_ne_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne_1 output = vx_test::e_test_ne_1();
      return output;
    }

    vx_core::Type_any Class_test_ne_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne_1 output = vx_test::e_test_ne_1();
      return output;
    }

    vx_core::Type_typedef Class_test_ne_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_ne_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_ne_1::vx_empty() const {return vx_test::e_test_ne_1();}
    vx_core::Type_any Class_test_ne_1::vx_type() const {return vx_test::t_test_ne_1();}
    vx_core::Type_msgblock Class_test_ne_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_ne_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_ne_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_ne_1(expected, fn_actual, context);
      return output;
    }

  //}

  // (func test-string)
  vx_test::Type_testresult f_test_string(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":passfail"),
        vx_core::f_eq(
          vx_core::f_string_from_any(expected),
          vx_core::f_string_from_any(actual)
        ),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-string", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-string)
  // class Class_test_string {
    Abstract_test_string::~Abstract_test_string() {}

    Class_test_string::Class_test_string() : Abstract_test_string::Abstract_test_string() {
      vx_core::refcount += 1;
    }
    Class_test_string::~Class_test_string() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string output = vx_test::e_test_string();
      return output;
    }

    vx_core::Type_any Class_test_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string output = vx_test::e_test_string();
      return output;
    }

    vx_core::Type_typedef Class_test_string::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_string::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_string::vx_empty() const {return vx_test::e_test_string();}
    vx_core::Type_any Class_test_string::vx_type() const {return vx_test::t_test_string();}
    vx_core::Type_msgblock Class_test_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_string(expected, actual, context);
      return output;
    }

  //}

  // (func test-string)
  vx_test::Type_testresult f_test_string_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":string"),
        vx_core::vx_new_string(":expected"),
        expected,
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-string", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-string)
  // class Class_test_string_1 {
    Abstract_test_string_1::~Abstract_test_string_1() {}

    Class_test_string_1::Class_test_string_1() : Abstract_test_string_1::Abstract_test_string_1() {
      vx_core::refcount += 1;
    }
    Class_test_string_1::~Class_test_string_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_string_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string_1 output = vx_test::e_test_string_1();
      return output;
    }

    vx_core::Type_any Class_test_string_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string_1 output = vx_test::e_test_string_1();
      return output;
    }

    vx_core::Type_typedef Class_test_string_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_string_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_string_1::vx_empty() const {return vx_test::e_test_string_1();}
    vx_core::Type_any Class_test_string_1::vx_type() const {return vx_test::t_test_string_1();}
    vx_core::Type_msgblock Class_test_string_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_string_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_string_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_string_1(expected, fn_actual, context);
      return output;
    }

  //}

  // (func test-true)
  vx_test::Type_testresult f_test_true(vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":true"),
        vx_core::vx_new_string(":passfail"),
        vx_core::f_eq(
          vx_core::vx_new_boolean(true),
          actual
        ),
        vx_core::vx_new_string(":expected"),
        vx_core::vx_new_boolean(true),
        vx_core::vx_new_string(":actual"),
        actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-true", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-true)
  // class Class_test_true {
    Abstract_test_true::~Abstract_test_true() {}

    Class_test_true::Class_test_true() : Abstract_test_true::Abstract_test_true() {
      vx_core::refcount += 1;
    }
    Class_test_true::~Class_test_true() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_true::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true output = vx_test::e_test_true();
      return output;
    }

    vx_core::Type_any Class_test_true::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true output = vx_test::e_test_true();
      return output;
    }

    vx_core::Type_typedef Class_test_true::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_true::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_true::vx_empty() const {return vx_test::e_test_true();}
    vx_core::Type_any Class_test_true::vx_type() const {return vx_test::t_test_true();}
    vx_core::Type_msgblock Class_test_true::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_true::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_true::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_test_true::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_test::f_test_true(inputval, context);
      return output;
    }

    vx_core::Type_any Class_test_true::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_true(actual, context);
      return output;
    }

  //}

  // (func test-true)
  vx_test::Type_testresult f_test_true_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult();
    try {
      output = vx_core::f_new(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":true"),
        vx_core::vx_new_string(":expected"),
        vx_core::vx_new_boolean(true),
        vx_core::vx_new_string(":fn-actual"),
        fn_actual
      })
    );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("test-true", err);
      output = vx_core::vx_copy(vx_test::t_testresult(), {msg});
    }
    return output;
  }

  // (func test-true)
  // class Class_test_true_1 {
    Abstract_test_true_1::~Abstract_test_true_1() {}

    Class_test_true_1::Class_test_true_1() : Abstract_test_true_1::Abstract_test_true_1() {
      vx_core::refcount += 1;
    }
    Class_test_true_1::~Class_test_true_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_test_true_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true_1 output = vx_test::e_test_true_1();
      return output;
    }

    vx_core::Type_any Class_test_true_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true_1 output = vx_test::e_test_true_1();
      return output;
    }

    vx_core::Type_typedef Class_test_true_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresult", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_test_true_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_test_true_1::vx_empty() const {return vx_test::e_test_true_1();}
    vx_core::Type_any Class_test_true_1::vx_type() const {return vx_test::t_test_true_1();}
    vx_core::Type_msgblock Class_test_true_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_true_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_true_1::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_test_true_1::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func_async inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), val);
      output = vx_test::f_test_true_1(inputval, context);
      return output;
    }

    vx_core::Type_any Class_test_true_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_true_1(fn_actual, context);
      return output;
    }

  //}

  // (func tr<-testdescribe-casename)
  vx_web_html::Type_tr f_tr_from_testdescribe_casename(vx_test::Type_testdescribe testdescribe, vx_core::Type_string casename) {
    vx_web_html::Type_tr output = vx_web_html::e_tr();
    output = vx_core::f_let(
      vx_web_html::t_tr(),
      vx_core::t_any_from_func()->vx_fn_new([testdescribe, casename]() {
        vx_core::Type_string describename = testdescribe->describename();
        vx_test::Type_testresult result = testdescribe->testresult();
        vx_core::Type_boolean passfail = result->passfail();
        vx_core::Type_string expected = vx_core::f_string_from_any(
          result->expected()
        );
        vx_core::Type_string actual = vx_core::f_string_from_any(
          result->actual()
        );
        vx_web_html::Type_style prestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test(),
          vx_core::vx_new_string(".preformatted")
        );
        return vx_core::f_new(
          vx_web_html::t_tr(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::f_new(
              vx_web_html::t_td(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_test::f_p_from_passfail(passfail)
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    casename
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    describename
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    expected
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_p(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    actual
                  })
                )
              })
            )
          })
        );
      })
    );
    return output;
  }

  // (func tr<-testdescribe-casename)
  // class Class_tr_from_testdescribe_casename {
    Abstract_tr_from_testdescribe_casename::~Abstract_tr_from_testdescribe_casename() {}

    Class_tr_from_testdescribe_casename::Class_tr_from_testdescribe_casename() : Abstract_tr_from_testdescribe_casename::Abstract_tr_from_testdescribe_casename() {
      vx_core::refcount += 1;
    }
    Class_tr_from_testdescribe_casename::~Class_tr_from_testdescribe_casename() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_tr_from_testdescribe_casename output = vx_test::e_tr_from_testdescribe_casename();
      return output;
    }

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_tr_from_testdescribe_casename output = vx_test::e_tr_from_testdescribe_casename();
      return output;
    }

    vx_core::Type_typedef Class_tr_from_testdescribe_casename::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_tr_from_testdescribe_casename::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_empty() const {return vx_test::e_tr_from_testdescribe_casename();}
    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_type() const {return vx_test::t_tr_from_testdescribe_casename();}
    vx_core::Type_msgblock Class_tr_from_testdescribe_casename::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_tr_from_testdescribe_casename::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string casename = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

  //}

  // (func trlist<-testcase)
  vx_web_html::Type_trlist f_trlist_from_testcase(vx_test::Type_testcase testcase) {
    vx_web_html::Type_trlist output = vx_web_html::e_trlist();
    output = vx_core::f_let(
      vx_web_html::t_trlist(),
      vx_core::t_any_from_func()->vx_fn_new([testcase]() {
        vx_test::Type_testdescribelist describelist = testcase->describelist();
        vx_core::Type_string casename = testcase->casename();
        return vx_core::f_list_from_list(
          vx_web_html::t_trlist(),
          describelist,
          vx_core::t_any_from_any()->vx_fn_new([casename](vx_core::Type_any testdescribe_any) {
            vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe(), testdescribe_any);
            return 
              vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
          })
        );
      })
    );
    return output;
  }

  // (func trlist<-testcase)
  // class Class_trlist_from_testcase {
    Abstract_trlist_from_testcase::~Abstract_trlist_from_testcase() {}

    Class_trlist_from_testcase::Class_trlist_from_testcase() : Abstract_trlist_from_testcase::Abstract_trlist_from_testcase() {
      vx_core::refcount += 1;
    }
    Class_trlist_from_testcase::~Class_trlist_from_testcase() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_trlist_from_testcase::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcase output = vx_test::e_trlist_from_testcase();
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcase output = vx_test::e_trlist_from_testcase();
      return output;
    }

    vx_core::Type_typedef Class_trlist_from_testcase::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_tr()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_trlist_from_testcase::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_empty() const {return vx_test::e_trlist_from_testcase();}
    vx_core::Type_any Class_trlist_from_testcase::vx_type() const {return vx_test::t_trlist_from_testcase();}
    vx_core::Type_msgblock Class_trlist_from_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_trlist_from_testcase::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_trlist_from_testcase::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcase inputval = vx_core::vx_any_from_any(vx_test::t_testcase(), val);
      output = vx_test::f_trlist_from_testcase(inputval);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_trlist_from_testcase(testcase);
      return output;
    }

  //}

  // (func trlist<-testcaselist)
  vx_web_html::Type_trlist f_trlist_from_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_web_html::Type_trlist output = vx_web_html::e_trlist();
    output = vx_core::f_list_join_from_list(
      vx_web_html::t_trlist(),
      testcaselist,
      vx_test::t_trlist_from_testcase()
    );
    return output;
  }

  // (func trlist<-testcaselist)
  // class Class_trlist_from_testcaselist {
    Abstract_trlist_from_testcaselist::~Abstract_trlist_from_testcaselist() {}

    Class_trlist_from_testcaselist::Class_trlist_from_testcaselist() : Abstract_trlist_from_testcaselist::Abstract_trlist_from_testcaselist() {
      vx_core::refcount += 1;
    }
    Class_trlist_from_testcaselist::~Class_trlist_from_testcaselist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_trlist_from_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcaselist output = vx_test::e_trlist_from_testcaselist();
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcaselist output = vx_test::e_trlist_from_testcaselist();
      return output;
    }

    vx_core::Type_typedef Class_trlist_from_testcaselist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_tr()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_trlist_from_testcaselist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_empty() const {return vx_test::e_trlist_from_testcaselist();}
    vx_core::Type_any Class_trlist_from_testcaselist::vx_type() const {return vx_test::t_trlist_from_testcaselist();}
    vx_core::Type_msgblock Class_trlist_from_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_trlist_from_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_trlist_from_testcaselist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist(), val);
      output = vx_test::f_trlist_from_testcaselist(inputval);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_trlist_from_testcaselist(testcaselist);
      return output;
    }

  //}

  vx_test::vx_Class_package* vx_package = new vx_test::vx_Class_package();

  vx_test::Type_testcase e_testcase() {
    vx_test::Type_testcase output = vx_test::vx_package->e_testcase;
    if (output == NULL) {
      output = new Class_testcase();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testcase = output;
    }
    return output;
  }
  vx_test::Type_testcase t_testcase() {
    vx_test::Type_testcase output = vx_test::vx_package->t_testcase;
    if (output == NULL) {
      output = new Class_testcase();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testcase = output;
    }
    return output;
  }

  vx_test::Type_testcaselist e_testcaselist() {
    vx_test::Type_testcaselist output = vx_test::vx_package->e_testcaselist;
    if (output == NULL) {
      output = new Class_testcaselist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testcaselist = output;
    }
    return output;
  }
  vx_test::Type_testcaselist t_testcaselist() {
    vx_test::Type_testcaselist output = vx_test::vx_package->t_testcaselist;
    if (output == NULL) {
      output = new Class_testcaselist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testcaselist = output;
    }
    return output;
  }

  vx_test::Type_testcoveragedetail e_testcoveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_test::vx_package->e_testcoveragedetail;
    if (output == NULL) {
      output = new Class_testcoveragedetail();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testcoveragedetail = output;
    }
    return output;
  }
  vx_test::Type_testcoveragedetail t_testcoveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_test::vx_package->t_testcoveragedetail;
    if (output == NULL) {
      output = new Class_testcoveragedetail();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testcoveragedetail = output;
    }
    return output;
  }

  vx_test::Type_testcoveragenums e_testcoveragenums() {
    vx_test::Type_testcoveragenums output = vx_test::vx_package->e_testcoveragenums;
    if (output == NULL) {
      output = new Class_testcoveragenums();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testcoveragenums = output;
    }
    return output;
  }
  vx_test::Type_testcoveragenums t_testcoveragenums() {
    vx_test::Type_testcoveragenums output = vx_test::vx_package->t_testcoveragenums;
    if (output == NULL) {
      output = new Class_testcoveragenums();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testcoveragenums = output;
    }
    return output;
  }

  vx_test::Type_testcoveragesummary e_testcoveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_test::vx_package->e_testcoveragesummary;
    if (output == NULL) {
      output = new Class_testcoveragesummary();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testcoveragesummary = output;
    }
    return output;
  }
  vx_test::Type_testcoveragesummary t_testcoveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_test::vx_package->t_testcoveragesummary;
    if (output == NULL) {
      output = new Class_testcoveragesummary();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testcoveragesummary = output;
    }
    return output;
  }

  vx_test::Type_testdescribe e_testdescribe() {
    vx_test::Type_testdescribe output = vx_test::vx_package->e_testdescribe;
    if (output == NULL) {
      output = new Class_testdescribe();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testdescribe = output;
    }
    return output;
  }
  vx_test::Type_testdescribe t_testdescribe() {
    vx_test::Type_testdescribe output = vx_test::vx_package->t_testdescribe;
    if (output == NULL) {
      output = new Class_testdescribe();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testdescribe = output;
    }
    return output;
  }

  vx_test::Type_testdescribelist e_testdescribelist() {
    vx_test::Type_testdescribelist output = vx_test::vx_package->e_testdescribelist;
    if (output == NULL) {
      output = new Class_testdescribelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testdescribelist = output;
    }
    return output;
  }
  vx_test::Type_testdescribelist t_testdescribelist() {
    vx_test::Type_testdescribelist output = vx_test::vx_package->t_testdescribelist;
    if (output == NULL) {
      output = new Class_testdescribelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testdescribelist = output;
    }
    return output;
  }

  vx_test::Type_testpackage e_testpackage() {
    vx_test::Type_testpackage output = vx_test::vx_package->e_testpackage;
    if (output == NULL) {
      output = new Class_testpackage();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testpackage = output;
    }
    return output;
  }
  vx_test::Type_testpackage t_testpackage() {
    vx_test::Type_testpackage output = vx_test::vx_package->t_testpackage;
    if (output == NULL) {
      output = new Class_testpackage();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testpackage = output;
    }
    return output;
  }

  vx_test::Type_testpackagelist e_testpackagelist() {
    vx_test::Type_testpackagelist output = vx_test::vx_package->e_testpackagelist;
    if (output == NULL) {
      output = new Class_testpackagelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testpackagelist = output;
    }
    return output;
  }
  vx_test::Type_testpackagelist t_testpackagelist() {
    vx_test::Type_testpackagelist output = vx_test::vx_package->t_testpackagelist;
    if (output == NULL) {
      output = new Class_testpackagelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testpackagelist = output;
    }
    return output;
  }

  vx_test::Type_testresult e_testresult() {
    vx_test::Type_testresult output = vx_test::vx_package->e_testresult;
    if (output == NULL) {
      output = new Class_testresult();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testresult = output;
    }
    return output;
  }
  vx_test::Type_testresult t_testresult() {
    vx_test::Type_testresult output = vx_test::vx_package->t_testresult;
    if (output == NULL) {
      output = new Class_testresult();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testresult = output;
    }
    return output;
  }

  vx_test::Type_testresultlist e_testresultlist() {
    vx_test::Type_testresultlist output = vx_test::vx_package->e_testresultlist;
    if (output == NULL) {
      output = new Class_testresultlist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_testresultlist = output;
    }
    return output;
  }
  vx_test::Type_testresultlist t_testresultlist() {
    vx_test::Type_testresultlist output = vx_test::vx_package->t_testresultlist;
    if (output == NULL) {
      output = new Class_testresultlist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_testresultlist = output;
    }
    return output;
  }

  // (const stylesheet-test)
  vx_test::Const_stylesheet_test c_stylesheet_test() {
    vx_test::Const_stylesheet_test output = vx_test::vx_package->c_stylesheet_test;
    if (output == NULL) {
      output = new vx_test::Class_stylesheet_test();
      vx_core::vx_reserve_type(output);
      vx_web_html::Type_stylesheet val = vx_web_html::f_stylesheet_loadmap(
        vx_core::f_new(
          vx_web_html::t_stylesheet(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("Test Suite"),
            vx_core::vx_new_string(":styles"),
            vx_core::f_new(
              vx_web_html::t_stylelist(),
              vx_core::vx_new(vx_core::t_anylist(), {
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("details summary"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("cursor"),
                        vx_core::vx_new_string("pointer"),
                        vx_core::vx_new_string("display"),
                        vx_core::vx_new_string("inline-flex"),
                        vx_core::vx_new_string("gap"),
                        vx_core::vx_new_string("10px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("table"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("vertical-align"),
                        vx_core::vx_new_string("top"),
                        vx_core::vx_new_string("border-collapse"),
                        vx_core::vx_new_string("collapse"),
                        vx_core::vx_new_string("margin"),
                        vx_core::vx_new_string("25px 0"),
                        vx_core::vx_new_string("font-size"),
                        vx_core::vx_new_string("0.9em"),
                        vx_core::vx_new_string("font-family"),
                        vx_core::vx_new_string("sans-serif"),
                        vx_core::vx_new_string("min-width"),
                        vx_core::vx_new_string("400px"),
                        vx_core::vx_new_string("box-shadow"),
                        vx_core::vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("thead tr"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("#009879"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("#ffffff"),
                        vx_core::vx_new_string("text-align"),
                        vx_core::vx_new_string("left")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("td"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("padding"),
                        vx_core::vx_new_string("10px 10px"),
                        vx_core::vx_new_string("vertical-align"),
                        vx_core::vx_new_string("top")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("border-bottom"),
                        vx_core::vx_new_string("1px solid #dddddd")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr:nth-of-type(even)"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("#f3f3f3")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr:last-of-type"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("border-bottom"),
                        vx_core::vx_new_string("2px solid #009879")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr.active-row"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("font-weight"),
                        vx_core::vx_new_string("bold"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("#009879")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".failflag"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("red"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("white"),
                        vx_core::vx_new_string("padding-left"),
                        vx_core::vx_new_string("4px"),
                        vx_core::vx_new_string("padding-right"),
                        vx_core::vx_new_string("4px"),
                        vx_core::vx_new_string("padding-top"),
                        vx_core::vx_new_string("1px"),
                        vx_core::vx_new_string("padding-bottom"),
                        vx_core::vx_new_string("1px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".passflag"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("green"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("white"),
                        vx_core::vx_new_string("padding-left"),
                        vx_core::vx_new_string("4px"),
                        vx_core::vx_new_string("padding-right"),
                        vx_core::vx_new_string("4px"),
                        vx_core::vx_new_string("padding-top"),
                        vx_core::vx_new_string("1px"),
                        vx_core::vx_new_string("padding-bottom"),
                        vx_core::vx_new_string("1px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragenums"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("width"),
                        vx_core::vx_new_string("90px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepct"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("text-align"),
                        vx_core::vx_new_string("right")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepctgreen"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("green"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("white"),
                        vx_core::vx_new_string("text-align"),
                        vx_core::vx_new_string("right")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepctred"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("red"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("white"),
                        vx_core::vx_new_string("text-align"),
                        vx_core::vx_new_string("right")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".pkgheader"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("display"),
                        vx_core::vx_new_string("inline-flex"),
                        vx_core::vx_new_string("gap"),
                        vx_core::vx_new_string("10px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".pkgname"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("font-weight"),
                        vx_core::vx_new_string("bold"),
                        vx_core::vx_new_string("width"),
                        vx_core::vx_new_string("180px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".preformatted"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("display"),
                        vx_core::vx_new_string("block"),
                        vx_core::vx_new_string("unicode-bidi"),
                        vx_core::vx_new_string("embed"),
                        vx_core::vx_new_string("font-family"),
                        vx_core::vx_new_string("monospace"),
                        vx_core::vx_new_string("white-space"),
                        vx_core::vx_new_string("pre")
                      })
                    )
                  })
                )
              })
            )
          })
        )
      );
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_name = val->name();
      output->vx_p_styles = val->styles();
      output->vx_p_stylemap = val->stylemap();
      vx_test::vx_package->c_stylesheet_test = output;
    }
    return output;
  }

  // (func div<-testcaselist)
  vx_test::Func_div_from_testcaselist e_div_from_testcaselist() {
    vx_test::Func_div_from_testcaselist output = vx_test::vx_package->e_div_from_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testcaselist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_div_from_testcaselist = output;
    }
    return output;
  }
  vx_test::Func_div_from_testcaselist t_div_from_testcaselist() {
    vx_test::Func_div_from_testcaselist output = vx_test::vx_package->t_div_from_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testcaselist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_div_from_testcaselist = output;
    }
    return output;
  }

  // (func div<-testpackage)
  vx_test::Func_div_from_testpackage e_div_from_testpackage() {
    vx_test::Func_div_from_testpackage output = vx_test::vx_package->e_div_from_testpackage;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testpackage();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_div_from_testpackage = output;
    }
    return output;
  }
  vx_test::Func_div_from_testpackage t_div_from_testpackage() {
    vx_test::Func_div_from_testpackage output = vx_test::vx_package->t_div_from_testpackage;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testpackage();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_div_from_testpackage = output;
    }
    return output;
  }

  // (func div<-testpackagelist)
  vx_test::Func_div_from_testpackagelist e_div_from_testpackagelist() {
    vx_test::Func_div_from_testpackagelist output = vx_test::vx_package->e_div_from_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testpackagelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_div_from_testpackagelist = output;
    }
    return output;
  }
  vx_test::Func_div_from_testpackagelist t_div_from_testpackagelist() {
    vx_test::Func_div_from_testpackagelist output = vx_test::vx_package->t_div_from_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_div_from_testpackagelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_div_from_testpackagelist = output;
    }
    return output;
  }

  // (func divchildlist<-testpackagelist)
  vx_test::Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist() {
    vx_test::Func_divchildlist_from_testpackagelist output = vx_test::vx_package->e_divchildlist_from_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_divchildlist_from_testpackagelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_divchildlist_from_testpackagelist = output;
    }
    return output;
  }
  vx_test::Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist() {
    vx_test::Func_divchildlist_from_testpackagelist output = vx_test::vx_package->t_divchildlist_from_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_divchildlist_from_testpackagelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_divchildlist_from_testpackagelist = output;
    }
    return output;
  }

  // (func file-test)
  vx_test::Func_file_test e_file_test() {
    vx_test::Func_file_test output = vx_test::vx_package->e_file_test;
    if (output == NULL) {
      output = new vx_test::Class_file_test();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_file_test = output;
    }
    return output;
  }
  vx_test::Func_file_test t_file_test() {
    vx_test::Func_file_test output = vx_test::vx_package->t_file_test;
    if (output == NULL) {
      output = new vx_test::Class_file_test();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_file_test = output;
    }
    return output;
  }

  // (func file-testhtml)
  vx_test::Func_file_testhtml e_file_testhtml() {
    vx_test::Func_file_testhtml output = vx_test::vx_package->e_file_testhtml;
    if (output == NULL) {
      output = new vx_test::Class_file_testhtml();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_file_testhtml = output;
    }
    return output;
  }
  vx_test::Func_file_testhtml t_file_testhtml() {
    vx_test::Func_file_testhtml output = vx_test::vx_package->t_file_testhtml;
    if (output == NULL) {
      output = new vx_test::Class_file_testhtml();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_file_testhtml = output;
    }
    return output;
  }

  // (func file-testnode)
  vx_test::Func_file_testnode e_file_testnode() {
    vx_test::Func_file_testnode output = vx_test::vx_package->e_file_testnode;
    if (output == NULL) {
      output = new vx_test::Class_file_testnode();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_file_testnode = output;
    }
    return output;
  }
  vx_test::Func_file_testnode t_file_testnode() {
    vx_test::Func_file_testnode output = vx_test::vx_package->t_file_testnode;
    if (output == NULL) {
      output = new vx_test::Class_file_testnode();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_file_testnode = output;
    }
    return output;
  }

  // (func html<-divtest)
  vx_test::Func_html_from_divtest e_html_from_divtest() {
    vx_test::Func_html_from_divtest output = vx_test::vx_package->e_html_from_divtest;
    if (output == NULL) {
      output = new vx_test::Class_html_from_divtest();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_html_from_divtest = output;
    }
    return output;
  }
  vx_test::Func_html_from_divtest t_html_from_divtest() {
    vx_test::Func_html_from_divtest output = vx_test::vx_package->t_html_from_divtest;
    if (output == NULL) {
      output = new vx_test::Class_html_from_divtest();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_html_from_divtest = output;
    }
    return output;
  }

  // (func p<-passfail)
  vx_test::Func_p_from_passfail e_p_from_passfail() {
    vx_test::Func_p_from_passfail output = vx_test::vx_package->e_p_from_passfail;
    if (output == NULL) {
      output = new vx_test::Class_p_from_passfail();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_p_from_passfail = output;
    }
    return output;
  }
  vx_test::Func_p_from_passfail t_p_from_passfail() {
    vx_test::Func_p_from_passfail output = vx_test::vx_package->t_p_from_passfail;
    if (output == NULL) {
      output = new vx_test::Class_p_from_passfail();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_p_from_passfail = output;
    }
    return output;
  }

  // (func p<-testcoveragenums)
  vx_test::Func_p_from_testcoveragenums e_p_from_testcoveragenums() {
    vx_test::Func_p_from_testcoveragenums output = vx_test::vx_package->e_p_from_testcoveragenums;
    if (output == NULL) {
      output = new vx_test::Class_p_from_testcoveragenums();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_p_from_testcoveragenums = output;
    }
    return output;
  }
  vx_test::Func_p_from_testcoveragenums t_p_from_testcoveragenums() {
    vx_test::Func_p_from_testcoveragenums output = vx_test::vx_package->t_p_from_testcoveragenums;
    if (output == NULL) {
      output = new vx_test::Class_p_from_testcoveragenums();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_p_from_testcoveragenums = output;
    }
    return output;
  }

  // (func resolve-testcase)
  vx_test::Func_resolve_testcase e_resolve_testcase() {
    vx_test::Func_resolve_testcase output = vx_test::vx_package->e_resolve_testcase;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testcase();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testcase = output;
    }
    return output;
  }
  vx_test::Func_resolve_testcase t_resolve_testcase() {
    vx_test::Func_resolve_testcase output = vx_test::vx_package->t_resolve_testcase;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testcase();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testcase = output;
    }
    return output;
  }

  // (func resolve-testcaselist)
  vx_test::Func_resolve_testcaselist e_resolve_testcaselist() {
    vx_test::Func_resolve_testcaselist output = vx_test::vx_package->e_resolve_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testcaselist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testcaselist = output;
    }
    return output;
  }
  vx_test::Func_resolve_testcaselist t_resolve_testcaselist() {
    vx_test::Func_resolve_testcaselist output = vx_test::vx_package->t_resolve_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testcaselist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testcaselist = output;
    }
    return output;
  }

  // (func resolve-testdescribe)
  vx_test::Func_resolve_testdescribe e_resolve_testdescribe() {
    vx_test::Func_resolve_testdescribe output = vx_test::vx_package->e_resolve_testdescribe;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testdescribe();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testdescribe = output;
    }
    return output;
  }
  vx_test::Func_resolve_testdescribe t_resolve_testdescribe() {
    vx_test::Func_resolve_testdescribe output = vx_test::vx_package->t_resolve_testdescribe;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testdescribe();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testdescribe = output;
    }
    return output;
  }

  // (func resolve-testdescribelist)
  vx_test::Func_resolve_testdescribelist e_resolve_testdescribelist() {
    vx_test::Func_resolve_testdescribelist output = vx_test::vx_package->e_resolve_testdescribelist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testdescribelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testdescribelist = output;
    }
    return output;
  }
  vx_test::Func_resolve_testdescribelist t_resolve_testdescribelist() {
    vx_test::Func_resolve_testdescribelist output = vx_test::vx_package->t_resolve_testdescribelist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testdescribelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testdescribelist = output;
    }
    return output;
  }

  // (func resolve-testpackage)
  vx_test::Func_resolve_testpackage e_resolve_testpackage() {
    vx_test::Func_resolve_testpackage output = vx_test::vx_package->e_resolve_testpackage;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testpackage();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testpackage = output;
    }
    return output;
  }
  vx_test::Func_resolve_testpackage t_resolve_testpackage() {
    vx_test::Func_resolve_testpackage output = vx_test::vx_package->t_resolve_testpackage;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testpackage();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testpackage = output;
    }
    return output;
  }

  // (func resolve-testpackagelist)
  vx_test::Func_resolve_testpackagelist e_resolve_testpackagelist() {
    vx_test::Func_resolve_testpackagelist output = vx_test::vx_package->e_resolve_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testpackagelist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testpackagelist = output;
    }
    return output;
  }
  vx_test::Func_resolve_testpackagelist t_resolve_testpackagelist() {
    vx_test::Func_resolve_testpackagelist output = vx_test::vx_package->t_resolve_testpackagelist;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testpackagelist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testpackagelist = output;
    }
    return output;
  }

  // (func resolve-testresult)
  vx_test::Func_resolve_testresult e_resolve_testresult() {
    vx_test::Func_resolve_testresult output = vx_test::vx_package->e_resolve_testresult;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testresult();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_resolve_testresult = output;
    }
    return output;
  }
  vx_test::Func_resolve_testresult t_resolve_testresult() {
    vx_test::Func_resolve_testresult output = vx_test::vx_package->t_resolve_testresult;
    if (output == NULL) {
      output = new vx_test::Class_resolve_testresult();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_resolve_testresult = output;
    }
    return output;
  }

  // (func test)
  vx_test::Func_test e_test() {
    vx_test::Func_test output = vx_test::vx_package->e_test;
    if (output == NULL) {
      output = new vx_test::Class_test();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test = output;
    }
    return output;
  }
  vx_test::Func_test t_test() {
    vx_test::Func_test output = vx_test::vx_package->t_test;
    if (output == NULL) {
      output = new vx_test::Class_test();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test = output;
    }
    return output;
  }

  // (func test)
  vx_test::Func_test_1 e_test_1() {
    vx_test::Func_test_1 output = vx_test::vx_package->e_test_1;
    if (output == NULL) {
      output = new vx_test::Class_test_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_1 = output;
    }
    return output;
  }
  vx_test::Func_test_1 t_test_1() {
    vx_test::Func_test_1 output = vx_test::vx_package->t_test_1;
    if (output == NULL) {
      output = new vx_test::Class_test_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_1 = output;
    }
    return output;
  }

  // (func test-false)
  vx_test::Func_test_false e_test_false() {
    vx_test::Func_test_false output = vx_test::vx_package->e_test_false;
    if (output == NULL) {
      output = new vx_test::Class_test_false();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_false = output;
    }
    return output;
  }
  vx_test::Func_test_false t_test_false() {
    vx_test::Func_test_false output = vx_test::vx_package->t_test_false;
    if (output == NULL) {
      output = new vx_test::Class_test_false();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_false = output;
    }
    return output;
  }

  // (func test-false)
  vx_test::Func_test_false_1 e_test_false_1() {
    vx_test::Func_test_false_1 output = vx_test::vx_package->e_test_false_1;
    if (output == NULL) {
      output = new vx_test::Class_test_false_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_false_1 = output;
    }
    return output;
  }
  vx_test::Func_test_false_1 t_test_false_1() {
    vx_test::Func_test_false_1 output = vx_test::vx_package->t_test_false_1;
    if (output == NULL) {
      output = new vx_test::Class_test_false_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_false_1 = output;
    }
    return output;
  }

  // (func test-gt)
  vx_test::Func_test_gt e_test_gt() {
    vx_test::Func_test_gt output = vx_test::vx_package->e_test_gt;
    if (output == NULL) {
      output = new vx_test::Class_test_gt();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_gt = output;
    }
    return output;
  }
  vx_test::Func_test_gt t_test_gt() {
    vx_test::Func_test_gt output = vx_test::vx_package->t_test_gt;
    if (output == NULL) {
      output = new vx_test::Class_test_gt();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_gt = output;
    }
    return output;
  }

  // (func test-gt)
  vx_test::Func_test_gt_1 e_test_gt_1() {
    vx_test::Func_test_gt_1 output = vx_test::vx_package->e_test_gt_1;
    if (output == NULL) {
      output = new vx_test::Class_test_gt_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_gt_1 = output;
    }
    return output;
  }
  vx_test::Func_test_gt_1 t_test_gt_1() {
    vx_test::Func_test_gt_1 output = vx_test::vx_package->t_test_gt_1;
    if (output == NULL) {
      output = new vx_test::Class_test_gt_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_gt_1 = output;
    }
    return output;
  }

  // (func test-ne)
  vx_test::Func_test_ne e_test_ne() {
    vx_test::Func_test_ne output = vx_test::vx_package->e_test_ne;
    if (output == NULL) {
      output = new vx_test::Class_test_ne();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_ne = output;
    }
    return output;
  }
  vx_test::Func_test_ne t_test_ne() {
    vx_test::Func_test_ne output = vx_test::vx_package->t_test_ne;
    if (output == NULL) {
      output = new vx_test::Class_test_ne();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_ne = output;
    }
    return output;
  }

  // (func test-ne)
  vx_test::Func_test_ne_1 e_test_ne_1() {
    vx_test::Func_test_ne_1 output = vx_test::vx_package->e_test_ne_1;
    if (output == NULL) {
      output = new vx_test::Class_test_ne_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_ne_1 = output;
    }
    return output;
  }
  vx_test::Func_test_ne_1 t_test_ne_1() {
    vx_test::Func_test_ne_1 output = vx_test::vx_package->t_test_ne_1;
    if (output == NULL) {
      output = new vx_test::Class_test_ne_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_ne_1 = output;
    }
    return output;
  }

  // (func test-string)
  vx_test::Func_test_string e_test_string() {
    vx_test::Func_test_string output = vx_test::vx_package->e_test_string;
    if (output == NULL) {
      output = new vx_test::Class_test_string();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_string = output;
    }
    return output;
  }
  vx_test::Func_test_string t_test_string() {
    vx_test::Func_test_string output = vx_test::vx_package->t_test_string;
    if (output == NULL) {
      output = new vx_test::Class_test_string();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_string = output;
    }
    return output;
  }

  // (func test-string)
  vx_test::Func_test_string_1 e_test_string_1() {
    vx_test::Func_test_string_1 output = vx_test::vx_package->e_test_string_1;
    if (output == NULL) {
      output = new vx_test::Class_test_string_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_string_1 = output;
    }
    return output;
  }
  vx_test::Func_test_string_1 t_test_string_1() {
    vx_test::Func_test_string_1 output = vx_test::vx_package->t_test_string_1;
    if (output == NULL) {
      output = new vx_test::Class_test_string_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_string_1 = output;
    }
    return output;
  }

  // (func test-true)
  vx_test::Func_test_true e_test_true() {
    vx_test::Func_test_true output = vx_test::vx_package->e_test_true;
    if (output == NULL) {
      output = new vx_test::Class_test_true();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_true = output;
    }
    return output;
  }
  vx_test::Func_test_true t_test_true() {
    vx_test::Func_test_true output = vx_test::vx_package->t_test_true;
    if (output == NULL) {
      output = new vx_test::Class_test_true();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_true = output;
    }
    return output;
  }

  // (func test-true)
  vx_test::Func_test_true_1 e_test_true_1() {
    vx_test::Func_test_true_1 output = vx_test::vx_package->e_test_true_1;
    if (output == NULL) {
      output = new vx_test::Class_test_true_1();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_test_true_1 = output;
    }
    return output;
  }
  vx_test::Func_test_true_1 t_test_true_1() {
    vx_test::Func_test_true_1 output = vx_test::vx_package->t_test_true_1;
    if (output == NULL) {
      output = new vx_test::Class_test_true_1();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_test_true_1 = output;
    }
    return output;
  }

  // (func tr<-testdescribe-casename)
  vx_test::Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename() {
    vx_test::Func_tr_from_testdescribe_casename output = vx_test::vx_package->e_tr_from_testdescribe_casename;
    if (output == NULL) {
      output = new vx_test::Class_tr_from_testdescribe_casename();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_tr_from_testdescribe_casename = output;
    }
    return output;
  }
  vx_test::Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename() {
    vx_test::Func_tr_from_testdescribe_casename output = vx_test::vx_package->t_tr_from_testdescribe_casename;
    if (output == NULL) {
      output = new vx_test::Class_tr_from_testdescribe_casename();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_tr_from_testdescribe_casename = output;
    }
    return output;
  }

  // (func trlist<-testcase)
  vx_test::Func_trlist_from_testcase e_trlist_from_testcase() {
    vx_test::Func_trlist_from_testcase output = vx_test::vx_package->e_trlist_from_testcase;
    if (output == NULL) {
      output = new vx_test::Class_trlist_from_testcase();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_trlist_from_testcase = output;
    }
    return output;
  }
  vx_test::Func_trlist_from_testcase t_trlist_from_testcase() {
    vx_test::Func_trlist_from_testcase output = vx_test::vx_package->t_trlist_from_testcase;
    if (output == NULL) {
      output = new vx_test::Class_trlist_from_testcase();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_trlist_from_testcase = output;
    }
    return output;
  }

  // (func trlist<-testcaselist)
  vx_test::Func_trlist_from_testcaselist e_trlist_from_testcaselist() {
    vx_test::Func_trlist_from_testcaselist output = vx_test::vx_package->e_trlist_from_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_trlist_from_testcaselist();
      vx_core::vx_reserve_empty(output);
      vx_test::vx_package->e_trlist_from_testcaselist = output;
    }
    return output;
  }
  vx_test::Func_trlist_from_testcaselist t_trlist_from_testcaselist() {
    vx_test::Func_trlist_from_testcaselist output = vx_test::vx_package->t_trlist_from_testcaselist;
    if (output == NULL) {
      output = new vx_test::Class_trlist_from_testcaselist();
      vx_core::vx_reserve_type(output);
      vx_test::vx_package->t_trlist_from_testcaselist = output;
    }
    return output;
  }

}