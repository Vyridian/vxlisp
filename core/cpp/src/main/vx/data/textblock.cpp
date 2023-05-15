#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "vx/data/textblock.hpp"

//namespace vx_data_textblock {

  /**
   * type: delimset
   * (type delimset)
   */
  //class Type_delimset {
    // start()
    vx_core::Type_stringlist vx_data_textblock::Class_delimset::start() {
      vx_core::Type_stringlist output = this->vx_p_start;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
      return output;
    }

    // end()
    vx_core::Type_stringlist vx_data_textblock::Class_delimset::end() {
      vx_core::Type_stringlist output = this->vx_p_end;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
      return output;
    }

    // split()
    vx_core::Type_stringlist vx_data_textblock::Class_delimset::split() {
      vx_core::Type_stringlist output = this->vx_p_split;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
      return output;
    }

    // subset()
    vx_data_textblock::Type_delimset vx_data_textblock::Class_delimset::subset() {
      vx_data_textblock::Type_delimset output = this->vx_p_subset;
      if (output == NULL) {
        output = vx_data_textblock::t_delimset;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_data_textblock::Class_delimset::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
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
    vx_core::vx_Type_mapany vx_data_textblock::Class_delimset::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":start"] = this->start();
      output[":end"] = this->end();
      output[":split"] = this->split();
      output[":subset"] = this->subset();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_delimset::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_textblock::e_delimset->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_delimset::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Type_delimset output;
      vx_data_textblock::Class_delimset* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_start = val->start();
      output->vx_p_end = val->end();
      output->vx_p_split = val->split();
      output->vx_p_subset = val->subset();
      std::set<std::string> validkeys;
      validkeys.insert(":start");
      validkeys.insert(":end");
      validkeys.insert(":split");
      validkeys.insert(":subset");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":start") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_start = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset :start " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":end") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_end = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset :end " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":split") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_split = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset :split " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":subset") {
            if (valsubtype == vx_data_textblock::t_delimset) {
              output->vx_p_subset = vx_core::any_from_any(vx_data_textblock::t_delimset, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset :subset " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new delimset) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_delimset::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_delimset;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_delimset::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_delimset;}

    vx_core::Type_typedef vx_data_textblock::Class_delimset::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delimset", // name
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

    vx_data_textblock::Type_delimset vx_data_textblock::e_delimset = std::make_shared<vx_data_textblock::Class_delimset>();
    vx_data_textblock::Type_delimset vx_data_textblock::t_delimset = std::make_shared<vx_data_textblock::Class_delimset>();
  //}

  /**
   * type: textblock
   * (type textblock)
   */
  //class Type_textblock {
    // name()
    vx_core::Type_string vx_data_textblock::Class_textblock::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // text()
    vx_core::Type_string vx_data_textblock::Class_textblock::text() {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // line()
    vx_core::Type_int vx_data_textblock::Class_textblock::line() {
      vx_core::Type_int output = this->vx_p_line;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // column()
    vx_core::Type_int vx_data_textblock::Class_textblock::column() {
      vx_core::Type_int output = this->vx_p_column;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // textblocks()
    vx_data_textblock::Type_textblocklist vx_data_textblock::Class_textblock::textblocks() {
      vx_data_textblock::Type_textblocklist output = this->vx_p_textblocks;
      if (output == NULL) {
        output = vx_data_textblock::t_textblocklist;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_data_textblock::Class_textblock::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
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
    vx_core::vx_Type_mapany vx_data_textblock::Class_textblock::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":text"] = this->text();
      output[":line"] = this->line();
      output[":column"] = this->column();
      output[":textblocks"] = this->textblocks();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_textblock::e_textblock->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Type_textblock output;
      vx_data_textblock::Class_textblock* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_name = val->name();
      output->vx_p_text = val->text();
      output->vx_p_line = val->line();
      output->vx_p_column = val->column();
      output->vx_p_textblocks = val->textblocks();
      std::set<std::string> validkeys;
      validkeys.insert(":name");
      validkeys.insert(":text");
      validkeys.insert(":line");
      validkeys.insert(":column");
      validkeys.insert(":textblocks");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":line") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_line = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock :line " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":column") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_column = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock :column " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":textblocks") {
            if (valsubtype == vx_data_textblock::t_textblocklist) {
              output->vx_p_textblocks = vx_core::any_from_any(vx_data_textblock::t_textblocklist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock :textblocks " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblock) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_textblock;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_textblock;}

    vx_core::Type_typedef vx_data_textblock::Class_textblock::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock", // name
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

    vx_data_textblock::Type_textblock vx_data_textblock::e_textblock = std::make_shared<vx_data_textblock::Class_textblock>();
    vx_data_textblock::Type_textblock vx_data_textblock::t_textblock = std::make_shared<vx_data_textblock::Class_textblock>();
  //}

  /**
   * type: textblocklist
   * (type textblocklist)
   */
  //class Type_textblocklist {
    vx_core::vx_Type_listany vx_data_textblock::Class_textblocklist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_textblock::Type_textblock vx_data_textblock::Class_textblocklist::vx_textblock(vx_core::Type_int index) {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
      vx_data_textblock::Class_textblocklist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_textblock::Type_textblock> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_textblock::Type_textblock> vx_data_textblock::Class_textblocklist::vx_listtextblock() {return vx_p_list;}

    vx_core::Type_any vx_data_textblock::Class_textblocklist::vx_any(vx_core::Type_int index) {
      return this->vx_textblock(index);
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocklist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_textblock::e_textblocklist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocklist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Type_textblocklist output;
      vx_data_textblock::Class_textblocklist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_textblock::Type_textblock> listval = val->vx_listtextblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_textblock) {
          listval->push_back(vx_core::any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (valsubtype == vx_data_textblock::t_textblocklist) {
          vx_data_textblock::Type_textblocklist multi = vx_core::any_from_any(vx_data_textblock::t_textblocklist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtextblock());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new textblocklist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocklist::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_textblocklist;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocklist::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_textblocklist;}

    vx_core::Type_typedef vx_data_textblock::Class_textblocklist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_textblock::t_textblock}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_textblock::Type_textblocklist vx_data_textblock::e_textblocklist = std::make_shared<vx_data_textblock::Class_textblocklist>();
    vx_data_textblock::Type_textblocklist vx_data_textblock::t_textblocklist = std::make_shared<vx_data_textblock::Class_textblocklist>();
  //}
  /**
   * @function parse
   * @param  {textblock} block
   * @param  {delimset} delimpairlist
   * @return {textblock}
   * (func parse)
   */
  //class Func_parse {

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_parse::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_parse output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_parse::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_parse output;
      return output;
    }

    vx_core::Type_typedef vx_data_textblock::Class_parse::vx_typedef() {return vx_data_textblock::t_parse->vx_typedef();}

    vx_core::Type_funcdef vx_data_textblock::Class_parse::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "parse", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_parse::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_parse;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_parse::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_parse;}

    vx_core::Type_any vx_data_textblock::Class_parse::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_data_textblock::Type_delimset delimpairlist = vx_core::f_any_from_any(vx_data_textblock::t_delimset, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_data_textblock::f_parse(block, delimpairlist);
      return output;
    }

    vx_data_textblock::Type_textblock vx_data_textblock::Class_parse::vx_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist) {
      return vx_data_textblock::f_parse(block, delimpairlist);
    }

  //}

  vx_data_textblock::Func_parse vx_data_textblock::e_parse = std::make_shared<vx_data_textblock::Class_parse>();
  vx_data_textblock::Func_parse vx_data_textblock::t_parse = std::make_shared<vx_data_textblock::Class_parse>();

  vx_data_textblock::Type_textblock vx_data_textblock::f_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    output = block;
    return output;
  }

  /**
   * @function stringlist_from_textblocklist
   * Returns the child textblocks from a given textblock.
   * @param  {textblocklist} textblocks
   * @return {stringlist}
   * (func stringlist<-textblocklist)
   */
  //class Func_stringlist_from_textblocklist {

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_stringlist_from_textblocklist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_stringlist_from_textblocklist output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_stringlist_from_textblocklist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_stringlist_from_textblocklist output;
      return output;
    }

    vx_core::Type_typedef vx_data_textblock::Class_stringlist_from_textblocklist::vx_typedef() {return vx_data_textblock::t_stringlist_from_textblocklist->vx_typedef();}

    vx_core::Type_funcdef vx_data_textblock::Class_stringlist_from_textblocklist::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_stringlist_from_textblocklist::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_stringlist_from_textblocklist;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_stringlist_from_textblocklist::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_stringlist_from_textblocklist;}

    vx_core::Func_any_from_any vx_data_textblock::Class_stringlist_from_textblocklist::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_textblock::Class_stringlist_from_textblocklist::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblocklist inputval = (vx_data_textblock::Type_textblocklist)value;
      vx_core::Type_any outputval = vx_data_textblock::f_stringlist_from_textblocklist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_textblock::Class_stringlist_from_textblocklist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist textblocks = vx_core::f_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_stringlist_from_textblocklist(textblocks);
      return output;
    }

    vx_core::Type_stringlist vx_data_textblock::Class_stringlist_from_textblocklist::vx_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks) {
      return vx_data_textblock::f_stringlist_from_textblocklist(textblocks);
    }

  //}

  vx_data_textblock::Func_stringlist_from_textblocklist vx_data_textblock::e_stringlist_from_textblocklist = std::make_shared<vx_data_textblock::Class_stringlist_from_textblocklist>();
  vx_data_textblock::Func_stringlist_from_textblocklist vx_data_textblock::t_stringlist_from_textblocklist = std::make_shared<vx_data_textblock::Class_stringlist_from_textblocklist>();

  vx_core::Type_stringlist vx_data_textblock::f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    output = vx_core::f_list_from_list(
      vx_core::t_stringlist,
      textblocks,
      vx_data_textblock::t_text_from_textblock
    );
    return output;
  }

  /**
   * @function text_from_textblock
   * Returns the text from a given textblock.
   * @param  {textblock} block
   * @return {string}
   * (func text<-textblock)
   */
  //class Func_text_from_textblock {

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_text_from_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_text_from_textblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_text_from_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_text_from_textblock output;
      return output;
    }

    vx_core::Type_typedef vx_data_textblock::Class_text_from_textblock::vx_typedef() {return vx_data_textblock::t_text_from_textblock->vx_typedef();}

    vx_core::Type_funcdef vx_data_textblock::Class_text_from_textblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_text_from_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_text_from_textblock;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_text_from_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_text_from_textblock;}

    vx_core::Func_any_from_any vx_data_textblock::Class_text_from_textblock::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_textblock::Class_text_from_textblock::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any outputval = vx_data_textblock::f_text_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_textblock::Class_text_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_text_from_textblock(block);
      return output;
    }

    vx_core::Type_string vx_data_textblock::Class_text_from_textblock::vx_text_from_textblock(vx_data_textblock::Type_textblock block) {
      return vx_data_textblock::f_text_from_textblock(block);
    }

  //}

  vx_data_textblock::Func_text_from_textblock vx_data_textblock::e_text_from_textblock = std::make_shared<vx_data_textblock::Class_text_from_textblock>();
  vx_data_textblock::Func_text_from_textblock vx_data_textblock::t_text_from_textblock = std::make_shared<vx_data_textblock::Class_text_from_textblock>();

  vx_core::Type_string vx_data_textblock::f_text_from_textblock(vx_data_textblock::Type_textblock block) {
    vx_core::Type_string output = vx_core::e_string;
    output = block->text();
    return output;
  }

  /**
   * @function textblocks_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} block
   * @return {textblocklist}
   * (func textblocks<-textblock)
   */
  //class Func_textblocks_from_textblock {

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocks_from_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_textblocks_from_textblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocks_from_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_textblock::Func_textblocks_from_textblock output;
      return output;
    }

    vx_core::Type_typedef vx_data_textblock::Class_textblocks_from_textblock::vx_typedef() {return vx_data_textblock::t_textblocks_from_textblock->vx_typedef();}

    vx_core::Type_funcdef vx_data_textblock::Class_textblocks_from_textblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocks<-textblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_textblock::t_textblock}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocks_from_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_textblock::e_textblocks_from_textblock;}
    template <class T> std::shared_ptr<T> vx_data_textblock::Class_textblocks_from_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_textblock::t_textblocks_from_textblock;}

    vx_core::Func_any_from_any vx_data_textblock::Class_textblocks_from_textblock::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_textblock::Class_textblocks_from_textblock::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any outputval = vx_data_textblock::f_textblocks_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_textblock::Class_textblocks_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_textblocks_from_textblock(block);
      return output;
    }

    vx_data_textblock::Type_textblocklist vx_data_textblock::Class_textblocks_from_textblock::vx_textblocks_from_textblock(vx_data_textblock::Type_textblock block) {
      return vx_data_textblock::f_textblocks_from_textblock(block);
    }

  //}

  vx_data_textblock::Func_textblocks_from_textblock vx_data_textblock::e_textblocks_from_textblock = std::make_shared<vx_data_textblock::Class_textblocks_from_textblock>();
  vx_data_textblock::Func_textblocks_from_textblock vx_data_textblock::t_textblocks_from_textblock = std::make_shared<vx_data_textblock::Class_textblocks_from_textblock>();

  vx_data_textblock::Type_textblocklist vx_data_textblock::f_textblocks_from_textblock(vx_data_textblock::Type_textblock block) {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist;
    output = block->textblocks();
    return output;
  }


//}
