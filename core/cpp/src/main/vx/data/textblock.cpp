#include <map>
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
        this->vx_p_startpos,
        this->vx_p_endpos,
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

    // startpos()
    vx_core::Type_int Class_delim::startpos() const {
      vx_core::Type_int output = this->vx_p_startpos;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // endpos()
    vx_core::Type_int Class_delim::endpos() const {
      vx_core::Type_int output = this->vx_p_endpos;
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
      } else if (skey == ":startpos") {
        output = this->startpos();
      } else if (skey == ":endpos") {
        output = this->endpos();
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
      output[":startpos"] = this->startpos();
      output[":endpos"] = this->endpos();
      output[":delimlist"] = this->delimlist();
      return output;
    }

    vx_core::Type_any Class_delim::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_delim, vals);
    }

    vx_core::Type_any Class_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
      vx_data_textblock::Type_delim val = vx_core::vx_any_from_any(vx_data_textblock::t_delim, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_starttext = val->starttext();
      vx_core::Type_string vx_p_endtext = val->endtext();
      vx_core::Type_int vx_p_startpos = val->startpos();
      vx_core::Type_int vx_p_endpos = val->endpos();
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
          } else if (testkey == ":startpos") {
            key = testkey;
          } else if (testkey == ":endpos") {
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
            if (valsubtype == vx_core::t_string) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":starttext") {
            if (valsubtype == vx_core::t_string) {
              vx_p_starttext = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :starttext " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":endtext") {
            if (valsubtype == vx_core::t_string) {
              vx_p_endtext = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :endtext " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":startpos") {
            if (valsubtype == vx_core::t_int) {
              vx_p_startpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :startpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":endpos") {
            if (valsubtype == vx_core::t_int) {
              vx_p_endpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delim :endpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":delimlist") {
            if (valsubtype == vx_data_textblock::t_delimlist) {
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
      if (output->vx_p_delimlist != vx_p_delimlist) {
        if (output->vx_p_delimlist) {
          vx_core::vx_release_one(output->vx_p_delimlist);
        }
        output->vx_p_delimlist = vx_p_delimlist;
        vx_core::vx_reserve(vx_p_delimlist);
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
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
      vx_data_textblock::Type_delimlist val = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_textblock::Type_delim> listval = val->vx_listdelim();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_delim) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_textblock::t_delim)) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub));
        } else if (valsubtype == vx_data_textblock::t_delimlist) {
          vx_data_textblock::Type_delimlist multi = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdelim());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new delimlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if ((listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
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
      output[":parent"] = this->parent();
      output[":children"] = this->children();
      return output;
    }

    vx_core::Type_any Class_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_textblock::e_textblock, vals);
    }

    vx_core::Type_any Class_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
      vx_data_textblock::Type_textblock val = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_text = val->text();
      vx_core::Type_int vx_p_startpos = val->startpos();
      vx_core::Type_int vx_p_endpos = val->endpos();
      vx_core::Type_int vx_p_curpos = val->curpos();
      vx_core::Type_int vx_p_line = val->line();
      vx_core::Type_int vx_p_column = val->column();
      vx_data_textblock::Type_delim vx_p_delim = val->delim();
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
            if (valsubtype == vx_core::t_string) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":startpos") {
            if (valsubtype == vx_core::t_int) {
              vx_p_startpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :startpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":endpos") {
            if (valsubtype == vx_core::t_int) {
              vx_p_endpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :endpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":curpos") {
            if (valsubtype == vx_core::t_int) {
              vx_p_curpos = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :curpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":line") {
            if (valsubtype == vx_core::t_int) {
              vx_p_line = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :line " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":column") {
            if (valsubtype == vx_core::t_int) {
              vx_p_column = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :column " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":delim") {
            if (valsubtype == vx_data_textblock::t_delim) {
              vx_p_delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :delim " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":parent") {
            if (valsubtype == vx_data_textblock::t_textblock) {
              vx_p_parent = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblock :parent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":children") {
            if (valsubtype == vx_data_textblock::t_textblocklist) {
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
      vx_data_textblock::Type_textblocklist val = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_textblock::Type_textblock> listval = val->vx_listtextblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_textblock::t_textblock) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_textblock::t_textblock)) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_textblock::t_textblock, valsub));
        } else if (valsubtype == vx_data_textblock::t_textblocklist) {
          vx_data_textblock::Type_textblocklist multi = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtextblock());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new textblocklist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if ((listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
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

  //}

  // (const delimbracketangle)
  // class Class_delimbracketangle {

    // vx_const_new()
    void vx_data_textblock::Class_delimbracketangle::vx_const_new(vx_data_textblock::Const_delimbracketangle output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimbracketangle::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketangle", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimbracketcurly)
  // class Class_delimbracketcurly {

    // vx_const_new()
    void vx_data_textblock::Class_delimbracketcurly::vx_const_new(vx_data_textblock::Const_delimbracketcurly output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimbracketcurly::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketcurly", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimbracketsquare)
  // class Class_delimbracketsquare {

    // vx_const_new()
    void vx_data_textblock::Class_delimbracketsquare::vx_const_new(vx_data_textblock::Const_delimbracketsquare output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimbracketsquare::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketsquare", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimclose)
  // class Class_delimclose {

    // vx_const_new()
    void vx_data_textblock::Class_delimclose::vx_const_new(vx_data_textblock::Const_delimclose output) {
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimclose"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(""),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimclose::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimclose", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimcomma)
  // class Class_delimcomma {

    // vx_const_new()
    void vx_data_textblock::Class_delimcomma::vx_const_new(vx_data_textblock::Const_delimcomma output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimcomma::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomma", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimcomment)
  // class Class_delimcomment {

    // vx_const_new()
    void vx_data_textblock::Class_delimcomment::vx_const_new(vx_data_textblock::Const_delimcomment output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimcomment::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomment", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimcommentblock)
  // class Class_delimcommentblock {

    // vx_const_new()
    void vx_data_textblock::Class_delimcommentblock::vx_const_new(vx_data_textblock::Const_delimcommentblock output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimcommentblock::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimcommentblock", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimline)
  // class Class_delimline {

    // vx_const_new()
    void vx_data_textblock::Class_delimline::vx_const_new(vx_data_textblock::Const_delimline output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimline::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimline", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimnonwhitespace)
  // class Class_delimnonwhitespace {

    // vx_const_new()
    void vx_data_textblock::Class_delimnonwhitespace::vx_const_new(vx_data_textblock::Const_delimnonwhitespace output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimnonwhitespace::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimnonwhitespace", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimparen)
  // class Class_delimparen {

    // vx_const_new()
    void vx_data_textblock::Class_delimparen::vx_const_new(vx_data_textblock::Const_delimparen output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimparen::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimparen", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimquote)
  // class Class_delimquote {

    // vx_const_new()
    void vx_data_textblock::Class_delimquote::vx_const_new(vx_data_textblock::Const_delimquote output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimquote::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimquote", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimquoteblock)
  // class Class_delimquoteblock {

    // vx_const_new()
    void vx_data_textblock::Class_delimquoteblock::vx_const_new(vx_data_textblock::Const_delimquoteblock output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimquoteblock::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimquoteblock", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimspace)
  // class Class_delimspace {

    // vx_const_new()
    void vx_data_textblock::Class_delimspace::vx_const_new(vx_data_textblock::Const_delimspace output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimspace::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimspace", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimtext)
  // class Class_delimtext {

    // vx_const_new()
    void vx_data_textblock::Class_delimtext::vx_const_new(vx_data_textblock::Const_delimtext output) {
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
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimtext::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimtext", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
    }


  //}

  // (const delimwhitespace)
  // class Class_delimwhitespace {

    // vx_const_new()
    void vx_data_textblock::Class_delimwhitespace::vx_const_new(vx_data_textblock::Const_delimwhitespace output) {
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimwhitespace"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string(":whitespace"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string(":nonwhitespace")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_startpos = val->startpos();
      vx_core::vx_reserve(output->vx_p_startpos);
      output->vx_p_endpos = val->endpos();
      vx_core::vx_reserve(output->vx_p_endpos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_textblock::Class_delimwhitespace::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/textblock", // pkgname
        "delimwhitespace", // name
        vx_core::Class_typedef::vx_typedef_new(
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
            "startpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "endpos", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "delimlist", // name
            vx_data_textblock::t_delimlist // type
          )
        }) // properties
        )
      );
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

  // (func delim-close<-delim)
  vx_data_textblock::Type_delim f_delim_close_from_delim(vx_data_textblock::Type_delim delim) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve(delim);
    output = vx_core::f_let(
      vx_data_textblock::t_delim,
      vx_core::t_any_from_func->vx_fn_new({delim}, [delim]() {
        vx_data_textblock::Type_delimlist delimlist = delim->delimlist();
        vx_core::vx_ref_plus(delimlist);
        vx_core::Type_string endtext = delim->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_delimlist addlist = vx_core::f_if_2(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({endtext}, [endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(""), endtext);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delimlist}, [delimlist]() {
                vx_core::Type_any output_1 = delimlist;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delimlist, endtext}, [delimlist, endtext]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_delimlist,
                  delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimclose,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":starttext"),
                        endtext
                      })
                    )
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(addlist);
        vx_data_textblock::Type_delim output_1 = vx_core::f_if_2(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({addlist}, [addlist]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(addlist);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim}, [delim]() {
                vx_core::Type_any output_1 = delim;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delim, addlist}, [delim, addlist]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    addlist
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimlist, endtext, addlist}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(delim, output);
    return output;
  }

  // (func delim-close<-delim)
  // class Class_delim_close_from_delim {
    Abstract_delim_close_from_delim::~Abstract_delim_close_from_delim() {}

    Class_delim_close_from_delim::Class_delim_close_from_delim() : Abstract_delim_close_from_delim::Abstract_delim_close_from_delim() {
      vx_core::refcount += 1;
    }

    Class_delim_close_from_delim::~Class_delim_close_from_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_close_from_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_close_from_delim output = vx_data_textblock::e_delim_close_from_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_close_from_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_close_from_delim output = vx_data_textblock::e_delim_close_from_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_close_from_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-close<-delim", // name
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

    vx_core::Type_funcdef Class_delim_close_from_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-close<-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_close_from_delim::vx_empty() const {return vx_data_textblock::e_delim_close_from_delim;}
    vx_core::Type_any Class_delim_close_from_delim::vx_type() const {return vx_data_textblock::t_delim_close_from_delim;}
    vx_core::Type_msgblock Class_delim_close_from_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_close_from_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_delim_close_from_delim::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_delim_close_from_delim::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim inputval = vx_core::vx_any_from_any(vx_data_textblock::t_delim, val);
      output = vx_data_textblock::f_delim_close_from_delim(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_delim_close_from_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_delim_close_from_delim(delim);
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
        vx_core::Type_int pos1 = delim1->startpos();
        vx_core::vx_ref_plus(pos1);
        vx_core::Type_int pos2 = delim2->startpos();
        vx_core::vx_ref_plus(pos2);
        vx_data_textblock::Type_delim output_1 = vx_core::f_if_2(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos2}, [pos2]() {
                vx_core::Type_boolean output_1 = vx_core::f_lt(pos2, vx_core::vx_new_int(0));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delim1}, [delim1]() {
                vx_core::Type_any output_1 = delim1;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({pos1}, [pos1]() {
                vx_core::Type_boolean output_1 = vx_core::f_lt(pos1, vx_core::vx_new_int(0));
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

  // (func delim-first<-string-delimlist-offset)
  vx_data_textblock::Type_delim f_delim_first_from_string_delimlist_offset(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist, vx_core::Type_int start) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve({text, delimlist, start});
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
          vx_core::t_any_from_func->vx_fn_new({text, delimlist, start}, [text, delimlist, start]() {
            vx_data_textblock::Type_delim output_1 = vx_core::f_let(
              vx_data_textblock::t_delim,
              vx_core::t_any_from_func->vx_fn_new({text, delimlist, start}, [text, delimlist, start]() {
                vx_data_textblock::Type_delimlist resolvedlist = vx_data_textblock::f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start);
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
    vx_core::vx_release_one_except({text, delimlist, start}, output);
    return output;
  }

  // (func delim-first<-string-delimlist-offset)
  // class Class_delim_first_from_string_delimlist_offset {
    Abstract_delim_first_from_string_delimlist_offset::~Abstract_delim_first_from_string_delimlist_offset() {}

    Class_delim_first_from_string_delimlist_offset::Class_delim_first_from_string_delimlist_offset() : Abstract_delim_first_from_string_delimlist_offset::Abstract_delim_first_from_string_delimlist_offset() {
      vx_core::refcount += 1;
    }

    Class_delim_first_from_string_delimlist_offset::~Class_delim_first_from_string_delimlist_offset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist_offset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_string_delimlist_offset output = vx_data_textblock::e_delim_first_from_string_delimlist_offset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist_offset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_first_from_string_delimlist_offset output = vx_data_textblock::e_delim_first_from_string_delimlist_offset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_first_from_string_delimlist_offset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist-offset", // name
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

    vx_core::Type_funcdef Class_delim_first_from_string_delimlist_offset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist-offset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_first_from_string_delimlist_offset::vx_empty() const {return vx_data_textblock::e_delim_first_from_string_delimlist_offset;}
    vx_core::Type_any Class_delim_first_from_string_delimlist_offset::vx_type() const {return vx_data_textblock::t_delim_first_from_string_delimlist_offset;}
    vx_core::Type_msgblock Class_delim_first_from_string_delimlist_offset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_first_from_string_delimlist_offset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delim_first_from_string_delimlist_offset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delimlist delimlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_delim_first_from_string_delimlist_offset(text, delimlist, start);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delim-pos<-string-delim-offset)
  vx_data_textblock::Type_delim f_delim_pos_from_string_delim_offset(vx_core::Type_string text, vx_data_textblock::Type_delim delim, vx_core::Type_int start) {
    vx_data_textblock::Type_delim output = vx_data_textblock::e_delim;
    vx_core::vx_reserve({text, delim, start});
    output = vx_core::f_let(
      vx_data_textblock::t_delim,
      vx_core::t_any_from_func->vx_fn_new({delim, text, start}, [delim, text, start]() {
        vx_core::Type_string find = delim->starttext();
        vx_core::vx_ref_plus(find);
        vx_core::Type_string work = vx_type::f_string_from_string_start(text, start);
        vx_core::vx_ref_plus(work);
        vx_core::Type_int pos = vx_type::f_int_from_string_findkeyword(work, find);
        vx_core::vx_ref_plus(pos);
        vx_data_textblock::Type_delim output_1 = vx_core::f_if_1(
          vx_data_textblock::t_delim,
          vx_core::f_eq(pos, vx_core::vx_new_int(-1)),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(-1)
            })
          ),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::f_plus(pos, start)
            })
          )
        );
        vx_core::vx_release_one_except({find, work, pos}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delim, start}, output);
    return output;
  }

  // (func delim-pos<-string-delim-offset)
  // class Class_delim_pos_from_string_delim_offset {
    Abstract_delim_pos_from_string_delim_offset::~Abstract_delim_pos_from_string_delim_offset() {}

    Class_delim_pos_from_string_delim_offset::Class_delim_pos_from_string_delim_offset() : Abstract_delim_pos_from_string_delim_offset::Abstract_delim_pos_from_string_delim_offset() {
      vx_core::refcount += 1;
    }

    Class_delim_pos_from_string_delim_offset::~Class_delim_pos_from_string_delim_offset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delim_pos_from_string_delim_offset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_pos_from_string_delim_offset output = vx_data_textblock::e_delim_pos_from_string_delim_offset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delim_pos_from_string_delim_offset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delim_pos_from_string_delim_offset output = vx_data_textblock::e_delim_pos_from_string_delim_offset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delim_pos_from_string_delim_offset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim-offset", // name
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

    vx_core::Type_funcdef Class_delim_pos_from_string_delim_offset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim-offset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delim_pos_from_string_delim_offset::vx_empty() const {return vx_data_textblock::e_delim_pos_from_string_delim_offset;}
    vx_core::Type_any Class_delim_pos_from_string_delim_offset::vx_type() const {return vx_data_textblock::t_delim_pos_from_string_delim_offset;}
    vx_core::Type_msgblock Class_delim_pos_from_string_delim_offset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delim_pos_from_string_delim_offset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delim_pos_from_string_delim_offset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_delim_pos_from_string_delim_offset(text, delim, start);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func delimlist-pos<-string-delimlist-offset)
  vx_data_textblock::Type_delimlist f_delimlist_pos_from_string_delimlist_offset(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist, vx_core::Type_int start) {
    vx_data_textblock::Type_delimlist output = vx_data_textblock::e_delimlist;
    vx_core::vx_reserve({text, delimlist, start});
    output = vx_core::f_list_from_list(
      vx_data_textblock::t_delimlist,
      delimlist,
      vx_core::t_any_from_any->vx_fn_new({text, start}, [text, start](vx_core::Type_any delim_any) {
        vx_data_textblock::Type_delim delim = vx_core::vx_any_from_any(vx_data_textblock::t_delim, delim_any);
        vx_core::Type_any output_1 = 
          vx_data_textblock::f_delim_pos_from_string_delim_offset(text, delim, start);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({text, delimlist, start}, output);
    return output;
  }

  // (func delimlist-pos<-string-delimlist-offset)
  // class Class_delimlist_pos_from_string_delimlist_offset {
    Abstract_delimlist_pos_from_string_delimlist_offset::~Abstract_delimlist_pos_from_string_delimlist_offset() {}

    Class_delimlist_pos_from_string_delimlist_offset::Class_delimlist_pos_from_string_delimlist_offset() : Abstract_delimlist_pos_from_string_delimlist_offset::Abstract_delimlist_pos_from_string_delimlist_offset() {
      vx_core::refcount += 1;
    }

    Class_delimlist_pos_from_string_delimlist_offset::~Class_delimlist_pos_from_string_delimlist_offset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist_offset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delimlist_pos_from_string_delimlist_offset output = vx_data_textblock::e_delimlist_pos_from_string_delimlist_offset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist_offset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_delimlist_pos_from_string_delimlist_offset output = vx_data_textblock::e_delimlist_pos_from_string_delimlist_offset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_delimlist_pos_from_string_delimlist_offset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist-offset", // name
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

    vx_core::Type_funcdef Class_delimlist_pos_from_string_delimlist_offset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist-offset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist_offset::vx_empty() const {return vx_data_textblock::e_delimlist_pos_from_string_delimlist_offset;}
    vx_core::Type_any Class_delimlist_pos_from_string_delimlist_offset::vx_type() const {return vx_data_textblock::t_delimlist_pos_from_string_delimlist_offset;}
    vx_core::Type_msgblock Class_delimlist_pos_from_string_delimlist_offset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_delimlist_pos_from_string_delimlist_offset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_delimlist_pos_from_string_delimlist_offset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delimlist delimlist = vx_core::vx_any_from_any(vx_data_textblock::t_delimlist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_textblock::f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start);
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

  // (func textblock-addchild<-textblock-child)
  vx_data_textblock::Type_textblock f_textblock_addchild_from_textblock_child(vx_data_textblock::Type_textblock textblockarg, vx_data_textblock::Type_textblock child) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockarg, child});
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg, child}, [textblockarg, child]() {
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
              vx_core::t_boolean_from_func->vx_fn_new({starttext, endtext}, [starttext, endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_and(
                  vx_core::f_eq(starttext, vx_core::vx_new_string("")),
                  vx_core::f_eq(endtext, vx_core::vx_new_string(""))
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockarg, children, child}, [textblockarg, children, child]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":children"),
                    vx_core::f_copy(vx_data_textblock::t_textblocklist, children, vx_core::vx_new(vx_core::t_anylist, {
                      child}))
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({textblockarg, parent, child}, [textblockarg, parent, child]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":parent"),
                    vx_data_textblock::f_textblock_addchild_from_textblock_child(parent, child)
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimcurr, parent, children, starttext, endtext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({textblockarg, child}, output);
    return output;
  }

  // (func textblock-addchild<-textblock-child)
  // class Class_textblock_addchild_from_textblock_child {
    Abstract_textblock_addchild_from_textblock_child::~Abstract_textblock_addchild_from_textblock_child() {}

    Class_textblock_addchild_from_textblock_child::Class_textblock_addchild_from_textblock_child() : Abstract_textblock_addchild_from_textblock_child::Abstract_textblock_addchild_from_textblock_child() {
      vx_core::refcount += 1;
    }

    Class_textblock_addchild_from_textblock_child::~Class_textblock_addchild_from_textblock_child() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_child::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_addchild_from_textblock_child output = vx_data_textblock::e_textblock_addchild_from_textblock_child;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_child::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_addchild_from_textblock_child output = vx_data_textblock::e_textblock_addchild_from_textblock_child;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_addchild_from_textblock_child::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-child", // name
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

    vx_core::Type_funcdef Class_textblock_addchild_from_textblock_child::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-child", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_addchild_from_textblock_child::vx_empty() const {return vx_data_textblock::e_textblock_addchild_from_textblock_child;}
    vx_core::Type_any Class_textblock_addchild_from_textblock_child::vx_type() const {return vx_data_textblock::t_textblock_addchild_from_textblock_child;}
    vx_core::Type_msgblock Class_textblock_addchild_from_textblock_child::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_addchild_from_textblock_child::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_addchild_from_textblock_child::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock child = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_addchild_from_textblock_child(textblockarg, child);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-delimnotfound)
  vx_data_textblock::Type_textblock f_textblock_delimnotfound(vx_data_textblock::Type_textblock textblockin) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockin);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
        vx_data_textblock::Type_delim delimin = textblockin->delim();
        vx_core::vx_ref_plus(delimin);
        vx_core::Type_string endtext = delimin->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_textblock parent = textblockin->parent();
        vx_core::vx_ref_plus(parent);
        vx_data_textblock::Type_delim delimp = parent->delim();
        vx_core::vx_ref_plus(delimp);
        vx_data_textblock::Type_delimlist delims = delimp->delimlist();
        vx_core::vx_ref_plus(delims);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({endtext}, [endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), endtext);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({parent, delims, textblockin, delimin}, [parent, delims, textblockin, delimin]() {
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
                          textblockin,
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
                                  delimin->name()
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
                vx_core::Type_boolean output_1 = vx_core::f_eq(
                  parent,
                  vx_core::f_empty(
                    vx_data_textblock::t_textblock
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
                vx_core::Type_any output_1 = textblockin;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_pop(textblockin);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimin, endtext, parent, delimp, delims}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockin, output);
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
      vx_data_textblock::Type_textblock textblockin = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_delimnotfound(textblockin);
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
  vx_data_textblock::Type_textblock f_textblock_parse_one(vx_data_textblock::Type_textblock textblockin) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockin);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
        vx_data_textblock::Type_delim delimin = textblockin->delim();
        vx_core::vx_ref_plus(delimin);
        vx_core::Type_int startpos = textblockin->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int curpos = textblockin->curpos();
        vx_core::vx_ref_plus(curpos);
        vx_core::Type_string textin = textblockin->text();
        vx_core::vx_ref_plus(textin);
        vx_data_textblock::Type_textblock parent = textblockin->parent();
        vx_core::vx_ref_plus(parent);
        vx_data_textblock::Type_textblock tbchg = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          textblockin,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":endpos"),
            vx_core::f_plus(
              startpos,
              vx_type::f_length_from_string(textin)
            )
          })
        );
        vx_core::vx_ref_plus(tbchg);
        vx_core::Type_string starttext = delimin->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimin->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_delimlist delimlistin = delimin->delimlist();
        vx_core::vx_ref_plus(delimlistin);
        vx_data_textblock::Type_delim delimfirst = vx_data_textblock::f_delim_first_from_string_delimlist_offset(textin, delimlistin, curpos);
        vx_core::vx_ref_plus(delimfirst);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({starttext, endtext}, [starttext, endtext]() {
                vx_core::Type_boolean output_1 = vx_core::f_and(
                  vx_core::f_ne(vx_core::vx_new_string(""), starttext),
                  vx_core::f_eq(vx_core::vx_new_string(""), endtext)
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({tbchg}, [tbchg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_push(tbchg);
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimlistin}, [delimlistin]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(
                  delimlistin,
                  vx_core::f_empty(
                    vx_data_textblock::t_delimlist
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({parent, tbchg}, [parent, tbchg]() {
                vx_data_textblock::Type_textblock output_1 = vx_core::f_if_2(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({parent}, [parent]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq(
                          parent,
                          vx_core::f_empty(
                            vx_data_textblock::t_textblock
                          )
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({tbchg}, [tbchg]() {
                        vx_core::Type_any output_1 = tbchg;
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({tbchg}, [tbchg]() {
                        vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_pop(tbchg);
                        return output_1;
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimfirst}, [delimfirst]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(
                  delimfirst,
                  vx_core::f_empty(
                    vx_data_textblock::t_delim
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({tbchg}, [tbchg]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_delimnotfound(tbchg);
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimfirst}, [delimfirst]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(
                  delimfirst->name(),
                  vx_core::f_any_from_struct(
                    vx_core::t_string,
                    vx_data_textblock::c_delimclose,
                    vx_core::vx_new_string(":name")
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({tbchg, delimfirst}, [tbchg, delimfirst]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_pop_from_textblock_delim(tbchg, delimfirst);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({tbchg, delimfirst}, [tbchg, delimfirst]() {
                vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_push_from_textblock_delim(tbchg, delimfirst);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delimin, startpos, curpos, textin, parent, tbchg, starttext, endtext, delimlistin, delimfirst}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockin, output);
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
      vx_data_textblock::Type_textblock textblockin = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_parse_one(textblockin);
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

  // (func textblock-pop)
  vx_data_textblock::Type_textblock f_textblock_pop(vx_data_textblock::Type_textblock textblockarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockarg);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
        vx_data_textblock::Type_textblock parent = textblockarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_string text = textblockarg->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_int startpos = textblockarg->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_int endpos = vx_core::f_plus(
          startpos,
          vx_type::f_length_from_string(text)
        );
        vx_core::vx_ref_plus(endpos);
        vx_data_textblock::Type_delim delimpar = parent->delim();
        vx_core::vx_ref_plus(delimpar);
        vx_data_textblock::Type_textblock child = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          textblockarg,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":endpos"),
            endpos,
            vx_core::vx_new_string(":delim"),
            vx_core::f_empty(
              vx_data_textblock::t_delim
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_empty(
              vx_data_textblock::t_textblock
            )
          })
        );
        vx_core::vx_ref_plus(child);
        vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_addchild_from_textblock_child(parent, child);
        vx_core::vx_release_one_except({parent, text, startpos, endpos, delimpar, child}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockarg, output);
    return output;
  }

  // (func textblock-pop)
  // class Class_textblock_pop {
    Abstract_textblock_pop::~Abstract_textblock_pop() {}

    Class_textblock_pop::Class_textblock_pop() : Abstract_textblock_pop::Abstract_textblock_pop() {
      vx_core::refcount += 1;
    }

    Class_textblock_pop::~Class_textblock_pop() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_pop::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_pop output = vx_data_textblock::e_textblock_pop;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_pop::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_pop output = vx_data_textblock::e_textblock_pop;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_pop::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop", // name
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

    vx_core::Type_funcdef Class_textblock_pop::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_pop::vx_empty() const {return vx_data_textblock::e_textblock_pop;}
    vx_core::Type_any Class_textblock_pop::vx_type() const {return vx_data_textblock::t_textblock_pop;}
    vx_core::Type_msgblock Class_textblock_pop::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_pop::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_pop::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_pop::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_pop(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_pop::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_pop(textblockarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-pop<-textblock-delim)
  vx_data_textblock::Type_textblock f_textblock_pop_from_textblock_delim(vx_data_textblock::Type_textblock textblockarg, vx_data_textblock::Type_delim delimarg) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockarg, delimarg});
    output = vx_core::f_if_2(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({delimarg}, [delimarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delimarg);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({textblockarg}, [textblockarg]() {
            vx_core::Type_any output_1 = textblockarg;
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({delimarg}, [delimarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_eq(
              delimarg->name(),
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new_string(":name")
              )
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({textblockarg, delimarg}, [textblockarg, delimarg]() {
            vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
              vx_data_textblock::t_textblock,
              vx_core::t_any_from_func->vx_fn_new({textblockarg, delimarg}, [textblockarg, delimarg]() {
                vx_data_textblock::Type_textblock parentcur = textblockarg->parent();
                vx_core::vx_ref_plus(parentcur);
                vx_data_textblock::Type_textblocklist childrenpar = parentcur->children();
                vx_core::vx_ref_plus(childrenpar);
                vx_data_textblock::Type_delim delimcur = textblockarg->delim();
                vx_core::vx_ref_plus(delimcur);
                vx_core::Type_string starttext = delimcur->starttext();
                vx_core::vx_ref_plus(starttext);
                vx_core::Type_string endtext = delimcur->endtext();
                vx_core::vx_ref_plus(endtext);
                vx_core::Type_int delimpos = delimarg->startpos();
                vx_core::vx_ref_plus(delimpos);
                vx_core::Type_int startpos = textblockarg->startpos();
                vx_core::vx_ref_plus(startpos);
                vx_core::Type_int startsub = vx_type::f_length_from_string(starttext);
                vx_core::vx_ref_plus(startsub);
                vx_core::Type_int endpos = vx_core::f_plus(
                  delimpos,
                  vx_type::f_length_from_string(endtext)
                );
                vx_core::vx_ref_plus(endpos);
                vx_core::Type_int endsub = delimpos;
                vx_core::vx_ref_plus(endsub);
                vx_core::Type_string textcur = textblockarg->text();
                vx_core::vx_ref_plus(textcur);
                vx_data_textblock::Type_textblocklist childrencur = textblockarg->children();
                vx_core::vx_ref_plus(childrencur);
                vx_core::Type_string textout = vx_type::f_string_from_string_start(textcur, endpos);
                vx_core::vx_ref_plus(textout);
                vx_core::Type_string textsub = vx_type::f_string_from_string_start_end(textcur, startsub, endsub);
                vx_core::vx_ref_plus(textsub);
                vx_core::Type_string textdelim = vx_type::f_string_from_string_start_end(textcur, vx_core::vx_new_int(0), endpos);
                vx_core::vx_ref_plus(textdelim);
                vx_data_textblock::Type_textblock childchg = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    textdelim,
                    vx_core::vx_new_string(":endpos"),
                    vx_core::f_plus(startpos, endpos),
                    vx_core::vx_new_string(":curpos"),
                    vx_core::vx_new_int(0),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      delimcur,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":endpos"),
                        vx_core::f_plus(startpos, delimpos),
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_empty(
                          vx_data_textblock::t_delimlist
                        )
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_empty(
                      vx_data_textblock::t_textblock
                    ),
                    vx_core::vx_new_string(":children"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblocklist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            textsub,
                            vx_core::vx_new_string(":startpos"),
                            vx_core::f_plus(startpos, startsub),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::f_plus(startpos, endsub),
                            vx_core::vx_new_string(":curpos"),
                            vx_core::vx_new_int(0)
                          })
                        )
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(childchg);
                vx_data_textblock::Type_textblock parentchg = vx_data_textblock::f_textblock_addchild_from_textblock_child(parentcur, childchg);
                vx_core::vx_ref_plus(parentchg);
                vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    textout,
                    vx_core::vx_new_string(":startpos"),
                    vx_core::f_plus1(endpos),
                    vx_core::vx_new_string(":parent"),
                    parentchg
                  })
                );
                vx_core::vx_release_one_except({parentcur, childrenpar, delimcur, starttext, endtext, delimpos, startpos, startsub, endpos, endsub, textcur, childrencur, textout, textsub, textdelim, childchg, parentchg}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({textblockarg, delimarg}, [textblockarg, delimarg]() {
            vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
              vx_data_textblock::t_textblock,
              vx_core::t_any_from_func->vx_fn_new({textblockarg, delimarg}, [textblockarg, delimarg]() {
                vx_data_textblock::Type_textblock parentcur = textblockarg->parent();
                vx_core::vx_ref_plus(parentcur);
                vx_data_textblock::Type_textblocklist childrenpar = parentcur->children();
                vx_core::vx_ref_plus(childrenpar);
                vx_data_textblock::Type_textblock childchg = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  textblockarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delim"),
                    delimarg,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_empty(
                      vx_data_textblock::t_textblock
                    )
                  })
                );
                vx_core::vx_ref_plus(childchg);
                vx_data_textblock::Type_textblocklist childrenchg = vx_core::f_copy(vx_data_textblock::t_textblocklist, childrenpar, vx_core::vx_new(vx_core::t_anylist, {
                childchg}));
                vx_core::vx_ref_plus(childrenchg);
                vx_data_textblock::Type_textblock output_1 = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  parentcur,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":children"),
                    childrenchg
                  })
                );
                vx_core::vx_release_one_except({parentcur, childrenpar, childchg, childrenchg}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({textblockarg, delimarg}, output);
    return output;
  }

  // (func textblock-pop<-textblock-delim)
  // class Class_textblock_pop_from_textblock_delim {
    Abstract_textblock_pop_from_textblock_delim::~Abstract_textblock_pop_from_textblock_delim() {}

    Class_textblock_pop_from_textblock_delim::Class_textblock_pop_from_textblock_delim() : Abstract_textblock_pop_from_textblock_delim::Abstract_textblock_pop_from_textblock_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_pop_from_textblock_delim::~Class_textblock_pop_from_textblock_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_pop_from_textblock_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_pop_from_textblock_delim output = vx_data_textblock::e_textblock_pop_from_textblock_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_pop_from_textblock_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_pop_from_textblock_delim output = vx_data_textblock::e_textblock_pop_from_textblock_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_pop_from_textblock_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop<-textblock-delim", // name
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

    vx_core::Type_funcdef Class_textblock_pop_from_textblock_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop<-textblock-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_pop_from_textblock_delim::vx_empty() const {return vx_data_textblock::e_textblock_pop_from_textblock_delim;}
    vx_core::Type_any Class_textblock_pop_from_textblock_delim::vx_type() const {return vx_data_textblock::t_textblock_pop_from_textblock_delim;}
    vx_core::Type_msgblock Class_textblock_pop_from_textblock_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_pop_from_textblock_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_pop_from_textblock_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delimarg = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_pop_from_textblock_delim(textblockarg, delimarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-push)
  vx_data_textblock::Type_textblock f_textblock_push(vx_data_textblock::Type_textblock textblockin) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(textblockin);
    output = vx_core::f_let(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
        vx_core::Type_string text = textblockin->text();
        vx_core::vx_ref_plus(text);
        vx_data_textblock::Type_delim delimcur = textblockin->delim();
        vx_core::vx_ref_plus(delimcur);
        vx_core::Type_int offset = textblockin->startpos();
        vx_core::vx_ref_plus(offset);
        vx_core::Type_string starttext = delimcur->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimcur->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_core::Type_boolean issingle = vx_core::f_and(
          vx_core::f_ne(vx_core::vx_new_string(""), starttext),
          vx_core::f_eq(vx_core::vx_new_string(""), endtext)
        );
        vx_core::vx_ref_plus(issingle);
        vx_core::Type_int curpos = textblockin->curpos();
        vx_core::vx_ref_plus(curpos);
        vx_data_textblock::Type_delim delimsplit = vx_core::f_if_1(
          vx_data_textblock::t_delim,
          issingle,
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            delimcur,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_empty(
                vx_data_textblock::t_delimlist
              )
            })
          ),
          delimcur
        );
        vx_core::vx_ref_plus(delimsplit);
        vx_data_textblock::Type_delim delimchg = vx_core::f_if_1(
          vx_data_textblock::t_delim,
          issingle,
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            delimsplit,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(0)
            })
          ),
          delimsplit
        );
        vx_core::vx_ref_plus(delimchg);
        vx_data_textblock::Type_textblock tbleft = vx_data_textblock::f_textblock_startleft_from_string_delim_offset(text, delimsplit, offset);
        vx_core::vx_ref_plus(tbleft);
        vx_data_textblock::Type_textblock tbright = vx_data_textblock::f_textblock_startright_from_string_delim_offset(text, delimsplit, offset);
        vx_core::vx_ref_plus(tbright);
        vx_data_textblock::Type_textblock tbchg = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          tbleft,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":delim"),
            delimchg
          })
        );
        vx_core::vx_ref_plus(tbchg);
        vx_data_textblock::Type_textblock parent = textblockin->parent();
        vx_core::vx_ref_plus(parent);
        vx_data_textblock::Type_textblock parentchg = vx_data_textblock::f_textblock_addchild_from_textblock_child(parent, tbchg);
        vx_core::vx_ref_plus(parentchg);
        vx_data_textblock::Type_delim delimright = vx_core::f_if_1(
          vx_data_textblock::t_delim,
          issingle,
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              delimcur->delimlist()
            })
          ),
          vx_core::f_empty(
            vx_data_textblock::t_delim
          )
        );
        vx_core::vx_ref_plus(delimright);
        vx_data_textblock::Type_textblock output_1 = vx_core::f_copy(
          vx_data_textblock::t_textblock,
          tbright,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(0),
            vx_core::vx_new_string(":delim"),
            delimright,
            vx_core::vx_new_string(":parent"),
            parentchg
          })
        );
        vx_core::vx_release_one_except({text, delimcur, offset, starttext, endtext, issingle, curpos, delimsplit, delimchg, tbleft, tbright, tbchg, parent, parentchg, delimright}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblockin, output);
    return output;
  }

  // (func textblock-push)
  // class Class_textblock_push {
    Abstract_textblock_push::~Abstract_textblock_push() {}

    Class_textblock_push::Class_textblock_push() : Abstract_textblock_push::Abstract_textblock_push() {
      vx_core::refcount += 1;
    }

    Class_textblock_push::~Class_textblock_push() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_push::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_push output = vx_data_textblock::e_textblock_push;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_push::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_push output = vx_data_textblock::e_textblock_push;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_push::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-push", // name
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

    vx_core::Type_funcdef Class_textblock_push::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-push", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_push::vx_empty() const {return vx_data_textblock::e_textblock_push;}
    vx_core::Type_any Class_textblock_push::vx_type() const {return vx_data_textblock::t_textblock_push;}
    vx_core::Type_msgblock Class_textblock_push::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_push::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_push::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_push::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_textblock::f_textblock_push(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_push::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockin = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_textblock::f_textblock_push(textblockin);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-push<-textblock-delim)
  vx_data_textblock::Type_textblock f_textblock_push_from_textblock_delim(vx_data_textblock::Type_textblock textblockin, vx_data_textblock::Type_delim delimin) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve({textblockin, delimin});
    output = vx_core::f_if_2(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({delimin}, [delimin]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delimin);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({textblockin}, [textblockin]() {
            vx_data_textblock::Type_textblock output_1 = vx_data_textblock::f_textblock_push(textblockin);
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({textblockin, delimin}, [textblockin, delimin]() {
            vx_data_textblock::Type_textblock output_1 = vx_core::f_let(
              vx_data_textblock::t_textblock,
              vx_core::t_any_from_func->vx_fn_new({textblockin, delimin}, [textblockin, delimin]() {
                vx_core::Type_string text = textblockin->text();
                vx_core::vx_ref_plus(text);
                vx_core::Type_int offset = textblockin->startpos();
                vx_core::vx_ref_plus(offset);
                vx_data_textblock::Type_delim delimcur = textblockin->delim();
                vx_core::vx_ref_plus(delimcur);
                vx_data_textblock::Type_textblock parent = textblockin->parent();
                vx_core::vx_ref_plus(parent);
                vx_core::Type_string starttext = delimin->starttext();
                vx_core::vx_ref_plus(starttext);
                vx_core::Type_string endtext = delimin->endtext();
                vx_core::vx_ref_plus(endtext);
                vx_core::Type_boolean issingle = vx_core::f_and(
                  vx_core::f_ne(vx_core::vx_new_string(""), starttext),
                  vx_core::f_eq(vx_core::vx_new_string(""), endtext)
                );
                vx_core::vx_ref_plus(issingle);
                vx_data_textblock::Type_textblock tbleft = vx_data_textblock::f_textblock_startleft_from_string_delim_offset(text, delimin, offset);
                vx_core::vx_ref_plus(tbleft);
                vx_data_textblock::Type_delimlist delimsr = delimcur->delimlist();
                vx_core::vx_ref_plus(delimsr);
                vx_data_textblock::Type_delim delimr = vx_core::f_if_1(
                  vx_data_textblock::t_delim,
                  issingle,
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    delimin,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      delimsr
                    })
                  ),
                  delimin
                );
                vx_core::vx_ref_plus(delimr);
                vx_data_textblock::Type_textblock tbright = vx_data_textblock::f_textblock_startright_from_string_delim_offset(text, delimr, offset);
                vx_core::vx_ref_plus(tbright);
                vx_data_textblock::Type_textblock tbparent = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  tbright,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_if_1(
                      vx_data_textblock::t_textblock,
                      vx_core::f_is_empty_1(parent),
                      textblockin,
                      parent
                    )
                  })
                );
                vx_core::vx_ref_plus(tbparent);
                vx_data_textblock::Type_delimlist delims = delimin->delimlist();
                vx_core::vx_ref_plus(delims);
                vx_data_textblock::Type_delim delimchg = vx_core::f_if_1(
                  vx_data_textblock::t_delim,
                  vx_core::f_is_empty_1(delims),
                  vx_core::f_empty(
                    vx_data_textblock::t_delim
                  ),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      delims
                    })
                  )
                );
                vx_core::vx_ref_plus(delimchg);
                vx_data_textblock::Type_textblock output_1 = vx_core::f_copy(
                  vx_data_textblock::t_textblock,
                  tbleft,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delim"),
                    delimchg,
                    vx_core::vx_new_string(":parent"),
                    tbparent
                  })
                );
                vx_core::vx_release_one_except({text, offset, delimcur, parent, starttext, endtext, issingle, tbleft, delimsr, delimr, tbright, tbparent, delims, delimchg}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({textblockin, delimin}, output);
    return output;
  }

  // (func textblock-push<-textblock-delim)
  // class Class_textblock_push_from_textblock_delim {
    Abstract_textblock_push_from_textblock_delim::~Abstract_textblock_push_from_textblock_delim() {}

    Class_textblock_push_from_textblock_delim::Class_textblock_push_from_textblock_delim() : Abstract_textblock_push_from_textblock_delim::Abstract_textblock_push_from_textblock_delim() {
      vx_core::refcount += 1;
    }

    Class_textblock_push_from_textblock_delim::~Class_textblock_push_from_textblock_delim() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_push_from_textblock_delim::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_push_from_textblock_delim output = vx_data_textblock::e_textblock_push_from_textblock_delim;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_push_from_textblock_delim::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_textblock::Func_textblock_push_from_textblock_delim output = vx_data_textblock::e_textblock_push_from_textblock_delim;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_push_from_textblock_delim::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/textblock", // pkgname
        "textblock-push<-textblock-delim", // name
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

    vx_core::Type_funcdef Class_textblock_push_from_textblock_delim::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-push<-textblock-delim", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_push_from_textblock_delim::vx_empty() const {return vx_data_textblock::e_textblock_push_from_textblock_delim;}
    vx_core::Type_any Class_textblock_push_from_textblock_delim::vx_type() const {return vx_data_textblock::t_textblock_push_from_textblock_delim;}
    vx_core::Type_msgblock Class_textblock_push_from_textblock_delim::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_push_from_textblock_delim::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_textblock_push_from_textblock_delim::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblockin = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_delim delimin = vx_core::vx_any_from_any(vx_data_textblock::t_delim, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_textblock::f_textblock_push_from_textblock_delim(textblockin, delimin);
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
        vx_core::Type_int startpos = delim->startpos();
        vx_core::vx_ref_plus(startpos);
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
              vx_core::t_any_from_func->vx_fn_new({text, startpos, offset}, [text, startpos, offset]() {
                vx_data_textblock::Type_textblock output_1 = vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_type::f_string_from_string_start_end(text, vx_core::vx_new_int(0), startpos),
                    vx_core::vx_new_string(":startpos"),
                    offset,
                    vx_core::vx_new_string(":endpos"),
                    vx_core::f_plus(offset, startpos),
                    vx_core::vx_new_string(":curpos"),
                    vx_core::vx_new_int(0)
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except(startpos, output_1);
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
        vx_core::Type_int startpos = delimin->startpos();
        vx_core::vx_ref_plus(startpos);
        vx_core::Type_string starttext = delimin->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_core::Type_string endtext = delimin->endtext();
        vx_core::vx_ref_plus(endtext);
        vx_data_textblock::Type_delimlist delimlist = delimin->delimlist();
        vx_core::vx_ref_plus(delimlist);
        vx_data_textblock::Type_delim delimclose = vx_core::f_if_2(
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
                vx_data_textblock::Type_delim output_1 = vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("delimclose"),
                    vx_core::vx_new_string(":starttext"),
                    endtext
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(delimclose);
        vx_data_textblock::Type_delimlist delims = vx_core::f_if_2(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delimclose}, [delimclose]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delimclose);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delimlist}, [delimlist]() {
                vx_core::Type_any output_1 = delimlist;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delimlist, delimclose}, [delimlist, delimclose]() {
                vx_core::Type_any output_1 = vx_core::f_copy(vx_data_textblock::t_delimlist, delimlist, vx_core::vx_new(vx_core::t_anylist, {
                delimclose}));
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(delims);
        vx_core::Type_int delimlen = vx_type::f_length_from_string(starttext);
        vx_core::vx_ref_plus(delimlen);
        vx_core::Type_int curpos = delimlen;
        vx_core::vx_ref_plus(curpos);
        vx_data_textblock::Type_delim delimnew = vx_core::f_if_2(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({delims}, [delims]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(delims);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({delimin}, [delimin]() {
                vx_core::Type_any output_1 = delimin;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({delimin, delims}, [delimin, delims]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  delimin,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    delims
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(delimnew);
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
              vx_core::t_any_from_func->vx_fn_new({text, startpos, offset, curpos, delimnew}, [text, startpos, offset, curpos, delimnew]() {
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
                    delimnew
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({startpos, starttext, endtext, delimlist, delimclose, delims, delimlen, curpos, delimnew}, output_1);
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
  vx_data_textblock::Const_delimcomma c_delimcomma = NULL;
  vx_data_textblock::Const_delimcomment c_delimcomment = NULL;
  vx_data_textblock::Const_delimcommentblock c_delimcommentblock = NULL;
  vx_data_textblock::Const_delimline c_delimline = NULL;
  vx_data_textblock::Const_delimnonwhitespace c_delimnonwhitespace = NULL;
  vx_data_textblock::Const_delimparen c_delimparen = NULL;
  vx_data_textblock::Const_delimquote c_delimquote = NULL;
  vx_data_textblock::Const_delimquoteblock c_delimquoteblock = NULL;
  vx_data_textblock::Const_delimspace c_delimspace = NULL;
  vx_data_textblock::Const_delimtext c_delimtext = NULL;
  vx_data_textblock::Const_delimwhitespace c_delimwhitespace = NULL;
  vx_data_textblock::Func_children_from_textblock e_children_from_textblock = NULL;
  vx_data_textblock::Func_children_from_textblock t_children_from_textblock = NULL;
  vx_data_textblock::Func_delim_close_from_delim e_delim_close_from_delim = NULL;
  vx_data_textblock::Func_delim_close_from_delim t_delim_close_from_delim = NULL;
  vx_data_textblock::Func_delim_first_from_delim_delim e_delim_first_from_delim_delim = NULL;
  vx_data_textblock::Func_delim_first_from_delim_delim t_delim_first_from_delim_delim = NULL;
  vx_data_textblock::Func_delim_first_from_string_delimlist_offset e_delim_first_from_string_delimlist_offset = NULL;
  vx_data_textblock::Func_delim_first_from_string_delimlist_offset t_delim_first_from_string_delimlist_offset = NULL;
  vx_data_textblock::Func_delim_pos_from_string_delim_offset e_delim_pos_from_string_delim_offset = NULL;
  vx_data_textblock::Func_delim_pos_from_string_delim_offset t_delim_pos_from_string_delim_offset = NULL;
  vx_data_textblock::Func_delimlist_pos_from_string_delimlist_offset e_delimlist_pos_from_string_delimlist_offset = NULL;
  vx_data_textblock::Func_delimlist_pos_from_string_delimlist_offset t_delimlist_pos_from_string_delimlist_offset = NULL;
  vx_data_textblock::Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = NULL;
  vx_data_textblock::Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = NULL;
  vx_data_textblock::Func_text_from_textblock e_text_from_textblock = NULL;
  vx_data_textblock::Func_text_from_textblock t_text_from_textblock = NULL;
  vx_data_textblock::Func_textblock_addchild_from_textblock_child e_textblock_addchild_from_textblock_child = NULL;
  vx_data_textblock::Func_textblock_addchild_from_textblock_child t_textblock_addchild_from_textblock_child = NULL;
  vx_data_textblock::Func_textblock_delimnotfound e_textblock_delimnotfound = NULL;
  vx_data_textblock::Func_textblock_delimnotfound t_textblock_delimnotfound = NULL;
  vx_data_textblock::Func_textblock_parse e_textblock_parse = NULL;
  vx_data_textblock::Func_textblock_parse t_textblock_parse = NULL;
  vx_data_textblock::Func_textblock_parse_one e_textblock_parse_one = NULL;
  vx_data_textblock::Func_textblock_parse_one t_textblock_parse_one = NULL;
  vx_data_textblock::Func_textblock_parse_from_string_delim e_textblock_parse_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_parse_from_string_delim t_textblock_parse_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_pop e_textblock_pop = NULL;
  vx_data_textblock::Func_textblock_pop t_textblock_pop = NULL;
  vx_data_textblock::Func_textblock_pop_from_textblock_delim e_textblock_pop_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_pop_from_textblock_delim t_textblock_pop_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_push e_textblock_push = NULL;
  vx_data_textblock::Func_textblock_push t_textblock_push = NULL;
  vx_data_textblock::Func_textblock_push_from_textblock_delim e_textblock_push_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_push_from_textblock_delim t_textblock_push_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_startleft_from_string_delim_offset e_textblock_startleft_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startleft_from_string_delim_offset t_textblock_startleft_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startright_from_string_delim_offset e_textblock_startright_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_startright_from_string_delim_offset t_textblock_startright_from_string_delim_offset = NULL;
  vx_data_textblock::Func_textblock_from_string_delim e_textblock_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_from_string_delim t_textblock_from_string_delim = NULL;
  vx_data_textblock::Func_textblock_from_textblock_delim e_textblock_from_textblock_delim = NULL;
  vx_data_textblock::Func_textblock_from_textblock_delim t_textblock_from_textblock_delim = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_textblock::c_delimbracketangle = new vx_data_textblock::Class_delimbracketangle();
      vx_data_textblock::c_delimbracketcurly = new vx_data_textblock::Class_delimbracketcurly();
      vx_data_textblock::c_delimbracketsquare = new vx_data_textblock::Class_delimbracketsquare();
      vx_data_textblock::c_delimclose = new vx_data_textblock::Class_delimclose();
      vx_data_textblock::c_delimcomma = new vx_data_textblock::Class_delimcomma();
      vx_data_textblock::c_delimcomment = new vx_data_textblock::Class_delimcomment();
      vx_data_textblock::c_delimcommentblock = new vx_data_textblock::Class_delimcommentblock();
      vx_data_textblock::c_delimline = new vx_data_textblock::Class_delimline();
      vx_data_textblock::c_delimnonwhitespace = new vx_data_textblock::Class_delimnonwhitespace();
      vx_data_textblock::c_delimparen = new vx_data_textblock::Class_delimparen();
      vx_data_textblock::c_delimquote = new vx_data_textblock::Class_delimquote();
      vx_data_textblock::c_delimquoteblock = new vx_data_textblock::Class_delimquoteblock();
      vx_data_textblock::c_delimspace = new vx_data_textblock::Class_delimspace();
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
      vx_data_textblock::e_delim_close_from_delim = new vx_data_textblock::Class_delim_close_from_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_close_from_delim);
      vx_data_textblock::t_delim_close_from_delim = new vx_data_textblock::Class_delim_close_from_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_close_from_delim);
      vx_data_textblock::e_delim_first_from_delim_delim = new vx_data_textblock::Class_delim_first_from_delim_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_first_from_delim_delim);
      vx_data_textblock::t_delim_first_from_delim_delim = new vx_data_textblock::Class_delim_first_from_delim_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_first_from_delim_delim);
      vx_data_textblock::e_delim_first_from_string_delimlist_offset = new vx_data_textblock::Class_delim_first_from_string_delimlist_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_first_from_string_delimlist_offset);
      vx_data_textblock::t_delim_first_from_string_delimlist_offset = new vx_data_textblock::Class_delim_first_from_string_delimlist_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_first_from_string_delimlist_offset);
      vx_data_textblock::e_delim_pos_from_string_delim_offset = new vx_data_textblock::Class_delim_pos_from_string_delim_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delim_pos_from_string_delim_offset);
      vx_data_textblock::t_delim_pos_from_string_delim_offset = new vx_data_textblock::Class_delim_pos_from_string_delim_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_delim_pos_from_string_delim_offset);
      vx_data_textblock::e_delimlist_pos_from_string_delimlist_offset = new vx_data_textblock::Class_delimlist_pos_from_string_delimlist_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_delimlist_pos_from_string_delimlist_offset);
      vx_data_textblock::t_delimlist_pos_from_string_delimlist_offset = new vx_data_textblock::Class_delimlist_pos_from_string_delimlist_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_delimlist_pos_from_string_delimlist_offset);
      vx_data_textblock::e_stringlist_from_textblocklist = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_empty(vx_data_textblock::e_stringlist_from_textblocklist);
      vx_data_textblock::t_stringlist_from_textblocklist = new vx_data_textblock::Class_stringlist_from_textblocklist();
      vx_core::vx_reserve_type(vx_data_textblock::t_stringlist_from_textblocklist);
      vx_data_textblock::e_text_from_textblock = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_empty(vx_data_textblock::e_text_from_textblock);
      vx_data_textblock::t_text_from_textblock = new vx_data_textblock::Class_text_from_textblock();
      vx_core::vx_reserve_type(vx_data_textblock::t_text_from_textblock);
      vx_data_textblock::e_textblock_addchild_from_textblock_child = new vx_data_textblock::Class_textblock_addchild_from_textblock_child();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_addchild_from_textblock_child);
      vx_data_textblock::t_textblock_addchild_from_textblock_child = new vx_data_textblock::Class_textblock_addchild_from_textblock_child();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_addchild_from_textblock_child);
      vx_data_textblock::e_textblock_delimnotfound = new vx_data_textblock::Class_textblock_delimnotfound();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_delimnotfound);
      vx_data_textblock::t_textblock_delimnotfound = new vx_data_textblock::Class_textblock_delimnotfound();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_delimnotfound);
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
      vx_data_textblock::e_textblock_pop = new vx_data_textblock::Class_textblock_pop();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_pop);
      vx_data_textblock::t_textblock_pop = new vx_data_textblock::Class_textblock_pop();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_pop);
      vx_data_textblock::e_textblock_pop_from_textblock_delim = new vx_data_textblock::Class_textblock_pop_from_textblock_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_pop_from_textblock_delim);
      vx_data_textblock::t_textblock_pop_from_textblock_delim = new vx_data_textblock::Class_textblock_pop_from_textblock_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_pop_from_textblock_delim);
      vx_data_textblock::e_textblock_push = new vx_data_textblock::Class_textblock_push();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_push);
      vx_data_textblock::t_textblock_push = new vx_data_textblock::Class_textblock_push();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_push);
      vx_data_textblock::e_textblock_push_from_textblock_delim = new vx_data_textblock::Class_textblock_push_from_textblock_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_push_from_textblock_delim);
      vx_data_textblock::t_textblock_push_from_textblock_delim = new vx_data_textblock::Class_textblock_push_from_textblock_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_push_from_textblock_delim);
      vx_data_textblock::e_textblock_startleft_from_string_delim_offset = new vx_data_textblock::Class_textblock_startleft_from_string_delim_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_startleft_from_string_delim_offset);
      vx_data_textblock::t_textblock_startleft_from_string_delim_offset = new vx_data_textblock::Class_textblock_startleft_from_string_delim_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_startleft_from_string_delim_offset);
      vx_data_textblock::e_textblock_startright_from_string_delim_offset = new vx_data_textblock::Class_textblock_startright_from_string_delim_offset();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_startright_from_string_delim_offset);
      vx_data_textblock::t_textblock_startright_from_string_delim_offset = new vx_data_textblock::Class_textblock_startright_from_string_delim_offset();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_startright_from_string_delim_offset);
      vx_data_textblock::e_textblock_from_string_delim = new vx_data_textblock::Class_textblock_from_string_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_string_delim);
      vx_data_textblock::t_textblock_from_string_delim = new vx_data_textblock::Class_textblock_from_string_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_string_delim);
      vx_data_textblock::e_textblock_from_textblock_delim = new vx_data_textblock::Class_textblock_from_textblock_delim();
      vx_core::vx_reserve_empty(vx_data_textblock::e_textblock_from_textblock_delim);
      vx_data_textblock::t_textblock_from_textblock_delim = new vx_data_textblock::Class_textblock_from_textblock_delim();
      vx_core::vx_reserve_type(vx_data_textblock::t_textblock_from_textblock_delim);
      vx_data_textblock::Class_delimbracketangle::vx_const_new(vx_data_textblock::c_delimbracketangle);
      vx_data_textblock::Class_delimbracketcurly::vx_const_new(vx_data_textblock::c_delimbracketcurly);
      vx_data_textblock::Class_delimbracketsquare::vx_const_new(vx_data_textblock::c_delimbracketsquare);
      vx_data_textblock::Class_delimclose::vx_const_new(vx_data_textblock::c_delimclose);
      vx_data_textblock::Class_delimcomma::vx_const_new(vx_data_textblock::c_delimcomma);
      vx_data_textblock::Class_delimcomment::vx_const_new(vx_data_textblock::c_delimcomment);
      vx_data_textblock::Class_delimcommentblock::vx_const_new(vx_data_textblock::c_delimcommentblock);
      vx_data_textblock::Class_delimline::vx_const_new(vx_data_textblock::c_delimline);
      vx_data_textblock::Class_delimnonwhitespace::vx_const_new(vx_data_textblock::c_delimnonwhitespace);
      vx_data_textblock::Class_delimparen::vx_const_new(vx_data_textblock::c_delimparen);
      vx_data_textblock::Class_delimquote::vx_const_new(vx_data_textblock::c_delimquote);
      vx_data_textblock::Class_delimquoteblock::vx_const_new(vx_data_textblock::c_delimquoteblock);
      vx_data_textblock::Class_delimspace::vx_const_new(vx_data_textblock::c_delimspace);
      vx_data_textblock::Class_delimtext::vx_const_new(vx_data_textblock::c_delimtext);
      vx_data_textblock::Class_delimwhitespace::vx_const_new(vx_data_textblock::c_delimwhitespace);
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
