#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "textblock.hpp"

namespace vx_data_textblock {


  // (type delimset)
  // class Class_delimset {
    Abstract_delimset::~Abstract_delimset() {}

    Class_delimset::Class_delimset() : Abstract_delimset::Abstract_delimset() {
      vx_core::refcount += 1;
    }
    Class_delimset::~Class_delimset() {
      vx_core::refcount -= 1;
    }
    // start()
    vx_core::Type_stringlist Class_delimset::start() const {
      vx_core::Type_stringlist output = this->vx_p_start;
      if (output == NULL) {
        output = vx_core::e_stringlist();
      }
      return output;
    }

    // end()
    vx_core::Type_stringlist Class_delimset::end() const {
      vx_core::Type_stringlist output = this->vx_p_end;
      if (output == NULL) {
        output = vx_core::e_stringlist();
      }
      return output;
    }

    // split()
    vx_core::Type_stringlist Class_delimset::split() const {
      vx_core::Type_stringlist output = this->vx_p_split;
      if (output == NULL) {
        output = vx_core::e_stringlist();
      }
      return output;
    }

    // subset()
    vx_data_textblock::Type_delimset Class_delimset::subset() const {
      vx_data_textblock::Type_delimset output = this->vx_p_subset;
      if (output == NULL) {
        output = vx_data_textblock::e_delimset();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_delimset::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":start") {
        output = this->start();
      } else if (skey == ":end") {
        output = this->end();
      } else if (skey == ":split") {
        output = this->split();
      } else if (skey == ":subset") {
        output = this->subset();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_delimset::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":start"] = this->start();
      output[":end"] = this->end();
      output[":split"] = this->split();
      output[":subset"] = this->subset();
      return output;
    }

