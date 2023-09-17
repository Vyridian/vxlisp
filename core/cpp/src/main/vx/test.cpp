#include <exception>
#include <map>
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_passfail,
        this->vx_p_testpkg,
        this->vx_p_casename,
        this->vx_p_describelist
      });
    }

    // passfail()
    vx_core::Type_boolean Class_testcase::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcase::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // casename()
    vx_core::Type_string Class_testcase::casename() const {
      vx_core::Type_string output = this->vx_p_casename;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // describelist()
    vx_test::Type_testdescribelist Class_testcase::describelist() const {
      vx_test::Type_testdescribelist output = this->vx_p_describelist;
      if (!output) {
        output = vx_test::e_testdescribelist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcase::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testcase, vals);
    }

    vx_core::Type_any Class_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcase output = vx_test::e_testcase;
      vx_test::Type_testcase val = vx_core::vx_any_from_any(vx_test::t_testcase, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_string vx_p_casename = val->casename();
      vx_test::Type_testdescribelist vx_p_describelist = val->describelist();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":casename") {
            if (valsubtype == vx_core::t_string) {
              vx_p_casename = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase :casename " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":describelist") {
            if (valsubtype == vx_test::t_testdescribelist) {
              vx_p_describelist = vx_core::vx_any_from_any(vx_test::t_testdescribelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase :describelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcase) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcase();
      if (output->vx_p_passfail != vx_p_passfail) {
        if (output->vx_p_passfail) {
          vx_core::vx_release_one(output->vx_p_passfail);
        }
        output->vx_p_passfail = vx_p_passfail;
        vx_core::vx_reserve(vx_p_passfail);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (output->vx_p_casename != vx_p_casename) {
        if (output->vx_p_casename) {
          vx_core::vx_release_one(output->vx_p_casename);
        }
        output->vx_p_casename = vx_p_casename;
        vx_core::vx_reserve(vx_p_casename);
      }
      if (output->vx_p_describelist != vx_p_describelist) {
        if (output->vx_p_describelist) {
          vx_core::vx_release_one(output->vx_p_describelist);
        }
        output->vx_p_describelist = vx_p_describelist;
        vx_core::vx_reserve(vx_p_describelist);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcase::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcase::vx_empty() const {return vx_test::e_testcase;}
    vx_core::Type_any Class_testcase::vx_type() const {return vx_test::t_testcase;}

    vx_core::Type_typedef Class_testcase::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "passfail", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "casename", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "describelist", // name
            vx_test::t_testdescribelist // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_testcaselist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testcase Class_testcaselist::vx_get_testcase(vx_core::Type_int index) const {
      vx_test::Type_testcase output = vx_test::e_testcase;
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testcase> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_test::Type_testcase> Class_testcaselist::vx_listtestcase() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testcaselist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testcase(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testcaselist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testcaselist output = vx_test::e_testcaselist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_test::Type_testcase> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_test::t_testcase) {
          vx_test::Type_testcase castval = vx_core::vx_any_from_any(vx_test::t_testcase, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(testcaselist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testcaselist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testcaselist, vals);
    }

    vx_core::Type_any Class_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcaselist output = vx_test::e_testcaselist;
      vx_test::Type_testcaselist val = vx_core::vx_any_from_any(vx_test::t_testcaselist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testcase> listval = val->vx_listtestcase();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testcase) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testcase, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_test::t_testcase)) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testcase, valsub));
        } else if (valsubtype == vx_test::t_testcaselist) {
          vx_test::Type_testcaselist multi = vx_core::vx_any_from_any(vx_test::t_testcaselist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestcase());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcaselist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testcaselist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcaselist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcaselist::vx_empty() const {return vx_test::e_testcaselist;}
    vx_core::Type_any Class_testcaselist::vx_type() const {return vx_test::t_testcaselist;}

    vx_core::Type_typedef Class_testcaselist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_test::t_testcase}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_constmap,
        this->vx_p_funcmap,
        this->vx_p_testpkg,
        this->vx_p_typemap
      });
    }

    // constmap()
    vx_core::Type_intmap Class_testcoveragedetail::constmap() const {
      vx_core::Type_intmap output = this->vx_p_constmap;
      if (!output) {
        output = vx_core::e_intmap;
      }
      return output;
    }

    // funcmap()
    vx_core::Type_intmap Class_testcoveragedetail::funcmap() const {
      vx_core::Type_intmap output = this->vx_p_funcmap;
      if (!output) {
        output = vx_core::e_intmap;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragedetail::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // typemap()
    vx_core::Type_intmap Class_testcoveragedetail::typemap() const {
      vx_core::Type_intmap output = this->vx_p_typemap;
      if (!output) {
        output = vx_core::e_intmap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragedetail::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testcoveragedetail, vals);
    }

    vx_core::Type_any Class_testcoveragedetail::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragedetail output = vx_test::e_testcoveragedetail;
      vx_test::Type_testcoveragedetail val = vx_core::vx_any_from_any(vx_test::t_testcoveragedetail, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_intmap vx_p_constmap = val->constmap();
      vx_core::Type_intmap vx_p_funcmap = val->funcmap();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_intmap vx_p_typemap = val->typemap();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":constmap") {
            if (valsubtype == vx_core::t_intmap) {
              vx_p_constmap = vx_core::vx_any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail :constmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":funcmap") {
            if (valsubtype == vx_core::t_intmap) {
              vx_p_funcmap = vx_core::vx_any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail :funcmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":typemap") {
            if (valsubtype == vx_core::t_intmap) {
              vx_p_typemap = vx_core::vx_any_from_any(vx_core::t_intmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail :typemap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragedetail) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragedetail();
      if (output->vx_p_constmap != vx_p_constmap) {
        if (output->vx_p_constmap) {
          vx_core::vx_release_one(output->vx_p_constmap);
        }
        output->vx_p_constmap = vx_p_constmap;
        vx_core::vx_reserve(vx_p_constmap);
      }
      if (output->vx_p_funcmap != vx_p_funcmap) {
        if (output->vx_p_funcmap) {
          vx_core::vx_release_one(output->vx_p_funcmap);
        }
        output->vx_p_funcmap = vx_p_funcmap;
        vx_core::vx_reserve(vx_p_funcmap);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (output->vx_p_typemap != vx_p_typemap) {
        if (output->vx_p_typemap) {
          vx_core::vx_release_one(output->vx_p_typemap);
        }
        output->vx_p_typemap = vx_p_typemap;
        vx_core::vx_reserve(vx_p_typemap);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragedetail::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragedetail::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragedetail::vx_empty() const {return vx_test::e_testcoveragedetail;}
    vx_core::Type_any Class_testcoveragedetail::vx_type() const {return vx_test::t_testcoveragedetail;}

    vx_core::Type_typedef Class_testcoveragedetail::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "constmap", // name
            vx_core::t_intmap // type
          ),
          vx_core::vx_new_arg(
            "funcmap", // name
            vx_core::t_intmap // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "typemap", // name
            vx_core::t_intmap // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_pct,
        this->vx_p_testpkg,
        this->vx_p_tests,
        this->vx_p_total
      });
    }

    // pct()
    vx_core::Type_int Class_testcoveragenums::pct() const {
      vx_core::Type_int output = this->vx_p_pct;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragenums::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // tests()
    vx_core::Type_int Class_testcoveragenums::tests() const {
      vx_core::Type_int output = this->vx_p_tests;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // total()
    vx_core::Type_int Class_testcoveragenums::total() const {
      vx_core::Type_int output = this->vx_p_total;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragenums::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testcoveragenums, vals);
    }

    vx_core::Type_any Class_testcoveragenums::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragenums output = vx_test::e_testcoveragenums;
      vx_test::Type_testcoveragenums val = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_pct = val->pct();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_core::Type_int vx_p_tests = val->tests();
      vx_core::Type_int vx_p_total = val->total();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pct") {
            if (valsubtype == vx_core::t_int) {
              vx_p_pct = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums :pct " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tests") {
            if (valsubtype == vx_core::t_int) {
              vx_p_tests = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums :tests " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":total") {
            if (valsubtype == vx_core::t_int) {
              vx_p_total = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums :total " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragenums) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragenums();
      if (output->vx_p_pct != vx_p_pct) {
        if (output->vx_p_pct) {
          vx_core::vx_release_one(output->vx_p_pct);
        }
        output->vx_p_pct = vx_p_pct;
        vx_core::vx_reserve(vx_p_pct);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (output->vx_p_tests != vx_p_tests) {
        if (output->vx_p_tests) {
          vx_core::vx_release_one(output->vx_p_tests);
        }
        output->vx_p_tests = vx_p_tests;
        vx_core::vx_reserve(vx_p_tests);
      }
      if (output->vx_p_total != vx_p_total) {
        if (output->vx_p_total) {
          vx_core::vx_release_one(output->vx_p_total);
        }
        output->vx_p_total = vx_p_total;
        vx_core::vx_reserve(vx_p_total);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragenums::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragenums::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragenums::vx_empty() const {return vx_test::e_testcoveragenums;}
    vx_core::Type_any Class_testcoveragenums::vx_type() const {return vx_test::t_testcoveragenums;}

    vx_core::Type_typedef Class_testcoveragenums::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "pct", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "tests", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "total", // name
            vx_core::t_int // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_bigospacenums,
        this->vx_p_bigotimenums,
        this->vx_p_constnums,
        this->vx_p_docnums,
        this->vx_p_funcnums,
        this->vx_p_testpkg,
        this->vx_p_totalnums,
        this->vx_p_typenums
      });
    }

    // bigospacenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::bigospacenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_bigospacenums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // bigotimenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::bigotimenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_bigotimenums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // constnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::constnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_constnums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // docnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::docnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_docnums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // funcnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::funcnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_funcnums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testcoveragesummary::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // totalnums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::totalnums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_totalnums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // typenums()
    vx_test::Type_testcoveragenums Class_testcoveragesummary::typenums() const {
      vx_test::Type_testcoveragenums output = this->vx_p_typenums;
      if (!output) {
        output = vx_test::e_testcoveragenums;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testcoveragesummary::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testcoveragesummary, vals);
    }

    vx_core::Type_any Class_testcoveragesummary::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testcoveragesummary output = vx_test::e_testcoveragesummary;
      vx_test::Type_testcoveragesummary val = vx_core::vx_any_from_any(vx_test::t_testcoveragesummary, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
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
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":bigospacenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_bigospacenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :bigospacenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":bigotimenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_bigotimenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :bigotimenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":constnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_constnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :constnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":docnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_docnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :docnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":funcnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_funcnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :funcnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":totalnums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_totalnums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :totalnums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":typenums") {
            if (valsubtype == vx_test::t_testcoveragenums) {
              vx_p_typenums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary :typenums " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testcoveragesummary) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testcoveragesummary();
      if (output->vx_p_bigospacenums != vx_p_bigospacenums) {
        if (output->vx_p_bigospacenums) {
          vx_core::vx_release_one(output->vx_p_bigospacenums);
        }
        output->vx_p_bigospacenums = vx_p_bigospacenums;
        vx_core::vx_reserve(vx_p_bigospacenums);
      }
      if (output->vx_p_bigotimenums != vx_p_bigotimenums) {
        if (output->vx_p_bigotimenums) {
          vx_core::vx_release_one(output->vx_p_bigotimenums);
        }
        output->vx_p_bigotimenums = vx_p_bigotimenums;
        vx_core::vx_reserve(vx_p_bigotimenums);
      }
      if (output->vx_p_constnums != vx_p_constnums) {
        if (output->vx_p_constnums) {
          vx_core::vx_release_one(output->vx_p_constnums);
        }
        output->vx_p_constnums = vx_p_constnums;
        vx_core::vx_reserve(vx_p_constnums);
      }
      if (output->vx_p_docnums != vx_p_docnums) {
        if (output->vx_p_docnums) {
          vx_core::vx_release_one(output->vx_p_docnums);
        }
        output->vx_p_docnums = vx_p_docnums;
        vx_core::vx_reserve(vx_p_docnums);
      }
      if (output->vx_p_funcnums != vx_p_funcnums) {
        if (output->vx_p_funcnums) {
          vx_core::vx_release_one(output->vx_p_funcnums);
        }
        output->vx_p_funcnums = vx_p_funcnums;
        vx_core::vx_reserve(vx_p_funcnums);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (output->vx_p_totalnums != vx_p_totalnums) {
        if (output->vx_p_totalnums) {
          vx_core::vx_release_one(output->vx_p_totalnums);
        }
        output->vx_p_totalnums = vx_p_totalnums;
        vx_core::vx_reserve(vx_p_totalnums);
      }
      if (output->vx_p_typenums != vx_p_typenums) {
        if (output->vx_p_typenums) {
          vx_core::vx_release_one(output->vx_p_typenums);
        }
        output->vx_p_typenums = vx_p_typenums;
        vx_core::vx_reserve(vx_p_typenums);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testcoveragesummary::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testcoveragesummary::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testcoveragesummary::vx_empty() const {return vx_test::e_testcoveragesummary;}
    vx_core::Type_any Class_testcoveragesummary::vx_type() const {return vx_test::t_testcoveragesummary;}

    vx_core::Type_typedef Class_testcoveragesummary::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "bigospacenums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "bigotimenums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "constnums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "docnums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "funcnums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "totalnums", // name
            vx_test::t_testcoveragenums // type
          ),
          vx_core::vx_new_arg(
            "typenums", // name
            vx_test::t_testcoveragenums // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_describename,
        this->vx_p_testpkg,
        this->vx_p_testresult
      });
    }

    // describename()
    vx_core::Type_string Class_testdescribe::describename() const {
      vx_core::Type_string output = this->vx_p_describename;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testdescribe::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // testresult()
    vx_test::Type_testresult Class_testdescribe::testresult() const {
      vx_test::Type_testresult output = this->vx_p_testresult;
      if (!output) {
        output = vx_test::e_testresult;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testdescribe::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":describename") {
        output = this->describename();
      } else if (skey == ":testpkg") {
        output = this->testpkg();
      } else if (skey == ":testresult") {
        output = this->testresult();
      }
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testdescribe, vals);
    }

    vx_core::Type_any Class_testdescribe::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testdescribe output = vx_test::e_testdescribe;
      vx_test::Type_testdescribe val = vx_core::vx_any_from_any(vx_test::t_testdescribe, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_describename = val->describename();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      vx_test::Type_testresult vx_p_testresult = val->testresult();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribe) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":describename") {
            if (valsubtype == vx_core::t_string) {
              vx_p_describename = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribe :describename " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribe :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testresult") {
            if (valsubtype == vx_test::t_testresult) {
              vx_p_testresult = vx_core::vx_any_from_any(vx_test::t_testresult, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribe :testresult " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribe) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testdescribe();
      if (output->vx_p_describename != vx_p_describename) {
        if (output->vx_p_describename) {
          vx_core::vx_release_one(output->vx_p_describename);
        }
        output->vx_p_describename = vx_p_describename;
        vx_core::vx_reserve(vx_p_describename);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (output->vx_p_testresult != vx_p_testresult) {
        if (output->vx_p_testresult) {
          vx_core::vx_release_one(output->vx_p_testresult);
        }
        output->vx_p_testresult = vx_p_testresult;
        vx_core::vx_reserve(vx_p_testresult);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testdescribe::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testdescribe::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testdescribe::vx_empty() const {return vx_test::e_testdescribe;}
    vx_core::Type_any Class_testdescribe::vx_type() const {return vx_test::t_testdescribe;}

    vx_core::Type_typedef Class_testdescribe::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "describename", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "testresult", // name
            vx_test::t_testresult // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_testdescribelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testdescribe Class_testdescribelist::vx_get_testdescribe(vx_core::Type_int index) const {
      vx_test::Type_testdescribe output = vx_test::e_testdescribe;
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testdescribe> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_test::Type_testdescribe> Class_testdescribelist::vx_listtestdescribe() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testdescribelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testdescribe(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testdescribelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testdescribelist output = vx_test::e_testdescribelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_test::Type_testdescribe> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_test::t_testdescribe) {
          vx_test::Type_testdescribe castval = vx_core::vx_any_from_any(vx_test::t_testdescribe, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(testdescribelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testdescribelist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_testdescribelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testdescribelist, vals);
    }

    vx_core::Type_any Class_testdescribelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testdescribelist output = vx_test::e_testdescribelist;
      vx_test::Type_testdescribelist val = vx_core::vx_any_from_any(vx_test::t_testdescribelist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testdescribe> listval = val->vx_listtestdescribe();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testdescribe) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testdescribe, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_test::t_testdescribe)) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testdescribe, valsub));
        } else if (valsubtype == vx_test::t_testdescribelist) {
          vx_test::Type_testdescribelist multi = vx_core::vx_any_from_any(vx_test::t_testdescribelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestdescribe());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testdescribelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testdescribelist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testdescribelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testdescribelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testdescribelist::vx_empty() const {return vx_test::e_testdescribelist;}
    vx_core::Type_any Class_testdescribelist::vx_type() const {return vx_test::t_testdescribelist;}

    vx_core::Type_typedef Class_testdescribelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_test::t_testdescribe}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_caselist,
        this->vx_p_coveragedetail,
        this->vx_p_coveragesummary,
        this->vx_p_passfail,
        this->vx_p_testpkg
      });
    }

    // caselist()
    vx_test::Type_testcaselist Class_testpackage::caselist() const {
      vx_test::Type_testcaselist output = this->vx_p_caselist;
      if (!output) {
        output = vx_test::e_testcaselist;
      }
      return output;
    }

    // coveragedetail()
    vx_test::Type_testcoveragedetail Class_testpackage::coveragedetail() const {
      vx_test::Type_testcoveragedetail output = this->vx_p_coveragedetail;
      if (!output) {
        output = vx_test::e_testcoveragedetail;
      }
      return output;
    }

    // coveragesummary()
    vx_test::Type_testcoveragesummary Class_testpackage::coveragesummary() const {
      vx_test::Type_testcoveragesummary output = this->vx_p_coveragesummary;
      if (!output) {
        output = vx_test::e_testcoveragesummary;
      }
      return output;
    }

    // passfail()
    vx_core::Type_boolean Class_testpackage::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // testpkg()
    vx_core::Type_string Class_testpackage::testpkg() const {
      vx_core::Type_string output = this->vx_p_testpkg;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testpackage::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testpackage, vals);
    }

    vx_core::Type_any Class_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testpackage output = vx_test::e_testpackage;
      vx_test::Type_testpackage val = vx_core::vx_any_from_any(vx_test::t_testpackage, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_test::Type_testcaselist vx_p_caselist = val->caselist();
      vx_test::Type_testcoveragedetail vx_p_coveragedetail = val->coveragedetail();
      vx_test::Type_testcoveragesummary vx_p_coveragesummary = val->coveragesummary();
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_string vx_p_testpkg = val->testpkg();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":caselist") {
            if (valsubtype == vx_test::t_testcaselist) {
              vx_p_caselist = vx_core::vx_any_from_any(vx_test::t_testcaselist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage :caselist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":coveragedetail") {
            if (valsubtype == vx_test::t_testcoveragedetail) {
              vx_p_coveragedetail = vx_core::vx_any_from_any(vx_test::t_testcoveragedetail, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage :coveragedetail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":coveragesummary") {
            if (valsubtype == vx_test::t_testcoveragesummary) {
              vx_p_coveragesummary = vx_core::vx_any_from_any(vx_test::t_testcoveragesummary, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage :coveragesummary " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":testpkg") {
            if (valsubtype == vx_core::t_string) {
              vx_p_testpkg = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage :testpkg " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackage) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testpackage();
      if (output->vx_p_caselist != vx_p_caselist) {
        if (output->vx_p_caselist) {
          vx_core::vx_release_one(output->vx_p_caselist);
        }
        output->vx_p_caselist = vx_p_caselist;
        vx_core::vx_reserve(vx_p_caselist);
      }
      if (output->vx_p_coveragedetail != vx_p_coveragedetail) {
        if (output->vx_p_coveragedetail) {
          vx_core::vx_release_one(output->vx_p_coveragedetail);
        }
        output->vx_p_coveragedetail = vx_p_coveragedetail;
        vx_core::vx_reserve(vx_p_coveragedetail);
      }
      if (output->vx_p_coveragesummary != vx_p_coveragesummary) {
        if (output->vx_p_coveragesummary) {
          vx_core::vx_release_one(output->vx_p_coveragesummary);
        }
        output->vx_p_coveragesummary = vx_p_coveragesummary;
        vx_core::vx_reserve(vx_p_coveragesummary);
      }
      if (output->vx_p_passfail != vx_p_passfail) {
        if (output->vx_p_passfail) {
          vx_core::vx_release_one(output->vx_p_passfail);
        }
        output->vx_p_passfail = vx_p_passfail;
        vx_core::vx_reserve(vx_p_passfail);
      }
      if (output->vx_p_testpkg != vx_p_testpkg) {
        if (output->vx_p_testpkg) {
          vx_core::vx_release_one(output->vx_p_testpkg);
        }
        output->vx_p_testpkg = vx_p_testpkg;
        vx_core::vx_reserve(vx_p_testpkg);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testpackage::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testpackage::vx_empty() const {return vx_test::e_testpackage;}
    vx_core::Type_any Class_testpackage::vx_type() const {return vx_test::t_testpackage;}

    vx_core::Type_typedef Class_testpackage::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "caselist", // name
            vx_test::t_testcaselist // type
          ),
          vx_core::vx_new_arg(
            "coveragedetail", // name
            vx_test::t_testcoveragedetail // type
          ),
          vx_core::vx_new_arg(
            "coveragesummary", // name
            vx_test::t_testcoveragesummary // type
          ),
          vx_core::vx_new_arg(
            "passfail", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "testpkg", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_testpackagelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testpackage Class_testpackagelist::vx_get_testpackage(vx_core::Type_int index) const {
      vx_test::Type_testpackage output = vx_test::e_testpackage;
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testpackage> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_test::Type_testpackage> Class_testpackagelist::vx_listtestpackage() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testpackagelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testpackage(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testpackagelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testpackagelist output = vx_test::e_testpackagelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_test::Type_testpackage> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_test::t_testpackage) {
          vx_test::Type_testpackage castval = vx_core::vx_any_from_any(vx_test::t_testpackage, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(testpackagelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testpackagelist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testpackagelist, vals);
    }

    vx_core::Type_any Class_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testpackagelist output = vx_test::e_testpackagelist;
      vx_test::Type_testpackagelist val = vx_core::vx_any_from_any(vx_test::t_testpackagelist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testpackage> listval = val->vx_listtestpackage();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testpackage) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testpackage, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_test::t_testpackage)) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testpackage, valsub));
        } else if (valsubtype == vx_test::t_testpackagelist) {
          vx_test::Type_testpackagelist multi = vx_core::vx_any_from_any(vx_test::t_testpackagelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestpackage());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testpackagelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testpackagelist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testpackagelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testpackagelist::vx_empty() const {return vx_test::e_testpackagelist;}
    vx_core::Type_any Class_testpackagelist::vx_type() const {return vx_test::t_testpackagelist;}

    vx_core::Type_typedef Class_testpackagelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_test::t_testpackage}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_code,
        this->vx_p_passfail,
        this->vx_p_expected,
        this->vx_p_actual,
        this->vx_p_fn_actual
      });
    }

    // code()
    vx_core::Type_string Class_testresult::code() const {
      vx_core::Type_string output = this->vx_p_code;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // passfail()
    vx_core::Type_boolean Class_testresult::passfail() const {
      vx_core::Type_boolean output = this->vx_p_passfail;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // expected()
    vx_core::Type_any Class_testresult::expected() const {
      vx_core::Type_any output = this->vx_p_expected;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // actual()
    vx_core::Type_any Class_testresult::actual() const {
      vx_core::Type_any output = this->vx_p_actual;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // fn_actual()
    vx_core::Func_any_from_func_async Class_testresult::fn_actual() const {
      vx_core::Func_any_from_func_async output = this->vx_p_fn_actual;
      if (!output) {
        output = vx_core::e_any_from_func_async;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_testresult::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_test::e_testresult, vals);
    }

    vx_core::Type_any Class_testresult::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testresult output = vx_test::e_testresult;
      vx_test::Type_testresult val = vx_core::vx_any_from_any(vx_test::t_testresult, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_code = val->code();
      vx_core::Type_boolean vx_p_passfail = val->passfail();
      vx_core::Type_any vx_p_expected = val->expected();
      vx_core::Type_any vx_p_actual = val->actual();
      vx_core::Func_any_from_func_async vx_p_fn_actual = val->fn_actual();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresult) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string) {
              vx_p_code = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresult :code " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":passfail") {
            if (valsubtype == vx_core::t_boolean) {
              vx_p_passfail = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresult :passfail " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":expected") {
            vx_p_expected = valsub;
          } else if (key == ":actual") {
            vx_p_actual = valsub;
          } else if (key == ":fn-actual") {
            if (valsubtype == vx_core::t_any_from_func_async) {
              vx_p_fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresult :fn-actual " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresult) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_test::Class_testresult();
      if (output->vx_p_code != vx_p_code) {
        if (output->vx_p_code) {
          vx_core::vx_release_one(output->vx_p_code);
        }
        output->vx_p_code = vx_p_code;
        vx_core::vx_reserve(vx_p_code);
      }
      if (output->vx_p_passfail != vx_p_passfail) {
        if (output->vx_p_passfail) {
          vx_core::vx_release_one(output->vx_p_passfail);
        }
        output->vx_p_passfail = vx_p_passfail;
        vx_core::vx_reserve(vx_p_passfail);
      }
      if (output->vx_p_expected != vx_p_expected) {
        if (output->vx_p_expected) {
          vx_core::vx_release_one(output->vx_p_expected);
        }
        output->vx_p_expected = vx_p_expected;
        vx_core::vx_reserve(vx_p_expected);
      }
      if (output->vx_p_actual != vx_p_actual) {
        if (output->vx_p_actual) {
          vx_core::vx_release_one(output->vx_p_actual);
        }
        output->vx_p_actual = vx_p_actual;
        vx_core::vx_reserve(vx_p_actual);
      }
      if (output->vx_p_fn_actual != vx_p_fn_actual) {
        if (output->vx_p_fn_actual) {
          vx_core::vx_release_one(output->vx_p_fn_actual);
        }
        output->vx_p_fn_actual = vx_p_fn_actual;
        vx_core::vx_reserve(vx_p_fn_actual);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testresult::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testresult::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testresult::vx_empty() const {return vx_test::e_testresult;}
    vx_core::Type_any Class_testresult::vx_type() const {return vx_test::t_testresult;}

    vx_core::Type_typedef Class_testresult::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "code", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "passfail", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "expected", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "actual", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "fn-actual", // name
            vx_core::t_any_from_func_async // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_testresultlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_test::Type_testresult Class_testresultlist::vx_get_testresult(vx_core::Type_int index) const {
      vx_test::Type_testresult output = vx_test::e_testresult;
      long iindex = index->vx_int();
      std::vector<vx_test::Type_testresult> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_test::Type_testresult> Class_testresultlist::vx_listtestresult() const {return vx_p_list;}

    vx_core::Type_any vx_test::Class_testresultlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_testresult(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_testresultlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_test::Type_testresultlist output = vx_test::e_testresultlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_test::Type_testresult> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_test::t_testresult) {
          vx_test::Type_testresult castval = vx_core::vx_any_from_any(vx_test::t_testresult, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(testresultlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_test::Class_testresultlist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_testresultlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_test::e_testresultlist, vals);
    }

    vx_core::Type_any Class_testresultlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Type_testresultlist output = vx_test::e_testresultlist;
      vx_test::Type_testresultlist val = vx_core::vx_any_from_any(vx_test::t_testresultlist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_test::Type_testresult> listval = val->vx_listtestresult();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_test::t_testresult) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testresult, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_test::t_testresult)) {
          listval.push_back(vx_core::vx_any_from_any(vx_test::t_testresult, valsub));
        } else if (valsubtype == vx_test::t_testresultlist) {
          vx_test::Type_testresultlist multi = vx_core::vx_any_from_any(vx_test::t_testresultlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtestresult());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new testresultlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_test::Class_testresultlist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_testresultlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_test::Class_testresultlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_testresultlist::vx_empty() const {return vx_test::e_testresultlist;}
    vx_core::Type_any Class_testresultlist::vx_type() const {return vx_test::t_testresultlist;}

    vx_core::Type_typedef Class_testresultlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_test::t_testresult}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

  //}

  // (const stylesheet-test)
  // class Class_stylesheet_test {

    // vx_const_new()
    void vx_test::Class_stylesheet_test::vx_const_new(vx_test::Const_stylesheet_test output) {
      long irefcount = vx_core::refcount;
      vx_web_html::Type_stylesheet val = vx_web_html::f_stylesheet_loadmap(
        vx_core::f_new(
          vx_web_html::t_stylesheet,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("Test Suite"),
            vx_core::vx_new_string(":styles"),
            vx_core::f_new(
              vx_web_html::t_stylelist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("body"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("font-size"),
                        vx_core::vx_new_string("0.9em"),
                        vx_core::vx_new_string("font-family"),
                        vx_core::vx_new_string("sans-serif")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("details summary"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("table"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("vertical-align"),
                        vx_core::vx_new_string("top"),
                        vx_core::vx_new_string("border-collapse"),
                        vx_core::vx_new_string("collapse"),
                        vx_core::vx_new_string("margin"),
                        vx_core::vx_new_string("25px 0"),
                        vx_core::vx_new_string("min-width"),
                        vx_core::vx_new_string("400px"),
                        vx_core::vx_new_string("box-shadow"),
                        vx_core::vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("thead tr"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("td"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("padding"),
                        vx_core::vx_new_string("10px 10px"),
                        vx_core::vx_new_string("vertical-align"),
                        vx_core::vx_new_string("top")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("border-bottom"),
                        vx_core::vx_new_string("1px solid #dddddd")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr:nth-of-type(even)"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("background-color"),
                        vx_core::vx_new_string("#f3f3f3")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr:last-of-type"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("border-bottom"),
                        vx_core::vx_new_string("2px solid #009879")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("tbody tr.active-row"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("font-weight"),
                        vx_core::vx_new_string("bold"),
                        vx_core::vx_new_string("color"),
                        vx_core::vx_new_string("#009879")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".failflag"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".passflag"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragenums"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("width"),
                        vx_core::vx_new_string("90px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepct"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("text-align"),
                        vx_core::vx_new_string("right")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepctgreen"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".coveragepctred"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".pkgheader"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("display"),
                        vx_core::vx_new_string("inline-flex"),
                        vx_core::vx_new_string("gap"),
                        vx_core::vx_new_string("10px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".pkgname"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("font-weight"),
                        vx_core::vx_new_string("bold"),
                        vx_core::vx_new_string("width"),
                        vx_core::vx_new_string("180px")
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string(".preformatted"),
                    vx_core::vx_new_string(":props"),
                    vx_core::f_new(
                      vx_web_html::t_propmap,
                      vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::vx_reserve(output->vx_p_id);
      output->vx_p_style = val->style();
      vx_core::vx_reserve(output->vx_p_style);
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_styles = val->styles();
      vx_core::vx_reserve(output->vx_p_styles);
      output->vx_p_stylemap = val->stylemap();
      vx_core::vx_reserve(output->vx_p_stylemap);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_test::Class_stylesheet_test::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_headchild}), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "styles", // name
            vx_web_html::t_stylelist // type
          ),
          vx_core::vx_new_arg(
            "stylemap", // name
            vx_web_html::t_stylemap // type
          )
        }) // properties
        )
      );
    }


  //}

  // (func div<-testcaselist)
  vx_web_html::Type_div f_div_from_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_web_html::Type_div output = vx_web_html::e_div;
    vx_core::vx_reserve(testcaselist);
    output = vx_core::f_new(
      vx_web_html::t_div,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::f_new(
          vx_web_html::t_table,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":thead"),
            vx_core::f_new(
              vx_web_html::t_thead,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_tr,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Pass?")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Name")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Test")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("Expected")
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_web_html::t_td,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_web_html::t_p,
                          vx_core::vx_new(vx_core::t_anylist, {
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
              vx_web_html::t_tbody,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_test::f_trlist_from_testcaselist(testcaselist)
              })
            )
          })
        )
      })
    );
    vx_core::vx_release_one_except(testcaselist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testcaselist output = vx_test::e_div_from_testcaselist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testcaselist output = vx_test::e_div_from_testcaselist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_div_from_testcaselist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_div_from_testcaselist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_empty() const {return vx_test::e_div_from_testcaselist;}
    vx_core::Type_any Class_div_from_testcaselist::vx_type() const {return vx_test::t_div_from_testcaselist;}
    vx_core::Type_msgblock Class_div_from_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testcaselist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist, val);
      output = vx_test::f_div_from_testcaselist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_div_from_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testcaselist(testcaselist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func div<-testpackage)
  vx_web_html::Type_div f_div_from_testpackage(vx_test::Type_testpackage testpackage) {
    vx_web_html::Type_div output = vx_web_html::e_div;
    vx_core::vx_reserve(testpackage);
    output = vx_core::f_let(
      vx_web_html::t_div,
      vx_core::t_any_from_func->vx_fn_new({testpackage}, [testpackage]() {
        vx_test::Type_testcoveragesummary testcoveragesummary = testpackage->coveragesummary();
        vx_core::vx_ref_plus(testcoveragesummary);
        vx_core::Type_string pkgname = testpackage->testpkg();
        vx_core::vx_ref_plus(pkgname);
        vx_test::Type_testcaselist caselist = testpackage->caselist();
        vx_core::vx_ref_plus(caselist);
        vx_core::Type_boolean passfail = testpackage->passfail();
        vx_core::vx_ref_plus(passfail);
        vx_web_html::Type_style pkgnamestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".pkgname")
        );
        vx_core::vx_ref_plus(pkgnamestyle);
        vx_web_html::Type_div node = vx_test::f_div_from_testcaselist(caselist);
        vx_core::vx_ref_plus(node);
        vx_web_html::Type_divchildlist nodes = vx_core::f_new(
          vx_web_html::t_divchildlist,
          vx_core::vx_new(vx_core::t_anylist, {
            node
          })
        );
        vx_core::vx_ref_plus(nodes);
        vx_web_html::Type_p p_passfail = vx_test::f_p_from_passfail(passfail);
        vx_core::vx_ref_plus(p_passfail);
        vx_web_html::Type_p p_pkgname = vx_core::f_new(
          vx_web_html::t_p,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":style"),
            pkgnamestyle,
            vx_core::vx_new_string(":text"),
            pkgname
          })
        );
        vx_core::vx_ref_plus(p_pkgname);
        vx_web_html::Type_p p_totalnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->totalnums()
        );
        vx_core::vx_ref_plus(p_totalnums);
        vx_web_html::Type_p p_coveragenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->typenums()
        );
        vx_core::vx_ref_plus(p_coveragenums);
        vx_web_html::Type_p p_constnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->constnums()
        );
        vx_core::vx_ref_plus(p_constnums);
        vx_web_html::Type_p p_funcnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->funcnums()
        );
        vx_core::vx_ref_plus(p_funcnums);
        vx_web_html::Type_p p_docnums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->docnums()
        );
        vx_core::vx_ref_plus(p_docnums);
        vx_web_html::Type_p p_bigospacenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigospacenums()
        );
        vx_core::vx_ref_plus(p_bigospacenums);
        vx_web_html::Type_p p_bigotimenums = vx_test::f_p_from_testcoveragenums(
          testcoveragesummary->bigotimenums()
        );
        vx_core::vx_ref_plus(p_bigotimenums);
        vx_web_html::Type_divchildlist summary = vx_core::f_new(
          vx_web_html::t_divchildlist,
          vx_core::vx_new(vx_core::t_anylist, {
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
        vx_core::vx_ref_plus(summary);
        vx_web_html::Type_details details = vx_core::f_new(
          vx_web_html::t_details,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":summary"),
            summary,
            vx_core::vx_new_string(":nodes"),
            nodes
          })
        );
        vx_core::vx_ref_plus(details);
        vx_web_html::Type_div output_1 = vx_core::f_new(
          vx_web_html::t_div,
          vx_core::vx_new(vx_core::t_anylist, {
            details
          })
        );
        vx_core::vx_release_one_except({testcoveragesummary, pkgname, caselist, passfail, pkgnamestyle, node, nodes, p_passfail, p_pkgname, p_totalnums, p_coveragenums, p_constnums, p_funcnums, p_docnums, p_bigospacenums, p_bigotimenums, summary, details}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(testpackage, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_div_from_testpackage::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackage output = vx_test::e_div_from_testpackage;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackage output = vx_test::e_div_from_testpackage;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_div_from_testpackage::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_div_from_testpackage::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_empty() const {return vx_test::e_div_from_testpackage;}
    vx_core::Type_any Class_div_from_testpackage::vx_type() const {return vx_test::t_div_from_testpackage;}
    vx_core::Type_msgblock Class_div_from_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testpackage::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testpackage::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackage inputval = vx_core::vx_any_from_any(vx_test::t_testpackage, val);
      output = vx_test::f_div_from_testpackage(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackage::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testpackage(testpackage);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func div<-testpackagelist)
  vx_web_html::Type_div f_div_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_web_html::Type_div output = vx_web_html::e_div;
    vx_core::vx_reserve(testpackagelist);
    output = vx_core::f_let(
      vx_web_html::t_div,
      vx_core::t_any_from_func->vx_fn_new({testpackagelist}, [testpackagelist]() {
        vx_web_html::Type_style stylepassfail = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".passfail")
        );
        vx_core::vx_ref_plus(stylepassfail);
        vx_web_html::Type_style stylepkgname = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".pkgname")
        );
        vx_core::vx_ref_plus(stylepkgname);
        vx_web_html::Type_style stylepkgheader = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".pkgheader")
        );
        vx_core::vx_ref_plus(stylepkgheader);
        vx_web_html::Type_style stylecoveragenum = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".coveragenums")
        );
        vx_core::vx_ref_plus(stylecoveragenum);
        vx_web_html::Type_div output_1 = vx_core::f_new(
          vx_web_html::t_div,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":style"),
                stylepkgheader,
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylepassfail,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Pass?")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylepkgname,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Package Name")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("Coverage")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(type)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(const)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(func)")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":doc")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":bigospace")
                  })
                ),
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(":bigotime")
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_test::f_divchildlist_from_testpackagelist(testpackagelist)
              })
            )
          })
        );
        vx_core::vx_release_one_except({stylepassfail, stylepkgname, stylepkgheader, stylecoveragenum}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(testpackagelist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackagelist output = vx_test::e_div_from_testpackagelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_div_from_testpackagelist output = vx_test::e_div_from_testpackagelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_div_from_testpackagelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_div_from_testpackagelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_empty() const {return vx_test::e_div_from_testpackagelist;}
    vx_core::Type_any Class_div_from_testpackagelist::vx_type() const {return vx_test::t_div_from_testpackagelist;}
    vx_core::Type_msgblock Class_div_from_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_div_from_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_div_from_testpackagelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist, val);
      output = vx_test::f_div_from_testpackagelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_div_from_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_div_from_testpackagelist(testpackagelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func divchildlist<-testpackagelist)
  vx_web_html::Type_divchildlist f_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist;
    vx_core::vx_reserve(testpackagelist);
    output = vx_core::f_list_from_list(
      vx_web_html::t_divchildlist,
      testpackagelist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any testpackage_any) {
        vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage, testpackage_any);
        vx_core::Type_any output_1 = vx_test::f_div_from_testpackage(testpackage);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(testpackagelist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_divchildlist_from_testpackagelist output = vx_test::e_divchildlist_from_testpackagelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_divchildlist_from_testpackagelist output = vx_test::e_divchildlist_from_testpackagelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_divchildlist_from_testpackagelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_divchildlist_from_testpackagelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_empty() const {return vx_test::e_divchildlist_from_testpackagelist;}
    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_type() const {return vx_test::t_divchildlist_from_testpackagelist;}
    vx_core::Type_msgblock Class_divchildlist_from_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_divchildlist_from_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_divchildlist_from_testpackagelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist, val);
      output = vx_test::f_divchildlist_from_testpackagelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_divchildlist_from_testpackagelist(testpackagelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func file-test)
  vx_data_file::Type_file f_file_test() {
    vx_data_file::Type_file output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::vx_new(vx_core::t_anylist, {
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_file_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_test output = vx_test::e_file_test;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_file_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_test output = vx_test::e_file_test;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_file_test::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "file-test", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_file_test::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_file_test::vx_empty() const {return vx_test::e_file_test;}
    vx_core::Type_any Class_file_test::vx_type() const {return vx_test::t_file_test;}
    vx_core::Type_msgblock Class_file_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_test::f_file_test();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func file-testhtml)
  vx_data_file::Type_file f_file_testhtml() {
    vx_data_file::Type_file output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::vx_new(vx_core::t_anylist, {
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_file_testhtml::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testhtml output = vx_test::e_file_testhtml;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_file_testhtml::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testhtml output = vx_test::e_file_testhtml;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_file_testhtml::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_file_testhtml::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_file_testhtml::vx_empty() const {return vx_test::e_file_testhtml;}
    vx_core::Type_any Class_file_testhtml::vx_type() const {return vx_test::t_file_testhtml;}
    vx_core::Type_msgblock Class_file_testhtml::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_testhtml::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_testhtml::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_test::f_file_testhtml();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func file-testnode)
  vx_data_file::Type_file f_file_testnode() {
    vx_data_file::Type_file output = vx_data_file::e_file;
    output = vx_core::f_new(
      vx_data_file::t_file,
      vx_core::vx_new(vx_core::t_anylist, {
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_file_testnode::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testnode output = vx_test::e_file_testnode;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_file_testnode::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_file_testnode output = vx_test::e_file_testnode;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_file_testnode::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_file_testnode::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_file_testnode::vx_empty() const {return vx_test::e_file_testnode;}
    vx_core::Type_any Class_file_testnode::vx_type() const {return vx_test::t_file_testnode;}
    vx_core::Type_msgblock Class_file_testnode::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_testnode::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_file_testnode::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_test::f_file_testnode();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func html<-divtest)
  vx_web_html::Type_html f_html_from_divtest(vx_web_html::Type_div divtest) {
    vx_web_html::Type_html output = vx_web_html::e_html;
    vx_core::vx_reserve(divtest);
    output = vx_core::f_new(
      vx_web_html::t_html,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":lang"),
        vx_core::vx_new_string("en"),
        vx_core::vx_new_string(":head"),
        vx_core::f_new(
          vx_web_html::t_head,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_web_html::t_meta,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":charset"),
                vx_core::vx_new_string("utf-8")
              })
            ),
            vx_core::f_new(
              vx_web_html::t_title,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("Test Suite")
              })
            ),
            vx_test::c_stylesheet_test
          })
        ),
        vx_core::vx_new_string(":body"),
        vx_core::f_new(
          vx_web_html::t_body,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_web_html::t_div,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_h1,
                  vx_core::vx_new(vx_core::t_anylist, {
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
    vx_core::vx_release_one_except(divtest, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_html_from_divtest::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_html_from_divtest output = vx_test::e_html_from_divtest;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_html_from_divtest::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_html_from_divtest output = vx_test::e_html_from_divtest;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_html_from_divtest::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_html_from_divtest::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_html_from_divtest::vx_empty() const {return vx_test::e_html_from_divtest;}
    vx_core::Type_any Class_html_from_divtest::vx_type() const {return vx_test::t_html_from_divtest;}
    vx_core::Type_msgblock Class_html_from_divtest::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_html_from_divtest::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_html_from_divtest::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_html_from_divtest::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_div inputval = vx_core::vx_any_from_any(vx_web_html::t_div, val);
      output = vx_test::f_html_from_divtest(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_html_from_divtest::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_div divtest = vx_core::vx_any_from_any(vx_web_html::t_div, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_html_from_divtest(divtest);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func p<-passfail)
  vx_web_html::Type_p f_p_from_passfail(vx_core::Type_boolean passfail) {
    vx_web_html::Type_p output = vx_web_html::e_p;
    vx_core::vx_reserve(passfail);
    output = vx_core::f_let(
      vx_web_html::t_p,
      vx_core::t_any_from_func->vx_fn_new({passfail}, [passfail]() {
        vx_core::Type_string text = vx_core::f_if_1(vx_core::t_string, passfail, vx_core::vx_new_string("Pass"), vx_core::vx_new_string("Fail"));
        vx_core::vx_ref_plus(text);
        vx_core::Type_string stylename = vx_core::f_if_1(vx_core::t_string, passfail, vx_core::vx_new_string(".passflag"), vx_core::vx_new_string(".failflag"));
        vx_core::vx_ref_plus(stylename);
        vx_web_html::Type_style style = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          stylename
        );
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_p output_1 = vx_core::f_new(
          vx_web_html::t_p,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":style"),
            style,
            vx_core::vx_new_string(":text"),
            text
          })
        );
        vx_core::vx_release_one_except({text, stylename, style}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(passfail, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_p_from_passfail::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_passfail output = vx_test::e_p_from_passfail;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_p_from_passfail::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_passfail output = vx_test::e_p_from_passfail;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_p_from_passfail::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_p_from_passfail::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_p_from_passfail::vx_empty() const {return vx_test::e_p_from_passfail;}
    vx_core::Type_any Class_p_from_passfail::vx_type() const {return vx_test::t_p_from_passfail;}
    vx_core::Type_msgblock Class_p_from_passfail::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_p_from_passfail::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_p_from_passfail::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_p_from_passfail::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_boolean inputval = vx_core::vx_any_from_any(vx_core::t_boolean, val);
      output = vx_test::f_p_from_passfail(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_p_from_passfail::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_boolean passfail = vx_core::vx_any_from_any(vx_core::t_boolean, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_p_from_passfail(passfail);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func p<-testcoveragenums)
  vx_web_html::Type_p f_p_from_testcoveragenums(vx_test::Type_testcoveragenums nums) {
    vx_web_html::Type_p output = vx_web_html::e_p;
    vx_core::vx_reserve(nums);
    output = vx_core::f_new(
      vx_web_html::t_p,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":style"),
        vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".coveragenums")
        ),
        vx_core::vx_new_string(":text"),
        vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            nums->pct(),
            vx_core::vx_new_string("% "),
            nums->tests(),
            vx_core::vx_new_string("/"),
            nums->total()
          })
        )
      })
    );
    vx_core::vx_release_one_except(nums, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_testcoveragenums output = vx_test::e_p_from_testcoveragenums;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_p_from_testcoveragenums output = vx_test::e_p_from_testcoveragenums;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_p_from_testcoveragenums::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_p_from_testcoveragenums::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_empty() const {return vx_test::e_p_from_testcoveragenums;}
    vx_core::Type_any Class_p_from_testcoveragenums::vx_type() const {return vx_test::t_p_from_testcoveragenums;}
    vx_core::Type_msgblock Class_p_from_testcoveragenums::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_p_from_testcoveragenums::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_p_from_testcoveragenums::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcoveragenums inputval = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, val);
      output = vx_test::f_p_from_testcoveragenums(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_p_from_testcoveragenums::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcoveragenums nums = vx_core::vx_any_from_any(vx_test::t_testcoveragenums, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_p_from_testcoveragenums(nums);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func resolve-testcase)
  vx_core::vx_Type_async f_resolve_testcase(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testcase);
    output = vx_core::f_let_async(
      vx_test::t_testcase,
      vx_core::t_any_from_func_async->vx_fn_new({testcase}, [testcase]() {
        vx_test::Type_testdescribelist describelist = testcase->describelist();
        vx_core::vx_ref_plus(describelist);
        vx_core::vx_Type_async future_resolvedlist = vx_test::f_resolve_testdescribelist(describelist);
        vx_core::vx_Type_fn_any_from_any fn_any_any_resolvedlist = [testcase](vx_core::Type_any any_resolvedlist) {
          vx_test::Type_testdescribelist resolvedlist = vx_core::vx_any_from_any(vx_test::t_testdescribelist, any_resolvedlist);
          vx_core::vx_ref_plus(resolvedlist);
          vx_core::Type_booleanlist passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist,
            resolvedlist,
            vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any testdescribe_any) {
              vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe, testdescribe_any);
              vx_core::Type_any output_1 = 
                vx_core::f_let(
                  vx_core::t_boolean,
                  vx_core::t_any_from_func->vx_fn_new({testdescribe}, [testdescribe]() {
                    vx_test::Type_testresult testresult = testdescribe->testresult();
                    vx_core::vx_ref_plus(testresult);
                    vx_core::Type_boolean output_1 = testresult->passfail();
                    vx_core::vx_release_one_except(testresult, output_1);
                    return output_1;
                  })
                );
              return output_1;
            })
          );
          vx_core::vx_ref_plus(passfaillist);
          vx_core::Type_boolean passfail = vx_core::f_and_1(passfaillist);
          vx_core::vx_ref_plus(passfail);
          vx_core::Type_any output_2 = vx_core::f_copy(
            vx_test::t_testcase,
            testcase,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":passfail"),
              passfail,
              vx_core::vx_new_string(":describelist"),
              resolvedlist
            })
          );
          vx_core::vx_release_one_except({resolvedlist, passfaillist, passfail}, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_resolvedlist, vx_test::t_testdescribelist, {testcase}, fn_any_any_resolvedlist);
        vx_core::vx_release_one(describelist);
        return output_1;
      })
    );
    vx_core::vx_release_one(testcase);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testcase);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testcase::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcase output = vx_test::e_resolve_testcase;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcase output = vx_test::e_resolve_testcase;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testcase::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testcase::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testcase::vx_empty() const {return vx_test::e_resolve_testcase;}
    vx_core::Type_any Class_resolve_testcase::vx_type() const {return vx_test::t_resolve_testcase;}
    vx_core::Type_msgblock Class_resolve_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testcase::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testcase::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testcase::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testcase inputval = vx_core::vx_any_from_any(vx_test::t_testcase, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testcase(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testcase::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testcase(testcase);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testcaselist)
  vx_core::vx_Type_async f_resolve_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testcaselist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testcaselist,
      testcaselist,
      vx_core::t_any_from_any_async->vx_fn_new({}, [](vx_core::Type_any testcase_any) {
        vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase, testcase_any);
        vx_core::vx_Type_async output_1 = vx_test::f_resolve_testcase(testcase);
        return output_1;
      })
    );
    vx_core::vx_release_one(testcaselist);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testcaselist);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcaselist output = vx_test::e_resolve_testcaselist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testcaselist output = vx_test::e_resolve_testcaselist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testcaselist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testcaselist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testcaselist::vx_empty() const {return vx_test::e_resolve_testcaselist;}
    vx_core::Type_any Class_resolve_testcaselist::vx_type() const {return vx_test::t_resolve_testcaselist;}
    vx_core::Type_msgblock Class_resolve_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testcaselist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testcaselist::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testcaselist(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testcaselist(testcaselist);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testdescribe)
  vx_core::vx_Type_async f_resolve_testdescribe(vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testdescribe);
    output = vx_core::f_let_async(
      vx_test::t_testdescribe,
      vx_core::t_any_from_func_async->vx_fn_new({testdescribe}, [testdescribe]() {
        vx_test::Type_testresult testresult = testdescribe->testresult();
        vx_core::vx_ref_plus(testresult);
        vx_core::vx_Type_async future_resolved = vx_test::f_resolve_testresult(testresult);
        vx_core::vx_Type_fn_any_from_any fn_any_any_resolved = [testdescribe](vx_core::Type_any any_resolved) {
          vx_test::Type_testresult resolved = vx_core::vx_any_from_any(vx_test::t_testresult, any_resolved);
          vx_core::vx_ref_plus(resolved);
          vx_core::Type_any output_2 = vx_core::f_copy(
            vx_test::t_testdescribe,
            testdescribe,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":testresult"),
              resolved
            })
          );
          vx_core::vx_release_one_except(resolved, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_resolved, vx_test::t_testresult, {testdescribe}, fn_any_any_resolved);
        vx_core::vx_release_one(testresult);
        return output_1;
      })
    );
    vx_core::vx_release_one(testdescribe);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testdescribe);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testdescribe::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribe output = vx_test::e_resolve_testdescribe;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribe::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribe output = vx_test::e_resolve_testdescribe;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testdescribe::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testdescribe::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribe::vx_empty() const {return vx_test::e_resolve_testdescribe;}
    vx_core::Type_any Class_resolve_testdescribe::vx_type() const {return vx_test::t_resolve_testdescribe;}
    vx_core::Type_msgblock Class_resolve_testdescribe::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testdescribe::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testdescribe::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testdescribe::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testdescribe inputval = vx_core::vx_any_from_any(vx_test::t_testdescribe, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testdescribe(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testdescribe::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testdescribe(testdescribe);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testdescribelist)
  vx_core::vx_Type_async f_resolve_testdescribelist(vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testdescribelist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testdescribelist,
      testdescribelist,
      vx_core::t_any_from_any_async->vx_fn_new({}, [](vx_core::Type_any testdescribe_any) {
        vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe, testdescribe_any);
        vx_core::vx_Type_async output_1 = vx_test::f_resolve_testdescribe(testdescribe);
        return output_1;
      })
    );
    vx_core::vx_release_one(testdescribelist);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testdescribelist);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testdescribelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribelist output = vx_test::e_resolve_testdescribelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testdescribelist output = vx_test::e_resolve_testdescribelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testdescribelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testdescribelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testdescribelist::vx_empty() const {return vx_test::e_resolve_testdescribelist;}
    vx_core::Type_any Class_resolve_testdescribelist::vx_type() const {return vx_test::t_resolve_testdescribelist;}
    vx_core::Type_msgblock Class_resolve_testdescribelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testdescribelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testdescribelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testdescribelist::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testdescribelist inputval = vx_core::vx_any_from_any(vx_test::t_testdescribelist, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testdescribelist(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testdescribelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testdescribelist testdescribelist = vx_core::vx_any_from_any(vx_test::t_testdescribelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testdescribelist(testdescribelist);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testpackage)
  vx_core::vx_Type_async f_resolve_testpackage(vx_test::Type_testpackage testpackage) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testpackage);
    output = vx_core::f_let_async(
      vx_test::t_testpackage,
      vx_core::t_any_from_func_async->vx_fn_new({testpackage}, [testpackage]() {
        vx_test::Type_testcaselist testcaselist = testpackage->caselist();
        vx_core::vx_ref_plus(testcaselist);
        vx_core::vx_Type_async future_resolvedlist = vx_test::f_resolve_testcaselist(testcaselist);
        vx_core::vx_Type_fn_any_from_any fn_any_any_resolvedlist = [testpackage](vx_core::Type_any any_resolvedlist) {
          vx_test::Type_testcaselist resolvedlist = vx_core::vx_any_from_any(vx_test::t_testcaselist, any_resolvedlist);
          vx_core::vx_ref_plus(resolvedlist);
          vx_core::Type_booleanlist passfaillist = vx_core::f_list_from_list(
            vx_core::t_booleanlist,
            resolvedlist,
            vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any testcase_any) {
              vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase, testcase_any);
              vx_core::Type_any output_1 = 
                testcase->passfail();
              return output_1;
            })
          );
          vx_core::vx_ref_plus(passfaillist);
          vx_core::Type_boolean passfail = vx_core::f_and_1(passfaillist);
          vx_core::vx_ref_plus(passfail);
          vx_core::Type_any output_2 = vx_core::f_copy(
            vx_test::t_testpackage,
            testpackage,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":passfail"),
              passfail,
              vx_core::vx_new_string(":caselist"),
              resolvedlist
            })
          );
          vx_core::vx_release_one_except({resolvedlist, passfaillist, passfail}, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_resolvedlist, vx_test::t_testcaselist, {testpackage}, fn_any_any_resolvedlist);
        vx_core::vx_release_one(testcaselist);
        return output_1;
      })
    );
    vx_core::vx_release_one(testpackage);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testpackage);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testpackage::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackage output = vx_test::e_resolve_testpackage;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testpackage::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackage output = vx_test::e_resolve_testpackage;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testpackage::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testpackage::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testpackage::vx_empty() const {return vx_test::e_resolve_testpackage;}
    vx_core::Type_any Class_resolve_testpackage::vx_type() const {return vx_test::t_resolve_testpackage;}
    vx_core::Type_msgblock Class_resolve_testpackage::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testpackage::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testpackage::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testpackage::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testpackage inputval = vx_core::vx_any_from_any(vx_test::t_testpackage, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testpackage(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testpackage::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testpackage(testpackage);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testpackagelist)
  vx_core::vx_Type_async f_resolve_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testpackagelist);
    output = vx_core::f_list_from_list_async(
      vx_test::t_testpackagelist,
      testpackagelist,
      vx_core::t_any_from_any_async->vx_fn_new({}, [](vx_core::Type_any testpackage_any) {
        vx_test::Type_testpackage testpackage = vx_core::vx_any_from_any(vx_test::t_testpackage, testpackage_any);
        vx_core::vx_Type_async output_1 = vx_test::f_resolve_testpackage(testpackage);
        return output_1;
      })
    );
    vx_core::vx_release_one(testpackagelist);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testpackagelist);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testpackagelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackagelist output = vx_test::e_resolve_testpackagelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testpackagelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testpackagelist output = vx_test::e_resolve_testpackagelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testpackagelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testpackagelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testpackagelist::vx_empty() const {return vx_test::e_resolve_testpackagelist;}
    vx_core::Type_any Class_resolve_testpackagelist::vx_type() const {return vx_test::t_resolve_testpackagelist;}
    vx_core::Type_msgblock Class_resolve_testpackagelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testpackagelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testpackagelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testpackagelist::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testpackagelist inputval = vx_core::vx_any_from_any(vx_test::t_testpackagelist, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testpackagelist(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testpackagelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testpackagelist testpackagelist = vx_core::vx_any_from_any(vx_test::t_testpackagelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testpackagelist(testpackagelist);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func resolve-testresult)
  vx_core::vx_Type_async f_resolve_testresult(vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(testresult);
    output = vx_core::f_let_async(
      vx_test::t_testresult,
      vx_core::t_any_from_func_async->vx_fn_new({testresult}, [testresult]() {
        vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
        vx_core::vx_ref_plus(fn_actual);
        vx_core::Type_any expected = testresult->expected();
        vx_core::vx_ref_plus(expected);
        vx_core::vx_Type_async future_actual = vx_core::f_resolve_async(vx_core::t_any, fn_actual);
        vx_core::vx_Type_fn_any_from_any fn_any_any_actual = [fn_actual, testresult, expected](vx_core::Type_any any_actual) {
          vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, any_actual);
          vx_core::vx_ref_plus(actual);
          vx_core::Type_any output_2 = vx_core::f_if_2(
            vx_test::t_testresult,
            vx_core::vx_new(vx_core::t_thenelselist, {
              vx_core::f_then(
                vx_core::t_boolean_from_func->vx_fn_new({fn_actual}, [fn_actual]() {
                  vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
                  return output_1;
                }),
                vx_core::t_any_from_func->vx_fn_new({testresult}, [testresult]() {
                  vx_core::Type_any output_1 = testresult;
                  return output_1;
                })
              ),
              vx_core::f_else(
                vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
                  vx_test::Type_testresult output_1 = vx_core::f_let(
                    vx_test::t_testresult,
                    vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
                      vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
                      vx_core::vx_ref_plus(passfail);
                      vx_test::Type_testresult output_1 = vx_core::f_copy(
                        vx_test::t_testresult,
                        testresult,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":passfail"),
                          passfail,
                          vx_core::vx_new_string(":actual"),
                          actual
                        })
                      );
                      vx_core::vx_release_one_except(passfail, output_1);
                      return output_1;
                    })
                  );
                  return output_1;
                })
              )
            })
          );
          vx_core::vx_release_one_except(actual, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_actual, vx_core::t_any, {fn_actual, testresult, expected}, fn_any_any_actual);
        vx_core::vx_release_one({fn_actual, expected});
        return output_1;
      })
    );
    vx_core::vx_release_one(testresult);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_test::e_testresult);
    }
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_resolve_testresult::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testresult output = vx_test::e_resolve_testresult;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_resolve_testresult::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_resolve_testresult output = vx_test::e_resolve_testresult;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_resolve_testresult::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_resolve_testresult::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_resolve_testresult::vx_empty() const {return vx_test::e_resolve_testresult;}
    vx_core::Type_any Class_resolve_testresult::vx_type() const {return vx_test::t_resolve_testresult;}
    vx_core::Type_msgblock Class_resolve_testresult::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_testresult::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_testresult::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_resolve_testresult::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_test::Type_testresult inputval = vx_core::vx_any_from_any(vx_test::t_testresult, val);
      vx_core::vx_Type_async output = vx_test::f_resolve_testresult(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_testresult::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_test::Type_testresult testresult = vx_core::vx_any_from_any(vx_test::t_testresult, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_resolve_testresult(testresult);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func test)
  vx_test::Type_testresult f_test(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test output = vx_test::e_test;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test output = vx_test::e_test;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test::vx_empty() const {return vx_test::e_test;}
    vx_core::Type_any Class_test::vx_type() const {return vx_test::t_test;}
    vx_core::Type_msgblock Class_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test(expected, actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test)
  vx_test::Type_testresult f_test_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, fn_actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":eq"),
          vx_core::vx_new_string(":expected"),
          expected,
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, fn_actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_1 output = vx_test::e_test_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_1 output = vx_test::e_test_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_1::vx_empty() const {return vx_test::e_test_1;}
    vx_core::Type_any Class_test_1::vx_type() const {return vx_test::t_test_1;}
    vx_core::Type_msgblock Class_test_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_1(expected, fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-false)
  vx_test::Type_testresult f_test_false(vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve(actual);
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-false", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except(actual, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_false::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false output = vx_test::e_test_false;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_false::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false output = vx_test::e_test_false;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_false::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-false", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_false::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_false::vx_empty() const {return vx_test::e_test_false;}
    vx_core::Type_any Class_test_false::vx_type() const {return vx_test::t_test_false;}
    vx_core::Type_msgblock Class_test_false::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_false::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_false::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_test_false::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_test::f_test_false(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_test_false::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_false(actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-false)
  vx_test::Type_testresult f_test_false_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve(fn_actual);
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":false"),
          vx_core::vx_new_string(":expected"),
          vx_core::vx_new_boolean(false),
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-false", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except(fn_actual, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_false_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false_1 output = vx_test::e_test_false_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_false_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_false_1 output = vx_test::e_test_false_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_false_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-false", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_false_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_false_1::vx_empty() const {return vx_test::e_test_false_1;}
    vx_core::Type_any Class_test_false_1::vx_type() const {return vx_test::t_test_false_1;}
    vx_core::Type_msgblock Class_test_false_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_false_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_false_1::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_test_false_1::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_any_from_func_async inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, val);
      output = vx_test::f_test_false_1(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_test_false_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_false_1(fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-gt)
  vx_test::Type_testresult f_test_gt(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-gt", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_gt::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt output = vx_test::e_test_gt;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_gt::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt output = vx_test::e_test_gt;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_gt::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-gt", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_gt::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_gt::vx_empty() const {return vx_test::e_test_gt;}
    vx_core::Type_any Class_test_gt::vx_type() const {return vx_test::t_test_gt;}
    vx_core::Type_msgblock Class_test_gt::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_gt::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_gt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_gt(expected, actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-gt)
  vx_test::Type_testresult f_test_gt_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, fn_actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":gt"),
          vx_core::vx_new_string(":expected"),
          expected,
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-gt", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, fn_actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_gt_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt_1 output = vx_test::e_test_gt_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_gt_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_gt_1 output = vx_test::e_test_gt_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_gt_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-gt", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_gt_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_gt_1::vx_empty() const {return vx_test::e_test_gt_1;}
    vx_core::Type_any Class_test_gt_1::vx_type() const {return vx_test::t_test_gt_1;}
    vx_core::Type_msgblock Class_test_gt_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_gt_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_gt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_gt_1(expected, fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-ne)
  vx_test::Type_testresult f_test_ne(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-ne", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_ne::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne output = vx_test::e_test_ne;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_ne::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne output = vx_test::e_test_ne;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_ne::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-ne", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_ne::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_ne::vx_empty() const {return vx_test::e_test_ne;}
    vx_core::Type_any Class_test_ne::vx_type() const {return vx_test::t_test_ne;}
    vx_core::Type_msgblock Class_test_ne::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_ne::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_ne::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_ne(expected, actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-ne)
  vx_test::Type_testresult f_test_ne_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, fn_actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":ne"),
          vx_core::vx_new_string(":expected"),
          expected,
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-ne", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, fn_actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_ne_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne_1 output = vx_test::e_test_ne_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_ne_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_ne_1 output = vx_test::e_test_ne_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_ne_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-ne", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_ne_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_ne_1::vx_empty() const {return vx_test::e_test_ne_1;}
    vx_core::Type_any Class_test_ne_1::vx_type() const {return vx_test::t_test_ne_1;}
    vx_core::Type_msgblock Class_test_ne_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_ne_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_ne_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_ne_1(expected, fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-string)
  vx_test::Type_testresult f_test_string(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-string", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string output = vx_test::e_test_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string output = vx_test::e_test_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_string::vx_empty() const {return vx_test::e_test_string;}
    vx_core::Type_any Class_test_string::vx_type() const {return vx_test::t_test_string;}
    vx_core::Type_msgblock Class_test_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_string(expected, actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-string)
  vx_test::Type_testresult f_test_string_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve({expected, fn_actual});
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":string"),
          vx_core::vx_new_string(":expected"),
          expected,
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-string", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except({expected, fn_actual}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_string_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string_1 output = vx_test::e_test_string_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_string_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_string_1 output = vx_test::e_test_string_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_string_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_string_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_string_1::vx_empty() const {return vx_test::e_test_string_1;}
    vx_core::Type_any Class_test_string_1::vx_type() const {return vx_test::t_test_string_1;}
    vx_core::Type_msgblock Class_test_string_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_string_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_test_string_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any expected = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_test::f_test_string_1(expected, fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-true)
  vx_test::Type_testresult f_test_true(vx_core::Type_any actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve(actual);
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
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
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-true", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except(actual, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_true::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true output = vx_test::e_test_true;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_true::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true output = vx_test::e_test_true;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_true::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-true", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_true::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_true::vx_empty() const {return vx_test::e_test_true;}
    vx_core::Type_any Class_test_true::vx_type() const {return vx_test::t_test_true;}
    vx_core::Type_msgblock Class_test_true::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_true::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_true::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_test_true::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_test::f_test_true(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_test_true::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any actual = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_true(actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func test-true)
  vx_test::Type_testresult f_test_true_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context) {
    vx_test::Type_testresult output = vx_test::e_testresult;
    vx_core::vx_reserve(fn_actual);
    try {
      output = vx_core::f_new(
        vx_test::t_testresult,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":code"),
          vx_core::vx_new_string(":true"),
          vx_core::vx_new_string(":expected"),
          vx_core::vx_new_boolean(true),
          vx_core::vx_new_string(":fn-actual"),
          fn_actual
        })
      );
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("test-true", err);
      output = vx_core::vx_new(vx_test::t_testresult, {msg});
    }
    vx_core::vx_release_one_except(fn_actual, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_test_true_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true_1 output = vx_test::e_test_true_1;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_test_true_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_test_true_1 output = vx_test::e_test_true_1;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_test_true_1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "test-true", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_test_true_1::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_test_true_1::vx_empty() const {return vx_test::e_test_true_1;}
    vx_core::Type_any Class_test_true_1::vx_type() const {return vx_test::t_test_true_1;}
    vx_core::Type_msgblock Class_test_true_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_test_true_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_test_true_1::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_test_true_1::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_any_from_func_async inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, val);
      output = vx_test::f_test_true_1(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_test_true_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_any_from_func_async fn_actual = vx_core::vx_any_from_any(vx_core::t_any_from_func_async, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_test_true_1(fn_actual, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func tr<-testdescribe-casename)
  vx_web_html::Type_tr f_tr_from_testdescribe_casename(vx_test::Type_testdescribe testdescribe, vx_core::Type_string casename) {
    vx_web_html::Type_tr output = vx_web_html::e_tr;
    vx_core::vx_reserve({testdescribe, casename});
    output = vx_core::f_let(
      vx_web_html::t_tr,
      vx_core::t_any_from_func->vx_fn_new({testdescribe, casename}, [testdescribe, casename]() {
        vx_core::Type_string describename = testdescribe->describename();
        vx_core::vx_ref_plus(describename);
        vx_test::Type_testresult result = testdescribe->testresult();
        vx_core::vx_ref_plus(result);
        vx_core::Type_boolean passfail = result->passfail();
        vx_core::vx_ref_plus(passfail);
        vx_core::Type_string expected = vx_core::f_string_from_any(
          result->expected()
        );
        vx_core::vx_ref_plus(expected);
        vx_core::Type_string actual = vx_core::f_string_from_any(
          result->actual()
        );
        vx_core::vx_ref_plus(actual);
        vx_web_html::Type_style prestyle = vx_web_html::f_style_from_stylesheet_name(
          vx_test::c_stylesheet_test,
          vx_core::vx_new_string(".preformatted")
        );
        vx_core::vx_ref_plus(prestyle);
        vx_web_html::Type_tr output_1 = vx_core::f_new(
          vx_web_html::t_tr,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_test::f_p_from_passfail(passfail)
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    casename
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    describename
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":style"),
                    prestyle,
                    vx_core::vx_new_string(":text"),
                    expected
                  })
                )
              })
            ),
            vx_core::f_new(
              vx_web_html::t_td,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
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
        vx_core::vx_release_one_except({describename, result, passfail, expected, actual, prestyle}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({testdescribe, casename}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_tr_from_testdescribe_casename output = vx_test::e_tr_from_testdescribe_casename;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_tr_from_testdescribe_casename output = vx_test::e_tr_from_testdescribe_casename;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_tr_from_testdescribe_casename::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_tr_from_testdescribe_casename::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_empty() const {return vx_test::e_tr_from_testdescribe_casename;}
    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_type() const {return vx_test::t_tr_from_testdescribe_casename;}
    vx_core::Type_msgblock Class_tr_from_testdescribe_casename::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_tr_from_testdescribe_casename::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_tr_from_testdescribe_casename::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string casename = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func trlist<-testcase)
  vx_web_html::Type_trlist f_trlist_from_testcase(vx_test::Type_testcase testcase) {
    vx_web_html::Type_trlist output = vx_web_html::e_trlist;
    vx_core::vx_reserve(testcase);
    output = vx_core::f_let(
      vx_web_html::t_trlist,
      vx_core::t_any_from_func->vx_fn_new({testcase}, [testcase]() {
        vx_test::Type_testdescribelist describelist = testcase->describelist();
        vx_core::vx_ref_plus(describelist);
        vx_core::Type_string casename = testcase->casename();
        vx_core::vx_ref_plus(casename);
        vx_web_html::Type_trlist output_1 = vx_core::f_list_from_list(
          vx_web_html::t_trlist,
          describelist,
          vx_core::t_any_from_any->vx_fn_new({casename}, [casename](vx_core::Type_any testdescribe_any) {
            vx_test::Type_testdescribe testdescribe = vx_core::vx_any_from_any(vx_test::t_testdescribe, testdescribe_any);
            vx_core::Type_any output_1 = 
              vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
            return output_1;
          })
        );
        vx_core::vx_release_one_except({describelist, casename}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(testcase, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcase output = vx_test::e_trlist_from_testcase;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcase output = vx_test::e_trlist_from_testcase;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_trlist_from_testcase::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_trlist_from_testcase::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_empty() const {return vx_test::e_trlist_from_testcase;}
    vx_core::Type_any Class_trlist_from_testcase::vx_type() const {return vx_test::t_trlist_from_testcase;}
    vx_core::Type_msgblock Class_trlist_from_testcase::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_trlist_from_testcase::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_trlist_from_testcase::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcase inputval = vx_core::vx_any_from_any(vx_test::t_testcase, val);
      output = vx_test::f_trlist_from_testcase(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcase::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_trlist_from_testcase(testcase);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func trlist<-testcaselist)
  vx_web_html::Type_trlist f_trlist_from_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_web_html::Type_trlist output = vx_web_html::e_trlist;
    vx_core::vx_reserve(testcaselist);
    output = vx_core::f_list_join_from_list(
      vx_web_html::t_trlist,
      testcaselist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any testcase_any) {
        vx_test::Type_testcase testcase = vx_core::vx_any_from_any(vx_test::t_testcase, testcase_any);
        vx_core::Type_any output_1 = vx_test::f_trlist_from_testcase(testcase);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(testcaselist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcaselist output = vx_test::e_trlist_from_testcaselist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_test::Func_trlist_from_testcaselist output = vx_test::e_trlist_from_testcaselist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_trlist_from_testcaselist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_trlist_from_testcaselist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_empty() const {return vx_test::e_trlist_from_testcaselist;}
    vx_core::Type_any Class_trlist_from_testcaselist::vx_type() const {return vx_test::t_trlist_from_testcaselist;}
    vx_core::Type_msgblock Class_trlist_from_testcaselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_trlist_from_testcaselist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_trlist_from_testcaselist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcaselist inputval = vx_core::vx_any_from_any(vx_test::t_testcaselist, val);
      output = vx_test::f_trlist_from_testcaselist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_trlist_from_testcaselist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_test::Type_testcaselist testcaselist = vx_core::vx_any_from_any(vx_test::t_testcaselist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_test::f_trlist_from_testcaselist(testcaselist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_test::Type_testcase e_testcase = NULL;
  vx_test::Type_testcase t_testcase = NULL;
  vx_test::Type_testcaselist e_testcaselist = NULL;
  vx_test::Type_testcaselist t_testcaselist = NULL;
  vx_test::Type_testcoveragedetail e_testcoveragedetail = NULL;
  vx_test::Type_testcoveragedetail t_testcoveragedetail = NULL;
  vx_test::Type_testcoveragenums e_testcoveragenums = NULL;
  vx_test::Type_testcoveragenums t_testcoveragenums = NULL;
  vx_test::Type_testcoveragesummary e_testcoveragesummary = NULL;
  vx_test::Type_testcoveragesummary t_testcoveragesummary = NULL;
  vx_test::Type_testdescribe e_testdescribe = NULL;
  vx_test::Type_testdescribe t_testdescribe = NULL;
  vx_test::Type_testdescribelist e_testdescribelist = NULL;
  vx_test::Type_testdescribelist t_testdescribelist = NULL;
  vx_test::Type_testpackage e_testpackage = NULL;
  vx_test::Type_testpackage t_testpackage = NULL;
  vx_test::Type_testpackagelist e_testpackagelist = NULL;
  vx_test::Type_testpackagelist t_testpackagelist = NULL;
  vx_test::Type_testresult e_testresult = NULL;
  vx_test::Type_testresult t_testresult = NULL;
  vx_test::Type_testresultlist e_testresultlist = NULL;
  vx_test::Type_testresultlist t_testresultlist = NULL;
  vx_test::Const_stylesheet_test c_stylesheet_test = NULL;
  vx_test::Func_div_from_testcaselist e_div_from_testcaselist = NULL;
  vx_test::Func_div_from_testcaselist t_div_from_testcaselist = NULL;
  vx_test::Func_div_from_testpackage e_div_from_testpackage = NULL;
  vx_test::Func_div_from_testpackage t_div_from_testpackage = NULL;
  vx_test::Func_div_from_testpackagelist e_div_from_testpackagelist = NULL;
  vx_test::Func_div_from_testpackagelist t_div_from_testpackagelist = NULL;
  vx_test::Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist = NULL;
  vx_test::Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist = NULL;
  vx_test::Func_file_test e_file_test = NULL;
  vx_test::Func_file_test t_file_test = NULL;
  vx_test::Func_file_testhtml e_file_testhtml = NULL;
  vx_test::Func_file_testhtml t_file_testhtml = NULL;
  vx_test::Func_file_testnode e_file_testnode = NULL;
  vx_test::Func_file_testnode t_file_testnode = NULL;
  vx_test::Func_html_from_divtest e_html_from_divtest = NULL;
  vx_test::Func_html_from_divtest t_html_from_divtest = NULL;
  vx_test::Func_p_from_passfail e_p_from_passfail = NULL;
  vx_test::Func_p_from_passfail t_p_from_passfail = NULL;
  vx_test::Func_p_from_testcoveragenums e_p_from_testcoveragenums = NULL;
  vx_test::Func_p_from_testcoveragenums t_p_from_testcoveragenums = NULL;
  vx_test::Func_resolve_testcase e_resolve_testcase = NULL;
  vx_test::Func_resolve_testcase t_resolve_testcase = NULL;
  vx_test::Func_resolve_testcaselist e_resolve_testcaselist = NULL;
  vx_test::Func_resolve_testcaselist t_resolve_testcaselist = NULL;
  vx_test::Func_resolve_testdescribe e_resolve_testdescribe = NULL;
  vx_test::Func_resolve_testdescribe t_resolve_testdescribe = NULL;
  vx_test::Func_resolve_testdescribelist e_resolve_testdescribelist = NULL;
  vx_test::Func_resolve_testdescribelist t_resolve_testdescribelist = NULL;
  vx_test::Func_resolve_testpackage e_resolve_testpackage = NULL;
  vx_test::Func_resolve_testpackage t_resolve_testpackage = NULL;
  vx_test::Func_resolve_testpackagelist e_resolve_testpackagelist = NULL;
  vx_test::Func_resolve_testpackagelist t_resolve_testpackagelist = NULL;
  vx_test::Func_resolve_testresult e_resolve_testresult = NULL;
  vx_test::Func_resolve_testresult t_resolve_testresult = NULL;
  vx_test::Func_test e_test = NULL;
  vx_test::Func_test t_test = NULL;
  vx_test::Func_test_1 e_test_1 = NULL;
  vx_test::Func_test_1 t_test_1 = NULL;
  vx_test::Func_test_false e_test_false = NULL;
  vx_test::Func_test_false t_test_false = NULL;
  vx_test::Func_test_false_1 e_test_false_1 = NULL;
  vx_test::Func_test_false_1 t_test_false_1 = NULL;
  vx_test::Func_test_gt e_test_gt = NULL;
  vx_test::Func_test_gt t_test_gt = NULL;
  vx_test::Func_test_gt_1 e_test_gt_1 = NULL;
  vx_test::Func_test_gt_1 t_test_gt_1 = NULL;
  vx_test::Func_test_ne e_test_ne = NULL;
  vx_test::Func_test_ne t_test_ne = NULL;
  vx_test::Func_test_ne_1 e_test_ne_1 = NULL;
  vx_test::Func_test_ne_1 t_test_ne_1 = NULL;
  vx_test::Func_test_string e_test_string = NULL;
  vx_test::Func_test_string t_test_string = NULL;
  vx_test::Func_test_string_1 e_test_string_1 = NULL;
  vx_test::Func_test_string_1 t_test_string_1 = NULL;
  vx_test::Func_test_true e_test_true = NULL;
  vx_test::Func_test_true t_test_true = NULL;
  vx_test::Func_test_true_1 e_test_true_1 = NULL;
  vx_test::Func_test_true_1 t_test_true_1 = NULL;
  vx_test::Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename = NULL;
  vx_test::Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename = NULL;
  vx_test::Func_trlist_from_testcase e_trlist_from_testcase = NULL;
  vx_test::Func_trlist_from_testcase t_trlist_from_testcase = NULL;
  vx_test::Func_trlist_from_testcaselist e_trlist_from_testcaselist = NULL;
  vx_test::Func_trlist_from_testcaselist t_trlist_from_testcaselist = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_test::e_testcase = new Class_testcase();
      vx_core::vx_reserve_empty(vx_test::e_testcase);
      vx_test::t_testcase = new Class_testcase();
      vx_core::vx_reserve_type(vx_test::t_testcase);
      vx_test::e_testcaselist = new Class_testcaselist();
      vx_core::vx_reserve_empty(vx_test::e_testcaselist);
      vx_test::t_testcaselist = new Class_testcaselist();
      vx_core::vx_reserve_type(vx_test::t_testcaselist);
      vx_test::e_testcoveragedetail = new Class_testcoveragedetail();
      vx_core::vx_reserve_empty(vx_test::e_testcoveragedetail);
      vx_test::t_testcoveragedetail = new Class_testcoveragedetail();
      vx_core::vx_reserve_type(vx_test::t_testcoveragedetail);
      vx_test::e_testcoveragenums = new Class_testcoveragenums();
      vx_core::vx_reserve_empty(vx_test::e_testcoveragenums);
      vx_test::t_testcoveragenums = new Class_testcoveragenums();
      vx_core::vx_reserve_type(vx_test::t_testcoveragenums);
      vx_test::e_testcoveragesummary = new Class_testcoveragesummary();
      vx_core::vx_reserve_empty(vx_test::e_testcoveragesummary);
      vx_test::t_testcoveragesummary = new Class_testcoveragesummary();
      vx_core::vx_reserve_type(vx_test::t_testcoveragesummary);
      vx_test::e_testdescribe = new Class_testdescribe();
      vx_core::vx_reserve_empty(vx_test::e_testdescribe);
      vx_test::t_testdescribe = new Class_testdescribe();
      vx_core::vx_reserve_type(vx_test::t_testdescribe);
      vx_test::e_testdescribelist = new Class_testdescribelist();
      vx_core::vx_reserve_empty(vx_test::e_testdescribelist);
      vx_test::t_testdescribelist = new Class_testdescribelist();
      vx_core::vx_reserve_type(vx_test::t_testdescribelist);
      vx_test::e_testpackage = new Class_testpackage();
      vx_core::vx_reserve_empty(vx_test::e_testpackage);
      vx_test::t_testpackage = new Class_testpackage();
      vx_core::vx_reserve_type(vx_test::t_testpackage);
      vx_test::e_testpackagelist = new Class_testpackagelist();
      vx_core::vx_reserve_empty(vx_test::e_testpackagelist);
      vx_test::t_testpackagelist = new Class_testpackagelist();
      vx_core::vx_reserve_type(vx_test::t_testpackagelist);
      vx_test::e_testresult = new Class_testresult();
      vx_core::vx_reserve_empty(vx_test::e_testresult);
      vx_test::t_testresult = new Class_testresult();
      vx_core::vx_reserve_type(vx_test::t_testresult);
      vx_test::e_testresultlist = new Class_testresultlist();
      vx_core::vx_reserve_empty(vx_test::e_testresultlist);
      vx_test::t_testresultlist = new Class_testresultlist();
      vx_core::vx_reserve_type(vx_test::t_testresultlist);
      vx_test::e_div_from_testcaselist = new vx_test::Class_div_from_testcaselist();
      vx_core::vx_reserve_empty(vx_test::e_div_from_testcaselist);
      vx_test::t_div_from_testcaselist = new vx_test::Class_div_from_testcaselist();
      vx_core::vx_reserve_type(vx_test::t_div_from_testcaselist);
      vx_test::e_div_from_testpackage = new vx_test::Class_div_from_testpackage();
      vx_core::vx_reserve_empty(vx_test::e_div_from_testpackage);
      vx_test::t_div_from_testpackage = new vx_test::Class_div_from_testpackage();
      vx_core::vx_reserve_type(vx_test::t_div_from_testpackage);
      vx_test::e_div_from_testpackagelist = new vx_test::Class_div_from_testpackagelist();
      vx_core::vx_reserve_empty(vx_test::e_div_from_testpackagelist);
      vx_test::t_div_from_testpackagelist = new vx_test::Class_div_from_testpackagelist();
      vx_core::vx_reserve_type(vx_test::t_div_from_testpackagelist);
      vx_test::e_divchildlist_from_testpackagelist = new vx_test::Class_divchildlist_from_testpackagelist();
      vx_core::vx_reserve_empty(vx_test::e_divchildlist_from_testpackagelist);
      vx_test::t_divchildlist_from_testpackagelist = new vx_test::Class_divchildlist_from_testpackagelist();
      vx_core::vx_reserve_type(vx_test::t_divchildlist_from_testpackagelist);
      vx_test::e_file_test = new vx_test::Class_file_test();
      vx_core::vx_reserve_empty(vx_test::e_file_test);
      vx_test::t_file_test = new vx_test::Class_file_test();
      vx_core::vx_reserve_type(vx_test::t_file_test);
      vx_test::e_file_testhtml = new vx_test::Class_file_testhtml();
      vx_core::vx_reserve_empty(vx_test::e_file_testhtml);
      vx_test::t_file_testhtml = new vx_test::Class_file_testhtml();
      vx_core::vx_reserve_type(vx_test::t_file_testhtml);
      vx_test::e_file_testnode = new vx_test::Class_file_testnode();
      vx_core::vx_reserve_empty(vx_test::e_file_testnode);
      vx_test::t_file_testnode = new vx_test::Class_file_testnode();
      vx_core::vx_reserve_type(vx_test::t_file_testnode);
      vx_test::e_html_from_divtest = new vx_test::Class_html_from_divtest();
      vx_core::vx_reserve_empty(vx_test::e_html_from_divtest);
      vx_test::t_html_from_divtest = new vx_test::Class_html_from_divtest();
      vx_core::vx_reserve_type(vx_test::t_html_from_divtest);
      vx_test::e_p_from_passfail = new vx_test::Class_p_from_passfail();
      vx_core::vx_reserve_empty(vx_test::e_p_from_passfail);
      vx_test::t_p_from_passfail = new vx_test::Class_p_from_passfail();
      vx_core::vx_reserve_type(vx_test::t_p_from_passfail);
      vx_test::e_p_from_testcoveragenums = new vx_test::Class_p_from_testcoveragenums();
      vx_core::vx_reserve_empty(vx_test::e_p_from_testcoveragenums);
      vx_test::t_p_from_testcoveragenums = new vx_test::Class_p_from_testcoveragenums();
      vx_core::vx_reserve_type(vx_test::t_p_from_testcoveragenums);
      vx_test::e_resolve_testcase = new vx_test::Class_resolve_testcase();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testcase);
      vx_test::t_resolve_testcase = new vx_test::Class_resolve_testcase();
      vx_core::vx_reserve_type(vx_test::t_resolve_testcase);
      vx_test::e_resolve_testcaselist = new vx_test::Class_resolve_testcaselist();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testcaselist);
      vx_test::t_resolve_testcaselist = new vx_test::Class_resolve_testcaselist();
      vx_core::vx_reserve_type(vx_test::t_resolve_testcaselist);
      vx_test::e_resolve_testdescribe = new vx_test::Class_resolve_testdescribe();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testdescribe);
      vx_test::t_resolve_testdescribe = new vx_test::Class_resolve_testdescribe();
      vx_core::vx_reserve_type(vx_test::t_resolve_testdescribe);
      vx_test::e_resolve_testdescribelist = new vx_test::Class_resolve_testdescribelist();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testdescribelist);
      vx_test::t_resolve_testdescribelist = new vx_test::Class_resolve_testdescribelist();
      vx_core::vx_reserve_type(vx_test::t_resolve_testdescribelist);
      vx_test::e_resolve_testpackage = new vx_test::Class_resolve_testpackage();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testpackage);
      vx_test::t_resolve_testpackage = new vx_test::Class_resolve_testpackage();
      vx_core::vx_reserve_type(vx_test::t_resolve_testpackage);
      vx_test::e_resolve_testpackagelist = new vx_test::Class_resolve_testpackagelist();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testpackagelist);
      vx_test::t_resolve_testpackagelist = new vx_test::Class_resolve_testpackagelist();
      vx_core::vx_reserve_type(vx_test::t_resolve_testpackagelist);
      vx_test::e_resolve_testresult = new vx_test::Class_resolve_testresult();
      vx_core::vx_reserve_empty(vx_test::e_resolve_testresult);
      vx_test::t_resolve_testresult = new vx_test::Class_resolve_testresult();
      vx_core::vx_reserve_type(vx_test::t_resolve_testresult);
      vx_test::e_test = new vx_test::Class_test();
      vx_core::vx_reserve_empty(vx_test::e_test);
      vx_test::t_test = new vx_test::Class_test();
      vx_core::vx_reserve_type(vx_test::t_test);
      vx_test::e_test_1 = new vx_test::Class_test_1();
      vx_core::vx_reserve_empty(vx_test::e_test_1);
      vx_test::t_test_1 = new vx_test::Class_test_1();
      vx_core::vx_reserve_type(vx_test::t_test_1);
      vx_test::e_test_false = new vx_test::Class_test_false();
      vx_core::vx_reserve_empty(vx_test::e_test_false);
      vx_test::t_test_false = new vx_test::Class_test_false();
      vx_core::vx_reserve_type(vx_test::t_test_false);
      vx_test::e_test_false_1 = new vx_test::Class_test_false_1();
      vx_core::vx_reserve_empty(vx_test::e_test_false_1);
      vx_test::t_test_false_1 = new vx_test::Class_test_false_1();
      vx_core::vx_reserve_type(vx_test::t_test_false_1);
      vx_test::e_test_gt = new vx_test::Class_test_gt();
      vx_core::vx_reserve_empty(vx_test::e_test_gt);
      vx_test::t_test_gt = new vx_test::Class_test_gt();
      vx_core::vx_reserve_type(vx_test::t_test_gt);
      vx_test::e_test_gt_1 = new vx_test::Class_test_gt_1();
      vx_core::vx_reserve_empty(vx_test::e_test_gt_1);
      vx_test::t_test_gt_1 = new vx_test::Class_test_gt_1();
      vx_core::vx_reserve_type(vx_test::t_test_gt_1);
      vx_test::e_test_ne = new vx_test::Class_test_ne();
      vx_core::vx_reserve_empty(vx_test::e_test_ne);
      vx_test::t_test_ne = new vx_test::Class_test_ne();
      vx_core::vx_reserve_type(vx_test::t_test_ne);
      vx_test::e_test_ne_1 = new vx_test::Class_test_ne_1();
      vx_core::vx_reserve_empty(vx_test::e_test_ne_1);
      vx_test::t_test_ne_1 = new vx_test::Class_test_ne_1();
      vx_core::vx_reserve_type(vx_test::t_test_ne_1);
      vx_test::e_test_string = new vx_test::Class_test_string();
      vx_core::vx_reserve_empty(vx_test::e_test_string);
      vx_test::t_test_string = new vx_test::Class_test_string();
      vx_core::vx_reserve_type(vx_test::t_test_string);
      vx_test::e_test_string_1 = new vx_test::Class_test_string_1();
      vx_core::vx_reserve_empty(vx_test::e_test_string_1);
      vx_test::t_test_string_1 = new vx_test::Class_test_string_1();
      vx_core::vx_reserve_type(vx_test::t_test_string_1);
      vx_test::e_test_true = new vx_test::Class_test_true();
      vx_core::vx_reserve_empty(vx_test::e_test_true);
      vx_test::t_test_true = new vx_test::Class_test_true();
      vx_core::vx_reserve_type(vx_test::t_test_true);
      vx_test::e_test_true_1 = new vx_test::Class_test_true_1();
      vx_core::vx_reserve_empty(vx_test::e_test_true_1);
      vx_test::t_test_true_1 = new vx_test::Class_test_true_1();
      vx_core::vx_reserve_type(vx_test::t_test_true_1);
      vx_test::e_tr_from_testdescribe_casename = new vx_test::Class_tr_from_testdescribe_casename();
      vx_core::vx_reserve_empty(vx_test::e_tr_from_testdescribe_casename);
      vx_test::t_tr_from_testdescribe_casename = new vx_test::Class_tr_from_testdescribe_casename();
      vx_core::vx_reserve_type(vx_test::t_tr_from_testdescribe_casename);
      vx_test::e_trlist_from_testcase = new vx_test::Class_trlist_from_testcase();
      vx_core::vx_reserve_empty(vx_test::e_trlist_from_testcase);
      vx_test::t_trlist_from_testcase = new vx_test::Class_trlist_from_testcase();
      vx_core::vx_reserve_type(vx_test::t_trlist_from_testcase);
      vx_test::e_trlist_from_testcaselist = new vx_test::Class_trlist_from_testcaselist();
      vx_core::vx_reserve_empty(vx_test::e_trlist_from_testcaselist);
      vx_test::t_trlist_from_testcaselist = new vx_test::Class_trlist_from_testcaselist();
      vx_core::vx_reserve_type(vx_test::t_trlist_from_testcaselist);
      vx_test::c_stylesheet_test = new vx_test::Class_stylesheet_test();
      vx_test::Class_stylesheet_test::vx_const_new(vx_test::c_stylesheet_test);
    }
    vx_core::vx_Type_mapany vx_Class_package::maptype() {
      vx_core::vx_Type_mapany output;
      output["anylist"] = vx_core::t_anylist;
      return output;
    }
    vx_core::vx_Type_mapany vx_Class_package::mapconst() {
      vx_core::vx_Type_mapany output;
      return output;
    }
    std::map<std::string, vx_core::Type_func> vx_Class_package::mapfunc() {
      vx_core::vx_Type_mapfunc output;
      return output;
    }
  // }

}
