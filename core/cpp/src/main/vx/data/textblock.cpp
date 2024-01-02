#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "textblock.hpp"

namespace vx_data_textblock {



  // (type delim)
  // class Class_delim {
    Abstract_delim::~Abstract_delim() {}

    Class_delim::Class_delim() : Abstract_delim::Abstract_delim() {
      vx_core::refcount += 1;
    }

    Class_delim::~Class_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_starttext,
        this->vx_p_endtext,
        this->vx_p_pos,
        this->vx_p_delimlist
      });
    }

    // name()
    vx_core::Type_string Class_delim::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // starttext()
    vx_core::Type_string Class_delim::starttext() const {
      vx_core::Type_string output = this->vx_p_starttext;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // endtext()
    vx_core::Type_string Class_delim::endtext() const {
      vx_core::Type_string output = this->vx_p_endtext;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // pos()
    vx_core::Type_int Class_delim::pos() const {
      vx_core::Type_int output = this->vx_p_pos;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // delimlist()
    vx_data_textblock::Type_delimlist Class_delim::delimlist() const {
      vx_data_textblock::Type_delimlist output = this->vx_p_delimlist;
      if (!output) {
        output = vx_data_textblock::e_delimlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_delim::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":starttext") {
        output = this->starttext();
      } else if (skey == ":endtext") {
        output = this->endtext();
      } else if (skey == ":pos") {
        output = this->pos();
      } else if (skey == ":delimlist") {
        output = this->delimlist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_delim::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":starttext"] = this->starttext();
      output[":endtext"] = this->endtext();
      output[":pos"] = this->pos();
      output[":delimlist"] = this->delimlist();
      return output;
    }

    vx_core::Type_any Class_delim::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_delim, vals);
    }

    vx_core::Type_any Class_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_textblock::Type_delim val = vx_core::vx_any_from_any(vx_data_textblock::t_delim, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_starttext = val->starttext();
      vx_core::Type_string vx_p_endtext = val->endtext();
      vx_core::Type_int vx_p_pos = val->pos();
      vx_data_textblock::Type_delimlist vx_p_delimlist = val->delimlist();
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
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":starttext") {
            key = testkey;
          } else if (testkey == ":endtext") {
            key = testkey;
          } else if (testkey == ":pos") {
            key = testkey;
          } else if (testkey == ":delimlist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":starttext") {
            if (vx_p_starttext == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_starttext = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :starttext " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":endtext") {
            if (vx_p_endtext == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_endtext = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :endtext " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":pos") {
            if (vx_p_pos == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_pos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :pos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":delimlist") {
            if (vx_p_delimlist == valsub) {
            } else if (valsubtype == vx_data_textblock::t_delimlist) {
              ischanged = true;
              vx_p_delimlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :delimlist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_delim();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_starttext != vx_p_starttext) {
          if (output->vx_p_starttext) {
            vx_core::vx_release_one(output->vx_p_starttext);
          }
          output->vx_p_starttext = vx_p_starttext;
          vx_core::vx_reserve(vx_p_starttext);
        }
        if (output->vx_p_endtext != vx_p_endtext) {
          if (output->vx_p_endtext) {
            vx_core::vx_release_one(output->vx_p_endtext);
          }
          output->vx_p_endtext = vx_p_endtext;
          vx_core::vx_reserve(vx_p_endtext);
        }
        if (output->vx_p_pos != vx_p_pos) {
          if (output->vx_p_pos) {
            vx_core::vx_release_one(output->vx_p_pos);
          }
          output->vx_p_pos = vx_p_pos;
          vx_core::vx_reserve(vx_p_pos);
        }
        if (output->vx_p_delimlist != vx_p_delimlist) {
          if (output->vx_p_delimlist) {
            vx_core::vx_release_one(output->vx_p_delimlist);
          }
          output->vx_p_delimlist = vx_p_delimlist;
          vx_core::vx_reserve(vx_p_delimlist);
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_delim::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_delim::vx_empty() const {return vx_data_textblock::e_delim;}
    vx_core::Type_any Class_delim::vx_type() const {return vx_data_textblock::t_delim;}

    vx_core::Type_typedef Class_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim", // name
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
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "starttext", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "endtext", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "pos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_delim::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type delimlist)
  // class Class_delimlist {
    Abstract_delimlist::~Abstract_delimlist() {}

    Class_delimlist::Class_delimlist() : Abstract_delimlist::Abstract_delimlist() {
      vx_core::refcount += 1;
    }

    Class_delimlist::~Class_delimlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_delimlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_textblock::Type_delim Class_delimlist::vx_get_delim(vx_core::Type_int index) const {
      vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
      long iindex = index->vx_int();
      std::vector<vx_data_textblock::Type_delim> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_textblock::Type_delim> Class_delimlist::vx_listdelim() const {return vx_p_list;}

    vx_core::Type_any vx_data_textblock::Class_delimlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_delim(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_delimlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_textblock::Type_delimlist output = vx_data_textblock::e_delimlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_textblock::Type_delim> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_textblock::t_delim) {
          vx_data_textblock::Type_delim castval = vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_textblock::t_delim)) {
          vx_data_textblock::Type_delim castval = vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(delimlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_delimlist();
        output->vx_p_list = list;
        for (vx_core::Type_any valadd : list) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_delimlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_delimlist, vals);
    }

    vx_core::Type_any Class_delimlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_delimlist output = vx_data_textblock::e_delimlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_textblock::Type_delimlist val = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_textblock::Type_delim> listval = val->vx_listdelim();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_delim) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_textblock::t_delim)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub));
        } else if (valsubtype == vx_data_textblock::t_delimlist) {
          ischanged = true;
          vx_data_textblock::Type_delimlist multi = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdelim());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delimlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_delimlist();
        output->vx_p_list = listval;
        for (vx_core::Type_any valadd : listval) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_delimlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_delimlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_delimlist::vx_empty() const {return vx_data_textblock::e_delimlist;}
    vx_core::Type_any Class_delimlist::vx_type() const {return vx_data_textblock::t_delimlist;}

    vx_core::Type_typedef Class_delimlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_textblock::t_delim}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_delimlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type textblock)
  // class Class_textblock {
    Abstract_textblock::~Abstract_textblock() {}

    Class_textblock::Class_textblock() : Abstract_textblock::Abstract_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock::~Class_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_text,
        this->vx_p_startpos,
        this->vx_p_endpos,
        this->vx_p_curpos,
        this->vx_p_line,
        this->vx_p_column,
        this->vx_p_delim,
        this->vx_p_close,
        this->vx_p_parent,
        this->vx_p_children
      });
    }

    // name()
    vx_core::Type_string Class_textblock::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_textblock::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // startpos()
    vx_core::Type_int Class_textblock::startpos() const {
      vx_core::Type_int output = this->vx_p_startpos;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // endpos()
    vx_core::Type_int Class_textblock::endpos() const {
      vx_core::Type_int output = this->vx_p_endpos;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // curpos()
    vx_core::Type_int Class_textblock::curpos() const {
      vx_core::Type_int output = this->vx_p_curpos;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // line()
    vx_core::Type_int Class_textblock::line() const {
      vx_core::Type_int output = this->vx_p_line;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // column()
    vx_core::Type_int Class_textblock::column() const {
      vx_core::Type_int output = this->vx_p_column;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // delim()
    vx_data_textblock::Type_delim Class_textblock::delim() const {
      vx_data_textblock::Type_delim output = this->vx_p_delim;
      if (!output) {
        output = vx_data_textblock::e_delim;
      }
      return output;
    }

    // close()
    vx_data_textblock::Type_delim Class_textblock::close() const {
      vx_data_textblock::Type_delim output = this->vx_p_close;
      if (!output) {
        output = vx_data_textblock::e_delim;
      }
      return output;
    }

    // parent()
    vx_data_textblock::Type_textblock Class_textblock::parent() const {
      vx_data_textblock::Type_textblock output = this->vx_p_parent;
      if (!output) {
        output = vx_data_textblock::e_textblock;
      }
      return output;
    }

    // children()
    vx_data_textblock::Type_textblocklist Class_textblock::children() const {
      vx_data_textblock::Type_textblocklist output = this->vx_p_children;
      if (!output) {
        output = vx_data_textblock::e_textblocklist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_textblock::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":text") {
        output = this->text();
      } else if (skey == ":startpos") {
        output = this->startpos();
      } else if (skey == ":endpos") {
        output = this->endpos();
      } else if (skey == ":curpos") {
        output = this->curpos();
      } else if (skey == ":line") {
        output = this->line();
      } else if (skey == ":column") {
        output = this->column();
      } else if (skey == ":delim") {
        output = this->delim();
      } else if (skey == ":close") {
        output = this->close();
      } else if (skey == ":parent") {
        output = this->parent();
      } else if (skey == ":children") {
        output = this->children();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_textblock::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":text"] = this->text();
      output[":startpos"] = this->startpos();
      output[":endpos"] = this->endpos();
      output[":curpos"] = this->curpos();
      output[":line"] = this->line();
      output[":column"] = this->column();
      output[":delim"] = this->delim();
      output[":close"] = this->close();
      output[":parent"] = this->parent();
      output[":children"] = this->children();
      return output;
    }

    vx_core::Type_any Class_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_textblock, vals);
    }

    vx_core::Type_any Class_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_textblock::Type_textblock val = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_text = val->text();
      vx_core::Type_int vx_p_startpos = val->startpos();
      vx_core::Type_int vx_p_endpos = val->endpos();
      vx_core::Type_int vx_p_curpos = val->curpos();
      vx_core::Type_int vx_p_line = val->line();
      vx_core::Type_int vx_p_column = val->column();
      vx_data_textblock::Type_delim vx_p_delim = val->delim();
      vx_data_textblock::Type_delim vx_p_close = val->close();
      vx_data_textblock::Type_textblock vx_p_parent = val->parent();
      vx_data_textblock::Type_textblocklist vx_p_children = val->children();
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
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (testkey == ":startpos") {
            key = testkey;
          } else if (testkey == ":endpos") {
            key = testkey;
          } else if (testkey == ":curpos") {
            key = testkey;
          } else if (testkey == ":line") {
            key = testkey;
          } else if (testkey == ":column") {
            key = testkey;
          } else if (testkey == ":delim") {
            key = testkey;
          } else if (testkey == ":close") {
            key = testkey;
          } else if (testkey == ":parent") {
            key = testkey;
          } else if (testkey == ":children") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":startpos") {
            if (vx_p_startpos == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_startpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :startpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":endpos") {
            if (vx_p_endpos == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_endpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :endpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":curpos") {
            if (vx_p_curpos == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_curpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :curpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":line") {
            if (vx_p_line == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_line = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :line " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":column") {
            if (vx_p_column == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_column = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :column " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":delim") {
            if (vx_p_delim == valsub) {
            } else if (valsubtype == vx_data_textblock::t_delim) {
              ischanged = true;
              vx_p_delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :delim " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":close") {
            if (vx_p_close == valsub) {
            } else if (valsubtype == vx_data_textblock::t_delim) {
              ischanged = true;
              vx_p_close = vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :close " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":parent") {
            if (vx_p_parent == valsub) {
            } else if (valsubtype == vx_data_textblock::t_textblock) {
              ischanged = true;
              vx_p_parent = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :parent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":children") {
            if (vx_p_children == valsub) {
            } else if (valsubtype == vx_data_textblock::t_textblocklist) {
              ischanged = true;
              vx_p_children = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :children " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_textblock();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
        }
        if (output->vx_p_startpos != vx_p_startpos) {
          if (output->vx_p_startpos) {
            vx_core::vx_release_one(output->vx_p_startpos);
          }
          output->vx_p_startpos = vx_p_startpos;
          vx_core::vx_reserve(vx_p_startpos);
        }
        if (output->vx_p_endpos != vx_p_endpos) {
          if (output->vx_p_endpos) {
            vx_core::vx_release_one(output->vx_p_endpos);
          }
          output->vx_p_endpos = vx_p_endpos;
          vx_core::vx_reserve(vx_p_endpos);
        }
        if (output->vx_p_curpos != vx_p_curpos) {
          if (output->vx_p_curpos) {
            vx_core::vx_release_one(output->vx_p_curpos);
          }
          output->vx_p_curpos = vx_p_curpos;
          vx_core::vx_reserve(vx_p_curpos);
        }
        if (output->vx_p_line != vx_p_line) {
          if (output->vx_p_line) {
            vx_core::vx_release_one(output->vx_p_line);
          }
          output->vx_p_line = vx_p_line;
          vx_core::vx_reserve(vx_p_line);
        }
        if (output->vx_p_column != vx_p_column) {
          if (output->vx_p_column) {
            vx_core::vx_release_one(output->vx_p_column);
          }
          output->vx_p_column = vx_p_column;
          vx_core::vx_reserve(vx_p_column);
        }
        if (output->vx_p_delim != vx_p_delim) {
          if (output->vx_p_delim) {
            vx_core::vx_release_one(output->vx_p_delim);
          }
          output->vx_p_delim = vx_p_delim;
          vx_core::vx_reserve(vx_p_delim);
        }
        if (output->vx_p_close != vx_p_close) {
          if (output->vx_p_close) {
            vx_core::vx_release_one(output->vx_p_close);
          }
          output->vx_p_close = vx_p_close;
          vx_core::vx_reserve(vx_p_close);
        }
        if (output->vx_p_parent != vx_p_parent) {
          if (output->vx_p_parent) {
            vx_core::vx_release_one(output->vx_p_parent);
          }
          output->vx_p_parent = vx_p_parent;
          vx_core::vx_reserve(vx_p_parent);
        }
        if (output->vx_p_children != vx_p_children) {
          if (output->vx_p_children) {
            vx_core::vx_release_one(output->vx_p_children);
          }
          output->vx_p_children = vx_p_children;
          vx_core::vx_reserve(vx_p_children);
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_textblock::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_textblock::vx_empty() const {return vx_data_textblock::e_textblock;}
    vx_core::Type_any Class_textblock::vx_type() const {return vx_data_textblock::t_textblock;}

    vx_core::Type_typedef Class_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "curpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "line", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "column", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delim", // name
            vx_data_textblock::t_delim // type
          ),
          vx_core::vx_new_arg(
            "close", // name
            vx_data_textblock::t_delim // type
          ),
          vx_core::vx_new_arg(
            "parent", // name
            vx_data_textblock::t_textblock // type
          ),
          vx_core::vx_new_arg(
            "children", // name
            vx_data_textblock::t_textblocklist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_textblock::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type textblocklist)
  // class Class_textblocklist {
    Abstract_textblocklist::~Abstract_textblocklist() {}

    Class_textblocklist::Class_textblocklist() : Abstract_textblocklist::Abstract_textblocklist() {
      vx_core::refcount += 1;
    }

    Class_textblocklist::~Class_textblocklist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_textblocklist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_textblock::Type_textblock Class_textblocklist::vx_get_textblock(vx_core::Type_int index) const {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
      long iindex = index->vx_int();
      std::vector<vx_data_textblock::Type_textblock> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_textblock::Type_textblock> Class_textblocklist::vx_listtextblock() const {return vx_p_list;}

    vx_core::Type_any vx_data_textblock::Class_textblocklist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_textblock(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_textblocklist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_textblock::Type_textblock> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_textblock::t_textblock) {
          vx_data_textblock::Type_textblock castval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_textblock::t_textblock)) {
          vx_data_textblock::Type_textblock castval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(textblocklist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_textblocklist();
        output->vx_p_list = list;
        for (vx_core::Type_any valadd : list) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_textblocklist, vals);
    }

    vx_core::Type_any Class_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_textblock::Type_textblocklist val = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_textblock::Type_textblock> listval = val->vx_listtextblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_textblock) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_textblock::t_textblock)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (valsubtype == vx_data_textblock::t_textblocklist) {
          ischanged = true;
          vx_data_textblock::Type_textblocklist multi = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtextblock());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblocklist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_textblock::Class_textblocklist();
        output->vx_p_list = listval;
        for (vx_core::Type_any valadd : listval) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_textblock::Class_textblocklist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_textblocklist::vx_empty() const {return vx_data_textblock::e_textblocklist;}
    vx_core::Type_any Class_textblocklist::vx_type() const {return vx_data_textblock::t_textblocklist;}

    vx_core::Type_typedef Class_textblocklist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_textblock::t_textblock}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_textblocklist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const delimbracketangle)
  // class Class_delimbracketangle {
    // vx_const_new()
    void vx_data_textblock::Class_delimbracketangle::vx_const_new(vx_data_textblock::Const_delimbracketangle output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimbracketangle");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimbracketangle"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("<"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string(">")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimbracketcurly)
  // class Class_delimbracketcurly {
    // vx_const_new()
    void vx_data_textblock::Class_delimbracketcurly::vx_const_new(vx_data_textblock::Const_delimbracketcurly output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimbracketcurly");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimbracketcurly"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("{"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("}")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimbracketsquare)
  // class Class_delimbracketsquare {
    // vx_const_new()
    void vx_data_textblock::Class_delimbracketsquare::vx_const_new(vx_data_textblock::Const_delimbracketsquare output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimbracketsquare");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimbracketsquare"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("["),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("]")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimclose)
  // class Class_delimclose {
    // vx_const_new()
    void vx_data_textblock::Class_delimclose::vx_const_new(vx_data_textblock::Const_delimclose output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimclose");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimclose")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimclosing)
  // class Class_delimclosing {
    // vx_const_new()
    void vx_data_textblock::Class_delimclosing::vx_const_new(vx_data_textblock::Const_delimclosing output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimclosing");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimclosing")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimcomma)
  // class Class_delimcomma {
    // vx_const_new()
    void vx_data_textblock::Class_delimcomma::vx_const_new(vx_data_textblock::Const_delimcomma output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimcomma");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimcomma"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(",")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimcomment)
  // class Class_delimcomment {
    // vx_const_new()
    void vx_data_textblock::Class_delimcomment::vx_const_new(vx_data_textblock::Const_delimcomment output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimcomment");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimcomment"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("//"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("\n")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimcommentblock)
  // class Class_delimcommentblock {
    // vx_const_new()
    void vx_data_textblock::Class_delimcommentblock::vx_const_new(vx_data_textblock::Const_delimcommentblock output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimcommentblock");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimcommentblock"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("/*"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("*/")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimline)
  // class Class_delimline {
    // vx_const_new()
    void vx_data_textblock::Class_delimline::vx_const_new(vx_data_textblock::Const_delimline output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimline");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimline"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("\n")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimlisttest1)
  // class Class_delimlisttest1 {
    // vx_const_new()
    void vx_data_textblock::Class_delimlisttest1::vx_const_new(vx_data_textblock::Const_delimlisttest1 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimlisttest1");
      vx_data_textblock::Type_delimlist val = vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_data_textblock::c_delimtest2
        })
      );
      output->vx_p_list = val->vx_listdelim();
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimlisttest2)
  // class Class_delimlisttest2 {
    // vx_const_new()
    void vx_data_textblock::Class_delimlisttest2::vx_const_new(vx_data_textblock::Const_delimlisttest2 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimlisttest2");
      vx_data_textblock::Type_delimlist val = vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_data_textblock::c_delimcomma,
          vx_data_textblock::c_delimtest3
        })
      );
      output->vx_p_list = val->vx_listdelim();
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimlisttest3)
  // class Class_delimlisttest3 {
    // vx_const_new()
    void vx_data_textblock::Class_delimlisttest3::vx_const_new(vx_data_textblock::Const_delimlisttest3 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimlisttest3");
      vx_data_textblock::Type_delimlist val = vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_data_textblock::c_delimcomma,
          vx_data_textblock::c_delimwhitespace
        })
      );
      output->vx_p_list = val->vx_listdelim();
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimnonwhitespace)
  // class Class_delimnonwhitespace {
    // vx_const_new()
    void vx_data_textblock::Class_delimnonwhitespace::vx_const_new(vx_data_textblock::Const_delimnonwhitespace output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimnonwhitespace");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimnonwhitespace"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(":nonwhitespace"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string(":whitespace")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimparen)
  // class Class_delimparen {
    // vx_const_new()
    void vx_data_textblock::Class_delimparen::vx_const_new(vx_data_textblock::Const_delimparen output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimparen");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimparen"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("("),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string(")")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimquote)
  // class Class_delimquote {
    // vx_const_new()
    void vx_data_textblock::Class_delimquote::vx_const_new(vx_data_textblock::Const_delimquote output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimquote");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimquote"),
          vx_core::vx_new_string(":starttext"),
          vx_core::c_quote,
          vx_core::vx_new_string(":endtext"),
          vx_core::c_quote
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimquoteblock)
  // class Class_delimquoteblock {
    // vx_const_new()
    void vx_data_textblock::Class_delimquoteblock::vx_const_new(vx_data_textblock::Const_delimquoteblock output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimquoteblock");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimquoteblock"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("`"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("`")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimspace)
  // class Class_delimspace {
    // vx_const_new()
    void vx_data_textblock::Class_delimspace::vx_const_new(vx_data_textblock::Const_delimspace output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimspace");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimspace"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(" "),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string(" ")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimtest1)
  // class Class_delimtest1 {
    // vx_const_new()
    void vx_data_textblock::Class_delimtest1::vx_const_new(vx_data_textblock::Const_delimtest1 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimtest1");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delimlist"),
          vx_data_textblock::c_delimlisttest1
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimtest2)
  // class Class_delimtest2 {
    // vx_const_new()
    void vx_data_textblock::Class_delimtest2::vx_const_new(vx_data_textblock::Const_delimtest2 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimtest2");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimbracketangle,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delimlist"),
          vx_data_textblock::c_delimlisttest2
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimtest3)
  // class Class_delimtest3 {
    // vx_const_new()
    void vx_data_textblock::Class_delimtest3::vx_const_new(vx_data_textblock::Const_delimtest3 output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimtest3");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimbracketcurly,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delimlist"),
          vx_data_textblock::c_delimlisttest3
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimtext)
  // class Class_delimtext {
    // vx_const_new()
    void vx_data_textblock::Class_delimtext::vx_const_new(vx_data_textblock::Const_delimtext output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimtext");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimtext")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimwhitespace)
  // class Class_delimwhitespace {
    // vx_const_new()
    void vx_data_textblock::Class_delimwhitespace::vx_const_new(vx_data_textblock::Const_delimwhitespace output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/textblock", "delimwhitespace");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimwhitespace"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(":whitespace")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func children<-textblock)
  vx_data_textblock::Type_textblocklist f_children_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist;
    vx_core::vx_reserve(textblock);
    output = textblock->children();
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func children<-textblock)
  // class Class_children_from_textblock {
    Abstract_children_from_textblock::~Abstract_children_from_textblock() {}

    Class_children_from_textblock::Class_children_from_textblock() : Abstract_children_from_textblock::Abstract_children_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_children_from_textblock::~Class_children_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_children_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_children_from_textblock output = vx_data_textblock::e_children_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_children_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_children_from_textblock output = vx_data_textblock::e_children_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_children_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_children_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_children_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_children_from_textblock::vx_empty() const {return vx_data_textblock::e_children_from_textblock;}
    vx_core::Type_any Class_children_from_textblock::vx_type() const {return vx_data_textblock::t_children_from_textblock;}
    vx_core::Type_msgblock Class_children_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_children_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_children_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_children_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_children_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_children_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_children_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delim-first<-delim-delim)
  vx_data_textblock::Type_delim f_delim_first_from_delim_delim(vx_data_textblock::Type_delim delim1, vx_data_textblock::Type_delim delim2) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve({delim1, delim2});
    output = vx_core::f_let(
      vx_data_textblock::t_delim,
      vx_core::t_any_from_func->vx_fn_new({delim1, delim2}, [delim1, delim2]() {
        vx_core::Type_int pos1 = delim1->pos();
        vx_core::vx_ref_plus(pos1);
        vx_core::Type_int pos2 = delim2->pos();
        vx_core::vx_ref_plus(pos2);
        vx_data_textblock::Type_delim output_1 = vx_core::f_if_2(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos2}, [pos2]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_int(0), pos2);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim1}, [delim1]() {
                vx_core::Type_any output_1 = delim1;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos1}, [pos1]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_int(0), pos1);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim2}, [delim2]() {
                vx_core::Type_any output_1 = delim2;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delim2}, [delim2]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delim2);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim1}, [delim1]() {
                vx_core::Type_any output_1 = delim1;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delim1}, [delim1]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delim1);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim2}, [delim2]() {
                vx_core::Type_any output_1 = delim2;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos2, pos1}, [pos2, pos1]() {
                vx_core::Type_boolean output_1 = vx_core::f_lt(pos2, pos1);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim2}, [delim2]() {
                vx_core::Type_any output_1 = delim2;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delim1}, [delim1]() {
                vx_core::Type_any output_1 = delim1;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({pos1, pos2}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({delim1, delim2}, output);
    return output;
  }

  // (func delim-first<-delim-delim)
  // class Class_delim_first_from_delim_delim {
    Abstract_delim_first_from_delim_delim::~Abstract_delim_first_from_delim_delim() {}

    Class_delim_first_from_delim_delim::Class_delim_first_from_delim_delim() : Abstract_delim_first_from_delim_delim::Abstract_delim_first_from_delim_delim() {
      vx_core::refcount += 1;
    }

    Class_delim_first_from_delim_delim::~Class_delim_first_from_delim_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_first_from_delim_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_delim_delim output = vx_data_textblock::e_delim_first_from_delim_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_first_from_delim_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_delim_delim output = vx_data_textblock::e_delim_first_from_delim_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_first_from_delim_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-delim-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_delim_first_from_delim_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_delim_first_from_delim_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-delim-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_first_from_delim_delim::vx_empty() const {return vx_data_textblock::e_delim_first_from_delim_delim;}
    vx_core::Type_any Class_delim_first_from_delim_delim::vx_type() const {return vx_data_textblock::t_delim_first_from_delim_delim;}
    vx_core::Type_msgblock Class_delim_first_from_delim_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_first_from_delim_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delim_first_from_delim_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim delim1 = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim2 = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_delim_first_from_delim_delim(delim1, delim2);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delim-first<-string-delimlist)
  vx_data_textblock::Type_delim f_delim_first_from_string_delimlist(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve({text, delimlist});
    output = vx_core::f_if_2(
      vx_data_textblock::t_delim,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({delimlist}, [delimlist]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delimlist);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_any output_1 = vx_core::f_empty(
              vx_data_textblock::t_delim
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({text, delimlist}, [text, delimlist]() {
            vx_data_textblock::Type_delim output_1 = vx_core::f_let(
              vx_data_textblock::t_delim,
              vx_core::t_any_from_func->vx_fn_new({text, delimlist}, [text, delimlist]() {
                vx_data_textblock::Type_delimlist resolvedlist = vx_data_textblock::f_delimlist_pos_from_string_delimlist(text, delimlist);
                vx_core::vx_ref_plus(resolvedlist);
                vx_data_textblock::Type_delim output_1 = vx_core::f_any_from_list_reduce(
                  vx_data_textblock::t_delim,
                  resolvedlist,
                  vx_core::f_empty(
                    vx_data_textblock::t_delim
                  ),
                  vx_core::t_any_from_reduce->vx_fn_new({}, [](vx_core::Type_any delim1_any, vx_core::Type_any delim2_any) {
                    vx_data_textblock::Type_delim delim1 = vx_core::vx_any_from_any(vx_data_textblock::t_delim, delim1_any);
                    vx_data_textblock::Type_delim delim2 = vx_core::vx_any_from_any(vx_data_textblock::t_delim, delim2_any);
                    vx_core::Type_any output_1 = vx_data_textblock::f_delim_first_from_delim_delim(delim1, delim2);
                    return output_1;
                  })
                );
                vx_core::vx_release_one_except(resolvedlist, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({text, delimlist}, output);
    return output;
  }

  // (func delim-first<-string-delimlist)
  // class Class_delim_first_from_string_delimlist {
    Abstract_delim_first_from_string_delimlist::~Abstract_delim_first_from_string_delimlist() {}

    Class_delim_first_from_string_delimlist::Class_delim_first_from_string_delimlist() : Abstract_delim_first_from_string_delimlist::Abstract_delim_first_from_string_delimlist() {
      vx_core::refcount += 1;
    }

    Class_delim_first_from_string_delimlist::~Class_delim_first_from_string_delimlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_string_delimlist output = vx_data_textblock::e_delim_first_from_string_delimlist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_string_delimlist output = vx_data_textblock::e_delim_first_from_string_delimlist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_first_from_string_delimlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_delim_first_from_string_delimlist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_delim_first_from_string_delimlist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist::vx_empty() const {return vx_data_textblock::e_delim_first_from_string_delimlist;}
    vx_core::Type_any Class_delim_first_from_string_delimlist::vx_type() const {return vx_data_textblock::t_delim_first_from_string_delimlist;}
    vx_core::Type_msgblock Class_delim_first_from_string_delimlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_first_from_string_delimlist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delim_first_from_string_delimlist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delimlist delimlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_delim_first_from_string_delimlist(text, delimlist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delim-pos<-string-delim)
  vx_data_textblock::Type_delim f_delim_pos_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve({text, delim});
    output = vx_core::f_let(
      vx_data_textblock::t_delim,
      vx_core::t_any_from_func->vx_fn_new({delim, text}, [delim, text]() {
        vx_core::Type_string find = delim->starttext();
        vx_core::vx_ref_plus(find);
        vx_core::Type_int pos = vx_type::f_int_from_string_findkeyword(text, find);
        vx_core::vx_ref_plus(pos);
        vx_data_textblock::Type_delim output_1 = vx_core::f_if_1(
          vx_data_textblock::t_delim,
          vx_core::f_eq(pos, vx_core::vx_new_int(0)),
          delim,
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              pos
            })
          )
        );
        vx_core::vx_release_one_except({find, pos}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delim}, output);
    return output;
  }

  // (func delim-pos<-string-delim)
  // class Class_delim_pos_from_string_delim {
    Abstract_delim_pos_from_string_delim::~Abstract_delim_pos_from_string_delim() {}

    Class_delim_pos_from_string_delim::Class_delim_pos_from_string_delim() : Abstract_delim_pos_from_string_delim::Abstract_delim_pos_from_string_delim() {
      vx_core::refcount += 1;
    }

    Class_delim_pos_from_string_delim::~Class_delim_pos_from_string_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_pos_from_string_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_pos_from_string_delim output = vx_data_textblock::e_delim_pos_from_string_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_pos_from_string_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_pos_from_string_delim output = vx_data_textblock::e_delim_pos_from_string_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_pos_from_string_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_delim_pos_from_string_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_delim_pos_from_string_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_pos_from_string_delim::vx_empty() const {return vx_data_textblock::e_delim_pos_from_string_delim;}
    vx_core::Type_any Class_delim_pos_from_string_delim::vx_type() const {return vx_data_textblock::t_delim_pos_from_string_delim;}
    vx_core::Type_msgblock Class_delim_pos_from_string_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_pos_from_string_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delim_pos_from_string_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_delim_pos_from_string_delim(text, delim);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delimlist-pos<-string-delimlist)
  vx_data_textblock::Type_delimlist f_delimlist_pos_from_string_delimlist(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist) {
    vx_data_textblock::Type_delimlist output = vx_data_textblock::e_delimlist;
    vx_core::vx_reserve({text, delimlist});
    output = vx_core::f_list_from_list(
      vx_data_textblock::t_delimlist,
      delimlist,
      vx_core::t_any_from_any->vx_fn_new({text}, [text](vx_core::Type_any delim_any) {
        vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, delim_any);
        vx_core::Type_any output_1 = 
          vx_data_textblock::f_delim_pos_from_string_delim(text, delim);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delimlist}, output);
    return output;
  }

  // (func delimlist-pos<-string-delimlist)
  // class Class_delimlist_pos_from_string_delimlist {
    Abstract_delimlist_pos_from_string_delimlist::~Abstract_delimlist_pos_from_string_delimlist() {}

    Class_delimlist_pos_from_string_delimlist::Class_delimlist_pos_from_string_delimlist() : Abstract_delimlist_pos_from_string_delimlist::Abstract_delimlist_pos_from_string_delimlist() {
      vx_core::refcount += 1;
    }

    Class_delimlist_pos_from_string_delimlist::~Class_delimlist_pos_from_string_delimlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delimlist_pos_from_string_delimlist output = vx_data_textblock::e_delimlist_pos_from_string_delimlist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delimlist_pos_from_string_delimlist output = vx_data_textblock::e_delimlist_pos_from_string_delimlist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delimlist_pos_from_string_delimlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_delimlist_pos_from_string_delimlist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_delimlist_pos_from_string_delimlist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist::vx_empty() const {return vx_data_textblock::e_delimlist_pos_from_string_delimlist;}
    vx_core::Type_any Class_delimlist_pos_from_string_delimlist::vx_type() const {return vx_data_textblock::t_delimlist_pos_from_string_delimlist;}
    vx_core::Type_msgblock Class_delimlist_pos_from_string_delimlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delimlist_pos_from_string_delimlist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delimlist delimlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_delimlist_pos_from_string_delimlist(text, delimlist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-close)
  vx_core::Type_boolean f_is_close(vx_data_textblock::Type_delim delimarg) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(delimarg);
    output = vx_core::f_eq(
      delimarg->name(),
      vx_core::f_any_from_struct(
        vx_core::t_string,
        vx_data_textblock::c_delimclose,
        vx_core::vx_new_string(":name")
      )
    );
    vx_core::vx_release_one_except(delimarg, output);
    return output;
  }

  // (func is-close)
  // class Class_is_close {
    Abstract_is_close::~Abstract_is_close() {}

    Class_is_close::Class_is_close() : Abstract_is_close::Abstract_is_close() {
      vx_core::refcount += 1;
    }

    Class_is_close::~Class_is_close() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_close::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_is_close output = vx_data_textblock::e_is_close;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_close::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_is_close output = vx_data_textblock::e_is_close;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_close::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "is-close", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_is_close::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_is_close::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "is-close", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_close::vx_empty() const {return vx_data_textblock::e_is_close;}
    vx_core::Type_any Class_is_close::vx_type() const {return vx_data_textblock::t_is_close;}
    vx_core::Type_msgblock Class_is_close::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_close::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_close::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_close::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim inputval = vx_core::vx_any_from_any(vx_data_textblock::t_delim, val);
      output = vx_data_textblock::f_is_close(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_close::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim delimarg = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_is_close(delimarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-single)
  vx_core::Type_boolean f_is_single(vx_data_textblock::Type_delim delimarg) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(delimarg);
    output = vx_core::f_and(
      vx_core::f_ne(
        vx_core::vx_new_string(""),
        delimarg->starttext()
      ),
      vx_core::f_eq(
        vx_core::vx_new_string(""),
        delimarg->endtext()
      )
    );
    vx_core::vx_release_one_except(delimarg, output);
    return output;
  }

  // (func is-single)
  // class Class_is_single {
    Abstract_is_single::~Abstract_is_single() {}

    Class_is_single::Class_is_single() : Abstract_is_single::Abstract_is_single() {
      vx_core::refcount += 1;
    }

    Class_is_single::~Class_is_single() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_single::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_is_single output = vx_data_textblock::e_is_single;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_single::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_is_single output = vx_data_textblock::e_is_single;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_single::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "is-single", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_is_single::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_is_single::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "is-single", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_single::vx_empty() const {return vx_data_textblock::e_is_single;}
    vx_core::Type_any Class_is_single::vx_type() const {return vx_data_textblock::t_is_single;}
    vx_core::Type_msgblock Class_is_single::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_single::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_single::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_single::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim inputval = vx_core::vx_any_from_any(vx_data_textblock::t_delim, val);
      output = vx_data_textblock::f_is_single(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_single::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim delimarg = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_is_single(delimarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocklist) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    vx_core::vx_reserve(textblocklist);
    output = vx_core::f_list_from_list(
      vx_core::t_stringlist,
      textblocklist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any block_any) {
        vx_data_textblock::Type_textblock block = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, block_any);
        vx_core::Type_any output_1 = vx_data_textblock::f_text_from_textblock(block);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblocklist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::e_stringlist_from_textblocklist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_stringlist_from_textblocklist output = vx_data_textblock::e_stringlist_from_textblocklist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stringlist_from_textblocklist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_stringlist_from_textblocklist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stringlist_from_textblocklist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_empty() const {return vx_data_textblock::e_stringlist_from_textblocklist;}
    vx_core::Type_any Class_stringlist_from_textblocklist::vx_type() const {return vx_data_textblock::t_stringlist_from_textblocklist;}
    vx_core::Type_msgblock Class_stringlist_from_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stringlist_from_textblocklist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stringlist_from_textblocklist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, val);
      output = vx_data_textblock::f_stringlist_from_textblocklist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stringlist_from_textblocklist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist textblocklist = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_stringlist_from_textblocklist(textblocklist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func text<-textblock)
  vx_core::Type_string f_text_from_textblock(vx_data_textblock::Type_textblock block) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(block);
    output = block->text();
    vx_core::vx_release_one_except(block, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_text_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::e_text_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_text_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_text_from_textblock output = vx_data_textblock::e_text_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_text_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_text_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_text_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_text_from_textblock::vx_empty() const {return vx_data_textblock::e_text_from_textblock;}
    vx_core::Type_any Class_text_from_textblock::vx_type() const {return vx_data_textblock::t_text_from_textblock;}
    vx_core::Type_msgblock Class_text_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_text_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_text_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_text_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_text_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_text_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock block = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_text_from_textblock(block);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-addchild<-textblock-find-child)
  vx_data_textblock::Type_textblock f_textblock_addchild_from_textblock_find_child(vx_data_textblock::Type_textblock textblockarg, vx_data_textblock::Type_textblock find, vx_data_textblock::Type_textblock child) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockarg, find, child});
    output = vx_core::f_if_2(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(textblockarg);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_any output_1 = vx_core::f_empty(
              vx_data_textblock::t_textblock
            );
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({find, textblockarg}, [find, textblockarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_and_1(
              vx_core::vx_new(vx_core::t_booleanlist, {
                vx_core::f_eqeq(find, textblockarg)
              })
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({textblockarg, child}, [textblockarg, child]() {
            vx_core::Type_any output_1 = vx_core::f_copy(
              vx_data_textblock::t_textblock,
              textblockarg,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":children"),
                vx_core::f_copy(
                  vx_data_textblock::t_textblocklist,
                  textblockarg->children(),
                  vx_core::vx_new(vx_core::t_anylist, {
                    child
                  })
                )
              })
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({textblockarg, find, child}, [textblockarg, find, child]() {
            vx_core::Type_any output_1 = vx_core::f_copy(
              vx_data_textblock::t_textblock,
              textblockarg,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":parent"),
                vx_data_textblock::f_textblock_addchild_from_textblock_find_child(
                  textblockarg->parent(),
                  find,
                  child
                )
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({textblockarg, find, child}, output);
    return output;
  }

  // (func textblock-addchild<-textblock-find-child)
  // class Class_textblock_addchild_from_textblock_find_child {
    Abstract_textblock_addchild_from_textblock_find_child::~Abstract_textblock_addchild_from_textblock_find_child() {}

    Class_textblock_addchild_from_textblock_find_child::Class_textblock_addchild_from_textblock_find_child() : Abstract_textblock_addchild_from_textblock_find_child::Abstract_textblock_addchild_from_textblock_find_child() {
      vx_core::refcount += 1;
    }

    Class_textblock_addchild_from_textblock_find_child::~Class_textblock_addchild_from_textblock_find_child() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_find_child::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_addchild_from_textblock_find_child output = vx_data_textblock::e_textblock_addchild_from_textblock_find_child;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_find_child::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_addchild_from_textblock_find_child output = vx_data_textblock::e_textblock_addchild_from_textblock_find_child;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_addchild_from_textblock_find_child::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-find-child", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_addchild_from_textblock_find_child::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_addchild_from_textblock_find_child::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-find-child", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_find_child::vx_empty() const {return vx_data_textblock::e_textblock_addchild_from_textblock_find_child;}
    vx_core::Type_any Class_textblock_addchild_from_textblock_find_child::vx_type() const {return vx_data_textblock::t_textblock_addchild_from_textblock_find_child;}
    vx_core::Type_msgblock Class_textblock_addchild_from_textblock_find_child::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_addchild_from_textblock_find_child::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_addchild_from_textblock_find_child::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock find = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_data_textblock::Type_textblock child = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-delimnotfound)
  vx_data_textblock::Type_textblock f_textblock_delimnotfound(vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockarg);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_data_textblock::Type_delim delima = textblockarg->delim();
        vx_core::vx_ref_plus(delima);
        vx_data_textblock::Type_delim close = textblockarg->close();
        vx_core::vx_ref_plus(close);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_data_textblock::Type_delim delimp = parent->delim();
        vx_core::vx_ref_plus(delimp);
        vx_data_textblock::Type_delimlist delims = delimp->delimlist();
        vx_core::vx_ref_plus(delims);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({close}, [close]() {
                vx_core::Type_boolean output_1 = vx_core::f_not(
                  vx_core::f_is_empty_1(close)
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({parent, delims, textblockarg, delima}, [parent, delims, textblockarg, delima]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  parent,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delimlist,
                      delims,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_copy(
                          vx_data_textblock::t_textblock,
                          textblockarg,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":parent"),
                            vx_core::f_empty(
                              vx_data_textblock::t_textblock
                            ),
                            vx_core::vx_new_string(":msg"),
                            vx_core::f_msg_from_error(
                              vx_core::f_new(
                                vx_core::t_string,
                                vx_core::vx_new(vx_core::t_anylist, {
                                  vx_core::vx_new_string("Close delim not found: "),
                                  delima->name()
                                })
                              )
                            )
                          })
                        )
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({parent}, [parent]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(parent);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_core::Type_any output_1 = textblockarg;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delima, text, textblockarg, parent}, [delima, text, textblockarg, parent]() {
                vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
                  vx_data_textblock::t_textblock,
                  vx_core::t_any_from_func->vx_fn_new({delima, text, textblockarg, parent}, [delima, text, textblockarg, parent]() {
                    vx_data_textblock::Type_delim delimchg = vx_core::f_if_1(
                      vx_data_textblock::t_delim,
                      vx_core::f_is_empty_1(
                        delima->delimlist()
                      ),
                      delima,
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        delima,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_core::f_empty(
                            vx_data_textblock::t_delimlist
                          )
                        })
                      )
                    );
                    vx_core::vx_ref_plus(delimchg);
                    vx_data_textblock::Type_textblock child = vx_core::f_if_1(
                      vx_data_textblock::t_textblock,
                      vx_core::f_eq(vx_core::vx_new_string(""), text),
                      vx_core::f_empty(
                        vx_data_textblock::t_textblock
                      ),
                      vx_core::f_copy(
                        vx_data_textblock::t_textblock,
                        textblockarg,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delim"),
                          delimchg,
                          vx_core::vx_new_string(":parent"),
                          vx_core::f_empty(
                            vx_data_textblock::t_textblock
                          )
                        })
                      )
                    );
                    vx_core::vx_ref_plus(child);
                    vx_data_textblock::Type_textblock find = vx_data_textblock::f_textblock_findparent_from_textblock(parent);
                    vx_core::vx_ref_plus(find);
                    vx_data_textblock::Type_delim closef = find->close();
                    vx_core::vx_ref_plus(closef);
                    vx_core::Type_boolean closing = vx_core::f_if(
                      vx_core::t_boolean,
                      vx_core::f_eqeq(
                        closef,
                        vx_data_textblock::c_delimclosing
                      ),
                      vx_core::vx_new_boolean(true)
                    );
                    vx_core::vx_ref_plus(closing);
                    vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_thenelselist, {
                        vx_core::f_then(
                          vx_core::t_boolean_from_func->vx_fn_new({closing}, [closing]() {
                            vx_core::Type_boolean output_1 = closing;
                            return output_1;
                          }),
                          vx_core::t_any_from_func->vx_fn_new({find, child, parent}, [find, child, parent]() {
                            vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
                              vx_data_textblock::t_textblock,
                              vx_core::t_any_from_func->vx_fn_new({find, child, parent}, [find, child, parent]() {
                                vx_data_textblock::Type_textblock parent2 = find->parent();
                                vx_core::vx_ref_plus(parent2);
                                vx_data_textblock::Type_textblock find2 = vx_data_textblock::f_textblock_findparent_from_textblock(parent2);
                                vx_core::vx_ref_plus(find2);
                                vx_data_textblock::Type_textblocklist children1 = vx_core::f_if_1(
                                  vx_data_textblock::t_textblocklist,
                                  vx_core::f_is_empty_1(child),
                                  find->children(),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_textblocklist,
                                    find->children(),
                                    vx_core::vx_new(vx_core::t_anylist, {
                                      child
                                    })
                                  )
                                );
                                vx_core::vx_ref_plus(children1);
                                vx_data_textblock::Type_textblock replace1 = vx_core::f_copy(
                                  vx_data_textblock::t_textblock,
                                  find,
                                  vx_core::vx_new(vx_core::t_anylist, {
                                    vx_core::vx_new_string(":close"),
                                    vx_core::f_empty(
                                      vx_data_textblock::t_delim
                                    ),
                                    vx_core::vx_new_string(":parent"),
                                    vx_core::f_empty(
                                      vx_data_textblock::t_textblock
                                    ),
                                    vx_core::vx_new_string(":children"),
                                    children1
                                  })
                                );
                                vx_core::vx_ref_plus(replace1);
                                vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
                                  vx_data_textblock::t_textblock,
                                  vx_core::vx_new(vx_core::t_thenelselist, {
                                    vx_core::f_then(
                                      vx_core::t_boolean_from_func->vx_fn_new({find2}, [find2]() {
                                        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(find2);
                                        return output_1;
                                      }),
                                      vx_core::t_any_from_func->vx_fn_new({parent, parent2, replace1}, [parent, parent2, replace1]() {
                                        vx_core::Type_any output_1 = vx_core::f_copy(
                                          vx_data_textblock::t_textblock,
                                          parent,
                                          vx_core::vx_new(vx_core::t_anylist, {
                                            vx_core::vx_new_string(":parent"),
                                            vx_core::f_copy(
                                              vx_data_textblock::t_textblock,
                                              parent2,
                                              vx_core::vx_new(vx_core::t_anylist, {
                                                vx_core::vx_new_string(":children"),
                                                vx_core::f_new(
                                                  vx_data_textblock::t_textblocklist,
                                                  vx_core::vx_new(vx_core::t_anylist, {
                                                    replace1
                                                  })
                                                )
                                              })
                                            )
                                          })
                                        );
                                        return output_1;
                                      })
                                    ),
                                    vx_core::f_else(
                                      vx_core::t_any_from_func->vx_fn_new({find2, replace1, parent2, parent, find}, [find2, replace1, parent2, parent, find]() {
                                        vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
                                          vx_data_textblock::t_textblock,
                                          vx_core::t_any_from_func->vx_fn_new({find2, replace1, parent2, parent, find}, [find2, replace1, parent2, parent, find]() {
                                            vx_data_textblock::Type_textblocklist children2 = vx_core::f_copy(
                                              vx_data_textblock::t_textblocklist,
                                              find2->children(),
                                              vx_core::vx_new(vx_core::t_anylist, {
                                                replace1
                                              })
                                            );
                                            vx_core::vx_ref_plus(children2);
                                            vx_data_textblock::Type_textblock replace2 = vx_core::f_copy(
                                              vx_data_textblock::t_textblock,
                                              find2,
                                              vx_core::vx_new(vx_core::t_anylist, {
                                                vx_core::vx_new_string(":close"),
                                                vx_core::f_empty(
                                                  vx_data_textblock::t_delim
                                                ),
                                                vx_core::vx_new_string(":children"),
                                                children2
                                              })
                                            );
                                            vx_core::vx_ref_plus(replace2);
                                            vx_data_textblock::Type_textblock replace = vx_data_textblock::f_textblock_replace_from_textblock_find_replace(parent2, find2, replace2);
                                            vx_core::vx_ref_plus(replace);
                                            vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_replace_from_textblock_find_replace(parent, find, replace);
                                            vx_core::vx_release_one_except({children2, replace2, replace}, output_1);
                                            return output_1;
                                          })
                                        );
                                        return output_1;
                                      })
                                    )
                                  })
                                );
                                vx_core::vx_release_one_except({parent2, find2, children1, replace1}, output_1);
                                return output_1;
                              })
                            );
                            return output_1;
                          })
                        ),
                        vx_core::f_then(
                          vx_core::t_boolean_from_func->vx_fn_new({child}, [child]() {
                            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(child);
                            return output_1;
                          }),
                          vx_core::t_any_from_func->vx_fn_new({parent}, [parent]() {
                            vx_core::Type_any output_1 = parent;
                            return output_1;
                          })
                        ),
                        vx_core::f_else(
                          vx_core::t_any_from_func->vx_fn_new({parent, find, child}, [parent, find, child]() {
                            vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_addchild_from_textblock_find_child(parent, find, child);
                            return output_1;
                          })
                        )
                      })
                    );
                    vx_core::vx_release_one_except({delimchg, child, find, closef, closing}, output_1);
                    return output_1;
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, delima, close, parent, delimp, delims}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockarg, output);
    return output;
  }

  // (func textblock-delimnotfound)
  // class Class_textblock_delimnotfound {
    Abstract_textblock_delimnotfound::~Abstract_textblock_delimnotfound() {}

    Class_textblock_delimnotfound::Class_textblock_delimnotfound() : Abstract_textblock_delimnotfound::Abstract_textblock_delimnotfound() {
      vx_core::refcount += 1;
    }

    Class_textblock_delimnotfound::~Class_textblock_delimnotfound() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_delimnotfound::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_delimnotfound output = vx_data_textblock::e_textblock_delimnotfound;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_delimnotfound::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_delimnotfound output = vx_data_textblock::e_textblock_delimnotfound;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_delimnotfound::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-delimnotfound", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_delimnotfound::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_delimnotfound::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-delimnotfound", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_delimnotfound::vx_empty() const {return vx_data_textblock::e_textblock_delimnotfound;}
    vx_core::Type_any Class_textblock_delimnotfound::vx_type() const {return vx_data_textblock::t_textblock_delimnotfound;}
    vx_core::Type_msgblock Class_textblock_delimnotfound::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_delimnotfound::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_delimnotfound::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_delimnotfound::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_delimnotfound(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_delimnotfound::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_delimnotfound(textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-findparent<-textblock)
  vx_data_textblock::Type_textblock f_textblock_findparent_from_textblock(vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockarg);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
        vx_data_textblock::Type_delim delimcurr = textblockarg->delim();
        vx_core::vx_ref_plus(delimcurr);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_data_textblock::Type_textblocklist children = textblockarg->children();
        vx_core::vx_ref_plus(children);
        vx_core::Type_string starttext = delimcurr->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimcurr->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(textblockarg);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_textblock
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({parent, starttext, endtext}, [parent, starttext, endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_or(
                  vx_core::f_is_empty_1(parent),
                  vx_core::f_and(
                    vx_core::f_ne(vx_core::vx_new_string(""), starttext),
                    vx_core::f_ne(vx_core::vx_new_string(""), endtext)
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_core::Type_any output_1 = textblockarg;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({parent}, [parent]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_findparent_from_textblock(parent);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimcurr, parent, children, starttext, endtext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockarg, output);
    return output;
  }

  // (func textblock-findparent<-textblock)
  // class Class_textblock_findparent_from_textblock {
    Abstract_textblock_findparent_from_textblock::~Abstract_textblock_findparent_from_textblock() {}

    Class_textblock_findparent_from_textblock::Class_textblock_findparent_from_textblock() : Abstract_textblock_findparent_from_textblock::Abstract_textblock_findparent_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock_findparent_from_textblock::~Class_textblock_findparent_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_findparent_from_textblock output = vx_data_textblock::e_textblock_findparent_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_findparent_from_textblock output = vx_data_textblock::e_textblock_findparent_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_findparent_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-findparent<-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_findparent_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_findparent_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-findparent<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_empty() const {return vx_data_textblock::e_textblock_findparent_from_textblock;}
    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_type() const {return vx_data_textblock::t_textblock_findparent_from_textblock;}
    vx_core::Type_msgblock Class_textblock_findparent_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_findparent_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_findparent_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_findparent_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_findparent_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_findparent_from_textblock(textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-groupby<-textblock-delim)
  vx_data_textblock::Type_textblock f_textblock_groupby_from_textblock_delim(vx_data_textblock::Type_textblock textblockarg, vx_data_textblock::Type_delim delimarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockarg, delimarg});
    output = vx_core::f_new(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":delim"),
        delimarg
      })
    );
    vx_core::vx_release_one_except({textblockarg, delimarg}, output);
    return output;
  }

  // (func textblock-groupby<-textblock-delim)
  // class Class_textblock_groupby_from_textblock_delim {
    Abstract_textblock_groupby_from_textblock_delim::~Abstract_textblock_groupby_from_textblock_delim() {}

    Class_textblock_groupby_from_textblock_delim::Class_textblock_groupby_from_textblock_delim() : Abstract_textblock_groupby_from_textblock_delim::Abstract_textblock_groupby_from_textblock_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_groupby_from_textblock_delim::~Class_textblock_groupby_from_textblock_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_groupby_from_textblock_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_groupby_from_textblock_delim output = vx_data_textblock::e_textblock_groupby_from_textblock_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_groupby_from_textblock_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_groupby_from_textblock_delim output = vx_data_textblock::e_textblock_groupby_from_textblock_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_groupby_from_textblock_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-groupby<-textblock-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_groupby_from_textblock_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_groupby_from_textblock_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-groupby<-textblock-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_groupby_from_textblock_delim::vx_empty() const {return vx_data_textblock::e_textblock_groupby_from_textblock_delim;}
    vx_core::Type_any Class_textblock_groupby_from_textblock_delim::vx_type() const {return vx_data_textblock::t_textblock_groupby_from_textblock_delim;}
    vx_core::Type_msgblock Class_textblock_groupby_from_textblock_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_groupby_from_textblock_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_groupby_from_textblock_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delimarg = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_groupby_from_textblock_delim(textblockarg, delimarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-init)
  vx_data_textblock::Type_textblock f_textblock_init(vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockarg);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_int startpos = vx_core::f_if_1(
          vx_core::t_int,
          vx_core::f_eq(vx_core::vx_new_string(""), text),
          vx_core::vx_new_int(0),
          vx_core::vx_new_int(1)
        );
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int endpos = vx_core::f_if_1(
          vx_core::t_int,
          vx_core::f_eq(vx_core::vx_new_string(""), text),
          vx_core::vx_new_int(0),
          vx_type::f_length_from_string(text)
        );
        vx_core::vx_ref_plus(endpos);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          textblockarg,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            startpos,
            vx_core::vx_new_string(":endpos"),
            endpos,
            vx_core::vx_new_string(":parent"),
            vx_core::f_copy(
              vx_data_textblock::t_textblock,
              textblockarg,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                startpos,
                vx_core::vx_new_string(":endpos"),
                endpos,
                vx_core::vx_new_string(":delim"),
                vx_core::f_empty(
                  vx_data_textblock::t_delim
                )
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, startpos, endpos}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockarg, output);
    return output;
  }

  // (func textblock-init)
  // class Class_textblock_init {
    Abstract_textblock_init::~Abstract_textblock_init() {}

    Class_textblock_init::Class_textblock_init() : Abstract_textblock_init::Abstract_textblock_init() {
      vx_core::refcount += 1;
    }

    Class_textblock_init::~Class_textblock_init() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_init::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_init output = vx_data_textblock::e_textblock_init;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_init::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_init output = vx_data_textblock::e_textblock_init;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_init::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-init", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_init::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_init::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-init", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_init::vx_empty() const {return vx_data_textblock::e_textblock_init;}
    vx_core::Type_any Class_textblock_init::vx_type() const {return vx_data_textblock::t_textblock_init;}
    vx_core::Type_msgblock Class_textblock_init::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_init::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_init::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_init::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_init(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_init::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_init(textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-parse)
  vx_data_textblock::Type_textblock f_textblock_parse(vx_data_textblock::Type_textblock textblock) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblock);
    output = vx_collection::f_any_from_for_until_loop(
      vx_data_textblock::t_textblock,
      textblock,
      vx_core::t_boolean_from_any->vx_fn_new({}, [](vx_core::Type_any current_any) {
        vx_data_textblock::Type_textblock current = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, current_any);
        vx_core::Type_boolean output_1 = 
          vx_core::f_is_empty_1(
            current->parent()
          );
        return output_1;
      }),
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any current_any) {
        vx_data_textblock::Type_textblock current = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, current_any);
        vx_core::Type_any output_1 = 
          vx_data_textblock::f_textblock_parse_one(current);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func textblock-parse)
  // class Class_textblock_parse {
    Abstract_textblock_parse::~Abstract_textblock_parse() {}

    Class_textblock_parse::Class_textblock_parse() : Abstract_textblock_parse::Abstract_textblock_parse() {
      vx_core::refcount += 1;
    }

    Class_textblock_parse::~Class_textblock_parse() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_parse::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse output = vx_data_textblock::e_textblock_parse;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_parse::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse output = vx_data_textblock::e_textblock_parse;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_parse::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_parse::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_parse::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_parse::vx_empty() const {return vx_data_textblock::e_textblock_parse;}
    vx_core::Type_any Class_textblock_parse::vx_type() const {return vx_data_textblock::t_textblock_parse;}
    vx_core::Type_msgblock Class_textblock_parse::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_parse::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_parse::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_parse::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_parse(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_parse::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_parse(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-parse-one)
  vx_data_textblock::Type_textblock f_textblock_parse_one(vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockarg);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
        vx_data_textblock::Type_delim delimarg = textblockarg->delim();
        vx_core::vx_ref_plus(delimarg);
        vx_data_textblock::Type_delim close = textblockarg->close();
        vx_core::vx_ref_plus(close);
        vx_core::Type_int startpos = textblockarg->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_string textarg = textblockarg->text();
        vx_core::vx_ref_plus(textarg);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_boolean is_init = vx_core::f_and(
          vx_core::f_is_empty_1(parent),
          vx_core::f_eq(startpos, vx_core::vx_new_int(0))
        );
        vx_core::vx_ref_plus(is_init);
        vx_core::Type_string starttext = delimarg->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimarg->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_delimlist delimlistarg = delimarg->delimlist();
        vx_core::vx_ref_plus(delimlistarg);
        vx_core::Type_int startposchg = vx_core::f_if_2(
          vx_core::t_int,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({textarg}, [textarg]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(""), textarg);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({startpos}, [startpos]() {
                vx_core::Type_any output_1 = startpos;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({startpos}, [startpos]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_int(0), startpos);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(1);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({startpos}, [startpos]() {
                vx_core::Type_any output_1 = startpos;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(startposchg);
        vx_data_textblock::Type_delimlist delimlistcl = vx_core::f_if_1(
          vx_data_textblock::t_delimlist,
          vx_core::f_is_empty_1(close),
          delimlistarg,
          vx_core::f_copy(vx_data_textblock::t_delimlist, delimlistarg, vx_core::vx_new(vx_core::t_anylist, {
            close}))
        );
        vx_core::vx_ref_plus(delimlistcl);
        vx_data_textblock::Type_delim delimfirst = vx_data_textblock::f_delim_first_from_string_delimlist(textarg, delimlistcl);
        vx_core::vx_ref_plus(delimfirst);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({is_init}, [is_init]() {
                vx_core::Type_boolean output_1 = is_init;
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_init(textblockarg);
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({parent}, [parent]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(parent);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_core::Type_any output_1 = textblockarg;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimfirst}, [delimfirst]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delimfirst);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_delimnotfound(textblockarg);
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimfirst}, [delimfirst]() {
                vx_core::Type_boolean output_1 = vx_data_textblock::f_is_close(delimfirst);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delimfirst, textblockarg}, [delimfirst, textblockarg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_from_close_textblock(delimfirst, textblockarg);
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimfirst}, [delimfirst]() {
                vx_core::Type_boolean output_1 = vx_data_textblock::f_is_single(delimfirst);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delimfirst, textblockarg}, [delimfirst, textblockarg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_from_single_textblock(delimfirst, textblockarg);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delimfirst, textblockarg}, [delimfirst, textblockarg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_from_open_textblock(delimfirst, textblockarg);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimarg, close, startpos, textarg, parent, is_init, starttext, endtext, delimlistarg, startposchg, delimlistcl, delimfirst}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockarg, output);
    return output;
  }

  // (func textblock-parse-one)
  // class Class_textblock_parse_one {
    Abstract_textblock_parse_one::~Abstract_textblock_parse_one() {}

    Class_textblock_parse_one::Class_textblock_parse_one() : Abstract_textblock_parse_one::Abstract_textblock_parse_one() {
      vx_core::refcount += 1;
    }

    Class_textblock_parse_one::~Class_textblock_parse_one() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_parse_one::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse_one output = vx_data_textblock::e_textblock_parse_one;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_parse_one::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse_one output = vx_data_textblock::e_textblock_parse_one;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_parse_one::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse-one", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_parse_one::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_parse_one::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse-one", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_parse_one::vx_empty() const {return vx_data_textblock::e_textblock_parse_one;}
    vx_core::Type_any Class_textblock_parse_one::vx_type() const {return vx_data_textblock::t_textblock_parse_one;}
    vx_core::Type_msgblock Class_textblock_parse_one::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_parse_one::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_parse_one::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_parse_one::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_parse_one(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_parse_one::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_parse_one(textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-parse<-string-delim)
  vx_data_textblock::Type_textblock f_textblock_parse_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({text, delim});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({text, delim}, [text, delim]() {
        vx_data_textblock::Type_textblock textblockinit = vx_data_textblock::f_textblock_from_string_delim(text, delim);
        vx_core::vx_ref_plus(textblockinit);
        vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_parse(textblockinit);
        vx_core::vx_release_one_except(textblockinit, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delim}, output);
    return output;
  }

  // (func textblock-parse<-string-delim)
  // class Class_textblock_parse_from_string_delim {
    Abstract_textblock_parse_from_string_delim::~Abstract_textblock_parse_from_string_delim() {}

    Class_textblock_parse_from_string_delim::Class_textblock_parse_from_string_delim() : Abstract_textblock_parse_from_string_delim::Abstract_textblock_parse_from_string_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_parse_from_string_delim::~Class_textblock_parse_from_string_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_parse_from_string_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse_from_string_delim output = vx_data_textblock::e_textblock_parse_from_string_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_parse_from_string_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_parse_from_string_delim output = vx_data_textblock::e_textblock_parse_from_string_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_parse_from_string_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse<-string-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_parse_from_string_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_parse_from_string_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse<-string-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_parse_from_string_delim::vx_empty() const {return vx_data_textblock::e_textblock_parse_from_string_delim;}
    vx_core::Type_any Class_textblock_parse_from_string_delim::vx_type() const {return vx_data_textblock::t_textblock_parse_from_string_delim;}
    vx_core::Type_msgblock Class_textblock_parse_from_string_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_parse_from_string_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_parse_from_string_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_parse_from_string_delim(text, delim);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-replace<-textblock-find-replace)
  vx_data_textblock::Type_textblock f_textblock_replace_from_textblock_find_replace(vx_data_textblock::Type_textblock textblockarg, vx_data_textblock::Type_textblock find, vx_data_textblock::Type_textblock replace) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockarg, find, replace});
    output = vx_core::f_if_2(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(textblockarg);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_any output_1 = vx_core::f_empty(
              vx_data_textblock::t_textblock
            );
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({find, textblockarg}, [find, textblockarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_and_1(
              vx_core::vx_new(vx_core::t_booleanlist, {
                vx_core::f_eqeq(find, textblockarg)
              })
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({replace}, [replace]() {
            vx_core::Type_any output_1 = replace;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({textblockarg, find, replace}, [textblockarg, find, replace]() {
            vx_core::Type_any output_1 = vx_core::f_copy(
              vx_data_textblock::t_textblock,
              textblockarg,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":parent"),
                vx_data_textblock::f_textblock_replace_from_textblock_find_replace(
                  textblockarg->parent(),
                  find,
                  replace
                )
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({textblockarg, find, replace}, output);
    return output;
  }

  // (func textblock-replace<-textblock-find-replace)
  // class Class_textblock_replace_from_textblock_find_replace {
    Abstract_textblock_replace_from_textblock_find_replace::~Abstract_textblock_replace_from_textblock_find_replace() {}

    Class_textblock_replace_from_textblock_find_replace::Class_textblock_replace_from_textblock_find_replace() : Abstract_textblock_replace_from_textblock_find_replace::Abstract_textblock_replace_from_textblock_find_replace() {
      vx_core::refcount += 1;
    }

    Class_textblock_replace_from_textblock_find_replace::~Class_textblock_replace_from_textblock_find_replace() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_replace_from_textblock_find_replace::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_replace_from_textblock_find_replace output = vx_data_textblock::e_textblock_replace_from_textblock_find_replace;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_replace_from_textblock_find_replace::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_replace_from_textblock_find_replace output = vx_data_textblock::e_textblock_replace_from_textblock_find_replace;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_replace_from_textblock_find_replace::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-replace<-textblock-find-replace", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_replace_from_textblock_find_replace::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_replace_from_textblock_find_replace::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-replace<-textblock-find-replace", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_replace_from_textblock_find_replace::vx_empty() const {return vx_data_textblock::e_textblock_replace_from_textblock_find_replace;}
    vx_core::Type_any Class_textblock_replace_from_textblock_find_replace::vx_type() const {return vx_data_textblock::t_textblock_replace_from_textblock_find_replace;}
    vx_core::Type_msgblock Class_textblock_replace_from_textblock_find_replace::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_replace_from_textblock_find_replace::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_replace_from_textblock_find_replace::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock find = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_data_textblock::Type_textblock replace = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-startleft<-string-delim-offset)
  vx_data_textblock::Type_textblock f_textblock_startleft_from_string_delim_offset(vx_core::Type_string text, vx_data_textblock::Type_delim delim, vx_core::Type_int offset) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({text, delim, offset});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({delim, text, offset}, [delim, text, offset]() {
        vx_core::Type_int pos = delim->pos();
        vx_core::vx_ref_plus(pos);
        vx_core::Type_int start = vx_core::vx_new_int(1);
        vx_core::vx_ref_plus(start);
        vx_core::Type_int end = vx_core::f_minus(pos, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(end);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(""), text);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_textblock
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos}, [pos]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_int(0), pos);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_textblock
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({text, start, end, offset}, [text, start, end, offset]() {
                vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_type::f_string_from_string_start_end(text, start, end),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::f_plus(offset, start),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::f_plus(offset, end),
                    vx_core::vx_new_string(":curpos"),
                    vx_core::vx_new_int(0)
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({pos, start, end}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delim, offset}, output);
    return output;
  }

  // (func textblock-startleft<-string-delim-offset)
  // class Class_textblock_startleft_from_string_delim_offset {
    Abstract_textblock_startleft_from_string_delim_offset::~Abstract_textblock_startleft_from_string_delim_offset() {}

    Class_textblock_startleft_from_string_delim_offset::Class_textblock_startleft_from_string_delim_offset() : Abstract_textblock_startleft_from_string_delim_offset::Abstract_textblock_startleft_from_string_delim_offset() {
      vx_core::refcount += 1;
    }

    Class_textblock_startleft_from_string_delim_offset::~Class_textblock_startleft_from_string_delim_offset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_startleft_from_string_delim_offset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_startleft_from_string_delim_offset output = vx_data_textblock::e_textblock_startleft_from_string_delim_offset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_startleft_from_string_delim_offset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_startleft_from_string_delim_offset output = vx_data_textblock::e_textblock_startleft_from_string_delim_offset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_startleft_from_string_delim_offset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-startleft<-string-delim-offset", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_startleft_from_string_delim_offset::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_startleft_from_string_delim_offset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startleft<-string-delim-offset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_startleft_from_string_delim_offset::vx_empty() const {return vx_data_textblock::e_textblock_startleft_from_string_delim_offset;}
    vx_core::Type_any Class_textblock_startleft_from_string_delim_offset::vx_type() const {return vx_data_textblock::t_textblock_startleft_from_string_delim_offset;}
    vx_core::Type_msgblock Class_textblock_startleft_from_string_delim_offset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_startleft_from_string_delim_offset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_startleft_from_string_delim_offset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int offset = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_textblock_startleft_from_string_delim_offset(text, delim, offset);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-startright<-string-delim-offset)
  vx_data_textblock::Type_textblock f_textblock_startright_from_string_delim_offset(vx_core::Type_string text, vx_data_textblock::Type_delim delimin, vx_core::Type_int offset) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({text, delimin, offset});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({delimin, text, offset}, [delimin, text, offset]() {
        vx_core::Type_int startpos = delimin->pos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_string starttext = delimin->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimin->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_delimlist delimlist = delimin->delimlist();
        vx_core::vx_ref_plus(delimlist);
        vx_data_textblock::Type_delim close = vx_core::f_if_2(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({endtext}, [endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(endtext, vx_core::vx_new_string(""));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_delim
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({endtext}, [endtext]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    endtext
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(close);
        vx_core::Type_int delimlen = vx_core::f_switch(
          vx_core::t_int,
          starttext,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(":nonwhitespace"),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(0);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::vx_new_string(":whitespace"),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(0);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({starttext}, [starttext]() {
                vx_core::Type_int output_1 = vx_type::f_length_from_string(starttext);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(delimlen);
        vx_core::Type_int curpos = vx_core::vx_new_int(0);
        vx_core::vx_ref_plus(curpos);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(text, vx_core::vx_new_string(""));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_textblock
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({startpos}, [startpos]() {
                vx_core::Type_boolean output_1 = vx_core::f_lt(startpos, vx_core::vx_new_int(0));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_any output_1 = vx_core::f_empty(
                  vx_data_textblock::t_textblock
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({text, startpos, offset, curpos, delimin, close}, [text, startpos, offset, curpos, delimin, close]() {
                vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_type::f_string_from_string_start(text, startpos),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::f_plus(offset, startpos),
                    vx_core::vx_new_string(":curpos"),
                    curpos,
                    vx_core::vx_new_string(":delim"),
                    delimin,
                    vx_core::vx_new_string(":close"),
                    close
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({startpos, starttext, endtext, delimlist, close, delimlen, curpos}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delimin, offset}, output);
    return output;
  }

  // (func textblock-startright<-string-delim-offset)
  // class Class_textblock_startright_from_string_delim_offset {
    Abstract_textblock_startright_from_string_delim_offset::~Abstract_textblock_startright_from_string_delim_offset() {}

    Class_textblock_startright_from_string_delim_offset::Class_textblock_startright_from_string_delim_offset() : Abstract_textblock_startright_from_string_delim_offset::Abstract_textblock_startright_from_string_delim_offset() {
      vx_core::refcount += 1;
    }

    Class_textblock_startright_from_string_delim_offset::~Class_textblock_startright_from_string_delim_offset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_startright_from_string_delim_offset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_startright_from_string_delim_offset output = vx_data_textblock::e_textblock_startright_from_string_delim_offset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_startright_from_string_delim_offset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_startright_from_string_delim_offset output = vx_data_textblock::e_textblock_startright_from_string_delim_offset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_startright_from_string_delim_offset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-startright<-string-delim-offset", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_startright_from_string_delim_offset::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_startright_from_string_delim_offset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startright<-string-delim-offset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_startright_from_string_delim_offset::vx_empty() const {return vx_data_textblock::e_textblock_startright_from_string_delim_offset;}
    vx_core::Type_any Class_textblock_startright_from_string_delim_offset::vx_type() const {return vx_data_textblock::t_textblock_startright_from_string_delim_offset;}
    vx_core::Type_msgblock Class_textblock_startright_from_string_delim_offset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_startright_from_string_delim_offset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_startright_from_string_delim_offset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delimin = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int offset = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_textblock_startright_from_string_delim_offset(text, delimin, offset);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-close-textblock)
  vx_data_textblock::Type_textblock f_textblock_from_close_textblock(vx_data_textblock::Type_delim close, vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({close, textblockarg});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg, close}, [textblockarg, close]() {
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_int startpos = textblockarg->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int endpos = textblockarg->endpos();
        vx_core::vx_ref_plus(endpos);
        vx_core::Type_int pos = close->pos();
        vx_core::vx_ref_plus(pos);
        vx_core::Type_string textclose = close->starttext();
        vx_core::vx_ref_plus(textclose);
        vx_core::Type_int lenclose = vx_type::f_length_from_string(textclose);
        vx_core::vx_ref_plus(lenclose);
        vx_core::Type_int posminus = vx_core::f_minus1(pos);
        vx_core::vx_ref_plus(posminus);
        vx_core::Type_int startleft = startpos;
        vx_core::vx_ref_plus(startleft);
        vx_core::Type_int startclose = vx_core::f_plus(startpos, posminus);
        vx_core::vx_ref_plus(startclose);
        vx_core::Type_int endclose = vx_core::f_switch(
          vx_core::t_int,
          textclose,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(":whitespace"),
              vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                vx_core::Type_int output_1 = vx_type::f_int_from_string_findkeyword(text, vx_core::vx_new_string(":nonwhitespace"));
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({startclose, lenclose}, [startclose, lenclose]() {
                vx_core::Type_int output_1 = vx_core::f_plus(
                  vx_core::f_minus1(startclose),
                  lenclose
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(endclose);
        vx_core::Type_int endleft = vx_core::f_if_1(
          vx_core::t_int,
          vx_core::f_eq(vx_core::vx_new_int(1), pos),
          startclose,
          vx_core::f_minus1(startclose)
        );
        vx_core::vx_ref_plus(endleft);
        vx_core::Type_int startright = vx_core::f_plus1(endclose);
        vx_core::vx_ref_plus(startright);
        vx_core::Type_int endright = vx_core::f_if_1(
          vx_core::t_int,
          vx_core::f_lt(endpos, startright),
          startright,
          endpos
        );
        vx_core::vx_ref_plus(endright);
        vx_core::Type_string textleft = vx_type::f_string_from_string_end(text, posminus);
        vx_core::vx_ref_plus(textleft);
        vx_core::Type_string textright = vx_type::f_string_from_string_start(
          text,
          vx_core::f_plus(pos, lenclose)
        );
        vx_core::vx_ref_plus(textright);
        vx_data_textblock::Type_textblock find = vx_data_textblock::f_textblock_findparent_from_textblock(parent);
        vx_core::vx_ref_plus(find);
        vx_data_textblock::Type_delim closefind = find->close();
        vx_core::vx_ref_plus(closefind);
        vx_core::Type_string textfind = find->text();
        vx_core::vx_ref_plus(textfind);
        vx_core::Type_int startfind = find->startpos();
        vx_core::vx_ref_plus(startfind);
        vx_data_textblock::Type_delim delimfind = find->delim();
        vx_core::vx_ref_plus(delimfind);
        vx_data_textblock::Type_delim delimright = vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":delimlist"),
            delimfind->delimlist()
          })
        );
        vx_core::vx_ref_plus(delimright);
        vx_core::Type_int lenfind = vx_core::f_minus(
          vx_core::f_plus1(endclose),
          startfind
        );
        vx_core::vx_ref_plus(lenfind);
        vx_core::Type_string textreplace = vx_type::f_string_from_string_end(textfind, lenfind);
        vx_core::vx_ref_plus(textreplace);
        vx_data_textblock::Type_textblock replace = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          find,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            textreplace,
            vx_core::vx_new_string(":endpos"),
            endclose,
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              delimfind,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_empty(
                  vx_data_textblock::t_delimlist
                )
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_data_textblock::c_delimclosing
          })
        );
        vx_core::vx_ref_plus(replace);
        vx_data_textblock::Type_textblock parentchg = vx_data_textblock::f_textblock_replace_from_textblock_find_replace(parent, find, replace);
        vx_core::vx_ref_plus(parentchg);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            textleft,
            vx_core::vx_new_string(":startpos"),
            startleft,
            vx_core::vx_new_string(":endpos"),
            endleft,
            vx_core::vx_new_string(":parent"),
            vx_core::f_copy(
              vx_data_textblock::t_textblock,
              textblockarg,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                textright,
                vx_core::vx_new_string(":startpos"),
                startright,
                vx_core::vx_new_string(":endpos"),
                endright,
                vx_core::vx_new_string(":delim"),
                delimright,
                vx_core::vx_new_string(":close"),
                closefind,
                vx_core::vx_new_string(":parent"),
                parentchg
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, parent, startpos, endpos, pos, textclose, lenclose, posminus, startleft, startclose, endclose, endleft, startright, endright, textleft, textright, find, closefind, textfind, startfind, delimfind, delimright, lenfind, textreplace, replace, parentchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({close, textblockarg}, output);
    return output;
  }

  // (func textblock<-close-textblock)
  // class Class_textblock_from_close_textblock {
    Abstract_textblock_from_close_textblock::~Abstract_textblock_from_close_textblock() {}

    Class_textblock_from_close_textblock::Class_textblock_from_close_textblock() : Abstract_textblock_from_close_textblock::Abstract_textblock_from_close_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_close_textblock::~Class_textblock_from_close_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_close_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_close_textblock output = vx_data_textblock::e_textblock_from_close_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_close_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_close_textblock output = vx_data_textblock::e_textblock_from_close_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_close_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-close-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_close_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_close_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-close-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_close_textblock::vx_empty() const {return vx_data_textblock::e_textblock_from_close_textblock;}
    vx_core::Type_any Class_textblock_from_close_textblock::vx_type() const {return vx_data_textblock::t_textblock_from_close_textblock;}
    vx_core::Type_msgblock Class_textblock_from_close_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_close_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_close_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim close = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_close_textblock(close, textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-empty-textblock)
  vx_data_textblock::Type_textblock f_textblock_from_empty_textblock(vx_data_textblock::Type_delim empty, vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({empty, textblockarg});
    vx_core::vx_release_one_except({empty, textblockarg}, output);
    return output;
  }

  // (func textblock<-empty-textblock)
  // class Class_textblock_from_empty_textblock {
    Abstract_textblock_from_empty_textblock::~Abstract_textblock_from_empty_textblock() {}

    Class_textblock_from_empty_textblock::Class_textblock_from_empty_textblock() : Abstract_textblock_from_empty_textblock::Abstract_textblock_from_empty_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_empty_textblock::~Class_textblock_from_empty_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_empty_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_empty_textblock output = vx_data_textblock::e_textblock_from_empty_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_empty_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_empty_textblock output = vx_data_textblock::e_textblock_from_empty_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_empty_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-empty-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_empty_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_empty_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-empty-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_empty_textblock::vx_empty() const {return vx_data_textblock::e_textblock_from_empty_textblock;}
    vx_core::Type_any Class_textblock_from_empty_textblock::vx_type() const {return vx_data_textblock::t_textblock_from_empty_textblock;}
    vx_core::Type_msgblock Class_textblock_from_empty_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_empty_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_empty_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim empty = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_empty_textblock(empty, textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-open-textblock)
  vx_data_textblock::Type_textblock f_textblock_from_open_textblock(vx_data_textblock::Type_delim open, vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({open, textblockarg});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg, open}, [textblockarg, open]() {
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_int startpos = textblockarg->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int endpos = textblockarg->endpos();
        vx_core::vx_ref_plus(endpos);
        vx_data_textblock::Type_delim delima = textblockarg->delim();
        vx_core::vx_ref_plus(delima);
        vx_core::Type_int pos = open->pos();
        vx_core::vx_ref_plus(pos);
        vx_core::Type_string textopen = open->starttext();
        vx_core::vx_ref_plus(textopen);
        vx_core::Type_string textclose = open->endtext();
        vx_core::vx_ref_plus(textclose);
        vx_data_textblock::Type_delimlist delimlistl = open->delimlist();
        vx_core::vx_ref_plus(delimlistl);
        vx_core::Type_int lenopen = vx_type::f_length_from_string(textopen);
        vx_core::vx_ref_plus(lenopen);
        vx_core::Type_int posminus = vx_core::f_minus1(pos);
        vx_core::vx_ref_plus(posminus);
        vx_core::Type_int startleft = vx_core::f_minus1(startpos);
        vx_core::vx_ref_plus(startleft);
        vx_core::Type_int endleft = vx_core::f_plus(startleft, posminus);
        vx_core::vx_ref_plus(endleft);
        vx_core::Type_int startright = vx_core::f_plus_2(
          vx_core::vx_new(vx_core::t_intlist, {
            startleft,
            pos,
            lenopen
          })
        );
        vx_core::vx_ref_plus(startright);
        vx_core::Type_int startopen = vx_core::f_plus(startpos, posminus);
        vx_core::vx_ref_plus(startopen);
        vx_core::Type_string textleft = vx_type::f_string_from_string_end(text, posminus);
        vx_core::vx_ref_plus(textleft);
        vx_core::Type_string textpar = vx_type::f_string_from_string_start(text, pos);
        vx_core::vx_ref_plus(textpar);
        vx_core::Type_string textright = vx_type::f_string_from_string_start(
          text,
          vx_core::f_plus(pos, lenopen)
        );
        vx_core::vx_ref_plus(textright);
        vx_data_textblock::Type_delim close = vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimclose,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            textclose
          })
        );
        vx_core::vx_ref_plus(close);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            textleft,
            vx_core::vx_new_string(":startpos"),
            startleft,
            vx_core::vx_new_string(":endpos"),
            endleft,
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                delimlistl
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                textright,
                vx_core::vx_new_string(":startpos"),
                startright,
                vx_core::vx_new_string(":endpos"),
                endpos,
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    delimlistl
                  })
                ),
                vx_core::vx_new_string(":close"),
                close,
                vx_core::vx_new_string(":parent"),
                vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":startpos"),
                    startopen,
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      open,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0),
                        vx_core::vx_new_string(":delimlist"),
                        delima->delimlist()
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    parent
                  })
                )
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, parent, startpos, endpos, delima, pos, textopen, textclose, delimlistl, lenopen, posminus, startleft, endleft, startright, startopen, textleft, textpar, textright, close}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({open, textblockarg}, output);
    return output;
  }

  // (func textblock<-open-textblock)
  // class Class_textblock_from_open_textblock {
    Abstract_textblock_from_open_textblock::~Abstract_textblock_from_open_textblock() {}

    Class_textblock_from_open_textblock::Class_textblock_from_open_textblock() : Abstract_textblock_from_open_textblock::Abstract_textblock_from_open_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_open_textblock::~Class_textblock_from_open_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_open_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_open_textblock output = vx_data_textblock::e_textblock_from_open_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_open_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_open_textblock output = vx_data_textblock::e_textblock_from_open_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_open_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-open-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_open_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_open_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-open-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_open_textblock::vx_empty() const {return vx_data_textblock::e_textblock_from_open_textblock;}
    vx_core::Type_any Class_textblock_from_open_textblock::vx_type() const {return vx_data_textblock::t_textblock_from_open_textblock;}
    vx_core::Type_msgblock Class_textblock_from_open_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_open_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_open_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim open = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_open_textblock(open, textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-single-textblock)
  vx_data_textblock::Type_textblock f_textblock_from_single_textblock(vx_data_textblock::Type_delim single, vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({single, textblockarg});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg, single}, [textblockarg, single]() {
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_int startpos = textblockarg->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int endpos = textblockarg->endpos();
        vx_core::vx_ref_plus(endpos);
        vx_core::Type_int pos = single->pos();
        vx_core::vx_ref_plus(pos);
        vx_core::Type_string origsingle = single->starttext();
        vx_core::vx_ref_plus(origsingle);
        vx_core::Type_string textsingle = vx_core::f_switch(
          vx_core::t_string,
          origsingle,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(":whitespace"),
              vx_core::t_any_from_func->vx_fn_new({text, pos}, [text, pos]() {
                vx_core::Type_string output_1 = vx_core::f_let(
                  vx_core::t_string,
                  vx_core::t_any_from_func->vx_fn_new({text, pos}, [text, pos]() {
                    vx_core::Type_string text2 = vx_type::f_string_from_string_start(text, pos);
                    vx_core::vx_ref_plus(text2);
                    vx_core::Type_int pos2 = vx_type::f_int_from_string_findkeyword(text2, vx_core::vx_new_string(":nonwhitespace"));
                    vx_core::vx_ref_plus(pos2);
                    vx_core::Type_int pos3 = vx_core::f_if_2(
                      vx_core::t_int,
                      vx_core::vx_new(vx_core::t_thenelselist, {
                        vx_core::f_then(
                          vx_core::t_boolean_from_func->vx_fn_new({pos2}, [pos2]() {
                            vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_int(0), pos2);
                            return output_1;
                          }),
                          vx_core::t_any_from_func->vx_fn_new({text2}, [text2]() {
                            vx_core::Type_int output_1 = vx_type::f_length_from_string(text2);
                            return output_1;
                          })
                        ),
                        vx_core::f_then(
                          vx_core::t_boolean_from_func->vx_fn_new({pos2, pos}, [pos2, pos]() {
                            vx_core::Type_boolean output_1 = vx_core::f_eq(pos2, pos);
                            return output_1;
                          }),
                          vx_core::t_any_from_func->vx_fn_new({pos2}, [pos2]() {
                            vx_core::Type_any output_1 = pos2;
                            return output_1;
                          })
                        ),
                        vx_core::f_else(
                          vx_core::t_any_from_func->vx_fn_new({pos2}, [pos2]() {
                            vx_core::Type_int output_1 = vx_core::f_minus1(pos2);
                            return output_1;
                          })
                        )
                      })
                    );
                    vx_core::vx_ref_plus(pos3);
                    vx_core::Type_string output_1 = vx_type::f_string_from_string_start_end(text, pos, pos3);
                    vx_core::vx_release_one_except({text2, pos2, pos3}, output_1);
                    return output_1;
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({origsingle}, [origsingle]() {
                vx_core::Type_any output_1 = origsingle;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(textsingle);
        vx_data_textblock::Type_delimlist delimlistl = single->delimlist();
        vx_core::vx_ref_plus(delimlistl);
        vx_core::Type_int lensingle = vx_type::f_length_from_string(textsingle);
        vx_core::vx_ref_plus(lensingle);
        vx_core::Type_int posminus = vx_core::f_minus1(pos);
        vx_core::vx_ref_plus(posminus);
        vx_core::Type_int startleft = startpos;
        vx_core::vx_ref_plus(startleft);
        vx_core::Type_int startsingle = vx_core::f_plus(startpos, posminus);
        vx_core::vx_ref_plus(startsingle);
        vx_core::Type_int endsingle = vx_core::f_switch(
          vx_core::t_int,
          textsingle,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(":whitespace"),
              vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                vx_core::Type_int output_1 = vx_type::f_int_from_string_findkeyword(text, vx_core::vx_new_string(":nonwhitespace"));
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({startsingle, lensingle}, [startsingle, lensingle]() {
                vx_core::Type_int output_1 = vx_core::f_plus(
                  vx_core::f_minus1(startsingle),
                  lensingle
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(endsingle);
        vx_core::Type_int endleft = vx_core::f_if_1(
          vx_core::t_int,
          vx_core::f_eq(startsingle, startpos),
          startsingle,
          vx_core::f_minus1(startsingle)
        );
        vx_core::vx_ref_plus(endleft);
        vx_core::Type_int startright = vx_core::f_plus1(endsingle);
        vx_core::vx_ref_plus(startright);
        vx_core::Type_string textleft = vx_type::f_string_from_string_end(text, posminus);
        vx_core::vx_ref_plus(textleft);
        vx_core::Type_string textpar = vx_type::f_string_from_string_start(text, pos);
        vx_core::vx_ref_plus(textpar);
        vx_core::Type_string textright = vx_type::f_string_from_string_start(
          text,
          vx_core::f_plus(pos, lensingle)
        );
        vx_core::vx_ref_plus(textright);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            textleft,
            vx_core::vx_new_string(":startpos"),
            startleft,
            vx_core::vx_new_string(":endpos"),
            endleft,
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                delimlistl
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                textsingle,
                vx_core::vx_new_string(":startpos"),
                startsingle,
                vx_core::vx_new_string(":endpos"),
                endsingle,
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  single,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0),
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_empty(
                      vx_data_textblock::t_delimlist
                    )
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    textright,
                    vx_core::vx_new_string(":startpos"),
                    startright,
                    vx_core::vx_new_string(":endpos"),
                    endpos
                  })
                )
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, parent, startpos, endpos, pos, origsingle, textsingle, delimlistl, lensingle, posminus, startleft, startsingle, endsingle, endleft, startright, textleft, textpar, textright}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({single, textblockarg}, output);
    return output;
  }

  // (func textblock<-single-textblock)
  // class Class_textblock_from_single_textblock {
    Abstract_textblock_from_single_textblock::~Abstract_textblock_from_single_textblock() {}

    Class_textblock_from_single_textblock::Class_textblock_from_single_textblock() : Abstract_textblock_from_single_textblock::Abstract_textblock_from_single_textblock() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_single_textblock::~Class_textblock_from_single_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_single_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_single_textblock output = vx_data_textblock::e_textblock_from_single_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_single_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_single_textblock output = vx_data_textblock::e_textblock_from_single_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_single_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-single-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_single_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_single_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-single-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_single_textblock::vx_empty() const {return vx_data_textblock::e_textblock_from_single_textblock;}
    vx_core::Type_any Class_textblock_from_single_textblock::vx_type() const {return vx_data_textblock::t_textblock_from_single_textblock;}
    vx_core::Type_msgblock Class_textblock_from_single_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_single_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_single_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim single = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_single_textblock(single, textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-string-delim)
  vx_data_textblock::Type_textblock f_textblock_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({text, delim});
    output = vx_core::f_new(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":text"),
        text,
        vx_core::vx_new_string(":delim"),
        delim,
        vx_core::vx_new_string(":startpos"),
        vx_core::vx_new_int(0),
        vx_core::vx_new_string(":endpos"),
        vx_type::f_length_from_string(text)
      })
    );
    vx_core::vx_release_one_except({text, delim}, output);
    return output;
  }

  // (func textblock<-string-delim)
  // class Class_textblock_from_string_delim {
    Abstract_textblock_from_string_delim::~Abstract_textblock_from_string_delim() {}

    Class_textblock_from_string_delim::Class_textblock_from_string_delim() : Abstract_textblock_from_string_delim::Abstract_textblock_from_string_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_string_delim::~Class_textblock_from_string_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_string_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_string_delim output = vx_data_textblock::e_textblock_from_string_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_string_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_string_delim output = vx_data_textblock::e_textblock_from_string_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_string_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-string-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_string_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_string_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-string-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_string_delim::vx_empty() const {return vx_data_textblock::e_textblock_from_string_delim;}
    vx_core::Type_any Class_textblock_from_string_delim::vx_type() const {return vx_data_textblock::t_textblock_from_string_delim;}
    vx_core::Type_msgblock Class_textblock_from_string_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_string_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_string_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_string_delim(text, delim);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-textblock-delim)
  vx_data_textblock::Type_textblock f_textblock_from_textblock_delim(vx_data_textblock::Type_textblock textblock, vx_data_textblock::Type_delim delim) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblock, delim});
    vx_core::vx_release_one_except({textblock, delim}, output);
    return output;
  }

  // (func textblock<-textblock-delim)
  // class Class_textblock_from_textblock_delim {
    Abstract_textblock_from_textblock_delim::~Abstract_textblock_from_textblock_delim() {}

    Class_textblock_from_textblock_delim::Class_textblock_from_textblock_delim() : Abstract_textblock_from_textblock_delim::Abstract_textblock_from_textblock_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_textblock_delim::~Class_textblock_from_textblock_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_textblock_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_textblock_delim output = vx_data_textblock::e_textblock_from_textblock_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_textblock_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_from_textblock_delim output = vx_data_textblock::e_textblock_from_textblock_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_textblock_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock<-textblock-delim", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_textblock_delim::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_textblock_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-textblock-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_textblock_delim::vx_empty() const {return vx_data_textblock::e_textblock_from_textblock_delim;}
    vx_core::Type_any Class_textblock_from_textblock_delim::vx_type() const {return vx_data_textblock::t_textblock_from_textblock_delim;}
    vx_core::Type_msgblock Class_textblock_from_textblock_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_textblock_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_from_textblock_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_from_textblock_delim(textblock, delim);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblocklist<-textblocklist-remove)
  vx_data_textblock::Type_textblocklist f_textblocklist_from_textblocklist_remove(vx_data_textblock::Type_textblocklist tblist, vx_data_textblock::Type_delim remove) {
    vx_data_textblock::Type_textblocklist output = vx_data_textblock::e_textblocklist;
    vx_core::vx_reserve({tblist, remove});
    output = vx_collection::f_list_from_list_filter(
      vx_data_textblock::t_textblocklist,
      tblist,
      vx_core::t_any_from_any->vx_fn_new({remove}, [remove](vx_core::Type_any textblock_any) {
        vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, textblock_any);
        vx_core::Type_any output_1 = 
          vx_core::f_let(
            vx_data_textblock::t_textblock,
            vx_core::t_any_from_func->vx_fn_new({textblock, remove}, [textblock, remove]() {
              vx_data_textblock::Type_delim delimcurr = textblock->delim();
              vx_core::vx_ref_plus(delimcurr);
              vx_core::Type_string namecurr = delimcurr->name();
              vx_core::vx_ref_plus(namecurr);
              vx_core::Type_string nameremove = remove->name();
              vx_core::vx_ref_plus(nameremove);
              vx_data_textblock::Type_textblock output_1 = vx_core::f_if(
                vx_data_textblock::t_textblock,
                vx_core::f_ne(namecurr, nameremove),
                textblock
              );
              vx_core::vx_release_one_except({delimcurr, namecurr, nameremove}, output_1);
              return output_1;
            })
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except({tblist, remove}, output);
    return output;
  }

  // (func textblocklist<-textblocklist-remove)
  // class Class_textblocklist_from_textblocklist_remove {
    Abstract_textblocklist_from_textblocklist_remove::~Abstract_textblocklist_from_textblocklist_remove() {}

    Class_textblocklist_from_textblocklist_remove::Class_textblocklist_from_textblocklist_remove() : Abstract_textblocklist_from_textblocklist_remove::Abstract_textblocklist_from_textblocklist_remove() {
      vx_core::refcount += 1;
    }

    Class_textblocklist_from_textblocklist_remove::~Class_textblocklist_from_textblocklist_remove() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblocklist_from_textblocklist_remove::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblocklist_from_textblocklist_remove output = vx_data_textblock::e_textblocklist_from_textblocklist_remove;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblocklist_from_textblocklist_remove::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblocklist_from_textblocklist_remove output = vx_data_textblock::e_textblocklist_from_textblocklist_remove;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblocklist_from_textblocklist_remove::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblocklist_from_textblocklist_remove::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblocklist_from_textblocklist_remove::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblocklist_from_textblocklist_remove::vx_empty() const {return vx_data_textblock::e_textblocklist_from_textblocklist_remove;}
    vx_core::Type_any Class_textblocklist_from_textblocklist_remove::vx_type() const {return vx_data_textblock::t_textblocklist_from_textblocklist_remove;}
    vx_core::Type_msgblock Class_textblocklist_from_textblocklist_remove::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblocklist_from_textblocklist_remove::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblocklist_from_textblocklist_remove::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist tblist = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim remove = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblocklist_from_textblocklist_remove(tblist, remove);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_textblock::Type_delim e_delim = NULL;
  vx_data_textblock::Type_delim t_delim = NULL;
  vx_data_textblock::Type_delimlist e_delimlist = NULL;
  vx_data_textblock::Type_delimlist t_delimlist = NULL;
  vx_data_textblock::Type_textblock e_textblock = NULL;
  vx_data_textblock::Type_textblock t_textblock = NULL;
  vx_data_textblock::Type_textblocklist e_textblocklist = NULL;
  vx_data_textblock::Type_textblocklist t_textblocklist = NULL;
  vx_data_textblock::Const_delimbracketangle c_delimbracketangle = NULL;
  vx_data_textblock::Const_delimbracketcurly c_delimbracketcurly = NULL;
  vx_data_textblock::Const_delimbracketsquare c_delimbracketsquare = NULL;
  vx_data_textblock::Const_delimclose c_delimclose = NULL;
  vx_data_textblock::Const_delimclosing c_delimclosing = NULL;
  vx_data_textblock::Const_delimcomma c_delimcomma = NULL;
  vx_data_textblock::Const_delimcomment c_delimcomment = NULL;
  vx_data_textblock::Const_delimcommentblock c_delimcommentblock = NULL;
  vx_data_textblock::Const_delimline c_delimline = NULL;
  vx_data_textblock::Const_delimlisttest1 c_delimlisttest1 = NULL;
  vx_data_textblock::Const_delimlisttest2 c_delimlisttest2 = NULL;
  vx_data_textblock::Const_delimlisttest3 c_delimlisttest3 = NULL;
  vx_data_textblock::Const_delimnonwhitespace c_delimnonwhitespace = NULL;
  vx_data_textblock::Const_delimparen c_delimparen = NULL;
  vx_data_textblock::Const_delimquote c_delimquote = NULL;
  vx_data_textblock::Const_delimquoteblock c_delimquoteblock = NULL;
  vx_data_textblock::Const_delimspace c_delimspace = NULL;
  vx_data_textblock::Const_delimtest1 c_delimtest1 = NULL;
  vx_data_textblock::Const_delimtest2 c_delimtest2 = NULL;
  vx_data_textblock::Const_delimtest3 c_delimtest3 = NULL;
  vx_data_textblock::Const_delimtext c_delimtext = NULL;
  vx_data_textblock::Const_delimwhitespace c_delimwhitespace = NULL;
  vx_data_textblock::Func_children_from_textblock e_children_from_textblock = NULL;
  vx_data_textblock::Func_children_from_textblock t_children_from_textblock = NULL;
  vx_data_textblock::Func_delim_first_from_delim_delim e_delim_first_from_delim_delim = NULL;
  vx_data_textblock::Func_delim_first_from_delim_delim t_delim_first_from_delim_delim = NULL;
  vx_data_textblock::Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist = NULL;
  vx_data_textblock::Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist = NULL;
  vx_data_textblock::Func_delim_pos_from_string_delim e_delim_pos_from_string_delim = NULL;
  vx_data_textblock::Func_delim_pos_from_string_delim t_delim_pos_from_string_delim = NULL;
  vx_data_textblock::Func_delimlist_pos_from_string_delimlist e_delimlist_pos_from_string_delimlist = NULL;
  vx_data_textblock::Func_delimlist_pos_from_string_delimlist t_delimlist_pos_from_string_delimlist = NULL;
  vx_data_textblock::Func_is_close e_is_close = NULL;
  vx_data_textblock::Func_is_close t_is_close = NULL;
  vx_data_textblock::Func_is_single e_is_single = NULL;
  vx_data_textblock::Func_is_single t_is_single = NULL;
  vx_data_textblock::Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = NULL;
  vx_data_textblock::Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = NULL;
  vx_data_textblock::Func_text_from_textblock e_text_from_textblock = NULL;
  vx_data_textblock::Func_text_from_textblock t_text_from_textblock = NULL;
  vx_data_textblock::Func_textblock_addchild_from_textblock_find_child e_textblock_addchild_from_textblock_find_child = NULL;
  vx_data_textblock::Func_textblock_addchild_from_textblock_find_child t_textblock_addchild_from_textblock_find_child = NULL;
  vx_data_textblock::Func_textblock_delimnotfound e_textblock_delimnotfound = NULL;
  vx_data_textblock::Func_textblock_delimnotfound t_textblock_delimnotfound = NULL;
  vx_data_textblock::Func_textblock_findparent_from_textblock e_textblock_findparent_from_textblock = NULL;
  vx_data_textblock::Func_textblock_findparent_from_textblock t_textblock_findparent_from_textblock = NULL;
  vx_data_textblock::Func_textblock_groupby_from_textblock_delim e_textblock_groupby_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_groupby_from_textblock_delim t_textblock_groupby_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_init e_textblock_init = NULL;
  vx_data_textblock::Func_textblock_init t_textblock_init = NULL;
  vx_data_textblock::Func_textblock_parse e_textblock_parse = NULL;
  vx_data_textblock::Func_textblock_parse t_textblock_parse = NULL;
  vx_data_textblock::Func_textblock_parse_one e_textblock_parse_one = NULL;
  vx_data_textblock::Func_textblock_parse_one t_textblock_parse_one = NULL;
  vx_data_textblock::Func_textblock_parse_from_string_delim e_textblock_parse_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_parse_from_string_delim t_textblock_parse_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_replace_from_textblock_find_replace e_textblock_replace_from_textblock_find_replace = NULL;
  vx_data_textblock::Func_textblock_replace_from_textblock_find_replace t_textblock_replace_from_textblock_find_replace = NULL;
  vx_data_textblock::Func_textblock_startleft_from_string_delim_offset e_textblock_startleft_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startleft_from_string_delim_offset t_textblock_startleft_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startright_from_string_delim_offset e_textblock_startright_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startright_from_string_delim_offset t_textblock_startright_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_from_close_textblock e_textblock_from_close_textblock = NULL;
  vx_data_textblock::Func_textblock_from_close_textblock t_textblock_from_close_textblock = NULL;
  vx_data_textblock::Func_textblock_from_empty_textblock e_textblock_from_empty_textblock = NULL;
  vx_data_textblock::Func_textblock_from_empty_textblock t_textblock_from_empty_textblock = NULL;
  vx_data_textblock::Func_textblock_from_open_textblock e_textblock_from_open_textblock = NULL;
  vx_data_textblock::Func_textblock_from_open_textblock t_textblock_from_open_textblock = NULL;
  vx_data_textblock::Func_textblock_from_single_textblock e_textblock_from_single_textblock = NULL;
  vx_data_textblock::Func_textblock_from_single_textblock t_textblock_from_single_textblock = NULL;
  vx_data_textblock::Func_textblock_from_string_delim e_textblock_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_from_string_delim t_textblock_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_from_textblock_delim e_textblock_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_from_textblock_delim t_textblock_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblocklist_from_textblocklist_remove e_textblocklist_from_textblocklist_remove = NULL;
  vx_data_textblock::Func_textblocklist_from_textblocklist_remove t_textblocklist_from_textblocklist_remove = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_textblock::c_delimbracketangle = new vx_data_textblock::Class_delimbracketangle();
      vx_data_textblock::c_delimbracketcurly = new vx_data_textblock::Class_delimbracketcurly();
      vx_data_textblock::c_delimbracketsquare = new vx_data_textblock::Class_delimbracketsquare();
      vx_data_textblock::c_delimclose = new vx_data_textblock::Class_delimclose();
      vx_data_textblock::c_delimclosing = new vx_data_textblock::Class_delimclosing();
      vx_data_textblock::c_delimcomma = new vx_data_textblock::Class_delimcomma();
      vx_data_textblock::c_delimcomment = new vx_data_textblock::Class_delimcomment();
      vx_data_textblock::c_delimcommentblock = new vx_data_textblock::Class_delimcommentblock();
      vx_data_textblock::c_delimline = new vx_data_textblock::Class_delimline();
      vx_data_textblock::c_delimlisttest1 = new vx_data_textblock::Class_delimlisttest1();
      vx_data_textblock::c_delimlisttest2 = new vx_data_textblock::Class_delimlisttest2();
      vx_data_textblock::c_delimlisttest3 = new vx_data_textblock::Class_delimlisttest3();
      vx_data_textblock::c_delimnonwhitespace = new vx_data_textblock::Class_delimnonwhitespace();
      vx_data_textblock::c_delimparen = new vx_data_textblock::Class_delimparen();
      vx_data_textblock::c_delimquote = new vx_data_textblock::Class_delimquote();
      vx_data_textblock::c_delimquoteblock = new vx_data_textblock::Class_delimquoteblock();
      vx_data_textblock::c_delimspace = new vx_data_textblock::Class_delimspace();
      vx_data_textblock::c_delimtest1 = new vx_data_textblock::Class_delimtest1();
      vx_data_textblock::c_delimtest2 = new vx_data_textblock::Class_delimtest2();
      vx_data_textblock::c_delimtest3 = new vx_data_textblock::Class_delimtest3();
      vx_data_textblock::c_delimtext = new vx_data_textblock::Class_delimtext();
      vx_data_textblock::c_delimwhitespace = new vx_data_textblock::Class_delimwhitespace();
      vx_data_textblock::e_delim = new Class_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim);
      vx_data_textblock::t_delim = new Class_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim);
      vx_data_textblock::e_delimlist = new Class_delimlist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delimlist);
      vx_data_textblock::t_delimlist = new Class_delimlist();
      vx_core::vx_reserve_type(vx_data_textblock::t_delimlist);
      vx_data_textblock::e_textblock = new Class_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock);
      vx_data_textblock::t_textblock = new Class_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock);
      vx_data_textblock::e_textblocklist = new Class_textblocklist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblocklist);
      vx_data_textblock::t_textblocklist = new Class_textblocklist();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblocklist);
      vx_data_textblock::e_children_from_textblock = new vx_data_textblock::Class_children_from_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_children_from_textblock);
      vx_data_textblock::t_children_from_textblock = new vx_data_textblock::Class_children_from_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_children_from_textblock);
      vx_data_textblock::e_delim_first_from_delim_delim = new vx_data_textblock::Class_delim_first_from_delim_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_first_from_delim_delim);
      vx_data_textblock::t_delim_first_from_delim_delim = new vx_data_textblock::Class_delim_first_from_delim_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_first_from_delim_delim);
      vx_data_textblock::e_delim_first_from_string_delimlist = new vx_data_textblock::Class_delim_first_from_string_delimlist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_first_from_string_delimlist);
      vx_data_textblock::t_delim_first_from_string_delimlist = new vx_data_textblock::Class_delim_first_from_string_delimlist();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_first_from_string_delimlist);
      vx_data_textblock::e_delim_pos_from_string_delim = new vx_data_textblock::Class_delim_pos_from_string_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_pos_from_string_delim);
      vx_data_textblock::t_delim_pos_from_string_delim = new vx_data_textblock::Class_delim_pos_from_string_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_pos_from_string_delim);
      vx_data_textblock::e_delimlist_pos_from_string_delimlist = new vx_data_textblock::Class_delimlist_pos_from_string_delimlist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delimlist_pos_from_string_delimlist);
      vx_data_textblock::t_delimlist_pos_from_string_delimlist = new vx_data_textblock::Class_delimlist_pos_from_string_delimlist();
      vx_core::vx_reserve_type(vx_data_textblock::t_delimlist_pos_from_string_delimlist);
      vx_data_textblock::e_is_close = new vx_data_textblock::Class_is_close();
      vx_core::vx_reserve_empty(vx_data_textblock::e_is_close);
      vx_data_textblock::t_is_close = new vx_data_textblock::Class_is_close();
      vx_core::vx_reserve_type(vx_data_textblock::t_is_close);
      vx_data_textblock::e_is_single = new vx_data_textblock::Class_is_single();
      vx_core::vx_reserve_empty(vx_data_textblock::e_is_single);
      vx_data_textblock::t_is_single = new vx_data_textblock::Class_is_single();
      vx_core::vx_reserve_type(vx_data_textblock::t_is_single);
      vx_data_textblock::e_stringlist_from_textblocklist = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_stringlist_from_textblocklist);
      vx_data_textblock::t_stringlist_from_textblocklist = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_type(vx_data_textblock::t_stringlist_from_textblocklist);
      vx_data_textblock::e_text_from_textblock = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_text_from_textblock);
      vx_data_textblock::t_text_from_textblock = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_text_from_textblock);
      vx_data_textblock::e_textblock_addchild_from_textblock_find_child = new vx_data_textblock::Class_textblock_addchild_from_textblock_find_child();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_addchild_from_textblock_find_child);
      vx_data_textblock::t_textblock_addchild_from_textblock_find_child = new vx_data_textblock::Class_textblock_addchild_from_textblock_find_child();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_addchild_from_textblock_find_child);
      vx_data_textblock::e_textblock_delimnotfound = new vx_data_textblock::Class_textblock_delimnotfound();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_delimnotfound);
      vx_data_textblock::t_textblock_delimnotfound = new vx_data_textblock::Class_textblock_delimnotfound();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_delimnotfound);
      vx_data_textblock::e_textblock_findparent_from_textblock = new vx_data_textblock::Class_textblock_findparent_from_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_findparent_from_textblock);
      vx_data_textblock::t_textblock_findparent_from_textblock = new vx_data_textblock::Class_textblock_findparent_from_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_findparent_from_textblock);
      vx_data_textblock::e_textblock_groupby_from_textblock_delim = new vx_data_textblock::Class_textblock_groupby_from_textblock_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_groupby_from_textblock_delim);
      vx_data_textblock::t_textblock_groupby_from_textblock_delim = new vx_data_textblock::Class_textblock_groupby_from_textblock_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_groupby_from_textblock_delim);
      vx_data_textblock::e_textblock_init = new vx_data_textblock::Class_textblock_init();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_init);
      vx_data_textblock::t_textblock_init = new vx_data_textblock::Class_textblock_init();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_init);
      vx_data_textblock::e_textblock_parse = new vx_data_textblock::Class_textblock_parse();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_parse);
      vx_data_textblock::t_textblock_parse = new vx_data_textblock::Class_textblock_parse();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_parse);
      vx_data_textblock::e_textblock_parse_one = new vx_data_textblock::Class_textblock_parse_one();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_parse_one);
      vx_data_textblock::t_textblock_parse_one = new vx_data_textblock::Class_textblock_parse_one();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_parse_one);
      vx_data_textblock::e_textblock_parse_from_string_delim = new vx_data_textblock::Class_textblock_parse_from_string_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_parse_from_string_delim);
      vx_data_textblock::t_textblock_parse_from_string_delim = new vx_data_textblock::Class_textblock_parse_from_string_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_parse_from_string_delim);
      vx_data_textblock::e_textblock_replace_from_textblock_find_replace = new vx_data_textblock::Class_textblock_replace_from_textblock_find_replace();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_replace_from_textblock_find_replace);
      vx_data_textblock::t_textblock_replace_from_textblock_find_replace = new vx_data_textblock::Class_textblock_replace_from_textblock_find_replace();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_replace_from_textblock_find_replace);
      vx_data_textblock::e_textblock_startleft_from_string_delim_offset = new vx_data_textblock::Class_textblock_startleft_from_string_delim_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_startleft_from_string_delim_offset);
      vx_data_textblock::t_textblock_startleft_from_string_delim_offset = new vx_data_textblock::Class_textblock_startleft_from_string_delim_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_startleft_from_string_delim_offset);
      vx_data_textblock::e_textblock_startright_from_string_delim_offset = new vx_data_textblock::Class_textblock_startright_from_string_delim_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_startright_from_string_delim_offset);
      vx_data_textblock::t_textblock_startright_from_string_delim_offset = new vx_data_textblock::Class_textblock_startright_from_string_delim_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_startright_from_string_delim_offset);
      vx_data_textblock::e_textblock_from_close_textblock = new vx_data_textblock::Class_textblock_from_close_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_close_textblock);
      vx_data_textblock::t_textblock_from_close_textblock = new vx_data_textblock::Class_textblock_from_close_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_close_textblock);
      vx_data_textblock::e_textblock_from_empty_textblock = new vx_data_textblock::Class_textblock_from_empty_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_empty_textblock);
      vx_data_textblock::t_textblock_from_empty_textblock = new vx_data_textblock::Class_textblock_from_empty_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_empty_textblock);
      vx_data_textblock::e_textblock_from_open_textblock = new vx_data_textblock::Class_textblock_from_open_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_open_textblock);
      vx_data_textblock::t_textblock_from_open_textblock = new vx_data_textblock::Class_textblock_from_open_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_open_textblock);
      vx_data_textblock::e_textblock_from_single_textblock = new vx_data_textblock::Class_textblock_from_single_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_single_textblock);
      vx_data_textblock::t_textblock_from_single_textblock = new vx_data_textblock::Class_textblock_from_single_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_single_textblock);
      vx_data_textblock::e_textblock_from_string_delim = new vx_data_textblock::Class_textblock_from_string_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_string_delim);
      vx_data_textblock::t_textblock_from_string_delim = new vx_data_textblock::Class_textblock_from_string_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_string_delim);
      vx_data_textblock::e_textblock_from_textblock_delim = new vx_data_textblock::Class_textblock_from_textblock_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_textblock_delim);
      vx_data_textblock::t_textblock_from_textblock_delim = new vx_data_textblock::Class_textblock_from_textblock_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_textblock_delim);
      vx_data_textblock::e_textblocklist_from_textblocklist_remove = new vx_data_textblock::Class_textblocklist_from_textblocklist_remove();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblocklist_from_textblocklist_remove);
      vx_data_textblock::t_textblocklist_from_textblocklist_remove = new vx_data_textblock::Class_textblocklist_from_textblocklist_remove();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblocklist_from_textblocklist_remove);
      vx_data_textblock::Class_delimbracketangle::vx_const_new(vx_data_textblock::c_delimbracketangle);
      vx_data_textblock::Class_delimbracketcurly::vx_const_new(vx_data_textblock::c_delimbracketcurly);
      vx_data_textblock::Class_delimbracketsquare::vx_const_new(vx_data_textblock::c_delimbracketsquare);
      vx_data_textblock::Class_delimclose::vx_const_new(vx_data_textblock::c_delimclose);
      vx_data_textblock::Class_delimclosing::vx_const_new(vx_data_textblock::c_delimclosing);
      vx_data_textblock::Class_delimcomma::vx_const_new(vx_data_textblock::c_delimcomma);
      vx_data_textblock::Class_delimcomment::vx_const_new(vx_data_textblock::c_delimcomment);
      vx_data_textblock::Class_delimcommentblock::vx_const_new(vx_data_textblock::c_delimcommentblock);
      vx_data_textblock::Class_delimline::vx_const_new(vx_data_textblock::c_delimline);
      vx_data_textblock::Class_delimlisttest1::vx_const_new(vx_data_textblock::c_delimlisttest1);
      vx_data_textblock::Class_delimlisttest2::vx_const_new(vx_data_textblock::c_delimlisttest2);
      vx_data_textblock::Class_delimlisttest3::vx_const_new(vx_data_textblock::c_delimlisttest3);
      vx_data_textblock::Class_delimnonwhitespace::vx_const_new(vx_data_textblock::c_delimnonwhitespace);
      vx_data_textblock::Class_delimparen::vx_const_new(vx_data_textblock::c_delimparen);
      vx_data_textblock::Class_delimquote::vx_const_new(vx_data_textblock::c_delimquote);
      vx_data_textblock::Class_delimquoteblock::vx_const_new(vx_data_textblock::c_delimquoteblock);
      vx_data_textblock::Class_delimspace::vx_const_new(vx_data_textblock::c_delimspace);
      vx_data_textblock::Class_delimtest1::vx_const_new(vx_data_textblock::c_delimtest1);
      vx_data_textblock::Class_delimtest2::vx_const_new(vx_data_textblock::c_delimtest2);
      vx_data_textblock::Class_delimtest3::vx_const_new(vx_data_textblock::c_delimtest3);
      vx_data_textblock::Class_delimtext::vx_const_new(vx_data_textblock::c_delimtext);
      vx_data_textblock::Class_delimwhitespace::vx_const_new(vx_data_textblock::c_delimwhitespace);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["delim"] = vx_data_textblock::t_delim;
      maptype["delimlist"] = vx_data_textblock::t_delimlist;
      maptype["textblock"] = vx_data_textblock::t_textblock;
      maptype["textblocklist"] = vx_data_textblock::t_textblocklist;
      mapconst["delimbracketangle"] = vx_data_textblock::c_delimbracketangle;
      mapconst["delimbracketcurly"] = vx_data_textblock::c_delimbracketcurly;
      mapconst["delimbracketsquare"] = vx_data_textblock::c_delimbracketsquare;
      mapconst["delimclose"] = vx_data_textblock::c_delimclose;
      mapconst["delimclosing"] = vx_data_textblock::c_delimclosing;
      mapconst["delimcomma"] = vx_data_textblock::c_delimcomma;
      mapconst["delimcomment"] = vx_data_textblock::c_delimcomment;
      mapconst["delimcommentblock"] = vx_data_textblock::c_delimcommentblock;
      mapconst["delimline"] = vx_data_textblock::c_delimline;
      mapconst["delimlisttest1"] = vx_data_textblock::c_delimlisttest1;
      mapconst["delimlisttest2"] = vx_data_textblock::c_delimlisttest2;
      mapconst["delimlisttest3"] = vx_data_textblock::c_delimlisttest3;
      mapconst["delimnonwhitespace"] = vx_data_textblock::c_delimnonwhitespace;
      mapconst["delimparen"] = vx_data_textblock::c_delimparen;
      mapconst["delimquote"] = vx_data_textblock::c_delimquote;
      mapconst["delimquoteblock"] = vx_data_textblock::c_delimquoteblock;
      mapconst["delimspace"] = vx_data_textblock::c_delimspace;
      mapconst["delimtest1"] = vx_data_textblock::c_delimtest1;
      mapconst["delimtest2"] = vx_data_textblock::c_delimtest2;
      mapconst["delimtest3"] = vx_data_textblock::c_delimtest3;
      mapconst["delimtext"] = vx_data_textblock::c_delimtext;
      mapconst["delimwhitespace"] = vx_data_textblock::c_delimwhitespace;
      mapfunc["children<-textblock"] = vx_data_textblock::t_children_from_textblock;
      mapfunc["delim-first<-delim-delim"] = vx_data_textblock::t_delim_first_from_delim_delim;
      mapfunc["delim-first<-string-delimlist"] = vx_data_textblock::t_delim_first_from_string_delimlist;
      mapfunc["delim-pos<-string-delim"] = vx_data_textblock::t_delim_pos_from_string_delim;
      mapfunc["delimlist-pos<-string-delimlist"] = vx_data_textblock::t_delimlist_pos_from_string_delimlist;
      mapfunc["is-close"] = vx_data_textblock::t_is_close;
      mapfunc["is-single"] = vx_data_textblock::t_is_single;
      mapfunc["stringlist<-textblocklist"] = vx_data_textblock::t_stringlist_from_textblocklist;
      mapfunc["text<-textblock"] = vx_data_textblock::t_text_from_textblock;
      mapfunc["textblock-addchild<-textblock-find-child"] = vx_data_textblock::t_textblock_addchild_from_textblock_find_child;
      mapfunc["textblock-delimnotfound"] = vx_data_textblock::t_textblock_delimnotfound;
      mapfunc["textblock-findparent<-textblock"] = vx_data_textblock::t_textblock_findparent_from_textblock;
      mapfunc["textblock-groupby<-textblock-delim"] = vx_data_textblock::t_textblock_groupby_from_textblock_delim;
      mapfunc["textblock-init"] = vx_data_textblock::t_textblock_init;
      mapfunc["textblock-parse"] = vx_data_textblock::t_textblock_parse;
      mapfunc["textblock-parse-one"] = vx_data_textblock::t_textblock_parse_one;
      mapfunc["textblock-parse<-string-delim"] = vx_data_textblock::t_textblock_parse_from_string_delim;
      mapfunc["textblock-replace<-textblock-find-replace"] = vx_data_textblock::t_textblock_replace_from_textblock_find_replace;
      mapfunc["textblock-startleft<-string-delim-offset"] = vx_data_textblock::t_textblock_startleft_from_string_delim_offset;
      mapfunc["textblock-startright<-string-delim-offset"] = vx_data_textblock::t_textblock_startright_from_string_delim_offset;
      mapfunc["textblock<-close-textblock"] = vx_data_textblock::t_textblock_from_close_textblock;
      mapfunc["textblock<-empty-textblock"] = vx_data_textblock::t_textblock_from_empty_textblock;
      mapfunc["textblock<-open-textblock"] = vx_data_textblock::t_textblock_from_open_textblock;
      mapfunc["textblock<-single-textblock"] = vx_data_textblock::t_textblock_from_single_textblock;
      mapfunc["textblock<-string-delim"] = vx_data_textblock::t_textblock_from_string_delim;
      mapfunc["textblock<-textblock-delim"] = vx_data_textblock::t_textblock_from_textblock_delim;
      mapfunc["textblocklist<-textblocklist-remove"] = vx_data_textblock::t_textblocklist_from_textblocklist_remove;
      vx_core::vx_global_package_set("vx/data/textblock", maptype, mapconst, mapfunc);
	   }
  // }

}