    vx_core::Type_any Class_delimset::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_delimset(), vals);
    }
    vx_core::Type_any Class_delimset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_delimset output = vx_data_textblock::e_delimset();
      vx_data_textblock::Type_delimset val = vx_core::vx_any_from_any(vx_data_textblock::t_delimset(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_stringlist vx_p_start = val->start();
      vx_core::Type_stringlist vx_p_end = val->end();
      vx_core::Type_stringlist vx_p_split = val->split();
      vx_data_textblock::Type_delimset vx_p_subset = val->subset();
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
          } else if (testkey == ":start") {
            key = testkey;
          } else if (testkey == ":end") {
            key = testkey;
          } else if (testkey == ":split") {
            key = testkey;
          } else if (testkey == ":subset") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":start") {
            if (valsubtype == vx_core::t_stringlist()) {
              vx_p_start = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset :start " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":end") {
            if (valsubtype == vx_core::t_stringlist()) {
              vx_p_end = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset :end " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":split") {
            if (valsubtype == vx_core::t_stringlist()) {
              vx_p_split = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset :split " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":subset") {
            if (valsubtype == vx_data_textblock::t_delimset()) {
              vx_p_subset = vx_core::vx_any_from_any(vx_data_textblock::t_delimset(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset :subset " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new delimset) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_textblock::Class_delimset();
      output->vx_p_start = vx_p_start;
      output->vx_p_end = vx_p_end;
      output->vx_p_split = vx_p_split;
      output->vx_p_subset = vx_p_subset;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_delimset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_delimset::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_delimset::vx_empty() const {return vx_data_textblock::e_delimset();}
    vx_core::Type_any Class_delimset::vx_type() const {return vx_data_textblock::t_delimset();}

    vx_core::Type_typedef Class_delimset::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delimset", // name
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

  // (type textblock)
  // class Class_textblock {
    Abstract_textblock::~Abstract_textblock() {}

    Class_textblock::Class_textblock() : Abstract_textblock::Abstract_textblock() {
      vx_core::refcount += 1;
    }
    Class_textblock::~Class_textblock() {
      vx_core::refcount -= 1;
    }
    // name()
    vx_core::Type_string Class_textblock::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_textblock::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // line()
    vx_core::Type_int Class_textblock::line() const {
      vx_core::Type_int output = this->vx_p_line;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // column()
    vx_core::Type_int Class_textblock::column() const {
      vx_core::Type_int output = this->vx_p_column;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // textblocks()
    vx_data_textblock::Type_textblocklist Class_textblock::textblocks() const {
      vx_data_textblock::Type_textblocklist output = this->vx_p_textblocks;
      if (output == NULL) {
        output = vx_data_textblock::e_textblocklist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_textblock::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":text") {
        output = this->text();
      } else if (skey == ":line") {
        output = this->line();
      } else if (skey == ":column") {
        output = this->column();
      } else if (skey == ":textblocks") {
        output = this->textblocks();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_textblock::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":text"] = this->text();
      output[":line"] = this->line();
      output[":column"] = this->column();
      output[":textblocks"] = this->textblocks();
      return output;
    }

    vx_core::Type_any Class_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_textblock(), vals);
    }
    vx_core::Type_any Class_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock();
      vx_data_textblock::Type_textblock val = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_text = val->text();
      vx_core::Type_int vx_p_line = val->line();
      vx_core::Type_int vx_p_column = val->column();
      vx_data_textblock::Type_textblocklist vx_p_textblocks = val->textblocks();
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
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (testkey == ":line") {
            key = testkey;
          } else if (testkey == ":column") {
            key = testkey;
          } else if (testkey == ":textblocks") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":line") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_line = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock :line " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":column") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_column = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock :column " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":textblocks") {
            if (valsubtype == vx_data_textblock::t_textblocklist()) {
              vx_p_textblocks = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock :textblocks " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblock) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_textblock::Class_textblock();
      output->vx_p_name = vx_p_name;
      output->vx_p_text = vx_p_text;
      output->vx_p_line = vx_p_line;
      output->vx_p_column = vx_p_column;
      output->vx_p_textblocks = vx_p_textblocks;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_textblock::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_textblock::vx_empty() const {return vx_data_textblock::e_textblock();}
    vx_core::Type_any Class_textblock::vx_type() const {return vx_data_textblock::t_textblock();}

    vx_core::Type_typedef Class_textblock::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock", // name
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

  // (type textblocklist)
  // class Class_textblocklist {
    Abstract_textblocklist::~Abstract_textblocklist() {}

    Class_textblocklist::Class_textblocklist() : Abstract_textblocklist::Abstract_textblocklist() {
      vx_core::refcount += 1;
    }
    Class_textblocklist::~Class_textblocklist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_textblocklist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_data_textblock::Type_textblock Class_textblocklist::vx_get_textblock(vx_core::Type_int index) const {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock();
      long iindex = index->vx_int();
      std::vector<vx_data_textblock::Type_textblock> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_textblock::Type_textblock> Class_textblocklist::vx_listtextblock() const {return vx_p_list;}

    vx_core::Type_any vx_data_textblock::Class_textblocklist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_textblock(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_textblocklist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_data_textblock::Type_textblock> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_textblock::t_textblock()) {
          vx_data_textblock::Type_textblock castval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(textblocklist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_textblock::Class_textblocklist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_textblocklist(), vals);
    }
    vx_core::Type_any Class_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist();
      vx_data_textblock::Type_textblocklist val = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_textblock::Type_textblock> listval = val->vx_listtextblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_textblock()) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), valsub));
        } else if (valsubtype == vx_data_textblock::t_textblocklist()) {
          vx_data_textblock::Type_textblocklist multi = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtextblock());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new textblocklist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_data_textblock::Class_textblocklist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_textblocklist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_textblocklist::vx_empty() const {return vx_data_textblock::e_textblocklist();}
    vx_core::Type_any Class_textblocklist::vx_type() const {return vx_data_textblock::t_textblocklist();}

    vx_core::Type_typedef Class_textblocklist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_textblock::t_textblock()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (func parse)
  vx_data_textblock::Type_textblock f_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock();
    output = block;
    return output;
  }

  // (func parse)
  // class Class_parse {
    Abstract_parse::~Abstract_parse() {}

    Class_parse::Class_parse() : Abstract_parse::Abstract_parse() {
      vx_core::refcount += 1;
    }
    Class_parse::~Class_parse() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_parse::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_parse output = vx_data_textblock::e_parse();
      return output;
    }

    vx_core::Type_any Class_parse::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_parse output = vx_data_textblock::e_parse();
      return output;
    }

    vx_core::Type_typedef Class_parse::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock", // name
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

    vx_core::Type_funcdef Class_parse::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "parse", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_parse::vx_empty() const {return vx_data_textblock::e_parse();}
    vx_core::Type_any Class_parse::vx_type() const {return vx_data_textblock::t_parse();}
    vx_core::Type_msgblock Class_parse::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_parse::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_parse::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock block = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delimset delimpairlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimset(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_parse(block, delimpairlist);
      return output;
    }

  //}

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks) {
    vx_core::Type_stringlist output = vx_core::e_stringlist();
    output = vx_core::f_list_from_list(
      vx_core::t_stringlist(),
      textblocks,
      vx_data_textblock::t_text_from_textblock()
    );
    return output;
  }

  // (func stringlist<-textblocklist)
  // class Class_stringlist_from_textblocklist {
    Abstract_stringlist_from_textblocklist::~Abstract_stringlist_from_textblocklist() {}

    Class_stringlist_from_textblocklist::Class_stringlist_from_textblocklist() : Abstract_stringlist_from_textblocklist::Abstract_stringlist_from_textblocklist() {
      vx_core::refcount += 1;
    }
    Class_stringlist_from_textblocklist::~Class_stringlist_from_textblocklist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_stringlist_from_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::e_stringlist_from_textblocklist();
      return output;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::e_stringlist_from_textblocklist();
      return output;
    }

    vx_core::Type_typedef Class_stringlist_from_textblocklist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_string()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_stringlist_from_textblocklist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_empty() const {return vx_data_textblock::e_stringlist_from_textblocklist();}
    vx_core::Type_any Class_stringlist_from_textblocklist::vx_type() const {return vx_data_textblock::t_stringlist_from_textblocklist();}
    vx_core::Type_msgblock Class_stringlist_from_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stringlist_from_textblocklist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stringlist_from_textblocklist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblocklist inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist(), val);
      output = vx_data_textblock::f_stringlist_from_textblocklist(inputval);
      return output;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblocklist textblocks = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_stringlist_from_textblocklist(textblocks);
      return output;
    }

  //}

  // (func text<-textblock)
  vx_core::Type_string f_text_from_textblock(vx_data_textblock::Type_textblock block) {
    vx_core::Type_string output = vx_core::e_string();
    output = block->text();
    return output;
  }

  // (func text<-textblock)
  // class Class_text_from_textblock {
    Abstract_text_from_textblock::~Abstract_text_from_textblock() {}

    Class_text_from_textblock::Class_text_from_textblock() : Abstract_text_from_textblock::Abstract_text_from_textblock() {
      vx_core::refcount += 1;
    }
    Class_text_from_textblock::~Class_text_from_textblock() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_text_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::e_text_from_textblock();
      return output;
    }

    vx_core::Type_any Class_text_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::e_text_from_textblock();
      return output;
    }

    vx_core::Type_typedef Class_text_from_textblock::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
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

    vx_core::Type_funcdef Class_text_from_textblock::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_text_from_textblock::vx_empty() const {return vx_data_textblock::e_text_from_textblock();}
    vx_core::Type_any Class_text_from_textblock::vx_type() const {return vx_data_textblock::t_text_from_textblock();}
    vx_core::Type_msgblock Class_text_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_text_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_text_from_textblock::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_text_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), val);
      output = vx_data_textblock::f_text_from_textblock(inputval);
      return output;
    }

    vx_core::Type_any Class_text_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock block = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_text_from_textblock(block);
      return output;
    }

  //}

  // (func textblocks<-textblock)
  vx_data_textblock::Type_textblocklist f_textblocks_from_textblock(vx_data_textblock::Type_textblock block) {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist();
    output = block->textblocks();
    return output;
  }

  // (func textblocks<-textblock)
  // class Class_textblocks_from_textblock {
    Abstract_textblocks_from_textblock::~Abstract_textblocks_from_textblock() {}

    Class_textblocks_from_textblock::Class_textblocks_from_textblock() : Abstract_textblocks_from_textblock::Abstract_textblocks_from_textblock() {
      vx_core::refcount += 1;
    }
    Class_textblocks_from_textblock::~Class_textblocks_from_textblock() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_textblocks_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblocks_from_textblock output = vx_data_textblock::e_textblocks_from_textblock();
      return output;
    }

    vx_core::Type_any Class_textblocks_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblocks_from_textblock output = vx_data_textblock::e_textblocks_from_textblock();
      return output;
    }

    vx_core::Type_typedef Class_textblocks_from_textblock::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_textblock::t_textblock()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_textblocks_from_textblock::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocks<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_textblocks_from_textblock::vx_empty() const {return vx_data_textblock::e_textblocks_from_textblock();}
    vx_core::Type_any Class_textblocks_from_textblock::vx_type() const {return vx_data_textblock::t_textblocks_from_textblock();}
    vx_core::Type_msgblock Class_textblocks_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblocks_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblocks_from_textblock::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_textblocks_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), val);
      output = vx_data_textblock::f_textblocks_from_textblock(inputval);
      return output;
    }

    vx_core::Type_any Class_textblocks_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock block = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblocks_from_textblock(block);
      return output;
    }

  //}

  vx_data_textblock::vx_Class_package* vx_package = new vx_data_textblock::vx_Class_package();

  vx_data_textblock::Type_delimset e_delimset() {
    vx_data_textblock::Type_delimset output = vx_data_textblock::vx_package->e_delimset;
    if (output == NULL) {
      output = new Class_delimset();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_delimset = output;
    }
    return output;
  }
  vx_data_textblock::Type_delimset t_delimset() {
    vx_data_textblock::Type_delimset output = vx_data_textblock::vx_package->t_delimset;
    if (output == NULL) {
      output = new Class_delimset();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_delimset = output;
    }
    return output;
  }

  vx_data_textblock::Type_textblock e_textblock() {
    vx_data_textblock::Type_textblock output = vx_data_textblock::vx_package->e_textblock;
    if (output == NULL) {
      output = new Class_textblock();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_textblock = output;
    }
    return output;
  }
  vx_data_textblock::Type_textblock t_textblock() {
    vx_data_textblock::Type_textblock output = vx_data_textblock::vx_package->t_textblock;
    if (output == NULL) {
      output = new Class_textblock();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_textblock = output;
    }
    return output;
  }

  vx_data_textblock::Type_textblocklist e_textblocklist() {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::vx_package->e_textblocklist;
    if (output == NULL) {
      output = new Class_textblocklist();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_textblocklist = output;
    }
    return output;
  }
  vx_data_textblock::Type_textblocklist t_textblocklist() {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::vx_package->t_textblocklist;
    if (output == NULL) {
      output = new Class_textblocklist();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_textblocklist = output;
    }
    return output;
  }

  // (func parse)
  vx_data_textblock::Func_parse e_parse() {
    vx_data_textblock::Func_parse output = vx_data_textblock::vx_package->e_parse;
    if (output == NULL) {
      output = new vx_data_textblock::Class_parse();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_parse = output;
    }
    return output;
  }
  vx_data_textblock::Func_parse t_parse() {
    vx_data_textblock::Func_parse output = vx_data_textblock::vx_package->t_parse;
    if (output == NULL) {
      output = new vx_data_textblock::Class_parse();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_parse = output;
    }
    return output;
  }

  // (func stringlist<-textblocklist)
  vx_data_textblock::Func_stringlist_from_textblocklist e_stringlist_from_textblocklist() {
    vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::vx_package->e_stringlist_from_textblocklist;
    if (output == NULL) {
      output = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_stringlist_from_textblocklist = output;
    }
    return output;
  }
  vx_data_textblock::Func_stringlist_from_textblocklist t_stringlist_from_textblocklist() {
    vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::vx_package->t_stringlist_from_textblocklist;
    if (output == NULL) {
      output = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_stringlist_from_textblocklist = output;
    }
    return output;
  }

  // (func text<-textblock)
  vx_data_textblock::Func_text_from_textblock e_text_from_textblock() {
    vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::vx_package->e_text_from_textblock;
    if (output == NULL) {
      output = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_text_from_textblock = output;
    }
    return output;
  }
  vx_data_textblock::Func_text_from_textblock t_text_from_textblock() {
    vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::vx_package->t_text_from_textblock;
    if (output == NULL) {
      output = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_text_from_textblock = output;
    }
    return output;
  }

  // (func textblocks<-textblock)
  vx_data_textblock::Func_textblocks_from_textblock e_textblocks_from_textblock() {
    vx_data_textblock::Func_textblocks_from_textblock output = vx_data_textblock::vx_package->e_textblocks_from_textblock;
    if (output == NULL) {
      output = new vx_data_textblock::Class_textblocks_from_textblock();
      vx_core::vx_reserve_empty(output);
      vx_data_textblock::vx_package->e_textblocks_from_textblock = output;
    }
    return output;
  }
  vx_data_textblock::Func_textblocks_from_textblock t_textblocks_from_textblock() {
    vx_data_textblock::Func_textblocks_from_textblock output = vx_data_textblock::vx_package->t_textblocks_from_textblock;
    if (output == NULL) {
      output = new vx_data_textblock::Class_textblocks_from_textblock();
      vx_core::vx_reserve_type(output);
      vx_data_textblock::vx_package->t_textblocks_from_textblock = output;
    }
    return output;
  }

}
