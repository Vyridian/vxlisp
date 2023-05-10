#include <any>
#include <map>
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
    vx_core::Type_stringlist* vx_data_textblock::Type_delimset::start() {
      vx_core::Type_stringlist* output = this->vx_p_start;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // end()
    vx_core::Type_stringlist* vx_data_textblock::Type_delimset::end() {
      vx_core::Type_stringlist* output = this->vx_p_end;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // split()
    vx_core::Type_stringlist* vx_data_textblock::Type_delimset::split() {
      vx_core::Type_stringlist* output = this->vx_p_split;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // subset()
    vx_data_textblock::Type_delimset* vx_data_textblock::Type_delimset::subset() {
      vx_data_textblock::Type_delimset* output = this->vx_p_subset;
      if (output == NULL) {
        output = vx_data_textblock::t_delimset;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_textblock::Type_delimset::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_textblock::Type_delimset::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":start"] = this->start();
      output[":end"] = this->end();
      output[":split"] = this->split();
      output[":subset"] = this->subset();
      return output;
    }

    template<typename... Args> vx_data_textblock::Type_delimset* vx_data_textblock::Type_delimset::vx_new(Args*... args) {return vx_data_textblock::e_delimset->vx_copy(args...);}
    template<typename... Args> vx_data_textblock::Type_delimset* vx_data_textblock::Type_delimset::vx_copy(Args*... args) {
      vx_data_textblock::Type_delimset* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_delimset* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":start") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_start = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset :start " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":end") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_end = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset :end " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":split") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_split = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset :split " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":subset") {
            if (valsubtype == vx_data_textblock::t_delimset) {
              output->vx_p_subset = vx_core::any_from_any(vx_data_textblock::t_delimset, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset :subset " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new delimset) - Invalid Key: " + key);
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

    vx_data_textblock::Type_delimset* vx_data_textblock::Type_delimset::vx_empty() {return vx_data_textblock::e_delimset;}
    vx_data_textblock::Type_delimset* vx_data_textblock::Type_delimset::vx_type() {return vx_data_textblock::t_delimset;}

    vx_core::Type_typedef* vx_data_textblock::Type_delimset::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: textblock
   * (type textblock)
   */
  //class Type_textblock {
    // name()
    vx_core::Type_string* vx_data_textblock::Type_textblock::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // text()
    vx_core::Type_string* vx_data_textblock::Type_textblock::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // line()
    vx_core::Type_int* vx_data_textblock::Type_textblock::line() {
      vx_core::Type_int* output = this->vx_p_line;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // column()
    vx_core::Type_int* vx_data_textblock::Type_textblock::column() {
      vx_core::Type_int* output = this->vx_p_column;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // textblocks()
    vx_data_textblock::Type_textblocklist* vx_data_textblock::Type_textblock::textblocks() {
      vx_data_textblock::Type_textblocklist* output = this->vx_p_textblocks;
      if (output == NULL) {
        output = vx_data_textblock::t_textblocklist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_textblock::Type_textblock::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_textblock::Type_textblock::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":name"] = this->name();
      output[":text"] = this->text();
      output[":line"] = this->line();
      output[":column"] = this->column();
      output[":textblocks"] = this->textblocks();
      return output;
    }

    template<typename... Args> vx_data_textblock::Type_textblock* vx_data_textblock::Type_textblock::vx_new(Args*... args) {return vx_data_textblock::e_textblock->vx_copy(args...);}
    template<typename... Args> vx_data_textblock::Type_textblock* vx_data_textblock::Type_textblock::vx_copy(Args*... args) {
      vx_data_textblock::Type_textblock* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_textblock* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":line") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_line = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_line = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock :line " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":column") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_column = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_column = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock :column " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":textblocks") {
            if (valsubtype == vx_data_textblock::t_textblocklist) {
              output->vx_p_textblocks = vx_core::any_from_any(vx_data_textblock::t_textblocklist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock :textblocks " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblock) - Invalid Key: " + key);
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

    vx_data_textblock::Type_textblock* vx_data_textblock::Type_textblock::vx_empty() {return vx_data_textblock::e_textblock;}
    vx_data_textblock::Type_textblock* vx_data_textblock::Type_textblock::vx_type() {return vx_data_textblock::t_textblock;}

    vx_core::Type_typedef* vx_data_textblock::Type_textblock::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: textblocklist
   * (type textblocklist)
   */
  //class Type_textblocklist {
    std::vector<vx_core::Type_any*> vx_data_textblock::Type_textblocklist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_textblock::Type_textblock* vx_data_textblock::Type_textblocklist::vx_textblock(vx_core::Type_int* index) {
      vx_data_textblock::Type_textblock* output = vx_data_textblock::e_textblock;
      vx_data_textblock::Type_textblocklist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_textblock::Type_textblock*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_textblock::Type_textblock*> vx_data_textblock::Type_textblocklist::vx_listtextblock() {return vx_p_list;}

    vx_core::Type_any* vx_data_textblock::Type_textblocklist::vx_any(vx_core::Type_int* index) {
      return this->vx_textblock(index);
    }

    template<typename... Args> vx_data_textblock::Type_textblocklist* vx_data_textblock::Type_textblocklist::vx_new(Args*... args) {return vx_data_textblock::e_textblocklist->vx_copy(args...);}
    template<typename... Args> vx_data_textblock::Type_textblocklist* vx_data_textblock::Type_textblocklist::vx_copy(Args*... args) {
      vx_data_textblock::Type_textblocklist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_textblock::Type_textblocklist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_textblock::Type_textblock*> listval = val->vx_listtextblock();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_textblock::t_textblock) {
          listval.push_back(vx_core::any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (valsubtype == vx_data_textblock::t_textblocklist) {
          vx_data_textblock::Type_textblocklist* multi = vx_core::any_from_any(vx_data_textblock::t_textblocklist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtextblock());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_textblock::t_textblock) {
              vx_data_textblock::Type_textblock* valitem = vx_core::any_from_any(vx_data_textblock::t_textblock, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new textblocklist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_textblock::Type_textblocklist* vx_data_textblock::Type_textblocklist::vx_empty() {return vx_data_textblock::e_textblocklist;}
    vx_data_textblock::Type_textblocklist* vx_data_textblock::Type_textblocklist::vx_type() {return vx_data_textblock::t_textblocklist;}

    vx_core::Type_typedef* vx_data_textblock::Type_textblocklist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_textblock::t_textblock), // allowtypes
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
   * @function parse
   * @param  {textblock} block
   * @param  {delimset} delimpairlist
   * @return {textblock}
   * (func parse)
   */
  //class Func_parse {

    template<class... Args> vx_data_textblock::Func_parse* vx_data_textblock::Func_parse::vx_new(Args*... args) {
      vx_data_textblock::Func_parse* output;
      return output;
    }

    template<class... Args> vx_data_textblock::Func_parse* vx_data_textblock::Func_parse::vx_copy(Args*... args) {
      vx_data_textblock::Func_parse* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_textblock::Func_parse::vx_typedef() {return vx_data_textblock::t_parse->vx_typedef();}

    vx_core::Type_funcdef* vx_data_textblock::Func_parse::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "parse", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_data_textblock::Func_parse* vx_data_textblock::Func_parse::vx_empty() {return vx_data_textblock::e_parse;}
    vx_data_textblock::Func_parse* vx_data_textblock::Func_parse::vx_type() {return vx_data_textblock::t_parse;}

    vx_core::Type_any* vx_data_textblock::Func_parse::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblock* block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_data_textblock::Type_delimset* delimpairlist = vx_core::f_any_from_any(vx_data_textblock::t_delimset, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_data_textblock::f_parse(block, delimpairlist);
      return output;
    }

    vx_data_textblock::Type_textblock* vx_data_textblock::Func_parse::vx_parse(vx_data_textblock::Type_textblock* block, vx_data_textblock::Type_delimset* delimpairlist) {
      return vx_data_textblock::f_parse(block, delimpairlist);
    }

  //}

  vx_data_textblock::Func_parse* vx_data_textblock::e_parse = new vx_data_textblock::Func_parse();
  vx_data_textblock::Func_parse* vx_data_textblock::t_parse = new vx_data_textblock::Func_parse();

  vx_data_textblock::Type_textblock* vx_data_textblock::f_parse(vx_data_textblock::Type_textblock* block, vx_data_textblock::Type_delimset* delimpairlist) {
    vx_data_textblock::Type_textblock* output = vx_data_textblock::e_textblock;
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

    template<class... Args> vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::Func_stringlist_from_textblocklist::vx_new(Args*... args) {
      vx_data_textblock::Func_stringlist_from_textblocklist* output;
      return output;
    }

    template<class... Args> vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::Func_stringlist_from_textblocklist::vx_copy(Args*... args) {
      vx_data_textblock::Func_stringlist_from_textblocklist* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_textblock::Func_stringlist_from_textblocklist::vx_typedef() {return vx_data_textblock::t_stringlist_from_textblocklist->vx_typedef();}

    vx_core::Type_funcdef* vx_data_textblock::Func_stringlist_from_textblocklist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_string), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::Func_stringlist_from_textblocklist::vx_empty() {return vx_data_textblock::e_stringlist_from_textblocklist;}
    vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::Func_stringlist_from_textblocklist::vx_type() {return vx_data_textblock::t_stringlist_from_textblocklist;}

    vx_core::Func_any_from_any* vx_data_textblock::Func_stringlist_from_textblocklist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_data_textblock::Func_stringlist_from_textblocklist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblocklist* inputval = (vx_data_textblock::Type_textblocklist)value;
      vx_core::Type_any* outputval = vx_data_textblock::f_stringlist_from_textblocklist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_data_textblock::Func_stringlist_from_textblocklist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist* textblocks = vx_core::f_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_stringlist_from_textblocklist(textblocks);
      return output;
    }

    vx_core::Type_stringlist* vx_data_textblock::Func_stringlist_from_textblocklist::vx_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist* textblocks) {
      return vx_data_textblock::f_stringlist_from_textblocklist(textblocks);
    }

  //}

  vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::e_stringlist_from_textblocklist = new vx_data_textblock::Func_stringlist_from_textblocklist();
  vx_data_textblock::Func_stringlist_from_textblocklist* vx_data_textblock::t_stringlist_from_textblocklist = new vx_data_textblock::Func_stringlist_from_textblocklist();

  vx_core::Type_stringlist* vx_data_textblock::f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist* textblocks) {
    vx_core::Type_stringlist* output = vx_core::e_stringlist;
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

    template<class... Args> vx_data_textblock::Func_text_from_textblock* vx_data_textblock::Func_text_from_textblock::vx_new(Args*... args) {
      vx_data_textblock::Func_text_from_textblock* output;
      return output;
    }

    template<class... Args> vx_data_textblock::Func_text_from_textblock* vx_data_textblock::Func_text_from_textblock::vx_copy(Args*... args) {
      vx_data_textblock::Func_text_from_textblock* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_textblock::Func_text_from_textblock::vx_typedef() {return vx_data_textblock::t_text_from_textblock->vx_typedef();}

    vx_core::Type_funcdef* vx_data_textblock::Func_text_from_textblock::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_data_textblock::Func_text_from_textblock* vx_data_textblock::Func_text_from_textblock::vx_empty() {return vx_data_textblock::e_text_from_textblock;}
    vx_data_textblock::Func_text_from_textblock* vx_data_textblock::Func_text_from_textblock::vx_type() {return vx_data_textblock::t_text_from_textblock;}

    vx_core::Func_any_from_any* vx_data_textblock::Func_text_from_textblock::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_data_textblock::Func_text_from_textblock::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock* inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any* outputval = vx_data_textblock::f_text_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_data_textblock::Func_text_from_textblock::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblock* block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_text_from_textblock(block);
      return output;
    }

    vx_core::Type_string* vx_data_textblock::Func_text_from_textblock::vx_text_from_textblock(vx_data_textblock::Type_textblock* block) {
      return vx_data_textblock::f_text_from_textblock(block);
    }

  //}

  vx_data_textblock::Func_text_from_textblock* vx_data_textblock::e_text_from_textblock = new vx_data_textblock::Func_text_from_textblock();
  vx_data_textblock::Func_text_from_textblock* vx_data_textblock::t_text_from_textblock = new vx_data_textblock::Func_text_from_textblock();

  vx_core::Type_string* vx_data_textblock::f_text_from_textblock(vx_data_textblock::Type_textblock* block) {
    vx_core::Type_string* output = vx_core::e_string;
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

    template<class... Args> vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::Func_textblocks_from_textblock::vx_new(Args*... args) {
      vx_data_textblock::Func_textblocks_from_textblock* output;
      return output;
    }

    template<class... Args> vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::Func_textblocks_from_textblock::vx_copy(Args*... args) {
      vx_data_textblock::Func_textblocks_from_textblock* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_textblock::Func_textblocks_from_textblock::vx_typedef() {return vx_data_textblock::t_textblocks_from_textblock->vx_typedef();}

    vx_core::Type_funcdef* vx_data_textblock::Func_textblocks_from_textblock::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocks<-textblock", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_data_textblock::t_textblock), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::Func_textblocks_from_textblock::vx_empty() {return vx_data_textblock::e_textblocks_from_textblock;}
    vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::Func_textblocks_from_textblock::vx_type() {return vx_data_textblock::t_textblocks_from_textblock;}

    vx_core::Func_any_from_any* vx_data_textblock::Func_textblocks_from_textblock::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_data_textblock::Func_textblocks_from_textblock::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock* inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any* outputval = vx_data_textblock::f_textblocks_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_data_textblock::Func_textblocks_from_textblock::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblock* block = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_textblock::f_textblocks_from_textblock(block);
      return output;
    }

    vx_data_textblock::Type_textblocklist* vx_data_textblock::Func_textblocks_from_textblock::vx_textblocks_from_textblock(vx_data_textblock::Type_textblock* block) {
      return vx_data_textblock::f_textblocks_from_textblock(block);
    }

  //}

  vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::e_textblocks_from_textblock = new vx_data_textblock::Func_textblocks_from_textblock();
  vx_data_textblock::Func_textblocks_from_textblock* vx_data_textblock::t_textblocks_from_textblock = new vx_data_textblock::Func_textblocks_from_textblock();

  vx_data_textblock::Type_textblocklist* vx_data_textblock::f_textblocks_from_textblock(vx_data_textblock::Type_textblock* block) {
    vx_data_textblock::Type_textblocklist* output = vx_data_textblock::e_textblocklist;
    output = block->textblocks();
    return output;
  }


//}
